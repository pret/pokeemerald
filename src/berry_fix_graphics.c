#include "global.h"
#include "graphics.h"

// Duplicate of sBerryFixGraphics in berry_fix_program.c
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
    }
};

// Unused. See berry_fix_program.c
static void LoadBerryFixGraphics(u32 idx)
{
    REG_DISPCNT = 0;
    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BLDCNT = 0;
    LZ77UnCompVram(sBerryFixGraphics[idx].gfx, (void *)BG_CHAR_ADDR(0));
    LZ77UnCompVram(sBerryFixGraphics[idx].tilemap, (void *)BG_SCREEN_ADDR(31));
    CpuCopy16(sBerryFixGraphics[idx].pltt, (void *)PLTT, 0x200);
    REG_BG0CNT = 0x1f00;
    REG_DISPCNT = DISPCNT_BG0_ON;
}
