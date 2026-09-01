#include "global.h"
#include "battle.h"
#include "battle_hold_effects.h"
#include "battle_stat_change.h"
#include "battle_util.h"
#include "battle_scripts.h"
#include "battle_switch_in.h"
#include "battle_controllers.h"
#include "config_changes.h"
#include "constants/battle.h"
#include "constants/moves.h"

static bool32 FirstEventBlockEvents(struct BattleCalcValues *calcValues);
static bool32 TryHazardsOnSwitchIn(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum Hazards hazardType);
static bool32 SecondEventBlockEvents(struct BattleCalcValues *calcValues);

bool32 DoSwitchInEvents(void)
{
    enum BattlerId battler;

    struct BattleCalcValues calcValues = {0};
    for (battler = 0; battler < gBattlersCount; battler++)
    {
        if (!IsBattlerAlive(battler))
            continue;
        calcValues.abilities[battler] = GetBattlerAbility(battler);
        calcValues.holdEffects[battler] = GetBattlerHoldEffect(battler);
    }

    switch (gBattleStruct->eventState.switchIn)
    {
    case SWITCH_IN_EVENTS_ORDER_BY_SPEED:
        for (enum BattlerId i = 0; i < gBattlersCount; i++)
            gBattlersBySpeed[i] = i;
        SortBattlersBySpeed(gBattlersBySpeed, FALSE);
        SortBattlersByRawSpeed(gBattlersByRawSpeed);
        gBattleStruct->battlersSorted = TRUE;
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.battlerSwitchIn = 0;
        gBattleStruct->eventState.switchIn++;
        // fallthrough
    case SWITCH_IN_EVENTS_TERA_SHIFT:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            battler = gBattlersByRawSpeed[gBattleStruct->switchInBattlerCounter++];
            if (AbilityBattleEffects(ABILITYEFFECT_TERA_SHIFT, battler, calcValues.abilities[battler], 0, gBattleStruct->battlerState[battler].switchIn))
                return TRUE;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_NEUTRALIZING_GAS:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            battler = gBattlersBySpeed[gBattleStruct->switchInBattlerCounter++];
            if (AbilityBattleEffects(ABILITYEFFECT_NEUTRALIZINGGAS, battler, calcValues.abilities[battler], 0, gBattleStruct->battlerState[battler].switchIn))
                return TRUE;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_UNNERVE:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            battler = gBattlersBySpeed[gBattleStruct->switchInBattlerCounter++];
            if (AbilityBattleEffects(ABILITYEFFECT_UNNERVE, battler, calcValues.abilities[battler], 0, gBattleStruct->battlerState[battler].switchIn))
                return TRUE;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_FIRST_BLOCK:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            battler = gBattlersBySpeed[gBattleStruct->switchInBattlerCounter];

            if (!IsBattlerAlive(battler) && gBattleStruct->eventState.battlerSwitchIn != FIRST_EVENT_BLOCK_HAZARDS)
            {
                gBattleStruct->switchInBattlerCounter++;
                gBattleStruct->eventState.battlerSwitchIn = 0;
                continue;
            }

            calcValues.battlerAtk = battler;
            while (gBattleStruct->eventState.battlerSwitchIn < FIRST_EVENT_BLOCK_COUNT)
            {
                if (FirstEventBlockEvents(&calcValues))
                    return TRUE;
            }

            gBattleStruct->switchInBattlerCounter++;
            gBattleStruct->eventState.battlerSwitchIn = 0;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_FORM_CHANGE:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            battler = gBattlersBySpeed[gBattleStruct->switchInBattlerCounter++];
            if (AbilityBattleEffects(ABILITYEFFECT_SWITCH_IN_FORM_CHANGE, battler, calcValues.abilities[battler], 0, gBattleStruct->battlerState[battler].switchIn))
                return TRUE;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_SECOND_BLOCK:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            battler = gBattlersByRawSpeed[gBattleStruct->switchInBattlerCounter];

            if (!IsBattlerAlive(battler))
            {
                gBattleStruct->switchInBattlerCounter++;
                gBattleStruct->eventState.battlerSwitchIn = 0;
                continue;
            }

            calcValues.battlerAtk = battler;
            while (gBattleStruct->eventState.battlerSwitchIn < SECOND_EVENT_BLOCK_COUNT)
            {
                if (SecondEventBlockEvents(&calcValues))
                    return TRUE;
            }

            gBattleStruct->switchInBattlerCounter++;
            gBattleStruct->eventState.battlerSwitchIn = 0;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_WHITE_HERB:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            enum BattlerId battler = gBattlersByRawSpeed[gBattleStruct->switchInBattlerCounter++];
            if (ItemBattleEffects(battler, 0, calcValues.holdEffects[battler], IsWhiteHerbActivation))
                return TRUE;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_OPPORTUNIST:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            enum BattlerId battler = gBattlersByRawSpeed[gBattleStruct->switchInBattlerCounter++];
            if (AbilityBattleEffects(ABILITYEFFECT_OPPORTUNIST, battler, calcValues.abilities[battler], MOVE_NONE, TRUE))
                return TRUE;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_MIRROR_HERB:
        while (gBattleStruct->switchInBattlerCounter < gBattlersCount)
        {
            enum BattlerId battler = gBattlersByRawSpeed[gBattleStruct->switchInBattlerCounter++];
            if (ItemBattleEffects(battler, 0, calcValues.holdEffects[battler], IsMirrorHerbActivation))
                return TRUE;
        }
        gBattleStruct->switchInBattlerCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_CLEAR_SET_VALUES:
        for (battler = 0; battler < gBattlersCount; battler++)
        {
            if (gBattleStruct->battlerState[battler].switchIn)
            {
                gBattleStruct->battlerState[battler].hpOnSwitchout = gBattleMons[battler].hp;
                gBattleStruct->battlerState[battler].switchIn = FALSE;
            }
        }

        gBattleStruct->intimidateActivated = FALSE;
        gBattleStruct->adrenalineOrbActivated = FALSE;
        gBattleStruct->battlersSorted = FALSE;
        gBattleStruct->hazardsCounter = 0;
        gBattleStruct->eventState.switchIn++;
        break;
    case SWITCH_IN_EVENTS_EJECT_PACK:
        gBattleStruct->eventState.switchIn++;
        if (TrySwitchInEjectPack(START_OF_TURN))
            return TRUE;
        break;
    case SWITCH_IN_EVENTS_COUNT:
        break;
    }
    return FALSE;
}

static bool32 CanBattlerBeHealed(enum BattlerId battler)
{
    if (GetConfig(B_HEALING_WISH_SWITCH) < GEN_8)
        return TRUE;

    if (gBattleMons[battler].hp != gBattleMons[battler].maxHP || gBattleMons[battler].status1)
        return TRUE;

    if (gBattleStruct->battlerState[battler].storedLunarDance
     && (gBattleMons[battler].pp[0] < CalculatePPWithBonus(gBattleMons[battler].moves[0], gBattleMons[battler].ppBonuses, 0)
      || gBattleMons[battler].pp[1] < CalculatePPWithBonus(gBattleMons[battler].moves[1], gBattleMons[battler].ppBonuses, 1)
      || gBattleMons[battler].pp[2] < CalculatePPWithBonus(gBattleMons[battler].moves[2], gBattleMons[battler].ppBonuses, 2)
      || gBattleMons[battler].pp[3] < CalculatePPWithBonus(gBattleMons[battler].moves[3], gBattleMons[battler].ppBonuses, 3)))
    {
        return TRUE;
    }

    return FALSE;
}

static bool32 FirstEventBlockEvents(struct BattleCalcValues *calcValues)
{
    bool32 effect = FALSE;
    enum BattlerId battler = calcValues->battlerAtk;

    switch (gBattleStruct->eventState.battlerSwitchIn)
    {
    case FIRST_EVENT_BLOCK_HEALING_WISH:
        if (!gBattleStruct->battlerState[battler].switchIn || !CanBattlerBeHealed(battler))
        {
            effect = FALSE;
        }
        else if (gBattleStruct->battlerState[battler].storedHealingWish)
        {
            gBattleStruct->battlerState[battler].storedHealingWish = FALSE;
            SetHealAmount(battler, GetNonDynamaxMaxHP(battler));
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_HealingWishActivates);
            effect = TRUE;
        }
        else if (gBattleStruct->battlerState[battler].storedLunarDance)
        {
            gBattleStruct->battlerState[battler].storedLunarDance = FALSE;
            SetHealAmount(battler, GetNonDynamaxMaxHP(battler));
            gBattleScripting.battler = battler;
            BattleScriptCall(BattleScript_LunarDanceActivates);
            effect = TRUE;
        }
        else if (gBattleStruct->zmove.healReplacement & 1u << battler)
        {
            gBattleStruct->zmove.healReplacement &= ~(1u << battler);
            SetHealAmount(battler, GetNonDynamaxMaxHP(battler));
            gBattleScripting.battler = battler;
            gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_Z_HP_TRAP;
            BattleScriptCall(BattleScript_HealReplacementZMove);
            effect = TRUE;
        }
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    case FIRST_EVENT_BLOCK_HAZARDS:
        if (!gBattleStruct->battlerState[battler].switchIn)
        {
            gBattleStruct->eventState.battlerSwitchIn++;
        }
        else if (EmergencyExitCanBeTriggered(battler, calcValues->abilities[battler]))
        {
            gBattleScripting.battler = gBattlerAbility = battler;
            gBattleStruct->battlerState[battler].forcedSwitch = FALSE;
            gBattleStruct->eventState.switchIn = 0;
            BattleScriptCall(BattleScript_EmergencyExitSendReplacement);
            effect = TRUE;
        }
        else
        {
            enum Hazards hazard = gBattleStruct->hazardsQueue[GetBattlerSide(battler)][gBattleStruct->hazardsCounter];
            if (hazard == HAZARDS_NONE || gBattleStruct->hazardsCounter >= HAZARDS_MAX_COUNT)
            {
                gBattleStruct->hazardsCounter = 0;
                gBattleStruct->eventState.battlerSwitchIn++;
            }
            else
            {
                effect = TryHazardsOnSwitchIn(battler, calcValues->abilities[battler], calcValues->holdEffects[battler], hazard);
            }
        }
        break;
    case FIRST_EVENT_BLOCK_GENERAL_ABILITIES:
        if (TryPrimalReversion(battler)
         || AbilityBattleEffects(ABILITYEFFECT_ON_SWITCHIN, battler, calcValues->abilities[battler], MOVE_NONE, gBattleStruct->battlerState[battler].switchIn)
         || TryClearIllusion(battler, calcValues->abilities[battler]))
            effect = TRUE;
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    case FIRST_EVENT_BLOCK_IMMUNITY_ABILITIES:
        if (AbilityBattleEffects(ABILITYEFFECT_IMMUNITY, battler, calcValues->abilities[battler], MOVE_NONE, TRUE))
            effect = TRUE;
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    case FIRST_EVENT_BLOCK_ITEMS:
        if (ItemBattleEffects(battler, 0, calcValues->holdEffects[battler], IsOnSwitchInActivation))
            effect = TRUE;
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    case FIRST_EVENT_BLOCK_COUNT:
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    }

    return effect;
}

static void SetDmgHazardsBattlescript(enum BattlerId battler, u8 multistringId)
{
    gBattleScripting.battler = battler;
    gBattleCommunication[MULTISTRING_CHOOSER] = multistringId;
    BattleScriptCall(BattleScript_DmgHazardsOnBattler);
}

static bool32 TryHazardsOnSwitchIn(enum BattlerId battler, enum Ability ability, enum HoldEffect holdEffect, enum Hazards hazardType)
{
    bool32 effect = FALSE;
    enum BattleSide side = GetBattlerSide(battler);
    bool32 clearedToxicSpikes = FALSE;

    switch (hazardType)
    {
    case HAZARDS_NONE:
        break;
    case HAZARDS_SPIKES:
        if (!IsAbilityAndRecord(battler, ability, ABILITY_MAGIC_GUARD)
         && IsBattlerAffectedByHazards(battler, holdEffect, FALSE)
         && IsBattlerGrounded(battler, ability, holdEffect))
        {
            s32 spikesDmg = GetNonDynamaxMaxHP(battler) / ((5 - gSideTimers[side].spikesAmount) * 2);
            SetPassiveDamageAmount(battler, spikesDmg);
            SetDmgHazardsBattlescript(battler, B_MSG_PKMNHURTBYSPIKES);
            effect = TRUE;
        }
        break;
    case HAZARDS_STICKY_WEB:
        if (IsBattlerAffectedByHazards(battler, holdEffect, FALSE) && IsBattlerGrounded(battler, ability, holdEffect))
        {
            gEffectBattler = battler;
            SetStatChange(battler, STAT_SPEED, -1);
            BattleScriptCall(BattleScript_StickyWebOnSwitchIn);
            effect = TRUE;
        }
        break;
    case HAZARDS_TOXIC_SPIKES:
        if (!IsBattlerGrounded(battler, ability, holdEffect))
        {
            effect = FALSE;
        }
        else if (IS_BATTLER_OF_TYPE(battler, TYPE_POISON)) // Absorb the toxic spikes.
        {
            gSideTimers[side].toxicSpikesAmount = 0;
            RemoveHazardFromField(side, HAZARDS_TOXIC_SPIKES);
            gEffectBattler = battler;
            BattleScriptCall(BattleScript_ToxicSpikesAbsorbed);
            clearedToxicSpikes = TRUE;
            effect = TRUE;
        }
        else if (IsBattlerAffectedByHazards(battler, holdEffect, TRUE)
              && CanBePoisoned(battler, battler, ABILITY_NONE, ability))
        {
            gBattleScripting.battler = battler;
            BattleScriptPushCursor();
            if (gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount >= 2)
            {
                gBattlescriptCurrInstr = BattleScript_ToxicSpikesBadlyPoisoned;
                gBattleMons[battler].status1 |= STATUS1_TOXIC_POISON;
            }
            else
            {
                gBattlescriptCurrInstr = BattleScript_ToxicSpikesPoisoned;
                gBattleMons[battler].status1 |= STATUS1_POISON;
            }

            BtlController_EmitSetMonData(battler, B_COMM_TO_CONTROLLER, REQUEST_STATUS_BATTLE, 0, sizeof(gBattleMons[battler].status1), &gBattleMons[battler].status1);
            MarkBattlerForControllerExec(battler);
            effect = TRUE;
        }
        break;
    case HAZARDS_STEALTH_ROCK:
        if (IsBattlerAffectedByHazards(battler, holdEffect, FALSE) && ability != ABILITY_MAGIC_GUARD)
        {
            gBattleStruct->passiveHpUpdate[battler] = GetStealthHazardDamage(TYPE_SIDE_HAZARD_POINTED_STONES, battler);
            if (gBattleStruct->passiveHpUpdate[battler] != 0)
            {
                SetDmgHazardsBattlescript(battler, B_MSG_STEALTHROCKDMG);
                effect = TRUE;
            }
        }
        break;
    case HAZARDS_STEELSURGE:
        if (IsBattlerAffectedByHazards(battler, holdEffect, FALSE) && ability != ABILITY_MAGIC_GUARD)
        {
            gBattleStruct->passiveHpUpdate[battler] = GetStealthHazardDamage(TYPE_SIDE_HAZARD_SHARP_STEEL, battler);
            if (gBattleStruct->passiveHpUpdate[battler] != 0)
            {
                SetDmgHazardsBattlescript(battler, B_MSG_SHARPSTEELDMG);
                effect = TRUE;
            }
        }
        break;
    case HAZARDS_MAX_COUNT:
        break;
    }

    if (!clearedToxicSpikes)
        gBattleStruct->hazardsCounter++;

    return effect;
}

static bool32 SecondEventBlockEvents(struct BattleCalcValues *calcValues)
{
    bool32 effect = FALSE;
    enum BattlerId battler = calcValues->battlerAtk;

    switch (gBattleStruct->eventState.battlerSwitchIn)
    {
    case SECOND_EVENT_ABILITIES:
        if (AbilityBattleEffects(ABILITYEFFECT_ON_WEATHER, battler, calcValues->abilities[battler], MOVE_NONE, TRUE)
         || AbilityBattleEffects(ABILITYEFFECT_ON_TERRAIN, battler, calcValues->abilities[battler], MOVE_NONE, TRUE)
         || AbilityBattleEffects(ABILITYEFFECT_DEPENDS_ON_ALLY, battler, calcValues->abilities[battler], MOVE_NONE, gBattleStruct->battlerState[battler].switchIn))
            effect = TRUE;
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    case SECOND_EVENT_BOOSTER_ENERGY:
        if (ItemBattleEffects(battler, 0, calcValues->holdEffects[battler], IsBoosterEnergyActivation))
            effect = TRUE;
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    case SECOND_EVENT_BLOCK_COUNT:
        gBattleStruct->eventState.battlerSwitchIn++;
        break;
    }

    return effect;
}
