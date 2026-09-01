#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_util.h"
#include "bg.h"
#include "chooseboxmon.h"
#include "contest_effect.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "item.h"
#include "move_relearner.h"
#include "list_menu.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "menu_specialized.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/party_menu.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "data/tutor_moves.h"

// The different versions of hearts are selected using animation
// commands.
enum {
    APPEAL_HEART_EMPTY,
    APPEAL_HEART_FULL,
    JAM_HEART_EMPTY,
    JAM_HEART_FULL,
};

#define TAG_MODE_ARROWS 5325
#define TAG_LIST_ARROWS 5425
#define GFXTAG_UI       5525
#define PALTAG_UI       5526

#define BATTLE_INFO 0
#define CONTEST_INFO 1
#define RETURN_FROM_MOVE_SELECT 2

struct RelearnType
{
    bool32 (*isActive)(void);
    bool32 (*hasMoveToRelearn)(struct BoxPokemon*);
    u32 (*getMoves)(struct BoxPokemon *, enum Move *);
    const u8 *moveText;
};

static EWRAM_DATA struct
{
    u8 heartSpriteIds[16];
    u16 movesToLearn[MAX_RELEARNER_MOVES];
    struct ListMenuItem menuItems[MAX_RELEARNER_MOVES + 1];
    u8 mainTask;
    u8 numMenuChoices;
    u8 numToShowAtOnce;
    u8 moveListMenuTask;
    u8 moveListScrollArrowTask;
    u8 moveDisplayArrowTask;
    u16 scrollOffset;
    u8 categoryIconSpriteId;
} *sMoveRelearnerStruct = {0};

static EWRAM_DATA struct {
    u16 listOffset;
    u16 listRow;
} sMoveRelearnerScrollState = {0};

EWRAM_DATA enum MoveRelearnerStates gMoveRelearnerState = MOVE_RELEARNER_LEVEL_UP_MOVES;
EWRAM_DATA enum RelearnMode gRelearnMode = RELEARN_MODE_NONE;

static const u16 sUI_Pal[] = INCGFX_U16("graphics/interface/ui_learn_move.png", ".gbapal");

// The arrow sprites in this spritesheet aren't used. The scroll-arrow system provides its own
// arrow sprites.
static const u8 sUI_Tiles[] = INCGFX_U8("graphics/interface/ui_learn_move.png", ".4bpp");

static const struct OamData sHeartSpriteOamData =
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

static const struct OamData sUnusedOam1 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sUnusedOam2 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sMoveRelearnerSpriteSheet =
{
    .data = sUI_Tiles,
    .size = sizeof(sUI_Tiles),
    .tag = GFXTAG_UI
};

static const struct SpritePalette sMoveRelearnerPalette =
{
    .data = sUI_Pal,
    .tag = PALTAG_UI
};

static const struct ScrollArrowsTemplate sDisplayModeArrowsTemplate =
{
    .firstArrowType = SCROLL_ARROW_LEFT,
    .firstX = 27,
    .firstY = 16,
    .secondArrowType = SCROLL_ARROW_RIGHT,
    .secondX = 117,
    .secondY = 16,
    .fullyUpThreshold = -1,
    .fullyDownThreshold = -1,
    .tileTag = TAG_MODE_ARROWS,
    .palTag = TAG_MODE_ARROWS,
    .palNum = 0,
};

static const struct ScrollArrowsTemplate sMoveListScrollArrowsTemplate =
{
    .firstArrowType = SCROLL_ARROW_UP,
    .firstX = 192,
    .firstY = 8,
    .secondArrowType = SCROLL_ARROW_DOWN,
    .secondX = 192,
    .secondY = 104,
    .fullyUpThreshold = 0,
    .fullyDownThreshold = 0,
    .tileTag = TAG_LIST_ARROWS,
    .palTag = TAG_LIST_ARROWS,
    .palNum = 0,
};

static const union AnimCmd sHeartSprite_AppealEmptyFrame[] =
{
    ANIMCMD_FRAME(8, 5, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sHeartSprite_AppealFullFrame[] =
{
    ANIMCMD_FRAME(9, 5, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sHeartSprite_JamEmptyFrame[] =
{
    ANIMCMD_FRAME(10, 5, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd sHeartSprite_JamFullFrame[] =
{
    ANIMCMD_FRAME(11, 5, FALSE, FALSE),
    ANIMCMD_END
};

static const union AnimCmd *const sHeartSpriteAnimationCommands[] =
{
    [APPEAL_HEART_EMPTY] = sHeartSprite_AppealEmptyFrame,
    [APPEAL_HEART_FULL] = sHeartSprite_AppealFullFrame,
    [JAM_HEART_EMPTY] = sHeartSprite_JamEmptyFrame,
    [JAM_HEART_FULL] = sHeartSprite_JamFullFrame,
};

static const struct SpriteTemplate sConstestMoveHeartSprite =
{
    .tileTag = GFXTAG_UI,
    .paletteTag = PALTAG_UI,
    .oam = &sHeartSpriteOamData,
    .anims = sHeartSpriteAnimationCommands,
};

static const struct BgTemplate sMoveRelearnerMenuBackgroundTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static void StoreMoveText(void);
static void CreateLearnableMovesList(void);
static void CreateUISprites(void);
static void CB2_MoveRelearnerMain(void);
static void Task_WaitForFadeOut(u8 taskId);
static void CB2_InitLearnMoveReturnFromSelectMove(void);
static void InitMoveRelearnerBackgroundLayers(void);
static void AddScrollArrows(void);
static void ShowTeachMoveText();
static s32 GetCurrentSelectedMove(void);
static void FreeMoveRelearnerResources(void);
static void RemoveScrollArrows(void);
static bool32 IsLevelUpMoveRelearnerActive(void);
static bool32 IsEggMoveRelearnerActive(void);
static bool32 IsTMMoveRelearnerActive(void);
static bool32 IsTutorMoveRelearnerActive(void);
static bool32 HasRelearnerLevelUpMoves(struct BoxPokemon *boxMon);
static bool32 HasRelearnerEggMoves(struct BoxPokemon *boxMon);
static bool32 HasRelearnerTMMoves(struct BoxPokemon *boxMon);
static bool32 HasRelearnerTutorMoves(struct BoxPokemon *boxMon);
static u32 GetRelearnerLevelUpMoves(struct BoxPokemon *mon, u16 *moves);
static u32 GetRelearnerEggMoves(struct BoxPokemon *mon, u16 *moves);
static u32 GetRelearnerTMMoves(struct BoxPokemon *mon, u16 *moves);
static u32 GetRelearnerTutorMoves(struct BoxPokemon *mon, u16 *moves);

static void Task_MoveRelearner_HandleInput(u8 taskId);
static void Task_MoveRelearner_LearnMove(u8 taskId);
static void Task_MoveRelearner_Quit(u8 taskId);
static void SortMovesAlphabetically(u16 *moves, u32 numMoves);
static void QuickSortMoves(u16 *moves, s32 left, s32 right);

static const struct RelearnType sRelearnTypes[MOVE_RELEARNER_COUNT] =
{
    [MOVE_RELEARNER_LEVEL_UP_MOVES] = {
        .isActive = IsLevelUpMoveRelearnerActive,
        .hasMoveToRelearn = HasRelearnerLevelUpMoves,
        .getMoves = GetRelearnerLevelUpMoves,
        .moveText = MoveRelearner_Text_LevelUpMoveLWR
    },
    [MOVE_RELEARNER_EGG_MOVES] = {
        .isActive = IsEggMoveRelearnerActive,
        .hasMoveToRelearn = HasRelearnerEggMoves,
        .getMoves = GetRelearnerEggMoves,
        .moveText = MoveRelearner_Text_EggMoveLWR
    },
    [MOVE_RELEARNER_TM_MOVES] = {
        .isActive = IsTMMoveRelearnerActive,
        .hasMoveToRelearn = HasRelearnerTMMoves,
        .getMoves = GetRelearnerTMMoves,
        .moveText = MoveRelearner_Text_TMMoveLWR
    },
    [MOVE_RELEARNER_TUTOR_MOVES] = {
        .isActive = IsTutorMoveRelearnerActive,
        .hasMoveToRelearn = HasRelearnerTutorMoves,
        .getMoves = GetRelearnerTutorMoves,
        .moveText = MoveRelearner_Text_TutorMoveLWR
    },
};

static void VBlankCB_MoveRelearner(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Script arguments: The Pokémon to teach is in VAR_0x8004
void TeachMoveRelearnerMove(void)
{
    LockPlayerFieldControls();
    CreateTask(Task_WaitForFadeOut, 10);
    gRelearnMode = RELEARN_MODE_SCRIPT;
    // Fade to black
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 0x10, RGB_BLACK);
}

static void Task_WaitForFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InitLearnMove);
        gFieldCallback = FieldCB_ContinueScriptHandleMusic;
        DestroyTask(taskId);
    }
}

#define tState      data[0]
#define tPartyIndex data[1]
#define tMove       data[2]
#define tRecoverPp  data[3]
#define tCategory   data[4]

static void CB2_InitLearnMove_Basic(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetSpriteData();
        FreeAllSpritePalettes();
        ClearScheduledBgCopiesToVram();
        SetVBlankCallback(VBlankCB_MoveRelearner);
        gMain.state++;
        break;
    case 1:
        InitMoveRelearnerBackgroundLayers();
        InitMoveRelearnerWindows(gTasks[sMoveRelearnerStruct->mainTask].tCategory == CONTEST_INFO);
        gMain.state++;
        break;
    case 2:
        LoadSpriteSheet(&sMoveRelearnerSpriteSheet);
        LoadSpritePalette(&sMoveRelearnerPalette);
        CreateUISprites();
        gMain.state++;
        break;
    case 3:
        StoreMoveText();
        CreateLearnableMovesList();
        sMoveRelearnerStruct->moveListMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, sMoveRelearnerScrollState.listOffset, sMoveRelearnerScrollState.listRow);
        gMain.state++;
        break;
    case 4:
        ShowTeachMoveText();
        MoveRelearnerShowHideHearts(GetCurrentSelectedMove());
        SetBackdropFromColor(RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, -2, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 5:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
            gMain.state++;
        break;
    default:
        if (gTasks[sMoveRelearnerStruct->mainTask].tState)
        {
            gTasks[sMoveRelearnerStruct->mainTask].func = Task_MoveRelearner_LearnMove;
        }
        else
        {
            AddScrollArrows();
            gTasks[sMoveRelearnerStruct->mainTask].func = Task_MoveRelearner_HandleInput;
        }
        if (gRelearnMode == RELEARN_MODE_SCRIPT)
            gTasks[sMoveRelearnerStruct->mainTask].tRecoverPp = TRUE;
        else
            gTasks[sMoveRelearnerStruct->mainTask].tRecoverPp = P_SUMMARY_MOVE_RELEARNER_FULL_PP;
        SetVBlankCallback(VBlankCB_MoveRelearner);
        SetMainCallback2(CB2_MoveRelearnerMain);
        break;
    }
}

void CB2_InitLearnMove(void)
{
    ResetTasks();
    sMoveRelearnerStruct = AllocZeroed(sizeof(*sMoveRelearnerStruct));
    sMoveRelearnerStruct->mainTask = CreateTask(TaskDummy, 1);
    sMoveRelearnerScrollState.listOffset = 0;
    sMoveRelearnerScrollState.listRow = 0;
    gTasks[sMoveRelearnerStruct->mainTask].tState = 0;
    gTasks[sMoveRelearnerStruct->mainTask].tPartyIndex = gSpecialVar_0x8004;
    gTasks[sMoveRelearnerStruct->mainTask].tMove = MOVE_NONE;
    if (!C_HIDE_CONTEST_DATA && gRelearnMode == RELEARN_MODE_PSS_PAGE_CONTEST_MOVES)
        gTasks[sMoveRelearnerStruct->mainTask].tCategory = CONTEST_INFO;
    else
        gTasks[sMoveRelearnerStruct->mainTask].tCategory = BATTLE_INFO;
    SetMainCallback2(CB2_InitLearnMove_Basic);
}

static void CB2_InitLearnMoveReturnFromSelectMove(void)
{
    ResetTasks();
    sMoveRelearnerStruct = AllocZeroed(sizeof(*sMoveRelearnerStruct));
    sMoveRelearnerStruct->mainTask = CreateTask(TaskDummy, 1);
    gTasks[sMoveRelearnerStruct->mainTask].tState = GetLearnMoveResumeAfterSummaryScreenState();
    gTasks[sMoveRelearnerStruct->mainTask].tPartyIndex = gSpecialVar_0x8008;
    gTasks[sMoveRelearnerStruct->mainTask].tMove = gSpecialVar_0x8009;
    gTasks[sMoveRelearnerStruct->mainTask].tCategory = gSpecialVar_0x800A;
    SetMainCallback2(CB2_InitLearnMove_Basic);
}

static bool32 GameHasDifferentRelearners(void)
{
    if (P_ENABLE_MOVE_RELEARNERS || P_TM_MOVES_RELEARNER)
        return TRUE;
    if (P_FLAG_EGG_MOVES || P_FLAG_TUTOR_MOVES)
        return TRUE;
    return FALSE;
}

static void StoreMoveText(void)
{
    if (GameHasDifferentRelearners() || gRelearnMode == RELEARN_MODE_SCRIPT)
        StringCopy(gStringVar3, sRelearnTypes[gMoveRelearnerState].moveText);
    else
        StringCopy(gStringVar3, MoveRelearner_Text_MoveLWR);
}

static void InitMoveRelearnerBackgroundLayers(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMoveRelearnerMenuBackgroundTemplates, ARRAY_COUNT(sMoveRelearnerMenuBackgroundTemplates));
    ResetAllBgsCoordinates();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP |
                                  DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void CB2_MoveRelearnerMain(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static bool32 ShouldConsumeTmItem(enum Move move)
{
    if (gMoveRelearnerState != MOVE_RELEARNER_TM_MOVES || gRelearnMode == RELEARN_MODE_SCRIPT)
        return FALSE;
    if (I_REUSABLE_TMS || P_ENABLE_ALL_TM_MOVES)
        return FALSE;
    return TRUE;
}

static void FreeMoveRelearnerResources(void)
{
    RemoveScrollArrows();
    DestroyListMenuTask(sMoveRelearnerStruct->moveListMenuTask, &sMoveRelearnerScrollState.listOffset, &sMoveRelearnerScrollState.listRow);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sMoveRelearnerStruct);
    ResetSpriteData();
    FreeAllSpritePalettes();
}

static void UIAskConfirmation(void)
{
    MoveRelearnerCreateYesNoMenu();
}

static s32 UIWaitConfirmation(void)
{
    return Menu_ProcessInputNoWrapClearOnChoose();
}

static void UIPrintMessage(const u8 *message)
{
    StringExpandPlaceholders(gStringVar4, message);
    MoveRelearnerPrintMessage(gStringVar4);
}

static void UIPlayFanfare(u32 songId)
{
    PlayFanfare(songId);
}

static void UIShowMoveList(u8 taskId)
{
    gSpecialVar_0x8008 = gTasks[taskId].tPartyIndex;
    gSpecialVar_0x8009 = gTasks[taskId].tMove;
    gSpecialVar_0x800A = gTasks[taskId].tCategory;
    ShowSelectMovePokemonSummaryScreen(gParties[B_TRAINER_PLAYER], gTasks[taskId].tPartyIndex, CB2_InitLearnMoveReturnFromSelectMove, gTasks[taskId].tMove);
    DestroyTask(taskId);
    FreeMoveRelearnerResources();
}

static void RedrawMoveList(void)
{
    CreateLearnableMovesList();
    if (sMoveRelearnerScrollState.listOffset > sMoveRelearnerStruct->numMenuChoices - sMoveRelearnerStruct->numToShowAtOnce)
        sMoveRelearnerScrollState.listOffset = sMoveRelearnerStruct->numMenuChoices - sMoveRelearnerStruct->numToShowAtOnce;
    DestroyListMenuTask(sMoveRelearnerStruct->moveListMenuTask, NULL, NULL);
    sMoveRelearnerStruct->moveListMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, sMoveRelearnerScrollState.listOffset, sMoveRelearnerScrollState.listRow);
    ShowTeachMoveText();
}

static void UIEndTask(u8 taskId)
{
    if (gSpecialVar_Result == TRUE && ShouldConsumeTmItem(gTasks[taskId].tMove))
    {
        enum Item item = GetTMHMItemIdFromMoveId(gTasks[taskId].tMove);
        if (!GetItemImportance(item))
            RemoveBagItem(item, 1);
    }
    if (gRelearnMode == RELEARN_MODE_SCRIPT && gSpecialVar_Result == TRUE)
    {
        gTasks[taskId].func = Task_MoveRelearner_Quit;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        return;
    }
    if (gSpecialVar_Result == TRUE)
        RedrawMoveList();
    else
        ShowTeachMoveText();
    AddScrollArrows();
    gTasks[taskId].func = Task_MoveRelearner_HandleInput;
}

static const struct MoveLearnUI sMoveLearnUI =
{
    .askConfirmation = UIAskConfirmation,
    .waitConfirmation = UIWaitConfirmation,
    .printMessage = UIPrintMessage,
    .playFanfare = UIPlayFanfare,
    .showMoveList = UIShowMoveList,
    .endTask = UIEndTask
};

static void Task_MoveRelearner_Quit(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    if (gInitialSummaryScreenCallback != NULL)
    {
        if (gRelearnMode == RELEARN_MODE_PSS_PAGE_CONTEST_MOVES)
            ShowPokemonSummaryScreen(SUMMARY_MODE_RELEARNER_CONTEST, gParties[B_TRAINER_PLAYER], gTasks[taskId].tPartyIndex, gPartiesCount[B_TRAINER_PLAYER] - 1, gInitialSummaryScreenCallback);
        else
            ShowPokemonSummaryScreen(SUMMARY_MODE_RELEARNER_BATTLE, gParties[B_TRAINER_PLAYER], gTasks[taskId].tPartyIndex, gPartiesCount[B_TRAINER_PLAYER] - 1, gInitialSummaryScreenCallback);
    }
    else
    {
        SetMainCallback2(CB2_ReturnToField);
    }

    FreeMoveRelearnerResources();
    gRelearnMode = RELEARN_MODE_NONE;
    DestroyTask(taskId);
}

static void Task_MoveRelearner_Giveup_Answer(u8 taskId)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        if (gRelearnMode == RELEARN_MODE_SCRIPT)
            gSpecialVar_Result = FALSE;
        gTasks[taskId].func = Task_MoveRelearner_Quit;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        break;
    case 1: // No
    case MENU_B_PRESSED:
        gTasks[taskId].func = Task_MoveRelearner_HandleInput;
        ShowTeachMoveText();
        AddScrollArrows();
        break;
    }
}

static void Task_MoveRelearner_Giveup_Prompt(u8 taskId)
{

    if (IsTextPrinterActiveOnWindow(RELEARNERWIN_MSG))
        return;

    MoveRelearnerCreateYesNoMenu();
    gTasks[taskId].func = Task_MoveRelearner_Giveup_Answer;
}



static void Task_MoveRelearner_LearnMove(u8 taskId)
{
    if (IsTextPrinterActiveOnWindow(RELEARNERWIN_MSG))
        return;
    gTasks[taskId].tState = LearnMove(&sMoveLearnUI, taskId);
}

static bool32 UpdateMoveRelearnerState(void)
{
    u32 state;
    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();
    for (u32 i = 1; i < MOVE_RELEARNER_COUNT; i++)
    {
        state = (gMoveRelearnerState + i) % MOVE_RELEARNER_COUNT;
        if (CanBoxMonRelearnMoves(boxmon, state))
        {
            gMoveRelearnerState = state;
            StoreMoveText();
            return TRUE;
        }
    }
    return FALSE;
}

static void Task_MoveRelearner_HandleInput(u8 taskId)
{
    s32 itemId = ListMenu_ProcessInput(sMoveRelearnerStruct->moveListMenuTask);
    ListMenuGetScrollAndRow(sMoveRelearnerStruct->moveListMenuTask, &sMoveRelearnerScrollState.listOffset, &sMoveRelearnerScrollState.listRow);

    switch (itemId)
    {
    case LIST_NOTHING_CHOSEN:
        if (JOY_NEW(SELECT_BUTTON) && gRelearnMode != RELEARN_MODE_SCRIPT)
        {
            if (UpdateMoveRelearnerState())
            {
                PlaySE(SE_SUCCESS);
                sMoveRelearnerScrollState.listOffset = 0;
                sMoveRelearnerScrollState.listRow = 0;
                RedrawMoveList();
            }
            else if (GameHasDifferentRelearners())
            {
                PlaySE(SE_FAILURE);
            }
        }
        else if (!C_HIDE_CONTEST_DATA)
        {
            if (!(JOY_NEW(DPAD_LEFT | DPAD_RIGHT)) && !GetLRKeysPressed())
                break;

            PlaySE(SE_SELECT);

            if (gTasks[taskId].tCategory == BATTLE_INFO)
            {
                PutWindowTilemap(RELEARNERWIN_DESC_CONTEST);
                gTasks[taskId].tCategory = CONTEST_INFO;
            }
            else
            {
                PutWindowTilemap(RELEARNERWIN_DESC_BATTLE);
                gTasks[taskId].tCategory = BATTLE_INFO;
            }

            MoveRelearnerShowHideHearts(GetCurrentSelectedMove());

            ScheduleBgCopyTilemapToVram(1);

            if (B_SHOW_CATEGORY_ICON == TRUE)
                MoveRelearnerShowHideCategoryIcon(GetCurrentSelectedMove());
            AddScrollArrows();
        }
        break;
    case LIST_CANCEL:
        PlaySE(SE_SELECT);
        RemoveScrollArrows();
        gTasks[taskId].func = Task_MoveRelearner_Giveup_Prompt;
        if (gRelearnMode == RELEARN_MODE_SCRIPT)
            StringExpandPlaceholders(gStringVar4, gText_MoveRelearnerGiveUp);
        else
            StringExpandPlaceholders(gStringVar4, gText_MoveRelearnerStop);
        MoveRelearnerPrintMessage(gStringVar4);
        break;
    default:
        PlaySE(SE_SELECT);
        RemoveScrollArrows();
        StringCopy(gStringVar2, GetMoveName(itemId));
        gTasks[taskId].func = Task_MoveRelearner_LearnMove;
        gTasks[taskId].tMove = GetCurrentSelectedMove();
        gTasks[taskId].tState = GetLearnMoveStartAfterPromptState();
        const u8 *message = gText_MoveRelearnerTeachMoveConfirm;
        if (ShouldConsumeTmItem(gTasks[taskId].tMove))
        {
            enum Item item = GetTMHMItemIdFromMoveId(gTasks[taskId].tMove);
            StringCopy(gStringVar3, GetItemName(item));
            if (!GetItemImportance(item))
                message = gText_MoveRelearnerTeachMoveConfirmUseTm;
        }
        UIPrintMessage(message);
        break;
    }
}

static s32 GetCurrentSelectedMove(void)
{
    return sMoveRelearnerStruct->menuItems[sMoveRelearnerScrollState.listRow + sMoveRelearnerScrollState.listOffset].id;
}

static void ShowTeachMoveText(void)
{
    StringExpandPlaceholders(gStringVar4, gText_TeachWhichMoveToPkmn);
    FillWindowPixelBuffer(RELEARNERWIN_MSG, 0x11);
    AddTextPrinterParameterized(RELEARNERWIN_MSG, FONT_NORMAL, gStringVar4, 0, 1, 0, NULL);
}

static void CreateUISprites(void)
{
    int i;

    sMoveRelearnerStruct->moveDisplayArrowTask = TASK_NONE;
    sMoveRelearnerStruct->moveListScrollArrowTask = TASK_NONE;

    sMoveRelearnerStruct->categoryIconSpriteId = 0xFF;
    LoadCompressedSpriteSheet(&gSpriteSheet_CategoryIcons);
    LoadSpritePalette(&gSpritePal_CategoryIcons);

    // These are the appeal hearts.
    for (i = 0; i < 8; i++)
        sMoveRelearnerStruct->heartSpriteIds[i] = CreateSprite(&sConstestMoveHeartSprite, (i - (i / 4) * 4) * 8 + 104, (i / 4) * 8 + 36, 0);

    // These are the jam harts.
    // The animation is used to toggle between full/empty heart sprites.
    for (i = 0; i < 8; i++)
    {
        sMoveRelearnerStruct->heartSpriteIds[i + 8] = CreateSprite(&sConstestMoveHeartSprite, (i - (i / 4) * 4) * 8 + 104, (i / 4) * 8 + 52, 0);
        StartSpriteAnim(&gSprites[sMoveRelearnerStruct->heartSpriteIds[i + 8]], 2);
    }

    for (i = 0; i < 16; i++)
        gSprites[sMoveRelearnerStruct->heartSpriteIds[i]].invisible = TRUE;
}

static void AddScrollArrows(void)
{
    if (!C_HIDE_CONTEST_DATA && sMoveRelearnerStruct->moveDisplayArrowTask == TASK_NONE)
        sMoveRelearnerStruct->moveDisplayArrowTask = AddScrollIndicatorArrowPair(&sDisplayModeArrowsTemplate, &sMoveRelearnerStruct->scrollOffset);

    if (sMoveRelearnerStruct->moveListScrollArrowTask == TASK_NONE)
    {
        gTempScrollArrowTemplate = sMoveListScrollArrowsTemplate;
        gTempScrollArrowTemplate.fullyDownThreshold = sMoveRelearnerStruct->numMenuChoices - sMoveRelearnerStruct->numToShowAtOnce;
        sMoveRelearnerStruct->moveListScrollArrowTask = AddScrollIndicatorArrowPair(&gTempScrollArrowTemplate, &sMoveRelearnerScrollState.listOffset);
    }
}

static void RemoveScrollArrows(void)
{
    if (!C_HIDE_CONTEST_DATA && sMoveRelearnerStruct->moveDisplayArrowTask != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sMoveRelearnerStruct->moveDisplayArrowTask);
        sMoveRelearnerStruct->moveDisplayArrowTask = TASK_NONE;
    }

    if (sMoveRelearnerStruct->moveListScrollArrowTask != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sMoveRelearnerStruct->moveListScrollArrowTask);
        sMoveRelearnerStruct->moveListScrollArrowTask = TASK_NONE;
    }
}

static void CreateLearnableMovesList(void)
{
    s32 i;

    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();
    if (gRelearnMode == RELEARN_MODE_SCRIPT || sRelearnTypes[gMoveRelearnerState].isActive())
        sMoveRelearnerStruct->numMenuChoices = sRelearnTypes[gMoveRelearnerState].getMoves(boxmon, sMoveRelearnerStruct->movesToLearn);

    if (P_SORT_MOVES)
        SortMovesAlphabetically(sMoveRelearnerStruct->movesToLearn, sMoveRelearnerStruct->numMenuChoices);

    for (i = 0; i < sMoveRelearnerStruct->numMenuChoices; i++)
    {
        sMoveRelearnerStruct->menuItems[i].name = GetMoveName(sMoveRelearnerStruct->movesToLearn[i]);
        sMoveRelearnerStruct->menuItems[i].id = sMoveRelearnerStruct->movesToLearn[i];
    }

    GetBoxMonData(boxmon, MON_DATA_NICKNAME, gStringVar1);

    sMoveRelearnerStruct->menuItems[sMoveRelearnerStruct->numMenuChoices].name = gText_Cancel;
    sMoveRelearnerStruct->menuItems[sMoveRelearnerStruct->numMenuChoices].id = LIST_CANCEL;
    sMoveRelearnerStruct->numMenuChoices++;
    sMoveRelearnerStruct->numToShowAtOnce = LoadMoveRelearnerMovesList(sMoveRelearnerStruct->menuItems, sMoveRelearnerStruct->numMenuChoices);
}

void MoveRelearnerShowHideHearts(s32 move)
{
    u16 numHearts;
    u16 i;

    if (gTasks[sMoveRelearnerStruct->mainTask].tCategory == BATTLE_INFO || move == LIST_CANCEL)
    {
        for (i = 0; i < 16; i++)
            gSprites[sMoveRelearnerStruct->heartSpriteIds[i]].invisible = TRUE;
    }
    else
    {
        numHearts = (u8)(gContestEffects[GetMoveContestEffect(move)].appeal / 10);

        if (numHearts == 0xFF)
            numHearts = 0;

        for (i = 0; i < 8; i++)
        {
            if (i < numHearts)
                StartSpriteAnim(&gSprites[sMoveRelearnerStruct->heartSpriteIds[i]], 1);
            else
                StartSpriteAnim(&gSprites[sMoveRelearnerStruct->heartSpriteIds[i]], 0);
            gSprites[sMoveRelearnerStruct->heartSpriteIds[i]].invisible = FALSE;
        }

        numHearts = (u8)(gContestEffects[GetMoveContestEffect(move)].jam / 10);

        if (numHearts == 0xFF)
            numHearts = 0;

        for (i = 0; i < 8; i++)
        {
            if (i < numHearts)
                StartSpriteAnim(&gSprites[sMoveRelearnerStruct->heartSpriteIds[i + 8]], 3);
            else
                StartSpriteAnim(&gSprites[sMoveRelearnerStruct->heartSpriteIds[i + 8]], 2);
            gSprites[sMoveRelearnerStruct->heartSpriteIds[i + 8]].invisible = FALSE;
        }
    }
}

void MoveRelearnerShowHideCategoryIcon(s32 moveId)
{
    if (gTasks[sMoveRelearnerStruct->mainTask].tCategory == CONTEST_INFO || moveId == LIST_CANCEL)
    {
        if (sMoveRelearnerStruct->categoryIconSpriteId != 0xFF)
            DestroySprite(&gSprites[sMoveRelearnerStruct->categoryIconSpriteId]);

        sMoveRelearnerStruct->categoryIconSpriteId = 0xFF;
    }
    else
    {
        if (sMoveRelearnerStruct->categoryIconSpriteId == 0xFF)
            sMoveRelearnerStruct->categoryIconSpriteId = CreateSprite(&gSpriteTemplate_CategoryIcons, 66, 40, 0);

        gSprites[sMoveRelearnerStruct->categoryIconSpriteId].invisible = FALSE;
        StartSpriteAnim(&gSprites[sMoveRelearnerStruct->categoryIconSpriteId], GetBattleMoveCategory(moveId));
    }
}

static void QuickSortMoves(u16 *moves, s32 left, s32 right)
{
    if (left >= right)
        return;

    u16 pivot = moves[(left + right) / 2];
    s32 i = left, j = right;

    while (i <= j)
    {
        while (moves[i] != MOVE_NONE && StringCompare(GetMoveName(moves[i]), GetMoveName(pivot)) < 0)
            i++;
        while (moves[j] != MOVE_NONE && StringCompare(GetMoveName(moves[j]), GetMoveName(pivot)) > 0)
            j--;

        if (i <= j)
        {
            u16 temp = moves[i];
            moves[i] = moves[j];
            moves[j] = temp;
            i++;
            j--;
        }
    }

    QuickSortMoves(moves, left, j);
    QuickSortMoves(moves, i, right);
}

static void SortMovesAlphabetically(u16 *moves, u32 numMoves)
{
    if (numMoves > 1)
        QuickSortMoves(moves, 0, numMoves - 1);
}

static bool32 IsTmAvailable(enum Item item)
{
    if (P_ENABLE_ALL_TM_MOVES)
        return TRUE;
    if (gRelearnMode == RELEARN_MODE_SCRIPT)
        return TRUE;
    return CheckBagHasItem(item, 1);
}

static u32 GetRelearnerLevelUpMoves(struct BoxPokemon *mon, u16 *moves)
{
    enum Species species = GetBoxMonData(mon, MON_DATA_SPECIES);
    u32 level = (P_ENABLE_ALL_LEVEL_UP_MOVES ? MAX_LEVEL : GetLevelFromBoxMonExp(mon));
    u32 numMoves = 0;
    do
    {
        const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

        for (u32 i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
        {
            if (learnset[i].level > level)
                break;

            if (BoxMonKnowsMove(mon, learnset[i].move))
                continue;

            bool32 alreadyInList = FALSE;
            for (u32 j = 0; j < numMoves; j++)
            {
                if (learnset[i].move == moves[j])
                    alreadyInList = TRUE;
            }
            if (!alreadyInList)
                moves[numMoves++] = learnset[i].move;
        }

        species = (P_PRE_EVO_MOVES ? GetSpeciesPreEvolution(species) : SPECIES_NONE);
    } while (species != SPECIES_NONE);

    return numMoves;
}

static u32 GetRelearnerEggMoves(struct BoxPokemon *mon, u16 *moves)
{
    enum Species species = GetBoxMonData(mon, MON_DATA_SPECIES);
    u32 numMoves = 0;
    while (GetSpeciesPreEvolution(species) != SPECIES_NONE)
        species = GetSpeciesPreEvolution(species);

    const u16 *eggMoves = GetSpeciesEggMoves(species);

    if (eggMoves[0] == MOVE_UNAVAILABLE)
        return 0;

    for (u32 i = 0; eggMoves[i] != MOVE_UNAVAILABLE; i++)
    {
        if (!BoxMonKnowsMove(mon, eggMoves[i]))
            moves[numMoves++] = eggMoves[i];
    }

    return numMoves;
}

static u32 GetRelearnerTMMoves(struct BoxPokemon *mon, u16 *moves)
{
    enum Species species = GetBoxMonData(mon, MON_DATA_SPECIES);
    u32 numMoves = 0;

    for (u32 i = 0; i < NUM_ALL_MACHINES; i++)
    {
        enum Item item = GetTMHMItemId(i + 1);
        enum Move move = GetTMHMMoveId(i + 1);

        if (move == MOVE_NONE)
            continue;

        if (!IsTmAvailable(item))
            continue;

        if (!CanLearnTeachableMove(species, move))
            continue;

        if (!BoxMonKnowsMove(mon, move))
            moves[numMoves++] = move;
    }

    return numMoves;
}

static u32 GetRelearnerTutorMoves(struct BoxPokemon *mon, u16 *moves)
{
    enum Species species = GetBoxMonData(mon, MON_DATA_SPECIES);
    u32 numMoves = 0;

    for (u32 i = 0; gTutorMoves[i] != MOVE_UNAVAILABLE; i++)
    {
        enum Move move = gTutorMoves[i];

        if (!CanLearnTeachableMove(species, move))
            continue;

        if (!BoxMonKnowsMove(mon, move))
            moves[numMoves++] = move;
    }

    return numMoves;
}

void Special_HasMoveToRelearn(void)
{
    struct BoxPokemon *boxmon = GetSelectedBoxMonFromPcOrParty();
    if (HasMoveToRelearn(boxmon, gMoveRelearnerState))
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

bool32 CanBoxMonRelearnMoves(struct BoxPokemon *boxMon, enum MoveRelearnerStates state)
{
    if (!sRelearnTypes[state].isActive())
        return FALSE;
    if (GetBoxMonData(boxMon, MON_DATA_IS_EGG))
        return FALSE;
    return sRelearnTypes[state].hasMoveToRelearn(boxMon);
}

bool32 HasMoveToRelearn(struct BoxPokemon *boxMon, enum MoveRelearnerStates state)
{
    return sRelearnTypes[state].hasMoveToRelearn(boxMon);
}

static bool32 HasRelearnerLevelUpMoves(struct BoxPokemon *boxMon)
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    u32 level = (P_ENABLE_ALL_LEVEL_UP_MOVES == TRUE) ? MAX_LEVEL : GetLevelFromBoxMonExp(boxMon);

    do
    {
        const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

        for (u32 i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
        {
            if (learnset[i].level > level)
                break;

            if (!BoxMonKnowsMove(boxMon, learnset[i].move))
                return TRUE;
        }

        species = (P_PRE_EVO_MOVES ? GetSpeciesPreEvolution(species) : SPECIES_NONE);

    } while (species != SPECIES_NONE);

    return FALSE;
}

static bool32 HasRelearnerEggMoves(struct BoxPokemon *boxMon)
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    while (GetSpeciesPreEvolution(species) != SPECIES_NONE)
        species = GetSpeciesPreEvolution(species);

    const u16 *eggMoves = GetSpeciesEggMoves(species);

    if (eggMoves[0] == MOVE_UNAVAILABLE)
        return FALSE;

    for (u32 i = 0; eggMoves[i] != MOVE_UNAVAILABLE; i++)
    {
        if (!BoxMonKnowsMove(boxMon, eggMoves[i]))
            return TRUE;
    }

    return FALSE;
}

static bool32 HasRelearnerTMMoves(struct BoxPokemon *boxMon)
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    for (u32 i = 0; i < NUM_ALL_MACHINES; i++)
    {
        enum Item item = GetTMHMItemId(i + 1);
        enum Move move = GetTMHMMoveId(i + 1);

        if (move == MOVE_NONE)
            continue;

        bool32 tmAvailable = IsTmAvailable(item);
        if (!tmAvailable)
            continue;

        if (!CanLearnTeachableMove(species, move))
            continue;

        if (!BoxMonKnowsMove(boxMon, move))
            return TRUE;
    }

    return FALSE;
}

static bool32 HasRelearnerTutorMoves(struct BoxPokemon *boxMon)
{
    enum Species species = GetBoxMonData(boxMon, MON_DATA_SPECIES);
    for (u32 i = 0; gTutorMoves[i] != MOVE_UNAVAILABLE; i++)
    {
        enum Move move = gTutorMoves[i];

        if (!CanLearnTeachableMove(species, move))
            continue;

        if (!BoxMonKnowsMove(boxMon, move))
            return TRUE;
    }

    return FALSE;
}

static bool32 IsLevelUpMoveRelearnerActive(void)
{
    return TRUE;
}

static bool32 IsEggMoveRelearnerActive(void)
{
    return (FlagGet(P_FLAG_EGG_MOVES) || P_ENABLE_MOVE_RELEARNERS);
}

static bool32 IsTMMoveRelearnerActive(void)
{
    return (P_TM_MOVES_RELEARNER || P_ENABLE_MOVE_RELEARNERS);
}

static bool32 IsTutorMoveRelearnerActive(void)
{
    return (FlagGet(P_FLAG_TUTOR_MOVES) || P_ENABLE_MOVE_RELEARNERS);
}
