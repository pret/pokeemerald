#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "bg.h"
#include "contest.h"
#include "contest_util.h"
#include "contest_link.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "event_data.h"
#include "field_specials.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "random.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "tv.h"
#include "util.h"
#include "window.h"
#include "constants/field_specials.h"
#include "constants/game_stat.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/tv.h"
#include "constants/vars.h"
#include "contest.h"

enum {
    SLIDING_TEXT_OFFSCREEN,
    SLIDING_TEXT_ENTERING,
    SLIDING_TEXT_ARRIVED,
    SLIDING_TEXT_EXITING,
};

enum {
    SLIDING_MON_ENTERED = 1,
    SLIDING_MON_EXITED,
};

#define GET_CONTEST_WINNER_ID(i) { for ((i) = 0; (i) < CONTESTANT_COUNT && gContestFinalStandings[(i)] != 0; (i)++); }

#define TAG_CONFETTI 3017

#define MAX_BAR_LENGTH 87

struct ContestResultsInternal
{
    u8 slidingTextBoxSpriteId;
    u8 linkTextBoxSpriteId;
    u8 showResultsTaskId;
    u8 highlightWinnerTaskId;
    u8 slidingTextBoxState;
    u8 numStandingsPrinted;
    u8 winnerMonSlidingState;
    u8 confettiCount;
    u8 winnerMonSpriteId;
    bool8 destroyConfetti;
    bool8 pointsFlashing;
    s16 unkC[CONTESTANT_COUNT];
    u8 numBarsUpdating;
};

struct ContestMonResults
{
    int relativePreliminaryPoints;
    int relativeRound2Points;
    u32 barLengthPreliminary;
    u32 barLengthRound2;
    bool8 lostPoints;
    u8 numStars;
    u8 numHearts;
};

struct ContestResults
{
    struct ContestResultsInternal *data;
    struct ContestMonResults (*monResults)[CONTESTANT_COUNT];
    u8 *unusedBg; // Allocated/freed, never used
    u8 *tilemapBuffers[4];
    u8 *unused; // Allocated/freed, never used
};

static EWRAM_DATA struct ContestResults *sContestResults = NULL;

static void LoadAllContestMonIconPalettes(void);
static void LoadContestResultsTilemaps(void);
static u8 GetNumPreliminaryPoints(u8, bool8);
static s8 GetNumRound2Points(u8, bool8);
static void AddContestTextPrinter(int, u8 *, int);
static void AllocContestResults(void);
static void FreeContestResults(void);
static void LoadAllContestMonIcons(u8, u8);
static void LoadContestResultSprites(void);
static void TryCreateWirelessSprites(void);
static void Task_StartShowContestResults(u8 taskId);
static void CB2_StartShowContestResults(void);
static void Task_ShowContestResults(u8);
static void CB2_ShowContestResults(void);
static void VBlankCB_ShowContestResults(void);
static void Task_SlideContestResultsBg(u8);
static void Task_WaitForLinkPartnersBeforeResults(u8);
static void sub_80F5F14(u8);
static void sub_80F5F30(u8);
static void Task_AnnouncePreliminaryResults(u8);
static void Task_FlashStarsAndHearts(u8);
static void Task_ShowPreliminaryResults(u8);
static void Task_AnnounceRound2Results(u8);
static void Task_ShowRound2Results(u8);
static void Task_AnnounceWinner(u8);
static void Task_DrawFinalStandingNumber(u8);
static void Task_StartHighlightWinnersBox(u8);
static void Task_HighlightWinnersBox(u8);
static void Task_ShowWinnerMonBanner(u8);
static void Task_SetSeenWinnerMon(u8);
static void Task_TryDisconnectLinkPartners(u8);
static void Task_WaitForLinkPartnersDisconnect(u8);
static void Task_TrySetContestInterviewData(u8);
static void Task_EndShowContestResults(u8);
static void CalculateContestantsResultData(void);
static void ShowLinkResultsTextBox(const u8 *);
static void HideLinkResultsTextBox(void);
static s32 DrawResultsTextWindow(const u8 *, u8);
static void StartTextBoxSlideIn(s16, u16, u16, u16);
static void UpdateContestResultBars(bool8, u8);
static void Task_UpdateContestResultBar(u8);
static void StartTextBoxSlideOut(u16);
static void BounceMonIconInBox(u8, u8);
static void Task_BounceMonIconInBox(u8);
static void SpriteCB_WinnerMonSlideIn(struct Sprite *);
static void SpriteCB_WinnerMonSlideOut(struct Sprite *);
static void Task_CreateConfetti(u8);
static void SpriteCB_TextBoxSlideIn(struct Sprite *);
static void SpriteCB_TextBoxSlideOut(struct Sprite *);
static void SpriteCB_EndTextBoxSlideIn(struct Sprite *);
static void sub_80F8508(u8);
static void sub_80F8568(u8);
static void sub_80F8584(u8);
static void sub_80F85A0(u8);
static void sub_80F85BC(u8);
static void sub_80F86B8(u8);
static void sub_80F878C(u8);
static void sub_80F87B4(u8);
static void SpriteCB_Confetti(struct Sprite *sprite);

static const u16 sUnknown_0858D6B0[] = INCBIN_U16("graphics/unknown/unknown_58D6B0.gbapal");
static const u8 sUnknown_0858D6D0[] = INCBIN_U8("graphics/unknown/unknown_58D6D0.4bpp");
static const u16 sMiscBlank_Pal[] = INCBIN_U16("graphics/interface/blank.gbapal");

static const struct OamData sOamData_858D7F0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 2,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_858D7F8 = 
{
    .tileTag = 3009, 
    .paletteTag = 3009, 
    .oam = &sOamData_858D7F0, 
    .anims = gDummySpriteAnimTable, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet sUnknown_0858D810[] = 
{
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3009 },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3010 },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3011 },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3012 },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3013 },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3014 },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3015 },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = 3016 },
};

static const struct SpritePalette sUnknown_0858D850 =
{
     .data = sMiscBlank_Pal,
     .tag = 3009,
};

static const struct OamData sOamData_Confetti =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteTemplate sSpriteTemplate_Confetti =
{
    .tileTag = TAG_CONFETTI, 
    .paletteTag = TAG_CONFETTI, 
    .oam = &sOamData_Confetti, 
    .anims = gDummySpriteAnimTable, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCB_Confetti
};

static const struct CompressedSpriteSheet sSpriteSheet_Confetti =
{
    .data = gConfetti_Gfx, 
    .size = 0x220, 
    .tag = TAG_CONFETTI
};


static const struct CompressedSpritePalette sSpritePalette_Confetti =
{
    .data = gConfetti_Pal, 
    .tag = TAG_CONFETTI
};

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 24,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    }, 
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    }, 
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 26,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    }
};

static const struct WindowTemplate sWindowTemplates[] =
{
    {
        .bg = 1, 
        .tilemapLeft = 7, 
        .tilemapTop = 4, 
        .width = 12, 
        .height = 2, 
        .paletteNum = 15, 
        .baseBlock = 770
    },
    {
        .bg = 1, 
        .tilemapLeft = 7, 
        .tilemapTop = 7, 
        .width = 12, 
        .height = 2, 
        .paletteNum = 15, 
        .baseBlock = 794
    },
    {
        .bg = 1, 
        .tilemapLeft = 7, 
        .tilemapTop = 10, 
        .width = 12, 
        .height = 2, 
        .paletteNum = 15, 
        .baseBlock = 818
    },
    {
        .bg = 1, 
        .tilemapLeft = 7, 
        .tilemapTop = 13, 
        .width = 12, 
        .height = 2, 
        .paletteNum = 15, 
        .baseBlock = 842
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct OamData sUnknown_0858D8C0 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};


static const struct SpriteTemplate sSpriteTemplate_858D8C8 =
{
    .tileTag = 22222, 
    .paletteTag = 0, 
    .oam = &sUnknown_0858D8C0, 
    .anims = gDummySpriteAnimTable, 
    .images = NULL, 
    .affineAnims = gDummySpriteAffineAnimTable, 
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet sUnknown_0858D8E0 = 
{
    .data = gMiscBlank_Gfx, 
    .size = 0x200, 
    .tag = 22222
};

static const u8 sContestLinkTextColors[4] = {TEXT_COLOR_WHITE, TEXT_DYNAMIC_COLOR_6, TEXT_DYNAMIC_COLOR_5};


static void InitContestResultsDisplay(void)
{
    int i;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    for (i = 0; i < (int)ARRAY_COUNT(sContestResults->tilemapBuffers); i++)
        SetBgTilemapBuffer(i, sContestResults->tilemapBuffers[i]);

    InitWindows(sWindowTemplates);
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

static void LoadContestResultsBgGfx(void)
{
    int i, j;
    s8 numStars, round2Points;
    u16 tile1, tile2;

    LZDecompressVram(gContestResults_Gfx, (void *)BG_CHAR_ADDR(0));
    CopyToBgTilemapBuffer(3, gUnknown_08C1A12C, 0, 0);
    CopyToBgTilemapBuffer(2, gUnknown_08C1A000, 0, 0);
    CopyToBgTilemapBuffer(0, gUnknown_08C19EEC, 0, 0);
    LoadContestResultsTilemaps();
    LoadCompressedPalette(gContestResults_Pal, 0, 0x200);
    LoadPalette(sUnknown_0858D6B0, 0xF0, 0x20);

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        numStars = GetNumPreliminaryPoints(i, TRUE);
        round2Points = GetNumRound2Points(i, TRUE);
        for (j = 0; j < 10; j++)
        {
            tile1 = 0x60B2;
            if (j < numStars)
                tile1 += 2;

            // Abs of round2Points is number of hearts
            if (j < abs(round2Points))
            {
                tile2 = 0x60A4;
                if (round2Points < 0)
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

static void LoadContestMonName(u8 monIndex)
{
    struct ContestPokemon *mon = &gContestMons[monIndex];
    u8 *str = gDisplayedStringBattle;
    if (monIndex == gContestPlayerMonIndex)
        str = StringCopy(gDisplayedStringBattle, gText_ColorDarkGrey);

    StringCopy(str, mon->nickname);
    AddContestTextPrinter(monIndex, gDisplayedStringBattle, 0);
    StringCopy(str, gText_Slash);
    StringAppend(str, mon->trainerName);
    AddContestTextPrinter(monIndex, gDisplayedStringBattle, 50);
}

static void LoadAllContestMonNames(void)
{
    int i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        LoadContestMonName(i);

    CopyBgTilemapBufferToVram(1);
}

static void CB2_StartShowContestResults(void)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    SetVBlankCallback(NULL);
    AllocContestResults();
    InitContestResultsDisplay();
    ScanlineEffect_Clear();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
    FreeAllSpritePalettes();
    LoadContestResultsBgGfx();
    LoadAllContestMonIconPalettes();
    LoadAllContestMonIcons(0, TRUE);
    LoadAllContestMonNames();
    memset(sContestResults->data, 0, sizeof(*sContestResults->data));
    memset(sContestResults->monResults, 0, sizeof(*sContestResults->monResults));
    LoadContestResultSprites();
    TryCreateWirelessSprites();
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    gPaletteFade.bufferTransferDisabled = FALSE;
    sContestResults->data->showResultsTaskId = CreateTask(Task_ShowContestResults, 5);
    SetMainCallback2(CB2_ShowContestResults);
    gBattle_WIN1H = 0x00F0;
    gBattle_WIN1V = 0x80A0;
    CreateTask(Task_SlideContestResultsBg, 20);
    CalculateContestantsResultData();
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
        gPaletteFade.bufferTransferDisabled = TRUE;
    else
        PlayBGM(MUS_CON_K);

    SetVBlankCallback(VBlankCB_ShowContestResults);
}

static void CB2_ShowContestResults(void)
{
    AnimateSprites();
    BuildOamBuffer();
    RunTasks();
    UpdatePaletteFade();
    CopyBgTilemapBufferToVram(1);
    CopyBgTilemapBufferToVram(2);
}

static void VBlankCB_ShowContestResults(void)
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
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

#define tState   data[0]
#define tTimer   data[1]
#define tCounter data[2]

static void Task_ShowContestResults(u8 taskId)
{
    u16 var;

    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        switch (gTasks[taskId].tState)
        {
        case 0:
            SaveLinkContestResults();
            if (gContestFinalStandings[gContestPlayerMonIndex] == 0)
            {
                IncrementGameStat(GAME_STAT_WON_LINK_CONTEST);
                gSpecialVar_0x8005 = TVSHOW_CONTEST_LIVE_UPDATES;
                InterviewBefore();
                if (gSpecialVar_Result != TRUE)
                    InterviewAfter();
            }

            TryGainNewFanFromCounter(FANCOUNTER_FINISHED_CONTEST);
            sub_80DEDA8(gSpecialVar_ContestRank);
            sub_80DEDA8(0xFE);
            gUnknown_02039F5C = TRUE;
            gUnknown_02039F5D = sub_80DEFA8(0xFE, 0);
            var = VarGet(VAR_CONTEST_HALL_STATE);
            VarSet(VAR_CONTEST_HALL_STATE, 0);
            SetContinueGameWarpStatusToDynamicWarp();
            TrySavingData(SAVE_LINK);
            ClearContinueGameWarpStatus2();
            VarSet(VAR_CONTEST_HALL_STATE, var);
            gTasks[taskId].tState++;
            break;
        case 1:
            gTasks[taskId].tState++;
            if (!(gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS))
                gTasks[taskId].tState = 100;
            break;
        case 2:
            if (IsLinkTaskFinished())
            {
                sub_800ADF8();
                gTasks[taskId].tState++;
            }
            return;
        case 3:
            if (IsLinkTaskFinished() == TRUE)
            {
                PlayBGM(MUS_CON_K);
                gPaletteFade.bufferTransferDisabled = FALSE;
                gTasks[taskId].tState++;
                break;
            }
            return;
        }
    }

    if (!gPaletteFade.active)
    {
        gTasks[taskId].tState = 0;
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        {
            ShowLinkResultsTextBox(gText_CommunicationStandby);
            gTasks[taskId].func = Task_WaitForLinkPartnersBeforeResults;
        }
        else
        {
            IncrementGameStat(GAME_STAT_ENTERED_CONTEST);
            if (gContestFinalStandings[gContestPlayerMonIndex] == 0)
                IncrementGameStat(GAME_STAT_WON_CONTEST);

            sub_80DEDA8(gSpecialVar_ContestRank);
            sub_80DEDA8(0xFE);
            gUnknown_02039F5C = TRUE;
            gUnknown_02039F5D = sub_80DEFA8(0xFE, 0);
            TryGainNewFanFromCounter(FANCOUNTER_FINISHED_CONTEST);
            gTasks[taskId].func = Task_AnnouncePreliminaryResults;
        }
    }
}

static void Task_WaitForLinkPartnersBeforeResults(u8 taskId)
{
    if (gReceivedRemoteLinkPlayers)
    {
        CreateTask(sub_80F5F14, 0);
        gTasks[taskId].func = TaskDummy;
    }
}

static void sub_80F5F14(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_80FC998, sub_80F5F30);
}

static void sub_80F5F30(u8 taskId)
{
    if (IsLinkTaskFinished())
    {
        DestroyTask(taskId);
        gTasks[sContestResults->data->showResultsTaskId].func = Task_AnnouncePreliminaryResults;
        HideLinkResultsTextBox();
    }
}

static void Task_AnnouncePreliminaryResults(u8 taskId)
{
    s16 x;

    if (gTasks[taskId].tState == 0)
    {
        CreateTask(Task_FlashStarsAndHearts, 20);
        x = DrawResultsTextWindow(gText_AnnouncingResults, sContestResults->data->slidingTextBoxSpriteId);
        StartTextBoxSlideIn(x, 144, 120, 1088);
        gTasks[taskId].tState++;
    }
    else if (gTasks[taskId].tState == 1)
    {
        // Wait for "Announcing Results" text to leave
        if (sContestResults->data->slidingTextBoxState == SLIDING_TEXT_OFFSCREEN)
        {
            gTasks[taskId].tTimer = 0;
            gTasks[taskId].tState++;
        }
    }
    else if (gTasks[taskId].tState == 2)
    {
        if (++gTasks[taskId].tTimer == 21)
        {
            gTasks[taskId].tTimer = 0;
            gTasks[taskId].tState++;
        }
    }
    else if (gTasks[taskId].tState == 3)
    {
        x = DrawResultsTextWindow(gText_PreliminaryResults, sContestResults->data->slidingTextBoxSpriteId);
        StartTextBoxSlideIn(x, 144, -1, 1088);
        gTasks[taskId].tState++;
    }
    else if (gTasks[taskId].tState == 4)
    {
        if (sContestResults->data->slidingTextBoxState == SLIDING_TEXT_ARRIVED)
        {
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = Task_ShowPreliminaryResults;
        }
    }
}

static void Task_ShowPreliminaryResults(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!sContestResults->data->pointsFlashing)
        {
            UpdateContestResultBars(FALSE, gTasks[taskId].tCounter++);
            if (sContestResults->data->numBarsUpdating == 0)
                gTasks[taskId].tState = 2;
            else
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (sContestResults->data->numBarsUpdating == 0)
            gTasks[taskId].tState = 0;
        break;
    case 2:
        StartTextBoxSlideOut(1088);
        gTasks[taskId].tState = 0;
        gTasks[taskId].tCounter = 0;
        gTasks[taskId].func = Task_AnnounceRound2Results;
        break;
    }
}

static void Task_AnnounceRound2Results(u8 taskId)
{
    s16 x;

    if (sContestResults->data->slidingTextBoxState == SLIDING_TEXT_OFFSCREEN)
    {
        if (++gTasks[taskId].tTimer == 21)
        {
            gTasks[taskId].tTimer = 0;
            x = DrawResultsTextWindow(gText_Round2Results, sContestResults->data->slidingTextBoxSpriteId);
            StartTextBoxSlideIn(x, 144, -1, 1088);
        }
    }
    else if (sContestResults->data->slidingTextBoxState == SLIDING_TEXT_ARRIVED)
    {
        gTasks[taskId].func = Task_ShowRound2Results;
    }
}

static void Task_ShowRound2Results(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!sContestResults->data->pointsFlashing)
        {
            UpdateContestResultBars(TRUE, gTasks[taskId].tCounter++);
            if (sContestResults->data->numBarsUpdating == 0)
                gTasks[taskId].tState = 2;
            else
                gTasks[taskId].tState++;
        }
        break;
    case 1:
        if (sContestResults->data->numBarsUpdating == 0)
            gTasks[taskId].tState = 0;
        break;
    case 2:
        StartTextBoxSlideOut(1088);
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_AnnounceWinner;
        break;
    }
}

// Task data for Task_DrawFinalStandingNumber
#define tFinalStanding data[0]
#define tMonIndex      data[1]

static void Task_AnnounceWinner(u8 taskId)
{
    int i;
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (sContestResults->data->slidingTextBoxState == SLIDING_TEXT_OFFSCREEN)
            gTasks[taskId].tState++;
        break;
    case 1:
        if (++gTasks[taskId].tTimer == 31)
        {
            gTasks[taskId].tTimer = 0;
            gTasks[taskId].tState++;
        }
        break;
    case 2:
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            u8 newTaskId = CreateTask(Task_DrawFinalStandingNumber, 10);
            gTasks[newTaskId].tFinalStanding = gContestFinalStandings[i];
            gTasks[newTaskId].tMonIndex = i;
        }
        gTasks[taskId].tState++;
        break;
    case 3:
        if (sContestResults->data->numStandingsPrinted == CONTESTANT_COUNT)
        {
            if (++gTasks[taskId].tTimer == 31)
            {
                gTasks[taskId].tTimer = 0;
                CreateTask(Task_StartHighlightWinnersBox, 10);
                gTasks[taskId].tState++;
                GET_CONTEST_WINNER_ID(i);
                BounceMonIconInBox(i, 14);
            }
        }
        break;
    case 4:
        if (++gTasks[taskId].tTimer == 21)
        {
            u8 winnerTextBuffer[100];
            s16 x;
            gTasks[taskId].tTimer = 0;
            GET_CONTEST_WINNER_ID(i);
            StringCopy(gStringVar1, gContestMons[i].trainerName);
            sub_81DB5AC(gStringVar1);
            StringCopy(gStringVar2, gContestMons[i].nickname);
            StringExpandPlaceholders(winnerTextBuffer, gText_ContestantsMonWon);
            x = DrawResultsTextWindow(winnerTextBuffer, sContestResults->data->slidingTextBoxSpriteId);
            StartTextBoxSlideIn(x, 144, -1, 1088);
            gTasks[taskId].tState++;
        }
        break;
    case 5:
        gTasks[taskId].tState = 0;
        gTasks[taskId].func = Task_ShowWinnerMonBanner;
        break;
    }
}

static void Task_ShowWinnerMonBanner(u8 taskId)
{
    int i;
    u8 spriteId;
    u16 species;
    u32 otId;
    u32 personality;
    const struct CompressedSpritePalette *pokePal;

    switch (gTasks[taskId].tState)
    {
    case 0:
        gBattle_WIN0H = 0x00F0;
        gBattle_WIN0V = 0x5050;

        GET_CONTEST_WINNER_ID(i);
        species = gContestMons[i].species;
        personality = gContestMons[i].personality;
        otId = gContestMons[i].otId;
        if (i == gContestPlayerMonIndex)
        {
            HandleLoadSpecialPokePic_2(
                &gMonFrontPicTable[species],
                gMonSpritesGfxPtr->sprites[1],
                species,
                personality);
        }
        else
        {
            HandleLoadSpecialPokePic_DontHandleDeoxys(
                &gMonFrontPicTable[species],
                gMonSpritesGfxPtr->sprites[1],
                species,
                personality);
        }

        pokePal = GetMonSpritePalStructFromOtIdPersonality(species, otId, personality);
        LoadCompressedSpritePalette(pokePal);
        SetMultiuseSpriteTemplateToPokemon(species, B_POSITION_OPPONENT_LEFT);
        gMultiuseSpriteTemplate.paletteTag = pokePal->tag;
        spriteId = CreateSprite(&gMultiuseSpriteTemplate, 272, 80, 10);
        gSprites[spriteId].data[1] = species;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].callback = SpriteCB_WinnerMonSlideIn;
        sContestResults->data->winnerMonSpriteId = spriteId;
        LoadCompressedSpriteSheet(&sSpriteSheet_Confetti);
        LoadCompressedSpritePalette(&sSpritePalette_Confetti);
        CreateTask(Task_CreateConfetti, 10);
        gTasks[taskId].tState++;
        break;
    case 1:
        if (++gTasks[taskId].data[3] == 1)
        {
            u8 counter;
            gTasks[taskId].data[3] = 0;
            gTasks[taskId].tCounter += 2;
            if (gTasks[taskId].tCounter > 32)
                gTasks[taskId].tCounter = 32;

            counter = gTasks[taskId].tCounter;
            gBattle_WIN0V = ((80 - counter) << 8) | (80 + counter);
            if (counter == 32)
                gTasks[taskId].tState++;
        }
        break;
    case 2:
        if (sContestResults->data->winnerMonSlidingState == SLIDING_MON_ENTERED)
            gTasks[taskId].tState++;
        break;
    case 3:
        if (++gTasks[taskId].tTimer == 121)
        {
            gTasks[taskId].tTimer = 0;
            gSprites[sContestResults->data->winnerMonSpriteId].callback = SpriteCB_WinnerMonSlideOut;
            gTasks[taskId].tState++;
        }
        break;
    case 4:
        if (sContestResults->data->winnerMonSlidingState == SLIDING_MON_EXITED)
        {
            u8 top = (gBattle_WIN0V >> 8);
            top += 2;
            if (top > 80)
                top = 80;

            gBattle_WIN0V = (top << 8) | (160 - top);
            if (top == 80)
                gTasks[taskId].tState++;
        }
        break;
    case 5:
        if (sContestResults->data->winnerMonSlidingState == SLIDING_MON_EXITED)
        {
            sContestResults->data->destroyConfetti = TRUE;
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = Task_SetSeenWinnerMon;
        }
        break;
    }
}

static void Task_SetSeenWinnerMon(u8 taskId)
{
    int i, nationalDexNum;

    if (JOY_NEW(A_BUTTON))
    {
        if (!(gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK))
        {
            for (i = 0; i < CONTESTANT_COUNT; i++)
            {
                nationalDexNum = SpeciesToNationalPokedexNum(gContestMons[i].species);
                GetSetPokedexFlag(nationalDexNum, FLAG_SET_SEEN);
            }
        }

        gTasks[taskId].data[10] = 0;
        gTasks[taskId].func = Task_TryDisconnectLinkPartners;
    }
}

static void Task_TryDisconnectLinkPartners(u8 taskId)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        if (!gTasks[taskId].data[10])
        {
            ShowLinkResultsTextBox(gText_CommunicationStandby);
            sub_800AC34();
            gTasks[taskId].func = Task_WaitForLinkPartnersDisconnect;
        }
    }
    else
    {
        gTasks[taskId].func = Task_TrySetContestInterviewData;
    }
}

static void Task_WaitForLinkPartnersDisconnect(u8 taskId)
{
    if (!gReceivedRemoteLinkPlayers)
    {
        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
            DestroyWirelessStatusIndicatorSprite();

        HideLinkResultsTextBox();
        gTasks[taskId].func = Task_TrySetContestInterviewData;
    }
}

static void Task_TrySetContestInterviewData(u8 taskId)
{
    if (!(gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK))
        BravoTrainerPokemonProfile_BeforeInterview2(gContestFinalStandings[gContestPlayerMonIndex]);

    BeginHardwarePaletteFade(0xFF, 0, 0, 16, 0);
    gTasks[taskId].func = Task_EndShowContestResults;
}

static void Task_EndShowContestResults(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[taskId].tTimer == 0)
        {
            DestroyTask(sContestResults->data->highlightWinnerTaskId);
            BlendPalettes(0x0000FFFF, 16, RGB_BLACK);
            gTasks[taskId].tTimer++;
        }
        else if (gTasks[taskId].tTimer == 1)
        {
            BlendPalettes(0xFFFF0000, 16, RGB_BLACK);
            gTasks[taskId].tTimer++;
        }
        else
        {
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            DestroyTask(taskId);
            FreeAllWindowBuffers();
            SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
            FreeContestResults();
        }
    }
}

#undef tState
#undef tTimer
#undef tCounter

static void Task_SlideContestResultsBg(u8 taskId)
{
    gBattle_BG3_X += 2;
    gBattle_BG3_Y += 1;
    if (gBattle_BG3_X > 255)
        gBattle_BG3_X -= 255;
    if (gBattle_BG3_Y > 255)
        gBattle_BG3_Y -= 255;
}

#define tDelay      data[0]
#define tCoeff      data[1]
#define tDecreasing data[2]

static void Task_FlashStarsAndHearts(u8 taskId)
{
    if (++gTasks[taskId].tDelay == 2)
    {
        gTasks[taskId].tDelay = 0;
        if (!gTasks[taskId].tDecreasing)
            gTasks[taskId].tCoeff++;
        else
            gTasks[taskId].tCoeff--;

        if (gTasks[taskId].tCoeff == 16)
            gTasks[taskId].tDecreasing = TRUE;
        else if (gTasks[taskId].tCoeff == 0)
            gTasks[taskId].tDecreasing = FALSE;

        BlendPalette(0x6B, 1, gTasks[taskId].tCoeff, RGB(30, 22, 11));
        BlendPalette(0x68, 1, gTasks[taskId].tCoeff, RGB_WHITE);
        BlendPalette(0x6E, 1, gTasks[taskId].tCoeff, RGB(30, 29, 29));
    }

    if (gTasks[taskId].tCoeff == 0)
        sContestResults->data->pointsFlashing = FALSE;
    else
        sContestResults->data->pointsFlashing = TRUE;
}

static void LoadContestMonIcon(u16 species, u8 monIndex, u8 srcOffset, u8 useDmaNow, u32 personality)
{
    const u8 *iconPtr;
    u16 var0, var1, frameNum;

    if (monIndex == gContestPlayerMonIndex)
        frameNum = 1;
    else
        frameNum = 0;

    iconPtr = GetMonIconPtr(species, personality, frameNum);
    iconPtr += srcOffset * 0x200 + 0x80;
    if (useDmaNow)
    {
        RequestDma3Copy(iconPtr, (void *)BG_CHAR_ADDR(1) + monIndex * 0x200, 0x180, 1);
        var0 = ((monIndex + 10) << 12);
        var1 = (monIndex * 0x10 + 0x200);
        WriteSequenceToBgTilemapBuffer(1, var1 | var0, 3, monIndex * 3 + 4, 4, 3, 17, 1);
    }
    else
    {
        RequestDma3Copy(iconPtr, (void *)BG_CHAR_ADDR(1) + monIndex * 0x200, 0x180, 1);
    }
}

static void LoadAllContestMonIcons(u8 srcOffset, bool8 useDmaNow)
{
    int i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        LoadContestMonIcon(gContestMons[i].species, i, srcOffset, useDmaNow, gContestMons[i].personality);
}

static void LoadAllContestMonIconPalettes(void)
{
    int i, species;

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        species = gContestMons[i].species;
        LoadPalette(gMonIconPalettes[gMonIconPaletteIndices[GetIconSpecies(species, 0)]], i * 0x10 + 0xA0, 0x20);
    }
}

static void TryCreateWirelessSprites(void)
{
    u16 sheet;
    u8 spriteId;

    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        LoadWirelessStatusIndicatorSpriteGfx();
        CreateWirelessStatusIndicatorSprite(8, 8);
        gSprites[gWirelessStatusIndicatorSpriteId].subpriority = 1;
        sheet = LoadSpriteSheet(&sUnknown_0858D8E0);
        RequestDma3Fill(0xFFFFFFFF, (void *)BG_CHAR_ADDR(4) + sheet * 0x20, 0x80, 1);
        spriteId = CreateSprite(&sSpriteTemplate_858D8C8, 8, 8, 0);
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_WINDOW;
    }
}

// Functionally equivalent, the same except compiler generated variables from
// src are placed on different stack positions.

#ifdef NONMATCHING
static s32 DrawResultsTextWindow(const u8 *text, u8 spriteId)
{
    u8 *windowTilesPtr;
    u16 windowId;
    int origWidth;
    struct WindowTemplate windowTemplate;
    int strWidth;
    u8 *spriteTilePtrs[4];
    u8 *dst;
    int i;
    struct Sprite *sprite;
    const u8 *src; // The culprit.

    memset(&windowTemplate, 0, sizeof(windowTemplate));
    windowTemplate.width = 30;
    windowTemplate.height = 2;
    windowId = AddWindow(&windowTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));

    origWidth = GetStringWidth(1, text, 0);
    strWidth = (origWidth + 9) / 8;
    if (strWidth > 30)
     strWidth = 30;

    AddTextPrinterParameterized3(windowId, 1, (strWidth * 8 - origWidth) / 2, 1, sContestLinkTextColors, -1, text);
    windowTilesPtr = (u8 *)(GetWindowAttribute(windowId, WINDOW_TILE_DATA));
    src = (u8 *)(sUnknown_0858D6D0);

    sprite = &gSprites[spriteId];
    spriteTilePtrs[0] = (u8 *)(sprite->oam.tileNum * 32 + VRAM + 0x10000);

    for (i = 1; i < 4; i++)
        spriteTilePtrs[i] = (void*)(gSprites[sprite->data[i - 1]].oam.tileNum * 32 + VRAM + 0x10000);

    for (i = 0; i < 4; i++)
        CpuFill32(0, spriteTilePtrs[i], 0x400);

    dst = spriteTilePtrs[0];
    CpuCopy32(src, dst, 0x20);
    CpuCopy32(src + 128, dst + 0x100, 0x20);
    CpuCopy32(src + 128, dst + 0x200, 0x20);
    CpuCopy32(src + 64,  dst + 0x300, 0x20);

    for (i = 0; i < strWidth; i++)
    {
        dst = &spriteTilePtrs[(i + 1) / 8][((i + 1) % 8) * 32];
        CpuCopy32(src + 192, dst, 0x20);
        CpuCopy32(windowTilesPtr, dst + 0x100, 0x20);
        CpuCopy32(windowTilesPtr + 960, dst + 0x200, 0x20);
        CpuCopy32(src + 224, dst + 0x300, 0x20);
        windowTilesPtr += 0x20;
    }

    dst = &spriteTilePtrs[(i + 1) / 8][((i + 1) % 8) * 32];
    CpuCopy32(src + 32,  dst, 0x20);
    CpuCopy32(src + 160, dst + 0x100, 0x20);
    CpuCopy32(src + 160, dst + 0x200, 0x20);
    CpuCopy32(src + 96,  dst + 0x300, 0x20);
    RemoveWindow(windowId);

    return (240 - (strWidth + 2) * 8) / 2;
}

#else
NAKED
static s32 DrawResultsTextWindow(const u8 *text, u8 spriteId)
{
    asm_unified("\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x44\n\
    adds r5, r0, 0\n\
    lsls r1, 24\n\
    lsrs r7, r1, 24\n\
    add r4, sp, 0x20\n\
    adds r0, r4, 0\n\
    movs r1, 0\n\
    movs r2, 0x8\n\
    bl memset\n\
    movs r0, 0x1E\n\
    strb r0, [r4, 0x3]\n\
    movs r0, 0x2\n\
    strb r0, [r4, 0x4]\n\
    adds r0, r4, 0\n\
    bl AddWindow\n\
    lsls r6, r0, 24\n\
    lsrs r4, r6, 24\n\
    adds r0, r4, 0\n\
    movs r1, 0x11\n\
    bl FillWindowPixelBuffer\n\
    movs r0, 0x1\n\
    adds r1, r5, 0\n\
    movs r2, 0\n\
    bl GetStringWidth\n\
    adds r2, r0, 0\n\
    adds r2, 0x9\n\
    cmp r2, 0\n\
    bge _080F6BC4\n\
    adds r2, 0x7\n\
_080F6BC4:\n\
    asrs r2, 3\n\
    mov r10, r2\n\
    cmp r2, 0x1E\n\
    ble _080F6BD0\n\
    movs r1, 0x1E\n\
    mov r10, r1\n\
_080F6BD0:\n\
    mov r1, r10\n\
    lsls r2, r1, 3\n\
    subs r2, r0\n\
    lsrs r0, r2, 31\n\
    adds r2, r0\n\
    asrs r2, 1\n\
    lsls r2, 24\n\
    lsrs r2, 24\n\
    ldr r0, =sContestLinkTextColors\n\
    str r0, [sp]\n\
    movs r0, 0x1\n\
    negs r0, r0\n\
    str r0, [sp, 0x4]\n\
    str r5, [sp, 0x8]\n\
    adds r0, r4, 0\n\
    movs r1, 0x1\n\
    movs r3, 0x1\n\
    bl AddTextPrinterParameterized3\n\
    adds r0, r4, 0\n\
    movs r1, 0x7\n\
    bl GetWindowAttribute\n\
    mov r9, r0\n\
    ldr r2, =sUnknown_0858D6D0\n\
    mov r8, r2\n\
    lsls r1, r7, 4\n\
    adds r1, r7\n\
    lsls r1, 2\n\
    ldr r3, =gSprites\n\
    adds r1, r3\n\
    ldrh r0, [r1, 0x4]\n\
    lsls r0, 22\n\
    lsrs r0, 17\n\
    ldr r2, =0x06010000\n\
    adds r0, r2\n\
    str r0, [sp, 0xC]\n\
    str r6, [sp, 0x38]\n\
    mov r7, sp\n\
    adds r7, 0x1C\n\
    str r7, [sp, 0x2C]\n\
    mov r0, r10\n\
    adds r0, 0x2\n\
    str r0, [sp, 0x30]\n\
    movs r5, 0\n\
    add r7, sp, 0x10\n\
    mov r12, r7\n\
    adds r6, r1, 0\n\
    adds r6, 0x2E\n\
    movs r4, 0x2\n\
_080F6C34:\n\
    adds r0, r6, r5\n\
    movs r7, 0\n\
    ldrsh r1, [r0, r7]\n\
    lsls r0, r1, 4\n\
    adds r0, r1\n\
    lsls r0, 2\n\
    adds r0, r3\n\
    ldrh r0, [r0, 0x4]\n\
    lsls r0, 22\n\
    lsrs r0, 17\n\
    adds r0, r2\n\
    mov r1, r12\n\
    adds r1, 0x4\n\
    mov r12, r1\n\
    subs r1, 0x4\n\
    stm r1!, {r0}\n\
    adds r5, 0x2\n\
    subs r4, 0x1\n\
    cmp r4, 0\n\
    bge _080F6C34\n\
    mov r7, r8\n\
    adds r7, 0x80\n\
    mov r2, r8\n\
    adds r2, 0x40\n\
    str r2, [sp, 0x28]\n\
    mov r0, r8\n\
    adds r0, 0x20\n\
    str r0, [sp, 0x3C]\n\
    mov r1, r8\n\
    adds r1, 0xA0\n\
    str r1, [sp, 0x40]\n\
    adds r2, 0x20\n\
    str r2, [sp, 0x34]\n\
    add r5, sp, 0xC\n\
    movs r6, 0\n\
    movs r4, 0x3\n\
_080F6C7C:\n\
    str r6, [sp, 0x1C]\n\
    ldm r5!, {r1}\n\
    ldr r0, [sp, 0x2C]\n\
    ldr r2, =0x05000100\n\
    bl CpuSet\n\
    subs r4, 0x1\n\
    cmp r4, 0\n\
    bge _080F6C7C\n\
    ldr r5, [sp, 0xC]\n\
    ldr r6, =0x04000008\n\
    mov r0, r8\n\
    adds r1, r5, 0\n\
    adds r2, r6, 0\n\
    bl CpuSet\n\
    movs r0, 0x80\n\
    lsls r0, 1\n\
    adds r1, r5, r0\n\
    adds r0, r7, 0\n\
    adds r2, r6, 0\n\
    bl CpuSet\n\
    movs r2, 0x80\n\
    lsls r2, 2\n\
    adds r1, r5, r2\n\
    adds r0, r7, 0\n\
    adds r2, r6, 0\n\
    bl CpuSet\n\
    movs r7, 0xC0\n\
    lsls r7, 2\n\
    adds r1, r5, r7\n\
    ldr r0, [sp, 0x28]\n\
    adds r2, r6, 0\n\
    bl CpuSet\n\
    movs r4, 0\n\
    cmp r4, r10\n\
    bge _080F6D32\n\
    adds r7, r6, 0\n\
_080F6CCE:\n\
    adds r6, r4, 0x1\n\
    adds r0, r6, 0\n\
    cmp r6, 0\n\
    bge _080F6CDA\n\
    adds r0, r4, 0\n\
    adds r0, 0x8\n\
_080F6CDA:\n\
    asrs r0, 3\n\
    lsls r1, r0, 2\n\
    add r1, sp\n\
    adds r1, 0xC\n\
    lsls r0, 3\n\
    subs r0, r6, r0\n\
    lsls r0, 5\n\
    ldr r1, [r1]\n\
    adds r5, r1, r0\n\
    mov r0, r8\n\
    adds r0, 0xC0\n\
    adds r1, r5, 0\n\
    adds r2, r7, 0\n\
    bl CpuSet\n\
    movs r0, 0x80\n\
    lsls r0, 1\n\
    adds r1, r5, r0\n\
    mov r0, r9\n\
    adds r2, r7, 0\n\
    bl CpuSet\n\
    movs r0, 0xF0\n\
    lsls r0, 2\n\
    add r0, r9\n\
    movs r2, 0x80\n\
    lsls r2, 2\n\
    adds r1, r5, r2\n\
    adds r2, r7, 0\n\
    bl CpuSet\n\
    movs r0, 0xC0\n\
    lsls r0, 2\n\
    adds r1, r5, r0\n\
    mov r0, r8\n\
    adds r0, 0xE0\n\
    adds r2, r7, 0\n\
    bl CpuSet\n\
    movs r1, 0x20\n\
    add r9, r1\n\
    adds r4, r6, 0\n\
    cmp r4, r10\n\
    blt _080F6CCE\n\
_080F6D32:\n\
    adds r2, r4, 0x1\n\
    adds r0, r2, 0\n\
    cmp r2, 0\n\
    bge _080F6D3E\n\
    adds r0, r4, 0\n\
    adds r0, 0x8\n\
_080F6D3E:\n\
    asrs r0, 3\n\
    lsls r1, r0, 2\n\
    add r1, sp\n\
    adds r1, 0xC\n\
    lsls r0, 3\n\
    subs r0, r2, r0\n\
    lsls r0, 5\n\
    ldr r1, [r1]\n\
    adds r5, r1, r0\n\
    ldr r4, =0x04000008\n\
    ldr r0, [sp, 0x3C]\n\
    adds r1, r5, 0\n\
    adds r2, r4, 0\n\
    bl CpuSet\n\
    movs r2, 0x80\n\
    lsls r2, 1\n\
    adds r1, r5, r2\n\
    ldr r0, [sp, 0x40]\n\
    adds r2, r4, 0\n\
    bl CpuSet\n\
    movs r7, 0x80\n\
    lsls r7, 2\n\
    adds r1, r5, r7\n\
    ldr r0, [sp, 0x40]\n\
    adds r2, r4, 0\n\
    bl CpuSet\n\
    movs r0, 0xC0\n\
    lsls r0, 2\n\
    adds r1, r5, r0\n\
    ldr r0, [sp, 0x34]\n\
    adds r2, r4, 0\n\
    bl CpuSet\n\
    ldr r1, [sp, 0x38]\n\
    lsrs r0, r1, 24\n\
    bl RemoveWindow\n\
    ldr r2, [sp, 0x30]\n\
    lsls r1, r2, 3\n\
    movs r0, 0xF0\n\
    subs r0, r1\n\
    asrs r0, 1\n\
    add sp, 0x44\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r1}\n\
    bx r1\n\
    .pool");
}
#endif // NONMATCHING

static void LoadContestResultSprites(void)
{
    int i;
    struct SpriteTemplate template;
    u8 spriteIds[ARRAY_COUNT(sUnknown_0858D810)];

    template = sSpriteTemplate_858D7F8;
    for (i = 0; i < (int)ARRAY_COUNT(sUnknown_0858D810); i++)
        LoadSpriteSheet(&sUnknown_0858D810[i]);

    LoadSpritePalette(&sUnknown_0858D850);
    for (i = 0; i < (int)ARRAY_COUNT(sUnknown_0858D810); i++)
    {
        spriteIds[i] = CreateSprite(&template, 272, 144, 10);
        template.tileTag++;
    }

    gSprites[spriteIds[0]].data[0] = spriteIds[1];
    gSprites[spriteIds[0]].data[1] = spriteIds[2];
    gSprites[spriteIds[0]].data[2] = spriteIds[3];

    gSprites[spriteIds[4]].data[0] = spriteIds[5];
    gSprites[spriteIds[4]].data[1] = spriteIds[6];
    gSprites[spriteIds[4]].data[2] = spriteIds[7];

    sContestResults->data->slidingTextBoxSpriteId = spriteIds[0];
    sContestResults->data->slidingTextBoxState = SLIDING_TEXT_OFFSCREEN;
    sContestResults->data->linkTextBoxSpriteId = spriteIds[4];
    HideLinkResultsTextBox();
}

#define sTargetX        data[4]
#define sSlideOutTimer  data[5]
#define sSlideIncrement data[6]
#define sDistance       data[7]

// If slideOutTimer is -1, it will not automatically slide out
static void StartTextBoxSlideIn(s16 x, u16 y, u16 slideOutTimer, u16 slideIncrement)
{
    struct Sprite *sprite = &gSprites[sContestResults->data->slidingTextBoxSpriteId];
    sprite->pos1.x = 272;
    sprite->pos1.y = y;
    sprite->pos2.x = 0;
    sprite->pos2.y = 0;
    sprite->sTargetX = x + 32;
    sprite->sSlideOutTimer = slideOutTimer;
    sprite->sSlideIncrement = slideIncrement;
    sprite->sDistance = 0;
    sprite->callback = SpriteCB_TextBoxSlideIn;
    sContestResults->data->slidingTextBoxState = SLIDING_TEXT_ENTERING;
}

static void StartTextBoxSlideOut(u16 slideIncrement)
{
    struct Sprite *sprite = &gSprites[sContestResults->data->slidingTextBoxSpriteId];
    sprite->pos1.x += sprite->pos2.x;
    sprite->pos1.y += sprite->pos2.y;
    sprite->pos2.y = 0;
    sprite->pos2.x = 0;
    sprite->sSlideIncrement = slideIncrement;
    sprite->sDistance = 0;
    sprite->callback = SpriteCB_TextBoxSlideOut;
    sContestResults->data->slidingTextBoxState = SLIDING_TEXT_EXITING;
}

static void EndTextBoxSlideOut(struct Sprite *sprite)
{
    sprite->pos1.x = 272;
    sprite->pos1.y = 144;
    sprite->pos2.y = 0;
    sprite->pos2.x = 0;
    sprite->callback = SpriteCallbackDummy;
    sContestResults->data->slidingTextBoxState = SLIDING_TEXT_OFFSCREEN;
}

static void SpriteCB_TextBoxSlideIn(struct Sprite *sprite)
{
    int i;

    s16 delta = sprite->sDistance + sprite->sSlideIncrement;
    sprite->pos1.x -= delta >> 8;
    sprite->sDistance += sprite->sSlideIncrement;
    sprite->sDistance &= 0xFF;

    // Prevent overshooting target
    if (sprite->pos1.x < sprite->sTargetX)
        sprite->pos1.x = sprite->sTargetX;

    for (i = 0; i < 3; i++)
    {
        struct Sprite *sprite2 = &gSprites[sprite->data[i]];
        sprite2->pos1.x = sprite->pos1.x + sprite->pos2.x + (i + 1) * 64;
    }

    if (sprite->pos1.x == sprite->sTargetX)
        sprite->callback = SpriteCB_EndTextBoxSlideIn;
}

static void SpriteCB_EndTextBoxSlideIn(struct Sprite *sprite)
{
    sContestResults->data->slidingTextBoxState = SLIDING_TEXT_ARRIVED;
    if ((u16)sprite->sSlideOutTimer != 0xFFFF)
    {
        if (--sprite->sSlideOutTimer == -1)
            StartTextBoxSlideOut(sprite->sSlideIncrement);
    }
}

static void SpriteCB_TextBoxSlideOut(struct Sprite *sprite)
{
    int i;
    s16 delta;

    delta = sprite->sDistance + sprite->sSlideIncrement;
    sprite->pos1.x -= delta >> 8;
    sprite->sDistance += sprite->sSlideIncrement;
    sprite->sDistance &= 0xFF;
    for (i = 0; i < 3; i++)
    {
        struct Sprite *sprite2 = &gSprites[sprite->data[i]];
        sprite2->pos1.x = sprite->pos1.x + sprite->pos2.x + (i + 1) * 64;
    }

    if (sprite->pos1.x + sprite->pos2.x < -224)
        EndTextBoxSlideOut(sprite);
}

static void ShowLinkResultsTextBox(const u8 *text)
{
    int i;
    u16 x;
    struct Sprite *sprite;

    x = DrawResultsTextWindow(text, sContestResults->data->linkTextBoxSpriteId);
    sprite = &gSprites[sContestResults->data->linkTextBoxSpriteId];
    sprite->pos1.x = x + 32;
    sprite->pos1.y = 80;
    sprite->invisible = FALSE;
    for (i = 0; i < 3; i++)
    {
        gSprites[sprite->data[i]].pos1.x = sprite->pos1.x + sprite->pos2.x + (i + 1) * 64;
        gSprites[sprite->data[i]].pos1.y = sprite->pos1.y;
        gSprites[sprite->data[i]].invisible = FALSE;
    }

    gBattle_WIN0H = 0x00F0;
    gBattle_WIN0V = ((sprite->pos1.y - 16) << 8) | (sprite->pos1.y + 16);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR
        | WININ_WIN0_BG1 | WININ_WIN0_BG2 | WININ_WIN0_BG3 | WININ_WIN0_OBJ | WININ_WIN0_CLR);
}

static void HideLinkResultsTextBox(void)
{
    int i;
    struct Sprite *sprite;

    sprite = &gSprites[sContestResults->data->linkTextBoxSpriteId];
    sprite->invisible = TRUE;
    for (i = 0; i < 3; i++)
        gSprites[sprite->data[i]].invisible = TRUE;

    gBattle_WIN0H = 0;
    gBattle_WIN0V = 0;
    SetGpuReg(REG_OFFSET_WIN0H, gBattle_WIN0H);
    SetGpuReg(REG_OFFSET_WIN0V, gBattle_WIN0V);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN0_CLR
        | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ | WININ_WIN1_CLR);
}

static void LoadContestResultsTilemaps(void)
{
    u8 palette;
    int x, y;

    x = 5;
    y = 1;
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        CopyToBgTilemapBufferRect(2, gLinkContestResults_Tilemap, 5, 1, 5, 2);
        x = 10;
    }
    else if (gSpecialVar_ContestRank == CONTEST_RANK_NORMAL)
    {
        CopyToBgTilemapBufferRect(2, gNormalContestResults_Tilemap, 5, 1, 10, 2);
        x = 15;
    }
    else if (gSpecialVar_ContestRank == CONTEST_RANK_SUPER)
    {
        CopyToBgTilemapBufferRect(2, gSuperContestResults_Tilemap, 5, 1, 10, 2);
        x = 15;
    }
    else if (gSpecialVar_ContestRank == CONTEST_RANK_HYPER)
    {
        CopyToBgTilemapBufferRect(2, gHyperContestResults_Tilemap, 5, 1, 10, 2);
        x = 15;
    }
    else // CONTEST_RANK_MASTER
    {
        CopyToBgTilemapBufferRect(2, gMasterContestResults_Tilemap, 5, 1, 10, 2);
        x = 15;
    }

    if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_COOL)
    {
        palette = 0;
        CopyToBgTilemapBufferRect(2, gCoolContestResults_Tilemap, x, y, 5, 2);
    }
    else if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_BEAUTY)
    {
        palette = 1;
        CopyToBgTilemapBufferRect(2, gBeautyContestResults_Tilemap, x, y, 5, 2);
    }
    else if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_CUTE)
    {
        palette = 2;
        CopyToBgTilemapBufferRect(2, gCuteContestResults_Tilemap, x, y, 5, 2);
    }
    else if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_SMART)
    {
        palette = 3;
        CopyToBgTilemapBufferRect(2, gSmartContestResults_Tilemap, x, y, 5, 2);
    }
    else // CONTEST_CATEGORY_TOUGH
    {
        palette = 4;
        CopyToBgTilemapBufferRect(2, gToughContestResults_Tilemap, x, y, 5, 2);
    }

    x += 5;
    CopyToBgTilemapBufferRect(2, gContestResults_Tilemap, x, y, 6, 2);
    CopyToBgTilemapBufferRect_ChangePalette(2, sContestResults->tilemapBuffers[2], 0, 0, 32, 4, palette);
}

// Represented on results board as stars
static u8 GetNumPreliminaryPoints(u8 monIndex, bool8 capPoints)
{
    u32 condition = gContestMonConditions[monIndex] << 16;
    u32 numStars = condition / 0x3F;

    if (numStars & 0xFFFF)
        numStars += 0x10000;

    numStars >>= 16;
    if (numStars == 0 && condition)
        numStars = 1;

    if (capPoints && numStars > 10)
        numStars = 10;

    return numStars;
}

// Represented on results board as hearts
static s8 GetNumRound2Points(u8 monIndex, bool8 capPoints)
{
    u32 r4, numHearts;
    s16 results;
    s8 points;

    results = gContestMonRound2Points[monIndex];
    if (results < 0)
        r4 = -results << 16;
    else
        r4 = results << 16;

    numHearts = r4 / 80;
    if (numHearts & 0xFFFF)
        numHearts += 0x10000;

    numHearts >>= 16;
    if (numHearts == 0 && r4 != 0)
        numHearts = 1;

    if (capPoints && numHearts > 10)
        numHearts = 10;

    if (gContestMonRound2Points[monIndex] < 0)
        points = -numHearts;
    else
        points = numHearts;

    return points;
}

#define tState         data[10]

static void Task_DrawFinalStandingNumber(u8 taskId)
{
    u16 firstTileNum;

    if (gTasks[taskId].tState == 0)
    {
        gTasks[taskId].data[11] = (3 - gTasks[taskId].tFinalStanding) * 40;
        gTasks[taskId].tState++;
    }
    else if (gTasks[taskId].tState == 1)
    {
        if (--gTasks[taskId].data[11] == -1)
        {
            firstTileNum = gTasks[taskId].tFinalStanding * 2 + 0x5043;
            WriteSequenceToBgTilemapBuffer(2, firstTileNum, 1, gTasks[taskId].tMonIndex * 3 + 5, 2, 1, 17, 1);
            WriteSequenceToBgTilemapBuffer(2, firstTileNum + 0x10, 1, gTasks[taskId].tMonIndex * 3 + 6, 2, 1, 17, 1);
            sContestResults->data->numStandingsPrinted++;
            DestroyTask(taskId);
            PlaySE(SE_JYUNI);
        }
    }
}

#undef tFinalStanding
#undef tMonIndex
#undef tState

static void Task_StartHighlightWinnersBox(u8 taskId)
{
    int i;
    GET_CONTEST_WINNER_ID(i);
    CopyToBgTilemapBufferRect_ChangePalette(2, i * 0xC0 + 0x100 + sContestResults->tilemapBuffers[2], 0, i * 3 + 4, 32, 3, 9);
    gTasks[taskId].data[10] = i;
    gTasks[taskId].data[12] = 1;
    gTasks[taskId].func = Task_HighlightWinnersBox;
    sContestResults->data->highlightWinnerTaskId = taskId;
}

static void Task_HighlightWinnersBox(u8 taskId)
{
    if (++gTasks[taskId].data[11] == 1)
    {
        gTasks[taskId].data[11] = 0;
        BlendPalette(0x91, 1, gTasks[taskId].data[12], RGB(13, 28, 27));
        if (gTasks[taskId].data[13] == 0)
        {
            if (++gTasks[taskId].data[12] == 16)
                gTasks[taskId].data[13] = 1;
        }
        else
        {
            if (--gTasks[taskId].data[12] == 0)
                gTasks[taskId].data[13] = 0;
        }
    }
}

static void SpriteCB_WinnerMonSlideIn(struct Sprite *sprite)
{
    if (sprite->data[0] < 10)
    {
        if (++sprite->data[0] == 10)
        {
            PlayCry1(sprite->data[1], 0);
            sprite->data[1] = 0;
        }
    }
    else
    {
        s16 delta = sprite->data[1] + 0x600;
        sprite->pos1.x -= delta >> 8;
        sprite->data[1] += 0x600;
        sprite->data[1] &= 0xFF;
        if (sprite->pos1.x < 120)
            sprite->pos1.x = 120;

        if (sprite->pos1.x == 120)
        {
            sprite->callback = SpriteCallbackDummy;
            sprite->data[1] = 0;
            sContestResults->data->winnerMonSlidingState = SLIDING_MON_ENTERED;
        }
    }
}

static void SpriteCB_WinnerMonSlideOut(struct Sprite *sprite)
{
    s16 delta = sprite->data[1] + 0x600;
    sprite->pos1.x -= delta >> 8;
    sprite->data[1] += + 0x600;
    sprite->data[1] &= 0xFF;
    if (sprite->pos1.x < -32)
    {
        sprite->callback = SpriteCallbackDummy;
        sprite->invisible = TRUE;
        sContestResults->data->winnerMonSlidingState = SLIDING_MON_EXITED;
    }
}

static void Task_CreateConfetti(u8 taskId)
{
    if (++gTasks[taskId].data[0] == 5)
    {
        gTasks[taskId].data[0] = 0;
        if (sContestResults->data->confettiCount < 40)
        {
            u8 spriteId = CreateSprite(&sSpriteTemplate_Confetti, (Random() % 240) - 20, 44, 5);
            gSprites[spriteId].data[0] = Random() % 512;
            gSprites[spriteId].data[1] = (Random() % 24) + 16;
            gSprites[spriteId].data[2] = (Random() % 256) + 48;
            gSprites[spriteId].oam.tileNum += Random() % 17;
            sContestResults->data->confettiCount++;
        }
    }

    if (sContestResults->data->destroyConfetti)
        DestroyTask(taskId);
}

static void SpriteCB_Confetti(struct Sprite *sprite)
{
    s16 delta;

    sprite->data[3] += sprite->data[0];
    sprite->pos2.x = Sin(sprite->data[3] >> 8, sprite->data[1]);
    delta = sprite->data[4] + sprite->data[2];
    sprite->pos1.x += delta >> 8;
    sprite->data[4] += sprite->data[2];
    sprite->data[4] &= 0xff;

    sprite->pos1.y++;
    if (sContestResults->data->destroyConfetti)
        sprite->invisible = TRUE;

    if (sprite->pos1.x > 248 || sprite->pos1.y > 116)
    {
        DestroySprite(sprite);
        sContestResults->data->confettiCount--;
    }
}

#define tMonIndex  data[0]
#define tNumFrames data[1]
#define tSpecies   data[2]
#define tTimer     data[10]
#define tBounced   data[11]

static void BounceMonIconInBox(u8 monIndex, u8 numFrames)
{
    u8 taskId = CreateTask(Task_BounceMonIconInBox, 8);
    gTasks[taskId].tMonIndex = monIndex;
    gTasks[taskId].tNumFrames = numFrames;
    gTasks[taskId].tSpecies = gContestMons[monIndex].species;
}

static void Task_BounceMonIconInBox(u8 taskId)
{
    u8 monIndex = gTasks[taskId].tMonIndex;
    if (gTasks[taskId].tTimer++ == gTasks[taskId].tNumFrames)
    {
        gTasks[taskId].tTimer = 0;
        LoadContestMonIcon(gTasks[taskId].tSpecies, monIndex, gTasks[taskId].tBounced, FALSE, gContestMons[monIndex].personality);
        gTasks[taskId].tBounced ^= 1;
    }
}

#undef tMonIndex
#undef tNumFrames
#undef tSpecies
#undef tTimer
#undef tBounced

static void CalculateContestantsResultData(void)
{
    int i, relativePoints;
    u32 barLength;
    s16 highestPoints;
    s8 round2Points;

    highestPoints = gContestMonTotalPoints[0];
    for (i = 1; i < CONTESTANT_COUNT; i++)
    {
        if (highestPoints < gContestMonTotalPoints[i])
            highestPoints = gContestMonTotalPoints[i];
    }

    if (highestPoints < 0)
    {
        highestPoints = gContestMonTotalPoints[0];
        for (i = 1; i < CONTESTANT_COUNT; i++)
        {
            if (highestPoints > gContestMonTotalPoints[i])
                highestPoints = gContestMonTotalPoints[i];
        }
    }

    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        relativePoints = (gContestMonConditions[i] * 1000) / abs(highestPoints);
        if (relativePoints % 10 > 4)
            relativePoints += 10;
        (*sContestResults->monResults)[i].relativePreliminaryPoints = relativePoints / 10;

        relativePoints = (abs(gContestMonRound2Points[i]) * 1000) / abs(highestPoints);
        if (relativePoints % 10 > 4)
            relativePoints += 10;
        (*sContestResults->monResults)[i].relativeRound2Points = relativePoints / 10;

        if (gContestMonRound2Points[i] < 0)
            (*sContestResults->monResults)[i].lostPoints = TRUE;

        barLength = ((*sContestResults->monResults)[i].relativePreliminaryPoints * 0x5800) / 100;
        if ((barLength & 0xFF) > 0x7F)
            barLength += 0x100;
        (*sContestResults->monResults)[i].barLengthPreliminary = barLength >> 8;

        barLength = ((*sContestResults->monResults)[i].relativeRound2Points * 0x5800) / 100;
        if ((barLength & 0xFF) > 0x7F)
            barLength += 0x100;
        (*sContestResults->monResults)[i].barLengthRound2 = barLength >> 8;

        (*sContestResults->monResults)[i].numStars = GetNumPreliminaryPoints(i, TRUE);
        round2Points = GetNumRound2Points(i, TRUE);
        (*sContestResults->monResults)[i].numHearts = abs(round2Points);

        if (gContestFinalStandings[i])
        {
            s16 barLengthPreliminary = (*sContestResults->monResults)[i].barLengthPreliminary;
            s16 barLengthRound2 = (*sContestResults->monResults)[i].barLengthRound2;

            if ((*sContestResults->monResults)[i].lostPoints)
                barLengthRound2 *= -1;

            if (barLengthPreliminary + barLengthRound2 == MAX_BAR_LENGTH + 1)
            {
                if (barLengthRound2 > 0)
                    (*sContestResults->monResults)[i].barLengthRound2--;
                else if (barLengthPreliminary > 0)
                    (*sContestResults->monResults)[i].barLengthPreliminary--;
            }
        }
    }
}

#define tMonId      data[0]
#define tTarget     data[1]
#define tDecreasing data[2]

static void UpdateContestResultBars(bool8 isRound2, u8 numUpdates)
{
    int i, taskId;
    u32 target;
    u8 numIncreasing = 0, numDecreasing = 0;

    if (!isRound2)
    {
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            u8 numStars = (*sContestResults->monResults)[i].numStars;
            if (numUpdates < numStars)
            {
                FillBgTilemapBufferRect_Palette0(1, 0x60B3, ((19 + numStars) - numUpdates) - 1, i * 3 + 5, 1, 1);
                taskId = CreateTask(Task_UpdateContestResultBar, 10);

                target = (((*sContestResults->monResults)[i].barLengthPreliminary << 16) / (*sContestResults->monResults)[i].numStars) * (numUpdates + 1);
                if ((target & 0xFFFF) > 0x7FFF)
                    target += 0x10000;

                gTasks[taskId].tMonId = i;
                gTasks[taskId].tTarget = target >> 16;
                sContestResults->data->numBarsUpdating++;
                numIncreasing++;
            }
        }
    }
    else
    {
        for (i = 0; i < CONTESTANT_COUNT; i++)
        {
            s8 numHearts = (*sContestResults->monResults)[i].numHearts;
            u32 tile = (*sContestResults->monResults)[i].lostPoints ? 0x60A5 : 0x60A3;
            if (numUpdates < numHearts)
            {
                FillBgTilemapBufferRect_Palette0(1, tile, ((19 + numHearts) - numUpdates) - 1, i * 3 + 6, 1, 1);
                taskId = CreateTask(Task_UpdateContestResultBar, 10);

                target = (((*sContestResults->monResults)[i].barLengthRound2 << 16) / (*sContestResults->monResults)[i].numHearts) * (numUpdates + 1);
                if ((target & 0xFFFF) > 0x7FFF)
                    target += 0x10000;

                gTasks[taskId].tMonId = i;
                if ((*sContestResults->monResults)[i].lostPoints)
                {
                    gTasks[taskId].tDecreasing = TRUE;
                    numDecreasing++;
                }
                else
                {
                    numIncreasing++;
                }

                if ((*sContestResults->monResults)[i].lostPoints)
                    gTasks[taskId].tTarget = -(target >> 16) + (*sContestResults->monResults)[i].barLengthPreliminary;
                else
                    gTasks[taskId].tTarget = (target >> 16) + (*sContestResults->monResults)[i].barLengthPreliminary;

                sContestResults->data->numBarsUpdating++;
            }
        }
    }

    if (numDecreasing)
        PlaySE(SE_BOO);
    if (numIncreasing)
        PlaySE(SE_PIN);
}

static void Task_UpdateContestResultBar(u8 taskId)
{
    int i;
    bool32 minMaxReached = FALSE;
    bool32 targetReached = FALSE;
    u8 monId = gTasks[taskId].tMonId;
    s16 target = gTasks[taskId].tTarget;
    s16 decreasing = gTasks[taskId].tDecreasing;

    if (decreasing)
    {
        if (sContestResults->data->unkC[monId] <= 0)
            minMaxReached = TRUE;
    }
    else
    {
        if (sContestResults->data->unkC[monId] > MAX_BAR_LENGTH)
            minMaxReached = TRUE;
    }

    if (sContestResults->data->unkC[monId] == target)
        targetReached = TRUE;

    if (!targetReached)
    {
        if (minMaxReached)
            sContestResults->data->unkC[monId] = target;
        else if (decreasing)
            sContestResults->data->unkC[monId] = sContestResults->data->unkC[monId] - 1;
        else
            sContestResults->data->unkC[monId] = sContestResults->data->unkC[monId] + 1;
    }

    if (!minMaxReached && !targetReached)
    {
        u8 var0;
        u16 tileNum;
        for (i = 0; i < 11; i++)
        {
            if (sContestResults->data->unkC[monId] >= (i + 1) * 8)
                var0 = 8;
            else if (sContestResults->data->unkC[monId] >= i * 8)
                var0 = sContestResults->data->unkC[monId] % 8;
            else
                var0 = 0;

            if (var0 < 4)
                tileNum = 0x504C + var0;
            else
                tileNum = 0x5057 + var0;

            FillBgTilemapBufferRect_Palette0(2, tileNum, i + 7, monId * 3 + 6, 1, 1);
        }
    }

    if (targetReached)
    {
        sContestResults->data->numBarsUpdating--;
        DestroyTask(taskId);
    }
}

#undef tMonId
#undef tTarget
#undef tDecreasing

static void AllocContestResults(void)
{
    sContestResults = AllocZeroed(sizeof(*sContestResults));
    sContestResults->data = AllocZeroed(sizeof(*sContestResults->data));
    sContestResults->monResults = AllocZeroed(sizeof(*sContestResults->monResults));
    sContestResults->unusedBg = AllocZeroed(BG_SCREEN_SIZE);
    sContestResults->tilemapBuffers[0] = AllocZeroed(BG_SCREEN_SIZE);
    sContestResults->tilemapBuffers[1] = AllocZeroed(BG_SCREEN_SIZE);
    sContestResults->tilemapBuffers[2] = AllocZeroed(BG_SCREEN_SIZE);
    sContestResults->tilemapBuffers[3] = AllocZeroed(BG_SCREEN_SIZE);
    sContestResults->unused = AllocZeroed(0x1000);
    AllocateMonSpritesGfx();
}

static void FreeContestResults(void)
{
    FREE_AND_SET_NULL(sContestResults->data);
    FREE_AND_SET_NULL(sContestResults->monResults);
    FREE_AND_SET_NULL(sContestResults->unusedBg);
    FREE_AND_SET_NULL(sContestResults->tilemapBuffers[0]);
    FREE_AND_SET_NULL(sContestResults->tilemapBuffers[1]);
    FREE_AND_SET_NULL(sContestResults->tilemapBuffers[2]);
    FREE_AND_SET_NULL(sContestResults->tilemapBuffers[3]);
    FREE_AND_SET_NULL(sContestResults->unused);
    FREE_AND_SET_NULL(sContestResults);
    FreeMonSpritesGfx();
}

static void AddContestTextPrinter(int windowId, u8 *str, int x)
{
    struct TextPrinterTemplate textPrinter;
    textPrinter.currentChar = str;
    textPrinter.windowId = windowId;
    textPrinter.fontId = 7;
    textPrinter.x = x;
    textPrinter.y = 2;
    textPrinter.currentX = x;
    textPrinter.currentY = 2;
    textPrinter.letterSpacing = 0;
    textPrinter.lineSpacing = 0;
    textPrinter.unk = 0;
    textPrinter.fgColor = 1;
    textPrinter.bgColor = 0;
    textPrinter.shadowColor = 8;
    AddTextPrinter(&textPrinter, 0, NULL);
    PutWindowTilemap(windowId);
}

void TryEnterContestMon(void)
{
    u8 eligibility = GetContestEntryEligibility(&gPlayerParty[gContestMonPartyIndex]);

    // Nonzero eligibility can still be non-eligibile, if mon is fainted or egg
    if (eligibility)
    {
        sub_80DAB8C(gSpecialVar_ContestCategory, gSpecialVar_ContestRank);
        sub_80DB09C(gSpecialVar_ContestCategory);
    }

    gSpecialVar_Result = eligibility;
}

u16 HasMonWonThisContestBefore(void)
{
    u16 hasRankRibbon = FALSE;
    struct Pokemon *mon = &gPlayerParty[gContestMonPartyIndex];
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        if (GetMonData(mon, MON_DATA_COOL_RIBBON) > gSpecialVar_ContestRank)
            hasRankRibbon = TRUE;
        break;
    case CONTEST_CATEGORY_BEAUTY:
        if (GetMonData(mon, MON_DATA_BEAUTY_RIBBON) > gSpecialVar_ContestRank)
            hasRankRibbon = TRUE;
        break;
    case CONTEST_CATEGORY_CUTE:
        if (GetMonData(mon, MON_DATA_CUTE_RIBBON) > gSpecialVar_ContestRank)
            hasRankRibbon = TRUE;
        break;
    case CONTEST_CATEGORY_SMART:
        if (GetMonData(mon, MON_DATA_SMART_RIBBON) > gSpecialVar_ContestRank)
            hasRankRibbon = TRUE;
        break;
    case CONTEST_CATEGORY_TOUGH:
        if (GetMonData(mon, MON_DATA_TOUGH_RIBBON) > gSpecialVar_ContestRank)
            hasRankRibbon = TRUE;
        break;
    }

    return hasRankRibbon;
}

void GiveMonContestRibbon(void)
{
    u8 ribbonData;

    if (gContestFinalStandings[gContestPlayerMonIndex] != 0)
        return;

    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        ribbonData = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_COOL_RIBBON);
        if (ribbonData <= gSpecialVar_ContestRank && ribbonData < 4)
        {
            ribbonData++;
            SetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_COOL_RIBBON, &ribbonData);
            if (GetRibbonCount(&gPlayerParty[gContestMonPartyIndex]) > NUM_CUTIES_RIBBONS)
                TryPutSpotTheCutiesOnAir(&gPlayerParty[gContestMonPartyIndex], MON_DATA_COOL_RIBBON);
        }
        break;
    case CONTEST_CATEGORY_BEAUTY:
        ribbonData = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_BEAUTY_RIBBON);
        if (ribbonData <= gSpecialVar_ContestRank && ribbonData < 4)
        {
            ribbonData++;
            SetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_BEAUTY_RIBBON, &ribbonData);
            if (GetRibbonCount(&gPlayerParty[gContestMonPartyIndex]) > NUM_CUTIES_RIBBONS)
                TryPutSpotTheCutiesOnAir(&gPlayerParty[gContestMonPartyIndex], MON_DATA_BEAUTY_RIBBON);
        }
        break;
    case CONTEST_CATEGORY_CUTE:
        ribbonData = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_CUTE_RIBBON);
        if (ribbonData <= gSpecialVar_ContestRank && ribbonData < 4)
        {
            ribbonData++;
            SetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_CUTE_RIBBON, &ribbonData);
            if (GetRibbonCount(&gPlayerParty[gContestMonPartyIndex]) > NUM_CUTIES_RIBBONS)
                TryPutSpotTheCutiesOnAir(&gPlayerParty[gContestMonPartyIndex], MON_DATA_CUTE_RIBBON);
        }
        break;
    case CONTEST_CATEGORY_SMART:
        ribbonData = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_SMART_RIBBON);
        if (ribbonData <= gSpecialVar_ContestRank && ribbonData < 4)
        {
            ribbonData++;
            SetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_SMART_RIBBON, &ribbonData);
            if (GetRibbonCount(&gPlayerParty[gContestMonPartyIndex]) > NUM_CUTIES_RIBBONS)
                TryPutSpotTheCutiesOnAir(&gPlayerParty[gContestMonPartyIndex], MON_DATA_SMART_RIBBON);
        }
        break;
    case CONTEST_CATEGORY_TOUGH:
        ribbonData = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_TOUGH_RIBBON);
        if (ribbonData <= gSpecialVar_ContestRank && ribbonData < 4)
        {
            ribbonData++;
            SetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_TOUGH_RIBBON, &ribbonData);
            if (GetRibbonCount(&gPlayerParty[gContestMonPartyIndex]) > NUM_CUTIES_RIBBONS)
                TryPutSpotTheCutiesOnAir(&gPlayerParty[gContestMonPartyIndex], MON_DATA_TOUGH_RIBBON);
        }
        break;
    }
}

void BufferContestantTrainerName(void)
{
    StringCopy(gStringVar1, gContestMons[gSpecialVar_0x8006].trainerName);
    sub_81DB5AC(gStringVar1);
}

void BufferContestantMonNickname(void)
{
    StringCopy(gStringVar3, gContestMons[gSpecialVar_0x8006].nickname);
}

// Unused script special
void GetContestMonConditionRanking(void)
{
    u8 i, rank;

    for (i = 0, rank = 0; i < CONTESTANT_COUNT; i++)
    {
        if (gContestMonConditions[gSpecialVar_0x8006] < gContestMonConditions[i])
            rank++;
    }

    gSpecialVar_0x8004 = rank;
}

void GetContestMonCondition(void)
{
    gSpecialVar_0x8004 = gContestMonConditions[gSpecialVar_0x8006];
}

void GetContestWinnerId(void)
{
    u8 i;
    GET_CONTEST_WINNER_ID(i);
    gSpecialVar_0x8005 = i;
}

void BufferContestWinnerTrainerName(void)
{
    u8 i;
    GET_CONTEST_WINNER_ID(i);
    StringCopy(gStringVar3, gContestMons[i].trainerName);
    sub_81DB5AC(gStringVar3);
}

void BufferContestWinnerMonName(void)
{
    u8 i;
    GET_CONTEST_WINNER_ID(i);
    StringCopy(gStringVar1, gContestMons[i].nickname);
}

void CB2_SetStartContestCallback(void)
{
    SetMainCallback2(CB2_StartContest);
}

static void Task_StartContest(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2(CB2_SetStartContestCallback);
    }
}

void StartContest(void)
{
    ScriptContext2_Enable();
    CreateTask(Task_StartContest, 10);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
}

void BufferContestantMonSpecies(void)
{
    gSpecialVar_0x8004 = gContestMons[gSpecialVar_0x8006].species;
}

static void Task_StartShowContestResults(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2(CB2_StartShowContestResults);
    }
}

void ShowContestResults(void)
{
    ScriptContext2_Enable();
    CreateTask(Task_StartShowContestResults, 10);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
}

void GetContestPlayerId(void)
{
    gSpecialVar_0x8004 = gContestPlayerMonIndex;
}

void ContestLinkTransfer(u8 taskId)
{
    u8 newTaskId;
    ScriptContext2_Enable();
    newTaskId = CreateTask(sub_80FC580, 0);
    SetTaskFuncWithFollowupFunc(newTaskId, sub_80FC580, sub_80F8508);
    gTasks[newTaskId].data[9] = taskId;
}

static void sub_80F8508(u8 taskId)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER)
    {
        sub_80DA8C8(gContestMonPartyIndex);
        SetTaskFuncWithFollowupFunc(taskId, sub_80FC6BC, sub_80F8568);
    }
    else
    {
        sub_80DA8C8(gContestMonPartyIndex);
        gTasks[taskId].func = sub_81D9DE4;
    }
}

static void sub_80F8568(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_80FC804, sub_80F8584);
}

static void sub_80F8584(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_80FCE48, sub_80F85A0);
}

static void sub_80F85A0(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, sub_80FC894, sub_80F85BC);
}

static void sub_80F85BC(u8 taskId)
{
    u8 i;
    u8 sp0[4];
    u8 sp4[4];

    memset(sp0, 0, sizeof(sp0));
    memset(sp4, 0, sizeof(sp4));

    for (i = 0; i < gNumLinkContestPlayers; i++)
        sp0[i] = gTasks[taskId].data[i + 1];

    for (i = 0; i < gNumLinkContestPlayers;)
    {
        i++;
        if (i >= gNumLinkContestPlayers || sp0[0] != sp0[i])
            break;
    }

    if (i == gNumLinkContestPlayers)
        gSpecialVar_0x8004 = 0;
    else
        gSpecialVar_0x8004 = 1;

    for (i = 0; i < gNumLinkContestPlayers; i++)
        sp4[i] = gTasks[taskId].data[i + 5];

    gUnknown_02039F2B = sub_80F86E0(sp4);
    sub_80DB09C(gSpecialVar_ContestCategory);
    SetTaskFuncWithFollowupFunc(taskId, sub_80FCF40, sub_80F86B8);
}

static void sub_80F86B8(u8 taskId)
{
    SortContestants(FALSE);
    SetTaskFuncWithFollowupFunc(taskId, sub_80FCFD0, sub_80F8714);
}

u8 sub_80F86E0(u8 *arg0)
{
    int i;
    u8 result = 0;

    for (i = 1; i < gNumLinkContestPlayers; i++)
    {
        if (arg0[result] < arg0[i])
            result = i;
    }

    return result;
}

void sub_80F8714(u8 taskId)
{
    int i;

    if (gSpecialVar_0x8004 == 1)
    {
        if (IsLinkTaskFinished())
            gTasks[taskId].func = sub_80F878C;
    }
    else
    {
        for (i = 0; i < CONTESTANT_COUNT; i++)
            StringGetEnd10(gContestMons[i].nickname);

        DestroyTask(taskId);
        SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
        ScriptContext2_Disable();
        EnableBothScriptContexts();
    }
}

static void sub_80F878C(u8 taskId)
{
    sub_800AC34();
    gTasks[taskId].func = sub_80F87B4;
}

static void sub_80F87B4(u8 taskId)
{
    if (!gReceivedRemoteLinkPlayers)
    {
        DestroyTask(taskId);
        ScriptContext2_Disable();
        EnableBothScriptContexts();
    }
}
