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

// Cry meter needle positions
//
//          0
//    32   .  .  -32
//      .        .
// 64  .          . -64
//     .          .
//      .        .
//    96   .  .  -96
//         127
//
#define MIN_NEEDLE_POS  32
#define MAX_NEEDLE_POS -32

#define NEEDLE_MOVE_INCREMENT  5

#define WAVEFORM_WINDOW_HEIGHT 56

#define TAG_NEEDLE 0x2000

struct PokedexCryMeterNeedle {
    s8 rotation;
    s8 targetRotation;
    u8 moveIncrement;
    u16 spriteId;
};

struct PokedexCryScreen
{
    u8 cryWaveformBuffer[16];
    u8 cryState;
    u8 playhead;
    u8 waveformPreviousY;
    u16 unk; // Never read
    u8 playStartPos;
    u16 species;
    u8 cryOverrideCountdown;
    u8 cryRepeatDelay;
};

static void PlayCryScreenCry(u16);
static void BufferCryWaveformSegment(void);
static void DrawWaveformFlatline(void);
static void AdvancePlayhead(u8);
static void DrawWaveformSegment(u8, u8);
static void DrawWaveformWindow(u8);
static void ShiftWaveformOver(u8, s16, bool8);
static void SpriteCB_CryMeterNeedle(struct Sprite *);
static void SetCryMeterNeedleTarget(s8);

// IWRAM common
COMMON_DATA u8 gDexCryScreenState = 0;

// EWRAM vars
static EWRAM_DATA struct PokedexCryScreen *sDexCryScreen = NULL;
static EWRAM_DATA u8 *sCryWaveformWindowTiledata = NULL;
static EWRAM_DATA struct PokedexCryMeterNeedle *sCryMeterNeedle = NULL;

static const u16 sCryMeterNeedle_Pal[] = INCBIN_U16("graphics/pokedex/cry_meter_needle.gbapal");
static const u8 sCryMeterNeedle_Gfx[] = INCBIN_U8("graphics/pokedex/cry_meter_needle.4bpp");

static const u16 sCryMeter_Tilemap[] = INCBIN_U16("graphics/pokedex/cry_meter_map.bin"); // Unused
static const u16 sCryMeter_Pal[] = INCBIN_U16("graphics/pokedex/cry_meter.gbapal");
static const u8 sCryMeter_Gfx[] = INCBIN_U8("graphics/pokedex/cry_meter.4bpp.lz");

static const u16 sWaveformOffsets[][72] =
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

static const u16 sCryScreenBg_Pal[] = INCBIN_U16("graphics/pokedex/cry_screen_bg.gbapal");
static const u8 sCryScreenBg_Gfx[] = INCBIN_U8("graphics/pokedex/cry_screen_bg.4bpp");

static const u8 sWaveformTileDataNybbleMasks[] = {0xF0, 0x0F};

// Waveform is blue in the middle (8) grading to white at peaks (15)
// Split into two arrays for the two vertical slice halves
static const u8 sWaveformColor[][16] =
{
    {
        15,      14,      13,      12,      11,      10,       9,       8,
         8,       9,      10,      11,      12,      13,      14,      15,
    }, {
        15 << 4, 14 << 4, 13 << 4, 12 << 4, 11 << 4, 10 << 4,  9 << 4,  8 << 4,
         8 << 4,  9 << 4, 10 << 4, 11 << 4, 12 << 4, 13 << 4, 14 << 4, 15 << 4,
    }
};

static const union AnimCmd sSpriteAnim_CryMeterNeedle[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_CryMeterNeedle[] =
{
    sSpriteAnim_CryMeterNeedle
};

static const struct OamData sOamData_CryMeterNeedle =
{
    .y = DISPLAY_HEIGHT,
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

static const struct SpriteTemplate sCryMeterNeedleSpriteTemplate =
{
    .tileTag = TAG_NEEDLE,
    .paletteTag = TAG_NEEDLE,
    .oam = &sOamData_CryMeterNeedle,
    .anims = sSpriteAnimTable_CryMeterNeedle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CryMeterNeedle
};

static const struct SpriteSheet sCryMeterNeedleSpriteSheets[] =
{
    {sCryMeterNeedle_Gfx, sizeof(sCryMeterNeedle_Gfx), TAG_NEEDLE},
    {}
};

static const struct SpritePalette sCryMeterNeedleSpritePalettes[] =
{
    {sCryMeterNeedle_Pal, TAG_NEEDLE},
    {}
};

bool8 LoadCryWaveformWindow(struct CryScreenWindow *window, u8 windowId)
{
    u8 i;
    u8 finished = FALSE;

    switch (gDexCryScreenState)
    {
    case 0:
        if (!sDexCryScreen)
        {
            sDexCryScreen = AllocZeroed(sizeof(*sDexCryScreen));
            sCryWaveformWindowTiledata = (u8 *)GetWindowAttribute(windowId, WINDOW_TILE_DATA);
        }

        sDexCryScreen->unk = window->unk0;
        sDexCryScreen->playStartPos = window->yPos;
        sDexCryScreen->cryOverrideCountdown = 0;
        sDexCryScreen->cryRepeatDelay = 0;
        sDexCryScreen->cryState = 0;
        sDexCryScreen->waveformPreviousY = WAVEFORM_WINDOW_HEIGHT / 2;
        sDexCryScreen->playhead = 0;
        ShiftWaveformOver(windowId, -8 * window->xPos, TRUE); // Does nothing
        for (i = 0; i < 224; i++)
            CopyToWindowPixelBuffer(windowId, sCryScreenBg_Gfx, TILE_SIZE_4BPP, i);

        gDexCryScreenState++;
        break;
    case 1:
        for (i = 0; i < sDexCryScreen->playStartPos * 8; i++)
            DrawWaveformSegment(i, 0);

        gDexCryScreenState++;
        break;
    case 2:
        DrawWaveformWindow(windowId);
        LoadPalette(sCryScreenBg_Pal, BG_PLTT_ID(window->paletteNo), PLTT_SIZE_4BPP);
        finished = TRUE;
        break;
    }

    return finished;
}

void UpdateCryWaveformWindow(u8 windowId)
{
    u8 waveformIdx;

    DrawWaveformWindow(windowId);
    AdvancePlayhead(windowId);

    // Cry cant be replayed until this counter is done
    if (sDexCryScreen->cryRepeatDelay)
        sDexCryScreen->cryRepeatDelay--;

    // Once a cry replay has started, it waits for this countdown before playing
    if (sDexCryScreen->cryOverrideCountdown)
    {
        sDexCryScreen->cryOverrideCountdown--;
        if (!sDexCryScreen->cryOverrideCountdown)
        {
            PlayCryScreenCry(sDexCryScreen->species);
            DrawWaveformFlatline();
            return;
        }
    }

    // No cry playing
    if (sDexCryScreen->cryState == 0)
    {
        DrawWaveformFlatline();
        return;
    }

    // Cry playing, buffer waveform
    if (sDexCryScreen->cryState == 1)
    {
        BufferCryWaveformSegment();
    }
    else if (sDexCryScreen->cryState > 8)
    {
        // Buffered waveform exhausted, end or buffer more
        if (!IsCryPlaying())
        {
            DrawWaveformFlatline();
            sDexCryScreen->cryState = 0;
            return;
        }

        BufferCryWaveformSegment();
        sDexCryScreen->cryState = 1;
    }

    // Draw cry
    waveformIdx = 2 * (sDexCryScreen->cryState - 1);
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 2, sDexCryScreen->cryWaveformBuffer[waveformIdx]);
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 1, sDexCryScreen->cryWaveformBuffer[waveformIdx + 1]);
    sDexCryScreen->cryState++;
}

void CryScreenPlayButton(u16 species)
{
    if (gMPlayInfo_BGM.status & MUSICPLAYER_STATUS_PAUSE && !sDexCryScreen->cryOverrideCountdown)
    {
        if (!sDexCryScreen->cryRepeatDelay)
        {
            sDexCryScreen->cryRepeatDelay = 4;
            if (IsCryPlaying() == TRUE)
            {
                StopCry();
                sDexCryScreen->species = species;
                sDexCryScreen->cryOverrideCountdown = 2;
            }
            else
            {
                PlayCryScreenCry(species);
            }
        }
    }
}

static void PlayCryScreenCry(u16 species)
{
    PlayCry_NormalNoDucking(species, 0, CRY_VOLUME_RS, CRY_PRIORITY_NORMAL);
    sDexCryScreen->cryState = 1;
}

static void BufferCryWaveformSegment(void)
{
    u8 i;
    s8 *baseBuffer;
    s8 *buffer;

    if (gPcmDmaCounter < 2)
        baseBuffer = gSoundInfo.pcmBuffer;
    else
        baseBuffer = gSoundInfo.pcmBuffer + (gSoundInfo.pcmDmaPeriod + 1 - gPcmDmaCounter) * gSoundInfo.pcmSamplesPerVBlank;

    buffer = baseBuffer + PCM_DMA_BUF_SIZE;
    for (i = 0; i < ARRAY_COUNT(sDexCryScreen->cryWaveformBuffer); i++)
        sDexCryScreen->cryWaveformBuffer[i] = buffer[i * 2] * 2;
}

static void DrawWaveformFlatline(void)
{
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 2, 0);
    DrawWaveformSegment(sDexCryScreen->playStartPos * 8 + sDexCryScreen->playhead - 1, 0);
}

static void AdvancePlayhead(u8 windowId)
{
    u8 i;
    u16 offset;

    ShiftWaveformOver(windowId, sDexCryScreen->playhead, FALSE);
    sDexCryScreen->playhead += 2;
    offset = (sDexCryScreen->playhead / 8 + sDexCryScreen->playStartPos + 1) % 32;
    for (i = 0; i < 7; i++)
        CopyToWindowPixelBuffer(windowId, sCryScreenBg_Gfx, TILE_SIZE_4BPP, offset + (i * TILE_SIZE_4BPP));
}

// Waveform segments are drawn in alternate vertical slices
// Note that the waveform isnt put on screen until DrawWaveformWindow
static void DrawWaveformSegment(u8 position, u8 amplitude)
{
    // Position is a bitfield containing the play start pos, the playhead pos, and which vertical slice half to draw
    #define PLAY_START_POS (position >> 3)
    #define PLAYHEAD_POS   (position & ((1 << 3) - 1))
    #define VERT_SLICE     (position & 1)

    u8 currentPointY;
    u8 nybble;
    u16 offset;
    u16 temp;
    u8 y;

    temp = (amplitude + 127) * 256;
    y = temp / 1152.0;
    if (y > WAVEFORM_WINDOW_HEIGHT - 1)
        y = WAVEFORM_WINDOW_HEIGHT - 1;
    currentPointY = y;
    nybble = VERT_SLICE;
    if (y > sDexCryScreen->waveformPreviousY)
    {
        // Current point lower than previous point, draw point and draw line up to previous
        do
        {
            offset = sWaveformOffsets[PLAYHEAD_POS][y] + PLAY_START_POS * TILE_SIZE_4BPP;
            sCryWaveformWindowTiledata[offset] &= sWaveformTileDataNybbleMasks[nybble];
            sCryWaveformWindowTiledata[offset] |= sWaveformColor[nybble][((y / 3) - 1) & 0x0F];
            y--;
        } while (y > sDexCryScreen->waveformPreviousY);
    }
    else
    {
        // Current point higher than previous point, draw point and draw line down to previous
        do
        {
            offset = sWaveformOffsets[PLAYHEAD_POS][y] + PLAY_START_POS * TILE_SIZE_4BPP;
            sCryWaveformWindowTiledata[offset] &= sWaveformTileDataNybbleMasks[nybble];
            sCryWaveformWindowTiledata[offset] |= sWaveformColor[nybble][((y / 3) - 1) & 0x0F];
            y++;
        } while (y < sDexCryScreen->waveformPreviousY);
    }

    sDexCryScreen->waveformPreviousY = currentPointY;
}

static void DrawWaveformWindow(u8 windowId)
{
    CopyWindowToVram(windowId, COPYWIN_GFX);
}

// rsVertical is leftover from a very different version of this function in RS
// In RS, when TRUE it would use VOFS and when FALSE it would use HOFS (only FALSE was used)
// Here when TRUE it does nothing
static void ShiftWaveformOver(u8 windowId, s16 offset, bool8 rsVertical)
{
    if (!rsVertical)
    {
        u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
        ChangeBgX(bg, offset << 8, BG_COORD_SET);
    }
}

bool8 LoadCryMeter(struct CryScreenWindow *window, u8 windowId)
{
    bool8 finished = FALSE;

    switch (gDexCryScreenState)
    {
    case 0:
        if (!sCryMeterNeedle)
            sCryMeterNeedle = AllocZeroed(sizeof(*sCryMeterNeedle));

        CopyToWindowPixelBuffer(windowId, sCryMeter_Gfx, 0, 0);
        LoadPalette(sCryMeter_Pal, BG_PLTT_ID(window->paletteNo), PLTT_SIZE_4BPP);
        gDexCryScreenState++;
        break;
    case 1:
        LoadSpriteSheets(sCryMeterNeedleSpriteSheets);
        LoadSpritePalettes(sCryMeterNeedleSpritePalettes);
        sCryMeterNeedle->spriteId = CreateSprite(&sCryMeterNeedleSpriteTemplate, 40 + window->xPos * 8, 56 + window->yPos * 8, 1);
        sCryMeterNeedle->rotation = MIN_NEEDLE_POS;
        sCryMeterNeedle->targetRotation = MIN_NEEDLE_POS;
        sCryMeterNeedle->moveIncrement = 0;
        finished = TRUE;
        break;
    }

    return finished;
}

void FreeCryScreen(void)
{
    FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(gSprites[sCryMeterNeedle->spriteId].oam.paletteNum));
    DestroySprite(gSprites + sCryMeterNeedle->spriteId);
    FREE_AND_SET_NULL(sDexCryScreen);
    FREE_AND_SET_NULL(sCryMeterNeedle);
}

static void SpriteCB_CryMeterNeedle(struct Sprite *sprite)
{
    u16 i;
    s8 peakAmplitude;
    s16 x;
    s16 y;
    struct ObjAffineSrcData affine;
    struct OamMatrix matrix;
    u8 amplitude;

    gSprites[sCryMeterNeedle->spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[sCryMeterNeedle->spriteId].oam.affineParam = 0;

    // While no cry is playing, cryState is 0
    // While cry is playing, cryState loops 1-8
    switch (sDexCryScreen->cryState)
    {
    case 0:
        sCryMeterNeedle->targetRotation = MIN_NEEDLE_POS;
        if (sCryMeterNeedle->rotation > 0)
        {
            if (sCryMeterNeedle->moveIncrement != 1)
                sCryMeterNeedle->moveIncrement--;
        }
        else
        {
            sCryMeterNeedle->moveIncrement = NEEDLE_MOVE_INCREMENT;
        }
        break;
    case 2:
        peakAmplitude = 0;
        for (i = 0; i < ARRAY_COUNT(sDexCryScreen->cryWaveformBuffer); i++)
        {
            if (peakAmplitude < sDexCryScreen->cryWaveformBuffer[i])
                peakAmplitude = sDexCryScreen->cryWaveformBuffer[i];
        }
        SetCryMeterNeedleTarget(peakAmplitude * 208 / 256);
        break;
    case 6:
        // To introduce some randomness, needle jumps to set pos in waveform rather than peak
        amplitude = sDexCryScreen->cryWaveformBuffer[10];
        SetCryMeterNeedleTarget(amplitude * 208 / 256);
        break;
    }

    if (sCryMeterNeedle->rotation == sCryMeterNeedle->targetRotation)
    {
        // Empty, needle has reached target
    }
    else if (sCryMeterNeedle->rotation < sCryMeterNeedle->targetRotation)
    {
        // Rotate needle left
        sCryMeterNeedle->rotation += sCryMeterNeedle->moveIncrement;
        if (sCryMeterNeedle->rotation > sCryMeterNeedle->targetRotation)
        {
            sCryMeterNeedle->rotation = sCryMeterNeedle->targetRotation;
            sCryMeterNeedle->targetRotation = 0;
        }
    }
    else
    {
        // Rotate needle right
        sCryMeterNeedle->rotation -= sCryMeterNeedle->moveIncrement;
        if (sCryMeterNeedle->rotation < sCryMeterNeedle->targetRotation)
        {
            sCryMeterNeedle->rotation = sCryMeterNeedle->targetRotation;
            sCryMeterNeedle->targetRotation = 0;
        }
    }

    affine.xScale = 256;
    affine.yScale = 256;
    affine.rotation = sCryMeterNeedle->rotation * 256;
    ObjAffineSet(&affine, &matrix, 1, 2);
    SetOamMatrix(0, matrix.a, matrix.b, matrix.c, matrix.d);
    x = gSineTable[((sCryMeterNeedle->rotation + 0x7F) & 0xFF)];
    y = gSineTable[((sCryMeterNeedle->rotation + 0x7F) & 0xFF) + 64];
    sprite->x2 = x * 24 / 256;
    sprite->y2 = y * 24 / 256;
}

static void SetCryMeterNeedleTarget(s8 offset)
{
    u16 rotation = (MIN_NEEDLE_POS - offset) & 0xFF;

    // Min is positive, max is negative. Make sure needle hasnt moved out of bounds
    if (rotation > MIN_NEEDLE_POS && rotation < (u8)MAX_NEEDLE_POS)
        rotation = (u8)MAX_NEEDLE_POS;

    sCryMeterNeedle->targetRotation = rotation;
    sCryMeterNeedle->moveIncrement = NEEDLE_MOVE_INCREMENT;
}

