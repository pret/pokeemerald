<!--1.7.x-->
This is a modified version of [the original tutorial about adding new Pokémon species available in Pokeemerald's wiki](https://github.com/pret/pokeemerald/wiki/How-to-add-a-new-Pokémon-species).

Despite the persistent rumors about an incredibly strong third form of Mew hiding somewhere, it actually wasn't possible to catch it... OR WAS IT?
In this tutorial, we will add a new Pokémon species to the game.

## IMPORTANT: This tutorial applies to 1.7.x versions.
- [Version 1.9.x](how_to_new_pokemon_1_9_0.md)
- [Version 1.8.x](how_to_new_pokemon_1_8_0.md)
- [Version 1.6.x](how_to_new_pokemon_1_6_0.md)

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

# Useful resources
You can open a sprite debug menu by pressing `Select` in a Pokémon's summary screen outside of battle.

![mGBA_6WOo1TSlsn](https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/0c625cd8-8f89-4bc8-a285-b10a420a8f6d)


# The Data - Part 1

Our plan is as simple as it is brilliant: clone Mewtwo... and make it even stronger!

## 1. Declare a species constant

Our first step towards creating a new digital lifeform is to define its own species constant.

Edit [include/constants/species.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/species.h):

```diff
 #define SPECIES_NONE                                    0
 #define SPECIES_BULBASAUR                               1
 ...
 #define SPECIES_EEVEE_PARTNER                           PLACEHOLDER_START + 54
+#define SPECIES_MEWTHREE                                PLACEHOLDER_START + 55

-#define GIGANTAMAX_START                                SPECIES_EEVEE_PARTNER
+#define GIGANTAMAX_START                                SPECIES_MEWTHREE

 // Gigantamax Forms
 #define SPECIES_VENUSAUR_GIGANTAMAX                     GIGANTAMAX_START + 1
```
This number is stored in a Pokémon's save structure. These should generally never change, otherwise your saved Pokémon species will change as well.

We add this before Gigantamax forms because they're temporary forms that shouldn't normally be saved into a Pokémon's save structure.

Now, let's see how it looks in-game!

![image](https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/dc15b0ba-a4bd-4f4e-9658-2dff73a11f79)

Hmmm, something's not right...

Oh, I know! We need to add the rest of the data! Normally, the vanilla game would crash if we try to look up anything about Mewthree in this state, but the expansion defaults all of its data to `SPECIES_NONE`.

Now, let's see what needs to be done.

## 2. `SpeciesInfo`'s structure
Now, to better understand Mewtwo, we also need to understand Mew. Let's look at its data.
```diff
    [SPECIES_MEW] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
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
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .isMythical = TRUE,
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
        FRONT_PIC(Mew, 64, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Mew,
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = 11,
        BACK_PIC(Mew, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Mew),
        ICON(Mew, 0),
        FOOTPRINT(Mew)
        LEARNSETS(Mew),
    },
```

That's a lot of stuff! But don't worry, we'll go through it step by step throught the tutorial
(and miles better than having this same data through 20+ files like it used to be).

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
+       .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
+       .catchRate = 3,
+       .expYield = 255,
+       .evYield_SpAttack  = 3,
+       .genderRatio = MON_GENDERLESS,
+       .eggCycles = 120,
+       .friendship = 0,
+       .growthRate = GROWTH_SLOW,
+       .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
+       .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_NONE },
+       .bodyColor = BODY_COLOR_PURPLE,
+    },
 };
```

The `.` is the structure reference operator in C to refer to the member object of the structure SpeciesInfo.

- `baseHP`, `baseAttack`, `baseDefense`, `baseSpeed`, `baseSpAttack` and `baseSpDefense` are the base stats. They can't go higher than 255.
- You may be confused as to why `types` has `TYPE_PSYCHIC` twice. This is because the way the game determines single-type mon is to define both types the same.
    - If we don't, it defaults to Normal due to it being the first type defined.
- `catchRate` is how likely it is to catch a Pokémon, the lower the value, the harder it is to catch. Legendaries generally have a catch rate of 3, so we put that here.
- `expYield` is the base amount of experience that a Pokémon gives when defeated/caught. In vanilla, this value caps at 255, but we've increased it to a maximum of 65535 accomodate later gen's higher experience yields. (The highest official value is Blissey's with 608, so going beyond this point may cause exponential gains that could break the system 😱)
    - If you noticed, Mew's had some `#if`s, `#elif`s and `#endif` around it. This is because its yield has changed over time, and we let you choose which ones you want. This is not relevant to our Mewthree however, so we can just put a single `.expYield = 255,` line here.
- `evYield_HP`, `evYield_Attack`, `evYield_Defense`, `evYield_Speed`, `evYield_SpAttack` and `evYield_SpDefense` are how many EVs does the Pokémon give when they're caught. Each of these fields can have a value of 3 at most. Officially, no Pokémon give out more than 3 EVs total, with them being determined by their evolution stage (eg, Pichu, Pikachu and Raichu give 1, 2 and 3 Speed EVs respectively), and they tend to be associated with its higher stats. Since our Mewthree is a Special Attack monster, we'll be consistent and make it give out 3 Special Attack EVs, but you're always free to assign whatever you feel like :)
    - Notice that the other `evYield` fields are not there. In C, numbers in a struct default to 0, so if we don't specify them, they'll be 0 all around! Less lines to worry about :D
- `itemCommon` and `itemRare` are used to determine what items is the Pokémon holding when encountering it in the wild.
    - 50% for `itemCommon` and 5% for `itemRare` (boosted to 60%/20% when the first mon in the party has Compound Grass or Super Luck)
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
- `eggGroups` are used for breed compatibility. Most Legendaries and Mythicals have the `EGG_GROUP_NO_EGGS_DISCOVERED` group, and so does our Mewthree. Go [here](https://bulbapedia.bulbagarden.net/wiki/Egg_Group) for more info.
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
        .isLegendary = TRUE,
        .allPerfectIVs = TRUE,
+       .speciesName = _("Mewthree"),
    },
 };
```
The `_()` underscore function doesn't really exist - it's a convention borrowed from GNU gettext to let `preproc` know this is text to be converted to the custom encoding used by the Gen 3 Pokemon games.

## 5. Define its cry

Time for audio!
We first need to convert an existing audio file to the format supported by the expansion.

Most formats are supported for conversion, but for simplicity's sake, we're gonna use this [mp3 file](https://cdn.discordapp.com/attachments/1206424179197349924/1206424212403920996/mewthree.mp3?ex=6600df1a&is=65ee6a1a&hm=4f05d58a7ae22bfdcd5f83558e15320fc1b6cd42a8cb9dee347b20bfb805ece5&).

Now, let's copy the file to the `sound/direct_sound_samples/cries` folder.
Once that's done, let's run the following command:
```
ffmpeg -i sound/direct_sound_samples/cries/mewthree.mp3 -c:a pcm_s8 -ac 1 -ar 13379 sound/direct_sound_samples/cries/mewthree.aif
```
This will convert your audio file to .aif, which is what's read by the compiler.

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
enum {
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
        .isLegendary = TRUE,
        .allPerfectIVs = TRUE,
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
enum {
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

Do keep in mind that if you intend to add your new species to the Hoenn Dex, you'll also want to add a `HOENN_DEX` constant for it, like this:

```diff
// Hoenn Pokedex order
enum {
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
![image](https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/3759dd4c-8da5-4b1c-9a50-b9e9d0815e7f)

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
![mGBA_lUBfmFEKUx](https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/3a8b8a17-759b-486b-9831-deb2f494bd71)


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
Finally, edit `icon.png`. Notice, that the icon will use one of 6 predefined palettes instead of `normal.pal`.

## 2. Add the sprites to the rom
Sadly, just putting the image files into the graphics folder is not enough. To use the sprites we have to register them, which is kind of tedious.
First, create constants for the file paths. You'll want to add the constants for your species after the constants for the last valid species.

Edit [src/data/graphics/pokemon.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/pokemon.h):

```diff
#if P_FAMILY_PECHARUNT
    // const u32 gMonFrontPic_Pecharunt[] = INCBIN_U32("graphics/pokemon/pecharunt/front.4bpp.lz");
    // const u32 gMonPalette_Pecharunt[] = INCBIN_U32("graphics/pokemon/pecharunt/normal.gbapal.lz");
    // const u32 gMonBackPic_Pecharunt[] = INCBIN_U32("graphics/pokemon/pecharunt/back.4bpp.lz");
    // const u32 gMonShinyPalette_Pecharunt[] = INCBIN_U32("graphics/pokemon/pecharunt/shiny.gbapal.lz");
    // const u8 gMonIcon_Pecharunt[] = INCBIN_U8("graphics/pokemon/pecharunt/icon.4bpp");
#if P_FOOTPRINTS
    // const u8 gMonFootprint_Pecharunt[] = INCBIN_U8("graphics/pokemon/pecharunt/footprint.1bpp");
#endif //P_FOOTPRINTS
#endif //P_FAMILY_PECHARUNT

+   const u32 gMonFrontPic_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/anim_front.4bpp.lz");
+   const u32 gMonBackPic_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/back.4bpp.lz");
+   const u32 gMonPalette_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/normal.gbapal.lz");
+   const u32 gMonShinyPalette_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/shiny.gbapal.lz");
+   const u8 gMonIcon_Mewthree[] = INCBIN_U8("graphics/pokemon/mewthree/icon.4bpp");
+   const u8 gMonFootprint_Mewthree[] = INCBIN_U8("graphics/pokemon/mewthree/footprint.1bpp");
```

Please note that Pecharunt, the Pokémon that should be above your insertion for the time being, reads a `front.png` sprite instead of an `anim_front.png` sprite. This is because currently, Pecharunt lacks a 2nd frame. If the front sprite sheet of your species uses 2 frames, you should use `anim_front`.

It is also worth to mention that Pecharunt's sprites are commented out simply because they're currently missing.

## 3. Add the animations to the rom

You can define the animation order, in which the sprites will be shown. The first number is the sprite index (so 0 or 1) and the second number is the number of frames the sprite will be visible.

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
+       FRONT_PIC(Mewthree, 64, 64),
+       .frontPicYOffset = 0,
+       .frontAnimFrames = sAnims_Mewthree,
+       .frontAnimId = ANIM_GROW_VIBRATE,
+       .frontAnimDelay = 15,
+       .enemyMonElevation = 6,
+       BACK_PIC(Mewthree, 64, 64),
+       .backPicYOffset = 0,
+       .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
+       PALETTES(Mewthree),
+       ICON(Mewthree, 2),
+       FOOTPRINT(Mewthree)
    },
 };
```
Let's explain each of these:
- `FRONT_PIC`:
    - This is a macro handles both the `frontPic` and `frontPicSize` fields.
        ```c
        #define FRONT_PIC(sprite, width, height)                    \
                .frontPic = gMonFrontPic_## sprite,                 \
                .frontPicSize = MON_COORDS_SIZE(width, height)
        ```
    - The first value in the macro is used to reference the front sprite, so in this case, using `Mewthree` will call for `gMonFrontPic_Mewthree`.
    - The second and third values (`width` and `height`) are used for defining the non-empty size of the sprite, which is used in move animations. If you're unsure of the values, you can leave them both as 64.
- `frontPicYOffset`:
    - Used to define what Y position the sprite sits at. This is used to set where they'd be "grounded". For the shadow, see `enemyMonElevation`.
- `frontAnimFrames`:
    - We link our animation frame animations that we defined earlier here.
- `frontAnimId`:
    - Because you are limited to two frames, there are already [predefined front sprite animations](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/pokemon_animation.h), describing translations, rotations, scalings or color changes.
- `frontAnimDelay`:
    - Sets a delay in frame count between when the Pokémon appears and when the animation starts.
- `enemyMonElevation`:
    - Used to determine the altitude from the ground. Any value above 0 will show a shadow under the Pokémon, to signify that they're floating.
- `BACK_PIC`:
    - A macro like `FRONT_PIC` except for the back sprite handling the `frontPic` and `frontPicSize` fields in the same way.
        ```c
        #define BACK_PIC(sprite, width, height)                     \
                .backPic = gMonBackPic_## sprite,                   \
                .backPicSize = MON_COORDS_SIZE(width, height)
        ```
- `backPicYOffset`:
    - Used to define what Y position of the back sprite. When working with the animation debug menu, we recommend aligning the back sprite to the white background, as it was designed to properyly align with the real battle layout.
- `backAnimId`:
    - Like `frontAnimId` except for the back sprites and them being a single frame. The IDs listed [here](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/pokemon_animation.h) are used to represent 3 different animations that happen based on the the Pokémon's nature.
- `PALETTES` 
    - This macro was created to handle both regular and shiny palettes of a Pokémon. It just needs the species suffix to call the corresponding palette.
        ```c
        #define PALETTES(pal)                                       \
                .palette = gMonPalette_## pal,                      \
                .shinyPalette = gMonShinyPalette_## pal
        ```
- `ICON`
    - This macro is calls both the icon sprite and its palette.
        ```c
        #define ICON(sprite, palId)                                 \
                .iconSprite = gMonIcon_## sprite,                   \
                .iconPalIndex = palId
        ```
        Here, you can choose between the six icon palettes; 0, 1, 2, 3, 4 and 5. All of them located in `graphics/pokemon/icon_palettes`.

        Open an icon sprite and load one of the palettes to find out which palette suits your icon sprite best.
- `FOOTPRINT`
    - We made this single field into a macro so that they can be ignored when `P_FOOTPRINTS` is set to false. It's also why we don't have an "," after calling it like the other macros (we add it as part of the macro itself).
        ```c
        #if P_FOOTPRINTS
        #define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
        #else
        #define FOOTPRINT(sprite)
        #endif
        ```

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
+       .isLegendary = TRUE,
+       .allPerfectIVs = TRUE,
    },
 };
```
Each species flag provides properties to the species:
- `isLegendary`:
    - Guarantees 3 perfect IVs upon generating the Pokémon[*](########## "As long as `P_LEGENDARY_PERFECT_IVS` is set to `GEN_6` or higher").
- `isMythical`:
    - Guarantees 3 perfect IVs upon generating the Pokémon[*](########## "As long as `P_LEGENDARY_PERFECT_IVS` is set to `GEN_6` or higher").
    - Is skipped during Pokédex evaluations.
        - Unless it also has the `dexForceRequired` flag.
    - Cannot obtain Gigantamax factor via `ToggleGigantamaxFactor`.
- `isUltraBeast`:
    - Guarantees 3 perfect IVs upon generating the Pokémon[*](########## "As long as `P_LEGENDARY_PERFECT_IVS` is set to `GEN_6` or higher").
    - Beast Ball's multiplier is set to x5 for this species.
        - All other ball multipliers are set to x0.1.
- `isParadoxForm`:
    - Currently has no functionality but can be utilized by users for their own benefits.
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
    - In the future, these will be used to determine breeding offspring from different based on their region.
- `cannotBeTraded`:
    - This species cannot be traded away (like Black/White Kyurem).
- `allPerfectIVs`:
    - Guarantees 6 perfect IVs upon generating the Pokémon (like LGPE's Partner Pikachu and Eevee).
- `tmIlliterate`:
    - This species will be unable to learn the universal moves.

*: As long as `P_LEGENDARY_PERFECT_IVS` is set to `GEN_6` or higher.

## 2. Delimit the moveset

Let's begin with the moves that can be learned by leveling up.

Append to [src/data/pokemon/level_up_learnsets.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/level_up_learnsets.h):

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

Again, we need to register the learnset in `gSpeciesInfo`:

```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     ...
     [SPECIES_MEWTHREE] =
     { 
        ...
        PALETTES(Mewthree),
        ICON(Mewthree, 2),
        FOOTPRINT(Mewthree)
+       .levelUpLearnset = sMewthreeLevelUpLearnset,
    },
 };
```

Next we need to specify which moves can be taught via TM, HM, or Move Tutor.

Append to [src/data/pokemon/teachable_learnsets.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/teachable_learnsets.h):

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
+   MOVE_HAIL,
+   MOVE_BULK_UP,
+   MOVE_HIDDEN_POWER,
+   MOVE_SUNNY_DAY,
+   MOVE_TAUNT,
+   MOVE_ICE_BEAM,
+   MOVE_BLIZZARD,
+   MOVE_HYPER_BEAM,
+   MOVE_LIGHT_SCREEN,
+   MOVE_PROTECT,
+   MOVE_RAIN_DANCE,
+   MOVE_SAFEGUARD,
+   MOVE_FRUSTRATION,
+   MOVE_SOLAR_BEAM,
+   MOVE_IRON_TAIL,
+   MOVE_THUNDERBOLT,
+   MOVE_THUNDER,
+   MOVE_EARTHQUAKE,
+   MOVE_RETURN,
+   MOVE_PSYCHIC,
+   MOVE_SHADOW_BALL,
+   MOVE_BRICK_BREAK,
+   MOVE_DOUBLE_TEAM,
+   MOVE_REFLECT,
+   MOVE_SHOCK_WAVE,
+   MOVE_FLAMETHROWER,
+   MOVE_SANDSTORM,
+   MOVE_FIRE_BLAST,
+   MOVE_ROCK_TOMB,
+   MOVE_AERIAL_ACE,
+   MOVE_TORMENT,
+   MOVE_FACADE,
+   MOVE_SECRET_POWER,
+   MOVE_REST,
+   MOVE_SKILL_SWAP,
+   MOVE_SNATCH,
+   MOVE_STRENGTH,
+   MOVE_FLASH,
+   MOVE_ROCK_SMASH,
+   MOVE_MEGA_PUNCH,
+   MOVE_MEGA_KICK,
+   MOVE_BODY_SLAM,
+   MOVE_DOUBLE_EDGE,
+   MOVE_COUNTER,
+   MOVE_SEISMIC_TOSS,
+   MOVE_MIMIC,
+   MOVE_METRONOME,
+   MOVE_DREAM_EATER,
+   MOVE_THUNDER_WAVE,
+   MOVE_SUBSTITUTE,
+   MOVE_DYNAMIC_PUNCH,
+   MOVE_PSYCH_UP,
+   MOVE_SNORE,
+   MOVE_ICY_WIND,
+   MOVE_ENDURE,
+   MOVE_MUD_SLAP,
+   MOVE_ICE_PUNCH,
+   MOVE_SWAGGER,
+   MOVE_SLEEP_TALK,
+   MOVE_SWIFT,
+   MOVE_THUNDER_PUNCH,
+   MOVE_FIRE_PUNCH,
+   MOVE_UNAVAILABLE, // This is required to determine where the array ends.
+};
#endif
```

Once more, we need to register the learnset in `gSpeciesInfo`:

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
        .isLegendary = TRUE,
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
We register the table each form entry in `gSpeciesInfo`.

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

![image](https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/a1a90b79-46a1-4cd6-97d6-ec5d741bfdc8) ![image](https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/7cffc6be-0b5c-4074-b689-736a97297843)

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
static const struct FormChange sGengarFormChangeTable[] = {
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
![mGBA_Wq5cbDkNZG](https://github.com/rh-hideout/pokeemerald-expansion/assets/2904965/45256192-b451-4baa-af06-f57ca16e1e46)

You may have seen that there's a couple of duplicate fields with a "Female" suffix.
```diff
    [SPECIES_FRILLISH] =
    {
        ...
        .frontPic = gMonFrontPic_Frillish,
+       .frontPicFemale = gMonFrontPic_FrillishF,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
+       .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Frillish,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .backPic = gMonBackPic_Frillish,
+       .backPicFemale = gMonBackPic_FrillishF,
        .backPicSize = MON_COORDS_SIZE(40, 56),
+       .backPicSizeFemale = MON_COORDS_SIZE(40, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Frillish,
+       .paletteFemale = gMonPalette_FrillishF,
        .shinyPalette = gMonShinyPalette_Frillish,
+       .shinyPaletteFemale = gMonShinyPalette_FrillishF,
        .iconSprite = gMonIcon_Frillish,
+       .iconSpriteFemale = gMonIcon_FrillishF,
        .iconPalIndex = 0,
+       .iconPalIndexFemale = 1,
        FOOTPRINT(Frillish)
        .levelUpLearnset = sFrillishLevelUpLearnset,
        .teachableLearnset = sFrillishTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_JELLICENT}),
    },
```
These are used to change the graphics of the Pokémon if they're female. If they're not registered, they default to the male values.

However, `iconPalIndexFemale` is a special case, where it's *doesn't* read the male icon palette if its `iconSpriteFemale` is set, so if you're setting a female icon, be sure to set their palette index as well.

