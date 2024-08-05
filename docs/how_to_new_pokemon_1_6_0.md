This is a modified version of [the original tutorial about adding new Pokémon species available in Pokeemerald's wiki](https://github.com/pret/pokeemerald/wiki/How-to-add-a-new-Pokémon-species).

Despite the persistent rumors about an incredibly strong third form of Mew hiding somewhere, it actually wasn't possible to catch it... OR WAS IT?
In this tutorial, we will add a new Pokémon species to the game.

## IMPORTANT: This tutorial applies to Version 1.6.2 and lower.
- [Version 1.9.x](how_to_new_pokemon_1_9_0.md)
- [Version 1.8.x](how_to_new_pokemon_1_8_0.md)
- [Version 1.7.x](how_to_new_pokemon_1_7_0.md)

# Changes compared to vanilla
The main things that the Expansion changes are listed here.
* Still Front Pics *(`gMonStillFrontPic_YourPokemon`)* and by extension `src/anim_mon_front_pics.c` have been removed.
* `src/data/pokemon/cry_ids.h` doesn't exist anymore.

# Content
* [The Graphics](#the-graphics)
  * [1. Edit the sprites](#1-edit-the-sprites)
  * [2. Register the sprites](#2-register-the-sprites)
  * [3. Animate the sprites](#3-animate-the-sprites)
  * [4. Update the tables](#4-update-the-tables)
* [The Data](#the-data)
  * [1. Declare a species constant](#1-declare-a-species-constant)
  * [2. Devise a name](#2-devise-a-name)
  * [3. Define its Pokédex entry](#3-define-its-pokédex-entry)
  * [4. Define its species information](#4-define-its-species-information)
  * [5. Delimit the moveset](#5-delimit-the-moveset)
  * [6. Define its cry](#6-define-its-cry)
  * [7. Define the Evolutions](#7-define-the-evolutions)
  * [8. Easy Chat about your Pokémon](#8-easy-chat-about-your-pokémon)
  * [9. Make it appear!](#9-make-it-appear)
* [Appendix](#appendix)
  * [Available Front Animations](#available-front-animations)
  * [Available Back Animations](#available-back-animations)
  * [Pokémon ordered by height](#pokémon-ordered-by-height)
  * [Pokémon ordered by weight](#pokémon-ordered-by-weight)
  * [Making this easier](#making-this-easier)


# The Graphics
We will start by copying the folder containing the sprites for Mewtwo and rename it to `mewthree` (pretty meta huh?):
```sh
cp -r graphics/pokemon/mewtwo graphics/pokemon/mewthree
```
## 1. Edit the sprites
Let's edit the sprites. Start your favourite image editor (I have used GIMP) and change `anim_front.png`, `front.png` and `back.png` to meet your expectations.
__Make sure that you are using the indexed mode and you have limited yourself to 15 colors!__
Put the RGB values of your colors into `normal.pal` between the first and the last color and the RGB values for the shiny version into `shiny.pal`.
Edit `footprint.png` using two colors in indexed mode, black and white.
Finally, edit `icon.png`. Notice, that the icon will use one of three predefined palettes instead of `normal.pal`.

## 2. Register the sprites
Sadly, just putting the image files into the graphics folder is not enough. To use the sprites we have to register them, which is kind of tedious.
First, create constants for the file paths. You'll want to add the constants for your species after the constants for the last valid species.
Edit [include/graphics.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/graphics.h):

```diff
 extern const u32 gMonFrontPic_Calyrex[];
+extern const u32 gMonFrontPic_Mewthree[];
```

```diff
 extern const u32 gMonBackPic_Calyrex[];
+extern const u32 gMonBackPic_Mewthree[];
```

```diff
 extern const u32 gMonPalette_Calyrex[];
+extern const u32 gMonPalette_Mewthree[];
```

```diff
 extern const u32 gMonShinyPalette_Calyrex[];
+extern const u32 gMonShinyPalette_Mewthree[];
```

```diff
 //extern const u8 gMonIcon_Calyrex[];
+extern const u8 gMonIcon_Mewthree[];
```

```diff
 extern const u8 gMonFootprint_Calyrex[];
+extern const u8 gMonFootprint_Mewthree[];
```

Now link the graphic files.

Edit [src/data/graphics/pokemon.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/pokemon.h):

```diff
 const u32 gMonFrontPic_Calyrex[] = INCBIN_U32("graphics/pokemon/calyrex/front.4bpp.lz");
+const u32 gMonFrontPic_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/front.4bpp.lz");
```

```diff
 const u32 gMonBackPic_Calyrex[] = INCBIN_U32("graphics/pokemon/calyrex/back.4bpp.lz");
+const u32 gMonBackPic_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/back.4bpp.lz");
```

```diff
 const u32 gMonPalette_Calyrex[] = INCBIN_U32("graphics/pokemon/calyrex/normal.gbapal.lz");
+const u32 gMonPalette_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/normal.gbapal.lz");
```

```diff
 const u32 gMonShinyPalette_Calyrex[] = INCBIN_U32("graphics/pokemon/calyrex/shiny.gbapal.lz");
+const u32 gMonShinyPalette_Mewthree[] = INCBIN_U32("graphics/pokemon/mewthree/shiny.gbapal.lz");
```

```diff
 //const u8 gMonIcon_Calyrex[] = INCBIN_U8("graphics/pokemon/calyrex/icon.4bpp");
+const u8 gMonIcon_Mewthree[] = INCBIN_U8("graphics/pokemon/mewthree/icon.4bpp");
```

```diff
 const u8 gMonFootprint_Calyrex[] = INCBIN_U8("graphics/pokemon/calyrex/footprint.1bpp");
+const u8 gMonFootprint_Mewthree[] = INCBIN_U8("graphics/pokemon/mewthree/footprint.1bpp");
```

Please note that Calyrex, the Pokémon that should be above your insertion for the time being, reads a "front.png" sprite instead of an "anim_front.png" sprite. This is because currently, Calyrex lacks a 2nd frame. If the front sprite sheet of your species uses 2 frames, you should use "anim_front".

It is also worth to mention that Calyrex's icon sprite is commented out simply because it's currently missing. If you do have an icon sprite sheet present inside your species' folder at `graphics/pokemon`, by all means do not comment entries involving the `gMonIcon` constants.

## 3. Animate the sprites

You can define the animation order, in which the sprites will be shown. The first number is the sprite index (so 0 or 1) and the second number is the number of frames the sprite will be visible.

Edit [src/data/pokemon_graphics/front_pic_anims.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/front_pic_anims.h):

```diff
static const union AnimCmd sAnim_Enamorus_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

+static const union AnimCmd sAnim_Mewthree_1[] =
+{
+    ANIMCMD_FRAME(1, 30),
+    ANIMCMD_FRAME(0, 20),
+    ANIMCMD_END,
+};
#endif
```

```diff
SINGLE_ANIMATION(Enamorus);
+SINGLE_ANIMATION(Mewthree);
#endif
```

```diff
 const union AnimCmd *const *const gMonFrontAnimsPtrTable[] =
 {
    [SPECIES_NONE]        = sAnims_None,
    [SPECIES_BULBASAUR]   = sAnims_Bulbasaur,
     ...
    [SPECIES_ENAMORUS] = sAnims_Enamorus,
+   [SPECIES_MEWTHREE] = sAnims_Mewthree,
#endif
     ...
 };
```

Because you are limited to two frames, there are already [predefined front sprite animations](#available-front-animations), describing translations, rotations, scalings or color changes.

Edit [src/pokemon.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/pokemon.c):
```diff
 static const u8 sMonFrontAnimIdsTable[] =
 {
     [SPECIES_BULBASAUR - 1]     = ANIM_V_JUMPS_H_JUMPS,
     ...
     [SPECIES_DEOXYS_SPEED - 1]           = ANIM_GROW_VIBRATE,
+    [SPECIES_MEWTHREE - 1]               = ANIM_GROW_VIBRATE,
 };
```

There are also [predefined back sprite animations](#available-back-animations) for the back sprites as well.

Edit [src/pokemon_animation.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/pokemon_animation.c):

```diff
 static const u8 sSpeciesToBackAnimSet[] =
 {
     [SPECIES_BULBASAUR]                    = BACK_ANIM_DIP_RIGHT_SIDE,
     ...
     [SPECIES_CHIMECHO]                     = BACK_ANIM_CONVEX_DOUBLE_ARC,
+    [SPECIES_MEWTHREE]                     = BACK_ANIM_GROW_STUTTER,
 };
```

If you want to delay the time between when the Pokémon appears and when the animation starts, you can add an entry to `sMonAnimationDelayTable`

Edit [src/pokemon.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/pokemon.c):

```diff
 static const u8 sMonAnimationDelayTable[NUM_SPECIES - 1] =
 {
     [SPECIES_BLASTOISE - 1]  = 50,
     ...
    [SPECIES_KYOGRE - 1]     = 60,
    [SPECIES_RAYQUAZA - 1]   = 60,
+   [SPECIES_MEWTHREE - 1]   = 15,
 };
```

If you want your Pokémon to fly above the ground, you can add an entry to `gEnemyMonElevation`.

Edit [src/data/pokemon_graphics/enemy_mon_elevation.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/enemy_mon_elevation.h):

```diff
 const u8 gEnemyMonElevation[NUM_SPECIES] =
 {
     [SPECIES_BUTTERFREE] = 10,
     ...
     [SPECIES_REGIDRAGO] = 5,
+    [SPECIES_MEWTHREE] = 6,
 };
```

## 4. Update the tables

Edit [src/data/pokemon_graphics/front_pic_table.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/front_pic_table.h):

```diff
 const struct CompressedSpriteSheet gMonFrontPicTable[] =
 {
     SPECIES_SPRITE(NONE, gMonFrontPic_CircledQuestionMark),
     SPECIES_SPRITE(BULBASAUR, gMonFrontPic_Bulbasaur),
     ...
     SPECIES_SPRITE(ENAMORUS, gMonFrontPic_Enamorus),
+    SPECIES_SPRITE(MEWTHREE, gMonFrontPic_Mewthree),
#endif
     ...
};
```

Edit [src/data/pokemon_graphics/front_pic_coordinates.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/front_pic_coordinates.h):

```diff
 const struct MonCoords gMonFrontPicCoords[] =
 {
     ...
    [SPECIES_ENAMORUS]                     = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },
+   [SPECIES_MEWTHREE]                     = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },
#endif
     ...
 };
```

Edit [src/data/pokemon_graphics/back_pic_table.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/back_pic_table.h):

```diff
 const struct CompressedSpriteSheet gMonBackPicTable[] =
 {
     SPECIES_SPRITE(NONE, gMonBackPic_CircledQuestionMark),
     SPECIES_SPRITE(BULBASAUR, gMonBackPic_Bulbasaur),
     ...
    SPECIES_SPRITE(ENAMORUS, gMonBackPic_Enamorus),
+   SPECIES_SPRITE(MEWTHREE, gMonBackPic_Mewthree),
#endif
     ...
 };
```

Edit [src/data/pokemon_graphics/back_pic_coordinates.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/back_pic_coordinates.h):

```diff
 const struct MonCoords gMonBackPicCoords[] =
 {
     ...
    [SPECIES_ENAMORUS]                     = { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },
+   [SPECIES_MEWTHREE]                     = { .size = MON_COORDS_SIZE(56, 64), .y_offset = 1  },
#endif
     ...
 };
```

Edit [src/data/pokemon_graphics/footprint_table.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/footprint_table.h):

```diff
 const u8 *const gMonFootprintTable[] =
 {
     [SPECIES_NONE] = gMonFootprint_Bulbasaur,
     [SPECIES_BULBASAUR] = gMonFootprint_Bulbasaur,
     ...
     [SPECIES_CALYREX] = gMonFootprint_Calyrex,
+    [SPECIES_MEWTHREE] = gMonFootprint_Mewthree,
#endif
     [SPECIES_EGG] = gMonFootprint_Bulbasaur,
 };
```

Edit [src/data/pokemon_graphics/palette_table.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/palette_table.h):

```diff
 const struct CompressedSpritePalette gMonPaletteTable[] =
 {
    SPECIES_PAL(NONE, gMonPalette_CircledQuestionMark),
    SPECIES_PAL(BULBASAUR, gMonPalette_Bulbasaur),
    ...
    SPECIES_PAL(ENAMORUS, gMonPalette_Enamorus),
+   SPECIES_PAL(MEWTHREE, gMonPalette_Mewthree),
#endif
    ...
};
```

Edit [src/data/pokemon_graphics/shiny_palette_table.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon_graphics/shiny_palette_table.h):

```diff
const struct CompressedSpritePalette gMonShinyPaletteTable[] =
{
     SPECIES_SHINY_PAL(NONE, gMonShinyPalette_CircledQuestionMark),
     SPECIES_SHINY_PAL(BULBASAUR, gMonShinyPalette_Bulbasaur),
     ...
    SPECIES_SHINY_PAL(ENAMORUS, gMonShinyPalette_Enamorus),
+   SPECIES_SHINY_PAL(MEWTHREE, gMonShinyPalette_Mewthree),
#endif
     ...
};
```

Edit [src/pokemon_icon.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/pokemon_icon.c):

```diff
 const u8 *const gMonIconTable[] =
 {
     [SPECIES_NONE] = gMonIcon_Bulbasaur,
     ...
    [SPECIES_ENAMORUS] = gMonIcon_Enamorus,
+   [SPECIES_MEWTHREE] = gMonIcon_Mewthree,
#endif
     ...
 };
```

```diff
 const u8 gMonIconPaletteIndices[] =
 {
     [SPECIES_NONE] = 0,
     ...
    [SPECIES_ENAMORUS] = 1,
+   [SPECIES_MEWTHREE] = 2,
    [SPECIES_VENUSAUR_MEGA] = 1,
     ...
 };
```

Here, you can choose between the six icon palettes; 0, 1, 2, 3, 4 and 5. All of them located in `graphics/pokemon/icon_palettes`.

Open an icon sprite and load one of the palettes to find out which palette suits your icon sprite best.

# The Data

Our plan is as simple as it is brilliant: clone Mewtwo... and make it even stronger!

## 1. Declare a species constant

Our first step towards creating a new digital lifeform is to define its own species constant.

Edit [include/constants/species.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/species.h):

```diff
 #define SPECIES_NONE 0
 #define SPECIES_BULBASAUR 1
 ...
 #define SPECIES_ENAMORUS 905
+#define SPECIES_MEWTHREE 906

-#define FORMS_START SPECIES_ENAMORUS
+#define FORMS_START SPECIES_MEWTHREE
```

## 2. Devise a name


This name will be displayed in the game. It may be different than the identifier of the species constant, especially when there are special characters involved.

Edit [src/data/text/species_names.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/text/species_names.h):

```diff
 const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1] = {
     [SPECIES_NONE] = _("??????????"),
     [SPECIES_BULBASAUR] = _("Bulbasaur"),
     ... 
     [SPECIES_ENAMORUS] = _("Enamorus"),
+    [SPECIES_MEWTHREE] = _("Mewthree"),
 };
```

The `_()` underscore function doesn't really exist - it's a convention borrowed from GNU gettext to let `preproc` know this is text to be converted to the custom encoding used by the Gen 3 Pokemon games.

## 3. Define its Pokédex entry

First, we will need to add new index constants for its Pokédex entry. The index constants are divided into the Hoenn Pokédex, which contains all Pokémon native to the Hoenn region, and the National Pokédex containing all known Pokémon, which can be received after entering the hall of fame for the first time.

Edit [include/constants/pokedex.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/pokedex.h):

```diff
// National Pokedex order
enum {
    NATIONAL_DEX_NONE,
    // Kanto
    NATIONAL_DEX_BULBASAUR,
...
    NATIONAL_DEX_ENAMORUS,
+   NATIONAL_DEX_MEWTHREE,
};
```

```diff
 #define KANTO_DEX_COUNT     NATIONAL_DEX_MEW
 #define JOHTO_DEX_COUNT     NATIONAL_DEX_CELEBI
#if P_GEN_8_POKEMON == TRUE
-   #define NATIONAL_DEX_COUNT  NATIONAL_DEX_ENAMORUS
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
...
};
```

```diff
- #define HOENN_DEX_COUNT (HOENN_DEX_DEOXYS + 1)
+ #define HOENN_DEX_COUNT (HOENN_DEX_MEWTHREE + 1)
```

Edit [src/pokemon.c](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/pokemon.c):


```diff
 // Assigns all species to the National Dex Index (Summary No. for National Dex)
 static const u16 sSpeciesToNationalPokedexNum[NUM_SPECIES - 1] =
 {
     SPECIES_TO_NATIONAL(ENAMORUS),
+    SPECIES_TO_NATIONAL(MEWTHREE),
 };
```

Just like before, if we want to insert our new species in the Hoenn Dex, we'll have to do a few extra steps:

```diff
 // Assigns all species to the Hoenn Dex Index (Summary No. for Hoenn Dex)
 static const u16 sSpeciesToHoennPokedexNum[NUM_SPECIES - 1] =
 {
     SPECIES_TO_HOENN(TREECKO),
     ...
     SPECIES_TO_HOENN(DEOXYS),
+    SPECIES_TO_HOENN(MEWTHREE),
 };
```

```diff
 const u16 gHoennToNationalOrder[NUM_SPECIES] = // Assigns Hoenn Dex Pokémon (Using National Dex Index)
 {
     HOENN_TO_NATIONAL(TREECKO),
     ...
     HOENN_TO_NATIONAL(DEOXYS),
+    HOENN_TO_NATIONAL(MEWTHREE),
 };
```

Now we can define the actual text of the Pokédex entry.

Append to [src/data/pokemon/pokedex_text.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/pokedex_text.h):

```diff
 const u8 gEnamorusPokedexText[] = _(
     "Its arrival brings an end to the\n"
     "winter. According to legend, this\n"
     "Pokémon's love gives rise to the\n"
     "budding of fresh life across the land.");
 
+const u8 gMewthreePokedexText[] = _(
+    "The rumors became true.\n"
+    "This is Mews final form.\n"
+    "Its power level is over 9000.\n"
+    "Has science gone too far?");
```

Finally, we will add the Pokédex entry for Mewthree and link the text to it.

Edit [src/data/pokemon/pokedex_entries.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/pokedex_entries.h):

```diff
 const struct PokedexEntry gPokedexEntries[] =
 {
     ...
     [NATIONAL_DEX_ENAMORUS] =
     {
         .categoryName = _("Love-Hate"),
         .height = 16,
         .weight = 480,
         .description = gEnamorusPokedexText,
         .pokemonScale = 259,
         .pokemonOffset = 1,
         .trainerScale = 296,
         .trainerOffset = 1,
     },
    
+    [NATIONAL_DEX_MEWTHREE] =
+    {
+        .categoryName = _("NEW SPECIES"),
+        .height = 15,
+        .weight = 330,
+        .description = gMewthreePokedexText,
+        .pokemonScale = 256,
+        .pokemonOffset = 0,
+        .trainerScale = 290,
+        .trainerOffset = 2,
+    },
 #endif
 };
```

The values `pokemonScale`, `pokemonOffset`, `trainerScale` and `trainerOffset` are used for the height comparison figure in the Pokédex. Height and weight are specified in meters and kilograms respectively, while the last digit is the first decimal place.

In Pokémon Emerald, you can sort the Pokédex by name, height or weight. Apparently, the Pokémon order is hardcoded in the game files and not calculated from their data. Therefore we have to include our new Pokémon species at the right places. While the correct position for the alphabetical order is easy to find, it can become quite tedious for height and weight. To find the right position for your Pokémon, you may look at the tables sorted by [height](#pokémon-ordered-by-height) and [weight](#pokémon-ordered-by-weight) respectively in the appendix.

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
     NATIONAL_DEX_ESCAVALIER,
     NATIONAL_DEX_FRILLISH,
     NATIONAL_DEX_DURANT,
     NATIONAL_DEX_CINDERACE,
+    NATIONAL_DEX_MEWTHREE,
     //NATIONAL_DEX_PERSIAN, // Alolan Form
     NATIONAL_DEX_DUGTRIO,
     ...
 };
 
 const u16 gPokedexOrder_Height[] =
 {
     ...
     NATIONAL_DEX_ZERAORA,
     NATIONAL_DEX_GRIMMSNARL,
     NATIONAL_DEX_MR_RIME,
+    NATIONAL_DEX_MEWTHREE,
     // 5'03" / 1.6m
     ...
 };
```

## 4. Define its species information
Edit [src/data/pokemon/species_info.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/species_info.h):
```diff
 const struct SpeciesInfo gSpeciesInfo[] =
 {
     [SPECIES_NONE] = {0},
     ...

      [SPECIES_ENAMORUS] =
      {
         .baseHP        = 74,
         .baseAttack    = 115,
         .baseDefense   = 70,
         .baseSpeed     = 106,
         .baseSpAttack  = 135,
         .baseSpDefense = 80,
         .types = { TYPE_FAIRY, TYPE_FLYING},
         .catchRate = 3,
         .expYield = 261,
         .evYield_SpAttack    = 3,
         .genderRatio = MON_FEMALE,
         .eggCycles = 120,
         .friendship = 90,
         .growthRate = GROWTH_SLOW,
         .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
         .abilities = {ABILITY_HEALER, ABILITY_NONE, ABILITY_CONTRARY},
         .bodyColor = BODY_COLOR_PINK,
         .noFlip = FALSE,
         .flags = SPECIES_FLAG_LEGENDARY,
     },

+     [SPECIES_MEWTHREE] =
+     { 
+        .baseHP        = 106,
+        .baseAttack    = 150,
+        .baseDefense   = 70,
+        .baseSpeed     = 140,
+        .baseSpAttack  = 194,
+        .baseSpDefense = 120,
+        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
+        .catchRate = 3,
+        .expYield = 255,
+        .evYield_SpAttack  = 3,
+        .genderRatio = MON_GENDERLESS,
+        .eggCycles = 120,
+        .friendship = 0,
+        .growthRate = GROWTH_SLOW,
+        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
+        .abilities = {ABILITY_INSOMNIA, ABILITY_NONE},
+        .safariZoneFleeRate = 0,
+        .bodyColor = BODY_COLOR_PURPLE,
+        .noFlip = FALSE,
+     },
#endif
 };
```

The `.` is the structure reference operator in C to refer to the member object of the structure SpeciesInfo.

Notice how I also set the ability to `ABILITY_INSOMNIA`, so our little monster doesn't even need to sleep anymore. You can find the abilities for example here [include/constants/abilities.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/abilities.h) and here [src/data/text/abilities.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/text/abilities.h).

You can also incorporate a 3rd ability to your species, which is intended to be a [Hidden Ability](https://bulbapedia.bulbagarden.net/wiki/Ability#Hidden_Abilities)!

## 5. Delimit the moveset

Let's begin with the moves that can be learned by leveling up.

Append to [src/data/pokemon/level_up_learnsets.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/level_up_learnsets.h):

```diff
static const struct LevelUpMove sEnamorusLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 7, MOVE_BITE),
    LEVEL_UP_MOVE(11, MOVE_TWISTER),
    LEVEL_UP_MOVE(14, MOVE_DRAINING_KISS),
    LEVEL_UP_MOVE(22, MOVE_IRON_DEFENSE),
    LEVEL_UP_MOVE(31, MOVE_EXTRASENSORY),
    LEVEL_UP_MOVE(41, MOVE_CRUNCH),
    LEVEL_UP_MOVE(47, MOVE_MOONBLAST),
    LEVEL_UP_MOVE( 1, MOVE_SPRINGTIDE_STORM),
    LEVEL_UP_END
};

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
#endif
```

Again, we need to register the learnset.

Edit [src/data/pokemon/level_up_learnset_pointers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/level_up_learnset_pointers.h):

```diff
 const struct LevelUpMove *const gLevelUpLearnsets[NUM_SPECIES] =
 {
     [SPECIES_NONE] = sBulbasaurLevelUpLearnset,
     [SPECIES_BULBASAUR] = sBulbasaurLevelUpLearnset,
     ...
     [SPECIES_ENAMORUS] = sEnamorusLevelUpLearnset,
+    [SPECIES_MEWTHREE] = sMewthreeLevelUpLearnset,
 };
```

Next we need to specify which moves can be taught via TM, HM, or Move Tutor.

Append to [src/data/pokemon/teachable_learnsets.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/teachable_learnsets.h):

```diff
static const u16 sEnamorusTeachableLearnset[] = {
    MOVE_UNAVAILABLE,
};

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
+   MOVE_UNAVAILABLE,
+};
#endif
```

Once more, we need to register the learnset.

Edit [src/data/pokemon/teachable_learnset_pointers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/teachable_learnset_pointers.h):

```diff
const u16 *const gTeachableLearnsets[NUM_SPECIES] =
 {
     [SPECIES_NONE] = sBulbasaurTeachableLearnset,
     [SPECIES_BULBASAUR] = sBulbasaurTeachableLearnset,
     ...
     [SPECIES_ENAMORUS] = sEnamorusTeachableLearnset,
+    [SPECIES_MEWTHREE] = sMewthreeTeachableLearnset,
 };
```

If you want to create a Pokémon which can breed, you will need to edit [src/data/pokemon/egg_moves.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/egg_moves.h).

## 6. Define its cry
First run these command to copy the Mewtwo sound files:
```sh
cp -r sound/direct_sound_samples/cries/mewtwo.bin sound/direct_sound_samples/cries/mewthree.bin
cp -r sound/direct_sound_samples/cries/mewtwo.aif sound/direct_sound_samples/cries/mewthree.aif
```

In [sound/direct_sound_data.inc](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/sound/direct_sound_data.inc).

```diff
    .align 2
Cry_Enamorus::
    .incbin "sound/direct_sound_samples/cries/enamorus.bin"

+   .align 2
+Cry_Mewthree::
+   .incbin "sound/direct_sound_samples/cries/mewthree.bin"

.endif
```

And linking it in [sound/cry_tables.inc](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/sound/cry_tables.inc). `cry_reverse` in particular is for reversed cries used by moves such as Growl.

```diff
...
    cry Cry_Enamorus
+   cry Cry_Mewthree
.else
```

```diff
    cry_reverse Cry_Overqwil
+   cry_reverse Cry_Mewthree
.else
```

Mon cries are 10512Hz. Make sure to put the aif file in the directory [sound/direct_sound_samples/cries](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/sound/direct_sound_samples/cries)

Higher frequencies may be ruined by compression. To have the cries uncompressed, follow [this](https://github.com/ShinyDragonHunter/pokefirereddx/commit/71ba1c193082817afbed9a8a0ba1d123fffb6f36#diff-e1823f56db7c2344fb9ee843e3c42797f72fa1e108e13a7080018e1db545322eR116) , then clear out the old sound bins

## 7. Define the Evolutions

We want Mewthree to evolve from Mewtwo by reaching level 100.

Edit [src/data/pokemon/evolution.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/pokemon/evolution.h):

```diff
    [SPECIES_SNEASEL_HISUIAN]       = {{EVO_ITEM_DAY, ITEM_RAZOR_CLAW, SPECIES_SNEASLER},
                                       {EVO_ITEM_HOLD_DAY, ITEM_RAZOR_CLAW, SPECIES_SNEASLER}},
+   [SPECIES_MEWTWO]                = {{EVO_LEVEL, 100, SPECIES_MEWTHREE}},
#endif
```

## 8. Easy Chat about your Pokémon


Edit [src/data/easy_chat/easy_chat_words_by_letter.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/easy_chat/easy_chat_words_by_letter.h):

```diff
 const u16 gEasyChatWordsByLetter_M[] = {
     EC_MOVE2(MACH_PUNCH),
     ...
     EC_POKEMON_NATIONAL(MEW),
+    EC_POKEMON_NATIONAL(MEWTHREE),
     EC_POKEMON_NATIONAL(MEWTWO),
     ...
     EC_WORD_MYSTERY,
 };
```

## 9. Make it appear!


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

# Appendix
## Available Front Animations
_Only 65 are used in-game, but you can use any animation from this list._
1. ANIM_V_SQUISH_AND_BOUNCE
2. ANIM_CIRCULAR_STRETCH_TWICE
3. ANIM_H_VIBRATE
4. ANIM_H_SLIDE
5. ANIM_V_SLIDE
6. ANIM_BOUNCE_ROTATE_TO_SIDES
7. ANIM_V_JUMPS_H_JUMPS
8. ANIM_ROTATE_TO_SIDES
9. ANIM_ROTATE_TO_SIDES_TWICE
10. ANIM_GROW_VIBRATE
11. ANIM_ZIGZAG_FAST
12. ANIM_SWING_CONCAVE
13. ANIM_SWING_CONCAVE_FAST
14. ANIM_SWING_CONVEX
15. ANIM_SWING_CONVEX_FAST
16. ANIM_H_SHAKE
17. ANIM_V_SHAKE
18. ANIM_CIRCULAR_VIBRATE
19. ANIM_TWIST
20. ANIM_SHRINK_GROW
21. ANIM_CIRCLE_C_CLOCKWISE
22. ANIM_GLOW_BLACK
23. ANIM_H_STRETCH
24. ANIM_V_STRETCH
25. ANIM_RISING_WOBBLE
26. ANIM_V_SHAKE_TWICE
27. ANIM_TIP_MOVE_FORWARD
28. ANIM_H_PIVOT
29. ANIM_V_SLIDE_WOBBLE
30. ANIM_H_SLIDE_WOBBLE
31. ANIM_V_JUMPS_BIG
32. ANIM_SPIN_LONG
33. ANIM_GLOW_ORANGE
34. ANIM_GLOW_RED
35. ANIM_GLOW_BLUE
36. ANIM_GLOW_YELLOW
37. ANIM_GLOW_PURPLE
38. ANIM_BACK_AND_LUNGE
39. ANIM_BACK_FLIP
40. ANIM_FLICKER
41. ANIM_BACK_FLIP_BIG
42. ANIM_FRONT_FLIP
43. ANIM_TUMBLING_FRONT_FLIP
44. ANIM_FIGURE_8
45. ANIM_FLASH_YELLOW
46. ANIM_SWING_CONCAVE_FAST_SHORT
47. ANIM_SWING_CONVEX_FAST_SHORT
48. ANIM_ROTATE_UP_SLAM_DOWN
49. ANIM_DEEP_V_SQUISH_AND_BOUNCE
50. ANIM_H_JUMPS
51. ANIM_H_JUMPS_V_STRETCH
52. ANIM_ROTATE_TO_SIDES_FAST
53. ANIM_ROTATE_UP_TO_SIDES
54. ANIM_FLICKER_INCREASING
55. ANIM_TIP_HOP_FORWARD
56. ANIM_PIVOT_SHAKE
57. ANIM_TIP_AND_SHAKE
58. ANIM_VIBRATE_TO_CORNERS
59. ANIM_GROW_IN_STAGES
60. ANIM_V_SPRING
61. ANIM_V_REPEATED_SPRING
62. ANIM_SPRING_RISING
63. ANIM_H_SPRING
64. ANIM_H_REPEATED_SPRING_SLOW
65. ANIM_H_SLIDE_SHRINK
66. ANIM_LUNGE_GROW
67. ANIM_CIRCLE_INTO_BG
68. ANIM_RAPID_H_HOPS
69. ANIM_FOUR_PETAL
70. ANIM_V_SQUISH_AND_BOUNCE_SLOW
71. ANIM_H_SLIDE_SLOW
72. ANIM_V_SLIDE_SLOW
73. ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL
74. ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW
75. ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW
76. ANIM_ZIGZAG_SLOW
77. ANIM_H_SHAKE_SLOW
78. ANIM_V_SHAKE_SLOW
79. ANIM_TWIST_TWICE
80. ANIM_CIRCLE_C_CLOCKWISE_SLOW
81. ANIM_V_SHAKE_TWICE_SLOW
82. ANIM_V_SLIDE_WOBBLE_SMALL
83. ANIM_V_JUMPS_SMALL
84. ANIM_SPIN
85. ANIM_TUMBLING_FRONT_FLIP_TWICE
86. ANIM_DEEP_V_SQUISH_AND_BOUNCE_TWICE
87. ANIM_H_JUMPS_V_STRETCH_TWICE
88. ANIM_V_SHAKE_BACK
89. ANIM_V_SHAKE_BACK_SLOW
90. ANIM_V_SHAKE_H_SLIDE_SLOW
91. ANIM_V_STRETCH_BOTH_ENDS_SLOW
92. ANIM_H_STRETCH_FAR_SLOW
93. ANIM_V_SHAKE_LOW_TWICE
94. ANIM_H_SHAKE_FAST
95. ANIM_H_SLIDE_FAST
96. ANIM_H_VIBRATE_FAST
97. ANIM_H_VIBRATE_FASTEST
98. ANIM_V_SHAKE_BACK_FAST
99. ANIM_V_SHAKE_LOW_TWICE_SLOW
100. ANIM_V_SHAKE_LOW_TWICE_FAST
101. ANIM_CIRCLE_C_CLOCKWISE_LONG
102. ANIM_GROW_STUTTER_SLOW
103. ANIM_V_SHAKE_H_SLIDE
104. ANIM_V_SHAKE_H_SLIDE_FAST
105. ANIM_TRIANGLE_DOWN_SLOW
106. ANIM_TRIANGLE_DOWN
107. ANIM_TRIANGLE_DOWN_TWICE
108. ANIM_GROW
109. ANIM_GROW_TWICE
110. ANIM_H_SPRING_FAST
111. ANIM_H_SPRING_SLOW
112. ANIM_H_REPEATED_SPRING_FAST
113. ANIM_H_REPEATED_SPRING
114. ANIM_SHRINK_GROW_FAST
115. ANIM_SHRINK_GROW_SLOW
116. ANIM_V_STRETCH_BOTH_ENDS
117. ANIM_V_STRETCH_BOTH_ENDS_TWICE
118. ANIM_H_STRETCH_FAR_TWICE
119. ANIM_H_STRETCH_FAR
120. ANIM_GROW_STUTTER_TWICE
121. ANIM_GROW_STUTTER
122. ANIM_CONCAVE_ARC_LARGE_SLOW
123. ANIM_CONCAVE_ARC_LARGE
124. ANIM_CONCAVE_ARC_LARGE_TWICE
125. ANIM_CONVEX_DOUBLE_ARC_SLOW
126. ANIM_CONVEX_DOUBLE_ARC
127. ANIM_CONVEX_DOUBLE_ARC_TWICE
128. ANIM_CONCAVE_ARC_SMALL_SLOW
129. ANIM_CONCAVE_ARC_SMALL
130. ANIM_CONCAVE_ARC_SMALL_TWICE
131. ANIM_H_DIP
132. ANIM_H_DIP_FAST
133. ANIM_H_DIP_TWICE
134. ANIM_SHRINK_GROW_VIBRATE_FAST
135. ANIM_SHRINK_GROW_VIBRATE
136. ANIM_SHRINK_GROW_VIBRATE_SLOW
137. ANIM_JOLT_RIGHT_FAST
138. ANIM_JOLT_RIGHT
139. ANIM_JOLT_RIGHT_SLOW
140. ANIM_SHAKE_FLASH_YELLOW_FAST
141. ANIM_SHAKE_FLASH_YELLOW
142. ANIM_SHAKE_FLASH_YELLOW_SLOW
143. ANIM_SHAKE_GLOW_RED_FAST
144. ANIM_SHAKE_GLOW_RED
145. ANIM_SHAKE_GLOW_RED_SLOW
146. ANIM_SHAKE_GLOW_GREEN_FAST
147. ANIM_SHAKE_GLOW_GREEN
148. ANIM_SHAKE_GLOW_GREEN_SLOW
149. ANIM_SHAKE_GLOW_BLUE_FAST
150. ANIM_SHAKE_GLOW_BLUE
151. ANIM_SHAKE_GLOW_BLUE_SLOW

## Available Back Animations
1. BACK_ANIM_NONE
2. BACK_ANIM_H_VIBRATE
3. BACK_ANIM_H_SLIDE
4. BACK_ANIM_H_SPRING
5. BACK_ANIM_H_SPRING_REPEATED
6. BACK_ANIM_SHRINK_GROW
7. BACK_ANIM_GROW
8. BACK_ANIM_CIRCLE_COUNTERCLOCKWISE
9. BACK_ANIM_H_SHAKE
10. BACK_ANIM_V_SHAKE
11. BACK_ANIM_V_SHAKE_H_SLIDE
12. BACK_ANIM_V_STRETCH
13. BACK_ANIM_H_STRETCH
14. BACK_ANIM_GROW_STUTTER
15. BACK_ANIM_V_SHAKE_LOW
16. BACK_ANIM_TRIANGLE_DOWN
17. BACK_ANIM_CONCAVE_ARC_LARGE
18. BACK_ANIM_CONVEX_DOUBLE_ARC
19. BACK_ANIM_CONCAVE_ARC_SMALL
20. BACK_ANIM_DIP_RIGHT_SIDE
21. BACK_ANIM_SHRINK_GROW_VIBRATE
22. BACK_ANIM_JOLT_RIGHT
23. BACK_ANIM_SHAKE_FLASH_YELLOW
24. BACK_ANIM_SHAKE_GLOW_RED
25. BACK_ANIM_SHAKE_GLOW_GREEN
26. BACK_ANIM_SHAKE_GLOW_BLUE

## Pokémon ordered by height
| Pokemon | height (m) |
| :------ | ---------: |
| Diglett | 0.2 |
| Natu | 0.2 |
| Azurill | 0.2 |
| Caterpie | 0.3 |
| Weedle | 0.3 |
| Pidgey | 0.3 |
| Rattata | 0.3 |
| Spearow | 0.3 |
| Paras | 0.3 |
| Magnemite | 0.3 |
| Shellder | 0.3 |
| Ditto | 0.3 |
| Eevee | 0.3 |
| Pichu | 0.3 |
| Cleffa | 0.3 |
| Igglybuff | 0.3 |
| Togepi | 0.3 |
| Sunkern | 0.3 |
| Wurmple | 0.3 |
| Taillow | 0.3 |
| Roselia | 0.3 |
| Castform | 0.3 |
| Jirachi | 0.3 |
| Pikachu | 0.4 |
| Nidoran_f | 0.4 |
| Meowth | 0.4 |
| Geodude | 0.4 |
| Krabby | 0.4 |
| Exeggcute | 0.4 |
| Cubone | 0.4 |
| Horsea | 0.4 |
| Omanyte | 0.4 |
| Mew | 0.4 |
| Bellossom | 0.4 |
| Marill | 0.4 |
| Hoppip | 0.4 |
| Wooper | 0.4 |
| Swinub | 0.4 |
| Smoochum | 0.4 |
| Torchic | 0.4 |
| Mudkip | 0.4 |
| Zigzagoon | 0.4 |
| Ralts | 0.4 |
| Shroomish | 0.4 |
| Aron | 0.4 |
| Plusle | 0.4 |
| Minun | 0.4 |
| Gulpin | 0.4 |
| Cacnea | 0.4 |
| Swablu | 0.4 |
| Barboach | 0.4 |
| Clamperl | 0.4 |
| Squirtle | 0.5 |
| Nidoran_m | 0.5 |
| Jigglypuff | 0.5 |
| Oddish | 0.5 |
| Mankey | 0.5 |
| Voltorb | 0.5 |
| Kabuto | 0.5 |
| Cyndaquil | 0.5 |
| Spinarak | 0.5 |
| Chinchou | 0.5 |
| Murkrow | 0.5 |
| Unown | 0.5 |
| Qwilfish | 0.5 |
| Phanpy | 0.5 |
| Treecko | 0.5 |
| Poochyena | 0.5 |
| Linoone | 0.5 |
| Lotad | 0.5 |
| Seedot | 0.5 |
| Surskit | 0.5 |
| Nincada | 0.5 |
| Sableye | 0.5 |
| Torkoal | 0.5 |
| Baltoy | 0.5 |
| Charmander | 0.6 |
| Kakuna | 0.6 |
| Sandshrew | 0.6 |
| Clefairy | 0.6 |
| Vulpix | 0.6 |
| Poliwag | 0.6 |
| Koffing | 0.6 |
| Goldeen | 0.6 |
| Totodile | 0.6 |
| Togetic | 0.6 |
| Mareep | 0.6 |
| Skiploom | 0.6 |
| Pineco | 0.6 |
| Snubbull | 0.6 |
| Shuckle | 0.6 |
| Teddiursa | 0.6 |
| Corsola | 0.6 |
| Remoraid | 0.6 |
| Houndour | 0.6 |
| Porygon2 | 0.6 |
| Elekid | 0.6 |
| Larvitar | 0.6 |
| Celebi | 0.6 |
| Silcoon | 0.6 |
| Wingull | 0.6 |
| Whismur | 0.6 |
| Skitty | 0.6 |
| Mawile | 0.6 |
| Meditite | 0.6 |
| Electrike | 0.6 |
| Illumise | 0.6 |
| Corphish | 0.6 |
| Feebas | 0.6 |
| Shuppet | 0.6 |
| Chimecho | 0.6 |
| Wynaut | 0.6 |
| Luvdisc | 0.6 |
| Bagon | 0.6 |
| Beldum | 0.6 |
| Bulbasaur | 0.7 |
| Metapod | 0.7 |
| Raticate | 0.7 |
| Dugtrio | 0.7 |
| Growlithe | 0.7 |
| Bellsprout | 0.7 |
| Hoothoot | 0.7 |
| Misdreavus | 0.7 |
| Slugma | 0.7 |
| Tyrogue | 0.7 |
| Magby | 0.7 |
| Marshtomp | 0.7 |
| Cascoon | 0.7 |
| Swellow | 0.7 |
| Volbeat | 0.7 |
| Numel | 0.7 |
| Spoink | 0.7 |
| Trapinch | 0.7 |
| Anorith | 0.7 |
| Snorunt | 0.7 |
| Raichu | 0.8 |
| Nidorina | 0.8 |
| Zubat | 0.8 |
| Gloom | 0.8 |
| Psyduck | 0.8 |
| Machop | 0.8 |
| Farfetchd | 0.8 |
| Staryu | 0.8 |
| Jolteon | 0.8 |
| Porygon | 0.8 |
| Sentret | 0.8 |
| Flaaffy | 0.8 |
| Azumarill | 0.8 |
| Jumpluff | 0.8 |
| Aipom | 0.8 |
| Sunflora | 0.8 |
| Magcargo | 0.8 |
| Kirlia | 0.8 |
| Masquerain | 0.8 |
| Slakoth | 0.8 |
| Ninjask | 0.8 |
| Shedinja | 0.8 |
| Carvanha | 0.8 |
| Duskull | 0.8 |
| Spheal | 0.8 |
| Nidorino | 0.9 |
| Abra | 0.9 |
| Tentacool | 0.9 |
| Grimer | 0.9 |
| Magikarp | 0.9 |
| Flareon | 0.9 |
| Chikorita | 0.9 |
| Quilava | 0.9 |
| Espeon | 0.9 |
| Sneasel | 0.9 |
| Octillery | 0.9 |
| Delibird | 0.9 |
| Grovyle | 0.9 |
| Combusken | 0.9 |
| Lairon | 0.9 |
| Grumpig | 0.9 |
| Whiscash | 0.9 |
| Ivysaur | 1.0 |
| Wartortle | 1.0 |
| Beedrill | 1.0 |
| Sandslash | 1.0 |
| Wigglytuff | 1.0 |
| Parasect | 1.0 |
| Venonat | 1.0 |
| Persian | 1.0 |
| Primeape | 1.0 |
| Poliwhirl | 1.0 |
| Weepinbell | 1.0 |
| Graveler | 1.0 |
| Ponyta | 1.0 |
| Magneton | 1.0 |
| Drowzee | 1.0 |
| Marowak | 1.0 |
| Rhyhorn | 1.0 |
| Tangela | 1.0 |
| Vaporeon | 1.0 |
| Omastar | 1.0 |
| Ledyba | 1.0 |
| Umbreon | 1.0 |
| Mightyena | 1.0 |
| Beautifly | 1.0 |
| Nuzleaf | 1.0 |
| Loudred | 1.0 |
| Makuhita | 1.0 |
| Nosepass | 1.0 |
| Lunatone | 1.0 |
| Lileep | 1.0 |
| Kecleon | 1.0 |
| Relicanth | 1.0 |
| Charmeleon | 1.1 |
| Butterfree | 1.1 |
| Pidgeotto | 1.1 |
| Ninetales | 1.1 |
| Seel | 1.1 |
| Chansey | 1.1 |
| Starmie | 1.1 |
| Electabuzz | 1.1 |
| Croconaw | 1.1 |
| Ariados | 1.1 |
| Politoed | 1.1 |
| Gligar | 1.1 |
| Piloswine | 1.1 |
| Donphan | 1.1 |
| Delcatty | 1.1 |
| Spinda | 1.1 |
| Vibrava | 1.1 |
| Altaria | 1.1 |
| Crawdaunt | 1.1 |
| Banette | 1.1 |
| Sealeo | 1.1 |
| Shelgon | 1.1 |
| Fearow | 1.2 |
| Vileplume | 1.2 |
| Slowpoke | 1.2 |
| Muk | 1.2 |
| Electrode | 1.2 |
| Lickitung | 1.2 |
| Weezing | 1.2 |
| Seadra | 1.2 |
| Bayleef | 1.2 |
| Lanturn | 1.2 |
| Sudowoodo | 1.2 |
| Yanma | 1.2 |
| Forretress | 1.2 |
| Smeargle | 1.2 |
| Miltank | 1.2 |
| Pupitar | 1.2 |
| Dustox | 1.2 |
| Lombre | 1.2 |
| Pelipper | 1.2 |
| Breloom | 1.2 |
| Solrock | 1.2 |
| Absol | 1.2 |
| Metang | 1.2 |
| Nidoqueen | 1.3 |
| Clefable | 1.3 |
| Poliwrath | 1.3 |
| Kadabra | 1.3 |
| Gastly | 1.3 |
| Kingler | 1.3 |
| Seaking | 1.3 |
| Mr_mime | 1.3 |
| Magmar | 1.3 |
| Kabutops | 1.3 |
| Wobbuffet | 1.3 |
| Shiftry | 1.3 |
| Medicham | 1.3 |
| Cacturne | 1.3 |
| Zangoose | 1.3 |
| Nidoking | 1.4 |
| Golem | 1.4 |
| Doduo | 1.4 |
| Hitmonchan | 1.4 |
| Jynx | 1.4 |
| Tauros | 1.4 |
| Ledian | 1.4 |
| Ampharos | 1.4 |
| Quagsire | 1.4 |
| Granbull | 1.4 |
| Houndoom | 1.4 |
| Stantler | 1.4 |
| Hitmontop | 1.4 |
| Vigoroth | 1.4 |
| Walrein | 1.4 |
| Latias | 1.4 |
| Pidgeot | 1.5 |
| Venomoth | 1.5 |
| Alakazam | 1.5 |
| Machoke | 1.5 |
| Cloyster | 1.5 |
| Gengar | 1.5 |
| Hitmonlee | 1.5 |
| Scyther | 1.5 |
| Pinsir | 1.5 |
| Xatu | 1.5 |
| Girafarig | 1.5 |
| Dunsparce | 1.5 |
| Heracross | 1.5 |
| Blissey | 1.5 |
| Swampert | 1.5 |
| Ludicolo | 1.5 |
| Exploud | 1.5 |
| Manectric | 1.5 |
| Claydol | 1.5 |
| Cradily | 1.5 |
| Armaldo | 1.5 |
| Glalie | 1.5 |
| Salamence | 1.5 |
| Blastoise | 1.6 |
| Golbat | 1.6 |
| Machamp | 1.6 |
| Tentacruel | 1.6 |
| Slowbro | 1.6 |
| Haunter | 1.6 |
| Hypno | 1.6 |
| Zapdos | 1.6 |
| Noctowl | 1.6 |
| Gardevoir | 1.6 |
| Dusclops | 1.6 |
| Metagross | 1.6 |
| Charizard | 1.7 |
| Golduck | 1.7 |
| Victreebel | 1.7 |
| Rapidash | 1.7 |
| Dewgong | 1.7 |
| Articuno | 1.7 |
| Typhlosion | 1.7 |
| Skarmory | 1.7 |
| Sceptile | 1.7 |
| Swalot | 1.7 |
| Huntail | 1.7 |
| Regirock | 1.7 |
| Deoxys | 1.7 |
| Dodrio | 1.8 |
| Aerodactyl | 1.8 |
| Dratini | 1.8 |
| Meganium | 1.8 |
| Furret | 1.8 |
| Crobat | 1.8 |
| Scizor | 1.8 |
| Ursaring | 1.8 |
| Kingdra | 1.8 |
| Sharpedo | 1.8 |
| Gorebyss | 1.8 |
| Regice | 1.8 |
| Arcanine | 1.9 |
| Rhydon | 1.9 |
| Raikou | 1.9 |
| Blaziken | 1.9 |
| Camerupt | 1.9 |
| Registeel | 1.9 |
| Venusaur | 2.0 |
| Ekans | 2.0 |
| Exeggutor | 2.0 |
| Moltres | 2.0 |
| Mewtwo | 2.0 |
| Slowking | 2.0 |
| Suicune | 2.0 |
| Tyranitar | 2.0 |
| Slaking | 2.0 |
| Wailmer | 2.0 |
| Flygon | 2.0 |
| Tropius | 2.0 |
| Latios | 2.0 |
| Snorlax | 2.1 |
| Mantine | 2.1 |
| Entei | 2.1 |
| Aggron | 2.1 |
| Kangaskhan | 2.2 |
| Dragonite | 2.2 |
| Feraligatr | 2.3 |
| Hariyama | 2.3 |
| Lapras | 2.5 |
| Seviper | 2.7 |
| Arbok | 3.5 |
| Groudon | 3.5 |
| Ho_oh | 3.8 |
| Dragonair | 4.0 |
| Kyogre | 4.5 |
| Lugia | 5.2 |
| Milotic | 6.2 |
| Gyarados | 6.5 |
| Rayquaza | 7.0 |
| Onix | 8.8 |
| Steelix | 9.2 |
| Wailord | 14.5 |

## Pokémon ordered by weight
| Pokemon | weight (kg) |
| :------ | ----------: |
| Gastly | 0.1 |
| Haunter | 0.1 |
| Hoppip | 0.5 |
| Diglett | 0.8 |
| Castform | 0.8 |
| Igglybuff | 1.0 |
| Koffing | 1.0 |
| Skiploom | 1.0 |
| Chimecho | 1.0 |
| Misdreavus | 1.0 |
| Jirachi | 1.1 |
| Swablu | 1.2 |
| Shedinja | 1.2 |
| Togepi | 1.5 |
| Surskit | 1.7 |
| Pidgey | 1.8 |
| Sunkern | 1.8 |
| Barboach | 1.9 |
| Natu | 2.0 |
| Azurill | 2.0 |
| Spearow | 2.0 |
| Pichu | 2.0 |
| Roselia | 2.0 |
| Murkrow | 2.1 |
| Taillow | 2.3 |
| Shuppet | 2.3 |
| Exeggcute | 2.5 |
| Torchic | 2.5 |
| Lotad | 2.6 |
| Caterpie | 2.9 |
| Cleffa | 3.0 |
| Jumpluff | 3.0 |
| Weedle | 3.2 |
| Togetic | 3.2 |
| Dratini | 3.3 |
| Rattata | 3.5 |
| Wurmple | 3.6 |
| Masquerain | 3.6 |
| Qwilfish | 3.9 |
| Shellder | 4.0 |
| Ditto | 4.0 |
| Mew | 4.0 |
| Seedot | 4.0 |
| Bellsprout | 4.0 |
| Meowth | 4.2 |
| Plusle | 4.2 |
| Minun | 4.2 |
| Shroomish | 4.5 |
| Unown | 5.0 |
| Treecko | 5.0 |
| Corsola | 5.0 |
| Celebi | 5.0 |
| Spinda | 5.0 |
| Paras | 5.4 |
| Oddish | 5.4 |
| Jigglypuff | 5.5 |
| Nincada | 5.5 |
| Bellossom | 5.8 |
| Magnemite | 6.0 |
| Pikachu | 6.0 |
| Smoochum | 6.0 |
| Sentret | 6.0 |
| Chikorita | 6.4 |
| Weepinbell | 6.4 |
| Eevee | 6.5 |
| Krabby | 6.5 |
| Cubone | 6.5 |
| Swinub | 6.5 |
| Ralts | 6.6 |
| Bulbasaur | 6.9 |
| Ekans | 6.9 |
| Nidoran_f | 7.0 |
| Pineco | 7.2 |
| Feebas | 7.4 |
| Omanyte | 7.5 |
| Clefairy | 7.5 |
| Zubat | 7.5 |
| Mudkip | 7.6 |
| Mareep | 7.8 |
| Snubbull | 7.8 |
| Cyndaquil | 7.9 |
| Horsea | 8.0 |
| Marill | 8.5 |
| Wooper | 8.5 |
| Spinarak | 8.5 |
| Charmander | 8.5 |
| Sunflora | 8.5 |
| Gloom | 8.6 |
| Luvdisc | 8.7 |
| Teddiursa | 8.8 |
| Squirtle | 9.0 |
| Nidoran_m | 9.0 |
| Totodile | 9.5 |
| Wingull | 9.5 |
| Weezing | 9.5 |
| Vulpix | 9.9 |
| Metapod | 9.9 |
| Kakuna | 10.0 |
| Silcoon | 10.0 |
| Magikarp | 10.0 |
| Gulpin | 10.3 |
| Voltorb | 10.4 |
| Houndour | 10.8 |
| Ledyba | 10.8 |
| Sableye | 11.0 |
| Skitty | 11.0 |
| Meditite | 11.2 |
| Kabuto | 11.5 |
| Mawile | 11.5 |
| Corphish | 11.5 |
| Cascoon | 11.5 |
| Aipom | 11.5 |
| Chinchou | 12.0 |
| Sandshrew | 12.0 |
| Remoraid | 12.0 |
| Ninjask | 12.0 |
| Wigglytuff | 12.0 |
| Poliwag | 12.4 |
| Anorith | 12.5 |
| Banette | 12.5 |
| Venomoth | 12.5 |
| Ivysaur | 13.0 |
| Flaaffy | 13.3 |
| Poochyena | 13.6 |
| Wynaut | 14.0 |
| Dunsparce | 14.0 |
| Goldeen | 15.0 |
| Trapinch | 15.0 |
| Farfetchd | 15.0 |
| Duskull | 15.0 |
| Xatu | 15.0 |
| Electrike | 15.2 |
| Vibrava | 15.3 |
| Victreebel | 15.5 |
| Bayleef | 15.8 |
| Delibird | 16.0 |
| Whismur | 16.3 |
| Dragonair | 16.5 |
| Snorunt | 16.8 |
| Zigzagoon | 17.5 |
| Illumise | 17.7 |
| Volbeat | 17.7 |
| Raticate | 18.5 |
| Vileplume | 18.6 |
| Growlithe | 19.0 |
| Quilava | 19.0 |
| Charmeleon | 19.0 |
| Machop | 19.5 |
| Nidorino | 19.5 |
| Abra | 19.5 |
| Combusken | 19.5 |
| Psyduck | 19.6 |
| Swellow | 19.8 |
| Ninetales | 19.9 |
| Geodude | 20.0 |
| Nidorina | 20.0 |
| Poliwhirl | 20.0 |
| Kirlia | 20.2 |
| Shuckle | 20.5 |
| Altaria | 20.6 |
| Carvanha | 20.8 |
| Tyrogue | 21.0 |
| Hoothoot | 21.2 |
| Magby | 21.4 |
| Baltoy | 21.5 |
| Grovyle | 21.6 |
| Kecleon | 22.0 |
| Wartortle | 22.5 |
| Lanturn | 22.5 |
| Gorebyss | 22.6 |
| Relicanth | 23.4 |
| Elekid | 23.5 |
| Whiscash | 23.6 |
| Lileep | 23.8 |
| Numel | 24.0 |
| Slakoth | 24.0 |
| Jolteon | 24.5 |
| Flareon | 25.0 |
| Croconaw | 25.0 |
| Seadra | 25.0 |
| Espeon | 26.5 |
| Umbreon | 27.0 |
| Huntail | 27.0 |
| Mankey | 28.0 |
| Marshtomp | 28.0 |
| Sneasel | 28.0 |
| Nuzleaf | 28.0 |
| Pelipper | 28.0 |
| Beautifly | 28.4 |
| Azumarill | 28.5 |
| Octillery | 28.5 |
| Wobbuffet | 28.5 |
| Vaporeon | 29.0 |
| Beedrill | 29.5 |
| Sandslash | 29.5 |
| Parasect | 29.5 |
| Raichu | 30.0 |
| Grimer | 30.0 |
| Venonat | 30.0 |
| Ponyta | 30.0 |
| Pidgeotto | 30.0 |
| Electabuzz | 30.0 |
| Muk | 30.0 |
| Spoink | 30.6 |
| Dusclops | 30.6 |
| Medicham | 31.5 |
| Dustox | 31.6 |
| Persian | 32.0 |
| Primeape | 32.0 |
| Butterfree | 32.0 |
| Drowzee | 32.4 |
| Linoone | 32.5 |
| Porygon2 | 32.5 |
| Lombre | 32.5 |
| Furret | 32.5 |
| Delcatty | 32.6 |
| Crawdaunt | 32.8 |
| Dugtrio | 33.3 |
| Phanpy | 33.5 |
| Ariados | 33.5 |
| Politoed | 33.9 |
| Staryu | 34.5 |
| Chansey | 34.6 |
| Slugma | 35.0 |
| Tangela | 35.0 |
| Omastar | 35.0 |
| Houndoom | 35.0 |
| Ledian | 35.6 |
| Slowpoke | 36.0 |
| Porygon | 36.5 |
| Mightyena | 37.0 |
| Fearow | 38.0 |
| Sudowoodo | 38.0 |
| Yanma | 38.0 |
| Seaking | 39.0 |
| Breloom | 39.2 |
| Doduo | 39.2 |
| Spheal | 39.5 |
| Pidgeot | 39.5 |
| Clefable | 40.0 |
| Latias | 40.0 |
| Manectric | 40.2 |
| Zangoose | 40.3 |
| Loudred | 40.5 |
| Kabutops | 40.5 |
| Gengar | 40.5 |
| Jynx | 40.6 |
| Noctowl | 40.8 |
| Girafarig | 41.5 |
| Bagon | 42.1 |
| Magmar | 44.5 |
| Marowak | 45.0 |
| Tentacool | 45.5 |
| Vigoroth | 46.5 |
| Blissey | 46.8 |
| Absol | 47.0 |
| Hitmontop | 48.0 |
| Alakazam | 48.0 |
| Gardevoir | 48.4 |
| Granbull | 48.7 |
| Hitmonlee | 49.8 |
| Hitmonchan | 50.2 |
| Skarmory | 50.5 |
| Cacnea | 51.3 |
| Blaziken | 52.0 |
| Sceptile | 52.2 |
| Clamperl | 52.5 |
| Seviper | 52.5 |
| Zapdos | 52.6 |
| Poliwrath | 54.0 |
| Heracross | 54.0 |
| Mr_mime | 54.5 |
| Magcargo | 55.0 |
| Pinsir | 55.0 |
| Ludicolo | 55.0 |
| Golbat | 55.0 |
| Tentacruel | 55.0 |
| Articuno | 55.4 |
| Piloswine | 55.8 |
| Scyther | 56.0 |
| Kadabra | 56.5 |
| Smeargle | 58.0 |
| Aerodactyl | 59.0 |
| Shiftry | 59.6 |
| Aron | 60.0 |
| Magneton | 60.0 |
| Nidoqueen | 60.0 |
| Kingler | 60.0 |
| Moltres | 60.0 |
| Latios | 60.0 |
| Cradily | 60.4 |
| Deoxys | 60.8 |
| Ampharos | 61.5 |
| Nidoking | 62.0 |
| Gligar | 64.8 |
| Arbok | 65.0 |
| Lickitung | 65.5 |
| Electrode | 66.6 |
| Armaldo | 68.2 |
| Machoke | 70.5 |
| Stantler | 71.2 |
| Grumpig | 71.5 |
| Larvitar | 72.0 |
| Quagsire | 75.0 |
| Crobat | 75.0 |
| Miltank | 75.5 |
| Hypno | 75.6 |
| Golduck | 76.6 |
| Cacturne | 77.4 |
| Slowbro | 78.5 |
| Typhlosion | 79.5 |
| Slowking | 79.5 |
| Starmie | 80.0 |
| Swalot | 80.0 |
| Kangaskhan | 80.0 |
| Torkoal | 80.4 |
| Swampert | 81.9 |
| Flygon | 82.0 |
| Exploud | 84.0 |
| Dodrio | 85.2 |
| Blastoise | 85.5 |
| Makuhita | 86.4 |
| Sealeo | 87.6 |
| Tauros | 88.4 |
| Sharpedo | 88.8 |
| Feraligatr | 88.8 |
| Seel | 90.0 |
| Charizard | 90.5 |
| Rapidash | 95.0 |
| Beldum | 95.2 |
| Nosepass | 97.0 |
| Venusaur | 100.0 |
| Tropius | 100.0 |
| Meganium | 100.5 |
| Salamence | 102.6 |
| Graveler | 105.0 |
| Claydol | 108.0 |
| Shelgon | 110.5 |
| Rhyhorn | 115.0 |
| Scizor | 118.0 |
| Lairon | 120.0 |
| Donphan | 120.0 |
| Dewgong | 120.0 |
| Rhydon | 120.0 |
| Exeggutor | 120.0 |
| Mewtwo | 122.0 |
| Forretress | 125.8 |
| Ursaring | 125.8 |
| Machamp | 130.0 |
| Wailmer | 130.0 |
| Slaking | 130.5 |
| Cloyster | 132.5 |
| Walrein | 150.6 |
| Pupitar | 152.0 |
| Kingdra | 152.0 |
| Solrock | 154.0 |
| Arcanine | 155.0 |
| Milotic | 162.0 |
| Lunatone | 168.0 |
| Regice | 175.0 |
| Raikou | 178.0 |
| Suicune | 187.0 |
| Entei | 198.0 |
| Ho_oh | 199.0 |
| Tyranitar | 202.0 |
| Metang | 202.5 |
| Registeel | 205.0 |
| Rayquaza | 206.5 |
| Dragonite | 210.0 |
| Onix | 210.0 |
| Lugia | 216.0 |
| Camerupt | 220.0 |
| Mantine | 220.0 |
| Lapras | 220.0 |
| Regirock | 230.0 |
| Gyarados | 235.0 |
| Hariyama | 253.8 |
| Glalie | 256.5 |
| Golem | 300.0 |
| Kyogre | 352.0 |
| Aggron | 360.0 |
| Wailord | 398.0 |
| Steelix | 400.0 |
| Snorlax | 460.0 |
| Metagross | 550.0 |
| Groudon | 950.0 |

## Making this easier
If you have multiple species that you want to add to pokeemerald but don't want to copy and paste or type everything out multiple times, just use this handy program to generate text with the species name in there!
https://github.com/smithk200/making-a-new-pokemon-species-in-pokeemerald
