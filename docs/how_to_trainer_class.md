# How to add a new trainer class

## Content
* [Quick Summary](#quick-summary)
* [The Graphics](#the-graphics)
  * [1. Edit the sprites](#2-edit-the-sprites)
  * [2. Register the sprites](#2-register-the-sprites)
  * [3. The Animation](#2-the-animation)
  * [4. Connecting pictures to the data](#2-connecting-pictures-to-the-data)
* [The Data](#the-data)
  * [5. Defining the trainer class](#2-defining-the-trainer-class)
* [Usage](#usage)

## Quick Summary
(Page contains out of date information, [new instructions for Sprites here](https://github.com/rh-hideout/pokeemerald-expansion/pull/3597).)  
If you've done this before and just need a quick lookup, here's what files you need:
1. GFX into [graphics/trainers/front_pics](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/front_pics)
2. Palette into [graphics/trainers/palettes](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/palettes)
3. Register sprites to [include/graphics.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/graphics.h)
4. Point game to where graphic files are found: [src/data/graphics/trainers](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h)
5. Add animation to: [src/data/trainer_graphics/front_pic_anims.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/trainer_graphics/front_pic_anims.h) 
6. Add the trainer to all three structs in: [src/data/trainer_graphics/front_pic_table.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/trainer_graphics/front_pic_table.h)
7. Add trainer to [include/constants/trainers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/trainers.h)

## The Graphics

### 1. Edit the sprites
We will start with a graphic that we want to use for our new trainer class. Unlike with adding Pokémon, the trainer sprites aren't sorted in individual folders, but rather in one folder:
[graphics/trainers/front_pics](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/graphics/trainers/front_pics)

**Remember to limit yourself to 16 colors including transparency in the first slot!**

Export the pallette and place into the same folder.

### 2. Register the sprites
Sadly, just putting the image files into the graphics folder is not enough. To use the sprites we have to register them, which is kind of tedious. First, create constants for the file paths.
Edit [include/graphics.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/graphics.h):
```diff
extern const u32 gTrainerFrontPic_RubySapphireMay[];
+ extern const u32 gTrainerFrontPic_myTrainerClass[];

extern const u32 gTrainerPalette_Hiker[];
...

...
extern const u32 gTrainerPalette_RubySapphireMay[];
+ extern const u32 gTrainerPalette_myTrainerClass[];

extern const u8 gTrainerBackPic_Brendan[];
```

Now link the graphic files.
[src/data/graphics/trainers](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/graphics/trainers.h):
```diff
const u32 gTrainerPalette_RubySapphireBrendan[] = INCBIN_U32("graphics/trainers/palettes/ruby_sapphire_brendan.gbapal.lz");

const u32 gTrainerFrontPic_RubySapphireMay[] = INCBIN_U32("graphics/trainers/front_pics/ruby_sapphire_may_front_pic.4bpp.lz");
const u32 gTrainerPalette_RubySapphireMay[] = INCBIN_U32("graphics/trainers/palettes/ruby_sapphire_may.gbapal.lz");

+ const u32 gTrainerFrontPic_Sheriff[] = INCBIN_U32("graphics/trainers/front_pics/myTrainerClass_front_pic.4bpp.lz");
+ const u32 gTrainerPalette_Sheriff[] = INCBIN_U32("graphics/trainers/palettes/myTrainerClass.gbapal.lz");

const u8 gTrainerBackPic_Brendan[] = INCBIN_U8("graphics/trainers/back_pics/brendan_back_pic.4
```

### 3. The Animation
Add the Animation of the trainer here:
[src/data/trainer_graphics/front_pic_anims.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/trainer_graphics/front_pic_anims.h)

The trainers don't really move, but in theory they could, it's just that the animation defined for each trainer just shows one frame:

```diff
static const union AnimCmd *const sAnims_RubySapphireMay[] ={
    sAnim_GeneralFrame0,
};

+ static const union AnimCmd *const sAnims_MyTrainerClass[] ={
+     sAnim_GeneralFrame0,
+ };

const union AnimCmd *const *const gTrainerFrontAnimsPtrTable[] =
{
    [TRAINER_PIC_HIKER] = sAnims_Hiker,
    [TRAINER_PIC_AQUA_GRUNT_M] = sAnims_AquaGruntM,
    [TRAINER_PIC_POKEMON_BREEDER_F] = sAnims_PokemonBreederF,
...

...
    [TRAINER_PIC_RS_BRENDAN] = sAnims_RubySapphireBrendan,
    [TRAINER_PIC_RS_MAY] = sAnims_RubySapphireMay,
+     [TRAINER_PIC_MYTRAINERCLASS] = sAnims_MyTrainerClass,
};
```

### 4. Connecting the Pictures to the Data
The last few things we have to do is prepare the graphics for usage. In [src/data/trainer_graphics/front_pic_table.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/trainer_graphics/front_pic_table.h) you'll find the structs, we need to add the trainer to all of these. You can just copy the last trainer type defined and edit it, but as far as I understand, these are what they do:

1. gTrainerFrontPicCoords: Pretty self explanatory. Coordinates like size and offset on the y-axis to position the sprite on screen.
2. gTrainerFrontPicTable: Connects the trainer type with the image we defined earlier.
3. gTrainerFrontPicPaletteTable: Connects the trainer type with the palette we defined earlier.

So, finally, it needs to look like this:
```diff
const struct MonCoords gTrainerFrontPicCoords[] =
{
    [TRAINER_PIC_HIKER] = {.size = 8, .y_offset = 1},
    [TRAINER_PIC_AQUA_GRUNT_M] = {.size = 8, .y_offset = 1},
...

...
    [TRAINER_PIC_RS_BRENDAN] = {.size = 8, .y_offset = 1},
    [TRAINER_PIC_RS_MAY] = {.size = 8, .y_offset = 1},
+     [TRAINER_PIC_MYTRAINERCLASS] = {.size = 8, .y_offset = 1},
};

#define TRAINER_SPRITE(trainerPic, sprite, size) [TRAINER_PIC_##trainerPic] = {sprite, size, TRAINER_PIC_##trainerPic}

const struct CompressedSpriteSheet gTrainerFrontPicTable[] =
{
    TRAINER_SPRITE(HIKER, gTrainerFrontPic_Hiker, 0x800),
    TRAINER_SPRITE(AQUA_GRUNT_M, gTrainerFrontPic_AquaGruntM, 0x800),
    TRAINER_SPRITE(POKEMON_BREEDER_F, gTrainerFrontPic_PokemonBreederF, 0x800),
    TRAINER_SPRITE(COOLTRAINER_M, gTrainerFrontPic_CoolTrainerM, 0x800),
...

...
    TRAINER_SPRITE(RS_BRENDAN, gTrainerFrontPic_RubySapphireBrendan, 0x800),
    TRAINER_SPRITE(RS_MAY, gTrainerFrontPic_RubySapphireMay, 0x800),
+     TRAINER_SPRITE(MYTRAINERCLASS, gTrainerFrontPic_MyTrainerClass, 0x800),
};

#define TRAINER_PAL(trainerPic, pal) [TRAINER_PIC_##trainerPic] = {pal, TRAINER_PIC_##trainerPic}

const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[] =
{
    TRAINER_PAL(HIKER, gTrainerPalette_Hiker),
    TRAINER_PAL(AQUA_GRUNT_M, gTrainerPalette_AquaGruntM),
    TRAINER_PAL(POKEMON_BREEDER_F, gTrainerPalette_PokemonBreederF),
...

...
    TRAINER_PAL(RS_BRENDAN, gTrainerPalette_RubySapphireBrendan),
    TRAINER_PAL(RS_MAY, gTrainerPalette_RubySapphireMay),
+     TRAINER_PAL(MYTRAINERCLASS, gTrainerPalette_MyTrainerClass),
};

```
### The Data
#### 5. Defining the trainer class
Finally, let's bring it all together by defining our new trainer class in [include/constants/trainers.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/include/constants/trainers.h):

```diff
#define TRAINER_PIC_RS_MAY                92
+ #define TRAINER_PIC_MYTRAINERCLASS      93

#define TRAINER_BACK_PIC_BRENDAN                0
#define TRAINER_BACK_PIC_MAY                    1
```
Remember to count the number next to the trainer class up by one!

## Usage
You can test your trainer type by going to [src/data/trainers](https://github.com/rh-hideout/pokeemerald-expansion/blob/master/src/data/trainers.h) and changing a trainer type. For example:
```diff
    [TRAINER_BRENDAN_PLACEHOLDER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RS_PROTAG,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
-       .trainerPic = TRAINER_PIC_RS_BRENDAN,
+       .trainerPic = TRAINER_PIC_MYTRAINERCLASS,
        .trainerName = _("BRENDAN"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = ARRAY_COUNT(sParty_BrendanLinkPlaceholder),
        .party = {.NoItemDefaultMoves = sParty_BrendanLinkPlaceholder},
    },
```
