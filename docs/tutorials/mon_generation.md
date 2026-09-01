# Generation of struct Pokemon instances

This document describes the ways you generate an instance of `struct Pokemon` through script or through code.
These Pokemon can be given to your players, be used as enemy trainer Pokemon or as static wild Pokemon.

## Through script (`givemon` and `createmon`)

### `createmon`

`createmon` is a script command that allows you to generate a Pokemon with any of the properties you might want. It has a lot of arguments in order to offer this flexibility.

#### Required Arguments

> **side, slot, species, level** are the required arguments.

- **side** determines if the Pokemon will be created as a player Pokemon or an enemy Pokemon:
  - `0` will put the Pokemon in the player party
  - `1` in the enemy party

- **slot** determines the slot in the player or enemy party the Pokemon will occupy.
  - `slot` goes from `0` to `5`
  - If `side` is `0` (player Pokemon), setting the slot to `6` will instead give the Pokemon to player automatically putting it in the first empty slot or sending it to the PC when the party is the full.
  - Setting `slot` to `6` when trying to create an enemy Pokemon will result in the `createmon` command being ignored.

- **species** and **level** refer to the species id and the level of the Pokemon you want to generate.

#### Optional Arguments

> `item`, `ball`, `nature`, `abilityNum`, `gender`, `hpEv`, `atkEv`, `defEv`, `speedEv`, `spAtkEv`, `spDefEv`, `hpIv`, `atkIv`, `defIv`, `speedIv`, `spAtkIv`, `spDefIv`, `move1`, `move2`, `move3`, `move4`, `shinyMode`, `gmaxFactor`, `teraType`, `dmaxLevel`.

The purpose of these arguments is largely self-explanatory but we will briefly discuss what they default to when nothing is explicitly specified.

- **item** refers to the item the Pokemon is holding. If the argument is missing, the Pokemon won’t be holding anything.

- **ball** refers to the type of ball the Pokemon comes out of. The expected type is `enum Pokeball` defaults to a `BALL_POKE`. If the Pokemon being generated is a Wild Pokemon this will be overwritten if the Pokemon is captured.

- **nature** and **gender** will default to random values.

- **abilityNum** will default to the value corresponding to the personality rolled (This is essentially random but it will be have correlations to the other parameters of the Pokemon).

- **EVs**
  `hpEv, atkEv, defEv, speedEv, spAtkEv, spDefEv` will default to `0`.

- **IVs**
  `hpIv, atkIv, defIv, speedIv, spAtkIv, spDefIv` will default to `USE_RANDOM_IVS` which tell the game to roll a random IV value (between `0` and `31`). If the generated species has a `perfectIVCount`, only the random values will be eligible to be perfected.

- **moves**
  `move1, move2, move3, move4` will default to `MOVE_DEFAULT` which tells the game to fill the slot with the last level up move available.

- **shinyMode** will default to `SHINY_MODE_RANDOM` doing random roll(s) to check if the Pokemon is shiny.
  - `SHINY_MODE_ALWAYS` forces the Pokemon to be shiny
  - `SHINY_MODE_NEVER` forces the Pokemon to not be shiny

- **gmaxFactor** defaults to `FALSE`.

- **teraType** will default to the value corresponding to the personality they will roll (in practice, it’s random but it will have correlations with other if the Pokemon parameters).

- **dmaxLevel** will default to `0`.

---

### `givemon`

`givemon` uses the same arguments as `createmon` minus `side` and `slot`.

This is because `givemon` is almost equivalent to `createmon 0 6 ...` and just gives the Pokemon to the player after generating it.

The exception being that `givemon` interacts with the abilities `Synchronize` and `Cute Charm` somewhat differently than `createmon` when `nature` or `gender` are not explicitly set.

---

### `setwildbattle`

##### Arguments

> `species:req`, `level:req`, `item=ITEM_NONE`, `species2=SPECIES_NONE`, `level2=0`, `item2=ITEM_NONE`

`setwildbattle` is a much simpler way to generate a Wild Pokemon ready for the player to fight.

It only takes 3 arguments (or 6 if you want to make it a double wild battle)

- `species` and `level` refer to the `species` and the `level` of the Pokemon you want to generate.
- `item` refers to the item the Pokemon is holding. If no argument is provided the Pokemon will not be holding an item.
- `species2`, `level2`, and `item2` determine the `species`, `level` and `held item` respectively of the second Pokemon generated in case you want to make a double wild battle
- The other properties like IVs and personality will be set randomly the same way as they are set in regular wild battles.

Pokemon generated with `setwildbattle` will always be considered static encounters (`STATIC_WILDMON_ORIGIN`) and will thus be eligible to be affected by Synchronize and Cute Charm

#### Synchronize and Cute Charm

 `nature` and `gender` also accept `NATURE_MAY_SYNCHRONIZE` and `MON_GENDER_MAY_CUTE_CHARM` respectively as arguments.

`NATURE_RANDOM` and `MON_GENDER_RANDOM` always return a random nature/gender and never check for Synchronize or Cute Charm. If you want the generated Pokemon to have a chance to receive the effects of Synchronize or Cute Charm, you need to use `NATURE_MAY_SYNCHRONIZE` and `MON_GENDER_MAY_CUTE_CHARM` respectively for nature and gender.

When you use `NATURE_MAY_SYNCHRONIZE` or `MON_GENDER_MAY_CUTE_CHARM`, you are telling the game can check if the player has a Pokemon with Synchronize or Cute Charm in the first slot of its party and roll a die to see if the nature or gender should be fixed based on the ability or rolled normally.

The Pokemon generated also need to be of the right "origin" to be eligible for Synchronize or Cute Charm. We don't want to "synchronize" a Pokemon belonging to a trainer or change the gender of a gift Pokemon with Cute Charm. So if a Pokemon is generated for the player side, it will be considered a "gift Pokemon" (`GIFTMON_ORIGIN`) and if a Pokemon is generated on the enemy side, it will be considered a static wild encounter (`STATIC_WILDMON_ORIGIN`).

`givemon` will default to use `NATURE_MAY_SYNCHRONIZE` and `MON_GENDER_MAY_CUTE_CHARM` because we assume you will use `givemon` to create "gift Pokemon" but if you don't want it to apply in a specific script, you can explicitly use `NATURE_RANDOM` and `MON_GENDER_RANDOM` instead

`createmon` on the other hand default to `NATURE_RANDOM` and `MON_GENDER_RANDOM` so you need to explicitly use `NATURE_MAY_SYNCHRONIZE` or `MON_GENDER_MAY_CUTE_CHARM` for the generated Pokemon to be considered a gift Pokemon or a static wild encounter

Static encounters and Gift Pokemon eligibility to Synchronize vary through generations in the official games so you can use the config `OW_SYNCHRONIZE_NATURE` to match your preference or you can check the `src/ow_abilities.c` to modify the Synchronize and Cute Charm eligibility of different origins however you like

---

## Through Code

There are several instances of Pokemon generation throughout the game:
- When you start a wild encounter,
- When a trainer generates its party from the data in `trainers.party`,
- Or when you call one of the scripts described in the previous section.

In this section we will go through some of the most common functions.

> NOTE: None of the functions described here allocate memory for the Pokemon struct, they all expect a pointer they will fill the data with.

It means they are usually called with `&gParties[B_TRAINER_PLAYER][index]` or `&gParties[B_TRAINER_OPPONENT_A][index]` because these are places in memory reserved for Pokemon struct.

### The Basics

To generate a Pokemon ready for battle, you usually need to go through the following steps:

1. Generate a personality value
2. Fill the generic mon structure based on `species`, `level` and `personality`.
3. Set IVs and EVs.
4. (Re-)Compute stats (this step does not happen if you are generating a `struct BoxPokemon` instead of `struct Pokemon`).
5. set the moves.

### `GetMonPersonality`

`GetMonPersonality` is the easiest way to make a personality value. It takes 4 arguments `species`, `gender`, `nature` and `unownLetter` then it rolls random personality values until it finds one that match all the selected criteria.

For example, if you want a personality for Wally's male Ralts, you would write:

```c
personality = GetMonPersonality(SPECIES_RALTS, MON_MALE, NATURE_RANDOM, RANDOM_UNOWN_LETTER);
```

And if you want a personality for a brave J Unown, you would write:

```c
personality = GetMonPersonality(SPECIES_UNOWN, MON_GENDER_RANDOM, NATURE_BRAVE, 9);
// J is the 10th letter of alphabet but for Unown A starts at 0 so B is 1 and J is 9
```

As you can see, you can use either a specific value or a special value `MON_GENDER_RANDOM`, `NATURE_RANDOM` or `RANDOM_UNOWN_LETTER` to tell the function to return any Pokemon matching the other properties. This means, writing:

```
personality = GetMonPersonality(SPECIES_X, MON_GENDER_RANDOM, NATURE_RANDOM, RANDOM_UNOWN_LETTER);
```

is equivalent to `personality = Random32();` which is why `Random32()` is used throughout the codebase to generate fully random personality values.

---

### `CreateMon` and `CreateBoxMon`

`CreateMon` is the most basic function to create a generic Pokemon struct. It takes 5 arguments:

- `mon` is a pointer to the Pokemon struct you want to set the data for

- `species` and `level` are self-explanatory.

- `personality` is the personality value you want to use to create your Pokemon, it will determine a lot of your Pokemon properties and will usually be a number that you generated by following the instructions from the previous section.

- `trainerID` is a special type of struct that explain how the function should set up the `otId` of the Pokemon. Usually you will want to use one of these 3 macros for the argument:

  - `OTID_STRUCT_PLAYER_ID` which means the Pokemon will use the player `otId` (used by Wild Pokemon so they the get the player id when captured)

  - `OTID_STRUCT_PRESET(value)` which set a specific `otId` that you pick/write yourself

  - `OTID_STRUCT_RANDOM_NO_SHINY` which picks a random `otId` and forces the Pokemon to not be shiny even if the random `otId` and chosen `personality` would have made the Pokemon shiny. It is used by NPC trainers.

- Both `CreateMon` and `CreateBoxMon` erase the Pokemon data in the pointer before they add the new data so every value they don't set will be zero-ed in some way. This is why they are considered "base" functions.

The values set by `CreateMon` and `CreateBoxMon` are the `gender`, `ability num`, `tera type` and `nature` (based on personality); the `met info` (location, level and game), the `OT name` , `gender` and `language` (always set to the player even for enemy trainer Pokemon), the `starting xp` (based on the xp required to reach the level the Pokemon is at), the `starting friendship` (based on the species info) and the `shinyness`.

`CreateMon` and `CreateBoxMon` are very similar. In fact, the `CreateMon` function calls `CreateBoxMon` to generate the BoxPokemon part of its structure but it also sets the level and a mail object (to an empty value)

### Setting IVs and EVs

#### IVs

Usually, you will want to use `SetBoxMonIVs(mon->box, ivs)` to set the IVs of the Pokemon being generated. The reason is that not only can you quickly set all ivs of your Pokemon to a single value.

For instance `SetBoxMonIVs(mon->box, 15)` will set all IVs to 15.

You can also use the special argument `USE_RANDOM_IVS`. When used with `USE_RANDOM_IVS`, `SetBoxMonIvs` will not only pick a random value between 0 and 31 for each stat, it will also allocate some perfect iv if the species of the Pokemon has a `perfectIvCount` set in the species data.

For example if you are generating a legendary with a `perfectIvCount` of 3, using `SetBoxMonIVs(mon->box, USE_RANDOM_IVS)` will guarantee that at least 3 IVs are set to 31. This is done using the function `SetBoxMonPerfectIVs`, which can also be used elsewhere to assign a number of random perfect IVs.

The other way to assign IV is to use `SetMonData`, for example:

```c
SetMonData(mon, MON_DATA_HP_IV, 15)
```

with the stats being in the order `MON_DATA_HP_IV`, `MON_DATA_ATK_IV`, `MON_DATA_DEF_IV`, `MON_DATA_SPEED_IV`, `MON_DATA_SPATK_IV` and `MON_DATA_SPDEF_IV`

You can also use a loop like this:

```c
for (i = 0; i < NUM_STATS; i++)
    SetMonData(mon, MON_DATA_HP_IV + i, iv_array[i])
```

if you happen to have an array containing the values you want. However, you must be careful about the order of the stats if you use this method.
#### EVs

EVs default to `0` when a Pokemon is generated with `CreateMon` or `CreateBoxMon`. You will not need to anything if you want to keep it that way.

If you want to change them, there are currently no utilities to set EVs. Thus you will need to use the `SetMonData` method:

```c
SetMonData(mon, MON_DATA_HP_EV, 252)
```

The stats have the same names as the IVs with I change into an E : `MON_DATA_HP_EV`, `MON_DATA_ATK_EV`, `MON_DATA_DEF_EV`, `MON_DATA_SPEED_EV`, `MON_DATA_SPATK_EV` and `MON_DATA_SPDEF_EV` so the loop method works here as well.

```c
for (i = 0; i < NUM_STATS; i++)
    SetMonData(mon, MON_DATA_HP_EV + i, ev_array[i])
```

Just be careful when setting IVs and EVs with `SetMonData` because there is no check to make sure the IV and EV values you are setting are valid and this may cause some issues.

### `CalculateMonStats`

After all the IVs and EVs have been set for your Pokemon, it's important to run `CalculateMonStats(mon)`. The function only has one argument so it's pretty simple but don't forget this step or you may have some issues.

### Setting moves

To set a move in slot `slot`, you would need to write:

```c
enum Move move = MOVE_X;
u32 pp = GetMovePP(move);
SetMonData(mon, MON_DATA_MOVE1 + slot, &move);
SetMonData(mon, MON_DATA_PP1 + slot, &spp);
```

where slot can be between 0 and 3 to represent the 1st to 4th move
You can also call the function `GiveMonInitialMoveset(mon)` that will give your Pokemon its last 4 level-up moves available similarly to the wild Pokemon you might encounter.

## Going from 1.14 to 1.15

When going from 1.14 to 1.15, Expansion deleted multiple functions related to Pokemon generation that were not used in Expansion anymore.
The following functions were deleted

```c
void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature);
void CreateMonWithGenderNatureLetter(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 gender, u8 nature, u8 unownLetter);
void CreateMonWithIVsOTID(struct Pokemon *mon, u16 species, u8 level, u8 *ivs, u32 otId);
void CreateMonWithEVSpread(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 evSpread);
void CreateMonWithEVSpreadNatureOTID(struct Pokemon *mon, u16 species, u8 level, u8 nature, u8 fixedIV, u8 evSpread, u32 otId);
```

If you add custom code relying on those functions, I would advise to simple recode them using the methods described in the previous section. If you follow the steps, you should be able to rewrite a function with the same effect easily.

However the move to 1.15 also completely rewrote these two functions:

```c
void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
```

`CreateMon` and `CreateBoxMon` now have different arguments and do less things than their 1.14 counterparts. If you have code that used those functions, we recommend you use these legacy version of `CreateMon` and `CreateBoxMon`:

```c
void CreateMonLegacy(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u32 personality = hasFixedPersonality ? fixedPersonality : Random32();
    struct OriginalTrainerId otId = {otIdType, fixedOtId};
    CreateMonWithIVs(mon, species, level, personality, otId, fixedIV);
    GiveMonInitialMoveset(mon);
}

void CreateBoxMonLegacy(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u32 personality = hasFixedPersonality ? fixedPersonality : Random32();
    struct OriginalTrainerId otId = {otIdType, fixedOtId};
    CreateBoxMon(boxMon, species, level, personality, otId);
    SetBoxMonIVs(boxMon, fixedIV);
    GiveBoxMonInitialMoveset(boxMon);
}
```

These two legacy functions use the 1.15 functions to recreate the 1.14 versions of `CreateMon` and `CreateBoxMon` with the same arguments and the same effects. Add these two legacy functions to your code then change your custom code that was relying on 1.14 `CreateMon` or `CreateBoxMon` to use `CreateMonLegacy` or `CreateBoxMonLegacy` instead and everything should work the same as before
