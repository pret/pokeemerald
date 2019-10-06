#include "global.h"
#include "bg.h"
#include "m4a.h"
#include "main.h"
#include "malloc.h"
#include "palette.h"
#include "pokedex_cry_screen.h"
#include "sound.h"
#include "trig.h"
#include "window.h"

struct PokedexCryVolumeMeter {
    s8 unk0;
    s8 unk1;
    u8 unk2;
    u16 needleSpriteId;
};

struct PokedexCryScreen
{
    u8 unk0[16];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u16 unk14;
    u8 unk16;
    u16 species;
    u8 unk1A;
    u8 unk1B;
};

static void sub_8145588(u16);
static void sub_81455A8(void);
static void sub_814560C(void);
static void sub_8145648(u8);
static void sub_81456A8(u8, u8);
static void sub_8145814(u8);
static void sub_8145824(u8, s16, u8);
static void sub_814596C(struct Sprite *);
static void sub_8145B24(s8);

// IWRAM common
u8 gDexCryScreenState;

// EWRAM vars
static EWRAM_DATA struct PokedexCryScreen *sDexCryScreen = NULL;
static EWRAM_DATA u8 *sCryWaveformWindowTiledata = NULL;
static EWRAM_DATA struct PokedexCryVolumeMeter *sCryVolumeMeter = NULL;

const u16 CryMeterNeedlePalette[] = INCBIN_U16("graphics/pokedex/cry_meter_needle.gbapal");
const u8 CryMeterNeedleTiles[] = INCBIN_U8("graphics/pokedex/cry_meter_needle.4bpp");

const u16 gUnknown_085B8378[] = INCBIN_U16("graphics/pokedex/cry_meter_map.bin");
const u16 gUnknown_085B8418[] = INCBIN_U16("graphics/pokedex/cry_meter.gbapal");
const u8 gUnknown_085B8438[] = INCBIN_U8("graphics/pokedex/cry_meter.4bpp.lz");

const u16 gUnknown_085B8770[][72] =
{
    {
        0x0000, 0x0004, 0x0008, 0x000C, 0x0010, 0x0014, 0x0018, 0x001C,
        0x0400, 0x0404, 0x0408, 0x040C, 0x0410, 0x0414, 0x0418, 0x041C,
        0x0800, 0x0804, 0x0808, 0x080C, 0x0810, 0x0814, 0x0818, 0x081C,
        0x0C00, 0x0C04, 0x0C08, 0x0C0C, 0x0C10, 0x0C14, 0x0C18, 0x0C1C,
        0x1000, 0x1004, 0x1008, 0x100C, 0x1010, 0x1014, 0x1018, 0x101C,
        0x1400, 0x1404, 0x1408, 0x140C, 0x1410, 0x1414, 0x1418, 0x141C,
        0x1800, 0x1804, 0x1808, 0x180C, 0x1810, 0x1814, 0x1818, 0x181C,
        0x1C00, 0x1C04, 0x1C08, 0x1C0C, 0x1C10, 0x1C14, 0x1C18, 0x1C1C,
        0x2000, 0x2004, 0x2008, 0x200C, 0x2010, 0x2014, 0x2018, 0x201C
    }, {
        0x0000, 0x0004, 0x0008, 0x000C, 0x0010, 0x0014, 0x0018, 0x001C,
        0x0400, 0x0404, 0x0408, 0x040C, 0x0410, 0x0414, 0x0418, 0x041C,
        0x0800, 0x0804, 0x0808, 0x080C, 0x0810, 0x0814, 0x0818, 0x081C,
        0x0C00, 0x0C04, 0x0C08, 0x0C0C, 0x0C10, 0x0C14, 0x0C18, 0x0C1C,
        0x1000, 0x1004, 0x1008, 0x100C, 0x1010, 0x1014, 0x1018, 0x101C,
        0x1400, 0x1404, 0x1408, 0x140C, 0x1410, 0x1414, 0x1418, 0x141C,
        0x1800, 0x1804, 0x1808, 0x180C, 0x1810, 0x1814, 0x1818, 0x181C,
        0x1C00, 0x1C04, 0x1C08, 0x1C0C, 0x1C10, 0x1C14, 0x1C18, 0x1C1C,
        0x2000, 0x2004, 0x2008, 0x200C, 0x2010, 0x2014, 0x2018, 0x201C
    }, {
        0x0001, 0x0005, 0x0009, 0x000D, 0x0011, 0x0015, 0x0019, 0x001D,
        0x0401, 0x0405, 0x0409, 0x040D, 0x0411, 0x0415, 0x0419, 0x041D,
        0x0801, 0x0805, 0x0809, 0x080D, 0x0811, 0x0815, 0x0819, 0x081D,
        0x0C01, 0x0C05, 0x0C09, 0x0C0D, 0x0C11, 0x0C15, 0x0C19, 0x0C1D,
        0x1001, 0x1005, 0x1009, 0x100D, 0x1011, 0x1015, 0x1019, 0x101D,
        0x1401, 0x1405, 0x1409, 0x140D, 0x1411, 0x1415, 0x1419, 0x141D,
        0x1801, 0x1805, 0x1809, 0x180D, 0x1811, 0x1815, 0x1819, 0x181D,
        0x1C01, 0x1C05, 0x1C09, 0x1C0D, 0x1C11, 0x1C15, 0x1C19, 0x1C1D,
        0x2001, 0x2005, 0x2009, 0x200D, 0x2011, 0x2015, 0x2019, 0x201D
    }, {
        0x0001, 0x0005, 0x0009, 0x000D, 0x0011, 0x0015, 0x0019, 0x001D,
        0x0401, 0x0405, 0x0409, 0x040D, 0x0411, 0x0415, 0x0419, 0x041D,
        0x0801, 0x0805, 0x0809, 0x080D, 0x0811, 0x0815, 0x0819, 0x081D,
        0x0C01, 0x0C05, 0x0C09, 0x0C0D, 0x0C11, 0x0C15, 0x0C19, 0x0C1D,
        0x1001, 0x1005, 0x1009, 0x100D, 0x1011, 0x1015, 0x1019, 0x101D,
        0x1401, 0x1405, 0x1409, 0x140D, 0x1411, 0x1415, 0x1419, 0x141D,
        0x1801, 0x1805, 0x1809, 0x180D, 0x1811, 0x1815, 0x1819, 0x181D,
        0x1C01, 0x1C05, 0x1C09, 0x1C0D, 0x1C11, 0x1C15, 0x1C19, 0x1C1D,
        0x2001, 0x2005, 0x2009, 0x200D, 0x2011, 0x2015, 0x2019, 0x201D
    }, {
        0x0002, 0x0006, 0x000A, 0x000E, 0x0012, 0x0016, 0x001A, 0x001E,
        0x0402, 0x0406, 0x040A, 0x040E, 0x0412, 0x0416, 0x041A, 0x041E,
        0x0802, 0x0806, 0x080A, 0x080E, 0x0812, 0x0816, 0x081A, 0x081E,
        0x0C02, 0x0C06, 0x0C0A, 0x0C0E, 0x0C12, 0x0C16, 0x0C1A, 0x0C1E,
        0x1002, 0x1006, 0x100A, 0x100E, 0x1012, 0x1016, 0x101A, 0x101E,
        0x1402, 0x1406, 0x140A, 0x140E, 0x1412, 0x1416, 0x141A, 0x141E,
        0x1802, 0x1806, 0x180A, 0x180E, 0x1812, 0x1816, 0x181A, 0x181E,
        0x1C02, 0x1C06, 0x1C0A, 0x1C0E, 0x1C12, 0x1C16, 0x1C1A, 0x1C1E,
        0x2002, 0x2006, 0x200A, 0x200E, 0x2012, 0x2016, 0x201A, 0x201E
    }, {
        0x0002, 0x0006, 0x000A, 0x000E, 0x0012, 0x0016, 0x001A, 0x001E,
        0x0402, 0x0406, 0x040A, 0x040E, 0x0412, 0x0416, 0x041A, 0x041E,
        0x0802, 0x0806, 0x080A, 0x080E, 0x0812, 0x0816, 0x081A, 0x081E,
        0x0C02, 0x0C06, 0x0C0A, 0x0C0E, 0x0C12, 0x0C16, 0x0C1A, 0x0C1E,
        0x1002, 0x1006, 0x100A, 0x100E, 0x1012, 0x1016, 0x101A, 0x101E,
        0x1402, 0x1406, 0x140A, 0x140E, 0x1412, 0x1416, 0x141A, 0x141E,
        0x1802, 0x1806, 0x180A, 0x180E, 0x1812, 0x1816, 0x181A, 0x181E,
        0x1C02, 0x1C06, 0x1C0A, 0x1C0E, 0x1C12, 0x1C16, 0x1C1A, 0x1C1E,
        0x2002, 0x2006, 0x200A, 0x200E, 0x2012, 0x2016, 0x201A, 0x201E
    }, {
        0x0003, 0x0007, 0x000B, 0x000F, 0x0013, 0x0017, 0x001B, 0x001F,
        0x0403, 0x0407, 0x040B, 0x040F, 0x0413, 0x0417, 0x041B, 0x041F,
        0x0803, 0x0807, 0x080B, 0x080F, 0x0813, 0x0817, 0x081B, 0x081F,
        0x0C03, 0x0C07, 0x0C0B, 0x0C0F, 0x0C13, 0x0C17, 0x0C1B, 0x0C1F,
        0x1003, 0x1007, 0x100B, 0x100F, 0x1013, 0x1017, 0x101B, 0x101F,
        0x1403, 0x1407, 0x140B, 0x140F, 0x1413, 0x1417, 0x141B, 0x141F,
        0x1803, 0x1807, 0x180B, 0x180F, 0x1813, 0x1817, 0x181B, 0x181F,
        0x1C03, 0x1C07, 0x1C0B, 0x1C0F, 0x1C13, 0x1C17, 0x1C1B, 0x1C1F,
        0x2003, 0x2007, 0x200B, 0x200F, 0x2013, 0x2017, 0x201B, 0x201F
    }, {
        0x0003, 0x0007, 0x000B, 0x000F, 0x0013, 0x0017, 0x001B, 0x001F,
        0x0403, 0x0407, 0x040B, 0x040F, 0x0413, 0x0417, 0x041B, 0x041F,
        0x0803, 0x0807, 0x080B, 0x080F, 0x0813, 0x0817, 0x081B, 0x081F,
        0x0C03, 0x0C07, 0x0C0B, 0x0C0F, 0x0C13, 0x0C17, 0x0C1B, 0x0C1F,
        0x1003, 0x1007, 0x100B, 0x100F, 0x1013, 0x1017, 0x101B, 0x101F,
        0x1403, 0x1407, 0x140B, 0x140F, 0x1413, 0x1417, 0x141B, 0x141F,
        0x1803, 0x1807, 0x180B, 0x180F, 0x1813, 0x1817, 0x181B, 0x181F,
        0x1C03, 0x1C07, 0x1C0B, 0x1C0F, 0x1C13, 0x1C17, 0x1C1B, 0x1C1F,
        0x2003, 0x2007, 0x200B, 0x200F, 0x2013, 0x2017, 0x201B, 0x201F
    }
};

const u16 gUnknown_085B8BF0[] = INCBIN_U16("graphics/pokedex/85B8C10.gbapal");
const u8 gUnknown_085B8C10[] = INCBIN_U8("graphics/pokedex/85B8C10.4bpp");

const u8 gUnknown_085B8C30[] = {0xF0, 0x0F};
const u8 gUnknown_085B8C32[][16] =
{
    {
        0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 0x08,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
    }, {
        0xF0, 0xE0, 0xD0, 0xC0, 0xB0, 0xA0, 0x90, 0x80,
        0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0
    }
};

const union AnimCmd gSpriteAnim_85B8C54[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

const union AnimCmd *const gSpriteAnimTable_85B8C5C[] =
{
    gSpriteAnim_85B8C54
};

const struct OamData gOamData_85B8C60 =
{
    .y = 160,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

const struct SpriteTemplate gUnknown_085B8C68 =
{
    0x2000,
    0x2000,
    &gOamData_85B8C60,
    gSpriteAnimTable_85B8C5C,
    NULL,
    gDummySpriteAffineAnimTable,
    sub_814596C
};

const struct SpriteSheet gCryMeterNeedleSpriteSheets[] =
{
    {CryMeterNeedleTiles, 0x800, 0x2000},
    {}
};

const struct SpritePalette gCryMeterNeedleSpritePalettes[] =
{
    {CryMeterNeedlePalette, 0x2000},
    {}
};

bool8 sub_8145354(struct CryRelatedStruct *arg0, u8 windowId)
{
    u8 i;
    u8 retVal = FALSE;

    switch (gDexCryScreenState)
    {
    case 0:
        if (!sDexCryScreen)
        {
            sDexCryScreen = AllocZeroed(sizeof(*sDexCryScreen));
            sCryWaveformWindowTiledata = (u8*)GetWindowAttribute(windowId, WINDOW_TILE_DATA);
        }

        sDexCryScreen->unk14 = arg0->unk0;
        sDexCryScreen->unk16 = arg0->yPos;
        sDexCryScreen->unk1A = 0;
        sDexCryScreen->unk1B = 0;
        sDexCryScreen->unk10 = 0;
        sDexCryScreen->unk12 = 28;
        sDexCryScreen->unk11 = 0;
        sub_8145824(windowId, -8 * arg0->xPos, 1);
        for (i = 0; i < 224; i++)
            CopyToWindowPixelBuffer(windowId, gUnknown_085B8C10, TILE_SIZE_4BPP, i);

        gDexCryScreenState++;
        break;
    case 1:
        for (i = 0; i < sDexCryScreen->unk16 * 8; i++)
            sub_81456A8(i, 0);
        
        gDexCryScreenState++;
        break;
    case 2:
        sub_8145814(windowId);
        LoadPalette(gUnknown_085B8BF0, arg0->paletteNo * 16, 32);
        retVal = TRUE;
        break;
    }

    return retVal;
}

void sub_814545C(u8 windowId)
{
    u8 var0;

    sub_8145814(windowId);
    sub_8145648(windowId);
    if (sDexCryScreen->unk1B)
        sDexCryScreen->unk1B--;

    if (sDexCryScreen->unk1A)
    {
        sDexCryScreen->unk1A--;
        if (!sDexCryScreen->unk1A)
        {
            sub_8145588(sDexCryScreen->species);
            sub_814560C();
            return;
        }
    }

    if (sDexCryScreen->unk10 == 0)
    {
        sub_814560C();
        return;
    }
    
    if (sDexCryScreen->unk10 == 1)
    {
        sub_81455A8();
    }
    else if (sDexCryScreen->unk10 > 8)
    {
        if (!IsCryPlaying())
        {
            sub_814560C();
            sDexCryScreen->unk10 = 0;
            return;
        }

        sub_81455A8();
        sDexCryScreen->unk10 = 1;
    }

    var0 = 2 * (sDexCryScreen->unk10 - 1);
    sub_81456A8(sDexCryScreen->unk16 * 8 + sDexCryScreen->unk11 - 2, sDexCryScreen->unk0[var0]);
    sub_81456A8(sDexCryScreen->unk16 * 8 + sDexCryScreen->unk11 - 1, sDexCryScreen->unk0[var0 + 1]);
    sDexCryScreen->unk10++;
}

void sub_8145534(u16 species)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE && !sDexCryScreen->unk1A)
    {
        if (!sDexCryScreen->unk1B)
        {
            sDexCryScreen->unk1B = 4;
            if (IsCryPlaying() == TRUE)
            {
                StopCry();
                sDexCryScreen->species = species;
                sDexCryScreen->unk1A = 2;
            }
            else
            {
                sub_8145588(species);
            }
        }
    }
}

static void sub_8145588(u16 species)
{
    PlayCry2(species, 0, 0x7d, 10);
    sDexCryScreen->unk10 = 1;
}

static void sub_81455A8(void)
{
    u8 i;
    s8 *baseBuffer;
    s8 *buffer;

    if (gPcmDmaCounter < 2)
        baseBuffer = gSoundInfo.pcmBuffer;
    else
        baseBuffer = gSoundInfo.pcmBuffer + (gSoundInfo.pcmDmaPeriod + 1 - gPcmDmaCounter) * gSoundInfo.pcmSamplesPerVBlank;

    buffer = baseBuffer + 0x630;
    for (i = 0; i < 16; i++)
        sDexCryScreen->unk0[i] = buffer[i * 2] * 2;
}

static void sub_814560C(void)
{
    sub_81456A8(sDexCryScreen->unk16 * 8 + sDexCryScreen->unk11 - 2, 0);
    sub_81456A8(sDexCryScreen->unk16 * 8 + sDexCryScreen->unk11 - 1, 0);
}

static void sub_8145648(u8 windowId)
{
    u8 i;
    u16 offset;

    sub_8145824(windowId, sDexCryScreen->unk11, 0);
    sDexCryScreen->unk11 += 2;
    offset = (sDexCryScreen->unk11 / 8 + sDexCryScreen->unk16 + 1) % 32;
    for (i = 0; i < 7; i++)
        CopyToWindowPixelBuffer(windowId, gUnknown_085B8C10, TILE_SIZE_4BPP, offset + (i * TILE_SIZE_4BPP));
}

static void sub_81456A8(u8 a0, u8 a1)
{
    u8 sp0;
    u8 r6;
    u8 r8;
    u16 offset;
    u16 r1;
    u8 i;

    r1 = (a1 + 127) * 256;
    i = r1 / 1152.0;
    if (i > 55)
        i = 55;
    sp0 = i;
    r6 = a0 & 1;
    if (i > sDexCryScreen->unk12)
    {
        do
        {
            offset = gUnknown_085B8770[a0 & 0x7][i] + (a0 / 8) * TILE_SIZE_4BPP;
            sCryWaveformWindowTiledata[offset] &= gUnknown_085B8C30[r6];
            sCryWaveformWindowTiledata[offset] |= gUnknown_085B8C32[r6][((i / 3) - 1) & 0x0F];
            i--;
        } while (i > sDexCryScreen->unk12);
    }
    else
    {
        do
        {
            offset = gUnknown_085B8770[a0 & 0x7][i] + (a0 / 8) * TILE_SIZE_4BPP;
            sCryWaveformWindowTiledata[offset] &= gUnknown_085B8C30[r6];
            sCryWaveformWindowTiledata[offset] |= gUnknown_085B8C32[r6][((i / 3) - 1) & 0x0F];
            i++;
        } while (i < sDexCryScreen->unk12);
    }

    sDexCryScreen->unk12 = sp0;
}

static void sub_8145814(u8 windowId)
{
    CopyWindowToVram(windowId, 2);
}

static void sub_8145824(u8 windowId, s16 arg1, u8 arg2)
{
    if (!arg2)
    {
        u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
        ChangeBgX(bg, arg1 << 8, 0);
    }
}

bool8 sub_8145850(struct CryRelatedStruct *arg0, u8 windowId)
{
    int retVal = FALSE;

    switch (gDexCryScreenState)
    {
    case 0:
        if (!sCryVolumeMeter)
            sCryVolumeMeter = AllocZeroed(sizeof(*sCryVolumeMeter));

        CopyToWindowPixelBuffer(windowId, gUnknown_085B8438, 0, 0);
        LoadPalette(gUnknown_085B8418, arg0->paletteNo * 16, 32);
        gDexCryScreenState++;
        break;
    case 1:
        LoadSpriteSheets(gCryMeterNeedleSpriteSheets);
        LoadSpritePalettes(gCryMeterNeedleSpritePalettes);
        sCryVolumeMeter->needleSpriteId = CreateSprite(&gUnknown_085B8C68, 40 + arg0->xPos * 8, 56 + arg0->yPos * 8, 1);
        sCryVolumeMeter->unk0 = 0x20;
        sCryVolumeMeter->unk1 = 0x20;
        sCryVolumeMeter->unk2 = 0;
        retVal = TRUE;
        break;
    }

    return retVal;
}

void sub_8145914(void)
{
    FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(gSprites[sCryVolumeMeter->needleSpriteId].oam.paletteNum));
    DestroySprite(gSprites + sCryVolumeMeter->needleSpriteId);
    FREE_AND_SET_NULL(sDexCryScreen);
    FREE_AND_SET_NULL(sCryVolumeMeter);
}

static void sub_814596C(struct Sprite *sprite)
{
    u16 i;
    s8 r3;
    s16 x;
    s16 y;
    struct ObjAffineSrcData affine;
    struct OamMatrix matrix;
    u8 *var0;

    gSprites[sCryVolumeMeter->needleSpriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[sCryVolumeMeter->needleSpriteId].oam.affineParam = 0;
    switch (sDexCryScreen->unk10)
    {
        case 0:
            sCryVolumeMeter->unk1 = 0x20;
            if (sCryVolumeMeter->unk0 > 0)
            {
                if (sCryVolumeMeter->unk2 != 1)
                    sCryVolumeMeter->unk2--;
            }
            else
                sCryVolumeMeter->unk2 = 5;
            break;
        case 2:
            r3 = 0;
            for (i = 0; i < 16; i++)
            {
                if (r3 < sDexCryScreen->unk0[i])
                    r3 = sDexCryScreen->unk0[i];
            }
            sub_8145B24(r3 * 0xd0 / 0x100);
            break;
        case 6:
            var0 = &sDexCryScreen->unk0[10];
            sub_8145B24(*var0 * 0xd0 / 0x100);
            break;
    }

    if (sCryVolumeMeter->unk0 == sCryVolumeMeter->unk1)
    {
        // empty block
    }
    else if (sCryVolumeMeter->unk0 < sCryVolumeMeter->unk1)
    {
        sCryVolumeMeter->unk0 += sCryVolumeMeter->unk2;
        if (sCryVolumeMeter->unk0 > sCryVolumeMeter->unk1)
        {
            sCryVolumeMeter->unk0 = sCryVolumeMeter->unk1;
            sCryVolumeMeter->unk1 = 0;
        }
    }
    else
    {
        sCryVolumeMeter->unk0 -= sCryVolumeMeter->unk2;
        if (sCryVolumeMeter->unk0 < sCryVolumeMeter->unk1)
        {
            sCryVolumeMeter->unk0 = sCryVolumeMeter->unk1;
            sCryVolumeMeter->unk1 = 0;
        }
    }

    affine.xScale = 0x100;
    affine.yScale = 0x100;
    affine.rotation = sCryVolumeMeter->unk0 * 256;
    ObjAffineSet(&affine, &matrix, 1, 2);
    SetOamMatrix(0, matrix.a, matrix.b, matrix.c, matrix.d);
    x = gSineTable[((sCryVolumeMeter->unk0 + 0x7F) & 0xFF)];
    y = gSineTable[((sCryVolumeMeter->unk0 + 0x7F) & 0xFF) + 0x40];
    sprite->pos2.x = x * 24 / 256;
    sprite->pos2.y = y * 24 / 256;
}

static void sub_8145B24(s8 a0)
{
    u16 r2 = (0x20 - a0) & 0xff;
    if (r2 > 0x20 && r2 < 0xe0)
        r2 = 0xe0;

    sCryVolumeMeter->unk1 = r2;
    sCryVolumeMeter->unk2 = 5;
}

