#include "global.h"

extern const struct {
    const u8 *unk_0;
    const u8 *unk_4;
    const u8 *unk_8;
} gUnknown_08617128[];

void sub_81BAD84(u32 idx)
{
    REG_DISPCNT = 0x0000;
    REG_BG0HOFS = 0x0000;
    REG_BG0VOFS = 0x0000;
    REG_BLDCNT = 0x0000;
    LZ77UnCompVram(gUnknown_08617128[idx].unk_0, (void *)BG_CHAR_ADDR(0));
    LZ77UnCompVram(gUnknown_08617128[idx].unk_4, (void *)BG_SCREEN_ADDR(31));
    CpuCopy16(gUnknown_08617128[idx].unk_8, (void *)PLTT, 0x200);
    REG_BG0CNT = 0x1f00;
    REG_DISPCNT = DISPCNT_BG0_ON;
}
