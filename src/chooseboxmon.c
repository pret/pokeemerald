#include "global.h"
#include "chooseboxmon.h"
#include "daycare.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_weather.h"
#include "malloc.h"
#include "menu.h"
#include "move.h"
#include "move_relearner.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "constants/party_menu.h"
#include "constants/songs.h"

#define VALID_MON 0
#define INVALID_MON 1

struct PcMonSelection
{
    void      (*partyMonBackup)(void);
    u32       (*isMonInvalid)(struct BoxPokemon *);
    const u8* postSelectionScript;
    u32       isStrict:1;
    u32       padding:31;
};

static EWRAM_DATA u8 sSelectionType = 0;

// All these filter functions return 0 when a mon is a valid or a number corresponding to the type of error
static u32 ChooseBoxMon_NoFilter(struct BoxPokemon *boxmon);
static u32 ChooseBoxMon_IsNotEgg(struct BoxPokemon *boxmon);
static u32 ChooseBoxMon_IsMatchingSpecies(struct BoxPokemon *boxmon);
static u32 ChooseBoxMon_CanMonDeleteMove(struct BoxPokemon *boxmon);
static u32 ChooseBoxMon_CanMonLearnSpecialVarMove(struct BoxPokemon *boxmon);
static u32 ChooseBoxMon_CanRelearnMoves(struct BoxPokemon *boxmon);
static u32 ChooseBoxMon_CanEvolve(struct BoxPokemon *boxmon);

static const struct PcMonSelection sPcMonSelectionTypes[] =
{
    [SELECT_PC_MON_NORMAL] = {ChoosePartyMon, ChooseBoxMon_NoFilter, NULL, FALSE},
    [SELECT_PC_MON_TRADE] = {ChoosePartyMon, ChooseBoxMon_IsMatchingSpecies, NULL, FALSE},
    [SELECT_PC_MON_DAYCARE] = {ChooseSendDaycareMon, ChooseBoxMon_IsNotEgg, NULL, TRUE},
    [SELECT_PC_MON_MOVE_TUTOR] = {ChooseMonForMoveTutor, ChooseBoxMon_CanMonLearnSpecialVarMove, MoveTutor_AfterChooseBoxMon, FALSE},
    [SELECT_PC_MON_MOVE_DELETER] = {ChoosePartyMon, ChooseBoxMon_CanMonDeleteMove, NULL, FALSE},
    [SELECT_PC_MON_MOVE_RELEARNER] = {ChooseMonForMoveRelearner, ChooseBoxMon_CanRelearnMoves, NULL, FALSE},
    [SELECT_PC_MON_EVOLUTION] = {ChoosePartyMon, ChooseBoxMon_CanEvolve, NULL, FALSE},
};

static u32 ChooseBoxMon_NoFilter(struct BoxPokemon *boxmon)
{
    return VALID_MON;
}

static u32 ChooseBoxMon_IsNotEgg(struct BoxPokemon *boxmon)
{
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG))
        return INVALID_MON;
    return VALID_MON;
}

static u32 ChooseBoxMon_CanRelearnMoves(struct BoxPokemon *boxmon)
{
    gRelearnMode = RELEARN_MODE_SCRIPT;
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG))
        return INVALID_MON;
    if (HasMoveToRelearn(boxmon, gMoveRelearnerState))
        return VALID_MON;
    return INVALID_MON;
}

static u32 ChooseBoxMon_IsMatchingSpecies(struct BoxPokemon *boxmon)
{
    if (GetBoxMonData(boxmon, MON_DATA_SPECIES_OR_EGG) == gSpecialVar_0x8009)
        return VALID_MON;
    return INVALID_MON;
}

static u32 ChooseBoxMon_CanMonDeleteMove(struct BoxPokemon *boxmon)
{
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG))
        return INVALID_MON;
    if (GetBoxMonData(boxmon, MON_DATA_MOVE2) == MOVE_NONE) // Only has One move
        return INVALID_MON;
    return VALID_MON;
}

static u32 ChooseBoxMon_CanMonLearnMove(struct BoxPokemon *boxmon, enum Move move)
{
    if (GetBoxMonData(boxmon, MON_DATA_IS_EGG))
        return CANNOT_LEARN_MOVE_IS_EGG;
    if (BoxMonKnowsMove(boxmon, move))
        return ALREADY_KNOWS_MOVE;
    if (CanLearnTeachableMove(GetBoxMonData(boxmon, MON_DATA_SPECIES), move))
        return VALID_MON;
    return CANNOT_LEARN_MOVE;
}

//super hacky way to exclude PC mons until I handle evolution for pc mon in a different PR
static bool32 IsFromPC(u32 adress)
{
    u32 pcMonStart = (u32)&gPokemonStoragePtr->boxes;
    u32 pcMonEnd = pcMonStart + sizeof(struct BoxPokemon) * TOTAL_BOXES_COUNT * IN_BOX_COUNT;
    return (pcMonStart <= adress && adress <= pcMonEnd);
}
static u32 ChooseBoxMon_CanEvolve(struct BoxPokemon *boxmon)
{
    struct Pokemon *mon = Alloc(sizeof(struct Pokemon));
    u32 result;

    if (IsFromPC((u32)boxmon))
        return INVALID_MON;
    BoxMonToMon(boxmon, mon);
    if (GetEvolutionTargetSpecies(mon, EVO_MODE_SCRIPT_TRIGGER, gSpecialVar_0x8005, NULL, NULL, CHECK_EVO))
        result = VALID_MON;
    else
        result = INVALID_MON;
    Free(mon);
    return result;
}

static u32 ChooseBoxMon_CanMonLearnSpecialVarMove(struct BoxPokemon *boxmon)
{
     return ChooseBoxMon_CanMonLearnMove(boxmon, gSpecialVar_0x8005);
}

u32 IsBoxMonExcluded(struct BoxPokemon *boxmon)
{
    return sPcMonSelectionTypes[sSelectionType].isMonInvalid(boxmon);
}

bool32 CanBoxMonBeSelected(struct BoxPokemon *boxmon)
{
    if (!sPcMonSelectionTypes[sSelectionType].isStrict)
        return TRUE;
    return !IsBoxMonExcluded(boxmon);
}

static void Task_ChooseBoxMon(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        ChooseMonFromStorage();
        DestroyTask(taskId);
    }
}

// Used as a script special for showing a box mon to various npcs (e.g. in-game trades, move deleter)
void ChooseBoxMon(struct ScriptContext *ctx)
{
    sSelectionType = ScriptReadByte(ctx);
    if (!OW_CHOOSE_FROM_PC_AND_PARTY)
    {
        sPcMonSelectionTypes[sSelectionType].partyMonBackup();
        return;
    }
    LockPlayerFieldControls();
    FadeScreen(FADE_TO_BLACK, 0);
    CreateTask(Task_ChooseBoxMon, 10);
    if (sPcMonSelectionTypes[sSelectionType].postSelectionScript)
    {
        ctx->scriptPtr++;
        ScriptCall(ctx, sPcMonSelectionTypes[sSelectionType].postSelectionScript);
    }
}

void PickPartyMon(struct ScriptContext *ctx)
{
    sSelectionType = ScriptReadByte(ctx);
    for (u32 i = 0; i < gPartiesCount[B_TRAINER_PLAYER]; i++)
    {
        if (!sPcMonSelectionTypes[sSelectionType].isMonInvalid(&gParties[B_TRAINER_PLAYER][i].box))
        {
            gSpecialVar_0x8004 = i;
            return;
        }
    }
    gSpecialVar_0x8004 = PARTY_NOTHING_CHOSEN;
}

enum LearnMoveState
{
    LEARN_MOVE_END,

    VALIDATE_BEFORE_LEARNING, //Start for OW move turors

    PROMPT_BEFORE_LEARNING_1, //Start for move relearner
    PROMPT_BEFORE_LEARNING_2,

    LEARN_MOVE,

    ASK_REPLACEMENT_1,
    ASK_REPLACEMENT_2,
    ASK_REPLACEMENT_3,

    REFUSE_REPLACE_1,
    REFUSE_REPLACE_2,
    REFUSE_REPLACE_3,

    WANT_REPLACE_1,
    WANT_REPLACE_2,
    WANT_REPLACE_3, //Return from Summary screen

    LEARNED_MOVE_1,
    LEARNED_MOVE_2,

    FORGOT_MOVE_1,

    REPLACE_MOVE_1,

    DID_NOT_LEARN_1,
};

static struct BoxPokemon *LearnMove_GetBoxMonFromTaskData(u8 partyIndex)
{
    struct BoxPokemon *boxmon;
    if (partyIndex == PC_MON_CHOSEN)
        boxmon = GetBoxedMonPtr(gSpecialVar_MonBoxId, gSpecialVar_MonBoxPos);
    else
        boxmon = &(gParties[B_TRAINER_PLAYER][partyIndex].box);
    return boxmon;
}

#define state         gTasks[taskId].data[0]
#define partyIndex    gTasks[taskId].data[1]
#define move          gTasks[taskId].data[2]
#define recoverPP     gTasks[taskId].data[3]
// MoveLearnUI does not contain a waitMessage function and LearnMove assumes the calling task will wait when a printer is active
// Remember to update Task_LearnMove is you wish to change to an explicit waitMessage system
s32 LearnMove(const struct MoveLearnUI *ui, u8 taskId)
{
    struct BoxPokemon *boxmon = LearnMove_GetBoxMonFromTaskData(partyIndex);
    switch (state)
    {
    case PROMPT_BEFORE_LEARNING_1:
        ui->askConfirmation();
        return PROMPT_BEFORE_LEARNING_2;
    case PROMPT_BEFORE_LEARNING_2:
        switch (ui->waitConfirmation())
        {
        case 0: // Yes
            return LEARN_MOVE;
        case 1: // No
        case MENU_B_PRESSED:
            gSpecialVar_Result = FALSE;
            return LEARN_MOVE_END;
        }
        return state;
    case VALIDATE_BEFORE_LEARNING:
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(move));
        gSpecialVar_Result = FALSE;
        switch(ChooseBoxMon_CanMonLearnMove(boxmon, move))
        {
        case VALID_MON:
            return LEARN_MOVE;
        case ALREADY_KNOWS_MOVE:
            ui->printMessage(gText_PkmnAlreadyKnows);
            return LEARN_MOVE_END;
        case CANNOT_LEARN_MOVE_IS_EGG:
        case CANNOT_LEARN_MOVE:
        default:
            ui->printMessage(gText_PkmnCantLearnMove);
            return LEARN_MOVE_END;
        }
    case LEARN_MOVE:
        if (GiveMoveToBoxMon(boxmon, move) != MON_HAS_MAX_MOVES)
            return LEARNED_MOVE_1;
        else
            return ASK_REPLACEMENT_1;
    case ASK_REPLACEMENT_1:
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(move));
        ui->printMessage(gText_PkmnNeedsToReplaceMove);
        return ASK_REPLACEMENT_2;
    case ASK_REPLACEMENT_2:
        ui->askConfirmation();
        return ASK_REPLACEMENT_3;
    case ASK_REPLACEMENT_3:
        switch (ui->waitConfirmation())
        {
        case 0: // Yes
            return WANT_REPLACE_1;
        case 1: // No
        case MENU_B_PRESSED:
            return REFUSE_REPLACE_1;
        }
        return state;
    case REFUSE_REPLACE_1:
        StringCopy(gStringVar2, GetMoveName(move));
        ui->printMessage(gText_StopLearningMove2);
        return REFUSE_REPLACE_2;
    case REFUSE_REPLACE_2:
        ui->askConfirmation();
        return REFUSE_REPLACE_3;
    case REFUSE_REPLACE_3:
        switch (ui->waitConfirmation())
        {
        case 0: // Yes
            return DID_NOT_LEARN_1;
        case 1: // No
        case MENU_B_PRESSED:
            return WANT_REPLACE_1;
        }
        return state;
    case WANT_REPLACE_1:
        ui->printMessage(gText_WhichMoveToForget);
        return WANT_REPLACE_2;
    case WANT_REPLACE_2:
        ui->showMoveList(taskId);
        return WANT_REPLACE_3;
    case WANT_REPLACE_3:
        if (GetMoveSlotToReplace() == MAX_MON_MOVES)
            return REFUSE_REPLACE_1;
        else
            return FORGOT_MOVE_1;
    case LEARNED_MOVE_1:
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(move));
        ui->printMessage(gText_PkmnLearnedMove4);
        return LEARNED_MOVE_2;
    case LEARNED_MOVE_2:
        gSpecialVar_Result = TRUE;
        ui->playFanfare(MUS_LEVEL_UP);
        return LEARN_MOVE_END;
    case FORGOT_MOVE_1:
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(GetBoxMonData(boxmon, MON_DATA_MOVE1 + GetMoveSlotToReplace())));
        ui->printMessage(gText_12PoofForgotMove);
        return REPLACE_MOVE_1;
    case REPLACE_MOVE_1:
    {
        u32 slot = GetMoveSlotToReplace();
        RemoveBoxMonPPBonus(boxmon, slot);
        u32 originalPP = GetBoxMonData(boxmon, MON_DATA_PP1 + slot);
        u32 pp = GetMovePP(move);
        SetBoxMonData(boxmon, MON_DATA_MOVE1 + slot, &move);
        if (recoverPP || (pp < originalPP))
            SetBoxMonData(boxmon, MON_DATA_PP1 + slot, &pp);
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(move));
        gSpecialVar_Result = TRUE;
        ui->printMessage(gText_PkmnLearnedMove4);
        return LEARN_MOVE_END;
    }
    case DID_NOT_LEARN_1:
        GetBoxMonNickname(boxmon, gStringVar1);
        StringCopy(gStringVar2, GetMoveName(move));
        gSpecialVar_Result = FALSE;
        ui->printMessage(gText_MoveNotLearned);
        return LEARN_MOVE_END;
    default:
        errorf("Unknown LearnMove state %d\nEnding move learning ...", state);
    case LEARN_MOVE_END:
        ui->endTask(taskId);
        return LEARN_MOVE_END;
    }
}

s32 GetLearnMoveStartState(void)
{
    return VALIDATE_BEFORE_LEARNING;
}

s32 GetLearnMoveStartAfterPromptState(void)
{
    return PROMPT_BEFORE_LEARNING_1;
}

//At the time of writing code for this, there was no prescribed way to make a task persist between scenes
//and I didn't want to implement one just for this, feel free to rewrite this if this has changed
s32 GetLearnMoveResumeAfterSummaryScreenState(void)
{
    return WANT_REPLACE_3;
}
#undef state
#undef partyIndex
#undef move
