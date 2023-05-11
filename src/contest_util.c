#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_gfx_sfx_util.h"
#include "bg.h"
#include "contest.h"
#include "contest_util.h"
#include "contest_link.h"
#include "contest_painting.h"
#include "data.h"
#include "decompress.h"
#include "dma3.h"
#include "event_data.h"
#include "event_object_movement.h"
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
#include "script_menu.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trig.h"
#include "tv.h"
#include "util.h"
#include "window.h"
#include "constants/event_objects.h"
#include "constants/field_specials.h"
#include "constants/game_stat.h"
#include "constants/rgb.h"
#include "constants/songs.h"
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

// Gfx/pal tags for the text window sprites on the contest results screen.
// Both types of text windows are made up of 4 individual sprites
// These tags are used by the spritesheets, and implicitly in the loop in CreateResultsTextWindowSprites
#define TAG_TEXT_WINDOW_BASE 3009
enum {
    TAG_RESULTS_TEXT_WINDOW_LEFT = TAG_TEXT_WINDOW_BASE,
    TAG_RESULTS_TEXT_WINDOW_MIDLEFT,
    TAG_RESULTS_TEXT_WINDOW_MIDRIGHT,
    TAG_RESULTS_TEXT_WINDOW_RIGHT,
    TAG_LINK_TEXT_WINDOW_LEFT,
    TAG_LINK_TEXT_WINDOW_MIDLEFT,
    TAG_LINK_TEXT_WINDOW_MIDRIGHT,
    TAG_LINK_TEXT_WINDOW_RIGHT, // 3016
};
#define TAG_CONFETTI 3017
#define TAG_WIRELESS_INDICATOR_WINDOW 22222

// Length of the score bar on the results screen
#define NUM_BAR_SEGMENTS 11
#define BAR_SEGMENT_LENGTH 8 // Each segment of the results bar is a single tile, so 8 pixels long
#define MAX_BAR_LENGTH (NUM_BAR_SEGMENTS * BAR_SEGMENT_LENGTH)

// Starting x/y for the sliding results screen text box
#define TEXT_BOX_X (DISPLAY_WIDTH + 32)
#define TEXT_BOX_Y (DISPLAY_HEIGHT - 16)

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
    s16 barLength[CONTESTANT_COUNT];
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
static void LoadContestResultsTitleBarTilemaps(void);
static u8 GetNumPreliminaryPoints(u8, bool8);
static s8 GetNumRound2Points(u8, bool8);
static void AddContestTextPrinter(int, u8 *, int);
static void AllocContestResults(void);
static void FreeContestResults(void);
static void LoadAllContestMonIcons(u8, u8);
static void CreateResultsTextWindowSprites(void);
static void TryCreateWirelessSprites(void);
static void Task_StartShowContestResults(u8 taskId);
static void CB2_StartShowContestResults(void);
static void Task_ShowContestResults(u8);
static void CB2_ShowContestResults(void);
static void VBlankCB_ShowContestResults(void);
static void Task_SlideContestResultsBg(u8);
static void Task_WaitForLinkPartnersBeforeResults(u8);
static void Task_CommunicateMonIdxsForResults(u8);
static void Task_WaitForLinkPartnerMonIdxs(u8);
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
static void Task_StartCommunication(u8);
static void Task_StartCommunicateRngRS(u8);
static void Task_StartCommunicateLeaderIdsRS(u8);
static void Task_StartCommunicateCategoryRS(u8);
static void Task_LinkContest_SetUpContestRS(u8);
static void Task_LinkContest_CalculateTurnOrderRS(u8);
static void Task_LinkContest_Disconnect(u8);
static void Task_LinkContest_WaitDisconnect(u8);
static void SpriteCB_Confetti(struct Sprite *sprite);
static void Task_ShowContestEntryMonPic(u8 taskId);
static void Task_LinkContestWaitForConnection(u8 taskId);

static const u16 sResultsTextWindow_Pal[] = INCBIN_U16("graphics/contest/results_screen/text_window.gbapal");
static const u8 sResultsTextWindow_Gfx[] = INCBIN_U8("graphics/contest/results_screen/text_window.4bpp");
static const u16 sMiscBlank_Pal[] = INCBIN_U16("graphics/interface/blank.gbapal");

static const struct OamData sOamData_ResultsTextWindow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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

static const struct SpriteTemplate sSpriteTemplate_ResultsTextWindow =
{
    .tileTag = TAG_TEXT_WINDOW_BASE,
    .paletteTag = TAG_TEXT_WINDOW_BASE,
    .oam = &sOamData_ResultsTextWindow,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet sSpriteSheets_ResultsTextWindow[] =
{
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_RESULTS_TEXT_WINDOW_LEFT },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_RESULTS_TEXT_WINDOW_MIDLEFT },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_RESULTS_TEXT_WINDOW_MIDRIGHT },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_RESULTS_TEXT_WINDOW_RIGHT },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_LINK_TEXT_WINDOW_LEFT },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_LINK_TEXT_WINDOW_MIDLEFT },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_LINK_TEXT_WINDOW_MIDRIGHT },
    { .data = gMiscBlank_Gfx, .size = 0x400, .tag = TAG_LINK_TEXT_WINDOW_RIGHT },
};

static const struct SpritePalette sSpritePalette_ResultsTextWindow =
{
     .data = sMiscBlank_Pal,
     .tag = TAG_TEXT_WINDOW_BASE,
};

static const struct OamData sOamData_Confetti =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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

// Window IDs are implicitly shared with contestant IDs in LoadContestMonName
static const struct WindowTemplate sWindowTemplates[CONTESTANT_COUNT + 1] =
{
    { // Contestant 1
        .bg = 1,
        .tilemapLeft = 7,
        .tilemapTop = 4,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 770
    },
    { // Contestant 2
        .bg = 1,
        .tilemapLeft = 7,
        .tilemapTop = 7,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 794
    },
    { // Contestant 3
        .bg = 1,
        .tilemapLeft = 7,
        .tilemapTop = 10,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 818
    },
    { // Contestant 4
        .bg = 1,
        .tilemapLeft = 7,
        .tilemapTop = 13,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 842
    },
    DUMMY_WIN_TEMPLATE
};

static const struct OamData sOamData_WirelessIndicatorWindow =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
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


static const struct SpriteTemplate sSpriteTemplate_WirelessIndicatorWindow =
{
    .tileTag = TAG_WIRELESS_INDICATOR_WINDOW,
    .paletteTag = 0,
    .oam = &sOamData_WirelessIndicatorWindow,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteSheet sSpriteSheet_WirelessIndicatorWindow =
{
    .data = gMiscBlank_Gfx,
    .size = 0x200,
    .tag = TAG_WIRELESS_INDICATOR_WINDOW
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
    CopyToBgTilemapBuffer(3, gContestResults_Bg_Tilemap, 0, 0);
    CopyToBgTilemapBuffer(2, gContestResults_Interface_Tilemap, 0, 0);
    CopyToBgTilemapBuffer(0, gContestResults_WinnerBanner_Tilemap, 0, 0);
    LoadContestResultsTitleBarTilemaps();
    LoadCompressedPalette(gContestResults_Pal, BG_PLTT_ID(0), 16 * PLTT_SIZE_4BPP);
    LoadPalette(sResultsTextWindow_Pal, BG_PLTT_ID(15), sizeof(sResultsTextWindow_Pal));

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
        str = StringCopy(gDisplayedStringBattle, gText_ColorDarkGray);

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
    CreateResultsTextWindowSprites();
    TryCreateWirelessSprites();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gPaletteFade.bufferTransferDisabled = FALSE;
    sContestResults->data->showResultsTaskId = CreateTask(Task_ShowContestResults, 5);
    SetMainCallback2(CB2_ShowContestResults);
    gBattle_WIN1H = WIN_RANGE(0, DISPLAY_WIDTH);
    gBattle_WIN1V = WIN_RANGE(DISPLAY_HEIGHT - 32, DISPLAY_HEIGHT);
    CreateTask(Task_SlideContestResultsBg, 20);
    CalculateContestantsResultData();
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
        gPaletteFade.bufferTransferDisabled = TRUE;
    else
        PlayBGM(MUS_CONTEST_RESULTS);

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
            SaveContestWinner(gSpecialVar_ContestRank); // Save for lobby painting
            SaveContestWinner(CONTEST_SAVE_FOR_ARTIST);
            gCurContestWinnerIsForArtist = TRUE;
            gCurContestWinnerSaveIdx = GetContestWinnerSaveIdx(CONTEST_SAVE_FOR_ARTIST, FALSE);
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
                SetLinkStandbyCallback();
                gTasks[taskId].tState++;
            }
            return;
        case 3:
            if (IsLinkTaskFinished() == TRUE)
            {
                PlayBGM(MUS_CONTEST_RESULTS);
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

            SaveContestWinner(gSpecialVar_ContestRank); // Save for lobby painting
            SaveContestWinner(CONTEST_SAVE_FOR_ARTIST);
            gCurContestWinnerIsForArtist = TRUE;
            gCurContestWinnerSaveIdx = GetContestWinnerSaveIdx(CONTEST_SAVE_FOR_ARTIST, FALSE);
            TryGainNewFanFromCounter(FANCOUNTER_FINISHED_CONTEST);
            gTasks[taskId].func = Task_AnnouncePreliminaryResults;
        }
    }
}

static void Task_WaitForLinkPartnersBeforeResults(u8 taskId)
{
    if (gReceivedRemoteLinkPlayers)
    {
        CreateTask(Task_CommunicateMonIdxsForResults, 0);
        gTasks[taskId].func = TaskDummy;
    }
}

static void Task_CommunicateMonIdxsForResults(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateMonIdxs, Task_WaitForLinkPartnerMonIdxs);
}

static void Task_WaitForLinkPartnerMonIdxs(u8 taskId)
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
        StartTextBoxSlideIn(x, TEXT_BOX_Y, 120, 1088);
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
        StartTextBoxSlideIn(x, TEXT_BOX_Y, -1, 1088);
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
            StartTextBoxSlideIn(x, TEXT_BOX_Y, -1, 1088);
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
            ConvertInternationalContestantName(gStringVar1);
            StringCopy(gStringVar2, gContestMons[i].nickname);
            StringExpandPlaceholders(winnerTextBuffer, gText_ContestantsMonWon);
            x = DrawResultsTextWindow(winnerTextBuffer, sContestResults->data->slidingTextBoxSpriteId);
            StartTextBoxSlideIn(x, TEXT_BOX_Y, -1, 1088);
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
        gBattle_WIN0H = WIN_RANGE(0, DISPLAY_WIDTH);
        gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT / 2);

        GET_CONTEST_WINNER_ID(i);
        species = gContestMons[i].species;
        personality = gContestMons[i].personality;
        otId = gContestMons[i].otId;
        if (i == gContestPlayerMonIndex)
        {
            HandleLoadSpecialPokePic_2(
                &gMonFrontPicTable[species],
                gMonSpritesGfxPtr->sprites.ptr[B_POSITION_OPPONENT_LEFT],
                species,
                personality);
        }
        else
        {
            HandleLoadSpecialPokePic_DontHandleDeoxys(
                &gMonFrontPicTable[species],
                gMonSpritesGfxPtr->sprites.ptr[B_POSITION_OPPONENT_LEFT],
                species,
                personality);
        }

        pokePal = GetMonSpritePalStructFromOtIdPersonality(species, otId, personality);
        LoadCompressedSpritePalette(pokePal);
        SetMultiuseSpriteTemplateToPokemon(species, B_POSITION_OPPONENT_LEFT);
        gMultiuseSpriteTemplate.paletteTag = pokePal->tag;
        spriteId = CreateSprite(&gMultiuseSpriteTemplate, DISPLAY_WIDTH + 32, DISPLAY_HEIGHT / 2, 10);
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
            gBattle_WIN0V = WIN_RANGE(DISPLAY_HEIGHT / 2 - counter, DISPLAY_HEIGHT / 2 + counter);
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
            if (top > DISPLAY_HEIGHT / 2)
                top = DISPLAY_HEIGHT / 2;

            gBattle_WIN0V = WIN_RANGE(top, DISPLAY_HEIGHT - top);
            if (top == DISPLAY_HEIGHT / 2)
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
            SetCloseLinkCallback();
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
            BlendPalettes(PALETTES_BG, 16, RGB_BLACK);
            gTasks[taskId].tTimer++;
        }
        else if (gTasks[taskId].tTimer == 1)
        {
            BlendPalettes(PALETTES_OBJECTS, 16, RGB_BLACK);
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

        BlendPalette(BG_PLTT_ID(6) + 11, 1, gTasks[taskId].tCoeff, RGB(30, 22, 11));
        BlendPalette(BG_PLTT_ID(6) + 8, 1, gTasks[taskId].tCoeff, RGB_WHITE);
        BlendPalette(BG_PLTT_ID(6) + 14, 1, gTasks[taskId].tCoeff, RGB(30, 29, 29));
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
        LoadPalette(gMonIconPalettes[gMonIconPaletteIndices[GetIconSpecies(species, 0)]], BG_PLTT_ID(10 + i), PLTT_SIZE_4BPP);
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
        sheet = LoadSpriteSheet(&sSpriteSheet_WirelessIndicatorWindow);
        RequestDma3Fill(0xFFFFFFFF, (void *)BG_CHAR_ADDR(4) + sheet * 0x20, 0x80, 1);
        spriteId = CreateSprite(&sSpriteTemplate_WirelessIndicatorWindow, 8, 8, 0);
        gSprites[spriteId].oam.objMode = ST_OAM_OBJ_WINDOW;
    }
}

static s32 DrawResultsTextWindow(const u8 *text, u8 spriteId)
{
    u16 windowId;
    int tileWidth;
    int strWidth;
    u8 *spriteTilePtrs[4];
    u8 *dst;

    struct WindowTemplate windowTemplate;
    memset(&windowTemplate, 0, sizeof(windowTemplate));
    windowTemplate.width = DISPLAY_TILE_WIDTH;
    windowTemplate.height = 2;
    windowId = AddWindow(&windowTemplate);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));

    strWidth = GetStringWidth(FONT_NORMAL, text, 0);
    tileWidth = (strWidth + 9) / 8;
    if (tileWidth > DISPLAY_TILE_WIDTH)
        tileWidth = DISPLAY_TILE_WIDTH;

    AddTextPrinterParameterized3(windowId, FONT_NORMAL, (tileWidth * 8 - strWidth) / 2, 1, sContestLinkTextColors, TEXT_SKIP_DRAW, text);
    {
        s32 i;
        struct Sprite *sprite;
        const u8 *src, *windowTilesPtr;
        windowTilesPtr = (u8 *)GetWindowAttribute(windowId, WINDOW_TILE_DATA);
        src = (u8 *)sResultsTextWindow_Gfx;

        sprite = &gSprites[spriteId];
        spriteTilePtrs[0] = (u8 *)(sprite->oam.tileNum * 32 + OBJ_VRAM0);

        for (i = 1; i < (int)ARRAY_COUNT(spriteTilePtrs); i++)
            spriteTilePtrs[i] = (void *)(gSprites[sprite->data[i - 1]].oam.tileNum * 32 + OBJ_VRAM0);

        for (i = 0; i < (int)ARRAY_COUNT(spriteTilePtrs); i++)
            CpuFill32(0, spriteTilePtrs[i], 0x400);

        dst = spriteTilePtrs[0];
        CpuCopy32(src, dst, 0x20);
        CpuCopy32(src + 128, dst + 0x100, 0x20);
        CpuCopy32(src + 128, dst + 0x200, 0x20);
        CpuCopy32(src + 64,  dst + 0x300, 0x20);

        for (i = 0; i < tileWidth; i++)
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
    }
    RemoveWindow(windowId);

    return (DISPLAY_WIDTH - (tileWidth + 2) * 8) / 2;
}

static void CreateResultsTextWindowSprites(void)
{
    int i;
    struct SpriteTemplate template;
    u8 spriteIds[ARRAY_COUNT(sSpriteSheets_ResultsTextWindow)];

    template = sSpriteTemplate_ResultsTextWindow;
    for (i = 0; i < (int)ARRAY_COUNT(sSpriteSheets_ResultsTextWindow); i++)
        LoadSpriteSheet(&sSpriteSheets_ResultsTextWindow[i]);

    LoadSpritePalette(&sSpritePalette_ResultsTextWindow);

    // Create sprites for the two window types, each made up of 4 sprites
    for (i = 0; i < (int)ARRAY_COUNT(sSpriteSheets_ResultsTextWindow); i++)
    {
        spriteIds[i] = CreateSprite(&template, TEXT_BOX_X, TEXT_BOX_Y, 10);
        template.tileTag++;
    }

    // Save sprite ids of the sliding text box onto its leftmost sprite
    gSprites[spriteIds[0]].data[0] = spriteIds[1];
    gSprites[spriteIds[0]].data[1] = spriteIds[2];
    gSprites[spriteIds[0]].data[2] = spriteIds[3];

    // Save sprite ids of the link text box onto its leftmost sprite
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
    sprite->x = TEXT_BOX_X;
    sprite->y = y;
    sprite->x2 = 0;
    sprite->y2 = 0;
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
    sprite->x += sprite->x2;
    sprite->y += sprite->y2;
    sprite->y2 = 0;
    sprite->x2 = 0;
    sprite->sSlideIncrement = slideIncrement;
    sprite->sDistance = 0;
    sprite->callback = SpriteCB_TextBoxSlideOut;
    sContestResults->data->slidingTextBoxState = SLIDING_TEXT_EXITING;
}

static void EndTextBoxSlideOut(struct Sprite *sprite)
{
    sprite->x = TEXT_BOX_X;
    sprite->y = TEXT_BOX_Y;
    sprite->y2 = 0;
    sprite->x2 = 0;
    sprite->callback = SpriteCallbackDummy;
    sContestResults->data->slidingTextBoxState = SLIDING_TEXT_OFFSCREEN;
}

static void SpriteCB_TextBoxSlideIn(struct Sprite *sprite)
{
    int i;

    s16 delta = sprite->sDistance + sprite->sSlideIncrement;
    sprite->x -= delta >> 8;
    sprite->sDistance += sprite->sSlideIncrement;
    sprite->sDistance &= 0xFF;

    // Prevent overshooting target
    if (sprite->x < sprite->sTargetX)
        sprite->x = sprite->sTargetX;

    for (i = 0; i < 3; i++)
    {
        struct Sprite *sprite2 = &gSprites[sprite->data[i]];
        sprite2->x = sprite->x + sprite->x2 + (i + 1) * 64;
    }

    if (sprite->x == sprite->sTargetX)
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
    sprite->x -= delta >> 8;
    sprite->sDistance += sprite->sSlideIncrement;
    sprite->sDistance &= 0xFF;
    for (i = 0; i < 3; i++)
    {
        struct Sprite *sprite2 = &gSprites[sprite->data[i]];
        sprite2->x = sprite->x + sprite->x2 + (i + 1) * 64;
    }

    if (sprite->x + sprite->x2 < -224)
        EndTextBoxSlideOut(sprite);
}

static void ShowLinkResultsTextBox(const u8 *text)
{
    int i;
    u16 x;
    struct Sprite *sprite;

    x = DrawResultsTextWindow(text, sContestResults->data->linkTextBoxSpriteId);
    sprite = &gSprites[sContestResults->data->linkTextBoxSpriteId];
    sprite->x = x + 32;
    sprite->y = 80;
    sprite->invisible = FALSE;
    for (i = 0; i < 3; i++)
    {
        gSprites[sprite->data[i]].x = sprite->x + sprite->x2 + (i + 1) * 64;
        gSprites[sprite->data[i]].y = sprite->y;
        gSprites[sprite->data[i]].invisible = FALSE;
    }

    gBattle_WIN0H = WIN_RANGE(0, DISPLAY_WIDTH);
    gBattle_WIN0V = WIN_RANGE(sprite->y - 16, sprite->y + 16);
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

static void LoadContestResultsTitleBarTilemaps(void)
{
    u8 palette;
    int x, y;

    x = 5;
    y = 1;
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Link_Tilemap, 5, 1, 5, 2);
        x = 10;
    }
    else if (gSpecialVar_ContestRank == CONTEST_RANK_NORMAL)
    {
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Normal_Tilemap, 5, 1, 10, 2);
        x = 15;
    }
    else if (gSpecialVar_ContestRank == CONTEST_RANK_SUPER)
    {
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Super_Tilemap, 5, 1, 10, 2);
        x = 15;
    }
    else if (gSpecialVar_ContestRank == CONTEST_RANK_HYPER)
    {
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Hyper_Tilemap, 5, 1, 10, 2);
        x = 15;
    }
    else // CONTEST_RANK_MASTER
    {
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Master_Tilemap, 5, 1, 10, 2);
        x = 15;
    }

    if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_COOL)
    {
        palette = 0;
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Cool_Tilemap, x, y, 5, 2);
    }
    else if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_BEAUTY)
    {
        palette = 1;
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Beauty_Tilemap, x, y, 5, 2);
    }
    else if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_CUTE)
    {
        palette = 2;
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Cute_Tilemap, x, y, 5, 2);
    }
    else if (gSpecialVar_ContestCategory == CONTEST_CATEGORY_SMART)
    {
        palette = 3;
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Smart_Tilemap, x, y, 5, 2);
    }
    else // CONTEST_CATEGORY_TOUGH
    {
        palette = 4;
        CopyToBgTilemapBufferRect(2, gContestResultsTitle_Tough_Tilemap, x, y, 5, 2);
    }

    x += 5;
    CopyToBgTilemapBufferRect(2, gContestResultsTitle_Tilemap, x, y, 6, 2);
    CopyToBgTilemapBufferRect_ChangePalette(2, sContestResults->tilemapBuffers[2], 0, 0, 32, 4, palette);
}

// Represented on results board as stars
static u8 GetNumPreliminaryPoints(u8 monIndex, bool8 capPoints)
{
    u32 condition = gContestMonRound1Points[monIndex] << 16;
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
            PlaySE(SE_CONTEST_PLACE);
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
        BlendPalette(BG_PLTT_ID(9) + 1, 1, gTasks[taskId].data[12], RGB(13, 28, 27));
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
            PlayCry_Normal(sprite->data[1], 0);
            sprite->data[1] = 0;
        }
    }
    else
    {
        s16 delta = sprite->data[1] + 0x600;
        sprite->x -= delta >> 8;
        sprite->data[1] += 0x600;
        sprite->data[1] &= 0xFF;
        if (sprite->x < DISPLAY_WIDTH / 2)
            sprite->x = DISPLAY_WIDTH / 2;

        if (sprite->x == DISPLAY_WIDTH / 2)
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
    sprite->x -= delta >> 8;
    sprite->data[1] += + 0x600;
    sprite->data[1] &= 0xFF;
    if (sprite->x < -32)
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
            u8 spriteId = CreateSprite(&sSpriteTemplate_Confetti, (Random() % DISPLAY_WIDTH) - 20, 44, 5);
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
    sprite->x2 = Sin(sprite->data[3] >> 8, sprite->data[1]);
    delta = sprite->data[4] + sprite->data[2];
    sprite->x += delta >> 8;
    sprite->data[4] += sprite->data[2];
    sprite->data[4] &= 0xff;

    sprite->y++;
    if (sContestResults->data->destroyConfetti)
        sprite->invisible = TRUE;

    if (sprite->x > DISPLAY_WIDTH + 8 || sprite->y > 116)
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
        relativePoints = (gContestMonRound1Points[i] * 1000) / abs(highestPoints);
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

            if (barLengthPreliminary + barLengthRound2 == MAX_BAR_LENGTH)
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

    // Has the results bar reached the limit?
    if (decreasing)
    {
        if (sContestResults->data->barLength[monId] <= 0)
            minMaxReached = TRUE;
    }
    else
    {
        if (sContestResults->data->barLength[monId] >= MAX_BAR_LENGTH)
            minMaxReached = TRUE;
    }

    if (sContestResults->data->barLength[monId] == target)
        targetReached = TRUE;

    if (!targetReached)
    {
        // Target length has not been reached, update bar length
        if (minMaxReached)
            sContestResults->data->barLength[monId] = target;
        else if (decreasing)
            sContestResults->data->barLength[monId]--;
        else
            sContestResults->data->barLength[monId]++;
    }

    // Update the tiles of the results bar if it's still changing
    if (!minMaxReached && !targetReached)
    {
        u8 tileOffset;
        u16 tileNum;
        for (i = 0; i < NUM_BAR_SEGMENTS; i++)
        {
            if (sContestResults->data->barLength[monId] >= (i + 1) * BAR_SEGMENT_LENGTH)
                tileOffset = 8; // Bar segment is full
            else if (sContestResults->data->barLength[monId] >= i * BAR_SEGMENT_LENGTH)
                tileOffset = sContestResults->data->barLength[monId] % 8; // Bar segment is between full and empty
            else
                tileOffset = 0; // Bar segment is empty

            // The first 4 bar segment tiles are not adjacent in the tileset to the
            // remaining bar segment tiles; choose the base tile number accordingly.
            if (tileOffset < 4)
                tileNum = 0x504C + tileOffset;
            else
                tileNum = 0x5057 + tileOffset;

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
    textPrinter.fontId = FONT_NARROW;
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
        SetContestants(gSpecialVar_ContestCategory, gSpecialVar_ContestRank);
        CalculateRound1Points(gSpecialVar_ContestCategory);
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
    ConvertInternationalContestantName(gStringVar1);
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
        if (gContestMonRound1Points[gSpecialVar_0x8006] < gContestMonRound1Points[i])
            rank++;
    }

    gSpecialVar_0x8004 = rank;
}

void GetContestMonCondition(void)
{
    gSpecialVar_0x8004 = gContestMonRound1Points[gSpecialVar_0x8006];
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
    ConvertInternationalContestantName(gStringVar3);
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
    LockPlayerFieldControls();
    CreateTask(Task_StartContest, 10);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
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
    LockPlayerFieldControls();
    CreateTask(Task_StartShowContestResults, 10);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}

void GetContestPlayerId(void)
{
    gSpecialVar_0x8004 = gContestPlayerMonIndex;
}

void ContestLinkTransfer(u8 category)
{
    u8 newTaskId;
    LockPlayerFieldControls();
    newTaskId = CreateTask(Task_LinkContest_Init, 0);
    SetTaskFuncWithFollowupFunc(newTaskId, Task_LinkContest_Init, Task_StartCommunication);
    gTasks[newTaskId].data[9] = category;
}

static void Task_StartCommunication(u8 taskId)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER)
    {
        CreateContestMonFromParty(gContestMonPartyIndex);
        SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateMonsRS, Task_StartCommunicateRngRS);
    }
    else
    {
        CreateContestMonFromParty(gContestMonPartyIndex);
        gTasks[taskId].func = Task_LinkContest_StartCommunicationEm;
    }
}

static void Task_StartCommunicateRngRS(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateRngRS, Task_StartCommunicateLeaderIdsRS);
}

static void Task_StartCommunicateLeaderIdsRS(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateLeaderIdsRS, Task_StartCommunicateCategoryRS);
}

static void Task_StartCommunicateCategoryRS(u8 taskId)
{
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateCategoryRS, Task_LinkContest_SetUpContestRS);
}

static void Task_LinkContest_SetUpContestRS(u8 taskId)
{
    u8 i;
    u8 categories[CONTESTANT_COUNT];
    u8 leaderIds[CONTESTANT_COUNT];

    memset(categories, 0, sizeof(categories));
    memset(leaderIds, 0, sizeof(leaderIds));

    for (i = 0; i < gNumLinkContestPlayers; i++)
        categories[i] = gTasks[taskId].data[i + 1];

    // Ensure all players are doing the same category
    for (i = 0; i < gNumLinkContestPlayers && categories[0] == categories[i]; i++)
        ;

    if (i == gNumLinkContestPlayers)
        gSpecialVar_0x8004 = FALSE; // Category choices the same
    else
        gSpecialVar_0x8004 = TRUE; // Category choices differ

    for (i = 0; i < gNumLinkContestPlayers; i++)
        leaderIds[i] = gTasks[taskId].data[i + 5];

    gContestLinkLeaderIndex = LinkContest_GetLeaderIndex(leaderIds);
    CalculateRound1Points(gSpecialVar_ContestCategory);
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateRound1Points, Task_LinkContest_CalculateTurnOrderRS);
}

static void Task_LinkContest_CalculateTurnOrderRS(u8 taskId)
{
    SortContestants(FALSE);
    SetTaskFuncWithFollowupFunc(taskId, Task_LinkContest_CommunicateTurnOrder, Task_LinkContest_FinalizeConnection);
}

u8 LinkContest_GetLeaderIndex(u8 *ids)
{
    int i;
    u8 leaderIdx = 0;

    for (i = 1; i < gNumLinkContestPlayers; i++)
    {
        if (ids[leaderIdx] < ids[i])
            leaderIdx = i;
    }

    return leaderIdx;
}

void Task_LinkContest_FinalizeConnection(u8 taskId)
{
    int i;

    if (gSpecialVar_0x8004 == TRUE)
    {
        // Link partner data doesn't agree, disconnect
        if (IsLinkTaskFinished())
            gTasks[taskId].func = Task_LinkContest_Disconnect;
    }
    else
    {
        // Succesfully connected
        for (i = 0; i < CONTESTANT_COUNT; i++)
            StringGet_Nickname(gContestMons[i].nickname);

        DestroyTask(taskId);
        SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
        UnlockPlayerFieldControls();
        ScriptContext_Enable();
    }
}

static void Task_LinkContest_Disconnect(u8 taskId)
{
    SetCloseLinkCallback();
    gTasks[taskId].func = Task_LinkContest_WaitDisconnect;
}

static void Task_LinkContest_WaitDisconnect(u8 taskId)
{
    if (!gReceivedRemoteLinkPlayers)
    {
        DestroyTask(taskId);
        UnlockPlayerFieldControls();
        ScriptContext_Enable();
    }
}

/*
    A section of contest script functions starts here
*/

void SetContestTrainerGfxIds(void)
{
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_0 - VARS_START] = gContestMons[0].trainerGfxId;
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_1 - VARS_START] = gContestMons[1].trainerGfxId;
    gSaveBlock1Ptr->vars[VAR_OBJ_GFX_ID_2 - VARS_START] = gContestMons[2].trainerGfxId;
}

// Unused
void GetNpcContestantLocalId(void)
{
    u16 localId;
    u8 contestant = gSpecialVar_0x8005;
    switch (contestant)
    {
    case 0:
        localId = 3;
        break;
    case 1:
        localId = 4;
        break;
    case 2:
        localId = 5;
        break;
    default: // Invalid
        localId = 100;
        break;
    }

    gSpecialVar_0x8004 = localId;
}

void BufferContestTrainerAndMonNames(void)
{
    BufferContestantTrainerName();
    BufferContestantMonNickname();
    BufferContestantMonSpecies();
}

// Unused
void DoesContestCategoryHaveMuseumPainting(void)
{
    int contestWinner;
    switch (gSpecialVar_ContestCategory)
    {
    case CONTEST_CATEGORY_COOL:
        contestWinner = CONTEST_WINNER_MUSEUM_COOL - 1;
        break;
    case CONTEST_CATEGORY_BEAUTY:
        contestWinner = CONTEST_WINNER_MUSEUM_BEAUTY - 1;
        break;
    case CONTEST_CATEGORY_CUTE:
        contestWinner = CONTEST_WINNER_MUSEUM_CUTE - 1;
        break;
    case CONTEST_CATEGORY_SMART:
        contestWinner = CONTEST_WINNER_MUSEUM_SMART - 1;
        break;
    case CONTEST_CATEGORY_TOUGH:
    default:
        contestWinner = CONTEST_WINNER_MUSEUM_TOUGH - 1;
        break;
    }

    if (gSaveBlock1Ptr->contestWinners[contestWinner].species == SPECIES_NONE)
        gSpecialVar_0x8004 = FALSE;
    else
        gSpecialVar_0x8004 = TRUE;
}

void SaveMuseumContestPainting(void)
{
    SaveContestWinner(CONTEST_SAVE_FOR_MUSEUM);
}

void ShouldReadyContestArtist(void)
{
    if (gContestFinalStandings[gContestPlayerMonIndex] == 0
     && gSpecialVar_ContestRank == CONTEST_RANK_MASTER
     && gContestMonTotalPoints[gContestPlayerMonIndex] >= 800)
    {
        gSpecialVar_0x8004 = TRUE;
    }
    else
    {
        gSpecialVar_0x8004 = FALSE;
    }
}

u8 CountPlayerMuseumPaintings(void)
{
    int i;
    u8 count = 0;

    for (i = 0; i < NUM_CONTEST_WINNERS - MUSEUM_CONTEST_WINNERS_START; i++)
    {
        if (gSaveBlock1Ptr->contestWinners[MUSEUM_CONTEST_WINNERS_START + i].species)
            count++;
    }

    return count;
}

// Unused
void GetContestantNamesAtRank(void)
{
    s16 conditions[CONTESTANT_COUNT];
    int i, j;
    s16 condition;
    s8 numAtCondition;
    u8 contestantOffset;
    u8 tieRank;
    u8 rank;

    // Get round 1 points
    for (i = 0; i < CONTESTANT_COUNT; i++)
        conditions[i] = gContestMonRound1Points[i];

    // Sort round 1 points
    for (i = 0; i < CONTESTANT_COUNT - 1; i++)
    {
        for (j = CONTESTANT_COUNT - 1; j > i; j--)
        {
            if (conditions[j - 1] < conditions[j])
            {
                int temp;
                SWAP(conditions[j], conditions[j - 1], temp)
            }
        }
    }

    // Get round 1 points at specified rank
    condition = conditions[gSpecialVar_0x8006];

    // Count number of contestants with the same number of points
    numAtCondition = 0;
    tieRank = 0;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (conditions[i] == condition)
        {
            numAtCondition++;
            if (i == gSpecialVar_0x8006)
                tieRank = numAtCondition;
        }
    }

    // Get rank of first contestant with the same number of points
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (conditions[i] == condition)
            break;
    }
    rank = i;

    // Get contestant id of player at rank (taking ties into account)
    contestantOffset = tieRank;
    for (i = 0; i < CONTESTANT_COUNT; i++)
    {
        if (condition == gContestMonRound1Points[i])
        {
            if (contestantOffset == 1)
                break;
            contestantOffset--;
        }
    }

    // Use contestant id to get names
    StringCopy(gStringVar1, gContestMons[i].nickname);
    StringCopy(gStringVar2, gContestMons[i].trainerName);
    ConvertInternationalContestantName(gStringVar2);

    // Return adjusted rank
    if (numAtCondition == 1)
        gSpecialVar_0x8006 = rank;
    else if (tieRank == numAtCondition)
        gSpecialVar_0x8006 = rank;
    else
        gSpecialVar_0x8006 = rank + CONTESTANT_COUNT;
}

static void ExitContestPainting(void)
{
    SetMainCallback2(CB2_ReturnToFieldContinueScriptPlayMapMusic);
}

void ShowContestPainting(void)
{
    SetMainCallback2(CB2_ContestPainting);
    gMain.savedCallback = ExitContestPainting;
}

void SetLinkContestPlayerGfx(void)
{
    int i;

    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        for (i = 0; i < gNumLinkContestPlayers; i++)
        {
            int version = (u8)gLinkPlayers[i].version;
            if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[i].gender == MALE)
                    gContestMons[i].trainerGfxId = OBJ_EVENT_GFX_LINK_RS_BRENDAN;
                else
                    gContestMons[i].trainerGfxId = OBJ_EVENT_GFX_LINK_RS_MAY;
            }
        }

        VarSet(VAR_OBJ_GFX_ID_0, gContestMons[0].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_1, gContestMons[1].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_2, gContestMons[2].trainerGfxId);
        VarSet(VAR_OBJ_GFX_ID_3, gContestMons[3].trainerGfxId);
    }
}

void LoadLinkContestPlayerPalettes(void)
{
    int i;
    u8 objectEventId;
    int version;
    struct Sprite *sprite;
    static const u8 sContestantLocalIds[CONTESTANT_COUNT] = { 3, 4, 5, 14 };

    gReservedSpritePaletteCount = 12;
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        for (i = 0; i < gNumLinkContestPlayers; i++)
        {
            objectEventId = GetObjectEventIdByLocalIdAndMap(sContestantLocalIds[i], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
            sprite = &gSprites[gObjectEvents[objectEventId].spriteId];
            sprite->oam.paletteNum = 6 + i;
            version = (u8)gLinkPlayers[i].version;
            if (version == VERSION_RUBY || version == VERSION_SAPPHIRE)
            {
                if (gLinkPlayers[i].gender == MALE)
                    LoadPalette(gObjectEventPal_RubySapphireBrendan, OBJ_PLTT_ID(6 + i), PLTT_SIZE_4BPP);
                else
                    LoadPalette(gObjectEventPal_RubySapphireMay, OBJ_PLTT_ID(6 + i), PLTT_SIZE_4BPP);
            }
            else
            {
                if (gLinkPlayers[i].gender == MALE)
                    LoadPalette(gObjectEventPal_Brendan, OBJ_PLTT_ID(6 + i), PLTT_SIZE_4BPP);
                else
                    LoadPalette(gObjectEventPal_May, OBJ_PLTT_ID(6 + i), PLTT_SIZE_4BPP);
            }
        }
    }
}

bool8 GiveMonArtistRibbon(void)
{
    u8 hasArtistRibbon;

    hasArtistRibbon = GetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_ARTIST_RIBBON);
    if (!hasArtistRibbon
        && gContestFinalStandings[gContestPlayerMonIndex] == 0
        && gSpecialVar_ContestRank == CONTEST_RANK_MASTER
        && gContestMonTotalPoints[gContestPlayerMonIndex] >= 800)
    {
        hasArtistRibbon = 1;
        SetMonData(&gPlayerParty[gContestMonPartyIndex], MON_DATA_ARTIST_RIBBON, &hasArtistRibbon);
        if (GetRibbonCount(&gPlayerParty[gContestMonPartyIndex]) > NUM_CUTIES_RIBBONS)
            TryPutSpotTheCutiesOnAir(&gPlayerParty[gContestMonPartyIndex], MON_DATA_ARTIST_RIBBON);

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 IsContestDebugActive(void)
{
    return FALSE; // gUnknown_0203856C in pokeruby
}

void ShowContestEntryMonPic(void)
{
    const struct CompressedSpritePalette *palette;
    u32 personality, otId;
    u16 species;
    u8 spriteId;
    u8 taskId;
    u8 left, top;

    if (FindTaskIdByFunc(Task_ShowContestEntryMonPic) == TASK_NONE)
    {
        AllocateMonSpritesGfx();
        left = 10;
        top = 3;
        species = gContestMons[gSpecialVar_0x8006].species;
        personality = gContestMons[gSpecialVar_0x8006].personality;
        otId = gContestMons[gSpecialVar_0x8006].otId;
        taskId = CreateTask(Task_ShowContestEntryMonPic, 0x50);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = species;
        if (gSpecialVar_0x8006 == gContestPlayerMonIndex)
            HandleLoadSpecialPokePic_2(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[B_POSITION_OPPONENT_LEFT], species, personality);
        else
            HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[species], gMonSpritesGfxPtr->sprites.ptr[B_POSITION_OPPONENT_LEFT], species, personality);

        palette = GetMonSpritePalStructFromOtIdPersonality(species, otId, personality);
        LoadCompressedSpritePalette(palette);
        SetMultiuseSpriteTemplateToPokemon(species, B_POSITION_OPPONENT_LEFT);
        gMultiuseSpriteTemplate.paletteTag = palette->tag;
        spriteId = CreateSprite(&gMultiuseSpriteTemplate, (left + 1) * 8 + 32, (top * 8) + 40, 0);

        if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        {
            if (!(gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER))
                DoMonFrontSpriteAnimation(&gSprites[spriteId], species, FALSE, 0);
        }
        else
        {
            DoMonFrontSpriteAnimation(&gSprites[spriteId], species, FALSE, 0);
        }

        gTasks[taskId].data[2] = spriteId;
        gTasks[taskId].data[3] = left;
        gTasks[taskId].data[4] = top;
        gSprites[spriteId].callback = SpriteCallbackDummy;
        gSprites[spriteId].oam.priority = 0;
    }
}

void HideContestEntryMonPic(void)
{
    u8 taskId = FindTaskIdByFunc(Task_ShowContestEntryMonPic);
    if (taskId != TASK_NONE)
    {
        gTasks[taskId].data[0]++;
        FreeMonSpritesGfx();
    }
}

static void Task_ShowContestEntryMonPic(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct Sprite *sprite;

    switch(task->data[0])
    {
    case 0:
        task->data[0]++;
        break;
    case 1:
        task->data[5] = CreateWindowFromRect(10, 3, 8, 8);
        SetStandardWindowBorderStyle(task->data[5], TRUE);
        task->data[0]++;
        break;
    case 2:
        break;
    case 3:
        sprite = &gSprites[task->data[2]];
        FreeSpritePaletteByTag(GetSpritePaletteTagByPaletteNum(sprite->oam.paletteNum));

        if(sprite->oam.affineMode)
            FreeOamMatrix(sprite->oam.matrixNum);

        DestroySprite(sprite);
        task->data[0]++;
        break;
    case 4:
        ClearToTransparentAndRemoveWindow(gTasks[taskId].data[5]);
        DestroyTask(taskId);
        break;
    }
}

void GetContestMultiplayerId(void)
{
    if ((gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
        && gNumLinkContestPlayers == CONTESTANT_COUNT
        && !(gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS))
        gSpecialVar_Result = GetMultiplayerId();
    else
        gSpecialVar_Result = MAX_LINK_PLAYERS;
}

void GenerateContestRand(void)
{
    u16 random;
    u16 *result;

    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_LINK)
    {
        gContestRngValue = ISO_RANDOMIZE1(gContestRngValue);
        random = gContestRngValue >> 16;
        result = &gSpecialVar_Result;
    }
    else
    {
        result = &gSpecialVar_Result;
        random = Random();
    }
    *result = random % *result;
}

u16 GetContestRand(void)
{
    gContestRngValue = ISO_RANDOMIZE1(gContestRngValue);
    return gContestRngValue >> 16;
}

bool8 LinkContestWaitForConnection(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        CreateTask(Task_LinkContestWaitForConnection, 5);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void Task_LinkContestWaitForConnection(u8 taskId)
{
    switch (gTasks[taskId].data[0])
    {
    case 0:
        if (IsLinkTaskFinished())
        {
            SetLinkStandbyCallback();
            gTasks[taskId].data[0]++;
        }
        break;
    case 1:
        gTasks[taskId].data[0]++;
        break;
    default:
        if (IsLinkTaskFinished() == 1)
        {
            ScriptContext_Enable();
            DestroyTask(taskId);
        }
        break;
    }
}

void LinkContestTryShowWirelessIndicator(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        if (gReceivedRemoteLinkPlayers)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(8, 8);
        }
    }
}

void LinkContestTryHideWirelessIndicator(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
    {
        if (gReceivedRemoteLinkPlayers)
            DestroyWirelessStatusIndicatorSprite();
    }
}

bool8 IsContestWithRSPlayer(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_HAS_RS_PLAYER)
        return TRUE;
    else
        return FALSE;
}

void ClearLinkContestFlags(void)
{
    gLinkContestFlags = 0;
}

bool8 IsWirelessContest(void)
{
    if (gLinkContestFlags & LINK_CONTEST_FLAG_IS_WIRELESS)
        return TRUE;
    else
        return FALSE;
}
