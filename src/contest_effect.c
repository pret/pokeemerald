#include "global.h"
#include "random.h"
#include "constants/moves.h"
#include "contest.h"
#include "contest_effect.h"

static void ContestEffect_HighlyAppealing(void);
static void ContestEffect_UserMoreEasilyStartled(void);
static void ContestEffect_GreatAppealButNoMoreMoves(void);
static void ContestEffect_RepetitionNotBoring(void);
static void ContestEffect_AvoidStartleOnce(void);
static void ContestEffect_AvoidStartle(void);
static void ContestEffect_AvoidStartleSlightly(void);
static void ContestEffect_UserLessEasilyStartled(void);
static void ContestEffect_StartleFrontMon(void);
static void ContestEffect_StartlePrevMons(void);
static void ContestEffect_StartlePrevMon2(void);
static void ContestEffect_StartlePrevMons2(void);
static void ContestEffect_ShiftJudgeAttention(void);
static void ContestEffect_StartleMonWithJudgesAttention(void);
static void ContestEffect_JamsOthersButMissOneTurn(void);
static void ContestEffect_StartleMonsSameTypeAppeal(void);
static void ContestEffect_StartleMonsCoolAppeal(void);
static void ContestEffect_StartleMonsBeautyAppeal(void);
static void ContestEffect_StartleMonsCuteAppeal(void);
static void ContestEffect_StartleMonsSmartAppeal(void);
static void ContestEffect_StartleMonsToughAppeal(void);
static void ContestEffect_MakeFollowingMonNervous(void);
static void ContestEffect_MakeFollowingMonsNervous(void);
static void ContestEffect_WorsenConditionOfPrevMons(void);
static void ContestEffect_BadlyStartlesMonsInGoodCondition(void);
static void ContestEffect_BetterIfFirst(void);
static void ContestEffect_BetterIfLast(void);
static void ContestEffect_AppealAsGoodAsPrevOnes(void);
static void ContestEffect_AppealAsGoodAsPrevOne(void);
static void ContestEffect_BetterWhenLater(void);
static void ContestEffect_QualityDependsOnTiming(void);
static void ContestEffect_BetterIfSameType(void);
static void ContestEffect_BetterIfDiffType(void);
static void ContestEffect_AffectedByPrevAppeal(void);
static void ContestEffect_ImproveConditionPreventNervousness(void);
static void ContestEffect_BetterWithGoodCondition(void);
static void ContestEffect_NextAppealEarlier(void);
static void ContestEffect_NextAppealLater(void);
static void ContestEffect_MakeScramblingTurnOrderEasier(void);
static void ContestEffect_ScrambleNextTurnOrder(void);
static void ContestEffect_ExciteAudienceInAnyContest(void);
static void ContestEffect_BadlyStartleMonsWithGoodAppeals(void);
static void ContestEffect_BetterWhenAudienceExcited(void);
static void ContestEffect_DontExciteAudience(void);
static void JamByMoveCategory(u8);
static bool8 CanUnnerveContestant(u8);
static u8 WasAtLeastOneOpponentJammed(void);
static void JamContestant(u8, u8);
static s16 RoundTowardsZero(s16);
static s16 RoundUp(s16);

#include "data/contest_moves.h"

bool8 AreMovesContestCombo(u16 lastMove, u16 nextMove)
{
    u8 nextMoveComboMoves[4];
    u8 lastMoveComboStarterId = gContestMoves[lastMove].comboStarterId;
    nextMoveComboMoves[0] = gContestMoves[nextMove].comboMoves[0];
    nextMoveComboMoves[1] = gContestMoves[nextMove].comboMoves[1];
    nextMoveComboMoves[2] = gContestMoves[nextMove].comboMoves[2];
    nextMoveComboMoves[3] = gContestMoves[nextMove].comboMoves[3];

    if (lastMoveComboStarterId == 0)
        return FALSE;
    else if (lastMoveComboStarterId == nextMoveComboMoves[0] || lastMoveComboStarterId == nextMoveComboMoves[1] || lastMoveComboStarterId == nextMoveComboMoves[2] || lastMoveComboStarterId == nextMoveComboMoves[3])
        return gComboStarterLookupTable[lastMoveComboStarterId];
    else
        return FALSE;
}

// A highly appealing move.
static void ContestEffect_HighlyAppealing(void)
{
}

// After this move, the user is more easily startled.
static void ContestEffect_UserMoreEasilyStartled(void)
{
    sContestantStatus[shared192D0.contestant].moreEasilyStartled = TRUE;
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_MORE_CONSCIOUS);
}

// Makes a great appeal, but allows no more to the end.
static void ContestEffect_GreatAppealButNoMoreMoves(void)
{
    sContestantStatus[shared192D0.contestant].exploded = TRUE;
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_NO_APPEAL);
}

// Can be used repeatedly without boring the JUDGE.
static void ContestEffect_RepetitionNotBoring(void)
{
    sContestantStatus[shared192D0.contestant].usedRepeatableMove = TRUE;
    sContestantStatus[shared192D0.contestant].disappointedRepeat = FALSE;
    sContestantStatus[shared192D0.contestant].moveRepeatCount = 0;
}

// Can avoid being startled by others once.
static void ContestEffect_AvoidStartleOnce(void)
{
    sContestantStatus[shared192D0.contestant].jamSafetyCount = 1;
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_SETTLE_DOWN);
}

// Can avoid being startled by others.
static void ContestEffect_AvoidStartle(void)
{
    sContestantStatus[shared192D0.contestant].immune = TRUE;
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_OBLIVIOUS_TO_OTHERS);
}

// Can avoid being startled by others a little.
static void ContestEffect_AvoidStartleSlightly(void)
{
    sContestantStatus[shared192D0.contestant].jamReduction = 20;
    SetContestantEffectStringID(shared192D0.contestant,CONTEST_STRING_LESS_AWARE);
}

// After this move, the user is less likely to be startled.
static void ContestEffect_UserLessEasilyStartled(void)
{
    sContestantStatus[shared192D0.contestant].resistant = TRUE;
    SetContestantEffectStringID(shared192D0.contestant,CONTEST_STRING_STOPPED_CARING);
}

// Slightly startles the POKÈMON in front.
static void ContestEffect_StartleFrontMon(void)
{
    u8 idx = 0;
    u8 a = shared192D0.contestant;

    if (shared192D0.turnOrder[a] != 0) {
        int i;

        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[a] - 1 == shared192D0.turnOrder[i])
                break;
        }
        shared192D0.jamQueue[0] = i;
        shared192D0.jamQueue[1] = 0xFF;
        idx = WasAtLeastOneOpponentJammed();
    }
    if (idx == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Slightly startles those that have made appeals.
static void ContestEffect_StartlePrevMons(void)
{
    u8 idx = 0;
    u8 a = shared192D0.contestant;

    if (shared192D0.turnOrder[a] != 0)
    {
        int i, j;

        for (i = 0, j = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[a] > shared192D0.turnOrder[i])
                shared192D0.jamQueue[j++] = i;
        }

        shared192D0.jamQueue[j] = 0xFF;
        idx = WasAtLeastOneOpponentJammed();
    }
    if (idx == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Startles the POKÈMON that appealed before the user.
static void ContestEffect_StartlePrevMon2(void)
{
    u8 rval = Random() % 10;
    int jam;

    if (rval < 2)
        jam = 20;
    else if (rval < 8)
        jam = 40;
    else
        jam = 60;

    shared192D0.jam = jam;
    ContestEffect_StartleFrontMon();
}

// Startles all POKÈMON that appealed before the user.
static void ContestEffect_StartlePrevMons2(void)
{
    u8 numStartled = 0;
    u8 contestant = shared192D0.contestant;
    u8 turnOrder = shared192D0.turnOrder[contestant];

    if (turnOrder != 0)
    {
        int i;

        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[contestant] > shared192D0.turnOrder[i])
            {
                u8 rval, jam;

                shared192D0.jamQueue[0] = i;
                shared192D0.jamQueue[1] = 0xFF;
                rval = Random() % 10;

                if (rval == 0)
                    jam = 0;
                else if (rval <= 2)
                    jam = 10;
                else if (rval <= 4)
                    jam = 20;
                else if (rval <= 6)
                    jam = 30;
                else if (rval <= 8)
                    jam = 40;
                else
                    jam = 60;

                shared192D0.jam = jam;

                if (WasAtLeastOneOpponentJammed())
                    numStartled++;
            }
        }
    }
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
    if (numStartled == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
}

// Shifts the JUDGE's attention from others.
static void ContestEffect_ShiftJudgeAttention(void)
{
    bool32 hitAny = FALSE;
    u8 contestant = shared192D0.contestant;

    if (shared192D0.turnOrder[shared192D0.contestant] != 0)
    {
        int i;

        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[contestant] > shared192D0.turnOrder[i] &&
                sContestantStatus[i].hasJudgesAttention &&
                CanUnnerveContestant(i))
            {
                sContestantStatus[i].hasJudgesAttention = FALSE;
                sContestantStatus[i].judgesAttentionWasRemoved = TRUE;
                SetContestantEffectStringID(i, CONTEST_STRING_JUDGE_LOOK_AWAY2);
                hitAny = TRUE;
            }
        }
    }
    SetContestantEffectStringID(shared192D0.contestant,CONTEST_STRING_DAZZLE_ATTEMPT);
    if (!hitAny)
    {
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
    }
}

// Startles the POKÈMON that has the JUDGE's attention.
static void ContestEffect_StartleMonWithJudgesAttention(void)
{
    u8 numStartled = 0;
    u8 contestant = shared192D0.contestant;

    if (shared192D0.turnOrder[shared192D0.contestant] != 0)
    {
        int i;

        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[contestant] > shared192D0.turnOrder[i])
            {
                if (sContestantStatus[i].hasJudgesAttention)
                    shared192D0.jam = 50;
                else
                    shared192D0.jam = 10;
                shared192D0.jamQueue[0] = i;
                shared192D0.jamQueue[1] = 0xFF;
                if (WasAtLeastOneOpponentJammed())
                    numStartled++;
            }
        }
    }
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
    if (numStartled == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
}

// Jams the others, and misses one turn of appeals.
static void ContestEffect_JamsOthersButMissOneTurn(void)
{
    sContestantStatus[shared192D0.contestant].turnSkipped = TRUE;
    ContestEffect_StartlePrevMons();
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Startles POKÈMON that made a same-type appeal.
static void ContestEffect_StartleMonsSameTypeAppeal(void)
{
    u16 move = sContestantStatus[shared192D0.contestant].currMove;
    JamByMoveCategory(gContestMoves[move].contestCategory);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Badly startles POKÈMON that made COOL appeals.
static void ContestEffect_StartleMonsCoolAppeal(void)
{
    JamByMoveCategory(CONTEST_CATEGORY_COOL);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Badly startles POKÈMON that made BEAUTY appeals.
static void ContestEffect_StartleMonsBeautyAppeal(void)
{
    JamByMoveCategory(CONTEST_CATEGORY_BEAUTY);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Badly startles POKÈMON that made CUTE appeals.
static void ContestEffect_StartleMonsCuteAppeal(void)
{
    JamByMoveCategory(CONTEST_CATEGORY_CUTE);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Badly startles POKÈMON that made SMART appeals.
static void ContestEffect_StartleMonsSmartAppeal(void)
{
    JamByMoveCategory(CONTEST_CATEGORY_SMART);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Badly startles POKÈMON that made TOUGH appeals.
static void ContestEffect_StartleMonsToughAppeal(void)
{
    JamByMoveCategory(CONTEST_CATEGORY_TOUGH);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// Makes one POKÈMON after the user nervous.
static void ContestEffect_MakeFollowingMonNervous(void)
{
    bool32 hitAny = FALSE;

    if (shared192D0.turnOrder[shared192D0.contestant] != 3)
    {
        int i;

        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[shared192D0.contestant] + 1 == shared192D0.turnOrder[i])
            {
                if (CanUnnerveContestant(i))
                {
                    MakeContestantNervous(i);
                    SetContestantEffectStringID(i, CONTEST_STRING_NERVOUS);
                    hitAny = TRUE;
                }
                else
                {
                    SetContestantEffectStringID(i, CONTEST_STRING_UNAFFECTED);
                    hitAny = TRUE;
                }
            }
        }
    }
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_UNNERVE_ATTEMPT);
    if (!hitAny)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
}

// Makes all POKÈMON after the user nervous.
static void ContestEffect_MakeFollowingMonsNervous(void)
{
    u8 numUnnerved = 0;
    bool32 contestantUnnerved = FALSE;
    u8 contestantIds[5];
    int i;
    int numAfter;
    s16 oddsMod[4];
    s16 odds[4];

    memset(contestantIds, 0xFF, ARRAY_COUNT(contestantIds));
    for (i = 0, numAfter = 0; i < 4; i++)
    {
        if (shared192D0.turnOrder[shared192D0.contestant] < shared192D0.turnOrder[i] &&
            !sContestantStatus[i].nervous && !Contest_IsMonsTurnDisabled(i))
            contestantIds[numAfter++] = i;
    }

    if (numAfter == 1)
    {
        odds[0] = 60;
    }
    else if (numAfter == 2)
    {
        odds[0] = 30;
        odds[1] = 30;
    }
    else if (numAfter == 3)
    {
        odds[0] = 20;
        odds[1] = 20;
        odds[2] = 20;
    }
    else
    {
        for (i = 0; i < 4; i++)
            odds[i] = 0;
    }
    for (i = 0; i < 4; i++)
    {
        if (sContestantStatus[i].hasJudgesAttention && sub_80DE1E8(i))
            oddsMod[i] = gComboStarterLookupTable[gContestMoves[sContestantStatus[i].prevMove].comboStarterId] * 10;
        else
            oddsMod[i] = 0;
        oddsMod[i] -= (sContestantStatus[i].condition / 10) * 10;
    }
    if (odds[0] != 0)
    {
        for (i = 0; contestantIds[i] != 0xFF; i++)
        {
            if (Random() % 100 < odds[i] + oddsMod[contestantIds[i]])
            {
                if (CanUnnerveContestant(contestantIds[i]))
                {
                    MakeContestantNervous(contestantIds[i]);
                    SetContestantEffectStringID(contestantIds[i], CONTEST_STRING_NERVOUS);
                    numUnnerved++;
                }
                else
                {
                    contestantUnnerved = TRUE;
                }
            }
            else
            {
                contestantUnnerved = TRUE;
            }

            if (contestantUnnerved)
            {
                contestantUnnerved = FALSE;
                SetContestantEffectStringID(contestantIds[i], CONTEST_STRING_UNAFFECTED);
                numUnnerved++;
            }
            shared192D0.unnervedPokes[contestantIds[i]] = 1;
        }
    }
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_UNNERVE_WAITING);
    if (numUnnerved == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
}

// Worsens the condition of those that made appeals.
static void ContestEffect_WorsenConditionOfPrevMons(void)
{
    u8 numHit = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        if (shared192D0.turnOrder[shared192D0.contestant] > shared192D0.turnOrder[i] &&
            sContestantStatus[i].condition > 0 &&
            CanUnnerveContestant(i))
        {
            sContestantStatus[i].condition = 0;
            sContestantStatus[i].conditionMod = 2;
            SetContestantEffectStringID(i, CONTEST_STRING_REGAINED_FORM);
            numHit++;
        }
    }

    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_TAUNT_WELL);
    if (numHit == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_IGNORED);
}

// Badly startles POKÈMON in good condition.
static void ContestEffect_BadlyStartlesMonsInGoodCondition(void)
{
    u8 numHit = 0;
    int i;

    for (i = 0; i < 4; i++)
    {
        if (shared192D0.turnOrder[shared192D0.contestant] > shared192D0.turnOrder[i])
        {
            if (sContestantStatus[i].condition > 0)
                shared192D0.jam = 40;
            else
                shared192D0.jam = 10;
            shared192D0.jamQueue[0] = i;
            shared192D0.jamQueue[1] = 0xFF;
            if (WasAtLeastOneOpponentJammed())
                numHit++;
        }
    }
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_JAM_WELL);
    if (numHit == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_IGNORED);
}

// The appeal works great if performed first.
static void ContestEffect_BetterIfFirst(void)
{
    if (gUnknown_02039F26[shared192D0.contestant] == 0)
    {
        u16 move = sContestantStatus[shared192D0.contestant].currMove;
        sContestantStatus[shared192D0.contestant].appeal2 += 2 * gContestEffects[gContestMoves[move].effect].appeal;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_HUSTLE_STANDOUT);
    }
}

// The appeal works great if performed last.
static void ContestEffect_BetterIfLast(void)
{
    if (gUnknown_02039F26[shared192D0.contestant] == 3)
    {
        u16 move = sContestantStatus[shared192D0.contestant].currMove;
        sContestantStatus[shared192D0.contestant].appeal2 += 2 * gContestEffects[gContestMoves[move].effect].appeal;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_WORK_HARD_UNNOTICED);
    }
}

// Makes the appeal as good as those before it.
static void ContestEffect_AppealAsGoodAsPrevOnes(void)
{
    int i;
    int appealSum;

    for (i = 0, appealSum = 0; i < 4; i++)
    {
        if (shared192D0.turnOrder[shared192D0.contestant] > shared192D0.turnOrder[i])
            appealSum += sContestantStatus[i].appeal2;
    }
    if (appealSum < 0)
        appealSum = 0;

    if (shared192D0.turnOrder[shared192D0.contestant] == 0 || appealSum == 0)
    {
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_NOT_WELL);
    }
    else
    {
        sContestantStatus[shared192D0.contestant].appeal2 += appealSum / 2;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_WORK_BEFORE);
    }
    sContestantStatus[shared192D0.contestant].appeal2 = RoundTowardsZero(sContestantStatus[shared192D0.contestant].appeal2);
}

// Makes the appeal as good as the one before it.
static void ContestEffect_AppealAsGoodAsPrevOne(void)
{
    s16 appeal = 0;

    if (shared192D0.turnOrder[shared192D0.contestant] != 0)
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[shared192D0.contestant] - 1 == shared192D0.turnOrder[i])
                appeal = sContestantStatus[i].appeal2;
        }
    }
    if (shared192D0.turnOrder[shared192D0.contestant] == 0 || appeal <= 0)
    {
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_NOT_WELL2);
    }
    else
    {
        sContestantStatus[shared192D0.contestant].appeal2 += appeal;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_WORK_PRECEDING);
    }
}

// The appeal works better the later it is performed.
static void ContestEffect_BetterWhenLater(void)
{
    u8 whichTurn = shared192D0.turnOrder[shared192D0.contestant];
    if (whichTurn == 0)
        sContestantStatus[shared192D0.contestant].appeal2 = 10;
    else
        sContestantStatus[shared192D0.contestant].appeal2 = 20 * whichTurn;
    if (whichTurn == 0)
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_NOT_SHOWN_WELL);
    else if (whichTurn == 1)
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_SLIGHTLY_WELL);
    else if (whichTurn == 2)
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_PRETTY_WELL);
    else
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_EXCELLENTLY);
}

// The appeal's quality varies depending on its timing.
static void ContestEffect_QualityDependsOnTiming(void)
{
    u8 rval = Random() % 10;
    s16 appeal;

    if (rval < 3)
    {
        appeal = 10;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_NOT_VERY_WELL);
    } else if (rval < 6)
    {
        appeal = 20;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_SLIGHTLY_WELL2);
    } else if (rval < 8)
    {
        appeal = 40;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_PRETTY_WELL2);
    } else if (rval < 9)
    {
        appeal = 60;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_VERY_WELL);
    }
    else
    {
        appeal = 80;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_EXCELLENTLY2);
    }
    sContestantStatus[shared192D0.contestant].appeal2 = appeal;
}

static void ContestEffect_BetterIfSameType(void)
{
    s8 turnOrder = shared192D0.turnOrder[shared192D0.contestant];
    s8 i = turnOrder - 1, j;
    u16 move;

    if (turnOrder == 0)
        return;

    while (1)
    {
        for (j = 0; j < 4; j++)
        {
            if (shared192D0.turnOrder[j] == i)
                break;
        }
        if (sContestantStatus[j].noMoreTurns || sContestantStatus[j].nervous || sContestantStatus[j].numTurnsSkipped)
        {
            if (--i < 0)
                return;
        }
        else
        {
            break;
        }
    }

    move = sContestantStatus[shared192D0.contestant].currMove;
    if (gContestMoves[move].contestCategory == gContestMoves[sContestantStatus[j].currMove].contestCategory)
    {
        sContestantStatus[shared192D0.contestant].appeal2 += gContestEffects[gContestMoves[move].effect].appeal * 2;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_SAME_TYPE_GOOD);
    }
}

// Works well if different in type than the one before.
static void ContestEffect_BetterIfDiffType(void)
{
    if (shared192D0.turnOrder[shared192D0.contestant] != 0)
    {
        u16 move = sContestantStatus[shared192D0.contestant].currMove;
        int i;

        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[shared192D0.contestant] - 1 == shared192D0.turnOrder[i] &&
                gContestMoves[move].contestCategory != gContestMoves[sContestantStatus[i].currMove].contestCategory)
            {
                sContestantStatus[shared192D0.contestant].appeal2 += gContestEffects[gContestMoves[move].effect].appeal * 2;
                SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_DIFF_TYPE_GOOD);
                break;
            }
        }
    }
}

// Affected by how well the appeal in front goes.
static void ContestEffect_AffectedByPrevAppeal(void)
{
    if (shared192D0.turnOrder[shared192D0.contestant] != 0)
    {
        int i;

        for (i = 0; i < 4; i++)
        {
            if (shared192D0.turnOrder[shared192D0.contestant] - 1 == shared192D0.turnOrder[i])
            {
                if (sContestantStatus[shared192D0.contestant].appeal2 > sContestantStatus[i].appeal2)
                {
                    sContestantStatus[shared192D0.contestant].appeal2 *= 2;
                    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_STOOD_OUT_AS_MUCH);
                }
                else if (sContestantStatus[shared192D0.contestant].appeal2 < sContestantStatus[i].appeal2)
                {
                    sContestantStatus[shared192D0.contestant].appeal2 = 0;
                    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_NOT_AS_WELL);
                }
            }
        }
    }
}

// Ups the user's condition. Helps prevent nervousness.
static void ContestEffect_ImproveConditionPreventNervousness(void)
{
    if (sContestantStatus[shared192D0.contestant].condition < 30)
    {
        sContestantStatus[shared192D0.contestant].condition += 10;
        sContestantStatus[shared192D0.contestant].conditionMod = 1;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_CONDITION_ROSE);
    }
    else
    {
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_NO_CONDITION_IMPROVE);
    }
}

// The appeal works well if the user's condition is good.
static void ContestEffect_BetterWithGoodCondition(void)
{
    sContestantStatus[shared192D0.contestant].appealTripleCondition = TRUE;
    if (sContestantStatus[shared192D0.contestant].condition != 0)
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_HOT_STATUS);
    else
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_BAD_CONDITION_WEAK_APPEAL);
}

// The next appeal can be made earlier next turn.
static void ContestEffect_NextAppealEarlier(void)
{
    s8 i;
    s8 j;
    u8 turnOrder[4];

    if (sContest.turnNumber != 4)
    {
        for (i = 0; i < 4; i++)
            turnOrder[i] = sContestantStatus[i].nextTurnOrder;

        turnOrder[shared192D0.contestant] = 0xFF;

        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (j != shared192D0.contestant &&
                    i == turnOrder[j] &&
                    turnOrder[j] == sContestantStatus[j].nextTurnOrder)
                {
                    turnOrder[j]++;
                    break;
                }
            }
            if (j == 4)
                break;
        }

        turnOrder[shared192D0.contestant] = 0;
        sContestantStatus[shared192D0.contestant].turnOrderMod = 1;

        for (i = 0; i < 4; i++)
        {
            sContestantStatus[i].nextTurnOrder = turnOrder[i];
        }
        sContestantStatus[shared192D0.contestant].turnOrderModAction = 1;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_MOVE_UP_LINE);
    }
}

// The next appeal can be made later next turn.
static void ContestEffect_NextAppealLater(void)
{
    s8 i;
    s8 j;
    u8 turnOrder[4];

    if (sContest.turnNumber != 4)
    {
        for (i = 0; i < 4; i++)
            turnOrder[i] = sContestantStatus[i].nextTurnOrder;

        turnOrder[shared192D0.contestant] = 0xFF;

        for (i = 3; i > -1; i--)
        {
            for (j = 0; j < 4; j++)
            {
                if (j != shared192D0.contestant &&
                    i == turnOrder[j] &&
                    turnOrder[j] == sContestantStatus[j].nextTurnOrder)
                {
                    turnOrder[j]--;
                    break;
                }
            }
            if (j == 4)
                break;
        }

        turnOrder[shared192D0.contestant] = 3;
        sContestantStatus[shared192D0.contestant].turnOrderMod = 1;

        for (i = 0; i < 4; i++)
        {
            sContestantStatus[i].nextTurnOrder = turnOrder[i];
        }
        sContestantStatus[shared192D0.contestant].turnOrderModAction = 2;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_MOVE_BACK_LINE);
    }
}

// Makes the next turn's order more easily scrambled.
static void ContestEffect_MakeScramblingTurnOrderEasier(void)
{
    // dummied out?
}

// Scrambles the order of appeals on the next turn.
static void ContestEffect_ScrambleNextTurnOrder(void)
{
    s8 i;
    s8 j;
    u8 turnOrder[4];
    u8 unselectedContestants[4];

    if (sContest.turnNumber != 4)
    {
        for (i = 0; i < 4; i++)
        {
            turnOrder[i] = sContestantStatus[i].nextTurnOrder;
            unselectedContestants[i] = i;
        }

        for (i = 0; i < 4; i++)
        {
            u8 rval = Random() % (4 - i);

            for (j = 0; j < 4; j++)
            {
                if (unselectedContestants[j] != 0xFF)
                {
                    if (rval == 0)
                    {
                        turnOrder[j] = i;
                        unselectedContestants[j] = 0xFF;
                        break;
                    }
                    else
                        rval--;
                }
            }
        }

        for (i = 0; i < 4; i++)
        {
            sContestantStatus[i].nextTurnOrder = turnOrder[i];
            sContestantStatus[i].turnOrderMod = 2;
        }
        sContestantStatus[shared192D0.contestant].turnOrderModAction = 3;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_SCRAMBLE_ORDER);
    }
}

// An appeal that excites the audience in any CONTEST.
static void ContestEffect_ExciteAudienceInAnyContest(void)
{
    if (gContestMoves[sContestantStatus[shared192D0.contestant].currMove].contestCategory != gSpecialVar_ContestCategory)
    {
        sContestantStatus[shared192D0.contestant].overrideCategoryExcitementMod = TRUE;
    }
}

// Badly startles all POKÈMON that made good appeals.
static void ContestEffect_BadlyStartleMonsWithGoodAppeals(void)
{
    int i;
    u8 numJammed = 0;

    for (i = 0; i < 4; i++)
    {
        if (shared192D0.turnOrder[shared192D0.contestant] > shared192D0.turnOrder[i])
        {
            if (sContestantStatus[i].appeal2 > 0)
            {
                shared192D0.jam = sContestantStatus[i].appeal2 / 2;
                shared192D0.jam = RoundUp(shared192D0.jam);
            }
            else
                shared192D0.jam = 10;
            shared192D0.jamQueue[0] = i;
            shared192D0.jamQueue[1] = 0xFF;
            if (WasAtLeastOneOpponentJammed())
                numJammed++;
        }
    }
    if (numJammed == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
    SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTEMPT_STARTLE);
}

// The appeal works best the more the crowd is excited.
static void ContestEffect_BetterWhenAudienceExcited(void)
{
    s16 appeal;

    if (sContest.applauseLevel == 0)
    {
        appeal = 10;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_NOT_VERY_WELL);
    }
    else if (sContest.applauseLevel == 1)
    {
        appeal = 20;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_SLIGHTLY_WELL2);
    }
    else if (sContest.applauseLevel == 2)
    {
        appeal = 30;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_PRETTY_WELL2);
    }
    else if (sContest.applauseLevel == 3)
    {
        appeal = 50;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_VERY_WELL);
    }
    else
    {
        appeal = 60;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_APPEAL_EXCELLENTLY2);
    }
    sContestantStatus[shared192D0.contestant].appeal2 = appeal;
}

// Temporarily stops the crowd from growing excited.
static void ContestEffect_DontExciteAudience(void)
{
    if (!shared19328.excitementFrozen)
    {
        shared19328.excitementFrozen = TRUE;
        shared19328.excitementFreezer = shared192D0.contestant;
        SetContestantEffectStringID(shared192D0.contestant, CONTEST_STRING_ATTRACTED_ATTENTION);
    }
}

static void JamByMoveCategory(u8 category)
{
    int i;
    int numJammed = 0;

    for (i = 0; i < 4; i++)
    {
        if (shared192D0.turnOrder[shared192D0.contestant] > shared192D0.turnOrder[i])
        {
            if (category == gContestMoves[sContestantStatus[i].currMove].contestCategory)
                shared192D0.jam = 40;
            else
                shared192D0.jam = 10;
            shared192D0.jamQueue[0] = i;
            shared192D0.jamQueue[1] = 0xFF;
            if (WasAtLeastOneOpponentJammed())
                numJammed++;
        }
    }

    if (numJammed == 0)
        SetContestantEffectStringID2(shared192D0.contestant, CONTEST_STRING_MESSED_UP2);
}

static bool8 CanUnnerveContestant(u8 i)
{
    shared192D0.unnervedPokes[i] = 1;
    if (sContestantStatus[i].immune)
    {
        SetContestantEffectStringID(i, CONTEST_STRING_AVOID_SEEING);
        return FALSE;
    }
    else if (sContestantStatus[i].jamSafetyCount != 0)
    {
        sContestantStatus[i].jamSafetyCount--;
        SetContestantEffectStringID(i, CONTEST_STRING_AVERT_GAZE);
        return FALSE;
    }
    else if (!sContestantStatus[i].noMoreTurns && sContestantStatus[i].numTurnsSkipped == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 WasAtLeastOneOpponentJammed(void)
{
    s16 jamBuffer[4] = {0};
    int i;

    for (i = 0; shared192D0.jamQueue[i] != 0xFF; i++)
    {
        u8 contestant = shared192D0.jamQueue[i];
        if (CanUnnerveContestant(contestant))
        {
            shared192D0.jam2 = shared192D0.jam;
            if (sContestantStatus[contestant].moreEasilyStartled)
                shared192D0.jam2 *= 2;
            if (sContestantStatus[contestant].resistant)
            {
                shared192D0.jam2 = 10;
                SetContestantEffectStringID(contestant, CONTEST_STRING_LITTLE_DISTRACTED);
            }
            else
            {
                shared192D0.jam2 -= sContestantStatus[contestant].jamReduction;
                if (shared192D0.jam2 <= 0)
                {
                    shared192D0.jam2 = 0;
                    SetContestantEffectStringID(contestant, CONTEST_STRING_NOT_FAZED);
                }
                else
                {
                    JamContestant(contestant, shared192D0.jam2);
                    SetStartledString(contestant, shared192D0.jam2);
                    jamBuffer[contestant] = shared192D0.jam2;
                }
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        if (jamBuffer[i] != 0)
            return TRUE;
    }
    return FALSE;
}

static void JamContestant(u8 i, u8 jam)
{
    sContestantStatus[i].appeal2 -= jam;
    sContestantStatus[i].jam += jam;
}

static s16 RoundTowardsZero(s16 score)
{
    s16 absScore = abs(score) % 10;
    if (score < 0)
    {
        if (absScore != 0)
            score -= 10 - absScore;
    }
    else
        score -= absScore;
    return score;
}

static s16 RoundUp(s16 score)
{
    s16 absScore = abs(score) % 10;
    if (absScore != 0)
        score += 10 - absScore;
    return score;
}
