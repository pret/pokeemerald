#include "global.h"
#include "main.h"
#include "battle.h"
#include "bg.h"
#include "contest_effect.h"
#include "data2.h"
#include "event_data.h"
#include "field_screen_effect.h"
#include "gpu_regs.h"
#include "move_tutor.h"
#include "list_menu.h"
#include "alloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon_summary_screen.h"
#include "pokenav.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "constants/rgb.h"
#include "constants/songs.h"

/*
 * Move tutor state machine
 * ------------------------
 * 
 * Entry point: TeachMoveTutorMove
 * 
 * TeachMoveTutorMove
 * Task_WaitForFadeOut
 * CB2_InitLearnMove
 *   - Creates moveDisplayArrowTask to listen to right/left buttons.
 *   - Creates moveListScrollArrowTask to listen to up/down buttons.
 *   - Whenever the selected move changes (and once on init), the MoveTutorCursorCallback
 *     is called (see gMoveTutorMovesListTemplate). That callback will reload the contest
 *     display and battle display windows for the new move. Both are always loaded in
 *     memory, but only the currently active one is copied to VRAM. The exception to this
 *     is the appeal and jam hearts, which are sprites. MoveTutorShowHideHearts is called
 *     while reloading the contest display to control them.
 * DoMoveTutorMain: MENU_STATE_FADE_TO_BLACK
 * DoMoveTutorMain: MENU_STATE_WAIT_FOR_FADE
 *   - Go to MENU_STATE_IDLE_BATTLE_MODE
 * 
 * DoMoveTutorMain: MENU_STATE_SETUP_BATTLE_MODE
 * DoMoveTutorMain: MENU_STATE_IDLE_BATTLE_MODE
 *   - If the player selected a move (pressed A), go to MENU_STATE_PRINT_TEACH_MOVE_PROMPT.
 *   - If the player cancelled (pressed B), go to MENU_STATE_PRINT_GIVE_UP_PROMPT.
 *   - If the player pressed left or right, swap the move display window to contest mode,
 *     and go to MENU_STATE_SETUP_CONTEST_MODE.
 * 
 * DoMoveTutorMain: MENU_STATE_SETUP_CONTEST_MODE
 * DoMoveTutorMain: MENU_STATE_IDLE_CONTEST_MODE
 *   - If the player selected a move, go to MENU_STATE_PRINT_TEACH_MOVE_PROMPT.
 *   - If the player cancelled, go to MENU_STATE_PRINT_GIVE_UP_PROMPT
 *   - If the player pressed left or right, swap the move display window to battle mode,
 *     and go to MENU_STATE_SETUP_BATTLE_MODE.
 * 
 * DoMoveTutorMain: MENU_STATE_PRINT_TEACH_MOVE_PROMPT
 * DoMoveTutorMain: MENU_STATE_TEACH_MOVE_CONFIRM
 *   - Wait for the player to confirm.
 *   - If cancelled, go to either MENU_STATE_SETUP_BATTLE_MODE or MENU_STATE_SETUP_CONTEST_MODE.
 *   - If confirmed and the pokemon had an empty move slot, set VAR_0x8004 to TRUE and go to
 *     MENU_STATE_PRINT_TEXT_THEN_FANFARE.
 *   - If confirmed and the pokemon doesn't have an empty move slot, go to
 *     MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT.
 * 
 * DoMoveTutorMain: MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT
 * DoMoveTutorMain: MENU_STATE_WAIT_FOR_TRYING_TO_LEARN
 * DoMoveTutorMain: MENU_STATE_CONFIRM_DELETE_OLD_MOVE
 *   - If the player confirms, go to MENU_STATE_PRINT_WHICH_MOVE_PROMPT.
 *   - If the player cancels, go to MENU_STATE_PRINT_STOP_TEACHING
 * 
 * DoMoveTutorMain: MENU_STATE_PRINT_STOP_TEACHING
 * DoMoveTutorMain: MENU_STATE_WAIT_FOR_STOP_TEACHING
 * DoMoveTutorMain: MENU_STATE_CONFIRM_STOP_TEACHING
 *   - If the player confirms, go to MENU_STATE_CHOOSE_SETUP_STATE.
 *   - If the player cancels, go back to MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT.
 * 
 * DoMoveTutorMain: MENU_STATE_PRINT_WHICH_MOVE_PROMPT
 * DoMoveTutorMain: MENU_STATE_SHOW_MOVE_SUMMARY_SCREEN
 *   - Go to ShowSelectMovePokemonSummaryScreen. When done, control returns to
 *     CB2_InitLearnMoveReturnFromSelectMove.
 * 
 * DoMoveTutorMain: MENU_STATE_DOUBLE_FANFARE_FORGOT_MOVE
 * DoMoveTutorMain: MENU_STATE_PRINT_TEXT_THEN_FANFARE
 * DoMoveTutorMain: MENU_STATE_WAIT_FOR_FANFARE
 * DoMoveTutorMain: MENU_STATE_WAIT_FOR_A_BUTTON
 * DoMoveTutorMain: MENU_STATE_FADE_AND_RETURN
 * DoMoveTutorMain: MENU_STATE_RETURN_TO_FIELD
 *   - Clean up and go to CB2_ReturnToField.
 * 
 * DoMoveTutorMain: MENU_STATE_PRINT_GIVE_UP_PROMPT
 * DoMoveTutorMain: MENU_STATE_GIVE_UP_CONFIRM
 *   - If the player confirms, go to MENU_STATE_FADE_AND_RETURN, and set VAR_0x8004 to FALSE.
 *   - If the player cancels, go to either MENU_STATE_SETUP_BATTLE_MODE or
 *     MENU_STATE_SETUP_CONTEST_MODE.
 * 
 * CB2_InitLearnMoveReturnFromSelectMove:
 *   - Do most of the same stuff as CB2_InitLearnMove.
 * DoMoveTutorMain: MENU_STATE_FADE_FROM_SUMMARY_SCREEN
 * DoMoveTutorMain: MENU_STATE_TRY_OVERWRITE_MOVE
 *   - If any of the pokemon's existing moves were chosen, overwrite the move and
 *     go to MENU_STATE_DOUBLE_FANFARE_FORGOT_MOVE and set VAR_0x8004 to TRUE.
 *   - If the chosen move is the one the player selected before the summary screen,
 *     go to MENU_STATE_PRINT_STOP_TEACHING.
 * 
 */

#define MENU_STATE_FADE_TO_BLACK 0
#define MENU_STATE_WAIT_FOR_FADE 1
#define MENU_STATE_UNREACHABLE 2
#define MENU_STATE_SETUP_BATTLE_MODE 3
#define MENU_STATE_IDLE_BATTLE_MODE 4
#define MENU_STATE_SETUP_CONTEST_MODE 5
#define MENU_STATE_IDLE_CONTEST_MODE 6
// State 7 is skipped.
#define MENU_STATE_PRINT_TEACH_MOVE_PROMPT 8
#define MENU_STATE_TEACH_MOVE_CONFIRM 9
// States 10 and 11 are skipped.
#define MENU_STATE_PRINT_GIVE_UP_PROMPT 12
#define MENU_STATE_GIVE_UP_CONFIRM 13
#define MENU_STATE_FADE_AND_RETURN 14
#define MENU_STATE_RETURN_TO_FIELD 15
#define MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT 16
#define MENU_STATE_WAIT_FOR_TRYING_TO_LEARN 17
#define MENU_STATE_CONFIRM_DELETE_OLD_MOVE 18
#define MENU_STATE_PRINT_WHICH_MOVE_PROMPT 19
#define MENU_STATE_SHOW_MOVE_SUMMARY_SCREEN 20
// States 21, 22, and 23 are skipped.
#define MENU_STATE_PRINT_STOP_TEACHING 24
#define MENU_STATE_WAIT_FOR_STOP_TEACHING 25
#define MENU_STATE_CONFIRM_STOP_TEACHING 26
#define MENU_STATE_CHOOSE_SETUP_STATE 27
#define MENU_STATE_FADE_FROM_SUMMARY_SCREEN 28
#define MENU_STATE_TRY_OVERWRITE_MOVE 29
#define MENU_STATE_DOUBLE_FANFARE_FORGOT_MOVE 30
#define MENU_STATE_PRINT_TEXT_THEN_FANFARE 31
#define MENU_STATE_WAIT_FOR_FANFARE 32
#define MENU_STATE_WAIT_FOR_A_BUTTON 33

// The different versions of hearts are selected using animation
// commands.
#define APPEAL_HEART_EMPTY 0
#define APPEAL_HEART_FULL 1
#define JAM_HEART_EMPTY 2
#define JAM_HEART_FULL 3

static EWRAM_DATA struct
{
    u8 state;
    u8 heartSpriteIds[16];              /*0x001*/
    u16 movesToLearn[4];                /*0x012*/
    u8 filler1A[0x44 - 0x1A];           /*0x01A*/
    u8 partyMon;                        /*0x044*/
    u8 moveSlot;                        /*0x045*/
    struct ListMenuItem menuItems[20];  /*0x048*/
    u8 fillerE8[0x110 - 0xE8];          /*0x0E8*/
    u8 numMenuChoices;                  /*0x110*/
    u8 numToShowAtOnce;                 /*0x111*/
    u8 moveListMenuTask;                    /*0x112*/
    u8 moveListScrollArrowTask;         /*0x113*/
    u8 moveDisplayArrowTask;            /*0x114*/
    u16 scrollOffset;                   /*0x116*/
} *sMoveTutorStruct = {0};

static EWRAM_DATA struct {
    u16 listOffset;
    u16 listRow;
    bool8 showContestInfo;
} sMoveTutorMenuSate = {0};

static const u16 sMoveTutorPaletteData[] = INCBIN_U16("graphics/interface/ui_learn_move.gbapal");

// The arrow sprites in this spritesheet aren't used. The scroll-arrow system provides its own
// arrow sprites.
static const u8 sMoveTutorSpriteSheetData[] = INCBIN_U8("graphics/interface/ui_learn_move.4bpp");

static const struct OamData sHeartSpriteOamData =
{
    .y = 0,
    .affineMode = 0,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_SQUARE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sUnusedOam1 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_V_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sUnusedOam2 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = ST_OAM_H_RECTANGLE,
    .x = 0,
    .matrixNum = 0,
    .size = 0,
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sMoveTutorSpriteSheet =
{
    .data = sMoveTutorSpriteSheetData,
    .size = 0x180,
    .tag = 5525
};

static const struct SpritePalette sMoveTutorPalette =
{
    .data = sMoveTutorPaletteData,
    .tag = 5526
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
    .tileTag = 5325,
    .palTag = 5325,
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
    .tileTag = 5425,
    .palTag = 5425,
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
    .tileTag = 5525,
    .paletteTag = 5526,
    .oam = &sHeartSpriteOamData,
    .anims = sHeartSpriteAnimationCommands,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct BgTemplate sMoveTutorMenuBackgroundTemplates[] =
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

static void DoMoveTutorMain(void);
static void CreateLearnableMovesList(void);
static void CreateUISprites(void);
static void CB2_MoveTutorMain(void);
static void Task_WaitForFadeOut(u8 taskId);
static void CB2_InitLearnMove(void);
static void CB2_InitLearnMoveReturnFromSelectMove(void);
static void InitMoveTutorBackgroundLayers(void);
static void AddScrollArrows(void);
static void HandleInput(u8);
static void ShowTeachMoveText(u8);
static s32 GetCurrentSelectedMove(void);
static void FreeMoveTutorResources(void);
static void RemoveScrollArrows(void);
static void HideHeartSpritesAndShowTeachMoveText(bool8);

static void VBlankCB_MoveTutor(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

// Script arguments: The pokemon to teach is in VAR_0x8004
void TeachMoveTutorMove(void)
{
    ScriptContext2_Enable();
    CreateTask(Task_WaitForFadeOut, 10);
    // Fade to black
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
}

static void Task_WaitForFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_InitLearnMove);
        gFieldCallback = FieldCallback_ReturnToEventScript2;
        DestroyTask(taskId);
    }
}

static void CB2_InitLearnMove(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    clear_scheduled_bg_copies_to_vram();
    sMoveTutorStruct = AllocZeroed(sizeof(*sMoveTutorStruct));
    sMoveTutorStruct->partyMon = gSpecialVar_0x8004;
    SetVBlankCallback(VBlankCB_MoveTutor);

    InitMoveTutorBackgroundLayers();
    InitMoveTutorWindows(FALSE);

    sMoveTutorMenuSate.listOffset = 0;
    sMoveTutorMenuSate.listRow = 0;
    sMoveTutorMenuSate.showContestInfo = FALSE;

    CreateLearnableMovesList();

    LoadSpriteSheet(&sMoveTutorSpriteSheet);
    LoadSpritePalette(&sMoveTutorPalette);
    CreateUISprites();

    sMoveTutorStruct->moveListMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, sMoveTutorMenuSate.listOffset, sMoveTutorMenuSate.listRow);
    FillPalette(RGB_BLACK, 0, 2);
    SetMainCallback2(CB2_MoveTutorMain);
}

static void CB2_InitLearnMoveReturnFromSelectMove(void)
{
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    clear_scheduled_bg_copies_to_vram();
    sMoveTutorStruct = AllocZeroed(sizeof(*sMoveTutorStruct));
    sMoveTutorStruct->state = MENU_STATE_FADE_FROM_SUMMARY_SCREEN;
    sMoveTutorStruct->partyMon = gSpecialVar_0x8004;
    sMoveTutorStruct->moveSlot = gSpecialVar_0x8005;
    SetVBlankCallback(VBlankCB_MoveTutor);

    InitMoveTutorBackgroundLayers();
    InitMoveTutorWindows(sMoveTutorMenuSate.showContestInfo);
    CreateLearnableMovesList();

    LoadSpriteSheet(&sMoveTutorSpriteSheet);
    LoadSpritePalette(&sMoveTutorPalette);
    CreateUISprites();

    sMoveTutorStruct->moveListMenuTask = ListMenuInit(&gMultiuseListMenuTemplate, sMoveTutorMenuSate.listOffset, sMoveTutorMenuSate.listRow);
    FillPalette(RGB_BLACK, 0, 2);
    SetMainCallback2(CB2_MoveTutorMain);
}

static void InitMoveTutorBackgroundLayers(void)
{
    ResetVramOamAndBgCntRegs();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMoveTutorMenuBackgroundTemplates, ARRAY_COUNT(sMoveTutorMenuBackgroundTemplates));
    ResetAllBgsCoordinates();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 |
                                  DISPCNT_OBJ_1D_MAP |
                                  DISPCNT_OBJ_ON);
    ShowBg(0);
    ShowBg(1);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
}

static void CB2_MoveTutorMain(void)
{
    DoMoveTutorMain();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    do_scheduled_bg_tilemap_copies_to_vram();
    UpdatePaletteFade();
}

static void FormatAndPrintText(const u8 *src)
{
    StringExpandPlaceholders(gStringVar4, src);
    MoveTutorPrintText(gStringVar4);
}

// See the state machine doc at the top of the file.
static void DoMoveTutorMain(void)
{
    switch (sMoveTutorStruct->state)
    {
    case MENU_STATE_FADE_TO_BLACK:
        sMoveTutorStruct->state++;
        HideHeartSpritesAndShowTeachMoveText(FALSE);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        break;
    case MENU_STATE_WAIT_FOR_FADE:
        if (!gPaletteFade.active)
        {
            sMoveTutorStruct->state = MENU_STATE_IDLE_BATTLE_MODE;
        }
        break;
    case MENU_STATE_UNREACHABLE:
        sMoveTutorStruct->state++;
        break;
    case MENU_STATE_SETUP_BATTLE_MODE:

        HideHeartSpritesAndShowTeachMoveText(FALSE);
        sMoveTutorStruct->state++;
        AddScrollArrows();
        break;
    case MENU_STATE_IDLE_BATTLE_MODE:
        HandleInput(FALSE);
        break;
    case MENU_STATE_SETUP_CONTEST_MODE:
        ShowTeachMoveText(FALSE);
        sMoveTutorStruct->state++;
        AddScrollArrows();
        break;
    case MENU_STATE_IDLE_CONTEST_MODE:
        HandleInput(TRUE);
        break;
    case MENU_STATE_PRINT_TEACH_MOVE_PROMPT:
        if (!MoveTutorRunTextPrinters())
        {
            MoveTutorCreateYesNoMenu();
            sMoveTutorStruct->state++;
        }
        break;
    case MENU_STATE_TEACH_MOVE_CONFIRM:
        {
            s8 selection = Menu_ProcessInputNoWrapClearOnChoose();

            if (selection == 0)
            {
                if (GiveMoveToMon(&gPlayerParty[sMoveTutorStruct->partyMon], GetCurrentSelectedMove()) != 0xFFFF)
                {
                    FormatAndPrintText(gText_MoveTutorPkmnLearnedMove);
                    gSpecialVar_0x8004 = TRUE;
                    sMoveTutorStruct->state = MENU_STATE_PRINT_TEXT_THEN_FANFARE;
                }
                else
                {
                    sMoveTutorStruct->state = MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT;
                }
            }
            else if (selection == MENU_B_PRESSED || selection == 1)
            {
                if (sMoveTutorMenuSate.showContestInfo == FALSE)
                {
                    sMoveTutorStruct->state = MENU_STATE_SETUP_BATTLE_MODE;
                }
                else if (sMoveTutorMenuSate.showContestInfo == TRUE)
                {
                    sMoveTutorStruct->state = MENU_STATE_SETUP_CONTEST_MODE;
                }
            }
        }
        break;
    case MENU_STATE_PRINT_GIVE_UP_PROMPT:
        if (!MoveTutorRunTextPrinters())
        {
            MoveTutorCreateYesNoMenu();
            sMoveTutorStruct->state++;
        }
        break;
    case MENU_STATE_GIVE_UP_CONFIRM:
        {
            s8 selection = Menu_ProcessInputNoWrapClearOnChoose();

            if (selection == 0)
            {
                gSpecialVar_0x8004 = FALSE;
                sMoveTutorStruct->state = MENU_STATE_FADE_AND_RETURN;
            }
            else if (selection == -1 || selection == 1)
            {
                if (sMoveTutorMenuSate.showContestInfo == FALSE)
                {
                    sMoveTutorStruct->state = MENU_STATE_SETUP_BATTLE_MODE;
                }
                else if (sMoveTutorMenuSate.showContestInfo == TRUE)
                {
                    sMoveTutorStruct->state = MENU_STATE_SETUP_CONTEST_MODE;
                }
            }
        }
        break;
    case MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT:
        FormatAndPrintText(gText_MoveTutorPkmnTryingToLearnMove);
        sMoveTutorStruct->state++;
        break;
    case MENU_STATE_WAIT_FOR_TRYING_TO_LEARN:
        if (!MoveTutorRunTextPrinters())
        {
            MoveTutorCreateYesNoMenu();
            sMoveTutorStruct->state = MENU_STATE_CONFIRM_DELETE_OLD_MOVE;
        }
        break;
    case MENU_STATE_CONFIRM_DELETE_OLD_MOVE:
        {
            s8 var = Menu_ProcessInputNoWrapClearOnChoose();

            if (var == 0)
            {
                FormatAndPrintText(gText_MoveTutorWhichMoveToForget);
                sMoveTutorStruct->state = MENU_STATE_PRINT_WHICH_MOVE_PROMPT;
            }
            else if (var == -1 || var == 1)
            {
                sMoveTutorStruct->state = MENU_STATE_PRINT_STOP_TEACHING;
            }
        }
        break;
    case MENU_STATE_PRINT_STOP_TEACHING:
        StringCopy(gStringVar2, gMoveNames[GetCurrentSelectedMove()]);
        FormatAndPrintText(gText_MoveTutorStopTryingToTeachMove);
        sMoveTutorStruct->state++;
        break;
    case MENU_STATE_WAIT_FOR_STOP_TEACHING:
        if (!MoveTutorRunTextPrinters())
        {
            MoveTutorCreateYesNoMenu();
            sMoveTutorStruct->state++;
        }
        break;
    case MENU_STATE_CONFIRM_STOP_TEACHING:
        {
            s8 var = Menu_ProcessInputNoWrapClearOnChoose();

            if (var == 0)
            {
                sMoveTutorStruct->state = MENU_STATE_CHOOSE_SETUP_STATE;
            }
            else if (var == MENU_B_PRESSED || var == 1)
            {
                // What's the point? It gets set to MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT, anyway.
                if (sMoveTutorMenuSate.showContestInfo == FALSE)
                {
                    sMoveTutorStruct->state = MENU_STATE_SETUP_BATTLE_MODE;
                }
                else if (sMoveTutorMenuSate.showContestInfo == TRUE)
                {
                    sMoveTutorStruct->state = MENU_STATE_SETUP_CONTEST_MODE;
                }
                sMoveTutorStruct->state = MENU_STATE_PRINT_TRYING_TO_LEARN_PROMPT;
            }
        }
        break;
    case MENU_STATE_CHOOSE_SETUP_STATE:
        if (!MoveTutorRunTextPrinters())
        {
            FillWindowPixelBuffer(3, 0x11);
            if (sMoveTutorMenuSate.showContestInfo == FALSE)
            {
                sMoveTutorStruct->state = MENU_STATE_SETUP_BATTLE_MODE;
            }
            else if (sMoveTutorMenuSate.showContestInfo == TRUE)
            {
                sMoveTutorStruct->state = MENU_STATE_SETUP_CONTEST_MODE;
            }
        }
        break;
    case MENU_STATE_PRINT_WHICH_MOVE_PROMPT:
        if (!MoveTutorRunTextPrinters())
        {
            sMoveTutorStruct->state = MENU_STATE_SHOW_MOVE_SUMMARY_SCREEN;
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        }
        break;
    case MENU_STATE_SHOW_MOVE_SUMMARY_SCREEN:
        if (!gPaletteFade.active)
        {
            ShowSelectMovePokemonSummaryScreen(gPlayerParty, sMoveTutorStruct->partyMon, gPlayerPartyCount - 1, CB2_InitLearnMoveReturnFromSelectMove, GetCurrentSelectedMove());
            FreeMoveTutorResources();
        }
        break;
    case 21:
        if (!MoveTutorRunTextPrinters())
        {
            sMoveTutorStruct->state = MENU_STATE_FADE_AND_RETURN;
        }
        break;
    case 22:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        break;
    case MENU_STATE_FADE_AND_RETURN:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        sMoveTutorStruct->state++;
        break;
    case MENU_STATE_RETURN_TO_FIELD:
        if (!gPaletteFade.active)
        {
            FreeMoveTutorResources();
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    case MENU_STATE_FADE_FROM_SUMMARY_SCREEN:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        sMoveTutorStruct->state++;
        if (sMoveTutorMenuSate.showContestInfo == FALSE)
        {
            HideHeartSpritesAndShowTeachMoveText(TRUE);
        }
        else if (sMoveTutorMenuSate.showContestInfo == TRUE)
        {
            ShowTeachMoveText(TRUE);
        }
        RemoveScrollArrows();
        CopyWindowToVram(3, 2);
        break;
    case MENU_STATE_TRY_OVERWRITE_MOVE:
        if (!gPaletteFade.active)
        {
            if (sMoveTutorStruct->moveSlot == MAX_MON_MOVES)
            {
                sMoveTutorStruct->state = MENU_STATE_PRINT_STOP_TEACHING;
            }
            else
            {
                u16 moveId = GetMonData(&gPlayerParty[sMoveTutorStruct->partyMon], MON_DATA_MOVE1 + sMoveTutorStruct->moveSlot);

                StringCopy(gStringVar3, gMoveNames[moveId]);
                RemoveMonPPBonus(&gPlayerParty[sMoveTutorStruct->partyMon], sMoveTutorStruct->moveSlot);
                SetMonMoveSlot(&gPlayerParty[sMoveTutorStruct->partyMon], GetCurrentSelectedMove(), sMoveTutorStruct->moveSlot);
                StringCopy(gStringVar2, gMoveNames[GetCurrentSelectedMove()]);
                FormatAndPrintText(gText_MoveTutorAndPoof);
                sMoveTutorStruct->state = MENU_STATE_DOUBLE_FANFARE_FORGOT_MOVE;
                gSpecialVar_0x8004 = TRUE;
            }
        }
        break;
    case MENU_STATE_DOUBLE_FANFARE_FORGOT_MOVE:
        if (!MoveTutorRunTextPrinters())
        {
            FormatAndPrintText(gText_MoveTutorPkmnForgotMoveAndLearnedNew);
            sMoveTutorStruct->state = MENU_STATE_PRINT_TEXT_THEN_FANFARE;
            PlayFanfare(MUS_FANFA1);
        }
        break;
    case MENU_STATE_PRINT_TEXT_THEN_FANFARE:
        if (!MoveTutorRunTextPrinters())
        {
            PlayFanfare(MUS_FANFA1);
            sMoveTutorStruct->state = MENU_STATE_WAIT_FOR_FANFARE;
        }
        break;
    case MENU_STATE_WAIT_FOR_FANFARE:
        if (IsFanfareTaskInactive())
        {
            sMoveTutorStruct->state = MENU_STATE_WAIT_FOR_A_BUTTON;
        }
        break;
    case MENU_STATE_WAIT_FOR_A_BUTTON:
        if (gMain.newKeys & A_BUTTON)
        {
            PlaySE(SE_SELECT);
            sMoveTutorStruct->state = MENU_STATE_FADE_AND_RETURN;
        }
        break;
    }
}

static void FreeMoveTutorResources(void)
{
    RemoveScrollArrows();
    DestroyListMenuTask(sMoveTutorStruct->moveListMenuTask, &sMoveTutorMenuSate.listOffset, &sMoveTutorMenuSate.listRow);
    FreeAllWindowBuffers();
    FREE_AND_SET_NULL(sMoveTutorStruct);
    ResetSpriteData();
    FreeAllSpritePalettes();
}

// Note: The hearts are already made invisible by MoveTutorShowHideHearts,
// which is called whenever the cursor in either list changes.
static void HideHeartSpritesAndShowTeachMoveText(bool8 onlyHideSprites)
{
    s32 i;

    for (i = 0; i < 16; i++)
    {
        gSprites[sMoveTutorStruct->heartSpriteIds[i]].invisible = TRUE;
    }

    if (!onlyHideSprites)
    {
        StringExpandPlaceholders(gStringVar4, gText_TeachWhichMoveToPkmn);
        FillWindowPixelBuffer(3, 0x11);
        AddTextPrinterParameterized(3, 1, gStringVar4, 0, 1, 0, NULL);
    }
}

static void HandleInput(bool8 showContest)
{
    s32 itemId = ListMenu_ProcessInput(sMoveTutorStruct->moveListMenuTask);
    ListMenuGetScrollAndRow(sMoveTutorStruct->moveListMenuTask, &sMoveTutorMenuSate.listOffset, &sMoveTutorMenuSate.listRow);

    switch (itemId)
    {
    case LIST_NOTHING_CHOSEN:
        if (!(gMain.newKeys & (DPAD_LEFT | DPAD_RIGHT)) && !GetLRKeysState())
        {
            break;
        }

        PlaySE(SE_SELECT);

        if (showContest == FALSE)
        {
            PutWindowTilemap(1);
            sMoveTutorStruct->state = MENU_STATE_SETUP_CONTEST_MODE;
            sMoveTutorMenuSate.showContestInfo = TRUE;
        }
        else
        {
            PutWindowTilemap(0);
            sMoveTutorStruct->state = MENU_STATE_SETUP_BATTLE_MODE;
            sMoveTutorMenuSate.showContestInfo = FALSE;
        }

        schedule_bg_copy_tilemap_to_vram(1);
        MoveTutorShowHideHearts(GetCurrentSelectedMove());
        break;
    case LIST_CANCEL:
        PlaySE(SE_SELECT);
        RemoveScrollArrows();
        sMoveTutorStruct->state = MENU_STATE_PRINT_GIVE_UP_PROMPT;
        StringExpandPlaceholders(gStringVar4, gText_MoveTutorGiveUp);
        MoveTutorPrintText(gStringVar4);
        break;
    default:
        PlaySE(SE_SELECT);
        RemoveScrollArrows();
        sMoveTutorStruct->state = MENU_STATE_PRINT_TEACH_MOVE_PROMPT;
        StringCopy(gStringVar2, gMoveNames[itemId]);
        StringExpandPlaceholders(gStringVar4, gText_MoveTutorTeachMoveConfirm);
        MoveTutorPrintText(gStringVar4);
        break;
    }
}

static s32 GetCurrentSelectedMove(void)
{
    return sMoveTutorStruct->menuItems[sMoveTutorMenuSate.listRow + sMoveTutorMenuSate.listOffset].id;
}

// Theory: This used to make the heart sprites visible again (i.e.
// this was the inverse of HideHeartsAndShowTeachMoveText), but the
// code was commented out. The bool argument would have been named
// "justShowHearts." The code for showing/hiding the heards was moved
// to MoveTutorShowHideHearts, which is called whenever a new move is
// selected and whenever the display mode changes.
static void ShowTeachMoveText(bool8 shouldDoNothingInstead)
{
    if (shouldDoNothingInstead == FALSE)
    {
        StringExpandPlaceholders(gStringVar4, gText_TeachWhichMoveToPkmn);
        FillWindowPixelBuffer(3, 0x11);
        AddTextPrinterParameterized(3, 1, gStringVar4, 0, 1, 0, NULL);
    }
}

static void CreateUISprites(void)
{
    int i;

    sMoveTutorStruct->moveDisplayArrowTask = 0xFF;
    sMoveTutorStruct->moveListScrollArrowTask = 0xFF;
    AddScrollArrows();

    // These are the appeal hearts.
    for (i = 0; i < 8; i++)
    {
        sMoveTutorStruct->heartSpriteIds[i] = CreateSprite(&sConstestMoveHeartSprite, (i - (i / 4) * 4) * 8 + 104, (i / 4) * 8 + 36, 0);
    }

    // These are the jam harts.
    // The animation is used to toggle between full/empty heart sprites.
    for (i = 0; i < 8; i++)
    {
        sMoveTutorStruct->heartSpriteIds[i + 8] = CreateSprite(&sConstestMoveHeartSprite, (i - (i / 4) * 4) * 8 + 104, (i / 4) * 8 + 52, 0);
        StartSpriteAnim(&gSprites[sMoveTutorStruct->heartSpriteIds[i + 8]], 2);
    }

    for (i = 0; i < 16; i++)
    {
        gSprites[sMoveTutorStruct->heartSpriteIds[i]].invisible = TRUE;
    }
}

static void AddScrollArrows(void)
{
    if (sMoveTutorStruct->moveDisplayArrowTask == 0xFF)
    {
        sMoveTutorStruct->moveDisplayArrowTask = AddScrollIndicatorArrowPair(&sDisplayModeArrowsTemplate, &sMoveTutorStruct->scrollOffset);
    }

    if (sMoveTutorStruct->moveListScrollArrowTask == 0xFF)
    {
        gTempScrollArrowTemplate = sMoveListScrollArrowsTemplate;
        gTempScrollArrowTemplate.fullyDownThreshold = sMoveTutorStruct->numMenuChoices - sMoveTutorStruct->numToShowAtOnce;
        sMoveTutorStruct->moveListScrollArrowTask = AddScrollIndicatorArrowPair(&gTempScrollArrowTemplate, &sMoveTutorMenuSate.listOffset);
    }
}

static void RemoveScrollArrows(void)
{
    if (sMoveTutorStruct->moveDisplayArrowTask != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sMoveTutorStruct->moveDisplayArrowTask);
        sMoveTutorStruct->moveDisplayArrowTask = 0xFF;
    }

    if (sMoveTutorStruct->moveListScrollArrowTask != 0xFF)
    {
        RemoveScrollIndicatorArrowPair(sMoveTutorStruct->moveListScrollArrowTask);
        sMoveTutorStruct->moveListScrollArrowTask = 0xFF;
    }
}

static void CreateLearnableMovesList(void)
{
    s32 i;
    u8 nickname[POKEMON_NAME_LENGTH + 1];

    sMoveTutorStruct->numMenuChoices = GetMoveRelearnerMoves(&gPlayerParty[sMoveTutorStruct->partyMon], sMoveTutorStruct->movesToLearn);

    for (i = 0; i < sMoveTutorStruct->numMenuChoices; i++)
    {
        sMoveTutorStruct->menuItems[i].name = gMoveNames[sMoveTutorStruct->movesToLearn[i]];
        sMoveTutorStruct->menuItems[i].id = sMoveTutorStruct->movesToLearn[i];
    }

    GetMonData(&gPlayerParty[sMoveTutorStruct->partyMon], MON_DATA_NICKNAME, nickname);
    StringCopy10(gStringVar1, nickname);
    sMoveTutorStruct->menuItems[sMoveTutorStruct->numMenuChoices].name = gText_Cancel;
    sMoveTutorStruct->menuItems[sMoveTutorStruct->numMenuChoices].id = LIST_CANCEL;
    sMoveTutorStruct->numMenuChoices++;
    sMoveTutorStruct->numToShowAtOnce = LoadMoveTutorMovesList(sMoveTutorStruct->menuItems, sMoveTutorStruct->numMenuChoices);
}

void MoveTutorShowHideHearts(s32 moveId)
{
    u16 numHearts;
    u16 i;

    if (!sMoveTutorMenuSate.showContestInfo || moveId == LIST_CANCEL)
    {
        for (i = 0; i < 16; i++)
        {
            gSprites[sMoveTutorStruct->heartSpriteIds[i]].invisible = TRUE;
        }
    }
    else
    {
        numHearts = (u8)(gContestEffects[gContestMoves[moveId].effect].appeal / 10);

        if (numHearts == 0xFF)
        {
            numHearts = 0;
        }

        for (i = 0; i < 8; i++)
        {
            if (i < numHearts)
            {
                StartSpriteAnim(&gSprites[sMoveTutorStruct->heartSpriteIds[i]], 1);
            }
            else
            {
                StartSpriteAnim(&gSprites[sMoveTutorStruct->heartSpriteIds[i]], 0);
            }
            gSprites[sMoveTutorStruct->heartSpriteIds[i]].invisible = FALSE;
        }

        numHearts = (u8)(gContestEffects[gContestMoves[moveId].effect].jam / 10);

        if (numHearts == 0xFF)
        {
            numHearts = 0;
        }

        for (i = 0; i < 8; i++)
        {
            if (i < numHearts)
            {
                StartSpriteAnim(&gSprites[sMoveTutorStruct->heartSpriteIds[i + 8]], 3);
            }
            else
            {
                StartSpriteAnim(&gSprites[sMoveTutorStruct->heartSpriteIds[i + 8]], 2);
            }
            gSprites[sMoveTutorStruct->heartSpriteIds[i + 8]].invisible = FALSE;
        }
    }
}
