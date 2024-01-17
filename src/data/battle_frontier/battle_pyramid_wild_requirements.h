#if BATTLE_PYRAMID_RANDOM_ENCOUNTERS == TRUE

#include "constants/abilities.h"
#include "constants/battle_move_effects.h"

struct BattlePyramidRequirement {
    const u16 *moves; /* use moves instead of effects so we don't need to find moves with said effect in our loop */
    u16 abilities[10];
    u8 nAbilities;
    u8 type;
    u8 nMoves;
    const u16 *evoItems;
    u8 nEvoItems;
};

// EFFECT_PARALYZE, MOVE_EFFECT_PARALYZE (30% or more)
static const u16 sParalyzingMoves[] = {
    //MOVE_THUNDER_PUNCH,
    MOVE_BODY_SLAM,
    MOVE_STUN_SPORE,
    //MOVE_THUNDER_SHOCK,
    //MOVE_THUNDERBOLT,
    MOVE_THUNDER_WAVE,
    MOVE_LICK,
    MOVE_GLARE,
    MOVE_ZAP_CANNON,
    MOVE_SPARK,
    MOVE_DRAGON_BREATH,
    MOVE_FORCE_PALM,
    MOVE_DISCHARGE,
    //MOVE_BOLT_STRIKE,
    MOVE_NUZZLE,
    MOVE_SPLISHY_SPLASH,
    MOVE_BUZZY_BUZZ,
    MOVE_COMBAT_TORQUE,
};

// MOVE_EFFECT_POISON (30% or more), EFFECT_POISON, MOVE_EFFECT_TOXIC, EFFECT_TOXIC, EFFECT_TOXIC_THREAD
static const u16 sPoisoningMoves[] = {
    MOVE_POISON_STING,
    //MOVE_TWINEEDLE,
    MOVE_SMOG,
    MOVE_SLUDGE,
    MOVE_SLUDGE_BOMB,
    //MOVE_POISON_TAIL,
    MOVE_POISON_JAB,
    //MOVE_CROSS_POISON,
    MOVE_GUNK_SHOT,
    //MOVE_SLUDGE_WAVE,
    MOVE_NOXIOUS_TORQUE,
    //MOVE_ACID,
    MOVE_POISON_POWDER,
    MOVE_TOXIC,
    MOVE_POISON_GAS,
    MOVE_POISON_FANG,
    MOVE_BANEFUL_BUNKER,
    MOVE_TOXIC_THREAD,
};

// MOVE_EFFECT_BURN, EFFECT_WILL_O_WISP
static const u16 sBurningMoves[] = {
    MOVE_WILL_O_WISP,
    //MOVE_EMBER,
    //MOVE_FLAMETHROWER,
    //MOVE_FIRE_BLAST,
    //MOVE_HEAT_WAVE,
    //MOVE_BLAZE_KICK,
    MOVE_LAVA_PLUME,
    MOVE_SCALD,
    MOVE_INFERNO,
    MOVE_SEARING_SHOT,
    MOVE_BLUE_FLARE,
    MOVE_STEAM_ERUPTION,
    MOVE_SIZZLY_SLIDE,
    //MOVE_PYRO_BALL,
    MOVE_BURNING_JEALOUSY,
    MOVE_SCORCHING_SANDS,
    MOVE_SANDSEAR_STORM,
    MOVE_BLAZING_TORQUE,
};

// EFFECT_FREEZE, MOVE_EFFECT_FREEZE_OR_FROSTBITE
static const u16 sFrostbiteMoves[] = {
    MOVE_ICE_PUNCH,
    MOVE_ICE_BEAM,
    MOVE_BLIZZARD,
    MOVE_POWDER_SNOW,
    MOVE_FREEZING_GLARE,
};

// EFFECT_GRUDGE, EFFECT_SPITE, EFFECT_EERIE_SPELL
static const u16 sPPReducingMoves[] = {
    MOVE_GRUDGE,
    MOVE_SPITE,
    MOVE_EERIE_SPELL,
};

// EFFECT_EXPLOSION
static const u16 sExplosionMoves[] = {
    MOVE_SELF_DESTRUCT,
    MOVE_EXPLOSION,
    MOVE_MISTY_EXPLOSION,
};

// EFFECT_RAIN_DANCE, EFFECT_SANDSTORM, EFFECT_HAIL, EFFECT_SUNNY_DAY,
static const u16 sWeatherChangingMoves[] = {
    MOVE_RAIN_DANCE,
    MOVE_SANDSTORM,
    MOVE_HAIL,
    MOVE_SUNNY_DAY,
};

// MOVE_EFFECT_RECHARGE, recoil
static const u16 sPowerfulNormalMoves[] = {
    MOVE_HYPER_BEAM,
    MOVE_GIGA_IMPACT,
    MOVE_THRASH,
    MOVE_BODY_SLAM,
    MOVE_DOUBLE_EDGE,
};

static const u16 sEvoItems[] = {ITEM_FIRE_STONE, ITEM_WATER_STONE, ITEM_THUNDER_STONE};

static const struct BattlePyramidRequirement sBattlePyramidRequirementsByRound[] = {
    [0] = /* pokemon with moves that paraylze */
    {
        .type = TYPE_MYSTERY, // no type limitation
        .moves = sParalyzingMoves,
        .nMoves = NELEMS(sParalyzingMoves),
        .abilities = { ABILITY_STATIC },
        .nAbilities = 1,
    },
    [1] = /* pokemon with moves that poison */
    {
        .type = TYPE_MYSTERY,
        .moves = sPoisoningMoves,
        .nMoves = NELEMS(sPoisoningMoves),
        .abilities = { ABILITY_POISON_POINT },
    },
    [2] = /* Pokemon with moves that burn */
    {
        .type = TYPE_MYSTERY,
        .moves = sBurningMoves,
        .nMoves = NELEMS(sBurningMoves),
        .abilities = { ABILITY_FLAME_BODY },
        .nAbilities = 1,
    },
    [3] = /* pokemon with moves that waste PP */
    {
        .type = TYPE_MYSTERY,
        .moves = sPPReducingMoves,
        .nMoves = NELEMS(sPPReducingMoves),
        .abilities = { ABILITY_PRESSURE },
        .nAbilities = 1,
    },
    [4] = /* pokemon with Levitate */
    {
        .type = TYPE_MYSTERY,
        .abilities = { ABILITY_LEVITATE },
        .nAbilities = 1,
    },
    [5] = /* pokemon with trapping abilities */
    {
        .type = TYPE_MYSTERY,
        .abilities = { ABILITY_SHADOW_TAG, ABILITY_ARENA_TRAP }, // TODO magnet pull?
        .nAbilities = 2,
    },
    [6] = /* ice types */
    {
        .type = TYPE_ICE,
    },

    [7] = /* pokemon with explosion effects */
    {
        .type = TYPE_MYSTERY,
        .moves = sExplosionMoves,
        .nMoves = NELEMS(sExplosionMoves),
    },
    [8] = /* psychic types */
    {
        .type = TYPE_PSYCHIC,
    },
    [9] = /* rock types */
    {
        .type = TYPE_ROCK,
    },
    [10] = /* fighting types */
    {
        .type = TYPE_FIGHTING,
    },
    [11] = /* pokemon with weather-altering effects */
    {
        .type = TYPE_MYSTERY,
        .moves = sWeatherChangingMoves,
        .nMoves = NELEMS(sWeatherChangingMoves),
        .abilities = { ABILITY_SAND_SPIT, ABILITY_DRIZZLE, ABILITY_SNOW_WARNING, ABILITY_DROUGHT, ABILITY_SAND_STREAM },
        .nAbilities = 5,
    },
    [12] = /* bug types */
    {
        .type = TYPE_BUG,
    },
    [13] = /* dark types */
    {
        .type = TYPE_DARK,
    },
    [14] = /* water types */
    {
        .type = TYPE_WATER,
    },
    [15] = /* ghost types */
    {
        .type = TYPE_GHOST,
    },
    [16] = /* steel types */
    {
        .type = TYPE_STEEL,
    },
    [17] = /* flying/dragon types */
    {
        .type = TYPE_DRAGON,
    },
    [18] = /* evolve via water/thunder/fire stone */
    {
        .type = TYPE_MYSTERY,
        .evoItems = sEvoItems,
        .nEvoItems = 3,
    },
    [19] = /* normal with powerful moves */
    {
        .type = TYPE_NORMAL,
        .moves = sPowerfulNormalMoves,
        .nMoves = NELEMS(sPowerfulNormalMoves),
    },
};

#endif
