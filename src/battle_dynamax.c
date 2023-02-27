#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_scripts.h"
#include "battle_script_commands.h"
#include "data.h"
#include "pokemon.h"
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
	[TYPE_WATER] = MOVE_G_MAX_HYDROSNIPE,
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
	{SPECIES_CHARIZARD_GMAX,                    TYPE_FIRE,       MOVE_G_MAX_WILDFIRE},
	{SPECIES_BLASTOISE_GMAX,                    TYPE_WATER,      MOVE_G_MAX_CANNONADE},
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

// Returns whether a move should be converted into a Max Move.
bool8 ShouldUseMaxMove(u16 battlerId, u16 baseMove)
{
    // TODO: Raids
	//if (IsRaidBoss(battlerId))
	//	return !IsRaidBossUsingRegularMove(battlerId, baseMove);
	if (gBattleStruct->dynamax.dynamaxTurns[battlerId] > 0)
		return TRUE;
	return TRUE;
}

// Returns the appropriate Max Move or G-Max Move for a battler to use.
u16 GetMaxMove(u16 battlerId, u16 baseMove)
{
	u16 move = baseMove;
	if (gBattleMoves[baseMove].split == SPLIT_STATUS)
    {
		move = MOVE_MAX_GUARD;
    }
	else if (gBattleStruct->dynamicMoveType) // unsure of how to deal with Hidden Power
	{
		move = sMaxMoveTable[gBattleStruct->dynamicMoveType & DYNAMIC_TYPE_MASK];
        gBattleStruct->dynamax.splits[battlerId] = gBattleMoves[baseMove].split;
	}
	else
    {
		move = sMaxMoveTable[gBattleMoves[baseMove].type];
        gBattleStruct->dynamax.splits[battlerId] = gBattleMoves[baseMove].split;
    }

	return move;
}

// Gets the base power of a Max Move.
u8 GetMaxMovePower(u16 move)
{
	if (gBattleMoves[GetMaxMove(gBattlerAttacker, move)].argument == MAX_EFFECT_FIXED_POWER)
		return 160;
	else
		return gMaxMovePowers[move]; // TODO: Rework to a field in gBattleMoves.
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

// Activates the secondary effect of a Max Move.
u16 SetMaxMoveEffect(u16 move)
{
	u16 effect = 0;
	u8 maxEffect = gBattleMoves[move].argument;
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
				gBattlescriptCurrInstr = BattleScript_EffectRaiseSideStats;
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
				gBattlescriptCurrInstr = BattleScript_EffectLowerSideStats;
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
	}
	return effect;
}
