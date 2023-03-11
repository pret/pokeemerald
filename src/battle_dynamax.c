#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_scripts.h"
#include "battle_script_commands.h"
#include "data.h"
#include "pokemon.h"
#include "random.h"
#include "string_util.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_string_ids.h"
#include "constants/hold_effects.h"
#include "constants/moves.h"

// Constant Data
static const u16 sMaxMoveTable[] =
{
	[TYPE_NORMAL] = MOVE_MAX_STRIKE,
	[TYPE_FIGHTING] = MOVE_MAX_KNUCKLE,
	[TYPE_FLYING] = MOVE_MAX_AIRSTREAM,
	[TYPE_POISON] = MOVE_MAX_OOZE,
	[TYPE_GROUND] = MOVE_MAX_QUAKE,
	[TYPE_ROCK] = MOVE_MAX_ROCKFALL,
	[TYPE_BUG] = MOVE_MAX_FLUTTERBY,
	[TYPE_GHOST] = MOVE_MAX_PHANTASM,
	[TYPE_STEEL] = MOVE_MAX_STEELSPIKE,
	[TYPE_FIRE] = MOVE_MAX_FLARE,
	[TYPE_WATER] = MOVE_MAX_GEYSER,
	[TYPE_GRASS] = MOVE_MAX_OVERGROWTH,
	[TYPE_ELECTRIC] = MOVE_MAX_LIGHTNING,
	[TYPE_PSYCHIC] = MOVE_MAX_MINDSTORM,
	[TYPE_ICE] = MOVE_MAX_HAILSTORM,
	[TYPE_DRAGON] = MOVE_MAX_WYRMWIND,
	[TYPE_DARK] = MOVE_MAX_DARKNESS,
	[TYPE_FAIRY] = MOVE_MAX_STARFALL,
};

struct GMaxMove
{
	u16 species;
	u8 moveType;
	u16 gmaxMove;
};

static const struct GMaxMove sGMaxMoveTable[] =
{
	{SPECIES_VENUSAUR_GMAX,	                    TYPE_GRASS,      MOVE_G_MAX_VINE_LASH},
	{SPECIES_BLASTOISE_GMAX,                    TYPE_WATER,      MOVE_G_MAX_CANNONADE},
	{SPECIES_CHARIZARD_GMAX,                    TYPE_FIRE,       MOVE_G_MAX_WILDFIRE},
	{SPECIES_BUTTERFREE_GMAX,                   TYPE_BUG,        MOVE_G_MAX_BEFUDDLE},
	{SPECIES_PIKACHU_GMAX,                      TYPE_ELECTRIC,   MOVE_G_MAX_VOLT_CRASH},
	{SPECIES_MEOWTH_GMAX,                       TYPE_NORMAL,     MOVE_G_MAX_GOLD_RUSH},
	{SPECIES_MACHAMP_GMAX,                      TYPE_FIGHTING,   MOVE_G_MAX_CHI_STRIKE},
	{SPECIES_GENGAR_GMAX,                       TYPE_GHOST,      MOVE_G_MAX_TERROR},
	{SPECIES_KINGLER_GMAX,                      TYPE_WATER,      MOVE_G_MAX_FOAM_BURST},
	{SPECIES_LAPRAS_GMAX,                       TYPE_ICE,        MOVE_G_MAX_RESONANCE},
	{SPECIES_EEVEE_GMAX,                        TYPE_NORMAL,     MOVE_G_MAX_CUDDLE},
	{SPECIES_SNORLAX_GMAX,                      TYPE_NORMAL,     MOVE_G_MAX_REPLENISH},
	{SPECIES_GARBODOR_GMAX,                     TYPE_POISON,     MOVE_G_MAX_MALODOR},
	{SPECIES_MELMETAL_GMAX,                     TYPE_STEEL,      MOVE_G_MAX_MELTDOWN},
	{SPECIES_RILLABOOM_GMAX,                    TYPE_GRASS,      MOVE_G_MAX_DRUM_SOLO},
	{SPECIES_CINDERACE_GMAX,                    TYPE_FIRE,       MOVE_G_MAX_FIREBALL},
	{SPECIES_INTELEON_GMAX,                     TYPE_WATER,      MOVE_G_MAX_HYDROSNIPE},
	{SPECIES_CORVIKNIGHT_GMAX,                  TYPE_FLYING,     MOVE_G_MAX_WIND_RAGE},
	{SPECIES_ORBEETLE_GMAX,                     TYPE_PSYCHIC,    MOVE_G_MAX_GRAVITAS},
	{SPECIES_DREDNAW_GMAX,                      TYPE_WATER,      MOVE_G_MAX_STONESURGE},
	{SPECIES_COALOSSAL_GMAX,                    TYPE_ROCK,       MOVE_G_MAX_VOLCALITH},
	{SPECIES_FLAPPLE_GMAX,                      TYPE_GRASS,      MOVE_G_MAX_TARTNESS},
	{SPECIES_APPLETUN_GMAX,                     TYPE_GRASS,      MOVE_G_MAX_SWEETNESS},
	{SPECIES_SANDACONDA_GMAX,                   TYPE_GROUND,     MOVE_G_MAX_SANDBLAST},
	{SPECIES_TOXTRICITY_GMAX,                   TYPE_ELECTRIC,   MOVE_G_MAX_STUN_SHOCK},
	{SPECIES_CENTISKORCH_GMAX,                  TYPE_FIRE,       MOVE_G_MAX_CENTIFERNO},
	{SPECIES_HATTERENE_GMAX,                    TYPE_FAIRY,      MOVE_G_MAX_SMITE},
	{SPECIES_GRIMMSNARL_GMAX,                   TYPE_DARK,       MOVE_G_MAX_SNOOZE},
	{SPECIES_ALCREMIE_GMAX,                     TYPE_FAIRY,      MOVE_G_MAX_FINALE},
	{SPECIES_COPPERAJAH_GMAX,                   TYPE_STEEL,      MOVE_G_MAX_STEELSURGE},
	{SPECIES_DURALUDON_GMAX,                    TYPE_DRAGON,     MOVE_G_MAX_DEPLETION},
	{SPECIES_URSHIFU_GMAX,                      TYPE_DARK,       MOVE_G_MAX_ONE_BLOW},
	{SPECIES_URSHIFU_RAPID_STRIKE_STYLE_GMAX,   TYPE_WATER,      MOVE_G_MAX_RAPID_FLOW},
};

extern u8 gMaxMovePowers[MOVES_COUNT];

// Returns whether a battler is Dynamaxed.
bool8 IsDynamaxed(u16 battlerId)
{
	u8 side = GetBattlerSide(battlerId);
	if (gBattleStruct->dynamax.dynamaxed[battlerId]
		/*|| IsRaidBoss(battlerId)*/)
		return TRUE;
	return FALSE;
}

// Returns whether a battler can Dynamax.
bool8 CanDynamax(u16 battlerId)
{
	// TODO: Requires Dynamax Band if not in a Max Raid (as well as special flag).
	if (!gBattleStruct->dynamax.alreadyDynamaxed[GetBattlerSide(battlerId)]
		&& !gBattleStruct->dynamax.dynamaxed[battlerId]
		&& !gBattleStruct->dynamax.dynamaxed[BATTLE_PARTNER(battlerId)]
		&& !gBattleStruct->dynamax.toDynamax[BATTLE_PARTNER(battlerId)])
		return TRUE;
	return FALSE;
}

// Applies the HP Multiplier for Dynamaxed Pokemon and Raid Bosses.
void ApplyDynamaxHPMultiplier(u16 battlerId, struct Pokemon* mon)
{
	if (gBattleMons[battlerId].species == SPECIES_SHEDINJA)
		return;
	else
	{
		u16 mult = UQ_4_12(1.5); // placeholder
		u16 hp = UQ_4_12_TO_INT((GetMonData(mon, MON_DATA_HP, NULL) * mult) + UQ_4_12_ROUND);
		u16 maxHP = UQ_4_12_TO_INT((GetMonData(mon, MON_DATA_HP, NULL) * mult) + UQ_4_12_ROUND);
		SetMonData(mon, MON_DATA_HP, &hp);
		SetMonData(mon, MON_DATA_MAX_HP, &maxHP);
	}
}

// Sets flags used for Dynamaxing.
void PrepareBattlerForDynamax(u16 battlerId)
{
	u8 side = GetBattlerSide(battlerId);
	gBattleStruct->dynamax.alreadyDynamaxed[side] = TRUE;
	gBattleStruct->dynamax.dynamaxed[battlerId] = TRUE;
	gBattleStruct->dynamax.dynamaxTurns[battlerId] = DYNAMAX_TURNS;
}

// Sets flags needed for undoing Dynamax.
void UndoDynamax(u16 battlerId)
{
	u8 side = GetBattlerSide(battlerId);
	gBattleStruct->dynamax.dynamaxed[battlerId] = FALSE;
	gBattleStruct->dynamax.dynamaxTurns[battlerId] = 0; // safety check for switch-in / faint
	// TODO: Undo Gigantamax form change.
}

// Returns whether a move should be converted into a Max Move.
bool8 ShouldUseMaxMove(u16 battlerId, u16 baseMove)
{
    // TODO: Raids
	//if (IsRaidBoss(battlerId))
	//	return !IsRaidBossUsingRegularMove(battlerId, baseMove);
	return IsDynamaxed(battlerId) || gBattleStruct->dynamax.toDynamax[battlerId];
}

static u16 GetTypeBasedMaxMove(u16 battlerId, u16 type)
{
	u32 species;
	if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
		species = GetMonData(&gPlayerParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL);
	else
		species = GetMonData(&gEnemyParty[gBattlerPartyIndexes[battlerId]], MON_DATA_SPECIES, NULL);

	// Gigantamax check
	if (species >= (SPECIES_VENUSAUR_GMAX)
		&& sGMaxMoveTable[species - (SPECIES_VENUSAUR_GMAX)].moveType == type)
		return sGMaxMoveTable[species - (SPECIES_VENUSAUR_GMAX)].gmaxMove;

	// regular Max Move
	else
	{
		return sMaxMoveTable[type];
	}
}

// Returns the appropriate Max Move or G-Max Move for a battler to use.
u16 GetMaxMove(u16 battlerId, u16 baseMove)
{
	u16 move = baseMove;
	if (baseMove == MOVE_NONE) // for move display
	{
		return MOVE_NONE;
	}
	else if (baseMove == MOVE_STRUGGLE)
	{
		return MOVE_STRUGGLE;
	}
	else if (gBattleMoves[baseMove].split == SPLIT_STATUS)
    {
		move = MOVE_MAX_GUARD;
    }
	else if (gBattleStruct->dynamicMoveType) // unsure of how to deal with Hidden Power
	{
		move = GetTypeBasedMaxMove(battlerId, gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK);
        gBattleStruct->dynamax.splits[battlerId] = gBattleMoves[baseMove].split;
	}
	else
    {
		move = GetTypeBasedMaxMove(battlerId, gBattleMoves[baseMove].type);
        gBattleStruct->dynamax.splits[battlerId] = gBattleMoves[baseMove].split;
    }

	return move;
}

// Gets the base power of a Max Move.
u8 GetMaxMovePower(u16 move)
{
	// G-Max Drum Solo, G-Max Hydrosnipe, and G-Max Fireball always have 160 base power. 
	if (gBattleMoves[GetMaxMove(gBattlerAttacker, move)].argument == MAX_EFFECT_FIXED_POWER)
		return 160;
	else if (gBattleMoves[move].effect == EFFECT_MULTI_HIT
			 || gBattleMoves[move].effect == EFFECT_OHKO
			 || gBattleMoves[move].effect == EFFECT_LEVEL_DAMAGE
			 || gBattleMoves[move].effect == EFFECT_DRAGON_RAGE
			 || gBattleMoves[move].effect == EFFECT_SONICBOOM
			 || gBattleMoves[move].effect == EFFECT_PSYWAVE)
		return gMaxMovePowers[move];
	// Fighting and Poison Max Moves are weaker than other types.
	else if (gBattleMoves[move].type == TYPE_FIGHTING
			 || gBattleMoves[move].type == TYPE_POISON)
		switch (gBattleMoves[move].power)
		{
			default:
			case 10 ... 40: return 70;
			case 45 ... 50: return 75;
			case 55 ... 60: return 80;
			case 65 ... 70: return 85;
			case 75 ... 100: return 90;
			case 110 ... 140: return 95;
			case 150 ... 250: return 100;
		}
	else
		switch (gBattleMoves[move].power)
		{
			default:
			case 10 ... 40: return 90;
			case 45 ... 50: return 100;
			case 55 ... 60: return 110;
			case 65 ... 70: return 120;
			case 75 ... 100: return 130;
			case 110 ... 140: return 140;
			case 150 ... 250: return 150;
		}
}

// Returns whether a move is a Max Move or not.
bool8 IsMaxMove(u16 move)
{
	return move >= FIRST_MAX_MOVE && move <= LAST_MAX_MOVE;
}

// Returns the full name of a Max Move for the move usage text.
const u8 *GetMaxMoveName(u16 move)
{
    if (IsMaxMove(move))
        return gMaxMoveNames[move - FIRST_MAX_MOVE];
    else
        return gMaxMoveNames[0];   // Failsafe
}

// Assigns the multistring to use for the "Damage Non- Types" G-Max effect. 
void ChooseDamageNonTypesString(u8 type)
{
	switch (type) {
		case TYPE_GRASS:
			gBattleCommunication[MULTISTRING_CHOOSER] = 0;
			break;
		case TYPE_WATER:
			gBattleCommunication[MULTISTRING_CHOOSER] = 1;
			break;
		case TYPE_FIRE:
			gBattleCommunication[MULTISTRING_CHOOSER] = 2;
			break;
		case TYPE_ROCK:
			gBattleCommunication[MULTISTRING_CHOOSER] = 3;
			break;
	}
}

// Returns the status effect that should be applied by a G-Max Move.
u32 GetMaxMoveStatusEffect(u16 move)
{
	u8 maxEffect = gBattleMoves[move].argument;
	switch (maxEffect)
	{
		// Status 1
		case MAX_EFFECT_PARALYZE_FOES:
			return STATUS1_PARALYSIS;
		case MAX_EFFECT_POISON_FOES:
			return STATUS1_POISON;
		case MAX_EFFECT_POISON_PARALYZE_FOES:
			if (Random() % 2)
				return STATUS1_POISON;
			else
				return STATUS1_PARALYSIS;
		case MAX_EFFECT_EFFECT_SPORE_FOES:
		{
			u8 effect = Random() % 3;
			if (effect == 0)
				return STATUS1_PARALYSIS;
			else if (effect == 1)
				return STATUS1_POISON;
			else
				return STATUS1_SLEEP;
		}
		// Status 2
		case MAX_EFFECT_CONFUSE_FOES:
		case MAX_EFFECT_CONFUSE_FOES_PAY_DAY:
			return STATUS2_CONFUSION;
		case MAX_EFFECT_INFATUATE_FOES:
			return STATUS2_INFATUATION;
		case MAX_EFFECT_MEAN_LOOK:
			return STATUS2_ESCAPE_PREVENTION;
		case MAX_EFFECT_TORMENT_FOES:
			return STATUS2_TORMENT;
	}
}

// Activates the secondary effect of a Max Move.
u16 SetMaxMoveEffect(u16 move)
{
	u16 effect = 0;
	u8 maxEffect = gBattleMoves[move].argument;

	// Don't continue if the move didn't land.
	if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
		return effect;
	
	switch (maxEffect)
	{
		case MAX_EFFECT_RAISE_TEAM_ATTACK:
		case MAX_EFFECT_RAISE_TEAM_DEFENSE:
		case MAX_EFFECT_RAISE_TEAM_SPEED:
		case MAX_EFFECT_RAISE_TEAM_SP_ATK:
		case MAX_EFFECT_RAISE_TEAM_SP_DEF:
			if (!NoAliveMonsForEitherParty())
			{
				// Max Effects are ordered by stat ID.
				SET_STATCHANGER(gBattleMoves[gCurrentMove].argument, 1, FALSE);
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectRaiseStatAllies;
				effect++;
			}
			break;
		case MAX_EFFECT_LOWER_ATTACK:
		case MAX_EFFECT_LOWER_DEFENSE:
		case MAX_EFFECT_LOWER_SPEED:
		case MAX_EFFECT_LOWER_SP_ATK:
		case MAX_EFFECT_LOWER_SP_DEF:
		case MAX_EFFECT_LOWER_SPEED_2_FOES:
		case MAX_EFFECT_LOWER_EVASIVENESS_FOES:
			if (!NoAliveMonsForEitherParty())
			{
				u8 statId = 0;
				u8 stage = 1;
				switch (maxEffect)
				{
					case MAX_EFFECT_LOWER_SPEED_2_FOES:
						statId = STAT_SPEED;
						stage = 2;
						break;
					case MAX_EFFECT_LOWER_EVASIVENESS_FOES:
						statId = STAT_EVASION;
						break;
					default:
						// Max Effects are ordered by stat ID.
						statId = gBattleMoves[gCurrentMove].argument - MAX_EFFECT_LOWER_ATTACK + 1;
						break;
				}
				SET_STATCHANGER(statId, stage, TRUE);
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectLowerStatFoes;
				effect++;
			}
			break;
		case MAX_EFFECT_SUN:
		case MAX_EFFECT_RAIN:
		case MAX_EFFECT_SANDSTORM:
		case MAX_EFFECT_HAIL:
		{
			u8 weather, msg;
			switch (maxEffect)
			{
				case MAX_EFFECT_SUN:
					weather = ENUM_WEATHER_SUN;
					msg = B_MSG_STARTED_SUNLIGHT;
					break;
				case MAX_EFFECT_RAIN:
					weather = ENUM_WEATHER_RAIN;
					msg = B_MSG_STARTED_RAIN;
					break;
				case MAX_EFFECT_SANDSTORM:
					weather = ENUM_WEATHER_SANDSTORM;
					msg = B_MSG_STARTED_SANDSTORM;
					break;
				case MAX_EFFECT_HAIL:
					weather = ENUM_WEATHER_HAIL;
					msg = B_MSG_STARTED_HAIL;
					break;
			}
			if (TryChangeBattleWeather(gBattlerAttacker, weather, FALSE))
			{
				gBattleCommunication[MULTISTRING_CHOOSER] = msg;
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectSetWeather;
				effect++;
			}
			break;
		}
		case MAX_EFFECT_MISTY_TERRAIN:
		case MAX_EFFECT_GRASSY_TERRAIN:
		case MAX_EFFECT_ELECTRIC_TERRAIN:
		case MAX_EFFECT_PSYCHIC_TERRAIN:
		{
			u32 statusFlag = 0;
			u8 *timer = NULL;
			switch (gBattleMoves[gCurrentMove].argument)
			{
				case MAX_EFFECT_MISTY_TERRAIN:
					statusFlag = STATUS_FIELD_MISTY_TERRAIN, timer = &gFieldTimers.terrainTimer;
					gBattleCommunication[MULTISTRING_CHOOSER] = 0;
					break;
				case MAX_EFFECT_GRASSY_TERRAIN:
					statusFlag = STATUS_FIELD_GRASSY_TERRAIN, timer = &gFieldTimers.terrainTimer;
					gBattleCommunication[MULTISTRING_CHOOSER] = 1;
					break;
				case MAX_EFFECT_ELECTRIC_TERRAIN:
					statusFlag = STATUS_FIELD_ELECTRIC_TERRAIN, timer = &gFieldTimers.terrainTimer;
					gBattleCommunication[MULTISTRING_CHOOSER] = 2;
					break;
				case MAX_EFFECT_PSYCHIC_TERRAIN:
					statusFlag = STATUS_FIELD_PSYCHIC_TERRAIN, timer = &gFieldTimers.terrainTimer;
					gBattleCommunication[MULTISTRING_CHOOSER] = 3;
					break;
			}
			if (!(gFieldStatuses & statusFlag) && statusFlag != 0)
			{
				gFieldStatuses &= ~STATUS_FIELD_TERRAIN_ANY;
				gFieldStatuses |= statusFlag;
				if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_TERRAIN_EXTENDER)
					*timer = 8;
				else
					*timer = 5;
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectSetTerrain;
			}
			break;
		}
		case MAX_EFFECT_VINE_LASH:
		case MAX_EFFECT_CANNONADE:
		case MAX_EFFECT_WILDFIRE:
		case MAX_EFFECT_VOLCALITH:
		{
			u8 side = GetBattlerSide(gBattlerTarget);
			if (!(gSideStatuses[side] & SIDE_STATUS_DAMAGE_NON_TYPES))
			{
				gSideStatuses[side] |= SIDE_STATUS_DAMAGE_NON_TYPES;
				gSideTimers[side].damageNonTypesTimer = 4;
				gSideTimers[side].damageNonTypesType = gBattleMoves[gCurrentMove].type;
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				ChooseDamageNonTypesString(gBattleMoves[gCurrentMove].type);
				gBattlescriptCurrInstr = BattleScript_DamageNonTypesStarts;
				effect++;
			}
			break;
		}
		case MAX_EFFECT_STEALTH_ROCK:
			if (!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEALTH_ROCK))
			{
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_StealthRockActivates;
				effect++;
			}
			break;
		case MAX_EFFECT_STEELSURGE:
			if (!(gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_STEELSURGE))
			{
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_SteelsurgeActivates;
				effect++;
			}
			break;
		case MAX_EFFECT_DEFOG:
			if (gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_SCREEN_ANY
				|| gSideStatuses[GetBattlerSide(gBattlerTarget)] & SIDE_STATUS_HAZARDS_ANY
				|| gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_HAZARDS_ANY
				|| gFieldStatuses & STATUS_FIELD_TERRAIN_ANY)
			{
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_DefogTryHazards;
				effect++;
			}
			break;
		case MAX_EFFECT_AURORA_VEIL:
			if (!(gSideStatuses[GetBattlerSide(gBattlerAttacker)] & SIDE_STATUS_AURORA_VEIL))
			{
				gSideStatuses[GetBattlerSide(gBattlerAttacker)] |= SIDE_STATUS_AURORA_VEIL;
				if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_LIGHT_CLAY)
                	gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilTimer = 8;
				else
					gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilTimer = 5;
            	gSideTimers[GetBattlerSide(gBattlerAttacker)].auroraVeilBattlerId = gBattlerAttacker;
				gBattleCommunication[MULTISTRING_CHOOSER] = B_MSG_SET_SAFEGUARD;
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectAuroraVeilSuccess;
				effect++;
			}
			break;
		case MAX_EFFECT_GRAVITY:
			if (!(gFieldStatuses & STATUS_FIELD_GRAVITY))
			{
				gFieldStatuses |= STATUS_FIELD_GRAVITY;
				gFieldTimers.gravityTimer = 5;
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectGravitySuccess;
				effect++;
			}
			break;
		case MAX_EFFECT_SANDBLAST_FOES:
		case MAX_EFFECT_FIRE_SPIN_FOES:
		{
			// Affects both opponents, but doesn't print strings so we can handle it here.
			u8 battler;
			for (battler = 0; battler < MAX_BATTLERS_COUNT; ++battler)
			{
				if (GetBattlerSide(battler) != GetBattlerSide(gBattlerTarget))
					continue;
				if (!(gBattleMons[battler].status2 & STATUS2_WRAPPED))
				{
					gBattleMons[battler].status2 |= STATUS2_WRAPPED;
					if (GetBattlerHoldEffect(gBattlerAttacker, TRUE) == HOLD_EFFECT_GRIP_CLAW)
				#if B_BINDING_TURNS >= GEN_5
						gDisableStructs[battler].wrapTurns = 7;
					else
						gDisableStructs[battler].wrapTurns = (Random() % 2) + 4;
				#else
						gDisableStructs[battler].wrapTurns = 5;
					else
						gDisableStructs[battler].wrapTurns = (Random() % 4) + 2;
				#endif
					gBattleStruct->wrappedBy[battler] = gBattlerAttacker;
					if (maxEffect == MAX_EFFECT_SANDBLAST_FOES)
						gBattleStruct->wrappedMove[battler] = MOVE_SAND_TOMB;
					else
						gBattleStruct->wrappedMove[battler] = MOVE_FIRE_SPIN;
				}
			}
			break;
		}
		case MAX_EFFECT_YAWN_FOE:
			if (!(gStatuses3[gBattlerTarget] & STATUS3_YAWN)
				&& CanSleep(gBattlerTarget))
			{
				gStatuses3[gBattlerTarget] |= STATUS3_YAWN_TURN(2);
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectYawnSuccess;
				effect++;
			}
			break;
		case MAX_EFFECT_SPITE:
			if (gLastMoves[gBattlerTarget] != MOVE_NONE
				&& gLastMoves[gBattlerTarget] != MOVE_UNAVAILABLE)
			{
				BattleScriptPush(gBattlescriptCurrInstr + 1);
				gBattlescriptCurrInstr = BattleScript_EffectTryReducePP;
				effect++;
			}
			break;
		case MAX_EFFECT_PARALYZE_FOES:
		case MAX_EFFECT_POISON_FOES:
		case MAX_EFFECT_POISON_PARALYZE_FOES:
		case MAX_EFFECT_EFFECT_SPORE_FOES:
			BattleScriptPush(gBattlescriptCurrInstr + 1);
			gBattlescriptCurrInstr = BattleScript_EffectStatus1Foes;
			effect++;
			break;
		case MAX_EFFECT_CONFUSE_FOES_PAY_DAY:
			if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
			{
				u16 payday = gPaydayMoney;
				gPaydayMoney += (gBattleMons[gBattlerAttacker].level * 100);
				if (payday > gPaydayMoney)
					gPaydayMoney = 0xFFFF;
				gBattleCommunication[CURSOR_POSITION] = 1; // add "Coins scattered." message
			}
			// fall through
		case MAX_EFFECT_CONFUSE_FOES:
		case MAX_EFFECT_INFATUATE_FOES:
		case MAX_EFFECT_TORMENT_FOES:
		case MAX_EFFECT_MEAN_LOOK:
			BattleScriptPush(gBattlescriptCurrInstr + 1);
			gBattlescriptCurrInstr = BattleScript_EffectStatus2Foes;
			effect++;
			break;
		case MAX_EFFECT_CRIT_PLUS:
			gBattleStruct->bonusCritStages[gBattlerAttacker]++;
			gBattleStruct->bonusCritStages[BATTLE_PARTNER(gBattlerAttacker)]++;
			BattleScriptPush(gBattlescriptCurrInstr + 1);
			gBattlescriptCurrInstr = BattleScript_EffectRaiseCritAlliesAnim;
			effect++;
			break;
		case MAX_EFFECT_HEAL_TEAM:
			BattleScriptPush(gBattlescriptCurrInstr + 1);
			gBattlescriptCurrInstr = BattleScript_EffectHealOneSixthAllies;
			effect++;
			break;
		case MAX_EFFECT_AROMATHERAPY:
			BattleScriptPush(gBattlescriptCurrInstr + 1);
			gBattlescriptCurrInstr = BattleScript_EffectCureStatusAllies;
			effect++;
			break;
		case MAX_EFFECT_RECYCLE_BERRIES:
			BattleScriptPush(gBattlescriptCurrInstr + 1);
			gBattlescriptCurrInstr = BattleScript_EffectRecycleBerriesAllies;
			effect++;
			break;

	}
	return effect;
}
