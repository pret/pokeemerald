#include "battle_anim_scripts.h"

#define ENVIRONMENT_BACKGROUND(Background)             \
{                                                      \
    .tileset = gBattleEnvironmentTiles_##Background,   \
    .tilemap = gBattleEnvironmentTilemap_##Background, \
}

#define ENVIRONMENT_ENTRY(Background)                      \
{                                                          \
    .tileset = gBattleEnvironmentAnimTiles_##Background,   \
    .tilemap = gBattleEnvironmentAnimTilemap_##Background, \
}

#define DEFAULT_CAMOUFLAGE_BLEND RGB_WHITE

// Cave values. Used for BATTLE_ENVIRONMENT_CAVE as well as BATTLE_ENVIRONMENT_GROUDON and BATTLE_ENVIRONMENT_KYOGRE
#if B_NATURE_POWER_MOVES >= GEN_6
    #define CAVE_NATURE_POWER MOVE_POWER_GEM
#elif B_NATURE_POWER_MOVES >= GEN_4
    #define CAVE_NATURE_POWER MOVE_ROCK_SLIDE
#else
    #define CAVE_NATURE_POWER MOVE_SHADOW_BALL
#endif
#define CAVE_SECRET_POWER_ANIMATION B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_RockThrow : gBattleAnimMove_Bite
#define CAVE_SECRET_POWER_EFFECT    MOVE_EFFECT_FLINCH
#define CAVE_CAMOUFLAGE_TYPE        TYPE_ROCK
#define CAVE_CAMOUFLAGE_BLEND       RGB(14, 9, 3)
#define CAVE_BATTLE_INTRO_SLIDE     BattleIntroSlide1

// Building values. Used for BATTLE_ENVIRONMENT_BUILDING as well as the environments that come from the vanilla MAP_BATTLE_SCENEs: BATTLE_ENVIRONMENT_PLAIN, BATTLE_ENVIRONMENT_FRONTIER, BATTLE_ENVIRONMENT_GYM, BATTLE_ENVIRONMENT_LEADER, BATTLE_ENVIRONMENT_MAGMA, BATTLE_ENVIRONMENT_AQUA, BATTLE_ENVIRONMENT_SIDNEY, BATTLE_ENVIRONMENT_PHOEBE, BATTLE_ENVIRONMENT_GLACIA, BATTLE_ENVIRONMENT_DRAKE, BATTLE_ENVIRONMENT_CHAMPION
#define BUILDING_NATURE_POWER        B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_TRI_ATTACK : MOVE_SWIFT
#if B_SECRET_POWER_ANIMATION >= GEN_7
    #define BUILDING_SECRET_POWER_ANIMATION gBattleAnimMove_SpitUp
#elif B_SECRET_POWER_ANIMATION >= GEN_4
    #define BUILDING_SECRET_POWER_ANIMATION gBattleAnimMove_BodySlam
#else
    #define BUILDING_SECRET_POWER_ANIMATION gBattleAnimMove_Strength
#endif
#define BUILDING_SECRET_POWER_EFFECT MOVE_EFFECT_PARALYSIS
#define BUILDING_CAMOUFLAGE_TYPE     TYPE_NORMAL
#define BUILDING_CAMOUFLAGE_BLEND    RGB_WHITE
#define BUILDING_BATTLE_INTRO_SLIDE  BattleIntroSlide3

// Plain values. USED for BATTLE_ENVIRONMENT_PLAIN as well as BATTLE_ENVIRONMENT_RAYQUAZA
// (BATTLE_ENVIRONMENT_SKY_PILLAR wasn't introduced until Gen6, so Sky Pillar's roof counts as a Route which uses Plain)
#if B_NATURE_POWER_MOVES >= GEN_6
    #define PLAIN_NATURE_POWER MOVE_TRI_ATTACK
#elif B_NATURE_POWER_MOVES >= GEN_4
    #define PLAIN_NATURE_POWER MOVE_EARTHQUAKE
#else
    #define PLAIN_NATURE_POWER MOVE_SWIFT
#endif
#if B_SECRET_POWER_ANIMATION >= GEN_7
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_SpitUp
#elif B_SECRET_POWER_ANIMATION == GEN_6
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_BodySlam
#elif B_SECRET_POWER_ANIMATION >= GEN_4
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_MudSlap
#else
    #define PLAIN_SECRET_POWER_ANIMATION gBattleAnimMove_Slam
#endif
#define PLAIN_SECRET_POWER_EFFECT (B_SECRET_POWER_EFFECT == GEN_4 || B_SECRET_POWER_EFFECT == GEN_5) ? SECRET_POWER_ACC_MINUS_1 : MOVE_EFFECT_PARALYSIS
#define PLAIN_CAMOUFLAGE_TYPE     (B_CAMOUFLAGE_TYPES == GEN_4 || B_CAMOUFLAGE_TYPES == GEN_5) ? TYPE_GROUND : TYPE_NORMAL
#define PLAIN_CAMOUFLAGE_BLEND    RGB_WHITE
#define PLAIN_BATTLE_INTRO_SLIDE  BattleIntroSlide3

const struct BattleEnvironment gBattleEnvironmentInfo[BATTLE_ENVIRONMENT_COUNT] =
{
    [BATTLE_ENVIRONMENT_GRASS] =
    {
        .name = _("Grass"),
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_ENERGY_BALL,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_SEED_BOMB,
    #else
        .naturePower = MOVE_STUN_SPORE,
    #endif
        .secretPowerAnimation = gBattleAnimMove_NeedleArm,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? MOVE_EFFECT_SLEEP : MOVE_EFFECT_POISON,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(12, 24, 2),
        .entry = ENVIRONMENT_ENTRY(TallGrass),
        .background = ENVIRONMENT_BACKGROUND(TallGrass),
        .palette = gBattleEnvironmentPalette_TallGrass,
        .battleIntroSlide = BattleIntroSlide1,
    },

    [BATTLE_ENVIRONMENT_LONG_GRASS] =
    {
        .name = _("Long Grass"),
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_ENERGY_BALL,
    #elif B_NATURE_POWER_MOVES >= GEN_4
        .naturePower = MOVE_SEED_BOMB,
    #else
        .naturePower = MOVE_RAZOR_LEAF,
    #endif
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_NeedleArm : gBattleAnimMove_MagicalLeaf,
        .secretPowerEffect = MOVE_EFFECT_SLEEP,
        .camouflageType = TYPE_GRASS,
        .camouflageBlend = RGB(0, 15, 2),
        .entry = ENVIRONMENT_ENTRY(LongGrass),
        .background = ENVIRONMENT_BACKGROUND(LongGrass),
        .palette = gBattleEnvironmentPalette_LongGrass,
        .battleIntroSlide = BattleIntroSlide1,
    },

    [BATTLE_ENVIRONMENT_SAND] =
    {
        .name = _("Sand"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_6 ? MOVE_EARTH_POWER : MOVE_EARTHQUAKE,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_MudSlap : gBattleAnimMove_MudShot,
        .secretPowerEffect = SECRET_POWER_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = RGB(30, 24, 11),
        .entry = ENVIRONMENT_ENTRY(Sand),
        .background = ENVIRONMENT_BACKGROUND(Sand),
        .palette = gBattleEnvironmentPalette_Sand,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_UNDERWATER] =
    {
        .name = _("Underwater"),
        .naturePower = MOVE_HYDRO_PUMP,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_6 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_Waterfall,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_6 ? SECRET_POWER_ATK_MINUS_1 : SECRET_POWER_DEF_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(0, 0, 18),
        .entry = ENVIRONMENT_ENTRY(Underwater),
        .background = ENVIRONMENT_BACKGROUND(Underwater),
        .palette = gBattleEnvironmentPalette_Underwater,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_WATER] =
    {
        .name = _("Water"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_SURF,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_Surf,
        .secretPowerEffect = SECRET_POWER_ATK_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(11, 22, 31),
        .entry = ENVIRONMENT_ENTRY(Water),
        .background = ENVIRONMENT_BACKGROUND(Water),
        .palette = gBattleEnvironmentPalette_Water,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_POND] =
    {
        .name = _("Pond"),
        .naturePower = B_NATURE_POWER_MOVES >= GEN_4 ? MOVE_HYDRO_PUMP : MOVE_BUBBLE_BEAM,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_4 ? gBattleAnimMove_WaterPulse : gBattleAnimMove_BubbleBeam,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_4 ? SECRET_POWER_ATK_MINUS_1 : SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_WATER,
        .camouflageBlend = RGB(11, 22, 31),
        .entry = ENVIRONMENT_ENTRY(PondWater),
        .background = ENVIRONMENT_BACKGROUND(PondWater),
        .palette = gBattleEnvironmentPalette_PondWater,
        .battleIntroSlide = BattleIntroSlide1,
    },

    [BATTLE_ENVIRONMENT_MOUNTAIN] =
    {
        .name = _("Mountain"),
    #if B_NATURE_POWER_MOVES >= GEN_6
        .naturePower = MOVE_EARTH_POWER,
    #elif B_NATURE_POWER_MOVES >= GEN_5
        .naturePower = MOVE_EARTHQUAKE,
    #else
        .naturePower = MOVE_ROCK_SLIDE,
    #endif
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_5 ? gBattleAnimMove_MudSlap : gBattleAnimMove_RockThrow,
    #if B_SECRET_POWER_EFFECT >= GEN_5
        .secretPowerEffect = SECRET_POWER_ACC_MINUS_1,
    #elif B_SECRET_POWER_EFFECT == GEN_4
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
    #else
        .secretPowerEffect = MOVE_EFFECT_CONFUSION,
    #endif
        .camouflageType = B_CAMOUFLAGE_TYPES >= GEN_5 ? TYPE_GROUND : TYPE_ROCK,
        .camouflageBlend = RGB(22, 16, 10),
        .entry = ENVIRONMENT_ENTRY(Rock),
        .background = ENVIRONMENT_BACKGROUND(Rock),
        .palette = gBattleEnvironmentPalette_Rock,
        .battleIntroSlide = BattleIntroSlide1,
    },

    [BATTLE_ENVIRONMENT_CAVE] =
    {
        .name = _("Cave"),
        .naturePower = CAVE_NATURE_POWER,
        .secretPowerAnimation = CAVE_SECRET_POWER_ANIMATION,
        .secretPowerEffect = CAVE_SECRET_POWER_EFFECT,
        .camouflageType = CAVE_CAMOUFLAGE_TYPE,
        .camouflageBlend = CAVE_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Cave),
        .background = ENVIRONMENT_BACKGROUND(Cave),
        .palette = gBattleEnvironmentPalette_Cave,
        .battleIntroSlide = CAVE_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_BUILDING] =
    {
        .name = _("Building"),
        .naturePower = BUILDING_NATURE_POWER,
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_Building,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_PLAIN] =
    {
        .name = _("Plain"),
        .naturePower = PLAIN_NATURE_POWER,
        .secretPowerAnimation = PLAIN_SECRET_POWER_ANIMATION,
        .secretPowerEffect = PLAIN_SECRET_POWER_EFFECT,
        .camouflageType = PLAIN_CAMOUFLAGE_TYPE,
        .camouflageBlend = PLAIN_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_Plain,
        .battleIntroSlide = PLAIN_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_FRONTIER] =
    {
        .name = _("Frontier"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_Frontier,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_GYM] =
    {
        .name = _("Gym"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_BuildingGym,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_LEADER] =
    {
        .name = _("Leader"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Building),
        .palette = gBattleEnvironmentPalette_BuildingLeader,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_MAGMA] =
    {
        .name = _("Magma"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumMagma,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_AQUA] =
    {
        .name = _("Aqua"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumAqua,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_SIDNEY] =
    {
        .name = _("Sidney"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumSidney,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_PHOEBE] =
    {
        .name = _("Phoebe"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumPhoebe,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_GLACIA] =
    {
        .name = _("Glacia"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumGlacia,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_DRAKE] =
    {
        .name = _("Drake"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumDrake,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_CHAMPION] =
    {
        .name = _("Champion"),
        .secretPowerAnimation = BUILDING_SECRET_POWER_ANIMATION,
        .secretPowerEffect = BUILDING_SECRET_POWER_EFFECT,
        .camouflageType = BUILDING_CAMOUFLAGE_TYPE,
        .camouflageBlend = BUILDING_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Building),
        .background = ENVIRONMENT_BACKGROUND(Stadium),
        .palette = gBattleEnvironmentPalette_StadiumWallace,
        .battleIntroSlide = BUILDING_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_GROUDON] =
    {
        .name = _("Groudon"),
        .naturePower = CAVE_NATURE_POWER,
        .secretPowerAnimation = CAVE_SECRET_POWER_ANIMATION,
        .secretPowerEffect = CAVE_SECRET_POWER_EFFECT,
        .camouflageType = CAVE_CAMOUFLAGE_TYPE,
        .camouflageBlend = CAVE_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Cave),
        .background = ENVIRONMENT_BACKGROUND(Cave),
        .palette = gBattleEnvironmentPalette_Groudon,
        .battleIntroSlide = CAVE_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_KYOGRE] =
    {
        .name = _("Kyogre"),
        .naturePower = CAVE_NATURE_POWER,
        .secretPowerAnimation = CAVE_SECRET_POWER_ANIMATION,
        .secretPowerEffect = CAVE_SECRET_POWER_EFFECT,
        .camouflageType = CAVE_CAMOUFLAGE_TYPE,
        .camouflageBlend = CAVE_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Underwater),
        .background = ENVIRONMENT_BACKGROUND(Water),
        .palette = gBattleEnvironmentPalette_Kyogre,
        .battleIntroSlide = BattleIntroSlide2,
    },

    [BATTLE_ENVIRONMENT_RAYQUAZA] =
    {
        .name = _("Rayquaza"),
        .naturePower = PLAIN_NATURE_POWER,
        .secretPowerAnimation = PLAIN_SECRET_POWER_ANIMATION,
        .secretPowerEffect = PLAIN_SECRET_POWER_EFFECT,
        .camouflageType = PLAIN_CAMOUFLAGE_TYPE,
        .camouflageBlend = PLAIN_CAMOUFLAGE_BLEND,
        .entry = ENVIRONMENT_ENTRY(Rayquaza),
        .background = ENVIRONMENT_BACKGROUND(Rayquaza),
        .palette = gBattleEnvironmentPalette_Rayquaza,
        .battleIntroSlide = PLAIN_BATTLE_INTRO_SLIDE,
    },

    [BATTLE_ENVIRONMENT_SOARING] =
    {
        .name = _("Soaring"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = gBattleAnimMove_Gust,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_SKY_PILLAR] =
    {
        .name = _("Sky Pillar"),
        .naturePower = MOVE_AIR_SLASH,
        .secretPowerAnimation = gBattleAnimMove_Gust,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_FLYING,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_BURIAL_GROUND] =
    {
        .name = _("Burial Ground"),
        .naturePower = MOVE_SHADOW_BALL,
        .secretPowerAnimation = gBattleAnimMove_ShadowSneak,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_GHOST,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_PUDDLE] =
    {
        .name = _("Puddle"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_5 ? gBattleAnimMove_MudShot : gBattleAnimMove_MudSlap,
        .secretPowerEffect = B_SECRET_POWER_EFFECT >= GEN_5 ? SECRET_POWER_SPD_MINUS_1 : SECRET_POWER_ACC_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_MARSH] =
    {
        .name = _("Marsh"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = gBattleAnimMove_MudShot,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_SWAMP] =
    {
        .name = _("Swamp"),
        .naturePower = MOVE_MUD_BOMB,
        .secretPowerAnimation = gBattleAnimMove_MudShot,
        .secretPowerEffect = SECRET_POWER_SPD_MINUS_1,
        .camouflageType = TYPE_GROUND,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_SNOW] =
    {
        .name = _("Snow"),
    #if B_NATURE_POWER_MOVES >= GEN_7
        .naturePower = MOVE_ICE_BEAM,
    #elif B_NATURE_POWER_MOVES == GEN_6
        .naturePower = MOVE_FROST_BREATH,
    #else
        .naturePower = MOVE_BLIZZARD,
    #endif
        .secretPowerAnimation = B_SECRET_POWER_ANIMATION >= GEN_7 ? gBattleAnimMove_IceShard : gBattleAnimMove_Avalanche,
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_ICE] =
    {
        .name = _("Ice"),
        .naturePower = MOVE_ICE_BEAM,
        .secretPowerAnimation = gBattleAnimMove_IceShard,
        .secretPowerEffect = MOVE_EFFECT_FREEZE_OR_FROSTBITE,
        .camouflageType = TYPE_ICE,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_VOLCANO] =
    {
        .name = _("Volcano"),
        .naturePower = MOVE_LAVA_PLUME,
        .secretPowerAnimation = gBattleAnimMove_Incinerate,
        .secretPowerEffect = MOVE_EFFECT_BURN,
        .camouflageType = TYPE_FIRE,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_DISTORTION_WORLD] =
    {
        .name = _("Distortion World"),
        .naturePower = MOVE_TRI_ATTACK,
        .secretPowerAnimation = gBattleAnimMove_Pound,
        .secretPowerEffect = MOVE_EFFECT_PARALYSIS,
        .camouflageType = TYPE_NORMAL,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_SPACE] =
    {
        .name = _("Space"),
        .naturePower = MOVE_DRACO_METEOR,
        .secretPowerAnimation = gBattleAnimMove_Swift,
        .secretPowerEffect = MOVE_EFFECT_FLINCH,
        .camouflageType = TYPE_DRAGON,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },

    [BATTLE_ENVIRONMENT_ULTRA_SPACE] =
    {
        .name = _("Ultra Space"),
        .naturePower = MOVE_PSYSHOCK,
        .secretPowerAnimation = gBattleAnimMove_Psywave,
        .secretPowerEffect = SECRET_POWER_DEF_MINUS_1,
        .camouflageType = TYPE_PSYCHIC,
        .camouflageBlend = DEFAULT_CAMOUFLAGE_BLEND,
    },
};

static const struct {
    u8 mapScene;
    u8 battleEnvironment;
} sMapBattleSceneMapping[] = {
    {MAP_BATTLE_SCENE_GYM,      BATTLE_ENVIRONMENT_GYM},
    {MAP_BATTLE_SCENE_MAGMA,    BATTLE_ENVIRONMENT_MAGMA},
    {MAP_BATTLE_SCENE_AQUA,     BATTLE_ENVIRONMENT_AQUA},
    {MAP_BATTLE_SCENE_SIDNEY,   BATTLE_ENVIRONMENT_SIDNEY},
    {MAP_BATTLE_SCENE_PHOEBE,   BATTLE_ENVIRONMENT_PHOEBE},
    {MAP_BATTLE_SCENE_GLACIA,   BATTLE_ENVIRONMENT_GLACIA},
    {MAP_BATTLE_SCENE_DRAKE,    BATTLE_ENVIRONMENT_DRAKE},
    {MAP_BATTLE_SCENE_FRONTIER, BATTLE_ENVIRONMENT_FRONTIER}
};
