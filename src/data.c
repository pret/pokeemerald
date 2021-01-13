#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "data.h"
#include "graphics.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/trainers.h"
#include "constants/battle_ai.h"

const u16 gUnknown_082FF1D8[] = INCBIN_U16("graphics/link/minigame_digits.gbapal");
const u32 gUnknown_082FF1F8[] = INCBIN_U32("graphics/link/minigame_digits.4bpp.lz");
// unused
const u32 gUnknown_082FF2B8[] = INCBIN_U32("graphics/link/minigame_digits2.4bpp.lz");

const struct SpriteFrameImage gUnknown_082FF3A8[] =
{
    gHeap + 0x8000, 0x800,
    gHeap + 0x8800, 0x800,
    gHeap + 0x9000, 0x800,
    gHeap + 0x9800, 0x800,
};

const struct SpriteFrameImage gUnknown_082FF3C8[] =
{
    gHeap + 0xA000, 0x800,
    gHeap + 0xA800, 0x800,
    gHeap + 0xB000, 0x800,
    gHeap + 0xB800, 0x800,
};

const struct SpriteFrameImage gUnknown_082FF3E8[] =
{
    gHeap + 0xC000, 0x800,
    gHeap + 0xC800, 0x800,
    gHeap + 0xD000, 0x800,
    gHeap + 0xD800, 0x800,
};

const struct SpriteFrameImage gUnknown_082FF408[] =
{
    gHeap + 0xE000, 0x800,
    gHeap + 0xE800, 0x800,
    gHeap + 0xF000, 0x800,
    gHeap + 0xF800, 0x800,
};

const struct SpriteFrameImage gTrainerBackPicTable_Brendan[] =
{
    gTrainerBackPic_Brendan, 0x0800,
    gTrainerBackPic_Brendan + 0x0800, 0x0800,
    gTrainerBackPic_Brendan + 0x1000, 0x0800,
    gTrainerBackPic_Brendan + 0x1800, 0x0800,
};

const struct SpriteFrameImage gTrainerBackPicTable_May[] =
{
    gTrainerBackPic_May, 0x0800,
    gTrainerBackPic_May + 0x0800, 0x0800,
    gTrainerBackPic_May + 0x1000, 0x0800,
    gTrainerBackPic_May + 0x1800, 0x0800,
};

const struct SpriteFrameImage gTrainerBackPicTable_Red[] =
{
    gTrainerBackPic_Red, 0x0800,
    gTrainerBackPic_Red + 0x0800, 0x0800,
    gTrainerBackPic_Red + 0x1000, 0x0800,
    gTrainerBackPic_Red + 0x1800, 0x0800,
    gTrainerBackPic_Red + 0x2000, 0x0800,
};

const struct SpriteFrameImage gTrainerBackPicTable_Leaf[] =
{
    gTrainerBackPic_Leaf, 0x0800,
    gTrainerBackPic_Leaf + 0x0800, 0x0800,
    gTrainerBackPic_Leaf + 0x1000, 0x0800,
    gTrainerBackPic_Leaf + 0x1800, 0x0800,
    gTrainerBackPic_Leaf + 0x2000, 0x0800,
};

const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireBrendan[] =
{
    gTrainerBackPic_RubySapphireBrendan, 0x0800,
    gTrainerBackPic_RubySapphireBrendan + 0x0800, 0x0800,
    gTrainerBackPic_RubySapphireBrendan + 0x1000, 0x0800,
    gTrainerBackPic_RubySapphireBrendan + 0x1800, 0x0800,
};

const struct SpriteFrameImage gTrainerBackPicTable_RubySapphireMay[] =
{
    gTrainerBackPic_RubySapphireMay, 0x0800,
    gTrainerBackPic_RubySapphireMay + 0x0800, 0x0800,
    gTrainerBackPic_RubySapphireMay + 0x1000, 0x0800,
    gTrainerBackPic_RubySapphireMay + 0x1800, 0x0800,
};

const struct SpriteFrameImage gTrainerBackPicTable_Wally[] =
{
    gTrainerBackPic_Wally, 0x0800,
    gTrainerBackPic_Wally + 0x0800, 0x0800,
    gTrainerBackPic_Wally + 0x1000, 0x0800,
    gTrainerBackPic_Wally + 0x1800, 0x0800,
};

const struct SpriteFrameImage gTrainerBackPicTable_Steven[] =
{
    gTrainerBackPic_Steven, 0x0800,
    gTrainerBackPic_Steven + 0x0800, 0x0800,
    gTrainerBackPic_Steven + 0x1000, 0x0800,
    gTrainerBackPic_Steven + 0x1800, 0x0800,
};

static const union AnimCmd sAnim_GeneralFrame0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_GeneralFrame3[] =
{
    ANIMCMD_FRAME(3, 0),
    ANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF548[] =
{
    AFFINEANIMCMD_FRAME(0x0100, 0x0100, 0x00, 0x00),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF558[] =
{
    AFFINEANIMCMD_FRAME(0xff00, 0x0100, 0x00, 0x00),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF568[] =
{
    AFFINEANIMCMD_FRAME(0x0028, 0x0028, 0x00, 0x00),
    AFFINEANIMCMD_FRAME(0x0012, 0x0012, 0x00, 0x0c),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF580[] =
{
    AFFINEANIMCMD_FRAME(0xfffe, 0xfffe, 0x00, 0x12),
    AFFINEANIMCMD_FRAME(0xfff0, 0xfff0, 0x00, 0x0f),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF598[] =
{
    AFFINEANIMCMD_FRAME(0x00a0, 0x0100, 0x00, 0x00),
    AFFINEANIMCMD_FRAME(0x0004, 0x0000, 0x00, 0x08),
    AFFINEANIMCMD_FRAME(0xfffc, 0x0000, 0x00, 0x08),
    AFFINEANIMCMD_JUMP(1),
};

static const union AffineAnimCmd gUnknown_082FF5B8[] =
{
    AFFINEANIMCMD_FRAME(0x0002, 0x0002, 0x00, 0x14),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF5C8[] =
{
    AFFINEANIMCMD_FRAME(0xfffe, 0xfffe, 0x00, 0x14),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF5D8[] =
{
    AFFINEANIMCMD_FRAME(0x0100, 0x0100, 0x00, 0000),
    AFFINEANIMCMD_FRAME(0xfff0, 0xfff0, 0x00, 0x09),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF5F0[] =
{
    AFFINEANIMCMD_FRAME(0x0004, 0x0004, 0x00, 0x3f),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF600[] =
{
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0xfd, 0x05),
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0x03, 0x05),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_082FF618[] =
{
    gUnknown_082FF548,
    gUnknown_082FF568,
    gUnknown_082FF580,
    gUnknown_082FF598,
    gUnknown_082FF5B8,
    gUnknown_082FF5C8,
    gUnknown_082FF5F0,
    gUnknown_082FF600,
    gUnknown_082FF5D8,
};

static const union AffineAnimCmd gUnknown_082FF63C[] =
{
    AFFINEANIMCMD_FRAME(0xfffc, 0xfffc, 0x04, 0x3f),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF64C[] =
{
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0x03, 0x05),
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0xfd, 0x05),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF664[] =
{
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0xfb, 0x14),
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0x00, 0x14),
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0x05, 0x14),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd gUnknown_082FF684[] =
{
    AFFINEANIMCMD_FRAME(0x0000, 0x0000, 0x09, 0x6e),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_082FF694[] =
{
    gUnknown_082FF548,
    gUnknown_082FF568,
    gUnknown_082FF580,
    gUnknown_082FF598,
    gUnknown_082FF5B8,
    gUnknown_082FF5C8,
    gUnknown_082FF63C,
    gUnknown_082FF64C,
    gUnknown_082FF664,
    gUnknown_082FF5D8,
    gUnknown_082FF684,
};

const union AffineAnimCmd *const gUnknown_082FF6C0[] =
{
    gUnknown_082FF558,
    gUnknown_082FF568,
    gUnknown_082FF580,
    gUnknown_082FF598,
    gUnknown_082FF5B8,
    gUnknown_082FF5C8,
    gUnknown_082FF63C,
    gUnknown_082FF64C,
    gUnknown_082FF664,
    gUnknown_082FF5D8,
    gUnknown_082FF684,
};

static const union AnimCmd gUnknown_082FF6EC[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_082FF6F4[] =
{
    ANIMCMD_FRAME(1, 0),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_082FF6FC[] =
{
    ANIMCMD_FRAME(2, 0),
    ANIMCMD_END,
};

static const union AnimCmd gUnknown_082FF704[] =
{
    ANIMCMD_FRAME(3, 0),
    ANIMCMD_END,
};

const union AnimCmd *const gUnknown_082FF70C[] =
{
    gUnknown_082FF6EC,
    gUnknown_082FF6F4,
    gUnknown_082FF6FC,
    gUnknown_082FF704,
};

#define SPECIES_SPRITE(species, sprite) [SPECIES_##species] = {sprite, 0x800, SPECIES_##species}
#define SPECIES_PAL(species, pal) [SPECIES_##species] = {pal, SPECIES_##species}
#define SPECIES_SHINY_PAL(species, pal) [SPECIES_##species] = {pal, SPECIES_##species + SPECIES_SHINY_TAG}

#include "data/pokemon_graphics/unknown_anims.h"
#include "data/pokemon_graphics/front_pic_coordinates.h"
#include "data/pokemon_graphics/still_front_pic_table.h"
#include "data/pokemon_graphics/back_pic_coordinates.h"

#include "data/pokemon_graphics/back_pic_table.h"
#include "data/pokemon_graphics/palette_table.h"
#include "data/pokemon_graphics/shiny_palette_table.h"

#include "data/trainer_graphics/front_pic_anims.h"
#include "data/trainer_graphics/front_pic_tables.h"
#include "data/trainer_graphics/back_pic_anims.h"
#include "data/trainer_graphics/back_pic_tables.h"

#include "data/pokemon_graphics/enemy_mon_elevation.h"
#include "data/pokemon_graphics/front_pic_anims.h"
#include "data/pokemon_graphics/front_pic_table.h"

// unused
const u32 gUnknown830AF4C[] =
{
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000088, 0x00000888, 0x00000888, 0x00000886,
    0x00000888, 0x00000886, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000886, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000886, 0x00000886,
    0x00000888, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000888, 0x00000886, 0x00000888,
    0x00000888, 0x00000888, 0x00000886, 0x00000886,
    0x00000888, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000886, 0x00000886, 0x00000088,
    0x00000886, 0x00000886, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000886, 0x00000888, 0x00000088, 0x00000088,
    0x00000888, 0x00000888, 0x00000888, 0x00000886,
    0x00000888, 0x00000888, 0x00000888, 0x00000886,
    0x00000886, 0x00000886, 0x00000886, 0x00000886,
    0x00000886, 0x00000886, 0x00000888, 0x00000888,
    0x00000886, 0x00000886, 0x00000886, 0x00000886,
    0x00000886, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000886, 0x00000886, 0x00000888,
    0x00000886, 0x00000886, 0x00000888, 0x00000888,
    0x00000088, 0x00000088, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000886, 0x00000886, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000088, 0x00000886,
    0x00000888, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000888, 0x00000886, 0x00000888,
    0x00000088, 0x00000088, 0x00000886, 0x00000886,
    0x00000088, 0x00000088, 0x00000888, 0x00000886,
    0x00000886, 0x00000888, 0x00000888, 0x00000088,
    0x00000888, 0x00000886, 0x00000886, 0x00000888,
    0x00000886, 0x00000888, 0x00000888, 0x00000886,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000088, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000088, 0x00000888, 0x00000888, 0x00000886,
    0x00000886, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000886,
    0x00000888, 0x00000886, 0x00000088, 0x00000088,
    0x00000088, 0x00000888, 0x00000088, 0x00000888,
    0x00000888, 0x00000088, 0x00000088, 0x00000888,
    0x00000886, 0x00000888, 0x00000886, 0x00000886,
    0x00000886, 0x00000888, 0x00000888, 0x00000888,
    0x00000088, 0x00000888, 0x00000888, 0x00000888,
    0x00000088, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000088, 0x00000088,
    0x00000886, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000088, 0x00000888,
    0x00000886, 0x00000888, 0x00000088, 0x00000088,
    0x00000888, 0x00000888, 0x00000088, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000088,
    0x00000888, 0x00000888, 0x00000088, 0x00000088,
    0x00000088, 0x00000888, 0x00000088, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000886, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000886, 0x00000886, 0x00000886,
    0x00000088, 0x00000088, 0x00000088, 0x00000886,
    0x00000088, 0x00000886, 0x00000886, 0x00000886,
    0x00000088, 0x00000886, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000886,
    0x00000886, 0x00000886, 0x00000888, 0x00000888,
    0x00000886, 0x00000886, 0x00000886, 0x00000886,
    0x00000088, 0x00000088, 0x00000886, 0x00000886,
    0x00001882, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000886, 0x00000886, 0x00000886,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000886, 0x00000088, 0x00000886, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000886, 0x00000886,
    0x00000088, 0x00000088, 0x00000088, 0x00000886,
    0x00000886, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000886, 0x00000088,
    0x00000088, 0x00000886, 0x00000886, 0x00000886,
    0x00000886, 0x00000886, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000886,
    0x00000886, 0x00000886, 0x00000886, 0x00000088,
    0x00000886, 0x00000088, 0x00000886, 0x00000886,
    0x00000886, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000886, 0x00000886,
    0x00000886, 0x00000888, 0x00000886, 0x00000886,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000886, 0x00000886, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000088, 0x00000088, 0x00000088,
    0x00000088, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
    0x00000888, 0x00000888, 0x00000888, 0x00000888,
};

#include "data/trainer_parties.h"
#include "data/text/trainer_class_names.h"
#include "data/trainers.h"
#include "data/text/species_names.h"
#include "data/text/move_names.h"
