
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

// Static type declarations

// Static RAM declarations

EWRAM_DATA struct {
    MainCallback callback;
    u8 filler_004[0x888];
    u16 unk_88c;
} *gUnknown_0203BCD0 = NULL;

// Static ROM declarations

static void sub_81701C4(void);
static void sub_8170260(void);
static void sub_8170274(void);
void sub_8170290(void);

// .rodata

extern const struct BgTemplate gUnknown_085E5068[];
extern const struct WindowTemplate gUnknown_085E5070[];

// .text

void sub_817018C(MainCallback callback)
{
    SetVBlankCallback(NULL);
    gUnknown_0203BCD0 = malloc(sizeof(*gUnknown_0203BCD0));
    gUnknown_0203BCD0->unk_88c = 0;
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
