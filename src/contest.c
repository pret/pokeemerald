#include "global.h"
#include "gpu_regs.h"
#include "bg.h"
#include "alloc.h"
#include "constants/items.h"
#include "constants/event_objects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "battle.h"
#include "battle_anim.h"
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
#include "contest_link_80F57C4.h"
#include "dma3.h"
#include "battle_message.h"
#include "event_scripts.h"
#include "event_data.h"
#include "strings.h"
#include "contest_effect.h"
#include "contest_link_80FC4F4.h"
#include "script_pokemon_util_80F87D8.h"
#include "international_string_util.h"
#include "data2.h"
#include "constants/rgb.h"

extern void (*gFieldCallback)(void);

void sub_80D782C(void);
void sub_80D7C7C(u8 taskId);
void sub_80D7CB4(u8 taskId);
void sub_80D7DAC(u8 taskId);
void sub_80D7DC8(u8 taskId);
void sub_80D7DE8(u8 taskId);
bool8 sub_80D7E44(u8 *);
void sub_80D80C8(u8 taskId);
void sub_80D8108(u8 taskId);
void vblank_cb_battle(void);
void sub_80D823C(void);
void sub_80D833C(u8 taskId);
void sub_80D8424(u8 taskId);
void sub_80D8610(u8 taskId);
void sub_80D8490(u8 taskId);
void sub_80D880C(s8);
void sub_80D883C(s8);
void sub_80D8894(u8 taskId);
void sub_80D892C(u8 taskId);
void sub_80D895C(u8 taskId);
void sub_80D8A04(u8 taskId);
void sub_80D8A50(u8 taskId);
void sub_80D8A88(u8 taskId);
void sub_80D8B38(u8 taskId);
void sub_80DA110(u8);
void sub_80DA134(struct Sprite *);
void sub_80DA164(struct Sprite *);
void sub_80DA198(u8);
void sub_80DA25C(u8);
void sub_80DA28C(u8);
void sub_80DA31C(u8);
void sub_80DA348(u8);
void sub_80DA38C(u8);
void sub_80DA3CC(u8);
void sub_80DA464(u8);
void sub_80DA49C(u8);
void sub_80DA4CC(u8);
void sub_80DA51C(u8);
void sub_80DA5B4(u8);
void sub_80DA5E8(u8);
void sub_80DA6B4(u8);
void sub_80DA700(u8);
void sub_80DA740(u8);
void sub_80DA7A0(u8);
void sub_80DA7EC(u8);
void sub_80DA830(u8);
void sub_80DA874(void);
bool8 sub_80DA8A4(void);
void sub_80DAF04(u8);
void sub_80DAF1C(u8 a0, u8 a1);
void sub_80DAF88(u8);
void sub_80DAFA0(u8, u8);
u8 sub_80DB0C4(void);
u8 sub_80DB120(void);
u8 sub_80DB174(u16, u32, u32, u32);
void sub_80DB2BC(void);
void prints_contest_move_description(u16);
u16 sub_80DE84C(u16);
void sub_80DB89C(void);
u16 sub_80DB8B8(u8);
void sub_80DB918(void);
bool8 Contest_IsMonsTurnDisabled(u8);
void sub_80DBF68(void);
void sub_80DBF90(void);
void sub_80DC2BC(void);
void sub_80DC490(bool8);
void sub_80DC4F0(void);
void sub_80DC594(void);
void sub_80DC5E8(void);
void sub_80DC7EC(void);
void sub_80DCD48(void);
void sub_80DCE58(u8);
void sub_80DD04C(void);
void sub_80DD590(void);
void sub_80DDB0C(void);
void sub_80DDBE8(void);
bool8 sub_80DE1E8(u8);
void sub_80DE224(void);
void sub_80DE350(void);
void sub_80DE424(u8);
void sub_80DE69C(u8);
void sub_80DEA20(void);
void Contest_PrintTextToBg0WindowAt(u32, u8 *, s32, u8, u8);
void Contest_StartTextPrinter(const u8 *, u8);
void ContestBG_FillBoxWithIncrementingTile(u8, u16, u8, u8, u8, u8, u8, u8);
bool32 Contest_RunTextPrinters(void);
void Contest_SetBgCopyFlags(u32);
void sub_80FC9F8(u8);
bool8 AreMovesContestCombo(u16, u16);
void sub_80DBD18(void);
void sub_80DF250(void);
void sub_80DF4F8(void);
void sub_80DD080(u8);
void sub_80DF080(u8);
void sub_80DF750(void);
void sub_80DE9DC(u8);
void sub_80DCBE8(u8, u8);
u8 sub_80DC9EC(u8);
u16 sub_80DE834(u16);
void sub_80DE864(u8);
void sub_80DEAA8(u16);
void sub_80DE9B0(u8);
void sub_80DC674(u8);
void sub_80DE12C(void);
void sub_80DD45C(u8, u8);
void sub_80DD720(u8);
void sub_80DE008(bool8);
void sub_80DC028(s16, s16, u8);
bool8 sub_80DB5B8(u8, u8);
bool8 sub_80DB798(u8);
void sub_80DB884(void);
void sub_80DC9B4(u8);
void sub_80DDED0(s8, s8);
void sub_80DDCDC(s8);
void sub_80DDE0C(void);
void sub_80DD940(void);
void sub_80DB944(void);
void sub_80DBA18(void);
void sub_80DC3AC(void);
bool8 sub_80DC3C4(void);
void sub_80DF9D4(u8 *);
void sub_80DF9E0(u8 *, s32);
void ContestBG_FillBoxWithTile(u8, u16, u8, u8, u8, u8, u8);
void Contest_PrintTextToBg0WindowStd(u8, const u8 *);

EWRAM_DATA struct ContestPokemon gContestMons[4] = {0};
EWRAM_DATA s16 gContestMonConditions[4] = {0};
EWRAM_DATA s16 gUnknown_02039F08[4] = {0};
EWRAM_DATA s16 gUnknown_02039F10[4] = {0};
EWRAM_DATA s16 gUnknown_02039F18[4] = {0};
EWRAM_DATA u8 gContestFinalStandings[4] = {0};
EWRAM_DATA u8 gUnknown_02039F24 = 0;
EWRAM_DATA u8 gContestPlayerMonIndex = 0;
EWRAM_DATA u8 gUnknown_02039F26[4] = {0};
EWRAM_DATA u8 gIsLinkContest = 0;
// Bit 0: Is a link contest
// Bit 1: Link contest uses wireless adapter
EWRAM_DATA u8 gUnknown_02039F2B = 0;
EWRAM_DATA u16 gSpecialVar_ContestCategory = 0;
EWRAM_DATA u16 gSpecialVar_ContestRank = 0;
EWRAM_DATA u8 gUnknown_02039F30 = 0;
EWRAM_DATA u8 gUnknown_02039F31 = 0;
EWRAM_DATA struct ContestResources * gContestResources = NULL;
EWRAM_DATA u8 sContestBgCopyFlags = 0;
EWRAM_DATA struct ContestWinner gUnknown_02039F3C = {0};

u32 gContestRngValue;

extern const u16 gUnknown_08587C30[];
extern const struct BgTemplate gUnknown_08587F34[4];
extern const struct WindowTemplate gUnknown_08587F44[];
extern const u8 *const gUnknown_08587D90[];
extern const u8 *const gUnknown_08587F08[];
extern const u8 *const gUnknown_08587F1C[];
extern const u8 gText_0827D55A[];
extern const u8 gText_0827E793[];
extern const u8 gText_0827E32E[];
extern const u8 gText_0827E35B[];
extern const u8 gText_0827E38D[];
extern const u8 gText_0827E2FE[];
extern const u8 gText_0827E6E3[];
extern const u8 gText_0827E73C[];
extern const u8 gText_0827E717[];
extern const u8 gText_0827E76A[];
extern const u8 gText_0827E7EA[];
extern const u8 gText_0827E817[];
extern const u8 gText_0827E58A[];
extern const u8 gText_0827D56F[];
extern const u8 gText_0827D597[];
extern const struct ContestPokemon gContestOpponents[96];
extern const u8 gUnknown_085898A4[96];
extern const struct CompressedSpriteSheet gUnknown_08587C00;
extern const u8 gContest2Pal[];
extern const struct SpriteTemplate gSpriteTemplate_8587BE8;
extern const struct CompressedSpriteSheet gUnknown_08587C08;
extern const struct CompressedSpritePalette gUnknown_08587C10;
extern const struct SpriteTemplate gSpriteTemplate_8587C18;
extern const union AffineAnimCmd *const gUnknown_082FF6C0[];
extern const union AffineAnimCmd *const gUnknown_082FF694[];
extern const u8 *const gContestEffectDescriptionPointers[];

void TaskDummy1(u8 taskId)
{
}

void ResetLinkContestBoolean(void)
{
    gIsLinkContest = 0;
}

void sub_80D7678(void)
{
    u16 savedIme;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR | WININ_WIN1_BG0 | WININ_WIN1_BG1 | WININ_WIN1_BG2 | WININ_WIN1_BG3 | WININ_WIN1_OBJ | WININ_WIN1_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR | WINOUT_WINOBJ_BG0 | WINOUT_WINOBJ_BG1 | WINOUT_WINOBJ_BG2 | WINOUT_WINOBJ_BG3 | WINOUT_WINOBJ_OBJ | WINOUT_WINOBJ_CLR);
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
        gTextFlags.canABSpeedUpPrint = FALSE;
    }
    else
    {
        gTextFlags.canABSpeedUpPrint = TRUE;
    }
}

void sub_80D782C(void)
{
    s32 i;

    LoadPalette(gUnknown_08587C30, 0xf0, 0x20);
    FillPalette(RGB_BLACK, 0, 2);
    for (i = 10; i < 14; i++)
        LoadPalette(gPlttBufferUnfaded + 241, 240 + i, 2);
    FillPalette(RGB(31, 17, 31), 0xF3, 2);
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

void sub_80D7988(void)
{
    gContestResources = AllocZeroed(sizeof(struct ContestResources));
    gContestResources->field_0 = AllocZeroed(sizeof(struct Contest));
    gContestResources->field_4 = AllocZeroed(sizeof(struct ContestantStatus) * 4);
    gContestResources->field_8 = AllocZeroed(sizeof(struct UnknownContestStruct7));
    gContestResources->field_C = AllocZeroed(sizeof(struct ContestAIInfo));
    gContestResources->field_10 = AllocZeroed(sizeof(struct UnknownContestStruct5) * 4);
    gContestResources->field_14 = AllocZeroed(sizeof(struct UnknownContestStruct4) * 4);
    gContestResources->field_18 = AllocZeroed(sizeof(struct ContestStruct_field_18));
    gContestResources->field_1c = AllocZeroed(sizeof(struct ContestResourcesField1C));
    gContestResources->field_20 = AllocZeroed(sizeof(struct ContestResourcesField20));
    gContestResources->field_24[0] = AllocZeroed(0x1000);
    gContestResources->field_24[1] = AllocZeroed(0x1000);
    gContestResources->field_24[2] = AllocZeroed(0x1000);
    gContestResources->field_24[3] = AllocZeroed(0x1000);
    gContestResources->field_34 = AllocZeroed(0x800);
    gContestResources->field_38 = AllocZeroed(0x800);
    gContestResources->field_3c = AllocZeroed(0x2000);
    gUnknown_0202305C = gContestResources->field_3c;
    gUnknown_02023060 = gContestResources->field_24[1];
}

void sub_80D7A5C(void)
{
    FREE_AND_SET_NULL(gContestResources->field_0);
    FREE_AND_SET_NULL(gContestResources->field_4);
    FREE_AND_SET_NULL(gContestResources->field_8);
    FREE_AND_SET_NULL(gContestResources->field_C);
    FREE_AND_SET_NULL(gContestResources->field_10);
    FREE_AND_SET_NULL(gContestResources->field_14);
    FREE_AND_SET_NULL(gContestResources->field_18);
    FREE_AND_SET_NULL(gContestResources->field_1c);
    FREE_AND_SET_NULL(gContestResources->field_20);
    FREE_AND_SET_NULL(gContestResources->field_24[0]);
    FREE_AND_SET_NULL(gContestResources->field_24[1]);
    FREE_AND_SET_NULL(gContestResources->field_24[2]);
    FREE_AND_SET_NULL(gContestResources->field_24[3]);
    FREE_AND_SET_NULL(gContestResources->field_34);
    FREE_AND_SET_NULL(gContestResources->field_38);
    FREE_AND_SET_NULL(gContestResources->field_3c);
    FREE_AND_SET_NULL(gContestResources);
    gUnknown_0202305C = NULL;
    gUnknown_02023060 = NULL;
}

void sub_80D7B24(void)
{
    switch (gMain.state)
    {
        case 0:
            sContestBgCopyFlags = 0;
            sub_80D7988();
            AllocateMonSpritesGfx();
            FREE_AND_SET_NULL(gMonSpritesGfxPtr->firstDecompressed);
            gMonSpritesGfxPtr->firstDecompressed = AllocZeroed(0x4000);
            SetVBlankCallback(NULL);
            sub_80D779C();
            sub_80D77E4();
            sub_80D7678();
            ScanlineEffect_Clear();
            ResetPaletteFade();
            gPaletteFade.bufferTransferDisabled = TRUE;
            ResetSpriteData();
            ResetTasks();
            FreeAllSpritePalettes();
            gReservedSpritePaletteCount = 4;
            //shared18000.unk18000 = 0;
            gHeap[0x1a000] = 0;
            ClearBattleMonForms();
            sub_80D787C();
            gMain.state++;
            break;
        case 1:
            gMain.state++;
            break;
        case 2:
            if (sub_80D7E44(&gContestResources->field_0->unk1925D))
            {
                gContestResources->field_0->unk1925D = 0;
                gMain.state++;
            }
            break;
        case 3:
            sub_80DE224();
            gBattle_BG1_X = 0;
            gBattle_BG1_Y = 0;
            BeginFastPaletteFade(2);
            gPaletteFade.bufferTransferDisabled = FALSE;
            SetVBlankCallback(vblank_cb_battle);
            gContestResources->field_0->mainTaskId = CreateTask(sub_80D7C7C, 10);
            SetMainCallback2(sub_80D823C);
            if (gIsLinkContest & 2)
            {
                sub_800E0E8();
                CreateWirelessStatusIndicatorSprite(8, 8);
            }
            break;
    }
}

void sub_80D7C7C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80D7CB4;
    }
}

void sub_80D7CB4(u8 taskId)
{
    if (gIsLinkContest & 1)
    {
        if (gIsLinkContest & 2)
        {
            switch (gTasks[taskId].data[0])
            {
                case 0:
                    sub_80DBF68();
                    gTasks[taskId].data[0]++;
                    // fallthrough
                case 1:
                    if (sub_800A520())
                    {
                        sub_800ADF8();
                        gTasks[taskId].data[0]++;
                    }
                    return;
                case 2:
                    if (sub_800A520() != TRUE)
                        return;
                    gTasks[taskId].data[0]++;
                    break;
            }
        }

        if (!gPaletteFade.active)
        {
            gPaletteFade.bufferTransferDisabled = FALSE;
            if (!(gIsLinkContest & 2))
                sub_80DBF68();
            CreateTask(sub_80D7DAC, 0);
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = TaskDummy1;
        }
    }
    else
    {
        gTasks[taskId].func = sub_80D80C8;
    }
}

void sub_80D7DAC(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_80FC998, sub_80D7DC8);
}

void sub_80D7DC8(u8 taskId)
{
    gTasks[taskId].data[0] = 1;
    gTasks[taskId].func = sub_80D7DE8;
}

void sub_80D7DE8(u8 taskId)
{
    gTasks[taskId].data[0]--;
    if (gTasks[taskId].data[0] <= 0)
    {
        GetMultiplayerId();  // unused return value
        DestroyTask(taskId);
        gTasks[gContestResources->field_0->mainTaskId].func = sub_80D80C8;
        gRngValue = gContestRngValue;
    }
}

u8 sub_80D7E44(u8 *a)
{
    u16 sp0[16];
    u16 sp20[16];

    switch (*a)
    {
        case 0:
            gPaletteFade.bufferTransferDisabled = TRUE;
            RequestDma3Fill(0, (void *)VRAM, 0x8000, 1);
            RequestDma3Fill(0, (void *)VRAM + 0x8000, 0x8000, 1);
            RequestDma3Fill(0, (void *)VRAM + 0x10000, 0x8000, 1);
            break;
        case 1:
            LZDecompressVram(gContestMiscGfx, (void *)VRAM);
            break;
        case 2:
            LZDecompressVram(gContestAudienceGfx, (void *)(VRAM + 0x2000));
            DmaCopyLarge32(3, (void *)(VRAM + 0x2000), shared15800, 0x2000, 0x1000);
            break;
        case 3:
            CopyToBgTilemapBuffer(3, gUnknown_08C16FA8, 0, 0);
            CopyBgTilemapBufferToVram(3);
            break;
        case 4:
            CopyToBgTilemapBuffer(2, gUnknown_08C17170, 0, 0);
            CopyBgTilemapBufferToVram(2);
            DmaCopy32Defvars(3, gContestResources->field_24[2], shared18000.unk18A04, 0x800);
            break;
        case 5:
            LoadCompressedPalette(gUnknown_08C16E90, 0, 0x200);
            CpuCopy32(gPlttBufferUnfaded + 128, sp0, 16 * sizeof(u16));
            CpuCopy32(gPlttBufferUnfaded + (5 + gContestPlayerMonIndex) * 16, sp20, 16 * sizeof(u16));
            CpuCopy32(sp20, gPlttBufferUnfaded + 128, 16 * sizeof(u16));
            CpuCopy32(sp0, gPlttBufferUnfaded + (5 + gContestPlayerMonIndex) * 16, 16 * sizeof(u16));
            DmaCopy32Defvars(3, gPlttBufferUnfaded, shared18000.unk18004, 0x200);
            sub_80D782C();
            break;
        case 6:
            sub_80DD04C();
            sub_80DBF90();
            sub_80DB2BC();
            gContestResources->field_0->unk19216 = sub_80DB120();
            sub_80DC2BC();
            sub_80DC4F0();
            sub_80DC594();
            sub_80DC5E8();
            sub_80DC7EC();
            gBattlerPositions[0] = 0;
            gBattlerPositions[1] = 1;
            gBattlerPositions[2] = 3;
            gBattlerPositions[3] = 2;
            gBattleTypeFlags = 0;
            gBattlerAttacker = 2;
            gBattlerTarget = 3;
            gBattlerSpriteIds[gBattlerAttacker] = sub_80DB0C4();
            sub_80DEA20();
            CopyBgTilemapBufferToVram(3);
            CopyBgTilemapBufferToVram(2);
            CopyBgTilemapBufferToVram(1);
            ShowBg(3);
            ShowBg(2);
            ShowBg(0);
            ShowBg(1);
            break;
        default:
            *a = 0;
            return 1;
    }

    (*a)++;
    return 0;
}

void sub_80D80C8(u8 taskId)
{
    gPaletteFade.bufferTransferDisabled = FALSE;
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = sub_80D8108;
    }
}


void sub_80D8108(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
        case 0:
            if (gTasks[taskId].data[1]++ <= 60)
                break;
            gTasks[taskId].data[1] = 0;
            PlaySE12WithPanning(SE_C_MAKU_U, 0);
            gTasks[taskId].data[0]++;
            break;
        case 1:
            (s16)gBattle_BG1_Y += 7;
            if ((s16)gBattle_BG1_Y <= 160)
                break;
            gTasks[taskId].data[0]++;
            break;
        case 2:
            sub_80DE350();
            gTasks[taskId].data[0]++;
            break;
        case 3:
        {
            u16 bg0Cnt = GetGpuReg(REG_OFFSET_BG0CNT);
            u16 bg2Cnt = GetGpuReg(REG_OFFSET_BG2CNT);
            ((struct BgCnt *)&bg0Cnt)->priority = 0;
            ((struct BgCnt *)&bg2Cnt)->priority = 0;
            SetGpuReg(REG_OFFSET_BG0CNT, bg0Cnt);
            SetGpuReg(REG_OFFSET_BG2CNT, bg2Cnt);
            sub_80DDB0C();
            gTasks[taskId].data[0]++;
            break;
        }
        case 4:
        default:
            if (gContestResources->field_0->unk1920A_6)
                break;
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].func = sub_80D833C;
            break;
    }
}

void sub_80D823C(void)
{
    s32 i;

    AnimateSprites();
    RunTasks();
    BuildOamBuffer();
    UpdatePaletteFade();

    for (i = 0; i < 4; i++)
    {
        if ((sContestBgCopyFlags >> i) & 1)
            CopyBgTilemapBufferToVram(i);
    }
    sContestBgCopyFlags = 0;
}

void vblank_cb_battle(void)
{
    SetGpuReg(REG_OFFSET_BG0HOFS, gBattle_BG0_X);
    SetGpuReg(REG_OFFSET_BG0VOFS, gBattle_BG0_Y);
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);
    SetGpuReg(REG_OFFSET_BG2HOFS, gBattle_BG2_X);
    SetGpuReg(REG_OFFSET_BG2VOFS, gBattle_BG2_Y);
    SetGpuReg(REG_OFFSET_BG3HOFS, gBattle_BG3_X);
    SetGpuReg(REG_OFFSET_BG3VOFS, gBattle_BG3_Y);
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WIN1H, gBattle_WIN1H);
    SetGpuReg(REG_OFFSET_WIN1V, gBattle_WIN1V);
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

void sub_80D833C(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        gBattle_BG0_Y = 0;
        gBattle_BG2_Y = 0;
        sub_80DCD48();
        DmaCopy32Defvars(3, gPlttBufferUnfaded, shared18000.unk18204, 0x400);
        ConvertIntToDecimalStringN(gStringVar1, gContestResources->field_0->turnNumber + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
        if (!Contest_IsMonsTurnDisabled(gContestPlayerMonIndex))
            StringCopy(gDisplayedStringBattle, gText_0827D507);
        else
            StringCopy(gDisplayedStringBattle, gText_0827D531);
        sub_80DB89C();
        StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
        Contest_StartTextPrinter(gStringVar4, 1);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!Contest_RunTextPrinters())
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = sub_80D8424;
        }
    }
}

void sub_80D8424(u8 taskId)
{
    if ((gMain.newKeys & A_BUTTON) || (gMain.newKeys == B_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (!Contest_IsMonsTurnDisabled(gContestPlayerMonIndex))
        {
            sub_80DC490(TRUE);
            gTasks[taskId].func = sub_80D8490;
        }
        else
        {
            gTasks[taskId].func = sub_80D8894;
        }
    }
}

void sub_80D8490(u8 taskId)
{
    u8 i;
    u8 sp8[32];

    gBattle_BG0_Y = 0xA0;
    gBattle_BG2_Y = 0xA0;

    for (i = 0; i < 4; i++)
    {
        u16 move = gContestMons[gContestPlayerMonIndex].moves[i];
        u8 *r5 = sp8;

        if (gContestResources->field_4[gContestPlayerMonIndex].prevMove != MOVE_NONE
            && sub_80DE1E8(gContestPlayerMonIndex)
            && AreMovesContestCombo(gContestResources->field_4[gContestPlayerMonIndex].prevMove, move) != 0
            && gContestResources->field_4[gContestPlayerMonIndex].hasJudgesAttention)
        {
            r5 = StringCopy(sp8, gText_ColorLightShadowDarkGrey);
        }
        else if (move != 0
                 && gContestResources->field_4[gContestPlayerMonIndex].prevMove == move
                 && gContestMoves[move].effect != CONTEST_EFFECT_REPETITION_NOT_BORING)
        {
            // Gray the text because it is a repeated move
            r5 = StringCopy(sp8, gText_ColorBlue);
        }
        r5 = StringCopy(r5, gMoveNames[move]);

        FillWindowPixelBuffer(i + 5, 0);
        Contest_PrintTextToBg0WindowAt(i + 5, sp8, 5, 1, 7);
    }

    sub_80D880C(gContestResources->field_0->playerMoveChoice);
    prints_contest_move_description(gContestMons[gContestPlayerMonIndex].moves[gContestResources->field_0->playerMoveChoice]);
    gTasks[taskId].func = sub_80D8610;
}

void sub_80D8610(u8 taskId)
{
    u8 numMoves = 0;
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gContestMons[gContestPlayerMonIndex].moves[i] != MOVE_NONE)
            numMoves++;
    }

    if (gMain.newKeys & A_BUTTON)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = sub_80D8894;
    }
    else
    {
        switch (gMain.newAndRepeatedKeys)
        {
            case B_BUTTON:
                PlaySE(SE_SELECT);
                sub_80DC490(FALSE);
                ConvertIntToDecimalStringN(gStringVar1, gContestResources->field_0->turnNumber + 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                if (!Contest_IsMonsTurnDisabled(gContestPlayerMonIndex))
                    StringCopy(gDisplayedStringBattle, gText_0827D507);
                else
                    StringCopy(gDisplayedStringBattle, gText_0827D531);
                sub_80DB89C();
                StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
                Contest_StartTextPrinter(gStringVar4, 0);
                gBattle_BG0_Y = 0;
                gBattle_BG2_Y = 0;
                gTasks[taskId].func = sub_80D8424;
                break;
            case DPAD_LEFT:
            case DPAD_RIGHT:
                break;
            case DPAD_UP:
                sub_80D883C(gContestResources->field_0->playerMoveChoice);
                if (gContestResources->field_0->playerMoveChoice == 0)
                    gContestResources->field_0->playerMoveChoice = numMoves - 1;
                else
                    gContestResources->field_0->playerMoveChoice--;
                sub_80D880C(gContestResources->field_0->playerMoveChoice);
                prints_contest_move_description(gContestMons[gContestPlayerMonIndex].moves[gContestResources->field_0->playerMoveChoice]);
                if (numMoves > 1)
                    PlaySE(SE_SELECT);
                break;
            case DPAD_DOWN:
                sub_80D883C(gContestResources->field_0->playerMoveChoice);
                if (gContestResources->field_0->playerMoveChoice == numMoves - 1)
                    gContestResources->field_0->playerMoveChoice = 0;
                else
                    gContestResources->field_0->playerMoveChoice++;
                sub_80D880C(gContestResources->field_0->playerMoveChoice);
                prints_contest_move_description(gContestMons[gContestPlayerMonIndex].moves[gContestResources->field_0->playerMoveChoice]);
                if (numMoves > 1)
                    PlaySE(SE_SELECT);
                break;
        }
    }
}

void sub_80D880C(s8 a0)
{
    ContestBG_FillBoxWithIncrementingTile(2, 55, 0, 31 + a0 * 2, 2, 2, 17, 1);
}

void sub_80D883C(s8 a0)
{
    ContestBG_FillBoxWithIncrementingTile(2, 11, 0, 31 + a0 * 2, 2, 1, 17, 1);
    ContestBG_FillBoxWithIncrementingTile(2, 11, 0, 32 + a0 * 2, 2, 1, 17, 1);
}

void sub_80D8894(u8 taskId)
{
    if (gIsLinkContest & 1)
    {
        u16 var = sub_80DB8B8(gContestPlayerMonIndex);
        u8 taskId2;

        gContestResources->field_4[gContestPlayerMonIndex].currMove = var;
        taskId2 = CreateTask(sub_80FC9F8, 0);
        SetTaskFuncWithFollowupFunc(taskId2, sub_80FC9F8, sub_80D892C);
        gTasks[taskId].func = TaskDummy1;
        sub_80DBF68();
        sub_80DC490(FALSE);
    }
    else
    {
        sub_80DB918();
        gTasks[taskId].func = sub_80D895C;
    }
}

void sub_80D892C(u8 taskId)
{
    DestroyTask(taskId);
    gTasks[gContestResources->field_0->mainTaskId].func = sub_80D895C;
}

void sub_80D895C(u8 taskId)
{
    s32 i;

    sub_80DB89C();
    gBattle_BG0_Y = 0;
    gBattle_BG2_Y = 0;
    sub_80DC490(FALSE);

    for (i = 0; i < 4; i++)
    {
        FillWindowPixelBuffer(5 + i, 0);
        PutWindowTilemap(5 + i);
        CopyWindowToVram(5 + i, 2);
    }
    Contest_SetBgCopyFlags(0);

    DmaCopy32Defvars(3, gPlttBufferFaded, shared18000.unk18604, 0x400);
    LoadPalette(shared18000.unk18204, 0, 0x400);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_80D8A04;
}

void sub_80D8A04(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 2)
    {
        gTasks[taskId].data[0] = 0;
        if (++gTasks[taskId].data[1] == 2)
        {
            sub_80DDBE8();
            sub_80DE69C(1);
            gTasks[taskId].func = sub_80D8A50;
        }
    }
}

void sub_80D8A50(u8 taskId)
{
    if (!gContestResources->field_0->unk1920A_6 && !gContestResources->field_0->unk1920B_1)
        gTasks[taskId].func = sub_80D8A88;
}

void sub_80D8A88(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 19)
    {
        gContestResources->field_0->unk19214 = 0;
        gContestResources->field_0->unk1921C = gRngValue;
        if ((gIsLinkContest & 1) && sub_80DA8A4())
        {
            s32 i;

            for (i = 0; i + gUnknown_02039F30 < 4; i++)
            {
                gContestResources->field_4[gUnknown_02039F30 + i].currMove = sub_80DB8B8(gUnknown_02039F30 + i);
            }
        }
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80D8B38;
    }
}

void sub_80D8B38(u8 taskId)
{
    u8 spriteId;
    s32 i;
    u8 r6 = gContestResources->field_0->unk19215;
    s8 r3;

    switch (gTasks[taskId].data[0])
    {
        case 0:
            sub_80DCD48();
            for (i = 0; gContestResources->field_0->unk19214 != gContestResources->field_8->turnOrder[i]; i++)
                ;
            gContestResources->field_0->unk19215 = i;
            r6 = gContestResources->field_0->unk19215;
            if (gIsLinkContest & 1)
            {
                u8 taskId2;

                gContestResources->field_0->unk1920B_2 = 1;
                if (sub_80DA8A4())
                    sub_80DD080(gContestResources->field_0->unk19215);
                taskId2 = CreateTask(sub_80FCC88, 0);
                SetTaskFuncWithFollowupFunc(taskId2, sub_80FCC88, sub_80DA110);
                sub_80DBF68();
                gTasks[taskId].data[0] = 1;
            }
            else
            {
                sub_80DD080(gContestResources->field_0->unk19215);
                gTasks[taskId].data[0] = 2;
            }
            return;
        case 1:
            if (!gContestResources->field_0->unk1920B_2)
                gTasks[taskId].data[0] = 2;
            return;
        case 2:
            sub_80DF080(r6);
            sub_80DF750();
            if (gContestResources->field_4[r6].numTurnsSkipped != 0
                || gContestResources->field_4[r6].noMoreTurns)
            {
                gTasks[taskId].data[0] = 31;
            }
            else
            {
                sub_80DB89C();
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 3;
            }
            return;
        case 3:
            for (i = 0; i < 4; i++)
                gBattleMonForms[i] = 0;
            memset(gContestResources->field_18, 0, sizeof(*gContestResources->field_18));
            sub_80DE9DC(gContestResources->field_0->unk19215);
            spriteId = sub_80DB174(
                gContestMons[gContestResources->field_0->unk19215].species,
                gContestMons[gContestResources->field_0->unk19215].otId,
                gContestMons[gContestResources->field_0->unk19215].personality,
                gContestResources->field_0->unk19215);
            gSprites[spriteId].pos2.x = 120;
            gSprites[spriteId].callback = sub_80DA134;
            gTasks[taskId].data[2] = spriteId;
            gBattlerSpriteIds[gBattlerAttacker] = spriteId;
            sub_80DCBE8(sub_80DC9EC(gContestResources->field_0->unk19215), FALSE);
            gTasks[taskId].data[0] = 4;
            return;
        case 4:
            spriteId = gTasks[taskId].data[2];
            if (gSprites[spriteId].callback == SpriteCallbackDummy)
            {
                if (!gContestResources->field_14[r6].unk2_1)
                    gTasks[taskId].data[0] = 5;
            }
            return;
        case 5:
            if (gContestResources->field_4[r6].nervous)
            {
                gTasks[taskId].data[0] = 33;
            }
            else
            {
                sub_80DB89C();
                StringCopy(gStringVar1, gContestMons[r6].nickname);
                if (gContestResources->field_4[r6].currMove < MOVES_COUNT)
                    StringCopy(gStringVar2, gMoveNames[gContestResources->field_4[r6].currMove]);
                else
                    StringCopy(gStringVar2, gUnknown_08587F1C[gContestResources->field_4[r6].moveCategory]);
                StringExpandPlaceholders(gStringVar4, gText_0827D55A);
                Contest_StartTextPrinter(gStringVar4, 1);
                gTasks[taskId].data[0] = 6;
            }
            return;
        case 6:
            if (!Contest_RunTextPrinters())
            {
                gContestResources->field_0->unk1925E = 0;
                gTasks[taskId].data[0] = 7;
            }
            return;
        case 7:
        {
            u16 move = sub_80DE834(gContestResources->field_4[gContestResources->field_0->unk19215].currMove);

            sub_80DE864(gContestResources->field_0->unk19215);
            sub_80DE9DC(gContestResources->field_0->unk19215);
            sub_80DEAA8(move);
            DoMoveAnim(move);
            gTasks[taskId].data[0] = 8;
        }
            return;
        case 8:
            gAnimScriptCallback();
            if (!gAnimScriptActive)
            {
                sub_80DE9B0(r6);
                if (gContestResources->field_0->unk1925E != 0)
                {
                    gTasks[taskId].data[10] = 0;
                    gTasks[taskId].data[0] = 9;
                }
                else
                {
                    if (!gContestResources->field_4[r6].hasJudgesAttention)
                        sub_80DC674(r6);
                    sub_80DE12C();
                    gTasks[taskId].data[0] = 23;
                }
            }
            return;
        case 9:
            if (gTasks[taskId].data[10]++ > 30)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 7;
            }
            return;
        case 23:
            gTasks[taskId].data[1] = 0;
            if (gContestResources->field_4[r6].effectStringId != CONTEST_STRING_NONE)
            {
                sub_80DD45C(r6, gContestResources->field_4[r6].effectStringId);
                gContestResources->field_4[r6].effectStringId = CONTEST_STRING_NONE;
                gTasks[taskId].data[0] = 24;
            }
            else
            {
                if (gContestResources->field_4[r6].effectStringId2 != CONTEST_STRING_NONE)
                {
                    for (i = 0; i < 4; i++)
                    {
                        if (i != r6 && gContestResources->field_4[i].effectStringId != CONTEST_STRING_NONE)
                            break;
                    }
                    if (i == 4)
                    {
                        sub_80DD45C(r6, gContestResources->field_4[r6].effectStringId2);
                        gContestResources->field_4[r6].effectStringId2 = CONTEST_STRING_NONE;
                        gTasks[taskId].data[0] = 24;
                    }
                    else
                    {
                        gTasks[taskId].data[0] = 48;
                    }
                }
                else
                {
                    gTasks[taskId].data[0] = 48;
                }
            }
            return;
        case 24:
            if (!Contest_RunTextPrinters())
                gTasks[taskId].data[0] = 23;
            return;
        case 48:
            if (gContestResources->field_4[r6].turnOrderModAction == 1)
            {
                sub_80DD720(5);
            }
            else if (gContestResources->field_4[r6].turnOrderModAction == 2)
            {
                sub_80DD720(6);
            }
            else if (gContestResources->field_4[r6].turnOrderModAction == 3)
            {
                sub_80DD720(7);
            }
            else
            {
                gTasks[taskId].data[0] = 47;
                return;
            }
            gTasks[taskId].data[0] = 49;
            return;
        case 49:
            if (!gContestResources->field_0->unk1920A_4)
                gTasks[taskId].data[0] = 47;
            return;
        case 47:
            sub_80DE008(TRUE);
            gTasks[taskId].data[0] = 12;
            return;
        case 12:
            sub_80DC028(0, gContestResources->field_4[r6].appeal2, r6);
            gTasks[taskId].data[0] = 13;
            return;
        case 13:
            if (!gContestResources->field_14[gContestResources->field_0->unk19215].unk2_2)
                gTasks[taskId].data[0] = 35;
            return;
        case 35:
            if (gContestResources->field_4[r6].conditionMod == 1)
                sub_80DD720(8);
            gTasks[taskId].data[0] = 36;
            return;
        case 36:
            if (!gContestResources->field_0->unk1920A_4)
                gTasks[taskId].data[0] = 37;
            return;
        case 37:
            if (sub_80DB5B8(r6, 1))
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 38;
            }
            else
            {
                gTasks[taskId].data[0] = 50;
            }
            return;
        case 38:
            if (++gTasks[taskId].data[10] > 20)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 50;
            }
            return;
        case 50:
            if (sub_80DB798(r6))
                PlaySE(SE_C_PASI);
            gTasks[taskId].data[0] = 25;
            return;
        case 25:
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0] = 26;
            return;
        case 26:
        {
            s32 r2 = 0;

            r3 = 0;
            for (i = gTasks[taskId].data[1]; i < 4; i++)
            {
                r3 = 0;
                for (r2 = 0; r2 < 4; r2++)
                {
                    if (r2 != r6 && gUnknown_02039F26[r2] == i
                        && gContestResources->field_4[r2].effectStringId != CONTEST_STRING_NONE)
                    {
                        r3 = 1;
                        break;
                    }
                }
                if (r3 != 0)
                    break;
            }
            if (r3)
            {
                gTasks[taskId].data[1] = gUnknown_02039F26[r2];
                sub_80DD45C(r2, gContestResources->field_4[r2].effectStringId);
                gContestResources->field_4[r2].effectStringId = CONTEST_STRING_NONE;
                gTasks[taskId].data[0] = 27;
            }
            else
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 51;
                sub_80DB884();
            }
        }
            return;
        case 27:
            if (!Contest_RunTextPrinters())
                gTasks[taskId].data[0] = 28;
            return;
        case 28:
            for (i = 0; gTasks[taskId].data[1] != gUnknown_02039F26[i]; i++)
                ;
            sub_80DC028(gContestResources->field_4[i].appeal2 + gContestResources->field_4[i].jam, -gContestResources->field_4[i].jam, i);
            gTasks[taskId].data[0] = 29;
            return;
        case 29:
            for (i = 0; gTasks[taskId].data[1] != gUnknown_02039F26[i]; i++)
                ;
            if (!gContestResources->field_14[i].unk2_2)
                gTasks[taskId].data[0] = 39;
            return;
        case 39:
            for (i = 0; gTasks[taskId].data[1] != gUnknown_02039F26[i]; i++)
                ;
            if (sub_80DB5B8(i, 1))
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 40;
            }
            else
            {
                gTasks[taskId].data[0] = 30;
            }
            return;
        case 40:
            if (++gTasks[taskId].data[10] > 20)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 30;
            }
            return;
        case 30:
            for (i = 0; i < 4; i++)
            {
                if (gUnknown_02039F26[i] == gTasks[taskId].data[1])
                    break;
            }
            if (sub_80DB798(i))
                PlaySE(SE_C_PASI);
            else
                PlaySE(SE_C_SYU);
            if (gContestResources->field_4[i].judgesAttentionWasRemoved)
            {
                sub_80DC674(i);
                gContestResources->field_4[i].judgesAttentionWasRemoved = 0;
            }
            gTasks[taskId].data[1]++;
            gTasks[taskId].data[0] = 26;
            return;
        case 51:
            if (gTasks[taskId].data[10]++ > 9)
            {
                gTasks[taskId].data[10] = 0;
                if (gContestResources->field_4[r6].numTurnsSkipped != 0
                    || gContestResources->field_4[r6].turnSkipped)
                {
                    sub_80DB89C();
                    StringCopy(gStringVar1, gContestMons[r6].nickname);
                    StringExpandPlaceholders(gStringVar4, gText_0827E793);
                    Contest_StartTextPrinter(gStringVar4, 1);
                }
                gTasks[taskId].data[0] = 52;
            }
            return;
        case 52:
            if (!Contest_RunTextPrinters())
            {
                if (!gContestResources->field_4[r6].unk15_6)
                    gTasks[taskId].data[0] = 17;
                else
                    gTasks[taskId].data[0] = 14;
            }
            return;
        case 14:
            r3 = gContestResources->field_4[r6].unk16;
            if (gContestResources->field_4[r6].unk16 != 0)
            {
                sub_80DB89C();
                if (r3 == 1)
                    Contest_StartTextPrinter(gText_0827E32E, 1);
                else if (r3 == 2)
                    Contest_StartTextPrinter(gText_0827E35B, 1);
                else
                    Contest_StartTextPrinter(gText_0827E38D, 1);
                sub_80DD720(3);
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 45;
            }
            else
            {
                sub_80DB89C();
                StringCopy(gStringVar1, gContestMons[r6].nickname);
                StringExpandPlaceholders(gStringVar4, gText_0827E2FE);
                Contest_StartTextPrinter(gStringVar4, 1);
                sub_80DD720(2);
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 45;
            }
            return;
        case 45:
            if (!gContestResources->field_0->unk1920A_4)
            {
                sub_80DC9B4(gContestResources->field_0->unk19215);
                gTasks[taskId].data[0] = 15;
            }
            return;
        case 15:
            if (!Contest_RunTextPrinters())
            {
                if (++gTasks[taskId].data[10] > 50)
                {
                    if (!gContestResources->field_4[r6].hasJudgesAttention)
                    {
                        sub_80DC028(
                            gContestResources->field_4[r6].appeal2,
                            gContestResources->field_4[r6].unk17,
                            r6);
                        gContestResources->field_4[r6].appeal2 += gContestResources->field_4[r6].unk17;
                    }
                    gTasks[taskId].data[0] = 16;
                }
            }
            return;
        case 16:
            if (!gContestResources->field_14[r6].unk2_2)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 17;
            }
            return;
        case 17:
            if (gContestResources->field_4[r6].disappointedRepeat)
            {
                sub_80DB89C();
                StringCopy(gStringVar1, gContestMons[r6].nickname);
                StringExpandPlaceholders(gStringVar4, gText_0827E6E3);
                Contest_StartTextPrinter(gStringVar4, 1);
                gTasks[taskId].data[10] = 0;
                sub_80DD720(0);
                gTasks[taskId].data[0] = 46;
            }
            else
            {
                gTasks[taskId].data[0] = 41;
            }
            return;
        case 46:
            if (!gContestResources->field_0->unk1920A_4)
                gTasks[taskId].data[0] = 19;
            return;
        case 19:
            if (!Contest_RunTextPrinters())
            {
                sub_80DC028(gContestResources->field_4[r6].appeal2, -gContestResources->field_4[r6].unk18, r6);
                gContestResources->field_4[r6].appeal2 -= gContestResources->field_4[r6].unk18;
                gTasks[taskId].data[0] = 18;
            }
            return;
        case 18:
            sub_80DCD48();
            if (!gContestResources->field_14[r6].unk2_2)
            {
                gTasks[taskId].data[10] = 0;
                sub_80DB89C();
                gTasks[taskId].data[0] = 41;
            }
            return;
        case 41:
            if (gContestResources->field_10->excitementFrozen && r6 != gContestResources->field_10->excitementFreezer)
            {
                gTasks[taskId].data[0] = 57;
            }
            else
            {
                r3 = gContestResources->field_10->bits_0;
                if (gContestResources->field_4[r6].overrideCategoryExcitementMod)
                {
                    r3 = 1;
                    StringCopy(gStringVar3, gMoveNames[gContestResources->field_4[r6].currMove]);
                }
                else
                {
                    StringCopy(gStringVar3, gUnknown_08587F08[gContestMoves[gContestResources->field_4[r6].currMove].contestCategory]);
                }
                if (r3 > 0)
                {
                    if (gContestResources->field_4[r6].disappointedRepeat)
                        r3 = 0;
                }
                sub_80DB89C();
                StringCopy(gStringVar1, gContestMons[r6].nickname);
                gContestResources->field_0->applauseLevel += r3;
                if (gContestResources->field_0->applauseLevel < 0)
                    gContestResources->field_0->applauseLevel = 0;
                if (r3 == 0)
                {
                    gTasks[taskId].data[0] = 55;
                }
                else
                {
                    if (r3 < 0)
                        StringExpandPlaceholders(gStringVar4, gText_0827E73C);
                    else if (r3 > 0 && gContestResources->field_0->applauseLevel <= 4)
                        StringExpandPlaceholders(gStringVar4, gText_0827E717);
                    else
                        StringExpandPlaceholders(gStringVar4, gText_0827E76A);
                    Contest_StartTextPrinter(gStringVar4, 1);
                    gTasks[taskId].data[10] = 0;
                    gTasks[taskId].data[11] = 0;
                    if (r3 < 0)
                        gTasks[taskId].data[0] = 53;
                    else
                        gTasks[taskId].data[0] = 54;
                }
            }
            return;
        case 53:
            switch (gTasks[taskId].data[10])
            {
                case 0:
                    sub_80DDED0(-1, 1);
                    PlayFanfare(MUS_ME_ZANNEN);
                    gTasks[taskId].data[10]++;
                    break;
                case 1:
                    if (!gContestResources->field_0->unk1920B_0 && !Contest_RunTextPrinters())
                    {
                        sub_80DDCDC(-1);
                        gTasks[taskId].data[10]++;
                    }
                    break;
                case 2:
                    if (!gContestResources->field_0->unk1920A_5)
                    {
                        if (gTasks[taskId].data[11]++ > 29)
                        {
                            gTasks[taskId].data[11] = 0;
                            sub_80DDED0(-1, -1);
                            gTasks[taskId].data[10]++;
                        }
                    }
                    break;
                case 3:
                    if (!gPaletteFade.active)
                    {
                        gTasks[taskId].data[10] = 0;
                        gTasks[taskId].data[11] = 0;
                        gTasks[taskId].data[0] = 43;
                    }
                    break;
            }
            return;
        case 54:
            switch (gTasks[taskId].data[10])
            {
                case 0:
                    if (!Contest_RunTextPrinters())
                    {
                        sub_80DDED0(1, 1);
                        gTasks[taskId].data[10]++;
                    }
                    break;
                case 1:
                    if (!gContestResources->field_0->unk1920B_0)
                    {
                        sub_80DDE0C();
                        PlaySE(SE_W227B);
                        sub_80DDCDC(1);
                        gTasks[taskId].data[10]++;
                    }
                    break;
                case 2:
                    if (!gContestResources->field_0->unk1920A_5)
                    {
                        if (gTasks[taskId].data[11]++ > 29)
                        {
                            gTasks[taskId].data[11] = 0;
                            sub_80DC028(gContestResources->field_4[r6].appeal2, gContestResources->field_10->unk2, r6);
                            gContestResources->field_4[r6].appeal2 += gContestResources->field_10->unk2;
                            gTasks[taskId].data[10]++;
                        }
                    }
                    break;
                case 3:
                    if (!gContestResources->field_14[r6].unk2_2)
                    {
                        if (!gContestResources->field_0->unk1920A_7)
                        {
                            sub_80DDED0(1, -1);
                            gTasks[taskId].data[10]++;
                        }
                    }
                    break;
                case 4:
                    if (!gPaletteFade.active)
                    {
                        gTasks[taskId].data[10] = 0;
                        gTasks[taskId].data[11] = 0;
                        gTasks[taskId].data[0] = 43;
                    }
                    break;
            }
            return;
        case 43:
            if (!gContestResources->field_14[r6].unk2_2)
            {
                sub_80DB89C();
                gTasks[taskId].data[0] = 55;
            }
            return;
        case 57:
            sub_80DB89C();
            StringCopy(gStringVar3, gContestMons[gContestResources->field_10->excitementFreezer].nickname);
            StringCopy(gStringVar1, gContestMons[r6].nickname);
            StringCopy(gStringVar2, gMoveNames[gContestResources->field_4[r6].currMove]);
            StringExpandPlaceholders(gStringVar4, gText_0827E7EA);
            Contest_StartTextPrinter(gStringVar4, 1);
            gTasks[taskId].data[0] = 58;
            return;
        case 58:
            if (!Contest_RunTextPrinters())
            {
                sub_80DB89C();
                StringExpandPlaceholders(gStringVar4, gText_0827E817);
                Contest_StartTextPrinter(gStringVar4, 1);
                gTasks[taskId].data[0] = 59;
            }
            return;
        case 59:
            if (!Contest_RunTextPrinters())
            {
                sub_80DB89C();
                gTasks[taskId].data[0] = 55;
            }
            return;
        case 33:
            if (gContestResources->field_4[r6].hasJudgesAttention)
                gContestResources->field_4[r6].hasJudgesAttention = 0;
            sub_80DC9B4(r6);
            StringCopy(gStringVar1, gContestMons[r6].nickname);
            StringCopy(gStringVar2, gMoveNames[gContestResources->field_4[r6].currMove]);
            StringExpandPlaceholders(gStringVar4, gText_0827E58A);
            Contest_StartTextPrinter(gStringVar4, 1);
            gTasks[taskId].data[0] = 34;
            return;
        case 34:
            if (!Contest_RunTextPrinters())
                gTasks[taskId].data[0] = 55;
            return;
        case 55:
            sub_80DDBE8();
            gTasks[taskId].data[0] = 56;
            return;
        case 56:
            if (!gContestResources->field_0->unk1920A_6)
            {
                if (gContestResources->field_0->applauseLevel > 4)
                {
                    gContestResources->field_0->applauseLevel = 0;
                    sub_80DD940();
                }
                gTasks[taskId].data[0] = 10;
            }
            return;
        case 10:
            spriteId = gTasks[taskId].data[2];
            gSprites[spriteId].callback = sub_80DA164;
            gTasks[taskId].data[0] = 11;
            return;
        case 11:
            spriteId = gTasks[taskId].data[2];
            if (gSprites[spriteId].invisible)
            {
                FreeSpriteOamMatrix(&gSprites[spriteId]);
                DestroySprite(&gSprites[spriteId]);
                gTasks[taskId].data[0] = 20;
            }
            return;
        case 20:
            gTasks[taskId].data[10] = 0;
            gTasks[taskId].data[0] = 21;
            return;
        case 31:
            sub_80DB89C();
            StringCopy(gStringVar1, gContestMons[r6].nickname);
            StringExpandPlaceholders(gStringVar4, gText_0827D56F);
            Contest_StartTextPrinter(gStringVar4, 1);
            gTasks[taskId].data[0] = 32;
            return;
        case 32:
            if (!Contest_RunTextPrinters())
                gTasks[taskId].data[0] = 21;
            return;
        case 21:
            if (++gTasks[taskId].data[10] > 29)
            {
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 22;
            }
            return;
        case 22:
            if (++gContestResources->field_0->unk19214 == 4)
            {
                gTasks[taskId].data[0] = 0;
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[2] = 0;
                gTasks[taskId].func = sub_80DA198;
            }
            else
            {
                gTasks[taskId].data[0] = 0;
            }
            return;
    }
}

void sub_80DA110(u8 taskId)
{
    sContest.unk1920B_2 = 0;
    DestroyTask(taskId);
}

void sub_80DA134(struct Sprite *sprite)
{
    if (sprite->pos2.x != 0)
    {
        sprite->pos2.x -= 2;
    }
    else
    {
        if (++sprite->data[0] == 31)
        {
            sprite->data[0] = 0;
            sprite->callback = SpriteCallbackDummy;
        }
    }
}

void sub_80DA164(struct Sprite *sprite)
{
    sprite->pos2.x -= 6;
    if (sprite->pos1.x + sprite->pos2.x < -32)
    {
        sprite->callback = SpriteCallbackDummy;
        sprite->invisible = TRUE;
    }
}

void sub_80DA198(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (gIsLinkContest & 1)
        {
            u8 taskId2;

            sContest.unk1920B_2 = 1;
            if (sub_80DA8A4())
            {
                sub_80DB944();
                sub_80DBA18();
            }
            taskId2 = CreateTask(sub_80FCC88, 0);
            SetTaskFuncWithFollowupFunc(taskId2, sub_80FCC88, sub_80DA110);
            sub_80DBF68();
            gTasks[taskId].data[0] = 1;
        }
        else
        {
            sub_80DB944();
            sub_80DBA18();
            gTasks[taskId].data[0] = 2;
        }
        break;
    case 1:
        if (!sContest.unk1920B_2)
            gTasks[taskId].data[0] = 2;
        break;
    case 2:
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DA25C;
        break;
    }
}

void sub_80DA25C(u8 taskId)
{
    sub_80DE008(FALSE);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_80DA28C;
}

void sub_80DA28C(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (++gTasks[taskId].data[1] > 20)
        {
            sub_80DE69C(2);
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        if (!sContest.unk1920B_1)
        {
            if (++gTasks[taskId].data[1] > 20)
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[0]++;
            }
        }
        break;
    case 2:
        sub_80DC3AC();
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = sub_80DA31C;
        break;
    }
}

void sub_80DA31C(u8 taskId)
{
    if (sub_80DC3C4())
        gTasks[taskId].func = sub_80DA348;
}

void sub_80DA348(u8 taskId)
{
    DmaCopy32Defvars(3, shared18000.unk18204, gPlttBufferUnfaded, 0x400);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 2;
    gTasks[taskId].func = sub_80DA38C;
}

void sub_80DA38C(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 2)
    {
        gTasks[taskId].data[0] = 0;
        if (--gTasks[taskId].data[1] == 0)
            gTasks[taskId].func = sub_80DA3CC;
    }
}

void sub_80DA3CC(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        u8 r4 = sContestantStatus[gContestPlayerMonIndex].attentionLevel;

        sub_80DB89C();
        StringCopy(gStringVar1, gContestMons[gContestPlayerMonIndex].nickname);
        StringExpandPlaceholders(gStringVar4, gUnknown_08587D90[r4]);
        Contest_StartTextPrinter(gStringVar4, 1);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!Contest_RunTextPrinters())
        {
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = sub_80DA464;
            sub_80DCD48();
        }
    }
}

void sub_80DA464(u8 taskId)
{
    if (gTasks[taskId].data[0]++ > 29)
    {
        gTasks[taskId].data[0] = 0;
        sub_80DC3AC();
        gTasks[taskId].func = sub_80DA49C;
    }
}

void sub_80DA49C(u8 taskId)
{
    if (sub_80DC3C4())
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DA4CC;
    }
}

void sub_80DA4CC(u8 taskId)
{
    sub_80DE224();
    gTasks[taskId].func = sub_80DE424;
}

void sub_80DA4F4(u8 taskId)
{
    sub_80DE350();
    gTasks[taskId].func = sub_80DA51C;
}

void sub_80DA51C(u8 taskId)
{
    vu16 sp0 = GetGpuReg(REG_OFFSET_BG0CNT);
    vu16 sp2 = GetGpuReg(REG_OFFSET_BG2CNT);
    ((vBgCnt *)&sp0)->priority = 0;
    ((vBgCnt *)&sp2)->priority = 0;
    SetGpuReg(REG_OFFSET_BG0CNT, sp0);
    SetGpuReg(REG_OFFSET_BG2CNT, sp2);
    sContest.turnNumber++;
    if (sContest.turnNumber == 5)
    {
        gTasks[taskId].func = sub_80DA5E8;
    }
    else
    {
        sub_80DDB0C();
        gTasks[taskId].func = sub_80DA5B4;
    }
}

void sub_80DA5B4(u8 taskId)
{
    if (!sContest.unk1920A_6)
        gTasks[taskId].func = sub_80D833C;
}

void sub_80DA5E8(u8 taskId)
{
    s32 i;

    gBattle_BG0_Y = 0;
    gBattle_BG2_Y = 0;
    for (i = 0; i < 4; i++)
        gUnknown_02039F10[i] = sContestantStatus[i].unk4;
    sub_80DBD18();
    sub_80DB89C();
    if (!(gIsLinkContest & 1))
        BravoTrainerPokemonProfile_BeforeInterview1(sContestantStatus[gContestPlayerMonIndex].prevMove);
    else
    {
        sub_80DF250();
        sub_80DF4F8();
        sub_80DF750();
    }
    gContestRngValue = gRngValue;
    StringExpandPlaceholders(gStringVar4, gText_0827D597);
    Contest_StartTextPrinter(gStringVar4, 1);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_80DA6B4;
}

void sub_80DA6B4(u8 taskId)
{
    if (!Contest_RunTextPrinters())
    {
        sub_80DE224();
        gBattle_BG1_X = 0;
        gBattle_BG1_Y = 160;
        PlaySE12WithPanning(SE_C_MAKU_D, 0);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DA700;
    }
}

void sub_80DA700(u8 taskId)
{
    gBattle_BG1_Y -= 7;
    if ((s16)gBattle_BG1_Y < 0)
        gBattle_BG1_Y = 0;
    if (gBattle_BG1_Y == 0)  // Why cast?
    {
        gTasks[taskId].func = sub_80DA740;
        gTasks[taskId].data[0] = 0;
    }
}

void sub_80DA740(u8 taskId)
{
    if (gTasks[taskId].data[0]++ >= 50)
    {
        gTasks[taskId].data[0] = 0;
        if (gIsLinkContest & 1)
        {
            gTasks[taskId].func = sub_80DA7A0;
        }
        else
        {
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
            gTasks[taskId].func = sub_80DA830;
        }
    }
}

void sub_80DA7A0(u8 taskId)
{
    u8 taskId2 = CreateTask(sub_80FCACC, 0);

    SetTaskFuncWithFollowupFunc(taskId2, sub_80FCACC, sub_80DA7EC);
    gTasks[taskId].func = TaskDummy1;
    sub_80DBF68();
    sub_80DC490(FALSE);
}

void sub_80DA7EC(u8 taskId)
{
    DestroyTask(taskId);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[sContest.mainTaskId].func = sub_80DA830;
}

void sub_80DA830(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        gFieldCallback = sub_80DA874;
        FreeAllWindowBuffers();
        sub_80D7A5C();
        FreeMonSpritesGfx();
        SetMainCallback2(CB2_ReturnToField);
    }
}

void sub_80DA874(void)
{
    ScriptContext2_Disable();
    EnableBothScriptContexts();
}

void sub_80DA884(void)
{
    if (!(gIsLinkContest & 1))
        gContestPlayerMonIndex = 3;
}

bool8 sub_80DA8A4(void)
{
    if (gContestPlayerMonIndex == gUnknown_02039F2B)
        return TRUE;
    return FALSE;
}


void sub_80DA8C8(u8 partyIndex)
{
    u8 name[20];
    u16 heldItem;
    s16 cool;
    s16 beauty;
    s16 cute;
    s16 smart;
    s16 tough;

    StringCopy(name, gSaveBlock2Ptr->playerName);
    if (gIsLinkContest & 1)
    {
        sub_80DF9D4(name);
    }
    memcpy(gContestMons[gContestPlayerMonIndex].trainerName, name, 8);
    if (gSaveBlock2Ptr->playerGender == MALE)
        gContestMons[gContestPlayerMonIndex].trainerGfxId = EVENT_OBJ_GFX_LINK_BRENDAN;
    else
        gContestMons[gContestPlayerMonIndex].trainerGfxId = EVENT_OBJ_GFX_LINK_MAY;
    gContestMons[gContestPlayerMonIndex].flags = 0;
    gContestMons[gContestPlayerMonIndex].unk2C[0] = 0;
    gContestMons[gContestPlayerMonIndex].species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, name);
    StringGetEnd10(name);
    if (gIsLinkContest & 1)
    {
        sub_80DF9E0(name, GetMonData(&gPlayerParty[partyIndex], MON_DATA_LANGUAGE));
    }
    memcpy(gContestMons[gContestPlayerMonIndex].nickname, name, POKEMON_NAME_LENGTH + 1);
    StringCopy(gContestMons[gContestPlayerMonIndex].nickname, name);
    gContestMons[gContestPlayerMonIndex].cool = GetMonData(&gPlayerParty[partyIndex], MON_DATA_COOL);
    gContestMons[gContestPlayerMonIndex].beauty = GetMonData(&gPlayerParty[partyIndex], MON_DATA_BEAUTY);
    gContestMons[gContestPlayerMonIndex].cute = GetMonData(&gPlayerParty[partyIndex], MON_DATA_CUTE);
    gContestMons[gContestPlayerMonIndex].smart = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SMART);
    gContestMons[gContestPlayerMonIndex].tough = GetMonData(&gPlayerParty[partyIndex], MON_DATA_TOUGH);
    gContestMons[gContestPlayerMonIndex].sheen = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SHEEN);
    gContestMons[gContestPlayerMonIndex].moves[0] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE1);
    gContestMons[gContestPlayerMonIndex].moves[1] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE2);
    gContestMons[gContestPlayerMonIndex].moves[2] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE3);
    gContestMons[gContestPlayerMonIndex].moves[3] = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MOVE4);
    gContestMons[gContestPlayerMonIndex].personality = GetMonData(&gPlayerParty[partyIndex], MON_DATA_PERSONALITY);
    gContestMons[gContestPlayerMonIndex].otId = GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_ID);

    heldItem = GetMonData(&gPlayerParty[partyIndex], MON_DATA_HELD_ITEM);
    cool   = gContestMons[gContestPlayerMonIndex].cool;
    beauty = gContestMons[gContestPlayerMonIndex].beauty;
    cute   = gContestMons[gContestPlayerMonIndex].cute;
    smart  = gContestMons[gContestPlayerMonIndex].smart;
    tough  = gContestMons[gContestPlayerMonIndex].tough;
    if      (heldItem == ITEM_RED_SCARF)
        cool += 20;
    else if (heldItem == ITEM_BLUE_SCARF)
        beauty += 20;
    else if (heldItem == ITEM_PINK_SCARF)
        cute += 20;
    else if (heldItem == ITEM_GREEN_SCARF)
        smart += 20;
    else if (heldItem == ITEM_YELLOW_SCARF)
        tough += 20;
    if (cool > 255)
        cool = 255;
    if (beauty > 255)
        beauty = 255;
    if (cute > 255)
        cute = 255;
    if (smart > 255)
        smart = 255;
    if (tough > 255)
        tough = 255;
    gContestMons[gContestPlayerMonIndex].cool = cool;
    gContestMons[gContestPlayerMonIndex].beauty = beauty;
    gContestMons[gContestPlayerMonIndex].cute = cute;
    gContestMons[gContestPlayerMonIndex].smart = smart;
    gContestMons[gContestPlayerMonIndex].tough = tough;
}

void sub_80DAB8C(u8 contestType, u8 rank)
{
    s32 i;
    u8 opponentsCount = 0;
    u8 opponents[100];
    bool8 r7 = FALSE;
    const u8 * r3;

    sub_80DA884();

    if (FlagGet(FLAG_SYS_GAME_CLEAR) && !(gIsLinkContest & 1))
        r7 = TRUE;

    // Find all suitable opponents
    r3 = gUnknown_085898A4;
    for (i = 0; i < ARRAY_COUNT(gContestOpponents); i++)
    {
        if (rank == gContestOpponents[i].whichRank)
        {
            if (r7 == TRUE)
            {
                if (r3[i] == 1)
                    continue;
            }
            else
            {
                if (r3[i] == 2)
                    continue;
            }
            if      (contestType == CONTEST_CATEGORY_COOL && gContestOpponents[i].aiPool_Cool)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_BEAUTY && gContestOpponents[i].aiPool_Beauty)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_CUTE && gContestOpponents[i].aiPool_Cute)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_SMART && gContestOpponents[i].aiPool_Smart)
                opponents[opponentsCount++] = i;
            else if (contestType == CONTEST_CATEGORY_TOUGH && gContestOpponents[i].aiPool_Tough)
                opponents[opponentsCount++] = i;
        }
    }
    opponents[opponentsCount] = 0xFF;

    // Choose three random opponents from the list
    for (i = 0; i < 3; i++)
    {
        u16 rnd = Random() % opponentsCount;
        s32 j;

        gContestMons[i] = gContestOpponents[opponents[rnd]];
        for (j = rnd; opponents[j] != 0xFF; j++)
            opponents[j] = opponents[j + 1];
        opponentsCount--;
    }

    sub_80DA8C8(gUnknown_02039F24);
}

#ifdef NONMATCHING
void sub_80DACBC(u8 contestType, u8 rank, bool32 isPostgame)
{
    s32 i;
    u8 opponentsCount = 0;
    u8 opponents[100];
    const u8 * r6;

    if (gUnknown_02039F30 == 4)
        return;

    r6 = gUnknown_085898A4;
    for (i = 0; i < ARRAY_COUNT(gContestOpponents); i++)
    {
        if (rank != gContestOpponents[i].whichRank)
            continue;
        if (isPostgame == TRUE)
        {
            if (r6[i] == 1)
                continue;
        }
        else
        {
            if (r6[i] == 2)
                continue;
        }
        if      (contestType == CONTEST_CATEGORY_COOL && gContestOpponents[i].aiPool_Cool)
            opponents[opponentsCount++] = i;
        else if (contestType == CONTEST_CATEGORY_BEAUTY && gContestOpponents[i].aiPool_Beauty)
            opponents[opponentsCount++] = i;
        else if (contestType == CONTEST_CATEGORY_CUTE && gContestOpponents[i].aiPool_Cute)
            opponents[opponentsCount++] = i;
        else if (contestType == CONTEST_CATEGORY_SMART && gContestOpponents[i].aiPool_Smart)
            opponents[opponentsCount++] = i;
        else if (contestType == CONTEST_CATEGORY_TOUGH && gContestOpponents[i].aiPool_Tough)
            opponents[opponentsCount++] = i;
    }
    opponents[opponentsCount] = 0xFF;
    for (i = 0; i < 4 - gUnknown_02039F30; i++)
    {
        u16 rnd = sub_80F903C() % opponentsCount;
        s32 j;

        gContestMons[gUnknown_02039F30 + i] = gContestOpponents[opponents[rnd]];
        sub_80DF9D4(gContestMons[gUnknown_02039F30 + i].trainerName);
        sub_80DF9E0(gContestMons[gUnknown_02039F30 + i].nickname, GAME_LANGUAGE);
        for (j = rnd; opponents[j] != 0xFF; j++)
            opponents[j] = opponents[j + 1];
        opponentsCount--;
    }
}
#else
NAKED void sub_80DACBC(u8 contestType, u8 rank, bool32 isPostgame)
{
    asm_unified("\tpush {r4-r7,lr}\n"
                "\tmov r7, r9\n"
                "\tmov r6, r8\n"
                "\tpush {r6,r7}\n"
                "\tsub sp, 0x64\n"
                "\tmov r8, r2\n"
                "\tlsls r0, 24\n"
                "\tlsrs r4, r0, 24\n"
                "\tlsls r1, 24\n"
                "\tlsrs r2, r1, 24\n"
                "\tmovs r7, 0\n"
                "\tldr r0, =gUnknown_02039F30\n"
                "\tldrb r1, [r0]\n"
                "\tmov r9, r0\n"
                "\tcmp r1, 0x4\n"
                "\tbne _080DACDE\n"
                "\tb _080DADF6\n"
                "_080DACDE:\n"
                "\tmovs r5, 0\n"
                "\tldr r3, =gContestOpponents\n"
                "\tldr r6, =gUnknown_085898A4\n"
                "_080DACE4:\n"
                "\tldrb r0, [r3, 0x1C]\n"
                "\tlsls r0, 30\n"
                "\tlsrs r0, 30\n"
                "\tcmp r2, r0\n"
                "\tbne _080DAD56\n"
                "\tmov r0, r8\n"
                "\tcmp r0, 0x1\n"
                "\tbne _080DAD08\n"
                "\tldrb r0, [r6]\n"
                "\tcmp r0, 0x1\n"
                "\tbeq _080DAD56\n"
                "\tb _080DAD0E\n"
                "\t.pool\n"
                "_080DAD08:\n"
                "\tldrb r0, [r6]\n"
                "\tcmp r0, 0x2\n"
                "\tbeq _080DAD56\n"
                "_080DAD0E:\n"
                "\tcmp r4, 0\n"
                "\tbne _080DAD1A\n"
                "\tldrb r0, [r3, 0x1C]\n"
                "\tlsls r0, 29\n"
                "\tcmp r0, 0\n"
                "\tblt _080DAD4A\n"
                "_080DAD1A:\n"
                "\tcmp r4, 0x1\n"
                "\tbne _080DAD26\n"
                "\tldrb r0, [r3, 0x1C]\n"
                "\tlsls r0, 28\n"
                "\tcmp r0, 0\n"
                "\tblt _080DAD4A\n"
                "_080DAD26:\n"
                "\tcmp r4, 0x2\n"
                "\tbne _080DAD32\n"
                "\tldrb r0, [r3, 0x1C]\n"
                "\tlsls r0, 27\n"
                "\tcmp r0, 0\n"
                "\tblt _080DAD4A\n"
                "_080DAD32:\n"
                "\tcmp r4, 0x3\n"
                "\tbne _080DAD3E\n"
                "\tldrb r0, [r3, 0x1C]\n"
                "\tlsls r0, 26\n"
                "\tcmp r0, 0\n"
                "\tblt _080DAD4A\n"
                "_080DAD3E:\n"
                "\tcmp r4, 0x4\n"
                "\tbne _080DAD56\n"
                "\tldrb r0, [r3, 0x1C]\n"
                "\tlsls r0, 25\n"
                "\tcmp r0, 0\n"
                "\tbge _080DAD56\n"
                "_080DAD4A:\n"
                "\tadds r0, r7, 0\n"
                "\tadds r1, r0, 0x1\n"
                "\tlsls r1, 24\n"
                "\tlsrs r7, r1, 24\n"
                "\tadd r0, sp\n"
                "\tstrb r5, [r0]\n"
                "_080DAD56:\n"
                "\tadds r3, 0x40\n"
                "\tadds r6, 0x1\n"
                "\tadds r5, 0x1\n"
                "\tcmp r5, 0x5F\n"
                "\tbls _080DACE4\n"
                "\tmov r3, sp\n"
                "\tadds r1, r3, r7\n"
                "\tmovs r0, 0xFF\n"
                "\tstrb r0, [r1]\n"
                "\tmovs r5, 0\n"
                "\tmov r0, r9\n"
                "\tldrb r1, [r0]\n"
                "\tmovs r0, 0x4\n"
                "\tsubs r0, r1\n"
                "\tcmp r5, r0\n"
                "\tbge _080DADF6\n"
                "\tldr r3, =gContestMons\n"
                "\tmov r8, r3\n"
                "\tmov r6, r9\n"
                "\tmovs r0, 0x2\n"
                "\tadd r0, r8\n"
                "\tmov r9, r0\n"
                "_080DAD82:\n"
                "\tbl sub_80F903C\n"
                "\tlsls r0, 16\n"
                "\tlsrs r0, 16\n"
                "\tadds r1, r7, 0\n"
                "\tbl __modsi3\n"
                "\tadds r1, r0, 0\n"
                "\tlsls r1, 16\n"
                "\tlsrs r1, 16\n"
                "\tldrb r0, [r6]\n"
                "\tadds r0, r5\n"
                "\tlsls r0, 6\n"
                "\tadd r0, r8\n"
                "\tldr r2, =gContestOpponents\n"
                "\tmov r3, sp\n"
                "\tadds r4, r3, r1\n"
                "\tldrb r1, [r4]\n"
                "\tlsls r1, 6\n"
                "\tadds r1, r2\n"
                "\tmovs r2, 0x40\n"
                "\tbl memcpy\n"
                "\tldrb r0, [r6]\n"
                "\tadds r0, r5\n"
                "\tlsls r0, 6\n"
                "\tmov r1, r8\n"
                "\tadds r1, 0xD\n"
                "\tadds r0, r1\n"
                "\tbl sub_80DF9D4\n"
                "\tldrb r0, [r6]\n"
                "\tadds r0, r5\n"
                "\tlsls r0, 6\n"
                "\tadd r0, r9\n"
                "\tmovs r1, 0x2\n"
                "\tbl sub_80DF9E0\n"
                "\tldrb r0, [r4]\n"
                "\tadds r3, r5, 0x1\n"
                "\tsubs r1, r7, 0x1\n"
                "\tcmp r0, 0xFF\n"
                "\tbeq _080DADE6\n"
                "\tadds r2, r4, 0\n"
                "_080DADDA:\n"
                "\tldrb r0, [r2, 0x1]\n"
                "\tstrb r0, [r2]\n"
                "\tadds r2, 0x1\n"
                "\tldrb r0, [r2]\n"
                "\tcmp r0, 0xFF\n"
                "\tbne _080DADDA\n"
                "_080DADE6:\n"
                "\tlsls r0, r1, 24\n"
                "\tlsrs r7, r0, 24\n"
                "\tadds r5, r3, 0\n"
                "\tldrb r1, [r6]\n"
                "\tmovs r0, 0x4\n"
                "\tsubs r0, r1\n"
                "\tcmp r5, r0\n"
                "\tblt _080DAD82\n"
                "_080DADF6:\n"
                "\tadd sp, 0x64\n"
                "\tpop {r3,r4}\n"
                "\tmov r8, r3\n"
                "\tmov r9, r4\n"
                "\tpop {r4-r7}\n"
                "\tpop {r0}\n"
                "\tbx r0\n"
                "\t.pool");
}
#endif

// GetContestAvailability?
u8 sub_80DAE0C(struct Pokemon *pkmn)
{
    u8 ribbon;
    u8 retVal;

    if (GetMonData(pkmn, MON_DATA_IS_EGG))
        return 3;
    if (GetMonData(pkmn, MON_DATA_HP) == 0)
        return 4;
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        ribbon = GetMonData(pkmn, MON_DATA_COOL_RIBBON);
        break;
    case CONTEST_CATEGORY_BEAUTY:
        ribbon = GetMonData(pkmn, MON_DATA_BEAUTY_RIBBON);
        break;
    case CONTEST_CATEGORY_CUTE:
        ribbon = GetMonData(pkmn, MON_DATA_CUTE_RIBBON);
        break;
    case CONTEST_CATEGORY_SMART:
        ribbon = GetMonData(pkmn, MON_DATA_SMART_RIBBON);
        break;
    case CONTEST_CATEGORY_TOUGH:
        ribbon = GetMonData(pkmn, MON_DATA_TOUGH_RIBBON);
        break;
    default:
        return 0;
    }

    // Couldn't get this to match any other way.
    // Returns 2, 1, or 0 respectively if ribbon's rank is above, equal, or below
    // the current contest rank.
    if (ribbon > gSpecialVar_ContestRank)
        retVal = 2;
    else if (ribbon >= gSpecialVar_ContestRank)
        retVal = 1;
    else
        retVal = 0;
    return retVal;
}

void sub_80DAEA4(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        FillWindowPixelBuffer(gUnknown_02039F26[i], 0);
        sub_80DAF04(i);
        sub_80DAF88(i);
    }
}

u8 * sub_80DAED4(const u8 * src, u8 color)
{
    u8 * ptr = StringCopy(gDisplayedStringBattle, gText_ColorTransparent);
    ptr[-1] = color;
    ptr = StringCopy(ptr, src);

    return ptr;
}

void sub_80DAF04(u8 a0)
{
    sub_80DAF1C(a0, a0 + 10);
}

void sub_80DAF1C(u8 a0, u8 a1)
{
    u8 buffer[32];
    s32 offset;

    StringCopy(buffer, gText_Slash);
    StringAppend(buffer, gContestMons[a0].trainerName);
    sub_80DAED4(buffer, a1);
    offset = GetStringRightAlignXOffset(7, gDisplayedStringBattle, 0x60);
    if (offset > 55)
        offset = 55;
    Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[a0], gDisplayedStringBattle, offset, 1, 7);
}

void sub_80DAF88(u8 a0)
{
    sub_80DAFA0(a0, a0 + 10);
}

void sub_80DAFA0(u8 a0, u8 a1)
{
    sub_80DAED4(gContestMons[a0].nickname, a1);
    Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[a0], gDisplayedStringBattle, 5, 1, 7);
}

u16 sub_80DAFE0(u8 who, u8 contestCategory)
{
    u8 statMain;
    u8 statSub1;
    u8 statSub2;

    switch (contestCategory)
    {
        case CONTEST_CATEGORY_COOL:
            statMain = gContestMons[who].cool;
            statSub1 = gContestMons[who].tough;
            statSub2 = gContestMons[who].beauty;
            break;
        case CONTEST_CATEGORY_BEAUTY:
            statMain = gContestMons[who].beauty;
            statSub1 = gContestMons[who].cool;
            statSub2 = gContestMons[who].cute;
            break;
        case CONTEST_CATEGORY_CUTE:
            statMain = gContestMons[who].cute;
            statSub1 = gContestMons[who].beauty;
            statSub2 = gContestMons[who].smart;
            break;
        case CONTEST_CATEGORY_SMART:
            statMain = gContestMons[who].smart;
            statSub1 = gContestMons[who].cute;
            statSub2 = gContestMons[who].tough;
            break;
        case CONTEST_CATEGORY_TOUGH:
        default:
            statMain = gContestMons[who].tough;
            statSub1 = gContestMons[who].smart;
            statSub2 = gContestMons[who].cool;
            break;
    }
    return statMain + (statSub1 + statSub2 + gContestMons[who].sheen) / 2;
}

void sub_80DB09C(u8 a0)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gContestMonConditions[i] = sub_80DAFE0(i, a0);
}

u8 sub_80DB0C4(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08587C00);
    LoadCompressedPalette(gContest2Pal, 0x110, 32);
    spriteId = CreateSprite(&gSpriteTemplate_8587BE8, 112, 36, 30);
    gSprites[spriteId].oam.paletteNum = 1;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    return spriteId;
}

u8 sub_80DB120(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08587C08);
    LoadCompressedSpritePalette(&gUnknown_08587C10);
    spriteId = CreateSprite(&gSpriteTemplate_8587C18, 96, 10, 29);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].data[0] = gSprites[spriteId].oam.tileNum;
    return spriteId;
}

u8 sub_80DB174(u16 species, u32 otId, u32 personality, u32 index)
{
    u8 spriteId;
    species = sub_80DE84C(species);

    if (index == gContestPlayerMonIndex)
        HandleLoadSpecialPokePic_2(gMonBackPicTable + species, gMonSpritesGfxPtr->sprites[0], species, personality);
    else
        HandleLoadSpecialPokePic_DontHandleDeoxys(gMonBackPicTable + species, gMonSpritesGfxPtr->sprites[0], species, personality);

    LoadCompressedPalette(GetFrontSpritePalFromSpeciesAndPersonality(species, otId, personality), 0x120, 0x20);
    SetMultiuseSpriteTemplateToPokemon(species, 0);

    spriteId = CreateSprite(&gMultiuseSpriteTemplate, 0x70, GetBattlerSpriteFinal_Y(2, species, FALSE), 30);
    gSprites[spriteId].oam.paletteNum = 2;
    gSprites[spriteId].oam.priority = 2;
    gSprites[spriteId].subpriority = GetBattlerSpriteSubpriority(2);
    gSprites[spriteId].callback = SpriteCallbackDummy;
    gSprites[spriteId].data[0] = gSprites[spriteId].oam.paletteNum;
    gSprites[spriteId].data[2] = species;
    if (IsSpeciesNotUnown(species))
        gSprites[spriteId].affineAnims = gUnknown_082FF6C0;
    else
        gSprites[spriteId].affineAnims = gUnknown_082FF694;
    StartSpriteAffineAnim(gSprites + spriteId, 0);

    return spriteId;
}

bool8 IsSpeciesNotUnown(u16 species)
{
    if (species == SPECIES_UNOWN)
        return FALSE;
    else
        return TRUE;
}

void sub_80DB2BC(void)
{
    CpuCopy16(gContestResources->field_24[0], gContestResources->field_24[0] + 0x500, 0x280);
    CpuCopy16(gContestResources->field_24[2], gContestResources->field_24[2] + 0x500, 0x280);
}

u16 sub_80DB2EC(u16 a0, u8 a1)
{
    u16 var;

    switch (gContestEffects[gContestMoves[a0].effect].effectType)
    {
        case 0:
        case 1:
        case 8:
            var = 0x9082;
            break;
        case 2:
        case 3:
            var = 0x9088;
            break;
        default:
            var = 0x9086;
            break;
    }
    var += 0x9000 + (a1 << 12);
    return var;
}

void prints_contest_move_description(u16 a)
{
    u8 category;
    u16 categoryTile;
    u8 numHearts;

    category = gContestMoves[a].contestCategory;
    if      (category == CONTEST_CATEGORY_COOL)
        categoryTile = 0x4040;
    else if (category == CONTEST_CATEGORY_BEAUTY)
        categoryTile = 0x4045;
    else if (category == CONTEST_CATEGORY_CUTE)
        categoryTile = 0x404A;
    else if (category == CONTEST_CATEGORY_SMART)
        categoryTile = 0x406A;
    else
        categoryTile = 0x408A;

    ContestBG_FillBoxWithIncrementingTile(0, categoryTile,        0x0b, 0x1f, 0x05, 0x01, 0x11, 0x01);
    ContestBG_FillBoxWithIncrementingTile(0, categoryTile + 0x10, 0x0b, 0x20, 0x05, 0x01, 0x11, 0x01);

    if (gContestEffects[gContestMoves[a].effect].appeal == 0xFF)
        numHearts = 0;
    else
        numHearts = gContestEffects[gContestMoves[a].effect].appeal / 10;
    if (numHearts > 8)
        numHearts = 8;
    ContestBG_FillBoxWithTile(0, 0x5035, 0x15, 0x1f, 0x08,      0x01, 0x11);
    ContestBG_FillBoxWithTile(0, 0x5012, 0x15, 0x1f, numHearts, 0x01, 0x11);

    if (gContestEffects[gContestMoves[a].effect].jam == 0xFF)
        numHearts = 0;
    else
        numHearts = gContestEffects[gContestMoves[a].effect].jam / 10;
    if (numHearts > 8)
        numHearts = 8;
    ContestBG_FillBoxWithTile(0, 0x5036, 0x15, 0x20, 0x08,      0x01, 0x11);
    ContestBG_FillBoxWithTile(0, 0x5014, 0x15, 0x20, numHearts, 0x01, 0x11);

    FillWindowPixelBuffer(10, 0);
    Contest_PrintTextToBg0WindowStd(10, gContestEffectDescriptionPointers[gContestMoves[a].effect]);
    Contest_PrintTextToBg0WindowStd(9, gText_Slash);
}

void sub_80DB4E0(u16 move, u8 b)
{
    u8 r7 = gUnknown_02039F26[b] * 5 + 2;

    if (!Contest_IsMonsTurnDisabled(b) && move != MOVE_NONE)
    {
        u16 tile = sub_80DB2EC(move, b);

        ContestBG_FillBoxWithIncrementingTile(0, tile,      20, r7,     2, 1, 17, 1);
        ContestBG_FillBoxWithIncrementingTile(0, tile + 16, 20, r7 + 1, 2, 1, 17, 1);
    }
    else
    {
        ContestBG_FillBoxWithTile(0, 0, 20, r7, 2, 2, 17);
    }
}

void sub_80DB584(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        sub_80DB4E0(gContestResources->field_4[i].currMove, i);
}

u16 sub_80DB5B0(void)
{
    return 0x2034;
}

bool8 sub_80DB5B8(u8 contestantIdx, bool8 resetMod)
{
    u8 r6;
    s32 r4;

    if (sContestantStatus[contestantIdx].conditionMod == 0)
        return FALSE;
    r6 = gUnknown_02039F26[contestantIdx] * 5 + 2;
    r4 = sContestantStatus[contestantIdx].condition / 10;
    if (sContestantStatus[contestantIdx].conditionMod == 1)
    {
        ContestBG_FillBoxWithTile(0, sub_80DB5B0(), 19, r6, 1, r4, 17);
        if (resetMod)
        {
            PlaySE(SE_EXPMAX);
            sContestantStatus[contestantIdx].conditionMod = 0;
        }
    }
    else
    {
        ContestBG_FillBoxWithTile(0, 0, 19, r6 + r4, 1, 3 - r4, 17);
        if (resetMod)
        {
            PlaySE(SE_FU_ZAKU2);
            sContestantStatus[contestantIdx].conditionMod = 0;
        }
    }
    return TRUE;
}

void sub_80DB69C(void)
{
    s32 i;
    s32 r6;

    for (i = 0; i < 4; i++)
    {
        u8 r4 = gUnknown_02039F26[i] * 5 + 2;
        u16 r5 = sub_80DB5B0();

        r6 = sContestantStatus[i].condition / 10;
        ContestBG_FillBoxWithTile(0, r5, 19, r4,      1, r6,     17);
        ContestBG_FillBoxWithTile(0,  0, 19, r4 + r6, 1, 3 - r6, 17);
    }
}

u16 sub_80DB748(u8 status)
{
    u16 var = 0;

    switch (status)
    {
        case 0:
            var = 0x80;
            break;
        case 1:
            var = 0x84;
            break;
        case 2:
            var = 0x86;
            break;
        case 3:
            var = 0x88;
            break;
        case 4:
            var = 0x82;
            break;
    }
    var += 0x9000;
    return var;
}

bool8 sub_80DB798(u8 a)
{
    bool8 r9 = TRUE;
    u16 r8 = 0;
    u8 r7 = gUnknown_02039F26[a] * 5 + 2;

    if (sContestantStatus[a].resistant != 0 || sContestantStatus[a].immune != 0 || sContestantStatus[a].jamSafetyCount != 0 || sContestantStatus[a].jamReduction != 0)
        r8 = sub_80DB748(0);
    else if (sContestantStatus[a].nervous)
        r8 = sub_80DB748(1);
    else if (sContestantStatus[a].numTurnsSkipped != 0 || sContestantStatus[a].noMoreTurns)
        r8 = sub_80DB748(2);
    else
        r9 = FALSE;
    if (r9)
    {
        ContestBG_FillBoxWithIncrementingTile(0, r8,      20, r7,     2, 1, 17, 1);
        ContestBG_FillBoxWithIncrementingTile(0, r8 + 16, 20, r7 + 1, 2, 1, 17, 1);
    }
    else
    {
        ContestBG_FillBoxWithTile(0, 0, 20, r7, 2, 2, 17);
    }
    return r9;
}
