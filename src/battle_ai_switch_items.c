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
static bool8 HasSuperEffectiveMoveAgainstOpponents(u32 battler, bool8 noRng);
static bool8 FindMonWithFlagsAndSuperEffective(u32 battler, u16 flags, u8 moduloPercent);
static bool8 ShouldUseItem(u32 battler);
static bool32 AiExpectsToFaintPlayer(u32 battler);
static bool32 AI_ShouldHeal(u32 battler, u32 healAmount);
static bool32 AI_OpponentCanFaintAiWithMod(u32 battler, u32 healAmount);
static u32 GetSwitchinHazardsDamage(u32 battler, struct BattlePokemon *battleMon);

static void InitializeSwitchinCandidate(struct Pokemon *mon)
{
    PokemonToBattleMon(mon, &AI_DATA->switchinCandidate.battleMon);
    AI_DATA->switchinCandidate.hypotheticalStatus = FALSE;
}

static bool32 IsAceMon(u32 battler, u32 monPartyId)
{
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_ACE_POKEMON
        && !(gBattleStruct->forcedSwitch & gBitTable[battler])
        && monPartyId == CalculateEnemyPartyCount()-1)
            return TRUE;
    return FALSE;
}

void GetAIPartyIndexes(u32 battler, s32 *firstId, s32 *lastId)
{
    if (BATTLE_TWO_VS_ONE_OPPONENT && (battler & BIT_SIDE) == B_SIDE_OPPONENT)
    {
        *firstId = 0, *lastId = PARTY_SIZE;
    }
    else if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_TOWER_LINK_MULTI))
    {
        if ((battler & BIT_FLANK) == B_FLANK_LEFT)
            *firstId = 0, *lastId = PARTY_SIZE / 2;
        else
            *firstId = PARTY_SIZE / 2, *lastId = PARTY_SIZE;
    }
    else
    {
        *firstId = 0, *lastId = PARTY_SIZE;
    }
}

// Note that as many return statements as possible are INTENTIONALLY put after all of the loops;
// the function can take a max of about 0.06s to run, and this prevents the player from identifying
// whether the mon will switch or not by seeing how long the delay is before they select a move
static bool8 HasBadOdds(u32 battler)

{
    //Variable initialization
	u8 opposingPosition, atkType1, atkType2, defType1, defType2, effectiveness;
    s32 i, damageDealt = 0, maxDamageDealt = 0, damageTaken = 0, maxDamageTaken = 0;
    u32 aiMove, playerMove, aiBestMove = MOVE_NONE, aiAbility = GetBattlerAbility(battler), opposingBattler, weather = AI_GetWeather(AI_DATA);
    bool8 getsOneShot = FALSE, hasStatusMove = FALSE, hasSuperEffectiveMove = FALSE;
	u16 typeEffectiveness = UQ_4_12(1.0), aiMoveEffect; //baseline typing damage

    // Only use this if AI_FLAG_SMART_SWITCHING is set for the trainer
    if (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    // Won't bother configuring this for double battles
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return FALSE;

	opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(battler));
    opposingBattler = GetBattlerAtPosition(opposingPosition);

    // Gets types of player (opposingBattler) and computer (battler)
	atkType1 = gBattleMons[opposingBattler].type1;
	atkType2 = gBattleMons[opposingBattler].type2;
	defType1 = gBattleMons[battler].type1;
	defType2 = gBattleMons[battler].type2;

    // Check AI moves for damage dealt
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        aiMove = gBattleMons[battler].moves[i];
        aiMoveEffect = gBattleMoves[aiMove].effect;
        if (aiMove != MOVE_NONE)
        {
            // Check if mon has an "important" status move
            if (aiMoveEffect == EFFECT_REFLECT || aiMoveEffect == EFFECT_LIGHT_SCREEN
            || aiMoveEffect == EFFECT_SPIKES || aiMoveEffect == EFFECT_TOXIC_SPIKES || aiMoveEffect == EFFECT_STEALTH_ROCK || aiMoveEffect == EFFECT_STICKY_WEB || aiMoveEffect == EFFECT_LEECH_SEED
            || aiMoveEffect == EFFECT_EXPLOSION
            || aiMoveEffect == EFFECT_SLEEP || aiMoveEffect == EFFECT_YAWN || aiMoveEffect == EFFECT_TOXIC || aiMoveEffect == EFFECT_WILL_O_WISP || aiMoveEffect == EFFECT_PARALYZE
            || aiMoveEffect == EFFECT_TRICK || aiMoveEffect == EFFECT_TRICK_ROOM || aiMoveEffect== EFFECT_WONDER_ROOM || aiMoveEffect ==  EFFECT_PSYCHO_SHIFT || aiMoveEffect == EFFECT_FAKE_OUT
            )
            {
                hasStatusMove = TRUE;
            }

            // Only check damage if move has power
            if (gBattleMoves[aiMove].power != 0)
            {
                // Check if mon has a super effective move
                if (AI_GetTypeEffectiveness(aiMove, battler, opposingBattler) >= UQ_4_12(2.0))
                    hasSuperEffectiveMove = TRUE;

                // Get maximum damage mon can deal
                damageDealt = AI_DATA->simulatedDmg[battler][opposingBattler][i];
                if(damageDealt > maxDamageDealt)
                {
                    maxDamageDealt = damageDealt;
                    aiBestMove = aiMove;
                }

            }
        }
    }

    // Calculate type advantage
    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType1, defType1)));
    if (atkType2 != atkType1)
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType2, defType1)));
    if (defType2 != defType1)
    {
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType1, defType2)));
        if (atkType2 != atkType1)
            typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType2, defType2)));
    }

    // Get max damage mon could take
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        playerMove = gBattleMons[opposingBattler].moves[i];
        if (playerMove != MOVE_NONE && gBattleMoves[playerMove].power != 0)
        {
            damageTaken = AI_CalcDamage(playerMove, opposingBattler, battler, &effectiveness, FALSE, weather);
            if (damageTaken > maxDamageTaken)
                maxDamageTaken = damageTaken;
        }
    }

    // Check if mon gets one shot
    if(maxDamageTaken > gBattleMons[battler].hp)
    {
        getsOneShot = TRUE;
    }

    // Check if current mon can outspeed and KO in spite of bad matchup, and don't switch out if it can
    if(damageDealt > gBattleMons[opposingBattler].hp)
    {
        if (AI_WhoStrikesFirst(battler, opposingBattler, aiBestMove) == AI_IS_FASTER)
            return FALSE;
    }

    // If we don't have any other viable options, don't switch out
    if (AI_DATA->mostSuitableMonId[battler] == PARTY_SIZE)
        return FALSE;

    // Start assessing whether or not mon has bad odds
    // Jump straight to swtiching out in cases where mon gets OHKO'd
    if (((getsOneShot && gBattleMons[opposingBattler].speed > gBattleMons[battler].speed) // If the player OHKOs and outspeeds OR OHKOs, doesn't outspeed but isn't 2HKO'd
            || (getsOneShot && gBattleMons[opposingBattler].speed <= gBattleMons[battler].speed && maxDamageDealt < gBattleMons[opposingBattler].hp / 2))
        && (gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2 // And the current mon has at least 1/2 their HP, or 1/4 HP and Regenerator
            || (aiAbility == ABILITY_REGENERATOR
            && gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 4)))
    {
        // 50% chance to stay in regardless
        if (Random() % 2 == 0)
            return FALSE;

        // Switch mon out
        *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    // General bad type matchups have more wiggle room
	if (typeEffectiveness >= UQ_4_12(2.0)) // If the player has at least a 2x type advantage
	{
		if (!hasSuperEffectiveMove // If the AI doesn't have a super effective move
		&& (gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2 // And the current mon has at least 1/2 their HP, or 1/4 HP and Regenerator
            || (aiAbility == ABILITY_REGENERATOR
            && gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 4)))
		{
            // Then check if they have an important status move, which is worth using even in a bad matchup
            if(hasStatusMove)
                return FALSE;

            // 50% chance to stay in regardless
            if (Random() % 2 == 0)
                return FALSE;

            // Switch mon out
			*(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
			BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
			return TRUE;
		}
	}
	return FALSE;
}

static bool8 ShouldSwitchIfAllBadMoves(u32 battler)
{
    if (AI_DATA->shouldSwitchMon & gBitTable[battler])
    {
        AI_DATA->shouldSwitchMon &= ~(gBitTable[battler]);
        gBattleStruct->AI_monToSwitchIntoId[battler] = AI_DATA->monToSwitchId[battler];
        BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 ShouldSwitchIfWonderGuard(u32 battler)
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

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(battler));

    if (GetBattlerAbility(GetBattlerAtPosition(opposingPosition)) != ABILITY_WONDER_GUARD)
        return FALSE;

    // Check if Pokemon has a super effective move.
    for (opposingBattler = GetBattlerAtPosition(opposingPosition), i = 0; i < MAX_MON_MOVES; i++)
    {
        move = gBattleMons[battler].moves[i];
        if (move != MOVE_NONE)
        {
            if (AI_GetTypeEffectiveness(move, battler, opposingBattler) >= UQ_4_12(2.0))
                return FALSE;
        }
    }

    // Get party information.
    GetAIPartyIndexes(battler, &firstId, &lastId);

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // Find a Pokemon in the party that has a super effective move.
    for (i = firstId; i < lastId; i++)
    {
        if (!IsValidForBattle(&party[i]))
            continue;
        if (i == gBattlerPartyIndexes[battler])
            continue;
        if (IsAceMon(battler, i))
            continue;

        for (opposingBattler = GetBattlerAtPosition(opposingPosition), j = 0; j < MAX_MON_MOVES; j++)
        {
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            if (move != MOVE_NONE)
            {
                if (AI_GetTypeEffectiveness(move, battler, opposingBattler) >= UQ_4_12(2.0) && Random() % 3 < 2)
                {
                    // We found a mon.
                    *(gBattleStruct->AI_monToSwitchIntoId + battler) = i;
                    BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE; // There is not a single Pokemon in the party that has a super effective move against a mon with Wonder Guard.
}

static bool8 FindMonThatAbsorbsOpponentsMove(u32 battler)
{
    u8 battlerIn1, battlerIn2;
    u8 numAbsorbingAbilities = 0;
    u16 absorbingTypeAbilities[3]; // Array size is maximum number of absorbing abilities for a single type
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;

    if (HasSuperEffectiveMoveAgainstOpponents(battler, TRUE) && Random() % 3 != 0)
        return FALSE;
    if (gLastLandedMoves[battler] == MOVE_NONE)
        return FALSE;
    if (gLastLandedMoves[battler] == MOVE_UNAVAILABLE)
        return FALSE;
    if (IS_MOVE_STATUS(gLastLandedMoves[battler]))
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)))])
            battlerIn2 = battler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)));
    }
    else
    {
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    // Create an array of possible absorb abilities so the AI considers all of them
    if (gBattleMoves[gLastLandedMoves[battler]].type == TYPE_FIRE)
    {
        absorbingTypeAbilities[0] = ABILITY_FLASH_FIRE;
        numAbsorbingAbilities = 1;
    }
    else if (gBattleMoves[gLastLandedMoves[battler]].type == TYPE_WATER)
    {
        absorbingTypeAbilities[0] = ABILITY_WATER_ABSORB;
        absorbingTypeAbilities[1] = ABILITY_STORM_DRAIN;
        absorbingTypeAbilities[2] = ABILITY_DRY_SKIN;
        numAbsorbingAbilities = 3;
    }
    else if (gBattleMoves[gLastLandedMoves[battler]].type == TYPE_ELECTRIC)
    {
        absorbingTypeAbilities[0] = ABILITY_VOLT_ABSORB;
        absorbingTypeAbilities[1] = ABILITY_MOTOR_DRIVE;
        absorbingTypeAbilities[2] = ABILITY_LIGHTNING_ROD;
        numAbsorbingAbilities = 3;
    }
    else if (gBattleMoves[gLastLandedMoves[battler]].type == TYPE_GRASS)
    {
        absorbingTypeAbilities[0] = ABILITY_SAP_SIPPER;
        numAbsorbingAbilities = 1;
    }
    else
    {
        return FALSE;
    }

    // Check current mon for all absorbing abilities
    for (i = 0; i < numAbsorbingAbilities; i++)
    {
        if (AI_DATA->abilities[battler] == absorbingTypeAbilities[i])
            return FALSE;
    }

    GetAIPartyIndexes(battler, &firstId, &lastId);

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 monAbility;

        if (!IsValidForBattle(&party[i]))
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;
        if (IsAceMon(battler, i))
            continue;

        monAbility = GetMonAbility(&party[i]);

        for (j = 0; j < numAbsorbingAbilities; j++)
        {
            if (absorbingTypeAbilities[j] == monAbility && Random() & 1)
            {
                // we found a mon.
                *(gBattleStruct->AI_monToSwitchIntoId + battler) = i;
                BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }
    }
    return FALSE;
}

static bool8 ShouldSwitchIfGameStatePrompt(u32 battler)
{
    bool8 switchMon = FALSE;
    u16 monAbility = AI_DATA->abilities[battler];
    u16 holdEffect = AI_DATA->holdEffects[battler];
    u8 opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(battler));
    u8 opposingBattler = GetBattlerAtPosition(opposingPosition);
    s32 moduloChance = 4; //25% Chance Default
    s32 chanceReducer = 1; //No Reduce default. Increase to reduce
    s32 firstId;
    s32 lastId;
    s32 i;
    struct Pokemon *party;

    if (AnyStatIsRaised(battler))
        chanceReducer = 5; // Reduce switchout probability by factor of 5 if setup

    //Perish Song
    if (gStatuses3[battler] & STATUS3_PERISH_SONG
        && gDisableStructs[battler].perishSongTimer == 0
        && monAbility != ABILITY_SOUNDPROOF)
        switchMon = TRUE;

    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_SMART_SWITCHING)
    {
        //Yawn
        if (gStatuses3[battler] & STATUS3_YAWN
            && AI_CanSleep(battler, monAbility)
            && gBattleMons[battler].hp > gBattleMons[battler].maxHP / 3)
        {
            switchMon = TRUE;

            //Double Battles
            //Check if partner can prevent sleep
            if (IsDoubleBattle())
            {
                if (IsBattlerAlive(BATTLE_PARTNER(battler))
                    && (GetAIChosenMove(BATTLE_PARTNER(battler)) == MOVE_UPROAR)
                    )
                    switchMon = FALSE;

                if (IsBattlerAlive(BATTLE_PARTNER(battler))
                    && (gBattleMoves[AI_DATA->partnerMove].effect == EFFECT_MISTY_TERRAIN
                        || gBattleMoves[AI_DATA->partnerMove].effect == EFFECT_ELECTRIC_TERRAIN)
                    && IsBattlerGrounded(battler)
                    )
                    switchMon = FALSE;

                if (*(gBattleStruct->AI_monToSwitchIntoId + BATTLE_PARTNER(battler)) != PARTY_SIZE) //Partner is switching
                    {
                        GetAIPartyIndexes(battler, &firstId, &lastId);

                        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
                            party = gPlayerParty;

                        for (i = firstId; i < lastId; i++)
                        {
                            if (IsAceMon(battler, i))
                                continue;

                            //Look for mon in party that is able to be switched into and has ability that sets terrain
                            if (IsValidForBattle(&party[i])
                                && i != gBattlerPartyIndexes[battler]
                                && i != gBattlerPartyIndexes[BATTLE_PARTNER(battler)]
                                && IsBattlerGrounded(battler)
                                && (GetMonAbility(&party[i]) == ABILITY_MISTY_SURGE
                                    || GetMonAbility(&party[i]) == ABILITY_ELECTRIC_SURGE)) //Ally has Misty or Electric Surge
                                {
                                    *(gBattleStruct->AI_monToSwitchIntoId + BATTLE_PARTNER(battler)) = i;
                                    BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_SWITCH, 0);
                                    switchMon = FALSE;
                                    break;
                                }
                        }
                    }
            }

            //Check if Active Pokemon can KO opponent instead of switching
            //Will still fall asleep, but take out opposing Pokemon first
            if (AiExpectsToFaintPlayer(battler))
                switchMon = FALSE;

            //Checks to see if active Pokemon can do something against sleep
            if ((monAbility == ABILITY_NATURAL_CURE
                || monAbility == ABILITY_SHED_SKIN
                || monAbility == ABILITY_EARLY_BIRD)
                || holdEffect == (HOLD_EFFECT_CURE_SLP | HOLD_EFFECT_CURE_STATUS)
                || HasMove(battler, MOVE_SLEEP_TALK)
                || (HasMoveEffect(battler, MOVE_SNORE) && AI_GetTypeEffectiveness(MOVE_SNORE, battler, opposingBattler) >= UQ_4_12(1.0))
                || (IsBattlerGrounded(battler)
                    && (HasMove(battler, MOVE_MISTY_TERRAIN) || HasMove(battler, MOVE_ELECTRIC_TERRAIN)))
                )
                switchMon = FALSE;

            //Check if Active Pokemon evasion boosted and might be able to dodge until awake
            if (gBattleMons[battler].statStages[STAT_EVASION] > (DEFAULT_STAT_STAGE + 3)
                && AI_DATA->abilities[opposingBattler] != ABILITY_UNAWARE
                && AI_DATA->abilities[opposingBattler] != ABILITY_KEEN_EYE
                && (B_ILLUMINATE_EFFECT >= GEN_9 && AI_DATA->abilities[opposingBattler] != ABILITY_ILLUMINATE)
                && !(gBattleMons[battler].status2 & STATUS2_FORESIGHT)
                && !(gStatuses3[battler] & STATUS3_MIRACLE_EYED))
                switchMon = FALSE;

        }

        //Secondary Damage
        if (monAbility != ABILITY_MAGIC_GUARD
            && !AiExpectsToFaintPlayer(battler))
        {
            //Toxic
            moduloChance = 2; //50%
            if (((gBattleMons[battler].status1 & STATUS1_TOXIC_COUNTER) >= STATUS1_TOXIC_TURN(2))
                && gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / 3)
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;

            //Cursed
            moduloChance = 2; //50%
            if (gBattleMons[battler].status2 & STATUS2_CURSED
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;

            //Nightmare
            moduloChance = 3; //33.3%
            if (gBattleMons[battler].status2 & STATUS2_NIGHTMARE
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;

            //Leech Seed
            moduloChance = 4; //25%
            if (gStatuses3[battler] & STATUS3_LEECHSEED
                && (Random() % (moduloChance*chanceReducer)) == 0)
                switchMon = TRUE;
        }

        //Infatuation
        if (gBattleMons[battler].status2 & STATUS2_INFATUATION
            && !AiExpectsToFaintPlayer(battler))
            switchMon = TRUE;

        //Todo
        //Pass Wish Heal

        //Semi-Invulnerable
        if (gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE)
        {
            if (FindMonThatAbsorbsOpponentsMove(battler)) //If find absorber default to switch
                switchMon = TRUE;
            if (!AI_OpponentCanFaintAiWithMod(battler, 0)
                && AnyStatIsRaised(battler))
                switchMon = FALSE;
            if (AiExpectsToFaintPlayer(battler)
                && !AI_STRIKES_FIRST(battler, opposingBattler, 0)
                && !AI_OpponentCanFaintAiWithMod(battler, 0))
                switchMon = FALSE;
        }
    }

    if (switchMon)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 ShouldSwitchIfAbilityBenefit(u32 battler)
{
    s32 moduloChance = 4; //25% Chance Default
    s32 chanceReducer = 1; //No Reduce default. Increase to reduce

    if (AnyStatIsRaised(battler))
        chanceReducer = 5; // Reduce switchout probability by factor of 5 if setup

    //Check if ability is blocked
    if (gStatuses3[battler] & STATUS3_GASTRO_ACID
        ||IsNeutralizingGasOnField())
        return FALSE;

    switch(AI_DATA->abilities[battler]) {
        case ABILITY_NATURAL_CURE:
            moduloChance = 4; //25%
            //Attempt to cure bad ailment
            if (gBattleMons[battler].status1 & (STATUS1_SLEEP | STATUS1_FREEZE | STATUS1_TOXIC_POISON)
                && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE)
                break;
            //Attempt to cure lesser ailment
            if ((gBattleMons[battler].status1 & STATUS1_ANY)
                && (gBattleMons[battler].hp >= gBattleMons[battler].maxHP / 2)
                && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE
                && Random() % (moduloChance*chanceReducer) == 0)
                break;

            return FALSE;

        case ABILITY_REGENERATOR:
            moduloChance = 2; //50%
            //Don't switch if ailment
            if (gBattleMons[battler].status1 & STATUS1_ANY)
                return FALSE;
            if ((gBattleMons[battler].hp <= ((gBattleMons[battler].maxHP * 2) / 3))
                 && AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE
                 && Random() % (moduloChance*chanceReducer) == 0)
                break;

            return FALSE;

        default:
            return FALSE;
    }

    *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
    BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_SWITCH, 0);

    return TRUE;
}

static bool8 HasSuperEffectiveMoveAgainstOpponents(u32 battler, bool8 noRng)
{
    u8 opposingPosition;
    u8 opposingBattler;
    s32 i;
    u16 move;

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(battler));
    opposingBattler = GetBattlerAtPosition(opposingPosition);

    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[battler].moves[i];
            if (move == MOVE_NONE)
                continue;

            if (AI_GetTypeEffectiveness(move, battler, opposingBattler) >= UQ_4_12(2.0))
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
            move = gBattleMons[battler].moves[i];
            if (move == MOVE_NONE)
                continue;

            if (AI_GetTypeEffectiveness(move, battler, opposingBattler) >= UQ_4_12(2.0))
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

static bool8 AreStatsRaised(u32 battler)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[battler].statStages[i] > DEFAULT_STAT_STAGE)
            buffedStatsValue += gBattleMons[battler].statStages[i] - DEFAULT_STAT_STAGE;
    }

    return (buffedStatsValue > 3);
}

static bool8 FindMonWithFlagsAndSuperEffective(u32 battler, u16 flags, u8 moduloPercent)
{
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u16 move;

    if (gLastLandedMoves[battler] == MOVE_NONE)
        return FALSE;
    if (gLastLandedMoves[battler] == MOVE_UNAVAILABLE)
        return FALSE;
    if (gLastHitBy[battler] == 0xFF)
        return FALSE;
    if (IS_MOVE_STATUS(gLastLandedMoves[battler]))
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)))])
            battlerIn2 = battler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)));
    }
    else
    {
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    GetAIPartyIndexes(battler, &firstId, &lastId);

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species, monAbility;

        if (!IsValidForBattle(&party[i]))
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;
        if (IsAceMon(battler, i))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
        monAbility = GetMonAbility(&party[i]);
        CalcPartyMonTypeEffectivenessMultiplier(gLastLandedMoves[battler], species, monAbility);
        if (gMoveResultFlags & flags)
        {
            battlerIn1 = gLastHitBy[battler];

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                if (move == 0)
                    continue;

                if (AI_GetTypeEffectiveness(move, battler, battlerIn1) >= UQ_4_12(2.0) && Random() % moduloPercent == 0)
                {
                    *(gBattleStruct->AI_monToSwitchIntoId + battler) = i;
                    BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

static bool32 CanMonSurviveHazardSwitchin(u32 battler)
{
    u32 battlerIn1, battlerIn2;
    u32 hazardDamage = 0, battlerHp = gBattleMons[battler].hp;
    u32 ability = GetBattlerAbility(battler), aiMove;
    s32 firstId, lastId, i, j;
    struct Pokemon *party;

    if (ability == ABILITY_REGENERATOR)
        battlerHp = (battlerHp * 133) / 100; // Account for Regenerator healing

    hazardDamage = GetSwitchinHazardsDamage(battler, &gBattleMons[battler]);

    // Battler will faint to hazards, check to see if another mon can clear them
    if (hazardDamage > battlerHp)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        {
            battlerIn1 = battler;
            if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)))])
                battlerIn2 = battler;
            else
                battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)));
        }
        else
        {
            battlerIn1 = battler;
            battlerIn2 = battler;
        }

        GetAIPartyIndexes(battler, &firstId, &lastId);
        party = GetBattlerParty(battler);

        for (i = firstId; i < lastId; i++)
        {
            if (!IsValidForBattle(&party[i]))
                continue;
            if (i == gBattlerPartyIndexes[battlerIn1])
                continue;
            if (i == gBattlerPartyIndexes[battlerIn2])
                continue;
            if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
                continue;
            if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
                continue;
            if (IsAceMon(battler, i))
                continue;

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                aiMove = GetMonData(&party[i], MON_DATA_MOVE1 + j, NULL);
                if (aiMove == MOVE_RAPID_SPIN || aiMove == MOVE_DEFOG || aiMove == MOVE_MORTAL_SPIN || aiMove == MOVE_TIDY_UP)
                {
                    // Have a mon that can clear the hazards, so switching out is okay
                    return TRUE;
                }
            }
        }
        // Faints to hazards and party can't clear them, don't switch out
        return FALSE;
    }
    return TRUE;
}

static bool32 ShouldSwitchIfEncored(u32 battler)
{
    // Only use this if AI_FLAG_SMART_SWITCHING is set for the trainer
    if (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    // If not Encored or if no good switchin, don't switch
    if (gDisableStructs[battler].encoredMove == MOVE_NONE || AI_DATA->mostSuitableMonId[battler] == PARTY_SIZE)
        return FALSE;

    // Otherwise 50% chance to switch out
    if (Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    return FALSE;
}

// AI should switch if it's become setup fodder and has something better to switch to
static bool8 AreAttackingStatsLowered(u32 battler)
{
    s8 attackingStage = gBattleMons[battler].statStages[STAT_ATK];
    s8 spAttackingStage = gBattleMons[battler].statStages[STAT_SPATK];

    // Only use this if AI_FLAG_SMART_SWITCHING is set for the trainer
    if (!(AI_THINKING_STRUCT->aiFlags & AI_FLAG_SMART_SWITCHING))
        return FALSE;

    // Physical attacker
    if (gBattleMons[battler].attack > gBattleMons[battler].spAttack)
    {
        // Don't switch if attack isn't below -1
        if (attackingStage > DEFAULT_STAT_STAGE - 2)
            return FALSE;
        // 50% chance if attack at -2 and have a good candidate mon
        else if (attackingStage == DEFAULT_STAT_STAGE - 2)
        {
            if (AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE && (Random() & 1))
            {
                *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
                BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }
        // If at -3 or worse, switch out regardless
        else if (attackingStage < DEFAULT_STAT_STAGE - 2)
        {
            *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
            return TRUE;
        }
    }

    // Special attacker
    else
    {
        // Don't switch if attack isn't below -1
        if (spAttackingStage > DEFAULT_STAT_STAGE - 2)
            return FALSE;
        // 50% chance if attack at -2 and have a good candidate mon
        else if (spAttackingStage == DEFAULT_STAT_STAGE - 2)
        {
            if (AI_DATA->mostSuitableMonId[battler] != PARTY_SIZE && (Random() & 1))
            {
                *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
                BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }
        // If at -3 or worse, switch out regardless
        else if (spAttackingStage < DEFAULT_STAT_STAGE - 2)
        {
            *(gBattleStruct->AI_monToSwitchIntoId + battler) = PARTY_SIZE;
            BtlController_EmitTwoReturnValues(battler, 1, B_ACTION_SWITCH, 0);
            return TRUE;
        }
    }
    return FALSE;
}

bool32 ShouldSwitch(u32 battler)
{
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;
    s32 availableToSwitch;
    bool32 hasAceMon = FALSE;

    if (gBattleMons[battler].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
        return FALSE;
    if (gStatuses3[battler] & STATUS3_ROOTED)
        return FALSE;
    if (IsAbilityPreventingEscape(battler))
        return FALSE;
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return FALSE;

    availableToSwitch = 0;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)))])
            battlerIn2 = battler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)));
    }
    else
    {
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    GetAIPartyIndexes(battler, &firstId, &lastId);

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        if (!IsValidForBattle(&party[i]))
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;
        if (IsAceMon(battler, i))
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
    if (ShouldSwitchIfWonderGuard(battler))
        return TRUE;
    if (ShouldSwitchIfGameStatePrompt(battler))
        return TRUE;
    if (FindMonThatAbsorbsOpponentsMove(battler))
        return TRUE;

    //These Functions can prompt switch to generic pary members
    if ((AI_THINKING_STRUCT->aiFlags & AI_FLAG_SMART_SWITCHING) && (CanMonSurviveHazardSwitchin(battler) == FALSE))
        return FALSE;
    if (ShouldSwitchIfAllBadMoves(battler))
        return TRUE;
    if (ShouldSwitchIfAbilityBenefit(battler))
        return TRUE;
    if (HasBadOdds(battler))
        return TRUE;
    if (ShouldSwitchIfEncored(battler))
        return TRUE;
    if (AreAttackingStatsLowered(battler))
        return TRUE;

    //Removing switch capabilites under specific conditions
    //These Functions prevent the "FindMonWithFlagsAndSuperEffective" from getting out of hand.
    if (HasSuperEffectiveMoveAgainstOpponents(battler, FALSE))
        return FALSE;
    if (AreStatsRaised(battler))
        return FALSE;

    //Default Function
    //Can prompt switch if AI has a pokemon in party that resists current opponent & has super effective move
    if (FindMonWithFlagsAndSuperEffective(battler, MOVE_RESULT_DOESNT_AFFECT_FOE, 2)
        || FindMonWithFlagsAndSuperEffective(battler, MOVE_RESULT_NOT_VERY_EFFECTIVE, 3))
        return TRUE;

    return FALSE;
}

void AI_TrySwitchOrUseItem(u32 battler)
{
    struct Pokemon *party;
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    u8 battlerPosition = GetBattlerPosition(battler);

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (ShouldSwitch(battler))
        {
            if (*(gBattleStruct->AI_monToSwitchIntoId + battler) == PARTY_SIZE)
            {
                s32 monToSwitchId = AI_DATA->mostSuitableMonId[battler];
                if (monToSwitchId == PARTY_SIZE)
                {
                    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerPosition);
                        battlerIn2 = battlerIn1;
                    }
                    else
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerPosition);
                        battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(battlerPosition));
                    }

                    GetAIPartyIndexes(battler, &firstId, &lastId);

                    for (monToSwitchId = (lastId-1); monToSwitchId >= firstId; monToSwitchId--)
                    {
                        if (!IsValidForBattle(&party[monToSwitchId]))
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn1])
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn2])
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
                            continue;
                        if (IsAceMon(battler, monToSwitchId))
                            continue;

                        break;
                    }
                }

                *(gBattleStruct->AI_monToSwitchIntoId + battler) = monToSwitchId;
            }

            *(gBattleStruct->monToSwitchIntoId + battler) = *(gBattleStruct->AI_monToSwitchIntoId + battler);
            return;
        }
        else if (ShouldUseItem(battler))
        {
            return;
        }
    }

    BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_USE_MOVE, BATTLE_OPPOSITE(battler) << 8);
}

// If there are two(or more) mons to choose from, always choose one that has baton pass
// as most often it can't do much on its own.
static u32 GetBestMonBatonPass(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, int aliveCount, u32 battler, u32 opposingBattler)
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

static u32 GetBestMonTypeMatchup(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, u32 battler, u32 opposingBattler)
{
    int i, bits = 0;

    while (bits != 0x3F) // All mons were checked.
    {
        uq4_12_t bestResist = UQ_4_12(1.0);
        int bestMonId = PARTY_SIZE;
        // Find the mon whose type is the most suitable defensively.
        for (i = firstId; i < lastId; i++)
        {
            if (!(gBitTable[i] & invalidMons) && !(gBitTable[i] & bits))
            {
                u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
                uq4_12_t typeEffectiveness = UQ_4_12(1.0);

                u8 atkType1 = gBattleMons[opposingBattler].type1;
                u8 atkType2 = gBattleMons[opposingBattler].type2;
                u8 defType1 = gSpeciesInfo[species].types[0];
                u8 defType2 = gSpeciesInfo[species].types[1];

                typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType1, defType1)));
                if (atkType2 != atkType1)
                    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType2, defType1)));
                if (defType2 != defType1)
                {
                    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType1, defType2)));
                    if (atkType2 != atkType1)
                        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType2, defType2)));
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
                if (move != MOVE_NONE && AI_GetTypeEffectiveness(move, battler, opposingBattler) >= UQ_4_12(2.0))
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

static u32 GetBestMonDmg(struct Pokemon *party, int firstId, int lastId, u8 invalidMons, u32 battler, u32 opposingBattler)
{
    int i, j;
    int dmg, bestDmg = 0;
    int bestMonId = PARTY_SIZE;
    u32 aiMove;

    gMoveResultFlags = 0;
    // If we couldn't find the best mon in terms of typing, find the one that deals most damage.
    for (i = firstId; i < lastId; i++)
    {
        if (gBitTable[i] & invalidMons)
            continue;
        InitializeSwitchinCandidate(&party[i]);
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            aiMove = AI_DATA->switchinCandidate.battleMon.moves[j];
            if (aiMove != MOVE_NONE && gBattleMoves[aiMove].power != 0)
            {
                aiMove = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                dmg = AI_CalcPartyMonDamage(aiMove, battler, opposingBattler, AI_DATA->switchinCandidate.battleMon, TRUE);
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

static bool32 IsMonGrounded(u16 heldItemEffect, u32 ability, u8 type1, u8 type2)
{
    // List that makes mon not grounded
    if (type1 == TYPE_FLYING || type2 == TYPE_FLYING || ability == ABILITY_LEVITATE
         || (heldItemEffect == HOLD_EFFECT_AIR_BALLOON && ability != ABILITY_KLUTZ))
    {
        // List that overrides being off the ground
        if ((heldItemEffect == HOLD_EFFECT_IRON_BALL && ability != ABILITY_KLUTZ) || (gFieldStatuses & STATUS_FIELD_GRAVITY) || (gFieldStatuses & STATUS_FIELD_MAGIC_ROOM))
            return TRUE;
        else
            return FALSE;
    }
    else
        return TRUE;
}

// Gets hazard damage
static u32 GetSwitchinHazardsDamage(u32 battler, struct BattlePokemon *battleMon)
{
    u8 defType1 = battleMon->type1, defType2 = battleMon->type2, tSpikesLayers;
    u16 heldItemEffect = gItems[battleMon->item].holdEffect;
    u32 maxHP = battleMon->maxHP, ability = battleMon->ability, status = battleMon->status1;
    u32 spikesDamage = 0, tSpikesDamage = 0, hazardDamage = 0;
    u32 hazardFlags = gSideStatuses[GetBattlerSide(battler)] & (SIDE_STATUS_SPIKES | SIDE_STATUS_STEALTH_ROCK | SIDE_STATUS_STICKY_WEB | SIDE_STATUS_TOXIC_SPIKES | SIDE_STATUS_SAFEGUARD);

    // Check ways mon might avoid all hazards
    if (ability != ABILITY_MAGIC_GUARD || (heldItemEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS &&
        !((gFieldStatuses & STATUS_FIELD_MAGIC_ROOM) || ability == ABILITY_KLUTZ)))
    {
        // Stealth Rock
        if ((hazardFlags & SIDE_STATUS_STEALTH_ROCK) && heldItemEffect != HOLD_EFFECT_HEAVY_DUTY_BOOTS)
            hazardDamage += GetStealthHazardDamageByTypesAndHP(gBattleMoves[MOVE_STEALTH_ROCK].type, defType1, defType2, battleMon->maxHP);
        // Spikes
        if ((hazardFlags & SIDE_STATUS_SPIKES) && IsMonGrounded(heldItemEffect, ability, defType1, defType2))
        {
            spikesDamage = maxHP / ((5 - gSideTimers[GetBattlerSide(battler)].spikesAmount) * 2);
            if (spikesDamage == 0)
                spikesDamage = 1;
            hazardDamage += spikesDamage;
        }

        // Toxic Spikes
        // TODO: CanBePoisoned compatibility to avoid duplicate code
        if ((hazardFlags & SIDE_STATUS_TOXIC_SPIKES) && (defType1 != TYPE_POISON && defType2 != TYPE_POISON
            && defType1 != TYPE_STEEL && defType2 != TYPE_STEEL
            && ability != ABILITY_IMMUNITY && ability != ABILITY_POISON_HEAL && ability != ABILITY_COMATOSE
            && status == 0
            && !(hazardFlags & SIDE_STATUS_SAFEGUARD)
            && !(IsAbilityOnSide(battler, ABILITY_PASTEL_VEIL))
            && !(IsBattlerTerrainAffected(battler, STATUS_FIELD_MISTY_TERRAIN))
            && !(IsAbilityStatusProtected(battler))
            && heldItemEffect != HOLD_EFFECT_CURE_PSN && heldItemEffect != HOLD_EFFECT_CURE_STATUS
            && IsMonGrounded(heldItemEffect, ability, defType1, defType2)))
        {
            tSpikesLayers = gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount;
            if (tSpikesLayers == 1)
            {
                tSpikesDamage = maxHP / 8;
                if (tSpikesDamage == 0)
                    tSpikesDamage = 1;
            }
            else if (tSpikesLayers >= 2)
            {
                tSpikesDamage = maxHP / 16;
                if (tSpikesDamage == 0)
                    tSpikesDamage = 1;
            }
            hazardDamage += tSpikesDamage;
        }
    }
    return hazardDamage;
}

// Gets damage / healing from weather
static s32 GetSwitchinWeatherImpact(void)
{
    s32 weatherImpact = 0, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, ability = AI_DATA->switchinCandidate.battleMon.ability;
    u16 item = AI_DATA->switchinCandidate.battleMon.item;

    if (WEATHER_HAS_EFFECT)
    {
        // Damage
        if (item != ITEM_SAFETY_GOGGLES)
        {
            if ((gBattleWeather & B_WEATHER_HAIL) && (AI_DATA->switchinCandidate.battleMon.type1 != TYPE_ICE || AI_DATA->switchinCandidate.battleMon.type2 != TYPE_ICE)
            && ability != ABILITY_OVERCOAT && ability != ABILITY_SNOW_CLOAK && ability != ABILITY_ICE_BODY)
            {
                weatherImpact = maxHP / 16;
                if (weatherImpact == 0)
                    weatherImpact = 1;
            }
            else if ((gBattleWeather & B_WEATHER_SANDSTORM) && (AI_DATA->switchinCandidate.battleMon.type1 != TYPE_GROUND && AI_DATA->switchinCandidate.battleMon.type2 != TYPE_GROUND
                && AI_DATA->switchinCandidate.battleMon.type1 != TYPE_ROCK && AI_DATA->switchinCandidate.battleMon.type2 != TYPE_ROCK
                && AI_DATA->switchinCandidate.battleMon.type1 != TYPE_STEEL && AI_DATA->switchinCandidate.battleMon.type2 != TYPE_STEEL
                && ability != ABILITY_OVERCOAT && ability != ABILITY_SAND_VEIL && ability != ABILITY_SAND_RUSH && ability != ABILITY_SAND_FORCE))
            {
                weatherImpact = maxHP / 16;
                if (weatherImpact == 0)
                    weatherImpact = 1;
            }
        }
        if ((gBattleWeather & B_WEATHER_SUN) && (ability == ABILITY_SOLAR_POWER || ability == ABILITY_DRY_SKIN))
        {
            weatherImpact = maxHP / 8;
            if (weatherImpact == 0)
                weatherImpact = 1;
        }

        // Healing
        if (gBattleWeather & B_WEATHER_RAIN)
        {
            if (ability == ABILITY_DRY_SKIN)
            {
                weatherImpact = maxHP / 8;
                if (weatherImpact == 0)
                    weatherImpact = 1;
            }
            else if (ability == ABILITY_RAIN_DISH)
            {
                weatherImpact = maxHP / 16;
                if (weatherImpact == 0)
                    weatherImpact = 1;
            }
        }
        if (((gBattleWeather & B_WEATHER_HAIL) || (gBattleWeather & B_WEATHER_SNOW)) && ability == ABILITY_ICE_BODY)
        {
            weatherImpact = maxHP / 16;
            if (weatherImpact == 0)
                weatherImpact =1;
        }
    }
    return weatherImpact;
}

// Gets one turn of recurring healing
static u32 GetSwitchinRecurringHealing(void)
{
    u32 recurringHealing = 0, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, ability = AI_DATA->switchinCandidate.battleMon.ability;
    u16 item = AI_DATA->switchinCandidate.battleMon.item;

    // Items
    if (ability != ABILITY_KLUTZ)
    {
        if (item == ITEM_BLACK_SLUDGE && (AI_DATA->switchinCandidate.battleMon.type1 == TYPE_POISON || AI_DATA->switchinCandidate.battleMon.type2 == TYPE_POISON))
        {
            recurringHealing = maxHP / 16;
            if (recurringHealing == 0)
                recurringHealing = 1;
        }
        else if (item == ITEM_LEFTOVERS)
        {
            recurringHealing = maxHP / 16;
            if (recurringHealing == 0)
                recurringHealing = 1;
        }
    } // Intentionally omitting Shell Bell for its inconsistency

    // Abilities
    if (ability == ABILITY_POISON_HEAL && (AI_DATA->switchinCandidate.battleMon.status1 & STATUS1_POISON))
    {
        recurringHealing = maxHP / 8;
        if (recurringHealing == 0)
            recurringHealing = 1;
    }
    return recurringHealing;
}

// Gets one turn of recurring damage
static u32 GetSwitchinRecurringDamage(void)
{
    u32 passiveDamage = 0, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, ability = AI_DATA->switchinCandidate.battleMon.ability;
    u16 item = AI_DATA->switchinCandidate.battleMon.item;

    // Items
    if (ability != ABILITY_MAGIC_GUARD && ability != ABILITY_KLUTZ)
    {
        if (item == ITEM_BLACK_SLUDGE && AI_DATA->switchinCandidate.battleMon.type1 != TYPE_POISON && AI_DATA->switchinCandidate.battleMon.type2 != TYPE_POISON)
        {
            passiveDamage = maxHP / 8;
            if (passiveDamage == 0)
                passiveDamage = 1;
        }
        else if (item == ITEM_LIFE_ORB && ability != ABILITY_SHEER_FORCE)
        {
            passiveDamage = maxHP / 10;
            if (passiveDamage == 0)
                passiveDamage = 1;
        }
        else if (item == ITEM_STICKY_BARB)
        {
            passiveDamage = maxHP / 8;
            if(passiveDamage == 0)
                passiveDamage = 1;
        }
    }
    return passiveDamage;
}

// Gets one turn of status damage
static u32 GetSwitchinStatusDamage(u32 battler)
{
    u8 defType1 = AI_DATA->switchinCandidate.battleMon.type1, defType2 = AI_DATA->switchinCandidate.battleMon.type2;
    u8 tSpikesLayers = gSideTimers[GetBattlerSide(battler)].toxicSpikesAmount;
    u16 heldItemEffect = gItems[AI_DATA->switchinCandidate.battleMon.item].holdEffect;
    u32 status = AI_DATA->switchinCandidate.battleMon.status1, ability = AI_DATA->switchinCandidate.battleMon.ability, maxHP = AI_DATA->switchinCandidate.battleMon.maxHP;
    u32 statusDamage = 0;

    // Status condition damage
    if ((status != 0) && AI_DATA->switchinCandidate.battleMon.ability != ABILITY_MAGIC_GUARD)
    {
        if (status & STATUS1_BURN)
        {
            #if B_BURN_DAMAGE >= GEN_7
                statusDamage = maxHP / 16;
            #else
                statusDamage = maxHP / 8;
            #endif
            if(ability == ABILITY_HEATPROOF)
                statusDamage = statusDamage / 2;
            if (statusDamage == 0)
                statusDamage = 1;
        }
        else if (status & STATUS1_FROSTBITE)
        {
            #if B_BURN_DAMAGE >= GEN_7
                statusDamage = maxHP / 16;
            #else
                statusDamage = maxHP / 8;
            #endif
            if (statusDamage == 0)
                statusDamage = 1;
        }
        else if ((status & STATUS1_POISON) && ability != ABILITY_POISON_HEAL)
        {
            statusDamage = maxHP / 8;
            if (statusDamage == 0)
                statusDamage = 1;
        }
        else if ((status & STATUS1_TOXIC_POISON) && ability != ABILITY_POISON_HEAL)
        {
            if ((status & STATUS1_TOXIC_COUNTER) != STATUS1_TOXIC_TURN(15)) // not 16 turns
                AI_DATA->switchinCandidate.battleMon.status1 += STATUS1_TOXIC_TURN(1);
            statusDamage *= AI_DATA->switchinCandidate.battleMon.status1 & STATUS1_TOXIC_COUNTER >> 8;
            if (statusDamage == 0)
                statusDamage = 1;
        }
    }

    // Apply hypothetical poisoning from Toxic Spikes, which means the first turn of damage already added in GetSwitchinHazardsDamage
    // Do this last to skip one iteration of Poison / Toxic damage, and start counting Toxic damage one turn later.
    if (tSpikesLayers != 0 && (defType1 != TYPE_POISON && defType2 != TYPE_POISON
        && ability != ABILITY_IMMUNITY && ability != ABILITY_POISON_HEAL
        && status == 0
        && !(heldItemEffect == HOLD_EFFECT_HEAVY_DUTY_BOOTS
            && (((gFieldStatuses & STATUS_FIELD_MAGIC_ROOM) || ability == ABILITY_KLUTZ)))
        && heldItemEffect != HOLD_EFFECT_CURE_PSN && heldItemEffect != HOLD_EFFECT_CURE_STATUS
        && IsMonGrounded(heldItemEffect, ability, defType1, defType2)))
    {
        if (tSpikesLayers == 1)
        {
            AI_DATA->switchinCandidate.battleMon.status1 = STATUS1_POISON; // Assign "hypothetical" status to the switchin candidate so we can get the damage it would take from TSpikes
            AI_DATA->switchinCandidate.hypotheticalStatus = TRUE;
        }
        if (tSpikesLayers == 2)
        {
            AI_DATA->switchinCandidate.battleMon.status1 = STATUS1_TOXIC_POISON; // Assign "hypothetical" status to the switchin candidate so we can get the damage it would take from TSpikes
            AI_DATA->switchinCandidate.battleMon.status1 += STATUS1_TOXIC_TURN(1);
            AI_DATA->switchinCandidate.hypotheticalStatus = TRUE;
        }
    }
    return statusDamage;
}

// Gets number of hits to KO factoring in hazards, healing held items, status, and weather
static u32 GetSwitchinHitsToKO(s32 damageTaken, u32 battler)
{
    u32 startingHP = AI_DATA->switchinCandidate.battleMon.hp - GetSwitchinHazardsDamage(battler, &AI_DATA->switchinCandidate.battleMon);
    s32 weatherImpact = GetSwitchinWeatherImpact(); // Signed to handle both damage and healing in the same value
    u32 recurringDamage = GetSwitchinRecurringDamage();
    u32 recurringHealing = GetSwitchinRecurringHealing();
    u32 statusDamage = GetSwitchinStatusDamage(battler);
    u32 hitsToKO = 0, singleUseItemHeal = 0;
    u16 maxHP = AI_DATA->switchinCandidate.battleMon.maxHP, item = AI_DATA->switchinCandidate.battleMon.item, heldItemEffect = gItems[AI_DATA->switchinCandidate.battleMon.item].holdEffect;
    u8 weatherDuration = gWishFutureKnock.weatherDuration, holdEffectParam = gItems[AI_DATA->switchinCandidate.battleMon.item].holdEffectParam;
    u32 opposingBattler = GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerPosition(battler)));
    u32 opposingAbility = gBattleMons[opposingBattler].ability;
    bool8 usedSingleUseHealingItem = FALSE;
    s32 currentHP = startingHP;

    // No damage being dealt
    if (damageTaken + statusDamage + recurringDamage == 0)
        return startingHP;

    // Mon fainted to hazards
    if (startingHP == 0)
        return 1;

    // Find hits to KO
    while (currentHP > 0)
    {
        // Remove weather damage when it would run out
        if (weatherImpact != 0 && weatherDuration == 0)
            weatherImpact = 0;

        // Take attack damage for the turn
        currentHP = currentHP - damageTaken;

        // If mon is still alive, apply weather impact first, as it might KO the mon before it can heal with its item (order is weather -> item -> status)
        if (currentHP != 0)
            currentHP = currentHP + weatherImpact;

        // Check if we're at a single use healing item threshold
        if (AI_DATA->switchinCandidate.battleMon.ability != ABILITY_KLUTZ && usedSingleUseHealingItem == FALSE)
        {
            if (currentHP < maxHP / 2)
            {
                if (item == ITEM_BERRY_JUICE)
                {
                    singleUseItemHeal = holdEffectParam;
                }
                else if (opposingAbility != ABILITY_UNNERVE && heldItemEffect == HOLD_EFFECT_RESTORE_HP)
                {
                    // By default, this should only encompass Oran Berry and Sitrus Berry.
                    singleUseItemHeal = holdEffectParam;
                    if (singleUseItemHeal == 0)
                        singleUseItemHeal = 1;
                }
            }
            else if (currentHP < maxHP / CONFUSE_BERRY_HP_FRACTION
                && opposingAbility != ABILITY_UNNERVE
                && (item == ITEM_AGUAV_BERRY || item == ITEM_FIGY_BERRY || item == ITEM_IAPAPA_BERRY || item == ITEM_MAGO_BERRY || item == ITEM_WIKI_BERRY))
            {
                singleUseItemHeal = maxHP / CONFUSE_BERRY_HEAL_FRACTION;
                if (singleUseItemHeal == 0)
                    singleUseItemHeal = 1;
            }

            // If we used one, apply it without overcapping our maxHP
            if (singleUseItemHeal > 0)
            {
                if ((currentHP + singleUseItemHeal) > maxHP)
                    currentHP = maxHP;
                else
                    currentHP = currentHP + singleUseItemHeal;
                usedSingleUseHealingItem = TRUE;
            }
        }

        // Healing from items occurs before status so we can do the rest in one line
        if (currentHP != 0)
            currentHP = currentHP + recurringHealing - recurringDamage - statusDamage;

        // Recalculate toxic damage if needed
        if (AI_DATA->switchinCandidate.battleMon.status1 & STATUS1_TOXIC_POISON)
            statusDamage = GetSwitchinStatusDamage(battler);

        // Reduce weather duration
        if (weatherDuration != 0)
            weatherDuration--;

        hitsToKO++;
    }

    // If mon had a hypothetical status from TSpikes, clear it
    if (AI_DATA->switchinCandidate.hypotheticalStatus == TRUE)
    {
        AI_DATA->switchinCandidate.battleMon.status1 = 0;
        AI_DATA->switchinCandidate.hypotheticalStatus = FALSE;
    }
    return hitsToKO;
}

static u16 GetSwitchinTypeMatchup(u32 opposingBattler, struct BattlePokemon battleMon)
{

    // Check type matchup
    u16 typeEffectiveness = UQ_4_12(1.0);
    u8 atkType1 = gSpeciesInfo[gBattleMons[opposingBattler].species].types[0], atkType2 = gSpeciesInfo[gBattleMons[opposingBattler].species].types[1],
    defType1 = battleMon.type1, defType2 = battleMon.type2;

    // Multiply type effectiveness by a factor depending on type matchup
    typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType1, defType1)));
    if (atkType2 != atkType1)
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType2, defType1)));
    if (defType2 != defType1)
    {
        typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType1, defType2)));
        if (atkType2 != atkType1)
            typeEffectiveness = uq4_12_multiply(typeEffectiveness, (GetTypeModifier(atkType2, defType2)));
    }
    return typeEffectiveness;
}

static int GetRandomSwitchinWithBatonPass(int aliveCount, int bits, int firstId, int lastId, int currentMonId)
{
    // Breakout early if there aren't any Baton Pass mons to save computation time
    if (bits == 0)
        return PARTY_SIZE;

    // GetBestMonBatonPass randomly chooses between all mons that met Baton Pass check
    if ((aliveCount == 2 || (aliveCount > 2 && Random() % 3 == 0)) && bits)
    {
        do
        {
            return (Random() % (lastId - firstId)) + firstId;
        } while (!(bits & gBitTable[currentMonId]));
    }

    // Catch any other cases (such as only one mon alive and it has Baton Pass)
    else
        return PARTY_SIZE;
}

static s32 GetMaxDamagePlayerCouldDealToSwitchin(u32 battler, u32 opposingBattler, struct BattlePokemon battleMon)
{
    int i = 0;
    u32 playerMove;
    s32 damageTaken = 0, maxDamageTaken = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        playerMove = gBattleMons[opposingBattler].moves[i];
        if (playerMove != MOVE_NONE && gBattleMoves[playerMove].power != 0)
        {
            damageTaken = AI_CalcPartyMonDamage(playerMove, opposingBattler, battler, battleMon, FALSE);
            if (damageTaken > maxDamageTaken)
                maxDamageTaken = damageTaken;
        }
    }
    return maxDamageTaken;
}

// This function splits switching behaviour mid-battle from after a KO.
// Mid battle, it integrates GetBestMonTypeMatchup (vanilla with modifications), GetBestMonDefensive (custom), and GetBestMonBatonPass (vanilla with modifications)
// After a KO, integrates GetBestMonRevengeKiller (custom), GetBestMonTypeMatchup (vanilla with modifications), GetBestMonBatonPass (vanilla with modifications), and GetBestMonDmg (vanilla)
// the Type Matchup code will prioritize switching into a mon with the best type matchup and also a super effective move, or just best type matchup if no super effective move is found
// the Most Defensive code will prioritize switching into the mon that takes the most hits to KO, with a minimum of 4 hits required to be considered a valid option
// the Baton Pass code will prioritize switching into a mon with Baton Pass if it can get in, boost, and BP out without being KO'd, and randomizes between multiple valid options
// the Revenge Killer code will prioritize, in order, OHKO and outspeeds / OHKO, slower but not 2HKO'd / 2HKO, outspeeds and not OHKO'd / 2HKO, slower but not 3HKO'd
// the Most Damage code will prioritize switching into whatever mon deals the most damage, which is generally not as good as having a good Type Matchup
// Everything runs in the same loop to minimize computation time. This makes it harder to read, but hopefully the comments can guide you!

static u32 GetBestMonIntegrated(struct Pokemon *party, int firstId, int lastId, u32 battler, u32 opposingBattler, u8 battlerIn1, u8 battlerIn2, bool8 isSwitchAfterKO)
{
    int revengeKillerId = PARTY_SIZE, slowRevengeKillerId = PARTY_SIZE, fastThreatenId = PARTY_SIZE, slowThreatenId = PARTY_SIZE, damageMonId = PARTY_SIZE;
    int batonPassId = PARTY_SIZE, typeMatchupId = PARTY_SIZE, typeMatchupEffectiveId = PARTY_SIZE, defensiveMonId = PARTY_SIZE, aceMonId = PARTY_SIZE;
    int i, j, aliveCount = 0, bits = 0;
    s32 defensiveMonHitKOThreshold = 3; // 3HKO threshold that candidate defensive mons must exceed
    u32 aiMove, hitsToKO, hitsToKOThreshold, maxHitsToKO = 0;
    s32 playerMonSpeed = gBattleMons[opposingBattler].speed, playerMonHP = gBattleMons[opposingBattler].hp, aiMonSpeed, maxDamageDealt = 0, damageDealt = 0;
    u16 bestResist = UQ_4_12(1.0), bestResistEffective = UQ_4_12(1.0), typeMatchup;

    if (isSwitchAfterKO)
        hitsToKOThreshold = 1; // After a KO, mons at minimum need to not be 1-shot, as they switch in for free
    else
        hitsToKOThreshold = 2; // When switching in otherwise need to not be 2-shot, as they do not switch in for free

    // Iterate through mons
    for (i = firstId; i < lastId; i++)
    {
        // Check mon validity
        if (!IsValidForBattle(&party[i])
            || gBattlerPartyIndexes[battlerIn1] == i
            || gBattlerPartyIndexes[battlerIn2] == i
            || i == *(gBattleStruct->monToSwitchIntoId + battlerIn1)
            || i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
        {
            continue;
        }
        // Save Ace Pokemon for last
        else if (IsAceMon(battler, i))
        {
            aceMonId = i;
            continue;
        }
        else
            aliveCount++;

        InitializeSwitchinCandidate(&party[i]);

        // While not really invalid per say, not really wise to switch into this mon
        if (AI_DATA->switchinCandidate.battleMon.ability == ABILITY_TRUANT && IsTruantMonVulnerable(battler, opposingBattler))
            continue;

        // Get max number of hits for player to KO AI mon
        hitsToKO = GetSwitchinHitsToKO(GetMaxDamagePlayerCouldDealToSwitchin(battler, opposingBattler, AI_DATA->switchinCandidate.battleMon), battler);

        // Track max hits to KO and set GetBestMonDefensive if applicable
        if(hitsToKO > maxHitsToKO)
        {
            maxHitsToKO = hitsToKO;
            if(maxHitsToKO > defensiveMonHitKOThreshold)
                defensiveMonId = i;
        }

        typeMatchup = GetSwitchinTypeMatchup(opposingBattler, AI_DATA->switchinCandidate.battleMon);

        // Check that good type matchups gets at least two turns and set GetBestMonTypeMatchup if applicable
        if (typeMatchup < bestResist)
        {
            if ((hitsToKO > hitsToKOThreshold && AI_DATA->switchinCandidate.battleMon.speed > playerMonSpeed) || hitsToKO > hitsToKOThreshold + 1) // Need to take an extra hit if slower
            {
                bestResist = typeMatchup;
                typeMatchupId = i;
            }
        }

        aiMonSpeed = AI_DATA->switchinCandidate.battleMon.speed;

        // Check through current mon's moves
        for (j = 0; j < MAX_MON_MOVES; j++)
        {
            aiMove = AI_DATA->switchinCandidate.battleMon.moves[j];

            // Only do damage calc if switching after KO, don't need it otherwise and saves ~0.02s per turn
            if (isSwitchAfterKO && aiMove != MOVE_NONE && gBattleMoves[aiMove].power != 0)
                damageDealt = AI_CalcPartyMonDamage(aiMove, battler, opposingBattler, AI_DATA->switchinCandidate.battleMon, TRUE);

            // Check for Baton Pass; hitsToKO requirements mean mon can boost and BP without dying whether it's slower or not
            if (aiMove == MOVE_BATON_PASS && ((hitsToKO > hitsToKOThreshold + 1 && AI_DATA->switchinCandidate.battleMon.speed < playerMonSpeed) || (hitsToKO > hitsToKOThreshold && AI_DATA->switchinCandidate.battleMon.speed > playerMonSpeed)))
                bits |= gBitTable[i];

            // Check for mon with resistance and super effective move for GetBestMonTypeMatchup
            if (aiMove != MOVE_NONE && gBattleMoves[aiMove].power != 0)
            {
                if (typeMatchup < bestResistEffective)
                {
                    if (AI_GetTypeEffectiveness(aiMove, battler, opposingBattler) >= UQ_4_12(2.0))
                    {
                        // Assuming a super effective move would do significant damage or scare the player out, so not being as conservative here
                        if (hitsToKO > hitsToKOThreshold)
                        {
                            bestResistEffective = typeMatchup;
                            typeMatchupEffectiveId = i;
                        }
                    }
                }

                // If a self destruction move doesn't OHKO, don't factor it into revenge killing
                if (gBattleMoves[aiMove].effect == EFFECT_EXPLOSION && damageDealt < playerMonHP)
                    continue;

                // Check that mon isn't one shot and set GetBestMonDmg if applicable
                if (damageDealt > maxDamageDealt)
                {
                    if(hitsToKO > hitsToKOThreshold)
                    {
                        maxDamageDealt = damageDealt;
                        damageMonId = i;
                    }
                }

                // Check if current mon can revenge kill in some capacity
                // If AI mon can one shot
                if (damageDealt > playerMonHP)
                {
                    // If AI mon is faster and doesn't die to hazards
                    if ((aiMonSpeed > playerMonSpeed || gBattleMoves[aiMove].priority > 0) && AI_DATA->switchinCandidate.battleMon.hp > GetSwitchinHazardsDamage(battler, &AI_DATA->switchinCandidate.battleMon))
                    {
                        // We have a revenge killer
                        revengeKillerId = i;
                    }

                    // If AI mon is slower
                    else
                    {
                        // If AI mon can't be OHKO'd
                        if (hitsToKO > hitsToKOThreshold)
                        {
                            // We have a slow revenge killer
                            slowRevengeKillerId = i;
                        }
                    }
                }

                // If AI mon can two shot
                if (damageDealt > playerMonHP / 2)
                {
                    // If AI mon is faster
                    if (aiMonSpeed > playerMonSpeed || gBattleMoves[aiMove].priority > 0)
                    {
                        // If AI mon can't be OHKO'd
                        if (hitsToKO > hitsToKOThreshold)
                        {
                            // We have a fast threaten
                            fastThreatenId = i;
                        }
                    }
                    // If AI mon is slower
                    else
                    {
                        // If AI mon can't be 2HKO'd
                        if (hitsToKO > hitsToKOThreshold + 1)
                        {
                            // We have a slow threaten
                            slowThreatenId = i;
                        }
                    }
                }
            }
        }
    }

    batonPassId = GetRandomSwitchinWithBatonPass(aliveCount, bits, firstId, lastId, i);

    // Different switching priorities depending on switching mid battle vs switching after a KO
    if (isSwitchAfterKO)
    {
        // Return GetBestMonRevengeKiller >  GetBestMonTypeMatchup > GetBestMonBatonPass > GetBestMonDmg
        if (revengeKillerId != PARTY_SIZE)
            return revengeKillerId;

        else if (slowRevengeKillerId != PARTY_SIZE)
            return slowRevengeKillerId;

        else if (fastThreatenId != PARTY_SIZE)
            return fastThreatenId;

        else if (slowThreatenId != PARTY_SIZE)
            return slowThreatenId;

        else if (typeMatchupEffectiveId != PARTY_SIZE)
            return typeMatchupEffectiveId;

        else if (typeMatchupId != PARTY_SIZE)
            return typeMatchupId;

        else if (batonPassId != PARTY_SIZE)
            return batonPassId;

        else if (damageMonId != PARTY_SIZE)
            return damageMonId;
    }
    else
    {
        // Return GetBestMonTypeMatchup > GetBestMonDefensive > GetBestMonBatonPass
        if (typeMatchupEffectiveId != PARTY_SIZE)
            return typeMatchupEffectiveId;

        else if (typeMatchupId != PARTY_SIZE)
            return typeMatchupId;

        else if (defensiveMonId != PARTY_SIZE)
            return defensiveMonId;

        else if (batonPassId != PARTY_SIZE)
            return batonPassId;

        // If ace mon is the last available Pokemon and U-Turn/Volt Switch was used - switch to the mon.
        else if (aceMonId != PARTY_SIZE
            && (gBattleMoves[gLastUsedMove].effect == EFFECT_HIT_ESCAPE || gBattleMoves[gLastUsedMove].effect == EFFECT_PARTING_SHOT))
            return aceMonId;
    }
    return PARTY_SIZE;
}

u8 GetMostSuitableMonToSwitchInto(u32 battler, bool32 switchAfterMonKOd)
{
    u32 opposingBattler = 0;
    u32 bestMonId = PARTY_SIZE;
    u8 battlerIn1 = 0, battlerIn2 = 0;
    s32 firstId = 0;
    s32 lastId = 0; // + 1
    struct Pokemon *party;

    if (*(gBattleStruct->monToSwitchIntoId + battler) != PARTY_SIZE)
        return *(gBattleStruct->monToSwitchIntoId + battler);
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return gBattlerPartyIndexes[battler] + 1;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = battler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)))])
            battlerIn2 = battler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(battler)));

        opposingBattler = BATTLE_OPPOSITE(battlerIn1);
        if (gAbsentBattlerFlags & gBitTable[opposingBattler])
            opposingBattler ^= BIT_FLANK;
    }
    else
    {
        opposingBattler = GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerPosition(battler)));
        battlerIn1 = battler;
        battlerIn2 = battler;
    }

    GetAIPartyIndexes(battler, &firstId, &lastId);

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // Split ideal mon decision between after previous mon KO'd (prioritize offensive options) and after switching active mon out (prioritize defensive options), and expand the scope of both.
    // Only use better mon selection if AI_FLAG_SMART_MON_CHOICES is set for the trainer.
    if (AI_THINKING_STRUCT->aiFlags & AI_FLAG_SMART_MON_CHOICES)
    {
        bestMonId = GetBestMonIntegrated(party, firstId, lastId, battler, opposingBattler, battlerIn1, battlerIn2, switchAfterMonKOd);
        return bestMonId;
    }

    // This all handled by the GetBestMonIntegrated function if the AI_FLAG_SMART_MON_CHOICES flag is set
    else
    {
        s32 i, aliveCount = 0;
        u32 invalidMons = 0, aceMonId = PARTY_SIZE;
        // Get invalid slots ids.
        for (i = firstId; i < lastId; i++)
        {
            if (!IsValidForBattle(&party[i])
                || gBattlerPartyIndexes[battlerIn1] == i
                || gBattlerPartyIndexes[battlerIn2] == i
                || i == *(gBattleStruct->monToSwitchIntoId + battlerIn1)
                || i == *(gBattleStruct->monToSwitchIntoId + battlerIn2)
                || (GetMonAbility(&party[i]) == ABILITY_TRUANT && IsTruantMonVulnerable(battler, opposingBattler))) // While not really invalid per say, not really wise to switch into this mon.)
            {
                invalidMons |= gBitTable[i];
            }
            else if (IsAceMon(battler, i))// Save Ace Pokemon for last.
            {
                aceMonId = i;
                invalidMons |= gBitTable[i];
            }
            else
            {
                aliveCount++;
            }
        }
        bestMonId = GetBestMonBatonPass(party, firstId, lastId, invalidMons, aliveCount, battler, opposingBattler);
        if (bestMonId != PARTY_SIZE)
            return bestMonId;

        bestMonId = GetBestMonTypeMatchup(party, firstId, lastId, invalidMons, battler, opposingBattler);
        if (bestMonId != PARTY_SIZE)
            return bestMonId;

        bestMonId = GetBestMonDmg(party, firstId, lastId, invalidMons, battler, opposingBattler);
        if (bestMonId != PARTY_SIZE)
            return bestMonId;

        // If ace mon is the last available Pokemon and switch move was used - switch to the mon.
        if (aceMonId != PARTY_SIZE)
            return aceMonId;

        return PARTY_SIZE;
    }
}

static bool32 AiExpectsToFaintPlayer(u32 battler)
{
    u8 target = gBattleStruct->aiChosenTarget[battler];

    if (gBattleStruct->aiMoveOrAction[battler] > 3)
        return FALSE; // AI not planning to use move

    if (GetBattlerSide(target) != GetBattlerSide(battler)
      && CanIndexMoveFaintTarget(battler, target, gBattleStruct->aiMoveOrAction[battler], 0)
      && AI_WhoStrikesFirst(battler, target, GetAIChosenMove(battler)) == AI_IS_FASTER) {
        // We expect to faint the target and move first -> dont use an item
        return TRUE;
    }

    return FALSE;
}

static bool8 ShouldUseItem(u32 battler)
{
    struct Pokemon *party;
    s32 i;
    u8 validMons = 0;
    bool8 shouldUse = FALSE;

    if (IsAiVsAiBattle())
        return FALSE;

    // If teaming up with player and Pokemon is on the right, or Pokemon is currently held by Sky Drop
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT)
       || gStatuses3[battler] & STATUS3_SKY_DROPPED)
        return FALSE;

    if (gStatuses3[battler] & STATUS3_EMBARGO)
        return FALSE;

    if (AiExpectsToFaintPlayer(battler))
        return FALSE;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (IsValidForBattle(&party[i]))
        {
            validMons++;
        }
    }

    for (i = 0; i < MAX_TRAINER_ITEMS; i++)
    {
        u16 item;
        const u8 *itemEffects;
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
            shouldUse = AI_ShouldHeal(battler, 0);
            break;
        case EFFECT_ITEM_RESTORE_HP:
            shouldUse = AI_ShouldHeal(battler, itemEffects[GetItemEffectParamOffset(battler, item, 4, ITEM4_HEAL_HP)]);
            break;
        case EFFECT_ITEM_CURE_STATUS:
            if (itemEffects[3] & ITEM3_SLEEP && gBattleMons[battler].status1 & STATUS1_SLEEP)
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_POISON && (gBattleMons[battler].status1 & STATUS1_POISON
                                               || gBattleMons[battler].status1 & STATUS1_TOXIC_POISON))
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_BURN && gBattleMons[battler].status1 & STATUS1_BURN)
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_FREEZE && (gBattleMons[battler].status1 & STATUS1_FREEZE || gBattleMons[battler].status1 & STATUS1_FROSTBITE))
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_PARALYSIS && gBattleMons[battler].status1 & STATUS1_PARALYSIS)
                shouldUse = TRUE;
            if (itemEffects[3] & ITEM3_CONFUSION && gBattleMons[battler].status2 & STATUS2_CONFUSION)
                shouldUse = TRUE;
            break;
        case EFFECT_ITEM_INCREASE_STAT:
        case EFFECT_ITEM_INCREASE_ALL_STATS:
            if (!gDisableStructs[battler].isFirstTurn
                || AI_OpponentCanFaintAiWithMod(battler, 0))
                break;
            shouldUse = TRUE;
            break;
        case EFFECT_ITEM_SET_FOCUS_ENERGY:
            if (!gDisableStructs[battler].isFirstTurn
                || gBattleMons[battler].status2 & STATUS2_FOCUS_ENERGY
                || AI_OpponentCanFaintAiWithMod(battler, 0))
                break;
            shouldUse = TRUE;
            break;
        case EFFECT_ITEM_SET_MIST:
            battlerSide = GetBattlerSide(battler);
            if (gDisableStructs[battler].isFirstTurn && gSideTimers[battlerSide].mistTimer == 0)
                shouldUse = TRUE;
            break;
        case EFFECT_ITEM_REVIVE:
            gBattleStruct->itemPartyIndex[battler] = GetFirstFaintedPartyIndex(battler);
            if (gBattleStruct->itemPartyIndex[battler] != PARTY_SIZE) // Revive if possible.
                shouldUse = TRUE;
            break;
        default:
            return FALSE;
        }
        if (shouldUse)
        {
            // Set selected party ID to current battler if none chosen.
            if (gBattleStruct->itemPartyIndex[battler] == PARTY_SIZE)
                gBattleStruct->itemPartyIndex[battler] = gBattlerPartyIndexes[battler];
            BtlController_EmitTwoReturnValues(battler, BUFFER_B, B_ACTION_USE_ITEM, 0);
            gBattleStruct->chosenItem[battler] = item;
            gBattleResources->battleHistory->trainerItems[i] = 0;
            return shouldUse;
        }
    }

    return FALSE;
}

static bool32 AI_ShouldHeal(u32 battler, u32 healAmount)
{
    bool32 shouldHeal = FALSE;

    if (gBattleMons[battler].hp < gBattleMons[battler].maxHP / 4
     || gBattleMons[battler].hp == 0
     || (healAmount != 0 && gBattleMons[battler].maxHP - gBattleMons[battler].hp > healAmount)) {
        // We have low enough HP to consider healing
        shouldHeal = !AI_OpponentCanFaintAiWithMod(battler, healAmount); // if target can kill us even after we heal, why bother
    }

    return shouldHeal;
}

static bool32 AI_OpponentCanFaintAiWithMod(u32 battler, u32 healAmount)
{
    u32 i;
    // Check special cases to NOT heal
    for (i = 0; i < gBattlersCount; i++) {
        if (GetBattlerSide(i) == B_SIDE_PLAYER) {
            if (CanTargetFaintAiWithMod(i, battler, healAmount, 0)) {
                // Target is expected to faint us
                return TRUE;
            }
        }
    }
    return FALSE;
}
