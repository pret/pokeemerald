#include "global.h"
#include "battle.h"
#include "contest.h"
#include "random.h"
#include "contest_ai.h"
#include "contest_effect.h"
#include "constants/moves.h"

#define AI_ACTION_DONE (1 << 0)

extern const u8 *gAIScriptPtr;
extern const u8 *gContestAI_ScriptsTable[];

static void ContestAICmd_score(void);
static void ContestAICmd_get_appeal_num(void);
static void ContestAICmd_if_appeal_num_less_than(void);
static void ContestAICmd_if_appeal_num_more_than(void);
static void ContestAICmd_if_appeal_num_eq(void);
static void ContestAICmd_if_appeal_num_not_eq(void);
static void ContestAICmd_get_excitement(void);
static void ContestAICmd_if_excitement_less_than(void);
static void ContestAICmd_if_excitement_more_than(void);
static void ContestAICmd_if_excitement_eq(void);
static void ContestAICmd_if_excitement_not_eq(void);
static void ContestAICmd_get_user_order(void);
static void ContestAICmd_if_user_order_less_than(void);
static void ContestAICmd_if_user_order_more_than(void);
static void ContestAICmd_if_user_order_eq(void);
static void ContestAICmd_if_user_order_not_eq(void);
static void ContestAICmd_get_user_condition(void);
static void ContestAICmd_if_user_condition_less_than(void);
static void ContestAICmd_if_user_condition_more_than(void);
static void ContestAICmd_if_user_condition_eq(void);
static void ContestAICmd_if_user_condition_not_eq(void);
static void ContestAICmd_get_points(void);
static void ContestAICmd_if_points_less_than(void);
static void ContestAICmd_if_points_more_than(void);
static void ContestAICmd_if_points_eq(void);
static void ContestAICmd_if_points_not_eq(void);
static void ContestAICmd_get_preliminary_points(void);
static void ContestAICmd_if_preliminary_points_less_than(void);
static void ContestAICmd_if_preliminary_points_more_than(void);
static void ContestAICmd_if_preliminary_points_eq(void);
static void ContestAICmd_if_preliminary_points_not_eq(void);
static void ContestAICmd_get_contest_type(void);
static void ContestAICmd_if_contest_type_eq(void);
static void ContestAICmd_if_contest_type_not_eq(void);
static void ContestAICmd_get_move_excitement(void);
static void ContestAICmd_if_move_excitement_less_than(void);
static void ContestAICmd_if_move_excitement_more_than(void);
static void ContestAICmd_if_move_excitement_eq(void);
static void ContestAICmd_if_move_excitement_not_eq(void);
static void ContestAICmd_get_move_effect(void);
static void ContestAICmd_if_move_effect_eq(void);
static void ContestAICmd_if_move_effect_not_eq(void);
static void ContestAICmd_get_move_effect_type(void);
static void ContestAICmd_if_move_effect_type_eq(void);
static void ContestAICmd_if_move_effect_type_not_eq(void);
static void ContestAICmd_check_most_appealing_move(void);
static void ContestAICmd_if_most_appealing_move(void);
static void ContestAICmd_check_most_jamming_move(void);
static void ContestAICmd_if_most_jamming_move(void);
static void ContestAICmd_get_num_move_hearts(void);
static void ContestAICmd_if_num_move_hearts_less_than(void);
static void ContestAICmd_if_num_move_hearts_more_than(void);
static void ContestAICmd_if_num_move_hearts_eq(void);
static void ContestAICmd_if_num_move_hearts_not_eq(void);
static void ContestAICmd_get_num_move_jam_hearts(void);
static void ContestAICmd_if_num_move_jam_hearts_less_than(void);
static void ContestAICmd_if_num_move_jam_hearts_more_than(void);
static void ContestAICmd_if_num_move_jam_hearts_eq(void);
static void ContestAICmd_if_num_move_jam_hearts_not_eq(void);
static void ContestAICmd_get_move_used_count(void);
static void ContestAICmd_if_most_used_count_less_than(void);
static void ContestAICmd_if_most_used_count_more_than(void);
static void ContestAICmd_if_most_used_count_eq(void);
static void ContestAICmd_if_most_used_count_not_eq(void);
static void ContestAICmd_check_combo_starter(void);
static void ContestAICmd_if_combo_starter(void);
static void ContestAICmd_if_not_combo_starter(void);
static void ContestAICmd_check_combo_finisher(void);
static void ContestAICmd_if_combo_finisher(void);
static void ContestAICmd_if_not_combo_finisher(void);
static void ContestAICmd_check_would_finish_combo(void);
static void ContestAICmd_if_would_finish_combo(void);
static void ContestAICmd_if_would_not_finish_combo(void);
static void ContestAICmd_get_condition(void);
static void ContestAICmd_if_condition_less_than(void);
static void ContestAICmd_if_condition_more_than(void);
static void ContestAICmd_if_condition_eq(void);
static void ContestAICmd_if_condition_not_eq(void);
static void ContestAICmd_get_used_combo_starter(void);
static void ContestAICmd_if_used_combo_starter_less_than(void);
static void ContestAICmd_if_used_combo_starter_more_than(void);
static void ContestAICmd_if_used_combo_starter_eq(void);
static void ContestAICmd_if_used_combo_starter_not_eq(void);
static void ContestAICmd_check_can_participate(void);
static void ContestAICmd_if_can_participate(void);
static void ContestAICmd_if_cannot_participate(void);
static void ContestAICmd_get_completed_combo(void);
static void ContestAICmd_if_completed_combo(void);
static void ContestAICmd_if_not_completed_combo(void);
static void ContestAICmd_get_points_diff(void);
static void ContestAICmd_if_points_more_than_mon(void);
static void ContestAICmd_if_points_less_than_mon(void);
static void ContestAICmd_if_points_eq_mon(void);
static void ContestAICmd_if_points_not_eq_mon(void);
static void ContestAICmd_get_preliminary_points_diff(void);
static void ContestAICmd_if_preliminary_points_more_than_mon(void);
static void ContestAICmd_if_preliminary_points_less_than_mon(void);
static void ContestAICmd_if_preliminary_points_eq_mon(void);
static void ContestAICmd_if_preliminary_points_not_eq_mon(void);
static void ContestAICmd_get_used_moves_effect(void);
static void ContestAICmd_if_used_moves_effect_less_than(void);
static void ContestAICmd_if_used_moves_effect_more_than(void);
static void ContestAICmd_if_used_moves_effect_eq(void);
static void ContestAICmd_if_used_moves_effect_not_eq(void);
static void ContestAICmd_get_used_moves_excitement(void);
static void ContestAICmd_if_used_moves_excitement_less_than(void);
static void ContestAICmd_if_used_moves_excitement_more_than(void);
static void ContestAICmd_if_used_moves_excitement_eq(void);
static void ContestAICmd_if_used_moves_excitement_not_eq(void);
static void ContestAICmd_get_used_moves_effect_type(void);
static void ContestAICmd_if_used_moves_effect_type_eq(void);
static void ContestAICmd_if_used_moves_effect_type_not_eq(void);
static void ContestAICmd_save_result(void);
static void ContestAICmd_setvar(void);
static void ContestAICmd_add(void);
static void ContestAICmd_addvar(void);
static void ContestAICmd_addvar_duplicate(void);
static void ContestAICmd_if_less_than(void);
static void ContestAICmd_if_greater_than(void);
static void ContestAICmd_if_eq(void);
static void ContestAICmd_if_not_eq(void);
static void ContestAICmd_if_less_than_var(void);
static void ContestAICmd_if_greater_than_var(void);
static void ContestAICmd_if_eq_var(void);
static void ContestAICmd_if_not_eq_var(void);
static void ContestAICmd_if_random_less_than(void);
static void ContestAICmd_if_random_greater_than(void);
static void ContestAICmd_goto(void);
static void ContestAICmd_call(void);
static void ContestAICmd_end(void);
static void ContestAICmd_check_user_has_exciting_move(void);
static void ContestAICmd_if_user_has_exciting_move(void);
static void ContestAICmd_if_user_doesnt_have_exciting_move(void);
static void ContestAICmd_check_user_has_move(void);
static void ContestAICmd_if_user_has_move(void);
static void ContestAICmd_if_user_doesnt_have_move(void);

typedef void (* ContestAICmdFunc)(void);

static const ContestAICmdFunc sContestAICmdTable[] =
{
    ContestAICmd_score,                               // 0x00
    ContestAICmd_get_appeal_num,                      // 0x01
    ContestAICmd_if_appeal_num_less_than,             // 0x02
    ContestAICmd_if_appeal_num_more_than,             // 0x03
    ContestAICmd_if_appeal_num_eq,                    // 0x04
    ContestAICmd_if_appeal_num_not_eq,                // 0x05
    ContestAICmd_get_excitement,                      // 0x06
    ContestAICmd_if_excitement_less_than,             // 0x07
    ContestAICmd_if_excitement_more_than,             // 0x08
    ContestAICmd_if_excitement_eq,                    // 0x09
    ContestAICmd_if_excitement_not_eq,                // 0x0A
    ContestAICmd_get_user_order,                      // 0x0B
    ContestAICmd_if_user_order_less_than,             // 0x0C
    ContestAICmd_if_user_order_more_than,             // 0x0D
    ContestAICmd_if_user_order_eq,                    // 0x0E
    ContestAICmd_if_user_order_not_eq,                // 0x0F
    ContestAICmd_get_user_condition,                  // 0x10
    ContestAICmd_if_user_condition_less_than,         // 0x11
    ContestAICmd_if_user_condition_more_than,         // 0x12
    ContestAICmd_if_user_condition_eq,                // 0x13
    ContestAICmd_if_user_condition_not_eq,            // 0x14
    ContestAICmd_get_points,                          // 0x15
    ContestAICmd_if_points_less_than,                 // 0x16
    ContestAICmd_if_points_more_than,                 // 0x17
    ContestAICmd_if_points_eq,                        // 0x18
    ContestAICmd_if_points_not_eq,                    // 0x19
    ContestAICmd_get_preliminary_points,              // 0x1A
    ContestAICmd_if_preliminary_points_less_than,     // 0x1B
    ContestAICmd_if_preliminary_points_more_than,     // 0x1C
    ContestAICmd_if_preliminary_points_eq,            // 0x1D
    ContestAICmd_if_preliminary_points_not_eq,        // 0x1E
    ContestAICmd_get_contest_type,                    // 0x1F
    ContestAICmd_if_contest_type_eq,                  // 0x20
    ContestAICmd_if_contest_type_not_eq,              // 0x21
    ContestAICmd_get_move_excitement,                 // 0x22
    ContestAICmd_if_move_excitement_less_than,        // 0x23
    ContestAICmd_if_move_excitement_more_than,        // 0x24
    ContestAICmd_if_move_excitement_eq,               // 0x25
    ContestAICmd_if_move_excitement_not_eq,           // 0x26
    ContestAICmd_get_move_effect,                     // 0x27
    ContestAICmd_if_move_effect_eq,                   // 0x28
    ContestAICmd_if_move_effect_not_eq,               // 0x29
    ContestAICmd_get_move_effect_type,                // 0x2A
    ContestAICmd_if_move_effect_type_eq,              // 0x2B
    ContestAICmd_if_move_effect_type_not_eq,          // 0x2C
    ContestAICmd_check_most_appealing_move,           // 0x2D
    ContestAICmd_if_most_appealing_move,              // 0x2E
    ContestAICmd_check_most_jamming_move,             // 0x2F
    ContestAICmd_if_most_jamming_move,                // 0x30
    ContestAICmd_get_num_move_hearts,                 // 0x31
    ContestAICmd_if_num_move_hearts_less_than,        // 0x32
    ContestAICmd_if_num_move_hearts_more_than,        // 0x33
    ContestAICmd_if_num_move_hearts_eq,               // 0x34
    ContestAICmd_if_num_move_hearts_not_eq,           // 0x35
    ContestAICmd_get_num_move_jam_hearts,             // 0x36
    ContestAICmd_if_num_move_jam_hearts_less_than,    // 0x37
    ContestAICmd_if_num_move_jam_hearts_more_than,    // 0x38
    ContestAICmd_if_num_move_jam_hearts_eq,           // 0x39
    ContestAICmd_if_num_move_jam_hearts_not_eq,       // 0x3A
    ContestAICmd_get_move_used_count,                 // 0x3B
    ContestAICmd_if_most_used_count_less_than,        // 0x3C
    ContestAICmd_if_most_used_count_more_than,        // 0x3D
    ContestAICmd_if_most_used_count_eq,               // 0x3E
    ContestAICmd_if_most_used_count_not_eq,           // 0x3F
    ContestAICmd_check_combo_starter,                 // 0x40
    ContestAICmd_if_combo_starter,                    // 0x41
    ContestAICmd_if_not_combo_starter,                // 0x42
    ContestAICmd_check_combo_finisher,                // 0x43
    ContestAICmd_if_combo_finisher,                   // 0x44
    ContestAICmd_if_not_combo_finisher,               // 0x45
    ContestAICmd_check_would_finish_combo,            // 0x46
    ContestAICmd_if_would_finish_combo,               // 0x47
    ContestAICmd_if_would_not_finish_combo,           // 0x48
    ContestAICmd_get_condition,                       // 0x49
    ContestAICmd_if_condition_less_than,              // 0x4A
    ContestAICmd_if_condition_more_than,              // 0x4B
    ContestAICmd_if_condition_eq,                     // 0x4C
    ContestAICmd_if_condition_not_eq,                 // 0x4D
    ContestAICmd_get_used_combo_starter,              // 0x4E
    ContestAICmd_if_used_combo_starter_less_than,     // 0x4F
    ContestAICmd_if_used_combo_starter_more_than,     // 0x50
    ContestAICmd_if_used_combo_starter_eq,            // 0x51
    ContestAICmd_if_used_combo_starter_not_eq,        // 0x52
    ContestAICmd_check_can_participate,               // 0x53
    ContestAICmd_if_can_participate,                  // 0x54
    ContestAICmd_if_cannot_participate,               // 0x55
    ContestAICmd_get_completed_combo,                 // 0x56
    ContestAICmd_if_completed_combo,                  // 0x57
    ContestAICmd_if_not_completed_combo,              // 0x58
    ContestAICmd_get_points_diff,                     // 0x59
    ContestAICmd_if_points_more_than_mon,             // 0x5A
    ContestAICmd_if_points_less_than_mon,             // 0x5B
    ContestAICmd_if_points_eq_mon,                    // 0x5C
    ContestAICmd_if_points_not_eq_mon,                // 0x5D
    ContestAICmd_get_preliminary_points_diff,         // 0x5E
    ContestAICmd_if_preliminary_points_more_than_mon, // 0x5F
    ContestAICmd_if_preliminary_points_less_than_mon, // 0x60
    ContestAICmd_if_preliminary_points_eq_mon,        // 0x61
    ContestAICmd_if_preliminary_points_not_eq_mon,    // 0x62
    ContestAICmd_get_used_moves_effect,               // 0x63
    ContestAICmd_if_used_moves_effect_less_than,      // 0x64
    ContestAICmd_if_used_moves_effect_more_than,      // 0x65
    ContestAICmd_if_used_moves_effect_eq,             // 0x66
    ContestAICmd_if_used_moves_effect_not_eq,         // 0x67
    ContestAICmd_get_used_moves_excitement,           // 0x68
    ContestAICmd_if_used_moves_excitement_less_than,  // 0x69
    ContestAICmd_if_used_moves_excitement_more_than,  // 0x6A
    ContestAICmd_if_used_moves_excitement_eq,         // 0x6B
    ContestAICmd_if_used_moves_excitement_not_eq,     // 0x6C
    ContestAICmd_get_used_moves_effect_type,          // 0x6D
    ContestAICmd_if_used_moves_effect_type_eq,        // 0x6E
    ContestAICmd_if_used_moves_effect_type_not_eq,    // 0x6F
    ContestAICmd_save_result,                         // 0x70
    ContestAICmd_setvar,                              // 0x71
    ContestAICmd_add,                                 // 0x72
    ContestAICmd_addvar,                              // 0x73
    ContestAICmd_addvar_duplicate,                    // 0x74
    ContestAICmd_if_less_than,                        // 0x75
    ContestAICmd_if_greater_than,                     // 0x76
    ContestAICmd_if_eq,                               // 0x77
    ContestAICmd_if_not_eq,                           // 0x78
    ContestAICmd_if_less_than_var,                    // 0x79
    ContestAICmd_if_greater_than_var,                 // 0x7A
    ContestAICmd_if_eq_var,                           // 0x7B
    ContestAICmd_if_not_eq_var,                       // 0x7C
    ContestAICmd_if_random_less_than,                 // 0x7D
    ContestAICmd_if_random_greater_than,              // 0x7E
    ContestAICmd_goto,                                // 0x7F
    ContestAICmd_call,                                // 0x80
    ContestAICmd_end,                                 // 0x81
    ContestAICmd_check_user_has_exciting_move,        // 0x82
    ContestAICmd_if_user_has_exciting_move,           // 0x83
    ContestAICmd_if_user_doesnt_have_exciting_move,   // 0x84
    ContestAICmd_check_user_has_move,                 // 0x85
    ContestAICmd_if_user_has_move,                    // 0x86
    ContestAICmd_if_user_doesnt_have_move,            // 0x87
};

static void ContestAI_DoAIProcessing(void);
static bool8 GetContestantIdByTurn(u8);
static void AIStackPushVar(const u8 *);
static u8 AIStackPop(void);

void ContestAI_ResetAI(u8 contestantAI)
{
    int i;
    memset(&eContestAI, 0, sizeof(struct ContestAIInfo));

    for (i = 0; i < MAX_MON_MOVES; i++)
        eContestAI.moveScores[i] = 100;

    eContestAI.contestantId = contestantAI;
    eContestAI.stackSize = 0;
    eContestAI.aiFlags = gContestMons[eContestAI.contestantId].aiFlags;
}

u8 ContestAI_GetActionToUse(void)
{
    while (eContestAI.aiFlags != 0)
    {
        if (eContestAI.aiFlags & 1)
        {
            eContestAI.aiState = CONTESTAI_SETTING_UP;
            ContestAI_DoAIProcessing();
        }
        eContestAI.aiFlags >>= 1;
        eContestAI.currentAIFlag++;
        eContestAI.nextMoveIndex = 0;
    }

    while (1)
    {
        // Randomly choose a move index. If it's the move
        // with the highest (or tied highest) score, return
        u8 moveIdx = MOD(Random(), MAX_MON_MOVES);
        u8 score = eContestAI.moveScores[moveIdx];
        int i;
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (score < eContestAI.moveScores[i])
                break;
        }
        if (i == MAX_MON_MOVES)
            return moveIdx;
    }
}

static void ContestAI_DoAIProcessing(void)
{
    while (eContestAI.aiState != CONTESTAI_FINISHED)
    {
        switch(eContestAI.aiState)
        {
            case CONTESTAI_DO_NOT_PROCESS:
                break;
            case CONTESTAI_SETTING_UP:
                gAIScriptPtr = gContestAI_ScriptsTable[eContestAI.currentAIFlag];

                if (gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex] == MOVE_NONE)
                    eContestAI.nextMove = MOVE_NONE; // don't process a move that doesn't exist.
                else
                    eContestAI.nextMove = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];
                eContestAI.aiState++;
                break;
            case CONTESTAI_PROCESSING:
                if (eContestAI.nextMove != MOVE_NONE)
                {
                    sContestAICmdTable[*gAIScriptPtr](); // run the command.
                }
                else
                {
                    eContestAI.moveScores[eContestAI.nextMoveIndex] = 0; // don't consider a move that doesn't exist.
                    eContestAI.aiAction |= AI_ACTION_DONE;
                }
                if (eContestAI.aiAction & AI_ACTION_DONE)
                {
                    eContestAI.nextMoveIndex++;
                    if (eContestAI.nextMoveIndex < MAX_MON_MOVES)
                        eContestAI.aiState = 0;
                    else
                        // aiState = CONTESTAI_FINISHED
                        eContestAI.aiState++;
                    eContestAI.aiAction &= ~AI_ACTION_DONE;
                }
                break;
        }
    }
}

static u8 GetContestantIdByTurn(u8 turn)
{
    int i;

    for (i = 0; i < CONTESTANT_COUNT; i++)
        if (eContestAppealResults.turnOrder[i] == turn)
            break;

    return i;
}

static void ContestAICmd_score(void)
{
    s16 score = eContestAI.moveScores[eContestAI.nextMoveIndex] + (s8)gAIScriptPtr[1];

    if (score > 255)
        score = 255;
    else if (score < 0)
        score = 0;

    eContestAI.moveScores[eContestAI.nextMoveIndex] = score;

    gAIScriptPtr += 2;
}

static void ContestAICmd_get_appeal_num(void)
{
    eContestAI.scriptResult = eContest.appealNumber;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_appeal_num_less_than(void)
{
    ContestAICmd_get_appeal_num();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_appeal_num_more_than(void)
{
    ContestAICmd_get_appeal_num();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_appeal_num_eq(void)
{
    ContestAICmd_get_appeal_num();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_appeal_num_not_eq(void)
{
    ContestAICmd_get_appeal_num();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_excitement(void)
{
    eContestAI.scriptResult = eContest.applauseLevel;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_excitement_less_than(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_excitement_more_than(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_excitement_eq(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_excitement_not_eq(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_user_order(void)
{
    eContestAI.scriptResult = eContestAppealResults.turnOrder[eContestAI.contestantId];
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_user_order_less_than(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_user_order_more_than(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_user_order_eq(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_user_order_not_eq(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_user_condition(void)
{
    eContestAI.scriptResult = eContestantStatus[eContestAI.contestantId].condition / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_user_condition_less_than(void)
{
    ContestAICmd_get_user_condition();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_user_condition_more_than(void)
{
    ContestAICmd_get_user_condition();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_user_condition_eq(void)
{
    ContestAICmd_get_user_condition();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_user_condition_not_eq(void)
{
    ContestAICmd_get_user_condition();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_points(void)
{
    eContestAI.scriptResult = eContestantStatus[eContestAI.contestantId].pointTotal;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_points_less_than(void)
{
    ContestAICmd_get_points();

    if (eContestAI.scriptResult < (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_if_points_more_than(void)
{
    ContestAICmd_get_points();

    if (eContestAI.scriptResult > (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_if_points_eq(void)
{
    ContestAICmd_get_points();

    if (eContestAI.scriptResult == (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_if_points_not_eq(void)
{
    ContestAICmd_get_points();

    if (eContestAI.scriptResult != (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_get_preliminary_points(void)
{
    eContestAI.scriptResult = gContestMonRound1Points[eContestAI.contestantId];
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_preliminary_points_less_than(void)
{
    ContestAICmd_get_preliminary_points();

    if (eContestAI.scriptResult < (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_if_preliminary_points_more_than(void)
{
    ContestAICmd_get_preliminary_points();

    if (eContestAI.scriptResult > (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_if_preliminary_points_eq(void)
{
    ContestAICmd_get_preliminary_points();

    if (eContestAI.scriptResult == (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_if_preliminary_points_not_eq(void)
{
    ContestAICmd_get_preliminary_points();

    if (eContestAI.scriptResult != (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_get_contest_type(void)
{
    eContestAI.scriptResult = gSpecialVar_ContestCategory;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_contest_type_eq(void)
{
    ContestAICmd_get_contest_type();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_contest_type_not_eq(void)
{
    ContestAICmd_get_contest_type();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_excitement(void)
{
    eContestAI.scriptResult = Contest_GetMoveExcitement(gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex]);
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_move_excitement_less_than(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI.scriptResult < (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_move_excitement_more_than(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI.scriptResult > (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_move_excitement_eq(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI.scriptResult == (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_move_excitement_not_eq(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI.scriptResult != (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_effect(void)
{
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    eContestAI.scriptResult = gContestMoves[move].effect;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_move_effect_eq(void)
{
    ContestAICmd_get_move_effect();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_move_effect_not_eq(void)
{
    ContestAICmd_get_move_effect();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_effect_type(void)
{
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    eContestAI.scriptResult = gContestEffects[gContestMoves[move].effect].effectType;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_move_effect_type_eq(void)
{
    ContestAICmd_get_move_effect_type();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_move_effect_type_not_eq(void)
{
    ContestAICmd_get_move_effect_type();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_check_most_appealing_move(void)
{
    int i;
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];
    u8 appeal = gContestEffects[gContestMoves[move].effect].appeal;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 newMove = gContestMons[eContestAI.contestantId].moves[i];
        if (newMove != 0 && appeal < gContestEffects[gContestMoves[newMove].effect].appeal)
            break;
    }

    if (i == MAX_MON_MOVES)
        eContestAI.scriptResult = TRUE;
    else
        eContestAI.scriptResult = FALSE;

    gAIScriptPtr += 1;
}

static void ContestAICmd_if_most_appealing_move(void)
{
    ContestAICmd_check_most_appealing_move();

    if (eContestAI.scriptResult != FALSE)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_check_most_jamming_move(void)
{
    int i;
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];
    u8 jam = gContestEffects[gContestMoves[move].effect].jam;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 newMove = gContestMons[eContestAI.contestantId].moves[i];
        if (newMove != MOVE_NONE && jam < gContestEffects[gContestMoves[newMove].effect].jam)
            break;
    }

    if (i == MAX_MON_MOVES)
        eContestAI.scriptResult = TRUE;
    else
        eContestAI.scriptResult = FALSE;

    gAIScriptPtr += 1;
}

static void ContestAICmd_if_most_jamming_move(void)
{
    ContestAICmd_check_most_jamming_move();

    if (eContestAI.scriptResult != FALSE)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_num_move_hearts(void)
{
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    eContestAI.scriptResult = gContestEffects[gContestMoves[move].effect].appeal / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_num_move_hearts_less_than(void)
{
    ContestAICmd_get_num_move_hearts();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_num_move_hearts_more_than(void)
{
    ContestAICmd_get_num_move_hearts();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_num_move_hearts_eq(void)
{
    ContestAICmd_get_num_move_hearts();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_num_move_hearts_not_eq(void)
{
    ContestAICmd_get_num_move_hearts();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_num_move_jam_hearts(void)
{
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    eContestAI.scriptResult = gContestEffects[gContestMoves[move].effect].jam / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_num_move_jam_hearts_less_than(void)
{
    ContestAICmd_get_num_move_jam_hearts();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_num_move_jam_hearts_more_than(void)
{
    ContestAICmd_get_num_move_jam_hearts();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_num_move_jam_hearts_eq(void)
{
    ContestAICmd_get_num_move_jam_hearts();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_num_move_jam_hearts_not_eq(void)
{
    ContestAICmd_get_num_move_jam_hearts();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_used_count(void)
{
    s16 result;
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    if (move != eContestantStatus[eContestAI.contestantId].prevMove)
        result = 0; // move is unique and not reused.
    else
        result = eContestantStatus[eContestAI.contestantId].moveRepeatCount + 1;

    eContestAI.scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_most_used_count_less_than(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_most_used_count_more_than(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_most_used_count_eq(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_most_used_count_not_eq(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_check_combo_starter(void)
{
    u8 result = 0;
    int i;
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gContestMons[eContestAI.contestantId].moves[i])
        {
            result = AreMovesContestCombo(move, gContestMons[eContestAI.contestantId].moves[i]);
            if (result)
            {
                result = 1;
                break;
            }
        }
    }

    if (result)
        result = 1;

    eContestAI.scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_combo_starter(void)
{
    ContestAICmd_check_combo_starter();

    if (eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_not_combo_starter(void)
{
    ContestAICmd_check_combo_starter();

    if (!eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_check_combo_finisher(void)
{
    u8 result = 0;
    int i;
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gContestMons[eContestAI.contestantId].moves[i])
        {
            result = AreMovesContestCombo(gContestMons[eContestAI.contestantId].moves[i], move);
            if (result)
            {
                result = 1;
                break;
            }
        }
    }

    if (result)
        result = 1;

    eContestAI.scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_combo_finisher(void)
{
    ContestAICmd_check_combo_finisher();

    if (eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_not_combo_finisher(void)
{
    ContestAICmd_check_combo_finisher();

    if (!eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_check_would_finish_combo(void)
{
    u8 result = 0;
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    if (eContestantStatus[eContestAI.contestantId].prevMove)
        result = AreMovesContestCombo(eContestantStatus[eContestAI.contestantId].prevMove, move);

    if (result)
        result = 1;

    eContestAI.scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_would_finish_combo(void)
{
    ContestAICmd_check_would_finish_combo();

    if (eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_would_not_finish_combo(void)
{
    ContestAICmd_check_would_finish_combo();

    if (!eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_condition(void)
{
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);

    eContestAI.scriptResult = eContestantStatus[contestant].condition / 10;
    gAIScriptPtr += 2;
}

static void ContestAICmd_if_condition_less_than(void)
{
    ContestAICmd_get_condition();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_condition_more_than(void)
{
    ContestAICmd_get_condition();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_condition_eq(void)
{
    ContestAICmd_get_condition();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_condition_not_eq(void)
{
    ContestAICmd_get_condition();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_used_combo_starter(void)
{
    u16 result = FALSE;
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);

    if (IsContestantAllowedToCombo(contestant))
        result = gContestMoves[eContestantStatus[contestant].prevMove].comboStarterId ? TRUE : FALSE;

    eContestAI.scriptResult = result;
    gAIScriptPtr += 2;
}

static void ContestAICmd_if_used_combo_starter_less_than(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_combo_starter_more_than(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_combo_starter_eq(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_combo_starter_not_eq(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_check_can_participate(void)
{
    if (Contest_IsMonsTurnDisabled(GetContestantIdByTurn(gAIScriptPtr[1])))
        eContestAI.scriptResult = FALSE;
    else
        eContestAI.scriptResult = TRUE;

    gAIScriptPtr += 2;
}

static void ContestAICmd_if_can_participate(void)
{
    ContestAICmd_check_can_participate();

    if (eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_cannot_participate(void)
{
    ContestAICmd_check_can_participate();

    if (!eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_completed_combo(void)
{
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);

    eContestAI.scriptResult = eContestantStatus[contestant].completedComboFlag;
    gAIScriptPtr += 2;
}

static void ContestAICmd_if_completed_combo(void)
{
    ContestAICmd_get_completed_combo();

    if (eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_not_completed_combo(void)
{
    ContestAICmd_get_completed_combo();

    if (!eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_points_diff(void)
{
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);

    eContestAI.scriptResult = eContestantStatus[contestant].pointTotal - eContestantStatus[eContestAI.contestantId].pointTotal;
    gAIScriptPtr += 2;
}

static void ContestAICmd_if_points_more_than_mon(void)
{
    ContestAICmd_get_points_diff();

    if (eContestAI.scriptResult < 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_points_less_than_mon(void)
{
    ContestAICmd_get_points_diff();

    if (eContestAI.scriptResult > 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_points_eq_mon(void)
{
    ContestAICmd_get_points_diff();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_points_not_eq_mon(void)
{
    ContestAICmd_get_points_diff();

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_preliminary_points_diff(void)
{
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);

    eContestAI.scriptResult = gContestMonRound1Points[contestant] - gContestMonRound1Points[eContestAI.contestantId];
    gAIScriptPtr += 2;
}

static void ContestAICmd_if_preliminary_points_more_than_mon(void)
{
    ContestAICmd_get_preliminary_points_diff();

    if (eContestAI.scriptResult < 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_preliminary_points_less_than_mon(void)
{
    ContestAICmd_get_preliminary_points_diff();

    if (eContestAI.scriptResult > 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_preliminary_points_eq_mon(void)
{
    ContestAICmd_get_preliminary_points_diff();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_preliminary_points_not_eq_mon(void)
{
    ContestAICmd_get_preliminary_points_diff();

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_used_moves_effect(void)
{
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);
    u8 round = gAIScriptPtr[2];
    u16 move = eContest.moveHistory[round][contestant];

    eContestAI.scriptResult = gContestMoves[move].effect;
    gAIScriptPtr += 3;
}

static void ContestAICmd_if_used_moves_effect_less_than(void)
{
    ContestAICmd_get_used_moves_effect();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_moves_effect_more_than(void)
{
    ContestAICmd_get_used_moves_effect();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_moves_effect_eq(void)
{
    ContestAICmd_get_used_moves_effect();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_moves_effect_not_eq(void)
{
    ContestAICmd_get_used_moves_effect();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_used_moves_excitement(void)
{
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);
    u8 round = gAIScriptPtr[2];
    s8 result = eContest.excitementHistory[round][contestant];

    eContestAI.scriptResult = result;
    gAIScriptPtr += 3;
}

static void ContestAICmd_if_used_moves_excitement_less_than(void)
{
    ContestAICmd_get_used_moves_excitement();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_moves_excitement_more_than(void)
{
    ContestAICmd_get_used_moves_excitement();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_moves_excitement_eq(void)
{
    ContestAICmd_get_used_moves_excitement();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_moves_excitement_not_eq(void)
{
    ContestAICmd_get_used_moves_excitement();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_used_moves_effect_type(void)
{
    u8 contestant = GetContestantIdByTurn(gAIScriptPtr[1]);
    u8 round = gAIScriptPtr[2];
    u16 move = eContest.moveHistory[round][contestant];

    eContestAI.scriptResult = gContestEffects[gContestMoves[move].effect].effectType;
    gAIScriptPtr += 3;
}

static void ContestAICmd_if_used_moves_effect_type_eq(void)
{
    ContestAICmd_get_used_moves_effect_type();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_used_moves_effect_type_not_eq(void)
{
    ContestAICmd_get_used_moves_effect_type();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_save_result(void)
{
    eContestAI.vars[gAIScriptPtr[1]] = eContestAI.scriptResult;
    gAIScriptPtr += 2;
}

static void ContestAICmd_setvar(void)
{
    eContestAI.vars[gAIScriptPtr[1]] = T1_READ_16(gAIScriptPtr + 2);
    gAIScriptPtr += 4;
}

static void ContestAICmd_add(void)
{
    // wtf? shouldn't T1_READ_16 work here? why the signed 8 load by gAIScriptPtr[2]?
    eContestAI.vars[gAIScriptPtr[1]] += ((s8)gAIScriptPtr[2] | gAIScriptPtr[3] << 8);
    gAIScriptPtr += 4;
}

static void ContestAICmd_addvar(void)
{
    eContestAI.vars[gAIScriptPtr[1]] += eContestAI.vars[gAIScriptPtr[2]];
    gAIScriptPtr += 3;
}

static void ContestAICmd_addvar_duplicate(void)
{
    eContestAI.vars[gAIScriptPtr[1]] += eContestAI.vars[gAIScriptPtr[2]];
    gAIScriptPtr += 3;
}

static void ContestAICmd_if_less_than(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] < T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_if_greater_than(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] > T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_if_eq(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] == T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_if_not_eq(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] != T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_if_less_than_var(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] < (eContestAI.vars[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_if_greater_than_var(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] > (eContestAI.vars[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_if_eq_var(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] == (eContestAI.vars[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_if_not_eq_var(void)
{
    if (eContestAI.vars[gAIScriptPtr[1]] != (eContestAI.vars[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

// UB: Should just be comparing to gAIScriptPtr[1] in the functions below
// The values passed via gAIScriptPtr[1] range from 0-255
// and vars is an s16[3], so this goes way out of bounds
static void ContestAICmd_if_random_less_than(void)
{
#ifndef UBFIX
    if ((Random() & 0xFF) < eContestAI.vars[gAIScriptPtr[1]])
#else
    if ((Random() & 0xFF) < gAIScriptPtr[1])
#endif
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_if_random_greater_than(void)
{
#ifndef UBFIX
    if (((Random()) & 0xFF) > eContestAI.vars[gAIScriptPtr[1]])
#else
    if (((Random()) & 0xFF) > gAIScriptPtr[1])
#endif
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_goto(void)
{
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void ContestAICmd_call(void)
{
    AIStackPushVar(gAIScriptPtr + 5);
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void ContestAICmd_end(void)
{
    if (!AIStackPop())
        eContestAI.aiAction |= AI_ACTION_DONE;
}

static void AIStackPushVar(const u8 *ptr)
{
    eContestAI.stack[eContestAI.stackSize++] = ptr;
}

static bool8 AIStackPop(void)
{
    if (eContestAI.stackSize != 0)
    {
        --eContestAI.stackSize;
        gAIScriptPtr = eContestAI.stack[eContestAI.stackSize];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void ContestAICmd_check_user_has_exciting_move(void)
{
    int result = 0;
    int i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gContestMons[eContestAI.contestantId].moves[i])
        {
            if (Contest_GetMoveExcitement(gContestMons[eContestAI.contestantId].moves[i]) == 1)
            {
                result = 1;
                break;
            }
        }
    }

    eContestAI.scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_user_has_exciting_move(void)
{
    ContestAICmd_check_user_has_exciting_move();

    if (eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_user_doesnt_have_exciting_move(void)
{
    ContestAICmd_check_user_has_exciting_move();

    if (!eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

// BUG: This is checking if the user has a specific move, but when it's used in the AI script
//      they're checking for an effect. Checking for a specific effect would make more sense,
//      but given that effects are normally read as a single byte and this reads 2 bytes, it
//      seems reading a move was intended and the AI script is using it incorrectly.
//      The fix below aligns the function with how it's used by the script, rather than the apparent
//      intention of its usage

static void ContestAICmd_check_user_has_move(void)
{
    int hasMove = FALSE;
    int i;
    u16 targetMove = T1_READ_16(gAIScriptPtr + 1);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        #ifdef BUGFIX
        u16 move = gContestMoves[gContestMons[eContestAI.contestantId].moves[i]].effect;
        #else
        u16 move = gContestMons[eContestAI.contestantId].moves[i];
        #endif

        if (move == targetMove)
        {
            hasMove = TRUE;
            break;
        }
    }

    eContestAI.scriptResult = hasMove;
    gAIScriptPtr += 3;
}

static void ContestAICmd_if_user_has_move(void)
{
    ContestAICmd_check_user_has_move();

    if (eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_user_doesnt_have_move(void)
{
    ContestAICmd_check_user_has_move();

    if (!eContestAI.scriptResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}
