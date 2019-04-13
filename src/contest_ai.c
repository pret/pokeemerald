#include "global.h"
#include "battle.h"
#include "contest.h"
#include "random.h"
#include "contest_ai.h"
#include "contest_effect.h"

extern const u8 *gAIScriptPtr;
extern const u8 *gContestAIChecks[];

static void ContestAICmd_score(void);
static void ContestAICmd_get_turn(void);
static void ContestAICmd_if_turn_less_than(void);
static void ContestAICmd_if_turn_more_than(void);
static void ContestAICmd_if_turn_eq(void);
static void ContestAICmd_if_turn_not_eq(void);
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
static void ContestAICmd_unk_15(void);
static void ContestAICmd_unk_16(void);
static void ContestAICmd_unk_17(void);
static void ContestAICmd_unk_18(void);
static void ContestAICmd_unk_19(void);
static void ContestAICmd_unk_1A(void);
static void ContestAICmd_unk_1B(void);
static void ContestAICmd_unk_1C(void);
static void ContestAICmd_unk_1D(void);
static void ContestAICmd_unk_1E(void);
static void ContestAICmd_get_contest_type(void);
static void ContestAICmd_if_contest_type_eq(void);
static void ContestAICmd_if_contest_type_not_eq(void);
static void ContestAICmd_get_move_excitement(void);
static void ContestAICmd_if_move_excitement_less_than(void);
static void ContestAICmd_if_move_excitement_greater_than(void);
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
static void ContestAICmd_unk_2F(void);
static void ContestAICmd_unk_30(void);
static void ContestAICmd_unk_31(void);
static void ContestAICmd_unk_32(void);
static void ContestAICmd_unk_33(void);
static void ContestAICmd_unk_34(void);
static void ContestAICmd_unk_35(void);
static void ContestAICmd_unk_36(void);
static void ContestAICmd_unk_37(void);
static void ContestAICmd_unk_38(void);
static void ContestAICmd_unk_39(void);
static void ContestAICmd_unk_3A(void);
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
static void ContestAICmd_get_val_812A188(void);
static void ContestAICmd_unk_57(void);
static void ContestAICmd_contest_58(void);
static void ContestAICmd_unk_59(void);
static void ContestAICmd_unk_5A(void);
static void ContestAICmd_unk_5B(void);
static void ContestAICmd_unk_5C(void);
static void ContestAICmd_unk_5D(void);
static void ContestAICmd_unk_5E(void);
static void ContestAICmd_unk_5F(void);
static void ContestAICmd_unk_60(void);
static void ContestAICmd_unk_61(void);
static void ContestAICmd_unk_62(void);
static void ContestAICmd_unk_63(void);
static void ContestAICmd_unk_64(void);
static void ContestAICmd_unk_65(void);
static void ContestAICmd_unk_66(void);
static void ContestAICmd_unk_67(void);
static void ContestAICmd_unk_68(void);
static void ContestAICmd_unk_69(void);
static void ContestAICmd_unk_6A(void);
static void ContestAICmd_unk_6B(void);
static void ContestAICmd_unk_6C(void);
static void ContestAICmd_unk_6D(void);
static void ContestAICmd_unk_6E(void);
static void ContestAICmd_unk_6F(void);
static void ContestAICmd_unk_70(void);
static void ContestAICmd_unk_71(void);
static void ContestAICmd_unk_72(void);
static void ContestAICmd_unk_73(void);
static void ContestAICmd_unk_74(void);
static void ContestAICmd_unk_75(void);
static void ContestAICmd_unk_76(void);
static void ContestAICmd_unk_77(void);
static void ContestAICmd_unk_78(void);
static void ContestAICmd_unk_79(void);
static void ContestAICmd_unk_7A(void);
static void ContestAICmd_unk_7B(void);
static void ContestAICmd_unk_7C(void);
static void ContestAICmd_if_random(void);
static void ContestAICmd_unk_7E(void);
static void ContestAICmd_jump(void);
static void ContestAICmd_call(void);
static void ContestAICmd_end(void);
static void ContestAICmd_check_user_has_exciting_move(void);
static void ContestAICmd_if_user_has_exciting_move(void);
static void ContestAICmd_if_user_doesnt_have_exciting_move(void);
static void ContestAICmd_unk_85(void);
static void ContestAICmd_unk_86(void);
static void ContestAICmd_if_effect_in_user_moveset(void);

typedef void (* ContestAICmdFunc)(void);

static const ContestAICmdFunc sContestAICmdTable[] =
{
    ContestAICmd_score,                             // 0x00
    ContestAICmd_get_turn,                          // 0x01
    ContestAICmd_if_turn_less_than,                 // 0x02
    ContestAICmd_if_turn_more_than,                 // 0x03
    ContestAICmd_if_turn_eq,                        // 0x04
    ContestAICmd_if_turn_not_eq,                    // 0x05
    ContestAICmd_get_excitement,                    // 0x06
    ContestAICmd_if_excitement_less_than,           // 0x07
    ContestAICmd_if_excitement_more_than,           // 0x08
    ContestAICmd_if_excitement_eq,                  // 0x09
    ContestAICmd_if_excitement_not_eq,              // 0x0A
    ContestAICmd_get_user_order,                    // 0x0B
    ContestAICmd_if_user_order_less_than,           // 0x0C
    ContestAICmd_if_user_order_more_than,           // 0x0D
    ContestAICmd_if_user_order_eq,                  // 0x0E
    ContestAICmd_if_user_order_not_eq,              // 0x0F
    ContestAICmd_get_user_condition,                // 0x10
    ContestAICmd_if_user_condition_less_than,       // 0x11
    ContestAICmd_if_user_condition_more_than,       // 0x12
    ContestAICmd_if_user_condition_eq,              // 0x13
    ContestAICmd_if_user_condition_not_eq,          // 0x14
    ContestAICmd_unk_15,                            // 0x15
    ContestAICmd_unk_16,                            // 0x16
    ContestAICmd_unk_17,                            // 0x17
    ContestAICmd_unk_18,                            // 0x18
    ContestAICmd_unk_19,                            // 0x19
    ContestAICmd_unk_1A,                            // 0x1A
    ContestAICmd_unk_1B,                            // 0x1B
    ContestAICmd_unk_1C,                            // 0x1C
    ContestAICmd_unk_1D,                            // 0x1D
    ContestAICmd_unk_1E,                            // 0x1E
    ContestAICmd_get_contest_type,                  // 0x1F
    ContestAICmd_if_contest_type_eq,                // 0x20
    ContestAICmd_if_contest_type_not_eq,            // 0x21
    ContestAICmd_get_move_excitement,               // 0x22
    ContestAICmd_if_move_excitement_less_than,      // 0x23
    ContestAICmd_if_move_excitement_greater_than,   // 0x24
    ContestAICmd_if_move_excitement_eq,             // 0x25
    ContestAICmd_if_move_excitement_not_eq,         // 0x26
    ContestAICmd_get_move_effect,                   // 0x27
    ContestAICmd_if_move_effect_eq,                 // 0x28
    ContestAICmd_if_move_effect_not_eq,             // 0x29
    ContestAICmd_get_move_effect_type,              // 0x2A
    ContestAICmd_if_move_effect_type_eq,            // 0x2B
    ContestAICmd_if_move_effect_type_not_eq,        // 0x2C
    ContestAICmd_check_most_appealing_move,         // 0x2D
    ContestAICmd_if_most_appealing_move,            // 0x2E
    ContestAICmd_unk_2F,                            // 0x2F
    ContestAICmd_unk_30,                            // 0x30
    ContestAICmd_unk_31,                            // 0x31
    ContestAICmd_unk_32,                            // 0x32
    ContestAICmd_unk_33,                            // 0x33
    ContestAICmd_unk_34,                            // 0x34
    ContestAICmd_unk_35,                            // 0x35
    ContestAICmd_unk_36,                            // 0x36
    ContestAICmd_unk_37,                            // 0x37
    ContestAICmd_unk_38,                            // 0x38
    ContestAICmd_unk_39,                            // 0x39
    ContestAICmd_unk_3A,                            // 0x3A
    ContestAICmd_get_move_used_count,               // 0x3B
    ContestAICmd_if_most_used_count_less_than,      // 0x3C
    ContestAICmd_if_most_used_count_more_than,      // 0x3D
    ContestAICmd_if_most_used_count_eq,             // 0x3E
    ContestAICmd_if_most_used_count_not_eq,         // 0x3F
    ContestAICmd_check_combo_starter,               // 0x40
    ContestAICmd_if_combo_starter,                  // 0x41
    ContestAICmd_if_not_combo_starter,              // 0x42
    ContestAICmd_check_combo_finisher,              // 0x43
    ContestAICmd_if_combo_finisher,                 // 0x44
    ContestAICmd_if_not_combo_finisher,             // 0x45
    ContestAICmd_check_would_finish_combo,          // 0x46
    ContestAICmd_if_would_finish_combo,             // 0x47
    ContestAICmd_if_would_not_finish_combo,         // 0x48
    ContestAICmd_get_condition,                     // 0x49
    ContestAICmd_if_condition_less_than,            // 0x4A
    ContestAICmd_if_condition_more_than,            // 0x4B
    ContestAICmd_if_condition_eq,                   // 0x4C
    ContestAICmd_if_condition_not_eq,               // 0x4D
    ContestAICmd_get_used_combo_starter,            // 0x4E
    ContestAICmd_if_used_combo_starter_less_than,   // 0x4F
    ContestAICmd_if_used_combo_starter_more_than,   // 0x50
    ContestAICmd_if_used_combo_starter_eq,          // 0x51
    ContestAICmd_if_used_combo_starter_not_eq,      // 0x52
    ContestAICmd_check_can_participate,             // 0x53
    ContestAICmd_if_can_participate,                // 0x54
    ContestAICmd_if_cannot_participate,             // 0x55
    ContestAICmd_get_val_812A188,                   // 0x56
    ContestAICmd_unk_57,                            // 0x57
    ContestAICmd_contest_58,                        // 0x58
    ContestAICmd_unk_59,                            // 0x59
    ContestAICmd_unk_5A,                            // 0x5A
    ContestAICmd_unk_5B,                            // 0x5B
    ContestAICmd_unk_5C,                            // 0x5C
    ContestAICmd_unk_5D,                            // 0x5D
    ContestAICmd_unk_5E,                            // 0x5E
    ContestAICmd_unk_5F,                            // 0x5F
    ContestAICmd_unk_60,                            // 0x60
    ContestAICmd_unk_61,                            // 0x61
    ContestAICmd_unk_62,                            // 0x62
    ContestAICmd_unk_63,                            // 0x63
    ContestAICmd_unk_64,                            // 0x64
    ContestAICmd_unk_65,                            // 0x65
    ContestAICmd_unk_66,                            // 0x66
    ContestAICmd_unk_67,                            // 0x67
    ContestAICmd_unk_68,                            // 0x68
    ContestAICmd_unk_69,                            // 0x69
    ContestAICmd_unk_6A,                            // 0x6A
    ContestAICmd_unk_6B,                            // 0x6B
    ContestAICmd_unk_6C,                            // 0x6C
    ContestAICmd_unk_6D,                            // 0x6D
    ContestAICmd_unk_6E,                            // 0x6E
    ContestAICmd_unk_6F,                            // 0x6F
    ContestAICmd_unk_70,                            // 0x70
    ContestAICmd_unk_71,                            // 0x71
    ContestAICmd_unk_72,                            // 0x72
    ContestAICmd_unk_73,                            // 0x73
    ContestAICmd_unk_74,                            // 0x74
    ContestAICmd_unk_75,                            // 0x75
    ContestAICmd_unk_76,                            // 0x76
    ContestAICmd_unk_77,                            // 0x77
    ContestAICmd_unk_78,                            // 0x78
    ContestAICmd_unk_79,                            // 0x79
    ContestAICmd_unk_7A,                            // 0x7A
    ContestAICmd_unk_7B,                            // 0x7B
    ContestAICmd_unk_7C,                            // 0x7C
    ContestAICmd_if_random,                         // 0x7D
    ContestAICmd_unk_7E,                            // 0x7E
    ContestAICmd_jump,                              // 0x7F
    ContestAICmd_call,                              // 0x80
    ContestAICmd_end,                               // 0x81
    ContestAICmd_check_user_has_exciting_move,      // 0x82
    ContestAICmd_if_user_has_exciting_move,         // 0x83
    ContestAICmd_if_user_doesnt_have_exciting_move, // 0x84
    ContestAICmd_unk_85,                            // 0x85
    ContestAICmd_unk_86,                            // 0x86
    ContestAICmd_if_effect_in_user_moveset,         // 0x87
};

static void ContestAI_DoAIProcessing(void);
static bool8 sub_81563B0(u8);
static void AIStackPushVar(const u8 *);
static u8 AIStackPop(void);

void ContestAI_ResetAI(u8 contestantAI)
{
    int i;
    memset(&eContestAI, 0, sizeof(struct ContestAIInfo));

    for (i = 0; i < 4; i++)
        eContestAI.unk5[i] = 100;

    eContestAI.contestantId = contestantAI;
    eContestAI.stackSize = 0;
    eContestAI.aiChecks = gContestMons[eContestAI.contestantId].aiChecks;
}

u8 ContestAI_GetActionToUse(void)
{
    while (eContestAI.aiChecks != 0)
    {
        if (eContestAI.aiChecks & 1)
        {
            eContestAI.aiState = CONTESTAI_SETTING_UP;
            ContestAI_DoAIProcessing();
        }
        eContestAI.aiChecks >>= 1;
        eContestAI.currentAICheck++;
        eContestAI.nextMoveIndex = 0;
    }

    while (1)
    {
        u8 rval = Random() & 3;
        u8 r2 = eContestAI.unk5[rval];
        int i;
        for (i = 0; i < 4; i++)
        {
            if (r2 < eContestAI.unk5[i])
                break;
        }
        if (i == 4)
            return rval;
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
                gAIScriptPtr = gContestAIChecks[eContestAI.currentAICheck];

                if (gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex] == 0)
                    eContestAI.nextMove = 0; // don't process a move that doesn't exist.
                else
                    eContestAI.nextMove = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];
                eContestAI.aiState++;
                break;
            case CONTESTAI_PROCESSING:
                if (eContestAI.nextMove != 0)
                {
                    sContestAICmdTable[*gAIScriptPtr](); // run the command.
                }
                else
                {
                    eContestAI.unk5[eContestAI.nextMoveIndex] = 0; // don't consider a move that doesn't exist.
                    eContestAI.aiAction |= 1;
                }
                if (eContestAI.aiAction & 1)
                {
                    eContestAI.nextMoveIndex++;
                    if (eContestAI.nextMoveIndex < 4)
                        eContestAI.aiState = 0;
                    else
                        // aiState = CONTESTAI_FINISHED
                        eContestAI.aiState++;
                    eContestAI.aiAction &= 0xFE; // TODO: Define action flags
                }
                break;
        }
    }
}

static u8 sub_81563B0(u8 var)
{
    int i;

    for (i = 0; i < 4; i++)
        if (eContestResources8.turnOrder[i] == var)
            break;

    return i;
}

static void ContestAICmd_score(void)
{
    s16 score = eContestAI.unk5[eContestAI.nextMoveIndex] + (s8)gAIScriptPtr[1];

    if (score > 255)
        score = 255;
    else if (score < 0)
        score = 0;

    eContestAI.unk5[eContestAI.nextMoveIndex] = score;

    gAIScriptPtr += 2;
}

static void ContestAICmd_get_turn(void)
{
    eContestAI.scriptResult = eContest.turnNumber;
    gAIScriptPtr += 1;
}

static void ContestAICmd_if_turn_less_than(void)
{
    ContestAICmd_get_turn();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_turn_more_than(void)
{
    ContestAICmd_get_turn();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_turn_eq(void)
{
    ContestAICmd_get_turn();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_if_turn_not_eq(void)
{
    ContestAICmd_get_turn();

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
    eContestAI.scriptResult = eContestResources8.turnOrder[eContestAI.contestantId];
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

static void ContestAICmd_unk_15(void)
{
    eContestAI.scriptResult = eContestantStatus[eContestAI.contestantId].pointTotal;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_16(void)
{
    ContestAICmd_unk_15();

    if (eContestAI.scriptResult < (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_17(void)
{
    ContestAICmd_unk_15();

    if (eContestAI.scriptResult > (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_18(void)
{
    ContestAICmd_unk_15();

    if (eContestAI.scriptResult == (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_19(void)
{
    ContestAICmd_unk_15();

    if (eContestAI.scriptResult != (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1A(void)
{
    eContestAI.scriptResult = gContestMonConditions[eContestAI.contestantId];
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_1B(void)
{
    ContestAICmd_unk_1A();

    if (eContestAI.scriptResult < (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1C(void)
{
    ContestAICmd_unk_1A();

    if (eContestAI.scriptResult > (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1D(void)
{
    ContestAICmd_unk_1A();

    if (eContestAI.scriptResult == (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1E(void)
{
    ContestAICmd_unk_1A();

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

static void ContestAICmd_if_move_excitement_greater_than(void)
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

static void ContestAICmd_unk_2F(void)
{
    int i;
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];
    u8 jam = gContestEffects[gContestMoves[move].effect].jam;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 newMove = gContestMons[eContestAI.contestantId].moves[i];
        if (newMove != 0 && jam < gContestEffects[gContestMoves[newMove].effect].jam)
            break;
    }

    if (i == MAX_MON_MOVES)
        eContestAI.scriptResult = TRUE;
    else
        eContestAI.scriptResult = FALSE;

    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_30(void)
{
    ContestAICmd_unk_2F();

    if (eContestAI.scriptResult != FALSE)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_31(void)
{
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    eContestAI.scriptResult = gContestEffects[gContestMoves[move].effect].appeal / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_32(void)
{
    ContestAICmd_unk_31();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_33(void)
{
    ContestAICmd_unk_31();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_34(void)
{
    ContestAICmd_unk_31();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_35(void)
{
    ContestAICmd_unk_31();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_36(void)
{
    u16 move = gContestMons[eContestAI.contestantId].moves[eContestAI.nextMoveIndex];

    eContestAI.scriptResult = gContestEffects[gContestMoves[move].effect].jam / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_37(void)
{
    ContestAICmd_unk_36();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_38(void)
{
    ContestAICmd_unk_36();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_39(void)
{
    ContestAICmd_unk_36();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_3A(void)
{
    ContestAICmd_unk_36();

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

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_not_combo_starter(void)
{
    ContestAICmd_check_combo_starter();

    if (eContestAI.scriptResult == 0)
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

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_not_combo_finisher(void)
{
    ContestAICmd_check_combo_finisher();

    if (eContestAI.scriptResult == 0)
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

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_would_not_finish_combo(void)
{
    ContestAICmd_check_would_finish_combo();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_condition(void)
{
    int var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI.scriptResult = eContestantStatus[var].condition / 10;
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
    u16 result = 0;
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    if (sub_80DE1E8(var))
        result = gContestMoves[eContestantStatus[var].prevMove].comboStarterId ? 1 : 0;

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
    if (Contest_IsMonsTurnDisabled(sub_81563B0(gAIScriptPtr[1])))
        eContestAI.scriptResult = FALSE;
    else
        eContestAI.scriptResult = TRUE;

    gAIScriptPtr += 2;
}

static void ContestAICmd_if_can_participate(void)
{
    ContestAICmd_check_can_participate();

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_cannot_participate(void)
{
    ContestAICmd_check_can_participate();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_val_812A188(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI.scriptResult = eContestantStatus[var].unk15_3;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_57(void)
{
    ContestAICmd_get_val_812A188();

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_contest_58(void)
{
    ContestAICmd_get_val_812A188();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_59(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI.scriptResult = eContestantStatus[var].pointTotal - eContestantStatus[eContestAI.contestantId].pointTotal;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_5A(void)
{
    ContestAICmd_unk_59();

    if (eContestAI.scriptResult < 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5B(void)
{
    ContestAICmd_unk_59();

    if (eContestAI.scriptResult > 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5C(void)
{
    ContestAICmd_unk_59();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5D(void)
{
    ContestAICmd_unk_59();

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5E(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI.scriptResult = gContestMonConditions[var] - gContestMonConditions[eContestAI.contestantId];
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_5F(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI.scriptResult < 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_60(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI.scriptResult > 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_61(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_62(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_63(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);
    u8 var2 = gAIScriptPtr[2];
    u16 move = eContest.moveHistory[var2][var];

    eContestAI.scriptResult = gContestMoves[move].effect;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_64(void)
{
    ContestAICmd_unk_63();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_65(void)
{
    ContestAICmd_unk_63();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_66(void)
{
    ContestAICmd_unk_63();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_67(void)
{
    ContestAICmd_unk_63();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_68(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);
    u8 var2 = gAIScriptPtr[2];
    s8 result = eContest.excitementHistory[var2][var];

    eContestAI.scriptResult = result;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_69(void)
{
    ContestAICmd_unk_68();

    if (eContestAI.scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6A(void)
{
    ContestAICmd_unk_68();

    if (eContestAI.scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6B(void)
{
    ContestAICmd_unk_68();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6C(void)
{
    ContestAICmd_unk_68();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6D(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);
    u8 var2 = gAIScriptPtr[2];
    u16 move = eContest.moveHistory[var2][var];

    eContestAI.scriptResult = gContestEffects[gContestMoves[move].effect].effectType;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_6E(void)
{
    ContestAICmd_unk_6D();

    if (eContestAI.scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6F(void)
{
    ContestAICmd_unk_6D();

    if (eContestAI.scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_70(void)
{
    eContestAI.scriptArr[gAIScriptPtr[1]] = eContestAI.scriptResult;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_71(void)
{
    eContestAI.scriptArr[gAIScriptPtr[1]] = T1_READ_16(gAIScriptPtr + 2);
    gAIScriptPtr += 4;
}

static void ContestAICmd_unk_72(void)
{
    // wtf? shouldn't T1_READ_16 work here? why the signed 8 load by gAIScriptPtr[2]?
    eContestAI.scriptArr[gAIScriptPtr[1]] += ((s8)gAIScriptPtr[2] | gAIScriptPtr[3] << 8);
    gAIScriptPtr += 4;
}

static void ContestAICmd_unk_73(void)
{
    eContestAI.scriptArr[gAIScriptPtr[1]] += eContestAI.scriptArr[gAIScriptPtr[2]];
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_74(void)
{
    eContestAI.scriptArr[gAIScriptPtr[1]] += eContestAI.scriptArr[gAIScriptPtr[2]];
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_75(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] < T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_76(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] > T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_77(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] == T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_78(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] != T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_79(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] < (eContestAI.scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_unk_7A(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] > (eContestAI.scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_unk_7B(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] == (eContestAI.scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_unk_7C(void)
{
    if (eContestAI.scriptArr[gAIScriptPtr[1]] != (eContestAI.scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_if_random(void)
{
    if ((Random() & 0xFF) < eContestAI.scriptArr[gAIScriptPtr[1]])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_7E(void)
{
    if ((Random() & 0xFF) > eContestAI.scriptArr[gAIScriptPtr[1]])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

// jump
static void ContestAICmd_jump(void)
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
        eContestAI.aiAction |= 1;
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

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_user_doesnt_have_exciting_move(void)
{
    ContestAICmd_check_user_has_exciting_move();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_85(void)
{
    int result = 0;
    int i;
    u16 arg = T1_READ_16(gAIScriptPtr + 1);

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 move = gContestMons[eContestAI.contestantId].moves[i];
        if (move == arg)
        {
            result = 1;
            break;
        }
    }

    eContestAI.scriptResult = result;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_86(void)
{
    ContestAICmd_unk_85();

    if (eContestAI.scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_if_effect_in_user_moveset(void)
{
    ContestAICmd_unk_85();

    if (eContestAI.scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}
