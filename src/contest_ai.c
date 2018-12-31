#include "global.h"
#include "battle.h"
#include "contest.h"
#include "random.h"
#include "contest_ai.h"
#include "contest_effect.h"

extern const u8 *gAIScriptPtr;
extern const u8 *gContestAIs[];

static void ContestAICmd_unk_00(void);
static void ContestAICmd_get_turn(void);
static void ContestAICmd_unk_02(void);
static void ContestAICmd_unk_03(void);
static void ContestAICmd_unk_04(void);
static void ContestAICmd_unk_05(void);
static void ContestAICmd_get_excitement(void);
static void ContestAICmd_unk_07(void);
static void ContestAICmd_unk_08(void);
static void ContestAICmd_unk_09(void);
static void ContestAICmd_unk_0A(void);
static void ContestAICmd_get_user_order(void);
static void ContestAICmd_unk_0C(void);
static void ContestAICmd_unk_0D(void);
static void ContestAICmd_unk_0E(void);
static void ContestAICmd_unk_0F(void);
static void ContestAICmd_get_user_condition_maybe(void);
static void ContestAICmd_unk_11(void);
static void ContestAICmd_unk_12(void);
static void ContestAICmd_unk_13(void);
static void ContestAICmd_unk_14(void);
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
static void ContestAICmd_unk_20(void);
static void ContestAICmd_unk_21(void);
static void ContestAICmd_get_move_excitement(void);
static void ContestAICmd_unk_23(void);
static void ContestAICmd_unk_24(void);
static void ContestAICmd_unk_25(void);
static void ContestAICmd_unk_26(void);
static void ContestAICmd_get_move_effect(void);
static void ContestAICmd_unk_28(void);
static void ContestAICmd_unk_29(void);
static void ContestAICmd_get_move_effect_type(void);
static void ContestAICmd_unk_2B(void);
static void ContestAICmd_unk_2C(void);
static void ContestAICmd_check_move_has_highest_appeal(void);
static void ContestAICmd_unk_2E(void);
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
static void ContestAICmd_unk_3C(void);
static void ContestAICmd_unk_3D(void);
static void ContestAICmd_unk_3E(void);
static void ContestAICmd_unk_3F(void);
static void ContestAICmd_check_combo_starter(void);
static void ContestAICmd_unk_41(void);
static void ContestAICmd_unk_42(void);
static void ContestAICmd_check_combo_finisher(void);
static void ContestAICmd_unk_44(void);
static void ContestAICmd_unk_45(void);
static void ContestAICmd_check_would_finish_combo(void);
static void ContestAICmd_unk_47(void);
static void ContestAICmd_unk_48(void);
static void ContestAICmd_get_condition(void);
static void ContestAICmd_unk_4A(void);
static void ContestAICmd_unk_4B(void);
static void ContestAICmd_unk_4C(void);
static void ContestAICmd_unk_4D(void);
static void ContestAICmd_get_used_combo_starter(void);
static void ContestAICmd_unk_4F(void);
static void ContestAICmd_unk_50(void);
static void ContestAICmd_unk_51(void);
static void ContestAICmd_unk_52(void);
static void ContestAICmd_check_can_participate(void);
static void ContestAICmd_unk_54(void);
static void ContestAICmd_unk_55(void);
static void ContestAICmd_get_val_812A188(void);
static void ContestAICmd_unk_57(void);
static void ContestAICmd_unk_58(void);
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
static void ContestAICmd_unk_7D(void);
static void ContestAICmd_unk_7E(void);
static void ContestAICmd_unk_7F(void);
static void ContestAICmd_unk_80(void);
static void ContestAICmd_unk_81(void);
static void ContestAICmd_check_for_exciting_move(void);
static void ContestAICmd_unk_83(void);
static void ContestAICmd_unk_84(void);
static void ContestAICmd_unk_85(void);
static void ContestAICmd_unk_86(void);
static void ContestAICmd_unk_87(void);

typedef void (* ContestAICmdFunc)(void);

static const ContestAICmdFunc sContestAICmdTable[] =
{
    ContestAICmd_unk_00,                          // 0x00
    ContestAICmd_get_turn,                        // 0x01
    ContestAICmd_unk_02,                          // 0x02
    ContestAICmd_unk_03,                          // 0x03
    ContestAICmd_unk_04,                          // 0x04
    ContestAICmd_unk_05,                          // 0x05
    ContestAICmd_get_excitement,                  // 0x06
    ContestAICmd_unk_07,                          // 0x07
    ContestAICmd_unk_08,                          // 0x08
    ContestAICmd_unk_09,                          // 0x09
    ContestAICmd_unk_0A,                          // 0x0A
    ContestAICmd_get_user_order,                  // 0x0B
    ContestAICmd_unk_0C,                          // 0x0C
    ContestAICmd_unk_0D,                          // 0x0D
    ContestAICmd_unk_0E,                          // 0x0E
    ContestAICmd_unk_0F,                          // 0x0F
    ContestAICmd_get_user_condition_maybe,        // 0x10
    ContestAICmd_unk_11,                          // 0x11
    ContestAICmd_unk_12,                          // 0x12
    ContestAICmd_unk_13,                          // 0x13
    ContestAICmd_unk_14,                          // 0x14
    ContestAICmd_unk_15,                          // 0x15
    ContestAICmd_unk_16,                          // 0x16
    ContestAICmd_unk_17,                          // 0x17
    ContestAICmd_unk_18,                          // 0x18
    ContestAICmd_unk_19,                          // 0x19
    ContestAICmd_unk_1A,                          // 0x1A
    ContestAICmd_unk_1B,                          // 0x1B
    ContestAICmd_unk_1C,                          // 0x1C
    ContestAICmd_unk_1D,                          // 0x1D
    ContestAICmd_unk_1E,                          // 0x1E
    ContestAICmd_get_contest_type,                // 0x1F
    ContestAICmd_unk_20,                          // 0x20
    ContestAICmd_unk_21,                          // 0x21
    ContestAICmd_get_move_excitement,             // 0x22
    ContestAICmd_unk_23,                          // 0x23
    ContestAICmd_unk_24,                          // 0x24
    ContestAICmd_unk_25,                          // 0x25
    ContestAICmd_unk_26,                          // 0x26
    ContestAICmd_get_move_effect,                 // 0x27
    ContestAICmd_unk_28,                          // 0x28
    ContestAICmd_unk_29,                          // 0x29
    ContestAICmd_get_move_effect_type,            // 0x2A
    ContestAICmd_unk_2B,                          // 0x2B
    ContestAICmd_unk_2C,                          // 0x2C
    ContestAICmd_check_move_has_highest_appeal,   // 0x2D
    ContestAICmd_unk_2E,                          // 0x2E
    ContestAICmd_unk_2F,                          // 0x2F
    ContestAICmd_unk_30,                          // 0x30
    ContestAICmd_unk_31,                          // 0x31
    ContestAICmd_unk_32,                          // 0x32
    ContestAICmd_unk_33,                          // 0x33
    ContestAICmd_unk_34,                          // 0x34
    ContestAICmd_unk_35,                          // 0x35
    ContestAICmd_unk_36,                          // 0x36
    ContestAICmd_unk_37,                          // 0x37
    ContestAICmd_unk_38,                          // 0x38
    ContestAICmd_unk_39,                          // 0x39
    ContestAICmd_unk_3A,                          // 0x3A
    ContestAICmd_get_move_used_count,             // 0x3B
    ContestAICmd_unk_3C,                          // 0x3C
    ContestAICmd_unk_3D,                          // 0x3D
    ContestAICmd_unk_3E,                          // 0x3E
    ContestAICmd_unk_3F,                          // 0x3F
    ContestAICmd_check_combo_starter,             // 0x40
    ContestAICmd_unk_41,                          // 0x41
    ContestAICmd_unk_42,                          // 0x42
    ContestAICmd_check_combo_finisher,            // 0x43
    ContestAICmd_unk_44,                          // 0x44
    ContestAICmd_unk_45,                          // 0x45
    ContestAICmd_check_would_finish_combo,        // 0x46
    ContestAICmd_unk_47,                          // 0x47
    ContestAICmd_unk_48,                          // 0x48
    ContestAICmd_get_condition,                   // 0x49
    ContestAICmd_unk_4A,                          // 0x4A
    ContestAICmd_unk_4B,                          // 0x4B
    ContestAICmd_unk_4C,                          // 0x4C
    ContestAICmd_unk_4D,                          // 0x4D
    ContestAICmd_get_used_combo_starter,          // 0x4E
    ContestAICmd_unk_4F,                          // 0x4F
    ContestAICmd_unk_50,                          // 0x50
    ContestAICmd_unk_51,                          // 0x51
    ContestAICmd_unk_52,                          // 0x52
    ContestAICmd_check_can_participate,           // 0x53
    ContestAICmd_unk_54,                          // 0x54
    ContestAICmd_unk_55,                          // 0x55
    ContestAICmd_get_val_812A188,                 // 0x56
    ContestAICmd_unk_57,                          // 0x57
    ContestAICmd_unk_58,                          // 0x58
    ContestAICmd_unk_59,                          // 0x59
    ContestAICmd_unk_5A,                          // 0x5A
    ContestAICmd_unk_5B,                          // 0x5B
    ContestAICmd_unk_5C,                          // 0x5C
    ContestAICmd_unk_5D,                          // 0x5D
    ContestAICmd_unk_5E,                          // 0x5E
    ContestAICmd_unk_5F,                          // 0x5F
    ContestAICmd_unk_60,                          // 0x60
    ContestAICmd_unk_61,                          // 0x61
    ContestAICmd_unk_62,                          // 0x62
    ContestAICmd_unk_63,                          // 0x63
    ContestAICmd_unk_64,                          // 0x64
    ContestAICmd_unk_65,                          // 0x65
    ContestAICmd_unk_66,                          // 0x66
    ContestAICmd_unk_67,                          // 0x67
    ContestAICmd_unk_68,                          // 0x68
    ContestAICmd_unk_69,                          // 0x69
    ContestAICmd_unk_6A,                          // 0x6A
    ContestAICmd_unk_6B,                          // 0x6B
    ContestAICmd_unk_6C,                          // 0x6C
    ContestAICmd_unk_6D,                          // 0x6D
    ContestAICmd_unk_6E,                          // 0x6E
    ContestAICmd_unk_6F,                          // 0x6F
    ContestAICmd_unk_70,                          // 0x70
    ContestAICmd_unk_71,                          // 0x71
    ContestAICmd_unk_72,                          // 0x72
    ContestAICmd_unk_73,                          // 0x73
    ContestAICmd_unk_74,                          // 0x74
    ContestAICmd_unk_75,                          // 0x75
    ContestAICmd_unk_76,                          // 0x76
    ContestAICmd_unk_77,                          // 0x77
    ContestAICmd_unk_78,                          // 0x78
    ContestAICmd_unk_79,                          // 0x79
    ContestAICmd_unk_7A,                          // 0x7A
    ContestAICmd_unk_7B,                          // 0x7B
    ContestAICmd_unk_7C,                          // 0x7C
    ContestAICmd_unk_7D,                          // 0x7D
    ContestAICmd_unk_7E,                          // 0x7E
    ContestAICmd_unk_7F,                          // 0x7F
    ContestAICmd_unk_80,                          // 0x80
    ContestAICmd_unk_81,                          // 0x81
    ContestAICmd_check_for_exciting_move,         // 0x82
    ContestAICmd_unk_83,                          // 0x83
    ContestAICmd_unk_84,                          // 0x84
    ContestAICmd_unk_85,                          // 0x85
    ContestAICmd_unk_86,                          // 0x86
    ContestAICmd_unk_87,                          // 0x87
};

static void ContestAI_DoAIProcessing(void);
static bool8 sub_81563B0(u8);
static void AIStackPushVar(const u8 *);
static u8 AIStackPop(void);

void ContestAI_ResetAI(u8 contestantAI)
{
    int i;
    memset(eContestAI, 0, sizeof(struct ContestAIInfo));

    for (i = 0; i < 4; i++)
        eContestAI->unk5[i] = 100;

    eContestAI->contestantId = contestantAI;
    eContestAI->stackSize = 0;
    eContestAI->flags = gContestMons[eContestAI->contestantId].flags;
}

u8 ContestAI_GetActionToUse(void)
{
    while (eContestAI->flags != 0)
    {
        if (eContestAI->flags & 1)
        {
            eContestAI->aiState = 0;
            ContestAI_DoAIProcessing();
        }
        eContestAI->flags >>= 1;
        eContestAI->unk10++;
        eContestAI->unk4 = 0;
    }

    while (1)
    {
        u8 rval = Random() & 3;
        u8 r2 = eContestAI->unk5[rval];
        int i;
        for (i = 0; i < 4; i++)
        {
            if (r2 < eContestAI->unk5[i])
                break;
        }
        if (i == 4)
            return rval;
    }
}

static void ContestAI_DoAIProcessing(void)
{
    while (eContestAI->aiState != CONTESTAI_FINISHED)
    {
        switch(eContestAI->aiState)
        {
            case CONTESTAI_DO_NOT_PROCESS:
                break;
            case CONTESTAI_SETTING_UP:
                gAIScriptPtr = gContestAIs[eContestAI->unk10];

                if (gContestMons[eContestAI->contestantId].moves[eContestAI->unk4] == 0)
                    eContestAI->unk2 = 0; // don't process a move that doesn't exist.
                else
                    eContestAI->unk2 = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];
                eContestAI->aiState++;
                break;
            case CONTESTAI_PROCESSING:
                if (eContestAI->unk2 != 0)
                    sContestAICmdTable[*gAIScriptPtr](); // run the command.
                else
                {
                    eContestAI->unk5[eContestAI->unk4] = 0; // don't consider a move that doesn't exist.
                    eContestAI->aiAction |= 1;
                }
                if (eContestAI->aiAction & 1)
                {
                    eContestAI->unk4++;
                    if (eContestAI->unk4 < 4)
                        eContestAI->aiState = 0;
                    else
                        eContestAI->aiState++;
                    eContestAI->aiAction &= 0xFE; // TODO: Define action flags
                }
                break;
        }
    }
}

static u8 sub_81563B0(u8 var)
{
    int i;

    for (i = 0; i < 4; i++)
        if (shared192D0.turnOrder[i] == var)
            break;

    return i;
}

static void ContestAICmd_unk_00(void)
{
    s16 score = eContestAI->unk5[eContestAI->unk4] + (s8)gAIScriptPtr[1];

    if (score > 255)
        score = 255;
    else if (score < 0)
        score = 0;

    eContestAI->unk5[eContestAI->unk4] = score;

    gAIScriptPtr += 2;
}

static void ContestAICmd_get_turn(void)
{
    eContestAI->scriptResult = sContest.turnNumber;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_02(void)
{
    ContestAICmd_get_turn();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_03(void)
{
    ContestAICmd_get_turn();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_04(void)
{
    ContestAICmd_get_turn();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_05(void)
{
    ContestAICmd_get_turn();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_excitement(void)
{
    eContestAI->scriptResult = sContest.applauseLevel;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_07(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_08(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_09(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_0A(void)
{
    ContestAICmd_get_excitement();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_user_order(void)
{
    eContestAI->scriptResult = shared192D0.turnOrder[eContestAI->contestantId];
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_0C(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_0D(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_0E(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_0F(void)
{
    ContestAICmd_get_user_order();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_user_condition_maybe(void)
{
    eContestAI->scriptResult = sContestantStatus[eContestAI->contestantId].condition / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_11(void)
{
    ContestAICmd_get_user_condition_maybe();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_12(void)
{
    ContestAICmd_get_user_condition_maybe();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_13(void)
{
    ContestAICmd_get_user_condition_maybe();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_14(void)
{
    ContestAICmd_get_user_condition_maybe();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_15(void)
{
    eContestAI->scriptResult = sContestantStatus[eContestAI->contestantId].unk4;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_16(void)
{
    ContestAICmd_unk_15();

    if (eContestAI->scriptResult < (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_17(void)
{
    ContestAICmd_unk_15();

    if (eContestAI->scriptResult > (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_18(void)
{
    ContestAICmd_unk_15();

    if (eContestAI->scriptResult == (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_19(void)
{
    ContestAICmd_unk_15();

    if (eContestAI->scriptResult != (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1A(void)
{
    eContestAI->scriptResult = gContestMonConditions[eContestAI->contestantId];
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_1B(void)
{
    ContestAICmd_unk_1A();

    if (eContestAI->scriptResult < (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1C(void)
{
    ContestAICmd_unk_1A();

    if (eContestAI->scriptResult > (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1D(void)
{
    ContestAICmd_unk_1A();

    if (eContestAI->scriptResult == (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_1E(void)
{
    ContestAICmd_unk_1A();

    if (eContestAI->scriptResult != (s16)T1_READ_16(gAIScriptPtr + 0))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_get_contest_type(void)
{
    eContestAI->scriptResult = gSpecialVar_ContestCategory;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_20(void)
{
    ContestAICmd_get_contest_type();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_21(void)
{
    ContestAICmd_get_contest_type();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_excitement(void)
{
    eContestAI->scriptResult = Contest_GetMoveExcitement(gContestMons[eContestAI->contestantId].moves[eContestAI->unk4]);
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_23(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI->scriptResult < (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_24(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI->scriptResult > (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_25(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI->scriptResult == (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_26(void)
{
    ContestAICmd_get_move_excitement();

    if (eContestAI->scriptResult != (s8)gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_effect(void)
{
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    eContestAI->scriptResult = gContestMoves[move].effect;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_28(void)
{
    ContestAICmd_get_move_effect();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_29(void)
{
    ContestAICmd_get_move_effect();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_effect_type(void)
{
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    eContestAI->scriptResult = gContestEffects[gContestMoves[move].effect].effectType;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_2B(void)
{
    ContestAICmd_get_move_effect_type();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_2C(void)
{
    ContestAICmd_get_move_effect_type();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_check_move_has_highest_appeal(void)
{
    int i;
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];
    u8 appeal = gContestEffects[gContestMoves[move].effect].appeal;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 newMove = gContestMons[eContestAI->contestantId].moves[i];
        if (newMove != 0 && appeal < gContestEffects[gContestMoves[newMove].effect].appeal)
            break;
    }

    if (i == MAX_MON_MOVES)
        eContestAI->scriptResult = TRUE;
    else
        eContestAI->scriptResult = FALSE;

    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_2E(void)
{
    ContestAICmd_check_move_has_highest_appeal();

    if (eContestAI->scriptResult != FALSE)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_2F(void)
{
    int i;
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];
    u8 jam = gContestEffects[gContestMoves[move].effect].jam;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 newMove = gContestMons[eContestAI->contestantId].moves[i];
        if (newMove != 0 && jam < gContestEffects[gContestMoves[newMove].effect].jam)
            break;
    }

    if (i == MAX_MON_MOVES)
        eContestAI->scriptResult = TRUE;
    else
        eContestAI->scriptResult = FALSE;

    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_30(void)
{
    ContestAICmd_unk_2F();

    if (eContestAI->scriptResult != FALSE)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_31(void)
{
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    eContestAI->scriptResult = gContestEffects[gContestMoves[move].effect].appeal / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_32(void)
{
    ContestAICmd_unk_31();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_33(void)
{
    ContestAICmd_unk_31();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_34(void)
{
    ContestAICmd_unk_31();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_35(void)
{
    ContestAICmd_unk_31();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_36(void)
{
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    eContestAI->scriptResult = gContestEffects[gContestMoves[move].effect].jam / 10;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_37(void)
{
    ContestAICmd_unk_36();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_38(void)
{
    ContestAICmd_unk_36();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_39(void)
{
    ContestAICmd_unk_36();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_3A(void)
{
    ContestAICmd_unk_36();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_move_used_count(void)
{
    s16 result;
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    if (move != sContestantStatus[eContestAI->contestantId].prevMove)
        result = 0; // move is unique and not reused.
    else
        result = sContestantStatus[eContestAI->contestantId].moveRepeatCount + 1;

    eContestAI->scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_3C(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_3D(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_3E(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_3F(void)
{
    ContestAICmd_get_move_used_count();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_check_combo_starter(void)
{
    u8 result = 0;
    int i;
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gContestMons[eContestAI->contestantId].moves[i])
        {
            result = AreMovesContestCombo(move, gContestMons[eContestAI->contestantId].moves[i]);
            if (result)
            {
                result = 1;
                break;
            }
        }
    }

    if (result)
        result = 1;

    eContestAI->scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_41(void)
{
    ContestAICmd_check_combo_starter();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_42(void)
{
    ContestAICmd_check_combo_starter();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_check_combo_finisher(void)
{
    u8 result = 0;
    int i;
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gContestMons[eContestAI->contestantId].moves[i])
        {
            result = AreMovesContestCombo(gContestMons[eContestAI->contestantId].moves[i], move);
            if (result)
            {
                result = 1;
                break;
            }
        }
    }

    if (result)
        result = 1;

    eContestAI->scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_44(void)
{
    ContestAICmd_check_combo_finisher();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_45(void)
{
    ContestAICmd_check_combo_finisher();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_check_would_finish_combo(void)
{
    u8 result = 0;
    u16 move = gContestMons[eContestAI->contestantId].moves[eContestAI->unk4];

    if (sContestantStatus[eContestAI->contestantId].prevMove)
        result = AreMovesContestCombo(sContestantStatus[eContestAI->contestantId].prevMove, move);

    if (result)
        result = 1;

    eContestAI->scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_47(void)
{
    ContestAICmd_check_would_finish_combo();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_48(void)
{
    ContestAICmd_check_would_finish_combo();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_condition(void)
{
    int var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI->scriptResult = sContestantStatus[var].condition / 10;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_4A(void)
{
    ContestAICmd_get_condition();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_4B(void)
{
    ContestAICmd_get_condition();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_4C(void)
{
    ContestAICmd_get_condition();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_4D(void)
{
    ContestAICmd_get_condition();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_get_used_combo_starter(void)
{
    u16 result = 0;
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    if (sub_80DE1E8(var))
        result = gContestMoves[sContestantStatus[var].prevMove].comboStarterId ? 1 : 0;

    eContestAI->scriptResult = result;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_4F(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_50(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_51(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_52(void)
{
    ContestAICmd_get_used_combo_starter();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_check_can_participate(void)
{
    if (Contest_IsMonsTurnDisabled(sub_81563B0(gAIScriptPtr[1])))
        eContestAI->scriptResult = FALSE;
    else
        eContestAI->scriptResult = TRUE;

    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_54(void)
{
    ContestAICmd_check_can_participate();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_55(void)
{
    ContestAICmd_check_can_participate();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_get_val_812A188(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI->scriptResult = sContestantStatus[var].unk15_3;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_57(void)
{
    ContestAICmd_get_val_812A188();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_58(void)
{
    ContestAICmd_get_val_812A188();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_59(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI->scriptResult = sContestantStatus[var].unk4 - sContestantStatus[eContestAI->contestantId].unk4;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_5A(void)
{
    ContestAICmd_unk_59();

    if (eContestAI->scriptResult < 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5B(void)
{
    ContestAICmd_unk_59();

    if (eContestAI->scriptResult > 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5C(void)
{
    ContestAICmd_unk_59();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5D(void)
{
    ContestAICmd_unk_59();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_5E(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);

    eContestAI->scriptResult = gContestMonConditions[var] - gContestMonConditions[eContestAI->contestantId];
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_5F(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI->scriptResult < 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_60(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI->scriptResult > 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_61(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_62(void)
{
    ContestAICmd_unk_5E();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_63(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);
    u8 var2 = gAIScriptPtr[2];
    u16 move = sContest.unk19220[var2][var];

    eContestAI->scriptResult = gContestMoves[move].effect;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_64(void)
{
    ContestAICmd_unk_63();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_65(void)
{
    ContestAICmd_unk_63();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_66(void)
{
    ContestAICmd_unk_63();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_67(void)
{
    ContestAICmd_unk_63();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_68(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);
    u8 var2 = gAIScriptPtr[2];
    s8 result = sContest.unk19248[var2][var];

    eContestAI->scriptResult = result;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_69(void)
{
    ContestAICmd_unk_68();

    if (eContestAI->scriptResult < gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6A(void)
{
    ContestAICmd_unk_68();

    if (eContestAI->scriptResult > gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6B(void)
{
    ContestAICmd_unk_68();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6C(void)
{
    ContestAICmd_unk_68();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6D(void)
{
    u8 var = sub_81563B0(gAIScriptPtr[1]);
    u8 var2 = gAIScriptPtr[2];
    u16 move = sContest.unk19220[var2][var];

    eContestAI->scriptResult = gContestEffects[gContestMoves[move].effect].effectType;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_6E(void)
{
    ContestAICmd_unk_6D();

    if (eContestAI->scriptResult == gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_6F(void)
{
    ContestAICmd_unk_6D();

    if (eContestAI->scriptResult != gAIScriptPtr[0])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void ContestAICmd_unk_70(void)
{
    eContestAI->scriptArr[gAIScriptPtr[1]] = eContestAI->scriptResult;
    gAIScriptPtr += 2;
}

static void ContestAICmd_unk_71(void)
{
    eContestAI->scriptArr[gAIScriptPtr[1]] = T1_READ_16(gAIScriptPtr + 2);
    gAIScriptPtr += 4;
}

static void ContestAICmd_unk_72(void)
{
    // wtf? shouldn't T1_READ_16 work here? why the signed 8 load by gAIScriptPtr[2]?
    eContestAI->scriptArr[gAIScriptPtr[1]] += ((s8)gAIScriptPtr[2] | gAIScriptPtr[3] << 8);
    gAIScriptPtr += 4;
}

static void ContestAICmd_unk_73(void)
{
    eContestAI->scriptArr[gAIScriptPtr[1]] += eContestAI->scriptArr[gAIScriptPtr[2]];
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_74(void)
{
    eContestAI->scriptArr[gAIScriptPtr[1]] += eContestAI->scriptArr[gAIScriptPtr[2]];
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_75(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] < T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_76(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] > T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_77(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] == T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_78(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] != T1_READ_16(gAIScriptPtr + 2))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void ContestAICmd_unk_79(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] < (eContestAI->scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_unk_7A(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] > (eContestAI->scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_unk_7B(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] == (eContestAI->scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_unk_7C(void)
{
    if (eContestAI->scriptArr[gAIScriptPtr[1]] != (eContestAI->scriptArr[gAIScriptPtr[2]]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void ContestAICmd_unk_7D(void)
{
    if ((Random() & 0xFF) < eContestAI->scriptArr[gAIScriptPtr[1]])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void ContestAICmd_unk_7E(void)
{
    if ((Random() & 0xFF) > eContestAI->scriptArr[gAIScriptPtr[1]])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

// jump
static void ContestAICmd_unk_7F(void)
{
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void ContestAICmd_unk_80(void)
{
    AIStackPushVar(gAIScriptPtr + 5);
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void ContestAICmd_unk_81(void)
{
    if (!AIStackPop())
        eContestAI->aiAction |= 1;
}

static void AIStackPushVar(const u8 *ptr)
{
    eContestAI->stack[eContestAI->stackSize++] = ptr;
}

static bool8 AIStackPop(void)
{
    if (eContestAI->stackSize != 0)
    {
        --eContestAI->stackSize;
        gAIScriptPtr = eContestAI->stack[eContestAI->stackSize];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void ContestAICmd_check_for_exciting_move(void)
{
    int result = 0;
    int i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gContestMons[eContestAI->contestantId].moves[i])
        {
            if (Contest_GetMoveExcitement(gContestMons[eContestAI->contestantId].moves[i]) == 1)
            {
                result = 1;
                break;
            }
        }
    }

    eContestAI->scriptResult = result;
    gAIScriptPtr += 1;
}

static void ContestAICmd_unk_83(void)
{
    ContestAICmd_check_for_exciting_move();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_84(void)
{
    ContestAICmd_check_for_exciting_move();

    if (eContestAI->scriptResult == 0)
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
        u16 move = gContestMons[eContestAI->contestantId].moves[i];
        if (move == arg)
        {
            result = 1;
            break;
        }
    }

    eContestAI->scriptResult = result;
    gAIScriptPtr += 3;
}

static void ContestAICmd_unk_86(void)
{
    ContestAICmd_unk_85();

    if (eContestAI->scriptResult != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}

static void ContestAICmd_unk_87(void)
{
    ContestAICmd_unk_85();

    if (eContestAI->scriptResult == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 0);
    else
        gAIScriptPtr += 4;
}
