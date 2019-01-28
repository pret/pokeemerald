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
#include "new_game.h"
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
#include "contest_ai.h"

extern void sub_80FC9F8(u8); // contest_link_80FC4F4.c

// This file's functions.
static void sub_80D782C(void);
static void sub_80D7C7C(u8 taskId);
static void sub_80D7CB4(u8 taskId);
static void sub_80D7DAC(u8 taskId);
static void sub_80D7DC8(u8 taskId);
static void sub_80D7DE8(u8 taskId);
static bool8 sub_80D7E44(u8 *);
static void sub_80D80C8(u8 taskId);
static void sub_80D8108(u8 taskId);
static void vblank_cb_battle(void);
static void sub_80D823C(void);
static void sub_80D833C(u8 taskId);
static void sub_80D8424(u8 taskId);
static void sub_80D8610(u8 taskId);
static void sub_80D8490(u8 taskId);
static void sub_80D880C(s8);
static void sub_80D883C(s8);
static void sub_80D8894(u8 taskId);
static void sub_80D892C(u8 taskId);
static void sub_80D895C(u8 taskId);
static void sub_80D8A04(u8 taskId);
static void sub_80D8A50(u8 taskId);
static void sub_80D8A88(u8 taskId);
static void sub_80D8B38(u8 taskId);
static void sub_80DA110(u8);
static void sub_80DA134(struct Sprite *);
static void sub_80DA164(struct Sprite *);
static void sub_80DA198(u8);
static void sub_80DA25C(u8);
static void sub_80DA28C(u8);
static void sub_80DA31C(u8);
static void sub_80DA348(u8);
static void sub_80DA38C(u8);
static void sub_80DA3CC(u8);
static void sub_80DA464(u8);
static void sub_80DA49C(u8);
static void sub_80DA4CC(u8);
static void sub_80DA51C(u8);
static void sub_80DA5B4(u8);
static void sub_80DA5E8(u8);
static void sub_80DA6B4(u8);
static void sub_80DA700(u8);
static void sub_80DA740(u8);
static void sub_80DA7A0(u8);
static void sub_80DA7EC(u8);
static void sub_80DA830(u8);
static void sub_80DA874(void);
static bool8 sub_80DA8A4(void);
static void sub_80DAF04(u8);
static void sub_80DAF1C(u8 a0, u8 a1);
static void sub_80DAF88(u8);
static void sub_80DAFA0(u8, u8);
static u8 sub_80DB0C4(void);
static u8 sub_80DB120(void);
static u8 sub_80DB174(u16, u32, u32, u32);
static void prints_contest_move_description(u16);
static u16 SanitizeSpecies(u16);
static void sub_80DB89C(void);
static u16 GetChosenMove(u8);
static void sub_80DB918(void);
static void sub_80DBF68(void);
static void sub_80DBF90(void);
static void sub_80DC2BC(void);
static void sub_80DC490(bool8);
static void sub_80DC4F0(void);
static void CreateApplauseMeterSprite(void);
static void sub_80DC5E8(void);
static void sub_80DC7EC(void);
static void sub_80DCD48(void);
static void sub_80DD04C(void);
static void sub_80DD590(void);
static void sub_80DDB0C(void);
static void sub_80DDBE8(void);
static void sub_80DE224(void);
static void sub_80DE350(void);
static void sub_80DE424(u8);
static void sub_80DE69C(u8);
static void sub_80DEA20(void);
static void Contest_StartTextPrinter(const u8 *, u32);
static void ContestBG_FillBoxWithIncrementingTile(u8, u16, u8, u8, u8, u8, u8, s16);
static bool32 Contest_RunTextPrinters(void);
static void Contest_SetBgCopyFlags(u32);
static void sub_80DBD18(void);
static void sub_80DD080(u8);
static void sub_80DE9DC(u8);
static void sub_80DCBE8(u8, u8);
static u8 sub_80DC9EC(u8);
static u16 SanitizeMove(u16);
static void sub_80DE864(u8);
static void SelectContestMoveBankTarget(u16);
static void sub_80DE9B0(u8);
static void sub_80DC674(u8);
static void sub_80DE12C(void);
static void sub_80DD45C(u8, u8);
static void sub_80DD720(u8);
static void sub_80DE008(bool8);
static u8 sub_80DC028(s16, s16, u8);
static bool8 sub_80DB5B8(u8, u8);
static bool8 sub_80DB798(u8);
static void sub_80DB884(void);
static void sub_80DC9B4(u8);
static void sub_80DDED0(s8, s8);
static void sub_80DDCDC(s8);
static void sub_80DDE0C(void);
static void sub_80DD940(void);
static void sub_80DB944(void);
static void sub_80DBA18(void);
static void sub_80DC3AC(void);
static bool8 sub_80DC3C4(void);
static void ContestBG_FillBoxWithTile(u8, u16, u8, u8, u8, u8, u8);
static void Contest_PrintTextToBg0WindowStd(u32, const u8 *);
static s16 sub_80DBD34(u8);
static void DetermineFinalStandings(void);
static bool8 sub_80DBF30(s32, s32, struct UnknownContestStruct6 *);
static void sub_80DC0F4(u8);
static void sub_80DC408(struct Sprite *);
static void sub_80DC728(u8);
static void sub_80DC6A4(u8);
static void sub_80DC8D0(u8);
static void sub_80DC81C(u8);
static void sub_80DC87C(u8);
static void sub_80DCC84(struct Sprite *);
static void sub_80DCCD8(struct Sprite *sprite);
static u8 sub_80DDA20(void);
static void c3_08130B10(u8);
static void sub_80DDB6C(u8);
static void task08_080CD1CC(u8);
static void sub_80DDD20(u8);
static void sub_80DDE30(u8);
static void sub_80DDF80(u8);
static const u8 *GetTurnOrderNumberGfx(u8);
static void sub_80DE464(u8);
static void sub_80DE4A8(u8);
static void sub_80DE5F4(u8);
static void sub_80DE65C(u8);
static void sub_80DE794(u8);
static void sub_80DEA5C(void);
static void sub_80DF250(void);
static void sub_80DF4F8(void);
static void sub_80DF080(u8);
static void sub_80DF750(void);
static void sub_80DF9D4(u8 *);
static void sub_80DF9E0(u8 *, s32);
static void sub_80DB2BC(void);

// EWRAM vars.
EWRAM_DATA struct ContestPokemon gContestMons[4] = {0};
EWRAM_DATA s16 gContestMonConditions[4] = {0};
EWRAM_DATA s16 gUnknown_02039F08[4] = {0};
EWRAM_DATA s16 gUnknown_02039F10[4] = {0};
EWRAM_DATA s16 gUnknown_02039F18[4] = {0};
EWRAM_DATA u8 gContestFinalStandings[4] = {0};
EWRAM_DATA u8 gContestMonPartyIndex = 0;
EWRAM_DATA u8 gContestPlayerMonIndex = 0;
EWRAM_DATA u8 gUnknown_02039F26[4] = {0};
EWRAM_DATA u8 gIsLinkContest = 0;
// Bit 0: Is a link contest
// Bit 1: Link contest uses wireless adapter
EWRAM_DATA u8 gUnknown_02039F2B = 0;
EWRAM_DATA u16 gSpecialVar_ContestCategory = 0;
EWRAM_DATA u16 gSpecialVar_ContestRank = 0;
EWRAM_DATA u8 gNumLinkContestPlayers = 0;
EWRAM_DATA u8 gHighestRibbonRank = 0;
EWRAM_DATA struct ContestResources *gContestResources = NULL;
EWRAM_DATA u8 sContestBgCopyFlags = 0;
EWRAM_DATA struct ContestWinner gUnknown_02039F3C = {0};

// IWRAM common vars.
u32 gContestRngValue;

extern const u16 gUnknown_08587C30[];
extern const struct BgTemplate gUnknown_08587F34[4];
extern const struct WindowTemplate gUnknown_08587F44[];
extern const u8 *const gUnknown_08587D90[];
extern const u8 *const gUnknown_08587F08[];
extern const u8 *const gUnknown_08587F1C[];
extern const u8 *const gUnknown_0827E8DA[];
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
extern const u8 gText_Contest_Shyness[];
extern const u8 gText_Contest_Anxiety[];
extern const u8 gText_Contest_Laziness[];
extern const u8 gText_Contest_Hesitancy[];
extern const u8 gText_Contest_Fear[];
extern const u8 gText_BDot[];
extern const u8 gText_CDot[];
extern const u8 *const gUnknown_08587E10[];
extern const struct ContestPokemon gContestOpponents[96];
extern const u8 gUnknown_085898A4[96];
extern const struct CompressedSpriteSheet gUnknown_08587C00;
extern const struct SpriteTemplate gSpriteTemplate_8587BE8;
extern const struct CompressedSpriteSheet gUnknown_08587C08;
extern const struct CompressedSpritePalette gUnknown_08587C10;
extern const struct SpriteTemplate gSpriteTemplate_8587C18;
extern const union AffineAnimCmd *const gUnknown_082FF6C0[];
extern const union AffineAnimCmd *const gUnknown_082FF694[];
extern const u8 *const gContestEffectDescriptionPointers[];
extern const struct SpriteSheet gUnknown_08587A74;
extern const u8 gUnknown_08587A6C[];
extern const struct SpriteTemplate gSpriteTemplate_8587AD0;
extern const struct SpritePalette gUnknown_08587B08;
extern const struct CompressedSpriteSheet gUnknown_08587AE8[];
extern const struct SpriteTemplate gSpriteTemplate_8587B18[];
extern const u8 gUnknown_08587A70[];
extern const struct SubspriteTable gSubspriteTables_8587B80[];
extern const struct CompressedSpriteSheet gUnknown_08587BB0;
extern const struct SpritePalette gUnknown_08587BB8;
extern const struct SpriteTemplate gSpriteTemplate_8587BC8;
extern void (*const gContestEffectFuncs[])(void);
extern const s8 gContestExcitementTable[][5];
extern const struct ContestWinner gUnknown_08587FA4[];
extern const struct CompressedSpriteSheet gUnknown_08589904[];
extern const struct SpritePalette gUnknown_08589924[];
extern const struct SpriteTemplate gSpriteTemplate_858998C[];

static void TaskDummy1(u8 taskId)
{
}

void ResetLinkContestBoolean(void)
{
    gIsLinkContest = 0;
}

static void sub_80D7678(void)
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
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 var = 5 + i;

        LoadPalette(shared18000.unk18004[var], 16 * (5 + gUnknown_02039F26[i]), 16 * sizeof(u16));
    }
}

static void sub_80D779C(void)
{
    s32 i;

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_08587F34, ARRAY_COUNT(gUnknown_08587F34));
    SetBgAttribute(3, BG_ATTR_WRAPAROUND, 1);
    for (i = 0; i < 4; i++)
    {
        SetBgTilemapBuffer(i, gContestResources->field_24[i]);
    }
}

static void sub_80D77E4(void)
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

static void sub_80D782C(void)
{
    s32 i;

    LoadPalette(gUnknown_08587C30, 0xf0, 0x20);
    FillPalette(RGB_BLACK, 0, 2);
    for (i = 10; i < 14; i++)
        LoadPalette(gPlttBufferUnfaded + 241, 240 + i, 2);
    FillPalette(RGB(31, 17, 31), 0xF3, 2);
}

static void sub_80D787C(void)
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
    memset(gContestResources->field_1c, 0, sizeof(*gContestResources->field_1c) * 4);
}

static void sub_80D7988(void)
{
    gContestResources = AllocZeroed(sizeof(struct ContestResources));
    gContestResources->field_0 = AllocZeroed(sizeof(struct Contest));
    gContestResources->field_4 = AllocZeroed(sizeof(struct ContestantStatus) * 4);
    gContestResources->field_8 = AllocZeroed(sizeof(struct UnknownContestStruct7));
    gContestResources->field_C = AllocZeroed(sizeof(struct ContestAIInfo));
    gContestResources->field_10 = AllocZeroed(sizeof(struct UnknownContestStruct5) * 4);
    gContestResources->field_14 = AllocZeroed(sizeof(struct UnknownContestStruct4) * 4);
    gContestResources->field_18 = AllocZeroed(sizeof(struct ContestStruct_field_18));
    gContestResources->field_1c = AllocZeroed(sizeof(struct ContestResourcesField1C) * 4);
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

static void sub_80D7A5C(void)
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

static void sub_80D7C7C(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80D7CB4;
    }
}

static void sub_80D7CB4(u8 taskId)
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
                if (IsLinkTaskFinished())
                {
                    sub_800ADF8();
                    gTasks[taskId].data[0]++;
                }
                return;
            case 2:
                if (IsLinkTaskFinished() != TRUE)
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

static void sub_80D7DAC(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_80FC998, sub_80D7DC8);
}

static void sub_80D7DC8(u8 taskId)
{
    gTasks[taskId].data[0] = 1;
    gTasks[taskId].func = sub_80D7DE8;
}

static void sub_80D7DE8(u8 taskId)
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

static u8 sub_80D7E44(u8 *a)
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
        CreateApplauseMeterSprite();
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

static void sub_80D80C8(u8 taskId)
{
    gPaletteFade.bufferTransferDisabled = FALSE;
    if (!gPaletteFade.active)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = sub_80D8108;
    }
}

static void sub_80D8108(u8 taskId)
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

static void sub_80D823C(void)
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

static void vblank_cb_battle(void)
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

static void sub_80D833C(u8 taskId)
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

static void sub_80D8424(u8 taskId)
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

static void sub_80D8490(u8 taskId)
{
    u8 i;
    u8 sp8[32];

    gBattle_BG0_Y = 0xA0;
    gBattle_BG2_Y = 0xA0;

    for (i = 0; i < MAX_MON_MOVES; i++)
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

static void sub_80D8610(u8 taskId)
{
    u8 numMoves = 0;
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
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

static void sub_80D880C(s8 a0)
{
    ContestBG_FillBoxWithIncrementingTile(2, 55, 0, 31 + a0 * 2, 2, 2, 17, 1);
}

static void sub_80D883C(s8 a0)
{
    ContestBG_FillBoxWithIncrementingTile(2, 11, 0, 31 + a0 * 2, 2, 1, 17, 1);
    ContestBG_FillBoxWithIncrementingTile(2, 11, 0, 32 + a0 * 2, 2, 1, 17, 1);
}

static void sub_80D8894(u8 taskId)
{
    if (gIsLinkContest & 1)
    {
        u16 var = GetChosenMove(gContestPlayerMonIndex);
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

static void sub_80D892C(u8 taskId)
{
    DestroyTask(taskId);
    gTasks[gContestResources->field_0->mainTaskId].func = sub_80D895C;
}

static void sub_80D895C(u8 taskId)
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

static void sub_80D8A04(u8 taskId)
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

static void sub_80D8A50(u8 taskId)
{
    if (!gContestResources->field_0->unk1920A_6 && !gContestResources->field_0->unk1920B_1)
        gTasks[taskId].func = sub_80D8A88;
}

static void sub_80D8A88(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 19)
    {
        gContestResources->field_0->unk19214 = 0;
        gContestResources->field_0->unk1921C = gRngValue;
        if ((gIsLinkContest & 1) && sub_80DA8A4())
        {
            s32 i;

            for (i = 0; i + gNumLinkContestPlayers < 4; i++)
            {
                gContestResources->field_4[gNumLinkContestPlayers + i].currMove = GetChosenMove(gNumLinkContestPlayers + i);
            }
        }
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80D8B38;
    }
}

static void sub_80D8B38(u8 taskId)
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
            u16 move = SanitizeMove(gContestResources->field_4[gContestResources->field_0->unk19215].currMove);

            sub_80DE864(gContestResources->field_0->unk19215);
            sub_80DE9DC(gContestResources->field_0->unk19215);
            SelectContestMoveBankTarget(move);
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

static void sub_80DA110(u8 taskId)
{
    sContest.unk1920B_2 = 0;
    DestroyTask(taskId);
}

static void sub_80DA134(struct Sprite *sprite)
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

static void sub_80DA164(struct Sprite *sprite)
{
    sprite->pos2.x -= 6;
    if (sprite->pos1.x + sprite->pos2.x < -32)
    {
        sprite->callback = SpriteCallbackDummy;
        sprite->invisible = TRUE;
    }
}

static void sub_80DA198(u8 taskId)
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

static void sub_80DA25C(u8 taskId)
{
    sub_80DE008(FALSE);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 0;
    gTasks[taskId].func = sub_80DA28C;
}

static void sub_80DA28C(u8 taskId)
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

static void sub_80DA31C(u8 taskId)
{
    if (sub_80DC3C4())
        gTasks[taskId].func = sub_80DA348;
}

static void sub_80DA348(u8 taskId)
{
    DmaCopy32Defvars(3, shared18000.unk18204, gPlttBufferUnfaded, 0x400);
    gTasks[taskId].data[0] = 0;
    gTasks[taskId].data[1] = 2;
    gTasks[taskId].func = sub_80DA38C;
}

static void sub_80DA38C(u8 taskId)
{
    if (++gTasks[taskId].data[0] > 2)
    {
        gTasks[taskId].data[0] = 0;
        if (--gTasks[taskId].data[1] == 0)
            gTasks[taskId].func = sub_80DA3CC;
    }
}

static void sub_80DA3CC(u8 taskId)
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

static void sub_80DA464(u8 taskId)
{
    if (gTasks[taskId].data[0]++ > 29)
    {
        gTasks[taskId].data[0] = 0;
        sub_80DC3AC();
        gTasks[taskId].func = sub_80DA49C;
    }
}

static void sub_80DA49C(u8 taskId)
{
    if (sub_80DC3C4())
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DA4CC;
    }
}

static void sub_80DA4CC(u8 taskId)
{
    sub_80DE224();
    gTasks[taskId].func = sub_80DE424;
}

static void sub_80DA4F4(u8 taskId)
{
    sub_80DE350();
    gTasks[taskId].func = sub_80DA51C;
}

static void sub_80DA51C(u8 taskId)
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

static void sub_80DA5B4(u8 taskId)
{
    if (!sContest.unk1920A_6)
        gTasks[taskId].func = sub_80D833C;
}

static void sub_80DA5E8(u8 taskId)
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

static void sub_80DA6B4(u8 taskId)
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

static void sub_80DA700(u8 taskId)
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

static void sub_80DA740(u8 taskId)
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

static void sub_80DA7A0(u8 taskId)
{
    u8 taskId2 = CreateTask(sub_80FCACC, 0);

    SetTaskFuncWithFollowupFunc(taskId2, sub_80FCACC, sub_80DA7EC);
    gTasks[taskId].func = TaskDummy1;
    sub_80DBF68();
    sub_80DC490(FALSE);
}

static void sub_80DA7EC(u8 taskId)
{
    DestroyTask(taskId);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, 0);
    gTasks[sContest.mainTaskId].func = sub_80DA830;
}

static void sub_80DA830(u8 taskId)
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

static void sub_80DA874(void)
{
    ScriptContext2_Disable();
    EnableBothScriptContexts();
}

static void sub_80DA884(void)
{
    if (!(gIsLinkContest & 1))
        gContestPlayerMonIndex = 3;
}

static bool8 sub_80DA8A4(void)
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

    sub_80DA8C8(gContestMonPartyIndex);
}

void sub_80DACBC(u8 contestType, u8 rank, bool32 isPostgame)
{
    s32 i, j;
    u8 opponentsCount = 0;
    u8 opponents[100];

    if (gNumLinkContestPlayers == 4)
        return;

    for (i = 0; i < ARRAY_COUNT(gContestOpponents); i++)
    {
        if (rank != gContestOpponents[i].whichRank)
            continue;

        if (isPostgame == TRUE)
        {
            if (gUnknown_085898A4[i] == 1)
                continue;
        }
        else
        {
            if (gUnknown_085898A4[i] == 2)
                continue;
        }
        if ((contestType == CONTEST_CATEGORY_COOL && gContestOpponents[i].aiPool_Cool)
            || (contestType == CONTEST_CATEGORY_BEAUTY && gContestOpponents[i].aiPool_Beauty)
            || (contestType == CONTEST_CATEGORY_CUTE && gContestOpponents[i].aiPool_Cute)
            || (contestType == CONTEST_CATEGORY_SMART && gContestOpponents[i].aiPool_Smart)
            || (contestType == CONTEST_CATEGORY_TOUGH && gContestOpponents[i].aiPool_Tough))
            opponents[opponentsCount++] = i;
    }
    opponents[opponentsCount] = 0xFF;
    for (i = 0; i < 4 - gNumLinkContestPlayers; i++)
    {
        u16 rnd = sub_80F903C() % opponentsCount;

        gContestMons[gNumLinkContestPlayers + i] = gContestOpponents[opponents[rnd]];
        sub_80DF9D4(gContestMons[gNumLinkContestPlayers + i].trainerName);
        sub_80DF9E0(gContestMons[gNumLinkContestPlayers + i].nickname, GAME_LANGUAGE);
        for (j = rnd; opponents[j] != 0xFF; j++)
            opponents[j] = opponents[j + 1];
        opponentsCount--;
    }
}

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

static void sub_80DAEA4(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        FillWindowPixelBuffer(gUnknown_02039F26[i], 0);
        sub_80DAF04(i);
        sub_80DAF88(i);
    }
}

static u8 *sub_80DAED4(const u8 *src, u8 color)
{
    u8 * ptr = StringCopy(gDisplayedStringBattle, gText_ColorTransparent);
    ptr[-1] = color;
    ptr = StringCopy(ptr, src);

    return ptr;
}

static void sub_80DAF04(u8 a0)
{
    sub_80DAF1C(a0, a0 + 10);
}

static void sub_80DAF1C(u8 a0, u8 a1)
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

static void sub_80DAF88(u8 a0)
{
    sub_80DAFA0(a0, a0 + 10);
}

static void sub_80DAFA0(u8 a0, u8 a1)
{
    sub_80DAED4(gContestMons[a0].nickname, a1);
    Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[a0], gDisplayedStringBattle, 5, 1, 7);
}

static u16 sub_80DAFE0(u8 who, u8 contestCategory)
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

void sub_80DB09C(u8 contestCategory)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gContestMonConditions[i] = sub_80DAFE0(i, contestCategory);
}

static u8 sub_80DB0C4(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08587C00);
    LoadCompressedPalette(gContest2Pal, 0x110, 32);
    spriteId = CreateSprite(&gSpriteTemplate_8587BE8, 112, 36, 30);
    gSprites[spriteId].oam.paletteNum = 1;
    gSprites[spriteId].callback = SpriteCallbackDummy;
    return spriteId;
}

static u8 sub_80DB120(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08587C08);
    LoadCompressedSpritePalette(&gUnknown_08587C10);
    spriteId = CreateSprite(&gSpriteTemplate_8587C18, 96, 10, 29);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].data[0] = gSprites[spriteId].oam.tileNum;
    return spriteId;
}

static u8 sub_80DB174(u16 species, u32 otId, u32 personality, u32 index)
{
    u8 spriteId;
    species = SanitizeSpecies(species);

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

static void sub_80DB2BC(void)
{
    CpuCopy16(gContestResources->field_24[0], gContestResources->field_24[0] + 0x500, 0x280);
    CpuCopy16(gContestResources->field_24[2], gContestResources->field_24[2] + 0x500, 0x280);
}

static u16 sub_80DB2EC(u16 a0, u8 a1)
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

static void prints_contest_move_description(u16 a)
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

static void sub_80DB4E0(u16 move, u8 b)
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

static void sub_80DB584(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        sub_80DB4E0(gContestResources->field_4[i].currMove, i);
}

static u16 sub_80DB5B0(void)
{
    return 0x2034;
}

static bool8 sub_80DB5B8(u8 contestantIdx, bool8 resetMod)
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

static void sub_80DB69C(void)
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

static u16 sub_80DB748(u8 status)
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

static bool8 sub_80DB798(u8 a)
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

static void sub_80DB884(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        sub_80DB798(i);
}

static void sub_80DB89C(void)
{
    FillWindowPixelBuffer(4, 0);
    CopyWindowToVram(4, 2);
    Contest_SetBgCopyFlags(0);
}

static u16 GetChosenMove(u8 a)
{
    if (Contest_IsMonsTurnDisabled(a))
        return 0;
    if (a == gContestPlayerMonIndex)
    {
        return gContestMons[a].moves[sContest.playerMoveChoice];
    }
    else
    {
        u8 moveChoice;

        ContestAI_ResetAI(a);
        moveChoice = ContestAI_GetActionToUse();
        return gContestMons[a].moves[moveChoice];
    }
}

static void sub_80DB918(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        sContestantStatus[i].currMove = GetChosenMove(i);
}

static void sub_80DB944(void)
{
    s32 i;
    s32 j;
    s16 arr[4];

    for (i = 0; i < 4; i++)
    {
        sContestantStatus[i].unk4 += sContestantStatus[i].appeal2;
        arr[i] = sContestantStatus[i].unk4;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 3; j > i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                u16 temp = arr[j];

                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (sContestantStatus[i].unk4 == arr[j])
            {
                sContestantStatus[i].unkB_0 = j;
                break;
            }
        }
    }
    sub_80DCE58(1);
    sub_80DD590();
}

static void sub_80DBA18(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        u8 attentionLevel;

        if (sContestantStatus[i].currMove == MOVE_NONE)
            attentionLevel = 5;
        else if (sContestantStatus[i].appeal2 <= 0)
            attentionLevel = 0;
        else if (sContestantStatus[i].appeal2 < 30)
            attentionLevel = 1;
        else if (sContestantStatus[i].appeal2 < 60)
            attentionLevel = 2;
        else if (sContestantStatus[i].appeal2 < 80)
            attentionLevel = 3;
        else
            attentionLevel = 4;

        sContestantStatus[i].attentionLevel = attentionLevel;
    }
}

static bool8 sub_80DBA68(u8 a)
{
    if (sContestantStatus[a].numTurnsSkipped != 0 || sContestantStatus[a].noMoreTurns)
        return FALSE;
    else
        return TRUE;
}

static void sub_80DBAA0(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        sContestantStatus[i].appeal2 = 0;
        sContestantStatus[i].appeal1 = 0;
        sContestantStatus[i].jamSafetyCount = 0;
        if (sContestantStatus[i].numTurnsSkipped > 0)
            sContestantStatus[i].numTurnsSkipped--;
        sContestantStatus[i].jam = 0;
        sContestantStatus[i].resistant = 0;
        sContestantStatus[i].jamReduction = 0;
        sContestantStatus[i].immune = 0;
        sContestantStatus[i].moreEasilyStartled = 0;
        sContestantStatus[i].usedRepeatableMove = 0;
        sContestantStatus[i].nervous = 0;
        sContestantStatus[i].effectStringId = CONTEST_STRING_NONE;
        sContestantStatus[i].effectStringId2 = CONTEST_STRING_NONE;
        sContestantStatus[i].conditionMod = 0;
        sContestantStatus[i].unk15_2 = sContestantStatus[i].disappointedRepeat;
        sContestantStatus[i].disappointedRepeat = FALSE;
        sContestantStatus[i].turnOrderModAction = 0;
        sContestantStatus[i].appealTripleCondition = 0;
        if (sContestantStatus[i].turnSkipped)
        {
            sContestantStatus[i].numTurnsSkipped = 1;
            sContestantStatus[i].turnSkipped = 0;
        }
        if (sContestantStatus[i].exploded)
        {
            sContestantStatus[i].noMoreTurns = 1;
            sContestantStatus[i].exploded = 0;
        }
        sContestantStatus[i].overrideCategoryExcitementMod = 0;
    }
    for (i = 0; i < 4; i++)
    {
        sContestantStatus[i].prevMove = sContestantStatus[i].currMove;
        sContest.unk19220[sContest.turnNumber][i] = sContestantStatus[i].currMove;
        sContest.unk19248[sContest.turnNumber][i] = Contest_GetMoveExcitement(sContestantStatus[i].currMove);
        sContestantStatus[i].currMove = MOVE_NONE;
    }
    shared19328.excitementFrozen = 0;
}

bool8 Contest_IsMonsTurnDisabled(u8 a)
{
    if (sContestantStatus[a].numTurnsSkipped != 0 || sContestantStatus[a].noMoreTurns)
        return TRUE;
    else
        return FALSE;
}

static void sub_80DBCE0(u8 a)
{
    gUnknown_02039F18[a] = sub_80DBD34(a);
    gUnknown_02039F08[a] = gContestMonConditions[a] + gUnknown_02039F18[a];
}

static void sub_80DBD18(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        sub_80DBCE0(i);
    DetermineFinalStandings();
}

static s16 sub_80DBD34(u8 a)
{
    return gUnknown_02039F10[a] * 2;
}

static void DetermineFinalStandings(void)
{
    u16 sp0[4] = {0};
    struct UnknownContestStruct6 sp8[4];
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++)
    {
        s32 r2;

        sp0[i] = Random();
        for (r2 = 0; r2 < i; r2++)
        {
            if (sp0[i] == sp0[r2])
            {
                i--;
                break;
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        sp8[i].unk0 = gUnknown_02039F08[i];
        sp8[i].unk4 = gContestMonConditions[i];
        sp8[i].unk8 = sp0[i];
        sp8[i].unkC = i;
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 3; j > i; j--)
        {
            if (sub_80DBF30(j - 1, j, sp8))
            {
                struct UnknownContestStruct6 temp;

                temp.unk0 = sp8[j - 1].unk0;
                temp.unk4 = sp8[j - 1].unk4;
                temp.unk8 = sp8[j - 1].unk8;
                temp.unkC = sp8[j - 1].unkC;

                sp8[j - 1].unk0 = sp8[j].unk0;
                sp8[j - 1].unk4 = sp8[j].unk4;
                sp8[j - 1].unk8 = sp8[j].unk8;
                sp8[j - 1].unkC = sp8[j].unkC;

                sp8[j].unk0 = temp.unk0;
                sp8[j].unk4 = temp.unk4;
                sp8[j].unk8 = temp.unk8;
                sp8[j].unkC = temp.unkC;
            }
        }
    }

    for (i = 0; i < 4; i++)
        gContestFinalStandings[sp8[i].unkC] = i;
}

void sub_80DBED4(void)
{
    if ((gIsLinkContest & 1))
    {
        gSaveBlock2Ptr->contestLinkResults[gSpecialVar_ContestCategory][gContestFinalStandings[gContestPlayerMonIndex]] =
        ((gSaveBlock2Ptr->contestLinkResults[gSpecialVar_ContestCategory][gContestFinalStandings[gContestPlayerMonIndex]] + 1) > 9999) ? 9999 :
        (gSaveBlock2Ptr->contestLinkResults[gSpecialVar_ContestCategory][gContestFinalStandings[gContestPlayerMonIndex]] + 1);

    }
}

static bool8 sub_80DBF30(s32 a, s32 b, struct UnknownContestStruct6 *c)
{
    bool8 retVal;

    if (c[a].unk0 < c[b].unk0)
        retVal = TRUE;
    else if (c[a].unk0 > c[b].unk0)
        retVal = FALSE;
    else if (c[a].unk4 < c[b].unk4)
        retVal = TRUE;
    else if (c[a].unk4 > c[b].unk4)
        retVal = FALSE;
    else if (c[a].unk8 < c[b].unk8)
        retVal = TRUE;
    else
        retVal = FALSE;
    return retVal;
}

static void sub_80DBF68(void)
{
    gBattle_BG0_Y = 0;
    gBattle_BG2_Y = 0;
    sub_80DB89C();
    Contest_StartTextPrinter((u8*) &gUnknown_0827E8DA, 0);
}

static void sub_80DBF90(void)
{
    int i;

    for(i = 0; i < 4; i++)
    {
        ContestBG_FillBoxWithTile(0, 0, 0x16, 2 + i * 5, 8, 2, 0x11);
    }
}

static u16 sub_80DBFC8(u8 a)
{
    u16 var;

    if (a == 0)
        var = 0x5011;
    else if (a == 1)
        var = 0x6011;
    else if (a == 2)
        var = 0x7011;
    else
        var = 0x8011;
    return var + 1;
}

static s8 sub_80DBFFC(s16 a)
{
    s8 retVal = a / 10;

    if (retVal > 16)
        retVal = 16;
    else if (retVal < -16)
        retVal = -16;
    return retVal;
}

static u8 sub_80DC028(s16 a, s16 b, u8 c)
{
    u8 taskId;
    s8 r4;
    s8 r5;

    gContestResources->field_14[c].unk2_2 = 1;
    taskId = CreateTask(sub_80DC0F4, 20);
    r4 = sub_80DBFFC(a);
    r5 = sub_80DBFFC(a + b) - r4;
    sub_80DBFC8(c);  // unused return value
    gTasks[taskId].data[0] = abs(r4);
    gTasks[taskId].data[1] = r5;
    if (r4 > 0 || (r4 == 0 && r5 > 0))
        gTasks[taskId].data[2] = 1;
    else
        gTasks[taskId].data[2] = -1;
    gTasks[taskId].data[3] = c;
    return taskId;
}

static void sub_80DC0F4(u8 taskId)
{
    u8 r7 = gTasks[taskId].data[3];
    s16 r3 = gTasks[taskId].data[0];
    s16 r1 = gTasks[taskId].data[1];

    if (++gTasks[taskId].data[10] > 14)
    {
        u16 r6;
        u8 r5;
        u8 r10;
        u8 r11;

        gTasks[taskId].data[10] = 0;
        if (gTasks[taskId].data[1] == 0)
        {
            DestroyTask(taskId);
            gContestResources->field_14[r7].unk2_2 = 0;
            return;
        }
        else if (r3 == 0)
        {
            if (r1 < 0)
            {
                r6 = sub_80DBFC8(r7) + 2;
                gTasks[taskId].data[1]++;
            }
            else
            {
                r6 = sub_80DBFC8(r7);
                gTasks[taskId].data[1]--;
            }
            r5 = gTasks[taskId].data[0]++;
        }
        else
        {
            if (gTasks[taskId].data[2] < 0)
            {
                if (r1 < 0)
                {
                    r5 = gTasks[taskId].data[0]++;
                    gTasks[taskId].data[1]++;
                    r6 = sub_80DBFC8(r7) + 2;
                }
                else
                {
                    r5 = --gTasks[taskId].data[0];
                    r6 = 0;
                    gTasks[taskId].data[1]--;
                }
            }
            else
            {
                if (r1 < 0)
                {
                    r5 = --gTasks[taskId].data[0];
                    r6 = 0;
                    gTasks[taskId].data[1]++;
                }
                else
                {
                    r5 = gTasks[taskId].data[0]++;
                    gTasks[taskId].data[1]--;
                    r6 = sub_80DBFC8(r7);
                }
            }
        }
        r10 = r5;
        r11 = 0;

        if (r5 > 7)
        {
            r11 = 1;
            r5-= 8;
        }
        ContestBG_FillBoxWithTile(0, r6, r5 + 22, gUnknown_02039F26[r7] * 5 + 2 + r11,  1, 1, 17);
        if (r1 > 0)
        {
            PlaySE(SE_C_GAJI);
            m4aMPlayImmInit(&gMPlayInfo_SE1);
            m4aMPlayPitchControl(&gMPlayInfo_SE1, 0xFFFF, r10 * 256);
        }
        else
        {
            PlaySE(SE_BOO);
        }

        if (!r11 && !r5 && !r6)
            gTasks[taskId].data[2] = -gTasks[taskId].data[2];
    }
}

static void sub_80DC2BC(void)
{
    s32 i;

    LoadSpriteSheet(&gUnknown_08587A74);
    for (i = 0; i < 4; i++)
    {
        u8 y = gUnknown_08587A6C[gUnknown_02039F26[i]];

        gContestResources->field_14[i].unk0 = CreateSprite(&gSpriteTemplate_8587AD0, 180, y, 1);
    }
}

static void sub_80DC308(u8 a)
{
    u8 spriteId;
    s16 r5;

    gContestResources->field_14[a].unk2_0 = 1;
    spriteId = gContestResources->field_14[a].unk0;
    r5 = sContestantStatus[a].unk4 / 10 * 2;
    if (r5 > 56)
        r5 = 56;
    else if (r5 < 0)
        r5 = 0;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].data[0] = a;
    gSprites[spriteId].data[1] = r5;
    if (gSprites[spriteId].data[1] > gSprites[spriteId].pos2.x)
        gSprites[spriteId].data[2] = 1;
    else
        gSprites[spriteId].data[2] = -1;
    gSprites[spriteId].callback = sub_80DC408;
}

static void sub_80DC3AC(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        sub_80DC308(i);
}

static bool8 sub_80DC3C4(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gContestResources->field_14[i].unk2_0)
            break;
    }
    if (i == 4)
        return TRUE;
    else
        return FALSE;
}

static void sub_80DC408(struct Sprite *sprite)
{
    if (sprite->pos2.x == sprite->data[1])
    {
        gContestResources->field_14[sprite->data[0]].unk2_0 = 0;
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        sprite->pos2.x += sprite->data[2];
    }
}

static void sub_80DC44C(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        gSprites[gContestResources->field_14[i].unk0].pos1.y = gUnknown_08587A6C[gUnknown_02039F26[i]];
}

static void sub_80DC490(bool8 a)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (gUnknown_02039F26[i] > 1)
        {
            if (!a)
                gSprites[gContestResources->field_14[i].unk0].pos1.x = 180;
            else
                gSprites[gContestResources->field_14[i].unk0].pos1.x = 256;
        }
    }
}

static void sub_80DC4F0(void)
{
    s32 i;

    LoadSpritePalette(&gUnknown_08587B08);
    for (i = 0; i < 4; i++)
    {
        LoadCompressedSpriteSheet(&gUnknown_08587AE8[i]);
        gContestResources->field_14[i].unk1 = CreateSprite(&gSpriteTemplate_8587B18[i],
                                                           204,
                                                           gUnknown_08587A70[gUnknown_02039F26[i]],
                                                           0);
        SetSubspriteTables(&gSprites[gContestResources->field_14[i].unk1], gSubspriteTables_8587B80);
        gSprites[gContestResources->field_14[i].unk1].invisible = TRUE;
    }
}

static void CreateApplauseMeterSprite(void)
{
    u8 spriteId;

    LoadCompressedSpriteSheet(&gUnknown_08587BB0);
    LoadSpritePalette(&gUnknown_08587BB8);
    spriteId = CreateSprite(&gSpriteTemplate_8587BC8, 30, 44, 1);
    gSprites[spriteId].invisible = TRUE;
    sContest.applauseMeterSpriteId = spriteId;
}

static void sub_80DC5E8(void)
{
    u8 i;
    u8 taskId = CreateTask(sub_80DC728, 30);

    sContest.unk19211 = taskId;
    for (i = 0; i < 4; i++)
        gTasks[taskId].data[i * 4] = 0xFF;
}

static void sub_80DC630(u8 a)
{
    gTasks[sContest.unk19211].data[a * 4 + 0] = 0;
    gTasks[sContest.unk19211].data[a * 4 + 1] = 0;
}

static void sub_80DC674(u8 a)
{
    u8 taskId = CreateTask(sub_80DC6A4, 31);

    gTasks[taskId].data[0] = a;
}

static void sub_80DC6A4(u8 taskId)
{
    u8 r4 = gTasks[taskId].data[0];

    if (gTasks[sContest.unk19211].data[r4 * 4 + 0] == 0
     || gTasks[sContest.unk19211].data[r4 * 4 + 0] == 0xFF)
    {
        gTasks[sContest.unk19211].data[r4 * 4 + 0] = 0xFF;
        gTasks[sContest.unk19211].data[r4 * 4 + 1] = 0;
        BlendPalette((sContest.unk19218[r4] + 5) * 16 + 6, 2, 0, RGB(31, 31, 18));
        DestroyTask(taskId);
    }
}

static void sub_80DC728(u8 taskId)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        u8 r3 = i * 4;

        if (gTasks[taskId].data[r3 + 0] != 0xFF)
        {
            if (gTasks[taskId].data[r3 + 1] == 0)
                gTasks[taskId].data[r3 + 0]++;
            else
                gTasks[taskId].data[r3 + 0]--;

            if (gTasks[taskId].data[r3 + 0] == 16
             || gTasks[taskId].data[r3 + 0] == 0)
                gTasks[taskId].data[r3 + 1] ^= 1;

            BlendPalette(
              (sContest.unk19218[i] + 5) * 16 + 6,
              2,
              gTasks[taskId].data[r3 + 0],
              RGB(31, 31, 18));
        }
    }
}

static void sub_80DC7EC(void)
{
    s32 i;

    sContest.unk19212 = CreateTask(sub_80DC8D0, 30);
    for (i = 0; i < 4; i++)
        sub_80DC81C(i);
}

static void sub_80DC81C(u8 a)
{
    gTasks[sContest.unk19212].data[a * 4 + 0] = 0xFF;
    gTasks[sContest.unk19212].data[a * 4 + 1] = 0;
}

static void sub_80DC864(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
        sub_80DC87C(i);
}

static void sub_80DC87C(u8 a)
{
    u32 var;
    u32 r0;

    sub_80DC81C(a);

    r0 = a + 5;
    DmaCopy16Defvars(3,
                     gPlttBufferUnfaded + r0 * 16 + 10,
                     gPlttBufferFaded   + r0 * 16 + 10,
                     2);
    var = (a + 5) * 16 + 12 + a;
    DmaCopy16Defvars(3,
                     gPlttBufferUnfaded + var,
                     gPlttBufferFaded + var,
                     2);
}

static void sub_80DC8D0(u8 taskId)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        u8 r3 = i * 4;

        if (gTasks[taskId].data[r3 + 0] != 0xFF)
        {
            if (++gTasks[taskId].data[r3 + 2] > 2)
            {
                gTasks[taskId].data[r3 + 2] = 0;

                if (gTasks[taskId].data[r3 + 1] == 0)
                    gTasks[taskId].data[r3 + 0]++;
                else
                    gTasks[taskId].data[r3 + 0]--;

                if (gTasks[taskId].data[r3 + 0] == 16
                 || gTasks[taskId].data[r3 + 0] == 0)
                    gTasks[taskId].data[r3 + 1] ^= 1;

                BlendPalette((i + 5) * 16 + 10, 1, gTasks[taskId].data[r3 + 0], RGB(31, 31, 18));
                BlendPalette((i + 5) * 16 + 12 + i, 1, gTasks[taskId].data[r3 + 0], RGB(31, 31, 18));
            }
        }
    }
}

static void sub_80DC9B4(u8 a)
{
    if (sContestantStatus[a].hasJudgesAttention)
        sub_80DC630(a);
    else
        sub_80DC674(a);
}

static u8 sub_80DC9EC(u8 a)
{
    u8 spriteId1, spriteId2;
    u8 x = gUnknown_02039F26[a] * 40 + 32;

    LoadCompressedSpriteSheet(&gUnknown_08589904[a]);
    LoadSpritePalette(&gUnknown_08589924[a]);
    spriteId1 = CreateSprite(&gSpriteTemplate_858998C[a], 184, x, 29);
    spriteId2 = CreateSprite(&gSpriteTemplate_858998C[a], 248, x, 29);
    gSprites[spriteId2].oam.tileNum += 64;

    CopySpriteTiles(0,
                    3,
                    (void *)VRAM,
                    (u16 *)(VRAM + 0xE000 + gUnknown_02039F26[a] * 5 * 64 + 0x26),
                    gContestResources->field_34);

    CopySpriteTiles(0,
                    3, (void *)VRAM,
                    (u16 *)(VRAM + 0xE000 + gUnknown_02039F26[a] * 5 * 64 + 0x36),
                    gContestResources->field_38);

    CpuFill32(0, gContestResources->field_34 + 0x500, 0x300);
    CpuFill32(0, gContestResources->field_38 + 0x500, 0x300);

    RequestDma3Copy(gContestResources->field_34,
                    (u8 *)(VRAM + 0x10000 + gSprites[spriteId1].oam.tileNum * 32),
                    0x800,
                    1);

    RequestDma3Copy(gContestResources->field_38,
                    (u8 *)(VRAM + 0x10000 + gSprites[spriteId2].oam.tileNum * 32),
                    0x800,
                    1);

    gSprites[spriteId1].data[0] = spriteId2;
    gSprites[spriteId2].data[0] = spriteId1;

    gSprites[spriteId1].data[1] = a;
    gSprites[spriteId2].data[1] = a;

    return spriteId1;
}

static void sub_80DCB78(u8 spriteId)
{
    u8 spriteId2 = gSprites[spriteId].data[0];

    FreeSpriteOamMatrix(&gSprites[spriteId2]);
    DestroySprite(&gSprites[spriteId2]);
    DestroySpriteAndFreeResources(&gSprites[spriteId]);
}

static void sub_80DCBB4(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 9));
}

static void sub_80DCBD0(void)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
}

static void sub_80DCBE8(u8 a, bool8 b)
{
    u8 r5;

    sub_80DCBB4();
    gContestResources->field_14[gSprites[a].data[1]].unk2_1 = 1;
    r5 = gSprites[a].data[0];
    StartSpriteAffineAnim(&gSprites[a], 1);
    StartSpriteAffineAnim(&gSprites[r5], 1);
    gSprites[a].callback = sub_80DCC84;
    gSprites[r5].callback = SpriteCallbackDummy;
    if (b == FALSE)
        PlaySE(SE_C_PIKON);
    else
        PlaySE(SE_PC_LOGIN);
}

static void sub_80DCC84(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        u8 r1 = sprite->data[0];

        if (gSprites[r1].affineAnimEnded)
        {
            sprite->invisible = TRUE;
            gSprites[r1].invisible = TRUE;
            sprite->callback = sub_80DCCD8;
        }
    }
}

static void sub_80DCCD8(struct Sprite *sprite)
{
    gContestResources->field_14[sprite->data[1]].unk2_1 = 0;
    sub_80DCB78(sprite->data[0]);
    sub_80DCBD0();
}

static void sub_80DCD08(void)
{
    if(gHeap[0x1A000] == 1)
        gHeap[0x1A000] = 0;
    else
        gHeap[0x1A000] = 1;

    if(gHeap[0x1A000] == 0)
    {
        sub_80DAEA4();
        sub_80DB2BC();
    }
    else
    {
        sub_80DCD48();
    }
}

static void sub_80DCD48(void)
{
    u8 i;
    s16 value;
    u8 *txtPtr;
    u8 text[8];

    if (gUnknown_020322D5 == 0)
        return;

    switch (gHeap[0x1A000])
    {
    case 0:
        break;
    case 2:
    case 3:
        sub_80DF750();
        break;
    default:
        for (i = 0; i < 4; i++)
            FillWindowPixelBuffer(i, 0);
        for (i = 0; i < 4; i++)
        {
            value = sContestantStatus[i].unk4;
            txtPtr = text;
            if (sContestantStatus[i].unk4 < 0)
            {
                value *= -1;
                txtPtr = StringCopy(txtPtr, gText_OneDash);
            }
            ConvertIntToDecimalStringN(txtPtr, value, STR_CONV_MODE_LEFT_ALIGN, 4);
            Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[i], text, 55, 1, 7);
        }
        for (i = 0; i < 4; i++)
        {
            value = sContestantStatus[i].appeal2;
            txtPtr = text;
            if (sContestantStatus[i].appeal2 < 0)
            {
                value *= -1;
                txtPtr = StringCopy(txtPtr, gText_OneDash);
            }
            ConvertIntToDecimalStringN(txtPtr, value, STR_CONV_MODE_LEFT_ALIGN, 4);
            Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[i], text, 5, 1, 7);
        }
        sub_80DB2BC();
        break;
    }
}

void sub_80DCE58(u8 a)
{
    u8 sp0[4];
    u16 sp4[4] = {0};
    s32 i;
    s32 r2;
    s32 r4;

    for (i = 0; i < 4; i++)
    {
        sp4[i] = Random();
        for (r2 = 0; r2 < i; r2++)
        {
            if (sp4[i] == sp4[r2])
            {
                i--;
                break;
            }
        }
    }

    if (a == 0)
    {
        for (i = 0; i < 4; i++)
        {
            gUnknown_02039F26[i] = i;
            for (r4 = 0; r4 < i; r4++)
            {
                if (gContestMonConditions[gUnknown_02039F26[r4]] < gContestMonConditions[i]
                 || (gContestMonConditions[gUnknown_02039F26[r4]] == gContestMonConditions[i] && sp4[gUnknown_02039F26[r4]] < sp4[i]))
                {
                    for (r2 = i; r2 > r4; r2--)
                        gUnknown_02039F26[r2] = gUnknown_02039F26[r2 - 1];
                    gUnknown_02039F26[r4] = i;
                    break;
                }
            }
            if (r4 == i)
                gUnknown_02039F26[i] = i;
        }
        memcpy(sp0, gUnknown_02039F26, sizeof(sp0));
        for (i = 0; i < 4; i++)
            gUnknown_02039F26[sp0[i]] = i;
    }
    else
    {
        memset(sp0, 0xFF, sizeof(sp0));
        for (i = 0; i < 4; i++)
        {
            u8 r2 = sContestantStatus[i].unkB_0;

            while (1)
            {
                u8 *ptr = &sp0[r2];
                if (*ptr == 0xFF)
                {
                    *ptr = i;
                    gUnknown_02039F26[i] = r2;
                    break;
                }
                r2++;
            }
        }
        for (i = 0; i < 3; i++)
        {
            for (r4 = 3; r4 > i; r4--)
            {
                if (sContestantStatus[r4 - 1].unkB_0 == sContestantStatus[r4].unkB_0
                 && gUnknown_02039F26[r4 - 1] < gUnknown_02039F26[r4]
                 && sp4[r4 - 1] < sp4[r4])
                {
                    u8 temp = gUnknown_02039F26[r4];

                    gUnknown_02039F26[r4] = gUnknown_02039F26[r4 - 1];
                    gUnknown_02039F26[r4 - 1] = temp;
                }
            }
        }
    }
}

static void sub_80DD04C(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        LoadPalette(&gHeap[0x1A004] + (i + 5) * 32, (gUnknown_02039F26[i] + 5) * 16, 32);
    }
    sub_80DAEA4();
}

static void sub_80DD080(u8 contestant)
{
    u16 move;
    u8 effect;
    u8 rnd;
    bool8 r8;
    s32 i;

    sContestantStatus[contestant].appeal2 = 0;
    sContestantStatus[contestant].appeal1 = 0;
    r8 = sub_80DBA68(contestant);
    if (!r8)
        return;

    move = sContestantStatus[contestant].currMove;
    effect = gContestMoves[move].effect;

    sContestantStatus[contestant].moveCategory = gContestMoves[sContestantStatus[contestant].currMove].contestCategory;
    if (sContestantStatus[contestant].currMove == sContestantStatus[contestant].prevMove && sContestantStatus[contestant].currMove != MOVE_NONE)
    {
        sContestantStatus[contestant].disappointedRepeat = TRUE;
        sContestantStatus[contestant].moveRepeatCount++;
    }
    else
    {
        sContestantStatus[contestant].moveRepeatCount = 0;
    }
    sContestantStatus[contestant].appeal1 = gContestEffects[effect].appeal;
    sContestantStatus[contestant].appeal2 = sContestantStatus[contestant].appeal1;
    shared192D0.jam = gContestEffects[effect].jam;
    shared192D0.jam2 = shared192D0.jam;

    shared192D0.contestant = contestant;
    for (i = 0; i < 4; i++)
    {
        sContestantStatus[i].jam = 0;
        shared192D0.unnervedPokes[i] = 0;
    }

    if (sContestantStatus[contestant].hasJudgesAttention
        && !AreMovesContestCombo(sContestantStatus[contestant].prevMove, sContestantStatus[contestant].currMove))
        sContestantStatus[contestant].hasJudgesAttention = 0;

    gContestEffectFuncs[effect]();

    if (sContestantStatus[contestant].conditionMod == 1)
        sContestantStatus[contestant].appeal2 += sContestantStatus[contestant].condition - 10;
    else if (sContestantStatus[contestant].appealTripleCondition)
        sContestantStatus[contestant].appeal2 += sContestantStatus[contestant].condition * 3;
    else
        sContestantStatus[contestant].appeal2 += sContestantStatus[contestant].condition;

    sContestantStatus[contestant].unk16 = 0;
    sContestantStatus[contestant].unk15_6 = 0;
    if (sub_80DE1E8(contestant))
    {
        u8 r2 = AreMovesContestCombo(sContestantStatus[contestant].prevMove, sContestantStatus[contestant].currMove);

        if (r2 != 0 && sContestantStatus[contestant].hasJudgesAttention)
        {
            sContestantStatus[contestant].unk16 = r2;
            sContestantStatus[contestant].unk15_6 = 1;
            sContestantStatus[contestant].hasJudgesAttention = 0;
            sContestantStatus[contestant].unk17 = sContestantStatus[contestant].appeal1 * sContestantStatus[contestant].unk16;
            sContestantStatus[contestant].unk15_3 = 1;
        }
        else
        {
            if (gContestMoves[sContestantStatus[contestant].currMove].comboStarterId != 0)
            {
                sContestantStatus[contestant].hasJudgesAttention = 1;
                sContestantStatus[contestant].unk15_6 = 1;
            }
            else
            {
                sContestantStatus[contestant].hasJudgesAttention = 0;
            }
        }
    }
    if (sContestantStatus[contestant].disappointedRepeat)
        sContestantStatus[contestant].unk18 = (sContestantStatus[contestant].moveRepeatCount + 1) * 10;

    if (sContestantStatus[contestant].nervous)
    {
        sContestantStatus[contestant].hasJudgesAttention = 0;
        sContestantStatus[contestant].appeal2 = 0;
        sContestantStatus[contestant].appeal1 = 0;
    }
    shared19328.bits_0 = Contest_GetMoveExcitement(sContestantStatus[contestant].currMove);
    if (sContestantStatus[contestant].overrideCategoryExcitementMod)
        shared19328.bits_0 = 1;

    if (shared19328.bits_0 > 0)
    {
        if (sContest.applauseLevel + shared19328.bits_0 > 4)
            shared19328.unk2 = 60;
        else
            shared19328.unk2 = 10;
    }
    else
    {
        shared19328.unk2 = 0;
    }

    rnd = Random() % 3;
    for (i = 0; i < 4; i++)
    {
        if (i != contestant)
        {
            if (rnd == 0)
                break;
            rnd--;
        }
    }
    sContestantStatus[contestant].unk1B = i;
}

void SetContestantEffectStringID(u8 a, u8 b)
{
    sContestantStatus[a].effectStringId = b;
}

void SetContestantEffectStringID2(u8 a, u8 b)
{
    sContestantStatus[a].effectStringId2 = b;
}

void SetStartledString(u8 contestant, u8 jam)
{
    if      (jam >= 60)
        SetContestantEffectStringID(contestant, CONTEST_STRING_TRIPPED_OVER);
    else if (jam >= 40)
        SetContestantEffectStringID(contestant, CONTEST_STRING_LEAPT_UP);
    else if (jam >= 30)
        SetContestantEffectStringID(contestant, CONTEST_STRING_UTTER_CRY);
    else if (jam >= 20)
        SetContestantEffectStringID(contestant, CONTEST_STRING_TURNED_BACK);
    else if (jam >= 10)
        SetContestantEffectStringID(contestant, CONTEST_STRING_LOOKED_DOWN);
}

static void sub_80DD45C(u8 contestant, u8 stringId)
{
    StringCopy(gStringVar1, gContestMons[contestant].nickname);
    StringCopy(gStringVar2, gMoveNames[sContestantStatus[contestant].currMove]);
    if      (gContestMoves[sContestantStatus[shared192D0.contestant].currMove].contestCategory == CONTEST_CATEGORY_COOL)
        StringCopy(gStringVar3, gText_Contest_Shyness);
    else if (gContestMoves[sContestantStatus[shared192D0.contestant].currMove].contestCategory == CONTEST_CATEGORY_BEAUTY)
        StringCopy(gStringVar3, gText_Contest_Anxiety);
    else if (gContestMoves[sContestantStatus[shared192D0.contestant].currMove].contestCategory == CONTEST_CATEGORY_CUTE)
        StringCopy(gStringVar3, gText_Contest_Laziness);
    else if (gContestMoves[sContestantStatus[shared192D0.contestant].currMove].contestCategory == CONTEST_CATEGORY_SMART)
        StringCopy(gStringVar3, gText_Contest_Hesitancy);
    else
        StringCopy(gStringVar3, gText_Contest_Fear);
    StringExpandPlaceholders(gStringVar4, gUnknown_08587E10[stringId]);
    sub_80DB89C();
    Contest_StartTextPrinter(gStringVar4, 1);
}

void MakeContestantNervous(u8 p)
{
    sContestantStatus[p].nervous = 1;
    sContestantStatus[p].currMove = MOVE_NONE;
}

static void sub_80DD590(void)
{
    u8 r12 = 0;
    s32 i;
    s32 j;
    u8 sp0[4];
    u8 sp4[4];

    for (i = 0; i < 4; i++)
    {
        sp0[i] = gUnknown_02039F26[i];
        sp4[i] = 0;
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (sContestantStatus[j].nextTurnOrder == i)
            {
                sp0[j] = i;
                sp4[j] = 1;
                break;
            }
        }
        if (j == 4)
        {
            for (j = 0; j < 4; j++)
            {
                if (sp4[j] == 0 && sContestantStatus[j].nextTurnOrder == 0xFF)
                {
                    r12 = j;
                    j++;
                    break;
                }
            }
            for (; j < 4; j++)
            {
                if (sp4[j] == 0 && sContestantStatus[j].nextTurnOrder == 0xFF
                 && gUnknown_02039F26[r12] > gUnknown_02039F26[j])
                    r12 = j;
            }
            sp0[r12] = i;
            sp4[r12] = 1;
        }
    }

    for (i = 0; i < 4; i++)
    {
        shared192D0.turnOrder[i] = sp0[i];
        sContestantStatus[i].nextTurnOrder = 0xFF;
        sContestantStatus[i].turnOrderMod = 0;
        gUnknown_02039F26[i] = sp0[i];
    }
}

static void sub_80DD6DC(struct Sprite *sprite)
{
    if (sprite->data[1]++ > 84)
    {
        sprite->data[1] = 0;
        sprite->invisible = TRUE;
        sprite->callback = SpriteCallbackDummy;
        sContest.unk1920A_4 = 0;
    }
}

static void sub_80DD720(u8 a)
{
    u8 spriteId = sContest.unk19216;

    switch (a)
    {
    case 0:
    case 1:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0];
        PlaySE(SE_HAZURE);
        break;
    case 2:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 4;
        PlaySE(SE_SEIKAI);
        break;
    case 3:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 8;
        PlaySE(SE_SEIKAI);
        break;
    case 4:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 12;
        PlaySE(SE_TK_WARPIN);
        break;
    case 5:  // exactly the same as case 4
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 12;
        PlaySE(SE_TK_WARPIN);
        break;
    case 6:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 16;
        PlaySE(SE_TK_WARPIN);
        break;
    case 8:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 24;
        PlaySE(SE_W215);
        break;
    case 7:
    default:
        gSprites[spriteId].oam.tileNum = gSprites[spriteId].data[0] + 20;
        PlaySE(SE_TK_WARPIN);
        break;
    }
    gSprites[spriteId].data[1] = 0;
    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].callback = sub_80DD6DC;
    sContest.unk1920A_4 = 1;
}

static void sub_80DD940(void)
{
    s32 i;

    for (i = 0; i < 5; i++)
    {
        const u8 *src;

        if (i < sContest.applauseLevel)
            src = gContestApplauseMeterGfx + 64;
        else
            src = gContestApplauseMeterGfx;
        CpuCopy32(src, (void *)(VRAM + 0x10000 + (gSprites[sContest.applauseMeterSpriteId].oam.tileNum + 17 + i) * 32), 32);
        CpuCopy32(src + 32, (void *)(VRAM + 0x10000 + (gSprites[sContest.applauseMeterSpriteId].oam.tileNum + 25 + i) * 32), 32);

        if (sContest.applauseLevel > 4)
            sub_80DDA20();
    }
}

s8 Contest_GetMoveExcitement(u16 move)
{
    return gContestExcitementTable[gSpecialVar_ContestCategory][gContestMoves[move].contestCategory];
}

static u8 sub_80DDA20(void)
{
    u8 taskId = CreateTask(c3_08130B10, 10);

    gTasks[taskId].data[1] = 1;
    gTasks[taskId].data[2] = IndexOfSpritePaletteTag(0x0ABE2);
    return taskId;
}

static void c3_08130B10(u8 taskId)
{
    if (++gTasks[taskId].data[0] == 1)
    {
        gTasks[taskId].data[0] = 0;
        if (gTasks[taskId].data[3] == 0)
            gTasks[taskId].data[4]++;
        else
            gTasks[taskId].data[4]--;
        BlendPalette(264 + gTasks[taskId].data[2] * 16, 1, gTasks[taskId].data[4], RGB(31, 31, 31));
        if (gTasks[taskId].data[4] == 0 || gTasks[taskId].data[4] == 16)
        {
            gTasks[taskId].data[3] ^= 1;
            if (sContest.applauseLevel < 5)
            {
                BlendPalette(264 + gTasks[taskId].data[2] * 16, 1, 0, RGB(31, 0, 0));
                DestroyTask(taskId);
            }
        }
    }
}

static void sub_80DDB0C(void)
{
    CreateTask(sub_80DDB6C, 10);
    gSprites[sContest.applauseMeterSpriteId].pos2.x = -70;
    gSprites[sContest.applauseMeterSpriteId].invisible = FALSE;
    sContest.unk1920A_6 = 1;
}

static void sub_80DDB6C(u8 taskId)
{
    struct Sprite *sprite = &gSprites[sContest.applauseMeterSpriteId];

    gTasks[taskId].data[10] += 1664;
    sprite->pos2.x += gTasks[taskId].data[10] >> 8;
    gTasks[taskId].data[10] = gTasks[taskId].data[10] & 0xFF;
    if (sprite->pos2.x > 0)
        sprite->pos2.x = 0;
    if (sprite->pos2.x == 0)
    {
        sContest.unk1920A_6 = 0;
        DestroyTask(taskId);
    }
}

static void sub_80DDBE8(void)
{
    if (gSprites[sContest.applauseMeterSpriteId].invisible == TRUE)
    {
        sContest.unk1920A_6 = 0;
    }
    else
    {
        CreateTask(task08_080CD1CC, 10);
        gSprites[sContest.applauseMeterSpriteId].pos2.x = 0;
        sContest.unk1920A_6 = 1;
    }
}

static void task08_080CD1CC(u8 taskId)
{
    struct Sprite *sprite = &gSprites[sContest.applauseMeterSpriteId];

    gTasks[taskId].data[10] += 1664;
    sprite->pos2.x -= gTasks[taskId].data[10] >> 8;
    gTasks[taskId].data[10] = gTasks[taskId].data[10] & 0xFF;
    if (sprite->pos2.x < -70)
        sprite->pos2.x = -70;
    if (sprite->pos2.x == -70)
    {
        sprite->invisible = TRUE;
        sContest.unk1920A_6 = 0;
        DestroyTask(taskId);
    }
}

static void sub_80DDCDC(s8 a)
{
    u8 taskId = CreateTask(sub_80DDD20, 5);

    gTasks[taskId].data[0] = a;
    sContest.unk1920A_5 = 1;
}

static void sub_80DDD20(u8 taskId)
{
    switch (gTasks[taskId].data[10])
    {
    case 0:
        sub_80DDB0C();
        gTasks[taskId].data[10]++;
        break;
    case 1:
        if (!sContest.unk1920A_6)
        {
            gTasks[taskId].data[10]++;
        }
        break;
    case 2:
        if (gTasks[taskId].data[11]++ > 20)
        {
            gTasks[taskId].data[11] = 0;
            sub_80DD940();
            sContest.unk1920A_5 = 0;
            DestroyTask(taskId);
        }
        break;
    }
}

void unref_sub_80DDDA8(void)
{
    gSprites[sContest.applauseMeterSpriteId].pos2.x = 0;
    gSprites[sContest.applauseMeterSpriteId].invisible = FALSE;
}

void unref_sub_80DDDE4(void)
{
    gSprites[sContest.applauseMeterSpriteId].invisible = TRUE;
}

static void sub_80DDE0C(void)
{
    CreateTask(sub_80DDE30, 15);
    sContest.unk1920A_7 = 1;
}

static void sub_80DDE30(u8 taskId)
{
    if (gTasks[taskId].data[10]++ > 6)
    {
        gTasks[taskId].data[10] = 0;
        if (gTasks[taskId].data[11] == 0)
        {
            RequestDma3Copy(shared16800, (void *)(VRAM + 0x2000), 0x1000, 1);
        }
        else
        {
            RequestDma3Copy(shared15800, (void *)(VRAM + 0x2000), 0x1000, 1);
            gTasks[taskId].data[12]++;
        }

        gTasks[taskId].data[11] ^= 1;

        if (gTasks[taskId].data[12] == 9)
        {
            sContest.unk1920A_7 = 0;
            DestroyTask(taskId);
        }
    }
}

#define tBlendColor data[0]
#define tBlendCoeff data[1]

static void sub_80DDED0(s8 a, s8 b)
{
    u8 taskId = CreateTask(sub_80DDF80, 10);
    u16 blendColor;
    u8 blendCoeff;
    u8 r3;

    if (a > 0)
    {
        blendColor = RGB(30, 27, 8);
        if (b > 0)
        {
            blendCoeff = 0;
            r3 = sContest.applauseLevel * 3;
        }
        else
        {
            blendCoeff = sContest.applauseLevel * 3;
            r3 = 0;
        }
    }
    else
    {
        blendColor = 0;
        if (b > 0)
        {
            blendCoeff = 0;
            r3 = 12;
        }
        else
        {
            blendCoeff = 12;
            r3 = 0;
        }
    }
    gTasks[taskId].tBlendColor = blendColor;
    gTasks[taskId].tBlendCoeff = blendCoeff;
    gTasks[taskId].data[2] = b;
    gTasks[taskId].data[3] = r3;
    sContest.unk1920B_0 = 0;
}

static void sub_80DDF80(u8 taskId)
{
    if (gTasks[taskId].data[10]++ >= 0)
    {
        gTasks[taskId].data[10] = 0;
        if (gTasks[taskId].data[2] > 0)
            gTasks[taskId].tBlendCoeff++;
        else
            gTasks[taskId].tBlendCoeff--;
        BlendPalette(17, 1, gTasks[taskId].tBlendCoeff, gTasks[taskId].tBlendColor);
        BlendPalette(26, 1, gTasks[taskId].tBlendCoeff, gTasks[taskId].tBlendColor);
        if (gTasks[taskId].tBlendCoeff == gTasks[taskId].data[3])
        {
            DestroyTask(taskId);
            sContest.unk1920B_0 = 0;
        }
    }
}

#undef tBlendColor
#undef tBlendCoeff

static void sub_80DE008(bool8 a)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (sContestantStatus[i].turnOrderMod != 0 && a)
        {
            CpuCopy32(GetTurnOrderNumberGfx(i), (void *)(VRAM + 0x10000 + (gSprites[gContestResources->field_14[i].unk1].oam.tileNum + 6) * 32), 32);
            gSprites[gContestResources->field_14[i].unk1].pos1.y = gUnknown_08587A70[gUnknown_02039F26[i]];
            gSprites[gContestResources->field_14[i].unk1].invisible = FALSE;
        }
        else
        {
            gSprites[gContestResources->field_14[i].unk1].invisible = TRUE;
        }
    }
}

static const u8 *GetTurnOrderNumberGfx(u8 contestant)
{
    if (sContestantStatus[contestant].turnOrderMod != 1)
        return gContestNextTurnRandomGfx;
    else
        return gContestNextTurnNumbersGfx + sContestantStatus[contestant].nextTurnOrder * 32;
}

static void sub_80DE12C(void)
{
    s32 r7 = 0;
    u8 r10 = 2;
    u8 r8 = 1;
    u8 r9 = 0x11;

    for (r7 = 0; r7 < 4; r7++)
    {
        if (shared192D0.unnervedPokes[r7] != 0 && !Contest_IsMonsTurnDisabled(r7))
        {
            u32 r6 = gUnknown_02039F26[r7] * 5 + 2;
            u16 var = sub_80DB748(3);

            ContestBG_FillBoxWithIncrementingTile(0, var, 0x14, r6, r10, r8, r9, r8);
            var += 16;
            ContestBG_FillBoxWithIncrementingTile(0, var, 0x14, r6 + 1, r10, r8, r9, r8);
            PlaySE(SE_C_PASI);
        }
    }
}

bool8 sub_80DE1E8(u8 a)
{
    if (sContestantStatus[a].disappointedRepeat || sContestantStatus[a].nervous)
        return FALSE;
    else
        return TRUE;
}

static void sub_80DE224(void)
{
    s32 i;
    u16 bg0Cnt, bg1Cnt, bg2Cnt;

    bg1Cnt = GetGpuReg(REG_OFFSET_BG1CNT);
    ((vBgCnt *)&bg1Cnt)->priority = 0;
    ((vBgCnt *)&bg1Cnt)->screenSize = 2;
    ((vBgCnt *)&bg1Cnt)->areaOverflowMode = 0;
    ((vBgCnt *)&bg1Cnt)->charBaseBlock = 0;

    SetGpuReg(REG_OFFSET_BG1CNT, bg1Cnt);

    bg0Cnt = GetGpuReg(REG_OFFSET_BG0CNT);
    bg2Cnt = GetGpuReg(REG_OFFSET_BG2CNT);
    ((vBgCnt *)&bg0Cnt)->priority = 1;
    ((vBgCnt *)&bg2Cnt)->priority = 1;

    SetGpuReg(REG_OFFSET_BG0CNT, bg0Cnt);
    SetGpuReg(REG_OFFSET_BG2CNT, bg2Cnt);

    gBattle_BG1_X = DISPLAY_WIDTH;
    gBattle_BG1_Y = DISPLAY_HEIGHT;
    SetGpuReg(REG_OFFSET_BG1HOFS, gBattle_BG1_X);
    SetGpuReg(REG_OFFSET_BG1VOFS, gBattle_BG1_Y);

    CpuFill32(0, gContestResources->field_24[1], 0x1000);

    CopyToBgTilemapBuffer(1, gUnknown_08C17980, 0, 0);
    Contest_SetBgCopyFlags(1);

    for (i = 0; i < 4; i++)
    {
        gSprites[gContestResources->field_14[i].unk0].oam.priority = 1;
        gSprites[gContestResources->field_14[i].unk1].oam.priority = 1;
    }
}

static void sub_80DE350(void)
{
    s32 i;
    u16 bg1Cnt;

    RequestDma3Fill(0,(void *)(VRAM + 0x8000), 0x2000, 0x1);
    CpuFill32(0, gContestResources->field_24[1], 0x1000);
    Contest_SetBgCopyFlags(1);
    bg1Cnt = GetGpuReg(REG_OFFSET_BG1CNT);
    ((vBgCnt *) &bg1Cnt)->priority = 1;
    ((vBgCnt *) &bg1Cnt)->screenSize = 0;
    ((vBgCnt *) &bg1Cnt)->areaOverflowMode = 0;
    ((vBgCnt *) &bg1Cnt)->charBaseBlock = 2;

    SetGpuReg(REG_OFFSET_BG1CNT, bg1Cnt);

    gBattle_BG1_X = 0;
    gBattle_BG1_Y = 0;

    for (i = 0; i < 4; i++)
    {
        gSprites[gContestResources->field_14[i].unk0].oam.priority = 0;
        gSprites[gContestResources->field_14[i].unk1].oam.priority = 0;
    }
}

static void sub_80DE424(u8 taskId)
{
    gBattle_BG1_X = 0;
    gBattle_BG1_Y = DISPLAY_HEIGHT;
    PlaySE12WithPanning(SE_C_MAKU_D, 0);
    gTasks[taskId].func = sub_80DE464;
}

static void sub_80DE464(u8 taskId)
{
    if ((s16)(gBattle_BG1_Y -= 7) < 0)
        gBattle_BG1_Y = 0;
    if (gBattle_BG1_Y == 0)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = sub_80DE4A8;
    }
}

static void sub_80DE4A8(u8 taskId)
{
    s32 i;

    switch (gTasks[taskId].data[0])
    {
    case 0:
        for (i = 0; i < 4; i++)
            sContest.unk19218[i] = gUnknown_02039F26[i];
        sub_80DBF90();
        sub_80DC864();
        sub_80DB69C();
        sub_80DD04C();
        sub_80DE008(TRUE);
        sub_80DC44C();
        gTasks[taskId].data[0] = 1;
        break;
    case 1:
        if (gIsLinkContest & 1)
        {
            u8 taskId2;

            sContest.unk1920B_2 = 1;
            if (sub_80DA8A4())
                sub_80DBAA0();
            taskId2 = CreateTask(sub_80FCC88, 0);
            SetTaskFuncWithFollowupFunc(taskId2, sub_80FCC88, sub_80DA110);
            sub_80DBF68();
            gTasks[taskId].data[0] = 2;
        }
        else
        {
            sub_80DBAA0();
            gTasks[taskId].data[0] = 3;
        }
        break;
    case 2:
        if (!sContest.unk1920B_2)
            gTasks[taskId].data[0] = 3;
        break;
    case 3:
        sub_80DB884();
        sub_80DB2BC();
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = sub_80DE5F4;
        break;
    }
}

static void sub_80DE5C0(u8 taskId)
{
    if ((s16)(gBattle_BG1_Y += 7) > DISPLAY_HEIGHT)
        gTasks[taskId].func = sub_80DA4F4;
}

static void sub_80DE5F4(u8 taskId)
{
    if (gTasks[taskId].data[2] < 10)
    {
        gTasks[taskId].data[2]++;
    }
    else
    {
        if (gTasks[taskId].data[1] == 0)
        {
            if (gTasks[taskId].data[0] == 16)
                gTasks[taskId].data[1]++;
            else
                gTasks[taskId].data[0]++;
        }
        else
        {
            if (gTasks[taskId].data[0] == 0)
            {
                gTasks[taskId].data[1] = 0;
                gTasks[taskId].data[2] = 0;
                gTasks[taskId].func = sub_80DE65C;
            }
            else
            {
                gTasks[taskId].data[0]--;
            }
        }
    }
}

static void sub_80DE65C(u8 taskId)
{
    if (gTasks[taskId].data[2] < 10)
    {
        gTasks[taskId].data[2]++;
    }
    else
    {
        gTasks[taskId].data[2] = 0;
        PlaySE12WithPanning(SE_C_MAKU_U, 0);
        gTasks[taskId].func = sub_80DE5C0;
    }
}

static void sub_80DE69C(u8 a)
{
    s32 i;
    u8 taskId;

    for (i = 0; i < 4; i++)
    {
        gSprites[gContestResources->field_14[i].unk0].oam.matrixNum = AllocOamMatrix();
        gSprites[gContestResources->field_14[i].unk0].oam.affineMode = 1;
        StartSpriteAffineAnim(&gSprites[gContestResources->field_14[i].unk0], a);
        if (a == 2)
        {
            AnimateSprite(&gSprites[gContestResources->field_14[i].unk0]);
            gSprites[gContestResources->field_14[i].unk0].invisible = FALSE;
        }
    }
    taskId = CreateTask(sub_80DE794, 5);
    gTasks[taskId].data[0] = a;
    sContest.unk1920B_1 = 1;
}

static void sub_80DE794(u8 taskId)
{
    s32 i;

    if (gSprites[gContestResources->field_14[0].unk0].affineAnimEnded)
    {
        if ((u8)gTasks[taskId].data[0] == 1)
        {
            for (i = 0; i < 4; i++)
                gSprites[gContestResources->field_14[i].unk0].invisible = TRUE;
        }
        for (i = 0; i < 4; i++)
            FreeSpriteOamMatrix(&gSprites[gContestResources->field_14[i].unk0]);
        sContest.unk1920B_1 = 0;
        DestroyTask(taskId);
    }
}

static u16 SanitizeMove(u16 move)
{
    if (move >= MOVES_COUNT)
        move = MOVE_POUND;
    return move;
}

static u16 SanitizeSpecies(u16 species)
{
    if (species >= NUM_SPECIES)
        species = SPECIES_NONE;
    return species;
}

static void sub_80DE864(u8 a)
{
    s32 i;
    u16 move = SanitizeMove(sContestantStatus[a].currMove);
    u16 species = SanitizeSpecies(gContestMons[a].species);
    u8 r5_2;

    memset(&gContestResources->field_18->species, 0, 0x14);
    ClearBattleAnimationVars();
    for (i = 0; i < 4; i++)
        gBattleMonForms[i] = 0;
    switch (move)
    {
    case MOVE_CURSE:
        if (gBaseStats[species].type1 == TYPE_GHOST || gBaseStats[species].type2 == TYPE_GHOST)
            gAnimMoveTurn = 0;
        else
            gAnimMoveTurn = 1;
        break;
    case MOVE_TRANSFORM:
    case MOVE_ROLE_PLAY:
        r5_2 = sContestantStatus[a].unk1B;
        gContestResources->field_18->unk2 = SanitizeSpecies(gContestMons[r5_2].species);
        gContestResources->field_18->unk10 = gContestMons[r5_2].personality;
        gContestResources->field_18->unk4_0 = 1;
        break;
    case MOVE_RETURN:
        gAnimFriendship = 0xFF;
        break;
    case MOVE_FRUSTRATION:
        gAnimFriendship = 0;
        break;
    case MOVE_SOLAR_BEAM:
    case MOVE_RAZOR_WIND:
    case MOVE_SKULL_BASH:
    case MOVE_SKY_ATTACK:
        if (sContest.unk1925E == 0)
        {
            sContest.unk1925E = 2;
            gAnimMoveTurn = 0;
        }
        else
        {
            gAnimMoveTurn = 1;
        }
        break;
    }
    sub_80DEA5C();
}

static void sub_80DE9B0(u8 unused)
{
    memset(&gContestResources->field_18->species, 0, 0x14);
    if (sContest.unk1925E != 0)
        sContest.unk1925E--;
}

static void sub_80DE9DC(u8 a)
{
    gContestResources->field_18->unk5 = a;
    gContestResources->field_18->species = SanitizeSpecies(gContestMons[a].species);
    gContestResources->field_18->unk8 = gContestMons[a].personality;
    gContestResources->field_18->unkC = gContestMons[a].otId;
}

static void sub_80DEA20(void)
{
    gBattlerSpriteIds[3] = CreateInvisibleSpriteWithCallback(SpriteCallbackDummy);
    InitSpriteAffineAnim(&gSprites[gBattlerSpriteIds[gBattlerTarget]]);
    sub_80DEA5C();
}

static void sub_80DEA5C(void)
{
    struct Sprite *sprite = &gSprites[gBattlerSpriteIds[3]];

    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    sprite->pos1.x = GetBattlerSpriteCoord(3, 0);
    sprite->pos1.y = GetBattlerSpriteCoord(3, 1);
    sprite->invisible = TRUE;
}

static void SelectContestMoveBankTarget(u16 move)
{
    switch (gBattleMoves[move].target)
    {
    case MOVE_TARGET_USER_OR_SELECTED:
    case MOVE_TARGET_USER:
        gBattlerTarget = 2;
        break;
    case MOVE_TARGET_SELECTED:
    case MOVE_TARGET_RANDOM:
    case MOVE_TARGET_BOTH:
    case MOVE_TARGET_FOES_AND_ALLY:
    default:
        gBattlerTarget = 3;
        break;
    }
}

static void Contest_PrintTextToBg0WindowStd(u32 a, const u8 *b)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = b;
    printerTemplate.windowId = a;
    printerTemplate.fontId = 1;
    printerTemplate.x = 0;
    printerTemplate.y = 1;
    printerTemplate.currentX = 0;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 15;
    printerTemplate.bgColor = 0;
    printerTemplate.shadowColor = 8;

    AddTextPrinter(&printerTemplate, 0, 0);
    PutWindowTilemap(a);
    Contest_SetBgCopyFlags(0);
}

void Contest_PrintTextToBg0WindowAt(u32 windowId, u8 *currChar, s32 x, s32 y, s32 fontId)
{
    struct TextPrinterTemplate printerTemplate;

    printerTemplate.currentChar = currChar;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = fontId;
    printerTemplate.x = x;
    printerTemplate.y = y;
    printerTemplate.currentX = x;
    printerTemplate.currentY = y;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 15;
    printerTemplate.bgColor = 0;
    printerTemplate.shadowColor = 8;

    AddTextPrinter(&printerTemplate, 0, 0);
    PutWindowTilemap(windowId);
    Contest_SetBgCopyFlags(0);
}

static void Contest_StartTextPrinter(const u8 *currChar, bool32 b)
{
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    printerTemplate.currentChar = currChar;
    printerTemplate.windowId = 4;
    printerTemplate.fontId = 1;
    printerTemplate.x = 0;
    printerTemplate.y = 1;
    printerTemplate.currentX = 0;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = 1;
    printerTemplate.bgColor = 0;
    printerTemplate.shadowColor = 8;

    if (!b)
    {
        AddTextPrinter(&printerTemplate, 0, 0);
    }
    else
    {
        if (gIsLinkContest & 1)
            speed = 4;
        else
            speed = GetPlayerTextSpeedDelay();
        AddTextPrinter(&printerTemplate, speed, 0);
    }

    PutWindowTilemap(4);
    Contest_SetBgCopyFlags(0);
}

static void ContestBG_FillBoxWithIncrementingTile(u8 a, u16 b, u8 c, u8 d, u8 e, u8 f, u8 g, s16 h)
{
    WriteSequenceToBgTilemapBuffer(a, b, c, d, e, f, g, h);
    Contest_SetBgCopyFlags(a);
}

static void ContestBG_FillBoxWithTile(u8 a, u16 b, u8 c, u8 d, u8 e, u8 f, u8 g)
{
    ContestBG_FillBoxWithIncrementingTile(a, b, c, d, e, f, g, 0);
}

static bool32 Contest_RunTextPrinters(void)
{
    RunTextPrinters();
    return IsTextPrinterActive(4);
}

static void Contest_SetBgCopyFlags(u32 var)
{
    sContestBgCopyFlags |= 1 << var;
}

void ResetContestLinkResults(void)
{
    s32 i;
    s32 j;

    for(i = 0; i < 5; i++)
        for(j = 0; j < 4; j++)
            gSaveBlock2Ptr->contestLinkResults[i][j] = 0;
}

bool8 sub_80DEDA8(u8 a)
{
    s32 i;
    u8 r7 = Random() % 3;

    for (i = 0; i < 3; i++)
    {
        if (gContestFinalStandings[i] == 0)
            break;
    }
    if (a == 0xFF && i != gContestPlayerMonIndex)
        return FALSE;
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        r7 += 0;
        break;
    case CONTEST_CATEGORY_BEAUTY:
        r7 += 3;
        break;
    case CONTEST_CATEGORY_CUTE:
        r7 += 6;
        break;
    case CONTEST_CATEGORY_SMART:
        r7 += 9;
        break;
    case CONTEST_CATEGORY_TOUGH:
        r7 += 12;
        break;
    }
    if (a != 0xFE)
    {
        u8 r4 = sub_80DEFA8(a, 1);

        gSaveBlock1Ptr->contestWinners[r4].personality = gContestMons[i].personality;
        gSaveBlock1Ptr->contestWinners[r4].species = gContestMons[i].species;
        gSaveBlock1Ptr->contestWinners[r4].trainerId = gContestMons[i].otId;
        StringCopy(gSaveBlock1Ptr->contestWinners[r4].monName, gContestMons[i].nickname);
        StringCopy(gSaveBlock1Ptr->contestWinners[r4].trainerName, gContestMons[i].trainerName);
        if(gIsLinkContest & 1)
            gSaveBlock1Ptr->contestWinners[r4].contestRank = 4;
        else
            gSaveBlock1Ptr->contestWinners[r4].contestRank = gSpecialVar_ContestRank;

        if (a != 0xFF)
            gSaveBlock1Ptr->contestWinners[r4].contestCategory = gSpecialVar_ContestCategory;
        else
            gSaveBlock1Ptr->contestWinners[r4].contestCategory = r7;
    }
    else
    {
        gUnknown_02039F3C.personality = gContestMons[i].personality;
        gUnknown_02039F3C.trainerId = gContestMons[i].otId;
        gUnknown_02039F3C.species = gContestMons[i].species;
        StringCopy(gUnknown_02039F3C.monName, gContestMons[i].nickname);
        StringCopy(gUnknown_02039F3C.trainerName, gContestMons[i].trainerName);
        gUnknown_02039F3C.contestCategory = r7;
    }
    return TRUE;
}

u8 sub_80DEFA8(u8 a, u8 b)
{
    s32 i;

    switch (a)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        if (b != 0)
        {
            for (i = 5; i >= 1; i--)
                memcpy(&gSaveBlock1Ptr->contestWinners[i], &gSaveBlock1Ptr->contestWinners[i - 1], sizeof(struct ContestWinner));
        }
        return 0;
    default:
        switch (gSpecialVar_ContestCategory)
        {
        case CONTEST_CATEGORY_COOL:
            return 8;
        case CONTEST_CATEGORY_BEAUTY:
            return 9;
        case CONTEST_CATEGORY_CUTE:
            return 10;
        case CONTEST_CATEGORY_SMART:
            return 11;
        case CONTEST_CATEGORY_TOUGH:
        default:
            return 12;
        }
    }
}

void ClearContestWinnerPicsInContestHall(void)
{
    s32 i;

    for (i = 0; i < 8; i++)
        gSaveBlock1Ptr->contestWinners[i] = gUnknown_08587FA4[i];
}

// The functions below are probably related to Contests in TV.
static void sub_80DF080(u8 contestant)
{
    s32 i;

    if (!gContestResources->field_10->excitementFrozen
        && gContestResources->field_10->bits_0 > 0
        && !gContestResources->field_4[contestant].disappointedRepeat)
    {
        gContestResources->field_1c[contestant].unkC |= 1;
        gContestResources->field_1c[contestant].unkE_2 = 1;
    }

    if (gContestResources->field_4[contestant].nervous)
        gContestResources->field_1c[contestant].unkC |= 2;

    if (!gContestResources->field_10->excitementFrozen
        && gContestResources->field_10->bits_0 != 0
        && gContestResources->field_10->unk2 == 60)
    {
        gContestResources->field_1c[contestant].unkC |= 4;
    }

    if (gContestResources->field_4[contestant].unk15_6
        && gContestResources->field_4[contestant].unk16 != 0)
    {
        gContestResources->field_1c[contestant].unkC |= 8;
    }

    for (i = 0; i < 4; i++)
    {
        if (i != contestant && gContestResources->field_4[i].jam != 0)
        {
            gContestResources->field_1c[contestant].unkC |= 0x10;
            gContestResources->field_1c[i].unkC |= 0x40;
        }
    }

    if (gContestResources->field_4[contestant].numTurnsSkipped != 0
        || gContestResources->field_4[contestant].noMoreTurns)
    {
        gContestResources->field_1c[contestant].unkC |= 0x20;
    }
    else if (!gContestResources->field_4[contestant].nervous)
    {
        gContestResources->field_1c[contestant].unkC |= 0x80;
        gContestResources->field_1c[contestant].unkE_1 = 1;
        gContestResources->field_1c[contestant].unk0[gContestResources->field_0->turnNumber] = gContestResources->field_4[contestant].currMove;
    }

    if (gContestResources->field_4[contestant].disappointedRepeat)
        gContestResources->field_1c[contestant].unkD |= 2;

    if (gContestResources->field_0->applauseLevel == 4
        && !gContestResources->field_10->excitementFrozen
        && gContestResources->field_10->bits_0 < 0)
    {
        gContestResources->field_1c[contestant].unkD |= 0x20;
    }
}

static void sub_80DF250(void)
{
    u8 r1;
    s32 i, j;
    bool32 r12, r8;
    u16 sp0[6];
    u8 spC[6];
    u16 sp14[5];
    u8 var_38;
    u8 r3;
    u8 count;

    r1 = 0;
    var_38 = 0;

    for (i = 0; i < 4; i++)
    {
        if (gContestFinalStandings[i] == 0)
            var_38 = i;
        else if (gContestFinalStandings[i] == 3)
            r1 = i;
    }

    gContestResources->field_1c[r1].unkD |= 1;
    for (i = 0; i < 4; i++)
    {
        if (i != var_38 && gUnknown_02039F08[var_38] - gUnknown_02039F08[i] <= 50)
            gContestResources->field_1c[i].unkD |= 4;

        if (!gContestResources->field_1c[i].unkE_2)
            gContestResources->field_1c[i].unkD |= 8;

        for (j = 0; j < 4; j++)
        {
            if (gContestMonConditions[i] < gContestMonConditions[j])
                break;
        }
        if (j == 4 && gContestFinalStandings[i] != 0)
            gContestResources->field_1c[i].unkD |= 0x10;

        r12 = FALSE;
        r8 = FALSE;
        for (j = 0; j < 4; j++)
        {
            if (gContestMonConditions[i] > gContestMonConditions[j])
                r12 = TRUE;
            if (gUnknown_02039F18[i] > gUnknown_02039F18[j])
                r8 = TRUE;
        }
        if (!r12 && !r8)
            gContestResources->field_1c[i].unkD |= 0x40;

        if (!gContestResources->field_1c[i].unkE_1)
            gContestResources->field_1c[i].unkD |= 0x80;
    }

    for (i = 0; i < 5; i++)
    {
        sp0[i] = 0;
        spC[i] = 0;
    }
    sp0[5] = 0xFFFF;
    spC[5] = 0;

    for (i = 0; i < 5; i++)
    {
        if (gContestResources->field_1c[var_38].unk0[i] != 0)
        {
            for (j = 0; j < 5; j++)
            {
                if (gContestResources->field_1c[var_38].unk0[i] != sp0[j])
                {
                    if (sp0[j] == 0)
                    {
                        sp0[j] = gContestResources->field_1c[var_38].unk0[i];
                        spC[j]++;
                    }
                }
                else
                {
                    spC[j]++;
                }
            }
        }
    }

    sp14[0] = sp0[0];
    r3 = spC[0];
    count = 0;
    for (i = 1; sp0[i] != 0xFFFF; i++)
    {
        if (r3 < spC[i])
        {
            sp14[0] = sp0[i];
            r3 = spC[i];
            count = 1;
        }
        else if (r3 == spC[i])
        {
            sp14[count] = sp0[i];
            count++;
        }
    }

    gContestResources->field_1c[var_38].unkA = sp14[Random() % count];
}

static void sub_80DF4F8(void)
{
    s32 i;
    u32 bits;
    u8 r7;
    u8 r9, r10;
    u8 count;
    u8 r5;
    u8 r2;
    u16 var;
    u8 r4;
    u8 r6;
    u8 sp0[4];

    if (gContestFinalStandings[gContestPlayerMonIndex] != 0)
        return;

    r7 = 0;
    for (i = 0; i < 4; i++)
    {
        if (gContestFinalStandings[i] == 0)
            r7 = i;
    }

    r9 = 0;
    r10 = 0;
    for (i = 0; i < 4; i++)
    {
        if (gContestMonConditions[r7] < gContestMonConditions[i])
            r9++;
        if (gUnknown_02039F18[r7] < gUnknown_02039F18[i])
            r10++;
    }

    bits = gContestResources->field_1c[r7].unkC;
    count = 0;
    for (i = 0; i < 8; bits >>= 1, i++)
    {
        if (bits & 1)
            count++;
    }

    r5 = Random() % count;
    bits = gContestResources->field_1c[r7].unkC;
    count = 0;
    r2 = 0;
    for (i = 0; i < 8; bits >>= 1, r2++, i++)
    {
        if (!(bits & 1))
            continue;
        if (r5 == count)
            break;
        count++;
    }

    var = 1 << r2;
    if (r7 == 0)
    {
        sp0[0] = 1;
        r4 = gContestResources->field_1c[1].unkD;
        i = 2;
    }
    else
    {
        sp0[0] = 0;
        r4 = gContestResources->field_1c[0].unkD;
        i = 1;
    }

    r5 = 1;
    for (; i < 4; i++)
    {
        if (i != r7)
        {
            if (r4 < gContestResources->field_1c[i].unkD)
            {
                sp0[0] = i;
                r4 = gContestResources->field_1c[i].unkD;
                r5 = 1;
            }
            else if (r4 == gContestResources->field_1c[i].unkD)
            {
                sp0[r5] = i;
                r5++;
            }
        }
    }

    r6 = sp0[Random() % r5];
    r2 = 0x80;
    for (i = 0; i < 8; r2 >>= 1, i++)
    {
        r4 = gContestResources->field_1c[r6].unkD & r2;
        if (r4)
            break;
    }

    ContestLiveUpdates_BeforeInterview_1(r9);
    ContestLiveUpdates_BeforeInterview_2(r10);
    ContestLiveUpdates_BeforeInterview_3(var);
    ContestLiveUpdates_BeforeInterview_4(gContestResources->field_1c[r7].unkA);
    ContestLiveUpdates_BeforeInterview_5(r4, r6);
}

// Unused
void sub_80DF704(u8 arg0)
{
    if (gHeap[0x1A000] == 0)
    {
        if (arg0 == 0)
            gHeap[0x1A000] = 2;
        else
            gHeap[0x1A000] = 3;
    }
    else
    {
        gHeap[0x1A000] = 0;
    }

    if (gHeap[0x1A000] == 0)
    {
        sub_80DAEA4();
        sub_80DB2BC();
    }
    else
    {
        sub_80DF750();
    }
}

static void sub_80DF750(void)
{
    u8 i;
    s8 j;
    u8 text1[20];
    u8 text2[20];
    u8 *txtPtr;
    u32 bits;

    if (gUnknown_020322D5 == 0)
        return;
    if (gHeap[0x1A000] != 2 && gHeap[0x1A000] != 3)
        return;

    for (i = 0; i < 4; i++)
        FillWindowPixelBuffer(i, 0);

    if (gHeap[0x1A000] == 2)
    {
        for (i = 0; i < 4; i++)
        {
            txtPtr = StringCopy(text1, gText_CDot);
            Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[i], text1, 5, 1, 7);
            bits = gContestResources->field_1c[i].unkC;
            for (j = 7; j > -1; j--) // Weird loop.
            {
                txtPtr = ConvertIntToDecimalStringN(txtPtr, bits & 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                bits >>= 1;
            }

            for (j = 0; j < 5; j++)
                text2[j] = text1[j];

            text2[j] = EOS;
            Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[i], text2, 5, 1, 7);
            Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[i], text1 + j, 55, 1, 7);
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            StringCopy(text1, gText_BDot);
            bits = gContestResources->field_1c[i].unkD;
            txtPtr = &text1[2];
            for (j = 7; j > -1; j--) // Weird loop.
            {
                txtPtr = ConvertIntToDecimalStringN(txtPtr, bits & 1, STR_CONV_MODE_LEFT_ALIGN, 1);
                bits >>= 1;
            }

            for (j = 0; j < 5; j++)
                text2[j] = text1[j];

            text2[j] = EOS;
            Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[i], text2, 5, 1, 7);
            Contest_PrintTextToBg0WindowAt(gUnknown_02039F26[i], text1 + j, 55, 1, 7);
        }
    }
    sub_80DB2BC();
}

static u8 sub_80DF940(u8 *nickname)
{
    u8 ret = GAME_LANGUAGE;

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
        return LANGUAGE_ENGLISH;

    if (StringLength(nickname) < 6)
    {
        while (*nickname != EOS)
        {
            if ((*nickname >= CHAR_A && *nickname <= CHAR_z)
                || (*nickname >= CHAR_0 && *nickname <= CHAR_9)
                || *nickname == CHAR_SPACE
                || *nickname == CHAR_PERIOD
                || *nickname == CHAR_COMMA
                || *nickname == CHAR_EXCL_MARK
                || *nickname == CHAR_QUESTION_MARK
                || *nickname == CHAR_MALE
                || *nickname == CHAR_FEMALE
                || *nickname == CHAR_SLASH
                || *nickname == CHAR_HYPHEN
                || *nickname == CHAR_ELLIPSIS
                || *nickname == CHAR_DBL_QUOT_LEFT
                || *nickname == CHAR_DBL_QUOT_RIGHT
                || *nickname == CHAR_SGL_QUOT_LEFT
                || *nickname == CHAR_DBL_QUOT_LEFT) // Most likely a typo, CHAR_SGL_QUOT_RIGHT should be here instead.
            {
                nickname++;
            }
            else
            {
                ret = LANGUAGE_JAPANESE;
                break;
            }
        }
    }

    return ret;
}

static void sub_80DF9D4(u8 *playerName)
{
    u8 chr = playerName[5];

    playerName[5] = EOS;
    playerName[PLAYER_NAME_LENGTH] = chr;
}

static void sub_80DF9E0(u8 *monName, s32 language)
{
    u8 chr;

    StripExtCtrlCodes(monName);
    if (language == LANGUAGE_JAPANESE)
    {
        monName[5] = EOS;
        monName[POKEMON_NAME_LENGTH] = EXT_CTRL_CODE_BEGIN;
    }
    else
    {
        chr = monName[5];
        monName[5] = EOS;
        monName[POKEMON_NAME_LENGTH] = chr;
    }
}

void sub_80DFA08(struct ContestPokemon *mon, s32 language)
{
    u8 *name = mon->nickname;

    if (language == LANGUAGE_JAPANESE)
    {
        ConvertInternationalString(name, sub_80DF940(name));
    }
    else if (name[POKEMON_NAME_LENGTH] == EXT_CTRL_CODE_BEGIN)
    {
        ConvertInternationalString(name, LANGUAGE_JAPANESE);
    }
    else
    {
        name[5] = name[POKEMON_NAME_LENGTH];
        name[POKEMON_NAME_LENGTH] = EOS;
    }

    name = mon->trainerName;
    if (language == LANGUAGE_JAPANESE)
    {
        name[PLAYER_NAME_LENGTH] = EOS;
        name[6] = name[4];
        name[5] = name[3];
        name[4] = name[2];
        name[3] = name[1];
        name[2] = mon->trainerName[0];
        name[1] = EXT_CTRL_CODE_JPN;
        name[0] = EXT_CTRL_CODE_BEGIN;
    }
    else
    {
        name[5] = name[PLAYER_NAME_LENGTH];
        name[PLAYER_NAME_LENGTH] = EOS;
    }
}
