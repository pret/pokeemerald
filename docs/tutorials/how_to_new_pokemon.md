This is a modified version of [the original tutorial about adding new Pokémon species available in Pokeemerald's wiki](https://github.com/pret/pokeemerald/wiki/How-to-add-a-new-Pokémon-species).

Despite the persistent rumors about an incredibly strong third form of Mew hiding somewhere, it actually wasn't possible to catch it... OR WAS IT?
In this tutorial, we will add a new Pokémon species to the game.

## IMPORTANT: This tutorial applies to 1.7.x versions onward.
- [v1.6.x and earlier](how_to_new_pokemon_1_6_0.md)

# Changes compared to vanilla
The main things that the Expansion changes are listed here.
* Still Front Pics *(`gMonStillFrontPic_YourPokemon`)* and by extension `src/anim_mon_front_pics.c` have been removed.
* `src/data/pokemon/cry_ids.h` doesn't exist anymore.
* You have 6 icon palettes available instead of the base 3.
* Most tables that use `SPECIES_x` as indexes have been moved to `gSpeciesInfo`.

# Content
* [Useful resources](#useful-resources)
* [The Data - Part 1](#the-data---part-1)
  * [1. Declare a species constant](#1-Declare-a-species-constant)
  * [2. `SpeciesInfo`'s structure](#2-speciesinfos-structure)
  * [3. Define its basic species information](#3-define-its-basic-species-information)
  * [4. Species Name](#4-species-name)
  * [5. Define its cry](#5-define-its-cry)
  * [6. Define its Pokédex entry](#6-define-its-pokédex-entry)
* [The Graphics](#the-graphics)
  * [1. Edit the sprites](#1-edit-the-sprites)
  * [2. Add the sprites to the rom](#2-add-the-sprites-to-the-rom)
  * [3. Add the animations to the rom](#3-add-the-animations-to-the-rom)
  * [4. Linking graphic information to our Pokémon](#4-linking-graphic-information-to-our-pokémon)
* [The Data - Part 2](#the-data---part-2)
  * [1. Species Flags](#1-species-flags)
  * [2. Delimit the moveset](#2-delimit-the-moveset)
  * [3. Define the Evolutions](#3-define-the-evolutions)
  * [4. Make it appear!](#4-make-it-appear)
* [Optional data](#optional-data)
  * [1. Form tables](#1-form-tables)
  * [2. Form change tables](#2-form-change-tables)
  * [3. Gender differences](#3-gender-differences)
  * [4. Overworld Data (v1.9 onwards)](#4-overworld-data-v19-onwards)
  * [5. In-battle shadows (v1.10 onwards)](#5-in-battle-shadows-v110-onwards)

# Useful resources
You can open a sprite debug menu by pressing `Select` in a Pokémon's summary screen outside of battle.

![visualizer1](img/add_pokemon/visualizer1.gif)

# The Data - Part 1

Our plan is as simple as it is brilliant: clone Mewtwo... and make it even stronger!

## 1. Declare a species constant

Our first step towards creating a new digital lifeform is to define its own species constant.

Edit [include/constants/species.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/species.h):

```diff
 #define SPECIES_NONE                                    0
 #define SPECIES_BULBASAUR                               1
 ...
 #define SPECIES_MIMIKYU_BUSTED_TOTEM                    1523
 #define SPECIES_MIMIKYU_TOTEM_BUSTED                    SPECIES_MIMIKYU_BUSTED_TOTEM
+#define SPECIES_MEWTHREE                                1524

-#define SPECIES_EGG                                     (SPECIES_MIMIKYU_BUSTED_TOTEM + 1)
+#define SPECIES_EGG                                     (SPECIES_MEWTHREE + 1)

 #define NUM_SPECIES SPECIES_EGG
```
This number is stored in a Pokémon's save structure. These should generally never change, otherwise your saved Pokémon species will change as well.

We add this at the end so that no existing species change Id and so that we don't have to renumber everything after it.

Now, let's see how it looks in-game!

![visualizer2](img/add_pokemon/visualizer2.png)

Hmmm, something's not right...

Oh, I know! We need to add the rest of the data! Normally, the vanilla game would crash if we try to look up anything about Mewthree in this state, but the expansion defaults all of its data to `SPECIES_NONE`.

Now, let's see what needs to be done.

## 2. `SpeciesInfo`'s structure
Now, to better understand Mewthree, we also need to understand Mew. Let's look at its data.
```c
    [SPECIES_MEW] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 64,
    #endif
        .evYield_HP = 3,
        .itemCommon = ITEM_LUM_BERRY,
        .itemRare = ITEM_LUM_BERRY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Mew"),
        .cryId = CRY_MEW,
        .natDexNum = NATIONAL_DEX_MEW,
        .categoryName = _("New Species"),
        .height = 4,
        .weight = 40,
        .description = COMPOUND_STRING(
            "A Mew is said to possess the genes of all\n"
            "Pokémon. It is capable of making itself\n"
            "invisible at will, so it entirely avoids\n"
            "notice even if it approaches people."),
        .pokemonScale = 457,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mew,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONVEX : ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 11,
        .backPic = gMonBackPic_Mew,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Mew,
        .shinyPalette = gMonShinyPalette_Mew,
        .iconSprite = gMonIcon_Mew,
        .iconPalIndex = 0,
        SHADOW(0, 13, SHADOW_SIZE_S)
        FOOTPRINT(Mew)
        OVERWORLD(
            sPicTable_Mew,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Mew,
            gShinyOverworldPalette_Mew
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMewLevelUpLearnset,
        .teachableLearnset = sMewTeachableLearnset,
    },
```

That's a lot of stuff! But don't worry, we'll go through it step by step throughout the tutorial
(and it's miles better than having this same data through 20+ files like it used to be).

Across the species files you'll see preprocessor instructions such as `#if/endif P_FAMILY_MEW`. These are used by expansion in order to allow users to disable species via config. Since we're making a new species from scratch, you DON'T need to add them as part of the process.

You can also ignore switch cases for `P_GBA_STYLE_SPECIES_GFX`, as those are only used to switching to GBA-styled sprites.

We'll start by adding the self-explanatory data that's also present in pret's vanilla structure:

## 3. Define its basic species information
Edit [src/data/pokemon/species_info.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/species_info.h):
```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     [SPECIES_NONE] = {0},
     ...

     [SPECIES_EGG] =
     {
         FRONT_PIC(Egg, 24, 24),
         .frontPicYOffset = 20,
         .backPic = gMonFrontPic_Egg,
         .backPicSize = MON_COORDS_SIZE(24, 24),
         .backPicYOffset = 20,
         .palette = gMonPalette_Egg,
         .shinyPalette = gMonPalette_Egg,
         ICON(Egg, 1),
     },

+    [SPECIES_MEWTHREE] =
+    {
+       .baseHP        = 106,
+       .baseAttack    = 150,
+       .baseDefense   = 70,
+       .baseSpeed     = 140,
+       .baseSpAttack  = 194,
+       .baseSpDefense = 120,
+       .types = MON_TYPES(TYPE_PSYCHIC),
+       .catchRate = 3,
+       .expYield = 255,
+       .evYield_SpAttack  = 3,
+       .genderRatio = MON_GENDERLESS,
+       .eggCycles = 120,
+       .friendship = 0,
+       .growthRate = GROWTH_SLOW,
+       .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
+       .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_NONE },
+       .bodyColor = BODY_COLOR_PURPLE,
+    },
 };
```

The `.` is the structure reference operator in C to refer to the member object of the structure SpeciesInfo.

- `baseHP`, `baseAttack`, `baseDefense`, `baseSpeed`, `baseSpAttack` and `baseSpDefense` are the base stats. They can't go higher than 255.
- `types` is using the macro `MON_TYPES` as a helper function for formatting so that only one type has to be input for species with a single type.
    - To add a species with 2 types, use the format `MON_TYPES(TYPE_PSYCHIC, TYPE_NORMAL)`.
    - ***1.9 and earlier:*** The format for setting types is the following:
        ```c
        // Mono-type
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        // Dual-type
        .types = { TYPE_PSYCHIC, TYPE_DARK },
        ```
- `catchRate` is how likely it is to catch a Pokémon, the lower the value, the harder it is to catch. Legendaries generally have a catch rate of 3, so we put that here.
- `expYield` is the base amount of experience that a Pokémon gives when defeated/caught. In vanilla, this value caps at 255, but we've increased it to a maximum of 65535 accomodate later gen's higher experience yields. (The highest official value is Blissey's with 608, so going beyond this point may cause exponential gains that could break the system 😱)
    - If you noticed, Mew's had some `#if`s, `#elif`s and `#endif` around it. This is because its yield has changed over time, and we let you choose which ones you want. This is not relevant to our Mewthree however, so we can just put a single `.expYield = 255,` line here.
- `evYield_HP`, `evYield_Attack`, `evYield_Defense`, `evYield_Speed`, `evYield_SpAttack` and `evYield_SpDefense` are how many EVs does the Pokémon give when they're caught. Each of these fields can have a value of 3 at most. Officially, no Pokémon give out more than 3 EVs total, with them being determined by their evolution stage (eg, Pichu, Pikachu and Raichu give 1, 2 and 3 Speed EVs respectively), and they tend to be associated with its higher stats. Since our Mewthree is a Special Attack monster, we'll be consistent and make it give out 3 Special Attack EVs, but you're always free to assign whatever you feel like :)
    - Notice that the other `evYield` fields are not there. In C, numbers in a struct default to 0, so if we don't specify them, they'll be 0 all around! Less lines to worry about :D
- `itemCommon` and `itemRare` are used to determine what items is the Pokémon holding when encountering it in the wild.
    - 50% for `itemCommon` and 5% for `itemRare` (boosted to 60%/20% when the first mon in the party has Compound Eyes or Super Luck)
    - If they're both set as the same item, the item has a 100% chance of appearing.
- `genderRatio` is a fun one.
    - There are 4 ways of handling this
        - `PERCENT_FEMALE` is what most Pokémon use, where you define how likely it's gonna be female. It supports decimals, so you can put `PERCENT_FEMALE(12.5)` to have a 1 in 8 chance of your mon to be female.
        - `MON_MALE` guarantees that all mon of this species will be male (eg. Tauros)
        - `MON_FEMALE` guarantees that all mon of this species will be female (eg. Miltank)
        - `MON_GENDERLESS` makes your species genderless, unable to breed with anything but Ditto to produce eggs. Most Legendaries are this, so we'll be chosing this as Mewthree's gender ratio.
    - When working with evolution lines and don't want their genders to change after evolving, be sure that their gender ratios match their stages and evolution methods. Azurill is the only case where there's a mismatch, causing 1/3 of all Azurill to change from Female to Male. <!--Trans rights :)-->
    - You might be wondering why some species have multiple defines for their genders, like `SPECIES_MEOWSTIC_(FE)MALE`. This is because those species have different stats and data from each other, so they're defined internally as different forms with `MON_MALE` and `MON_FEMALE` as gender ratios. If your species evolves depending on its gender and the evolutions have different stats, be sure to apply the correct evolution method!
- `eggCycles` determines how fast an egg of this species will hatch. Doesn't matter much for evolved species or those that can't lay eggs, but we add the field here just in case.
- `friendship` determines the amount of friendship of the mon when you catch it. Most Pokémon use `STANDARD_FRIENDSHIP`, but this creature of chaos does not want to be your friend, starting with 0.
- `growthRate` determines the amounts of experience required to reach each level. Go [here](https://bulbapedia.bulbagarden.net/wiki/Experience) for more info.
    - This should be consistent across evolution lines, otherwise levels could change upon evolution.
- `eggGroups` are used for breed compatibility. Most Legendaries and Mythicals have the `EGG_GROUP_NO_EGGS_DISCOVERED` group, and so does our Mewthree. Go [here](https://bulbapedia.bulbagarden.net/wiki/Egg_Group) for more info.
    - This is using the helper macro `MON_EGG_GROUPS`.
    - ***1.9 and earlier:*** The format for setting egg groups is the following:
        ```c
        // Mono-group
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        // Dual-group
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MINERAL },
        ```
- `abilities` determines the potential abilites of our species. Notice how I also set the ability to `ABILITY_INSOMNIA`, so our little monster doesn't even need to sleep anymore. You can find the abilities for example here [include/constants/abilities.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/abilities.h).
    - When both slot 1 and 2 are defined as not being `ABILITY_NONE`, their starting ability will be decided on a coin flip using their personality. They can later be changed using an Ability Capsule.
        - Certain Pokémon such as Zygarde and Rockruff have different forms to add additional abilities. As such, they cannot be changed using an Ability Capsule (though the Zygarde Cube can change Zygarde's ability by changing them to their corresponding form)
    - The 3rd slot is for Hidden Abilities. If defined as `ABILITY_NONE`, it will default to Slot 1 (eg. Metapod doesn't have a Hidden Ability, but Caterpie and Butterfree do). Go [here](https://bulbapedia.bulbagarden.net/wiki/Ability#Hidden_Abilities) and [here](https://bulbapedia.bulbagarden.net/wiki/Ability_Patch) for more info.
        - If the array is defined as `{ABILITY_1, ABILITY_2}`, the Hidden Ability is set as `ABILITY_NONE`.
- `bodyColor` is used in the Pokédex as a search filter.
- `noFlip` is used in to prevent front sprites from being flipped horizontally and cause weird issues, like Clawitzer's big claw changing sides.

That's all the basic fields present in vanilla emerald, so now let's take a look at the new fields added by the expansion.

## 4. Species Name

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        .bodyColor = BODY_COLOR_PURPLE,
+       .speciesName = _("Mewthree"),
    },
 };
```
The `_()` underscore function doesn't really exist - it's a convention borrowed from GNU gettext to let `preproc` know this is text to be converted to the custom encoding used by the Gen 3 Pokemon games.

## 5. Define its cry

Time for audio!
We first need to convert an existing audio file to the format supported by the expansion.

Most formats are supported for conversion, but for simplicity's sake, we're gonna use an mp3 file.

Now, let's copy the file to the `sound/direct_sound_samples/cries` folder.
Once that's done, let's run the following command:
```
ffmpeg -i sound/direct_sound_samples/cries/mewthree.mp3 -c:a pcm_u8 -ac 1 -ar 13379 sound/direct_sound_samples/cries/mewthree.wav
```
This will convert your audio file to .wav, which is what's read by the compiler.

Let's add the cry to the ROM via [sound/direct_sound_data.inc](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/sound/direct_sound_data.inc).

```diff
.if P_FAMILY_PECHARUNT == TRUE
	.align 2
Cry_Pecharunt::
	.incbin "sound/direct_sound_samples/cries/pecharunt.bin"
.endif @ P_FAMILY_PECHARUNT

+	.align 2
+Cry_Mewthree::
+	.incbin "sound/direct_sound_samples/cries/mewthree.bin"

```

Then we add the cry ID to [include/constants/cries.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/cries.h):

```diff
enum PokemonCry
{
    CRY_NONE,
    ...
#if P_FAMILY_TERAPAGOS
    CRY_TERAPAGOS,
#endif //P_FAMILY_TERAPAGOS
#if P_FAMILY_PECHARUNT
    CRY_PECHARUNT,
#endif //P_FAMILY_PECHARUNT
+   CRY_MEWTHREE,
    CRY_COUNT,
};
```

And then link it in [sound/cry_tables.inc](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/sound/cry_tables.inc). `cry_reverse` in particular is for reversed cries used by moves such as Growl. The order of these two tables should match the order of the cry IDs, otherwise they'll be shifted.

```diff
	cry Cry_Terapagos
	cry Cry_Pecharunt
+	cry Cry_Mewthree
```
```diff
	cry_reverse Cry_Terapagos
	cry_reverse Cry_Pecharunt
+	cry_reverse Cry_Mewthree
```

Lastly, we add the cry to our species entry
```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        .speciesName = _("Mewthree"),
+       .cryId = CRY_MEWTHREE,
    },
 };
```

And let's see how it sounds in-game:

https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/4f7667db-4db9-4bfd-a8dd-ece26f09f327

Good! Our monster now has a mighty roar!

You can now delete the mp3 from the cries folder now once you made sure that the cry sounds like how you want it to.

## 6. Define its Pokédex entry

First, we will need to add new index constants for its Pokédex entry. The index constants are divided into the Hoenn Pokédex, which contains all Pokémon native to the Hoenn region, and the National Pokédex containing all known Pokémon, which can be received after entering the hall of fame for the first time.

Edit [include/constants/pokedex.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/pokedex.h):

```diff
// National Pokedex order
enum NationalDexOrder
{
    NATIONAL_DEX_NONE,
    // Kanto
    NATIONAL_DEX_BULBASAUR,
...
    NATIONAL_DEX_PECHARUNT,
+   NATIONAL_DEX_MEWTHREE,
};
```

```diff
 #define KANTO_DEX_COUNT     NATIONAL_DEX_MEW
 #define JOHTO_DEX_COUNT     NATIONAL_DEX_CELEBI

#if P_GEN_9_POKEMON == TRUE
-   #define NATIONAL_DEX_COUNT  NATIONAL_DEX_PECHARUNT
+   #define NATIONAL_DEX_COUNT  NATIONAL_DEX_MEWTHREE
```

Do keep in mind that if you intend to add your new species to the Hoenn Dex, you'll also want to add a `HOENN_DEX` constant for it and give it a `HOENN_TO_NATIONAL` member, like this:

```diff
// Hoenn Pokedex order
enum HoennDexOrder
{
    HOENN_DEX_NONE,
    HOENN_DEX_TREECKO,
...
    HOENN_DEX_DEOXYS,
+   HOENN_DEX_MEWTHREE,
};

- #define HOENN_DEX_COUNT (HOENN_DEX_DEOXYS + 1)
+ #define HOENN_DEX_COUNT (HOENN_DEX_MEWTHREE + 1)
```

Edit [src/pokemon.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/pokemon.c):

```diff
 const u16 sHoennToNationalOrder[NUM_SPECIES] = // Assigns Hoenn Dex Pokémon (Using National Dex Index)
 {
     HOENN_TO_NATIONAL(TREECKO),
     ...
     HOENN_TO_NATIONAL(DEOXYS),
+    HOENN_TO_NATIONAL(MEWTHREE),
 };
```

Now we can add the number and entry to our Mewthree:
```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        .cryId = CRY_MEWTHREE,
+       .natDexNum = NATIONAL_DEX_MEWTHREE,
+       .categoryName = _("New Species"),
+       .height = 15,
+       .weight = 330,
+       .description = COMPOUND_STRING(
+           "The rumors became true.\n"
+           "This is Mew's final form.\n"
+           "Its power level is over 9000.\n"
+           "Has science gone too far?"),
+       .pokemonScale = 256,
+       .pokemonOffset = 0,
+       .trainerScale = 290,
+       .trainerOffset = 2,
    },
 };
```
![image](img/add_pokemon/dex1.png)

The values `pokemonScale`, `pokemonOffset`, `trainerScale` and `trainerOffset` are used for the height comparison figure in the Pokédex.

`height` and `weight` are specified in decimeters and hectograms respectively (which are meters and kilograms multiplied by 10, so 2.5 meters are 25 decimeters).

In Pokémon Emerald, you can sort the Pokédex by name, height or weight. Apparently, the Pokémon order is hardcoded in the game files and not calculated from their data. Therefore we have to include our new Pokémon species at the right places. While the correct position for the alphabetical order is easy to find, it can become quite tedious for height and weight, so we added comments to the listings in order help out were they should fit.

Edit [src/data/pokemon/pokedex_orders.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/pokedex_orders.h):

```diff
 const u16 gPokedexOrder_Alphabetical[] =
 {
     ...
     NATIONAL_DEX_MEW,
+    NATIONAL_DEX_MEWTHREE,
     NATIONAL_DEX_MEWTWO,
     ...
 };

 const u16 gPokedexOrder_Weight[] =
 {
     ...
     // 72.8 lbs / 33.0 kg
     //NATIONAL_DEX_MEWTWO_MEGA_Y,
     NATIONAL_DEX_ESCAVALIER,
     NATIONAL_DEX_FRILLISH,
     NATIONAL_DEX_DURANT,
     NATIONAL_DEX_CINDERACE,
+    NATIONAL_DEX_MEWTHREE,
     //NATIONAL_DEX_PERSIAN_ALOLAN,
     NATIONAL_DEX_TOEDSCOOL,
     // 73.4 lbs / 33.3 kg
     NATIONAL_DEX_DUGTRIO,
     ...
 };

 const u16 gPokedexOrder_Height[] =
 {
     ...
     // 4'11" / 1.5m
     ...
     NATIONAL_DEX_GLIMMORA,
     NATIONAL_DEX_WO_CHIEN,
     NATIONAL_DEX_IRON_LEAVES,
     NATIONAL_DEX_IRON_BOULDER,
+    NATIONAL_DEX_MEWTHREE,
    // 5'03" / 1.6m
     ...
 };
```
![mGBA_lUBfmFEKUx](img/add_pokemon/dex2.gif)


# The Graphics
We will start by copying the following files for *Mew* (not Mewtwo) and rename it to `mewthree`.
```sh
cp -r graphics/pokemon/mew/. graphics/pokemon/mewthree
```
We aren't copying Mewtwo's folder because he has those pesky Mega Evolutions that will get in the way of what we're doing, so our sample will need to be pure from the source.

## 1. Edit the sprites
Let's edit the sprites. Start your favourite image editor (I recommend Aseprite or its free alternative, Libresprite) and change `anim_front.png` and `back.png` to meet your expectations.

__Make sure that you are using the indexed mode and you have limited yourself to 15 colors!__

Put the RGB values of your colors into `normal.pal` between the first and the last color and the RGB values for the shiny version into `shiny.pal`.
Edit `footprint.png` using two colors in indexed mode, black and white.
Finally, edit `icon.png`.
**Note**: the icon will use one of 6 predefined palettes instead of `normal.pal`.
Open an icon sprite and load one of the palettes to find out which palette suits your icon sprite best.

## 2. Add the sprites to the rom
Sadly, just putting the image files into the graphics folder is not enough. To use the sprites we have to register them, which is kind of tedious.
First, create constants for the file paths. You'll want to add the constants for your species after the constants for the last valid species.

Edit [src/data/graphics/pokemon.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/pokemon.h):

```diff
#if P_FAMILY_PECHARUNT
    const u32 gMonFrontPic_Pecharunt[] = INCGFX_U32("graphics/pokemon/pecharunt/front.png", ".4bpp.lz");
    const u16 gMonPalette_Pecharunt[] = INCGFX_U16("graphics/pokemon/pecharunt/normal.pal", ".gbapal");
    const u32 gMonBackPic_Pecharunt[] = INCGFX_U32("graphics/pokemon/pecharunt/back.png", ".4bpp.lz");
    const u16 gMonShinyPalette_Pecharunt[] = INCGFX_U16("graphics/pokemon/pecharunt/shiny.pal", ".gbapal");
    const u8 gMonIcon_Pecharunt[] = INCGFX_U8("graphics/pokemon/pecharunt/icon.png", ".4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pecharunt[] = INCGFX_U8("graphics/pokemon/pecharunt/footprint.png", ".1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pecharunt[] = INCGFX_COMP("graphics/pokemon/pecharunt/overworld.png", ".4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u16 gOverworldPalette_Pecharunt[] = INCGFX_U16("graphics/pokemon/pecharunt/overworld_normal.pal", ".gbapal");
    const u16 gShinyOverworldPalette_Pecharunt[] = INCGFX_U16("graphics/pokemon/pecharunt/overworld_shiny.pal", ".gbapal");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PECHARUNT

    const u32 gMonFrontPic_Egg[] = INCGFX_U32("graphics/pokemon/egg/anim_front.png", ".4bpp.lz");
    const u16 gMonPalette_Egg[] = INCGFX_U16("graphics/pokemon/egg/normal.pal", ".gbapal");
    const u8 gMonIcon_Egg[] = INCGFX_U8("graphics/pokemon/egg/icon.png", ".4bpp");

+   const u32 gMonFrontPic_Mewthree[] = INCGFX_U32("graphics/pokemon/mewthree/anim_front.png", ".4bpp.lz");
+   const u32 gMonBackPic_Mewthree[] = INCGFX_U32("graphics/pokemon/mewthree/back.png", ".4bpp.lz");
+   const u16 gMonPalette_Mewthree[] = INCGFX_U16("graphics/pokemon/mewthree/normal.pal", ".gbapal");
+   const u16 gMonShinyPalette_Mewthree[] = INCGFX_U16("graphics/pokemon/mewthree/shiny.pal", ".gbapal");
+   const u8 gMonIcon_Mewthree[] = INCGFX_U8("graphics/pokemon/mewthree/icon.png", ".4bpp");
+   const u8 gMonFootprint_Mewthree[] = INCGFX_U8("graphics/pokemon/mewthree/footprint.png", ".1bpp");
```

Please note that Pecharunt, the Pokémon that should be above your insertion for the time being, reads a `front.png` sprite instead of an `anim_front.png` sprite. This is because currently, Pecharunt lacks a 2nd frame. If the front sprite sheet of your species uses 2 frames, you should use `anim_front`.

## 3. Add the animations to the rom

You can define the animation order, in which the sprites will be shown. The first number is the sprite index (so 0 or 1) and the second number is the number of frames the sprite will be visible.

### Version 1.11.0 or later
We add this data directly to the entry, so go to section 4.

### Version 1.10.3 or earlier
Edit [src/data/pokemon_graphics/front_pic_anims.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/front_pic_anims.h):

```diff
#if P_FAMILY_PECHARUNT
PLACEHOLDER_ANIM_SINGLE_FRAME(Pecharunt);
#endif //P_FAMILY_PECHARUNT

+static const union AnimCmd sAnim_Mewthree_1[] =
+{
+    ANIMCMD_FRAME(1, 30),
+    ANIMCMD_FRAME(0, 20),
+    ANIMCMD_END,
+};
```

```diff
#if P_FAMILY_PECHARUNT
SINGLE_ANIMATION(Pecharunt);
#endif //P_FAMILY_PECHARUNT
+SINGLE_ANIMATION(Mewthree);
SINGLE_ANIMATION(Egg);
```

You might be wondering what `PLACEHOLDER_ANIM_SINGLE_FRAME` is. Well, since Pecharun only has 1 frame, we use what's called a preprocessor *macro* to have in a single line what otherwise would've been this in the C file:
```c
static const union AnimCmd sAnim_Pecharunt_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
}
```
Instead, we can use the already established macro that does the same thing, replacing the value in parenthesis with what we want (in this case, `Pecharunt`):
```c
#define PLACEHOLDER_ANIM_SINGLE_FRAME(name)     \
static const union AnimCmd sAnim_##name##_1[] = \
{                                               \
    ANIMCMD_FRAME(0, 1),                        \
    ANIMCMD_END,                                \
}
```

## 4. Linking graphic information to our Pokémon
Now that we have all the external data ready, we just need to add it to `gSpeciesInfo` plus the rest of the animation and graphical data that we want to use:

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
+       .frontPic = gMonFrontPic_Mewthree,
+       .frontPicSize = MON_COORDS_SIZE(64, 64),
+       .frontPicYOffset = 0,
+       .frontAnimFrames = ANIM_FRAMES(
+           ANIMCMD_FRAME(0, 1),
+       ),
+       .frontAnimId = ANIM_GROW_VIBRATE,
+       .frontAnimDelay = 15,
+       .enemyMonElevation = 6,
+       .backPic = gMonBackPic_Mewthree,
+       .backPicSize = MON_COORDS_SIZE(64, 64),
+       .backPicYOffset = 0,
+       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
+       .palette = gMonPalette_Mewthree,
+       .shinyPalette = gMonShinyPalette_Mewthree,
        .iconSprite = gMonIcon_Mewthree,
        .iconPalIndex = 2,
+       FOOTPRINT(Mewthree)
    },
 };
```
Let's explain each of these:
- `frontPic`:
    - Used to reference the front sprite, so in this case, we call for `gMonFrontPic_Mewthree`.
- `frontPicSize`:
    - The two values (`width` and `height`) are used for defining the non-empty size of the front sprite, which is used in move animations. If you're unsure of the values, you can leave them both as 64.
- `frontPicYOffset`:
    - Used to define what Y position the sprite sits at. This is used to set where they'd be "grounded". For the shadow, see `enemyMonElevation`.
- `frontAnimFrames`:
    - We define our animation frame animations directly here. In version `1.10.3 and earlier`, we add the reference to the table that we defined earlier here like this instead:
        ```diff
        +       .frontAnimFrames = sAnims_Mewthree,
        ```
- `frontAnimId`:
    - Because you are limited to two frames, there are already [predefined front sprite animations](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/pokemon_animation.h), describing translations, rotations, scalings or color changes.
- `frontAnimDelay`:
    - Sets a delay in frame count between when the Pokémon appears and when the animation starts.
- `enemyMonElevation`:
    - Used to determine the altitude from the ground. Any value above 0 will show a shadow under the Pokémon, to signify that they're floating.
- `backPic`:
    - Used to reference the back sprite, so in this case, we call for `gMonBackPic_Mewthree`.
- `backPicSize`:
    - The two values (`width` and `height`) are used for defining the non-empty size of the back sprite, which is used in move animations. If you're unsure of the values, you can leave them both as 64.
    - **NOTE**: Mew has a ternary switch here in order to change values depending on if a config option is set for displaying the original Gen 3 sprites.
- `backPicYOffset`:
    - Used to define what Y position of the back sprite. When working with the animation debug menu, we recommend aligning the back sprite to the white background, as it was designed to properyly align with the real battle layout.
- `backAnimId`:
    - Like `frontAnimId` except for the back sprites and them being a single frame. The IDs listed [here](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/pokemon_animation.h) are used to represent 3 different animations that happen based on the the Pokémon's nature.
- `palette`:
    - Used to reference the non-shiny palette, so in this case, we call for `gMonPalette_Mewthree`.
- `shinyPalette`:
    - Used to reference the shiny palette, so in this case, we call for `gMonShinyPalette_Mewthree`.
- `iconSprite`:
    - Used to reference the icon sprite, so in this case, we call for `gMonIcon_Mewthree`.
- `iconPalIndex`:
    - Here, you can choose between the six icon palettes; 0, 1, 2, 3, 4 and 5. All of them located in `graphics/pokemon/icon_palettes`.
- `FOOTPRINT`
    - We made this single field into a macro so that they can be ignored when `P_FOOTPRINTS` is set to false. It's also why we don't have an "," after calling it like the other macros (we add it as part of the macro itself).
        ```c
        #if P_FOOTPRINTS
        #define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
        #else
        #define FOOTPRINT(sprite)
        #endif
        ```

***NOTE:** In v1.7.x only, there were macros that set multiple of these fields. However, they were considered clunky to use, so they were removed in v1.8.
    - `FRONT_PIC`: For `frontPic` and `frontPicSize`.
    - `BACK_PIC`: For `backPic` and `backPicSize`.
    - `PALETTES`: For `palette` and `shinyPalette`.
    - `ICON`: For `iconSprite` and `iconPalIndex`.

# The Data - Part 2

We're almost there just a bit left!

## 1. Species Flags

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
+       .isRestrictedLegendary = TRUE,
+       .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
    },
 };
```
Each species flag provides properties to the species:
- `perfectIVCount` ***(1.10 onwards)***:
    - Guarantees that the number of IVs specified here will be perfect.
- `isRestrictedLegendary`:
    - ***1.14.3 onwards:*** Does nothing.
- `isSubLegendary`:
    - ***1.14.3 onwards:*** Does nothing.
- `isMythical`:
    - Is skipped during Pokédex evaluations.
        - Unless it also has the `dexForceRequired` flag.
    - Cannot obtain Gigantamax factor via `ToggleGigantamaxFactor`.
    - ***1.9 and earlier:*** Guaranteed 3 perfect IVs for the species.
- `isUltraBeast`:
    - Beast Ball's multiplier is set to x5 for this species.
        - All other ball multipliers are set to x0.1.
    - ***1.9 and earlier:*** Guaranteed 3 perfect IVs for the species.
- `isParadox` (`isParadoxForm` previous to 1.9):
    - ***1.10 onwards:*** Makes it so that Booster Energy cannot be knocked off.
    - ***1.9 and earlier:*** Does nothing.
- `isTotem`:
    - ***1.10 onwards:*** Does nothing.
    - ***1.9 and earlier:*** Guaranteed 3 perfect IVs for the species.
- `isMegaEvolution`:
    - A Mega indicator is added to the battle box indicating that they're Mega Evolved.
    - The species doesn't receive affection benefits.
    - Required when adding new Mega Evolutions.
- `isPrimalReversion`:
    - A Primal Reversion indicator (Alpha or Omega for Kyogre/Groudon respectively) is added to the battle box indicating that they're Primal Reverted.
    - Required when adding new Primal Reversions.
- `isUltraBurst`:
    - Required when adding new Ultra Burst forms.
- `isGigantamax`:
    - Used to determine if Gigantamax forms should have their GMax moves or not.
    - Required when adding new Gigantamax forms.
- `isAlolanForm`, `isGalarianForm`, `isHisuianForm`, `isPaldeanForm`:
    - **1.10.3 onwards:** Used to determine breeding offspring from different parents based on their region.
    - **1.10.2 and earlier:** Does nothing.
- `cannotBeTraded`:
    - This species cannot be traded away (like Black/White Kyurem).
- `tmIlliterate`:
    - This species will be unable to learn the universal TM or Tutor moves.
- `isFrontierBanned` ***(1.9 onwards)***:
    - This species will be unable to enter Battle Frontier facilities. Replaces `gFrontierBannedSpecies`.

## 2. Delimit the moveset

Let's begin with the moves that can be learned by leveling up.

Append to [src/data/pokemon/level_up_learnsets/gen_9.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/level_up_learnsets/gen_9.h):
**NOTE**: You can ignore the warning at the top of the file if you're just adding moves to Pokemon.

```diff
#if P_FAMILY_PECHARUNT
static const struct LevelUpMove sPecharuntLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_SMOG),
    LEVEL_UP_MOVE( 1, MOVE_POISON_GAS),
    LEVEL_UP_MOVE( 1, MOVE_MEMENTO),
    LEVEL_UP_MOVE( 1, MOVE_ASTONISH),
    LEVEL_UP_MOVE( 8, MOVE_WITHDRAW),
    LEVEL_UP_MOVE(16, MOVE_DESTINY_BOND),
    LEVEL_UP_MOVE(24, MOVE_FAKE_TEARS),
    LEVEL_UP_MOVE(32, MOVE_PARTING_SHOT),
    LEVEL_UP_MOVE(40, MOVE_SHADOW_BALL),
    LEVEL_UP_MOVE(48, MOVE_MALIGNANT_CHAIN),
    LEVEL_UP_MOVE(56, MOVE_TOXIC),
    LEVEL_UP_MOVE(64, MOVE_NASTY_PLOT),
    LEVEL_UP_MOVE(72, MOVE_RECOVER),
    LEVEL_UP_END
};
#endif

+static const struct LevelUpMove sMewthreeLevelUpLearnset[] = {
+   LEVEL_UP_MOVE( 1, MOVE_CONFUSION),
+   LEVEL_UP_MOVE( 1, MOVE_DISABLE),
+   LEVEL_UP_MOVE(11, MOVE_BARRIER),
+   LEVEL_UP_MOVE(22, MOVE_SWIFT),
+   LEVEL_UP_MOVE(33, MOVE_PSYCH_UP),
+   LEVEL_UP_MOVE(44, MOVE_FUTURE_SIGHT),
+   LEVEL_UP_MOVE(55, MOVE_MIST),
+   LEVEL_UP_MOVE(66, MOVE_PSYCHIC),
+   LEVEL_UP_MOVE(77, MOVE_AMNESIA),
+   LEVEL_UP_MOVE(88, MOVE_RECOVER),
+   LEVEL_UP_MOVE(99, MOVE_SAFEGUARD),
+   LEVEL_UP_END
+};
```
**NOTE**: If `P_LVL_UP_LEARNSETS` is not set to something equal to `GEN_9`, the file to be edited will change to what's specified.

Again, we need to register the learnset in `gSpeciesInfo`:

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        .palette = gMonPalette_Mewthree,
        .shinyPalette = gMonShinyPalette_Mewthree,
        .iconSprite = gMonIcon_Mewthree,
        .iconPalIndex = 2,
+       .levelUpLearnset = sMewthreeLevelUpLearnset,
    },
 };
```

Next we need to specify which moves can be taught via TM, HM, or Move Tutor.

Those are defined in [src/data/pokemon/teachable_learnsets.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/teachable_learnsets.h). This file is automatically generated by default and you can read the details of how this works in this [doc](tutorials/how_to_trainer_front_pic.md)
but let's go through the basics.

If you open [src/data/pokemon/all_learnables.json](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/tall_learnables.json), you will see list of moves associated with every species, the order doesn't matter so let's add Mewthree moves at the top.
```diff
{
+  "MEWTHREE": [
+    MOVE_FOCUS_PUNCH,
+    MOVE_WATER_PULSE,
+    MOVE_CALM_MIND,
+    MOVE_TOXIC
+  ],
  "PINCURCHIN": [
  ...
```
When compiling, the game will look at the moves and cross-references with the tutor and TM moves available in your game to generate the final list (so you don't need to worry about putting a move there is no way to learn in your game).

While this is not recommended, you can also disable the learnset helper that generates [src/data/pokemon/teachable_learnsets.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/teachable_learnsets.h) and edit the file yourself. First change the config in `include/config/pokemon.h`:
```
// Learnset helper toggles
#define P_LEARNSET_HELPER_TEACHABLE TRUE        // If TRUE, teachable_learnsets.h will be populated by tools/learnset_helpers/teachable.py using the included JSON files based on available TMs and tutors.
```

so that your manual changes are not overwritten then you can update the file

```diff
#if P_FAMILY_PECHARUNT
static const u16 sPecharuntTeachableLearnset[] = {
    ...
    MOVE_UNAVAILABLE,
};
#endif //P_FAMILY_PECHARUNT

+static const u16 sMewthreeTeachableLearnset[] = {
+   MOVE_FOCUS_PUNCH,
+   MOVE_WATER_PULSE,
+   MOVE_CALM_MIND,
+   MOVE_TOXIC,
+   MOVE_UNAVAILABLE, // This is required to determine where the array ends.
+};
```

Once more, we also need to register the learnset in `gSpeciesInfo`:

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        FOOTPRINT(Mewthree)
        .levelUpLearnset = sMewthreeLevelUpLearnset,
+       .teachableLearnset = sMewthreeTeachableLearnset,
    },
 };
```

If you want to create a Pokémon which can breed, you will need to edit [src/data/pokemon/egg_moves.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/egg_moves.h).


## 3. Define the Evolutions

We want Mewthree to evolve from Mewtwo by reaching level 100.

Edit `gSpeciesInfo`:

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTWO] =
     {
        ...
        FOOTPRINT(Mewtwo)
        .isRestrictedLegendary = TRUE,
        .levelUpLearnset = sMewtwoLevelUpLearnset,
        .teachableLearnset = sMewtwoTeachableLearnset,
        .formSpeciesIdTable = sMewtwoFormSpeciesIdTable,
        .formChangeTable = sMewtwoFormChangeTable,
+       .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_MEWTHREE}),
    },
 };
```

## 4. Make it appear!
Now Mewthree really does slumber in the games code - but we won't know until we make him appear somewhere! The legend tells that Mewthree is hiding somewhere in Petalburg Woods...

Edit [src/data/wild_encounters.json](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/wild_encounters.json):

```diff
         {
           "map": "MAP_PETALBURG_WOODS",
           "base_label": "gPetalburgWoods",
           "land_mons": {
             "encounter_rate": 20,
             "mons": [
               {
                 "min_level": 5,
                 "max_level": 5,
                 "species": "SPECIES_POOCHYENA"
               },
               {
                 "min_level": 5,
                 "max_level": 5,
                 "species": "SPECIES_WURMPLE"
               },
               {
                 "min_level": 5,
                 "max_level": 5,
                 "species": "SPECIES_SHROOMISH"
               },
               {
-                "min_level": 6,
-                "max_level": 6,
-                "species": "SPECIES_POOCHYENA"
+                "min_level": 5,
+                "max_level": 5,
+                "species": "SPECIES_MEWTHREE"
               },
               ...
        }
```

Congratulations, you have created your own personal pocket monster! You may call yourself a mad scientist now.

# Optional data

Now that you now have all the essential pieces to create a base species, there are some aspects that you might want to know if you want to do other stuff with your custom Pokémon.

## 1. Form tables
Found in `src/data/pokemon/form_species_tables.h`.

These are introduced to have a reference of what forms correspond to what Species of Pokémon. For example, we have Pikachu's table:
```c
#if P_FAMILY_PIKACHU
static const u16 sPikachuFormSpeciesIdTable[] = {
    SPECIES_PIKACHU,
    SPECIES_PIKACHU_COSPLAY,
    SPECIES_PIKACHU_ROCK_STAR,
    SPECIES_PIKACHU_BELLE,
    SPECIES_PIKACHU_POP_STAR,
    SPECIES_PIKACHU_PH_D,
    SPECIES_PIKACHU_LIBRE,
    SPECIES_PIKACHU_ORIGINAL_CAP,
    SPECIES_PIKACHU_HOENN_CAP,
    SPECIES_PIKACHU_SINNOH_CAP,
    SPECIES_PIKACHU_UNOVA_CAP,
    SPECIES_PIKACHU_KALOS_CAP,
    SPECIES_PIKACHU_ALOLA_CAP,
    SPECIES_PIKACHU_PARTNER_CAP,
    SPECIES_PIKACHU_WORLD_CAP,
    FORM_SPECIES_END,
};
#endif //P_FAMILY_PIKACHU
```
We register the table for each form in `gSpeciesInfo`.

```diff
    [SPECIES_PIKACHU] =
    {
        ...
        .teachableLearnset = sPikachuTeachableLearnset,
+       .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_RAICHU},
                                {EVO_NONE, 0, SPECIES_RAICHU_ALOLAN}),
    },

    [SPECIES_PIKACHU_COSPLAY] =
    {
        ...
        .teachableLearnset = sPikachuTeachableLearnset,
+       .formSpeciesIdTable = sPikachuFormSpeciesIdTable,
    },
```
...and so on.

What this allows us to do is to be able to get all forms of a Pokémon in our code by using the `GetSpeciesFormTable` function.

For example, in the HGSS dex, it lets us browse between the entries of every form available.:

![hgssdex1](img/add_pokemon/hgssdex1.png) ![image](img/add_pokemon/hgssdex2.png)

In addition, we have the `GET_BASE_SPECIES_ID` macro, which returns the first entry of the table (or return the species itself if it doesn't have a table registered). With this, you can check if a Pokémon is any form of a species. For example, making it so that the Light Ball affects all Pikachu forms:
```c
    case HOLD_EFFECT_LIGHT_BALL:
        if (GET_BASE_SPECIES_ID(gBattleMons[battlerAtk].species) == SPECIES_PIKACHU && IS_MOVE_SPECIAL(move))
            modifier = uq4_12_multiply_half_down(modifier, UQ_4_12(2.0));
        break;
```

## 2. Form change tables
Found in `src/data/pokemon/form_species_tables.h`.

These tables, unlike the regular form tables, registers how Pokémon can switch between forms.

```c
#if P_FAMILY_GASTLY
static const struct FormChange sGengarFormChangeTable[] =
{
    {FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM, SPECIES_GENGAR_MEGA, ITEM_GENGARITE},
    {FORM_CHANGE_BATTLE_GIGANTAMAX,          SPECIES_GENGAR_GIGANTAMAX},
    {FORM_CHANGE_TERMINATOR},
};
#endif //P_FAMILY_GASTLY
```
The first value is the type of form change. In the case of Gengar, we have both Mega Evolution and Gigantamax form changes.

The second value is the target form, to which the Pokémon will change into.

Values after that are referred as arguments, and needs to be put there depends on the type of form change, detailed in `include/constants/form_change_types.h`.

## 3. Gender differences
![gender_diffs](img/add_pokemon/gender_diffs.gif)

You may have seen that there's a couple of duplicate fields with a "Female" suffix.
```diff
    [SPECIES_FRILLISH] =
    {
        ...
        .frontPic = gMonFrontPic_Frillish,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_RISING_WOBBLE,
        .backPic = gMonBackPic_Frillish,
        .backPicSize = MON_COORDS_SIZE(40, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Frillish,
        .shinyPalette = gMonShinyPalette_Frillish,
        .iconSprite = gMonIcon_Frillish,
        .iconPalIndex = 0,
+#if P_GENDER_DIFFERENCES
+       .frontPicFemale = gMonFrontPic_FrillishF,
+       .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
+       .backPicFemale = gMonBackPic_FrillishF,
+       .backPicSizeFemale = MON_COORDS_SIZE(40, 56),
+       .paletteFemale = gMonPalette_FrillishF,
+       .shinyPaletteFemale = gMonShinyPalette_FrillishF,
+       .iconSpriteFemale = gMonIcon_FrillishF,
+       .iconPalIndexFemale = 1,
+#endif //P_GENDER_DIFFERENCES
        FOOTPRINT(Frillish)
        .levelUpLearnset = sFrillishLevelUpLearnset,
        .teachableLearnset = sFrillishTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_JELLICENT}),
    },
```
These are used to change the graphics of the Pokémon if they're female. If they're not registered, they default to the male values.

However, `iconPalIndexFemale` is a special case, where it's *doesn't* read the male icon palette if its `iconSpriteFemale` is set, so if you're setting a female icon, be sure to set their palette index as well.

## 4. Overworld Data (v1.9 onwards)
If you have `OW_POKEMON_OBJECT_EVENTS` in your hack, you can add Overworld sprite data of your new species. Naturally, these can also be used for followers.

First, since you copied the contents from Mew's folder previously, you should also have copied its overworld sprites. Edit those to your liking, as we have done before, making sure to update the palettes

Secondly, in [src/data/graphics/pokemon.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/pokemon.h), add the following:

```diff
    const u8 gMonIcon_Mewthree[] = INCGFX_U8("graphics/pokemon/mewthree/icon.png", ".4bpp");
    const u8 gMonFootprint_Mewthree[] = INCGFX_U8("graphics/pokemon/mewthree/footprint.png", ".1bpp");
+   const u32 gObjectEventPic_Mewthree[] = INCGFX_COMP("graphics/pokemon/mewthree/overworld.png", ".4bpp");
+   const u32 gOverworldPalette_Mewthree[] = INCGFX_U32("graphics/pokemon/mewthree/overworld_normal.pal", ".gbapal");
+   const u32 gShinyOverworldPalette_Mewthree[] = INCGFX_U32("graphics/pokemon/mewthree/overworld_shiny.pal", ".gbapal");
```

Thirdly, in [src/data/object_events/object_event_pic_tables_followers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/object_events/object_event_pic_tables_followers.h):
```diff
#if P_FAMILY_PECHARUNT
/*static const struct SpriteFrameImage sPicTable_Pecharunt[] = {
    overworld_ascending_frames(gObjectEventPic_Pecharunt, 4, 4),
};*/
#endif //P_FAMILY_PECHARUNT

+static const struct SpriteFrameImage sPicTable_Mewthree[] = {
+    overworld_ascending_frames(gObjectEventPic_Mewthree, 4, 4),
+};
```

And finally, in `gSpeciesInfo`:

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     {
        ...
        FOOTPRINT(Mewthree)
+       OVERWORLD(
+           sPicTable_Mewthree,
+           SIZE_32x32,
+           SHADOW_SIZE_M,
+           TRACKS_FOOT,
+           sAnimTable_Following,
+           gOverworldPalette_Mewthree,
+           gShinyOverworldPalette_Mewthree
+       )
        .levelUpLearnset = sMewthreeLevelUpLearnset,
        .teachableLearnset = sMewthreeTeachableLearnset,
    },
 };
```
**Note: In versions previous to 1.11, `sAnimTable_Following` is not added here.**

### Sprite Size
Depending on your species, you might want to use different sizes for it. For example, certain species known for being big like Steelix use sprites that fit a 64x64 frame instead of 32x32, and as such have `SIZE_64x64` in their data instead of `SIZE_32x32` to accomodate for them.

Also, in `spritesheet_rules.mk`, `-mwidth` and `-mheight` need to be set to 8 instead of 4 for such cases.

### Shadows
You have 4 options for their shadow, between Small, Medium, Large and None:
 - `SHADOW_SIZE_NONE`
 - `SHADOW_SIZE_S` ![shadow_small](/graphics/field_effects/pics/shadow_small.png)
 - `SHADOW_SIZE_M` ![shadow_medium](/graphics/field_effects/pics/shadow_medium.png)
 - `SHADOW_SIZE_L` ![shadow_large](/graphics/field_effects/pics/shadow_large.png)

### Tracks
You have 4 options for the tracks that your species will leave behind on sand.
 - `TRACKS_NONE`
 - `TRACKS_FOOT` ![sand_footprints](/graphics/field_effects/pics/sand_footprints.png)
 - `TRACKS_SLITHER` ![slither_tracks](/graphics/field_effects/pics/slither_tracks.png)
 - `TRACKS_SPOT` ![spot_tracks](/graphics/field_effects/pics/spot_tracks.png)
 - `TRACKS_BUG` ![bug_tracks](/graphics/field_effects/pics/bug_tracks.png)

 ...though technically you can also use `TRACKS_BIKE_TIRE` if you wish to.

![bike_tire_tracks](/graphics/field_effects/pics/bike_tire_tracks.png)

### Asymmetric sprites (Version 1.10.0 onwards)

![scovillain](/graphics/pokemon/scovillain/overworld.png)

You can set up an east-west asymetric overworld sprite by adding the East frames at the end of the sheet and changing the following:

#### Version 1.11.0 onwards
```diff
        OVERWORLD(
            sPicTable_Mewthree,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
-           sAnimTable_Following,
+           sAnimTable_Following_Asym,
            gOverworldPalette_Mewthree,
            gShinyOverworldPalette_Mewthree
        )
```
#### Version 1.10.x
```diff
-       OVERWORLD(
+       OVERWORLD_SET_ANIM(
            sPicTable_Mewthree,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
+           sAnimTable_Following_Asym,
            gOverworldPalette_Mewthree,
            gShinyOverworldPalette_Mewthree
        )
```

Either way, you may also create custom animation tables and use them here appropiately.

### How to add the Pokémon Object Events to map
In Porymap, select the object you want to set the sprite to. Then, change the field "Sprite" to use `OBJ_EVENT_GFX_SPECIES(SPECIES)`, replacing SPECIES with the name of the species you want to use. If you get a compiler error, it's because it used the species define as part of the macro, so it needs to match how you defined it all the way back in [Declare a species constant](#1-Declare-a-species-constant).
![charizard](img/add_pokemon/charizard.png)
![overworld_data](img/add_pokemon/overworld_data.gif)

If you want to use their shiny and/or female versions, use one of the following macros:
- `OBJ_EVENT_GFX_SPECIES_SHINY(name)`
- `OBJ_EVENT_GFX_SPECIES_FEMALE(name)`
- `OBJ_EVENT_GFX_SPECIES_SHINY_FEMALE(name)`

## 5. In-battle shadows (v1.10 onwards)
Gen 4-style shadows are defined by the `SHADOW` macro which takes the following arguments:
 - X offset
 - Y offset
 - Shadow size: you have 4 options for their shadow, between Small, Medium, Large and Extra Large:
    - `SHADOW_SIZE_S`
    - `SHADOW_SIZE_M`
    - `SHADOW_SIZE_L`
    - `SHADOW_SIZE_XL_BATTLE_ONLY`

To make the Pokémon have no shadow, use the `NO_SHADOW` macro instead of `SHADOW`.

## 6. Limiting species allowed as followers
You may use the following configs in `include/config/overworld.h`
```c
#define OW_FOLLOWERS_ALLOWED_SPECIES (0)
#define OW_FOLLOWERS_ALLOWED_MET_LVL (0)
#define OW_FOLLOWERS_ALLOWED_MET_LOC (0)
```
Examples:
```c
// Yellow Pikachu:
#define OW_FOLLOWERS_ALLOWED_SPECIES (SPECIES_PIKACHU)
#define OW_FOLLOWERS_ALLOWED_MET_LVL (0)
#define OW_FOLLOWERS_ALLOWED_MET_LOC (MAPSEC_PALLET_TOWN)
// Hoenn Starter:
#define OW_FOLLOWERS_ALLOWED_SPECIES (0)
#define OW_FOLLOWERS_ALLOWED_MET_LVL (5)
#define OW_FOLLOWERS_ALLOWED_MET_LOC (MAPSEC_ROUTE_101)
// Species set in VAR_XXXX:
#define OW_FOLLOWERS_ALLOWED_SPECIES (VAR_XXXX)
#define OW_FOLLOWERS_ALLOWED_MET_LVL (0)
#define OW_FOLLOWERS_ALLOWED_MET_LOC (0)
```
