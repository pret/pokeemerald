#include "global.h"
#include "graphics.h"

const struct {
    const u8 *gfx;
    const u8 *tileMap;
    const u16 *pltt;
} gUnknown_08617128[] = {
    {
        gUnknown_08DD87C0,
        gUnknown_08DD8EE0,
        gUnknown_08DD8780
    }, {
        gUnknown_08DD90E0,
        gUnknown_08DD9718,
        gUnknown_08DD9080
    }, {
        gUnknown_08DD98B4,
        gUnknown_08DD9E58,
        gUnknown_08DD9874
    }, {
        gUnknown_08DDA02C,
        gUnknown_08DDA63C,
        gUnknown_08DD9FEC
    }, {
        gUnknown_08DDA840,
        gUnknown_08DDAE40,
        gUnknown_08DDA800
    }, {
        gUnknown_08DDB020,
        gUnknown_08DDB2C4,
        gUnknown_08DDAFE0
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
