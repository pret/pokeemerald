# How to add a new trainer front pic

## Content
* [Quick Summary](#quick-summary)
* [The Graphics](#the-graphics)
  * [1. Edit the sprites](#2-edit-the-sprites)
  * [2. Register the sprites](#2-register-the-sprites)
  * [3. Connecting pictures to the data](#2-connecting-pictures-to-the-data)
* [The Data](#the-data)
  * [4. Defining the trainer pic](#2-defining-the-trainer-pic)
* [Usage](#usage)

## Quick Summary
If you've done this before and just need a quick lookup, here's what files you need:
1. Place graphics into [`graphics/trainers/front_pics`](./graphics/trainers/front_pics).
2. Point game to where graphic files are found: [`src/data/graphics/trainers`](./src/data/graphics/trainers.h).
3. Add trainer to [`include/constants/trainers.h`](./include/constants/trainers.h).

## The Graphics

### 1. Edit the sprites
We will start with a graphic that we want to use for our new trainer pic. Unlike with adding Pokémon, the trainer sprites aren't sorted in individual folders, but rather in one folder: [`graphics/trainers/front_pics`](./graphics/trainers/front_pics).  **Trainers sprites cannot have more than 16 colors - this includes the color that will be transparent, which is the first slot of the palette.**

### 2. Register the sprites
Sadly, just putting the image files into the graphics folder is not enough. To use the sprites we have to register them by linking the graphic files in [`src/data/graphics/trainers`](./data/graphics/trainers.h):
```diff
 const u16 gTrainerPalette_RubySapphireBrendan[] = INCGFX_U16("graphics/trainers/palettes/brendan_rs.pal", ".gbapal");

 const u32 gTrainerFrontPic_RubySapphireMay[] = INCGFX_U32("graphics/trainers/front_pics/may_rs.png", ".4bpp.smol");
 const u16 gTrainerPalette_RubySapphireMay[] = INCGFX_U16("graphics/trainers/palettes/may_rs.pal", ".gbapal");
+
+const u32 gTrainerFrontPic_NewOne[] = INCGFX_U32("graphics/trainers/front_pics/new_one.png", ".4bpp.smol");
+const u16 gTrainerPalette_NewOne[] = INCGFX_U16("graphics/trainers/front_pics/new_one.pal", ".gbapal");

 const u8 gTrainerBackPic_Brendan[] = INCGFX_U8("graphics/trainers/back_pics/brendan.png", ".4bpp");
```

### 3. Connecting the Pictures to the Data
The last few things we have to do is prepare the graphics for usage. In [`src/data/graphics/trainers.h`](./src/data/graphics/trainers.h) you'll find the `gTrainerSprites` struct, we need to add the trainer to this. You can just copy the last trainer type defined and edit it, but this is what it does: Connects the new trainer with the image we defined earlier.

So, finally, it needs to look like this:
```diff
 #define TRAINER_SPRITE(trainerPic, picFile, paletteFile, ...)                  \
     [trainerPic] =                                                             \
     {                                                                          \
         .frontPic = {picFile, TRAINER_PIC_SIZE, trainerPic},                   \
         .palette = {paletteFile, trainerPic},                                  \
         .mugshotCoords = {DEFAULT(0, __VA_ARGS__), DEFAULT_2(0, __VA_ARGS__)}, \
         .mugshotRotation = DEFAULT_3(0x200, __VA_ARGS__),                      \
     }

 const struct TrainerSprite gTrainerSprites[] =
 {
     TRAINER_SPRITE(TRAINER_PIC_FRONT_HIKER, gTrainerFrontPic_Hiker, gTrainerPalette_Hiker),
     TRAINER_SPRITE(TRAINER_PIC_FRONT_AQUA_GRUNT_M, gTrainerFrontPic_AquaGruntM, gTrainerPalette_AquaGruntM),
     ...
     TRAINER_SPRITE(TRAINER_PIC_FRONT_RS_MAY, gTrainerFrontPic_RubySapphireMay, gTrainerPalette_RubySapphireMay),
+    TRAINER_SPRITE(TRAINER_PIC_FRONT_NEW_ONE, gTrainerFrontPic_NewOne, gTrainerPalette_NewOne),
 };
```
### The Data
#### 4. Defining the trainer pic
Finally, let's bring it all together by defining our new trainer pic in [`include/constants/trainers.h`](./include/constants/trainers.h):

```diff
    TRAINER_PIC_FRONT_RS_MAY,
+   TRAINER_PIC_FRONT_NEW_ONE,
    TRAINER_PIC_FRONT_COUNT,
    TRAINER_PIC_BACK_BRENDAN = TRAINER_PIC_FRONT_COUNT, // The player back pics are assumed to alternate according to the gender values (MALE/FEMALE)
    TRAINER_PIC_BACK_MAY,
```
Remember to add new front pics before `TRAINER_PIC_FRONT_COUNT`!

## Usage
You can test your trainer type by going to [`src/data/trainers.party`](./src/data/trainers.party) and change the `Pic` field. The syntax should match the constant (`TRAINER_PIC_FRONT_NEW_ONE`) with the underscore replaced by spaces. For example:
```diff
 === TRAINER_BRENDAN_PLACEHOLDER ===
 Name: BRENDAN
 Class: RS Protag
-Pic: RS Brendan
+Pic: New One
 Gender: Male
 Music: Male
 Double Battle: No
```

Otherwise if you use [`src/data/trainers.h`](./src/data/trainers.h), change the `.trainerPic` field instead. For example:
```diff
     [DIFFICULTY_NORMAL][TRAINER_BRENDAN_PLACEHOLDER] =
     {
         .trainerName = _("BRENDAN"),
         .trainerClass = TRAINER_CLASS_RS_PROTAG,
-        .trainerPic = TRAINER_PIC_FRONT_RS_BRENDAN,
+        .trainerPic = TRAINER_PIC_FRONT_NEW_ONE,
         .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
         .doubleBattle = FALSE,
```
