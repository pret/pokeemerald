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

// Static type declarations

typedef struct {
    u8 state;
    u8 unk1;
    u16 unk2;
    struct MultiBootParam mb;
} berryfix_t;

// Static RAM declarations

static berryfix_t *berry_fix_mb_manager;

// Static ROM declarations

static void berry_fix_main(void);
static void berry_fix_gpu_set(void);
static int berry_fix_text_update(int);
static void berry_fix_text_print(int);
static void berry_fix_bg_hide(void);

// .rodata

static const u8 sText_BerryProgramUpdate[] = _("Berry Program Update");
static const u8 sText_RubySapphire[] = _("Ruby/Sapphire");
static const u8 sText_Emerald[] = _("Emerald");

static const u8 sText_BerryProgramWillBeUpdatedPressA[] = _("The Berry Program on your POKéMON\nRuby/Sapphire Game Pak will be updated.\n{COLOR RED}{SHADOW LIGHT_RED}Press the A Button.");
static const u8 sText_EnsureGBAConnectionMatches[] = _("Please ensure the connection of your\nGame Boy Advance system matches this.\n{COLOR RED}{SHADOW LIGHT_RED}YES: Press the A Button.\nNO: Turn off the power and try again.");
static const u8 sText_TurnOffPowerHoldingStartSelect[] = _("Please turn on the power of POKéMON\nRuby/Sapphire while holding START and\nSELECT simultaneously. Then, ensure\nthe picture above appears.");
static const u8 sText_TransmittingPleaseWait[] = _("Transmitting. Please wait.\n{COLOR RED}{SHADOW LIGHT_RED}Please do not turn off the power or\nunplug the Game Boy Advance Game\nLink Cable.");
static const u8 sText_PleaseFollowInstructionsOnScreen[] = _("Please follow the instructions on your\nPOKéMON Ruby/Sapphire screen.");
static const u8 sText_TransmissionFailureTryAgain[] = _("Transmission failure.\n{COLOR RED}{SHADOW LIGHT_RED}Please try again.");

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

static const u16 sUnknown_08618138[] = {
    0x7fff, 0x7fff, 0x318c, 0x675a,
    0x043c, 0x3aff, 0x0664, 0x4bd2,
    0x6546, 0x7b14, 0x7fff, 0x318c,
    0x675a, 0, 0, 0
};

static const u8 sBerryProgramTextColors[] = {TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2, TEXT_DYNAMIC_COLOR_3};
static const u8 sGameTitleTextColors[] = { TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_4};

static const u8 *const sBerryProgramTexts[] = {
    sText_EnsureGBAConnectionMatches,
    sText_TurnOffPowerHoldingStartSelect,
    sText_TransmittingPleaseWait,
    sText_PleaseFollowInstructionsOnScreen,
    sText_TransmissionFailureTryAgain,
    sText_BerryProgramWillBeUpdatedPressA
};


static const struct {
    const u32 *gfx;
    const u32 *tilemap;
    const u16 *pltt;
} sBerryFixGraphics[] = {
    {
        gBerryFixGameboy_Gfx,
        gBerryFixGameboy_Tilemap,
        gBerryFixGameboy_Pal
    }, {
        gBerryFixGameboyLogo_Gfx,
        gBerryFixGameboyLogo_Tilemap,
        gBerryFixGameboyLogo_Pal
    }, {
        gBerryFixGbaTransfer_Gfx,
        gBerryFixGbaTransfer_Tilemap,
        gBerryFixGbaTransfer_Pal
    }, {
        gBerryFixGbaTransferHighlight_Gfx,
        gBerryFixGbaTransferHighlight_Tilemap,
        gBerryFixGbaTransferHighlight_Pal
    }, {
        gBerryFixGbaTransferError_Gfx,
        gBerryFixGbaTransferError_Tilemap,
        gBerryFixGbaTransferError_Pal
    }, {
        gBerryFixWindow_Gfx,
        gBerryFixWindow_Tilemap,
        gBerryFixWindow_Pal
    },
};

extern const u8 gMultiBootProgram_BerryGlitchFix_Start[0x3BF4];
extern const u8 gMultiBootProgram_BerryGlitchFix_End[];

// .text

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
    berry_fix_mb_manager = AllocZeroed(0x50);
    berry_fix_mb_manager->state = 0;
    berry_fix_mb_manager->unk1 = 6;
    SetMainCallback2(berry_fix_main);
}

static void berry_fix_main(void)
{
    switch (berry_fix_mb_manager->state)
    {
        case 0:
            berry_fix_gpu_set();
            berry_fix_mb_manager->state = 1;
            break;
        case 1:
            if (berry_fix_text_update(5) == 5 && (JOY_NEW(A_BUTTON)))
            {
                berry_fix_mb_manager->state = 2;
            }
            break;
        case 2:
            if (berry_fix_text_update(0) == 0 && (JOY_NEW(A_BUTTON)))
            {
                berry_fix_mb_manager->state = 3;
            }
            break;
        case 3:
            if (berry_fix_text_update(1) == 1)
            {
                berry_fix_mb_manager->mb.masterp = gMultiBootProgram_BerryGlitchFix_Start;
                berry_fix_mb_manager->mb.server_type = 0;
                MultiBootInit(&berry_fix_mb_manager->mb);
                berry_fix_mb_manager->unk2 = 0;
                berry_fix_mb_manager->state = 4;
            }
            break;
        case 4:
            MultiBootMain(&berry_fix_mb_manager->mb);
            if (berry_fix_mb_manager->mb.probe_count != 0 || (!(berry_fix_mb_manager->mb.response_bit & 2) || !(berry_fix_mb_manager->mb.client_bit & 2)))
            {
                berry_fix_mb_manager->unk2 = 0;
            }
            else if (++ berry_fix_mb_manager->unk2 > 180)
            {
                MultiBootStartMaster(&berry_fix_mb_manager->mb, gMultiBootProgram_BerryGlitchFix_Start + ROM_HEADER_SIZE, (u32)(gMultiBootProgram_BerryGlitchFix_End - (gMultiBootProgram_BerryGlitchFix_Start + ROM_HEADER_SIZE)), 4, 1);
                berry_fix_mb_manager->state = 5;
            }
            break;
        case 5:
            if (berry_fix_text_update(2) == 2) {
                MultiBootMain(&berry_fix_mb_manager->mb);
                if (MultiBootCheckComplete(&berry_fix_mb_manager->mb)) {
                    berry_fix_mb_manager->state = 6;
                }
                else if (!(berry_fix_mb_manager->mb.client_bit & 2)) {
                    berry_fix_mb_manager->state = 7;
                }
            }
            break;
        case 6:
            if (berry_fix_text_update(3) == 3 && JOY_NEW(A_BUTTON))
            {
                DoSoftReset();
            }
            break;
        case 7:
            if (berry_fix_text_update(4) == 4 && JOY_NEW(A_BUTTON))
            {
                berry_fix_mb_manager->state = 1;
            }
            break;
    }
}

static void berry_fix_gpu_set(void)
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
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    InitWindows(sBerryFixWindowTemplates);
    DeactivateAllTextPrinters();

    DmaCopy32(3, sUnknown_08618138, BG_PLTT + 0x1E0, 0x20);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    FillWindowPixelBuffer(2, PIXEL_FILL(0));
    FillWindowPixelBuffer(3, PIXEL_FILL(0));
    FillWindowPixelBuffer(0, PIXEL_FILL(0xA));

    width = GetStringWidth(0, sText_Emerald, 0);
    left = (0x78 - width) / 2;
    AddTextPrinterParameterized3(2, 0, left, 3, sGameTitleTextColors, TEXT_SPEED_FF, sText_Emerald);

    width = GetStringWidth(0, sText_RubySapphire, 0);
    left = (0x78 - width) / 2 + 0x78;
    AddTextPrinterParameterized3(2, 0, left, 3, sGameTitleTextColors, TEXT_SPEED_FF, sText_RubySapphire);

    width = GetStringWidth(0, sText_RubySapphire, 0);
    left = (0x70 - width) / 2;
    AddTextPrinterParameterized3(3, 0, left, 0, sGameTitleTextColors, TEXT_SPEED_FF, sText_RubySapphire);

    width = GetStringWidth(1, sText_BerryProgramUpdate, 0);
    left = (0xD0 - width) / 2;
    AddTextPrinterParameterized3(0, 1, left, 2, sBerryProgramTextColors, TEXT_SPEED_FF, sText_BerryProgramUpdate);

    CopyWindowToVram(2, 2);
    CopyWindowToVram(3, 2);
    CopyWindowToVram(0, 2);
}

static int berry_fix_text_update(int checkval)
{
    if (berry_fix_mb_manager->unk1 == checkval)
    {
        return checkval;
    }
    if (berry_fix_mb_manager->unk1 == 6)
    {
        berry_fix_text_print(checkval);
        berry_fix_mb_manager->unk1 = checkval;
    }
    else
    {
        berry_fix_bg_hide();
        berry_fix_mb_manager->unk1 = 6;
    }
    return berry_fix_mb_manager->unk1;
}

static void berry_fix_text_print(int scene)
{
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    FillWindowPixelBuffer(1, PIXEL_FILL(0xA));
    AddTextPrinterParameterized3(1, 1, 0, 0, sBerryProgramTextColors, -1, sBerryProgramTexts[scene]);
    PutWindowTilemap(1);
    CopyWindowToVram(1, 2);
    switch (scene)
    {
        case 0:
        case 2:
        case 3:
        case 4:
            PutWindowTilemap(2);
            break;
        case 1:
            PutWindowTilemap(3);
            break;
        case 5:
            PutWindowTilemap(0);
            break;
    }
    CopyBgTilemapBufferToVram(0);
    LZ77UnCompVram(sBerryFixGraphics[scene].gfx, (void *)BG_CHAR_ADDR(1));
    LZ77UnCompVram(sBerryFixGraphics[scene].tilemap, (void *)BG_SCREEN_ADDR(31));
    CpuCopy32(sBerryFixGraphics[scene].pltt, (void *)BG_PLTT, 0x100);
    ShowBg(0);
    ShowBg(1);
}

static void berry_fix_bg_hide(void)
{
    HideBg(0);
    HideBg(1);
}
