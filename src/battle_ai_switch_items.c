#include "global.h"
#include "battle.h"
#include "constants/battle_ai.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "battle_util.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_main.h"
#include "constants/hold_effects.h"
#include "battle_setup.h"
#include "data.h"
#include "item.h"
#include "party_menu.h"
#include "pokemon.h"
#include "random.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/item_effects.h"
#include "constants/battle_move_effects.h"
#include "constants/items.h"
#include "constants/moves.h"

// this file's functions
static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng);
static bool8 FindMonWithFlagsAndSuperEffective(u16 flags, u8 moduloPercent);
static bool8 ShouldUseItem(void);
static bool32 AiExpectsToFaintPlayer(void);
static bool32 AI_ShouldHeal(u32 healAmount);
static bool32 AI_OpponentCanFaintAiWithMod(u32 healAmount);

static bool32 IsAceMon(u32 battlerId, u32 monPartyId)
{
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_ACE_POKEMON
        && !(gBattleStruct->forcedSwitch & gBitTable[battlerId])
        && monPartyId == CalculateEnemyPartyCount()-1)
            return TRUE;
    return FALSE;
}

void GetAIPartyIndexes(u32 battlerId, s32 *firstId, s32 *lastId)
{
    if (BATTLE_TWO_VS_ONE_OPPONENT && (battlerId & BIT_SIDE) == B_SIDE_OPPONENT)
    {
        *firstId = 0, *lastId = PARTY_SIZE;
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_TOWER_LINK_MULTI))
    {
        if ((battlerId & BIT_FLANK) == B_FLANK_LEFT)
            *firstId = 0, *lastId = PARTY_SIZE / 2;
        else
            *firstId = PARTY_SIZE / 2, *lastId = PARTY_SIZE;
    }
    else
    {
        *firstId = 0, *lastId = PARTY_SIZE;
    }
}

static bool8 ShouldSwitchIfAllBadMoves(void)
{
    if (gBattleResources->ai->switchMon)
    {
        gBattleResources->ai->switchMon = 0;
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 ShouldSwitchIfWonderGuard(void)
{
    u8 opposingPosition;
    u8 opposingBattler;
    s32 i, j;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party = NULL;
    u16 move;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return FALSE;

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler));

    if (GetBattlerAbility(GetBattlerAtPosition(opposingPosition)) != ABILITY_WONDER_GUARD)
        return FALSE;

    // Check if Pokemon has a super effective move.
    for (opposingBattler = GetBattlerAtPosition(opposingPosition), i = 0; i < MAX_MON_MOVES; i++)
    {
        move = gBattleMons[gActiveBattler].moves[i];
        if (move != MOVE_NONE)
        {
            if (AI_GetTypeEffectiveness(move, gActiveBattler, opposingBattler) >= UQ_4_12(2.0))
                return FALSE;
        }
    }

    // Get party information.
    GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // Find a Pokemon in the party that has a super effective move.
    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[gActiveBattler])
            continue;
        if (IsAceMon(gActiveBattler, i))
            continue;

        for (opposingBattler = GetBattlerAtPosition(opposingPosition), j = 0; j < MAX_MON_MOVES; j++)
        {
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            if (move != MOVE_NONE)
            {
                if (AI_GetTypeEffectiveness(move, gActiveBattler, opposingBattler) >= UQ_4_12(2.0) && Random() % 3 < 2)
                {
                    // We found a mon.
                    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                    BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE; // There is not a single Pokemon in the party that has a super effective move against a mon with Wonder Guard.
}

static bool8 FindMonThatAbsorbsOpponentsMove(void)
{
    u8 battlerIn1, battlerIn2;
    u16 absorbingTypeAbility;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;

    if (HasSuperEffectiveMoveAgainstOpponents(TRUE) && Random() % 3 != 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == MOVE_NONE)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == MOVE_UNAVAILABLE)
        return FALSE;
    if (IS_MOVE_STATUS(gLastLandedMoves[gActiveBattler]))
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_FIRE)
        absorbingTypeAbility = ABILITY_FLASH_FIRE;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_WATER)
        absorbingTypeAbility = ABILITY_WATER_ABSORB;
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].type == TYPE_ELECTRIC)
        absorbingTypeAbility = ABILITY_VOLT_ABSORB;
    else
        return FALSE;

    if (AI_DATA->abilities[gActiveBattler] == absorbingTypeAbility)
        return FALSE;

    GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u16 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        if (species == SPECIES_NONE || species == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;
        if (IsAceMon(gActiveBattler, i))
            continue;

        monAbility = GetMonAbility(&party[i]);

        if (absorbingTypeAbility == monAbility && Random() & 1)
        {
            // we found a mon.
            *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SWITCH, 0);
            return TRUE;
        }
    }

    return FALSE;
}

static bool8 ShouldSwitchIfGameStatePrompt(void)
{
    bool8 switchMon = FALSE;
    u16 monAbility = AI_DATA->abilities[gActiveBattler];
    u16 holdEffect = AI_DATA->holdEffects[gActiveBattler];
    u8 opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler));
    u8 opposingBattler = GetBattlerAtPosition(opposingPosition);
    s32 moduloChance = 4; //25% Chance Default
    s32 chanceReducer = 1; //No Reduce default. Increase to reduce
    s32 firstId;
    s32 lastId;
    s32 i;
    struct Pokemon *party;


    if (AnyStatIsRaised(gActiveBattler))
        chanceReducer = 5; // Reduce switchout probability by factor of 5 if setup

    //Perish Song
    if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG
        && gDisableStructs[gActiveBattler].perishSongTimer == 0
        && monAbility != ABILITY_SOUNDPROOF)
        switchMon = TRUE;

    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_SMART_SWITCHING)
    {
        //Yawn
        if (gStatuses3[gActiveBattler] & STATUS3_YAWN
            && AI_CanSleep(gActiveBattler, monAbility)
            && gBattleMons[gActiveBattler].hp > gBattleMons[gActiveBattler].maxHP / 3)
        {
            switchMon = TRUE;

            //Double Battles
            //Check if partner can prevent sleep
            if (IsDoubleBattle())
            {
                if (IsBattlerAlive(BATTLE_PARTNER(gActiveBattler))
                    && (GetAIChosenMove(BATTLE_PARTNER(gActiveBattler)) == MOVE_UPROAR)
                    )
                    switchMon = FALSE;

                if (IsBattlerAlive(BATTLE_PARTNER(gActiveBattler))
                    && (gBattleMoves[AI_DATA->partnerMove].effect == EFFECT_MISTY_TERRAIN
                        || gBattleMoves[AI_DATA->partnerMove].effect == EFFECT_ELECTRIC_TERRAIN)
                    && IsBattlerGrounded(gActiveBattler)
                    )
                    switchMon = FALSE;

                if (*(gBattleStruct->AI_monToSwitchIntoId + BATTLE_PARTNER(gActiveBattler)) != PARTY_SIZE) //Partner is switching
                    {
                        GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

                        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
                            party = gPlayerParty;

                        for (i = firstId; i < lastId; i++)
                        {
                            if (IsAceMon(gActiveBattler, i))
                                continue;

                            //Look for mon in party that is able to be switched into and has ability that sets terrain
                            if (GetMonData(&party[i], MON_DATA_HP) != 0
                                && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
                                && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
                                && i != gBattlerPartyIndexes[gActiveBattler]
                                && i != gBattlerPartyIndexes[BATTLE_PARTNER(gActiveBattler)]
                                && IsBattlerGrounded(gActiveBattler)
                                && (GetMonAbility(&party[i]) == ABILITY_MISTY_SURGE
                                    || GetMonAbility(&party[i]) == ABILITY_ELECTRIC_SURGE)) //Ally has Misty or Electric Surge
                                {
                                    *(gBattleStruct->AI_monToSwitchIntoId + BATTLE_PARTNER(gActiveBattler)) = i;
                                    BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SWITCH, 0);
                                    switchMon = FALSE;
                                    break;
                                }
                        }
                    }
            }

            //Check if Active Pokemon can KO opponent instead of switching
            //Will still fall asleep, but take out opposing Pokemon first
            if (AiExpectsToFaintPlayer())
                switchMon = FALSE;

            //Checks to see if active Pokemon can do something against sleep
            if ((monAbility == ABILITY_NATURAL_CURE
                || monAbility == ABILITY_SHED_SKIN
                || monAbility == ABILITY_EARLY_BIRD)
                || holdEffect == (HOLD_EFFECT_CURE_SLP | HOLD_EFFECT_CURE_STATUS)
                || HasMove(gActiveBattler, MOVE_SLEEP_TALK)
                || (HasMoveEffect(gActiveBattler, MOVE_SNORE) && AI_GetTypeEffectiveness(MOVE_SNORE, gActiveBattler, opposingBattler) >= UQ_4_12(1.0))
                || (IsBattlerGrounded(gActiveBattler)
                    && (HasMove(gActiveBattler, MOVE_MISTY_TERRAIN) || HasMove(gActiveBattler, MOVE_ELECTRIC_TERRAIN)))
                )
                switchMon = FALSE;

            //Check if Active Pokemon evasion boosted and might be able to dodge until awake
            if (gBattleMons[gActiveBattler].statStages[STAT_EVASION] > (DEFAULT_STAT_STAGE + 3)
                && AI_DATA->abilities[opposingBattler] != ABILITY_UNAWARE
                && AI_DATA->abilities[opposingBattler] != ABILITY_KEEN_EYE
                && !(gBattleMons[gActiveBattler].status2 & STATUS2_FORESIGHT)
                && !(gStatuses3[gActiveBattler] & STATUS3_MIRACLE_EYED))
                switchMon = FALSE;

        }

        //Secondary Damage
        if (monAbility != ABILITY_MAGIC_GUARD
            && !AiExpectsToFaintPlayer())
        {
            //Toxic
            moduloChance = 2; //50%
            if (((gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_COUNTER) >= STATUS1_TOXIC_TURN(2))
                && gBattleMons[gActiveBattler].hp >= (gBattleMons[gActiveBattler].maxHP / 3)
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;

            //Cursed
            moduloChance = 2; //50%
            if (gBattleMons[gActiveBattler].status2 & STATUS2_CURSED
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;

            //Nightmare
            moduloChance = 3; //33.3%
            if (gBattleMons[gActiveBattler].status2 & STATUS2_NIGHTMARE
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;

            //Leech Seed
            moduloChance = 4; //25%
            if (gStatuses3[gActiveBattler] & STATUS3_LEECHSEED
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;
        }

        //Infatuation
        if (gBattleMons[gActiveBattler].status2 & STATUS2_INFATUATION
            && !AiExpectsToFaintPlayer())
            switchMon = TRUE;

        //Todo
        //Pass Wish Heal

        //Semi-Invulnerable
        if (gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE)
        {
            if (FindMonThatAbsorbsOpponentsMove()) //If find absorber default to switch
                switchMon = TRUE;
            if (!AI_OpponentCanFaintAiWithMod(0)
                && AnyStatIsRaised(gActiveBattler))
                switchMon = FALSE;
            if (AiExpectsToFaintPlayer()
                && !WillAIStrikeFirst()
                && !AI_OpponentCanFaintAiWithMod(0))
                switchMon = FALSE;
        }
    }

    if (switchMon)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 ShouldSwitchIfAbilityBenefit(void)
{
    s32 monToSwitchId;
    s32 moduloChance = 4; //25% Chance Default
    s32 chanceReducer = 1; //No Reduce default. Increase to reduce
    u8 battlerId = GetBattlerPosition(gActiveBattler);

    if (AnyStatIsRaised(battlerId))
        chanceReducer = 5; // Reduce switchout probability by factor of 5 if setup

    //Check if ability is blocked
    if (gStatuses3[gActiveBattler] & STATUS3_GASTRO_ACID
        ||IsNeutralizingGasOnField())
        return FALSE;

    switch(AI_DATA->abilities[gActiveBattler]) {
        case ABILITY_NATURAL_CURE:
            moduloChance = 4; //25%
            //Attempt to cure bad ailment
            if (gBattleMons[gActiveBattler].status1 & (STATUS1_SLEEP | STATUS1_FREEZE | STATUS1_TOXIC_POISON)
                && GetMostSuitableMonToSwitchInto() != PARTY_SIZE)
                break;
            //Attempt to cure lesser ailment
            if ((gBattleMons[gActiveBattler].status1 & STATUS1_ANY)
                && (gBattleMons[gActiveBattler].hp >= gBattleMons[gActiveBattler].maxHP / 2)
                && GetMostSuitableMonToSwitchInto() != PARTY_SIZE
                && Random() % (moduloChance*chanceReducer) == 0)
                break;

            return FALSE;

        case ABILITY_REGENERATOR:
            moduloChance = 2; //50%
            //Don't switch if ailment
            if (gBattleMons[gActiveBattler].status1 & STATUS1_ANY)
                return FALSE;
            if ((gBattleMons[gActiveBattler].hp <= ((gBattleMons[gActiveBattler].maxHP * 2) / 3))
                 && GetMostSuitableMonToSwitchInto() != PARTY_SIZE
                 && Random() % (moduloChance*chanceReducer) == 0)
                break;

            return FALSE;

        default:
            return FALSE;
    }

    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
    BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SWITCH, 0);

    return TRUE;
}

static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng)
{
    u8 opposingPosition;
    u8 opposingBattler;
    s32 i;
    u16 move;

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler));
    opposingBattler = GetBattlerAtPosition(opposingPosition);

    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            if (AI_GetTypeEffectiveness(move, gActiveBattler, opposingBattler) >= UQ_4_12(2.0))
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    opposingBattler = GetBattlerAtPosition(BATTLE_PARTNER(opposingPosition));

    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            if (AI_GetTypeEffectiveness(move, gActiveBattler, opposingBattler) >= UQ_4_12(2.0))
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

static bool8 AreStatsRaised(void)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[gActiveBattler].statStages[i] > DEFAULT_STAT_STAGE)
            buffedStatsValue += gBattleMons[gActiveBattler].statStages[i] - DEFAULT_STAT_STAGE;
    }

    return (buffedStatsValue > 3);
}

static bool8 FindMonWithFlagsAndSuperEffective(u16 flags, u8 moduloPercent)
{
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u16 move;

    if (gLastLandedMoves[gActiveBattler] == MOVE_NONE)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == MOVE_UNAVAILABLE)
        return FALSE;
    if (gLastHitBy[gActiveBattler] == 0xFF)
        return FALSE;
    if (IS_MOVE_STATUS(gLastLandedMoves[gActiveBattler]))
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u16 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        if (species == SPECIES_NONE || species == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;
        if (IsAceMon(gActiveBattler, i))
            continue;

        monAbility = GetMonAbility(&party[i]);

        CalcPartyMonTypeEffectivenessMultiplier(gLastLandedMoves[gActiveBattler], species, monAbility);
        if (gMoveResultFlags & flags)
        {
            battlerIn1 = gLastHitBy[gActiveBattler];

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                if (move == 0)
                    continue;

                if (AI_GetTypeEffectiveness(move, gActiveBattler, battlerIn1) >= UQ_4_12(2.0) && Random() % moduloPercent == 0)
                {
                    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                    BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

bool32 ShouldSwitch(void)
{
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;
    s32 availableToSwitch;
    bool32 hasAceMon = FALSE;

    if (gBattleMons[gActiveBattler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
        return FALSE;
    if (gStatuses3[gActiveBattler] & STATUS3_ROOTED)
        return FALSE;
    if (IsAbilityPreventingEscape(gActiveBattler))
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return FALSE;

    availableToSwitch = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;
        if (IsAceMon(gActiveBattler, i))
        {
            hasAceMon = TRUE;
            continue;
        }

        availableToSwitch++;
    }

    if (availableToSwitch == 0)
    {
        if (hasAceMon) // If the ace mon is the only available mon, use it
            availableToSwitch++;
        else
            return FALSE;
    }

    //NOTE: The sequence of the below functions matter! Do not change unless you have carefully considered the outcome.
    //Since the order is sequencial, and some of these functions prompt switch to specific party members.

    //These Functions can prompt switch to specific party members
    if (ShouldSwitchIfWonderGuard())
        return TRUE;
    if (ShouldSwitchIfGameStatePrompt())
        return TRUE;
    if (FindMonThatAbsorbsOpponentsMove())
        return TRUE;

    //These Functions can prompt switch to generic pary members
    if (ShouldSwitchIfAllBadMoves())
        return TRUE;
    if (ShouldSwitchIfAbilityBenefit())
        return TRUE;

    //Removing switch capabilites under specific conditions
    //These Functions prevent the "FindMonWithFlagsAndSuperEffective" from getting out of hand.
    if (HasSuperEffectiveMoveAgainstOpponents(FALSE))
        return FALSE;
    if (AreStatsRaised())
        return FALSE;

    //Default Function
    //Can prompt switch if AI has a pokemon in party that resists current opponent & has super effective move
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 2)
        || FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 3))
        return TRUE;

    return FALSE;
}

void AI_TrySwitchOrUseItem(void)
{
    struct Pokemon *party;
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    u8 battlerIdentity = GetBattlerPosition(gActiveBattler);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (ShouldSwitch())
        {
            if (*(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) == PARTY_SIZE)
            {
                s32 monToSwitchId = GetMostSuitableMonToSwitchInto();
                if (monToSwitchId == PARTY_SIZE)
                {
                    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerIdentity);
                        battlerIn2 = battlerIn1;
                    }
                    else
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerIdentity);
                        battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(battlerIdentity));
                    }

                    GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

                    for (monToSwitchId = (lastId-1); monToSwitchId >= firstId; monToSwitchId--)
                    {
                        if (GetMonData(&party[monToSwitchId], MON_DATA_HP) == 0)
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn1])
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn2])
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
                            continue;
                        if (IsAceMon(gActiveBattler, monToSwitchId))
                            continue;

                        break;
                    }
                }

                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = monToSwitchId;
            }

            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler);
            return;
        }
        else if (ShouldUseItem())
        {
            return;
        }
    }

    BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_USE_MOVE, BATTLE_OPPOSITE(gActiveBattler) << 8);
}

// If there are two(or more) mons to choose from, always choose one that has baton pass
// as most often it can't do much on its own.
static u32 GetBestMonBatonPass(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, int aliveCount)
{
    int i, j, bits = 0;

    for (i = firstId; i < lastId; i++)
    {
        if (invalidMons & gBitTable[i])
            continue;

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            if (GetMonData(&party[i], MON_DATA_MOVE1 + j, NULL) == MOVE_BATON_PASS)
            {
                bits |= gBitTable[i];
                break;
            }
        }
    }

    if ((aliveCount == 2 || (aliveCount > 2 && Random() % 3 == 0)) && bits)
    {
        do
        {
            i = (Random() % (lastId - firstId)) + firstId;
        } while (!(bits & gBitTable[i]));
        return i;
    }

    return PARTY_SIZE;
}

static u32 GetBestMonTypeMatchup(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, u32 opposingBattler)
{
    int i, bits = 0;

    while (bits != 0x3F) // All mons were checked.
    {
        u16 bestResist = UQ_4_12(1.0);
        int bestMonId = PARTY_SIZE;
        // Find the mon whose type is the most suitable defensively.
        for (i = firstId; i < lastId; i++)
        {
            if (!(gBitTable[i] & invalidMons) && !(gBitTable[i] & bits))
            {
                u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
                u16 typeEffectiveness = UQ_4_12(1.0);

                u8 atkType1 = gBattleMons[opposingBattler].type1;
                u8 atkType2 = gBattleMons[opposingBattler].type2;
                u8 defType1 = gSpeciesInfo[species].types[0];
                u8 defType2 = gSpeciesInfo[species].types[1];

                MulModifier(&typeEffectiveness, (GetTypeModifier(atkType1, defType1)));
                if (atkType2 != atkType1)
                    MulModifier(&typeEffectiveness, (GetTypeModifier(atkType2, defType1)));
                if (defType2 != defType1)
                {
                    MulModifier(&typeEffectiveness, (GetTypeModifier(atkType1, defType2)));
                    if (atkType2 != atkType1)
                        MulModifier(&typeEffectiveness, (GetTypeModifier(atkType2, defType2)));
                }
                if (typeEffectiveness < bestResist)
                {
                    bestResist = typeEffectiveness;
                    bestMonId = i;
                }
            }
        }

        // Ok, we know the mon has the right typing but does it have at least one super effective move?
        if (bestMonId != PARTY_SIZE)
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                u32 move = GetMonData(&party[bestMonId], MON_DATA_MOVE1 + i);
                if (move != MOVE_NONE && AI_GetTypeEffectiveness(move, gActiveBattler, opposingBattler) >= UQ_4_12(2.0))
                    break;
            }

            if (i != MAX_MON_MOVES)
                return bestMonId; // Has both the typing and at least one super effective move.

            bits |= gBitTable[bestMonId]; // Sorry buddy, we want something better.
        }
        else
        {
            bits = 0x3F; // No viable mon to switch.
        }
    }

    return PARTY_SIZE;
}

static u32 GetBestMonDmg(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, u32 opposingBattler)
{
    int i, j;
    int bestDmg = 0;
    int bestMonId = PARTY_SIZE;

    gMoveResultFlags = 0;
    // If we couldn't find the best mon in terms of typing, find the one that deals most damage.
    for (i = firstId; i < lastId; i++)
    {
        if (gBitTable[i] & invalidMons)
            continue;

        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            u32 move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            if (move != MOVE_NONE && gBattleMoves[move].power != 0)
            {
                s32 dmg = AI_CalcPartyMonDamage(move, gActiveBattler, opposingBattler, &party[i]);
                if (bestDmg < dmg)
                {
                    bestDmg = dmg;
                    bestMonId = i;
                }
            }
        }
    }

    return bestMonId;
}

u8 GetMostSuitableMonToSwitchInto(void)
{
    u32 opposingBattler = 0;
    u32 bestMonId = 0;
    u8 battlerIn1 = 0, battlerIn2 = 0;
    s32 firstId = 0;
    s32 lastId = 0; // + 1
    struct Pokemon *party;
    s32 i, j, aliveCount = 0;
    u32 invalidMons = 0, aceMonId = PARTY_SIZE;

    if (*(gBattleStruct->monToSwitchIntoId + gActiveBattler) != PARTY_SIZE)
        return *(gBattleStruct->monToSwitchIntoId + gActiveBattler);
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return gBattlerPartyIndexes[gActiveBattler] + 1;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));

        opposingBattler = BATTLE_OPPOSITE(battlerIn1);
        if (gAbsentBattlerFlags & gBitTable[opposingBattler])
            opposingBattler ^= BIT_FLANK;
    }
    else
    {
        opposingBattler = GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler)));
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    GetAIPartyIndexes(gActiveBattler, &firstId, &lastId);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // Get invalid slots ids.
    for (i = firstId; i < lastId; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        if (species == SPECIES_NONE
            || species == SPECIES_EGG
            || GetMonData(&party[i], MON_DATA_HP) == 0
            || gBattlerPartyIndexes[battlerIn1] == i
            || gBattlerPartyIndexes[battlerIn2] == i
            || i == *(gBattleStruct->monToSwitchIntoId + battlerIn1)
            || i == *(gBattleStruct->monToSwitchIntoId + battlerIn2)
            || (GetMonAbility(&party[i]) == ABILITY_TRUANT && IsTruantMonVulnerable(gActiveBattler, opposingBattler))) // While not really invalid per say, not really wise to switch into this mon.)
        {
            invalidMons |= gBitTable[i];
        }
        else if (IsAceMon(gActiveBattler, i))// Save Ace Pokemon for last.
        {
            aceMonId = i;
            invalidMons |= gBitTable[i];
        }
        else
        {
            aliveCount++;
        }
    }

    bestMonId = GetBestMonBatonPass(party, firstId, lastId, invalidMons, aliveCount);
    if (bestMonId != PARTY_SIZE)
        return bestMonId;

    bestMonId = GetBestMonTypeMatchup(party, firstId, lastId, invalidMons, opposingBattler);
    if (bestMonId != PARTY_SIZE)
        return bestMonId;

    bestMonId = GetBestMonDmg(party, firstId, lastId, invalidMons, opposingBattler);
    if (bestMonId != PARTY_SIZE)
        return bestMonId;

    // If ace mon is the last available Pokemon and switch move was used - switch to the mon.
    if (aceMonId != PARTY_SIZE)
        return aceMonId;

    return PARTY_SIZE;
}

static bool32 AiExpectsToFaintPlayer(void)
{
    bool32 canFaintPlayer;
    u32 i;
    u8 target = gBattleStruct->aiChosenTarget[gActiveBattler];

    if (gBattleStruct->aiMoveOrAction[gActiveBattler] > 3)
        return FALSE; // AI not planning to use move

    if (GetBattlerSide(target) != GetBattlerSide(gActiveBattler)
      && CanIndexMoveFaintTarget(gActiveBattler, target, gBattleStruct->aiMoveOrAction[gActiveBattler], 0)
      && AI_WhoStrikesFirst(gActiveBattler, target, GetAIChosenMove(gActiveBattler)) == AI_IS_FASTER) {
        // We expect to faint the target and move first -> dont use an item
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldUseItem(void)
{
    struct Pokemon *party;
    s32 i;
    u8 validMons = 0;
    bool8 shouldUse = FALSE;

    // If teaming up with player and Pokemon is on the right, or Pokemon is currently held by Sky Drop
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_RIGHT)
       || gStatuses3[gActiveBattler] & STATUS3_SKY_DROPPED)
        return FALSE;

    if (gStatuses3[gActiveBattler] & STATUS3_EMBARGO)
        return FALSE;

    if (AiExpectsToFaintPlayer())
        return FALSE;

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) != 0
            && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
            && GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
        {
            validMons++;
        }
    }

    for (i = 0; i < MAX_TRAINER_ITEMS; i++)
    {
        u16 item;
        const u8 *itemEffects;
        u8 paramOffset;
        u8 battlerSide;

        item = gBattleResources->battleHistory->trainerItems[i];
        if (item == ITEM_NONE)
            continue;
        itemEffects = GetItemEffect(item);
        if (itemEffects == NULL)
            continue;

        switch (ItemId_GetBattleUsage(item))
        {
        case EFFECT_ITEM_HEAL_AND_CURE_STATUS:
            shouldUse = AI_ShouldHeal(0);
            break;
        case EFFECT_ITEM_RESTORE_HP:
            shouldUse = AI_ShouldHeal(itemEffects[GetItemEffectParamOffset(item, 4, 4)]);
            break;
        case EFFECT_ITEM_CURE_STATUS:
            if (itemEffects[3] & ITEM3_SLEEP && gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_POISON && (gBattleMons[gActiveBattler].status1 & STATUS1_POISON
                                               || gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON))
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_BURN && gBattleMons[gActiveBattler].status1 & STATUS1_BURN)
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_FREEZE && (gBattleMons[gActiveBattler].status1 & STATUS1_FREEZE || gBattleMons[gActiveBattler].status1 & STATUS1_FROSTBITE))
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_PARALYSIS && gBattleMons[gActiveBattler].status1 & STATUS1_PARALYSIS)
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_CONFUSION && gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
                shouldUse = TRUE;
            break;
        case EFFECT_ITEM_INCREASE_STAT:
        case EFFECT_ITEM_INCREASE_ALL_STATS:
            if (!gDisableStructs[gActiveBattler].isFirstTurn
                || AI_OpponentCanFaintAiWithMod(0))
                break;
            shouldUse = TRUE;
            break;
        case EFFECT_ITEM_SET_FOCUS_ENERGY:
            if (!gDisableStructs[gActiveBattler].isFirstTurn
                || gBattleMons[gActiveBattler].status2 & STATUS2_FOCUS_ENERGY
                || AI_OpponentCanFaintAiWithMod(0))
                break;
            shouldUse = TRUE;
            break;
        case EFFECT_ITEM_SET_MIST:
            battlerSide = GetBattlerSide(gActiveBattler);
            if (gDisableStructs[gActiveBattler].isFirstTurn && gSideTimers[battlerSide].mistTimer == 0)
                shouldUse = TRUE;
            break;
        case EFFECT_ITEM_REVIVE:
            gBattleStruct->itemPartyIndex[gActiveBattler] = GetFirstFaintedPartyIndex(gActiveBattler);
            if (gBattleStruct->itemPartyIndex[gActiveBattler] != PARTY_SIZE) // Revive if possible.
                shouldUse = TRUE;
            break;
        default:
            return FALSE;
        }
        if (shouldUse)
        {
            // Set selected party ID to current battler if none chosen.
            if (gBattleStruct->itemPartyIndex[gActiveBattler] == PARTY_SIZE)
                gBattleStruct->itemPartyIndex[gActiveBattler] = gBattlerPartyIndexes[gActiveBattler];
            BtlController_EmitTwoReturnValues(BUFFER_B, B_ACTION_USE_ITEM, 0);
            gBattleStruct->chosenItem[gActiveBattler] = item;
            gBattleResources->battleHistory->trainerItems[i] = 0;
            return shouldUse;
        }
    }

    return FALSE;
}

static bool32 AI_ShouldHeal(u32 healAmount)
{
    bool32 shouldHeal = FALSE;

    if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 4
     || gBattleMons[gActiveBattler].hp == 0
     || (healAmount != 0 && gBattleMons[gActiveBattler].maxHP - gBattleMons[gActiveBattler].hp > healAmount)) {
        // We have low enough HP to consider healing
        shouldHeal = !AI_OpponentCanFaintAiWithMod(healAmount); // if target can kill us even after we heal, why bother
    }

    return shouldHeal;
}

static bool32 AI_OpponentCanFaintAiWithMod(u32 healAmount)
{
    u32 i;
    // Check special cases to NOT heal
    for (i = 0; i < gBattlersCount; i++) {
        if (GetBattlerSide(i) == B_SIDE_PLAYER) {
            if (CanTargetFaintAiWithMod(i, gActiveBattler, healAmount, 0)) {
                // Target is expected to faint us
                return TRUE;
            }
        }
    }
    return FALSE;
}
