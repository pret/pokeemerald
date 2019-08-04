#include "global.h"
#include "bg.h"
#include "gym_leader_rematch.h"
#include "pokenav.h"
#include "sprite.h"
#include "window.h"
#include "strings.h"
#include "scanline_effect.h"

extern const u32 gPokenavOptions_Gfx[];
extern const u16 gPokenavOptions_Pal[];

const u16 gUnknown_0861FC78[] = INCBIN_U16("graphics/pokenav/bg.gbapal");
const u32 gUnknown_0861FC98[] = INCBIN_U32("graphics/pokenav/bg.4bpp.lz");
const u32 gUnknown_0861FCAC[] = INCBIN_U32("graphics/pokenav/bg.bin.lz");
const u16 gUnknown_0861FD4C[] = INCBIN_U16("graphics/pokenav/outline.gbapal");
const u32 gUnknown_0861FD6C[] = INCBIN_U32("graphics/pokenav/outline.4bpp.lz");
const u32 gUnknown_0861FFF4[] = INCBIN_U32("graphics/pokenav/outline_map.bin.lz");
const u16 gUnknown_08620104[] = INCBIN_U16("graphics/pokenav/blue_light.gbapal");    
const u32 gUnknown_08620124[] = INCBIN_U32("graphics/pokenav/blue_light.4bpp.lz");

const struct BgTemplate gUnknown_08620194[3] = 
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x0F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x17,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

u32 sub_81C9C6C(s32);
u32 sub_81C9CA8(s32);
u32 sub_81C9D44(s32);
u32 sub_81C9DD8(s32);
u32 sub_81C9E58(s32);
u32 sub_81C9EC8(s32);
u32 sub_81C9EF8(s32);
u32 sub_81C9F28(s32);

u32 (*const gUnknown_086201A0[])(s32) = 
{
    NULL,
    sub_81C9C6C,
    sub_81C9CA8,
    sub_81C9D44,
    sub_81C9DD8,
    sub_81C9E58,
    sub_81C9EC8,
    sub_81C9EF8,
    sub_81C9F28
};

const struct CompressedSpriteSheet gUnknown_086201C4[] =
{
    {
        .data = gPokenavOptions_Gfx,
        .size = 0x3400,
        .tag = 0x0003
    },
    {
        .data = gUnknown_08620124,
        .size = 0x0100,
        .tag = 0x0001
    }
};

 const struct SpritePalette gUnknown_086201D4[] = 
 {
    {gPokenavOptions_Pal + 0x00, 4},
    {gPokenavOptions_Pal + 0x10, 5},
    {gPokenavOptions_Pal + 0x20, 6},
    {gPokenavOptions_Pal + 0x30, 7},
    {gPokenavOptions_Pal + 0x40, 8},
    {gUnknown_08620104, 3},
    {}
};

const u16 gUnknown_0862020C[] = {0, 0};
const u16 gUnknown_08620210[] = {0x20, 1};    
const u16 gUnknown_08620214[] = {0x40, 4};    
const u16 gUnknown_08620218[] = {0x60, 2};
const u16 gUnknown_0862021C[] = {0x80, 3};    
const u16 gUnknown_08620220[] = {0xA0, 1};
const u16 gUnknown_08620224[] = {0xC0, 1};
const u16 gUnknown_08620228[] = {0xE0, 4};
const u16 gUnknown_0862022C[] = {0x100, 1};
const u16 gUnknown_08620230[] = {0x120, 2};
const u16 gUnknown_08620234[] = {0x140, 0};
const u16 gUnknown_08620238[] = {0x160, 0};
const u16 gUnknown_0862023C[] = {0x180, 3};

struct UnkStruct_08620240
{
    u16 unk0;
    u16 unk2;
    const u16 *unk4[6];
};

const struct UnkStruct_08620240 gUnknown_08620240[5] = 
{
    {
        0x2A,
        0x14,
        {gUnknown_0862020C, gUnknown_08620210, gUnknown_0862021C, NULL, NULL, NULL}
    },
    {
        0x2A,
        0x14,
        {gUnknown_0862020C, gUnknown_08620210, gUnknown_08620214, gUnknown_0862021C, NULL, NULL}
    },
    {
        0x2A,
        0x14,
        {gUnknown_0862020C, gUnknown_08620210, gUnknown_08620214, gUnknown_08620218, gUnknown_0862021C, NULL}
    },
    {
        0x38,
        0x14,
        {gUnknown_08620220, gUnknown_08620224, gUnknown_0862023C, NULL, NULL, NULL}
    },
    {
        0x28,
        0x10,
        {gUnknown_08620228, gUnknown_0862022C, gUnknown_08620230, gUnknown_08620234, gUnknown_08620238, gUnknown_0862023C}
    },
};

const struct WindowTemplate gUnknown_086202CC = 
{
    .bg = 1,
    .tilemapLeft = 3,
    .tilemapTop = 17,
    .width = 0x18,
    .height = 0x2,
    .paletteNum = 1,
    .baseBlock = 8
};

const u8 *const gUnknown_086202D4[] = 
{
    gUnknown_085EBCC5,
    gUnknown_085EBCE8,
    gUnknown_085EBD01,
    gUnknown_085EBD1C,
    gUnknown_085EBD34,
    gUnknown_085EBD83,
    gUnknown_085EBDA2,
    gUnknown_085EBDBF,
    gUnknown_085EBDDB,
    gUnknown_085EBDEE,
    gUnknown_085EBE06,
    gUnknown_085EBE19,
    gUnknown_085EBE2D,
    gUnknown_085EBE41
};

const u8 gUnknown_0862030C[] = {6, 8, 7};

const u8 gUnknown_0862030F[] = {6, 8, 7, 0, 0};

const struct OamData gUnknown_08620314 = 
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const union AffineAnimCmd gUnknown_0862031C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd gUnknown_0862032C[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_FRAME(0x10, 0x10, 0, 0x12),
    AFFINEANIMCMD_END,
};

const union AffineAnimCmd *const gUnknown_08620344[] =
{
    gUnknown_0862031C,
    gUnknown_0862032C
};

const struct SpriteTemplate gUnknown_0862034C =
{
    .tileTag = 3,
    .paletteTag = 4,
    .oam = &gUnknown_08620314,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gUnknown_08620344,
    .callback = SpriteCallbackDummy,
};

const struct OamData gUnknown_08620364 = 
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

const struct SpriteTemplate gUnknown_0862036C =
{
    .tileTag = 1,
    .paletteTag = 3,
    .oam = &gUnknown_08620364,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

const struct ScanlineEffectParams gUnknown_08620384 = 
{
    (void *)REG_ADDR_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1,
    0
};

bool32 sub_81C98D4(void)
{
    s32 i;

    for (i = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (sub_81CB0C8(i) == gMapHeader.regionMapSectionId
         && sub_81CAE08(i)
         && gSaveBlock1Ptr->trainerRematches[i])
            return TRUE;
    }

    return FALSE;
}
