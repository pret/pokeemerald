#include "global.h"
#include "battle.h"
#include "bg.h"
#include "contest.h"
#include "decompress.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "link.h"
#include "palette.h"
#include "random.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "window.h"

struct ContestLink80F57C4
{
    u8 filler0[0xC];
    u8 *unkC[4];
};

extern struct ContestLink80F57C4 *gUnknown_0203A034;

extern const struct BgTemplate gUnknown_0858D888[4];
extern const struct WindowTemplate gUnknown_0858D898[];

void sub_80F71C8(void);
u8 sub_80F7310(u8, u8);
s8 sub_80F7364(u8, u8);
void sub_80F7ED0(int, u8 *, int);

void sub_80F57C4(void)
{
    int i;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_0858D888, ARRAY_COUNT(gUnknown_0858D888));
    for (i = 0; i < 4; i++)
        SetBgTilemapBuffer(i, gUnknown_0203A034->unkC[i]);
    
    InitWindows(gUnknown_0858D898);
    DeactivateAllTextPrinters();
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG_ALL | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
    gBattle_BG0_X = 0;
    gBattle_BG0_Y = 0;
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;
    gBattle_BG2_X = 0;
    gBattle_BG2_Y = 0;
    gBattle_BG3_X = 0;
    gBattle_BG3_Y = 0;
    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    gBattle_WIN1H = 0;
    gBattle_WIN1V = 0;
}

void sub_80F591C(void)
{
    int i, j;
    s8 var0;
    s8 var1;
    int var2;
    u16 tile1, tile2;

    LZDecompressVram(gUnknown_08C19588, (void *)BG_CHAR_ADDR(0));
    CopyToBgTilemapBuffer(3, gUnknown_08C1A12C, 0, 0);
    CopyToBgTilemapBuffer(2, gUnknown_08C1A000, 0, 0);
    CopyToBgTilemapBuffer(0, gUnknown_08C19EEC, 0, 0);
    sub_80F71C8();
    LoadCompressedPalette(gUnknown_08C1A2B4, 0, 0x200);
    LoadPalette(gUnknown_0858D6B0, 0xF0, 0x20);

    for (i = 0; i < 4; i++)
    {
        var0 = sub_80F7310(i, 1);
        var1 = sub_80F7364(i, 1);
        for (j = 0; j < 10; j++)
        {
            tile1 = 0x60B2;
            if (j < var0)
                tile1 += 2;

            var2 = var1;
            if (var1 < 0)
                var2 = -var2;

            if (j < var2)
            {
                tile2 = 0x60A4;
                if (var1 < 0)
                    tile2 += 2;
            }
            else
            {
                tile2 = 0x60A2;
            }

            FillBgTilemapBufferRect_Palette0(1, tile1, j + 19, i * 3 + 5, 1, 1);
            FillBgTilemapBufferRect_Palette0(1, tile2, j + 19, i * 3 + 6, 1, 1);
        }
    }

    CopyBgTilemapBufferToVram(0);
    CopyBgTilemapBufferToVram(1);
    CopyBgTilemapBufferToVram(2);
    CopyBgTilemapBufferToVram(3);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void sub_80F5A74(u8 monIndex)
{
    struct ContestPokemon *mon = &gContestMons[monIndex];
    u8 *str = gDisplayedStringBattle;
    if (monIndex == gContestPlayerMonIndex)
        str = StringCopy(gDisplayedStringBattle, gText_ColorDarkGrey);

    StringCopy(str, mon->nickname);
    sub_80F7ED0(monIndex, gDisplayedStringBattle, 0);
    StringCopy(str, gText_Slash);
    StringAppend(str, mon->trainerName);
    sub_80F7ED0(monIndex, gDisplayedStringBattle, 50);
}

void sub_80F5AE0(void)
{
    int i;

    for (i = 0; i < 4; i++)
        sub_80F5A74(i);

    CopyBgTilemapBufferToVram(1);
}
