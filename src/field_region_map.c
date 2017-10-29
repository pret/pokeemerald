
// Includes
#include "global.h"
#include "main.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "bg.h"
#include "text.h"
#include "window.h"
#include "text_window.h"
#include "palette.h"
#include "menu.h"
#include "strings.h"
#include "international_string_util.h"
#include "region_map.h"

// Static type declarations

// Static RAM declarations

EWRAM_DATA struct {
    MainCallback callback;
    u32 filler_004;
    struct RegionMap regionMap;
    u16 state;
} *gUnknown_0203BCD0 = NULL;

// Static ROM declarations

static void sub_81701C4(void);
static void sub_8170260(void);
static void sub_8170274(void);
static void sub_8170290(void);
static void sub_8170428(void);

// .rodata

extern const struct BgTemplate gUnknown_085E5068[];
extern const struct WindowTemplate gUnknown_085E5070[];

// .text

void sub_817018C(MainCallback callback)
{
    SetVBlankCallback(NULL);
    gUnknown_0203BCD0 = malloc(sizeof(*gUnknown_0203BCD0));
    gUnknown_0203BCD0->state = 0;
    gUnknown_0203BCD0->callback = callback;
    SetMainCallback2(sub_81701C4);
}

static void sub_81701C4(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, gUnknown_085E5068, 2);
    InitWindows(gUnknown_085E5070);
    DeactivateAllTextPrinters();
    sub_809882C(0, 0x27, 0xd0);
    clear_scheduled_bg_copies_to_vram();
    SetMainCallback2(sub_8170274);
    SetVBlankCallback(sub_8170260);
}

static void sub_8170260(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void sub_8170274(void)
{
    sub_8170290();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    do_scheduled_bg_tilemap_copies_to_vram();
}

void sub_8170290(void)
{
    u8 offset;

    switch (gUnknown_0203BCD0->state)
    {
        case 0:
            sub_8122CDC(&gUnknown_0203BCD0->regionMap, 0);
            sub_8124288(0, 0);
            sub_81240D4(1, 1);
            gUnknown_0203BCD0->state ++;
            break;
        case 1:
            SetWindowBorderStyle(1, 0, 0x27, 0xd);
            offset = GetStringCenterAlignXOffset(1, gText_Hoenn, 0x38);
            PrintTextOnWindow(1, 1, gText_Hoenn, offset, 1, 0, NULL);
            schedule_bg_copy_tilemap_to_vram(0);
            SetWindowBorderStyle(0, 0, 0x27, 0xd);
            sub_8170428();
            BeginNormalPaletteFade(-1, 0, 16, 0, 0);
            gUnknown_0203BCD0->state ++;
            break;
        case 2:
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(2);
            gUnknown_0203BCD0->state ++;
            break;
        case 3:
            if (!gPaletteFade.active)
            {
                gUnknown_0203BCD0->state ++;
            }
            break;
        case 4:
            switch (sub_81230AC())
            {
                case 3:
                    sub_8170428();
                    break;
                case 4:
                case 5:
                    gUnknown_0203BCD0->state ++;
                    break;
            }
            break;
        case 5:
            BeginNormalPaletteFade(-1, 0, 0, 16, 0);
            gUnknown_0203BCD0->state ++;
            break;
        case 6:
            if (!gPaletteFade.active)
            {
                sub_812305C();
                SetMainCallback2(gUnknown_0203BCD0->callback);
                if (gUnknown_0203BCD0 != NULL)
                {
                    free(gUnknown_0203BCD0);
                    gUnknown_0203BCD0 = NULL;
                }
                FreeAllWindowBuffers();
            }
            break;
    }
}

static void sub_8170428(void)
{
    if (gUnknown_0203BCD0->regionMap.unk_02)
    {
        FillWindowPixelBuffer(0, 0x11);
        PrintTextOnWindow(0, 1, gUnknown_0203BCD0->regionMap.mapSecName, 0, 1, 0, NULL);
        schedule_bg_copy_tilemap_to_vram(0);
    }
    else
    {
        FillWindowPixelBuffer(0, 0x11);
        CopyWindowToVram(0, 3);
    }
}
