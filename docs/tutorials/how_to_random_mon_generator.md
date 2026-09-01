# How to Use the Random Mon Generator
*Written by Jordan/harbingerofruination*

## What is the random mon generator?

The random mon generator is a script-based command that can be used to set up in-game trades, events, or other scenarios where you would need a random mon. It is only entirely random if you want it to be, and has a wide range of customization and feature options. The purpose of this document is to explain and show you how to set it up for your own use case.

# Step 1: Setting Up Your Rules

So you want to make a custom ruleset for a possible random pokemon you'd like to use or distribute. Well, naturally, if you're giving something to the player early, it's unlikely you're going to want to have them receive a legendary or mythical pokemon, or a pokemon holding the choice specs or assault vest. Let's look at how to set it up such that you have the perfect pool of pokemon for your script to fetch from.

## Species Generation Options

### Setting Up Our Random Species

First thing's first, we need a way for the logic to read that we want a specific kind of random mon. Add your named species generator options in [include/constants/random_mon_generation.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/random_mon_generation.h), configure their rules in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h), then pass those names to `getrandomspecies` in scripts.

### The Random Species Struct

```
struct RandomSpeciesGeneratorOptions
{
    const enum Species *bannedSpecies;
    const enum Species *speciesPool;
    bool32 (*filterFunc)(enum Species species, const struct FilterFuncArgs *filterFuncArgs);
    u32 speciesPoolCount:11;
    u32 bannedSpeciesCount:11;
    u32 banLegendary:1;
    u32 banMythical:1;
    u32 banSubLegendary:1;
    u32 banUltraBeast:1;
    u32 banParadox:1;
    u32 randomizeForms:1;
    enum RandomSpeciesDexMode dexMode:1;
    u32 padding:3;
};
```

These are the options you can toggle and change to select the ideal possible species. Let's go over the options one-by-one.

* `enum RandomSpeciesDexMode dexMode`: With values of either `RANDOM_MON_DEX_NATIONAL` or `RANDOM_MON_DEX_HOENN`, allows you to select whether you want to choose from your National Dex or the Hoenn Dex. If you've replaced the hoenn dex but want to use that functionality, be sure that you investigate that path and substitute any references or functions specific to the hoenn dex to parallel ones for your custom dex.
* `const enum Species *speciesPool`: A pointer to the specific species pool you want to use, if any. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). Examples of this will come later. You can repeat values in this pool to create pseudo weights; for example, `{SPECIES_BULBASAUR, SPECIES_BULBASAUR, SPECIES_BULBASAUR, SPECIES_SQUIRTLE}` gives a 75% chance of Bulbasaur and a 25% chance of Squirtle.
* `u32 speciesPoolCount`: The total number of species in your pool, if any.
* `const enum Species *bannedSpecies`: A pointer to the a pool containing any species of pokemon you want *banned* from selection. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). You shouldn't use this in combination with the speciesPool, as that doesn't really make sense. Leave this one NULL if you have a specific pool of species you want to pick from, or use it if you want more randomness but with some specific banning restrictions that the other options below don't allow.
* `u32 bannedSpeciesCount`: The total number of banned species in the above pool, if any.
* `u32 banLegendary`: Whether to ban restricted legendary pokemon from selection.
* `u32 banMythical`: Whether to ban mythical pokemon from selection.
* `u32 banSubLegendary`: Whether to ban sub-legendary pokemon (Regi trio, genies, etc) from selection.
* `u32 banUltraBeast`: Whether to ban ultra beast pokemon from selection.
* `u32 banParadox`: Whether to ban paradox pokemon from selection.
* `u32 randomizeForms`: Whether to randomize forms of pokemon. By default, megas, fusions, and in-battle transformations are disallowed. To add exceptions, see and modify `IsRandomSpeciesFormTableException` in [src/random_mon_generation.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/random_mon_generation.c).

### Filter Functions

Now you may notice that we didn't discuss `bool32 (*filterFunc)(enum Species species, const struct FilterFuncArgs *filterFuncArgs)`, and for good reason, as that element is more complicated than the others. This is a pointer to an additional filter you can mess with or add to select for specific traits or features.

For example, one of the default options uses `.filterFunc = IsInBstRangeFilterFunc`. When you call `getrandomspecies`, the optional `arg1` and `arg2` values are forwarded to the filter function. `IsInBstRangeFilterFunc` treats `arg1` as the BST target and `arg2` as the leniency, so `arg1=300, arg2=100` allows pokemon with BST 200 through 400.

If a species option has a `filterFunc`, pass any args that function requires. Omitted args default to `0xFFFF`, and each filter function decides how to handle omitted args. For example, `IsInBstRangeFilterFunc` requires both args and asserts if either one is omitted, but a custom filter function can ignore the args entirely.

You could also, using similar logic, create a function that treats `arg1` as a type value, and then filter only for pokemon of that type if possible. If you do not pass a filter function, then no filter beyond the other elements is applied.

### Debugging randomizer options

If you want to verify you set up your options correctly, you can open your debug menu and go
Utility -> Test Species/Item Randomiser
Then select the index of the options in options array, followed by the filter function arguments (you can leave it at 0 if not relevant) and the game will generate 24 random results. You can press A to generate 24 more or press B to quit.

### Example Setup

For a named random mon option, define the script-facing value in [include/constants/random_mon_generation.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/random_mon_generation.h), then use that same enum value as the array index in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). With separate species and/or ban pools, your setup would look like this:

```
enum
{
    SPECIES_GENERATOR_NO_SUPERMONS,
    SPECIES_GENERATOR_LIMITED_POOL,
    SPECIES_GENERATOR_BST_RESTRICTED,
    RANDOM_SPECIES_OPTIONS_COUNT,
};

static const enum Species sRandomSpeciesOption0SpeciesPool[] =
{
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_RALTS,
    SPECIES_ARON,
    SPECIES_TRAPINCH,
    SPECIES_BAGON,
    SPECIES_BELDUM,
};

static const enum Species sRandomSpeciesOption0BannedSpecies[] =
{
    SPECIES_BELDUM,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[] =
{
    [SPECIES_GENERATOR_LIMITED_POOL] =
    {
        .speciesPool = sRandomSpeciesOption0SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption0SpeciesPool),
        .bannedSpecies = sRandomSpeciesOption0BannedSpecies,
        .bannedSpeciesCount = ARRAY_COUNT(sRandomSpeciesOption0BannedSpecies),
        .banLegendary = TRUE,
        .banMythical = TRUE,
        .banSubLegendary = TRUE,
        .banUltraBeast = TRUE,
        .banParadox = TRUE,
        .randomizeForms = TRUE,
    },

    [SPECIES_GENERATOR_BST_RESTRICTED] =
    {
        .dexMode = RANDOM_MON_DEX_HOENN,
        .filterFunc = IsInBstRangeFilterFunc,
        .banLegendary = TRUE,
        .banMythical = TRUE,
        .banSubLegendary = TRUE,
        .banUltraBeast = TRUE,
        .banParadox = TRUE,
        .randomizeForms = TRUE,
    },
}
```

> [!NOTE]
> You really don't need to use a choosable species pool and a banned species pool in the same ruleset, it just doesn't make sense and may end up causing more trouble than anything. Additionally, you should never include SPECIES_NONE in either of these kinds of pools, only actual, defined species.

Small explicit species pools are checked exhaustively before choosing, which gives clear errors if every entry is filtered out. Larger explicit pools and full dex searches use repeated random attempts. If the filters are too restrictive or an invalid option is requested, the command resolves to `SPECIES_NONE`.

## Item Generator Options

Item randomization is handled separately from pokemon randomization, meaning that you could always give a charmander but it could always hold a random or semi-random item. Compared to the species generation options, here we have far fewer to discuss.

### Setting Up Our Random Items

As we did for our random species, we need to also do for our random items. Add your named item generator options in [include/constants/random_mon_generation.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/random_mon_generation.h), configure their rules in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h), then pass those names to `getrandomitem` in scripts.

### The Random Item Struct

```
struct RandomItemGeneratorOptions
{
    const enum Item *heldItemPool;
    const enum HoldEffect *bannedHoldEffects;
    bool32 (*filterFunc)(enum Item item, const struct FilterFuncArgs *filterFuncArgs);
    u16 heldItemPoolCount;
    u16 bannedHoldEffectsCount;
};
```

* `const enum Item *heldItemPool`: A pointer to the specific item pool you want to use, if any. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). You can repeat values in this pool to create pseudo weights; for example, `{ITEM_NONE, ITEM_NONE, ITEM_NONE, ITEM_LUM_BERRY}` gives a 75% chance of no item and a 25% chance of Lum Berry.
* `u16 heldItemPoolCount`: The number of items in your held item pool, if any.
* `const enum HoldEffect *bannedHoldEffects`: A pointer to the specific list of banned hold effects you want to use, if any. Leave it NULL or create one in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h).
* `u16 bannedHoldEffectsCount`: The number of banned hold effects in your pool, if any.
* `bool32 (*filterFunc)(enum Item item, const struct FilterFuncArgs *filterFuncArgs)`: An optional item filter function. The built-in `IsHeldItemFilterFunc` only allows items with a non-`HOLD_EFFECT_NONE` hold effect. `getrandomitem` currently passes a zeroed `FilterFuncArgs` value, so custom item filters can accept the same argument struct as species filters even if the script command does not expose item filter arguments yet.

Key items are always blocked from random item generation, even if they are included in an explicit pool. TM/HM-pocket items with a sell price of 0 are also blocked to protect against obvious sequence breaks.

### Example Setup

For a named random item option, define the script-facing value in [include/constants/random_mon_generation.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/random_mon_generation.h), then use that same enum value as the array index in [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h). With separate held item pools and/or hold effect ban pools, your setup would look like this:

```
enum
{
    ITEM_GENERATOR_STANDARD,
    ITEM_GENERATOR_LIMITED_POOL,
    RANDOM_ITEM_OPTIONS_COUNT,
};

static const enum HoldEffect sRandomItemOption0BannedHoldEffects[] =
{
    HOLD_EFFECT_NONE,
    HOLD_EFFECT_REPEL,
    HOLD_EFFECT_SOUL_DEW,
    HOLD_EFFECT_DEEP_SEA_TOOTH,
    HOLD_EFFECT_DEEP_SEA_SCALE,
    HOLD_EFFECT_LIGHT_BALL,
    HOLD_EFFECT_THICK_CLUB,
    HOLD_EFFECT_LEEK,
    HOLD_EFFECT_ADAMANT_ORB,
    HOLD_EFFECT_LUSTROUS_ORB,
    HOLD_EFFECT_GRISEOUS_ORB,
    HOLD_EFFECT_ENIGMA_BERRY,
    HOLD_EFFECT_PLATE,
    HOLD_EFFECT_DRIVE,
    HOLD_EFFECT_GEMS,
    HOLD_EFFECT_MEGA_STONE,
    HOLD_EFFECT_PRIMAL_ORB,
    HOLD_EFFECT_MEMORY,
    HOLD_EFFECT_Z_CRYSTAL,
    HOLD_EFFECT_BOOSTER_ENERGY,
    HOLD_EFFECT_OGERPON_MASK,
};

static const enum Item sRandomItemOption0HeldItemPool[] =
{
    ITEM_LEFTOVERS,
    ITEM_SITRUS_BERRY,
    ITEM_LUM_BERRY,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SCARF,
    ITEM_CHOICE_SPECS,
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[] =
{
    [ITEM_GENERATOR_STANDARD] =
    {
        .bannedHoldEffects = sRandomItemOption0BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption0BannedHoldEffects),
        .filterFunc = IsHeldItemFilterFunc,
    },
    [ITEM_GENERATOR_LIMITED_POOL] =
    {
        .heldItemPool = sRandomItemOption0HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption0HeldItemPool),
        .bannedHoldEffects = sRandomItemOption0BannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemOption0BannedHoldEffects),
        .filterFunc = IsHeldItemFilterFunc,
    },
};
```

> [!NOTE]
> `ITEM_NONE` is never selected during full item randomization, but it can be included in an explicit held item pool if you want that option to sometimes produce no held item. Small explicit item pools are checked exhaustively before choosing, while larger explicit pools and full item searches use repeated random attempts.

# Step 2: Other options to be aware of

## Random Species and Item Commands

Random species and random items are generated before calling `givemon` or `createmon`. Use `getrandomspecies` to write a generated species into a var, and `getrandomitem` to write a generated item into a var. Then pass those vars into `givemon`, `createmon`, or another script command.

```
getrandomspecies VAR_0x8000, SPECIES_GENERATOR_LIMITED_POOL
getrandomitem VAR_0x8001, ITEM_GENERATOR_LIMITED_POOL
givemon VAR_0x8000, 50, item=VAR_0x8001
```

If your species option uses a `filterFunc`, you can pass up to two optional arguments. If you omit them, they default to `0xFFFF`; the filter function itself decides whether omitted args are valid.

```
getrandomspecies VAR_0x8000, SPECIES_GENERATOR_BST_RESTRICTED, arg1=300, arg2=100
```

## Random Ball Generation

This feature also includes random ball generation. When doing `givemon` or `createmon`, just use `ball=BALL_RANDOM` as an argument.

## Random Move Generation

This feature also includes random teachable move generation. When doing `givemon` or `createmon`, for move slot x, just use `movex=MOVE_RANDOM_TEACHABLE` as an argument.

# Step 3: Putting it all together

Here's an example of how you'd call it in a script when it all comes together:

```
EventScript_GiveFilteredRandomMon::
    // BST target = 300, leniency = 100, so valid BST range is 200-400.
    // SPECIES_GENERATOR_BST_RESTRICTED uses IsInBstRangeFilterFunc as a filterFunc.
    getrandomspecies VAR_0x8000, SPECIES_GENERATOR_BST_RESTRICTED, arg1=300, arg2=100
    getrandomitem VAR_0x8001, ITEM_GENERATOR_LIMITED_POOL

    givemon VAR_0x8000, 50,
        item=VAR_0x8001,
        ball=BALL_RANDOM,
        move1=MOVE_RANDOM_TEACHABLE,
        move2=MOVE_RANDOM_TEACHABLE,
        move3=MOVE_RANDOM_TEACHABLE,
        move4=MOVE_DEFAULT;

    end
```

This will produce a random mon from the BST-restricted species option with between 200 and 400 BST, a random item from the limited item pool, a random ball, 3 random teachable moves, and one move it'd normally have at that level (`MOVE_DEFAULT`).

# Appendix: Example Randomizer Data

The default [src/data/random_mon_generator.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/random_mon_generator.h) file intentionally leaves the option arrays empty. If you want a quick starting point, copy and adapt this into that file, then add matching enum names to [include/constants/random_mon_generation.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/random_mon_generation.h).

```
static const enum Species sRandomSpeciesOption1SpeciesPool[] =
{
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_RALTS,
    SPECIES_ARON,
    SPECIES_TRAPINCH,
    SPECIES_BAGON,
    SPECIES_BELDUM,
};

static const enum Species sRandomSpeciesOption1BannedSpecies[] =
{
    SPECIES_BELDUM,
};

static const enum HoldEffect sRandomItemStandardBannedHoldEffects[] =
{
    HOLD_EFFECT_NONE,
    HOLD_EFFECT_REPEL,
    HOLD_EFFECT_SOUL_DEW,
    HOLD_EFFECT_DEEP_SEA_TOOTH,
    HOLD_EFFECT_DEEP_SEA_SCALE,
    HOLD_EFFECT_LIGHT_BALL,
    HOLD_EFFECT_THICK_CLUB,
    HOLD_EFFECT_LEEK,
    HOLD_EFFECT_ADAMANT_ORB,
    HOLD_EFFECT_LUSTROUS_ORB,
    HOLD_EFFECT_GRISEOUS_ORB,
    HOLD_EFFECT_ENIGMA_BERRY,
    HOLD_EFFECT_PLATE,
    HOLD_EFFECT_DRIVE,
    HOLD_EFFECT_GEMS,
    HOLD_EFFECT_MEGA_STONE,
    HOLD_EFFECT_PRIMAL_ORB,
    HOLD_EFFECT_MEMORY,
    HOLD_EFFECT_Z_CRYSTAL,
    HOLD_EFFECT_BOOSTER_ENERGY,
    HOLD_EFFECT_OGERPON_MASK,
};

static const enum Item sRandomItemOption1HeldItemPool[] =
{
    ITEM_LEFTOVERS,
    ITEM_SITRUS_BERRY,
    ITEM_LUM_BERRY,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SCARF,
    ITEM_CHOICE_SPECS,
};

static const struct RandomSpeciesGeneratorOptions sRandomSpeciesGeneratorOptions[RANDOM_SPECIES_OPTIONS_COUNT] =
{
    [SPECIES_GENERATOR_NO_SUPERMONS] =
    {
        .dexMode = RANDOM_MON_DEX_NATIONAL,
        .banLegendary = TRUE,
        .banMythical = TRUE,
        .banSubLegendary = TRUE,
        .banUltraBeast = TRUE,
        .banParadox = TRUE,
        .randomizeForms = TRUE,
    },
    [SPECIES_GENERATOR_LIMITED_POOL] =
    {
        .speciesPool = sRandomSpeciesOption1SpeciesPool,
        .speciesPoolCount = ARRAY_COUNT(sRandomSpeciesOption1SpeciesPool),
        .bannedSpecies = sRandomSpeciesOption1BannedSpecies,
        .bannedSpeciesCount = ARRAY_COUNT(sRandomSpeciesOption1BannedSpecies),
        .banLegendary = TRUE,
        .banMythical = TRUE,
        .banSubLegendary = TRUE,
        .banUltraBeast = TRUE,
        .banParadox = TRUE,
        .randomizeForms = TRUE,
    },
    [SPECIES_GENERATOR_BST_RESTRICTED] =
    {
        .dexMode = RANDOM_MON_DEX_HOENN,
        .filterFunc = IsInBstRangeFilterFunc,
        .banLegendary = TRUE,
        .banMythical = TRUE,
        .banSubLegendary = TRUE,
        .banUltraBeast = TRUE,
        .banParadox = TRUE,
        .randomizeForms = TRUE,
    },
};

static const struct RandomItemGeneratorOptions sRandomItemGeneratorOptions[RANDOM_ITEM_OPTIONS_COUNT] =
{
    [ITEM_GENERATOR_STANDARD] =
    {
        .bannedHoldEffects = sRandomItemStandardBannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemStandardBannedHoldEffects),
        .filterFunc = IsHeldItemFilterFunc,
    },
    [ITEM_GENERATOR_LIMITED_POOL] =
    {
        .heldItemPool = sRandomItemOption1HeldItemPool,
        .heldItemPoolCount = ARRAY_COUNT(sRandomItemOption1HeldItemPool),
        .bannedHoldEffects = sRandomItemStandardBannedHoldEffects,
        .bannedHoldEffectsCount = ARRAY_COUNT(sRandomItemStandardBannedHoldEffects),
        .filterFunc = IsHeldItemFilterFunc,
    },
};
```
