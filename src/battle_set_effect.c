#include "global.h"
#include "battle.h"
#include "battle_set_effect.h"
#include "battle_util.h"
#include "battle_script_commands.h"
#include "battle_hold_effects.h"
#include "battle_message.h"
#include "battle_ai_record.h"
#include "battle_scripts.h"
#include "battle_environment.h"
#include "battle_stat_change.h"
#include "battle_controllers.h"
#include "battle_dynamax.h"
#include "battle_gimmick.h"
#include "battle_terastal.h"
#include "item.h"
#include "pokemon.h"
#include "util.h"
#include "move.h"
#include "random.h"
#include "string_util.h"
#include "config/battle.h"

static inline bool32 IgnoreTargetingForMoveEffect(enum MoveEffect moveEffect);
static bool32 DoesSubstituteBlockMoveEffectOnTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum MoveEffect moveEffect);
static bool32 IsFinalStrikeEffect(enum MoveEffect moveEffect);

static void HandleSetEffectNone(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattlescriptCurrInstr = se->script;

    assertf(se->moveEffect != MOVE_EFFECT_FLORAL_HEALING, "no effect assigned to MOVE_EFFECT_FLORAL_HEALING");
}

static void HandleSetEffectNonVolatile(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsSafeguardProtected(cv->battlerAtk, se->effectBattler, cv->abilities[cv->battlerAtk]) && !se->primary)
    {
        gBattlescriptCurrInstr = se->script;
    }
    else if (CanSetNonVolatileStatus(
                cv->battlerAtk,
                se->effectBattler,
                cv->abilities[cv->battlerAtk],
                cv->abilities[se->effectBattler],
                se->moveEffect,
                CHECK_TRIGGER))
    {
        SetNonVolatileStatus(cv->battlerAtk, se->effectBattler, se->moveEffect, se->script, TRIGGER_ON_MOVE);
    }
    else
    {
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectConfusion(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!CanBeConfused(cv->battlerAtk, se->effectBattler))
    {
        gBattlescriptCurrInstr = se->script;
    }
    else
    {
        gBattleMons[se->effectBattler].volatiles.confusionTimer = RandomUniform(RNG_CONFUSION_TURNS, 2, B_CONFUSION_TURNS); // 2-5 turns
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectConfusion;
    }
}

static void HandleSetEffectFlinch(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->abilities[se->effectBattler] == ABILITY_INNER_FOCUS)
    {
        if (se->primary || se->certain)
        {
            gLastUsedAbility = ABILITY_INNER_FOCUS;
            gBattlerAbility = se->effectBattler;
            RecordAbilityBattle(se->effectBattler, ABILITY_INNER_FOCUS);
            gBattlescriptCurrInstr = se->script;
        }
        else
        {
            gBattlescriptCurrInstr = se->script;
        }
    }
    else if (gBattleMons[se->effectBattler].volatiles.flinched)
    {
        gBattlescriptCurrInstr = se->script;
    }
    else if (!HasBattlerActedThisTurn(se->effectBattler)
          && GetActiveGimmick(se->effectBattler) != GIMMICK_DYNAMAX)
    {
        gBattleMons[se->effectBattler].volatiles.flinched = TRUE;
        gBattlescriptCurrInstr = se->script;
    }
    else
    {
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectAbsorb(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleStruct->moveDamage[cv->battlerDef] > 0
     && IsBattlerTurnDamaged(cv->battlerDef, INCLUDING_SUBSTITUTES)
     && IsBattlerAlive(cv->battlerAtk))
    {
        u32 absorbPercentage = se->additionalEffect->argument.absorbPercentage;

        assertf(absorbPercentage != 0, "Missing absorb percentage for %S", gMovesInfo[cv->move].name)
        {
            return;
        }

        s32 healAmount = (gBattleStruct->moveDamage[cv->battlerDef] * absorbPercentage / 100);
        healAmount = GetDrainedBigRootHp(cv->battlerAtk, healAmount);
        gEffectBattler = cv->battlerAtk;
        gBattlerAbility = gBattleScripting.battler = cv->battlerDef;

        if (cv->abilities[cv->battlerDef] == ABILITY_LIQUID_OOZE
         && (GetMoveEffect(cv->move)!= EFFECT_DREAM_EATER || GetConfig(B_DREAM_EATER_LIQUID_OOZE) >= GEN_5))
        {
            SetPassiveDamageAmount(cv->battlerAtk, healAmount);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB_OOZE;
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_EffectAbsorbLiquidOoze;
        }
        else if (!IsBattlerAtMaxHp(cv->battlerAtk) || GetConfig(B_ABSORB_MESSAGE) < GEN_5)
        {
            SetHealAmount(cv->battlerAtk, healAmount);
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_ABSORB;
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_EffectAbsorb;
        }
    }
}

static void HandleSetEffectRandomFromList(struct BattleCalcValues *cv, struct SetEffect *se)
{
    const enum MoveEffect *sRandomFromListEffects = se->additionalEffect->argument.randomMoveEffects;
    u32 validEffectCount = 0;

    while (validEffectCount < MAX_RANDOM_ADDITIONAL_EFFECTS && sRandomFromListEffects[validEffectCount] != MOVE_EFFECT_NONE)
    {
        validEffectCount++;
    }

    assertf(validEffectCount != 0, "Missing or empty randomMoveEffects array for move %S", gMovesInfo[gCurrentMove].name)
    {
        return;
    }

    u32 chosenMoveEffect = RandomUniform(RNG_RANDOM_FROM_LIST, 0, validEffectCount - 1);
    if (sRandomFromListEffects[chosenMoveEffect] == MOVE_EFFECT_BURN)
        gBattleStruct->triAttackBurn = TRUE;

    se->moveEffect = sRandomFromListEffects[chosenMoveEffect];
    SetMoveEffect(cv, se);
}

static void HandleSetEffectUproar(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.uproarTurns)
    {
        gBattleMons[se->effectBattler].volatiles.multipleTurns = TRUE;
        gLockedMoves[se->effectBattler] = cv->move;
        gBattleMons[se->effectBattler].volatiles.uproarTurns = B_UPROAR_TURNS >= GEN_5
                                                             ? B_UPROAR_TURN_COUNT - 2
                                                             : RandomUniform(RNG_CONFUSION_TURNS, 2, B_UPROAR_TURN_COUNT);

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectUproar;
    }
    else
    {
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectPayday(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsOnPlayerSide(cv->battlerAtk))
    {
        u16 payday = gPaydayMoney;
        enum MoveTarget moveTarget = GetBattlerMoveTargetType(cv->battlerAtk, cv->move);
        gPaydayMoney += (gBattleMons[cv->battlerAtk].level * 5);
        if (payday > gPaydayMoney)
            gPaydayMoney = 0xFFFF;

        // For a move that hits multiple targets (i.e. Make it Rain)
        // we only want to print the message on the final hit
        if (!(NumAffectedSpreadMoveTargets() > 1 && GetNextTarget(moveTarget, TRUE) != MAX_BATTLERS_COUNT))
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_MoveEffectPayDay;
        }
        else
        {
            gBattlescriptCurrInstr = se->script;
        }
    }
    else
    {
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectWrap(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.wrapped)
    {
        gBattlescriptCurrInstr = se->script;
    }
    else
    {
        SetWrapTurns(se->effectBattler, GetBattlerHoldEffect(cv->battlerAtk));
        gBattleMons[se->effectBattler].volatiles.wrapped = TRUE;
        gBattleMons[se->effectBattler].volatiles.wrappedMove = cv->move;
        gBattleMons[se->effectBattler].volatiles.wrappedBy = cv->battlerAtk;
        gBattleCommunication[MULTISTRING_CHOOSER] = se->additionalEffect->argument.wrapped;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectWrap;
    }
}

static void HandleSetEffectStatChange(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum Stat i = STAT_ATK; i < NUM_BATTLE_STATS; i++)
    {
        enum Stat stat = sAccurateStatOrder[i];
        s32 stage = GetStatStage(stat, se->additionalEffect);

        if (stage == 0)
            continue;

        if (se->additionalEffect->moveEffect == MOVE_EFFECT_STAT_MINUS)
            stage = -1 * stage;

        SetStatChange(se->effectBattler, stat, stage);
        if (se->additionalEffect->onSide)
            SetStatChange(GetPartnerBattler(se->effectBattler), stat, stage);
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
}

static void HandleSetEffectRemoveArgType(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Type type = GetMoveArgType(cv->move); // TODO use the arg field from move effects

    BattleScriptPush(se->script);

    switch (type)
    {
    case TYPE_FIRE: // Burn Up
        gBattlescriptCurrInstr = BattleScript_RemoveFireType;
        break;
    case TYPE_ELECTRIC: // Double Shot
        gBattlescriptCurrInstr = BattleScript_RemoveElectricType;
        break;
    default:
        gBattlescriptCurrInstr = BattleScript_RemoveGenericType;
        break;
    }
    RemoveBattlerType(se->effectBattler, type);
}

static void HandleSetEffectRecharge(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (B_SKIP_RECHARGE == GEN_1 && !IsBattlerAlive(cv->battlerDef))  // Skip recharge if gen 1 and foe is KO'd
        return;

    gBattleMons[se->effectBattler].volatiles.rechargeTimer = 2;
    gLockedMoves[se->effectBattler] = cv->move;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectRage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattleMons[se->effectBattler].volatiles.rage = TRUE;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectPreventEscape(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.escapePrevention)
    {
        gBattleMons[se->effectBattler].volatiles.escapePrevention = TRUE;
        gBattleMons[se->effectBattler].volatiles.battlerPreventingEscape = cv->battlerAtk;
    }
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectNightmare(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattleMons[se->effectBattler].volatiles.nightmare = TRUE;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectGlaiveRush(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gBattleMons[cv->battlerAtk].volatiles.glaiveRush = TRUE;
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectRemoveStatus(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 argStatus = GetMoveEffectArg_Status(gCurrentMove); // TODO: use the arg field in move effect
    if ((gBattleMons[se->effectBattler].status1 & argStatus)
     && (NumAffectedSpreadMoveTargets() > 1 || !IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler])))
    {
        gBattleScripting.battler = se->effectBattler;
        gBattleMons[se->effectBattler].status1 &= ~(argStatus);
        BtlController_EmitSetMonData(se->effectBattler, 0, REQUEST_STATUS_BATTLE, 0, 4, &gBattleMons[se->effectBattler].status1);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPush(se->script);

        switch (argStatus)
        {
        case STATUS1_PARALYSIS:
            gBattlescriptCurrInstr = BattleScript_TargetPRLZHeal;
            break;
        case STATUS1_SLEEP:
            TryDeactivateSleepClause(se->effectBattler, gBattlerPartyIndexes[se->effectBattler]);
            gBattlescriptCurrInstr = BattleScript_TargetWokeUp;
            break;
        case STATUS1_BURN:
            gBattlescriptCurrInstr = BattleScript_TargetBurnHeal;
            break;
        case STATUS1_FREEZE:
            gBattlescriptCurrInstr = BattleScript_BattlerDefrosted;
            break;
        case STATUS1_FROSTBITE:
            gBattlescriptCurrInstr = BattleScript_BattlerFrostbiteHealed;
            break;
        case STATUS1_POISON:
        case STATUS1_TOXIC_POISON:
        case STATUS1_PSN_ANY:
            gBattlescriptCurrInstr = BattleScript_TargetPoisonHealed;
            break;
        }
    }
}

static void HandleSetEffectThrash(struct BattleCalcValues *cv, struct SetEffect *se)
{
    // Petal Dance (dance move) doesn't lock mons that copy the move with Dancer
    if (gSpecialStatuses[se->effectBattler].dancerUsedMove || gBattleMons[se->effectBattler].volatiles.rampageTurns)
    {
        gBattlescriptCurrInstr = se->script;
    }
    else
    {
        gBattleMons[se->effectBattler].volatiles.multipleTurns = TRUE;
        gLockedMoves[se->effectBattler] = cv->move;
        gBattleMons[se->effectBattler].volatiles.rampageTurns = RandomUniform(RNG_RAMPAGE_TURNS, 2, B_RAMPAGE_TURNS);
    }
}

static void HandleSetEffectClearSmog(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Stat stat;
    for (stat = 0; stat < NUM_BATTLE_STATS; stat++)
    {
        if (gBattleMons[se->effectBattler].statStages[stat] != DEFAULT_STAT_STAGE)
            break;
    }
    if (IsBattlerTurnDamaged(se->effectBattler, EXCLUDING_SUBSTITUTES) && stat != NUM_BATTLE_STATS)
    {
        for (u32 i = 0; i < NUM_BATTLE_STATS; i++)
            gBattleMons[se->effectBattler].statStages[i] = DEFAULT_STAT_STAGE;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectClearSmog;
    }
}

static void HandleSetEffectFlameBurst(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId partner = GetPartnerBattler(se->effectBattler);

    if (IsBattlerAlive(partner)
     && !IsSemiInvulnerable(partner, CHECK_ALL)
     && GetBattlerAbility(partner) != ABILITY_MAGIC_GUARD)
    {
        gEffectBattler = partner;
        SetPassiveDamageAmount(partner, gBattleMons[partner].maxHP / 16);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectFlameBurst;
    }
}

static void HandleSetEffectFeint(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 removeProtect = FALSE;

    if (gProtectStructs[se->effectBattler].protected != PROTECT_NONE
     && gProtectStructs[se->effectBattler].protected != PROTECT_MAX_GUARD)
    {
        gProtectStructs[se->effectBattler].protected = PROTECT_NONE;
        gBattleMons[se->effectBattler].volatiles.consecutiveMoveUses = 0;
        removeProtect = TRUE;
    }
    enum BattlerId partner = GetPartnerBattler(se->effectBattler);
    if (GetProtectType(gProtectStructs[partner].protected) == PROTECT_TYPE_SIDE)
    {
        gProtectStructs[partner].protected = PROTECT_NONE;
        gBattleMons[partner].volatiles.consecutiveMoveUses = 0;
        removeProtect = TRUE;
    }
    if (removeProtect)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = se->additionalEffect->argument.brokeProtect;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectFeint;
    }
}

static void HandleSetEffectHappyHour(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsOnPlayerSide(cv->battlerAtk) && !gBattleStruct->moneyMultiplierMove)
    {
        gBattleStruct->moneyMultiplier *= 2;
        gBattleStruct->moneyMultiplierMove = 1;
    }
    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectCoreEnforcer(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (HasBattlerActedThisTurn(se->effectBattler)
     && gBattleStruct->battlerState[se->effectBattler].isFirstTurn != 2
     && !NoAliveMonsForEitherParty())
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectCoreEnforcer;
    }
}

static void HandleSetEffectThroatChop(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.throatChopTimer == 0)
    {
        gBattleMons[se->effectBattler].volatiles.throatChopTimer = B_THROAT_CHOP_TIMER;
        gBattlescriptCurrInstr = se->script;
    }
}

static void HandleSetEffectIncinerate(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (cv->abilities[se->effectBattler] == ABILITY_STICKY_HOLD)
        return;

    if (gItemsInfo[gBattleMons[se->effectBattler].item].pocket == POCKET_BERRIES
     || (B_INCINERATE_GEMS >= GEN_6 && GetItemHoldEffect(gBattleMons[se->effectBattler].item) == HOLD_EFFECT_GEMS))
    {
        gLastUsedItem = gBattleMons[se->effectBattler].item;
        gBattleMons[se->effectBattler].item = ITEM_NONE;
        CheckSetUnburden(se->effectBattler);

        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[se->effectBattler].item), &gBattleMons[se->effectBattler].item);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectIncinerate;
    }
}

static void HandleSetEffectBugBite(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetBattlerHoldEffect(se->effectBattler) == HOLD_EFFECT_JABOCA_BERRY || gSpecialStatuses[se->effectBattler].berryReduced)
    {
        // jaboca berry / resist berries trigger instead of being stolen
        gBattlescriptCurrInstr = se->script;
    }
    else if (GetItemPocket(gBattleMons[se->effectBattler].item) == POCKET_BERRIES
        && cv->abilities[se->effectBattler] != ABILITY_STICKY_HOLD)
    {
        // target loses their berry
        gLastUsedItem = gBattleMons[se->effectBattler].item;
        gBattleMons[se->effectBattler].item = ITEM_NONE;
        CheckSetUnburden(se->effectBattler);

        BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_HELDITEM_BATTLE, 0, sizeof(gBattleMons[se->effectBattler].item), &gBattleMons[se->effectBattler].item);
        MarkBattlerForControllerExec(se->effectBattler);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectBugBite;
    }
}

static void HandleSetEffectRecoilHp25(struct BattleCalcValues *cv, struct SetEffect *se)
{
    s32 recoil = (gBattleMons[se->effectBattler].maxHP) / 4;
    if (B_UPDATED_MOVE_DATA >= GEN_5 && (gBattleMons[se->effectBattler].maxHP % 4) >= 2) // Account for standard rounding (Gen5+)
        recoil++;
    if (recoil == 0)
        recoil = 1;

    SetPassiveDamageAmount(se->effectBattler, recoil);
    TryUpdateEvolutionTracker(IF_RECOIL_DAMAGE_GE, gBattleStruct->passiveHpUpdate[cv->battlerAtk], MOVE_NONE);
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectRecoilHP25;
}

static void HandleSetEffectTrapBoth(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!(gBattleMons[se->effectBattler].volatiles.escapePrevention || gBattleMons[cv->battlerAtk].volatiles.escapePrevention))
    {
        if (!gBattleMons[se->effectBattler].volatiles.escapePrevention)
            gBattleMons[se->effectBattler].volatiles.battlerPreventingEscape = cv->battlerAtk;

        if (!gBattleMons[cv->battlerAtk].volatiles.escapePrevention)
            gBattleMons[cv->battlerAtk].volatiles.battlerPreventingEscape = se->effectBattler;

        gBattleMons[se->effectBattler].volatiles.escapePrevention = TRUE;
        gBattleMons[cv->battlerAtk].volatiles.escapePrevention = TRUE;

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_BothCanNoLongerEscape;
    }
}

static void HandleSetEffectRound(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (IsDoubleBattle())
    {
        u32 i;
        u32 j = 0;
        u32 k = 0;
        u32 currRounder = 0;
        u8 roundUsers[3] = {0xFF, 0xFF, 0xFF};
        u8 nonRoundUsers[3] = {0xFF, 0xFF, 0xFF};
        for (i = 0; i < gBattlersCount; i++)
        {
            if (gBattlerByTurnOrder[i] == gBattlerAttacker)
            {
                currRounder = i + 1; // Current battler going after attacker
                break;
            }
        }

        // Get battlers after attacker using round
        for (i = currRounder; i < gBattlersCount; i++)
        {
            if (gChosenMoveByBattler[gBattlerByTurnOrder[i]] == MOVE_ROUND)
                roundUsers[j++] = gBattlerByTurnOrder[i];
            else
                nonRoundUsers[k++] = gBattlerByTurnOrder[i];
        }

        // update turn order for round users
        for (i = 0; i < 3 && roundUsers[i] != 0xFF; i++)
        {
            gBattlerByTurnOrder[currRounder] = roundUsers[i];
            gProtectStructs[roundUsers[i]].quash = TRUE; // Make it so their turn order can't be changed again
            currRounder++;
        }

        // Update turn order for non-round users
        for (i = 0; i < 3 && nonRoundUsers[i] != 0xFF; i++)
        {
            gBattlerByTurnOrder[currRounder] = nonRoundUsers[i];
            currRounder++;
        }
    }

    gBattlescriptCurrInstr = se->script;
}

static void HandleSetEffectSyrupBomb(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.syrupBomb)
    {
        struct Pokemon *mon = GetBattlerMon(cv->battlerAtk);

        gBattleMons[se->effectBattler].volatiles.syrupBomb = TRUE;
        gBattleMons[se->effectBattler].volatiles.stickySyrupedBy = cv->battlerAtk;
        gBattleMons[se->effectBattler].volatiles.syrupBombTimer = B_SYRUP_BOMB_TIMER;
        gBattleMons[se->effectBattler].volatiles.syrupBombIsShiny = IsMonShiny(mon);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_SyrupBombActivates;
    }
}

static void HandleSetEffectSecretPower(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 moveEffect = MOVE_EFFECT_NONE;

    if (IsBattlerAlive(cv->battlerAtk))
    {
        // TODO: Refactor in a way so that the addtional effect constants don't exist anymore
        if (gFieldTimers.terrain != B_TERRAIN_NONE)
            moveEffect = gBattleTerrainInfo[gFieldTimers.terrain].secretPowerEffect;
        else
            moveEffect = gBattleEnvironmentInfo[gBattleEnvironment].secretPowerEffect;

        bool32 statDown = FALSE;
        switch (moveEffect)
        {
        case SECRET_POWER_ATK_MINUS_1:
            SetStatChange(se->effectBattler, STAT_ATK, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_DEF_MINUS_1:
            SetStatChange(se->effectBattler, STAT_DEF, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_SPD_MINUS_1:
            SetStatChange(se->effectBattler, STAT_SPEED, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_SP_ATK_MINUS_1:
            SetStatChange(se->effectBattler, STAT_SPATK, -1);
            statDown = TRUE;
            break;
        case SECRET_POWER_ACC_MINUS_1:
            SetStatChange(se->effectBattler, STAT_ACC, -1);
            statDown = TRUE;
            break;
        default:
            break;
        }

        if (statDown)
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
        }
        else
        {
            se->moveEffect = moveEffect;
            SetMoveEffect(cv, se);
        }
    }
}

static void HandleSetEffectPsychicNoise(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattlerId battler = IsAbilityOnSide(se->effectBattler, ABILITY_AROMA_VEIL);

    if (battler)
    {
        gBattlerAbility = battler - 1;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_AromaVeilProtectsRet;
    }
    else if (!gBattleMons[se->effectBattler].volatiles.healBlockTimer)
    {
        gBattleMons[se->effectBattler].volatiles.healBlockTimer = 2;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectPsychicNoise;
    }
}

static void HandleSetEffectTeraBlast(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetActiveGimmick(se->effectBattler) == GIMMICK_TERA
     && GetBattlerTeraType(se->effectBattler) == TYPE_STELLAR
     && !NoAliveMonsForEitherParty())
    {
        SetStatChange(se->effectBattler, STAT_ATK, -1);
        SetStatChange(se->effectBattler, STAT_SPATK, -1);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
    }
}

static void HandleSetEffectOrderUp(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum Stat stat = 0;
    bool32 commanderAffected = TRUE;
    switch (gBattleStruct->battlerState[se->effectBattler].commanderSpecies)
    {
    case SPECIES_TATSUGIRI_CURLY:
        stat = STAT_ATK;
        break;
    case SPECIES_TATSUGIRI_DROOPY:
        stat = STAT_DEF;
        break;
    case SPECIES_TATSUGIRI_STRETCHY:
        stat = STAT_SPEED;
        break;
    default:
        commanderAffected = FALSE;
        break;
    }

    if (commanderAffected)
    {
        SetStatChange(se->effectBattler, stat, 1);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStatChange;
    }
}

static void HandleSetEffectIonDeluge(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!(gFieldStatuses & STATUS_FIELD_ION_DELUGE))
    {
        gFieldStatuses |= STATUS_FIELD_ION_DELUGE;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectIonDeluge;
    }
}

static void HandleSetEffectHaze(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; battler++)
        TryResetBattlerStatChanges(battler);
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectHaze;
}

static void HandleSetEffectLeechSeed(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!IS_BATTLER_OF_TYPE(se->effectBattler, TYPE_GRASS) && !gBattleMons[se->effectBattler].volatiles.leechSeed)
    {
        gBattleMons[se->effectBattler].volatiles.leechSeed = LEECHSEEDED_BY(cv->battlerAtk);
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectLeechSeed;
    }
}

static void HandleSetEffectReflect(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (TrySetReflect(se->effectBattler))
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectScreens;
    }
}

static void HandleSetEffectLightScreen(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (TrySetLightScreen(se->effectBattler))
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectScreens;
    }
}

static void HandleSetEffectSaltCure(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!gBattleMons[se->effectBattler].volatiles.saltCure)
    {
        gBattleMons[se->effectBattler].volatiles.saltCure = TRUE;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSaltCure;
    }
}

static void HandleSetEffectEerieSpell(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gLastMoves[se->effectBattler] == MOVE_NONE || gLastMoves[se->effectBattler] == MOVE_UNAVAILABLE)
        return;

    enum Move moveToReduce = gLastMoves[se->effectBattler];

    if (IsMaxMove(moveToReduce))
        moveToReduce = gBattleStruct->dynamax.baseMoves[se->effectBattler];

    u32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moveToReduce == gBattleMons[se->effectBattler].moves[i])
            break;
    }

    if (i != MAX_MON_MOVES && gBattleMons[se->effectBattler].pp[i] != 0)
    {
        u32 ppToDeduct = 3;

        if (gBattleMons[se->effectBattler].pp[i] < ppToDeduct)
            ppToDeduct = gBattleMons[se->effectBattler].pp[i];

        PREPARE_MOVE_BUFFER(gBattleTextBuff1, moveToReduce)
        ConvertIntToDecimalStringN(gBattleTextBuff2, ppToDeduct, STR_CONV_MODE_LEFT_ALIGN, 1);
        PREPARE_BYTE_NUMBER_BUFFER(gBattleTextBuff2, 1, ppToDeduct)
        gBattleMons[se->effectBattler].pp[i] -= ppToDeduct;
        if (!(gBattleMons[se->effectBattler].volatiles.mimickedMoves & (1u << i))
            && !(gBattleMons[se->effectBattler].volatiles.transformed))
        {
            BtlController_EmitSetMonData(se->effectBattler, B_COMM_TO_CONTROLLER, REQUEST_PPMOVE1_BATTLE + i, 0, sizeof(gBattleMons[se->effectBattler].pp[i]), &gBattleMons[se->effectBattler].pp[i]);
            MarkBattlerForControllerExec(se->effectBattler);
        }

        if (gBattleMons[se->effectBattler].pp[i] == 0)
            CancelMultiTurnMoves(se->effectBattler);

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectEerieSpell;
    }
}

static void HandleSetEffectFling(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (CanFling(cv->battlerAtk, cv->abilities[cv->battlerAtk]) || gBattleStruct->flungItem == FLUNG_ITEM_REMOVED)
    {
        enum Item item = ITEM_NONE;

        switch (gBattleStruct->flungItem)
        {
        case FLUNG_ITEM_NONE:
            gBattleStruct->flungItem = FLUNG_ITEM_REMOVE;
            item = gLastUsedItem = gBattleStruct->flingItem = gBattleMons[cv->battlerAtk].item;
            break;
        case FLUNG_ITEM_REMOVE:
        case FLUNG_ITEM_REMOVED:
            gBattleStruct->flungItem = FLUNG_ITEM_REMOVED;
            item = gLastUsedItem = gBattleStruct->flingItem;
            break;
        }

        enum HoldEffect holdEffect = GetItemHoldEffect(item);

        if (IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler]))
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_FlingBlockedByShieldDust;
            return;
        }

        if (GetItemPocket(item) == POCKET_BERRIES)
        {
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_EffectFlingConsumeBerry;
            return;
        }

        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_RemoveItem;

        struct SetEffect flingEffect = {0};
        flingEffect.script = gBattlescriptCurrInstr;
        flingEffect.effectBattler = se->effectBattler;

        switch (holdEffect)
        {
        case HOLD_EFFECT_FLAME_ORB:
            flingEffect.moveEffect = MOVE_EFFECT_BURN;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_TOXIC_ORB:
            flingEffect.moveEffect = MOVE_EFFECT_TOXIC;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_LIGHT_BALL:
            flingEffect.moveEffect = MOVE_EFFECT_PARALYSIS;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_TYPE_POWER:
            if (GetItemSecondaryId(item) == TYPE_POISON)
            {
                flingEffect.moveEffect = MOVE_EFFECT_POISON;
                SetMoveEffect(cv, &flingEffect);
            }
            break;
        case HOLD_EFFECT_FLINCH:
            flingEffect.moveEffect = MOVE_EFFECT_FLINCH;
            SetMoveEffect(cv, &flingEffect);
            break;
        case HOLD_EFFECT_MENTAL_HERB:
        case HOLD_EFFECT_WHITE_HERB:
            ItemBattleEffects(se->effectBattler, 0, holdEffect, IsOnFlingActivation);
            break;
        default:
            break;
        }
    }
}

static void HandleSetEffectRainbow(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_RAINBOW)
        return;

    gSideStatuses[side] |= SIDE_STATUS_RAINBOW;
    gSideTimers[side].rainbowTimer = 4;
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_TheRainbowActivates;
}

static void HandleSetEffectSeaOfFire(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (gSideStatuses[side] & SIDE_STATUS_SEA_OF_FIRE)
        return;

    gSideStatuses[side] |= SIDE_STATUS_SEA_OF_FIRE;
    gSideTimers[side].seaOfFireTimer = 4;
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_SeaOfFireActivates;
}

static void HandleSetEffectSwamp(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);
    if (gSideStatuses[side] & SIDE_STATUS_SWAMP)
        return;

    gSideStatuses[side] |= SIDE_STATUS_SWAMP;
    gSideTimers[side].swampTimer = 4;
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_TheSwampActivates;
}

static void HandleSetEffectWeather(struct BattleCalcValues *cv, struct SetEffect *se)
{
    u32 weather = 0, msg = 0;
    switch (se->moveEffect)
    {
    case MOVE_EFFECT_SUN:
        weather = BATTLE_WEATHER_SUN;
        msg = B_MSG_STARTED_SUNLIGHT;
        break;
    case MOVE_EFFECT_RAIN:
        weather = BATTLE_WEATHER_RAIN;
        msg = B_MSG_STARTED_RAIN;
        break;
    case MOVE_EFFECT_SANDSTORM:
        weather = BATTLE_WEATHER_SANDSTORM;
        msg = B_MSG_STARTED_SANDSTORM;
        break;
    case MOVE_EFFECT_HAIL:
        if (B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW)
        {
            weather = BATTLE_WEATHER_SNOW;
            msg = B_MSG_STARTED_SNOW;
        }
        else
        {
            weather = BATTLE_WEATHER_HAIL;
            msg = B_MSG_STARTED_HAIL;
        }
        break;
    default:
        break;
    }
    if (TryChangeBattleWeather(cv->battlerAtk, weather, ABILITY_NONE) == WEATHER_FAILURE_SUCCESS)
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = msg;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSetWeather;
    }
}

static void HandleSetEffectTerrain(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleTerrain terrain = B_TERRAIN_NONE;
    switch (se->moveEffect)
    {
    case MOVE_EFFECT_MISTY_TERRAIN:
        terrain = B_TERRAIN_MISTY;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_MISTY;
        break;
    case MOVE_EFFECT_GRASSY_TERRAIN:
        terrain = B_TERRAIN_GRASSY;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_GRASSY;
        break;
    case MOVE_EFFECT_ELECTRIC_TERRAIN:
        terrain = B_TERRAIN_ELECTRIC;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_ELECTRIC;
        break;
    case MOVE_EFFECT_PSYCHIC_TERRAIN:
        terrain = B_TERRAIN_PSYCHIC;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_TERRAIN_SET_PSYCHIC;
        break;
    default:
        break;
    }
    if (TryChangeBattleTerrain(cv->battlerAtk, terrain))
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSetTerrain;
    }
}

static void HandleSetEffectGmaxNonTypeDamage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);
    if (!(gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES))
    {
        u32 moveType = GetMoveType(gCurrentMove);
        gSideStatuses[side] |= SIDE_STATUS_DAMAGE_NON_TYPES;
        gSideTimers[side].damageNonTypesTimer = 5;
        gSideTimers[side].damageNonTypesType = moveType;
        BattleScriptPush(se->script);
        ChooseDamageNonTypesString(moveType);
        gBattlescriptCurrInstr = BattleScript_MoveEffectDamageNonTypes;
    }
}

static void HandleSetEffectEffectSporeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectEffectSporeSide;
}

static void HandleSetEffectParalyzeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectParalyzeSide;
}

static void HandleSetEffectConfusePayDaySide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER && IsOnPlayerSide(cv->battlerAtk))
    {
        u32 payday = gPaydayMoney;
        gPaydayMoney += (gBattleMons[cv->battlerAtk].level * 100);
        if (payday > gPaydayMoney)
            gPaydayMoney = 0xFFFF;
        gBattleCommunication[CURSOR_POSITION] = 1; // add "Coins scattered." message
    }

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectConfuseSide;
}

static void HandleSetEffectCritPlusSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.bonusCritStages < 3)
        gBattleMons[se->effectBattler].volatiles.bonusCritStages++;

    enum BattlerId partner = GetPartnerBattler(se->effectBattler);
    if (gBattleMons[partner].volatiles.bonusCritStages < 3)
        gBattleMons[partner].volatiles.bonusCritStages++;

    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectRaiseCritAlliesAnim;
}

static void HandleSetEffectPreventEscapeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectMeanLookSide;
}

static void HandleSetEffectAuroraVeil(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side = GetBattlerSide(se->effectBattler);

    if (!(gSideStatuses[side] & SIDE_STATUS_AURORA_VEIL))
    {
        gSideStatuses[side] |= SIDE_STATUS_AURORA_VEIL;
        if (GetBattlerHoldEffect(se->effectBattler) == HOLD_EFFECT_LIGHT_CLAY)
            gSideTimers[side].auroraVeilTimer = 8;
        else
            gSideTimers[side].auroraVeilTimer = 5;
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_AURORA_VEIL;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectScreens;
    }
}

static void HandleSetEffectInfatuateSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectInfatuateSide;
}

static void HandleSetEffectRecycleBerries(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (RandomPercentage(RNG_G_MAX_REPLENISH, 50))
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_EffectRecycleBerriesAllies;
    }
}

static void HandleSetEffectPoisonSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectPoisonSide;
}

static void HandleSetEffectDefog(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gSideStatuses[GetBattlerSide(se->effectBattler)] & SIDE_STATUS_SCREEN_ANY
        || AreAnyHazardsOnSide(GetBattlerSide(se->effectBattler))
        || AreAnyHazardsOnSide(GetBattlerSide(cv->battlerAtk))
        || gFieldTimers.terrain != B_TERRAIN_NONE)
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectDefog;
    }
}

static void HandleSetEffectPoisonParalyzeSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectPoisonParalyzeSide;
}

static void HandleSetEffectHealTeam(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectHealOneSixthAllies;
}

static void HandleSetEffectSpite(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gLastMoves[se->effectBattler] != MOVE_NONE && gLastMoves[se->effectBattler] != MOVE_UNAVAILABLE)
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSpite;
    }
}

static void HandleSetEffectGravity(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
    {
        gFieldStatuses |= STATUS_FIELD_GRAVITY;
        gFieldTimers.gravityTimer = 5;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectGravity;
    }
}

static void HandleSetEffectYawnFoe(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (gBattleMons[se->effectBattler].volatiles.yawn == 0
     && CanBeSlept(cv->battlerAtk, se->effectBattler, cv->abilities[se->effectBattler], BLOCKED_BY_SLEEP_CLAUSE)
     && RandomPercentage(RNG_G_MAX_SNOOZE, 50))
    {
        gBattleMons[se->effectBattler].volatiles.yawn = 2;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectYawnFoe;
    }
}

static void HandleSetEffectAromatherapy(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_MoveEffectAromatherapy;
}

static void HandleSetEffectConfuseSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectConfuseSide;
}

static void HandleSetEffectSteelsurge(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!IsHazardOnSide(GetBattlerSide(se->effectBattler), HAZARDS_STEELSURGE))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SHARPSTEELFLOATS;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectSteelsurge;
    }
}

static void HandleSetEffectStealthRock(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (!IsHazardOnSide(GetBattlerSide(se->effectBattler), HAZARDS_STEALTH_ROCK))
    {
        gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_POINTEDSTONESFLOAT;
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_MoveEffectStealthRock;
    }
}

static void HandleSetEffectTormentSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    BattleScriptPush(se->script);
    gBattlescriptCurrInstr = BattleScript_EffectTormentSide;
}

static void HandleSetEffectFireSpinSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; ++battler)
    {
        if (!IsBattlerAlly(battler, se->effectBattler))
            continue;

        if (!gBattleMons[battler].volatiles.wrapped)
        {
            gBattleMons[battler].volatiles.wrapped = TRUE;
            SetWrapTurns(battler, GetBattlerHoldEffect(cv->battlerAtk));
            // The Wrap effect does not expire when the user switches, so here's some cheese.
            gBattleMons[battler].volatiles.wrappedBy = se->effectBattler;
            gBattleMons[battler].volatiles.wrappedMove = MOVE_FIRE_SPIN;
        }
    }
}

static void HandleSetEffectSandblastSide(struct BattleCalcValues *cv, struct SetEffect *se)
{
    for (enum BattlerId battler = 0; battler < gBattlersCount; ++battler)
    {
        if (!IsBattlerAlly(battler, se->effectBattler))
            continue;

        if (!gBattleMons[battler].volatiles.wrapped)
        {
            gBattleMons[battler].volatiles.wrapped = TRUE;
            SetWrapTurns(battler, GetBattlerHoldEffect(cv->battlerAtk));
            // The Wrap effect does not expire when the user switches, so here's some cheese.
            gBattleMons[battler].volatiles.wrappedBy = se->effectBattler;
            gBattleMons[battler].volatiles.wrappedMove = MOVE_SAND_TOMB;
        }
    }
}

static void HandleSetEffectBreakScreen(struct BattleCalcValues *cv, struct SetEffect *se)
{
    enum BattleSide side;

    if (B_BRICK_BREAK >= GEN_4)
        side = GetBattlerSide(cv->battlerDef); // From Gen 4 onwards, Brick Break can remove screens on the user's side if used on an ally
    else
        side = GetBattlerSide(cv->battlerAtk) ^ BIT_SIDE;

    if (gSideStatuses[side] & SIDE_STATUS_SCREEN_ANY)
    {
        bool32 failed;

        if (B_BRICK_BREAK >= GEN_5)
            failed = gBattleStruct->moveResultFlags[cv->battlerDef] & MOVE_RESULT_NO_EFFECT;
        else
            failed = FALSE;

        if (!failed)
        {
            if (gSideTimers[side].reflectTimer)
                gBattleCommunication[MULTISTRING_CHOOSER] |= 1 << 0;
            if (gSideTimers[side].lightscreenTimer)
                gBattleCommunication[MULTISTRING_CHOOSER] |= 1 << 1;
            if (gSideTimers[side].auroraVeilTimer)
                gBattleCommunication[MULTISTRING_CHOOSER] |= 1 << 2;

            gSideStatuses[side] &= ~SIDE_STATUS_SCREEN_ANY;
            gBattleScripting.animTurn = 1;
            gBattleScripting.animTargetsHit = 1;
            gBattleStruct->attackAnimPlayed = TRUE; // The whole brick break animation is covered by the move so don't play twice
            BattleScriptPush(se->script);
            gBattlescriptCurrInstr = BattleScript_BreakScreens;
        }
        else
        {
            gBattleScripting.animTurn = 0;
            gBattleScripting.animTargetsHit = 0;
        }
    }
}

static void HandleSetEffectStealStats(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 atLeastOneStatStolen = FALSE;

    for (enum Stat stat = STAT_ATK; stat < NUM_BATTLE_STATS; stat++)
    {
        s32 stageToSteal = gBattleMons[se->effectBattler].statStages[stat];

        if (stageToSteal > DEFAULT_STAT_STAGE && gBattleMons[cv->battlerAtk].statStages[stat] != MAX_STAT_STAGE)
        {
            atLeastOneStatStolen = TRUE;
            gBattleMons[se->effectBattler].statStages[stat] = DEFAULT_STAT_STAGE;
            SetStatChange(cv->battlerAtk, stat, stageToSteal - DEFAULT_STAT_STAGE);
        }
    }

    if (atLeastOneStatStolen)
    {
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_StealStats;
    }
}

static void HandleSetEffectBeatUpMessage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    if (GetConfig(B_BEAT_UP) >= GEN_5) // Gen5+ don't print any custom message on attack
        return;

    if (!IsBattlerAlive(cv->battlerDef))
    {
        gMultiHitCounter = 0;
        gBattlescriptCurrInstr = BattleScript_MoveEnd;
    }
    else if (gBattleStruct->beatUpSlot == 0 && gMultiHitCounter == 0)
    {
        gBattlescriptCurrInstr = BattleScript_ButItFailed;
    }
    else
    {
        PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff1, cv->battlerAtk, gBattleStruct->beatUpSpecies[gBattleStruct->beatUpSlot])
        BattleScriptPush(se->script);
        gBattlescriptCurrInstr = BattleScript_BeatUpAttackMessage;
    }
}

static void HandleSetEffectItemMessage(struct BattleCalcValues *cv, struct SetEffect *se)
{
    gLastUsedItem = gBattleMons[se->effectBattler].item;
    BattleScriptPush(se->script);

    if (se->effectBattler == cv->battlerAtk)
        gBattlescriptCurrInstr = BattleScript_FlingMessage;
    else
        gBattlescriptCurrInstr = BattleScript_PoltergeistMessage;
}

static void (*const sSetEffectHandlers[])(struct BattleCalcValues *cv, struct SetEffect *se) =
{
    [MOVE_EFFECT_NONE] = HandleSetEffectNone,
    [MOVE_EFFECT_SLEEP] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_POISON] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_BURN] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_FREEZE] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_PARALYSIS] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_TOXIC] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_FROSTBITE] = HandleSetEffectNonVolatile,
    [MOVE_EFFECT_CONFUSION] = HandleSetEffectConfusion,
    [MOVE_EFFECT_FLINCH] = HandleSetEffectFlinch,
    [MOVE_EFFECT_ABSORB] = HandleSetEffectAbsorb,
    [MOVE_EFFECT_RANDOM_FROM_LIST] = HandleSetEffectRandomFromList,
    [MOVE_EFFECT_UPROAR] = HandleSetEffectUproar,
    [MOVE_EFFECT_PAYDAY] = HandleSetEffectPayday,
    [MOVE_EFFECT_WRAP] = HandleSetEffectWrap,
    [MOVE_EFFECT_STAT_PLUS] = HandleSetEffectStatChange,
    [MOVE_EFFECT_STAT_MINUS] = HandleSetEffectStatChange,
    [MOVE_EFFECT_REMOVE_ARG_TYPE] = HandleSetEffectRemoveArgType,
    [MOVE_EFFECT_RECHARGE] = HandleSetEffectRecharge,
    [MOVE_EFFECT_RAGE] = HandleSetEffectRage,
    [MOVE_EFFECT_PREVENT_ESCAPE] = HandleSetEffectPreventEscape,
    [MOVE_EFFECT_NIGHTMARE] = HandleSetEffectNightmare,
    [MOVE_EFFECT_GLAIVE_RUSH] = HandleSetEffectGlaiveRush,
    [MOVE_EFFECT_REMOVE_STATUS] = HandleSetEffectRemoveStatus,
    [MOVE_EFFECT_THRASH] = HandleSetEffectThrash,
    [MOVE_EFFECT_CLEAR_SMOG] = HandleSetEffectClearSmog,
    [MOVE_EFFECT_FLAME_BURST] = HandleSetEffectFlameBurst,
    [MOVE_EFFECT_FEINT] = HandleSetEffectFeint,
    [MOVE_EFFECT_HAPPY_HOUR] = HandleSetEffectHappyHour,
    [MOVE_EFFECT_CORE_ENFORCER] = HandleSetEffectCoreEnforcer,
    [MOVE_EFFECT_THROAT_CHOP] = HandleSetEffectThroatChop,
    [MOVE_EFFECT_INCINERATE] = HandleSetEffectIncinerate,
    [MOVE_EFFECT_BUG_BITE] = HandleSetEffectBugBite,
    [MOVE_EFFECT_RECOIL_HP_25] = HandleSetEffectRecoilHp25,
    [MOVE_EFFECT_TRAP_BOTH] = HandleSetEffectTrapBoth,
    [MOVE_EFFECT_ROUND] = HandleSetEffectRound,
    [MOVE_EFFECT_SYRUP_BOMB] = HandleSetEffectSyrupBomb,
    [MOVE_EFFECT_FLORAL_HEALING] = HandleSetEffectNone,
    [MOVE_EFFECT_SECRET_POWER] = HandleSetEffectSecretPower,
    [MOVE_EFFECT_PSYCHIC_NOISE] = HandleSetEffectPsychicNoise,
    [MOVE_EFFECT_TERA_BLAST] = HandleSetEffectTeraBlast,
    [MOVE_EFFECT_ORDER_UP] = HandleSetEffectOrderUp,
    [MOVE_EFFECT_ION_DELUGE] = HandleSetEffectIonDeluge,
    [MOVE_EFFECT_HAZE] = HandleSetEffectHaze,
    [MOVE_EFFECT_LEECH_SEED] = HandleSetEffectLeechSeed,
    [MOVE_EFFECT_REFLECT] = HandleSetEffectReflect,
    [MOVE_EFFECT_LIGHT_SCREEN] = HandleSetEffectLightScreen,
    [MOVE_EFFECT_SALT_CURE] = HandleSetEffectSaltCure,
    [MOVE_EFFECT_EERIE_SPELL] = HandleSetEffectEerieSpell,
    [MOVE_EFFECT_FLING] = HandleSetEffectFling,
    [MOVE_EFFECT_RAINBOW] = HandleSetEffectRainbow,
    [MOVE_EFFECT_SEA_OF_FIRE] = HandleSetEffectSeaOfFire,
    [MOVE_EFFECT_SWAMP] = HandleSetEffectSwamp,
    [MOVE_EFFECT_SUN] = HandleSetEffectWeather,
    [MOVE_EFFECT_RAIN] = HandleSetEffectWeather,
    [MOVE_EFFECT_SANDSTORM] = HandleSetEffectWeather,
    [MOVE_EFFECT_HAIL] = HandleSetEffectWeather,
    [MOVE_EFFECT_MISTY_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_GRASSY_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_ELECTRIC_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_PSYCHIC_TERRAIN] = HandleSetEffectTerrain,
    [MOVE_EFFECT_VINE_LASH] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_WILDFIRE] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_CANNONADE] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_EFFECT_SPORE_SIDE] = HandleSetEffectEffectSporeSide,
    [MOVE_EFFECT_PARALYZE_SIDE] = HandleSetEffectParalyzeSide,
    [MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE] = HandleSetEffectConfusePayDaySide,
    [MOVE_EFFECT_CRIT_PLUS_SIDE] = HandleSetEffectCritPlusSide,
    [MOVE_EFFECT_PREVENT_ESCAPE_SIDE] = HandleSetEffectPreventEscapeSide,
    [MOVE_EFFECT_AURORA_VEIL] = HandleSetEffectAuroraVeil,
    [MOVE_EFFECT_INFATUATE_SIDE] = HandleSetEffectInfatuateSide,
    [MOVE_EFFECT_RECYCLE_BERRIES] = HandleSetEffectRecycleBerries,
    [MOVE_EFFECT_POISON_SIDE] = HandleSetEffectPoisonSide,
    [MOVE_EFFECT_DEFOG] = HandleSetEffectDefog,
    [MOVE_EFFECT_POISON_PARALYZE_SIDE] = HandleSetEffectPoisonParalyzeSide,
    [MOVE_EFFECT_HEAL_TEAM] = HandleSetEffectHealTeam,
    [MOVE_EFFECT_SPITE] = HandleSetEffectSpite,
    [MOVE_EFFECT_GRAVITY] = HandleSetEffectGravity,
    [MOVE_EFFECT_VOLCALITH] = HandleSetEffectGmaxNonTypeDamage,
    [MOVE_EFFECT_SANDBLAST_SIDE] = HandleSetEffectSandblastSide,
    [MOVE_EFFECT_YAWN_FOE] = HandleSetEffectYawnFoe,
    [MOVE_EFFECT_AROMATHERAPY] = HandleSetEffectAromatherapy,
    [MOVE_EFFECT_CONFUSE_SIDE] = HandleSetEffectConfuseSide,
    [MOVE_EFFECT_STEELSURGE] = HandleSetEffectSteelsurge,
    [MOVE_EFFECT_STEALTH_ROCK] = HandleSetEffectStealthRock,
    [MOVE_EFFECT_TORMENT_SIDE] = HandleSetEffectTormentSide,
    [MOVE_EFFECT_FIRE_SPIN_SIDE] = HandleSetEffectFireSpinSide,
    [MOVE_EFFECT_FIXED_POWER] = HandleSetEffectNone,
    [STAT_CHANGE_EFFECT_PLUS] = HandleSetEffectNone,
    [STAT_CHANGE_EFFECT_MINUS] = HandleSetEffectNone,
    [MOVE_EFFECT_BREAK_SCREEN] = HandleSetEffectBreakScreen,
    [MOVE_EFFECT_STEAL_STATS] = HandleSetEffectStealStats,
    [MOVE_EFFECT_BEAT_UP_MESSAGE] = HandleSetEffectBeatUpMessage,
    [MOVE_EFFECT_ITEM_MESSAGE] = HandleSetEffectItemMessage,
    [SECRET_POWER_ATK_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_DEF_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_SPD_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_SP_ATK_MINUS_1] = HandleSetEffectNone,
    [SECRET_POWER_ACC_MINUS_1] = HandleSetEffectNone,
};

void SetMoveEffect(struct BattleCalcValues *cv, struct SetEffect *se)
{
    bool32 affectsUser = (cv->battlerAtk == se->effectBattler);

    if (gSpecialStatuses[cv->battlerAtk].parentalBondState == PARENTAL_BOND_1ST_HIT
     && IsBattlerAlive(se->effectBattler)
     && IsFinalStrikeEffect(se->moveEffect))
    {
        gBattlescriptCurrInstr = se->script;
        return;
    }

    gBattleScripting.battler = cv->battlerAtk;
    gEffectBattler = se->effectBattler;

    if (!se->primary && !affectsUser && IsMoveEffectBlockedByTarget(cv->abilities[se->effectBattler]))
        se->moveEffect = MOVE_EFFECT_NONE;
    else if (!se->primary
          && IsSheerForceAffected(cv->move, cv->abilities[cv->battlerAtk])
          && !(se->moveEffect == MOVE_EFFECT_ORDER_UP && gBattleStruct->battlerState[cv->battlerAtk].commanderSpecies != SPECIES_NONE))
        se->moveEffect = MOVE_EFFECT_NONE;
    else if (!IsBattlerAlive(se->effectBattler) && !IgnoreTargetingForMoveEffect(se->moveEffect))
        se->moveEffect = MOVE_EFFECT_NONE;
    else if (DoesSubstituteBlockMoveEffectOnTarget(cv->battlerAtk, se->effectBattler, se->moveEffect))
        se->moveEffect = MOVE_EFFECT_NONE;

    sSetEffectHandlers[se->moveEffect](cv, se);

    gBattleScripting.moveEffect = MOVE_EFFECT_NONE;
}

void SetMoveEffectHelper(enum BattlerId battlerAtk, enum BattlerId effectBattler, enum MoveEffect moveEffect, const u8 *battleScript, enum SetMoveEffectFlags effectFlags)
{
    struct BattleCalcValues cv = {0};
    cv.battlerAtk = battlerAtk;
    cv.battlerDef = gBattlerTarget;
    cv.move = gCurrentMove; // Should be set to None eventually. When Cmd_seteffectprimary is gone

    for (enum BattlerId battler = B_BATTLER_0; battler < gBattlersCount; battler++)
    {
        cv.abilities[battler] = GetBattlerAbility(battler);
        cv.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }

    struct SetEffect se = {0};
    se.moveEffect = moveEffect;
    se.script = battleScript;
    se.effectBattler = effectBattler;
    se.primary = effectFlags & EFFECT_PRIMARY;
    se.certain = effectFlags & EFFECT_CERTAIN;

    SetMoveEffect(&cv, &se);
}

static inline bool32 IgnoreTargetingForMoveEffect(enum MoveEffect moveEffect) // Currently only used to determine move effects which happen even if the move's defined effectbattler is fainted
{
    switch (moveEffect)
    {
    case MOVE_EFFECT_PAYDAY:
    case MOVE_EFFECT_BUG_BITE:
    case MOVE_EFFECT_FLAME_BURST:
    case MOVE_EFFECT_STEALTH_ROCK:
    case MOVE_EFFECT_STEELSURGE:
    case MOVE_EFFECT_SUN:
    case MOVE_EFFECT_RAIN:
    case MOVE_EFFECT_SANDSTORM:
    case MOVE_EFFECT_HAIL:
    case MOVE_EFFECT_MISTY_TERRAIN:
    case MOVE_EFFECT_GRASSY_TERRAIN:
    case MOVE_EFFECT_ELECTRIC_TERRAIN:
    case MOVE_EFFECT_PSYCHIC_TERRAIN:
    case MOVE_EFFECT_DEFOG:
    case MOVE_EFFECT_ION_DELUGE:
    case MOVE_EFFECT_HAZE:
    case MOVE_EFFECT_VINE_LASH:
    case MOVE_EFFECT_WILDFIRE:
    case MOVE_EFFECT_CANNONADE:
    case MOVE_EFFECT_VOLCALITH:
    case MOVE_EFFECT_PREVENT_ESCAPE_SIDE:
    case MOVE_EFFECT_SANDBLAST_SIDE:
    case MOVE_EFFECT_FIRE_SPIN_SIDE:
    case MOVE_EFFECT_PARALYZE_SIDE:
    case MOVE_EFFECT_POISON_SIDE:
    case MOVE_EFFECT_CONFUSE_PAY_DAY_SIDE:
    case MOVE_EFFECT_POISON_PARALYZE_SIDE:
    case MOVE_EFFECT_EFFECT_SPORE_SIDE:
    case MOVE_EFFECT_INFATUATE_SIDE:
    case MOVE_EFFECT_CONFUSE_SIDE:
    case MOVE_EFFECT_TORMENT_SIDE:
    case MOVE_EFFECT_CORE_ENFORCER:
    case MOVE_EFFECT_RAINBOW:
    case MOVE_EFFECT_SEA_OF_FIRE:
    case MOVE_EFFECT_SWAMP:
    case MOVE_EFFECT_ABSORB:
        return TRUE;
    default:
        return FALSE;
    }
}

static bool32 DoesSubstituteBlockMoveEffectOnTarget(enum BattlerId battlerAtk, enum BattlerId battlerDef, enum MoveEffect moveEffect)
{
    if (battlerAtk == battlerDef)
        return FALSE;

    if (moveEffect != MOVE_EFFECT_BUG_BITE && IgnoreTargetingForMoveEffect(moveEffect))
        return FALSE;

    if (moveEffect == MOVE_EFFECT_BREAK_SCREEN)
        return FALSE;

    if (DoesSubstituteBlockMove(battlerAtk, battlerDef, gCurrentMove))
        return TRUE;

    return FALSE;
}

static bool32 IsFinalStrikeEffect(enum MoveEffect moveEffect)
{
    switch (moveEffect)
    {
    case MOVE_EFFECT_REMOVE_ARG_TYPE:
    case MOVE_EFFECT_REMOVE_STATUS:
    case MOVE_EFFECT_RECOIL_HP_25:
    case MOVE_EFFECT_PREVENT_ESCAPE:
    case MOVE_EFFECT_WRAP:
        return TRUE;
    default:
        return FALSE;
    }
}

