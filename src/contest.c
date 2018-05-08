#include "global.h"
#include "gpu_regs.h"
#include "bg.h"
#include "malloc.h"
#include "constants/items.h"
#include "constants/map_objects.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/flags.h"
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
#include "contest_link_80F57C4.h"
#include "dma3.h"
#include "battle_message.h"
#include "event_scripts.h"
#include "event_data.h"
#include "strings.h"
#include "contest_effect.h"
#include "contest_link_80FC4F4.h"

#define DESTROY_POINTER(ptr) \
    free(ptr); \
    ptr = NULL;

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
void sub_80DE424(u8);
u8 sub_80DB0C4(void);
u8 sub_80DB120(void);
void sub_80DB2BC(void);
void sub_80DB89C(void);
u16 sub_80DB8B8(u8);
void sub_80DB918(void);
bool8 sub_80DBCA8(u8);
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
void sub_80DE69C(u8);
void sub_80DEA20(void);
void sub_80DEBD0(u32, u8 *, u8, u8, u8);
void sub_80DEC30(const u8 *, u8);
void sub_80DECB8(u8, u16, u8, u8, u8, u8, u8, u8);
bool32 sub_80DED4C(void);
void sub_80DED60(u32);
void sub_80FC9F8(u8);
bool8 AreMovesContestCombo(u16, u16);
void prints_contest_move_description(u16);
void sub_80DBD18(void);
void sub_80DF250(void);
void sub_80DF4F8(void);
void sub_80DD080(u8);
void sub_80DF080(u8);
void sub_80DF750(void);
void sub_80DE9DC(u8);
u8 sub_80DB174(u16, u32, u32, u32);
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

EWRAM_DATA struct ContestPokemon gContestMons[4] = {0};
EWRAM_DATA s16 gUnknown_02039F00[4] = {0};
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

extern u16 gBattle_BG0_X;
extern u16 gBattle_BG0_Y;
extern u16 gBattle_BG1_X;
extern s16 gBattle_BG1_Y;
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
extern const u8 gUnknown_08C17170[];
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
    DESTROY_POINTER(gContestResources->field_0);
    DESTROY_POINTER(gContestResources->field_4);
    DESTROY_POINTER(gContestResources->field_8);
    DESTROY_POINTER(gContestResources->field_C);
    DESTROY_POINTER(gContestResources->field_10);
    DESTROY_POINTER(gContestResources->field_14);
    DESTROY_POINTER(gContestResources->field_18);
    DESTROY_POINTER(gContestResources->field_1c);
    DESTROY_POINTER(gContestResources->field_20);
    DESTROY_POINTER(gContestResources->field_24[0]);
    DESTROY_POINTER(gContestResources->field_24[1]);
    DESTROY_POINTER(gContestResources->field_24[2]);
    DESTROY_POINTER(gContestResources->field_24[3]);
    DESTROY_POINTER(gContestResources->field_34);
    DESTROY_POINTER(gContestResources->field_38);
    DESTROY_POINTER(gContestResources->field_3c);
    DESTROY_POINTER(gContestResources);
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
            DESTROY_POINTER(gMonSpritesGfxPtr->firstDecompressed);
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
            if ((gBattle_BG1_Y += 7) <= 160)
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
        if (!sub_80DBCA8(gContestPlayerMonIndex))
            StringCopy(gDisplayedStringBattle, gText_0827D507);
        else
            StringCopy(gDisplayedStringBattle, gText_0827D531);
        sub_80DB89C();
        StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
        sub_80DEC30(gStringVar4, 1);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!sub_80DED4C())
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
        if (!sub_80DBCA8(gContestPlayerMonIndex))
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
        sub_80DEBD0(i + 5, sp8, 5, 1, 7);
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
                if (!sub_80DBCA8(gContestPlayerMonIndex))
                    StringCopy(gDisplayedStringBattle, gText_0827D507);
                else
                    StringCopy(gDisplayedStringBattle, gText_0827D531);
                sub_80DB89C();
                StringExpandPlaceholders(gStringVar4, gDisplayedStringBattle);
                sub_80DEC30(gStringVar4, 0);
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
    sub_80DECB8(2, 55, 0, 31 + a0 * 2, 2, 2, 17, 1);
}

void sub_80D883C(s8 a0)
{
    sub_80DECB8(2, 11, 0, 31 + a0 * 2, 2, 1, 17, 1);
    sub_80DECB8(2, 11, 0, 32 + a0 * 2, 2, 1, 17, 1);
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
    sub_80DED60(0);

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
                if (gContestResources->field_4[r6].currMove < NUM_MOVES)
                    StringCopy(gStringVar2, gMoveNames[gContestResources->field_4[r6].currMove]);
                else
                    StringCopy(gStringVar2, gUnknown_08587F1C[gContestResources->field_4[r6].moveCategory]);
                StringExpandPlaceholders(gStringVar4, gText_0827D55A);
                sub_80DEC30(gStringVar4, 1);
                gTasks[taskId].data[0] = 6;
            }
            return;
        case 6:
            if (!sub_80DED4C())
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
            if (!sub_80DED4C())
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
            if (!sub_80DED4C())
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
                    sub_80DEC30(gStringVar4, 1);
                }
                gTasks[taskId].data[0] = 52;
            }
            return;
        case 52:
            if (!sub_80DED4C())
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
                    sub_80DEC30(gText_0827E32E, 1);
                else if (r3 == 2)
                    sub_80DEC30(gText_0827E35B, 1);
                else
                    sub_80DEC30(gText_0827E38D, 1);
                sub_80DD720(3);
                gTasks[taskId].data[10] = 0;
                gTasks[taskId].data[0] = 45;
            }
            else
            {
                sub_80DB89C();
                StringCopy(gStringVar1, gContestMons[r6].nickname);
                StringExpandPlaceholders(gStringVar4, gText_0827E2FE);
                sub_80DEC30(gStringVar4, 1);
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
            if (!sub_80DED4C())
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
                sub_80DEC30(gStringVar4, 1);
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
            if (!sub_80DED4C())
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
                    sub_80DEC30(gStringVar4, 1);
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
                    if (!gContestResources->field_0->unk1920B_0 && !sub_80DED4C())
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
                    if (!sub_80DED4C())
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
            sub_80DEC30(gStringVar4, 1);
            gTasks[taskId].data[0] = 58;
            return;
        case 58:
            if (!sub_80DED4C())
            {
                sub_80DB89C();
                StringExpandPlaceholders(gStringVar4, gText_0827E817);
                sub_80DEC30(gStringVar4, 1);
                gTasks[taskId].data[0] = 59;
            }
            return;
        case 59:
            if (!sub_80DED4C())
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
            sub_80DEC30(gStringVar4, 1);
            gTasks[taskId].data[0] = 34;
            return;
        case 34:
            if (!sub_80DED4C())
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
            sub_80DEC30(gStringVar4, 1);
            gTasks[taskId].data[0] = 32;
            return;
        case 32:
            if (!sub_80DED4C())
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
        sub_80DEC30(gStringVar4, 1);
        gTasks[taskId].data[0]++;
    }
    else
    {
        if (!sub_80DED4C())
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
    sub_80DEC30(gStringVar4, 1);
    gTasks[taskId].data[2] = 0;
    gTasks[taskId].func = sub_80DA6B4;
}

void sub_80DA6B4(u8 taskId)
{
    if (!sub_80DED4C())
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
    if (gBattle_BG1_Y < 0)
        gBattle_BG1_Y = 0;
    if (*(u16 *)&gBattle_BG1_Y == 0)  // Why cast?
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
        gContestMons[gContestPlayerMonIndex].trainerGfxId = MAP_OBJ_GFX_LINK_BRENDAN;
    else
        gContestMons[gContestPlayerMonIndex].trainerGfxId = MAP_OBJ_GFX_LINK_MAY;
    gContestMons[gContestPlayerMonIndex].flags = 0;
    gContestMons[gContestPlayerMonIndex].unk2C[0] = 0;
    gContestMons[gContestPlayerMonIndex].species = GetMonData(&gPlayerParty[partyIndex], MON_DATA_SPECIES);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_NICKNAME, name);
    StringGetEnd10(name);
    if (gIsLinkContest & 1)
    {
        sub_80DF9E0(name, GetMonData(&gPlayerParty[partyIndex], MON_DATA_LANGUAGE));
    }
    memcpy(gContestMons[gContestPlayerMonIndex].nickname, name, 11);
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
            if      (contestType == 0 && gContestOpponents[i].aiPool_Cool)
                opponents[opponentsCount++] = i;
            else if (contestType == 1 && gContestOpponents[i].aiPool_Beauty)
                opponents[opponentsCount++] = i;
            else if (contestType == 2 && gContestOpponents[i].aiPool_Cute)
                opponents[opponentsCount++] = i;
            else if (contestType == 3 && gContestOpponents[i].aiPool_Smart)
                opponents[opponentsCount++] = i;
            else if (contestType == 4 && gContestOpponents[i].aiPool_Tough)
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
