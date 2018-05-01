#include "global.h"
#include "gpu_regs.h"
#include "bg.h"
#include "malloc.h"
#include "constants/items.h"
#include "constants/map_objects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "battle.h"
#include "battle_anim.h"
#include "blend_palette.h"
#include "contest.h"
#include "data2.h"
#include "decompress.h"
#include "graphics.h"
#include "link.h"
#include "m4a.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "scanline_effect.h"
#include "util.h"

void sub_80DD590(void);
void sub_80D782C(void);
void sub_80DCE58(u8);

EWRAM_DATA struct ContestPokemon gContestMons[4] = {0};
EWRAM_DATA s16 gUnknown_02039F00[4] = {0};
EWRAM_DATA s16 gUnknown_02039F08[4] = {0};
EWRAM_DATA s16 gUnknown_02039F10[4] = {0};
EWRAM_DATA s16 gUnknown_02039F18[4] = {0};
EWRAM_DATA u8 gContestFinalStandings[4] = {0};
EWRAM_DATA u8 gUnknown_02039F24 = 0;
EWRAM_DATA u8 gContestPlayerMonIndex = 0;
EWRAM_DATA u8 gUnknown_02039F26[4] = {0};
EWRAM_DATA bool8 gIsLinkContest = FALSE;
EWRAM_DATA u8 gUnknown_02039F2B = 0;
EWRAM_DATA u16 gSpecialVar_ContestCategory = 0;
EWRAM_DATA u16 gSpecialVar_ContestRank = 0;

extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern u16 gBattle_BG1_Y;
extern u16 gBattle_BG2_X;
extern u16 gBattle_BG2_Y;
extern u16 gBattle_BG3_X;
extern u16 gBattle_BG3_Y;
extern u16 gBattle_WIN0H;
extern u16 gBattle_WIN0V;
extern u16 gBattle_WIN1H;
extern u16 gBattle_WIN1V;

extern const u8 gContestMiscGfx[];
extern const u8 gContestAudienceGfx[];
extern const u8 gUnknown_08C16FA8[];
extern const u8 gUnknown_08C16E90[];
extern const struct BgTemplate gUnknown_08587F34[4];
extern const struct WindowTemplate gUnknown_08587F44[];
extern const u16 gUnknown_08587C30[];

void TaskDummy1(u8 taskId)
{
}

void ResetLinkContestBoolean(void)
{
    gIsLinkContest = FALSE;
}

void sub_80D7678(void)
{
    u16 savedIme;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, 0x3F3F);
    SetGpuReg(REG_OFFSET_WINOUT, 0x3F3F);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON);

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

void LoadContestBgAfterMoveAnim(void)
{
    s32 i;

    LZDecompressVram(gContestMiscGfx, (void *)VRAM);
    LZDecompressVram(gContestAudienceGfx, (void *)(VRAM + 0x2000));
    CopyToBgTilemapBuffer(3, gUnknown_08C16FA8, 0, 0);
    CopyBgTilemapBufferToVram(3);
    LoadCompressedPalette(gUnknown_08C16E90, 0, 0x200);
    sub_80D782C();
    for (i = 0; i < 4; i++)
    {
        u32 var = 5 + i;

        LoadPalette(shared18000.unk18004[var], 16 * (5 + gUnknown_02039F26[i]), 16 * sizeof(u16));
    }
}

void sub_80D779C(void)
{
    s32 i;

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08587F34, ARRAY_COUNT(gUnknown_08587F34));
    SetBgAttribute(3, BG_CTRL_ATTR_PRIORITY, 1);
    for (i = 0; i < 4; i++)
    {
        SetBgTilemapBuffer(i, gContestResources->field_24[i]);
    }
}

void sub_80D77E4(void)
{
    InitWindows(gUnknown_08587F44);
    DeactivateAllTextPrinters();
    if (gIsLinkContest & 1)
    {
        gTextFlags.flag_0 = FALSE;
    }
    else
    {
        gTextFlags.flag_0 = TRUE;
    }
}

void sub_80D782C(void)
{
    s32 i;

    LoadPalette(gUnknown_08587C30, 0xf0, 0x20);
    FillPalette(0, 0, 2);
    for (i = 10; i < 14; i++)
        LoadPalette(gPlttBufferUnfaded + 241, 240 + i, 2);
    FillPalette(0x7E3F, 0xF3, 2);
}

void sub_80D787C(void)
{
    s32 i;

    *gContestResources->field_0 = (struct Contest){};
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_0->unk19206[i] = 0xFF;
    }
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_4[i] = (struct ContestantStatus){};
    }
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_4[i].unkB_0 = 0;
        gContestResources->field_4[i].effectStringId = CONTEST_STRING_NONE;
        gContestResources->field_4[i].effectStringId2 = CONTEST_STRING_NONE;
    }
    *gContestResources->field_8 = (struct UnknownContestStruct7){};
    *gContestResources->field_C = (struct ContestAIInfo){};
    *gContestResources->field_10 = (struct UnknownContestStruct5){};
    memset(gContestResources->field_14, 0, 4 * sizeof(struct UnknownContestStruct4));
    if (!(gIsLinkContest & 1))
        sub_80DCE58(0);
    for (i = 0; i < 4; i++)
    {
        gContestResources->field_4[i].nextTurnOrder = 0xFF;
        gContestResources->field_0->unk19218[i] = gUnknown_02039F26[i];
    }
    sub_80DD590();
    *gContestResources->field_1c = (struct ContestResourcesField1C){};
}
