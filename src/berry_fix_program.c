#include "global.h"
#include "gpu_regs.h"
#include "multiboot.h"
#include "malloc.h"
#include "bg.h"
#include "graphics.h"
#include "main.h"
#include "sprite.h"
#include "task.h"
#include "scanline_effect.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "m4a.h"
#include "constants/rgb.h"

struct {
    u8 state;
    u8 curScene;
    u16 timer;
    struct MultiBootParam mb;
} static * sBerryFix;

static void BerryFix_Main(void);
static void BerryFix_GpuSet(void);
static int BerryFix_TrySetScene(int);
static void BerryFix_SetScene(int);
static void BerryFix_HideScene(void);

static const u8 sText_BerryProgramUpdate[] = _("Berry Program Update");
static const u8 sText_RubySapphire[] = _("Ruby/Sapphire");
static const u8 sText_Emerald[] = _("Emerald");
static const u8 sText_BerryProgramWillBeUpdatedPressA[] = _("The Berry Program on your POKéMON\n"
                                                            "Ruby/Sapphire Game Pak will be updated.\n"
                                                            "{COLOR RED}{SHADOW LIGHT_RED}Press the A Button.");
static const u8 sText_EnsureGBAConnectionMatches[] = _("Please ensure the connection of your\n"
                                                       "Game Boy Advance system matches this.\n"
                                                       "{COLOR RED}{SHADOW LIGHT_RED}YES: Press the A Button.\n"
                                                       "NO: Turn off the power and try again.");
static const u8 sText_TurnOffPowerHoldingStartSelect[] = _("Please turn on the power of POKéMON\n"
                                                           "Ruby/Sapphire while holding START and\n"
                                                           "SELECT simultaneously. Then, ensure\n"
                                                           "the picture above appears.");
static const u8 sText_TransmittingPleaseWait[] = _("Transmitting. Please wait.\n"
                                                   "{COLOR RED}{SHADOW LIGHT_RED}Please do not turn off the power or\n"
                                                   "unplug the Game Boy Advance Game\nLink Cable.");
static const u8 sText_PleaseFollowInstructionsOnScreen[] = _("Please follow the instructions on your\n"
                                                             "POKéMON Ruby/Sapphire screen.");
static const u8 sText_TransmissionFailureTryAgain[] = _("Transmission failure.\n"
                                                        "{COLOR RED}{SHADOW LIGHT_RED}Please try again.");

static const struct BgTemplate sBerryFixBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const struct WindowTemplate sBerryFixWindowTemplates[] = {
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 4,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 11,
        .width = 28,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 53
    },
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 8,
        .width = 30,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 277
    },
    {
        .bg = 0,
        .tilemapLeft = 8,
        .tilemapTop = 0,
        .width = 14,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 337
    },
    DUMMY_WIN_TEMPLATE
};

static const u16 sBerryFixPalColors[] = {
    RGB_WHITE,       RGB_WHITE,       RGB(12, 12, 12), RGB(26, 26, 25),
    RGB(28, 1, 1),   RGB(31, 23, 14), RGB(4, 19, 1),   RGB(18, 30, 18),
    RGB(6, 10, 25),  RGB(20, 24, 30), RGB_WHITE,       RGB(12, 12, 12),
    RGB(26, 26, 25), RGB_BLACK,       RGB_BLACK,       RGB_BLACK
};

static const u8 sBerryProgramTextColors[] = {TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2, TEXT_DYNAMIC_COLOR_3};
static const u8 sGameTitleTextColors[] = { TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_4};

enum {
    SCENE_ENSURE_CONNECT,
    SCENE_TURN_OFF_POWER,
    SCENE_TRANSMITTING,
    SCENE_FOLLOW_INSTRUCT,
    SCENE_TRANSMIT_FAILED,
    SCENE_BEGIN,
    SCENE_NONE
};

static const u8 *const sBerryProgramTexts[] = {
    [SCENE_ENSURE_CONNECT]  = sText_EnsureGBAConnectionMatches,
    [SCENE_TURN_OFF_POWER]  = sText_TurnOffPowerHoldingStartSelect,
    [SCENE_TRANSMITTING]    = sText_TransmittingPleaseWait,
    [SCENE_FOLLOW_INSTRUCT] = sText_PleaseFollowInstructionsOnScreen,
    [SCENE_TRANSMIT_FAILED] = sText_TransmissionFailureTryAgain,
    [SCENE_BEGIN]           = sText_BerryProgramWillBeUpdatedPressA
};

static const struct {
    const u32 *gfx;
    const u32 *tilemap;
    const u16 *palette;
} sBerryFixGraphics[] = {
    [SCENE_ENSURE_CONNECT] = {
        gBerryFixGameboy_Gfx,
        gBerryFixGameboy_Tilemap,
        gBerryFixGameboy_Pal
    },
    [SCENE_TURN_OFF_POWER] = {
        gBerryFixGameboyLogo_Gfx,
        gBerryFixGameboyLogo_Tilemap,
        gBerryFixGameboyLogo_Pal
    },
    [SCENE_TRANSMITTING] = {
        gBerryFixGbaTransfer_Gfx,
        gBerryFixGbaTransfer_Tilemap,
        gBerryFixGbaTransfer_Pal
    },
    [SCENE_FOLLOW_INSTRUCT] = {
        gBerryFixGbaTransferHighlight_Gfx,
        gBerryFixGbaTransferHighlight_Tilemap,
        gBerryFixGbaTransferHighlight_Pal
    },
    [SCENE_TRANSMIT_FAILED] = {
        gBerryFixGbaTransferError_Gfx,
        gBerryFixGbaTransferError_Tilemap,
        gBerryFixGbaTransferError_Pal
    },
    [SCENE_BEGIN] = {
        gBerryFixWindow_Gfx,
        gBerryFixWindow_Tilemap,
        gBerryFixWindow_Pal
    },
};

extern const u8 gMultiBootProgram_BerryGlitchFix_Start[0x3BF4];
extern const u8 gMultiBootProgram_BerryGlitchFix_End[];

enum {
    MAINSTATE_INIT,
    MAINSTATE_BEGIN,
    MAINSTATE_CONNECT,
    MAINSTATE_INIT_MULTIBOOT,
    MAINSTATE_MULTIBOOT,
    MAINSTATE_TRANSMIT,
    MAINSTATE_EXIT,
    MAINSTATE_FAILED,
};

void CB2_InitBerryFixProgram(void)
{
    DisableInterrupts(0xFFFF); // all
    EnableInterrupts(INTR_FLAG_VBLANK);
    m4aSoundVSyncOff();
    SetVBlankCallback(NULL);
    ResetSpriteData();
    ResetTasks();
    ScanlineEffect_Stop();
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    sBerryFix = AllocZeroed(sizeof(*sBerryFix));
    sBerryFix->state = MAINSTATE_INIT;
    sBerryFix->curScene = SCENE_NONE;
    SetMainCallback2(BerryFix_Main);
}

#define TryScene(sceneNum) BerryFix_TrySetScene(sceneNum) == (sceneNum)

static void BerryFix_Main(void)
{
    switch (sBerryFix->state)
    {
        case MAINSTATE_INIT:
            BerryFix_GpuSet();
            sBerryFix->state = MAINSTATE_BEGIN;
            break;
        case MAINSTATE_BEGIN:
            if (TryScene(SCENE_BEGIN) && (JOY_NEW(A_BUTTON)))
                sBerryFix->state = MAINSTATE_CONNECT;
            break;
        case MAINSTATE_CONNECT:
            if (TryScene(SCENE_ENSURE_CONNECT) && (JOY_NEW(A_BUTTON)))
                sBerryFix->state = MAINSTATE_INIT_MULTIBOOT;
            break;
        case MAINSTATE_INIT_MULTIBOOT:
            if (TryScene(SCENE_TURN_OFF_POWER))
            {
                sBerryFix->mb.masterp = gMultiBootProgram_BerryGlitchFix_Start;
                sBerryFix->mb.server_type = 0;
                MultiBootInit(&sBerryFix->mb);
                sBerryFix->timer = 0;
                sBerryFix->state = MAINSTATE_MULTIBOOT;
            }
            break;
        case MAINSTATE_MULTIBOOT:
            MultiBootMain(&sBerryFix->mb);
            if (sBerryFix->mb.probe_count != 0 || (!(sBerryFix->mb.response_bit & 2) || !(sBerryFix->mb.client_bit & 2)))
            {
                sBerryFix->timer = 0;
            }
            else if (++sBerryFix->timer > 180)
            {
                MultiBootStartMaster(&sBerryFix->mb,
                                     gMultiBootProgram_BerryGlitchFix_Start + ROM_HEADER_SIZE,
                                     (u32)(gMultiBootProgram_BerryGlitchFix_End - (gMultiBootProgram_BerryGlitchFix_Start + ROM_HEADER_SIZE)),
                                     4,
                                     1);
                sBerryFix->state = MAINSTATE_TRANSMIT;
            }
            break;
        case MAINSTATE_TRANSMIT:
            if (TryScene(SCENE_TRANSMITTING))
            {
                MultiBootMain(&sBerryFix->mb);

                if (MultiBootCheckComplete(&sBerryFix->mb))
                    sBerryFix->state = MAINSTATE_EXIT;
                else if (!(sBerryFix->mb.client_bit & 2))
                    sBerryFix->state = MAINSTATE_FAILED;
            }
            break;
        case MAINSTATE_EXIT:
            if (TryScene(SCENE_FOLLOW_INSTRUCT) && JOY_NEW(A_BUTTON))
                DoSoftReset();
            break;
        case MAINSTATE_FAILED:
            if (TryScene(SCENE_TRANSMIT_FAILED) && JOY_NEW(A_BUTTON))
                sBerryFix->state = MAINSTATE_BEGIN;
            break;
    }
}

static void BerryFix_GpuSet(void)
{
    s32 width, left;

    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);

    DmaFill32(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill32(3, 0, PLTT, PLTT_SIZE);
    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sBerryFixBgTemplates, ARRAY_COUNT(sBerryFixBgTemplates));
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    InitWindows(sBerryFixWindowTemplates);
    DeactivateAllTextPrinters();

    DmaCopy32(3, sBerryFixPalColors, BG_PLTT + 0x1E0, sizeof(sBerryFixPalColors));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    FillWindowPixelBuffer(3, PIXEL_FILL(0));
    FillWindowPixelBuffer(0, PIXEL_FILL(10));

    width = GetStringWidth(FONT_SMALL, sText_Emerald, 0);
    left = (120 - width) / 2;
    AddTextPrinterParameterized3(2, FONT_SMALL, left, 3, sGameTitleTextColors, TEXT_SKIP_DRAW, sText_Emerald);

    width = GetStringWidth(FONT_SMALL, sText_RubySapphire, 0);
    left = (120 - width) / 2 + 120;
    AddTextPrinterParameterized3(2, FONT_SMALL, left, 3, sGameTitleTextColors, TEXT_SKIP_DRAW, sText_RubySapphire);

    width = GetStringWidth(FONT_SMALL, sText_RubySapphire, 0);
    left = (112 - width) / 2;
    AddTextPrinterParameterized3(3, FONT_SMALL, left, 0, sGameTitleTextColors, TEXT_SKIP_DRAW, sText_RubySapphire);

    width = GetStringWidth(FONT_NORMAL, sText_BerryProgramUpdate, 0);
    left = (208 - width) / 2;
    AddTextPrinterParameterized3(0, FONT_NORMAL, left, 2, sBerryProgramTextColors, TEXT_SKIP_DRAW, sText_BerryProgramUpdate);

    CopyWindowToVram(2, COPYWIN_GFX);
    CopyWindowToVram(3, COPYWIN_GFX);
    CopyWindowToVram(0, COPYWIN_GFX);
}

static int BerryFix_TrySetScene(int scene)
{
    if (sBerryFix->curScene == scene)
        return scene;

    if (sBerryFix->curScene == SCENE_NONE)
    {
        BerryFix_SetScene(scene);
        sBerryFix->curScene = scene;
    }
    else
    {
        BerryFix_HideScene();
        sBerryFix->curScene = SCENE_NONE;
    }
    return sBerryFix->curScene;
}

static void BerryFix_SetScene(int scene)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    FillWindowPixelBuffer(1, PIXEL_FILL(10));
    AddTextPrinterParameterized3(1, FONT_NORMAL, 0, 0, sBerryProgramTextColors, TEXT_SKIP_DRAW, sBerryProgramTexts[scene]);
    PutWindowTilemap(1);
    CopyWindowToVram(1, COPYWIN_GFX);
    switch (scene)
    {
    case SCENE_ENSURE_CONNECT:
    case SCENE_TRANSMITTING:
    case SCENE_FOLLOW_INSTRUCT:
    case SCENE_TRANSMIT_FAILED:
        PutWindowTilemap(2);
        break;
    case SCENE_TURN_OFF_POWER:
        PutWindowTilemap(3);
        break;
    case SCENE_BEGIN:
        PutWindowTilemap(0);
        break;
    }
    CopyBgTilemapBufferToVram(0);
    LZ77UnCompVram(sBerryFixGraphics[scene].gfx, (void *)BG_CHAR_ADDR(1));
    LZ77UnCompVram(sBerryFixGraphics[scene].tilemap, (void *)BG_SCREEN_ADDR(31));
    CpuCopy32(sBerryFixGraphics[scene].palette, (void *)BG_PLTT, 0x100);
    ShowBg(0);
    ShowBg(1);
}

static void BerryFix_HideScene(void)
{
    HideBg(0);
    HideBg(1);
}
