#include "global.h"
#include "battle.h"
#include "data.h"
#include "pokemon.h"
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

// Functions:
bool8 ShouldUseMaxMove(u16 battlerId, u16 baseMove)
{
    // TODO: Raids
	//if (IsRaidBoss(battlerId))
	//	return !IsRaidBossUsingRegularMove(battlerId, baseMove);
	if (gBattleStruct->dynamax.dynamaxTurns[battlerId] > 0)
		return TRUE;
	return TRUE;
}

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

bool8 IsMaxMove(u16 move)
{
	return move >= FIRST_MAX_MOVE && move <= LAST_MAX_MOVE;
}

const u8 *GetMaxMoveName(u16 move)
{
    if (IsMaxMove(move))
        return gMaxMoveNames[move - FIRST_MAX_MOVE];
    else
        return gMaxMoveNames[0];   // Failsafe
}
