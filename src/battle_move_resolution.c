#include "global.h"
#include "battle.h"
#include "battle_arena.h"
#include "battle_environment.h"
#include "battle_hold_effects.h"
#include "battle_ai_record.h"
#include "battle_util.h"
#include "battle_move_resolution.h"
#include "battle_script_commands.h"
#include "battle_stat_change.h"
#include "battle_scripts.h"
#include "battle_z_move.h"
#include "battle_anim_scripts.h"
#include "item.h"
#include "battle_controllers.h"
#include "move.h"
#include "test_runner.h"
#include "constants/battle_move_resolution.h"
#include "constants/songs.h"

static void ValidateBattlers(void);
static enum Move GetOriginallyUsedMove(enum Move chosenMove);
static void SetSameMoveTurnValues(enum BattleMoveEffects moveEffect);
static void TryClearChargeVolatile(enum Type moveType);
static inline bool32 IsBattlerUsingBeakBlast(enum BattlerId battler);
static void RequestNonVolatileChange(enum BattlerId battlerAtk);
static bool32 CanBattlerBounceBackMove(struct BattleCalcValues *cv);
static bool32 TryMagicBounce(struct BattleCalcValues *cv);
static bool32 TryMagicCoat(struct BattleCalcValues *cv);
static bool32 TryActivatePowderStatus(enum Move move);
static void CalculateMagnitudeDamage(void);
static void UpdateStallMons(struct BattleCalcValues *cv);

// Submoves
static enum Move GetMirrorMoveMove(void);
static enum Move GetMetronomeMove(void);
static enum Move GetAssistMove(void);
static enum Move GetSleepTalkMove(void);
static enum Move GetCopycatMove(void);
static enum Move GetMeFirstMove(void);

// Stat change moves
static bool32 TryBellyDrum(enum BattlerId battler);
static bool32 TryHalfHp(enum BattlerId battler);
static bool32 CutThirdOfHp(enum BattlerId battler);

// ==============
// Attackcanceler
// ==============

static enum CancelerResult CancelerClearFlags(struct BattleCalcValues *cv)
{
    gBattleMons[cv->battlerAtk].volatiles.grudge = FALSE;
    gBattleMons[cv->battlerAtk].volatiles.glaiveRush = FALSE;
    gBattleStruct->eventState.atkCancelerBattler = 0;
    gBattleStruct->eventState.moveEndBlock = 0;
    return CANCELER_RESULT_SUCCESS;
}

static bool32 TryFormChangeBeforeMove(void)
{
    enum Ability ability = GetBattlerAbility(gBattlerAttacker);

    if (TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_BEFORE_MOVE, ability)
        || TryBattleFormChange(gBattlerAttacker, FORM_CHANGE_BATTLE_BEFORE_MOVE_CATEGORY, ability))
    {
        gBattleScripting.battler = gBattlerAttacker;
        BattleScriptCall(BattleScript_BattlerFormChange);
        return TRUE;
    }
    return FALSE;
}

static enum CancelerResult CancelerStanceChangeOne(struct BattleCalcValues *cv)
{
    if (B_STANCE_CHANGE_FAIL < GEN_7 && gChosenMove == cv->move && TryFormChangeBeforeMove())
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerSkyDrop(struct BattleCalcValues *cv)
{
    // If Pokemon is being held in Sky Drop
    if (gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable == STATE_SKY_DROP_TARGET)
    {
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerRecharge(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.rechargeTimer > 0)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedMustRecharge;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerChillyReception(struct BattleCalcValues *cv)
{
    if (cv->moveEffect == EFFECT_WEATHER_AND_SWITCH)
    {
        BattleScriptCall(BattleScript_ChillyReceptionMessage);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static void DefrostBattler(enum BattlerId battler, u32 status)
{
    GetBattlerPartyState(battler)->freezeTurns = 0;
    gBattleScripting.battler = battler;
    gBattleMons[battler].status1 &= ~status;
    RequestNonVolatileChange(battler);
}

static enum CancelerResult CancelerAsleepOrFrozen(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;

    if (gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP)
    {
        if (GetConfig(B_UPROAR) < GEN_5 && UproarWakeUpCheck(cv->battlerAtk))
        {
            TryDeactivateSleepClause(cv->battlerAtk, gBattlerPartyIndexes[cv->battlerAtk]);
            gBattleMons[cv->battlerAtk].status1 &= ~STATUS1_SLEEP;
            gBattleMons[cv->battlerAtk].volatiles.nightmare = FALSE;
            gEffectBattler = cv->battlerAtk;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP_UPROAR;
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
            BattleScriptCall(BattleScript_MoveUsedWokeUp);
        }
        else
        {
            u32 toSub;
            if (IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_EARLY_BIRD))
                toSub = 2;
            else
                toSub = 1;

            if ((gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP) < toSub)
                gBattleMons[cv->battlerAtk].status1 &= ~STATUS1_SLEEP;
            else
                gBattleMons[cv->battlerAtk].status1 -= toSub;

            if (gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP)
            {
                if (cv->moveEffect == EFFECT_SNORE)
                {
                    BattleScriptCall(BattleScript_BeforeSnoreMessage);
                    result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                }
                else if (cv->moveEffect == EFFECT_SLEEP_TALK)
                {
                    result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                }
                else
                {
                    gBattlescriptCurrInstr = BattleScript_MoveUsedIsAsleep;
                    result = CANCELER_RESULT_FAILURE;
                }
            }
            else
            {
                TryDeactivateSleepClause(cv->battlerAtk, gBattlerPartyIndexes[cv->battlerAtk]);
                gBattleMons[cv->battlerAtk].volatiles.nightmare = FALSE;
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_WOKE_UP;
                result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                BattleScriptCall(BattleScript_MoveUsedWokeUp);
            }
        }
        RequestNonVolatileChange(cv->battlerAtk);
    }
    else if (gBattleMons[cv->battlerAtk].status1 & STATUS1_FREEZE && !MoveThawsUser(cv->move))
    {
        if (!RandomPercentage(RNG_FROZEN, (GetConfig(B_FREEZE_TURNS) >= GEN_CHAMPIONS ? 25 : 20)) && GetBattlerPartyState(cv->battlerAtk)->freezeTurns < 2)
        {
            result = CANCELER_RESULT_FAILURE;
            if (GetConfig(B_FREEZE_TURNS) >= GEN_CHAMPIONS)
                GetBattlerPartyState(cv->battlerAtk)->freezeTurns++;
            gBattlescriptCurrInstr = BattleScript_MoveUsedIsFrozen;
        }
        else // unfreeze
        {
            DefrostBattler(cv->battlerAtk, STATUS1_FREEZE);
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
            BattleScriptCall(BattleScript_BattlerDefrosted);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
        }
    }

    return result;
}

static enum CancelerResult CancelerObedience(struct BattleCalcValues *cv)
{
    if (!gBattleMons[cv->battlerAtk].volatiles.multipleTurns)
    {
        enum Obedience obedienceResult = GetAttackerObedienceForAction();
        switch (obedienceResult)
        {
        case OBEYS:
            return CANCELER_RESULT_SUCCESS;
        case DISOBEYS_LOAFS:
            // Randomly select, then print a disobedient string
            // B_MSG_LOAFING, B_MSG_WONT_OBEY, B_MSG_TURNED_AWAY, or B_MSG_PRETEND_NOT_NOTICE
            gBattleCommunication[MULTISTRING_CHOOSER] = MOD(Random(), NUM_LOAF_STRINGS);
            gBattlescriptCurrInstr = BattleScript_MoveUsedLoafingAround;
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            return CANCELER_RESULT_FAILURE;
        case DISOBEYS_HITS_SELF:
            gBattlerTarget = cv->battlerAtk;
            struct DamageContext dmgCtx = {0};
            dmgCtx.battlerAtk = dmgCtx.battlerDef = cv->battlerAtk;
            dmgCtx.move = dmgCtx.chosenMove = MOVE_NONE;
            dmgCtx.baseMove = gBattleStruct->baseMove;
            dmgCtx.moveType = TYPE_MYSTERY;
            dmgCtx.isCrit = FALSE;
            dmgCtx.randomFactor = FALSE;
            dmgCtx.updateFlags = TRUE;
            dmgCtx.isSelfInflicted = TRUE;
            dmgCtx.fixedBasePower = 40;
            gBattleStruct->moveDamage[cv->battlerAtk] = CalculateMoveDamage(&dmgCtx);
            gBattlescriptCurrInstr = BattleScript_IgnoresAndHitsItself;
            return CANCELER_RESULT_FAILURE; // Move doesn't fail but mon hits itself
        case DISOBEYS_FALL_ASLEEP:
            if (IsSleepClauseEnabled())
                gBattleStruct->battlerState[cv->battlerAtk].sleepClauseEffectExempt = TRUE;
            gBattlescriptCurrInstr = BattleScript_IgnoresAndFallsAsleep;
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            return CANCELER_RESULT_FAILURE;
            break;
        case DISOBEYS_WHILE_ASLEEP:
            gBattlescriptCurrInstr = BattleScript_IgnoresWhileAsleep;
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
            return CANCELER_RESULT_FAILURE;
        case DISOBEYS_RANDOM_MOVE:
            gCurrentMove = gCalledMove = gBattleMons[cv->battlerAtk].moves[gCurrMovePos];
            gBattlescriptCurrInstr = GetMoveBattleScript(gCalledMove);
            BattleScriptCall(BattleScript_IgnoresAndUsesRandomMove);
            gBattlerTarget = GetBattleMoveTarget(gCalledMove, TARGET_NONE);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerPowerPoints(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].pp[gCurrMovePos] == 0
     && cv->move != MOVE_STRUGGLE
     && !gSpecialStatuses[cv->battlerAtk].dancerUsedMove
     && !gBattleMons[cv->battlerAtk].volatiles.multipleTurns)
    {
        gBattlescriptCurrInstr = BattleScript_NoPPForMove;
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerTruant(struct BattleCalcValues *cv)
{
    if (GetBattlerAbility(cv->battlerAtk) == ABILITY_TRUANT && gBattleMons[cv->battlerAtk].volatiles.truantCounter)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_LOAFING;
        gBattlerAbility = cv->battlerAtk;
        gBattlescriptCurrInstr = BattleScript_TruantLoafingAround;
        gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerFocus(struct BattleCalcValues *cv)
{
    u32 focusPunchFailureConfig = GetConfig(B_FOCUS_PUNCH_FAILURE);

    // In Gens 3-4, only check if is using Focus Punch.
    // In Gens 5-6, only check if the chosen move is Focus Punch.
    // In Gens 7+, check if chose and is using Focus Punch.
    if ((gProtectStructs[cv->battlerAtk].physicalDmg || gProtectStructs[cv->battlerAtk].specialDmg)
     && (focusPunchFailureConfig < GEN_5 || GetMoveEffect(gChosenMoveByBattler[cv->battlerAtk]) == EFFECT_FOCUS_PUNCH)
     && (focusPunchFailureConfig == GEN_5 || focusPunchFailureConfig == GEN_6 || cv->moveEffect == EFFECT_FOCUS_PUNCH)
     && !gProtectStructs[cv->battlerAtk].survivedOHKO)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_FocusPunchLostFocus;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerFocusGen5(struct BattleCalcValues *cv)
{
    if (GetConfig(B_FOCUS_PUNCH_FAILURE) >= GEN_5)
        return CancelerFocus(cv);
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerFlinch(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.flinched)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        if (cv->abilities[cv->battlerAtk] == ABILITY_STEADFAST)
        {
            SetStatChange(cv->battlerAtk, STAT_SPEED, 1);
            gBattlerAbility = cv->battlerAtk;
            gBattlescriptCurrInstr = BattleScript_MoveUsedFlinchedAndSteadfast;
        }
        else
        {
            gBattlescriptCurrInstr = BattleScript_MoveUsedFlinched;
        }
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerDisabled(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
     && gBattleMons[cv->battlerAtk].volatiles.disabledMove == cv->move
     && gBattleMons[cv->battlerAtk].volatiles.disabledMove != MOVE_NONE)
    {
        gBattleScripting.battler = cv->battlerAtk;
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsDisabled;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerVolatileBlocked(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
     && IsHealBlockPreventingMove(cv->battlerAtk, cv->move))
    {
        gBattleScripting.battler = cv->battlerAtk;
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedHealBlockPrevents;
        result = CANCELER_RESULT_FAILURE;
    }
    else if (IsGravityPreventingMove(GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE ? gBattleStruct->baseMove : cv->move))
    {
        gBattleScripting.battler = cv->battlerAtk;
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedGravityPrevents;
        result = CANCELER_RESULT_FAILURE;
    }
    else if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE && gBattleMons[cv->battlerAtk].volatiles.throatChopTimer > 0 && IsSoundMove(cv->move))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsThroatChopPrevented;
        result = CANCELER_RESULT_FAILURE;
    }

    if (gBattleStruct->snatchedMoveIsUsed)
        gBattleStruct->eventState.atkCanceler = CANCELER_SET_TARGETS - 1; // minus one since state is incremented on success by default

    return result;
}

static enum CancelerResult CancelerTaunted(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
     && gBattleMons[cv->battlerAtk].volatiles.tauntTimer
     && IsBattleMoveStatus(cv->move)
     && (GetConfig(B_TAUNT_ME_FIRST) < GEN_5 || cv->moveEffect != EFFECT_ME_FIRST))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsTaunted;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerImprisoned(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE && GetImprisonedMovesCount(cv->battlerAtk, cv->move))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsImprisoned;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerConfused(struct BattleCalcValues *cv)
{
    struct Volatiles *vol = &gBattleMons[cv->battlerAtk].volatiles;

    if (vol->confusionTimer)
    {
        if (vol->confusionTimer != PERMANENT_VOLATILE)
            vol->confusionTimer--;

        if (vol->confusionTimer)
        {
             // confusion dmg
            if (RandomPercentage(RNG_CONFUSION, (GetConfig(B_CONFUSION_SELF_DMG_CHANCE) >= GEN_7 ? 33 : 50)))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = TRUE;
                gBattlerTarget = gBattlerAttacker;
                struct DamageContext dmgCtx = {0};
                dmgCtx.battlerAtk = dmgCtx.battlerDef = cv->battlerAtk;
                dmgCtx.move = dmgCtx.chosenMove = dmgCtx.baseMove = MOVE_NONE;
                dmgCtx.moveType = TYPE_MYSTERY;
                dmgCtx.isCrit = FALSE;
                dmgCtx.randomFactor = FALSE;
                dmgCtx.updateFlags = TRUE;
                dmgCtx.isSelfInflicted = TRUE;
                dmgCtx.fixedBasePower = 40;
                dmgCtx.abilities[gBattlerAttacker] = cv->abilities[gBattlerAttacker];
                dmgCtx.holdEffects[gBattlerAttacker] = cv->holdEffects[gBattlerAttacker];
                gBattleStruct->passiveHpUpdate[cv->battlerAtk] = CalculateMoveDamage(&dmgCtx);
                gBattlescriptCurrInstr = BattleScript_MoveUsedIsConfused;
                return CANCELER_RESULT_FAILURE;
            }
            else
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = FALSE;
                BattleScriptCall(BattleScript_MoveUsedIsConfused);
                return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
            }
        }
        else // snapped out of confusion
        {
            BattleScriptCall(BattleScript_MoveUsedIsConfusedNoMore);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerGhost(struct BattleCalcValues *cv) // GHOST in Pokémon Tower
{
    if (IsGhostBattleWithoutScope())
    {
        if (GetBattlerSide(cv->battlerAtk) == B_SIDE_PLAYER)
            gBattlescriptCurrInstr = BattleScript_TooScaredToMove;
        else
            gBattlescriptCurrInstr = BattleScript_GhostGetOutGetOut;
        gBattleCommunication[MULTISTRING_CHOOSER] = 0;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerParalyzed(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].status1 & STATUS1_PARALYSIS
        && !(B_MAGIC_GUARD == GEN_4 && IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
        && (RandomWeighted(RNG_PARALYSIS, (GetConfig(B_PARALYSIS_CHANCE) >= GEN_CHAMPIONS ? 7 : 3), 1)))
    {
        CancelMultiTurnMoves(gBattlerAttacker);
        gBattlescriptCurrInstr = BattleScript_MoveUsedIsParalyzed;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerInfatuation(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.infatuation)
    {
        gBattleScripting.battler = gBattleMons[cv->battlerAtk].volatiles.infatuation - 1;
        if (!RandomPercentage(RNG_INFATUATION, 50))
        {
            BattleScriptCall(BattleScript_MoveUsedIsInLove);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        else
        {
            BattleScriptPush(BattleScript_MoveUsedIsInLoveCantAttack);
            CancelMultiTurnMoves(cv->battlerAtk);
            gBattlescriptCurrInstr = BattleScript_MoveUsedIsInLove;
            return CANCELER_RESULT_FAILURE;
        }
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerZMoves(struct BattleCalcValues *cv)
{
    if (GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE)
    {
        // attacker has a queued z move
        RecordItemEffectBattle(cv->battlerAtk, HOLD_EFFECT_Z_CRYSTAL);
        SetGimmickAsActivated(cv->battlerAtk, GIMMICK_Z_MOVE);

        gBattleScripting.battler = cv->battlerAtk;
        if (IsBattleMoveStatus(cv->move))
            BattleScriptCall(BattleScript_ZMoveActivateStatus);
        else
            BattleScriptCall(BattleScript_ZMoveActivateDamaging);

        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerChoiceLock(struct BattleCalcValues *cv)
{
    enum Move *choicedMoveAtk = &gBattleStruct->choicedMove[cv->battlerAtk];
    enum HoldEffect holdEffect = GetBattlerHoldEffect(cv->battlerAtk);

    if (gChosenMove != MOVE_STRUGGLE
     && (*choicedMoveAtk == MOVE_NONE || *choicedMoveAtk == MOVE_UNAVAILABLE)
     && (IsHoldEffectChoice(holdEffect) || cv->abilities[cv->battlerAtk] == ABILITY_GORILLA_TACTICS))
        *choicedMoveAtk = gChosenMove;

    u32 moveIndex;
    for (moveIndex = 0; moveIndex < MAX_MON_MOVES; moveIndex++)
    {
        if (gBattleMons[cv->battlerAtk].moves[moveIndex] == *choicedMoveAtk)
            break;
    }

    if (moveIndex == MAX_MON_MOVES)
        *choicedMoveAtk = MOVE_NONE;

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerCallSubmove(struct BattleCalcValues *cv)
{
    bool32 noEffect = FALSE;
    enum Move calledMove = MOVE_NONE;
    const u8 *battleScript = NULL;
    battleScript = BattleScript_SubmoveAttackstring;

    switch (cv->moveEffect)
    {
    case EFFECT_MIRROR_MOVE:
        calledMove = GetMirrorMoveMove();
        break;
    case EFFECT_METRONOME:
        calledMove = GetMetronomeMove();
        battleScript = BattleScript_MetronomeAttackstring;
        break;
    case EFFECT_ASSIST:
        calledMove = GetAssistMove();
        break;
    case EFFECT_NATURE_POWER:
        calledMove = GetNaturePowerMove();
        battleScript = BattleScript_NaturePowerAttackstring;
        break;
    case EFFECT_SLEEP_TALK:
        calledMove = GetSleepTalkMove();
        battleScript = BattleScript_SleepTalkAttackstring;
        break;
    case EFFECT_COPYCAT:
        calledMove = GetCopycatMove();
        break;
    case EFFECT_ME_FIRST:
        calledMove = GetMeFirstMove();
        break;
    default:
        noEffect = TRUE;
        break;
    }

    if (noEffect)
    {
        gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
        return CANCELER_RESULT_SUCCESS;
    }

    if (calledMove != MOVE_NONE)
    {
        if (GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE && !IsBattleMoveStatus(calledMove))
            calledMove = GetTypeBasedZMove(calledMove);
        if (cv->moveEffect == EFFECT_COPYCAT && IsMaxMove(calledMove))
            calledMove = gBattleStruct->dynamax.lastUsedBaseMove;

        gBattleStruct->submoveAnnouncement = SUBMOVE_SUCCESS;
        gCalledMove = calledMove;
        if (GetBattlerMoveTargetType(cv->battlerAtk, cv->move) == TARGET_DEPENDS) // originally using a move without a set target
            gBattlerTarget = GetBattleMoveTarget(calledMove, TARGET_NONE);
        BattleScriptCall(battleScript);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }

    gBattleStruct->submoveAnnouncement = SUBMOVE_FAILURE;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerThaw(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;

    if (MoveThawsUser(cv->move))
    {
        if (gBattleMons[cv->battlerAtk].status1 & STATUS1_FREEZE)
        {
            if (!IsMoveEffectRemoveSpeciesType(cv->move, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) || IS_BATTLER_OF_TYPE(cv->battlerAtk, TYPE_FIRE))
            {
                DefrostBattler(cv->battlerAtk, STATUS1_FREEZE);
                result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                BattleScriptCall(BattleScript_BattlerDefrosted);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED_BY_MOVE;
            }
            else
            {
                result = CANCELER_RESULT_FAILURE;
            }
        }
        else if (gBattleMons[cv->battlerAtk].status1 & STATUS1_FROSTBITE)
        {
            if (!IsMoveEffectRemoveSpeciesType(cv->move, MOVE_EFFECT_REMOVE_ARG_TYPE, TYPE_FIRE) || IS_BATTLER_OF_TYPE(cv->battlerAtk, TYPE_FIRE))
            {
                DefrostBattler(cv->battlerAtk, STATUS1_FROSTBITE);
                result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
                BattleScriptCall(BattleScript_BattlerFrostbiteHealed);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FROSTBITE_HEALED_BY_MOVE;
            }
            else
            {
                result = CANCELER_RESULT_FAILURE;
            }
        }
    }
    return result;
}

static enum CancelerResult CancelerStanceChangeTwo(struct BattleCalcValues *cv)
{
    if (B_STANCE_CHANGE_FAIL >= GEN_7 && gChosenMove == cv->move && TryFormChangeBeforeMove())
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerAttackstring(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.bideTurns)
        return CANCELER_RESULT_SUCCESS;

    BattleScriptCall(BattleScript_Attackstring);
    if (!gSpecialStatuses[gBattlerAttacker].dancerUsedMove)
    {
        gBattleMons[gBattlerAttacker].volatiles.usedMoves |= 1u << gCurrMovePos;
        gBattleStruct->battlerState[gBattlerAttacker].lastMoveTarget = gBattlerTarget;
        gLastPrintedMoves[gBattlerAttacker] = gChosenMove;
        RecordKnownMove(gBattlerAttacker, gChosenMove);
    }
    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

static enum CancelerResult CancelerPledgeAttack(struct BattleCalcValues *cv)
{
    if (gBattleStruct->pledgeState == PLEDGE_COMBO_WAITING)
    {
        enum Move partnerMove = GetBattlerChosenMove(GetPartnerBattler(cv->battlerAtk));

        if (GetPledgeComboMove(cv->move) == partnerMove)
            gCurrentMove = GetPledgeResultMove(cv->move);
        else
            gCurrentMove = GetPledgeResultMove(partnerMove);

        gBattleStruct->pledgeState = PLEDGE_COMBO_ATTACK;
        gBattlescriptCurrInstr = GetMoveBattleScript(gCurrentMove);
        BattleScriptCall(BattleScript_EffectHitCombinedPledge);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }

    return CANCELER_RESULT_SUCCESS;
}

#define checkFailure TRUE
#define skipFailure FALSE
static bool32 IsSingleTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef != gBattlerTarget)
        return skipFailure;
    return checkFailure;
}

static bool32 IsSmartTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (!IsBattlerAlly(gBattlerTarget, battlerDef) || battlerAtk == battlerDef)
        return skipFailure;
    return checkFailure;
}

static bool32 IsTargetingBothFoes(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef == GetPartnerBattler(battlerAtk) || battlerAtk == battlerDef)
    {
        gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_DOESNT_AFFECT_FOE;
        return skipFailure;
    }
    return checkFailure;
}

static bool32 IsTargetingSelf(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return skipFailure;
}

static bool32 IsTargetingAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef != GetPartnerBattler(battlerAtk))
    {
        gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_DOESNT_AFFECT_FOE;
        return skipFailure;
    }
    return checkFailure;
}

static bool32 IsTargetingSelfAndAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef != GetPartnerBattler(battlerAtk))
    {
        if (battlerDef != battlerAtk) // Don't set result flags for user
            gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_DOESNT_AFFECT_FOE;
        return skipFailure;
    }
    return checkFailure;
}

static bool32 IsTargetingSelfOrAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerDef == battlerAtk)
        return skipFailure;

    if (battlerDef == gBattlerTarget)
        return checkFailure;

    gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_DOESNT_AFFECT_FOE;
    return skipFailure;
}

static bool32 IsTargetingFoesAndAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (battlerAtk == battlerDef)
        return skipFailure;  // Don't set result flags for user
    return checkFailure;
}

static bool32 IsTargetingField(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return skipFailure;
}

static bool32 IsTargetingOpponentsField(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (IsBattlerAlly(battlerDef, GetOppositeBattler(battlerAtk)))
        return checkFailure;
    return skipFailure;
}

static bool32 IsTargetingAllBattlers(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    return checkFailure;
}

// ShouldCheckFailureOnTarget
static bool32 (*const sShouldCheckTargetMoveFailure[])(enum BattlerId battlerAtk, enum BattlerId battlerDef) =
{
    [TARGET_NONE] = IsTargetingField,
    [TARGET_SELECTED] = IsSingleTarget,
    [TARGET_DEPENDS] = IsSingleTarget,
    [TARGET_OPPONENT] = IsSingleTarget,
    [TARGET_RANDOM] = IsSingleTarget,
    [TARGET_BOTH] = IsTargetingBothFoes,
    [TARGET_USER] = IsTargetingSelf,
    [TARGET_SMART] = IsSmartTarget,
    [TARGET_ALLY] = IsTargetingAlly,
    [TARGET_USER_AND_ALLY] = IsTargetingSelfAndAlly,
    [TARGET_USER_OR_ALLY] = IsTargetingSelfOrAlly,
    [TARGET_FOES_AND_ALLY] = IsTargetingFoesAndAlly,
    [TARGET_FIELD] = IsTargetingField,
    [TARGET_OPPONENTS_FIELD] = IsTargetingOpponentsField,
    [TARGET_ALL_BATTLERS] = IsTargetingAllBattlers,
};

static bool32 ShouldCheckTargetMoveFailure(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum Move move, enum MoveTarget moveTarget)
{
    // For Bounced moves
    if (IsBattlerUnaffectedByMove(battlerDef))
        return skipFailure;

    if ((moveTarget != TARGET_FIELD && moveTarget != TARGET_OPPONENTS_FIELD) && !IsBattlerAlive(battlerDef))
        return skipFailure;

    return sShouldCheckTargetMoveFailure[moveTarget](battlerAtk, battlerDef);
}
#undef checkFailure
#undef skipFailure

static inline bool32 IsSmartTargetMoveConsecutiveHit(enum BattlerId battlerAtk, enum Move move)
{
    if (GetBattlerMoveTargetType(battlerAtk, move) != TARGET_SMART)
        return FALSE;

    if (gMultiHitCounter < GetMoveStrikeCount(move))
        return TRUE;

    return FALSE;
}

bool32 IsAffectedByFollowMe(enum BattlerId battlerAtk, enum BattleSide defSide, enum Move move)
{
    enum Ability ability = GetBattlerAbility(battlerAtk);
    enum BattleMoveEffects effect = GetMoveEffect(move);


    if (gSideTimers[defSide].followmeTimer == 0
        || (!IsBattlerAlive(gSideTimers[defSide].followmeTarget) && !IsSmartTargetMoveConsecutiveHit(battlerAtk, move))
        || effect == EFFECT_SNIPE_SHOT
        || effect == EFFECT_SKY_DROP
        || IsAbilityAndRecord(battlerAtk, ability, ABILITY_PROPELLER_TAIL)
        || IsAbilityAndRecord(battlerAtk, ability, ABILITY_STALWART))
        return FALSE;

    if (effect == EFFECT_PURSUIT && IsPursuitTargetSet())
        return FALSE;

    if (gSideTimers[defSide].followmePowder && !IsAffectedByPowderMove(battlerAtk, ability, GetBattlerHoldEffect(battlerAtk)))
        return FALSE;

    return TRUE;
}

static bool32 HandleMoveTargetRedirection(struct BattleCalcValues *cv, enum MoveTarget moveTarget)
{
    u32 redirectorOrderNum = MAX_BATTLERS_COUNT;
    enum BattleSide side = (GetBattlerSide(cv->battlerAtk) ^ BIT_SIDE);

    if (cv->moveEffect == EFFECT_REFLECT_DAMAGE)
    {
        enum DamageCategory reflectCategory = GetReflectDamageMoveDamageCategory(cv->battlerAtk, cv->move);

        if (reflectCategory == DAMAGE_CATEGORY_PHYSICAL)
            cv->battlerDef = gBattleStruct->moveTarget[cv->battlerAtk] = gProtectStructs[cv->battlerAtk].physicalBattlerId;
        else
            cv->battlerDef = gBattleStruct->moveTarget[cv->battlerAtk] = gProtectStructs[cv->battlerAtk].specialBattlerId;
    }

    if (IsAffectedByFollowMe(cv->battlerAtk, side, cv->move)
     && (moveTarget == TARGET_SELECTED || moveTarget == TARGET_SMART || cv->moveEffect == EFFECT_REFLECT_DAMAGE)
     && !IsBattlerAlly(cv->battlerAtk, gSideTimers[side].followmeTarget))
    {
        gBattleStruct->moveTarget[cv->battlerAtk] = cv->battlerDef = gSideTimers[side].followmeTarget; // follow me moxie fix
        return TRUE;
    }

    enum Type moveType = GetBattleMoveType(cv->move);
    enum Ability ability = cv->abilities[cv->battlerDef];
    bool32 currTargetCantAbsorb = ((ability != ABILITY_LIGHTNING_ROD && moveType == TYPE_ELECTRIC)
                                || (ability != ABILITY_STORM_DRAIN && moveType == TYPE_WATER));

    if (currTargetCantAbsorb
     && IsDoubleBattle()
     && gSideTimers[side].followmeTimer == 0
     && moveTarget != TARGET_USER
     && moveTarget != TARGET_ALL_BATTLERS
     && moveTarget != TARGET_FIELD
     && cv->moveEffect != EFFECT_TEATIME
     && cv->moveEffect != EFFECT_SNIPE_SHOT
     && cv->moveEffect != EFFECT_PLEDGE)
    {
        // Find first battler that redirects the move (in turn order)
        enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
        enum BattlerId battler;
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            ability = cv->abilities[battler];
            if ((B_REDIRECT_ABILITY_ALLIES >= GEN_4 || !IsBattlerAlly(cv->battlerAtk, battler))
                && battler != cv->battlerAtk
                && battler != cv->battlerDef
                && ((ability == ABILITY_LIGHTNING_ROD && moveType == TYPE_ELECTRIC)
                 || (ability == ABILITY_STORM_DRAIN && moveType == TYPE_WATER))
                && GetBattlerTurnOrderNum(battler) < redirectorOrderNum
                && !IsAbilityAndRecord(cv->battlerAtk, abilityAtk, ABILITY_PROPELLER_TAIL)
                && !IsAbilityAndRecord(cv->battlerAtk, abilityAtk, ABILITY_STALWART))
            {
                redirectorOrderNum = GetBattlerTurnOrderNum(battler);
            }
        }
        if (redirectorOrderNum != MAX_BATTLERS_COUNT)
        {
            cv->battlerDef = gBattlerByTurnOrder[redirectorOrderNum];
            RecordAbilityBattle(cv->battlerDef, cv->abilities[cv->battlerDef]);
            gSpecialStatuses[cv->battlerDef].abilityRedirected = TRUE;
            return TRUE;
        }
    }

    return FALSE;
}

static bool32 WasOriginalTargetAlly(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum MoveTarget moveTarget)
{
    if (!gProtectStructs[GetPartnerBattler(battlerAtk)].usedAllySwitch)
        return FALSE;

    if ((moveTarget == TARGET_ALLY || moveTarget == TARGET_USER_OR_ALLY) && battlerAtk == battlerDef)
        return TRUE;

    return FALSE;
}

static enum CancelerResult CancelerSetTargets(struct BattleCalcValues *cv)
{
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
    bool32 isDoubleBattle = IsDoubleBattle();

    if (!HandleMoveTargetRedirection(cv, moveTarget))
    {
        if (isDoubleBattle && moveTarget == TARGET_RANDOM)
        {
            cv->battlerDef = SetRandomTarget(cv->battlerAtk);
            if (!IsBattlerAlive(cv->battlerAtk) && !IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
            {
                cv->battlerDef = GetPartnerBattler(cv->battlerDef);
            }
        }
        else if (moveTarget == TARGET_SELECTED && cv->battlerDef == cv->battlerAtk)
        {
            cv->battlerDef = SetRandomTarget(cv->battlerAtk);
        }
        else if (moveTarget == TARGET_ALLY && !IsBattlerAlly(cv->battlerDef, cv->battlerAtk))
        {
            cv->battlerDef = GetPartnerBattler(cv->battlerAtk);
        }
        else if (isDoubleBattle && moveTarget == TARGET_FOES_AND_ALLY)
        {
            for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
            {
                if (battlerDef == cv->battlerAtk)
                    continue;

                if (IsBattlerAlive(battlerDef))
                {
                    cv->battlerDef = battlerDef;
                    break;
                }
            }
        }
        else if (moveTarget == TARGET_USER || moveTarget == TARGET_USER_AND_ALLY)
        {
            cv->battlerDef = cv->battlerAtk;
        }
        else if (isDoubleBattle && moveTarget == TARGET_USER_OR_ALLY && !IsBattlerAlive(cv->battlerDef))
        {
            cv->battlerDef = cv->battlerAtk;
        }
        else if (isDoubleBattle
              && moveTarget != TARGET_OPPONENTS_FIELD
              && !IsBattlerAlive(cv->battlerDef)
              && !IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
        {
            cv->battlerDef = GetPartnerBattler(cv->battlerDef);
        }
    }

    gBattlerTarget = cv->battlerDef; // ShouldCheckTargetMoveFailure relies on gBattlerTarget

    while (gBattleStruct->eventState.atkCancelerBattler < gBattlersCount)
    {
        enum BattlerId battlerDef = gBattleStruct->eventState.atkCancelerBattler++;

        if (!ShouldCheckTargetMoveFailure(cv->battlerAtk, battlerDef, cv->move, moveTarget))
            gBattleStruct->battlerState[cv->battlerAtk].targetsDone[battlerDef] = TRUE;
        if (moveTarget != TARGET_FIELD && moveTarget != TARGET_OPPONENTS_FIELD && !IsBattlerAlive(battlerDef))
            gBattleStruct->moveResultFlags[battlerDef] |= MOVE_RESULT_NOT_PRESENT;
    }
    gBattleStruct->eventState.atkCancelerBattler = 0;

    if (IsBattlerAlly(cv->battlerAtk, cv->battlerDef) && !IsBattlerAlive(cv->battlerDef))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (WasOriginalTargetAlly(cv->battlerAtk, cv->battlerDef, moveTarget))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }

    SetDynamicMoveCategory(cv->battlerAtk, cv->battlerDef, cv->move);
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerPPDeduction(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.multipleTurns
     || gSpecialStatuses[cv->battlerAtk].dancerUsedMove
     || gBattleStruct->bouncedMoveIsUsed
     || gBattleStruct->snatchedMoveIsUsed
     || gBattleMons[cv->battlerAtk].volatiles.bideTurns
     || cv->move == MOVE_STRUGGLE)
        return CANCELER_RESULT_SUCCESS;

    s32 ppToDeduct = 1;
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
    u32 movePosition = gCurrMovePos;

    if (gBattleStruct->submoveAnnouncement == SUBMOVE_SUCCESS)
        movePosition = gChosenMovePos;

    if (IsSpreadMove(moveTarget)
     || moveTarget == TARGET_ALL_BATTLERS
     || moveTarget == TARGET_FIELD
     || MoveForcesPressure(cv->move))
    {
        for (u32 i = 0; i < gBattlersCount; i++)
        {
            if (!IsBattlerAlly(i, cv->battlerAtk))
                ppToDeduct += (GetBattlerAbility(i) == ABILITY_PRESSURE);
        }
    }
    else if (moveTarget != TARGET_OPPONENTS_FIELD)
    {
        if (cv->battlerAtk != cv->battlerDef && GetBattlerAbility(cv->battlerDef) == ABILITY_PRESSURE)
             ppToDeduct++;
    }

    // For item Metronome, echoed voice
    if (cv->move != gLastResultingMoves[cv->battlerAtk] || gBattleStruct->unableToUseMove)
        gBattleMons[cv->battlerAtk].volatiles.metronomeItemCounter = 0;

    if (gBattleMons[cv->battlerAtk].pp[movePosition] > ppToDeduct)
        gBattleMons[cv->battlerAtk].pp[movePosition] -= ppToDeduct;
    else
        gBattleMons[cv->battlerAtk].pp[movePosition] = 0;

    gLastMoves[cv->battlerAtk] = gChosenMove;

    if (MOVE_IS_PERMANENT(cv->battlerAtk, movePosition))
    {
        BtlController_EmitSetMonData(
            cv->battlerAtk,
            B_COMM_TO_CONTROLLER,
            REQUEST_PPMOVE1_BATTLE + movePosition,
            0,
            sizeof(gBattleMons[cv->battlerAtk].pp[movePosition]),
            &gBattleMons[cv->battlerAtk].pp[movePosition]);
        MarkBattlerForControllerExec(cv->battlerAtk);
    }

    if (gBattleStruct->submoveAnnouncement != SUBMOVE_NO_EFFECT)
    {
        if (gBattleStruct->submoveAnnouncement == SUBMOVE_FAILURE)
        {
            gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
            gBattlescriptCurrInstr = BattleScript_ButItFailed;
            return CANCELER_RESULT_FAILURE;
        }
        else if (CancelerVolatileBlocked(cv) == CANCELER_RESULT_FAILURE) // Check Gravity/Heal Block/Throat Chop for Submove
        {
            gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
            return CANCELER_RESULT_FAILURE;
        }
        else
        {
            gBattleStruct->submoveAnnouncement = SUBMOVE_NO_EFFECT;
            gBattleScripting.animTurn = 0;
            gBattleScripting.animTargetsHit = 0;

            // Possibly better to just move type setting and redirection to attackcanceler as a new case at this point
            SetTypeBeforeUsingMove(cv->move, cv->battlerAtk, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk]);
            gBattlescriptCurrInstr = GetMoveBattleScript(cv->move);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
    }

    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT; // Apply power point change
}

// We don't have clear data on where this belongs to but I assume it should at least be checked before Protean
static enum CancelerResult CancelerSkyBattle(struct BattleCalcValues *cv)
{
    if (gBattleStruct->isSkyBattle && IsMoveSkyBattleBanned(gCurrentMove))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerWeatherPrimal(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    if (GetMovePower(cv->move) > 0 && HasWeatherEffect())
    {
        enum Type moveType = GetBattleMoveType(cv->move);
        if (moveType == TYPE_FIRE && gBattleWeather & B_WEATHER_RAIN_PRIMAL && (GetConfig(B_POWDER_STATUS_HEAVY_RAIN) >= GEN_7 || !TryActivatePowderStatus(cv->move)))
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN;
            result = CANCELER_RESULT_FAILURE;
        }
        else if (moveType == TYPE_WATER && gBattleWeather & B_WEATHER_SUN_PRIMAL)
        {
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN;
            result = CANCELER_RESULT_FAILURE;
        }
        if (result == CANCELER_RESULT_FAILURE)
        {
            gProtectStructs[cv->battlerAtk].chargingTurn = FALSE;
            CancelMultiTurnMoves(cv->battlerAtk);
            gBattlescriptCurrInstr = BattleScript_PrimalWeatherBlocksMove;
        }
    }

    return result;
}

static enum CancelerResult CancelerFocusPreGen5(struct BattleCalcValues *cv)
{
    if (GetConfig(B_FOCUS_PUNCH_FAILURE) < GEN_5)
        return CancelerFocus(cv);
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerBide(struct BattleCalcValues *cv)
{
    if (cv->moveEffect != EFFECT_BIDE)
        return CANCELER_RESULT_SUCCESS;

    if (gBattleMons[cv->battlerAtk].volatiles.bideTurns)
    {
        if (--gBattleMons[cv->battlerAtk].volatiles.bideTurns)
        {
            gBattlescriptCurrInstr = BattleScript_BideStoringEnergy;
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT; // Jump to moveend
        }
        else if (gBideDmg[cv->battlerAtk])
        {
            gBattlerTarget = gBideTarget[cv->battlerAtk];
            gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
            if (!IsBattlerAlive(gBattlerTarget))
                gBattlerTarget = GetBattleMoveTarget(gCurrentMove, TARGET_SELECTED);
            gBattleStruct->battlerState[cv->battlerAtk].targetsDone[gBattlerTarget] = FALSE;
            BattleScriptCall(BattleScript_BideAttack);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        else
        {
            gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
            gBattlescriptCurrInstr = BattleScript_BideNoEnergyToAttack;
            return CANCELER_RESULT_FAILURE;
        }
    }
    else
    {
        gBattleMons[gBattlerAttacker].volatiles.multipleTurns = TRUE;
        gLockedMoves[gBattlerAttacker] = gCurrentMove;
        gBideDmg[gBattlerAttacker] = 0;
        gBattleMons[gBattlerAttacker].volatiles.bideTurns = 2;
        gBattlescriptCurrInstr = BattleScript_SetUpBide;
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT; // Jump to moveend
    }

    return CANCELER_RESULT_SUCCESS;
}

static bool32 ShouldSkipFailureCheckOnBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (gBattleStruct->battlerState[battlerAtk].targetsDone[battlerDef])
        return TRUE;
    if (gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_INVALID_TARGET)
        return TRUE;
    if (GetConfig(B_CHECK_USER_FAILURE) >= GEN_5 && battlerAtk == battlerDef)
        return TRUE;
    return FALSE;
}

// Insert failure here when it doesn't depend on the target
static enum CancelerResult CancelerMoveFailure(struct BattleCalcValues *cv)
{
    const u8 *battleScript = NULL;

    switch (cv->moveEffect)
    {
    case EFFECT_FLING:
        if (!CanFling(cv->battlerAtk, cv->abilities[cv->battlerAtk]))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_FAIL_IF_NOT_ARG_TYPE:
        if (!IS_BATTLER_OF_TYPE(cv->battlerAtk, GetMoveArgType(cv->move)))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_DARK_VOID:
        if (gBattleStruct->bouncedMoveIsUsed)
            break;
        if (B_DARK_VOID_FAIL >= GEN_7 && gBattleMons[cv->battlerAtk].species != SPECIES_DARKRAI)
            battleScript = BattleScript_PokemonCantUseTheMove;
        break;
    case EFFECT_AURA_WHEEL:
        if (gBattleMons[cv->battlerAtk].species != SPECIES_MORPEKO_FULL_BELLY
         && gBattleMons[cv->battlerAtk].species != SPECIES_MORPEKO_HANGRY)
            battleScript = BattleScript_PokemonCantUseTheMove;
        break;
    case EFFECT_HYPERSPACE_FURY:
        if (gBattleMons[cv->battlerAtk].species == SPECIES_HOOPA_CONFINED)
            battleScript = BattleScript_ButHoopaCantUseIt;
        else if (gBattleMons[cv->battlerAtk].species != SPECIES_HOOPA_UNBOUND)
            battleScript = BattleScript_PokemonCantUseTheMove;
        break;
    case EFFECT_AURORA_VEIL:
        if (!(GetWeather() & B_WEATHER_ICY_ANY))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_CLANGOROUS_SOUL:
        if (gBattleMons[cv->battlerAtk].hp <= max(1, GetNonDynamaxMaxHP(cv->battlerAtk) / 3))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_REFLECT_DAMAGE:
    {
        enum DamageCategory reflectCategory = GetReflectDamageMoveDamageCategory(cv->battlerAtk, cv->move);
        if (IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
            battleScript = BattleScript_ButItFailed;
        // Counter / Metal Burst and took physical damage
        else if (reflectCategory == DAMAGE_CATEGORY_PHYSICAL
              && gProtectStructs[cv->battlerAtk].physicalDmg > 0
              && (GetConfig(B_COUNTER_TRY_HIT_PARTNER) >= GEN_5 || gBattleMons[gProtectStructs[cv->battlerAtk].physicalBattlerId].hp))
            break;
        // Mirror Coat / Metal Burst and took special damage
        else if (reflectCategory == DAMAGE_CATEGORY_SPECIAL
              && gProtectStructs[cv->battlerAtk].specialDmg > 0
              && (GetConfig(B_COUNTER_TRY_HIT_PARTNER) >= GEN_5 || gBattleMons[gProtectStructs[cv->battlerAtk].specialBattlerId].hp))
            break;
        else
            battleScript = BattleScript_ButItFailed;
        break;
    }
    case EFFECT_DESTINY_BOND:
        if (DoesDestinyBondFail(cv->battlerAtk))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_FIRST_TURN_ONLY:
        if (!IsBattlersFirstTurn(cv->battlerAtk) || gSpecialStatuses[cv->battlerAtk].backUpTarget)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_MAT_BLOCK:
        if (!IsBattlersFirstTurn(cv->battlerAtk) || gSpecialStatuses[cv->battlerAtk].backUpTarget)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_FOLLOW_ME:
        if (B_UPDATED_MOVE_DATA >= GEN_8 && !(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_LAST_RESORT:
        if (!CanUseLastResort(cv->battlerAtk))
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_NO_RETREAT:
        if (gBattleMons[cv->battlerAtk].volatiles.noRetreat)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_PROTECT:
    case EFFECT_ENDURE:
        TryResetConsecutiveUseCounter(cv->battlerAtk);
        if (IsLastMonToMove(cv->battlerAtk))
        {
            battleScript = BattleScript_ButItFailed;
        }
        else
        {
            enum ProtectMethod protectMethod = GetMoveProtectMethod(cv->move);
            bool32 canUseProtectSecondTime = CanUseMoveConsecutively(cv->battlerAtk);
            bool32 canUseWideGuard = (GetConfig(B_WIDE_GUARD) >= GEN_6 && protectMethod == PROTECT_WIDE_GUARD);
            bool32 canUseQuickGuard = (GetConfig(B_QUICK_GUARD) >= GEN_6 && protectMethod == PROTECT_QUICK_GUARD);

            if (!canUseProtectSecondTime
             && !canUseWideGuard
             && !canUseQuickGuard
             && protectMethod != PROTECT_CRAFTY_SHIELD)
                battleScript = BattleScript_ButItFailed;
        }
        if (battleScript != NULL)
        {
            gBattleMons[cv->battlerAtk].volatiles.consecutiveMoveUses = 0;
            gBattleStruct->battlerState[cv->battlerAtk].stompingTantrumTimer = 2;
        }
        break;
    case EFFECT_REST:
        if (IsAsleepOrComatose(cv->battlerDef, cv->abilities[cv->battlerDef]))
            battleScript = BattleScript_RestIsAlreadyAsleep;
        else if (gBattleMons[cv->battlerAtk].hp == gBattleMons[cv->battlerAtk].maxHP)
            battleScript = BattleScript_AlreadyAtFullHp;
        else if (cv->abilities[cv->battlerAtk] == ABILITY_INSOMNIA
              || cv->abilities[cv->battlerAtk] == ABILITY_VITAL_SPIRIT
              || cv->abilities[cv->battlerAtk] == ABILITY_PURIFYING_SALT)
            battleScript = BattleScript_InsomniaProtects;
        break;
    case EFFECT_SNORE:
        if (!(gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP)
         && cv->abilities[cv->battlerAtk] != ABILITY_COMATOSE)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_STEEL_ROLLER:
        if (gFieldTimers.terrain == B_TERRAIN_NONE)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_STOCKPILE:
        if (gBattleMons[cv->battlerAtk].volatiles.stockpileCounter >= 3)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_STUFF_CHEEKS:
        if (GetItemPocket(gBattleMons[cv->battlerAtk].item) != POCKET_BERRIES)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_SWALLOW:
    case EFFECT_SPIT_UP:
        if (gBattleMons[cv->battlerAtk].volatiles.stockpileCounter == 0 && !gBattleStruct->snatchedMoveIsUsed)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_TELEPORT:
        // TODO: follow up: Can't make sense of teleport logic
        break;
    case EFFECT_NATURAL_GIFT:
        if (GetItemPocket(gBattleMons[cv->battlerAtk].item) != POCKET_BERRIES
         || gFieldStatuses & STATUS_FIELD_MAGIC_ROOM
         || cv->abilities[cv->battlerAtk] == ABILITY_KLUTZ
         || gBattleMons[cv->battlerAtk].volatiles.embargoTimer)
            battleScript = BattleScript_ButItFailed;
        break;
    case EFFECT_BELCH:
        if (!GetBattlerPartyState(cv->battlerAtk)->ateBerry)
            battleScript = BattleScript_BelchFails;
        break;
    case EFFECT_BEAK_BLAST:
        if (!gBattleStruct->battlerState[cv->battlerAtk].focusPunchBattlers && GetConfig(B_MOVE_EFFECTS_BEFORE_MOVES) <= GEN_9)
            battleScript = BattleScript_ButItFailed;
        break;
    default:
        break;
    }

    if (battleScript != NULL)
    {
        gBattlescriptCurrInstr = battleScript;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

// Insert failure here if it depends on target and follow the existing structure
static enum CancelerResult CancelerMoveEffectFailureTarget(struct BattleCalcValues *cv)
{
    const u8 *battleScript = NULL;
    u32 numAffectedTargets = 0;
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

    while (gBattleStruct->eventState.atkCancelerBattler < gBattlersCount)
    {
        enum BattlerId battlerDef = gBattleStruct->eventState.atkCancelerBattler++;

        bool32 checkUserFailure = (battlerDef == cv->battlerAtk && moveTarget == TARGET_USER_AND_ALLY);
        if (!checkUserFailure && ShouldSkipFailureCheckOnBattler(cv->battlerAtk, battlerDef))
            continue;

        switch (cv->moveEffect)
        {
        case EFFECT_FLING:
            numAffectedTargets++;
            continue;
        case EFFECT_FUTURE_SIGHT:
            if (gBattleStruct->futureSight[battlerDef].counter > 0)
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_POLTERGEIST:
            if (gBattleMons[battlerDef].item == ITEM_NONE)
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_SUCKER_PUNCH:
        {
            u32 defMove = GetBattlerChosenMove(battlerDef);
            if (HasBattlerActedThisTurn(battlerDef)
             || (IsBattleMoveStatus(defMove) && !gProtectStructs[battlerDef].noValidMoves && GetMoveEffect(defMove) != EFFECT_ME_FIRST))
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }

        }
            break;
        case EFFECT_UPPER_HAND:
        {
            s32 prio = GetChosenMovePriority(battlerDef, GetBattlerAbility(battlerDef));
            if (prio < 1 || prio > 3 // Fails if priority is less than 1 or greater than 3, if target already moved, or if using a status
             || HasBattlerActedThisTurn(battlerDef)
             || gChosenMoveByBattler[battlerDef] == MOVE_NONE
             || IsBattleMoveStatus(gChosenMoveByBattler[battlerDef]))
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        }
        case EFFECT_LOW_KICK:
        case EFFECT_HEAT_CRASH:
            if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
            {
                battleScript = BattleScript_MoveBlockedByDynamax;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_CAPTIVATE:
            if (!AreBattlersOfOppositeGender(cv->battlerAtk, battlerDef))
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_STAT_CHANGE_ON_STATUS:
            if (!(gBattleMons[battlerDef].status1 & GetMoveStatusOnStatChange(cv->move)))
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_STAT_CHANGE_MAGNETIC:
            if (cv->abilities[battlerDef] != ABILITY_PLUS && cv->abilities[battlerDef] != ABILITY_MINUS)
            {
                battleScript = BattleScript_ButItFailed;
            }
            else
            {
                numAffectedTargets++;
                continue;
            }
            break;
        case EFFECT_PRESENT:
            if (gBattleStruct->presentBasePower > 0)
            {
                numAffectedTargets++;
                continue;
            }
            else if (gBattleMons[cv->battlerDef].maxHP == gBattleMons[cv->battlerDef].hp)
            {
                battleScript = BattleScript_AlreadyAtFullHp;
            }
            else
            {
                SetHealAmount(cv->battlerDef, GetNonDynamaxMaxHP(cv->battlerDef) / 4);
                gBattlescriptCurrInstr = BattleScript_PresentHeal;
                numAffectedTargets++;
                continue;
            }
            break;
        default:
            continue;
        }

        gBattleStruct->moveResultFlags[battlerDef] = MOVE_RESULT_DOESNT_AFFECT_FOE;
    }

    gBattleStruct->eventState.atkCancelerBattler = 0;

    if (numAffectedTargets == 0)
    {
        if (battleScript == NULL && cv->moveEffect == EFFECT_FLING)
        {
            // Edge case for removing a mon's item when there is no target available after using Fling.
            gBattlescriptCurrInstr = BattleScript_FlingFailConsumeItem;
            return CANCELER_RESULT_FAILURE;
        }
        else if (battleScript != NULL)
        {
            gBattlescriptCurrInstr = battleScript;
            return CANCELER_RESULT_FAILURE;
        }
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerPowderStatus(struct BattleCalcValues *cv)
{
    if (TryActivatePowderStatus(cv->move))
    {
        if (!IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
            SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / 4);

        // This might be incorrect
        if (GetActiveGimmick(cv->battlerAtk) != GIMMICK_Z_MOVE
         || HasTrainerUsedGimmick(cv->battlerAtk, GIMMICK_Z_MOVE))
            gBattlescriptCurrInstr = BattleScript_MoveUsedPowder;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

bool32 IsDazzlingAbility(enum Ability ability)
{
    switch (ability)
    {
    case ABILITY_DAZZLING:        return TRUE;
    case ABILITY_QUEENLY_MAJESTY: return TRUE;
    case ABILITY_ARMOR_TAIL:      return TRUE;
    default: break;
    }
    return FALSE;
}

static enum CancelerResult CancelerPriorityBlock(struct BattleCalcValues *cv)
{
    bool32 effect = FALSE;
    s32 priority = GetChosenMovePriority(cv->battlerAtk, cv->abilities[cv->battlerAtk]);
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

    if (priority <= 0 || moveTarget == TARGET_FIELD || moveTarget == TARGET_OPPONENTS_FIELD)
        return CANCELER_RESULT_SUCCESS;

    enum BattlerId battler;
    enum Ability ability = ABILITY_NONE; // ability of battler who is blocking
    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (!IsBattlerAlive(battler) || IsBattlerAlly(cv->battlerAtk, battler))
            continue;
        if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, battler)
         && (!IsDoubleBattle() || ShouldSkipFailureCheckOnBattler(cv->battlerAtk, GetPartnerBattler(battler)))) // either battler or partner is affected
            continue;

        ability = cv->abilities[battler];
        if (IsDazzlingAbility(ability))
        {
            effect = TRUE;
            break;
        }
    }

    if (effect)
    {
        gLastUsedAbility = ability;
        RecordAbilityBattle(battler, ability);
        gBattlerAbility = battler;
        gBattlescriptCurrInstr = BattleScript_PokemonCannotUseMove;
        return CANCELER_RESULT_FAILURE;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerExplodingDamp(struct BattleCalcValues *cv)
{
    if (!IsMoveDampBanned(cv->move))
        return CANCELER_RESULT_SUCCESS;

    u32 dampBattler = IsAbilityOnField(ABILITY_DAMP);
    if (dampBattler)
    {
        gBattlerAbility = dampBattler - 1;
        gLastUsedAbility = ABILITY_DAMP;
        RecordAbilityBattle(gBattlerAbility, ABILITY_DAMP);
        gBattlescriptCurrInstr = BattleScript_PokemonCannotUseMove;
        return CANCELER_RESULT_FAILURE;
    }
    return CANCELER_RESULT_SUCCESS;
}

static bool32 CanPledgeComboAttackHappen(struct BattleCalcValues *cv)
{
    enum BattlerId partner = GetPartnerBattler(cv->battlerAtk);
    enum Move partnerMove = GetBattlerChosenMove(partner);

    if (gBattleStruct->pledgeState != PLEDGE_COMBO_NONE)
        return FALSE; // already in progress

    if (!IsDoubleBattle()
     || GetMoveEffect(partnerMove) != EFFECT_PLEDGE
     || !IsBattlerAlive(partner)
     || cv->move == partnerMove
     || gChosenActionByBattler[partner] != B_ACTION_USE_MOVE
     || HasBattlerActedThisTurn(partner))
        return FALSE;

    if (GetPledgeComboMove(cv->move) == partnerMove || GetPledgeComboMove(partnerMove) == cv->move)
    {
        u32 k = 0;
        u32 currPledgeUser = 0;
        u32 newTurnOrder[] = {0xFF, 0xFF};

        for (u32 i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gBattlerAttacker)
            {
                currPledgeUser = i + 1; // Current battler going after attacker
                break;
            }
        }
        for (u32 i = currPledgeUser; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] != partner)
                newTurnOrder[k++] = gBattlerByTurnOrder[i];
        }

        gBattlerByTurnOrder[currPledgeUser++] = partner;

        for (u32 i = 0; newTurnOrder[i] != 0xFF && i < 2; i++)
            gBattlerByTurnOrder[currPledgeUser++] = newTurnOrder[i];

        gBattleStruct->pledgeState = PLEDGE_COMBO_WAITING;
        return TRUE;
    }

    return FALSE;
}

static enum CancelerResult CancelerInterruptibleMoves(struct BattleCalcValues *cv)
{
    switch (cv->moveEffect)
    {
    case EFFECT_FUTURE_SIGHT:
        gBattleStruct->futureSight[cv->battlerDef].move = cv->move;
        gBattleStruct->futureSight[cv->battlerDef].battlerIndex = cv->battlerAtk;
        gBattleStruct->futureSight[cv->battlerDef].partyIndex = gBattlerPartyIndexes[cv->battlerAtk];
        gBattleStruct->futureSight[cv->battlerDef].counter = 3;

        if (gCurrentMove == MOVE_DOOM_DESIRE)
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DOOM_DESIRE;
        else
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_FUTURE_SIGHT;

        gBattleStruct->eventState.atkCanceler = CANCELER_END;
        break;
    case EFFECT_PLEDGE:
        if (CanPledgeComboAttackHappen(cv))
        {
            gBattleStruct->eventState.atkCanceler = CANCELER_END;
            gBattlescriptCurrInstr = BattleScript_PledgeWaitingForPartner;
            return CANCELER_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_SHELL_TRAP:
        if (!gProtectStructs[cv->battlerAtk].shellTrap)
        {
            gBattlescriptCurrInstr = BattleScript_ShellTrapFailed;
            return CANCELER_RESULT_FAILURE;
        }
        break;
    default:
        break;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerProtean(struct BattleCalcValues *cv)
{
    enum Type moveType = GetBattleMoveType(cv->move);
    if (ProteanTryChangeType(cv->battlerAtk, cv->abilities[cv->battlerAtk], cv->move, moveType))
    {
        if (GetConfig(B_PROTEAN_LIBERO) >= GEN_9)
            gBattleMons[cv->battlerAtk].volatiles.usedProteanLibero = TRUE;
        PREPARE_TYPE_BUFFER(gBattleTextBuff1, moveType);
        gBattlerAbility = cv->battlerAtk;
        PrepareStringBattleWithWait(STRINGID_EMPTYSTRING3, cv->battlerAtk);
        BattleScriptCall(BattleScript_ProteanActivates);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static bool32 IsBattlerWeatherAffectedTemp(enum HoldEffect holdEffect, u32 weather, u32 weatherFlags)
{
    if (weather & (B_WEATHER_SUN | B_WEATHER_RAIN) && holdEffect == HOLD_EFFECT_UTILITY_UMBRELLA)
        return FALSE;

    if (weather == B_WEATHER_NONE || !(GetBattleWeather(gBattleWeather) & weatherFlags))
        return FALSE;

    return TRUE;
}

static bool32 CanTwoTurnMoveFireThisTurn(struct BattleCalcValues *cv, bool32 *showAbilityPopUp)
{
    if (cv->moveEffect == EFFECT_GEOMANCY || gBattleMoveEffects[cv->moveEffect].semiInvulnerableEffect)
        return FALSE;

    u32 weather = GetWeather();
    u32 attackerWeather = GetAttackerWeather(cv->holdEffects[cv->battlerAtk], cv->abilities[cv->battlerAtk], weather);

    if (attackerWeather == B_WEATHER_NONE)
        return FALSE;

    enum BattleWeather moveAffectedByWeather = GetTwoTurnMoveWeather(cv->move);
    enum BattleWeather weatherType = gBattleWeatherInfo[GetBattleWeather(weather)].type;
    enum BattleWeather attackerWeatherType = gBattleWeatherInfo[GetBattleWeather(attackerWeather)].type;

    if (weatherType == moveAffectedByWeather && IsBattlerWeatherAffectedTemp(cv->holdEffects[cv->battlerAtk], weather, moveAffectedByWeather))
    {
        return TRUE;
    }

    if (attackerWeatherType == moveAffectedByWeather)
    {
        *showAbilityPopUp = TRUE;
        return TRUE;
    }

    return FALSE;
}

static enum CancelerResult HandleSkyDropResult(struct BattleCalcValues *cv)
{
    if (gBattleMons[cv->battlerAtk].volatiles.multipleTurns) // Second turn
    {
        gBattleScripting.animTurn = 1;
        gBattleScripting.animTargetsHit = 0;
        gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
        gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;

        // Sky Drop fails if target already left the field
        if (gBattleMons[cv->battlerDef].volatiles.semiInvulnerable == STATE_NONE || gBattleMons[cv->battlerAtk].volatiles.skyDropTarget == 0)
        {
            gBattleMons[cv->battlerAtk].volatiles.skyDropTarget = 0;
            gBattlescriptCurrInstr = BattleScript_SkyDropNoTarget;
            return CANCELER_RESULT_FAILURE;
        }

        gBattleMons[cv->battlerAtk].volatiles.skyDropTarget = 0;
        gBattleMons[cv->battlerDef].volatiles.semiInvulnerable = STATE_NONE;
        return CANCELER_RESULT_SUCCESS;
    }

    if (IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (gBattleMons[cv->battlerDef].volatiles.semiInvulnerable != STATE_NONE)
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (DoesSubstituteBlockMove(cv->battlerAtk, cv->battlerDef, cv->move))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }
    else if (GetBattlerWeight(cv->battlerDef, cv->abilities[cv->battlerDef], cv->holdEffects[cv->battlerDef]) >= 2000)
    {
        gBattlescriptCurrInstr = BattleScript_SkyDropTargetTooHeavy;
        return CANCELER_RESULT_FAILURE;
    }

    // First turn

    if (gBattleMons[cv->battlerDef].volatiles.rampageTurns > 0)
        gBattleMons[cv->battlerDef].volatiles.confuseAfterDrop = TRUE;

    CancelMultiTurnMoves(cv->battlerDef);
    gLockedMoves[cv->battlerAtk] = cv->move;
    gProtectStructs[cv->battlerAtk].chargingTurn = TRUE;
    gBattleMons[cv->battlerAtk].volatiles.multipleTurns = TRUE;
    gBattleMons[cv->battlerAtk].volatiles.skyDropTarget = cv->battlerDef + 1;
    gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_SKY_DROP_ATTACKER;
    gBattleMons[cv->battlerDef].volatiles.semiInvulnerable = STATE_SKY_DROP_TARGET;
    if (gSideTimers[GetBattlerSide(cv->battlerDef)].followmeTimer != 0 && gSideTimers[GetBattlerSide(cv->battlerDef)].followmeTarget == cv->battlerDef)
        gSideTimers[GetBattlerSide(cv->battlerDef)].followmeTimer = 0;

    gBattlescriptCurrInstr = BattleScript_SkyDropCharging;
    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

static enum CancelerResult CancelerCharging(struct BattleCalcValues *cv)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    if (!gBattleMoveEffects[cv->moveEffect].twoTurnEffect)
    {
        result = CANCELER_RESULT_SUCCESS;
    }
    else if (cv->moveEffect == EFFECT_SKY_DROP)
    {
        result = HandleSkyDropResult(cv);
    }
    else if (gBattleMons[cv->battlerAtk].volatiles.multipleTurns) // Second turn
    {
        gBattleScripting.animTurn = 1;
        gBattleScripting.animTargetsHit = 0;
        gBattleMons[cv->battlerAtk].volatiles.multipleTurns = FALSE;
        if (gBattleMoveEffects[cv->moveEffect].semiInvulnerableEffect)
            gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
        result = CANCELER_RESULT_SUCCESS;
    }
    else if (!gProtectStructs[cv->battlerAtk].chargingTurn) // First turn charge
    {
        gLockedMoves[cv->battlerAtk] = cv->move;
        gProtectStructs[cv->battlerAtk].chargingTurn = TRUE;
        if (gBattleMoveEffects[cv->moveEffect].semiInvulnerableEffect)
            gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = GetTwoTurnMoveSemiInvulnerability(cv->move);
        BattleScriptCall(BattleScript_TwoTurnMoveCharging);
        result = CANCELER_RESULT_RUN_SCRIPT;
    }
    else // Try move this turn. Otherwise use next turn
    {
        bool32 showAbilityPopUp = FALSE;
        if (CanTwoTurnMoveFireThisTurn(cv, &showAbilityPopUp))
        {
            gBattleScripting.animTurn = 1;
            gBattleScripting.animTargetsHit = 0;
            gBattleScripting.battler = cv->battlerAtk;
            gProtectStructs[cv->battlerAtk].chargingTurn = FALSE;
            if (gBattleMoveEffects[cv->moveEffect].semiInvulnerableEffect)
                gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
            if (showAbilityPopUp)
            {
                BattleScriptCall(BattleScript_MegaSolActivatesTwoTurnMove);
                result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
            }
            else
            {
                result = CANCELER_RESULT_SUCCESS;
            }
        }
        else if (cv->holdEffects[cv->battlerAtk] == HOLD_EFFECT_POWER_HERB)
        {
            gBattleScripting.animTurn = 1;
            gBattleScripting.animTargetsHit = 0;
            gProtectStructs[cv->battlerAtk].chargingTurn = FALSE;
            if (gBattleMoveEffects[cv->moveEffect].semiInvulnerableEffect)
                gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
            gLastUsedItem = gBattleMons[cv->battlerAtk].item;
            BattleScriptCall(BattleScript_PowerHerbActivation);
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        else // Use move next turn
        {
            gBattleMons[cv->battlerAtk].volatiles.multipleTurns = TRUE;
            gBattlescriptCurrInstr = BattleScript_MoveEnd;
            result = CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
    }

    return result;
}

static enum CancelerResult CancelerSnatch(struct BattleCalcValues *cv)
{
    for (u32 i = 0; i < gCurrentTurnActionNumber; i++)
    {
        if (!gProtectStructs[gBattlerByTurnOrder[i]].stealMove
         || !MoveCanBeSnatched(cv->move))
            continue;

        if (B_SNATCH < GEN_5 || !gBattleStruct->snatchedMoveIsUsed)
        {
            u32 snatchBattler = gBattlerByTurnOrder[i];

            if (!gBattleStruct->snatchedMoveIsUsed) // store only once
            {
                SaveBattlerAttacker(gBattlerAttacker);
                SaveBattlerTarget(gBattlerTarget);
            }

            gProtectStructs[snatchBattler].stealMove = FALSE;
            gBattleStruct->snatchedMoveIsUsed = TRUE;

            if (cv->battlerAtk == cv->battlerDef)
            {
                gBattleScripting.battler = gBattlerTarget;
                gBattlerAttacker = gBattlerTarget = snatchBattler;
            }
            else
            {
                gBattlerTarget = gBattlerAttacker;
                gBattlerAttacker = snatchBattler;
            }

            gBattleStruct->eventState.atkCanceler = CANCELER_VOLATILE_BLOCKED;
            BattleScriptCall(BattleScript_SnatchedMove);
            return CANCELER_RESULT_RUN_SCRIPT;
        }
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerExplosion(struct BattleCalcValues *cv)
{
    // KO user of Explosion; for Final Gambit doesn't happen if target is immune or if it missed
    if (IsExplosionMove(cv->move)
     && (cv->moveEffect != EFFECT_FINAL_GAMBIT || IsAnyTargetAffected()))
    {
        BattleScriptCall(BattleScript_Explosion);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerMoveSpecificMessage(struct BattleCalcValues *cv)
{
    switch (cv->moveEffect)
    {
    case EFFECT_MAGNITUDE:
        CalculateMagnitudeDamage();
        BattleScriptCall(BattleScript_MagnitudeMessage);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    case EFFECT_FICKLE_BEAM:
        gBattleStruct->fickleBeamBoosted = RandomPercentage(RNG_FICKLE_BEAM, 30);
        if (gBattleStruct->fickleBeamBoosted)
        {
            BattleScriptCall(BattleScript_FickleBeamMessage);
            return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
        }
        break;
    default:
        break;
    }

    return CANCELER_RESULT_SUCCESS;
}

static bool32 NoTargetPresent(enum BattlerId battler, enum Move move, enum MoveTarget moveTarget)
{
    switch (moveTarget)
    {
    case TARGET_USER_AND_ALLY:
        return FALSE; // At least user is present
    case TARGET_ALLY:
        if (!IsBattlerAlive(gBattlerTarget))
            return TRUE;
        break;
    case TARGET_SELECTED:
    case TARGET_DEPENDS:
    case TARGET_RANDOM:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(GetBattleMoveTarget(move, TARGET_NONE)))
            return TRUE;
        break;
    case TARGET_BOTH:
    case TARGET_SMART:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(GetPartnerBattler(gBattlerTarget)))
            return TRUE;
        break;
    case TARGET_FOES_AND_ALLY:
        if (!IsBattlerAlive(gBattlerTarget) && !IsBattlerAlive(GetPartnerBattler(gBattlerTarget)) && !IsBattlerAlive(GetPartnerBattler(gBattlerAttacker)))
            return TRUE;
        break;
    default:
        break;
    }

    return FALSE;
}

static enum CancelerResult CancelerNoTarget(struct BattleCalcValues *cv)
{
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

    if (NoTargetPresent(gBattlerAttacker, gCurrentMove, moveTarget))
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }

    if (cv->battlerAtk == cv->battlerDef
     && moveTarget == TARGET_ALLY
     && gProtectStructs[GetPartnerBattler(cv->battlerAtk)].usedAllySwitch)
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        return CANCELER_RESULT_FAILURE;
    }

    gBattleStruct->eventState.moveEndBlock = 0;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerTookAttack(struct BattleCalcValues *cv)
{
    if (gSpecialStatuses[cv->battlerDef].abilityRedirected)
    {
        gSpecialStatuses[cv->battlerDef].abilityRedirected = FALSE;
        BattleScriptCall(BattleScript_TookAttack);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }
    return CANCELER_RESULT_SUCCESS;
}

static void SetDamageContextValues(struct DamageContext *ctx, struct BattleCalcValues *cv)
{
    ctx->battlerAtk = cv->battlerAtk;
    ctx->battlerDef = cv->battlerDef;
    ctx->move = cv->move;
    ctx->chosenMove = gChosenMove;
    ctx->baseMove = gBattleStruct->baseMove;
    ctx->moveType = GetBattleMoveType(cv->move);
    ctx->weather = GetWeather();
    ctx->terrain = gFieldTimers.terrain;
    ctx->updateFlags = TRUE;
    ctx->runScript = TRUE;
    for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
    {
        ctx->abilities[battler] = cv->abilities[battler];
        ctx->holdEffects[battler] = cv->holdEffects[battler];
    }
}

static bool32 IsTargetUnaffectedByMoveEffect(struct BattleCalcValues *cv)
{
    switch (cv->moveEffect)
    {
    case EFFECT_ENDEAVOR:
        if (GetNonDynamaxHP(cv->battlerDef) <= gBattleMons[cv->battlerAtk].hp)
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_NO_EFFECT;
            BattleScriptCall(BattleScript_ItDoesntAffectScrTarget);
            return TRUE;
        }
        break;
    case EFFECT_DREAM_EATER:
        if (GetConfig(B_DREAM_EATER_SUBSTITUTE) < GEN_5 && IsSubstituteProtected(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->move))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_NO_EFFECT;
            BattleScriptCall(BattleScript_ItDoesntAffectScrTarget);
            return TRUE;
        }
        if (!IsAsleepOrComatose(cv->battlerDef, cv->abilities[cv->battlerDef]))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_NO_EFFECT;
            BattleScriptCall(BattleScript_ItDoesntAffectScrTarget);
            return TRUE;
        }
        break;
    case EFFECT_SYNCHRONOISE:
        if (!DoBattlersShareType(cv->battlerAtk, cv->battlerDef))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_NO_EFFECT;
            BattleScriptCall(BattleScript_ItDoesntAffectScrTarget);
            return TRUE;
        }
        break;
    case EFFECT_SKY_DROP:
        if (!gProtectStructs[cv->battlerAtk].chargingTurn
         && IS_BATTLER_OF_TYPE(cv->battlerDef, TYPE_FLYING))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_NO_EFFECT;
            BattleScriptCall(BattleScript_SkyDropFlyingType);
            return TRUE;
        }
        break;
    default:
        break;
    }

    return FALSE;
}

static enum CancelerResult TargetAvoidedAttack(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    gLastLandedMoves[battlerDef] = 0; // Might need investigation on what exactly clears is
    gLastHitByType[battlerDef] = 0;
    gBattleScripting.battler = battlerDef;
    CancelMultiTurnMoves(battlerAtk);
    return CANCELER_RESULT_RUN_SCRIPT;
}

static enum CancelerResult CancelerTargetFailure(struct BattleCalcValues *cv)
{
    bool32 bounced = FALSE;
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
    s32 movePriority = GetChosenMovePriority(cv->battlerAtk, cv->abilities[cv->battlerAtk]);

    struct DamageContext ctx = {0};
    SetDamageContextValues(&ctx, cv);

    switch (gBattleStruct->eventState.moveEndBlock)
    {
    case TARGET_FAILURE_SEMI_INVULNERABILITY:
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            cv->battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

            if (moveTarget == TARGET_OPPONENTS_FIELD)
                continue;

            if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
                continue;

            if (!CanBreakThroughSemiInvulnerablity(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->abilities[cv->battlerDef], cv->move))
            {
                gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
                if (cv->moveEffect == EFFECT_FLING)
                    BattleScriptCall(BattleScript_TargetAvoidsAttackConsumeFlingItem);
                else
                    BattleScriptCall(BattleScript_BattlerAvoidedAttack);
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
        }
        gBattleStruct->eventState.moveEndBlock++;
    case TARGET_FAILURE_PSYCHIC_TERRAIN:
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            cv->battlerDef = ctx.battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

            if (moveTarget == TARGET_OPPONENTS_FIELD)
                continue;

            if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
                continue;

            if (CanPsychicTerrainProtectTarget(&ctx, movePriority))
            {
                gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
                gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
        }
        gBattleStruct->eventState.moveEndBlock++;
    case TARGET_FAILURE_PROTECT:
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            cv->battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

            if (moveTarget == TARGET_OPPONENTS_FIELD)
                continue;

            if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
                continue;

            if (IsBattlerProtected(cv))
            {
                SetOrClearRageVolatile();
                gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_PROTECTED;
                if (cv->moveEffect == EFFECT_FLING)
                    BattleScriptCall(BattleScript_TargetProtectedConsumeFlingItem);
                else
                    BattleScriptCall(BattleScript_TargetProtected);
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
        }
        gBattleStruct->eventState.moveEndBlock++;
    case TARGET_FAILURE_BOUNCE:
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            cv->battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

            if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
                continue;

            if (!IsSemiInvulnerable(cv->battlerDef, CHECK_ALL) && CanBattlerBounceBackMove(cv))
            {
                gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
                gLastLandedMoves[cv->battlerDef] = 0;
                gLastHitByType[cv->battlerDef] = 0;
                bounced = TRUE;
            }
        }

        if (bounced && moveTarget == TARGET_OPPONENTS_FIELD)
        {
            gBattleStruct->eventState.moveEndBlock = 0;
            gBattlescriptCurrInstr = BattleScript_MoveEnd;
            return CANCELER_RESULT_FAILURE;
        }
        gBattleStruct->eventState.moveEndBlock++;
    case TARGET_FAILURE_TARGET_BLOCKED:
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            cv->battlerDef = ctx.battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

            if (moveTarget == TARGET_OPPONENTS_FIELD)
                continue;

            if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
                continue;

            if (CanMoveBeBlockedByTarget(&ctx, movePriority))
            {
                gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_FAILED;
                gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
        }
        gBattleStruct->eventState.moveEndBlock++;
    case TARGET_FAILURE_EFFECTIVENESS:
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            cv->battlerDef = ctx.battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

            if (moveTarget == TARGET_OPPONENTS_FIELD)
                continue;

            if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
                continue;

            ctx.typeEffectivenessModifier = CalcTypeEffectivenessMultiplier(&ctx);
            gSpecialStatuses[cv->battlerDef].storedTypeEffectiveness = ctx.typeEffectivenessModifier;

            if (ctx.abilityBlocked)
            {
                gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;
                gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_FAILED;
                gBattlerAbility = cv->battlerDef;
                RecordAbilityBattle(cv->battlerDef, cv->abilities[cv->battlerDef]);
                BattleScriptCall(BattleScript_AbilityProtectedTarget);
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
            else if (ctx.airBalloonBlocked)
            {
                gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;
                gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_FAILED;
                BattleScriptCall(BattleScript_DoesntAffectScripting);
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
            else if (ctx.typeEffectivenessModifier == UQ_4_12(0.0))
            {
                TryInitializeTrainerSlideMonUnaffected(cv->battlerDef, cv->battlerAtk);
                gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;
                gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_FAILED;
                BattleScriptCall(BattleScript_DoesntAffectScripting);
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
            else if (IsTargetUnaffectedByMoveEffect(cv))
            {
                TryInitializeTrainerSlideMonUnaffected(cv->battlerDef, cv->battlerAtk);
                gSpecialStatuses[cv->battlerDef].updateStallMons = TRUE;
                return TargetAvoidedAttack(cv->battlerAtk, cv->battlerDef);
            }
        }
        gBattleStruct->eventState.moveEndBlock++;
    }

    if (IsDoubleBattle())
    {
        if (moveTarget == TARGET_BOTH)
            gBattleStruct->numSpreadTargets = CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER_SIDE, gBattlerAttacker);
        else if (moveTarget == TARGET_FOES_AND_ALLY)
            gBattleStruct->numSpreadTargets = CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, gBattlerAttacker);
    }

    cv->battlerDef = gBattlerTarget;
    gBattleStruct->eventState.moveEndBlock = 0;
    gBattleStruct->eventState.atkCancelerBattler = 0;

    return CANCELER_RESULT_SUCCESS;
}

static bool32 IsMoveParentalBondAffected(struct BattleCalcValues *cv)
{
    if (cv->abilities[cv->battlerAtk] != ABILITY_PARENTAL_BOND
     || gBattleStruct->numSpreadTargets > 1
     || IsMoveParentalBondBanned(cv->move)
     || IsBattleMoveStatus(cv->move)
     || gBattleMoveEffects[cv->moveEffect].twoTurnEffect
     || cv->moveEffect == EFFECT_OHKO
     || GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE
     || cv->move == MOVE_STRUGGLE)
        return FALSE;
    return TRUE;
}

static void SetPossibleNewSmartTarget(u32 move)
{
    if (!IsBattlerUnaffectedByMove(gBattlerTarget)
     || !CanTargetPartner(gBattlerAttacker, gBattlerTarget)
     || IsAffectedByFollowMe(gBattlerAttacker, GetBattlerSide(gBattlerTarget), move)
     || GetBattlerMoveTargetType(gBattlerAttacker, move) != TARGET_SMART)
        return;

    enum BattlerId partner = GetPartnerBattler(gBattlerTarget);
    if (!IsBattlerUnaffectedByMove(partner))
        gBattlerTarget = partner;
}

static void SetRandomMultiHitCounter(enum HoldEffect holdEffect)
{
    if (holdEffect == HOLD_EFFECT_LOADED_DICE)
        gMultiHitCounter = RandomUniform(RNG_LOADED_DICE, 4, 5);
    else if (GetConfig(B_MULTI_HIT_CHANCE) >= GEN_5)
        gMultiHitCounter = RandomWeighted(RNG_HITS, 0, 0, 7, 7, 3, 3); // 35%: 2 hits, 35%: 3 hits, 15% 4 hits, 15% 5 hits.
    else
        gMultiHitCounter = RandomWeighted(RNG_HITS, 0, 0, 3, 3, 1, 1); // 37.5%: 2 hits, 37.5%: 3 hits, 12.5% 4 hits, 12.5% 5 hits.
}

static enum CancelerResult CancelerMultihitMoves(struct BattleCalcValues *cv)
{
    SetPossibleNewSmartTarget(cv->move);

    if (IsBattlerUnaffectedByMove(gBattlerTarget))
    {
        gMultiHitCounter = 0;
    }
    else if (IsMultiHitMove(cv->move))
    {
        if (cv->moveEffect == EFFECT_SPECIES_POWER_OVERRIDE
         && gBattleMons[cv->battlerAtk].species == GetMoveSpeciesPowerOverride_Species(cv->move))
        {
            gMultiHitCounter = GetMoveSpeciesPowerOverride_NumOfHits(cv->move);
        }
        else if (cv->abilities[cv->battlerAtk] == ABILITY_SKILL_LINK)
        {
            gMultiHitCounter = 5;
        }
        else
        {
            SetRandomMultiHitCounter(cv->holdEffects[cv->battlerAtk]);
        }

        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
    }
    else if (GetMoveStrikeCount(cv->move) > 1)
    {
        if (GetMoveEffect(cv->move) == EFFECT_POPULATION_BOMB
         && cv->holdEffects[cv->battlerAtk] == HOLD_EFFECT_LOADED_DICE
         && cv->abilities[cv->battlerAtk] != ABILITY_SKILL_LINK)
        {
            gMultiHitCounter = RandomUniform(RNG_LOADED_DICE, 4, 10);
        }
        else
        {
            gMultiHitCounter = GetMoveStrikeCount(cv->move);
        }

        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 3, 0)
    }
    else if (cv->moveEffect == EFFECT_BEAT_UP)
    {
        struct Pokemon* party = GetBattlerParty(cv->battlerAtk);
        int i;
        gBattleStruct->beatUpSlot = 0;
        gMultiHitCounter = 0;
        memset(gBattleStruct->beatUpSpecies, 0xFF, sizeof(gBattleStruct->beatUpSpecies));

        for (i = 0; i < PARTY_SIZE; i++)
        {
            enum Species species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (species != SPECIES_NONE
             && GetMonData(&party[i], MON_DATA_HP)
             && !GetMonData(&party[i], MON_DATA_IS_EGG)
             && !GetMonData(&party[i], MON_DATA_STATUS))
            {
                if (GetConfig(B_BEAT_UP) >= GEN_5)
                    gBattleStruct->beatUpSpecies[gMultiHitCounter] = species;
                else
                    gBattleStruct->beatUpSpecies[gMultiHitCounter] = i;
                gMultiHitCounter++;
            }
        }

        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
    }
    else if (IsMoveParentalBondAffected(cv))
    {
        gSpecialStatuses[gBattlerAttacker].parentalBondState = PARENTAL_BOND_1ST_HIT;
        gMultiHitCounter = 2;
        PREPARE_BYTE_NUMBER_BUFFER(gBattleScripting.multihitString, 1, 0)
    }
    else
    {
        gMultiHitCounter = 0;
    }

    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerSubstitute(struct BattleCalcValues *cv)
{
    if (!IsBattleMoveStatus(cv->move)
     || IsStatChangeMove(cv->move)
     || (cv->moveEffect == EFFECT_TRANSFORM && GetConfig(B_TRANSFORM_SUBSTITUTE_FAIL) < GEN_5))
        return CANCELER_RESULT_SUCCESS;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
            continue;

        if (IsSubstituteProtected(cv->battlerAtk, battler, cv->abilities[cv->battlerAtk], cv->move))
            gBattleStruct->moveResultFlags[battler] = MOVE_RESULT_DOESNT_AFFECT_FOE;
    }

    if (!IsAnyTargetAffected())
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
        gBattleStruct->eventState.atkCanceler = CANCELER_END;
        return CANCELER_RESULT_END;
    }

    return CANCELER_RESULT_SUCCESS;
}

static bool32 ShouldSkipAccuracyCalcPastFirstHit(enum BattlerId battlerAtk, enum Ability abilityAtk, enum HoldEffect holdEffectAtk, u32 moveEffect)
{
    if (gSpecialStatuses[battlerAtk].parentalBondState == PARENTAL_BOND_2ND_HIT)
        return TRUE;

    if (!gSpecialStatuses[battlerAtk].multiHitOn)
        return FALSE;

    if (abilityAtk == ABILITY_SKILL_LINK || holdEffectAtk == HOLD_EFFECT_LOADED_DICE)
        return TRUE;

    if (moveEffect == EFFECT_TRIPLE_KICK || moveEffect == EFFECT_POPULATION_BOMB)
        return FALSE;

    return TRUE; // multiHitOn is set so skip Acc check for everything else
}

static bool32 ShouldSkipFRLGAccuracyCheck(void)
{
    if (!IS_FRLG)
        return FALSE;

    if ((gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE
     && (!BtlCtrl_OakOldMan_TestState2Flag(1) || !BtlCtrl_OakOldMan_TestState2Flag(2))
     && GetMovePower(gCurrentMove) != 0
     && GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER))
    {
        return TRUE;
    }

    if (gBattleTypeFlags & BATTLE_TYPE_POKEDUDE)
        return TRUE;

    return FALSE;
}

static enum CancelerResult CancelerAccuracyCheck(struct BattleCalcValues *cv)
{
    if (IsStatChangeMove(cv->move))
    {
        gBattleStruct->eventState.atkCanceler = CANCELER_END;
        return CANCELER_RESULT_END;
    }

    enum SmartTargetState {
        INITIAL_STATE,
        MISSED_FIRST_TARGET,
        TRY_SECOND_TARGET,
    };

    if (ShouldSkipFRLGAccuracyCheck()
     || ShouldSkipAccuracyCalcPastFirstHit(cv->battlerAtk, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->moveEffect)
     || IsMaxMove(cv->move)
     || IsZMove(cv->move))
        return CANCELER_RESULT_SUCCESS;

    enum SmartTargetState smartTargetState = INITIAL_STATE;
    bool32 isSmartTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move) == TARGET_SMART;
    bool32 isMultiHitOn = gSpecialStatuses[cv->battlerAtk].multiHitOn;

    while (gBattleStruct->eventState.atkCancelerBattler < gBattlersCount)
    {
        cv->battlerDef = GetTargetBySlot(cv->battlerAtk, gBattleStruct->eventState.atkCancelerBattler);

        gBattleStruct->eventState.atkCancelerBattler++;

        if (ShouldSkipFailureCheckOnBattler(cv->battlerAtk, cv->battlerDef))
            continue;

        if (DoesMoveMissTarget(cv))
        {
            gBattleStruct->moveResultFlags[cv->battlerDef] |= MOVE_RESULT_MISSED;

            if (cv->holdEffects[cv->battlerAtk] == HOLD_EFFECT_BLUNDER_POLICY
             && cv->moveEffect != EFFECT_OHKO
             && !isMultiHitOn)
                gBattleStruct->blunderPolicy = TRUE;

            if (isSmartTarget
             && smartTargetState == INITIAL_STATE
             && !IsAffectedByFollowMe(cv->battlerAtk, GetBattlerSide(cv->battlerDef), cv->move)
             && CanTargetPartner(cv->battlerAtk, cv->battlerDef)
             && !IsBattlerUnaffectedByMove(GetPartnerBattler(cv->battlerDef)))
            {
                smartTargetState = MISSED_FIRST_TARGET;
                gBattlerTarget = GetPartnerBattler(cv->battlerDef); // Smart target to partner if miss
            }

            if (!isMultiHitOn)
            {
                gLastLandedMoves[cv->battlerDef] = 0;
                gLastHitByType[cv->battlerDef] = 0;
            }

            if (smartTargetState == MISSED_FIRST_TARGET) // Silent failure on first target.
            {
                smartTargetState = TRY_SECOND_TARGET;
                continue;
            }

            if (isMultiHitOn)
            {
                gMultiHitCounter = 0;
                gBattleStruct->moveDamage[gBattlerTarget] = 0;
                gSpecialStatuses[gBattlerTarget].damagedByAttack = FALSE;
                BattleScriptCall(BattleScript_BattlerAvoidedMultiHit);
            }
            else if (gBattleStruct->moveResultFlags[cv->battlerDef] & MOVE_RESULT_ONE_HIT_KO_STURDY)
            {
                gLastUsedAbility = ABILITY_STURDY;
                gBattlerAbility = cv->battlerDef;
                BattleScriptCall(BattleScript_SturdyPreventsOHKO);
            }
            else if (gBattleStruct->moveResultFlags[cv->battlerDef] & MOVE_RESULT_ONE_HIT_KO_NO_AFFECT)
            {
                BattleScriptCall(BattleScript_ItDoesntAffectScrTarget);
            }
            else if (cv->moveEffect == EFFECT_FLING)
            {
                BattleScriptCall(BattleScript_TargetAvoidsAttackConsumeFlingItem);
            }
            else
            {
                BattleScriptCall(BattleScript_BattlerAvoidedAttack);
            }

            if (gBattleStruct->moveResultFlags[cv->battlerDef] & (MOVE_RESULT_ONE_HIT_KO_NO_AFFECT | MOVE_RESULT_ONE_HIT_KO_STURDY))
                gBattleStruct->moveResultFlags[cv->battlerDef] = (MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED);

            SetOrClearRageVolatile();
            gBattleScripting.battler = cv->battlerDef;
            return CANCELER_RESULT_RUN_SCRIPT;
        }
    }

    cv->battlerDef = gBattlerTarget;
    gBattleStruct->eventState.atkCancelerBattler = 0;

    if (!IsAnyTargetAffected())
    {
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
        gBattleStruct->eventState.atkCanceler = CANCELER_END;
        return CANCELER_RESULT_END;
    }

    return CANCELER_RESULT_SUCCESS;
}

static bool32 ShouldSkipBattlerForDamage(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    if (gBattleStruct->numSpreadTargets == 0 && battlerDef != gBattlerTarget)
        return TRUE;
    if (gBattleStruct->battlerState[battlerAtk].targetsDone[battlerDef])
        return TRUE;
    if (gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_INVALID_TARGET)
        return TRUE;
    return FALSE;
}

static enum CancelerResult CancelerPreAttackMoveEffect(struct BattleCalcValues *cv)
{
    if (IsBattleMoveStatus(cv->move))
    {
        gBattleStruct->eventState.atkCanceler = CANCELER_END;
        return CANCELER_RESULT_END;
    }

    u32 numAdditionalEffects = GetMoveAdditionalEffectCount(cv->move);
    struct SetEffect se = {0};

    while (gBattleStruct->eventState.atkCancelerBattler < gBattlersCount)
    {
        gEffectBattler = GetTargetBySlot(cv->battlerAtk, gBattleStruct->eventState.atkCancelerBattler);

        while (gBattleStruct->additionalEffectsCounter < numAdditionalEffects)
        {
            const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(cv->move, gBattleStruct->additionalEffectsCounter);
            gBattleStruct->additionalEffectsCounter++;

            if (!additionalEffect->preAttackEffect)
                continue;

            bool32 isSelf = gEffectBattler == cv->battlerAtk;
            if (isSelf != additionalEffect->self)
                continue;

            if (!isSelf && ShouldSkipFailureCheckOnBattler(cv->battlerAtk, gEffectBattler))
                continue;

            u32 percentChance = CalcSecondaryEffectChance(cv->battlerAtk, cv->abilities[cv->battlerAtk], additionalEffect);

            // Activate effect if it's primary (chance == 0) or if RNGesus says so
            if ((percentChance == 0) || RandomPercentage(RNG_SECONDARY_EFFECT + gBattleStruct->additionalEffectsCounter, percentChance))
            {
                se.additionalEffect = additionalEffect;
                se.moveEffect = additionalEffect->moveEffect;
                se.script = gBattlescriptCurrInstr;
                se.effectBattler = additionalEffect->self ? cv->battlerAtk : cv->battlerDef;
                se.primary = percentChance == 0;
                se.certain = percentChance >= 100;
                se.onSide = additionalEffect->onSide; // TODO

                SetMoveEffect(cv, &se);
            }
            return CANCELER_RESULT_RUN_SCRIPT; // We don't know if a script should be run or not so try
        }

        gBattleStruct->eventState.atkCancelerBattler++;
        gBattleStruct->additionalEffectsCounter = 0;
    }

    gBattleStruct->additionalEffectsCounter = 0;
    gBattleStruct->eventState.atkCancelerBattler = 0;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerDamageCalc(struct BattleCalcValues *cv)
{
    struct DamageContext ctx = {
        .battlerAtk = cv->battlerAtk,
        .move = cv->move,
        .chosenMove = gChosenMove,
        .baseMove = gBattleStruct->baseMove,
        .moveType = GetBattleMoveType(cv->move),
        .weather = GetWeather(),
        .terrain = gFieldTimers.terrain,
        .randomFactor = TRUE,
        .updateFlags = TRUE,
        .useStoredTypeEffectiveness = TRUE,
    };

    for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
    {
        ctx.abilities[battler] = cv->abilities[battler];
        ctx.holdEffects[battler] = cv->holdEffects[battler];
    }

    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (ShouldSkipBattlerForDamage(cv->battlerAtk, battlerDef))
            continue;

        ctx.battlerDef = battlerDef;
        gBattleStruct->moveDamage[battlerDef] = CalculateMoveDamage(&ctx);
    }

    if (gSpecialStatuses[cv->battlerAtk].gemBoost
     && gBattleMons[cv->battlerAtk].item
     && IsAnyTargetAffected())
    {
        BattleScriptCall(BattleScript_GemActivates);
        gLastUsedItem = gBattleMons[cv->battlerAtk].item;
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
    }

    return CANCELER_RESULT_SUCCESS;
}


static enum CancelerResult CancelerPreAnimActivations(struct BattleCalcValues *cv)
{
    switch (gBattleStruct->eventState.moveEndBlock)
    {
    case PRE_ANIM_STRONG_WINDS:
        if (GetWeather() & B_WEATHER_STRONG_WINDS)
        {
            for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
            {
                if (ShouldSkipBattlerForDamage(cv->battlerAtk, battlerDef))
                    continue;

                if (gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_HIGH_EFFECTIVENESS
                 && IS_BATTLER_OF_TYPE(battlerDef, TYPE_FLYING))
                {
                    BattleScriptCall(BattleScript_AttackWeakenedByStrongWinds);
                    gBattleStruct->eventState.moveEndBlock++;
                    return CANCELER_RESULT_RUN_SCRIPT;
                }
            }
        }
        gBattleStruct->eventState.moveEndBlock++;
    case PRE_ANIM_TERA_SHELL:
        for (enum BattlerId battler = B_BATTLER_0; battler < MAX_BATTLERS_COUNT; battler++)
        {
            enum BattlerId battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

            if (ShouldSkipBattlerForDamage(cv->battlerAtk, battlerDef))
                continue;

            if (gSpecialStatuses[battlerDef].teraShellAbilityDone)
            {
                gSpecialStatuses[battlerDef].teraShellAbilityDone = FALSE;
                gBattleScripting.battler = battlerDef;
                BattleScriptCall(BattleScript_TeraShellDistortingTypeMatchups);
                return CANCELER_RESULT_RUN_SCRIPT;
            }
        }
        gBattleStruct->eventState.moveEndBlock++;
    case PRE_ANIM_RESIST_BERRY:
        while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
        {
            enum BattlerId battlerDef = GetTargetBySlot(cv->battlerAtk, gBattleStruct->eventState.moveEndBattler);

            gBattleStruct->eventState.moveEndBattler++;

            if (ShouldSkipBattlerForDamage(cv->battlerAtk, battlerDef))
                continue;

            if (!gSpecialStatuses[battlerDef].berryReduced
             || gBattleMons[battlerDef].item == ITEM_NONE)
                continue;

            if (DoesDisguiseBlockMove(battlerDef, cv->move))
            {
                gSpecialStatuses[battlerDef].berryReduced = FALSE;
                continue;
            }

            gBattleScripting.battler = battlerDef;
            BattleScriptCall(BattleScript_BerryReduceAnimation);
            return CANCELER_RESULT_RUN_SCRIPT;
        }
        gBattleStruct->eventState.moveEndBlock++;
    default:
        break;
    }

    gBattleStruct->eventState.moveEndBlock = 0;
    gBattleStruct->eventState.moveEndBattler = 0;
    return CANCELER_RESULT_SUCCESS;
}

static enum CancelerResult CancelerMoveAnimation(struct BattleCalcValues *cv)
{
    if (gSpecialStatuses[cv->battlerAtk].parentalBondState == PARENTAL_BOND_2ND_HIT)
        return CANCELER_RESULT_SUCCESS;

    bool32 isAnimDisabled = (gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION)
                          || gBattleStruct->attackAnimPlayed);
    if (isAnimDisabled
     && cv->moveEffect != EFFECT_TRANSFORM
     && cv->moveEffect != EFFECT_SUBSTITUTE
     && cv->moveEffect != EFFECT_ALLY_SWITCH
     // In a wild double battle gotta use the teleport animation if two wild Pokémon are alive.
     && !(cv->moveEffect == EFFECT_TELEPORT && WILD_DOUBLE_BATTLE && !IsOnPlayerSide(cv->battlerAtk) && IsBattlerAlive(GetPartnerBattler(cv->battlerAtk))))
    {
        gBattleScripting.animTurn++;
        gBattleScripting.animTargetsHit++;
        BattleScriptCall(BattleScript_Pausex20);
        return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;

    }

    // handle special move animations.
    if (GetMoveAnimationScript(cv->move) == gBattleAnimMove_ExpandingForce
     && gBattleStruct->numSpreadTargets > 1)
        gBattleScripting.animTurn = 1;

    u32 multiHit = gMultiHitCounter;
    bool32 willDamageFaintBattler = (gBattleMons[cv->battlerDef].hp <= gBattleStruct->moveDamage[cv->battlerDef]);
    if (!gBattleMons[cv->battlerDef].volatiles.substitute && willDamageFaintBattler)
        multiHit = 1;

    BtlController_EmitMoveAnimation(
        cv->battlerAtk,
        B_COMM_TO_CONTROLLER,
        cv->move,
        gBattleScripting.animTurn,
        gBattleMovePower,
        gBattleStruct->moveDamage[cv->battlerDef],
        gBattleMons[cv->battlerAtk].friendship,
        multiHit
    );

    #if TESTING
    gCountAllocs = TRUE;
    gSpriteAllocs = 0;
    #endif

    MarkBattlerForControllerExec(gBattlerAttacker);
    BattleScriptCall(BattleScript_MoveAnimation);

    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

static inline bool32 DoesBattlerNegateDamage(enum BattlerId battler, enum Ability ability, enum Move move)
{
    enum Species species = gBattleMons[battler].species;

    if (gBattleMons[battler].volatiles.transformed)
        return FALSE;
    if (ability == ABILITY_DISGUISE && IsMimikyuDisguised(battler))
        return TRUE;
    if (ability == ABILITY_ICE_FACE && species == SPECIES_EISCUE_ICE && IsBattleMovePhysical(move))
        return TRUE;

    return FALSE;
}

static u32 UpdateEffectivenessResultFlagsForDoubleSpreadMoves(struct BattleCalcValues *cv)
{
    u32 resultFlags = 0;
    for (u32 battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (ShouldSkipBattlerForDamage(cv->battlerAtk, battlerDef))
            continue;
        if (DoesBattlerNegateDamage(battlerDef, cv->abilities[battlerDef], cv->move))
            continue;

        resultFlags |= gBattleStruct->moveResultFlags[battlerDef];

        if (!(gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_LOW_EFFECTIVENESS))
            resultFlags &= ~MOVE_RESULT_NOT_VERY_EFFECTIVE; // any battler with 1x or better effectiveness removes NVE sound
        if (gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_HIGH_EFFECTIVENESS)
            resultFlags |= MOVE_RESULT_SUPER_EFFECTIVE; // any super effective result will play SE_SUPER_EFFECTIVE
    }
    return resultFlags;
}

static enum CancelerResult CancelerEffectivenessSound(struct BattleCalcValues *cv)
{
    u32 moveResultFlags = UpdateEffectivenessResultFlagsForDoubleSpreadMoves(cv);

    switch (moveResultFlags)
    {
    case MOVE_RESULT_SUPER_EFFECTIVE:
    case MOVE_RESULT_EXTREMELY_EFFECTIVE:
        #if TESTING
        if (gTestRunnerEnabled)
            TestRunner_Battle_RecordEffectivenessSound(gBattlerTarget, SE_SUPER_EFFECTIVE);
        #endif
        BtlController_EmitPlaySE(gBattlerTarget, B_COMM_TO_CONTROLLER, SE_SUPER_EFFECTIVE);
        MarkBattlerForControllerExec(gBattlerTarget);
        break;
    case MOVE_RESULT_NOT_VERY_EFFECTIVE:
    case MOVE_RESULT_MOSTLY_INEFFECTIVE:
        #if TESTING
        if (gTestRunnerEnabled)
            TestRunner_Battle_RecordEffectivenessSound(gBattlerTarget, SE_NOT_EFFECTIVE);
        #endif
        BtlController_EmitPlaySE(gBattlerTarget, B_COMM_TO_CONTROLLER, SE_NOT_EFFECTIVE);
        MarkBattlerForControllerExec(gBattlerTarget);
        break;
    case MOVE_RESULT_DOESNT_AFFECT_FOE:
    case MOVE_RESULT_FAILED:
        // no sound
        break;
    case MOVE_RESULT_FOE_ENDURED:
    case MOVE_RESULT_ONE_HIT_KO:
    case MOVE_RESULT_FOE_HUNG_ON:
    case MOVE_RESULT_STURDIED:
    default:
        if (moveResultFlags & MOVE_RESULT_HIGH_EFFECTIVENESS)
        {
            #if TESTING
            if (gTestRunnerEnabled)
                TestRunner_Battle_RecordEffectivenessSound(gBattlerTarget, SE_SUPER_EFFECTIVE);
            #endif
            BtlController_EmitPlaySE(gBattlerTarget, B_COMM_TO_CONTROLLER, SE_SUPER_EFFECTIVE);
            MarkBattlerForControllerExec(gBattlerTarget);
        }
        else if (moveResultFlags & MOVE_RESULT_LOW_EFFECTIVENESS)
        {
            #if TESTING
            if (gTestRunnerEnabled)
                TestRunner_Battle_RecordEffectivenessSound(gBattlerTarget, SE_NOT_EFFECTIVE);
            #endif
            BtlController_EmitPlaySE(gBattlerTarget, B_COMM_TO_CONTROLLER, SE_NOT_EFFECTIVE);
            MarkBattlerForControllerExec(gBattlerTarget);
        }
        else if (!(moveResultFlags & (MOVE_RESULT_DOESNT_AFFECT_FOE | MOVE_RESULT_FAILED)))
        {
            #if TESTING
            if (gTestRunnerEnabled)
                TestRunner_Battle_RecordEffectivenessSound(gBattlerTarget, SE_EFFECTIVE);
            #endif
            BtlController_EmitPlaySE(gBattlerTarget, B_COMM_TO_CONTROLLER, SE_EFFECTIVE);
            MarkBattlerForControllerExec(gBattlerTarget);
        }
        break;
    }

    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

static enum CancelerResult CancelerHitAnimation(struct BattleCalcValues *cv)
{
    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (ShouldSkipBattlerForDamage(cv->battlerAtk, battlerDef))
            continue;

        if (!(DoesSubstituteBlockMove(cv->battlerAtk, battlerDef, gCurrentMove))
         || gBattleMons[battlerDef].volatiles.substituteHP == 0)
        {
            BtlController_EmitHitAnimation(battlerDef, B_COMM_TO_CONTROLLER);
            MarkBattlerForControllerExec(battlerDef);
        }
    }

    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

static enum CancelerResult CancelerSkipFrame(struct BattleCalcValues *cv)
{
    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT;
}

static enum CancelerResult CancelerHealthBarUpdate(struct BattleCalcValues *cv)
{
    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (DoesSubstituteBlockMove(cv->battlerAtk, battlerDef, cv->move))
        {
            PrepareStringBattle(STRINGID_SUBSTITUTEDAMAGED, battlerDef);
            continue;
        }

        if (ShouldSkipBattlerForDamage(cv->battlerAtk, battlerDef)
         || DoesDisguiseBlockMove(battlerDef, cv->move)
         || DoesIceFaceBlockMove(battlerDef, cv->move))
            continue;

        s32 dmgUpdate = min(gBattleStruct->moveDamage[battlerDef], 10000);
        BtlController_EmitHealthBarUpdate(battlerDef, B_COMM_TO_CONTROLLER, dmgUpdate);
        MarkBattlerForControllerExec(battlerDef);
        if (IsOnPlayerSide(battlerDef) && dmgUpdate > 0)
            gBattleResults.playerMonWasDamaged = TRUE;
    }

    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT; // Update health bar
}

static bool32 TryMoveDamageUpdate(struct BattleCalcValues *cv)
{
    if (DoesSubstituteBlockMove(cv->battlerAtk, cv->battlerDef, cv->move) && gBattleMons[cv->battlerDef].volatiles.substituteHP)
    {
        if (gBattleMons[cv->battlerDef].volatiles.substituteHP >= gBattleStruct->moveDamage[cv->battlerDef])
        {
            TestRunner_Battle_RecordSubHit(cv->battlerDef, gBattleStruct->moveDamage[cv->battlerDef], FALSE);
            gBattleMons[cv->battlerDef].volatiles.substituteHP -= gBattleStruct->moveDamage[cv->battlerDef];
        }
        else
        {
            TestRunner_Battle_RecordSubHit(cv->battlerDef, gBattleMons[cv->battlerDef].volatiles.substituteHP, TRUE);
            gBattleStruct->moveDamage[cv->battlerDef] = gBattleMons[cv->battlerDef].volatiles.substituteHP;
            gBattleMons[cv->battlerDef].volatiles.substituteHP = 0;
        }
        // check substitute fading
        if (gBattleMons[cv->battlerDef].volatiles.substituteHP == 0)
        {
            gBattleScripting.battler = cv->battlerDef;
            BattleScriptCall(BattleScript_SubstituteFade);
            return TRUE;
        }
        return FALSE;
    }
    else if (DoesDisguiseBlockMove(cv->battlerDef, cv->move) || DoesIceFaceBlockMove(cv->battlerDef, cv->move))
    {
        // Damage deals typeless 0 HP.
        gBattleStruct->moveResultFlags[cv->battlerDef] &= ~(MOVE_RESULT_HIGH_EFFECTIVENESS | MOVE_RESULT_LOW_EFFECTIVENESS);
        gBattleStruct->moveDamage[cv->battlerDef] = 0;
        if (cv->moveEffect == EFFECT_OHKO)
            gProtectStructs[cv->battlerDef].survivedOHKO = TRUE;
        if (DoesIceFaceBlockMove(cv->battlerDef, cv->move))
            gProtectStructs[cv->battlerDef].assuranceDoubled = TRUE;
    }
    else
    {
        if (gBattleStruct->moveDamage[cv->battlerDef] < 0)
        {
            // Negative damage is HP gain
            gBattleMons[cv->battlerDef].hp += -gBattleStruct->moveDamage[cv->battlerDef];
            if (gBattleMons[cv->battlerDef].hp > gBattleMons[cv->battlerDef].maxHP)
                gBattleMons[cv->battlerDef].hp = gBattleMons[cv->battlerDef].maxHP;
        }
        else
        {
            u16 hpBefore;
            u16 hpLost;

            gBideDmg[cv->battlerDef] += gBattleStruct->moveDamage[cv->battlerDef];
            gBideTarget[cv->battlerDef] = cv->battlerAtk;

            // Deal damage to the battler
            hpBefore = gBattleMons[cv->battlerDef].hp;
            if (gBattleMons[cv->battlerDef].hp > gBattleStruct->moveDamage[cv->battlerDef])
            {
                if (cv->moveEffect == EFFECT_OHKO && gBattleStruct->moveResultFlags[cv->battlerDef] & MOVE_RESULT_FOE_HUNG_ON)
                {
                    gProtectStructs[cv->battlerDef].survivedOHKO = TRUE;
                }
                gBattleMons[cv->battlerDef].hp -= gBattleStruct->moveDamage[cv->battlerDef];
            }
            else
            {
                gBattleStruct->moveDamage[cv->battlerDef] = gBattleMons[cv->battlerDef].hp;
                gBattleMons[cv->battlerDef].hp = 0;
            }

            hpLost = hpBefore - gBattleMons[cv->battlerDef].hp;
            if (hpLost != 0)
                gBattleStruct->innardsOutHpLost[cv->battlerDef] += hpLost;

            gProtectStructs[cv->battlerDef].assuranceDoubled = TRUE;
            gProtectStructs[cv->battlerDef].revengeDoubled |= 1u << cv->battlerAtk;

        }
        // Send updated HP
        BtlController_EmitSetMonData(cv->battlerDef, B_COMM_TO_CONTROLLER, REQUEST_HP_BATTLE, 0, sizeof(gBattleMons[cv->battlerDef].hp), &gBattleMons[cv->battlerDef].hp);
        MarkBattlerForControllerExec(cv->battlerDef);
    }

    // Note: While physicalDmg/specialDmg below are only distinguished between for Counter/Mirror Coat,
    //       they are used in combination as general damage trackers for other purposes.
    if (GetConfig(B_COUNTER_MIRROR_COAT_ALLY) <= GEN_4 || !IsBattlerAlly(cv->battlerDef, cv->battlerAtk))
    {
        if (IsBattleMovePhysical(cv->move) || ((GetConfig(B_HIDDEN_POWER_COUNTER) < GEN_4) && cv->moveEffect == EFFECT_HIDDEN_POWER))
        {
            gProtectStructs[cv->battlerDef].physicalDmg = gBattleStruct->moveDamage[cv->battlerDef] + 1;
            gProtectStructs[cv->battlerDef].physicalBattlerId = cv->battlerAtk;
            gProtectStructs[cv->battlerDef].lastHitBySpecialMove = FALSE;
        }
        else // Special move
        {
            gProtectStructs[cv->battlerDef].specialDmg = gBattleStruct->moveDamage[cv->battlerDef] + 1;
            gProtectStructs[cv->battlerDef].specialBattlerId = cv->battlerAtk;
            gProtectStructs[cv->battlerDef].lastHitBySpecialMove = TRUE;
        }
    }

    GetBattlerPartyState(cv->battlerDef)->timesGotHit++;
    gSpecialStatuses[cv->battlerDef].damagedByAttack = TRUE;
    return FALSE;
}

static enum CancelerResult CancelerMoveDamageUpdate(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        cv->battlerDef = GetTargetBySlot(cv->battlerAtk, gBattleStruct->eventState.moveEndBattler);
        gBattleStruct->eventState.moveEndBattler++;

        if (ShouldSkipBattlerForDamage(cv->battlerAtk, cv->battlerDef))
            continue;

        if (TryMoveDamageUpdate(cv))
            return CANCELER_RESULT_RUN_SCRIPT;
    }

    cv->battlerDef = gBattlerTarget;
    gBattleStruct->eventState.moveEndBattler = 0;
    return CANCELER_RESULT_RUN_SCRIPT_AND_INCREMENT; // Update hp
}

static enum CancelerResult (*const sMoveSuccessOrderCancelers[])(struct BattleCalcValues *cv) =
{
    [CANCELER_CLEAR_FLAGS] = CancelerClearFlags,
    [CANCELER_STANCE_CHANGE_1] = CancelerStanceChangeOne,
    [CANCELER_SKY_DROP] = CancelerSkyDrop,
    [CANCELER_RECHARGE] = CancelerRecharge,
    [CANCELER_CHILLY_RECEPTION] = CancelerChillyReception,
    [CANCELER_ASLEEP_OR_FROZEN] = CancelerAsleepOrFrozen,
    [CANCELER_OBEDIENCE] = CancelerObedience,
    [CANCELER_POWER_POINTS] = CancelerPowerPoints,
    [CANCELER_TRUANT] = CancelerTruant,
    [CANCELER_FOCUS_GEN5] = CancelerFocusGen5,
    [CANCELER_FLINCH] = CancelerFlinch,
    [CANCELER_DISABLED] = CancelerDisabled,
    [CANCELER_VOLATILE_BLOCKED] = CancelerVolatileBlocked,
    [CANCELER_TAUNTED] = CancelerTaunted,
    [CANCELER_IMPRISONED] = CancelerImprisoned,
    [CANCELER_CONFUSED] = CancelerConfused,
    [CANCELER_GHOST] = CancelerGhost,
    [CANCELER_PARALYZED] = CancelerParalyzed,
    [CANCELER_INFATUATION] = CancelerInfatuation,
    [CANCELER_Z_MOVES] = CancelerZMoves,
    [CANCELER_CHOICE_LOCK] = CancelerChoiceLock,
    [CANCELER_CALLSUBMOVE] = CancelerCallSubmove,
    [CANCELER_THAW] = CancelerThaw,
    [CANCELER_STANCE_CHANGE_2] = CancelerStanceChangeTwo,
    [CANCELER_ATTACKSTRING] = CancelerAttackstring,
    [CANCELER_PLEDGE_ATTACK] = CancelerPledgeAttack,
    [CANCELER_SET_TARGETS] = CancelerSetTargets,
    [CANCELER_PPDEDUCTION] = CancelerPPDeduction,
    [CANCELER_SKY_BATTLE] = CancelerSkyBattle,
    [CANCELER_WEATHER_PRIMAL] = CancelerWeatherPrimal,
    [CANCELER_FOCUS_PRE_GEN5] = CancelerFocusPreGen5,
    [CANCELER_BIDE] = CancelerBide,
    [CANCELER_MOVE_FAILURE] = CancelerMoveFailure,
    [CANCELER_MOVE_EFFECT_FAILURE_TARGET] = CancelerMoveEffectFailureTarget,
    [CANCELER_POWDER_STATUS] = CancelerPowderStatus,
    [CANCELER_PRIORITY_BLOCK] = CancelerPriorityBlock,
    [CANCELER_EXPLODING_DAMP] = CancelerExplodingDamp,
    [CANCELER_INTERRUPTIBLE_MOVES] = CancelerInterruptibleMoves,
    [CANCELER_PROTEAN] = CancelerProtean,
    [CANCELER_CHARGING] = CancelerCharging,
    [CANCELER_SNATCH] = CancelerSnatch,
    [CANCELER_EXPLOSION] = CancelerExplosion,
    [CANCELER_MOVE_SPECIFIC_MESSAGE] = CancelerMoveSpecificMessage,
    [CANCELER_NO_TARGET] = CancelerNoTarget,
    [CANCELER_TOOK_ATTACK] = CancelerTookAttack,
    [CANCELER_TARGET_FAILURE] = CancelerTargetFailure,
    [CANCELER_MULTIHIT_MOVES] = CancelerMultihitMoves,
    [CANCELER_SUBSTITUTE] = CancelerSubstitute,
    [CANCELER_ACCURACY_CHECK] = CancelerAccuracyCheck,
    [CANCELER_PRE_ATTACK_MOVE_EFFECT] = CancelerPreAttackMoveEffect,
    [CANCELER_DAMAGE_CALC] = CancelerDamageCalc,
    [CANCELER_PRE_ANIM_ACTIVATIONS] = CancelerPreAnimActivations,
    [CANCELER_MOVE_ANIMATION] = CancelerMoveAnimation,
    [CANCELER_EFFECTIVENESS_SOUND] = CancelerEffectivenessSound,
    [CANCELER_HIT_ANIMATION] = CancelerHitAnimation,
    [CANCELER_SKIP_FRAME] = CancelerSkipFrame,
    [CANCELER_HEALTH_BAR_UPDATE] = CancelerHealthBarUpdate,
    [CANCELER_MOVE_DAMAGE_UPDATE] = CancelerMoveDamageUpdate,
};

enum CancelerResult DoAttackCanceler(void)
{
    enum CancelerResult result = CANCELER_RESULT_SUCCESS;

    struct BattleCalcValues cv = {
        .battlerAtk = gBattlerAttacker,
        .battlerDef = gBattlerTarget,
        .move = gCurrentMove,
    };

    cv.moveEffect = GetMoveEffect(cv.move);
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        cv.abilities[battler] = GetBattlerAbility(battler);
        cv.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }

    while (gBattleStruct->eventState.atkCanceler < CANCELER_END && result == CANCELER_RESULT_SUCCESS)
    {
        result = sMoveSuccessOrderCancelers[gBattleStruct->eventState.atkCanceler](&cv);

        if (result != CANCELER_RESULT_RUN_SCRIPT)
            gBattleStruct->eventState.atkCanceler++;
    }

    if (result == CANCELER_RESULT_FAILURE)
    {
        gBattleStruct->unableToUseMove = TRUE;
        gBattleStruct->pledgeState = PLEDGE_COMBO_NONE;
        gBattleStruct->eventState.atkCanceler = CANCELER_END;
    }

    return result;
}

// ========
// Move End
// ========

static enum MoveEndResult MoveEndSetValues(struct BattleCalcValues *cv)
{
    gBattleScripting.savedDmg += gBattleStruct->moveDamage[cv->battlerDef];
    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleStruct->eventState.moveEndBlock = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static bool32 GetProtectBypassMethod(enum BattlerId battlerDef, enum Ability abilityAtk)
{
    if (IsBattlerUnaffectedByMove(battlerDef))
        return PROTECT_BYPASS_NONE;
    if (MoveIgnoresProtect(gCurrentMove))
        return PROTECT_BYPASS_MOVE_IGNORES;
    if (gSpecialStatuses[battlerDef].breaksThroughProtectFully)
        return PROTECT_BYPASS_ABILITY_IGNORES;
    if (!IsZMove(gCurrentMove) && !IsMaxMove(gCurrentMove))
        return PROTECT_BYPASS_NONE;
    if (GetProtectType(gProtectStructs[battlerDef].protected) == PROTECT_TYPE_SINGLE
        && gProtectStructs[battlerDef].protected != PROTECT_MAX_GUARD)
        return PROTECT_BYPASS_OTHER;
    return PROTECT_BYPASS_MOVE_IGNORES;
}

static enum MoveEndResult MoveEndProtectBypassEffects(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum Ability abilityAtk = cv->abilities[cv->battlerAtk];
    enum ProtectBypass protectBypassMethod = GetProtectBypassMethod(cv->battlerDef, abilityAtk);

    switch (protectBypassMethod)
    {
        case PROTECT_BYPASS_ABILITY_IGNORES:
            BattleScriptCall(BattleScript_UnseenFist);
            result = MOVEEND_RESULT_RUN_SCRIPT;
            break;
        case PROTECT_BYPASS_OTHER:
            BattleScriptCall(BattleScript_CouldntFullyProtect);
            result = MOVEEND_RESULT_RUN_SCRIPT;
            break;
        default:
            break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndProtectLikeEffect(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum ProtectMethod method = gProtectStructs[cv->battlerDef].protected;

    if (gProtectStructs[cv->battlerAtk].chargingTurn
     || !IsBattlerAlive(cv->battlerAtk)
     || CanBattlerAvoidContactEffects(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move))
    {
        gBattleScripting.moveendState++;
        return result;
    }

    if (gSpecialStatuses[cv->battlerDef].breaksThroughProtectFully && GetConfig(B_UNSEEN_FIST_PIERCING_DRILL) <= GEN_9)
    {
        gBattleScripting.moveendState++;
        return result;
    }

    if (gBattleStruct->unableToUseMove)
    {
        gBattleScripting.moveendState++;
        return result;
    }

    switch (method)
    {
    case PROTECT_SPIKY_SHIELD:
        if (!IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
        {
            SetPassiveDamageAmount(cv->battlerAtk, GetNonDynamaxMaxHP(cv->battlerAtk) / 8);
            PREPARE_MOVE_BUFFER(gBattleTextBuff1, MOVE_SPIKY_SHIELD);
            BattleScriptCall(BattleScript_SpikyShieldEffect);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case PROTECT_KINGS_SHIELD:
    {
        s32 stage = (B_KINGS_SHIELD_LOWER_ATK >= GEN_8) ? -1 : -2;
        gEffectBattler = gBattlerAttacker;
        SetStatChange(gEffectBattler, STAT_ATK, stage);
        BattleScriptCall(BattleScript_KingsShieldEffect);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break;
    }
    case PROTECT_BANEFUL_BUNKER:
        if (CanBePoisoned(cv->battlerDef, cv->battlerAtk, cv->abilities[cv->battlerDef], cv->abilities[cv->battlerAtk]))
        {
            gBattleScripting.moveEffect = MOVE_EFFECT_POISON;
            BattleScriptCall(BattleScript_BanefulBunkerEffect);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case PROTECT_BURNING_BULWARK:
        if (CanBeBurned(cv->battlerDef, cv->battlerAtk, cv->abilities[cv->battlerAtk]))
        {
            gBattleScripting.moveEffect = MOVE_EFFECT_BURN;
            BattleScriptCall(BattleScript_BanefulBunkerEffect);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case PROTECT_OBSTRUCT:
        gEffectBattler = gBattlerAttacker;
        SetStatChange(gEffectBattler, STAT_DEF, -2);
        BattleScriptCall(BattleScript_KingsShieldEffect);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break;
    case PROTECT_SILK_TRAP:
        gEffectBattler = gBattlerAttacker;
        SetStatChange(gEffectBattler, STAT_SPEED, -1);
        BattleScriptCall(BattleScript_KingsShieldEffect);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break;
    default:
        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAbsorb(struct BattleCalcValues *cv)
{
    if (gBattleStruct->unableToUseMove)
    {
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_CONTINUE;
    }

    if (IsExplosionMove(cv->move)
     && !IsBattlerAlive(cv->battlerAtk)
     && !gBattleStruct->battlerState[cv->battlerAtk].notOnField)
    {
        gBattleStruct->passiveHpUpdate[cv->battlerAtk] = 0;
        BattleScriptCall(BattleScript_FaintAttackerForExplosion);
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_RUN_SCRIPT;
    }

    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    switch (cv->moveEffect)
    {
    case EFFECT_STRENGTH_SAP:
        if (gBattleStruct->passiveHpUpdate[cv->battlerAtk] > 0 && !IsBattlerUnaffectedByMove(cv->battlerDef))
        {
            s32 healAmount = gBattleStruct->passiveHpUpdate[cv->battlerAtk];
            healAmount = GetDrainedBigRootHp(cv->battlerAtk, healAmount);
            gEffectBattler = cv->battlerAtk;

            if (cv->abilities[cv->battlerDef] == ABILITY_LIQUID_OOZE)
            {
                SetPassiveDamageAmount(cv->battlerAtk, healAmount);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB_OOZE;
                gBattlerAbility = gBattleScripting.battler = cv->battlerDef;
                BattleScriptCall(BattleScript_EffectAbsorbLiquidOoze);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
            else if (!IsBattlerAtMaxHp(cv->battlerAtk) || GetConfig(B_ABSORB_MESSAGE) < GEN_5)
            {
                SetHealAmount(cv->battlerAtk, healAmount);
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB;
                gEffectBattler = cv->battlerAtk;
                BattleScriptCall(BattleScript_EffectAbsorb);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
        }
        break;
    case EFFECT_MAX_HP_50_RECOIL:
        if (IsBattlerAlive(cv->battlerAtk)
         && !gBattleStruct->unableToUseMove
         && !gSpecialStatuses[cv->battlerAtk].mindBlownRecoil
         && !IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
        {
            s32 recoil = (GetNonDynamaxMaxHP(cv->battlerAtk) + 1) / 2; // Half of Max HP Rounded UP
            SetPassiveDamageAmount(cv->battlerAtk, recoil);
            gSpecialStatuses[cv->battlerAtk].mindBlownRecoil = TRUE;
            TryUpdateEvolutionTracker(IF_RECOIL_DAMAGE_GE, gBattleStruct->passiveHpUpdate[cv->battlerAtk], MOVE_NONE);
            BattleScriptCall(BattleScript_MaxHp50Recoil);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    default:
        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndRage(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleMons[cv->battlerDef].volatiles.rage
     && IsBattlerAlive(cv->battlerDef)
     && cv->battlerAtk != cv->battlerDef
     && !IsBattlerAlly(cv->battlerAtk, cv->battlerDef)
     && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
     && !IsBattleMoveStatus(cv->move)
     && CompareStat(cv->battlerDef, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, cv->abilities[cv->battlerDef]))
    {
        // Does rage show any anim or does it just increase by one and print the rage message?
        SetStatChange(gBattlerTarget, STAT_ATK, 1);
        BattleScriptCall(BattleScript_RageIsBuilding);
        result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndBeakBlast(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (IsBattlerUsingBeakBlast(cv->battlerDef)
     && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
     && IsMoveMakingContact(cv->battlerAtk, cv->battlerDef, cv->abilities[cv->battlerAtk], cv->holdEffects[cv->battlerAtk], cv->move)
     && CanBeBurned(cv->battlerAtk, cv->battlerAtk, cv->abilities[cv->battlerAtk]))
    {
        gBattleMons[cv->battlerAtk].status1 = STATUS1_BURN;
        BtlController_EmitSetMonData(cv->battlerAtk, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[cv->battlerAtk].status1), &gBattleMons[cv->battlerAtk].status1);
        MarkBattlerForControllerExec(cv->battlerAtk);
        BattleScriptCall(BattleScript_BeakBlastBurn);
        result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAbilities(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum Ability targetAbility = cv->abilities[cv->battlerDef];

    if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END, cv->battlerDef, targetAbility, 0, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;
    else if (TryClearIllusion(cv->battlerDef, targetAbility))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndResistBerryMessage(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gSpecialStatuses[cv->battlerDef].berryReduced
     && !gSpecialStatuses[cv->battlerDef].berryReducedMessagePrinted)
    {
        gBattleScripting.battler = cv->battlerDef;
        gLastUsedItem = gBattleMons[cv->battlerDef].item;
        GetBattlerPartyState(cv->battlerDef)->ateBerry = TRUE;
        gSpecialStatuses[cv->battlerDef].berryReducedMessagePrinted = TRUE;
        BattleScriptCall(BattleScript_BerryReduceDmg);
        result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndFormChangeOnHit(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_FORM_CHANGE_ON_HIT, cv->battlerDef, cv->abilities[cv->battlerDef], 0, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAbilitiesAttacker(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END_ATTACKER, cv->battlerAtk, 0, 0, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndQueueDancer(struct BattleCalcValues *cv)
{
    if (!IsDanceMove(cv->move)
     || IsBattlerUnaffectedByMove(cv->battlerDef)
     || gBattleStruct->unableToUseMove
     || gSpecialStatuses[cv->battlerAtk].dancerUsedMove
     || gBattleStruct->snatchedMoveIsUsed
     || gBattleStruct->bouncedMoveIsUsed)
    {
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_CONTINUE;
    }

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (battler == cv->battlerAtk)
            continue;

        if (cv->abilities[battler] == ABILITY_DANCER)
            gBattleMons[battler].volatiles.activateDancer = TRUE;
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndStatusImmunityAbilities(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, battler, 0, 0, TRUE))
            result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    if (result == MOVEEND_RESULT_CONTINUE)
        gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAttackerInvisible(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (IsSemiInvulnerable(cv->battlerAtk, CHECK_ALL)
     && gHitMarker & (HITMARKER_NO_ANIMATIONS | HITMARKER_DISABLE_ANIMATION))
    {
        BtlController_EmitSpriteInvisibility(cv->battlerAtk, B_COMM_TO_CONTROLLER, TRUE);
        MarkBattlerForControllerExec(cv->battlerAtk);
        result = MOVEEND_RESULT_BREAK;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAttackerVisible(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (IsBattlerUnaffectedByMove(cv->battlerDef)
        || !IsSemiInvulnerable(cv->battlerAtk, CHECK_ALL)
        || (gBattleStruct->unableToUseMove && gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable != STATE_SKY_DROP_TARGET))
    {
        BtlController_EmitSpriteInvisibility(cv->battlerAtk, B_COMM_TO_CONTROLLER, FALSE);
        MarkBattlerForControllerExec(cv->battlerAtk);
        gBattleMons[cv->battlerAtk].volatiles.semiInvulnerable = STATE_NONE;
        gSpecialStatuses[cv->battlerAtk].restoredBattlerSprite = TRUE;
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_BREAK;
    }
    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndTargetVisible(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (!gSpecialStatuses[cv->battlerDef].restoredBattlerSprite
     && cv->battlerDef < gBattlersCount
     && !IsSemiInvulnerable(cv->battlerDef, CHECK_ALL))
    {
        BtlController_EmitSpriteInvisibility(cv->battlerDef, B_COMM_TO_CONTROLLER, FALSE);
        MarkBattlerForControllerExec(cv->battlerDef);
        gSpecialStatuses[cv->battlerDef].restoredBattlerSprite = TRUE;
        gBattleMons[cv->battlerDef].volatiles.semiInvulnerable = STATE_NONE;
        result = MOVEEND_RESULT_BREAK;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemEffectsTarget(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum HoldEffect holdEffect = cv->holdEffects[cv->battlerDef];

    if (ItemBattleEffects(cv->battlerDef, cv->battlerAtk, holdEffect, IsOnTargetHitActivation)
     || ItemBattleEffects(cv->battlerDef, cv->battlerAtk, holdEffect, IsOnStatusChangeActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemEffectsAttacker1(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum HoldEffect holdEffect = cv->holdEffects[cv->battlerAtk];

    if (ItemBattleEffects(cv->battlerAtk, cv->battlerDef, holdEffect, IsOnAttackerAfterHitActivation)
     || ItemBattleEffects(cv->battlerAtk, cv->battlerDef, holdEffect, IsOnStatusChangeActivation)
     || ItemBattleEffects(cv->battlerAtk, cv->battlerDef, holdEffect, IsOnHpThresholdActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSymbiosis(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if ((gSpecialStatuses[battler].berryReduced
              || (GetConfig(B_SYMBIOSIS_GEMS) >= GEN_7 && gSpecialStatuses[battler].gemBoost))
            && TryTriggerSymbiosis(battler, GetPartnerBattler(battler)))
        {
            BestowItem(GetPartnerBattler(battler), battler);
            gSpecialStatuses[battler].berryReduced = FALSE;
            gLastUsedAbility = gBattleMons[GetPartnerBattler(battler)].ability;
            gEffectBattler = battler;
            gBattleScripting.battler = gBattlerAbility = GetPartnerBattler(battler);
            BattleScriptPushCursor();
            gBattlescriptCurrInstr = BattleScript_SymbiosisActivates;
            result = MOVEEND_RESULT_RUN_SCRIPT;
            break;
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSubstitute(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (gBattleMons[i].volatiles.substituteHP == 0)
            gBattleMons[i].volatiles.substitute = FALSE;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndFaintBlock(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    do
    {
        switch (gBattleStruct->eventState.moveEndBlock)
        {
        case FAINT_BLOCK_FINAL_GAMBIT:
            if (cv->moveEffect == EFFECT_FINAL_GAMBIT
             && IsBattlerAlive(cv->battlerAtk)
             && !gBattleStruct->unableToUseMove
             && !IsBattlerUnaffectedByMove(cv->battlerDef))
            {
                BattleScriptCall(BattleScript_FinalGambit);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_CHECK_TARGET_FAINTED: // Stop if target already ran the block / is alive or absent
            if (IsBattlerAlive(cv->battlerDef)
             || cv->battlerDef >= gBattlersCount
             || (gAbsentBattlerFlags & 1u << cv->battlerDef)
             || gBattleStruct->battlerState[cv->battlerDef].notOnField)
            {
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_CONTINUE;
            }

            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_VICTORY_CATCH:
            if (IsVictoryCatch()
             && gBattleStruct->victoryCatchState != VICTORY_CATCH_FAINTED
             && !IsOnPlayerSide(gBattlerTarget))
            {
                u8 hp = 1;
                SetMonData(GetBattlerMon(gBattlerTarget), MON_DATA_HP, &hp);
                BattleScriptCall(BattleScript_WildBattleVictory);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_END_NEUTRALIZING_GAS:
            if (gBattleMons[cv->battlerDef].volatiles.neutralizingGas)
            {
                gBattleMons[cv->battlerDef].volatiles.neutralizingGas = FALSE;
                if (!IsNeutralizingGasOnField())
                {
                    BattleScriptCall(BattleScript_NeutralizingGasExits);
                    result = MOVEEND_RESULT_RUN_SCRIPT;
                }
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_DO_GRUDGE:
            if (gBattleMons[cv->battlerDef].volatiles.grudge
             && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(cv->battlerAtk)
             && !IsBattlerAlly(cv->battlerAtk, cv->battlerDef)
             && !IsZMove(cv->move)
             && cv->move != MOVE_STRUGGLE
             && cv->moveEffect != EFFECT_FUTURE_SIGHT)
            {
                u32 moveIndex = gBattleStruct->chosenMovePositions[cv->battlerAtk];

                gBattleMons[cv->battlerAtk].pp[moveIndex] = 0;
                BtlController_EmitSetMonData(cv->battlerAtk, B_COMM_TO_CONTROLLER, moveIndex + REQUEST_PPMOVE1_BATTLE, 0, sizeof(gBattleMons[cv->battlerAtk].pp[moveIndex]), &gBattleMons[cv->battlerAtk].pp[moveIndex]);
                MarkBattlerForControllerExec(cv->battlerAtk);
                PREPARE_MOVE_BUFFER(gBattleTextBuff1, gBattleMons[cv->battlerAtk].moves[moveIndex])
                BattleScriptCall(BattleScript_GrudgeTakesPP);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_TRY_DESTINY_BOND: // Checked before FAINT_BLOCK_FAINT_TARGET but occurs after since volatiles are cleared on faint
            if (gBattleMons[cv->battlerDef].volatiles.destinyBond
             && IsBattlerTurnDamaged(cv->battlerDef, EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(cv->battlerAtk)
             && GetActiveGimmick(cv->battlerAtk) != GIMMICK_DYNAMAX
             && !IsBattlerAlly(cv->battlerAtk, cv->battlerDef))
            {
                gBattleStruct->passiveHpUpdate[cv->battlerAtk] = gBattleMons[cv->battlerAtk].hp;
                BattleScriptCall(BattleScript_DestinyBondTakesLife);
                // Hack: don't change result here so that Faint Target's script plays first
            }
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_FAINT_TARGET:
            TryUpdateEvolutionTracker(IF_DEFEAT_X_WITH_ITEMS, 1, MOVE_NONE);
            SetValuesOnFaint(cv->battlerDef);
            BattleScriptCall(BattleScript_FaintBattler);
            result = MOVEEND_RESULT_RUN_SCRIPT;
            gBattleStruct->eventState.moveEndBlock++;
            break;
        case FAINT_BLOCK_COUNT:
            break;
        }

        if (result == MOVEEND_RESULT_RUN_SCRIPT)
            break;

    } while (gBattleStruct->eventState.moveEndBlock < FAINT_BLOCK_COUNT);

    if (result == MOVEEND_RESULT_CONTINUE)
    {
        gBattleStruct->eventState.moveEndBlock = 0;
        gBattleScripting.moveendState++;
    }

    return result;
}

static enum MoveEndResult MoveEndUpdateLastMoves(struct BattleCalcValues *cv)
{
    if (!IsOnPlayerSide(cv->battlerAtk))
        UpdateStallMons(cv);

    if (gBattleStruct->snatchedMoveIsUsed)
    {
        RestoreAttacker();
        RestoreTarget();
    }

    enum BattleMoveEffects originalEffect = GetMoveEffect(GetOriginallyUsedMove(gChosenMove));
    if (IsBattlerAlive(cv->battlerAtk) // Why do we need to check if user fainted? We just want to set with what move the target got hit
     && originalEffect != EFFECT_BATON_PASS
     && originalEffect != EFFECT_HEALING_WISH
     && originalEffect != EFFECT_LUNAR_DANCE)
    {
        if (!gBattleStruct->unableToUseMove)
        {
            if (!gSpecialStatuses[cv->battlerAtk].dancerUsedMove)
            {
                gLastMoves[cv->battlerAtk] = gChosenMove;
                gLastResultingMoves[cv->battlerAtk] = cv->move;
                gLastUsedMoveType[cv->battlerAtk] = GetBattleMoveType(cv->move);
            }
        }
        else
        {
            gLastResultingMoves[cv->battlerAtk] = MOVE_UNAVAILABLE;
            gLastUsedMoveType[cv->battlerAtk] = 0;
        }

        if (IsBattlerAlive(cv->battlerDef))
            gLastHitBy[cv->battlerDef] = cv->battlerAtk; // Used by switch AI only

        if (!gBattleStruct->unableToUseMove
         && !IsBattlerUnaffectedByMove(cv->battlerDef)
         && gChosenMove != MOVE_UNAVAILABLE
         && !gSpecialStatuses[cv->battlerAtk].dancerUsedMove)
        {
            gLastUsedMove = cv->move;
            if (IsMaxMove(cv->move))
                gBattleStruct->dynamax.lastUsedBaseMove = gBattleStruct->dynamax.baseMoves[cv->battlerAtk];
        }

        if (!gBattleStruct->unableToUseMove
         && !IsBattlerUnaffectedByMove(cv->battlerDef)
         && IsBattlerAlive(cv->battlerDef))
        {
            if (gChosenMove == MOVE_UNAVAILABLE)
            {
                gLastLandedMoves[cv->battlerDef] = gChosenMove;
            }
            else
            {
                gLastLandedMoves[cv->battlerDef] = cv->move;
                gLastHitByType[cv->battlerDef] = GetBattleMoveType(cv->move);
            }
        }
        else
        {
            gLastHitByType[cv->battlerDef] = TYPE_MYSTERY;
            gLastLandedMoves[cv->battlerDef] = MOVE_UNAVAILABLE;
        }
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndMirrorMove(struct BattleCalcValues *cv)
{
    if (!gBattleStruct->unableToUseMove
     && cv->battlerAtk != cv->battlerDef
     && IsBattlerAlive(cv->battlerAtk)
     && IsBattlerAlive(cv->battlerDef)
     && !IsMoveMirrorMoveBanned(GetOriginallyUsedMove(gChosenMove)))
    {
        gBattleStruct->lastTakenMove[cv->battlerDef] = gChosenMove;
        gBattleStruct->lastTakenMoveFrom[cv->battlerDef][cv->battlerAtk] = gChosenMove;
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

// Used for non damaging (status) stat change moves
bool32 IsStatChangeMove(enum Move move)
{
    u32 additionalEffectCount = GetMoveAdditionalEffectCount(move);
    for (u32 i = 0; i < additionalEffectCount; i++)
    {
        const struct AdditionalEffect *additionalEffect = GetMoveAdditionalEffectById(move, i);
        switch (additionalEffect->moveEffect)
        {
        case STAT_CHANGE_EFFECT_MINUS:
        case STAT_CHANGE_EFFECT_PLUS:
           return TRUE;
        default:
           return FALSE;
        }
    }
    return FALSE;
}

static enum MoveEndResult MoveEndNextTarget(struct BattleCalcValues *cv)
{
    enum MoveTarget moveTarget = GetBattlerMoveTargetType(gBattlerAttacker, gCurrentMove);

    gBattleStruct->battlerState[gBattlerAttacker].targetsDone[gBattlerTarget] = TRUE;

    if (gBattleStruct->unableToUseMove || gProtectStructs[gBattlerAttacker].chargingTurn)
    {
        // unable to use move
    }
    else if (moveTarget == TARGET_USER_AND_ALLY)
    {
        enum BattlerId partner = GetPartnerBattler(gBattlerAttacker);
        if (partner != gBattlerTarget && IsBattlerAlive(partner))
        {
            gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = partner;
            gBattleScripting.moveendState = 0;

            if (IsStatChangeMove(cv->move))
                return MOVEEND_RESULT_CONTINUE;
            else
                BattleScriptPush(GetMoveBattleScript(cv->move));

            gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
            return MOVEEND_RESULT_BREAK;
        }
    }
    else if (IsSpreadMove(moveTarget))
    {
        u32 nextTarget = GetNextTarget(moveTarget, FALSE);

        if (nextTarget != MAX_BATTLERS_COUNT)
        {
            // no point in writting
            gBattleStruct->moveTarget[gBattlerAttacker] = gBattlerTarget = nextTarget; // Fix for moxie spread moves
            gBattleScripting.moveendState = 0;

            if (IsStatChangeMove(cv->move))
                return MOVEEND_RESULT_CONTINUE;
            else
                BattleScriptPush(GetMoveBattleScript(cv->move));

            gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
            return MOVEEND_RESULT_BREAK;
        }
    }

    RecordLastUsedMoveBy(gBattlerAttacker, gCurrentMove);
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndBouncedMove(struct BattleCalcValues *cv)
{
    if (gBattleStruct->bouncedMoveIsUsed)
    {
        gBattleScripting.moveendState++;
        return MOVEEND_RESULT_CONTINUE;
    }

    if (gBattleStruct->magicBouncePending || gBattleStruct->magicCoatPending)
    {
        enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);

        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
        {
            u32 bounceBattler = gBattlersByRawSpeed[battler];

            if (gBattleStruct->magicBouncePending & 1u << bounceBattler)
            {
                gBattlerAbility = bounceBattler;
                gBattlescriptCurrInstr = GetMoveBattleScript(gCurrentMove);
                BattleScriptCall(BattleScript_MagicBounce);
            }
            else if (gBattleStruct->magicCoatPending & 1u << bounceBattler)
            {
                gBattlescriptCurrInstr = GetMoveBattleScript(gCurrentMove);
                BattleScriptCall(BattleScript_MagicCoat);
            }
            else
            {
                continue;
            }

            if (moveTarget == TARGET_OPPONENTS_FIELD)
            {
                gBattleStruct->magicBouncePending = 0;
                gBattleStruct->magicCoatPending = 0;
            }
            else
            {
                gBattleStruct->magicBouncePending &= ~(1u << bounceBattler);
                gBattleStruct->magicCoatPending &= ~(1u << bounceBattler);
            }

            SaveBattlerAttacker(cv->battlerAtk);
            SaveBattlerTarget(cv->battlerDef);
            gBattlerTarget = cv->battlerAtk;
            gBattlerAttacker = bounceBattler;
            gBattleStruct->bouncedMoveIsUsed = TRUE;
            for (enum BattlerId i = B_BATTLER_0; i < gBattlersCount; i++)
            {
                gBattleStruct->savedMoveResultFlags[i] = gBattleStruct->moveResultFlags[i];
                gBattleStruct->battlerState[cv->battlerAtk].targetsDone[i] = FALSE;
            }

            ClearDamageCalcResults();
            gBattleStruct->eventState.atkCanceler = CANCELER_SET_TARGETS;
            gBattleStruct->eventState.atkCancelerBattler = 0;
            gBattleStruct->moveTarget[cv->battlerAtk] = cv->battlerDef;
            gBattleScripting.moveendState = 0;
            gBattleScripting.animTurn = 0;
            gBattleScripting.animTargetsHit = 0;

            return MOVEEND_RESULT_RUN_SCRIPT;
        }
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndHpThresholdItemsTarget(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gMultiHitCounter &&
        ItemBattleEffects(cv->battlerDef, cv->battlerAtk, cv->holdEffects[cv->battlerDef], IsOnHpThresholdActivation))
    {
        result = MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndMultihitMove(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (!IsBattlerUnaffectedByMove(cv->battlerDef)
     && !gBattleStruct->unableToUseMove
     && gMultiHitCounter)
    {
        enum MoveTarget target = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
        gMultiHitCounter--;
        if (!IsBattlerAlive(cv->battlerDef) && target != TARGET_SMART)
            gMultiHitCounter = 0;

        gBattleScripting.multihitString[4]++;
        if (gMultiHitCounter == 0)
        {
            if (target != TARGET_SMART) // Dragon Darts doesn't print hit x times message
            {
                BattleScriptCall(BattleScript_MultiHitPrintStrings);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
        }
        else
        {
            if (target == TARGET_SMART
             && !IsAffectedByFollowMe(cv->battlerAtk, GetBattlerSide(cv->battlerDef), cv->move)
             && !(gBattleStruct->moveResultFlags[GetPartnerBattler(cv->battlerDef)] & MOVE_RESULT_MISSED) // didn't miss the other target
             && CanTargetPartner(cv->battlerAtk, cv->battlerDef)
             && !IsBattlerUnaffectedByMove(GetPartnerBattler(cv->battlerDef)))
                gBattlerTarget = cv->battlerDef = GetPartnerBattler(cv->battlerDef); // Target the partner in doubles for second hit.

            enum BattleMoveEffects chosenEffect = GetMoveEffect(gChosenMove);

            if (gBattleMons[cv->battlerAtk].hp
             && gBattleMons[cv->battlerDef].hp
             && (IsUsableWhileAsleepEffect(chosenEffect) || !(gBattleMons[cv->battlerAtk].status1 & STATUS1_SLEEP))
             && !(gBattleMons[cv->battlerAtk].status1 & STATUS1_FREEZE))
            {
                if (gSpecialStatuses[cv->battlerAtk].parentalBondState)
                    gSpecialStatuses[cv->battlerAtk].parentalBondState--;

                gBattleStruct->eventState.atkCanceler = CANCELER_ACCURACY_CHECK;
                gBattleStruct->eventState.atkCancelerBattler = 0;
                gBattleStruct->battlerState[cv->battlerAtk].targetsDone[cv->battlerDef] = FALSE;
                gBattleScripting.animTargetsHit = 0;
                gBattleScripting.moveendState = 0;
                gSpecialStatuses[cv->battlerAtk].multiHitOn = TRUE;
                BattleScriptPush(GetMoveBattleScript(cv->move));
                gBattlescriptCurrInstr = BattleScript_FlushMessageBox;
                return MOVEEND_RESULT_BREAK;
            }
            else if (target != TARGET_SMART) // Dragon Darts doesn't print hit x times message
            {
                BattleScriptCall(BattleScript_MultiHitPrintStrings);
                result = MOVEEND_RESULT_RUN_SCRIPT;
            }
        }
    }

    gMultiHitCounter = 0;
    gSpecialStatuses[cv->battlerAtk].parentalBondState = PARENTAL_BOND_OFF;
    gSpecialStatuses[cv->battlerAtk].multiHitOn = 0;
    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndDefrost(struct BattleCalcValues *cv)
{
    const u8 *battleScript = NULL;

    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;

        if (battler == gBattlerAttacker)
            continue;

        if (!(gBattleMons[battler].status1 & STATUS1_ICY_ANY)
         || !IsBattlerTurnDamaged(battler, EXCLUDING_SUBSTITUTES)
         || !IsBattlerAlive(battler))
            continue;

        if (gBattleMons[battler].status1 & STATUS1_FREEZE)
            battleScript = BattleScript_BattlerDefrosted;
        else
            battleScript = BattleScript_BattlerFrostbiteHealed;

        if ((CanFireMoveThawTarget(cv->move, GetBattleMoveType(cv->move)) || CanBurnHitThaw(cv->move)) && gBattleMons[battler].status1 & STATUS1_FREEZE)
        {
            DefrostBattler(battler, gBattleMons[battler].status1);
            BattleScriptCall(battleScript);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
            return MOVEEND_RESULT_RUN_SCRIPT;
        }
        else if (IsBattlerAlive(cv->battlerAtk)
              && CanMoveThawTarget(cv->abilities[cv->battlerAtk], cv->move))
        {
            DefrostBattler(battler, gBattleMons[battler].status1);
            BattleScriptCall(battleScript);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_DEFROSTED;
            return MOVEEND_RESULT_RUN_SCRIPT;
        }
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndMoveBlockRecoil(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    switch (cv->moveEffect)
    {
    case EFFECT_RECOIL_IF_MISS:
        if (IsBattlerAlive(cv->battlerAtk)
         && IsBattlerUnaffectedByMove(cv->battlerDef)
         && !gBattleStruct->unableToUseMove)
        {
            s32 recoil = 0;
            if (B_CRASH_IF_TARGET_IMMUNE == GEN_4 && gBattleStruct->moveResultFlags[cv->battlerDef] & MOVE_RESULT_DOESNT_AFFECT_FOE)
            {
                recoil = GetNonDynamaxMaxHP(cv->battlerDef) / 2;
            }
            if (B_RECOIL_IF_MISS_DMG >= GEN_5)
            {
                recoil = GetNonDynamaxMaxHP(cv->battlerAtk) / 2;
            }
            else if (B_RECOIL_IF_MISS_DMG >= GEN_3)
            {
                if ((GetNonDynamaxMaxHP(cv->battlerDef) / 2) < gBattleStruct->moveDamage[cv->battlerDef])
                    recoil = gBattleStruct->moveDamage[cv->battlerDef];
                else
                    recoil = GetNonDynamaxMaxHP(cv->battlerDef) / 2;
            }
            else if (B_RECOIL_IF_MISS_DMG == GEN_2)
            {
                recoil = gBattleStruct->moveDamage[cv->battlerDef] / 8;
            }
            else
            {
                recoil = 1;
            }
            SetPassiveDamageAmount(cv->battlerAtk, recoil);
            BattleScriptCall(BattleScript_RecoilIfMiss);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_RECOIL:
        if (gBattleStruct->moveDamage[cv->battlerDef] == 0)
            break;
        // fallthrough
    case EFFECT_CHLOROBLAST:
        if (IsBattlerTurnDamaged(cv->battlerDef, INCLUDING_SUBSTITUTES) && IsBattlerAlive(cv->battlerAtk))
        {
            if (IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_ROCK_HEAD)
             || IsAbilityAndRecord(cv->battlerAtk, cv->abilities[cv->battlerAtk], ABILITY_MAGIC_GUARD))
                break;

            if (cv->moveEffect == EFFECT_CHLOROBLAST)
            {
                s32 recoil = (GetNonDynamaxMaxHP(cv->battlerAtk) + 1) / 2; // Half of Max HP Rounded UP
                SetPassiveDamageAmount(cv->battlerAtk, recoil);
            }
            else
            {
                SetPassiveDamageAmount(cv->battlerAtk, gBattleScripting.savedDmg * max(1, GetMoveRecoil(cv->move)) / 100);
            }
            TryUpdateEvolutionTracker(IF_RECOIL_DAMAGE_GE, gBattleStruct->passiveHpUpdate[cv->battlerAtk], MOVE_NONE);
            BattleScriptCall(BattleScript_MoveEffectRecoil);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    default:
        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSheerForce(struct BattleCalcValues *cv)
{
    if (IsSheerForceAffected(cv->move, cv->abilities[cv->battlerAtk]))
        gBattleScripting.moveendState = MOVEEND_ITEMS_EFFECTS_ALL;
    else
        gBattleScripting.moveendState++;

    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndMoveBlock(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum BattleSide side = GetBattlerSide(cv->battlerDef);

    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {

        enum BattlerId battlerDef = gEffectBattler = GetTargetBySlot(cv->battlerAtk, gBattleStruct->eventState.moveEndBattler);
        gBattleStruct->eventState.moveEndBattler++;

        if (battlerDef == cv->battlerAtk)
            continue;

        switch (cv->moveEffect)
        {
        case EFFECT_SPIT_UP:
        case EFFECT_SWALLOW:
            if (!gBattleStruct->unableToUseMove)
            {
                gBattleMons[cv->battlerAtk].volatiles.stockpileCounter = 0;

                if (gBattleMons[cv->battlerAtk].volatiles.stockpileDef > 0)
                {
                    SetStatChange(gBattlerAttacker, STAT_DEF, -1 * gBattleMons[gBattlerAttacker].volatiles.stockpileDef);
                    gBattleMons[gBattlerAttacker].volatiles.stockpileDef = 0;
                }
                if (gBattleMons[gBattlerAttacker].volatiles.stockpileSpDef > 0)
                {
                    SetStatChange(gBattlerAttacker, STAT_SPDEF, -1 * gBattleMons[gBattlerAttacker].volatiles.stockpileSpDef);
                    gBattleMons[gBattlerAttacker].volatiles.stockpileSpDef = 0;
                }

                BattleScriptCall(BattleScript_MoveEffectStockpileWoreOff);
                gBattleStruct->eventState.moveEndBattler = 0;
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_KNOCK_OFF:
            if (gBattleMons[battlerDef].item != ITEM_NONE
             && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
             && !(B_KNOCK_OFF_REMOVAL >= GEN_5 && side == B_SIDE_PLAYER && !(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
             && CanBattlerGetOrLoseItem(battlerDef, cv->battlerAtk, gBattleMons[battlerDef].item)
             && !NoAliveMonsForEitherParty())
            {
                if (!IsBattlerAlive(cv->battlerAtk) && GetConfig(B_FAINT_MOVE_EFFECT_TIMING) < GEN_CHAMPIONS)
                    break;

                if (cv->abilities[battlerDef] == ABILITY_STICKY_HOLD)
                {
                    gBattlerAbility = battlerDef;
                    BattleScriptCall(BattleScript_StickyHoldActivatesRet);
                    return MOVEEND_RESULT_RUN_SCRIPT;
                    break;
                }

                gLastUsedItem = gBattleMons[battlerDef].item;
                gBattleMons[battlerDef].item = ITEM_NONE;
                if (gBattleMons[battlerDef].ability != ABILITY_GORILLA_TACTICS)
                    gBattleStruct->choicedMove[battlerDef] = MOVE_NONE;
                CheckSetUnburden(battlerDef);

                // In Gen 5+, Knock Off removes the target's item rather than rendering it unusable
                if (B_KNOCK_OFF_REMOVAL >= GEN_5)
                {
                    BtlController_EmitSetMonData(battlerDef, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[battlerDef].item), &gBattleMons[battlerDef].item);
                    MarkBattlerForControllerExec(battlerDef);
                    // Mark item as stolen so it will be restored after battle
                    gBattleStruct->itemLost[GetBattlerTrainer(battlerDef)][gBattlerPartyIndexes[battlerDef]].stolen = TRUE;
                }
                else
                {
                    GetBattlerPartyState(battlerDef)->isKnockedOff = TRUE;
                }

                BattleScriptCall(BattleScript_KnockedOff);
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_STEAL_ITEM:
            if (!IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
             || gBattleMons[cv->battlerAtk].item != ITEM_NONE
             || gBattleMons[battlerDef].item == ITEM_NONE
             || (!IsBattlerAlive(cv->battlerAtk) && GetConfig(B_FAINT_MOVE_EFFECT_TIMING) < GEN_CHAMPIONS)
             || !CanStealItem(cv->battlerAtk, battlerDef, gBattleMons[battlerDef].item))
                continue;

            if (cv->abilities[battlerDef] == ABILITY_STICKY_HOLD)
            {
                BattleScriptCall(BattleScript_StickyHoldActivatesRet);
                gBattlerAbility = battlerDef;
                gLastUsedAbility = gBattleMons[battlerDef].ability;
                RecordAbilityBattle(battlerDef, gLastUsedAbility);
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            else
            {
                StealTargetItem(cv->battlerAtk, battlerDef, ITEM_NONE);  // Attacker steals target item

                if (!(GetConfig(B_STEAL_WILD_ITEMS) >= GEN_9
                 && !(gBattleTypeFlags & (BATTLE_TYPE_TRAINER | BATTLE_TYPE_PALACE))))
                {
                    gBattleMons[cv->battlerAtk].item = gLastUsedItem;
                }

                gEffectBattler = cv->battlerDef;
                if (IsBattlerAlive(cv->battlerAtk))
                    BattleScriptCall(BattleScript_ItemSteal);
                else
                    BattleScriptCall(BattleScript_ItemStealNoAnim);

                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_HIT_SWITCH_TARGET:
            battlerDef = gBattlerTarget;
            if (IsBattlerTurnDamaged(battlerDef , EXCLUDING_SUBSTITUTES)
             && IsBattlerAlive(battlerDef)
             && IsBattlerAlive(cv->battlerAtk)
             && gBattleStruct->battlerState[battlerDef].commanderSpecies == SPECIES_NONE)
            {
                if (cv->abilities[battlerDef] == ABILITY_GUARD_DOG)
                {
                    gBattleStruct->eventState.moveEndBattler = 0;
                    gBattleScripting.moveendState++;
                    return MOVEEND_RESULT_CONTINUE;
                }
                else if (cv->abilities[battlerDef] == ABILITY_SUCTION_CUPS)
                {
                    gBattlerAbility = battlerDef;
                    BattleScriptCall(BattleScript_AbilityPreventsPhasingOutRet);
                }
                else if (gBattleMons[battlerDef].volatiles.root)
                {
                    BattleScriptCall(BattleScript_PrintMonIsRootedRet);
                }
                else if (GetActiveGimmick(battlerDef) == GIMMICK_DYNAMAX)
                {
                    BattleScriptCall(BattleScript_HitSwitchTargetDynamaxed);
                }
                else
                {
                    gBattleScripting.switchCase = B_SWITCH_HIT;
                    BattleScriptCall(BattleScript_TryHitSwitchTarget);
                }

                gBattleStruct->eventState.moveEndBattler = 0;
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_SMACK_DOWN:
            if (IsBattlerAlive(battlerDef)
             && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
             && gBattleMons[battlerDef].volatiles.semiInvulnerable != STATE_SKY_DROP_ATTACKER
             && gBattleMons[battlerDef].volatiles.semiInvulnerable != STATE_SKY_DROP_TARGET)
            {
                bool32 onAir = gBattleMons[battlerDef].volatiles.semiInvulnerable == STATE_ON_AIR;

                if (!onAir && IsBattlerGrounded(battlerDef, cv->abilities[battlerDef], cv->holdEffects[battlerDef]))
                    break;

                gBattleMons[battlerDef].volatiles.smackDown = TRUE;
                gBattleMons[battlerDef].volatiles.telekinesis = FALSE;
                gBattleMons[battlerDef].volatiles.magnetRiseTimer = FALSE;

                if (onAir)
                {
                    gBattleMons[battlerDef].volatiles.semiInvulnerable = STATE_NONE;
                    gBattleMons[battlerDef].volatiles.multipleTurns = FALSE;
                }

                BattleScriptCall(BattleScript_MoveEffectSmackDown);
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_RAPID_SPIN:
            if (IsBattlerTurnDamaged(battlerDef, INCLUDING_SUBSTITUTES))
            {
                if (!IsBattlerAlive(cv->battlerAtk) && GetConfig(B_FAINT_MOVE_EFFECT_TIMING) < GEN_CHAMPIONS)
                    break;

                BattleScriptCall(BattleScript_RapidSpinAway);
                gBattleStruct->eventState.moveEndBattler = 0;
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_FELL_STINGER:
            if (IsBattlerAlive(cv->battlerAtk)
             && !IsBattlerAlive(battlerDef)
             && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
             && !NoAliveMonsForEitherParty()
             && CompareStat(cv->battlerAtk, STAT_ATK, MAX_STAT_STAGE, CMP_LESS_THAN, cv->abilities[cv->battlerAtk]))
            {
                s32 stage = GetConfig(B_FELL_STINGER_STAT_RAISE) >= GEN_7 ? 3 : 2;
                SetStatChange(gBattlerAttacker, STAT_ATK, stage);
                BattleScriptCall(BattleScript_MoveEffectStatChange);
                gBattleStruct->eventState.moveEndBattler = 0;
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_STONE_AXE:
            if (!IsHazardOnSide(side, HAZARDS_STEALTH_ROCK)
             && IsBattlerTurnDamaged(battlerDef, INCLUDING_SUBSTITUTES)
             && IsBattlerAlive(cv->battlerAtk))
            {
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_POINTEDSTONESFLOAT;
                BattleScriptCall(BattleScript_MoveEffectStealthRock);
                gBattleStruct->eventState.moveEndBattler = 0;
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        case EFFECT_CEASELESS_EDGE:
            if (gSideTimers[side].spikesAmount < 3
             && IsBattlerTurnDamaged(battlerDef, INCLUDING_SUBSTITUTES)
             && IsBattlerAlive(cv->battlerAtk))
            {
                if (gBattleStruct->isSkyBattle)
                {
                    gBattleStruct->eventState.moveEndBattler = 0;
                    gBattleScripting.moveendState++;
                    return MOVEEND_RESULT_CONTINUE;
                }
                else
                {
                    gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SPIKESSCATTERED;
                    BattleScriptCall(BattleScript_MoveEffectSpikes);
                    gBattleStruct->eventState.moveEndBattler = 0;
                    gBattleScripting.moveendState++;
                    return MOVEEND_RESULT_RUN_SCRIPT;
                }
            }
            break;
        case EFFECT_SCALE_SHOT:
            if (IsBattlerAlive(cv->battlerAtk)
             && IsBattlerTurnDamaged(battlerDef, INCLUDING_SUBSTITUTES))
            {
                SetStatChange(cv->battlerAtk, STAT_DEF, -1);
                SetStatChange(cv->battlerAtk, STAT_SPEED, 1);
                BattleScriptCall(BattleScript_MoveEffectStatChange);
                gBattleStruct->eventState.moveEndBattler = 0;
                gBattleScripting.moveendState++;
                return MOVEEND_RESULT_RUN_SCRIPT;
            }
            break;
        default:
            result = MOVEEND_RESULT_CONTINUE;
            break;
        }
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemEffectsAttacker2(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (ItemBattleEffects(cv->battlerAtk, cv->battlerDef, cv->holdEffects[cv->battlerAtk], IsOnStatusChangeActivation)
     || ItemBattleEffects(cv->battlerAtk, cv->battlerDef, cv->holdEffects[cv->battlerAtk], IsOnHpThresholdActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndAbilityEffectFoesFainted(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_MOVE_END_FOES_FAINTED, cv->battlerAtk, cv->abilities[cv->battlerAtk], cv->move, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndShellTrap(struct BattleCalcValues *cv)
{
    u32 shellTrapBattlerMask = 0;

    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (battlerDef == cv->battlerAtk || IsBattlerAlly(battlerDef, cv->battlerAtk))
            continue;

        // Set ShellTrap to activate after the attacker's turn if target was hit by a physical move.
        if (GetMoveEffect(gChosenMoveByBattler[battlerDef]) == EFFECT_SHELL_TRAP
         && IsBattleMovePhysical(cv->move)
         && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
         && gProtectStructs[battlerDef].physicalBattlerId == cv->battlerAtk)
        {
            gProtectStructs[battlerDef].shellTrap = TRUE;
            shellTrapBattlerMask |= 1u << battlerDef;
        }
    }

    if (IsDoubleBattle() && shellTrapBattlerMask != 0)
    {
        enum BattlerId shellTrapBattlers[MAX_BATTLERS_COUNT];
        u32 numShellTrapBattlers = 0;

        for (u32 i = 0; i < gBattlersCount; i++)
        {
            enum BattlerId battler = gBattlersBySpeed[i];

            if (shellTrapBattlerMask & (1u << battler))
                shellTrapBattlers[numShellTrapBattlers++] = battler;
        }

        // Each reorder inserts the battler immediately after the attacker, so use reverse turn order to keep faster battlers first.
        while (numShellTrapBattlers != 0)
            ChangeOrderTargetAfterAttacker(shellTrapBattlers[--numShellTrapBattlers]);
    }

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndColorChange(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;

        if (battler == cv->battlerAtk)
            continue;
        if (AbilityBattleEffects(ABILITYEFFECT_COLOR_CHANGE, battler, cv->abilities[battler], 0, TRUE))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndKeeMarangaHpThresholdItemTarget(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battlerDef = gBattleStruct->eventState.moveEndBattler++;

        if (battlerDef == cv->battlerAtk)
            continue;

        if (ItemBattleEffects(battlerDef, cv->battlerAtk, cv->holdEffects[battlerDef], IsKeeMarangaBerryActivation)
         || ItemBattleEffects(battlerDef, cv->battlerAtk, cv->holdEffects[battlerDef], IsOnHpThresholdActivation))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static bool32 HasAnyBattlerQueuedSwitch(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gSpecialStatuses[battler].queuedSwitch != NO_QUEUED_SWITCH)
            return TRUE;
    }
    return FALSE;
}

static bool32 TryRedCard(enum BattlerId battlerAtk, enum BattlerId redCardBattler, enum BattleMoveEffects moveEffect)
{
    if (!IsBattlerAlive(redCardBattler)
     || !IsBattlerAlive(battlerAtk)
     || gBattleStruct->redCardActivated
     || !IsBattlerTurnDamaged(redCardBattler, EXCLUDING_SUBSTITUTES)
     || moveEffect == EFFECT_FUTURE_SIGHT
     || !CanBattlerSwitch(battlerAtk))
        return FALSE;

    gBattleStruct->redCardActivated = TRUE;
    gLastUsedItem = gBattleMons[redCardBattler].item;
    SaveBattlerTarget(redCardBattler); // save battler with red card
    SaveBattlerAttacker(battlerAtk);
    gBattleScripting.battler = gBattlerTarget = redCardBattler;
    gEffectBattler = battlerAtk;
    if (gBattleStruct->battlerState[battlerAtk].commanderSpecies != SPECIES_NONE
     || GetBattlerAbility(battlerAtk) == ABILITY_GUARD_DOG
     || GetActiveGimmick(battlerAtk) == GIMMICK_DYNAMAX)
        BattleScriptCall(BattleScript_RedCardActivationNoSwitch);
    else
        BattleScriptCall(BattleScript_RedCardActivates);

    return TRUE;
}

static bool32 TryEjectButton(enum BattlerId battlerAtk, u32 ejectButtonBattler, enum BattleMoveEffects moveEffect)
{
    if (!IsBattlerTurnDamaged(ejectButtonBattler, EXCLUDING_SUBSTITUTES)
     || moveEffect == EFFECT_FUTURE_SIGHT
     || HasAnyBattlerQueuedSwitch()
     || IsBattlerInvolvedInSkyDrop(ejectButtonBattler)
     || IsPursuitTargetSet()
     || gBattleStruct->battlerState[ejectButtonBattler].commanderSpecies != SPECIES_NONE
     || !CanBattlerSwitch(ejectButtonBattler))
        return FALSE;

    gBattleScripting.battler = ejectButtonBattler;
    gLastUsedItem = gBattleMons[ejectButtonBattler].item;
    gBattleStruct->battlerState[ejectButtonBattler].usedEjectItem = TRUE;
    gSpecialStatuses[ejectButtonBattler].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
    BattleScriptCall(BattleScript_EjectItemActivates);
    gAiLogicData->ejectButtonSwitch = TRUE;
    return TRUE;
}

static enum MoveEndResult MoveEndCardButton(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattlersByRawSpeed[gBattleStruct->eventState.moveEndBattler++];

        if (battler == gBattlerAttacker)
            continue;

        switch (cv->holdEffects[battler])
        {
        case HOLD_EFFECT_EJECT_BUTTON:
            if (TryEjectButton(cv->battlerAtk, battler, cv->moveEffect))
                return MOVEEND_RESULT_RUN_SCRIPT;
            break;
        case HOLD_EFFECT_RED_CARD:
            if (TryRedCard(cv->battlerAtk, battler, cv->moveEffect))
                return MOVEEND_RESULT_RUN_SCRIPT;
            break;
        default:
            break;
        }
    }

    gBattleStruct->redCardActivated = FALSE;
    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndFormChange(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleStruct->battlerState[cv->battlerAtk].originalBattlerPartyId == PARTY_SIZE
     && TryBattleFormChange(cv->battlerAtk, FORM_CHANGE_BATTLE_AFTER_MOVE, cv->abilities[cv->battlerAtk]))
    {
        result = MOVEEND_RESULT_RUN_SCRIPT;
        BattleScriptCall(BattleScript_AttackerFormChangeMoveEffect);
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndLifeOrbShellBell(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (ItemBattleEffects(cv->battlerAtk, 0, cv->holdEffects[cv->battlerAtk], IsLifeOrbShellBellActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndEmergencyExit(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    u32 numEmergencyExitBattlers = 0;
    u32 emergencyExitBattlers = 0;

    if (HasAnyBattlerQueuedSwitch())
    {
        gBattleScripting.moveendState++;
        return result;
    }

    // Because sorting the battlers by speed takes lots of cycles,
    // we check if EE can be activated and count how many.
    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        if (!IsBattleMoveStatus(cv->move)
         && !gBattleStruct->unableToUseMove
         && EmergencyExitCanBeTriggered(i, cv->abilities[i]))
        {
            emergencyExitBattlers |= 1u << i;
            numEmergencyExitBattlers++;
        }
    }

    if (numEmergencyExitBattlers == 0)
    {
        gBattleScripting.moveendState++;
        return result;
    }

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleMons[i].volatiles.tryEjectPack = FALSE;

    enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};
    if (numEmergencyExitBattlers > 1)
        SortBattlersBySpeed(battlers, FALSE);

    for (u32 i = 0; i < gBattlersCount; i++)
    {
        enum BattlerId battler = battlers[i];

        if (!(emergencyExitBattlers & 1u << battler))
            continue;

        gBattleScripting.battler = battler;
        gSpecialStatuses[battler].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
        BattleScriptCall(BattleScript_EmergencyExit);
        result = MOVEEND_RESULT_RUN_SCRIPT;
        break; // Only the fastest Emergency Exit / Wimp Out activates
    }

    gBattleScripting.moveendState++;
    return result;
}

static bool32 CanPartingShotTrigger(enum BattlerId battlerAtk)
{
    if (GetConfig(B_PARTING_SHOT_SWITCH) < GEN_7 && CanBattlerSwitch(battlerAtk))
        return TRUE;

    if (gBattleStruct->allowPartingShot)
        return TRUE;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_STAT_CHANGED)
            return TRUE;
    }

    return FALSE;
}

static enum MoveEndResult MoveEndHitEscape(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    switch (GetMoveEffect(cv->move))
    {
    case EFFECT_HIT_ESCAPE:
        if (!HasAnyBattlerQueuedSwitch()
         && gBattleStruct->battlerState[cv->battlerAtk].originalBattlerPartyId == PARTY_SIZE
         && !gBattleStruct->unableToUseMove
         && IsAnyTargetTurnDamaged(cv->battlerAtk, INCLUDING_SUBSTITUTES)
         && IsBattlerAlive(cv->battlerAtk)
         && !NoAliveMonsForBattlerSide(cv->battlerDef))
        {
            result = MOVEEND_RESULT_RUN_SCRIPT;
            gSpecialStatuses[cv->battlerAtk].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
            BattleScriptCall(BattleScript_EffectHitEscape);
        }
        break;
    case EFFECT_PARTING_SHOT:
        if (CanPartingShotTrigger(cv->battlerAtk))
        {
            for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
                gBattleMons[battler].volatiles.tryEjectPack = FALSE;

            result = MOVEEND_RESULT_RUN_SCRIPT;
            BattleScriptCall(BattleScript_PartingShotEscape);
        }
        break;
    default:
        break;
    }

    gBattleStruct->allowPartingShot = FALSE;
    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndPickpocket(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;
    enum Item itemToSteal;
    enum Ability abilityAtk;
    enum HoldEffect holdEffectAtk;
    u32 originalAttackerPartyId = gBattleStruct->battlerState[cv->battlerAtk].originalBattlerPartyId;
    bool32 originalAttackerOnField = originalAttackerPartyId == PARTY_SIZE;

    if (gSpecialStatuses[cv->battlerAtk].attackerInParty)
    {
        gBattleScripting.moveendState++;
        return result;
    }

    if (originalAttackerOnField)
    {
        if (IsBattlerAlive(cv->battlerAtk) && !GetBattlerPartyState(cv->battlerAtk)->isKnockedOff) // Gen3 edge case where the knocked of item was not removed
        {
            itemToSteal = gBattleMons[cv->battlerAtk].item;
            holdEffectAtk = cv->holdEffects[cv->battlerAtk];
            abilityAtk = cv->abilities[cv->battlerAtk];
        }
        else
        {
            itemToSteal = ITEM_NONE;
            holdEffectAtk = HOLD_EFFECT_NONE;
            abilityAtk = ABILITY_NONE;
        }
    }
    else
    {
        itemToSteal = GetMonData(&gParties[GetBattlerTrainer(cv->battlerAtk)][originalAttackerPartyId], MON_DATA_HELD_ITEM);
        holdEffectAtk = HOLD_EFFECT_NONE;
        abilityAtk = ABILITY_NONE;
    }

    if (itemToSteal != ITEM_NONE) // valid item to steal
    {
        enum BattlerId battlers[MAX_BATTLERS_COUNT] = {0, 1, 2, 3};
        SortBattlersBySpeed(battlers, FALSE); // Pickpocket activates for fastest mon without item
        for (u32 i = 0; i < gBattlersCount; i++)
        {
            enum BattlerId battlerDef = battlers[i];
            if (battlerDef != cv->battlerAtk
              && !gBattleStruct->battlerState[battlerDef].notOnField
              && !IsBattlerUnaffectedByMove(battlerDef)
              && cv->abilities[battlerDef] == ABILITY_PICKPOCKET
              && IsMoveMakingContact(cv->battlerAtk, battlerDef, abilityAtk, holdEffectAtk, gCurrentMove)
              && IsBattlerTurnDamaged(battlerDef, EXCLUDING_SUBSTITUTES)
              && gBattleMons[battlerDef].item == ITEM_NONE
              && CanStealItem(battlerDef, cv->battlerAtk, itemToSteal))
            {
                gBattlerTarget = gBattlerAbility = battlerDef;
                gEffectBattler = cv->battlerAtk;
                // Battle scripting is super brittle so we shall do the item exchange now (if possible)
                if (abilityAtk != ABILITY_STICKY_HOLD)
                {
                    if (originalAttackerOnField)
                    {
                        StealTargetItem(battlerDef, cv->battlerAtk, ITEM_NONE);  // Target takes attacker's item
                    }
                    else
                    {
                        StealTargetItem(battlerDef, cv->battlerAtk, itemToSteal); // Don't change cv->battlerAtk's item

                        PREPARE_MON_NICK_WITH_PREFIX_LOWER_BUFFER(gBattleTextBuff2, cv->battlerAtk, originalAttackerPartyId);

                        if (B_TRAINERS_KNOCK_OFF_ITEMS == TRUE
                         && gBattleTypeFlags & BATTLE_TYPE_TRAINER
                         && !(gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                         && IsOnPlayerSide(cv->battlerAtk)
                         && itemToSteal == gBattleStruct->itemLost[GetBattlerTrainer(cv->battlerAtk)][originalAttackerPartyId].originalItem)
                            gBattleStruct->itemLost[GetBattlerTrainer(cv->battlerAtk)][originalAttackerPartyId].stolen = TRUE;
                        itemToSteal = ITEM_NONE;
                        BtlController_EmitSetMonData(
                            cv->battlerAtk,
                            B_COMM_TO_CONTROLLER,
                            REQUEST_HELDITEM_BATTLE,
                            1u << originalAttackerPartyId,
                            sizeof(itemToSteal),
                            &itemToSteal);
                        MarkBattlerForControllerExec(cv->battlerAtk);
                    }
                    BattleScriptCall(BattleScript_Pickpocket);
                }
                else
                {
                    BattleScriptCall(BattleScript_PickpocketPrevented);
                }
                result = MOVEEND_RESULT_RUN_SCRIPT;
                break; // Pickpocket activates on fastest mon, so exit loop.
            }
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndItemsEffectsAll(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattleStruct->eventState.moveEndBattler++;

        if (ItemBattleEffects(battler, 0, cv->holdEffects[battler], IsOnStatusChangeActivation)
         || ItemBattleEffects(battler, 0, cv->holdEffects[battler], IsOnHpThresholdActivation))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndOpportunist(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattlersByRawSpeed[gBattleStruct->eventState.moveEndBattler++];

        if (AbilityBattleEffects(ABILITYEFFECT_OPPORTUNIST, battler, cv->abilities[battler], 0, TRUE))
            return MOVEEND_RESULT_RUN_SCRIPT;
    }

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndThirdMoveBlock(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    switch (cv->moveEffect)
    {
    case EFFECT_STEEL_ROLLER:
        if (gFieldTimers.terrain != B_TERRAIN_NONE && IsAnyTargetTurnDamaged(cv->battlerAtk, INCLUDING_SUBSTITUTES))
        {
            BattleScriptCall(BattleScript_RemoveTerrain);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_ICE_SPINNER:
        if (gFieldTimers.terrain != B_TERRAIN_NONE
         && IsAnyTargetTurnDamaged(cv->battlerAtk, INCLUDING_SUBSTITUTES))
        {
            if ((!IsBattlerAlive(cv->battlerAtk) || gLastPrintedMoves[cv->battlerAtk] != cv->move) && GetConfig(B_FAINT_MOVE_EFFECT_TIMING) < GEN_CHAMPIONS)
                break;

            BattleScriptCall(BattleScript_RemoveTerrain);
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    case EFFECT_NATURAL_GIFT:
        if (!gBattleStruct->unableToUseMove && GetItemPocket(gBattleMons[cv->battlerAtk].item) == POCKET_BERRIES)
        {
            enum Item item = gBattleMons[cv->battlerAtk].item;
            gBattleMons[gBattlerAttacker].item = ITEM_NONE;
            gBattleStruct->battlerState[cv->battlerAtk].canPickupItem = TRUE;
            GetBattlerPartyState(cv->battlerAtk)->usedHeldItem = item;
            CheckSetUnburden(cv->battlerAtk);
            BtlController_EmitSetMonData(
                cv->battlerAtk,
                B_COMM_TO_CONTROLLER,
                REQUEST_HELDITEM_BATTLE,
                0,
                sizeof(gBattleMons[cv->battlerAtk].item),
                &gBattleMons[cv->battlerAtk].item);
            MarkBattlerForControllerExec(cv->battlerAtk);
            ClearBattlerItemEffectHistory(cv->battlerAtk);

            if (!TrySymbiosis(cv->battlerAtk, item, NULL))
                result = MOVEEND_RESULT_RUN_SCRIPT;
        }
        break;
    default:
        break;
    }

    gBattleScripting.moveendState++;
    return result;
}

static inline bool32 TryEjectPack(enum BattlerId battlerAtk, enum BattlerId ejectPackBattler)
{
    if (!gBattleMons[ejectPackBattler].volatiles.tryEjectPack
     || HasAnyBattlerQueuedSwitch()
     || IsPursuitTargetSet()
     || IsBattlerInvolvedInSkyDrop(ejectPackBattler)
     || gBattleMons[ejectPackBattler].volatiles.semiInvulnerable == STATE_COMMANDER
     || gBattleStruct->battlerState[ejectPackBattler].commanderSpecies != SPECIES_NONE
     || !CanBattlerSwitch(ejectPackBattler)
     || (GetMoveEffect(gCurrentMove) == EFFECT_PARTING_SHOT && CanBattlerSwitch(battlerAtk)))
        return FALSE;

    gBattleScripting.battler = ejectPackBattler;
    gLastUsedItem = gBattleMons[ejectPackBattler].item;
    gBattleStruct->battlerState[ejectPackBattler].usedEjectItem = TRUE;
    gSpecialStatuses[ejectPackBattler].queuedSwitch = QUEUED_SWITCH_OPEN_PARTY_SCREEN;
    BattleScriptCall(BattleScript_EjectItemActivates);
    gAiLogicData->ejectPackSwitch = TRUE;
    return TRUE;
}

static enum MoveEndResult MoveEndItemOnStatChange(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattlersByRawSpeed[gBattleStruct->eventState.moveEndBattler++];

        switch (cv->holdEffects[battler])
        {
        case HOLD_EFFECT_WHITE_HERB:
            if (ItemBattleEffects(battler, 0, cv->holdEffects[battler], IsWhiteHerbActivation))
                return MOVEEND_RESULT_RUN_SCRIPT;
            break;
        case HOLD_EFFECT_EJECT_PACK:
            if (TryEjectPack(cv->battlerAtk, battler))
                return MOVEEND_RESULT_RUN_SCRIPT;
            break;
        case HOLD_EFFECT_MIRROR_HERB:
            if (ItemBattleEffects(battler, 0, cv->holdEffects[battler], IsMirrorHerbActivation))
                return MOVEEND_RESULT_RUN_SCRIPT;
            break;
        default:
            break;
        }
    }

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
        gBattleMons[i].volatiles.tryEjectPack = FALSE;

    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndSendOutReplacements(struct BattleCalcValues *cv)
{
    while (gBattleStruct->eventState.moveEndBattler < gBattlersCount)
    {
        enum BattlerId battler = gBattlersBySpeed[gBattleStruct->eventState.moveEndBattler++];

        switch (gSpecialStatuses[battler].queuedSwitch)
        {
        case NO_QUEUED_SWITCH:
            continue;
        case QUEUED_SWITCH_SEND_REPLACEMENT:
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_QueuedSwitch);
            return MOVEEND_RESULT_RUN_SCRIPT;
        case QUEUED_SWITCH_OPEN_PARTY_SCREEN:
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_QueuedSwitchOpenPartyScreen);
            return MOVEEND_RESULT_RUN_SCRIPT;
        default:
            errorf("Invalid value - queuedSwitch");
            break;
        }
    }
    gBattleStruct->eventState.moveEndBattler = 0;
    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndRampage(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleMons[cv->battlerAtk].volatiles.rampageTurns == 0
     || gSpecialStatuses[cv->battlerAtk].dancerUsedMove
     || B_RAMPAGE_CONFUSION < GEN_5)
    {
        result = MOVEEND_RESULT_CONTINUE;
    }
    else if (--gBattleMons[cv->battlerAtk].volatiles.rampageTurns == 0)
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        if (CanBeConfused(cv->battlerAtk, cv->battlerAtk))
        {
            gBattleScripting.battler = cv->battlerAtk;
            gBattleMons[cv->battlerAtk].volatiles.confusionTimer = RandomUniform(RNG_CONFUSION_TURNS, 2, B_CONFUSION_TURNS); // 2-5 turns
            BattleScriptCall(BattleScript_ConfusionAfterRampage);
            result = MOVEEND_RESULT_BREAK;
        }
    }
    else if (IsBattlerUnaffectedByMove(cv->battlerDef))
    {
        CancelMultiTurnMoves(cv->battlerAtk);
        result = MOVEEND_RESULT_CONTINUE;
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndConfusionAfterSkyDrop(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleMons[cv->battlerDef].volatiles.confuseAfterDrop
     && gBattleMons[cv->battlerDef].volatiles.semiInvulnerable != STATE_SKY_DROP_TARGET)
    {
        gBattleMons[cv->battlerDef].volatiles.confuseAfterDrop = FALSE;
        if (CanBeConfused(cv->battlerDef, cv->battlerDef))
        {
            gBattleScripting.battler = cv->battlerDef;
            gBattleMons[cv->battlerDef].volatiles.confusionTimer = RandomUniform(RNG_CONFUSION_TURNS, 2, B_CONFUSION_TURNS); // 2-5 turns
            BattleScriptCall(BattleScript_ConfusionAfterRampage);
            result = MOVEEND_RESULT_BREAK;
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndSprayLeppaBlunder(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    // Throat Spray, Leppa Berry, Blunder Policy
    if (ItemBattleEffects(cv->battlerAtk, 0, cv->holdEffects[cv->battlerAtk], IsSprayLeppaBlunderActivation))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static bool32 ShouldSetStompingTantrumTimer(void)
{
    u32 numNotAffectedTargets = 0;

    if (gBattleStruct->battlerState[gBattlerAttacker].originalBattlerPartyId != PARTY_SIZE) // no longer the same battler
        return FALSE;

    if (gBattleStruct->pledgeState == PLEDGE_COMBO_WAITING // Is the battler that uses the first Pledge move in the combo
     || gBattleStruct->unableToUseMove)
        return TRUE;

    if (!IsDoubleSpreadMove())
        return gBattleStruct->moveResultFlags[gBattlerTarget] & (MOVE_RESULT_MISSED | MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE);

    for (enum BattlerId battlerDef = 0; battlerDef < gBattlersCount; battlerDef++)
    {
        if (gBattlerAttacker == battlerDef)
            continue;
        if (gBattleStruct->moveResultFlags[battlerDef] & (MOVE_RESULT_MISSED | MOVE_RESULT_FAILED | MOVE_RESULT_DOESNT_AFFECT_FOE))
            numNotAffectedTargets++;
    }

    return numNotAffectedTargets == gBattleStruct->numSpreadTargets;
}

static enum MoveEndResult MoveEndClearBits(struct BattleCalcValues *cv)
{
    // go to next Bouncer or original attacker if possible
    if (gBattleStruct->bouncedMoveIsUsed)
    {
        RestoreAttacker();
        RestoreTarget();
        gBattleStruct->bouncedMoveIsUsed = FALSE;
        gBattleScripting.moveendState = MOVEEND_BOUNCED_MOVE;
        for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
            gBattleStruct->moveResultFlags[battler] = gBattleStruct->savedMoveResultFlags[battler];
        return MOVEEND_RESULT_RUN_SCRIPT;
    }

    ValidateBattlers();

    enum Move originallyUsedMove = GetOriginallyUsedMove(gChosenMove);
    enum Type moveType = GetBattleMoveType(cv->move);

    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        BattleArena_AddSkillPoints(cv->battlerAtk);

    if (ShouldSetStompingTantrumTimer())
        gBattleStruct->battlerState[cv->battlerAtk].stompingTantrumTimer = 2;

    if (gSpecialStatuses[cv->battlerAtk].backUpTarget)
        gBattleStruct->moveTarget[cv->battlerAtk] = gSpecialStatuses[cv->battlerAtk].backUpTarget - 1;

    // If the Pokémon needs to keep track of move usage for its evolutions, do it
    if (originallyUsedMove != MOVE_NONE)
        TryUpdateEvolutionTracker(IF_USED_MOVE_X_TIMES, 1, originallyUsedMove);

    SetSameMoveTurnValues(cv->moveEffect);
    TryClearChargeVolatile(moveType);
    gProtectStructs[cv->battlerAtk].shellTrap = FALSE;
    gBattleStruct->battlerState[cv->battlerAtk].ateBoost = FALSE;
    gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
    gBattleStruct->additionalEffectsCounter = 0;
    gBattleStruct->triAttackBurn = FALSE;
    gBattleStruct->fickleBeamBoosted = FALSE;
    gBattleStruct->battlerState[cv->battlerAtk].usedMicleBerry = FALSE;
    gBattleStruct->toxicChainPriority = FALSE;
    gBattleStruct->flungItem = FLUNG_ITEM_NONE;
    gBattleStruct->blunderPolicy = FALSE;
    gBattleScripting.animTurn = 0;
    gBattleScripting.animTargetsHit = 0;

    if (gBattleStruct->pledgeState == PLEDGE_COMBO_ATTACK)
        gBattleStruct->pledgeState = PLEDGE_COMBO_NONE;

    if (GetActiveGimmick(cv->battlerAtk) == GIMMICK_Z_MOVE)
        SetActiveGimmick(cv->battlerAtk, GIMMICK_NONE);

    if (gBattleMons[cv->battlerAtk].volatiles.destinyBond > 0)
        gBattleMons[cv->battlerAtk].volatiles.destinyBond--;

    // check if Stellar type boost should be used up
    if (GetActiveGimmick(cv->battlerAtk) == GIMMICK_TERA
     && GetBattlerTeraType(cv->battlerAtk) == TYPE_STELLAR
     && !IsBattleMoveStatus(cv->move)
     && IsTypeStellarBoosted(cv->battlerAtk, moveType))
        ExpendTypeStellarBoost(cv->battlerAtk, moveType);
    memset(gQueuedStatBoosts, 0, sizeof(gQueuedStatBoosts));

    for (enum BattlerId i = 0; i < gBattlersCount; i++)
    {
        gBattleStruct->battlerState[cv->battlerAtk].targetsDone[i] = FALSE;
        gBattleStruct->battlerState[i].originalBattlerPartyId = PARTY_SIZE;
        gBattleMons[i].volatiles.tryEjectPack = FALSE;

        if (gBattleStruct->battlerState[i].commanderSpecies != SPECIES_NONE && !IsBattlerAlive(i))
        {
            enum BattlerId partner = GetPartnerBattler(i);
            gBattleStruct->battlerState[i].commanderSpecies = SPECIES_NONE;
            if (gBattleMons[partner].volatiles.semiInvulnerable == STATE_COMMANDER)
                gBattleMons[partner].volatiles.semiInvulnerable = STATE_NONE;
        }
    }

    // Need to check a specific battler during the end turn
    gBattleMons[cv->battlerAtk].volatiles.unableToUseMove = gBattleStruct->unableToUseMove;
    ClearDamageCalcResults();

    gBattleScripting.moveendState++;
    return MOVEEND_RESULT_CONTINUE;
}

static enum MoveEndResult MoveEndDancer(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (AbilityBattleEffects(ABILITYEFFECT_DANCER, cv->battlerAtk, ABILITY_DANCER, cv->move, TRUE))
        result = MOVEEND_RESULT_RUN_SCRIPT;

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult MoveEndPursuitNextAction(struct BattleCalcValues *cv)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    if (gBattleStruct->battlerState[gBattlerTarget].pursuitTarget)
    {
        u32 storedTarget = gBattlerTarget;
        if (SetTargetToNextPursuiter(gBattlerTarget))
        {
            ChangeOrderTargetAfterAttacker(gBattlerTarget);
            gBattleStruct->moveTarget[gBattlerTarget] = storedTarget;
            gBattlerTarget = storedTarget;
        }
        else if (IsBattlerAlive(gBattlerTarget))
        {
            gBattlerAttacker = gBattlerTarget;
            if (gBattleStruct->pursuitStoredSwitch == PARTY_SIZE)
                gBattlescriptCurrInstr = BattleScript_MoveSwitchOpenPartyScreen;
            else
                gBattlescriptCurrInstr = BattleScript_DoSwitchOut;
            gBattleStruct->monToSwitchIntoId[gBattlerTarget] = gBattleStruct->pursuitStoredSwitch;
            ClearPursuitValues();
            result = MOVEEND_RESULT_RUN_SCRIPT;
        }
    }

    gBattleScripting.moveendState++;
    return result;
}

static enum MoveEndResult (*const sMoveEndHandlers[])(struct BattleCalcValues *cv) =
{
    [MOVEEND_SET_VALUES] = MoveEndSetValues,
    [MOVEEND_PROTECT_BYPASS_EFFECTS] = MoveEndProtectBypassEffects,
    [MOVEEND_PROTECT_LIKE_EFFECT] = MoveEndProtectLikeEffect,
    [MOVEEND_ABSORB] = MoveEndAbsorb,
    [MOVEEND_RAGE] = MoveEndRage,
    [MOVEEND_BEAK_BLAST] = MoveEndBeakBlast,
    [MOVEEND_ABILITIES] = MoveEndAbilities,
    [MOVEEND_RESIST_BERRY_MESSAGE] = MoveEndResistBerryMessage,
    [MOVEEND_FORM_CHANGE_ON_HIT] = MoveEndFormChangeOnHit,
    [MOVEEND_ABILITIES_ATTACKER] = MoveEndAbilitiesAttacker,
    [MOVEEND_QUEUE_DANCER] = MoveEndQueueDancer,
    [MOVEEND_STATUS_IMMUNITY_ABILITIES] = MoveEndStatusImmunityAbilities,
    [MOVEEND_ATTACKER_INVISIBLE] = MoveEndAttackerInvisible,
    [MOVEEND_ATTACKER_VISIBLE] = MoveEndAttackerVisible,
    [MOVEEND_TARGET_VISIBLE] = MoveEndTargetVisible,
    [MOVEEND_ITEM_EFFECTS_TARGET] = MoveEndItemEffectsTarget,
    [MOVEEND_ITEM_EFFECTS_ATTACKER_1] = MoveEndItemEffectsAttacker1,
    [MOVEEND_SYMBIOSIS] = MoveEndSymbiosis,
    [MOVEEND_SUBSTITUTE] = MoveEndSubstitute,
    [MOVEEND_FAINT_BLOCK] = MoveEndFaintBlock,
    [MOVEEND_UPDATE_LAST_MOVES] = MoveEndUpdateLastMoves,
    [MOVEEND_MIRROR_MOVE] = MoveEndMirrorMove,
    [MOVEEND_NEXT_TARGET] = MoveEndNextTarget,
    [MOVEEND_BOUNCED_MOVE] = MoveEndBouncedMove,
    [MOVEEND_HP_THRESHOLD_ITEMS_TARGET] = MoveEndHpThresholdItemsTarget,
    [MOVEEND_MULTIHIT_MOVE] = MoveEndMultihitMove,
    [MOVEEND_DEFROST] = MoveEndDefrost,
    [MOVEEND_MOVE_BLOCK_RECOIL] = MoveEndMoveBlockRecoil,
    [MOVEEND_SHEER_FORCE] = MoveEndSheerForce,
    [MOVEEND_MOVE_BLOCK] = MoveEndMoveBlock,
    [MOVEEND_ITEM_EFFECTS_ATTACKER_2] = MoveEndItemEffectsAttacker2,
    [MOVEEND_ABILITY_EFFECT_FOES_FAINTED] = MoveEndAbilityEffectFoesFainted,
    [MOVEEND_SHELL_TRAP] = MoveEndShellTrap,
    [MOVEEND_COLOR_CHANGE] = MoveEndColorChange,
    [MOVEEND_KEE_MARANGA_HP_THRESHOLD_ITEM_TARGET] = MoveEndKeeMarangaHpThresholdItemTarget,
    [MOVEEND_CARD_BUTTON] = MoveEndCardButton,
    [MOVEEND_FORM_CHANGE] = MoveEndFormChange,
    [MOVEEND_LIFE_ORB_SHELL_BELL] = MoveEndLifeOrbShellBell,
    [MOVEEND_EMERGENCY_EXIT] = MoveEndEmergencyExit,
    [MOVEEND_HIT_ESCAPE] = MoveEndHitEscape,
    [MOVEEND_PICKPOCKET] = MoveEndPickpocket,
    [MOVEEND_ITEMS_EFFECTS_ALL] = MoveEndItemsEffectsAll,
    [MOVEEND_OPPORTUNIST] = MoveEndOpportunist,
    [MOVEEND_THIRD_MOVE_BLOCK] = MoveEndThirdMoveBlock,
    [MOVEEND_RAMPAGE] = MoveEndRampage,
    [MOVEEND_CONFUSION_AFTER_SKY_DROP] = MoveEndConfusionAfterSkyDrop,
    [MOVEEND_SPRAY_LEPPA_BLUNDER] = MoveEndSprayLeppaBlunder,
    [MOVEEND_ITEM_ON_STAT_CHANGE] = MoveEndItemOnStatChange,
    [MOVEEND_SEND_OUT_REPLACEMENTS] = MoveEndSendOutReplacements,
    [MOVEEND_CLEAR_BITS] = MoveEndClearBits,
    [MOVEEND_DANCER] = MoveEndDancer,
    [MOVEEND_PURSUIT_NEXT_ACTION] = MoveEndPursuitNextAction,
};

enum MoveEndResult DoMoveEnd(enum MoveEndState endMode, enum MoveEndState endState)
{
    enum MoveEndResult result = MOVEEND_RESULT_CONTINUE;

    struct BattleCalcValues cv = {
        .battlerAtk = gBattlerAttacker,
        .battlerDef = gBattlerTarget,
        .move = gCurrentMove,
    };

    cv.moveEffect = GetMoveEffect(cv.move);
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        cv.abilities[battler] = GetBattlerAbility(battler);
        cv.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }

    do
    {
        result = sMoveEndHandlers[gBattleScripting.moveendState](&cv);

        if (endMode == 1 && result == MOVEEND_RESULT_CONTINUE)
            gBattleScripting.moveendState = MOVEEND_COUNT;
        if (endMode == 2 && endState == gBattleScripting.moveendState)
            gBattleScripting.moveendState = MOVEEND_COUNT;

    } while (gBattleScripting.moveendState != MOVEEND_COUNT && result == MOVEEND_RESULT_CONTINUE);

    return result;
}

// ======================
// Stat Change Resolution
// ======================

static bool32 ShouldSkipStatChangeOnBattler(enum BattlerId battlerAtk, enum BattlerId battlerDef)
{
    // It is convenient to use targetsDone here but needs a hack for self target stat change moves
    bool32 isSelf = battlerAtk == battlerDef && gBattlerAttacker == gBattlerTarget;

    if (!isSelf && gBattleStruct->battlerState[battlerAtk].targetsDone[battlerDef])
        return TRUE;
    if (gBattleStruct->moveResultFlags[battlerDef] & MOVE_RESULT_INVALID_TARGET)
        return TRUE;

    return FALSE;
}

// Avoid erroneous, second failure message
static bool32 ShouldSkipStatChangeResolution(enum BattlerId battlerAtk)
{
    if (battlerAtk == gBattlerTarget)
        return FALSE;

    u32 numUnaffectedTargets = 0;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleStruct->battlerState[battlerAtk].targetsDone[battler])
            numUnaffectedTargets++;
        else if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_NO_EFFECT)
            numUnaffectedTargets++;
    }

    return numUnaffectedTargets == gBattlersCount;
}

static enum MoveResult StatChangeSubstitute(struct BattleCalcValues *cv)
{
    if (ShouldSkipStatChangeResolution(cv->battlerAtk))
        return MOVE_RESULT_DONE;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (ShouldSkipStatChangeOnBattler(cv->battlerAtk, battler)
         || cv->battlerAtk == battler)
            continue;

        if (IsSubstituteProtected(cv->battlerAtk, battler, cv->abilities[cv->battlerAtk], cv->move))
            gBattleStruct->moveResultFlags[battler] = MOVE_RESULT_DOESNT_AFFECT_FOE;
    }

    return MOVE_RESULT_CONTINUE;
}

static void TryAcupressureStatChange(struct BattleCalcValues *cv)
{
    u32 bits = 0;

    if (ShouldSkipStatChangeOnBattler(cv->battlerAtk, cv->battlerDef))
        return;

    for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
    {
        if (CompareStat(cv->battlerDef, stat, MAX_STAT_STAGE, CMP_LESS_THAN, cv->abilities[cv->battlerDef]))
            bits |= 1u << stat;
    }

    if (bits)
    {
        enum Stat statId;
        do
        {
            statId = (Random() % (NUM_BATTLE_STATS - 1)) + 1;
        } while (!(bits & (1u << statId)));

        SetStatChange(cv->battlerDef, statId, 2);
        gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_ATTEMPT_STAT_CHANGE;
    }
    else
    {
        gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_DOESNT_AFFECT_FOE;
    }
}

static enum MoveResult StatChangeCanAnyChange(struct BattleCalcValues *cv)
{
    if (GetMoveEffect(cv->move) == EFFECT_ACUPRESSURE)
    {
        TryAcupressureStatChange(cv);
        return MOVE_RESULT_CONTINUE;
    }

    struct StatChange st = {
        .onlyChecking = TRUE,
        .ignoreCertainFailure = TRUE,
    };

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        cv->battlerDef = GetTargetBySlot(cv->battlerAtk, battler);

        if (ShouldSkipStatChangeOnBattler(cv->battlerAtk, cv->battlerDef))
            continue;

        st.certain = cv->battlerAtk == cv->battlerDef;

        if (CanAnyStatChange(cv, &st))
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_ATTEMPT_STAT_CHANGE;
        else
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_STAT_CHANGE_PREVENTED;

        if (st.additionalEffectTriggers)
            gBattleStruct->moveResultFlags[cv->battlerDef] = MOVE_RESULT_ATTEMPT_STAT_CHANGE;
    }

    cv->battlerDef = gBattlerTarget;
    gBattleStruct->additionalEffectsCounter = 0;
    gBattleStruct->statChangeBattler = 0;

    return MOVE_RESULT_CONTINUE;
}

static enum MoveResult StatChangeAccuracy(struct BattleCalcValues *cv)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (ShouldSkipStatChangeOnBattler(cv->battlerAtk, battler)
         || gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_STAT_CHANGE_PREVENTED
         || cv->battlerAtk == battler)
            continue;

        cv->battlerDef = battler;
        if (DoesMoveMissTarget(cv))
        {
            if (cv->holdEffects[cv->battlerAtk] == HOLD_EFFECT_BLUNDER_POLICY)
                gBattleStruct->blunderPolicy = TRUE;
            gBattleStruct->moveResultFlags[battler] = MOVE_RESULT_MISSED;
        }
    }

    cv->battlerDef = gBattlerTarget;
    return MOVE_RESULT_CONTINUE;
}

static enum MoveResult StatChangeMirrorArmor(struct BattleCalcValues *cv)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (ShouldSkipStatChangeOnBattler(cv->battlerAtk, battler)
         || gBattleStruct->moveResultFlags[battler] & (MOVE_RESULT_STAT_CHANGE_PREVENTED | MOVE_RESULT_MIRROR_ARMOR_PENDING)
         || cv->battlerAtk == battler)
            continue;

        if (GetBattlerAbility(battler) == ABILITY_MIRROR_ARMOR)
            gBattleStruct->moveResultFlags[battler] = MOVE_RESULT_MIRROR_ARMOR_PENDING;
    }

    return MOVE_RESULT_CONTINUE;
}

static bool32 WillAnyStatChange(void)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_ATTEMPT_STAT_CHANGE)
            return TRUE;
    }
    return FALSE;
}

static enum MoveResult StatChangeBeforeChange(struct BattleCalcValues *cv)
{
    switch (GetMoveEffect(cv->move))
    {
    default:
        if (WillAnyStatChange())
        {
            BattleScriptCall(BattleScript_PlayMoveAnim);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        break;
    case EFFECT_STUFF_CHEEKS:
        // Back up current queue for later use
        memcpy(
            gSpecialStatuses[cv->battlerAtk].statStageQueue2,
            gSpecialStatuses[cv->battlerAtk].statStageQueue,
            sizeof(gSpecialStatuses[cv->battlerAtk].statStageQueue)
        );
        memset(gSpecialStatuses[cv->battlerAtk].statStageQueue, 0, sizeof(gSpecialStatuses[cv->battlerAtk].statStageQueue));
        gSpecialStatuses[cv->battlerAtk].statStageAmount2 = gSpecialStatuses[cv->battlerAtk].statStageAmount;
        gSpecialStatuses[cv->battlerAtk].statStageAmount = 0;
        BattleScriptCall(BattleScript_StuffCheeks);
        return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
    case EFFECT_STOCKPILE:
        gBattleMons[cv->battlerAtk].volatiles.stockpileCounter++;
        PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 1, gBattleMons[cv->battlerAtk].volatiles.stockpileCounter);
        BattleScriptCall(BattleScript_Stockpile);
        return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
    case EFFECT_DEFOG:
        if (WillAnyStatChange() || TryDefogClear(gBattlerAttacker, FALSE))
        {
            BattleScriptCall(BattleScript_PlayMoveAnim);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        break;
    case EFFECT_TIDY_UP:
        if (TryTidyUpClear(FALSE))
        {
            BattleScriptCall(BattleScript_PlayTidyUp);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        else if (WillAnyStatChange())
        {
            BattleScriptCall(BattleScript_PlayMoveAnim);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        break;
    case EFFECT_TAKE_HEART:
        if (WillAnyStatChange() || gBattleMons[cv->battlerAtk].status1 != 0)
        {
            u32 status = gBattleMons[cv->battlerAtk].status1;
            if (status & STATUS1_SLEEP)
                TryDeactivateSleepClause(cv->battlerAtk, gBattlerPartyIndexes[cv->battlerAtk]);

            if (status & STATUS1_PARALYSIS)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_PARALYSIS;
            else if (status & STATUS1_POISON || status & STATUS1_TOXIC_POISON)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_POISON;
            else if (status & STATUS1_BURN)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_BURN;
            else if (status & STATUS1_SLEEP)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_SLEEP;
            else if (status & STATUS1_FREEZE)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FREEZE;
            else if (status & STATUS1_FROSTBITE)
                gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_CURED_FROSTBITE;

            gBattleScripting.battler = cv->battlerAtk;
            gBattleMons[gBattlerAttacker].status1 = 0;
            BtlController_EmitSetMonData(cv->battlerAtk, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[cv->battlerAtk].status1), &gBattleMons[cv->battlerAtk].status1);
            MarkBattlerForControllerExec(cv->battlerAtk);
            BattleScriptCall(BattleScript_TakeHeart);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        break;
    case EFFECT_MEMENTO:
        gBattleStruct->passiveHpUpdate[cv->battlerAtk] = gBattleMons[cv->battlerAtk].hp;
        BtlController_EmitHealthBarUpdate(cv->battlerAtk, B_COMM_TO_CONTROLLER, INSTANT_HP_BAR_DROP);
        MarkBattlerForControllerExec(cv->battlerAtk);
        BattleScriptCall(BattleScript_Memento);
        return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        break;
    case EFFECT_PARTING_SHOT:
        if ((GetConfig(B_PARTING_SHOT_SWITCH) < GEN_7 && CanBattlerSwitch(cv->battlerAtk))
         || WillAnyStatChange())
        {
            BattleScriptCall(BattleScript_PlayMoveAnim);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        break;
    case EFFECT_CLANGOROUS_SOUL:
        if (WillAnyStatChange() && CutThirdOfHp(cv->battlerAtk))
        {
            BattleScriptCall(BattleScript_PlayMoveAnimAndChangeHP);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        else
        {
            gBattlescriptCurrInstr = BattleScript_StatChangeFailed;
            return MOVE_RESULT_FAILURE;
        }
        break;
    case EFFECT_STAT_CHANGE_HALF_HP:
        if (WillAnyStatChange() && TryHalfHp(cv->battlerAtk))
        {
            BattleScriptCall(BattleScript_PlayMoveAnim);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        else
        {
            gBattlescriptCurrInstr = BattleScript_StatChangeFailed;
            return MOVE_RESULT_FAILURE;
        }
        break;
    case EFFECT_BELLY_DRUM:
        if (WillAnyStatChange() && TryBellyDrum(cv->battlerAtk))
        {
            BattleScriptCall(BattleScript_PlayMoveAnimAndChangeHP);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        else
        {
            gBattlescriptCurrInstr = BattleScript_StatChangeFailed;
            return MOVE_RESULT_FAILURE;
        }
        break;
    case EFFECT_CHARGE:
        if (WillAnyStatChange() || gBattleMons[cv->battlerAtk].volatiles.chargeTimer == 0)
        {
            gBattleMons[cv->battlerAtk].volatiles.chargeTimer = 2;
            BattleScriptCall(BattleScript_PlayMoveAnim);
            return MOVE_RESULT_RUN_SCRIPT_INCREMENT;
        }
        else
        {
            gBattlescriptCurrInstr = BattleScript_StatChangeFailed;
            return MOVE_RESULT_FAILURE;
        }
        break;
    }

    #define MOVE_RESULT_HANDLE_FAILURE (MOVE_RESULT_MISSED | MOVE_RESULT_MIRROR_ARMOR_PENDING | MOVE_RESULT_ATTEMPT_STAT_CHANGE | MOVE_RESULT_STAT_CHANGE_PREVENTED)
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_HANDLE_FAILURE)
            return MOVE_RESULT_CONTINUE;
    }
    #undef MOVE_RESULT_HANDLE_FAILURE

    gBattlescriptCurrInstr = BattleScript_ButItFailed;
    return MOVE_RESULT_FAILURE;
}

static enum MoveResult StatChangeTryChange(struct BattleCalcValues *cv)
{
    struct StatChange st = {
        .ignoreCertainFailure = TRUE,
    };

    while (gBattleStruct->statChangeBattler < gBattlersCount)
    {
        cv->battlerDef = GetTargetBySlot(cv->battlerAtk, gBattleStruct->statChangeBattler);

        if (gBattleStruct->moveResultFlags[cv->battlerDef] & MOVE_RESULT_MISSED)
        {
            gBattleScripting.battler = cv->battlerDef;
            gBattleStruct->statChangeBattler++;
            BattleScriptCall(BattleScript_BattlerAvoidedAttack);
            return MOVE_RESULT_RUN_SCRIPT;
        }

        if (ShouldSkipStatChangeOnBattler(cv->battlerAtk, cv->battlerDef))
        {
            gBattleStruct->statChangeBattler++;
            continue;
        }

        st.certain = cv->battlerAtk == cv->battlerDef;

        bool32 runScript = FALSE;
        st.statStageQueue = gSpecialStatuses[cv->battlerDef].statStageQueue;
        st.statStageAmount = gSpecialStatuses[cv->battlerDef].statStageAmount;

        if (TryStatChange(cv, &st) != STAT_CHANGE_DIDNT_WORK)
            runScript = TRUE;

        if (st.nextBattler) // Or done
        {
            st.nextBattler = FALSE;
            gBattleStruct->negativeAnimPlayed = 0;
            gBattleStruct->positiveAnimPlayed = 0;
            gBattleStruct->statChangeBattler++;

            if (st.moveScript != NULL)
            {
                gBattlescriptCurrInstr = st.moveScript;
                if (!runScript)
                    return MOVE_RESULT_RUN_SCRIPT;
            }
        }

        if (runScript)
        {
            BattleScriptCall(st.script);
            return MOVE_RESULT_RUN_SCRIPT;
        }
    }

    cv->battlerDef = gBattlerTarget;
    return MOVE_RESULT_DONE;
}

static enum MoveResult (*const sStatChangeHandlers[])(struct BattleCalcValues *cv) =
{
    [STAT_CHANGE_SUBSTITUTE] = StatChangeSubstitute,
    [STAT_CHANGE_CAN_ANY_CHANGE] = StatChangeCanAnyChange,
    [STAT_CHANGE_ACCURACY] = StatChangeAccuracy,
    [STAT_CHANGE_MIRROR_ARMOR] = StatChangeMirrorArmor,
    [STAT_CHANGE_BEFORE_CHANGE] = StatChangeBeforeChange,
    [STAT_CHANGE_TRY_CHANGE] = StatChangeTryChange,
};

enum MoveResult DoStatChange(void)
{
    enum MoveResult result = MOVE_RESULT_DONE;

    struct BattleCalcValues cv = {
        .battlerAtk = gBattlerAttacker,
        .battlerDef = gBattlerTarget,
        .move = gCurrentMove,
        .moveEffect = GetMoveEffect(gCurrentMove),
    };

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        cv.abilities[battler] = GetBattlerAbility(battler);
        cv.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }

    while (gBattleStruct->eventState.resolution < STAT_CHANGE_COUNT)
    {
        result = sStatChangeHandlers[gBattleStruct->eventState.resolution](&cv);
        switch (result)
        {
        case MOVE_RESULT_CONTINUE:
            gBattleStruct->eventState.resolution++;
            break;
        case MOVE_RESULT_RUN_SCRIPT_INCREMENT:
            gBattleStruct->eventState.resolution++;
            return result;
        case MOVE_RESULT_RUN_SCRIPT:
            return result;
        case MOVE_RESULT_DONE:
        case MOVE_RESULT_FAILURE:
            gBattleStruct->eventState.resolution = 0;
            gBattleStruct->statChangeBattler = 0;
            ClearStatChangeValues();
            return result;
        }
    }

    return result;
}


// Utility functions

static void ValidateBattlers(void)
{
    assertf(gBattlerAttacker < MAX_BATTLERS_COUNT, "invalid gBattlerAttacker: %d\nmove: %S", gBattlerAttacker, GetMoveName(gCurrentMove));
    assertf(gBattlerTarget < MAX_BATTLERS_COUNT, "invalid gBattlerTarget: %d\nmove: %S", gBattlerTarget, GetMoveName(gCurrentMove));

    // More calls to SaveBattlerAttacker than RestoreBattlerAttacker.
    assertf(gBattleStruct->savedAttackerCount == 0, "savedAttackerCount is greater than 0");

    // More calls to SaveBattlerTarget than RestoreBattlerTarget.
    assertf(gBattleStruct->savedTargetCount == 0, "savedTargetCount is greater than 0");
}

static enum Move GetOriginallyUsedMove(enum Move chosenMove)
{
    return (gChosenMove == MOVE_UNAVAILABLE) ? MOVE_NONE : gChosenMove;
}

static void SetSameMoveTurnValues(enum BattleMoveEffects moveEffect)
{
    bool32 increment = IsAnyTargetAffected()
                    && !gBattleStruct->unableToUseMove
                    && gLastResultingMoves[gBattlerAttacker] == gCurrentMove;

    switch (moveEffect)
    {
    case EFFECT_FURY_CUTTER:
        if (increment && gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter < 5)
            gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter++;
        else
            gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter = 0;
        break;
    case EFFECT_ROLLOUT:
        if (increment && ++gBattleMons[gBattlerAttacker].volatiles.rolloutTimer < 5)
        {
            gBattleMons[gBattlerAttacker].volatiles.multipleTurns = TRUE;
            gLockedMoves[gBattlerAttacker] = gCurrentMove;
        }
        else
        {
            gBattleMons[gBattlerAttacker].volatiles.multipleTurns = FALSE;
            gBattleMons[gBattlerAttacker].volatiles.rolloutTimer = 0;
        }
        break;
    case EFFECT_ECHOED_VOICE:
        if (!gBattleStruct->unableToUseMove) // Increment even if targets unaffected
            gBattleStruct->incrementEchoedVoice = TRUE;
        break;
    default: // not consecutive
        gBattleMons[gBattlerAttacker].volatiles.rolloutTimer = 0;
        gBattleMons[gBattlerAttacker].volatiles.furyCutterCounter = 0;
        break;
    }

    if (increment)
        gBattleMons[gBattlerAttacker].volatiles.metronomeItemCounter++;
    else
        gBattleMons[gBattlerAttacker].volatiles.metronomeItemCounter = 0;
}

static void TryClearChargeVolatile(enum Type moveType)
{
    if (B_CHARGE < GEN_9) // Prior to gen9, charge is cleared during the end turn
        return;

    if (moveType == TYPE_ELECTRIC && gBattleMons[gBattlerAttacker].volatiles.chargeTimer == 1)
        gBattleMons[gBattlerAttacker].volatiles.chargeTimer = 0;

    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
    {
        if (gBattleMons[battler].volatiles.chargeTimer == 2) // Has been set this turn by move or ability
            gBattleMons[battler].volatiles.chargeTimer--;
    }
}

static inline bool32 IsBattlerUsingBeakBlast(enum BattlerId battler)
{
    if (gChosenActionByBattler[battler] != B_ACTION_USE_MOVE)
        return FALSE;
    if (GetMoveEffect(gChosenMoveByBattler[battler]) != EFFECT_BEAK_BLAST)
        return FALSE;
    return !HasBattlerActedThisTurn(battler);
}

static void RequestNonVolatileChange(enum BattlerId battlerAtk)
{
    BtlController_EmitSetMonData(
        battlerAtk,
        B_COMM_TO_CONTROLLER,
        REQUEST_STATUS_BATTLE,
        0,
        sizeof(gBattleMons[battlerAtk].status1),
        &gBattleMons[battlerAtk].status1);
    MarkBattlerForControllerExec(battlerAtk);
}

static enum Move GetMirrorMoveMove(void)
{
    s32 i, validMovesCount;
    enum Move move = MOVE_NONE;
    enum Move validMoves[MAX_BATTLERS_COUNT] = {MOVE_NONE};

    for (validMovesCount = 0, i = 0; i < gBattlersCount; i++)
    {
        if (i != gBattlerAttacker)
        {
            move = gBattleStruct->lastTakenMoveFrom[gBattlerAttacker][i];
            if (move != MOVE_NONE && move != MOVE_UNAVAILABLE)
            {
                validMoves[validMovesCount] = move;
                validMovesCount++;
            }
        }
    }

    move = gBattleStruct->lastTakenMove[gBattlerAttacker];
    if ((move == MOVE_NONE || move == MOVE_UNAVAILABLE) && validMovesCount != 0)
        move = validMoves[Random() % validMovesCount];

    if (GetActiveGimmick(gBattlerAttacker) == GIMMICK_Z_MOVE && !IsBattleMoveStatus(move))
        move = GetTypeBasedZMove(move);

    return move;
}

static bool32 InvalidMetronomeMove(u32 move)
{
    return GetMoveEffect(move) == EFFECT_PLACEHOLDER
        || IsMoveMetronomeBanned(move);
}

static enum Move GetMetronomeMove(void)
{
    enum Move move = MOVE_NONE;

#if B_METRONOME_MOVES >= GEN_9
    u32 moveCount = MOVES_COUNT_GEN9;
#elif B_METRONOME_MOVES >= GEN_8
    u32 moveCount = MOVES_COUNT_GEN8;
#elif B_METRONOME_MOVES >= GEN_7
    u32 moveCount = MOVES_COUNT_GEN7;
#elif B_METRONOME_MOVES >= GEN_6
    u32 moveCount = MOVES_COUNT_GEN6;
#elif B_METRONOME_MOVES >= GEN_5
    u32 moveCount = MOVES_COUNT_GEN5;
#elif B_METRONOME_MOVES >= GEN_4
    u32 moveCount = MOVES_COUNT_GEN4;
#elif B_METRONOME_MOVES >= GEN_3
    u32 moveCount = MOVES_COUNT_GEN3;
#elif B_METRONOME_MOVES >= GEN_2
    u32 moveCount = MOVES_COUNT_GEN2;
#else
    u32 moveCount = MOVES_COUNT_GEN1;
#endif

    move = RandomUniformExcept(RNG_METRONOME, 1, moveCount - 1, InvalidMetronomeMove);
    return move;
}

static enum Move GetAssistMove(void)
{
    enum Move move = MOVE_NONE;
    u32 chooseableMovesNo = 0;
    struct Pokemon *party;
    u8 battlerByPartyId[PARTY_SIZE];
    enum Move validMoves[PARTY_SIZE * MAX_MON_MOVES] = {MOVE_NONE};

    party = GetBattlerParty(gBattlerAttacker);

    for (u32 i = 0; i < PARTY_SIZE; i++)
        battlerByPartyId[i] = MAX_BATTLERS_COUNT;
    for (u32 battler = 0; battler < gBattlersCount; battler++)
    {
        if (!IsBattlerAlly(battler, gBattlerAttacker))
            continue;

        if (gBattlerPartyIndexes[battler] < PARTY_SIZE)
            battlerByPartyId[gBattlerPartyIndexes[battler]] = battler;
    }

    for (u32 monId = 0; monId < PARTY_SIZE; monId++)
    {
        if (monId == gBattlerPartyIndexes[gBattlerAttacker])
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;

        for (u32 moveId = 0; moveId < MAX_MON_MOVES; moveId++)
        {
            enum Move move;

            if (battlerByPartyId[monId] != MAX_BATTLERS_COUNT)
                move = gBattleMons[battlerByPartyId[monId]].moves[moveId];
            else
                move = GetMonData(&party[monId], MON_DATA_MOVE1 + moveId);

            if (IsMoveAssistBanned(move))
                continue;

            validMoves[chooseableMovesNo++] = move;
        }
    }

    if (chooseableMovesNo)
        move = validMoves[Random() % chooseableMovesNo];

    return move;
}

enum Move GetNaturePowerMove(void)
{
    enum Move move = gBattleEnvironmentInfo[gBattleEnvironment].naturePower;

    if (gFieldTimers.terrain != B_TERRAIN_NONE)
        move = gBattleTerrainInfo[gFieldTimers.terrain].naturePowerMove;
    else if (gBattleEnvironmentInfo[gBattleEnvironment].naturePower == MOVE_NONE)
        move = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT;

    return move;
}

static enum Move GetSleepTalkMove(void)
{
    enum Move move = MOVE_NONE;

    u32 i, unusableMovesBits = 0, movePosition;

    if (GetBattlerAbility(gBattlerAttacker) != ABILITY_COMATOSE
     && !(gBattleMons[gBattlerAttacker].status1 & STATUS1_SLEEP))
        return move;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (IsMoveSleepTalkBanned(gBattleMons[gBattlerAttacker].moves[i])
            || gBattleMoveEffects[GetMoveEffect(gBattleMons[gBattlerAttacker].moves[i])].twoTurnEffect)
            unusableMovesBits |= (1 << (i));
    }

    unusableMovesBits = CheckMoveLimitations(gBattlerAttacker, unusableMovesBits, ~(MOVE_LIMITATION_PP | MOVE_LIMITATION_CHOICE_ITEM | MOVE_LIMITATION_UNUSABLE));
    if (unusableMovesBits == ALL_MOVES_MASK) // all 4 moves cannot be chosen
        return move;

    // Set Sleep Talk as used move, so it works with Last Resort.
    gBattleMons[gBattlerAttacker].volatiles.usedMoves |= 1u << gCurrMovePos;
    do
    {
        movePosition = MOD(Random(), MAX_MON_MOVES);
    } while ((1u << movePosition) & unusableMovesBits);

    move = gBattleMons[gBattlerAttacker].moves[movePosition];
    gCurrMovePos = movePosition;

    return move;
}

static enum Move GetCopycatMove(void)
{
    if (gLastUsedMove == MOVE_NONE
     || gLastUsedMove == MOVE_UNAVAILABLE
     || IsMoveCopycatBanned(gLastUsedMove)
     || IsZMove(gLastUsedMove))
        return MOVE_NONE;

    return gLastUsedMove;
}

static enum Move GetMeFirstMove(void)
{
    enum Move move = GetBattlerChosenMove(gBattlerTarget);

    if (IsBattleMoveStatus(move)
     || IsMoveMeFirstBanned(move)
     || HasBattlerActedThisTurn(gBattlerTarget))
        return MOVE_NONE;

    return move;
}

static bool32 CanBattlerBounceBackMove(struct BattleCalcValues *cv)
{
    return TryMagicBounce(cv) || TryMagicCoat(cv);
}

static bool32 TryMagicBounce(struct BattleCalcValues *cv)
{
    if (!MoveCanBeBouncedBack(cv->move))
        return FALSE;

    if (gBattleStruct->bouncedMoveIsUsed)
        return FALSE;

    if (cv->abilities[cv->battlerDef] != ABILITY_MAGIC_BOUNCE)
        return FALSE;

    gBattleStruct->magicBouncePending |= 1u << cv->battlerDef;
    return TRUE;
}

static bool32 TryMagicCoat(struct BattleCalcValues *cv)
{
    if (!MoveCanBeBouncedBack(cv->move))
        return FALSE;

    if (gBattleStruct->bouncedMoveIsUsed)
        return FALSE;

    if (!gProtectStructs[cv->battlerDef].bounceMove)
        return FALSE;

    gBattleStruct->magicCoatPending |= 1u << cv->battlerDef;
    return TRUE;
}

static bool32 TryActivatePowderStatus(enum Move move)
{
    if (!gBattleMons[gBattlerAttacker].volatiles.powder)
        return FALSE;
    if (GetBattleMoveType(move) == TYPE_FIRE)
        return TRUE;
    return FALSE;
}

static void CalculateMagnitudeDamage(void)
{
    u32 magnitude = RandomUniform(RNG_MAGNITUDE, 0, 99);

    if (magnitude < 5)
    {
        gBattleStruct->magnitudeBasePower = 10;
        magnitude = 4;
    }
    else if (magnitude < 15)
    {
        gBattleStruct->magnitudeBasePower = 30;
        magnitude = 5;
    }
    else if (magnitude < 35)
    {
        gBattleStruct->magnitudeBasePower = 50;
        magnitude = 6;
    }
    else if (magnitude < 65)
    {
        gBattleStruct->magnitudeBasePower = 70;
        magnitude = 7;
    }
    else if (magnitude < 85)
    {
        gBattleStruct->magnitudeBasePower = 90;
        magnitude = 8;
    }
    else if (magnitude < 95)
    {
        gBattleStruct->magnitudeBasePower = 110;
        magnitude = 9;
    }
    else
    {
        gBattleStruct->magnitudeBasePower = 150;
        magnitude = 10;
    }

    PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff1, 2, magnitude)
}

static void UpdateStallMons(struct BattleCalcValues *cv)
{
    if (IsBattlerTurnDamaged(cv->battlerDef, INCLUDING_SUBSTITUTES) || IsBattleMoveStatus(cv->move))
        return;

    if (IsBattlerProtected(cv))
        return;

    enum MoveTarget target = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
    if (!IsDoubleBattle() || target == TARGET_SELECTED)
    {
        if (gSpecialStatuses[cv->battlerDef].updateStallMons)
            gAiBattleData->playerStallMons[gBattlerPartyIndexes[cv->battlerDef]]++;
    }
    //  Handling for moves that target multiple opponents in doubles not handled currently
}

// Move Stat Change Functions

static bool32 TryBellyDrum(enum BattlerId battler)
{
    if (CompareStat(battler, STAT_ATK, MAX_STAT_STAGE, CMP_EQUAL, ABILITY_NONE))
        return FALSE;

    u32 halfHp = GetNonDynamaxMaxHP(battler) / 2;

    if (halfHp == 0)
        halfHp = 1;

    if (gBattleMons[battler].hp > halfHp)
    {
        SetPassiveDamageAmount(battler, halfHp);
        return TRUE;
    }

    return FALSE;
}

static bool32 TryHalfHp(enum BattlerId battler)
{
    if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_STAT_CHANGE_PREVENTED)
        return FALSE;

    u32 halfHp = GetNonDynamaxMaxHP(battler) / 2;

    if (halfHp == 0)
        halfHp = 1;

    if (gBattleMons[battler].hp > halfHp)
    {
        SetPassiveDamageAmount(battler, halfHp);
        return TRUE;
    }

    return FALSE;
}

static bool32 CutThirdOfHp(enum BattlerId battler)
{
    if (gBattleStruct->moveResultFlags[battler] & MOVE_RESULT_STAT_CHANGE_PREVENTED)
        return FALSE;

    u32 thirdHp = GetNonDynamaxMaxHP(battler) / 3;

    if (thirdHp == 0)
        thirdHp = 1;

    if (gBattleMons[battler].hp > thirdHp)
    {
        SetPassiveDamageAmount(battler, thirdHp);
        return TRUE;
    }

    return FALSE;
}
