#include "global.h"
#include "graphics.h"

const struct {
    const u32 *gfx;
    const u32 *tileMap;
    const u16 *pltt;
} gUnknown_08617128[] = {
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

void sub_81BAD84(u32 idx)
{
    REG_DISPCNT = 0x0000;
    REG_BG0HOFS = 0x0000;
    REG_BG0VOFS = 0x0000;
    REG_BLDCNT = 0x0000;
    LZ77UnCompVram(gUnknown_08617128[idx].gfx, (void *)BG_CHAR_ADDR(0));
    LZ77UnCompVram(gUnknown_08617128[idx].tileMap, (void *)BG_SCREEN_ADDR(31));
    CpuCopy16(gUnknown_08617128[idx].pltt, (void *)PLTT, 0x200);
    REG_BG0CNT = 0x1f00;
    REG_DISPCNT = DISPCNT_BG0_ON;
}
