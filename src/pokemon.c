#include "global.h"
#include "malloc.h"
#include "apprentice.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "bw_summary_screen.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "evolution_scene.h"
#include "field_specials.h"
#include "field_weather.h"
#include "graphics.h"
#include "item.h"
#include "level_caps.h"
#include "link.h"
#include "main.h"
#include "overworld.h"
#include "m4a.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokeblock.h"
#include "pokemon.h"
#include "pokemon_animation.h"
#include "pokemon_icon.h"
#include "pokemon_summary_screen.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "recorded_battle.h"
#include "rtc.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "trainer_hill.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/battle_move_effects.h"
#include "constants/battle_script_commands.h"
#include "constants/battle_partner.h"
#include "constants/cries.h"
#include "constants/event_objects.h"
#include "constants/form_change_types.h"
#include "constants/hold_effects.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/union_room.h"
#include "constants/weather.h"
#include "tx_randomizer_and_challenges.h"
#include "daycare.h"
#include "config/general.h"
#include "field_screen_effect.h"
#include "script.h"
#include "wild_encounter.h"

#define FRIENDSHIP_EVO_THRESHOLD ((P_FRIENDSHIP_EVO_THRESHOLD >= GEN_8) ? 160 : 220)


#define RANDOM_MOVES_COUNT ARRAY_COUNT(sRandomValidMoves)
static const u16 sRandomValidMoves[] =
{
    MOVE_POUND,
    MOVE_KARATE_CHOP,
    MOVE_DOUBLE_SLAP,
    MOVE_COMET_PUNCH,
    MOVE_MEGA_PUNCH,
    MOVE_PAY_DAY,
    MOVE_FIRE_PUNCH,
    MOVE_ICE_PUNCH,
    MOVE_THUNDER_PUNCH,
    MOVE_SCRATCH,
    MOVE_VISE_GRIP,
    MOVE_GUILLOTINE,
    MOVE_RAZOR_WIND,
    MOVE_SWORDS_DANCE,
    MOVE_CUT,
    MOVE_GUST,
    MOVE_WING_ATTACK,
    MOVE_WHIRLWIND,
    MOVE_FLY,
    MOVE_BIND,
    MOVE_SLAM,
    MOVE_VINE_WHIP,
    MOVE_STOMP,
    MOVE_DOUBLE_KICK,
    MOVE_MEGA_KICK,
    MOVE_JUMP_KICK,
    MOVE_ROLLING_KICK,
    MOVE_SAND_ATTACK,
    MOVE_HEADBUTT,
    MOVE_HORN_ATTACK,
    MOVE_FURY_ATTACK,
    MOVE_HORN_DRILL,
    MOVE_TACKLE,
    MOVE_BODY_SLAM,
    MOVE_WRAP,
    MOVE_TAKE_DOWN,
    MOVE_THRASH,
    MOVE_DOUBLE_EDGE,
    MOVE_TAIL_WHIP,
    MOVE_POISON_STING,
    MOVE_TWINEEDLE,
    MOVE_PIN_MISSILE,
    MOVE_LEER,
    MOVE_BITE,
    MOVE_GROWL,
    MOVE_ROAR,
    MOVE_SING,
    MOVE_SUPERSONIC,
    MOVE_SONIC_BOOM,
    MOVE_DISABLE,
    MOVE_ACID,
    MOVE_EMBER,
    MOVE_FLAMETHROWER,
    MOVE_MIST,
    MOVE_WATER_GUN,
    MOVE_HYDRO_PUMP,
    MOVE_SURF,
    MOVE_ICE_BEAM,
    MOVE_BLIZZARD,
    MOVE_PSYBEAM,
    MOVE_BUBBLE_BEAM,
    MOVE_AURORA_BEAM,
    MOVE_HYPER_BEAM,
    MOVE_PECK,
    MOVE_DRILL_PECK,
    MOVE_SUBMISSION,
    MOVE_LOW_KICK,
    MOVE_COUNTER,
    MOVE_SEISMIC_TOSS,
    MOVE_STRENGTH,
    MOVE_ABSORB,
    MOVE_MEGA_DRAIN,
    MOVE_LEECH_SEED,
    MOVE_GROWTH,
    MOVE_RAZOR_LEAF,
    MOVE_SOLAR_BEAM,
    MOVE_POISON_POWDER,
    MOVE_STUN_SPORE,
    MOVE_SLEEP_POWDER,
    MOVE_PETAL_DANCE,
    MOVE_STRING_SHOT,
    MOVE_DRAGON_RAGE,
    MOVE_FIRE_SPIN,
    MOVE_THUNDER_SHOCK,
    MOVE_THUNDERBOLT,
    MOVE_THUNDER_WAVE,
    MOVE_THUNDER,
    MOVE_ROCK_THROW,
    MOVE_EARTHQUAKE,
    MOVE_FISSURE,
    MOVE_DIG,
    MOVE_TOXIC,
    MOVE_CONFUSION,
    MOVE_PSYCHIC,
    MOVE_HYPNOSIS,
    MOVE_MEDITATE,
    MOVE_AGILITY,
    MOVE_QUICK_ATTACK,
    MOVE_RAGE,
    MOVE_TELEPORT,
    MOVE_NIGHT_SHADE,
    MOVE_MIMIC,
    MOVE_SCREECH,
    MOVE_DOUBLE_TEAM,
    MOVE_RECOVER,
    MOVE_HARDEN,
    MOVE_MINIMIZE,
    MOVE_SMOKESCREEN,
    MOVE_CONFUSE_RAY,
    MOVE_WITHDRAW,
    MOVE_DEFENSE_CURL,
    MOVE_BARRIER,
    MOVE_LIGHT_SCREEN,
    MOVE_HAZE,
    MOVE_REFLECT,
    MOVE_FOCUS_ENERGY,
    MOVE_BIDE,
    MOVE_METRONOME,
    MOVE_MIRROR_MOVE,
    MOVE_SELF_DESTRUCT,
    MOVE_EGG_BOMB,
    MOVE_LICK,
    MOVE_SMOG,
    MOVE_SLUDGE,
    MOVE_BONE_CLUB,
    MOVE_FIRE_BLAST,
    MOVE_WATERFALL,
    MOVE_CLAMP,
    MOVE_SWIFT,
    MOVE_SKULL_BASH,
    MOVE_SPIKE_CANNON,
    MOVE_CONSTRICT,
    MOVE_AMNESIA,
    MOVE_KINESIS,
    MOVE_SOFT_BOILED,
    MOVE_HIGH_JUMP_KICK,
    MOVE_GLARE,
    MOVE_DREAM_EATER,
    MOVE_POISON_GAS,
    MOVE_BARRAGE,
    MOVE_LEECH_LIFE,
    MOVE_LOVELY_KISS,
    MOVE_SKY_ATTACK,
    MOVE_TRANSFORM,
    MOVE_BUBBLE,
    MOVE_DIZZY_PUNCH,
    MOVE_SPORE,
    MOVE_FLASH,
    MOVE_PSYWAVE,
    MOVE_SPLASH,
    MOVE_ACID_ARMOR,
    MOVE_CRABHAMMER,
    MOVE_EXPLOSION,
    MOVE_FURY_SWIPES,
    MOVE_BONEMERANG,
    MOVE_REST,
    MOVE_ROCK_SLIDE,
    MOVE_HYPER_FANG,
    MOVE_SHARPEN,
    MOVE_CONVERSION,
    MOVE_TRI_ATTACK,
    MOVE_SUPER_FANG,
    MOVE_SLASH,
    MOVE_SUBSTITUTE,
    //MOVE_SKETCH,
    MOVE_TRIPLE_KICK,
    MOVE_THIEF,
    MOVE_SPIDER_WEB,
    MOVE_MIND_READER,
    MOVE_NIGHTMARE,
    MOVE_FLAME_WHEEL,
    MOVE_SNORE,
    MOVE_CURSE,
    MOVE_FLAIL,
    MOVE_CONVERSION_2,
    MOVE_AEROBLAST,
    MOVE_COTTON_SPORE,
    MOVE_REVERSAL,
    MOVE_SPITE,
    MOVE_POWDER_SNOW,
    MOVE_PROTECT,
    MOVE_MACH_PUNCH,
    MOVE_SCARY_FACE,
    MOVE_FEINT_ATTACK,
    MOVE_SWEET_KISS,
    MOVE_BELLY_DRUM,
    MOVE_SLUDGE_BOMB,
    MOVE_MUD_SLAP,
    MOVE_OCTAZOOKA,
    MOVE_SPIKES,
    MOVE_ZAP_CANNON,
    MOVE_FORESIGHT,
    MOVE_DESTINY_BOND,
    MOVE_PERISH_SONG,
    MOVE_ICY_WIND,
    MOVE_DETECT,
    MOVE_BONE_RUSH,
    MOVE_LOCK_ON,
    MOVE_OUTRAGE,
    MOVE_SANDSTORM,
    MOVE_GIGA_DRAIN,
    MOVE_ENDURE,
    MOVE_CHARM,
    MOVE_ROLLOUT,
    MOVE_FALSE_SWIPE,
    MOVE_SWAGGER,
    MOVE_MILK_DRINK,
    MOVE_SPARK,
    MOVE_FURY_CUTTER,
    MOVE_STEEL_WING,
    MOVE_MEAN_LOOK,
    MOVE_ATTRACT,
    MOVE_SLEEP_TALK,
    MOVE_HEAL_BELL,
    MOVE_RETURN,
    MOVE_PRESENT,
    MOVE_FRUSTRATION,
    MOVE_SAFEGUARD,
    MOVE_PAIN_SPLIT,
    MOVE_SACRED_FIRE,
    MOVE_MAGNITUDE,
    MOVE_DYNAMIC_PUNCH,
    MOVE_MEGAHORN,
    MOVE_DRAGON_BREATH,
    MOVE_BATON_PASS,
    MOVE_ENCORE,
    MOVE_PURSUIT,
    MOVE_RAPID_SPIN,
    MOVE_SWEET_SCENT,
    MOVE_IRON_TAIL,
    MOVE_METAL_CLAW,
    MOVE_VITAL_THROW,
    MOVE_MORNING_SUN,
    MOVE_SYNTHESIS,
    MOVE_MOONLIGHT,
    MOVE_HIDDEN_POWER,
    MOVE_CROSS_CHOP,
    MOVE_TWISTER,
    MOVE_RAIN_DANCE,
    MOVE_SUNNY_DAY,
    MOVE_CRUNCH,
    MOVE_MIRROR_COAT,
    MOVE_PSYCH_UP,
    MOVE_EXTREME_SPEED,
    MOVE_ANCIENT_POWER,
    MOVE_SHADOW_BALL,
    //MOVE_FUTURE_SIGHT, REMOVED UNTIL NOT BUGGY
    MOVE_ROCK_SMASH,
    MOVE_WHIRLPOOL,
    MOVE_BEAT_UP,
    MOVE_FAKE_OUT,
    MOVE_UPROAR,
    MOVE_STOCKPILE,
    MOVE_SPIT_UP,
    MOVE_SWALLOW,
    MOVE_HEAT_WAVE,
    MOVE_HAIL,
    MOVE_TORMENT,
    MOVE_FLATTER,
    MOVE_WILL_O_WISP,
    MOVE_MEMENTO,
    MOVE_FACADE,
    MOVE_FOCUS_PUNCH,
    MOVE_SMELLING_SALTS,
    MOVE_FOLLOW_ME,
    MOVE_NATURE_POWER,
    MOVE_CHARGE,
    MOVE_TAUNT,
    MOVE_HELPING_HAND,
    MOVE_TRICK,
    MOVE_ROLE_PLAY,
    MOVE_WISH,
    MOVE_ASSIST,
    MOVE_INGRAIN,
    MOVE_SUPERPOWER,
    MOVE_MAGIC_COAT,
    MOVE_RECYCLE,
    MOVE_REVENGE,
    MOVE_BRICK_BREAK,
    MOVE_YAWN,
    MOVE_KNOCK_OFF,
    MOVE_ENDEAVOR,
    MOVE_ERUPTION,
    MOVE_SKILL_SWAP,
    MOVE_IMPRISON,
    MOVE_REFRESH,
    MOVE_GRUDGE,
    MOVE_SNATCH,
    MOVE_SECRET_POWER,
    MOVE_DIVE,
    MOVE_ARM_THRUST,
    MOVE_CAMOUFLAGE,
    MOVE_TAIL_GLOW,
    MOVE_LUSTER_PURGE,
    MOVE_MIST_BALL,
    MOVE_FEATHER_DANCE,
    MOVE_TEETER_DANCE,
    MOVE_BLAZE_KICK,
    MOVE_MUD_SPORT,
    MOVE_ICE_BALL,
    MOVE_NEEDLE_ARM,
    MOVE_SLACK_OFF,
    MOVE_HYPER_VOICE,
    MOVE_POISON_FANG,
    MOVE_CRUSH_CLAW,
    MOVE_BLAST_BURN,
    MOVE_HYDRO_CANNON,
    MOVE_METEOR_MASH,
    MOVE_ASTONISH,
    MOVE_WEATHER_BALL,
    MOVE_AROMATHERAPY,
    MOVE_FAKE_TEARS,
    MOVE_AIR_CUTTER,
    MOVE_OVERHEAT,
    MOVE_ODOR_SLEUTH,
    MOVE_ROCK_TOMB,
    MOVE_SILVER_WIND,
    MOVE_METAL_SOUND,
    MOVE_GRASS_WHISTLE,
    MOVE_TICKLE,
    MOVE_COSMIC_POWER,
    MOVE_WATER_SPOUT,
    MOVE_SIGNAL_BEAM,
    MOVE_SHADOW_PUNCH,
    MOVE_EXTRASENSORY,
    MOVE_SKY_UPPERCUT,
    MOVE_SAND_TOMB,
    MOVE_SHEER_COLD,
    MOVE_MUDDY_WATER,
    MOVE_BULLET_SEED,
    MOVE_AERIAL_ACE,
    MOVE_ICICLE_SPEAR,
    MOVE_IRON_DEFENSE,
    MOVE_BLOCK,
    MOVE_HOWL,
    MOVE_DRAGON_CLAW,
    MOVE_FRENZY_PLANT,
    MOVE_BULK_UP,
    MOVE_BOUNCE,
    MOVE_MUD_SHOT,
    MOVE_POISON_TAIL,
    MOVE_COVET,
    MOVE_VOLT_TACKLE,
    MOVE_MAGICAL_LEAF,
    MOVE_WATER_SPORT,
    MOVE_CALM_MIND,
    MOVE_LEAF_BLADE,
    MOVE_DRAGON_DANCE,
    MOVE_ROCK_BLAST,
    MOVE_SHOCK_WAVE,
    MOVE_WATER_PULSE,
    MOVE_DOOM_DESIRE,
    MOVE_PSYCHO_BOOST,
#ifndef PIT_GEN_3_MODE
    // Gen 4 moves
    MOVE_ROOST,
    MOVE_GRAVITY,
    MOVE_MIRACLE_EYE,
    MOVE_WAKE_UP_SLAP,
    MOVE_HAMMER_ARM,
    MOVE_GYRO_BALL,
    MOVE_HEALING_WISH,
    MOVE_BRINE,
    MOVE_NATURAL_GIFT,
    MOVE_FEINT,
    MOVE_PLUCK,
    MOVE_TAILWIND,
    MOVE_ACUPRESSURE,
    MOVE_METAL_BURST,
    MOVE_U_TURN,
    MOVE_CLOSE_COMBAT,
    MOVE_PAYBACK,
    MOVE_ASSURANCE,
    MOVE_EMBARGO,
    MOVE_FLING,
    MOVE_PSYCHO_SHIFT,
    MOVE_TRUMP_CARD,
    MOVE_HEAL_BLOCK,
    MOVE_WRING_OUT,
    MOVE_POWER_TRICK,
    MOVE_GASTRO_ACID,
    MOVE_LUCKY_CHANT,
    MOVE_ME_FIRST,
    MOVE_COPYCAT,
    MOVE_POWER_SWAP,
    MOVE_GUARD_SWAP,
    MOVE_PUNISHMENT,
    MOVE_LAST_RESORT,
    MOVE_WORRY_SEED,
    MOVE_SUCKER_PUNCH,
    MOVE_TOXIC_SPIKES,
    MOVE_HEART_SWAP,
    MOVE_AQUA_RING,
    MOVE_MAGNET_RISE,
    MOVE_FLARE_BLITZ,
    MOVE_FORCE_PALM,
    MOVE_AURA_SPHERE,
    MOVE_ROCK_POLISH,
    MOVE_POISON_JAB,
    MOVE_DARK_PULSE,
    MOVE_NIGHT_SLASH,
    MOVE_AQUA_TAIL,
    MOVE_SEED_BOMB,
    MOVE_AIR_SLASH,
    MOVE_X_SCISSOR,
    MOVE_BUG_BUZZ,
    MOVE_DRAGON_PULSE,
    MOVE_DRAGON_RUSH,
    MOVE_POWER_GEM,
    MOVE_DRAIN_PUNCH,
    MOVE_VACUUM_WAVE,
    MOVE_FOCUS_BLAST,
    MOVE_ENERGY_BALL,
    MOVE_BRAVE_BIRD,
    MOVE_EARTH_POWER,
    MOVE_SWITCHEROO,
    MOVE_GIGA_IMPACT,
    MOVE_NASTY_PLOT,
    MOVE_BULLET_PUNCH,
    MOVE_AVALANCHE,
    MOVE_ICE_SHARD,
    MOVE_SHADOW_CLAW,
    MOVE_THUNDER_FANG,
    MOVE_ICE_FANG,
    MOVE_FIRE_FANG,
    MOVE_SHADOW_SNEAK,
    MOVE_MUD_BOMB,
    MOVE_PSYCHO_CUT,
    MOVE_ZEN_HEADBUTT,
    MOVE_MIRROR_SHOT,
    MOVE_FLASH_CANNON,
    MOVE_ROCK_CLIMB,
    MOVE_DEFOG,
    MOVE_TRICK_ROOM,
    MOVE_DRACO_METEOR,
    MOVE_DISCHARGE,
    MOVE_LAVA_PLUME,
    MOVE_LEAF_STORM,
    MOVE_POWER_WHIP,
    MOVE_ROCK_WRECKER,
    MOVE_CROSS_POISON,
    MOVE_GUNK_SHOT,
    MOVE_IRON_HEAD,
    MOVE_MAGNET_BOMB,
    MOVE_STONE_EDGE,
    MOVE_CAPTIVATE,
    MOVE_STEALTH_ROCK,
    MOVE_GRASS_KNOT,
    MOVE_CHATTER,
    MOVE_JUDGMENT,
    MOVE_BUG_BITE,
    MOVE_CHARGE_BEAM,
    MOVE_WOOD_HAMMER,
    MOVE_AQUA_JET,
    MOVE_ATTACK_ORDER,
    MOVE_DEFEND_ORDER,
    MOVE_HEAL_ORDER,
    MOVE_HEAD_SMASH,
    MOVE_DOUBLE_HIT,
    MOVE_ROAR_OF_TIME,
    MOVE_SPACIAL_REND,
    MOVE_LUNAR_DANCE,
    MOVE_CRUSH_GRIP,
    MOVE_MAGMA_STORM,
    MOVE_SEED_FLARE,
    MOVE_OMINOUS_WIND,
    MOVE_SHADOW_FORCE,
    // Gen 5 moves
    MOVE_HONE_CLAWS,
    MOVE_WIDE_GUARD,
    MOVE_GUARD_SPLIT,
    MOVE_POWER_SPLIT,
    MOVE_WONDER_ROOM,
    MOVE_PSYSHOCK,
    MOVE_VENOSHOCK,
    MOVE_AUTOTOMIZE,
    MOVE_RAGE_POWDER,
    MOVE_TELEKINESIS,
    MOVE_MAGIC_ROOM,
    MOVE_SMACK_DOWN,
    MOVE_STORM_THROW,
    MOVE_FLAME_BURST,
    MOVE_SLUDGE_WAVE,
    MOVE_QUIVER_DANCE,
    MOVE_HEAVY_SLAM,
    MOVE_SYNCHRONOISE,
    MOVE_ELECTRO_BALL,
    MOVE_SOAK,
    MOVE_FLAME_CHARGE,
    MOVE_COIL,
    MOVE_LOW_SWEEP,
    MOVE_ACID_SPRAY,
    MOVE_FOUL_PLAY,
    MOVE_SIMPLE_BEAM,
    MOVE_ENTRAINMENT,
    MOVE_AFTER_YOU,
    MOVE_ROUND,
    MOVE_ECHOED_VOICE,
    MOVE_CHIP_AWAY,
    MOVE_CLEAR_SMOG,
    MOVE_STORED_POWER,
    MOVE_QUICK_GUARD,
    MOVE_ALLY_SWITCH,
    MOVE_SCALD,
    MOVE_SHELL_SMASH,
    MOVE_HEAL_PULSE,
    MOVE_HEX,
    MOVE_SKY_DROP,
    MOVE_SHIFT_GEAR,
    MOVE_CIRCLE_THROW,
    MOVE_INCINERATE,
    MOVE_QUASH,
    MOVE_ACROBATICS,
    MOVE_REFLECT_TYPE,
    MOVE_RETALIATE,
    MOVE_FINAL_GAMBIT,
    MOVE_BESTOW,
    MOVE_INFERNO,
    MOVE_WATER_PLEDGE,
    MOVE_FIRE_PLEDGE,
    MOVE_GRASS_PLEDGE,
    MOVE_VOLT_SWITCH,
    MOVE_STRUGGLE_BUG,
    MOVE_BULLDOZE,
    MOVE_FROST_BREATH,
    MOVE_DRAGON_TAIL,
    MOVE_WORK_UP,
    MOVE_ELECTROWEB,
    MOVE_WILD_CHARGE,
    MOVE_DRILL_RUN,
    MOVE_DUAL_CHOP,
    MOVE_HEART_STAMP,
    MOVE_HORN_LEECH,
    MOVE_SACRED_SWORD,
    MOVE_RAZOR_SHELL,
    MOVE_HEAT_CRASH,
    MOVE_LEAF_TORNADO,
    MOVE_STEAMROLLER,
    MOVE_COTTON_GUARD,
    MOVE_NIGHT_DAZE,
    MOVE_PSYSTRIKE,
    MOVE_TAIL_SLAP,
    MOVE_HURRICANE,
    MOVE_HEAD_CHARGE,
    MOVE_GEAR_GRIND,
    MOVE_SEARING_SHOT,
    MOVE_TECHNO_BLAST,
    MOVE_RELIC_SONG,
    MOVE_SECRET_SWORD,
    MOVE_GLACIATE,
    MOVE_BOLT_STRIKE,
    MOVE_BLUE_FLARE,
    MOVE_FIERY_DANCE,
    MOVE_FREEZE_SHOCK,
    MOVE_ICE_BURN,
    MOVE_SNARL,
    MOVE_ICICLE_CRASH,
    MOVE_V_CREATE,
    MOVE_FUSION_FLARE,
    MOVE_FUSION_BOLT,
#endif
#ifdef PIT_GEN_9_MODE
    // Gen 6 moves
    MOVE_FLYING_PRESS,
    MOVE_MAT_BLOCK,
    MOVE_BELCH,
    MOVE_ROTOTILLER,
    MOVE_STICKY_WEB,
    MOVE_FELL_STINGER,
    MOVE_PHANTOM_FORCE,
    MOVE_TRICK_OR_TREAT,
    MOVE_NOBLE_ROAR,
    MOVE_ION_DELUGE,
    MOVE_PARABOLIC_CHARGE,
    MOVE_FORESTS_CURSE,
    MOVE_PETAL_BLIZZARD,
    MOVE_FREEZE_DRY,
    MOVE_DISARMING_VOICE,
    MOVE_PARTING_SHOT,
    MOVE_TOPSY_TURVY,
    MOVE_DRAINING_KISS,
    MOVE_CRAFTY_SHIELD,
    MOVE_FLOWER_SHIELD,
    MOVE_GRASSY_TERRAIN,
    MOVE_MISTY_TERRAIN,
    MOVE_ELECTRIFY,
    MOVE_PLAY_ROUGH,
    MOVE_FAIRY_WIND,
    MOVE_MOONBLAST,
    MOVE_BOOMBURST,
    MOVE_FAIRY_LOCK,
    MOVE_KINGS_SHIELD,
    MOVE_PLAY_NICE,
    MOVE_CONFIDE,
    MOVE_DIAMOND_STORM,
    MOVE_STEAM_ERUPTION,
    MOVE_WATER_SHURIKEN,
    MOVE_MYSTICAL_FIRE,
    MOVE_SPIKY_SHIELD,
    MOVE_AROMATIC_MIST,
    MOVE_EERIE_IMPULSE,
    MOVE_VENOM_DRENCH,
    MOVE_POWDER,
    MOVE_GEOMANCY,
    MOVE_MAGNETIC_FLUX,
    MOVE_HAPPY_HOUR,
    MOVE_ELECTRIC_TERRAIN,
    MOVE_DAZZLING_GLEAM,
    MOVE_CELEBRATE,
    MOVE_HOLD_HANDS,
    MOVE_BABY_DOLL_EYES,
    MOVE_NUZZLE,
    MOVE_HOLD_BACK,
    MOVE_INFESTATION,
    MOVE_POWER_UP_PUNCH,
    MOVE_OBLIVION_WING,
    MOVE_THOUSAND_ARROWS,
    MOVE_THOUSAND_WAVES,
    MOVE_LANDS_WRATH,
    MOVE_LIGHT_OF_RUIN,
    // ORAS Moves
    MOVE_ORIGIN_PULSE,
    MOVE_PRECIPICE_BLADES,
    MOVE_DRAGON_ASCENT,
    //MOVE_HYPERSPACE_FURY,
    // Gen 7 moves
    MOVE_SHORE_UP,
    MOVE_FIRST_IMPRESSION,
    MOVE_BANEFUL_BUNKER,
    MOVE_SPIRIT_SHACKLE,
    MOVE_DARKEST_LARIAT,
    MOVE_SPARKLING_ARIA,
    MOVE_ICE_HAMMER,
    MOVE_FLORAL_HEALING,
    MOVE_HIGH_HORSEPOWER,
    MOVE_STRENGTH_SAP,
    MOVE_SOLAR_BLADE,
    MOVE_LEAFAGE,
    MOVE_SPOTLIGHT,
    MOVE_TOXIC_THREAD,
    MOVE_LASER_FOCUS,
    MOVE_GEAR_UP,
    MOVE_THROAT_CHOP,
    MOVE_POLLEN_PUFF,
    MOVE_ANCHOR_SHOT,
    MOVE_PSYCHIC_TERRAIN,
    MOVE_LUNGE,
    MOVE_FIRE_LASH,
    MOVE_POWER_TRIP,
    MOVE_BURN_UP,
    MOVE_SPEED_SWAP,
    MOVE_SMART_STRIKE,
    MOVE_PURIFY,
    MOVE_REVELATION_DANCE,
    MOVE_CORE_ENFORCER,
    MOVE_TROP_KICK,
    MOVE_INSTRUCT,
    MOVE_BEAK_BLAST,
    MOVE_CLANGING_SCALES,
    MOVE_DRAGON_HAMMER,
    MOVE_BRUTAL_SWING,
    MOVE_AURORA_VEIL,
    MOVE_SHELL_TRAP,
    MOVE_FLEUR_CANNON,
    MOVE_PSYCHIC_FANGS,
    MOVE_STOMPING_TANTRUM,
    MOVE_SHADOW_BONE,
    MOVE_ACCELEROCK,
    MOVE_LIQUIDATION,
    MOVE_PRISMATIC_LASER,
    MOVE_SPECTRAL_THIEF,
    MOVE_SUNSTEEL_STRIKE,
    MOVE_MOONGEIST_BEAM,
    MOVE_TEARFUL_LOOK,
    MOVE_ZING_ZAP,
    MOVE_NATURES_MADNESS,
    MOVE_MULTI_ATTACK,
    // USUM Moves
    MOVE_MIND_BLOWN,
    MOVE_PLASMA_FISTS,
    MOVE_PHOTON_GEYSER,
    // Gen 8 moves
    MOVE_DYNAMAX_CANNON,
    MOVE_SNIPE_SHOT,
    MOVE_JAW_LOCK,
    MOVE_STUFF_CHEEKS,
    MOVE_NO_RETREAT,
    MOVE_TAR_SHOT,
    MOVE_MAGIC_POWDER,
    MOVE_DRAGON_DARTS,
    MOVE_TEATIME,
    MOVE_OCTOLOCK,
    MOVE_BOLT_BEAK,
    MOVE_FISHIOUS_REND,
    MOVE_COURT_CHANGE,
    MOVE_CLANGOROUS_SOUL,
    MOVE_BODY_PRESS,
    MOVE_DECORATE,
    MOVE_DRUM_BEATING,
    MOVE_SNAP_TRAP,
    MOVE_PYRO_BALL,
    MOVE_BEHEMOTH_BLADE,
    MOVE_BEHEMOTH_BASH,
    MOVE_BREAKING_SWIPE,
    MOVE_BRANCH_POKE,
    MOVE_OVERDRIVE,
    MOVE_APPLE_ACID,
    MOVE_GRAV_APPLE,
    MOVE_SPIRIT_BREAK,
    MOVE_STRANGE_STEAM,
    MOVE_LIFE_DEW,
    MOVE_OBSTRUCT,
    MOVE_FALSE_SURRENDER,
    MOVE_METEOR_ASSAULT,
    MOVE_ETERNABEAM,
    MOVE_STEEL_BEAM,
    // Isle of Armor Moves
    MOVE_EXPANDING_FORCE,
    MOVE_STEEL_ROLLER,
    MOVE_SCALE_SHOT,
    MOVE_METEOR_BEAM,
    MOVE_SHELL_SIDE_ARM,
    MOVE_MISTY_EXPLOSION,
    MOVE_GRASSY_GLIDE,
    MOVE_RISING_VOLTAGE,
    MOVE_TERRAIN_PULSE,
    MOVE_SKITTER_SMACK,
    MOVE_BURNING_JEALOUSY,
    MOVE_LASH_OUT,
    MOVE_POLTERGEIST,
    MOVE_CORROSIVE_GAS,
    MOVE_COACHING,
    MOVE_FLIP_TURN,
    MOVE_TRIPLE_AXEL,
    MOVE_DUAL_WINGBEAT,
    MOVE_SCORCHING_SANDS,
    MOVE_JUNGLE_HEALING,
    MOVE_WICKED_BLOW,
    MOVE_SURGING_STRIKES,
    // Crown Tundra Moves
    MOVE_THUNDER_CAGE,
    MOVE_DRAGON_ENERGY,
    MOVE_FREEZING_GLARE,
    MOVE_FIERY_WRATH,
    MOVE_THUNDEROUS_KICK,
    MOVE_GLACIAL_LANCE,
    MOVE_ASTRAL_BARRAGE,
    MOVE_EERIE_SPELL,
    #endif
};
//**********************

#define INVALID_ABILITIES_COUNT ARRAY_COUNT(sInvalidRandomAbilities)
static const u16 sInvalidRandomAbilities[] =
{
    ABILITY_MULTITYPE,
    ABILITY_STANCE_CHANGE,
    ABILITY_SCHOOLING,
    ABILITY_COMATOSE,
    ABILITY_SHIELDS_DOWN,
    ABILITY_DISGUISE,
    ABILITY_RKS_SYSTEM,
    ABILITY_BATTLE_BOND,
    ABILITY_POWER_CONSTRUCT,
    ABILITY_ICE_FACE,
    ABILITY_GULP_MISSILE,
    ABILITY_ZERO_TO_HERO,
    ABILITY_COMMANDER,
    ABILITY_ZEN_MODE,
    ABILITY_FORECAST,
    ABILITY_FLOWER_GIFT,
    ABILITY_AS_ONE_ICE_RIDER,
    ABILITY_AS_ONE_SHADOW_RIDER,
    ABILITY_NEUTRALIZING_GAS,
};


struct SpeciesItem
{
    u16 species;
    u16 item;
};

static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon);
static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType);
static void EncryptBoxMon(struct BoxPokemon *boxMon);
static void DecryptBoxMon(struct BoxPokemon *boxMon);
static void Task_PlayMapChosenOrBattleBGM(u8 taskId);
static bool8 ShouldSkipFriendshipChange(void);
static void RemoveIVIndexFromList(u8 *ivs, u8 selectedIv);
static u16 GetPreEvolution(u16 species);
void TrySpecialOverworldEvo();
void TryLevelUpOverworldEvo();

EWRAM_DATA static u8 sLearningMoveTableID = 0;
EWRAM_DATA u8 gPlayerPartyCount = 0;
EWRAM_DATA u8 gEnemyPartyCount = 0;
EWRAM_DATA struct Pokemon gPlayerParty[PARTY_SIZE] = {0};
EWRAM_DATA struct Pokemon gEnemyParty[PARTY_SIZE] = {0};
EWRAM_DATA struct SpriteTemplate gMultiuseSpriteTemplate = {0};
EWRAM_DATA static struct MonSpritesGfxManager *sMonSpritesGfxManagers[MON_SPR_GFX_MANAGERS_COUNT] = {NULL};
EWRAM_DATA static u8 sTriedEvolving = 0;
EWRAM_DATA u16 gFollowerSteps = 0;

#include "data/moves_info.h"
#include "data/abilities.h"

// Used in an unreferenced function in RS.
// Unreferenced here and in FRLG.
struct CombinedMove
{
    u16 move1;
    u16 move2;
    u16 newMove;
};

static const struct CombinedMove sCombinedMoves[2] =
{
    {MOVE_EMBER, MOVE_GUST, MOVE_HEAT_WAVE},
    {0xFFFF, 0xFFFF, 0xFFFF}
};

// NOTE: The order of the elements in the array below is irrelevant.
// To reorder the pokedex, see the values in include/constants/pokedex.h.

#define HOENN_TO_NATIONAL(name)     [HOENN_DEX_##name - 1] = NATIONAL_DEX_##name

// Assigns all Hoenn Dex Indexes to a National Dex Index
static const u16 sHoennToNationalOrder[HOENN_DEX_COUNT - 1] =
{
    HOENN_TO_NATIONAL(TREECKO),
    HOENN_TO_NATIONAL(GROVYLE),
    HOENN_TO_NATIONAL(SCEPTILE),
    HOENN_TO_NATIONAL(TORCHIC),
    HOENN_TO_NATIONAL(COMBUSKEN),
    HOENN_TO_NATIONAL(BLAZIKEN),
    HOENN_TO_NATIONAL(MUDKIP),
    HOENN_TO_NATIONAL(MARSHTOMP),
    HOENN_TO_NATIONAL(SWAMPERT),
    HOENN_TO_NATIONAL(POOCHYENA),
    HOENN_TO_NATIONAL(MIGHTYENA),
    HOENN_TO_NATIONAL(ZIGZAGOON),
    HOENN_TO_NATIONAL(LINOONE),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GALARIAN_FORMS
    HOENN_TO_NATIONAL(OBSTAGOON),
#endif
    HOENN_TO_NATIONAL(WURMPLE),
    HOENN_TO_NATIONAL(SILCOON),
    HOENN_TO_NATIONAL(BEAUTIFLY),
    HOENN_TO_NATIONAL(CASCOON),
    HOENN_TO_NATIONAL(DUSTOX),
    HOENN_TO_NATIONAL(LOTAD),
    HOENN_TO_NATIONAL(LOMBRE),
    HOENN_TO_NATIONAL(LUDICOLO),
    HOENN_TO_NATIONAL(SEEDOT),
    HOENN_TO_NATIONAL(NUZLEAF),
    HOENN_TO_NATIONAL(SHIFTRY),
    HOENN_TO_NATIONAL(TAILLOW),
    HOENN_TO_NATIONAL(SWELLOW),
    HOENN_TO_NATIONAL(WINGULL),
    HOENN_TO_NATIONAL(PELIPPER),
    HOENN_TO_NATIONAL(RALTS),
    HOENN_TO_NATIONAL(KIRLIA),
    HOENN_TO_NATIONAL(GARDEVOIR),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_4_CROSS_EVOS
    HOENN_TO_NATIONAL(GALLADE),
#endif
    HOENN_TO_NATIONAL(SURSKIT),
    HOENN_TO_NATIONAL(MASQUERAIN),
    HOENN_TO_NATIONAL(SHROOMISH),
    HOENN_TO_NATIONAL(BRELOOM),
    HOENN_TO_NATIONAL(SLAKOTH),
    HOENN_TO_NATIONAL(VIGOROTH),
    HOENN_TO_NATIONAL(SLAKING),
    HOENN_TO_NATIONAL(ABRA),
    HOENN_TO_NATIONAL(KADABRA),
    HOENN_TO_NATIONAL(ALAKAZAM),
    HOENN_TO_NATIONAL(NINCADA),
    HOENN_TO_NATIONAL(NINJASK),
    HOENN_TO_NATIONAL(SHEDINJA),
    HOENN_TO_NATIONAL(WHISMUR),
    HOENN_TO_NATIONAL(LOUDRED),
    HOENN_TO_NATIONAL(EXPLOUD),
    HOENN_TO_NATIONAL(MAKUHITA),
    HOENN_TO_NATIONAL(HARIYAMA),
    HOENN_TO_NATIONAL(GOLDEEN),
    HOENN_TO_NATIONAL(SEAKING),
    HOENN_TO_NATIONAL(MAGIKARP),
    HOENN_TO_NATIONAL(GYARADOS),
    HOENN_TO_NATIONAL(AZURILL),
    HOENN_TO_NATIONAL(MARILL),
    HOENN_TO_NATIONAL(AZUMARILL),
    HOENN_TO_NATIONAL(GEODUDE),
    HOENN_TO_NATIONAL(GRAVELER),
    HOENN_TO_NATIONAL(GOLEM),
    HOENN_TO_NATIONAL(NOSEPASS),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_4_CROSS_EVOS
    HOENN_TO_NATIONAL(PROBOPASS),
#endif
    HOENN_TO_NATIONAL(SKITTY),
    HOENN_TO_NATIONAL(DELCATTY),
    HOENN_TO_NATIONAL(ZUBAT),
    HOENN_TO_NATIONAL(GOLBAT),
    HOENN_TO_NATIONAL(CROBAT),
    HOENN_TO_NATIONAL(TENTACOOL),
    HOENN_TO_NATIONAL(TENTACRUEL),
    HOENN_TO_NATIONAL(SABLEYE),
    HOENN_TO_NATIONAL(MAWILE),
    HOENN_TO_NATIONAL(ARON),
    HOENN_TO_NATIONAL(LAIRON),
    HOENN_TO_NATIONAL(AGGRON),
    HOENN_TO_NATIONAL(MACHOP),
    HOENN_TO_NATIONAL(MACHOKE),
    HOENN_TO_NATIONAL(MACHAMP),
    HOENN_TO_NATIONAL(MEDITITE),
    HOENN_TO_NATIONAL(MEDICHAM),
    HOENN_TO_NATIONAL(ELECTRIKE),
    HOENN_TO_NATIONAL(MANECTRIC),
    HOENN_TO_NATIONAL(PLUSLE),
    HOENN_TO_NATIONAL(MINUN),
    HOENN_TO_NATIONAL(MAGNEMITE),
    HOENN_TO_NATIONAL(MAGNETON),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_4_CROSS_EVOS
    HOENN_TO_NATIONAL(MAGNEZONE),
#endif
    HOENN_TO_NATIONAL(VOLTORB),
    HOENN_TO_NATIONAL(ELECTRODE),
    HOENN_TO_NATIONAL(VOLBEAT),
    HOENN_TO_NATIONAL(ILLUMISE),
    HOENN_TO_NATIONAL(ODDISH),
    HOENN_TO_NATIONAL(GLOOM),
    HOENN_TO_NATIONAL(VILEPLUME),
    HOENN_TO_NATIONAL(BELLOSSOM),
    HOENN_TO_NATIONAL(DODUO),
    HOENN_TO_NATIONAL(DODRIO),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_4_CROSS_EVOS
    HOENN_TO_NATIONAL(BUDEW),
    HOENN_TO_NATIONAL(ROSELIA),
    HOENN_TO_NATIONAL(ROSERADE),
#else
    HOENN_TO_NATIONAL(ROSELIA),
#endif
    HOENN_TO_NATIONAL(GULPIN),
    HOENN_TO_NATIONAL(SWALOT),
    HOENN_TO_NATIONAL(CARVANHA),
    HOENN_TO_NATIONAL(SHARPEDO),
    HOENN_TO_NATIONAL(WAILMER),
    HOENN_TO_NATIONAL(WAILORD),
    HOENN_TO_NATIONAL(NUMEL),
    HOENN_TO_NATIONAL(CAMERUPT),
    HOENN_TO_NATIONAL(SLUGMA),
    HOENN_TO_NATIONAL(MAGCARGO),
    HOENN_TO_NATIONAL(TORKOAL),
    HOENN_TO_NATIONAL(GRIMER),
    HOENN_TO_NATIONAL(MUK),
    HOENN_TO_NATIONAL(KOFFING),
    HOENN_TO_NATIONAL(WEEZING),
    HOENN_TO_NATIONAL(SPOINK),
    HOENN_TO_NATIONAL(GRUMPIG),
    HOENN_TO_NATIONAL(SANDSHREW),
    HOENN_TO_NATIONAL(SANDSLASH),
    HOENN_TO_NATIONAL(SPINDA),
    HOENN_TO_NATIONAL(SKARMORY),
    HOENN_TO_NATIONAL(TRAPINCH),
    HOENN_TO_NATIONAL(VIBRAVA),
    HOENN_TO_NATIONAL(FLYGON),
    HOENN_TO_NATIONAL(CACNEA),
    HOENN_TO_NATIONAL(CACTURNE),
    HOENN_TO_NATIONAL(SWABLU),
    HOENN_TO_NATIONAL(ALTARIA),
    HOENN_TO_NATIONAL(ZANGOOSE),
    HOENN_TO_NATIONAL(SEVIPER),
    HOENN_TO_NATIONAL(LUNATONE),
    HOENN_TO_NATIONAL(SOLROCK),
    HOENN_TO_NATIONAL(BARBOACH),
    HOENN_TO_NATIONAL(WHISCASH),
    HOENN_TO_NATIONAL(CORPHISH),
    HOENN_TO_NATIONAL(CRAWDAUNT),
    HOENN_TO_NATIONAL(BALTOY),
    HOENN_TO_NATIONAL(CLAYDOL),
    HOENN_TO_NATIONAL(LILEEP),
    HOENN_TO_NATIONAL(CRADILY),
    HOENN_TO_NATIONAL(ANORITH),
    HOENN_TO_NATIONAL(ARMALDO),
    HOENN_TO_NATIONAL(IGGLYBUFF),
    HOENN_TO_NATIONAL(JIGGLYPUFF),
    HOENN_TO_NATIONAL(WIGGLYTUFF),
    HOENN_TO_NATIONAL(FEEBAS),
    HOENN_TO_NATIONAL(MILOTIC),
    HOENN_TO_NATIONAL(CASTFORM),
    HOENN_TO_NATIONAL(STARYU),
    HOENN_TO_NATIONAL(STARMIE),
    HOENN_TO_NATIONAL(KECLEON),
    HOENN_TO_NATIONAL(SHUPPET),
    HOENN_TO_NATIONAL(BANETTE),
    HOENN_TO_NATIONAL(DUSKULL),
    HOENN_TO_NATIONAL(DUSCLOPS),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_4_CROSS_EVOS
    HOENN_TO_NATIONAL(DUSKNOIR),
    HOENN_TO_NATIONAL(TROPIUS),
    HOENN_TO_NATIONAL(CHINGLING),
#else
    HOENN_TO_NATIONAL(TROPIUS),
#endif
    HOENN_TO_NATIONAL(CHIMECHO),
    HOENN_TO_NATIONAL(ABSOL),
    HOENN_TO_NATIONAL(VULPIX),
    HOENN_TO_NATIONAL(NINETALES),
    HOENN_TO_NATIONAL(PICHU),
    HOENN_TO_NATIONAL(PIKACHU),
    HOENN_TO_NATIONAL(RAICHU),
    HOENN_TO_NATIONAL(PSYDUCK),
    HOENN_TO_NATIONAL(GOLDUCK),
    HOENN_TO_NATIONAL(WYNAUT),
    HOENN_TO_NATIONAL(WOBBUFFET),
    HOENN_TO_NATIONAL(NATU),
    HOENN_TO_NATIONAL(XATU),
    HOENN_TO_NATIONAL(GIRAFARIG),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_9_CROSS_EVOS
    HOENN_TO_NATIONAL(FARIGIRAF),
#endif
    HOENN_TO_NATIONAL(PHANPY),
    HOENN_TO_NATIONAL(DONPHAN),
    HOENN_TO_NATIONAL(PINSIR),
    HOENN_TO_NATIONAL(HERACROSS),
    HOENN_TO_NATIONAL(RHYHORN),
    HOENN_TO_NATIONAL(RHYDON),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_4_CROSS_EVOS
    HOENN_TO_NATIONAL(RHYPERIOR),
#endif
    HOENN_TO_NATIONAL(SNORUNT),
    HOENN_TO_NATIONAL(GLALIE),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GEN_4_CROSS_EVOS
    HOENN_TO_NATIONAL(FROSLASS),
#endif
    HOENN_TO_NATIONAL(SPHEAL),
    HOENN_TO_NATIONAL(SEALEO),
    HOENN_TO_NATIONAL(WALREIN),
    HOENN_TO_NATIONAL(CLAMPERL),
    HOENN_TO_NATIONAL(HUNTAIL),
    HOENN_TO_NATIONAL(GOREBYSS),
    HOENN_TO_NATIONAL(RELICANTH),
    HOENN_TO_NATIONAL(CORSOLA),
#if P_NEW_EVOS_IN_REGIONAL_DEX && P_GALARIAN_FORMS
    HOENN_TO_NATIONAL(CURSOLA),
#endif
    HOENN_TO_NATIONAL(CHINCHOU),
    HOENN_TO_NATIONAL(LANTURN),
    HOENN_TO_NATIONAL(LUVDISC),
    HOENN_TO_NATIONAL(HORSEA),
    HOENN_TO_NATIONAL(SEADRA),
    HOENN_TO_NATIONAL(KINGDRA),
    HOENN_TO_NATIONAL(BAGON),
    HOENN_TO_NATIONAL(SHELGON),
    HOENN_TO_NATIONAL(SALAMENCE),
    HOENN_TO_NATIONAL(BELDUM),
    HOENN_TO_NATIONAL(METANG),
    HOENN_TO_NATIONAL(METAGROSS),
    HOENN_TO_NATIONAL(REGIROCK),
    HOENN_TO_NATIONAL(REGICE),
    HOENN_TO_NATIONAL(REGISTEEL),
    HOENN_TO_NATIONAL(LATIAS),
    HOENN_TO_NATIONAL(LATIOS),
    HOENN_TO_NATIONAL(KYOGRE),
    HOENN_TO_NATIONAL(GROUDON),
    HOENN_TO_NATIONAL(RAYQUAZA),
    HOENN_TO_NATIONAL(JIRACHI),
    HOENN_TO_NATIONAL(DEOXYS),
};

const struct SpindaSpot gSpindaSpotGraphics[] =
{
    {.x = 16, .y =  7, .image = INCBIN_U16("graphics/pokemon/spinda/spots/spot_0.1bpp")},
    {.x = 40, .y =  8, .image = INCBIN_U16("graphics/pokemon/spinda/spots/spot_1.1bpp")},
    {.x = 22, .y = 25, .image = INCBIN_U16("graphics/pokemon/spinda/spots/spot_2.1bpp")},
    {.x = 34, .y = 26, .image = INCBIN_U16("graphics/pokemon/spinda/spots/spot_3.1bpp")}
};

// In Battle Palace, moves are chosen based on the pokemons nature rather than by the player
// Moves are grouped into "Attack", "Defense", or "Support" (see PALACE_MOVE_GROUP_*)
// Each nature has a certain percent chance of selecting a move from a particular group
// and a separate percent chance for each group when at or below 50% HP
// The table below doesn't list percentages for Support because you can subtract the other two
// Support percentages are listed in comments off to the side instead
#define PALACE_STYLE(atk, def, atkLow, defLow) {atk, atk + def, atkLow, atkLow + defLow}

const struct NatureInfo gNaturesInfo[NUM_NATURES] =
{
    [NATURE_HARDY] =
    {
        .name = COMPOUND_STRING("Hardy"),
        .statUp = STAT_ATK,
        .statDown = STAT_ATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_HARDY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlHardy,
        .battlePalacePercents = PALACE_STYLE(61, 7, 61, 7), //32% support >= 50% HP, 32% support < 50% HP
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_LONELY] =
    {
        .name = COMPOUND_STRING("Lonely"),
        .statUp = STAT_ATK,
        .statDown = STAT_DEF,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_LONELY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlLonely,
        .battlePalacePercents = PALACE_STYLE(20, 25, 84, 8), //55%,  8%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_BRAVE] =
    {
        .name = COMPOUND_STRING("Brave"),
        .statUp = STAT_ATK,
        .statDown = STAT_SPEED,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_BRAVE, AFFINE_TURN_UP},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlBrave,
        .battlePalacePercents = PALACE_STYLE(70, 15, 32, 60), //15%, 8%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_ADAMANT] =
    {
        .name = COMPOUND_STRING("Adamant"),
        .statUp = STAT_ATK,
        .statDown = STAT_SPATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_ADAMANT, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlAdamant,
        .battlePalacePercents = PALACE_STYLE(38, 31, 70, 15), //31%, 15%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_NAUGHTY] =
    {
        .name = COMPOUND_STRING("Naughty"),
        .statUp = STAT_ATK,
        .statDown = STAT_SPDEF,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_NAUGHTY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlNaughty,
        .battlePalacePercents = PALACE_STYLE(20, 70, 70, 22), //10%, 8%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_BOLD] =
    {
        .name = COMPOUND_STRING("Bold"),
        .statUp = STAT_DEF,
        .statDown = STAT_ATK,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_BOLD, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlBold,
        .battlePalacePercents = PALACE_STYLE(30, 20, 32, 58), //50%, 10%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_DOCILE] =
    {
        .name = COMPOUND_STRING("Docile"),
        .statUp = STAT_DEF,
        .statDown = STAT_DEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_DOCILE, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_RANDOM,
    },
    [NATURE_RELAXED] =
    {
        .name = COMPOUND_STRING("Relaxed"),
        .statUp = STAT_DEF,
        .statDown = STAT_SPEED,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_RELAXED, AFFINE_TURN_UP_AND_DOWN},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlRelaxed,
        .battlePalacePercents = PALACE_STYLE(25, 15, 75, 15), //60%, 10%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_IMPISH] =
    {
        .name = COMPOUND_STRING("Impish"),
        .statUp = STAT_DEF,
        .statDown = STAT_SPATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_IMPISH, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlImpish,
        .battlePalacePercents = PALACE_STYLE(69, 6, 28, 55), //25%, 17%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_LAX] =
    {
        .name = COMPOUND_STRING("Lax"),
        .statUp = STAT_DEF,
        .statDown = STAT_SPDEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_LAX, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlLax,
        .battlePalacePercents = PALACE_STYLE(35, 10, 29, 6), //55%, 65%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_TIMID] =
    {
        .name = COMPOUND_STRING("Timid"),
        .statUp = STAT_SPEED,
        .statDown = STAT_ATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_TIMID, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlTimid,
        .battlePalacePercents = PALACE_STYLE(62, 10, 30, 20), //28%, 50%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_HASTY] =
    {
        .name = COMPOUND_STRING("Hasty"),
        .statUp = STAT_SPEED,
        .statDown = STAT_DEF,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_HASTY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlHasty,
        .battlePalacePercents = PALACE_STYLE(58, 37, 88, 6), //5%, 6%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_SERIOUS] =
    {
        .name = COMPOUND_STRING("Serious"),
        .statUp = STAT_SPEED,
        .statDown = STAT_SPEED,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_SERIOUS, AFFINE_TURN_DOWN},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSerious,
        .battlePalacePercents = PALACE_STYLE(34, 11, 29, 11), //55%, 60%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_JOLLY] =
    {
        .name = COMPOUND_STRING("Jolly"),
        .statUp = STAT_SPEED,
        .statDown = STAT_SPATK,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_JOLLY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlJolly,
        .battlePalacePercents = PALACE_STYLE(35, 5, 35, 60), //60%, 5%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_NAIVE] =
    {
        .name = COMPOUND_STRING("Naive"),
        .statUp = STAT_SPEED,
        .statDown = STAT_SPDEF,
        .backAnim = 0,
        .pokeBlockAnim = {ANIM_NAIVE, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_RANDOM,
    },
    [NATURE_MODEST] =
    {
        .name = COMPOUND_STRING("Modest"),
        .statUp = STAT_SPATK,
        .statDown = STAT_ATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_MODEST, AFFINE_TURN_DOWN_SLOW},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlModest,
        .battlePalacePercents = PALACE_STYLE(35, 45, 34, 60), //20%, 6%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_MILD] =
    {
        .name = COMPOUND_STRING("Mild"),
        .statUp = STAT_SPATK,
        .statDown = STAT_DEF,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_MILD, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlMild,
        .battlePalacePercents = PALACE_STYLE(44, 50, 34, 6), //6%, 60%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_QUIET] =
    {
        .name = COMPOUND_STRING("Quiet"),
        .statUp = STAT_SPATK,
        .statDown = STAT_SPEED,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_QUIET, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_BASHFUL] =
    {
        .name = COMPOUND_STRING("Bashful"),
        .statUp = STAT_SPATK,
        .statDown = STAT_SPATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_BASHFUL, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlBashful,
        .battlePalacePercents = PALACE_STYLE(30, 58, 30, 58), //12%, 12%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_RASH] =
    {
        .name = COMPOUND_STRING("Rash"),
        .statUp = STAT_SPATK,
        .statDown = STAT_SPDEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_RASH, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlRash,
        .battlePalacePercents = PALACE_STYLE(30, 13, 27, 6), //57%, 67%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_CALM] =
    {
        .name = COMPOUND_STRING("Calm"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_ATK,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_CALM, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlCalm,
        .battlePalacePercents = PALACE_STYLE(40, 50, 25, 62), //10%, 13%
        .battlePalaceFlavorText = B_MSG_GETTING_IN_POS,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_GENTLE] =
    {
        .name = COMPOUND_STRING("Gentle"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_DEF,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_GENTLE, AFFINE_TURN_DOWN_SLIGHT},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlGentle,
        .battlePalacePercents = PALACE_STYLE(18, 70, 90, 5), //12%, 5%
        .battlePalaceFlavorText = B_MSG_GLINT_IN_EYE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
    [NATURE_SASSY] =
    {
        .name = COMPOUND_STRING("Sassy"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_SPEED,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_SASSY, AFFINE_TURN_UP_HIGH},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlSassy,
        .battlePalacePercents = PALACE_STYLE(88, 6, 22, 20), //6%, 58%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_CAREFUL] =
    {
        .name = COMPOUND_STRING("Careful"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_SPATK,
        .backAnim = 2,
        .pokeBlockAnim = {ANIM_CAREFUL, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlCareful,
        .battlePalacePercents = PALACE_STYLE(42, 50, 42, 5), //8%, 53%
        .battlePalaceFlavorText = B_MSG_GROWL_DEEPLY,
        .battlePalaceSmokescreen = PALACE_TARGET_WEAKER,
    },
    [NATURE_QUIRKY] =
    {
        .name = COMPOUND_STRING("Quirky"),
        .statUp = STAT_SPDEF,
        .statDown = STAT_SPDEF,
        .backAnim = 1,
        .pokeBlockAnim = {ANIM_QUIRKY, AFFINE_NONE},
        .natureGirlMessage = BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky,
        .battlePalacePercents = PALACE_STYLE(56, 22, 56, 22), //22%, 22%
        .battlePalaceFlavorText = B_MSG_EAGER_FOR_MORE,
        .battlePalaceSmokescreen = PALACE_TARGET_STRONGER,
    },
};

#include "data/graphics/pokemon.h"
#include "data/pokemon_graphics/front_pic_anims.h"

#include "data/pokemon/trainer_class_lookups.h"
#include "data/pokemon/experience_tables.h"

#if P_LVL_UP_LEARNSETS >= GEN_9
#include "data/pokemon/level_up_learnsets/gen_9.h" // Scarlet/Violet
#elif P_LVL_UP_LEARNSETS >= GEN_8
#include "data/pokemon/level_up_learnsets/gen_8.h" // Sword/Shield
#elif P_LVL_UP_LEARNSETS >= GEN_7
#include "data/pokemon/level_up_learnsets/gen_7.h" // Ultra Sun/Ultra Moon
#elif P_LVL_UP_LEARNSETS >= GEN_6
#include "data/pokemon/level_up_learnsets/gen_6.h" // Omega Ruby/Alpha Sapphire
#elif P_LVL_UP_LEARNSETS >= GEN_5
#include "data/pokemon/level_up_learnsets/gen_5.h" // Black 2/White 2
#elif P_LVL_UP_LEARNSETS >= GEN_4
#include "data/pokemon/level_up_learnsets/gen_4.h" // HeartGold/SoulSilver
#elif P_LVL_UP_LEARNSETS >= GEN_3
#include "data/pokemon/level_up_learnsets/gen_3.h" // Ruby/Sapphire/Emerald
#elif P_LVL_UP_LEARNSETS >= GEN_2
#include "data/pokemon/level_up_learnsets/gen_2.h" // Crystal
#elif P_LVL_UP_LEARNSETS >= GEN_1
#include "data/pokemon/level_up_learnsets/gen_1.h" // Yellow
#endif

#include "data/pokemon/teachable_learnsets.h"
#include "data/pokemon/egg_moves.h"
#include "data/pokemon/form_species_tables.h"
#include "data/pokemon/form_change_tables.h"
#include "data/pokemon/form_change_table_pointers.h"
#include "data/object_events/object_event_pic_tables_followers.h"

#include "data/pokemon/species_info.h"

#define PP_UP_SHIFTS(val)           val,        (val) << 2,        (val) << 4,        (val) << 6
#define PP_UP_SHIFTS_INV(val) (u8)~(val), (u8)~((val) << 2), (u8)~((val) << 4), (u8)~((val) << 6)

// PP Up bonuses are stored for a Pokémon as a single byte.
// There are 2 bits (a value 0-3) for each move slot that
// represent how many PP Ups have been applied.
// The following arrays take a move slot id and return:
// gPPUpGetMask - A mask to get the number of PP Ups applied to that move slot
// gPPUpClearMask - A mask to clear the number of PP Ups applied to that move slot
// gPPUpAddValues - A value to add to the PP Bonuses byte to apply 1 PP Up to that move slot
const u8 gPPUpGetMask[MAX_MON_MOVES]   = {PP_UP_SHIFTS(3)};
const u8 gPPUpClearMask[MAX_MON_MOVES] = {PP_UP_SHIFTS_INV(3)};
const u8 gPPUpAddValues[MAX_MON_MOVES] = {PP_UP_SHIFTS(1)};

const u8 gStatStageRatios[MAX_STAT_STAGE + 1][2] =
{
    {10, 40}, // -6, MIN_STAT_STAGE
    {10, 35}, // -5
    {10, 30}, // -4
    {10, 25}, // -3
    {10, 20}, // -2
    {10, 15}, // -1
    {10, 10}, //  0, DEFAULT_STAT_STAGE
    {15, 10}, // +1
    {20, 10}, // +2
    {25, 10}, // +3
    {30, 10}, // +4
    {35, 10}, // +5
    {40, 10}, // +6, MAX_STAT_STAGE
};

// The classes used by other players in the Union Room.
// These should correspond with the overworld graphics in sUnionRoomObjGfxIds
const u16 gUnionRoomFacilityClasses[NUM_UNION_ROOM_CLASSES * GENDER_COUNT] =
{
    // Male classes
    FACILITY_CLASS_COOLTRAINER_M,
    FACILITY_CLASS_BLACK_BELT,
    FACILITY_CLASS_CAMPER,
    FACILITY_CLASS_YOUNGSTER,
    FACILITY_CLASS_PSYCHIC_M,
    FACILITY_CLASS_BUG_CATCHER,
    FACILITY_CLASS_PKMN_BREEDER_M,
    FACILITY_CLASS_GUITARIST,
    // Female classes
    FACILITY_CLASS_COOLTRAINER_F,
    FACILITY_CLASS_HEX_MANIAC,
    FACILITY_CLASS_PICNICKER,
    FACILITY_CLASS_LASS,
    FACILITY_CLASS_PSYCHIC_F,
    FACILITY_CLASS_BATTLE_GIRL,
    FACILITY_CLASS_PKMN_BREEDER_F,
    FACILITY_CLASS_BEAUTY
};

const struct SpriteTemplate gBattlerSpriteTemplates[MAX_BATTLERS_COUNT] =
{
    [B_POSITION_PLAYER_LEFT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gBattlerPicTable_PlayerLeft,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [B_POSITION_OPPONENT_LEFT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpriteOpponentSide,
        .anims = NULL,
        .images = gBattlerPicTable_OpponentLeft,
        .affineAnims = gAffineAnims_BattleSpriteOpponentSide,
        .callback = SpriteCB_WildMon,
    },
    [B_POSITION_PLAYER_RIGHT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gBattlerPicTable_PlayerRight,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [B_POSITION_OPPONENT_RIGHT] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpriteOpponentSide,
        .anims = NULL,
        .images = gBattlerPicTable_OpponentRight,
        .affineAnims = gAffineAnims_BattleSpriteOpponentSide,
        .callback = SpriteCB_WildMon
    },
};

static const struct SpriteTemplate sTrainerBackSpriteTemplates[] =
{
    [TRAINER_BACK_PIC_BRENDAN] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Brendan,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_MAY] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_May,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_RED] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Red,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_LEAF] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Leaf,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_LUCAS] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Lucas,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_DAWN] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Dawn,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_CYNTHIA] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Cynthia,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_STEVEN] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Steven,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_OAK] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Oak,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_PHOEBE] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Phoebe,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_ETHAN] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Ethan,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
    [TRAINER_BACK_PIC_LYRA] = {
        .tileTag = TAG_NONE,
        .paletteTag = 0,
        .oam = &gOamData_BattleSpritePlayerSide,
        .anims = NULL,
        .images = gTrainerBackPicTable_Lyra,
        .affineAnims = gAffineAnims_BattleSpritePlayerSide,
        .callback = SpriteCB_BattleSpriteStartSlideLeft,
    },
};

#define NUM_SECRET_BASE_CLASSES 5
static const u8 sSecretBaseFacilityClasses[GENDER_COUNT][NUM_SECRET_BASE_CLASSES] =
{
    [MALE] = {
        FACILITY_CLASS_YOUNGSTER,
        FACILITY_CLASS_BUG_CATCHER,
        FACILITY_CLASS_RICH_BOY,
        FACILITY_CLASS_CAMPER,
        FACILITY_CLASS_COOLTRAINER_M
    },
    [FEMALE] = {
        FACILITY_CLASS_LASS,
        FACILITY_CLASS_SCHOOL_KID_F,
        FACILITY_CLASS_LADY,
        FACILITY_CLASS_PICNICKER,
        FACILITY_CLASS_COOLTRAINER_F
    }
};

static const u8 sGetMonDataEVConstants[] =
{
    MON_DATA_HP_EV,
    MON_DATA_ATK_EV,
    MON_DATA_DEF_EV,
    MON_DATA_SPEED_EV,
    MON_DATA_SPDEF_EV,
    MON_DATA_SPATK_EV
};

// For stat-raising items
static const u8 sStatsToRaise[] =
{
    STAT_ATK, STAT_ATK, STAT_DEF, STAT_SPEED, STAT_SPATK, STAT_SPDEF, STAT_ACC
};

// 3 modifiers each for how much to change friendship for different ranges
// 0-99, 100-199, 200+
static const s8 sFriendshipEventModifiers[][3] =
{
    [FRIENDSHIP_EVENT_GROW_LEVEL]      = { 5,  3,  2},
    [FRIENDSHIP_EVENT_VITAMIN]         = { 5,  3,  2},
    [FRIENDSHIP_EVENT_BATTLE_ITEM]     = { 1,  1,  0},
    [FRIENDSHIP_EVENT_LEAGUE_BATTLE]   = { 3,  2,  1},
    [FRIENDSHIP_EVENT_LEARN_TMHM]      = { 1,  1,  0},
    [FRIENDSHIP_EVENT_WALKING]         = { 1,  1,  1},
    [FRIENDSHIP_EVENT_FAINT_SMALL]     = {-1, -1, -1},
    [FRIENDSHIP_EVENT_FAINT_FIELD_PSN] = {-5, -5, -10},
    [FRIENDSHIP_EVENT_FAINT_LARGE]     = {-5, -5, -10},
};

#define HM_MOVES_END 0xFFFF

static const u16 sHMMoves[] =
{
    MOVE_CUT, MOVE_FLY, MOVE_SURF, MOVE_STRENGTH, MOVE_FLASH,
    MOVE_ROCK_SMASH, MOVE_WATERFALL, MOVE_DIVE, HM_MOVES_END
};

static const struct SpeciesItem sAlteringCaveWildMonHeldItems[] =
{
    {SPECIES_NONE,      ITEM_NONE},
    {SPECIES_MAREEP,    ITEM_GANLON_BERRY},
    {SPECIES_PINECO,    ITEM_APICOT_BERRY},
    {SPECIES_HOUNDOUR,  ITEM_BIG_MUSHROOM},
    {SPECIES_TEDDIURSA, ITEM_PETAYA_BERRY},
    {SPECIES_AIPOM,     ITEM_BERRY_JUICE},
    {SPECIES_SHUCKLE,   ITEM_BERRY_JUICE},
    {SPECIES_STANTLER,  ITEM_PETAYA_BERRY},
    {SPECIES_SMEARGLE,  ITEM_SALAC_BERRY},
};

static const struct OamData sOamData_64x64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

static const struct SpriteTemplate sSpriteTemplate_64x64 =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_NONE,
    .oam = &sOamData_64x64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// NOTE: Reordering this array will break compatibility with existing
// saves.
static const u32 sCompressedStatuses[] =
{
    STATUS1_NONE,
    STATUS1_SLEEP_TURN(1),
    STATUS1_SLEEP_TURN(2),
    STATUS1_SLEEP_TURN(3),
    STATUS1_SLEEP_TURN(4),
    STATUS1_SLEEP_TURN(5),
    STATUS1_POISON,
    STATUS1_BURN,
    STATUS1_FREEZE,
    STATUS1_PARALYSIS,
    STATUS1_TOXIC_POISON,
    STATUS1_FROSTBITE,
};

// Attempt to detect situations where the BoxPokemon struct is unable to
// contain all the values.
// TODO: Is it possible to compute:
// - The maximum experience.
// - The maximum PP.
// - The maximum HP.
// - The maximum form countdown.

// The following STATIC_ASSERT will prevent developers from compiling the game if the value of the constant on the left does not fit within the number of bits defined in PokemonSubstruct0 (currently located in include/pokemon.h).

// To successfully compile, developers will need to do one of the following:
// 1) Decrease the size of the constant.
// 2) Increase the number of bits both on the struct AND in the corresponding assert. This will likely break user's saves unless there is free space after the member that is being adjsted.
// 3) Repurpose unused IDs.

// EXAMPLES
// If a developer has added enough new items so that ITEMS_COUNT now equals 1200, they could...
// 1) remove new items until ITEMS_COUNT is 1023, the max value that will fit in 10 bits.
// 2) change heldItem:10 to heldItem:11 AND change the below assert for ITEMS_COUNT to check for (1 << 11).
// 3) repurpose IDs from other items that aren't being used, like ITEM_GOLD_TEETH or ITEM_SS_TICKET until ITEMS_COUNT equals 1023, the max value that will fit in 10 bits.

STATIC_ASSERT(NUM_SPECIES < (1 << 11), PokemonSubstruct0_species_TooSmall);
STATIC_ASSERT(NUMBER_OF_MON_TYPES + 1 <= (1 << 5), PokemonSubstruct0_teraType_TooSmall);
STATIC_ASSERT(ITEMS_COUNT < (1 << 10), PokemonSubstruct0_heldItem_TooSmall);
STATIC_ASSERT(MAX_LEVEL <= 100, PokemonSubstruct0_experience_PotentiallTooSmall); // Maximum of ~2 million exp.
STATIC_ASSERT(LAST_BALL < (1 << 6), PokemonSubstruct0_pokeball_TooSmall);
STATIC_ASSERT(MOVES_COUNT_ALL < (1 << 11), PokemonSubstruct1_moves_TooSmall);
STATIC_ASSERT(ARRAY_COUNT(sCompressedStatuses) <= (1 << 4), PokemonSubstruct3_compressedStatus_TooSmall);
STATIC_ASSERT(MAX_LEVEL < (1 << 7), PokemonSubstruct3_metLevel_TooSmall);
STATIC_ASSERT(NUM_VERSIONS < (1 << 4), PokemonSubstruct3_metGame_TooSmall);
STATIC_ASSERT(MAX_DYNAMAX_LEVEL < (1 << 4), PokemonSubstruct3_dynamaxLevel_TooSmall);
STATIC_ASSERT(MAX_PER_STAT_IVS < (1 << 5), PokemonSubstruct3_ivs_TooSmall);
STATIC_ASSERT(NUM_NATURES <= (1 << 5), BoxPokemon_hiddenNatureModifier_TooSmall);

static u32 CompressStatus(u32 status)
{
    s32 i;
    for (i = 0; i < ARRAY_COUNT(sCompressedStatuses); i++)
    {
        if (sCompressedStatuses[i] == status)
            return i;
    }
    return 0; // STATUS1_NONE
}

static u32 UncompressStatus(u32 compressedStatus)
{
    if (compressedStatus < ARRAY_COUNT(sCompressedStatuses))
        return sCompressedStatuses[compressedStatus];
    else
        return STATUS1_NONE;
}

void ZeroBoxMonData(struct BoxPokemon *boxMon)
{
    u8 *raw = (u8 *)boxMon;
    u32 i;
    for (i = 0; i < sizeof(struct BoxPokemon); i++)
        raw[i] = 0;
}

void ZeroMonData(struct Pokemon *mon)
{
    u32 arg;
    ZeroBoxMonData(&mon->box);
    arg = 0;
    SetMonData(mon, MON_DATA_STATUS, &arg);
    SetMonData(mon, MON_DATA_LEVEL, &arg);
    SetMonData(mon, MON_DATA_HP, &arg);
    SetMonData(mon, MON_DATA_MAX_HP, &arg);
    SetMonData(mon, MON_DATA_ATK, &arg);
    SetMonData(mon, MON_DATA_DEF, &arg);
    SetMonData(mon, MON_DATA_SPEED, &arg);
    SetMonData(mon, MON_DATA_SPATK, &arg);
    SetMonData(mon, MON_DATA_SPDEF, &arg);
    arg = MAIL_NONE;
    SetMonData(mon, MON_DATA_MAIL, &arg);
}

void ZeroPlayerPartyMons(void)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);
}

void ZeroEnemyPartyMons(void)
{
    s32 i;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&gEnemyParty[i]);
}

void CreateMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u32 mail;
    ZeroMonData(mon);
    CreateBoxMon(&mon->box, species, level, fixedIV, hasFixedPersonality, fixedPersonality, otIdType, fixedOtId);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    mail = MAIL_NONE;
    SetMonData(mon, MON_DATA_MAIL, &mail);
    CalculateMonStats(mon);
}

void CreateBoxMon(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    u32 personality;
    u32 value;
    u16 checksum;
    u8 i;
    u8 availableIVs[NUM_STATS];
    u8 selectedIvs[LEGENDARY_PERFECT_IV_COUNT];
    bool32 isShiny;

    ZeroBoxMonData(boxMon);

    if (hasFixedPersonality)
        personality = fixedPersonality;
    else
        personality = Random32();

    // Determine original trainer ID
    if (otIdType == OT_ID_RANDOM_NO_SHINY)
    {
        value = Random32();
        isShiny = FALSE;
    }
    else if (otIdType == OT_ID_PRESET)
    {
        value = fixedOtId;
        isShiny = GET_SHINY_VALUE(value, personality) < SHINY_ODDS;
    }
    else // Player is the OT
    {
        value = gSaveBlock2Ptr->playerTrainerId[0]
              | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
              | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
              | (gSaveBlock2Ptr->playerTrainerId[3] << 24);

        if (P_FLAG_FORCE_NO_SHINY != 0 && FlagGet(P_FLAG_FORCE_NO_SHINY))
        {
            isShiny = FALSE;
        }
        else if (P_FLAG_FORCE_SHINY != 0 && FlagGet(P_FLAG_FORCE_SHINY))
        {
            isShiny = TRUE;
        }
        else if (P_ONLY_OBTAINABLE_SHINIES && InBattlePyramid())
        {
            isShiny = FALSE;
        }
        else if (P_NO_SHINIES_WITHOUT_POKEBALLS && !HasAtLeastOnePokeBall())
        {
            isShiny = FALSE;
        }
        else
        {
            u32 totalRerolls = 0;
            if (CheckBagHasItem(ITEM_SHINY_CHARM, 1))
                totalRerolls += I_SHINY_CHARM_ADDITIONAL_ROLLS;
            if (LURE_STEP_COUNT != 0)
                totalRerolls += 1;
            if (I_FISHING_CHAIN && gIsFishingEncounter)
                totalRerolls += CalculateChainFishingShinyRolls();

            while (GET_SHINY_VALUE(value, personality) >= SHINY_ODDS && totalRerolls > 0)
            {
                personality = Random32();
                totalRerolls--;
            }

            isShiny = GET_SHINY_VALUE(value, personality) < SHINY_ODDS;
        }
    }

    SetBoxMonData(boxMon, MON_DATA_PERSONALITY, &personality);
    SetBoxMonData(boxMon, MON_DATA_OT_ID, &value);

    checksum = CalculateBoxMonChecksum(boxMon);
    SetBoxMonData(boxMon, MON_DATA_CHECKSUM, &checksum);
    EncryptBoxMon(boxMon);
    SetBoxMonData(boxMon, MON_DATA_IS_SHINY, &isShiny);
    StringCopy(speciesName, GetSpeciesName(species));
    SetBoxMonData(boxMon, MON_DATA_NICKNAME, speciesName);
    SetBoxMonData(boxMon, MON_DATA_LANGUAGE, &gGameLanguage);
    SetBoxMonData(boxMon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetBoxMonData(boxMon, MON_DATA_SPECIES, &species);
    SetBoxMonData(boxMon, MON_DATA_EXP, &gExperienceTables[gSpeciesInfo[species].growthRate][level]);
    SetBoxMonData(boxMon, MON_DATA_FRIENDSHIP, &gSpeciesInfo[species].friendship);
    value = GetCurrentRegionMapSectionId();
    SetBoxMonData(boxMon, MON_DATA_MET_LOCATION, &value);
    SetBoxMonData(boxMon, MON_DATA_MET_LEVEL, &level);
    SetBoxMonData(boxMon, MON_DATA_MET_GAME, &gGameVersion);
    value = ITEM_POKE_BALL;
    SetBoxMonData(boxMon, MON_DATA_POKEBALL, &value);
    SetBoxMonData(boxMon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);

    if (fixedIV < USE_RANDOM_IVS)
    {
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &fixedIV);
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &fixedIV);
    }
    else
    {
        u32 iv;
        u32 ivRandom = Random32();
        value = (u16)ivRandom;

        iv = value & MAX_IV_MASK;
        SetBoxMonData(boxMon, MON_DATA_HP_IV, &iv);
        iv = (value & (MAX_IV_MASK << 5)) >> 5;
        SetBoxMonData(boxMon, MON_DATA_ATK_IV, &iv);
        iv = (value & (MAX_IV_MASK << 10)) >> 10;
        SetBoxMonData(boxMon, MON_DATA_DEF_IV, &iv);

        value = (u16)(ivRandom >> 16);

        iv = value & MAX_IV_MASK;
        SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &iv);
        iv = (value & (MAX_IV_MASK << 5)) >> 5;
        SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &iv);
        iv = (value & (MAX_IV_MASK << 10)) >> 10;
        SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &iv);

        if (gSpeciesInfo[species].allPerfectIVs)
        {
            iv = MAX_PER_STAT_IVS;
            SetBoxMonData(boxMon, MON_DATA_HP_IV, &iv);
            SetBoxMonData(boxMon, MON_DATA_ATK_IV, &iv);
            SetBoxMonData(boxMon, MON_DATA_DEF_IV, &iv);
            SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &iv);
            SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &iv);
            SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &iv);
        }
        else if (P_LEGENDARY_PERFECT_IVS >= GEN_6
         && (gSpeciesInfo[species].isLegendary
          || gSpeciesInfo[species].isMythical
          || gSpeciesInfo[species].isUltraBeast
          || gSpeciesInfo[species].isTotem))
        {
            iv = MAX_PER_STAT_IVS;
            // Initialize a list of IV indices.
            for (i = 0; i < NUM_STATS; i++)
            {
                availableIVs[i] = i;
            }

            // Select the 3 IVs that will be perfected.
            for (i = 0; i < LEGENDARY_PERFECT_IV_COUNT; i++)
            {
                u8 index = Random() % (NUM_STATS - i);
                selectedIvs[i] = availableIVs[index];
                RemoveIVIndexFromList(availableIVs, index);
            }
            for (i = 0; i < LEGENDARY_PERFECT_IV_COUNT; i++)
            {
                switch (selectedIvs[i])
                {
                case STAT_HP:
                    SetBoxMonData(boxMon, MON_DATA_HP_IV, &iv);
                    break;
                case STAT_ATK:
                    SetBoxMonData(boxMon, MON_DATA_ATK_IV, &iv);
                    break;
                case STAT_DEF:
                    SetBoxMonData(boxMon, MON_DATA_DEF_IV, &iv);
                    break;
                case STAT_SPEED:
                    SetBoxMonData(boxMon, MON_DATA_SPEED_IV, &iv);
                    break;
                case STAT_SPATK:
                    SetBoxMonData(boxMon, MON_DATA_SPATK_IV, &iv);
                    break;
                case STAT_SPDEF:
                    SetBoxMonData(boxMon, MON_DATA_SPDEF_IV, &iv);
                    break;
                }
            }
        }
    }

    if (gSpeciesInfo[species].abilities[1])
    {
        value = personality & 1;
        SetBoxMonData(boxMon, MON_DATA_ABILITY_NUM, &value);
    }

    GiveBoxMonInitialMoveset(boxMon);
}

void CreateMonWithNature(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 nature)
{
    u32 personality;

    do
    {
        personality = Random32();
    }
    while (nature != GetNatureFromPersonality(personality));

    CreateMon(mon, species, level, fixedIV, TRUE, personality, OT_ID_PLAYER_ID, 0);
}

void CreateMonWithGenderNatureLetter(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 gender, u8 nature, u8 unownLetter)
{
    u32 personality;

    if ((u8)(unownLetter - 1) < NUM_UNOWN_FORMS)
    {
        u16 actualLetter;

        do
        {
            personality = Random32();
            actualLetter = GET_UNOWN_LETTER(personality);
        }
        while (nature != GetNatureFromPersonality(personality)
            || gender != GetGenderFromSpeciesAndPersonality(species, personality)
            || actualLetter != unownLetter - 1);
    }
    else
    {
        do
        {
            personality = Random32();
        }
        while (nature != GetNatureFromPersonality(personality)
            || gender != GetGenderFromSpeciesAndPersonality(species, personality));
    }

    CreateMon(mon, species, level, fixedIV, TRUE, personality, OT_ID_PLAYER_ID, 0);
}

// This is only used to create Wally's Ralts.
void CreateMaleMon(struct Pokemon *mon, u16 species, u8 level)
{
    u32 personality;
    u32 otId;

    do
    {
        otId = Random32();
        personality = Random32();
    }
    while (GetGenderFromSpeciesAndPersonality(species, personality) != MON_MALE);
    CreateMon(mon, species, level, USE_RANDOM_IVS, TRUE, personality, OT_ID_PRESET, otId);
}

void CreateMonWithIVsPersonality(struct Pokemon *mon, u16 species, u8 level, u32 ivs, u32 personality)
{
    CreateMon(mon, species, level, 0, TRUE, personality, OT_ID_PLAYER_ID, 0);
    SetMonData(mon, MON_DATA_IVS, &ivs);
    CalculateMonStats(mon);
}

void CreateMonWithIVsOTID(struct Pokemon *mon, u16 species, u8 level, u8 *ivs, u32 otId)
{
    CreateMon(mon, species, level, 0, FALSE, 0, OT_ID_PRESET, otId);
    SetMonData(mon, MON_DATA_HP_IV, &ivs[STAT_HP]);
    SetMonData(mon, MON_DATA_ATK_IV, &ivs[STAT_ATK]);
    SetMonData(mon, MON_DATA_DEF_IV, &ivs[STAT_DEF]);
    SetMonData(mon, MON_DATA_SPEED_IV, &ivs[STAT_SPEED]);
    SetMonData(mon, MON_DATA_SPATK_IV, &ivs[STAT_SPATK]);
    SetMonData(mon, MON_DATA_SPDEF_IV, &ivs[STAT_SPDEF]);
    CalculateMonStats(mon);
}

void CreateMonWithEVSpread(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 evSpread)
{
    s32 i;
    s32 statCount = 0;
    u16 evAmount;
    u8 evsBits;

    CreateMon(mon, species, level, fixedIV, FALSE, 0, OT_ID_PLAYER_ID, 0);

    evsBits = evSpread;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (evsBits & 1)
            statCount++;
        evsBits >>= 1;
    }

    evAmount = MAX_TOTAL_EVS / statCount;

    evsBits = 1;

    for (i = 0; i < NUM_STATS; i++)
    {
        if (evSpread & evsBits)
            SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);
        evsBits <<= 1;
    }

    CalculateMonStats(mon);
}

void CreateBattleTowerMon(struct Pokemon *mon, struct BattleTowerPokemon *src)
{
    s32 i;
    u8 nickname[max(32, POKEMON_NAME_BUFFER_SIZE)];
    u8 language;
    u8 value;

    CreateMon(mon, src->species, src->level, 0, TRUE, src->personality, OT_ID_PRESET, src->otId);

    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, src->moves[i], i);

    SetMonData(mon, MON_DATA_PP_BONUSES, &src->ppBonuses);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->heldItem);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &src->friendship);

    StringCopy(nickname, src->nickname);

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
    {
        language = LANGUAGE_JAPANESE;
        StripExtCtrlCodes(nickname);
    }
    else
    {
        language = GAME_LANGUAGE;
    }

    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_NICKNAME, nickname);
    SetMonData(mon, MON_DATA_HP_EV, &src->hpEV);
    SetMonData(mon, MON_DATA_ATK_EV, &src->attackEV);
    SetMonData(mon, MON_DATA_DEF_EV, &src->defenseEV);
    SetMonData(mon, MON_DATA_SPEED_EV, &src->speedEV);
    SetMonData(mon, MON_DATA_SPATK_EV, &src->spAttackEV);
    SetMonData(mon, MON_DATA_SPDEF_EV, &src->spDefenseEV);
    value = src->abilityNum;
    SetMonData(mon, MON_DATA_ABILITY_NUM, &value);
    value = src->hpIV;
    SetMonData(mon, MON_DATA_HP_IV, &value);
    value = src->attackIV;
    SetMonData(mon, MON_DATA_ATK_IV, &value);
    value = src->defenseIV;
    SetMonData(mon, MON_DATA_DEF_IV, &value);
    value = src->speedIV;
    SetMonData(mon, MON_DATA_SPEED_IV, &value);
    value = src->spAttackIV;
    SetMonData(mon, MON_DATA_SPATK_IV, &value);
    value = src->spDefenseIV;
    SetMonData(mon, MON_DATA_SPDEF_IV, &value);
    MonRestorePP(mon);
    CalculateMonStats(mon);
}

void CreateBattleTowerMon_HandleLevel(struct Pokemon *mon, struct BattleTowerPokemon *src, bool8 lvl50)
{
    s32 i;
    u8 nickname[max(32, POKEMON_NAME_BUFFER_SIZE)];
    u8 level;
    u8 language;
    u8 value;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
        level = GetFrontierEnemyMonLevel(gSaveBlock2Ptr->frontier.lvlMode);
    else if (lvl50)
        level = FRONTIER_MAX_LEVEL_50;
    else
        level = src->level;

    CreateMon(mon, src->species, level, 0, TRUE, src->personality, OT_ID_PRESET, src->otId);

    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, src->moves[i], i);

    SetMonData(mon, MON_DATA_PP_BONUSES, &src->ppBonuses);
    SetMonData(mon, MON_DATA_HELD_ITEM, &src->heldItem);
    SetMonData(mon, MON_DATA_FRIENDSHIP, &src->friendship);

    StringCopy(nickname, src->nickname);

    if (nickname[0] == EXT_CTRL_CODE_BEGIN && nickname[1] == EXT_CTRL_CODE_JPN)
    {
        language = LANGUAGE_JAPANESE;
        StripExtCtrlCodes(nickname);
    }
    else
    {
        language = GAME_LANGUAGE;
    }

    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_NICKNAME, nickname);
    SetMonData(mon, MON_DATA_HP_EV, &src->hpEV);
    SetMonData(mon, MON_DATA_ATK_EV, &src->attackEV);
    SetMonData(mon, MON_DATA_DEF_EV, &src->defenseEV);
    SetMonData(mon, MON_DATA_SPEED_EV, &src->speedEV);
    SetMonData(mon, MON_DATA_SPATK_EV, &src->spAttackEV);
    SetMonData(mon, MON_DATA_SPDEF_EV, &src->spDefenseEV);
    value = src->abilityNum;
    SetMonData(mon, MON_DATA_ABILITY_NUM, &value);
    value = src->hpIV;
    SetMonData(mon, MON_DATA_HP_IV, &value);
    value = src->attackIV;
    SetMonData(mon, MON_DATA_ATK_IV, &value);
    value = src->defenseIV;
    SetMonData(mon, MON_DATA_DEF_IV, &value);
    value = src->speedIV;
    SetMonData(mon, MON_DATA_SPEED_IV, &value);
    value = src->spAttackIV;
    SetMonData(mon, MON_DATA_SPATK_IV, &value);
    value = src->spDefenseIV;
    SetMonData(mon, MON_DATA_SPDEF_IV, &value);
    MonRestorePP(mon);
    CalculateMonStats(mon);
}

void CreateApprenticeMon(struct Pokemon *mon, const struct Apprentice *src, u8 monId)
{
    s32 i;
    u16 evAmount;
    u8 language;
    u32 otId = gApprentices[src->id].otId;
    u32 personality = ((gApprentices[src->id].otId >> 8) | ((gApprentices[src->id].otId & 0xFF) << 8))
                    + src->party[monId].species + src->number;

    CreateMon(mon,
              src->party[monId].species,
              GetFrontierEnemyMonLevel(src->lvlMode - 1),
              MAX_PER_STAT_IVS,
              TRUE,
              personality,
              OT_ID_PRESET,
              otId);

    SetMonData(mon, MON_DATA_HELD_ITEM, &src->party[monId].item);
    for (i = 0; i < MAX_MON_MOVES; i++)
        SetMonMoveSlot(mon, src->party[monId].moves[i], i);

    evAmount = MAX_TOTAL_EVS / NUM_STATS;
    for (i = 0; i < NUM_STATS; i++)
        SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);

    language = src->language;
    SetMonData(mon, MON_DATA_LANGUAGE, &language);
    SetMonData(mon, MON_DATA_OT_NAME, GetApprenticeNameInLanguage(src->id, language));
    CalculateMonStats(mon);
}

void CreateMonWithEVSpreadNatureOTID(struct Pokemon *mon, u16 species, u8 level, u8 nature, u8 fixedIV, u8 evSpread, u32 otId)
{
    s32 i;
    s32 statCount = 0;
    u8 evsBits;
    u16 evAmount;

    // i is reused as personality value
    do
    {
        i = Random32();
    } while (nature != GetNatureFromPersonality(i));

    CreateMon(mon, species, level, fixedIV, TRUE, i, OT_ID_PRESET, otId);
    evsBits = evSpread;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (evsBits & 1)
            statCount++;
        evsBits >>= 1;
    }

    evAmount = MAX_TOTAL_EVS / statCount;
    evsBits = 1;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (evSpread & evsBits)
            SetMonData(mon, MON_DATA_HP_EV + i, &evAmount);
        evsBits <<= 1;
    }

    CalculateMonStats(mon);
}

void ConvertPokemonToBattleTowerPokemon(struct Pokemon *mon, struct BattleTowerPokemon *dest)
{
    s32 i;
    u16 heldItem;

    dest->species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);

    if (heldItem == ITEM_ENIGMA_BERRY_E_READER)
        heldItem = ITEM_NONE;

    dest->heldItem = heldItem;

    for (i = 0; i < MAX_MON_MOVES; i++)
        dest->moves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, NULL);

    dest->level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    dest->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    dest->otId = GetMonData(mon, MON_DATA_OT_ID, NULL);
    dest->hpEV = GetMonData(mon, MON_DATA_HP_EV, NULL);
    dest->attackEV = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    dest->defenseEV = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    dest->speedEV = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    dest->spAttackEV = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    dest->spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    dest->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
    dest->hpIV = GetMonData(mon, MON_DATA_HP_IV, NULL);
    dest->attackIV = GetMonData(mon, MON_DATA_ATK_IV, NULL);
    dest->defenseIV = GetMonData(mon, MON_DATA_DEF_IV, NULL);
    dest->speedIV  = GetMonData(mon, MON_DATA_SPEED_IV, NULL);
    dest->spAttackIV  = GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    dest->spDefenseIV  = GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    dest->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM, NULL);
    dest->personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    GetMonData(mon, MON_DATA_NICKNAME10, dest->nickname);
}

static void CreateEventMon(struct Pokemon *mon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    bool32 isModernFatefulEncounter = TRUE;

    CreateMon(mon, species, level, fixedIV, hasFixedPersonality, fixedPersonality, otIdType, fixedOtId);
    SetMonData(mon, MON_DATA_MODERN_FATEFUL_ENCOUNTER, &isModernFatefulEncounter);
}

// If FALSE, should load this game's Deoxys form. If TRUE, should load normal Deoxys form
bool8 ShouldIgnoreDeoxysForm(u8 caseId, u8 battlerId)
{
    switch (caseId)
    {
    case 0:
    default:
        return FALSE;
    case 1: // Player's side in battle
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            return FALSE;
        if (!gMain.inBattle)
            return FALSE;
        if (gLinkPlayers[GetMultiplayerId()].id == battlerId)
            return FALSE;
        break;
    case 2:
        break;
    case 3: // Summary Screen
        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
            return FALSE;
        if (!gMain.inBattle)
            return FALSE;
        if (battlerId == 1 || battlerId == 4 || battlerId == 5)
            return TRUE;
        return FALSE;
    case 4:
        break;
    case 5: // In move animation, e.g. in Role Play or Snatch
        if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        {
            if (!gMain.inBattle)
                return FALSE;
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                if (gLinkPlayers[GetMultiplayerId()].id == battlerId)
                    return FALSE;
            }
            else
            {
                if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
                    return FALSE;
            }
        }
        else
        {
            if (!gMain.inBattle)
                return FALSE;
            if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
                return FALSE;
        }
        break;
    }

    return TRUE;
}

u16 GetUnionRoomTrainerPic(void)
{
    u8 linkId;
    u32 arrId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        linkId = gRecordedBattleMultiplayerId ^ 1;
    else
        linkId = GetMultiplayerId() ^ 1;

    arrId = gLinkPlayers[linkId].trainerId % NUM_UNION_ROOM_CLASSES;
    arrId |= gLinkPlayers[linkId].gender * NUM_UNION_ROOM_CLASSES;
    return FacilityClassToPicIndex(gUnionRoomFacilityClasses[arrId]);
}

u16 GetUnionRoomTrainerClass(void)
{
    u8 linkId;
    u32 arrId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        linkId = gRecordedBattleMultiplayerId ^ 1;
    else
        linkId = GetMultiplayerId() ^ 1;

    arrId = gLinkPlayers[linkId].trainerId % NUM_UNION_ROOM_CLASSES;
    arrId |= gLinkPlayers[linkId].gender * NUM_UNION_ROOM_CLASSES;
    return gFacilityClassToTrainerClass[gUnionRoomFacilityClasses[arrId]];
}

void CreateEnemyEventMon(void)
{
    s32 species = gSpecialVar_0x8004;
    s32 level = gSpecialVar_0x8005;
    s32 itemId = gSpecialVar_0x8006;

    ZeroEnemyPartyMons();
    CreateEventMon(&gEnemyParty[0], species, level, USE_RANDOM_IVS, FALSE, 0, OT_ID_PLAYER_ID, 0);
    if (itemId)
    {
        u8 heldItem[2];
        heldItem[0] = itemId;
        heldItem[1] = itemId >> 8;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, heldItem);
    }
}

static u16 CalculateBoxMonChecksum(struct BoxPokemon *boxMon)
{
    u16 checksum = 0;
    union PokemonSubstruct *substruct0 = GetSubstruct(boxMon, boxMon->personality, 0);
    union PokemonSubstruct *substruct1 = GetSubstruct(boxMon, boxMon->personality, 1);
    union PokemonSubstruct *substruct2 = GetSubstruct(boxMon, boxMon->personality, 2);
    union PokemonSubstruct *substruct3 = GetSubstruct(boxMon, boxMon->personality, 3);
    s32 i;

    for (i = 0; i < (s32)ARRAY_COUNT(substruct0->raw); i++)
        checksum += substruct0->raw[i];

    for (i = 0; i < (s32)ARRAY_COUNT(substruct1->raw); i++)
        checksum += substruct1->raw[i];

    for (i = 0; i < (s32)ARRAY_COUNT(substruct2->raw); i++)
        checksum += substruct2->raw[i];

    for (i = 0; i < (s32)ARRAY_COUNT(substruct3->raw); i++)
        checksum += substruct3->raw[i];

    return checksum;
}

#define CALC_STAT(base, iv, ev, statIndex, field)               \
{                                                               \
    u8 baseStat = gSpeciesInfo[species].base;                   \
    s32 n = (((2 * baseStat + iv + ev / 4) * level) / 100) + 5; \
    n = ModifyStatByNature(nature, n, statIndex);               \
    if (B_FRIENDSHIP_BOOST == TRUE)                             \
        n = n + ((n * 10 * friendship) / (MAX_FRIENDSHIP * 100));\
    SetMonData(mon, field, &n);                                 \
}

#define RANDOM_STAT(base, iv, ev, statIndex, field)               \
{                                                               \
    s32 n = (((2 * base + iv + ev / 4) * level) / 100) + 5; \
    n = ModifyStatByNature(nature, n, statIndex);               \
    if (B_FRIENDSHIP_BOOST == TRUE)                             \
        n = n + ((n * 10 * friendship) / (MAX_FRIENDSHIP * 100));\
    SetMonData(mon, field, &n);                                 \
}

void CalculateMonStats(struct Pokemon *mon)
{
    s32 oldMaxHP = GetMonData(mon, MON_DATA_MAX_HP, NULL);
    s32 currentHP = GetMonData(mon, MON_DATA_HP, NULL);
    s32 hpIV = GetMonData(mon, MON_DATA_HYPER_TRAINED_HP) ? MAX_PER_STAT_IVS : GetMonData(mon, MON_DATA_HP_IV, NULL);
    s32 hpEV = GetMonData(mon, MON_DATA_HP_EV, NULL);
    s32 attackIV = GetMonData(mon, MON_DATA_HYPER_TRAINED_ATK) ? MAX_PER_STAT_IVS : GetMonData(mon, MON_DATA_ATK_IV, NULL);
    s32 attackEV = GetMonData(mon, MON_DATA_ATK_EV, NULL);
    s32 defenseIV = GetMonData(mon, MON_DATA_HYPER_TRAINED_DEF) ? MAX_PER_STAT_IVS : GetMonData(mon, MON_DATA_DEF_IV, NULL);
    s32 defenseEV = GetMonData(mon, MON_DATA_DEF_EV, NULL);
    s32 speedIV = GetMonData(mon, MON_DATA_HYPER_TRAINED_SPEED) ? MAX_PER_STAT_IVS : GetMonData(mon, MON_DATA_SPEED_IV, NULL);
    s32 speedEV = GetMonData(mon, MON_DATA_SPEED_EV, NULL);
    s32 spAttackIV = GetMonData(mon, MON_DATA_HYPER_TRAINED_SPATK) ? MAX_PER_STAT_IVS : GetMonData(mon, MON_DATA_SPATK_IV, NULL);
    s32 spAttackEV = GetMonData(mon, MON_DATA_SPATK_EV, NULL);
    s32 spDefenseIV = GetMonData(mon, MON_DATA_HYPER_TRAINED_SPDEF) ? MAX_PER_STAT_IVS : GetMonData(mon, MON_DATA_SPDEF_IV, NULL);
    s32 spDefenseEV = GetMonData(mon, MON_DATA_SPDEF_EV, NULL);
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);
    s32 level = GetLevelFromMonExp(mon);
    s32 newMaxHP;
    u64 bst, weightTotal;
    u64 temp1;
    u32 hpW, atW, atsW, deW, desW, spW;
    u32 hp_, at_, ats_, de_, des_, sp_;
    u32 notValidStats = 1;

    u8 nature = GetMonData(mon, MON_DATA_HIDDEN_NATURE, NULL);

    SetMonData(mon, MON_DATA_LEVEL, &level);

    if(gSaveBlock2Ptr->randomBST)
    {
        bst = (gSpeciesInfo[species].baseHP + gSpeciesInfo[species].baseAttack + gSpeciesInfo[species].baseDefense + gSpeciesInfo[species].baseSpAttack + gSpeciesInfo[species].baseSpDefense + gSpeciesInfo[species].baseSpeed) - 70;
        bst *= 1000;

        do
        {
            hpW = RandomSeededModulo2(notValidStats + species + gSpeciesInfo[species].baseHP, 1000);
            atW = RandomSeededModulo2(notValidStats + hpW + species + gSpeciesInfo[species].baseAttack, 1000);
            atsW = RandomSeededModulo2(notValidStats + atW + species + gSpeciesInfo[species].baseSpAttack, 1000);
            deW = RandomSeededModulo2(notValidStats + atsW + species + gSpeciesInfo[species].baseDefense, 1000);
            desW = RandomSeededModulo2(notValidStats + deW + species + gSpeciesInfo[species].baseSpDefense, 1000);
            spW = RandomSeededModulo2(notValidStats + desW + species + gSpeciesInfo[species].baseSpeed, 1000);
            weightTotal = hpW + atW + atsW + deW + desW + spW;

            temp1 = (((u64) hpW) * bst) / weightTotal;
            temp1 = temp1 / ((u64) 1000);
            if (!(temp1 >= 1))
                temp1 = 1;
            hp_ = ((u32) temp1) + 20;

            temp1 = (((u64) atW) * bst) / weightTotal;
            temp1 = temp1 / ((u64) 1000);
            if (!(temp1 >= 1))
                temp1 = 1;
            at_ = ((u32) temp1) + 10;

            temp1 = (((u64) atsW) * bst) / weightTotal;
            temp1 = temp1 / ((u64) 1000);
            if (!(temp1 >= 1))
                temp1 = 1;
            ats_ = ((u32) temp1) + 10;

            temp1 = (((u64) deW) * bst) / weightTotal;
            temp1 = temp1 / ((u64) 1000);
            if (!(temp1 >= 1))
                temp1 = 1;
            de_ = ((u32) temp1) + 10;

            temp1 = (((u64) desW) * bst) / weightTotal;
            temp1 = temp1 / ((u64) 1000);
            if (!(temp1 >= 1))
                temp1 = 1;
            des_ = ((u32) temp1) + 10;

            temp1 = (((u64) spW) * bst) / weightTotal;
            temp1 = temp1 / ((u64) 1000);
            if (!(temp1 >= 1))
                temp1 = 1;
            sp_ = ((u32) temp1) + 10;

            if(hp_ > 255 || at_ > 255 || ats_ > 255 || de_ > 255 || des_ > 255 || sp_ > 255)
                notValidStats += 1;
            else
                notValidStats = 0;
        } while(notValidStats != 0 && species != SPECIES_NONE);

        if (species == SPECIES_SHEDINJA)
        {
            newMaxHP = 1;
        }
        else
        {
            s32 n = 2 * hp_ + hpIV;
            newMaxHP = (((n + hpEV / 4) * level) / 100) + level + 10;
        }

        gBattleScripting.levelUpHP = newMaxHP - oldMaxHP;
        if (gBattleScripting.levelUpHP == 0)
            gBattleScripting.levelUpHP = 1;

        SetMonData(mon, MON_DATA_MAX_HP, &newMaxHP);
        
        RANDOM_STAT(at_, attackIV, attackEV, STAT_ATK, MON_DATA_ATK)
        RANDOM_STAT(de_, defenseIV, defenseEV, STAT_DEF, MON_DATA_DEF)
        RANDOM_STAT(sp_, speedIV, speedEV, STAT_SPEED, MON_DATA_SPEED)
        RANDOM_STAT(ats_, spAttackIV, spAttackEV, STAT_SPATK, MON_DATA_SPATK)
        RANDOM_STAT(des_, spDefenseIV, spDefenseEV, STAT_SPDEF, MON_DATA_SPDEF)

        if (species == SPECIES_SHEDINJA)
        {
            if (currentHP != 0 || oldMaxHP == 0)
                currentHP = 1;
            else
                return;
        }
        else
        {
            if (currentHP == 0 && oldMaxHP == 0)
                currentHP = newMaxHP;
            else if (currentHP != 0)
            {
                if (newMaxHP > oldMaxHP)
                    currentHP += newMaxHP - oldMaxHP;
                if (currentHP <= 0)
                    currentHP = 1;
                if (currentHP > newMaxHP)
                    currentHP = newMaxHP;
            }
            else
                return;
        
        }

        SetMonData(mon, MON_DATA_HP, &currentHP);
        return;
    }

    if (species == SPECIES_SHEDINJA)
    {
        newMaxHP = 1;
    }
    else
    {
        s32 n = 2 * gSpeciesInfo[species].baseHP + hpIV;
        newMaxHP = (((n + hpEV / 4) * level) / 100) + level + 10;
    }

    gBattleScripting.levelUpHP = newMaxHP - oldMaxHP;
    if (gBattleScripting.levelUpHP == 0)
        gBattleScripting.levelUpHP = 1;

    SetMonData(mon, MON_DATA_MAX_HP, &newMaxHP);

    CALC_STAT(baseAttack, attackIV, attackEV, STAT_ATK, MON_DATA_ATK)
    CALC_STAT(baseDefense, defenseIV, defenseEV, STAT_DEF, MON_DATA_DEF)
    CALC_STAT(baseSpeed, speedIV, speedEV, STAT_SPEED, MON_DATA_SPEED)
    CALC_STAT(baseSpAttack, spAttackIV, spAttackEV, STAT_SPATK, MON_DATA_SPATK)
    CALC_STAT(baseSpDefense, spDefenseIV, spDefenseEV, STAT_SPDEF, MON_DATA_SPDEF)

    if (species == SPECIES_SHEDINJA)
    {
        if (currentHP != 0 || oldMaxHP == 0)
            currentHP = 1;
        else
            return;
    }
    else
    {
        if (currentHP == 0 && oldMaxHP == 0)
            currentHP = newMaxHP;
        else if (currentHP != 0)
        {
            if (newMaxHP > oldMaxHP)
                currentHP += newMaxHP - oldMaxHP;
            if (currentHP <= 0)
                currentHP = 1;
            if (currentHP > newMaxHP)
                currentHP = newMaxHP;
        }
        else
            return;
    }

    SetMonData(mon, MON_DATA_HP, &currentHP);
}

void BoxMonToMon(const struct BoxPokemon *src, struct Pokemon *dest)
{
    u32 value = 0;
    dest->box = *src;
    dest->status = GetBoxMonData(&dest->box, MON_DATA_STATUS, NULL);
    dest->hp = 0;
    dest->maxHP = 0;
    value = MAIL_NONE;
    SetMonData(dest, MON_DATA_MAIL, &value);
    value = GetBoxMonData(&dest->box, MON_DATA_HP_LOST);
    CalculateMonStats(dest);
    value = GetMonData(dest, MON_DATA_MAX_HP) - value;
    SetMonData(dest, MON_DATA_HP, &value);
}

u8 GetLevelFromMonExp(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = GetMonData(mon, MON_DATA_EXP, NULL);
    s32 level = 1;

    while (level <= MAX_LEVEL && gExperienceTables[gSpeciesInfo[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u8 GetLevelFromBoxMonExp(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    u32 exp = GetBoxMonData(boxMon, MON_DATA_EXP, NULL);
    s32 level = 1;

    while (level <= MAX_LEVEL && gExperienceTables[gSpeciesInfo[species].growthRate][level] <= exp)
        level++;

    return level - 1;
}

u16 GiveMoveToMon(struct Pokemon *mon, u16 move)
{
    return GiveMoveToBoxMon(&mon->box, move);
}

u16 GiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 existingMove = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, NULL);
        if (existingMove == MOVE_NONE)
        {
            SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &move);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &gMovesInfo[move].pp);
            return move;
        }
        if (existingMove == move)
            return MON_ALREADY_KNOWS_MOVE;
    }
    return MON_HAS_MAX_MOVES;
}

u16 GiveMoveToBattleMon(struct BattlePokemon *mon, u16 move)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (mon->moves[i] == MOVE_NONE)
        {
            mon->moves[i] = move;
            mon->pp[i] = gMovesInfo[move].pp;
            return move;
        }
    }

    return MON_HAS_MAX_MOVES;
}

void SetMonMoveSlot(struct Pokemon *mon, u16 move, u8 slot)
{
    SetMonData(mon, MON_DATA_MOVE1 + slot, &move);
    SetMonData(mon, MON_DATA_PP1 + slot, &gMovesInfo[move].pp);
}

static void SetMonMoveSlot_KeepPP(struct Pokemon *mon, u16 move, u8 slot)
{
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    u8 currPP = GetMonData(mon, MON_DATA_PP1 + slot, NULL);
    u8 newPP = CalculatePPWithBonus(move, ppBonuses, slot);
    u16 finalPP = min(currPP, newPP);

    SetMonData(mon, MON_DATA_MOVE1 + slot, &move);
    SetMonData(mon, MON_DATA_PP1 + slot, &finalPP);
}

void SetBattleMonMoveSlot(struct BattlePokemon *mon, u16 move, u8 slot)
{
    mon->moves[slot] = move;
    mon->pp[slot] = gMovesInfo[move].pp;
}

void GiveMonInitialMoveset(struct Pokemon *mon)
{
    GiveBoxMonInitialMoveset(&mon->box);
}

void GiveBoxMonInitialMovesetRandom(struct BoxPokemon *boxMon)
{
    s32 j;
    u16 move = 0;
    bool8 firstMoveGiven = TRUE;

    for (j = 0; j < MAX_MON_MOVES; j++)
    {
        move = sRandomValidMoves[RandomModulo(move, RANDOM_MOVES_COUNT)];
        
        if (firstMoveGiven)
        {
            u16 i;
            for (i=0; i<1000; i++)
            {
                if (gMovesInfo[move].power <= 1)
                {
                    move = sRandomValidMoves[RandomModulo(move, RANDOM_MOVES_COUNT)];
                }
                else
                    break;
            }
        }
        if (firstMoveGiven)
            firstMoveGiven = FALSE;
        GiveMoveToBoxMon(boxMon, move);
    }
}

void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    s32 level = GetLevelFromBoxMonExp(boxMon);
    s32 i;
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    if(FlagGet(FLAG_RANDOM_MODE))
    {
        GiveBoxMonInitialMovesetRandom(boxMon);
        return;
    }
    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (learnset[i].level > level)
            break;
        if (learnset[i].level == 0)
            continue;
        if (GiveMoveToBoxMon(boxMon, learnset[i].move) == MON_HAS_MAX_MOVES)
            DeleteFirstMoveAndGiveMoveToBoxMon(boxMon, learnset[i].move);
    }
}

void GiveBoxMonInitialMoveset_Fast(struct BoxPokemon *boxMon) //Credit: AsparagusEduardo
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    s32 level = GetLevelFromBoxMonExp(boxMon);
    s32 i;
    u16 moves[MAX_MON_MOVES] = {MOVE_NONE};
    u8 addedMoves = 0;
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        s32 j;
        bool32 alreadyKnown = FALSE;

        if (learnset[i].level > level)
            break;
        if (learnset[i].level == 0)
            continue;

        for (j = 0; j < addedMoves; j++)
        {
            if (moves[j] == learnset[i].move)
            {
                alreadyKnown = TRUE;
                break;
            }
        }

        if (!alreadyKnown)
        {
            if (addedMoves < MAX_MON_MOVES)
            {
                moves[addedMoves] = learnset[i].move;
                addedMoves++;
            }
            else
            {
                for (j = 0; j < MAX_MON_MOVES - 1; j++)
                    moves[j] = moves[j + 1];
                moves[MAX_MON_MOVES - 1] = learnset[i].move;
            }
        }
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &moves[i]);
        SetBoxMonData(boxMon, MON_DATA_PP1 + i, &gMovesInfo[moves[i]].pp);
    }
}

void GiveMonInitialMoveset_Fast(struct Pokemon *mon)
{
    GiveBoxMonInitialMoveset_Fast(&mon->box);
}

u16 MonTryLearningNewMove(struct Pokemon *mon, bool8 firstMove)
{
    u32 retVal = MOVE_NONE;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    // since you can learn more than one move per level
    // the game needs to know whether you decided to
    // learn it or keep the old set to avoid asking
    // you to learn the same move over and over again
    if (firstMove)
    {
        sLearningMoveTableID = 0;

        while (learnset[sLearningMoveTableID].level != level)
        {
            sLearningMoveTableID++;
            if (learnset[sLearningMoveTableID].move == LEVEL_UP_MOVE_END)
                return MOVE_NONE;
        }
    }

    if (learnset[sLearningMoveTableID].level == level)
    {
        if(FlagGet(FLAG_RANDOM_MODE))
            gMoveToLearn = sRandomValidMoves[Random() % RANDOM_MOVES_COUNT];
        else
            gMoveToLearn = learnset[sLearningMoveTableID].move;
        sLearningMoveTableID++;
        retVal = GiveMoveToMon(mon, gMoveToLearn);
    }

    return retVal;
}

void DeleteFirstMoveAndGiveMoveToMon(struct Pokemon *mon, u16 move)
{
    s32 i;
    u16 moves[MAX_MON_MOVES];
    u8 pp[MAX_MON_MOVES];
    u8 ppBonuses;

    for (i = 0; i < MAX_MON_MOVES - 1; i++)
    {
        moves[i] = GetMonData(mon, MON_DATA_MOVE2 + i, NULL);
        pp[i] = GetMonData(mon, MON_DATA_PP2 + i, NULL);
    }

    ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses >>= 2;
    moves[MAX_MON_MOVES - 1] = move;
    pp[MAX_MON_MOVES - 1] = gMovesInfo[move].pp;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        SetMonData(mon, MON_DATA_MOVE1 + i, &moves[i]);
        SetMonData(mon, MON_DATA_PP1 + i, &pp[i]);
    }

    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

void DeleteFirstMoveAndGiveMoveToBoxMon(struct BoxPokemon *boxMon, u16 move)
{
    s32 i;
    u16 moves[MAX_MON_MOVES];
    u8 pp[MAX_MON_MOVES];
    u8 ppBonuses;

    for (i = 0; i < MAX_MON_MOVES - 1; i++)
    {
        moves[i] = GetBoxMonData(boxMon, MON_DATA_MOVE2 + i, NULL);
        pp[i] = GetBoxMonData(boxMon, MON_DATA_PP2 + i, NULL);
    }

    ppBonuses = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses >>= 2;
    moves[MAX_MON_MOVES - 1] = move;
    pp[MAX_MON_MOVES - 1] = gMovesInfo[move].pp;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        SetBoxMonData(boxMon, MON_DATA_MOVE1 + i, &moves[i]);
        SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp[i]);
    }

    SetBoxMonData(boxMon, MON_DATA_PP_BONUSES, &ppBonuses);
}

u8 CountAliveMonsInBattle(u8 caseId, u32 battler)
{
    s32 i;
    u8 retVal = 0;

    switch (caseId)
    {
    case BATTLE_ALIVE_EXCEPT_BATTLER:
        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (i != battler && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    case BATTLE_ALIVE_SIDE:
        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (GetBattlerSide(i) == GetBattlerSide(battler) && !(gAbsentBattlerFlags & gBitTable[i]))
                retVal++;
        }
        break;
    }

    return retVal;
}

u8 GetDefaultMoveTarget(u8 battlerId)
{
    u8 opposing = BATTLE_OPPOSITE(GetBattlerSide(battlerId));

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return GetBattlerAtPosition(opposing);
    if (CountAliveMonsInBattle(BATTLE_ALIVE_EXCEPT_BATTLER, battlerId) > 1)
    {
        u8 position;

        if ((Random() & 1) == 0)
            position = BATTLE_PARTNER(opposing);
        else
            position = opposing;

        return GetBattlerAtPosition(position);
    }
    else
    {
        if ((gAbsentBattlerFlags & gBitTable[opposing]))
            return GetBattlerAtPosition(BATTLE_PARTNER(opposing));
        else
            return GetBattlerAtPosition(opposing);
    }
}

u8 GetMonGender(struct Pokemon *mon)
{
    return GetBoxMonGender(&mon->box);
}

u8 GetBoxMonGender(struct BoxPokemon *boxMon)
{
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    u32 personality = GetBoxMonData(boxMon, MON_DATA_PERSONALITY, NULL);

    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gSpeciesInfo[species].genderRatio;
    }

    if (gSpeciesInfo[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

u8 GetGenderFromSpeciesAndPersonality(u16 species, u32 personality)
{
    switch (gSpeciesInfo[species].genderRatio)
    {
    case MON_MALE:
    case MON_FEMALE:
    case MON_GENDERLESS:
        return gSpeciesInfo[species].genderRatio;
    }

    if (gSpeciesInfo[species].genderRatio > (personality & 0xFF))
        return MON_FEMALE;
    else
        return MON_MALE;
}

bool32 IsPersonalityFemale(u16 species, u32 personality)
{
    return GetGenderFromSpeciesAndPersonality(species, personality) == MON_FEMALE;
}

u32 GetUnownSpeciesId(u32 personality)
{
    u16 unownLetter = GetUnownLetterByPersonality(personality);

    if (unownLetter == 0)
        return SPECIES_UNOWN;
    return unownLetter + SPECIES_UNOWN_B - 1;
}

void SetMultiuseSpriteTemplateToPokemon(u16 speciesTag, u8 battlerPosition)
{
    if (gMonSpritesGfxPtr != NULL)
        gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
    else if (sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_A])
        gMultiuseSpriteTemplate = sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_A]->templates[battlerPosition];
    else if (sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_B])
        gMultiuseSpriteTemplate = sMonSpritesGfxManagers[MON_SPR_GFX_MANAGER_B]->templates[battlerPosition];
    else
        gMultiuseSpriteTemplate = gBattlerSpriteTemplates[battlerPosition];

    gMultiuseSpriteTemplate.paletteTag = speciesTag;
    if (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_PLAYER_RIGHT)
        gMultiuseSpriteTemplate.anims = gAnims_MonPic;
    else
    {
        if (speciesTag > SPECIES_SHINY_TAG)
            speciesTag = speciesTag - SPECIES_SHINY_TAG;

        speciesTag = SanitizeSpeciesId(speciesTag);
        if (gSpeciesInfo[speciesTag].frontAnimFrames != NULL)
            gMultiuseSpriteTemplate.anims = gSpeciesInfo[speciesTag].frontAnimFrames;
        else
            gMultiuseSpriteTemplate.anims = gSpeciesInfo[SPECIES_NONE].frontAnimFrames;
    }
}

void SetMultiuseSpriteTemplateToTrainerBack(u16 trainerPicId, u8 battlerPosition)
{
    gMultiuseSpriteTemplate.paletteTag = trainerPicId;
    if (battlerPosition == B_POSITION_PLAYER_LEFT || battlerPosition == B_POSITION_PLAYER_RIGHT)
    {
        gMultiuseSpriteTemplate = sTrainerBackSpriteTemplates[trainerPicId];
        gMultiuseSpriteTemplate.anims = gTrainerBacksprites[trainerPicId].animation;
    }
    else
    {
        if (gMonSpritesGfxPtr != NULL)
            gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
        else
            gMultiuseSpriteTemplate = gBattlerSpriteTemplates[battlerPosition];
        gMultiuseSpriteTemplate.anims = sAnims_Trainer;
    }
}

void SetMultiuseSpriteTemplateToTrainerFront(u16 trainerPicId, u8 battlerPosition)
{
    if (gMonSpritesGfxPtr != NULL)
        gMultiuseSpriteTemplate = gMonSpritesGfxPtr->templates[battlerPosition];
    else
        gMultiuseSpriteTemplate = gBattlerSpriteTemplates[battlerPosition];

    gMultiuseSpriteTemplate.paletteTag = trainerPicId;
    gMultiuseSpriteTemplate.anims = sAnims_Trainer;
}

static void EncryptBoxMon(struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(boxMon->secure.raw); i++)
    {
        boxMon->secure.raw[i] ^= boxMon->personality;
        boxMon->secure.raw[i] ^= boxMon->otId;
    }
}

static void DecryptBoxMon(struct BoxPokemon *boxMon)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(boxMon->secure.raw); i++)
    {
        boxMon->secure.raw[i] ^= boxMon->otId;
        boxMon->secure.raw[i] ^= boxMon->personality;
    }
}

#define SUBSTRUCT_CASE(n, v1, v2, v3, v4)                               \
case n:                                                                 \
    {                                                                   \
                                                                        \
        switch (substructType)                                          \
        {                                                               \
        case 0:                                                         \
            substruct = &boxMon->secure.substructs[v1];                          \
            break;                                                      \
        case 1:                                                         \
            substruct = &boxMon->secure.substructs[v2];                          \
            break;                                                      \
        case 2:                                                         \
            substruct = &boxMon->secure.substructs[v3];                          \
            break;                                                      \
        case 3:                                                         \
            substruct = &boxMon->secure.substructs[v4];                          \
            break;                                                      \
        }                                                               \
        break;                                                          \
    }                                                                   \


static union PokemonSubstruct *GetSubstruct(struct BoxPokemon *boxMon, u32 personality, u8 substructType)
{
    union PokemonSubstruct *substruct = NULL;

    switch (personality % 24)
    {
        SUBSTRUCT_CASE( 0,0,1,2,3)
        SUBSTRUCT_CASE( 1,0,1,3,2)
        SUBSTRUCT_CASE( 2,0,2,1,3)
        SUBSTRUCT_CASE( 3,0,3,1,2)
        SUBSTRUCT_CASE( 4,0,2,3,1)
        SUBSTRUCT_CASE( 5,0,3,2,1)
        SUBSTRUCT_CASE( 6,1,0,2,3)
        SUBSTRUCT_CASE( 7,1,0,3,2)
        SUBSTRUCT_CASE( 8,2,0,1,3)
        SUBSTRUCT_CASE( 9,3,0,1,2)
        SUBSTRUCT_CASE(10,2,0,3,1)
        SUBSTRUCT_CASE(11,3,0,2,1)
        SUBSTRUCT_CASE(12,1,2,0,3)
        SUBSTRUCT_CASE(13,1,3,0,2)
        SUBSTRUCT_CASE(14,2,1,0,3)
        SUBSTRUCT_CASE(15,3,1,0,2)
        SUBSTRUCT_CASE(16,2,3,0,1)
        SUBSTRUCT_CASE(17,3,2,0,1)
        SUBSTRUCT_CASE(18,1,2,3,0)
        SUBSTRUCT_CASE(19,1,3,2,0)
        SUBSTRUCT_CASE(20,2,1,3,0)
        SUBSTRUCT_CASE(21,3,1,2,0)
        SUBSTRUCT_CASE(22,2,3,1,0)
        SUBSTRUCT_CASE(23,3,2,1,0)
    }

    return substruct;
}

/* GameFreak called GetMonData with either 2 or 3 arguments, for type
 * safety we have a GetMonData macro (in include/pokemon.h) which
 * dispatches to either GetMonData2 or GetMonData3 based on the number
 * of arguments. */
u32 GetMonData3(struct Pokemon *mon, s32 field, u8 *data)
{
    u32 ret;

    switch (field)
    {
    case MON_DATA_STATUS:
        ret = mon->status;
        break;
    case MON_DATA_LEVEL:
        ret = mon->level;
        break;
    case MON_DATA_HP:
        ret = mon->hp;
        break;
    case MON_DATA_MAX_HP:
        ret = mon->maxHP;
        break;
    case MON_DATA_ATK:
        ret = mon->attack;
        break;
    case MON_DATA_DEF:
        ret = mon->defense;
        break;
    case MON_DATA_SPEED:
        ret = mon->speed;
        break;
    case MON_DATA_SPATK:
        ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF:
        ret = mon->spDefense;
        break;
    case MON_DATA_ATK2:
        ret = mon->attack;
        break;
    case MON_DATA_DEF2:
        ret = mon->defense;
        break;
    case MON_DATA_SPEED2:
        ret = mon->speed;
        break;
    case MON_DATA_SPATK2:
        ret = mon->spAttack;
        break;
    case MON_DATA_SPDEF2:
        ret = mon->spDefense;
        break;
    case MON_DATA_MAIL:
        ret = mon->mail;
        break;
    default:
        ret = GetBoxMonData(&mon->box, field, data);
        break;
    }
    return ret;
}

u32 GetMonData2(struct Pokemon *mon, s32 field)
{
    return GetMonData3(mon, field, NULL);
}

struct EvolutionTrackerBitfield
{
    u16 a: 5;
    u16 b: 5;
    u16 unused: 6;
};

union EvolutionTracker
{
    u16 value;
    struct EvolutionTrackerBitfield asField;
};

/* GameFreak called GetBoxMonData with either 2 or 3 arguments, for type
 * safety we have a GetBoxMonData macro (in include/pokemon.h) which
 * dispatches to either GetBoxMonData2 or GetBoxMonData3 based on the
 * number of arguments. */
u32 GetBoxMonData3(struct BoxPokemon *boxMon, s32 field, u8 *data)
{
    s32 i;
    u32 retVal = 0;
    struct PokemonSubstruct0 *substruct0 = NULL;
    struct PokemonSubstruct1 *substruct1 = NULL;
    struct PokemonSubstruct2 *substruct2 = NULL;
    struct PokemonSubstruct3 *substruct3 = NULL;
    union EvolutionTracker evoTracker;

    // Any field greater than MON_DATA_ENCRYPT_SEPARATOR is encrypted and must be treated as such
    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        substruct0 = &(GetSubstruct(boxMon, boxMon->personality, 0)->type0);
        substruct1 = &(GetSubstruct(boxMon, boxMon->personality, 1)->type1);
        substruct2 = &(GetSubstruct(boxMon, boxMon->personality, 2)->type2);
        substruct3 = &(GetSubstruct(boxMon, boxMon->personality, 3)->type3);

        DecryptBoxMon(boxMon);

        if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum)
        {
            boxMon->isBadEgg = TRUE;
            boxMon->isEgg = TRUE;
            substruct3->isEgg = TRUE;
        }

        switch (field)
        {
        case MON_DATA_NICKNAME:
        case MON_DATA_NICKNAME10:
        {
            if (boxMon->isBadEgg)
            {
                for (retVal = 0;
                    retVal < POKEMON_NAME_LENGTH && gText_BadEgg[retVal] != EOS;
                    data[retVal] = gText_BadEgg[retVal], retVal++) {}

                data[retVal] = EOS;
            }
            else if (boxMon->isEgg)
            {
                StringCopy(data, gText_EggNickname);
                retVal = StringLength(data);
            }
            else if (boxMon->language == LANGUAGE_JAPANESE)
            {
                data[0] = EXT_CTRL_CODE_BEGIN;
                data[1] = EXT_CTRL_CODE_JPN;

                for (retVal = 2, i = 0;
                    i < 5 && boxMon->nickname[i] != EOS;
                    data[retVal] = boxMon->nickname[i], retVal++, i++) {}

                data[retVal++] = EXT_CTRL_CODE_BEGIN;
                data[retVal++] = EXT_CTRL_CODE_ENG;
                data[retVal] = EOS;
            }
            else
            {
                retVal = 0;
                while (retVal < min(sizeof(boxMon->nickname), POKEMON_NAME_LENGTH))
                {
                    data[retVal] = boxMon->nickname[retVal];
                    retVal++;
                }

                // Vanilla Pokémon have 0s in nickname11 and nickname12
                // so if both are 0 we assume that this is a vanilla
                // Pokémon and replace them with EOS. This means that
                // two CHAR_SPACE at the end of a nickname are trimmed.
                if (field != MON_DATA_NICKNAME10 && POKEMON_NAME_LENGTH >= 12)
                {
                    if (substruct0->nickname11 == 0 && substruct0->nickname12 == 0)
                    {
                        data[retVal++] = EOS;
                        data[retVal++] = EOS;
                    }
                    else
                    {
                        data[retVal++] = substruct0->nickname11;
                        data[retVal++] = substruct0->nickname12;
                    }
                }
                else if (POKEMON_NAME_LENGTH >= 11)
                {
                    if (substruct0->nickname11 == 0)
                    {
                        data[retVal++] = EOS;
                    }
                    else
                    {
                        data[retVal++] = substruct0->nickname11;
                    }
                }

                data[retVal] = EOS;
            }
            break;
        }
        case MON_DATA_SPECIES:
            retVal = boxMon->isBadEgg ? SPECIES_EGG : substruct0->species;
            break;
        case MON_DATA_HELD_ITEM:
            retVal = substruct0->heldItem;
            break;
        case MON_DATA_EXP:
            retVal = substruct0->experience;
            break;
        case MON_DATA_PP_BONUSES:
            retVal = substruct0->ppBonuses;
            break;
        case MON_DATA_FRIENDSHIP:
            retVal = substruct0->friendship;
            break;
        case MON_DATA_MOVE1:
            retVal = substruct1->move1;
            break;
        case MON_DATA_MOVE2:
            retVal = substruct1->move2;
            break;
        case MON_DATA_MOVE3:
            retVal = substruct1->move3;
            break;
        case MON_DATA_MOVE4:
            retVal = substruct1->move4;
            break;
        case MON_DATA_PP1:
            retVal = substruct1->pp1;
            break;
        case MON_DATA_PP2:
            retVal = substruct1->pp2;
            break;
        case MON_DATA_PP3:
            retVal = substruct1->pp3;
            break;
        case MON_DATA_PP4:
            retVal = substruct1->pp4;
            break;
        case MON_DATA_HP_EV:
            retVal = substruct2->hpEV;
            break;
        case MON_DATA_ATK_EV:
            retVal = substruct2->attackEV;
            break;
        case MON_DATA_DEF_EV:
            retVal = substruct2->defenseEV;
            break;
        case MON_DATA_SPEED_EV:
            retVal = substruct2->speedEV;
            break;
        case MON_DATA_SPATK_EV:
            retVal = substruct2->spAttackEV;
            break;
        case MON_DATA_SPDEF_EV:
            retVal = substruct2->spDefenseEV;
            break;
        case MON_DATA_COOL:
            retVal = substruct2->cool;
            break;
        case MON_DATA_BEAUTY:
            retVal = substruct2->beauty;
            break;
        case MON_DATA_CUTE:
            retVal = substruct2->cute;
            break;
        case MON_DATA_SMART:
            retVal = substruct2->smart;
            break;
        case MON_DATA_TOUGH:
            retVal = substruct2->tough;
            break;
        case MON_DATA_SHEEN:
            retVal = substruct2->sheen;
            break;
        case MON_DATA_POKERUS:
            retVal = substruct3->pokerus;
            break;
        case MON_DATA_MET_LOCATION:
            retVal = substruct3->metLocation;
            break;
        case MON_DATA_MET_LEVEL:
            retVal = substruct3->metLevel;
            break;
        case MON_DATA_MET_GAME:
            retVal = substruct3->metGame;
            break;
        case MON_DATA_POKEBALL:
            retVal = substruct0->pokeball;
            break;
        case MON_DATA_OT_GENDER:
            retVal = substruct3->otGender;
            break;
        case MON_DATA_HP_IV:
            retVal = substruct3->hpIV;
            break;
        case MON_DATA_ATK_IV:
            retVal = substruct3->attackIV;
            break;
        case MON_DATA_DEF_IV:
            retVal = substruct3->defenseIV;
            break;
        case MON_DATA_SPEED_IV:
            retVal = substruct3->speedIV;
            break;
        case MON_DATA_SPATK_IV:
            retVal = substruct3->spAttackIV;
            break;
        case MON_DATA_SPDEF_IV:
            retVal = substruct3->spDefenseIV;
            break;
        case MON_DATA_IS_EGG:
            retVal = substruct3->isEgg;
            break;
        case MON_DATA_ABILITY_NUM:
            retVal = substruct3->abilityNum;
            break;
        case MON_DATA_COOL_RIBBON:
            retVal = substruct3->coolRibbon;
            break;
        case MON_DATA_BEAUTY_RIBBON:
            retVal = substruct3->beautyRibbon;
            break;
        case MON_DATA_CUTE_RIBBON:
            retVal = substruct3->cuteRibbon;
            break;
        case MON_DATA_SMART_RIBBON:
            retVal = substruct3->smartRibbon;
            break;
        case MON_DATA_TOUGH_RIBBON:
            retVal = substruct3->toughRibbon;
            break;
        case MON_DATA_CHAMPION_RIBBON:
            retVal = substruct3->championRibbon;
            break;
        case MON_DATA_WINNING_RIBBON:
            retVal = substruct3->winningRibbon;
            break;
        case MON_DATA_VICTORY_RIBBON:
            retVal = substruct3->victoryRibbon;
            break;
        case MON_DATA_ARTIST_RIBBON:
            retVal = substruct3->artistRibbon;
            break;
        case MON_DATA_EFFORT_RIBBON:
            retVal = substruct3->effortRibbon;
            break;
        case MON_DATA_MARINE_RIBBON:
            retVal = substruct3->marineRibbon;
            break;
        case MON_DATA_LAND_RIBBON:
            retVal = substruct3->landRibbon;
            break;
        case MON_DATA_SKY_RIBBON:
            retVal = substruct3->skyRibbon;
            break;
        case MON_DATA_COUNTRY_RIBBON:
            retVal = substruct3->countryRibbon;
            break;
        case MON_DATA_NATIONAL_RIBBON:
            retVal = substruct3->nationalRibbon;
            break;
        case MON_DATA_EARTH_RIBBON:
            retVal = substruct3->earthRibbon;
            break;
        case MON_DATA_WORLD_RIBBON:
            retVal = substruct3->worldRibbon;
            break;
        case MON_DATA_MODERN_FATEFUL_ENCOUNTER:
            retVal = substruct3->modernFatefulEncounter;
            break;
        case MON_DATA_SPECIES_OR_EGG:
            retVal = substruct0->species;
            if (substruct0->species && (substruct3->isEgg || boxMon->isBadEgg))
                retVal = SPECIES_EGG;
            break;
        case MON_DATA_IVS:
            retVal = substruct3->hpIV
                    | (substruct3->attackIV << 5)
                    | (substruct3->defenseIV << 10)
                    | (substruct3->speedIV << 15)
                    | (substruct3->spAttackIV << 20)
                    | (substruct3->spDefenseIV << 25);
            break;
        case MON_DATA_KNOWN_MOVES:
            if (substruct0->species && !substruct3->isEgg)
            {
                u16 *moves = (u16 *)data;
                s32 i = 0;

                while (moves[i] != MOVES_COUNT)
                {
                    u16 move = moves[i];
                    if (substruct1->move1 == move
                        || substruct1->move2 == move
                        || substruct1->move3 == move
                        || substruct1->move4 == move)
                        retVal |= gBitTable[i];
                    i++;
                }
            }
            break;
        case MON_DATA_RIBBON_COUNT:
            retVal = 0;
            if (substruct0->species && !substruct3->isEgg)
            {
                retVal += substruct3->coolRibbon;
                retVal += substruct3->beautyRibbon;
                retVal += substruct3->cuteRibbon;
                retVal += substruct3->smartRibbon;
                retVal += substruct3->toughRibbon;
                retVal += substruct3->championRibbon;
                retVal += substruct3->winningRibbon;
                retVal += substruct3->victoryRibbon;
                retVal += substruct3->artistRibbon;
                retVal += substruct3->effortRibbon;
                retVal += substruct3->marineRibbon;
                retVal += substruct3->landRibbon;
                retVal += substruct3->skyRibbon;
                retVal += substruct3->countryRibbon;
                retVal += substruct3->nationalRibbon;
                retVal += substruct3->earthRibbon;
                retVal += substruct3->worldRibbon;
            }
            break;
        case MON_DATA_RIBBONS:
            retVal = 0;
            if (substruct0->species && !substruct3->isEgg)
            {
                retVal = substruct3->championRibbon
                    | (substruct3->coolRibbon << 1)
                    | (substruct3->beautyRibbon << 4)
                    | (substruct3->cuteRibbon << 7)
                    | (substruct3->smartRibbon << 10)
                    | (substruct3->toughRibbon << 13)
                    | (substruct3->winningRibbon << 16)
                    | (substruct3->victoryRibbon << 17)
                    | (substruct3->artistRibbon << 18)
                    | (substruct3->effortRibbon << 19)
                    | (substruct3->marineRibbon << 20)
                    | (substruct3->landRibbon << 21)
                    | (substruct3->skyRibbon << 22)
                    | (substruct3->countryRibbon << 23)
                    | (substruct3->nationalRibbon << 24)
                    | (substruct3->earthRibbon << 25)
                    | (substruct3->worldRibbon << 26);
            }
            break;
        case MON_DATA_HYPER_TRAINED_HP:
            retVal = substruct1->hyperTrainedHP;
            break;
        case MON_DATA_HYPER_TRAINED_ATK:
            retVal = substruct1->hyperTrainedAttack;
            break;
        case MON_DATA_HYPER_TRAINED_DEF:
            retVal = substruct1->hyperTrainedDefense;
            break;
        case MON_DATA_HYPER_TRAINED_SPEED:
            retVal = substruct1->hyperTrainedSpeed;
            break;
        case MON_DATA_HYPER_TRAINED_SPATK:
            retVal = substruct1->hyperTrainedSpAttack;
            break;
        case MON_DATA_HYPER_TRAINED_SPDEF:
            retVal = substruct1->hyperTrainedSpDefense;
            break;
        case MON_DATA_IS_SHADOW:
            retVal = substruct3->isShadow;
            break;
        case MON_DATA_DYNAMAX_LEVEL:
            retVal = substruct3->dynamaxLevel;
            break;
        case MON_DATA_GIGANTAMAX_FACTOR:
            retVal = substruct3->gigantamaxFactor;
            break;
        case MON_DATA_TERA_TYPE:
            //if (gSpeciesInfo[substruct0->species].forceTeraType)
            //{
            //    retVal = gSpeciesInfo[substruct0->species].forceTeraType;
            //}
            //else if (substruct0->teraType == TYPE_NONE) // Tera Type hasn't been modified so we can just use the personality
            //{
            //    const u8 *types = gSpeciesInfo[substruct0->species].types;
            //    retVal = (boxMon->personality & 0x1) == 0 ? types[0] : types[1];
            //}
            //else
            //{
            //    retVal = substruct0->teraType;
            //}
            retVal = substruct0->teraType == TYPE_NONE;
            break;
        case MON_DATA_EVOLUTION_TRACKER:
            evoTracker.asField.a = substruct1->evolutionTracker1;
            evoTracker.asField.b = substruct1->evolutionTracker2;
            evoTracker.asField.unused = 0;
            retVal = evoTracker.value;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (field)
        {
        case MON_DATA_STATUS:
            retVal = UncompressStatus(boxMon->compressedStatus);
            break;
        case MON_DATA_HP_LOST:
            retVal = boxMon->hpLost;
            break;
        case MON_DATA_PERSONALITY:
            retVal = boxMon->personality;
            break;
        case MON_DATA_OT_ID:
            retVal = boxMon->otId;
            break;
        case MON_DATA_LANGUAGE:
            retVal = boxMon->language;
            break;
        case MON_DATA_SANITY_IS_BAD_EGG:
            retVal = boxMon->isBadEgg;
            break;
        case MON_DATA_SANITY_HAS_SPECIES:
            retVal = boxMon->hasSpecies;
            break;
        case MON_DATA_SANITY_IS_EGG:
            retVal = boxMon->isEgg;
            break;
        case MON_DATA_OT_NAME:
        {
            retVal = 0;

            while (retVal < PLAYER_NAME_LENGTH)
            {
                data[retVal] = boxMon->otName[retVal];
                retVal++;
            }

            data[retVal] = EOS;
            break;
        }
        case MON_DATA_MARKINGS:
            retVal = boxMon->markings;
            break;
        case MON_DATA_CHECKSUM:
            retVal = boxMon->checksum;
            break;
        case MON_DATA_IS_SHINY:
        {
            u32 shinyValue = GET_SHINY_VALUE(boxMon->otId, boxMon->personality);
            retVal = (shinyValue < SHINY_ODDS) ^ boxMon->shinyModifier;
            break;
        }
        case MON_DATA_HIDDEN_NATURE:
        {
            u32 nature = GetNatureFromPersonality(boxMon->personality);
            retVal = nature ^ boxMon->hiddenNatureModifier;
            break;
        }
        case MON_DATA_DAYS_SINCE_FORM_CHANGE:
            retVal = boxMon->daysSinceFormChange;
            break;
        default:
            break;
        }
    }

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
        EncryptBoxMon(boxMon);

    return retVal;
}

u32 GetBoxMonData2(struct BoxPokemon *boxMon, s32 field)
{
    return GetBoxMonData3(boxMon, field, NULL);
}

#define SET8(lhs) (lhs) = *data
#define SET16(lhs) (lhs) = data[0] + (data[1] << 8)
#define SET32(lhs) (lhs) = data[0] + (data[1] << 8) + (data[2] << 16) + (data[3] << 24)

void SetMonData(struct Pokemon *mon, s32 field, const void *dataArg)
{
    const u8 *data = dataArg;

    switch (field)
    {
    case MON_DATA_STATUS:
        SET32(mon->status);
        SetBoxMonData(&mon->box, MON_DATA_STATUS, dataArg);
        break;
    case MON_DATA_LEVEL:
        SET8(mon->level);
        break;
    case MON_DATA_HP:
    {
        u32 hpLost;
        SET16(mon->hp);
        hpLost = mon->maxHP - mon->hp;
        SetBoxMonData(&mon->box, MON_DATA_HP_LOST, &hpLost);
        break;
    }
    case MON_DATA_HP_LOST:
    {
        u32 hpLost;
        SET16(hpLost);
        mon->hp = mon->maxHP - hpLost;
        SetBoxMonData(&mon->box, MON_DATA_HP_LOST, &hpLost);
        break;
    }
    case MON_DATA_MAX_HP:
        SET16(mon->maxHP);
        break;
    case MON_DATA_ATK:
        SET16(mon->attack);
        break;
    case MON_DATA_DEF:
        SET16(mon->defense);
        break;
    case MON_DATA_SPEED:
        SET16(mon->speed);
        break;
    case MON_DATA_SPATK:
        SET16(mon->spAttack);
        break;
    case MON_DATA_SPDEF:
        SET16(mon->spDefense);
        break;
    case MON_DATA_MAIL:
        SET8(mon->mail);
        break;
    case MON_DATA_SPECIES_OR_EGG:
        break;
    default:
        SetBoxMonData(&mon->box, field, data);
        break;
    }
}

void SetBoxMonData(struct BoxPokemon *boxMon, s32 field, const void *dataArg)
{
    const u8 *data = dataArg;

    struct PokemonSubstruct0 *substruct0 = NULL;
    struct PokemonSubstruct1 *substruct1 = NULL;
    struct PokemonSubstruct2 *substruct2 = NULL;
    struct PokemonSubstruct3 *substruct3 = NULL;

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        substruct0 = &(GetSubstruct(boxMon, boxMon->personality, 0)->type0);
        substruct1 = &(GetSubstruct(boxMon, boxMon->personality, 1)->type1);
        substruct2 = &(GetSubstruct(boxMon, boxMon->personality, 2)->type2);
        substruct3 = &(GetSubstruct(boxMon, boxMon->personality, 3)->type3);

        DecryptBoxMon(boxMon);

        if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum)
        {
            boxMon->isBadEgg = TRUE;
            boxMon->isEgg = TRUE;
            substruct3->isEgg = TRUE;
            EncryptBoxMon(boxMon);
            return;
        }

        switch (field)
        {
        case MON_DATA_NICKNAME:
        case MON_DATA_NICKNAME10:
        {
            s32 i;
            for (i = 0; i < min(sizeof(boxMon->nickname), POKEMON_NAME_LENGTH); i++)
                boxMon->nickname[i] = data[i];
            if (field != MON_DATA_NICKNAME10)
            {
                if (POKEMON_NAME_LENGTH >= 11)
                    substruct0->nickname11 = data[10];
                if (POKEMON_NAME_LENGTH >= 12)
                    substruct0->nickname12 = data[11];
            }
            else
            {
                substruct0->nickname11 = EOS;
                substruct0->nickname12 = EOS;
            }
            break;
        }
        case MON_DATA_SPECIES:
        {
            SET16(substruct0->species);
            if (substruct0->species)
                boxMon->hasSpecies = TRUE;
            else
                boxMon->hasSpecies = FALSE;
            break;
        }
        case MON_DATA_HELD_ITEM:
            SET16(substruct0->heldItem);
            break;
        case MON_DATA_EXP:
            SET32(substruct0->experience);
            break;
        case MON_DATA_PP_BONUSES:
            SET8(substruct0->ppBonuses);
            break;
        case MON_DATA_FRIENDSHIP:
            SET8(substruct0->friendship);
            break;
        case MON_DATA_MOVE1:
            SET16(substruct1->move1);
            break;
        case MON_DATA_MOVE2:
            SET16(substruct1->move2);
            break;
        case MON_DATA_MOVE3:
            SET16(substruct1->move3);
            break;
        case MON_DATA_MOVE4:
            SET16(substruct1->move4);
            break;
        case MON_DATA_PP1:
            SET8(substruct1->pp1);
            break;
        case MON_DATA_PP2:
            SET8(substruct1->pp2);
            break;
        case MON_DATA_PP3:
            SET8(substruct1->pp3);
            break;
        case MON_DATA_PP4:
            SET8(substruct1->pp4);
            break;
        case MON_DATA_HP_EV:
            SET8(substruct2->hpEV);
            break;
        case MON_DATA_ATK_EV:
            SET8(substruct2->attackEV);
            break;
        case MON_DATA_DEF_EV:
            SET8(substruct2->defenseEV);
            break;
        case MON_DATA_SPEED_EV:
            SET8(substruct2->speedEV);
            break;
        case MON_DATA_SPATK_EV:
            SET8(substruct2->spAttackEV);
            break;
        case MON_DATA_SPDEF_EV:
            SET8(substruct2->spDefenseEV);
            break;
        case MON_DATA_COOL:
            SET8(substruct2->cool);
            break;
        case MON_DATA_BEAUTY:
            SET8(substruct2->beauty);
            break;
        case MON_DATA_CUTE:
            SET8(substruct2->cute);
            break;
        case MON_DATA_SMART:
            SET8(substruct2->smart);
            break;
        case MON_DATA_TOUGH:
            SET8(substruct2->tough);
            break;
        case MON_DATA_SHEEN:
            SET8(substruct2->sheen);
            break;
        case MON_DATA_POKERUS:
            SET8(substruct3->pokerus);
            break;
        case MON_DATA_MET_LOCATION:
            SET8(substruct3->metLocation);
            break;
        case MON_DATA_MET_LEVEL:
        {
            u8 metLevel = *data;
            substruct3->metLevel = metLevel;
            break;
        }
        case MON_DATA_MET_GAME:
            SET8(substruct3->metGame);
            break;
        case MON_DATA_POKEBALL:
        {
            u8 pokeball = *data;
            substruct0->pokeball = pokeball;
            break;
        }
        case MON_DATA_OT_GENDER:
            SET8(substruct3->otGender);
            break;
        case MON_DATA_HP_IV:
            SET8(substruct3->hpIV);
            break;
        case MON_DATA_ATK_IV:
            SET8(substruct3->attackIV);
            break;
        case MON_DATA_DEF_IV:
            SET8(substruct3->defenseIV);
            break;
        case MON_DATA_SPEED_IV:
            SET8(substruct3->speedIV);
            break;
        case MON_DATA_SPATK_IV:
            SET8(substruct3->spAttackIV);
            break;
        case MON_DATA_SPDEF_IV:
            SET8(substruct3->spDefenseIV);
            break;
        case MON_DATA_IS_EGG:
            SET8(substruct3->isEgg);
            if (substruct3->isEgg)
                boxMon->isEgg = TRUE;
            else
                boxMon->isEgg = FALSE;
            break;
        case MON_DATA_ABILITY_NUM:
            SET8(substruct3->abilityNum);
            break;
        case MON_DATA_COOL_RIBBON:
            SET8(substruct3->coolRibbon);
            break;
        case MON_DATA_BEAUTY_RIBBON:
            SET8(substruct3->beautyRibbon);
            break;
        case MON_DATA_CUTE_RIBBON:
            SET8(substruct3->cuteRibbon);
            break;
        case MON_DATA_SMART_RIBBON:
            SET8(substruct3->smartRibbon);
            break;
        case MON_DATA_TOUGH_RIBBON:
            SET8(substruct3->toughRibbon);
            break;
        case MON_DATA_CHAMPION_RIBBON:
            SET8(substruct3->championRibbon);
            break;
        case MON_DATA_WINNING_RIBBON:
            SET8(substruct3->winningRibbon);
            break;
        case MON_DATA_VICTORY_RIBBON:
            SET8(substruct3->victoryRibbon);
            break;
        case MON_DATA_ARTIST_RIBBON:
            SET8(substruct3->artistRibbon);
            break;
        case MON_DATA_EFFORT_RIBBON:
            SET8(substruct3->effortRibbon);
            break;
        case MON_DATA_MARINE_RIBBON:
            SET8(substruct3->marineRibbon);
            break;
        case MON_DATA_LAND_RIBBON:
            SET8(substruct3->landRibbon);
            break;
        case MON_DATA_SKY_RIBBON:
            SET8(substruct3->skyRibbon);
            break;
        case MON_DATA_COUNTRY_RIBBON:
            SET8(substruct3->countryRibbon);
            break;
        case MON_DATA_NATIONAL_RIBBON:
            SET8(substruct3->nationalRibbon);
            break;
        case MON_DATA_EARTH_RIBBON:
            SET8(substruct3->earthRibbon);
            break;
        case MON_DATA_WORLD_RIBBON:
            SET8(substruct3->worldRibbon);
            break;
        case MON_DATA_MODERN_FATEFUL_ENCOUNTER:
            SET8(substruct3->modernFatefulEncounter);
            break;
        case MON_DATA_IVS:
        {
            u32 ivs = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
            substruct3->hpIV = ivs & MAX_IV_MASK;
            substruct3->attackIV = (ivs >> 5) & MAX_IV_MASK;
            substruct3->defenseIV = (ivs >> 10) & MAX_IV_MASK;
            substruct3->speedIV = (ivs >> 15) & MAX_IV_MASK;
            substruct3->spAttackIV = (ivs >> 20) & MAX_IV_MASK;
            substruct3->spDefenseIV = (ivs >> 25) & MAX_IV_MASK;
            break;
        }
        case MON_DATA_HYPER_TRAINED_HP:
            SET8(substruct1->hyperTrainedHP);
            break;
        case MON_DATA_HYPER_TRAINED_ATK:
            SET8(substruct1->hyperTrainedAttack);
            break;
        case MON_DATA_HYPER_TRAINED_DEF:
            SET8(substruct1->hyperTrainedDefense);
            break;
        case MON_DATA_HYPER_TRAINED_SPEED:
            SET8(substruct1->hyperTrainedSpeed);
            break;
        case MON_DATA_HYPER_TRAINED_SPATK:
            SET8(substruct1->hyperTrainedSpAttack);
            break;
        case MON_DATA_HYPER_TRAINED_SPDEF:
            SET8(substruct1->hyperTrainedSpDefense);
            break;
        case MON_DATA_IS_SHADOW:
            SET8(substruct3->isShadow);
            break;
        case MON_DATA_DYNAMAX_LEVEL:
            SET8(substruct3->dynamaxLevel);
            break;
        case MON_DATA_GIGANTAMAX_FACTOR:
            SET8(substruct3->gigantamaxFactor);
            break;
        case MON_DATA_TERA_TYPE:
        {
            u32 teraType;
            SET8(teraType);
            substruct0->teraType = teraType;
            break;
        }
        case MON_DATA_EVOLUTION_TRACKER:
        {
            union EvolutionTracker evoTracker;
            u32 evoTrackerValue;
            SET32(evoTrackerValue);
            evoTracker.value = evoTrackerValue;
            substruct1->evolutionTracker1 = evoTracker.asField.a;
            substruct1->evolutionTracker2 = evoTracker.asField.b;
            break;
        }
        default:
            break;
        }
    }
    else
    {
        switch (field)
        {
        case MON_DATA_STATUS:
        {
            u32 status;
            SET32(status);
            boxMon->compressedStatus = CompressStatus(status);
            break;
        }
        case MON_DATA_HP_LOST:
            SET16(boxMon->hpLost);
            break;
        case MON_DATA_PERSONALITY:
            SET32(boxMon->personality);
            break;
        case MON_DATA_OT_ID:
            SET32(boxMon->otId);
            break;
        case MON_DATA_LANGUAGE:
            SET8(boxMon->language);
            break;
        case MON_DATA_SANITY_IS_BAD_EGG:
            SET8(boxMon->isBadEgg);
            break;
        case MON_DATA_SANITY_HAS_SPECIES:
            SET8(boxMon->hasSpecies);
            break;
        case MON_DATA_SANITY_IS_EGG:
            SET8(boxMon->isEgg);
            break;
        case MON_DATA_OT_NAME:
        {
            s32 i;
            for (i = 0; i < PLAYER_NAME_LENGTH; i++)
                boxMon->otName[i] = data[i];
            break;
        }
        case MON_DATA_MARKINGS:
            SET8(boxMon->markings);
            break;
        case MON_DATA_CHECKSUM:
            SET16(boxMon->checksum);
            break;
        case MON_DATA_IS_SHINY:
        {
            u32 shinyValue = GET_SHINY_VALUE(boxMon->otId, boxMon->personality);
            bool32 isShiny;
            SET8(isShiny);
            boxMon->shinyModifier = (shinyValue < SHINY_ODDS) ^ isShiny;
            break;
        }
        case MON_DATA_HIDDEN_NATURE:
        {
            u32 nature = GetNatureFromPersonality(boxMon->personality);
            u32 hiddenNature;
            SET8(hiddenNature);
            boxMon->hiddenNatureModifier = nature ^ hiddenNature;
            break;
        }
        case MON_DATA_DAYS_SINCE_FORM_CHANGE:
            SET8(boxMon->daysSinceFormChange);
            break;
        }
    }

    if (field > MON_DATA_ENCRYPT_SEPARATOR)
    {
        boxMon->checksum = CalculateBoxMonChecksum(boxMon);
        EncryptBoxMon(boxMon);
    }
}

void CopyMon(void *dest, void *src, size_t size)
{
    memcpy(dest, src, size);
}

u8 GiveMonToPlayer(struct Pokemon *mon)
{
    s32 i;

    SetMonData(mon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetMonData(mon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);
    SetMonData(mon, MON_DATA_OT_ID, gSaveBlock2Ptr->playerTrainerId);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            break;
    }

    if (i >= PARTY_SIZE)
        return CopyMonToPC(mon);

    CopyMon(&gPlayerParty[i], mon, sizeof(*mon));
    gPlayerPartyCount = i + 1;
    return MON_GIVEN_TO_PARTY;
}

u8 CopyMonToPC(struct Pokemon *mon)
{
    s32 boxNo, boxPos;

    SetPCBoxToSendMon(VarGet(VAR_PC_BOX_TO_SEND_MON));

    boxNo = StorageGetCurrentBox();

    do
    {
        for (boxPos = 0; boxPos < IN_BOX_COUNT; boxPos++)
        {
            struct BoxPokemon* checkingMon = GetBoxedMonPtr(boxNo, boxPos);
            if (GetBoxMonData(checkingMon, MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            {
                MonRestorePP(mon);
                CopyMon(checkingMon, &mon->box, sizeof(mon->box));
                gSpecialVar_MonBoxId = boxNo;
                gSpecialVar_MonBoxPos = boxPos;
                if (GetPCBoxToSendMon() != boxNo)
                    FlagClear(FLAG_SHOWN_BOX_WAS_FULL_MESSAGE);
                VarSet(VAR_PC_BOX_TO_SEND_MON, boxNo);
                return MON_GIVEN_TO_PC;
            }
        }

        boxNo++;
        if (boxNo == TOTAL_BOXES_COUNT)
            boxNo = 0;
    } while (boxNo != StorageGetCurrentBox());

    return MON_CANT_GIVE;
}

u8 CalculatePartyCount(struct Pokemon *party)
{
    u32 partyCount = 0;

    while (partyCount < PARTY_SIZE
        && GetMonData(&party[partyCount], MON_DATA_SPECIES, NULL) != SPECIES_NONE)
    {
        partyCount++;
    }

    return partyCount;
}

u8 CalculatePlayerPartyCount(void)
{
    gPlayerPartyCount = CalculatePartyCount(gPlayerParty);
    return gPlayerPartyCount;
}

u8 CalculateEnemyPartyCount(void)
{
    gEnemyPartyCount = CalculatePartyCount(gEnemyParty);
    return gEnemyPartyCount;
}

u8 GetMonsStateToDoubles(void)
{
    s32 aliveCount = 0;
    s32 i;
    CalculatePlayerPartyCount();

    if (OW_DOUBLE_APPROACH_WITH_ONE_MON)
        return PLAYER_HAS_TWO_USABLE_MONS;

    if (gPlayerPartyCount == 1)
        return gPlayerPartyCount; // PLAYER_HAS_ONE_MON

    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG
         && GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) != 0
         && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_NONE)
            aliveCount++;
    }

    return (aliveCount > 1) ? PLAYER_HAS_TWO_USABLE_MONS : PLAYER_HAS_ONE_USABLE_MON;
}

u8 GetMonsStateToDoubles_2(void)
{
    s32 aliveCount = 0;
    s32 i;

    if (TRUE)
        return PLAYER_HAS_TWO_USABLE_MONS;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG, NULL);
        if (species != SPECIES_EGG && species != SPECIES_NONE
         && GetMonData(&gPlayerParty[i], MON_DATA_HP, NULL) != 0)
            aliveCount++;
    }

    if (aliveCount == 1)
        return PLAYER_HAS_ONE_MON; // may have more than one, but only one is alive

    return (aliveCount > 1) ? PLAYER_HAS_TWO_USABLE_MONS : PLAYER_HAS_ONE_USABLE_MON;
}

u16 GetAbilityBySpecies(u16 species, u8 abilityNum)
{
    int i;
    bool8 reroll;
    int counter = 0;

    //DebugPrintf("GetAbilityBySpecies");

#ifdef PIT_GEN_3_MODE
    //exclude hidden abilities
    if(abilityNum == 2)
        abilityNum = 1;
#endif

    do
    {
        reroll = FALSE;

        //randomize species to determine ability
        if(FlagGet(FLAG_RANDOM_MODE))
        {
            species = GetSpeciesRandomSeeded(species);
            if ((gSpeciesInfo[species].abilities[1] == ABILITY_NONE) && (abilityNum == 1))
                abilityNum = 0;
        }

        if (abilityNum < NUM_ABILITY_SLOTS)
            gLastUsedAbility = gSpeciesInfo[species].abilities[abilityNum];
        else
            gLastUsedAbility = ABILITY_NONE;

        if (abilityNum >= NUM_NORMAL_ABILITY_SLOTS) // if abilityNum is empty hidden ability, look for other hidden abilities
        {
            for (i = NUM_NORMAL_ABILITY_SLOTS; i < NUM_ABILITY_SLOTS && gLastUsedAbility == ABILITY_NONE; i++)
            {
                gLastUsedAbility = gSpeciesInfo[species].abilities[i];
            }
        }

        for (i = 0; i < NUM_ABILITY_SLOTS && gLastUsedAbility == ABILITY_NONE; i++) // look for any non-empty ability
        {
            gLastUsedAbility = gSpeciesInfo[species].abilities[i];
        }

        //check if ability is valid
        if(FlagGet(FLAG_RANDOM_MODE))
        {
            //DebugPrintf("check for invalid abilities");
            for (i=0; i<INVALID_ABILITIES_COUNT; i++)
            {
                if (gLastUsedAbility == sInvalidRandomAbilities[i])
                {
                    //DebugPrintf("reroll Ability: %d", gLastUsedAbility);
                    reroll = TRUE;
                    i = INVALID_ABILITIES_COUNT;
                }
            }
            // infinite loop protection setting a default ability if nothing is found
            if (counter >= 10)
            {
                reroll = FALSE;
                gLastUsedAbility = ABILITY_TECHNICIAN;
            }

            counter++;
        }
    } while (reroll);

    //DebugPrintf("gLastUsedAbility = %d", gLastUsedAbility);
    return gLastUsedAbility;
}

u16 GetMonAbility(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM, NULL);
    return GetAbilityBySpecies(species, abilityNum);
}

void CreateSecretBaseEnemyParty(struct SecretBase *secretBaseRecord)
{
    s32 i, j;

    ZeroEnemyPartyMons();
    *gBattleResources->secretBase = *secretBaseRecord;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (gBattleResources->secretBase->party.species[i])
        {
            CreateMon(&gEnemyParty[i],
                gBattleResources->secretBase->party.species[i],
                gBattleResources->secretBase->party.levels[i],
                15,
                TRUE,
                gBattleResources->secretBase->party.personality[i],
                OT_ID_RANDOM_NO_SHINY,
                0);

            SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleResources->secretBase->party.heldItems[i]);

            for (j = 0; j < NUM_STATS; j++)
                SetMonData(&gEnemyParty[i], MON_DATA_HP_EV + j, &gBattleResources->secretBase->party.EVs[i]);

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                SetMonData(&gEnemyParty[i], MON_DATA_MOVE1 + j, &gBattleResources->secretBase->party.moves[i * MAX_MON_MOVES + j]);
                SetMonData(&gEnemyParty[i], MON_DATA_PP1 + j, &gMovesInfo[gBattleResources->secretBase->party.moves[i * MAX_MON_MOVES + j]].pp);
            }
        }
    }
}

u8 GetSecretBaseTrainerPicIndex(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % NUM_SECRET_BASE_CLASSES];
    return gFacilityClassToPicIndex[facilityClass];
}

u8 GetSecretBaseTrainerClass(void)
{
    u8 facilityClass = sSecretBaseFacilityClasses[gBattleResources->secretBase->gender][gBattleResources->secretBase->trainerId[0] % NUM_SECRET_BASE_CLASSES];
    return gFacilityClassToTrainerClass[facilityClass];
}

bool8 IsPlayerPartyAndPokemonStorageFull(void)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL) == SPECIES_NONE)
            return FALSE;

    return IsPokemonStorageFull();
}

bool8 IsPokemonStorageFull(void)
{
    s32 i, j;

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
        for (j = 0; j < IN_BOX_COUNT; j++)
            if (GetBoxMonDataAt(i, j, MON_DATA_SPECIES) == SPECIES_NONE)
                return FALSE;

    return TRUE;
}

const u8 *GetSpeciesName(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].speciesName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].speciesName;
    return gSpeciesInfo[species].speciesName;
}

const u8 *GetSpeciesCategory(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].categoryName[0] == 0)
        return gSpeciesInfo[SPECIES_NONE].categoryName;
    return gSpeciesInfo[species].categoryName;
}

const u8 *GetSpeciesPokedexDescription(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].description == NULL)
        return gSpeciesInfo[SPECIES_NONE].description;
    return gSpeciesInfo[species].description;
}

u16 GetSpeciesHeight(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].height;
}

u16 GetSpeciesWeight(u16 species)
{
    return gSpeciesInfo[SanitizeSpeciesId(species)].weight;
}

const struct LevelUpMove *GetSpeciesLevelUpLearnset(u16 species)
{
    const struct LevelUpMove *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].levelUpLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].levelUpLearnset;
    return learnset;
}

const u16 *GetSpeciesTeachableLearnset(u16 species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].teachableLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].teachableLearnset;
    return learnset;
}

const u16 *GetSpeciesEggMoves(u16 species)
{
    const u16 *learnset = gSpeciesInfo[SanitizeSpeciesId(species)].eggMoveLearnset;
    if (learnset == NULL)
        return gSpeciesInfo[SPECIES_NONE].eggMoveLearnset;
    return learnset;
}

const struct Evolution *GetSpeciesEvolutions(u16 species)
{
    const struct Evolution *evolutions = gSpeciesInfo[SanitizeSpeciesId(species)].evolutions;
    if (evolutions == NULL)
        return gSpeciesInfo[SPECIES_NONE].evolutions;
    return evolutions;
}

const u16 *GetSpeciesFormTable(u16 species)
{
    const u16 *formTable = gSpeciesInfo[SanitizeSpeciesId(species)].formSpeciesIdTable;
    if (formTable == NULL)
        return gSpeciesInfo[SPECIES_NONE].formSpeciesIdTable;
    return formTable;
}

const struct FormChange *GetSpeciesFormChanges(u16 species)
{
    const struct FormChange *evolutions = gSpeciesInfo[SanitizeSpeciesId(species)].formChangeTable;
    if (evolutions == NULL)
        return gSpeciesInfo[SPECIES_NONE].formChangeTable;
    return evolutions;
}

u8 CalculatePPWithBonus(u16 move, u8 ppBonuses, u8 moveIndex)
{
    u8 basePP = gMovesInfo[move].pp;
    return basePP + ((basePP * 20 * ((gPPUpGetMask[moveIndex] & ppBonuses) >> (2 * moveIndex))) / 100);
}

void RemoveMonPPBonus(struct Pokemon *mon, u8 moveIndex)
{
    u8 ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
    ppBonuses &= gPPUpClearMask[moveIndex];
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);
}

void RemoveBattleMonPPBonus(struct BattlePokemon *mon, u8 moveIndex)
{
    mon->ppBonuses &= gPPUpClearMask[moveIndex];
}

void PokemonToBattleMon(struct Pokemon *src, struct BattlePokemon *dst)
{
    s32 i;
    u8 nickname[POKEMON_NAME_BUFFER_SIZE];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        dst->moves[i] = GetMonData(src, MON_DATA_MOVE1 + i, NULL);
        dst->pp[i] = GetMonData(src, MON_DATA_PP1 + i, NULL);
    }

    dst->species = GetMonData(src, MON_DATA_SPECIES, NULL);
    dst->item = GetMonData(src, MON_DATA_HELD_ITEM, NULL);
    dst->ppBonuses = GetMonData(src, MON_DATA_PP_BONUSES, NULL);
    dst->friendship = GetMonData(src, MON_DATA_FRIENDSHIP, NULL);
    dst->experience = GetMonData(src, MON_DATA_EXP, NULL);
    dst->hpIV = GetMonData(src, MON_DATA_HP_IV, NULL);
    dst->attackIV = GetMonData(src, MON_DATA_ATK_IV, NULL);
    dst->defenseIV = GetMonData(src, MON_DATA_DEF_IV, NULL);
    dst->speedIV = GetMonData(src, MON_DATA_SPEED_IV, NULL);
    dst->spAttackIV = GetMonData(src, MON_DATA_SPATK_IV, NULL);
    dst->spDefenseIV = GetMonData(src, MON_DATA_SPDEF_IV, NULL);
    dst->personality = GetMonData(src, MON_DATA_PERSONALITY, NULL);
    dst->status1 = GetMonData(src, MON_DATA_STATUS, NULL);
    dst->level = GetMonData(src, MON_DATA_LEVEL, NULL);
    dst->hp = GetMonData(src, MON_DATA_HP, NULL);
    dst->maxHP = GetMonData(src, MON_DATA_MAX_HP, NULL);
    dst->attack = GetMonData(src, MON_DATA_ATK, NULL);
    dst->defense = GetMonData(src, MON_DATA_DEF, NULL);
    dst->speed = GetMonData(src, MON_DATA_SPEED, NULL);
    dst->spAttack = GetMonData(src, MON_DATA_SPATK, NULL);
    dst->spDefense = GetMonData(src, MON_DATA_SPDEF, NULL);
    dst->abilityNum = GetMonData(src, MON_DATA_ABILITY_NUM, NULL);
    dst->otId = GetMonData(src, MON_DATA_OT_ID, NULL);
    
    dst->types[0] = GetTypeBySpecies(dst->species, 1);
    dst->types[1] = GetTypeBySpecies(dst->species, 2);
    dst->types[2] = TYPE_MYSTERY;
    dst->isShiny = IsMonShiny(src);
    dst->ability = GetAbilityBySpecies(dst->species, dst->abilityNum);
    GetMonData(src, MON_DATA_NICKNAME, nickname);
    StringCopy_Nickname(dst->nickname, nickname);
    GetMonData(src, MON_DATA_OT_NAME, dst->otName);

    for (i = 0; i < NUM_BATTLE_STATS; i++)
        dst->statStages[i] = DEFAULT_STAT_STAGE;

    dst->status2 = 0;
}

void CopyPartyMonToBattleData(u32 battlerId, u32 partyIndex)
{
    u32 side = GetBattlerSide(battlerId);
    struct Pokemon *party = GetSideParty(side);
    PokemonToBattleMon(&party[partyIndex], &gBattleMons[battlerId]);
    gBattleStruct->hpOnSwitchout[side] = gBattleMons[battlerId].hp;
    UpdateSentPokesToOpponentValue(battlerId);
    ClearTemporarySpeciesSpriteData(battlerId, FALSE);
}

bool8 ExecuteTableBasedItemEffect(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex)
{
    return PokemonUseItemEffects(mon, item, partyIndex, moveIndex, FALSE);
}

#define UPDATE_FRIENDSHIP_FROM_ITEM()                                                                   \
{                                                                                                       \
    if ((retVal == 0 || friendshipOnly) && !ShouldSkipFriendshipChange() && friendshipChange == 0)      \
    {                                                                                                   \
        friendshipChange = itemEffect[itemEffectParam];                                                 \
        friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, NULL);                                        \
        if (friendshipChange > 0 && holdEffect == HOLD_EFFECT_FRIENDSHIP_UP)                            \
            friendship += 150 * friendshipChange / 100;                                                 \
        else                                                                                            \
            friendship += friendshipChange;                                                             \
        if (friendshipChange > 0)                                                                       \
        {                                                                                               \
            if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == ITEM_LUXURY_BALL)                           \
                friendship++;                                                                           \
            if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == GetCurrentRegionMapSectionId())         \
                friendship++;                                                                           \
        }                                                                                               \
        if (friendship < 0)                                                                             \
            friendship = 0;                                                                             \
        if (friendship > MAX_FRIENDSHIP)                                                                \
            friendship = MAX_FRIENDSHIP;                                                                \
        SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);                                              \
        retVal = FALSE;                                                                                 \
    }                                                                                                   \
}

// EXP candies store an index for this table in their holdEffectParam.
const u32 sExpCandyExperienceTable[] = {
    [EXP_100 - 1] = 100,
    [EXP_800 - 1] = 800,
    [EXP_3000 - 1] = 3000,
    [EXP_10000 - 1] = 10000,
    [EXP_30000 - 1] = 30000,
};

// Returns TRUE if the item has no effect on the Pokémon, FALSE otherwise
bool8 PokemonUseItemEffects(struct Pokemon *mon, u16 item, u8 partyIndex, u8 moveIndex, bool8 usedByAI)
{
    u32 dataUnsigned;
    s32 dataSigned, evCap;
    s32 friendship;
    s32 i;
    bool8 retVal = TRUE;
    const u8 *itemEffect;
    u8 itemEffectParam = ITEM_EFFECT_ARG_START;
    u32 temp1, temp2;
    s8 friendshipChange = 0;
    u8 holdEffect;
    u8 battlerId = MAX_BATTLERS_COUNT;
    u32 friendshipOnly = FALSE;
    u16 heldItem;
    u8 effectFlags;
    s8 evChange;
    u16 evCount;

    // Get item hold effect
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, NULL);
    if (heldItem == ITEM_ENIGMA_BERRY_E_READER)
    #if FREE_ENIGMA_BERRY == FALSE
        holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    #else
        holdEffect = 0;
    #endif //FREE_ENIGMA_BERRY
    else
        holdEffect = ItemId_GetHoldEffect(heldItem);

    // Skip using the item if it won't do anything
    if (ItemId_GetEffect(item) == NULL && item != ITEM_ENIGMA_BERRY_E_READER)
        return TRUE;

    // Get item effect
    itemEffect = ItemId_GetEffect(item);

    // Do item effect
    for (i = 0; i < ITEM_EFFECT_ARG_START; i++)
    {
        switch (i)
        {

        // Handle ITEM0 effects (infatuation, Dire Hit, X Attack). ITEM0_SACRED_ASH is handled in party_menu.c
        // Now handled in item battle scripts.
        case 0:
            break;

        // Handle ITEM1 effects (in-battle stat boosting effects)
        // Now handled in item battle scripts.
        case 1:
            break;
        // Formerly used by the item effects of the X Sp. Atk and the X Accuracy
        case 2:
            break;

        // Handle ITEM3 effects (Guard Spec, Rare Candy, cure status)
        case 3:
            // Rare Candy / EXP Candy
            if ((itemEffect[i] & ITEM3_LEVEL_UP)
             && GetMonData(mon, MON_DATA_LEVEL, NULL) != MAX_LEVEL)
            {
                u8 param = ItemId_GetHoldEffectParam(item);
                dataUnsigned = 0;

                if (param == 0) // Rare Candy
                {
                    dataUnsigned = gExperienceTables[gSpeciesInfo[GetMonData(mon, MON_DATA_SPECIES, NULL)].growthRate][GetMonData(mon, MON_DATA_LEVEL, NULL) + 1];
                }
                else if (param - 1 < ARRAY_COUNT(sExpCandyExperienceTable)) // EXP Candies
                {
                    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
                    dataUnsigned = sExpCandyExperienceTable[param - 1] + GetMonData(mon, MON_DATA_EXP, NULL);

                    if (B_RARE_CANDY_CAP && B_EXP_CAP_TYPE == EXP_CAP_HARD)
                    {
                        u32 currentLevelCap = GetCurrentLevelCap();
                        if (dataUnsigned > gExperienceTables[gSpeciesInfo[species].growthRate][currentLevelCap])
                            dataUnsigned = gExperienceTables[gSpeciesInfo[species].growthRate][currentLevelCap];
                    }
                    else if (dataUnsigned > gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL])
                    {
                        dataUnsigned = gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL];
                    }
                }

                if (dataUnsigned != 0) // Failsafe
                {
                    SetMonData(mon, MON_DATA_EXP, &dataUnsigned);
                    CalculateMonStats(mon);
                    retVal = FALSE;
                }
            }

            // Cure status
            if ((itemEffect[i] & ITEM3_SLEEP) && HealStatusConditions(mon, STATUS1_SLEEP, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_POISON) && HealStatusConditions(mon, STATUS1_PSN_ANY | STATUS1_TOXIC_COUNTER, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_BURN) && HealStatusConditions(mon, STATUS1_BURN, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_FREEZE) && HealStatusConditions(mon, STATUS1_FREEZE | STATUS1_FROSTBITE, battlerId) == 0)
                retVal = FALSE;
            if ((itemEffect[i] & ITEM3_PARALYSIS) && HealStatusConditions(mon, STATUS1_PARALYSIS, battlerId) == 0)
                retVal = FALSE;
            break;

        // Handle ITEM4 effects (Change HP/Atk EVs, HP heal, PP heal, PP up, Revive, and evolution stones)
        case 4:
            effectFlags = itemEffect[i];

            // PP Up
            if (effectFlags & ITEM4_PP_UP)
            {
                effectFlags &= ~ITEM4_PP_UP;
                dataUnsigned = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                temp1 = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                if (dataUnsigned <= 2 && temp1 > 4)
                {
                    dataUnsigned = GetMonData(mon, MON_DATA_PP_BONUSES, NULL) + gPPUpAddValues[moveIndex];
                    SetMonData(mon, MON_DATA_PP_BONUSES, &dataUnsigned);

                    dataUnsigned = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), dataUnsigned, moveIndex) - temp1;
                    dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL) + dataUnsigned;
                    SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                    retVal = FALSE;
                }
            }
            temp1 = 0;

            // Loop through and try each of the remaining ITEM4 effects
            while (effectFlags != 0)
            {
                if (effectFlags & 1)
                {
                    switch (temp1)
                    {
                    case 0: // ITEM4_EV_HP
                    case 1: // ITEM4_EV_ATK
                        evCount = GetMonEVCount(mon);
                        temp2 = itemEffect[itemEffectParam];
                        dataSigned = GetMonData(mon, sGetMonDataEVConstants[temp1], NULL);
                        evChange = temp2;

                        if (evChange > 0) // Increasing EV (HP or Atk)
                        {
                            // Has EV increase limit already been reached?
                            if (evCount >= MAX_TOTAL_EVS)
                                return TRUE;

                            if (itemEffect[10] & ITEM10_IS_VITAMIN)
                                evCap = EV_ITEM_RAISE_LIMIT;
                            else
                                evCap = MAX_PER_STAT_EVS;

                            if (dataSigned >= evCap)
                                break;

                            // Limit the increase
                            if (dataSigned + evChange > evCap)
                                temp2 = evCap - (dataSigned + evChange) + evChange;
                            else
                                temp2 = evChange;

                            if (evCount + temp2 > MAX_TOTAL_EVS)
                                temp2 += MAX_TOTAL_EVS - (evCount + temp2);

                            dataSigned += temp2;
                        }
                        else if (evChange < 0) // Decreasing EV (HP or Atk)
                        {
                            if (dataSigned == 0)
                            {
                                // No EVs to lose, but make sure friendship updates anyway
                                friendshipOnly = TRUE;
                                itemEffectParam++;
                                break;
                            }
                            dataSigned += evChange;
                            if (I_BERRY_EV_JUMP == GEN_4 && dataSigned > 100)
                                dataSigned = 100;
                            if (dataSigned < 0)
                                dataSigned = 0;
                        }
                        else // Reset EV (HP or Atk)
                        {
                            if (dataSigned == 0)
                                break;

                            dataSigned = 0;
                        }

                        // Update EVs and stats
                        SetMonData(mon, sGetMonDataEVConstants[temp1], &dataSigned);
                        CalculateMonStats(mon);
                        itemEffectParam++;
                        retVal = FALSE;
                        break;

                    case 2: // ITEM4_HEAL_HP
                        // Check use validity.
                        if ((effectFlags & (ITEM4_REVIVE >> 2) && GetMonData(mon, MON_DATA_HP, NULL) != 0)
                              || (!(effectFlags & (ITEM4_REVIVE >> 2)) && GetMonData(mon, MON_DATA_HP, NULL) == 0))
                        {
                            itemEffectParam++;
                            break;
                        }

                        // Get amount of HP to restore
                        dataUnsigned = itemEffect[itemEffectParam++];
                        switch (dataUnsigned)
                        {
                        case ITEM6_HEAL_HP_FULL:
                            dataUnsigned = GetMonData(mon, MON_DATA_MAX_HP, NULL) - GetMonData(mon, MON_DATA_HP, NULL);
                            break;
                        case ITEM6_HEAL_HP_HALF:
                            dataUnsigned = GetMonData(mon, MON_DATA_MAX_HP, NULL) / 2;
                            if (dataUnsigned == 0)
                                dataUnsigned = 1;
                            break;
                        case ITEM6_HEAL_HP_LVL_UP:
                            dataUnsigned = gBattleScripting.levelUpHP;
                            break;
                        case ITEM6_HEAL_HP_QUARTER:
                            dataUnsigned = GetMonData(mon, MON_DATA_MAX_HP, NULL) / 4;
                            if (dataUnsigned == 0)
                                dataUnsigned = 1;
                            break;
                        }

                        // Only restore HP if not at max health
                        if (GetMonData(mon, MON_DATA_MAX_HP, NULL) != GetMonData(mon, MON_DATA_HP, NULL))
                        {
                            // Restore HP
                            dataUnsigned = GetMonData(mon, MON_DATA_HP, NULL) + dataUnsigned;
                            if (dataUnsigned > GetMonData(mon, MON_DATA_MAX_HP, NULL))
                                dataUnsigned = GetMonData(mon, MON_DATA_MAX_HP, NULL);
                            SetMonData(mon, MON_DATA_HP, &dataUnsigned);
                            retVal = FALSE;
                        }
                        effectFlags &= ~(ITEM4_REVIVE >> 2);
                        break;

                    case 3: // ITEM4_HEAL_PP
                        if (!(effectFlags & (ITEM4_HEAL_PP_ONE >> 3)))
                        {
                            // Heal PP for all moves
                            for (temp2 = 0; (signed)(temp2) < (signed)(MAX_MON_MOVES); temp2++)
                            {
                                u16 moveId;
                                dataUnsigned = GetMonData(mon, MON_DATA_PP1 + temp2, NULL);
                                moveId = GetMonData(mon, MON_DATA_MOVE1 + temp2, NULL);
                                if (dataUnsigned != CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), temp2))
                                {
                                    dataUnsigned += itemEffect[itemEffectParam];
                                    moveId = GetMonData(mon, MON_DATA_MOVE1 + temp2, NULL); // Redundant
                                    if (dataUnsigned > CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), temp2))
                                    {
                                        moveId = GetMonData(mon, MON_DATA_MOVE1 + temp2, NULL); // Redundant
                                        dataUnsigned = CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), temp2);
                                    }
                                    SetMonData(mon, MON_DATA_PP1 + temp2, &dataUnsigned);
                                    retVal = FALSE;
                                }
                            }
                            itemEffectParam++;
                        }
                        else
                        {
                            // Heal PP for one move
                            u16 moveId;
                            dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL);
                            moveId = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL);
                            if (dataUnsigned != CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex))
                            {
                                dataUnsigned += itemEffect[itemEffectParam++];
                                moveId = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL); // Redundant
                                if (dataUnsigned > CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex))
                                {
                                    moveId = GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL); // Redundant
                                    dataUnsigned = CalculatePPWithBonus(moveId, GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);
                                }
                                SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                                retVal = FALSE;
                            }
                        }
                        break;

                    // cases 4-6 are ITEM4_HEAL_PP_ONE, ITEM4_PP_UP, and ITEM4_REVIVE, which
                    // are already handled above by other cases or before the loop

                    case 7: // ITEM4_EVO_STONE
                        {
                            u16 targetSpecies = GetEvolutionTargetSpecies(mon, EVO_MODE_ITEM_USE, item, NULL);

                            if (targetSpecies != SPECIES_NONE)
                            {
                                BeginEvolutionScene(mon, targetSpecies, FALSE, partyIndex);
                                return FALSE;
                            }
                        }
                        break;
                    }
                }
                temp1++;
                effectFlags >>= 1;
            }
            break;

        // Handle ITEM5 effects (Change Def/SpDef/SpAtk/Speed EVs, PP Max, and friendship changes)
        case 5:
            effectFlags = itemEffect[i];
            temp1 = 0;

            // Loop through and try each of the ITEM5 effects
            while (effectFlags != 0)
            {
                if (effectFlags & 1)
                {
                    switch (temp1)
                    {
                    case 0: // ITEM5_EV_DEF
                    case 1: // ITEM5_EV_SPEED
                    case 2: // ITEM5_EV_SPDEF
                    case 3: // ITEM5_EV_SPATK
                        evCount = GetMonEVCount(mon);
                        temp2 = itemEffect[itemEffectParam];
                        dataSigned = GetMonData(mon, sGetMonDataEVConstants[temp1 + 2], NULL);
                        evChange = temp2;
                        if (evChange > 0) // Increasing EV
                        {
                            // Has EV increase limit already been reached?
                            if (evCount >= MAX_TOTAL_EVS)
                                return TRUE;

                            if (itemEffect[10] & ITEM10_IS_VITAMIN)
                                evCap = EV_ITEM_RAISE_LIMIT;
                            else
                                evCap = MAX_PER_STAT_EVS;

                            if (dataSigned >= evCap)
                                break;

                            // Limit the increase
                            if (dataSigned + evChange > evCap)
                                temp2 = evCap - (dataSigned + evChange) + evChange;
                            else
                                temp2 = evChange;

                            if (evCount + temp2 > MAX_TOTAL_EVS)
                                temp2 += MAX_TOTAL_EVS - (evCount + temp2);

                            dataSigned += temp2;
                        }
                        else if (evChange < 0) // Decreasing EV
                        {
                            if (dataSigned == 0)
                            {
                                // No EVs to lose, but make sure friendship updates anyway
                                friendshipOnly = TRUE;
                                itemEffectParam++;
                                break;
                            }
                            dataSigned += evChange;
                            if (I_BERRY_EV_JUMP == GEN_4 && dataSigned > 100)
                                dataSigned = 100;
                            if (dataSigned < 0)
                                dataSigned = 0;
                        }
                        else // Reset EV
                        {
                            if (dataSigned == 0)
                                break;

                            dataSigned = 0;
                        }

                        // Update EVs and stats
                        SetMonData(mon, sGetMonDataEVConstants[temp1 + 2], &dataSigned);
                        CalculateMonStats(mon);
                        retVal = FALSE;
                        itemEffectParam++;
                        break;

                    case 4: // ITEM5_PP_MAX
                        dataUnsigned = (GetMonData(mon, MON_DATA_PP_BONUSES, NULL) & gPPUpGetMask[moveIndex]) >> (moveIndex * 2);
                        temp2 = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), GetMonData(mon, MON_DATA_PP_BONUSES, NULL), moveIndex);

                        // Check if 3 PP Ups have been applied already, and that the move has a total PP of at least 5 (excludes Sketch)
                        if (dataUnsigned < 3 && temp2 >= 5)
                        {
                            dataUnsigned = GetMonData(mon, MON_DATA_PP_BONUSES, NULL);
                            dataUnsigned &= gPPUpClearMask[moveIndex];
                            dataUnsigned += gPPUpAddValues[moveIndex] * 3; // Apply 3 PP Ups (max)

                            SetMonData(mon, MON_DATA_PP_BONUSES, &dataUnsigned);
                            dataUnsigned = CalculatePPWithBonus(GetMonData(mon, MON_DATA_MOVE1 + moveIndex, NULL), dataUnsigned, moveIndex) - temp2;
                            dataUnsigned = GetMonData(mon, MON_DATA_PP1 + moveIndex, NULL) + dataUnsigned;
                            SetMonData(mon, MON_DATA_PP1 + moveIndex, &dataUnsigned);
                            retVal = FALSE;
                        }
                        break;

                    case 5: // ITEM5_FRIENDSHIP_LOW
                        // Changes to friendship are given differently depending on
                        // how much friendship the Pokémon already has.
                        // In general, Pokémon with lower friendship receive more,
                        // and Pokémon with higher friendship receive less.
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) < 100)
                            UPDATE_FRIENDSHIP_FROM_ITEM();
                        itemEffectParam++;
                        break;

                    case 6: // ITEM5_FRIENDSHIP_MID
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 100 && GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) < 200)
                            UPDATE_FRIENDSHIP_FROM_ITEM();
                        itemEffectParam++;
                        break;

                    case 7: // ITEM5_FRIENDSHIP_HIGH
                        if (GetMonData(mon, MON_DATA_FRIENDSHIP, NULL) >= 200)
                            UPDATE_FRIENDSHIP_FROM_ITEM();
                        itemEffectParam++;
                        break;
                    }
                }
                temp1++;
                effectFlags >>= 1;
            }
            break;
        }
    }
    return retVal;
}

bool8 HealStatusConditions(struct Pokemon *mon, u32 healMask, u8 battlerId)
{
    u32 status = GetMonData(mon, MON_DATA_STATUS, 0);

    if (status & healMask)
    {
        status &= ~healMask;
        SetMonData(mon, MON_DATA_STATUS, &status);
        if (gMain.inBattle && battlerId != MAX_BATTLERS_COUNT)
            gBattleMons[battlerId].status1 &= ~healMask;
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

u8 GetItemEffectParamOffset(u32 battler, u16 itemId, u8 effectByte, u8 effectBit)
{
    const u8 *temp;
    const u8 *itemEffect;
    u8 offset;
    int i;
    u8 j;
    u8 effectFlags;

    offset = ITEM_EFFECT_ARG_START;

    temp = ItemId_GetEffect(itemId);

    if (temp != NULL && !temp && itemId != ITEM_ENIGMA_BERRY_E_READER)
        return 0;

    if (itemId == ITEM_ENIGMA_BERRY_E_READER)
    {
        temp = gEnigmaBerries[battler].itemEffect;
    }

    itemEffect = temp;

    for (i = 0; i < ITEM_EFFECT_ARG_START; i++)
    {
        switch (i)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            if (i == effectByte)
                return 0;
            break;
        case 4:
            effectFlags = itemEffect[4];
            if (effectFlags & ITEM4_PP_UP)
                effectFlags &= ~(ITEM4_PP_UP);
            j = 0;
            while (effectFlags)
            {
                if (effectFlags & 1)
                {
                    switch (j)
                    {
                    case 2: // ITEM4_HEAL_HP
                        if (effectFlags & (ITEM4_REVIVE >> 2))
                            effectFlags &= ~(ITEM4_REVIVE >> 2);
                        // fallthrough
                    case 0: // ITEM4_EV_HP
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 1: // ITEM4_EV_ATK
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 3: // ITEM4_HEAL_PP
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7: // ITEM4_EVO_STONE
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                effectFlags >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        case 5:
            effectFlags = itemEffect[5];
            j = 0;
            while (effectFlags)
            {
                if (effectFlags & 1)
                {
                    switch (j)
                    {
                    case 0: // ITEM5_EV_DEF
                    case 1: // ITEM5_EV_SPEED
                    case 2: // ITEM5_EV_SPDEF
                    case 3: // ITEM5_EV_SPATK
                    case 4: // ITEM5_PP_MAX
                    case 5: // ITEM5_FRIENDSHIP_LOW
                    case 6: // ITEM5_FRIENDSHIP_MID
                        if (i == effectByte && (effectFlags & effectBit))
                            return offset;
                        offset++;
                        break;
                    case 7: // ITEM5_FRIENDSHIP_HIGH
                        if (i == effectByte)
                            return 0;
                        break;
                    }
                }
                j++;
                effectFlags >>= 1;
                if (i == effectByte)
                    effectBit >>= 1;
            }
            break;
        }
    }

    return offset;
}

static void BufferStatRoseMessage(s32 statIdx)
{
    gBattlerTarget = gBattlerInMenuId;
    StringCopy(gBattleTextBuff1, gStatNamesTable[sStatsToRaise[statIdx]]);
    if (B_X_ITEMS_BUFF >= GEN_7)
    {
        StringCopy(gBattleTextBuff2, gText_StatSharply);
        StringAppend(gBattleTextBuff2, gText_StatRose);
    }
    else
    {
        StringCopy(gBattleTextBuff2, gText_StatRose);
    }
    BattleStringExpandPlaceholdersToDisplayedString(gText_DefendersStatRose);
}

u8 *UseStatIncreaseItem(u16 itemId)
{
    const u8 *itemEffect;

    if (itemId == ITEM_ENIGMA_BERRY_E_READER)
    {
        if (gMain.inBattle)
            itemEffect = gEnigmaBerries[gBattlerInMenuId].itemEffect;
        else
        #if FREE_ENIGMA_BERRY == FALSE
            itemEffect = gSaveBlock1Ptr->enigmaBerry.itemEffect;
        #else
            itemEffect = 0;
        #endif //FREE_ENIGMA_BERRY
    }
    else
    {
        itemEffect = ItemId_GetEffect(itemId);
    }

    gPotentialItemEffectBattler = gBattlerInMenuId;

    if (itemEffect[0] & ITEM0_DIRE_HIT)
    {
        gBattlerAttacker = gBattlerInMenuId;
        BattleStringExpandPlaceholdersToDisplayedString(gText_PkmnGettingPumped);
    }

    switch (itemEffect[1])
    {
        case ITEM1_X_ATTACK:
            BufferStatRoseMessage(STAT_ATK);
            break;
        case ITEM1_X_DEFENSE:
            BufferStatRoseMessage(STAT_DEF);
            break;
        case ITEM1_X_SPEED:
            BufferStatRoseMessage(STAT_SPEED);
            break;
        case ITEM1_X_SPATK:
            BufferStatRoseMessage(STAT_SPATK);
            break;
        case ITEM1_X_SPDEF:
            BufferStatRoseMessage(STAT_SPDEF);
            break;
        case ITEM1_X_ACCURACY:
            BufferStatRoseMessage(STAT_ACC);
            break;
    }

    if (itemEffect[3] & ITEM3_GUARD_SPEC)
    {
        gBattlerAttacker = gBattlerInMenuId;
        BattleStringExpandPlaceholdersToDisplayedString(gText_PkmnShroudedInMist);
    }

    return gDisplayedStringBattle;
}

u8 GetNature(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_PERSONALITY, 0) % NUM_NATURES;
}

u8 GetNatureFromPersonality(u32 personality)
{
    return personality % NUM_NATURES;
}

static u32 GetGMaxTargetSpecies(u32 species)
{
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);
    u32 i;
    for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_BATTLE_GIGANTAMAX)
            return formChanges[i].targetSpecies;
    }
    return SPECIES_NONE;
}

u16 GetEvolutionTargetSpecies(struct Pokemon *mon, u8 mode, u16 evolutionItem, struct Pokemon *tradePartner)
{
    int i, j, k;
    u16 targetSpecies = SPECIES_NONE;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u16 heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, 0);
    u8 level;
    u16 friendship;
    u8 beauty = GetMonData(mon, MON_DATA_BEAUTY, 0);
    u16 upperPersonality = personality >> 16;
    u32 holdEffect, currentMap, partnerSpecies, partnerHeldItem, partnerHoldEffect;
    bool32 consumeItem = FALSE;
    u16 evolutionTracker = GetMonData(mon, MON_DATA_EVOLUTION_TRACKER, 0);
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions == NULL)
        return SPECIES_NONE;

    if (tradePartner != NULL)
    {
        partnerSpecies = GetMonData(tradePartner, MON_DATA_SPECIES, 0);
        partnerHeldItem = GetMonData(tradePartner, MON_DATA_HELD_ITEM, 0);

        if (partnerHeldItem == ITEM_ENIGMA_BERRY_E_READER)
        #if FREE_ENIGMA_BERRY == FALSE
            partnerHoldEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        #else
            partnerHoldEffect = 0;
        #endif //FREE_ENIGMA_BERRY
        else
            partnerHoldEffect = ItemId_GetHoldEffect(partnerHeldItem);
    }
    else
    {
        partnerSpecies = SPECIES_NONE;
        partnerHeldItem = ITEM_NONE;
        partnerHoldEffect = HOLD_EFFECT_NONE;
    }

    if (heldItem == ITEM_ENIGMA_BERRY_E_READER)
    #if FREE_ENIGMA_BERRY == FALSE
        holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
    #else
        holdEffect = 0;
    #endif //FREE_ENIGMA_BERRY
    else
        holdEffect = ItemId_GetHoldEffect(heldItem);

    // Prevent evolution with Everstone, unless we're just viewing the party menu with an evolution item
    if (holdEffect == HOLD_EFFECT_PREVENT_EVOLVE
        && mode != EVO_MODE_ITEM_CHECK
        && (P_KADABRA_EVERSTONE < GEN_4 || species != SPECIES_KADABRA))
        return SPECIES_NONE;

    switch (mode)
    {
    case EVO_MODE_NORMAL:
    case EVO_MODE_BATTLE_ONLY:
        level = GetMonData(mon, MON_DATA_LEVEL, 0);
        friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, 0);

        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_LEVEL_HOLD_ITEM:
                if (evolutions[i].param <= level)
                {
                    //handle special cases below
                    switch (GetMonData(mon, MON_DATA_SPECIES))
                    {
                        case SPECIES_RUFFLET:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_PSYCHIC_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_GOOMY:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_STEEL_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_BERGMITE:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_ROCK_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_DARTRIX:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_FIGHTING_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_CUBONE:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_GHOST_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_KOFFING:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_FAIRY_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_QUILAVA:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_GHOST_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_DEWOTT:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_DARK_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                    }
                }
                break;
            case EVO_FRIENDSHIP:
                if (friendship >= FRIENDSHIP_EVO_THRESHOLD)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_FRIENDSHIP_DAY:
                if (GetTimeOfDay() != TIME_NIGHT && friendship >= FRIENDSHIP_EVO_THRESHOLD)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_DAY:
                if (GetTimeOfDay() != TIME_NIGHT && evolutions[i].param <= level)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_FRIENDSHIP_NIGHT:
                if (GetTimeOfDay() == TIME_NIGHT && friendship >= FRIENDSHIP_EVO_THRESHOLD)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_NIGHT:
                if (GetTimeOfDay() == TIME_NIGHT && evolutions[i].param <= level)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_ITEM_HOLD_NIGHT:
                if (GetTimeOfDay() == TIME_NIGHT && heldItem == evolutions[i].param)
                {
                    targetSpecies = evolutions[i].targetSpecies;
                    consumeItem = TRUE;
                }
                break;
            case EVO_ITEM_HOLD_DAY:
                if (GetTimeOfDay() != TIME_NIGHT && heldItem == evolutions[i].param)
                {
                    targetSpecies = evolutions[i].targetSpecies;
                    consumeItem = TRUE;
                }
                break;
            case EVO_LEVEL_DUSK:
                if (GetTimeOfDay() == TIME_EVENING && evolutions[i].param <= level)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL:
                if (evolutions[i].param <= level)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_FEMALE:
                if (evolutions[i].param <= level && GetMonGender(mon) == MON_FEMALE)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_MALE:
                if (evolutions[i].param <= level && GetMonGender(mon) == MON_MALE)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_GT_DEF:
                if (evolutions[i].param <= level)
                    if (GetMonData(mon, MON_DATA_ATK, 0) > GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_EQ_DEF:
                if (evolutions[i].param <= level)
                    if (GetMonData(mon, MON_DATA_ATK, 0) == GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_ATK_LT_DEF:
                if (evolutions[i].param <= level)
                    if (GetMonData(mon, MON_DATA_ATK, 0) < GetMonData(mon, MON_DATA_DEF, 0))
                        targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_SILCOON:
                if (evolutions[i].param <= level && (upperPersonality % 10) <= 4)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_CASCOON:
                if (evolutions[i].param <= level && (upperPersonality % 10) > 4)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_NINJASK:
                if (evolutions[i].param <= level)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_FAMILY_OF_FOUR:
                if (mode == EVO_MODE_BATTLE_ONLY && evolutions[i].param <= level && (personality % 100) != 0)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_FAMILY_OF_THREE:
                if (mode == EVO_MODE_BATTLE_ONLY && evolutions[i].param <= level && (personality % 100) == 0)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_BEAUTY:
                if (evolutions[i].param <= beauty)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_MOVE:
                if (MonKnowsMove(mon, evolutions[i].param))
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_MOVE_TWO_SEGMENT:
                if (MonKnowsMove(mon, evolutions[i].param) && (personality % 100) != 0)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_MOVE_THREE_SEGMENT:
                if (MonKnowsMove(mon, evolutions[i].param) && (personality % 100) == 0)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_FRIENDSHIP_MOVE_TYPE:
                if (friendship >= FRIENDSHIP_EVO_THRESHOLD)
                {
                    for (j = 0; j < MAX_MON_MOVES; j++)
                    {
                        if (gMovesInfo[GetMonData(mon, MON_DATA_MOVE1 + j, NULL)].type == evolutions[i].param)
                        {
                            targetSpecies = evolutions[i].targetSpecies;
                            break;
                        }
                    }
                }
                break;
            case EVO_SPECIFIC_MON_IN_PARTY:
                for (j = 0; j < PARTY_SIZE; j++)
                {
                    if (GetMonData(&gPlayerParty[j], MON_DATA_SPECIES, NULL) == evolutions[i].param)
                    {
                        targetSpecies = evolutions[i].targetSpecies;
                        break;
                    }
                }
                break;
            case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
                if (evolutions[i].param <= level)
                {
                    for (j = 0; j < PARTY_SIZE; j++)
                    {
                        u16 currSpecies = GetMonData(&gPlayerParty[j], MON_DATA_SPECIES, NULL);
                        
                        if (GetTypeBySpecies(currSpecies, 1) == TYPE_DARK
                         || GetTypeBySpecies(currSpecies, 2) == TYPE_DARK)
                        {
                            targetSpecies = evolutions[i].targetSpecies;
                            break;
                        }
                    }
                }
                break;
            case EVO_LEVEL_RAIN:
                j = GetCurrentWeather();
                if (evolutions[i].param <= level
                 && (j == WEATHER_RAIN || j == WEATHER_RAIN_THUNDERSTORM || j == WEATHER_DOWNPOUR))
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_FOG:
                j = GetCurrentWeather();
                if (evolutions[i].param <= level
                 && (j == WEATHER_FOG_HORIZONTAL || j == WEATHER_FOG_DIAGONAL))
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_MAPSEC:
                if (gMapHeader.regionMapSectionId == evolutions[i].param)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_SPECIFIC_MAP:
                currentMap = ((gSaveBlock1Ptr->location.mapGroup) << 8 | gSaveBlock1Ptr->location.mapNum);
                if (currentMap == evolutions[i].param)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_LEVEL_NATURE_AMPED:
                if (evolutions[i].param <= level)
                {
                    u8 nature = GetNature(mon);
                    switch (nature)
                    {
                    case NATURE_HARDY:
                    case NATURE_BRAVE:
                    case NATURE_ADAMANT:
                    case NATURE_NAUGHTY:
                    case NATURE_DOCILE:
                    case NATURE_IMPISH:
                    case NATURE_LAX:
                    case NATURE_HASTY:
                    case NATURE_JOLLY:
                    case NATURE_NAIVE:
                    case NATURE_RASH:
                    case NATURE_SASSY:
                    case NATURE_QUIRKY:
                        targetSpecies = evolutions[i].targetSpecies;
                        break;
                    }
                }
                break;
            case EVO_LEVEL_NATURE_LOW_KEY:
                if (evolutions[i].param <= level)
                {
                    u8 nature = GetNature(mon);
                    switch (nature)
                    {
                    case NATURE_LONELY:
                    case NATURE_BOLD:
                    case NATURE_RELAXED:
                    case NATURE_TIMID:
                    case NATURE_SERIOUS:
                    case NATURE_MODEST:
                    case NATURE_MILD:
                    case NATURE_QUIET:
                    case NATURE_BASHFUL:
                    case NATURE_CALM:
                    case NATURE_GENTLE:
                    case NATURE_CAREFUL:
                        targetSpecies = evolutions[i].targetSpecies;
                        break;
                    }
                }
                break;
            case EVO_ITEM_HOLD:
                if (heldItem == evolutions[i].param)
                {
                    targetSpecies = evolutions[i].targetSpecies;
                    consumeItem = TRUE;
                }
                break;
            case EVO_USE_MOVE_TWENTY_TIMES:
                if (evolutionTracker >= 20)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_RECOIL_DAMAGE_MALE:
                if (evolutionTracker >= evolutions[i].param && GetMonGender(mon) == MON_MALE)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_RECOIL_DAMAGE_FEMALE:
                if (evolutionTracker >= evolutions[i].param && GetMonGender(mon) == MON_FEMALE)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_DEFEAT_THREE_WITH_ITEM:
                if (evolutionTracker >= 3)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_OVERWORLD_STEPS:
                if (mon == GetFirstLiveMon() && gFollowerSteps >= evolutions[i].param)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    case EVO_MODE_CANT_STOP:
        level = GetMonData(mon, MON_DATA_LEVEL, 0);
        friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, 0);

        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_ITEM_COUNT_999:
                if (CheckBagHasItem(evolutions[i].param, 999))
                {
                    targetSpecies = evolutions[i].targetSpecies;
                    RemoveBagItem(evolutions[i].param, 999);
                }
                break;
            }
        }
        break;
    case EVO_MODE_TRADE:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_TRADE:
                targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_TRADE_ITEM:
                if (evolutions[i].param == heldItem)
                {
                    targetSpecies = evolutions[i].targetSpecies;
                    consumeItem = TRUE;
                }
                break;
            case EVO_TRADE_SPECIFIC_MON:
                if (evolutions[i].param == partnerSpecies && partnerHoldEffect != HOLD_EFFECT_PREVENT_EVOLVE)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    case EVO_MODE_ITEM_USE:
    case EVO_MODE_ITEM_CHECK:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_ITEM_HOLD_ITEM:
                if (evolutions[i].param == evolutionItem)
                {
                    switch(GetMonData(mon, MON_DATA_SPECIES))
                    {
                        case SPECIES_PIKACHU:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_PSYCHIC_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_EXEGGCUTE:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_DRAGON_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                        case SPECIES_PETILIL:
                            if (GetMonData(mon, MON_DATA_HELD_ITEM) == ITEM_FIGHTING_MEMORY)
                                targetSpecies = evolutions[i].targetSpecies;
                            break;
                    }
                }
                break;
            case EVO_ITEM:
                if (evolutions[i].param == evolutionItem)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_ITEM_FEMALE:
                if (GetMonGender(mon) == MON_FEMALE && evolutions[i].param == evolutionItem)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_ITEM_MALE:
                if (GetMonGender(mon) == MON_MALE && evolutions[i].param == evolutionItem)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_ITEM_NIGHT:
                if (GetTimeOfDay() == TIME_NIGHT && evolutions[i].param == evolutionItem)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_ITEM_DAY:
                if (GetTimeOfDay() != TIME_NIGHT && evolutions[i].param == evolutionItem)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_ITEM_SPECIFIC_MON_IN_PARTY:
                if (evolutions[i].param == evolutionItem)
                {
                    switch(GetMonData(mon, MON_DATA_SPECIES))
                    {
                        case SPECIES_KARRABLAST:
                            for (k=0; k<PARTY_SIZE; k++)
                            {
                                if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES) == SPECIES_SHELMET)
                                targetSpecies = evolutions[i].targetSpecies;
                            }
                            //DebugPrintf("target species = %d", targetSpecies);
                            break;
                        case SPECIES_SHELMET:
                            for (k=0; k<PARTY_SIZE; k++)
                            {
                                if (GetMonData(&gPlayerParty[k], MON_DATA_SPECIES) == SPECIES_KARRABLAST)
                                    targetSpecies = evolutions[i].targetSpecies;
                            }
                            //DebugPrintf("target species = %d", targetSpecies);
                            break;
                    }
                }
                break;
            }
        }
        break;
    // Battle evolution without leveling; party slot is being passed into the evolutionItem arg.
    case EVO_MODE_BATTLE_SPECIAL:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_CRITICAL_HITS:
                if (gPartyCriticalHits[evolutionItem] >= evolutions[i].param)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    // Overworld evolution without leveling; evolution method is being passed into the evolutionItem arg.
    case EVO_MODE_OVERWORLD_SPECIAL:
        for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
        {
            if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
                continue;

            switch (evolutions[i].method)
            {
            case EVO_SCRIPT_TRIGGER_DMG:
            {
                u16 currentHp = GetMonData(mon, MON_DATA_HP, NULL);
                if (evolutionItem == EVO_SCRIPT_TRIGGER_DMG
                    && currentHp != 0
                    && (GetMonData(mon, MON_DATA_MAX_HP, NULL) - currentHp >= evolutions[i].param))
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            }
            case EVO_DARK_SCROLL:
                if (evolutionItem == EVO_DARK_SCROLL)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            case EVO_WATER_SCROLL:
                if (evolutionItem == EVO_WATER_SCROLL)
                    targetSpecies = evolutions[i].targetSpecies;
                break;
            }
        }
        break;
    }

    // Pikachu, Meowth, and Eevee cannot evolve if they have the
    // Gigantamax Factor. We assume that is because their evolutions
    // do not have a Gigantamax Form.
    if (GetMonData(mon, MON_DATA_GIGANTAMAX_FACTOR, NULL)
     && GetGMaxTargetSpecies(species) != SPECIES_NONE
     && GetGMaxTargetSpecies(targetSpecies) == SPECIES_NONE)
    {
        return SPECIES_NONE;
    }

    if (consumeItem)
    {
        heldItem = ITEM_NONE;
        SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
    }

    if (gSaveBlock2Ptr->randomEvos && (targetSpecies != SPECIES_NONE))
    {
        targetSpecies = GetSpeciesRandomNotSeeded(targetSpecies);
    }

    return targetSpecies;
}

bool8 IsMonPastEvolutionLevel(struct Pokemon *mon)
{
    int i;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    const struct Evolution *evolutions = GetSpeciesEvolutions(species);

    if (evolutions == NULL)
        return FALSE;

    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (SanitizeSpeciesId(evolutions[i].targetSpecies) == SPECIES_NONE)
            continue;

        switch (evolutions[i].method)
        {
        case EVO_LEVEL:
            if (evolutions[i].param <= level)
                return TRUE;
            break;
        }
    }

    return FALSE;
}

u16 NationalPokedexNumToSpecies(u16 nationalNum)
{
    u16 species;

    if (!nationalNum)
        return 0;

    species = 1;

    while (species < (NUM_SPECIES) && gSpeciesInfo[species].natDexNum != nationalNum)
        species++;

    if (species == NUM_SPECIES)
        return NATIONAL_DEX_NONE;

    return GET_BASE_SPECIES_ID(species);
}

u16 NationalToHoennOrder(u16 nationalNum)
{
    u16 hoennNum;

    if (!nationalNum)
        return 0;

    hoennNum = 0;

    while (hoennNum < (HOENN_DEX_COUNT - 1) && sHoennToNationalOrder[hoennNum] != nationalNum)
        hoennNum++;

    if (hoennNum >= HOENN_DEX_COUNT - 1)
        return 0;

    return hoennNum + 1;
}

u16 SpeciesToNationalPokedexNum(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (!species)
        return NATIONAL_DEX_NONE;

    return gSpeciesInfo[species].natDexNum;
}

u16 SpeciesToHoennPokedexNum(u16 species)
{
    if (!species)
        return 0;
    return NationalToHoennOrder(gSpeciesInfo[species].natDexNum);
}

u16 HoennToNationalOrder(u16 hoennNum)
{
    if (!hoennNum || hoennNum >= HOENN_DEX_COUNT)
        return 0;

    return sHoennToNationalOrder[hoennNum - 1];
}

// Spots can be drawn on Spinda's color indexes 1, 2, or 3
#define FIRST_SPOT_COLOR 1
#define LAST_SPOT_COLOR  3

// To draw a spot pixel, add 4 to the color index
#define SPOT_COLOR_ADJUSTMENT 4
/*
    The function below handles drawing the randomly-placed spots on Spinda's front sprite.
    Spinda has 4 spots, each with an entry in gSpindaSpotGraphics. Each entry contains
    a base x and y coordinate for the spot and a 16x16 binary image. Each bit in the image
    determines whether that pixel should be considered part of the spot.

    The position of each spot is randomized using the Spinda's personality. The entire 32 bit
    personality value is used, 4 bits for each coordinate of the 4 spots. If the personality
    value is 0x87654321, then 0x1 will be used for the 1st spot's x coord, 0x2 will be used for
    the 1st spot's y coord, 0x3 will be used for the 2nd spot's x coord, and so on. Each
    coordinate is calculated as (baseCoord + (given 4 bits of personality) - 8). In effect this
    means each spot can start at any position -8 to +7 off of its base coordinates (256 possibilities).

    The function then loops over the 16x16 spot image. For each bit in the spot's binary image, if
    the bit is set then it's part of the spot; try to draw it. A pixel is drawn on Spinda if the
    pixel on Spinda satisfies the following formula: ((u8)(colorIndex - 1) <= 2). The -1 excludes
    transparent pixels, as these are index 0. Therefore only colors 1, 2, or 3 on Spinda will
    allow a spot to be drawn. These color indexes are Spinda's light brown body colors. To create
    the spot it adds 4 to the color index, so Spinda's spots will be colors 5, 6, and 7.

    The above is done two different ways in the function: one with << 4, and one without. This
    is because Spinda's sprite is a 4 bits per pixel image, but the pointer to Spinda's pixels
    (destPixels) is an 8 bit pointer, so it addresses two pixels. Shifting by 4 accesses the 2nd
    of these pixels, so this is done every other time.
*/
void DrawSpindaSpots(u32 personality, u8 *dest, bool32 isSecondFrame)
{
    s32 i;
    for (i = 0; i < (s32)ARRAY_COUNT(gSpindaSpotGraphics); i++)
    {
        s32 row;
        u8 x = gSpindaSpotGraphics[i].x + (personality & 0x0F);
        u8 y = gSpindaSpotGraphics[i].y + ((personality & 0xF0) >> 4);

        if (isSecondFrame)
        {
            x -= 12;
            y += 56;
        }
        else
        {
            x -= 8;
            y -= 8;
        }

        for (row = 0; row < SPINDA_SPOT_HEIGHT; row++)
        {
            s32 column;
            s32 spotPixelRow = gSpindaSpotGraphics[i].image[row];

            for (column = x; column < x + SPINDA_SPOT_WIDTH; column++)
            {
                /* Get target pixels on Spinda's sprite */
                u8 *destPixels = dest + ((column / 8) * TILE_SIZE_4BPP) +
                    ((column % 8) / 2) +
                    ((y / 8) * TILE_SIZE_4BPP * 8) +
                    ((y % 8) * 4);

                /* Is this pixel in the 16x16 spot image part of the spot? */
                if (spotPixelRow & 1)
                {
                    /* destPixels addressess two pixels, alternate which */
                    /* of the two pixels is being considered for drawing */
                    if (column & 1)
                    {
                        /* Draw spot pixel if this is Spinda's body color */
                        if ((u8)((*destPixels & 0xF0) - (FIRST_SPOT_COLOR << 4))
                            <= ((LAST_SPOT_COLOR - FIRST_SPOT_COLOR) << 4))
                            *destPixels += (SPOT_COLOR_ADJUSTMENT << 4);
                    }
                    else
                    {
                        /* Draw spot pixel if this is Spinda's body color */
                        if ((u8)((*destPixels & 0xF) - FIRST_SPOT_COLOR)
                            <= (LAST_SPOT_COLOR - FIRST_SPOT_COLOR))
                            *destPixels += SPOT_COLOR_ADJUSTMENT;
                    }
                }

                spotPixelRow >>= 1;
            }

            y++;
        }

        personality >>= 8;
    }
}

void EvolutionRenameMon(struct Pokemon *mon, u16 oldSpecies, u16 newSpecies)
{
    u8 language;
    GetMonData(mon, MON_DATA_NICKNAME, gStringVar1);
    language = GetMonData(mon, MON_DATA_LANGUAGE, &language);
    if (language == GAME_LANGUAGE && !StringCompare(GetSpeciesName(oldSpecies), gStringVar1))
        SetMonData(mon, MON_DATA_NICKNAME, GetSpeciesName(newSpecies));
}

// The below two functions determine which side of a multi battle the trainer battles on
// 0 is the left (top in  party menu), 1 is right (bottom in party menu)
u8 GetPlayerFlankId(void)
{
    u8 flankId = 0;
    switch (gLinkPlayers[GetMultiplayerId()].id)
    {
    case 0:
    case 3:
        flankId = 0;
        break;
    case 1:
    case 2:
        flankId = 1;
        break;
    }
    return flankId;
}

u16 GetLinkTrainerFlankId(u8 linkPlayerId)
{
    u16 flankId = 0;
    switch (gLinkPlayers[linkPlayerId].id)
    {
    case 0:
    case 3:
        flankId = 0;
        break;
    case 1:
    case 2:
        flankId = 1;
        break;
    }
    return flankId;
}

s32 GetBattlerMultiplayerId(u16 id)
{
    s32 multiplayerId;
    for (multiplayerId = 0; multiplayerId < MAX_LINK_PLAYERS; multiplayerId++)
        if (gLinkPlayers[multiplayerId].id == id)
            break;
    return multiplayerId;
}

u8 GetTrainerEncounterMusicId(u16 trainerOpponentId)
{
    if (InBattlePyramid())
        return GetTrainerEncounterMusicIdInBattlePyramid(trainerOpponentId);
    else if (InTrainerHillChallenge())
        return GetTrainerEncounterMusicIdInTrainerHill(trainerOpponentId);
    else
        return gTrainers[SanitizeTrainerId(trainerOpponentId)].encounterMusic_gender & (F_TRAINER_FEMALE - 1);
}

u16 ModifyStatByNature(u8 nature, u16 stat, u8 statIndex)
{
    // Don't modify HP, Accuracy, or Evasion by nature
    if (statIndex <= STAT_HP || statIndex > NUM_NATURE_STATS || gNaturesInfo[nature].statUp == gNaturesInfo[nature].statDown)
        return stat;
    else if (statIndex == gNaturesInfo[nature].statUp)
        return stat * 110 / 100;
    else if (statIndex == gNaturesInfo[nature].statDown)
        return stat * 90 / 100;
    else
        return stat;
}

void AdjustFriendship(struct Pokemon *mon, u8 event)
{
    u16 species, heldItem;
    u8 holdEffect;
    s8 mod;

    if (ShouldSkipFriendshipChange())
        return;

    species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0);
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);

    if (heldItem == ITEM_ENIGMA_BERRY_E_READER)
    {
        if (gMain.inBattle)
            holdEffect = gEnigmaBerries[0].holdEffect;
        else
        #if FREE_ENIGMA_BERRY == FALSE
            holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        #else
            holdEffect = 0;
        #endif //FREE_ENIGMA_BERRY
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(heldItem);
    }

    if (species && species != SPECIES_EGG)
    {
        u8 friendshipLevel = 0;
        s16 friendship = GetMonData(mon, MON_DATA_FRIENDSHIP, 0);
        u32 opponentTrainerClass = GetTrainerClassFromId(gTrainerBattleOpponent_A);

        if (friendship > 99)
            friendshipLevel++;
        if (friendship > 199)
            friendshipLevel++;

        if (event == FRIENDSHIP_EVENT_WALKING)
        {
            // 50% chance every 128 steps
            if (Random() & 1)
                return;
        }
        if (event == FRIENDSHIP_EVENT_LEAGUE_BATTLE)
        {
            // Only if it's a trainer battle with league progression significance
            if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
                return;
            if (!(opponentTrainerClass == TRAINER_CLASS_LEADER
                || opponentTrainerClass == TRAINER_CLASS_ELITE_FOUR
                || opponentTrainerClass == TRAINER_CLASS_CHAMPION))
                return;
        }

        mod = sFriendshipEventModifiers[event][friendshipLevel];
        if (mod > 0 && holdEffect == HOLD_EFFECT_FRIENDSHIP_UP)
            // 50% increase, rounding down
            mod = (150 * mod) / 100;

        friendship += mod;
        if (mod > 0)
        {
            if (GetMonData(mon, MON_DATA_POKEBALL, NULL) == ITEM_LUXURY_BALL)
                friendship++;
            if (GetMonData(mon, MON_DATA_MET_LOCATION, NULL) == GetCurrentRegionMapSectionId())
                friendship++;
        }

        if (friendship < 0)
            friendship = 0;
        if (friendship > MAX_FRIENDSHIP)
            friendship = MAX_FRIENDSHIP;

        SetMonData(mon, MON_DATA_FRIENDSHIP, &friendship);
    }
}

void MonGainEVs(struct Pokemon *mon, u16 defeatedSpecies)
{
    u8 evs[NUM_STATS];
    u16 evIncrease = 0;
    u16 totalEVs = 0;
    u16 heldItem;
    u8 holdEffect;
    int i, multiplier;
    u8 stat;
    u8 bonus;

    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM, 0);
    if (heldItem == ITEM_ENIGMA_BERRY_E_READER)
    {
        if (gMain.inBattle)
            holdEffect = gEnigmaBerries[0].holdEffect;
        else
        #if FREE_ENIGMA_BERRY == FALSE
            holdEffect = gSaveBlock1Ptr->enigmaBerry.holdEffect;
        #else
            holdEffect = 0;
        #endif //FREE_ENIGMA_BERRY
    }
    else
    {
        holdEffect = ItemId_GetHoldEffect(heldItem);
    }

    stat = ItemId_GetSecondaryId(heldItem);
    bonus = ItemId_GetHoldEffectParam(heldItem);

    for (i = 0; i < NUM_STATS; i++)
    {
        evs[i] = GetMonData(mon, MON_DATA_HP_EV + i, 0);
        totalEVs += evs[i];
    }

    for (i = 0; i < NUM_STATS; i++)
    {
        if (totalEVs >= MAX_TOTAL_EVS)
            break;

        if (CheckPartyHasHadPokerus(mon, 0))
            multiplier = 2;
        else
            multiplier = 1;

        switch (i)
        {
        case STAT_HP:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_HP)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_HP + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_HP * multiplier;
            break;
        case STAT_ATK:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_ATK)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_Attack + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_Attack * multiplier;
            break;
        case STAT_DEF:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_DEF)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_Defense + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_Defense * multiplier;
            break;
        case STAT_SPEED:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_SPEED)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_Speed + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_Speed * multiplier;
            break;
        case STAT_SPATK:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_SPATK)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_SpAttack + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_SpAttack * multiplier;
            break;
        case STAT_SPDEF:
            if (holdEffect == HOLD_EFFECT_POWER_ITEM && stat == STAT_SPDEF)
                evIncrease = (gSpeciesInfo[defeatedSpecies].evYield_SpDefense + bonus) * multiplier;
            else
                evIncrease = gSpeciesInfo[defeatedSpecies].evYield_SpDefense * multiplier;
            break;
        }

        if (holdEffect == HOLD_EFFECT_MACHO_BRACE)
            evIncrease *= 2;

        if (totalEVs + (s16)evIncrease > MAX_TOTAL_EVS)
            evIncrease = ((s16)evIncrease + MAX_TOTAL_EVS) - (totalEVs + evIncrease);

        if (evs[i] + (s16)evIncrease > MAX_PER_STAT_EVS)
        {
            int val1 = (s16)evIncrease + MAX_PER_STAT_EVS;
            int val2 = evs[i] + evIncrease;
            evIncrease = val1 - val2;
        }

        evs[i] += evIncrease;
        totalEVs += evIncrease;
        SetMonData(mon, MON_DATA_HP_EV + i, &evs[i]);
    }
}

u16 GetMonEVCount(struct Pokemon *mon)
{
    int i;
    u16 count = 0;

    for (i = 0; i < NUM_STATS; i++)
        count += GetMonData(mon, MON_DATA_HP_EV + i, 0);

    return count;
}

void RandomlyGivePartyPokerus(struct Pokemon *party)
{
    u16 rnd = Random();
    if (rnd == 0x4000 || rnd == 0x8000 || rnd == 0xC000)
    {
        struct Pokemon *mon;

        do
        {
            rnd = Random() % PARTY_SIZE;
            mon = &party[rnd];
        }
        while (!GetMonData(mon, MON_DATA_SPECIES, 0) || GetMonData(mon, MON_DATA_IS_EGG, 0));

        if (!(CheckPartyHasHadPokerus(party, gBitTable[rnd])))
        {
            u8 rnd2;

            do
            {
                rnd2 = Random();
            }
            while ((rnd2 & 0x7) == 0);

            if (rnd2 & 0xF0)
                rnd2 &= 0x7;

            rnd2 |= (rnd2 << 4);
            rnd2 &= 0xF3;
            rnd2++;

            SetMonData(&party[rnd], MON_DATA_POKERUS, &rnd2);
        }
    }
}

u8 CheckPartyPokerus(struct Pokemon *party, u8 selection)
{
    u8 retVal;

    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (selection)
    {
        do
        {
            if ((selection & 1) && (GetMonData(&party[partyIndex], MON_DATA_POKERUS, 0) & 0xF))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            selection >>= 1;
        }
        while (selection);
    }
    else if (GetMonData(&party[0], MON_DATA_POKERUS, 0) & 0xF)
    {
        retVal = 1;
    }

    return retVal;
}

u8 CheckPartyHasHadPokerus(struct Pokemon *party, u8 selection)
{
    u8 retVal;

    int partyIndex = 0;
    unsigned curBit = 1;
    retVal = 0;

    if (selection)
    {
        do
        {
            if ((selection & 1) && GetMonData(&party[partyIndex], MON_DATA_POKERUS, 0))
                retVal |= curBit;
            partyIndex++;
            curBit <<= 1;
            selection >>= 1;
        }
        while (selection);
    }
    else if (GetMonData(&party[0], MON_DATA_POKERUS, 0))
    {
        retVal = 1;
    }

    return retVal;
}

void UpdatePartyPokerusTime(u16 days)
{
    int i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, 0))
        {
            u8 pokerus = GetMonData(&gPlayerParty[i], MON_DATA_POKERUS, 0);
            if (pokerus & 0xF)
            {
                if ((pokerus & 0xF) < days || days > 4)
                    pokerus &= 0xF0;
                else
                    pokerus -= days;

                if (pokerus == 0)
                    pokerus = 0x10;

                SetMonData(&gPlayerParty[i], MON_DATA_POKERUS, &pokerus);
            }
        }
    }
}

void PartySpreadPokerus(struct Pokemon *party)
{
    if ((Random() % 3) == 0)
    {
        int i;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData(&party[i], MON_DATA_SPECIES, 0))
            {
                u8 pokerus = GetMonData(&party[i], MON_DATA_POKERUS, 0);
                u8 curPokerus = pokerus;
                if (pokerus)
                {
                    if (pokerus & 0xF)
                    {
                        // Spread to adjacent party members.
                        if (i != 0 && !(GetMonData(&party[i - 1], MON_DATA_POKERUS, 0) & 0xF0))
                            SetMonData(&party[i - 1], MON_DATA_POKERUS, &curPokerus);
                        if (i != (PARTY_SIZE - 1) && !(GetMonData(&party[i + 1], MON_DATA_POKERUS, 0) & 0xF0))
                        {
                            SetMonData(&party[i + 1], MON_DATA_POKERUS, &curPokerus);
                            i++;
                        }
                    }
                }
            }
        }
    }
}

bool8 TryIncrementMonLevel(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 nextLevel = GetMonData(mon, MON_DATA_LEVEL, 0) + 1;
    u32 expPoints = GetMonData(mon, MON_DATA_EXP, 0);
    if (expPoints > gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL])
    {
        expPoints = gExperienceTables[gSpeciesInfo[species].growthRate][MAX_LEVEL];
        SetMonData(mon, MON_DATA_EXP, &expPoints);
    }
    if (nextLevel > GetCurrentLevelCap() || expPoints < gExperienceTables[gSpeciesInfo[species].growthRate][nextLevel])
    {
        return FALSE;
    }
    else
    {
        SetMonData(mon, MON_DATA_LEVEL, &nextLevel);
        return TRUE;
    }
}

void ForceIncrementMonLevel(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 nextLevel = GetMonData(mon, MON_DATA_LEVEL, 0) + 1;
    u32 expPoints = GetMonData(mon, MON_DATA_EXP, 0);
    s32 currentHP = GetMonData(mon, MON_DATA_HP, NULL);
    expPoints = gExperienceTables[gSpeciesInfo[species].growthRate][nextLevel];
    SetMonData(mon, MON_DATA_EXP, &expPoints);
    SetMonData(mon, MON_DATA_LEVEL, &nextLevel);
    CalculateMonStats(mon);
    if(currentHP == 0)
        SetMonData(mon, MON_DATA_HP, &currentHP);
    return;
}

static const u16 sUniversalMoves[] =
{
    MOVE_BIDE,
    MOVE_FRUSTRATION,
    MOVE_HIDDEN_POWER,
    MOVE_MIMIC,
    MOVE_NATURAL_GIFT,
    MOVE_RAGE,
    MOVE_RETURN,
    MOVE_SECRET_POWER,
    MOVE_SUBSTITUTE,
    MOVE_TERA_BLAST,
};

u8 CanLearnTeachableMove(u16 species, u16 move)
{
    if(FlagGet(FLAG_RANDOM_MODE))
    {
        species = GetSpeciesRandomSeeded(species + move);
        if(species % 4)
            return FALSE; 
        else
            return TRUE;
    }

    if (species == SPECIES_EGG)
    {
        return FALSE;
    }
    else if (species == SPECIES_MEW)
    {
        switch (move)
        {
        case MOVE_BADDY_BAD:
        case MOVE_BOUNCY_BUBBLE:
        case MOVE_BUZZY_BUZZ:
        case MOVE_DRAGON_ASCENT:
        case MOVE_FLOATY_FALL:
        case MOVE_FREEZY_FROST:
        case MOVE_GLITZY_GLOW:
        case MOVE_RELIC_SONG:
        case MOVE_SAPPY_SEED:
        case MOVE_SECRET_SWORD:
        case MOVE_SIZZLY_SLIDE:
        case MOVE_SPARKLY_SWIRL:
        case MOVE_SPLISHY_SPLASH:
        case MOVE_VOLT_TACKLE:
        case MOVE_ZIPPY_ZAP:
            return FALSE;
        default:
            return TRUE;
        }
    }
    else
    {
        u32 i, j;
        const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);

        //DebugPrintf("species = %d, move = %d", species, move);
        for (i = 0; i < ARRAY_COUNT(sUniversalMoves); i++)
        {
            if (sUniversalMoves[i] == move)
            {
                if (!gSpeciesInfo[species].tmIlliterate)
                {
                    if (move == MOVE_TERA_BLAST && GET_BASE_SPECIES_ID(species) == SPECIES_TERAPAGOS)
                        return FALSE;
                    if (GET_BASE_SPECIES_ID(species) == SPECIES_PYUKUMUKU && (move == MOVE_HIDDEN_POWER || move == MOVE_RETURN || move == MOVE_FRUSTRATION))
                        return FALSE;
                    return TRUE;
                }
                else
                {
                    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

                    if (P_TM_LITERACY < GEN_6)
                        return FALSE;

                    for (j = 0; j < MAX_LEVEL_UP_MOVES && learnset[j].move != LEVEL_UP_MOVE_END; j++)
                    {
                        if (learnset[j].move == move)
                            return TRUE;
                    }
                    return FALSE;
                }
            }
        }
        for (i = 0; teachableLearnset[i] != MOVE_UNAVAILABLE; i++)
        {
            if (teachableLearnset[i] == move)
                return TRUE;
        }
        return FALSE;
    }
}

u8 GetMoveRelearnerMoves(struct Pokemon *mon, u16 *moves)
{
    u16 learnedMoves[4];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    int i, j, k;

    for (i = 0; i < MAX_MON_MOVES; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < MAX_LEVEL_UP_MOVES; i++)
    {
        u16 moveLevel;

        if (learnset[i].move == LEVEL_UP_MOVE_END)
            break;

        moveLevel = learnset[i].level;

        if (moveLevel <= level)
        {
            for (j = 0; j < MAX_MON_MOVES && learnedMoves[j] != learnset[i].move; j++)
                ;

            if (j == MAX_MON_MOVES)
            {
                for (k = 0; k < numMoves && moves[k] != learnset[i].move; k++)
                    ;
            
                if(FlagGet(FLAG_RANDOM_MODE))
                {
                    if (k == numMoves)
                        moves[numMoves++] = GetRandomMove(learnset[i].move, species);
                }
                else
                {
                    if (k == numMoves)
                        moves[numMoves++] = learnset[i].move;
                }
            }
        }
    }

    return numMoves;
}

u8 GetLevelUpMovesBySpecies(u16 species, u16 *moves)
{
    u8 numMoves = 0;
    int i;
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    for (i = 0; i < MAX_LEVEL_UP_MOVES && learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (FlagGet(FLAG_RANDOM_MODE))
            moves[numMoves++] = GetRandomMove(Random(), species);
        else
            moves[numMoves++] = learnset[i].move;
    }
        

     return numMoves;
}

u8 GetNumberOfRelearnableMoves(struct Pokemon *mon)
{
    u16 learnedMoves[MAX_MON_MOVES];
    u16 moves[MAX_LEVEL_UP_MOVES];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    int i, j, k;

    if (species == SPECIES_EGG)
        return 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < MAX_LEVEL_UP_MOVES; i++)
    {
        u16 moveLevel;

        if (learnset[i].move == LEVEL_UP_MOVE_END)
            break;

        moveLevel = learnset[i].level;

        if (moveLevel <= level)
        {
            for (j = 0; j < MAX_MON_MOVES && learnedMoves[j] != learnset[i].move; j++)
                ;

            if (j == MAX_MON_MOVES)
            {
                for (k = 0; k < numMoves && moves[k] != learnset[i].move; k++)
                    ;

                if (k == numMoves)
                    moves[numMoves++] = learnset[i].move;
            }
        }
    }

    return numMoves;
}

u16 SpeciesToPokedexNum(u16 species)
{
    if (IsNationalPokedexEnabled())
    {
        return SpeciesToNationalPokedexNum(species);
    }
    else
    {
        species = SpeciesToHoennPokedexNum(species);
        if (species <= HOENN_DEX_COUNT)
            return species;
        return 0xFFFF;
    }
}

bool32 IsSpeciesInHoennDex(u16 species)
{
    if (SpeciesToHoennPokedexNum(species) > HOENN_DEX_COUNT)
        return FALSE;
    else
        return TRUE;
}

u16 GetBattleBGM(void)
{
    u8 trainerClass;
    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        trainerClass = GetFrontierOpponentClass(gTrainerBattleOpponent_A);
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        trainerClass = TRAINER_CLASS_EXPERT;
    else
        trainerClass = GetTrainerClassFromId(gTrainerBattleOpponent_A);

    if(trainerClass == TRAINER_CLASS_AQUA_LEADER)
        return MUS_VS_AQUA_MAGMA_LEADER;

    if((Random() % 10) <= 7)
    {
        switch (Random() % 26)
        {
            case 0:
                return MUS_VS_AQUA_MAGMA;
            case 1:
                return MUS_VS_GYM_LEADER;
            case 2:
                return MUS_VS_CHAMPION;
            case 3:
                return MUS_VS_RIVAL;
            case 4:
                return MUS_VS_ELITE_FOUR;
            case 5:
                return MUS_RG_VS_LEGEND;
            case 6:
                return MUS_VS_FRONTIER_BRAIN;
            case 7:        
                return MUS_HG_VS_TRAINER;    
            case 8:        
                return MUS_HG_VS_GYM_LEADER;  
            case 9:        
                return MUS_HG_VS_RIVAL;  
            case 10:        
                return MUS_HG_VS_ROCKET;  
            case 11:        
                return MUS_HG_VS_CHAMPION;  
            case 12:        
                return MUS_HG_VS_TRAINER_KANTO;  
            case 13:        
                return MUS_HG_VS_GYM_LEADER_KANTO;
            case 14:        
                return MUS_DP_VS_GYM_LEADER;
            case 15:        
                return MUS_DP_VS_TRAINER;
            case 16:        
                return MUS_DP_VS_GALACTIC_BOSS;
            case 17:        
                return MUS_DP_VS_CHAMPION;
            case 18:        
                return MUS_DP_VS_GALACTIC;
            case 19:        
                return MUS_DP_VS_RIVAL;
            case 20:        
                return MUS_HG_VS_GYM_LEADER_KANTO;
            case 21:        
                return MUS_HG_VS_GYM_LEADER_KANTO;      
            case 22:
                return MUS_DP_VS_GALACTIC_COMMANDER;
            case 23:         
                return MUS_DP_VS_ELITE_FOUR;                
            default:
                return MUS_VS_TRAINER;
        }
    }

    switch(Random() % 20)
    {
        case 0:
            return MUS_VS_RAYQUAZA;
        case 1:
            return MUS_VS_KYOGRE_GROUDON;
        case 2:
            return MUS_VS_REGI;
        case 3:
            return MUS_RG_VS_MEWTWO;
        case 4:
            return MUS_VS_MEW;
        case 5:
            return MUS_HG_VS_RAIKOU;
        case 6:
            return MUS_HG_VS_ENTEI;
        case 7:
            return MUS_HG_VS_SUICUNE;
        case 8:
            return MUS_HG_VS_LUGIA;
        case 9:
            return MUS_HG_VS_HO_OH;
        case 10:
            return MUS_HG_VS_WILD;
        case 11:
            return MUS_RG_VS_DEOXYS;
        case 12:
            return MUS_DP_VS_UXIE_MESPRIT_AZELF;
        case 13:
            return MUS_DP_VS_DIALGA_PALKIA;
        case 14:
            return MUS_DP_VS_LEGEND;
        case 15:
            return MUS_PL_VS_GIRATINA;
        case 16:
            return MUS_DP_VS_WILD;
        case 17:
            return MUS_DP_VS_ARCEUS;
        default:
            return MUS_VS_WILD;
    }
}


void PlayBattleBGM(void)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    PlayBGM(GetBattleBGM());
}

void PlayMapChosenOrBattleBGM(u16 songId)
{
    ResetMapMusic();
    m4aMPlayAllStop();
    if (songId)
        PlayNewMapMusic(songId);
    else
        PlayNewMapMusic(GetBattleBGM());
}

// Identical to PlayMapChosenOrBattleBGM, but uses a task instead
// Only used by Battle Dome
#define tSongId data[0]
void CreateTask_PlayMapChosenOrBattleBGM(u16 songId)
{
    u8 taskId;

    ResetMapMusic();
    m4aMPlayAllStop();

    taskId = CreateTask(Task_PlayMapChosenOrBattleBGM, 0);
    gTasks[taskId].tSongId = songId;
}

static void Task_PlayMapChosenOrBattleBGM(u8 taskId)
{
    if (gTasks[taskId].tSongId)
        PlayNewMapMusic(gTasks[taskId].tSongId);
    else
        PlayNewMapMusic(GetBattleBGM());
    DestroyTask(taskId);
}

#undef tSongId

const u32 *GetMonFrontSpritePal(struct Pokemon *mon)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, NULL);
    bool32 isShiny = GetMonData(mon, MON_DATA_IS_SHINY, NULL);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY, NULL);
    return GetMonSpritePalFromSpeciesAndPersonality(species, isShiny, personality);
}

const u32 *GetMonSpritePalFromSpeciesAndPersonality(u16 species, bool32 isShiny, u32 personality)
{
    return GetMonSpritePalFromSpecies(species, isShiny, IsPersonalityFemale(species, personality));
}

const u32 *GetMonSpritePalFromSpecies(u16 species, bool32 isShiny, bool32 isFemale)
{
    species = SanitizeSpeciesId(species);

    if (isShiny)
    {
        if (gSpeciesInfo[species].shinyPaletteFemale != NULL && isFemale)
            return gSpeciesInfo[species].shinyPaletteFemale;
        else if (gSpeciesInfo[species].shinyPalette != NULL)
            return gSpeciesInfo[species].shinyPalette;
        else
            return gSpeciesInfo[SPECIES_NONE].shinyPalette;
    }
    else
    {
        if (gSpeciesInfo[species].paletteFemale != NULL && isFemale)
            return gSpeciesInfo[species].paletteFemale;
        else if (gSpeciesInfo[species].palette != NULL)
            return gSpeciesInfo[species].palette;
        else
            return gSpeciesInfo[SPECIES_NONE].palette;
    }
}

bool8 IsMoveHM(u16 move)
{
    return FALSE;
}

bool8 IsMonSpriteNotFlipped(u16 species)
{
    return gSpeciesInfo[species].noFlip;
}

s8 GetMonFlavorRelation(struct Pokemon *mon, u8 flavor)
{
    u8 nature = GetNature(mon);
    return gPokeblockFlavorCompatibilityTable[nature * FLAVOR_COUNT + flavor];
}

s8 GetFlavorRelationByPersonality(u32 personality, u8 flavor)
{
    u8 nature = GetNatureFromPersonality(personality);
    return gPokeblockFlavorCompatibilityTable[nature * FLAVOR_COUNT + flavor];
}

bool8 IsTradedMon(struct Pokemon *mon)
{
    //u8 otName[PLAYER_NAME_LENGTH + 1];
    //u32 otId;
    //GetMonData(mon, MON_DATA_OT_NAME, otName);
    //otId = GetMonData(mon, MON_DATA_OT_ID, 0);
    return FALSE;
}

bool8 IsOtherTrainer(u32 otId, u8 *otName)
{
    if (otId ==
        (gSaveBlock2Ptr->playerTrainerId[0]
      | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
      | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
      | (gSaveBlock2Ptr->playerTrainerId[3] << 24)))
    {
        int i;
        for (i = 0; otName[i] != EOS; i++)
            if (otName[i] != gSaveBlock2Ptr->playerName[i])
                return TRUE;
        return FALSE;
    }

    return TRUE;
}

u16 GetAverageEVsFromParty(void)
{
    u16 averageEVs = 0;
    u16 totalEVs = 0;
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        totalEVs += GetMonData(&gPlayerParty[i], MON_DATA_HP_EV);
        totalEVs += GetMonData(&gPlayerParty[i], MON_DATA_ATK_EV);
        totalEVs += GetMonData(&gPlayerParty[i], MON_DATA_DEF_EV);
        totalEVs += GetMonData(&gPlayerParty[i], MON_DATA_SPEED_EV);
        totalEVs += GetMonData(&gPlayerParty[i], MON_DATA_SPATK_EV);
        totalEVs += GetMonData(&gPlayerParty[i], MON_DATA_SPDEF_EV);
    }

    averageEVs = totalEVs/CalculatePlayerPartyCount();
    DebugPrintf("party size = %d, averageEVs = %d", CalculatePlayerPartyCount(), averageEVs);

    return averageEVs;
}

void MonRestorePP(struct Pokemon *mon)
{
    BoxMonRestorePP(&mon->box);
}

void BoxMonRestorePP(struct BoxPokemon *boxMon)
{
    int i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0))
        {
            u16 move = GetBoxMonData(boxMon, MON_DATA_MOVE1 + i, 0);
            u16 bonus = GetBoxMonData(boxMon, MON_DATA_PP_BONUSES, 0);
            u8 pp = CalculatePPWithBonus(move, bonus, i);
            SetBoxMonData(boxMon, MON_DATA_PP1 + i, &pp);
        }
    }
}

void SetMonPreventsSwitchingString(void)
{
    gLastUsedAbility = gBattleStruct->abilityPreventingSwitchout;

    gBattleTextBuff1[0] = B_BUFF_PLACEHOLDER_BEGIN;
    gBattleTextBuff1[1] = B_BUFF_MON_NICK_WITH_PREFIX;
    gBattleTextBuff1[2] = gBattleStruct->battlerPreventingSwitchout;
    gBattleTextBuff1[4] = B_BUFF_EOS;

    if (GetBattlerSide(gBattleStruct->battlerPreventingSwitchout) == B_SIDE_PLAYER)
        gBattleTextBuff1[3] = GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[gBattleStruct->battlerPreventingSwitchout]);
    else
        gBattleTextBuff1[3] = gBattlerPartyIndexes[gBattleStruct->battlerPreventingSwitchout];

    PREPARE_MON_NICK_WITH_PREFIX_BUFFER(gBattleTextBuff2, gBattlerInMenuId, GetPartyIdFromBattlePartyId(gBattlerPartyIndexes[gBattlerInMenuId]))

    BattleStringExpandPlaceholders(gText_PkmnsXPreventsSwitching, gStringVar4);
}

static s32 GetWildMonTableIdInAlteringCave(u16 species)
{
    s32 i;
    for (i = 0; i < (s32) ARRAY_COUNT(sAlteringCaveWildMonHeldItems); i++)
        if (sAlteringCaveWildMonHeldItems[i].species == species)
            return i;
    return 0;
}

static inline bool32 CanFirstMonBoostHeldItemRarity(void)
{
    u32 ability;
    if (GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        return FALSE;

    ability = GetMonAbility(&gPlayerParty[0]);
    if (ability == ABILITY_COMPOUND_EYES)
        return TRUE;
    else if ((OW_SUPER_LUCK >= GEN_8) && ability == ABILITY_SUPER_LUCK)
        return TRUE;
    return FALSE;
}

void SetWildMonHeldItem(void)
{
    if (!(gBattleTypeFlags & (BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_TRAINER | BATTLE_TYPE_PYRAMID | BATTLE_TYPE_PIKE)))
    {
        u16 rnd;
        u16 species;
        u16 count = (WILD_DOUBLE_BATTLE) ? 2 : 1;
        u16 i;
        bool32 itemHeldBoost = CanFirstMonBoostHeldItemRarity();
        u16 chanceNoItem = itemHeldBoost ? 20 : 45;
        u16 chanceNotRare = itemHeldBoost ? 80 : 95;

        for (i = 0; i < count; i++)
        {
            if (GetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, NULL) != ITEM_NONE)
                continue; // prevent overwriting previously set item

            rnd = Random() % 100;
            species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES, 0);
            if (gMapHeader.mapLayoutId == LAYOUT_ALTERING_CAVE)
            {
                s32 alteringCaveId = GetWildMonTableIdInAlteringCave(species);
                if (alteringCaveId != 0)
                {
                    // In active Altering Cave, use special item list
                    if (rnd < chanceNotRare)
                        continue;
                    SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &sAlteringCaveWildMonHeldItems[alteringCaveId].item);
                }
                else
                {
                    // In inactive Altering Cave, use normal items
                    if (rnd < chanceNoItem)
                        continue;
                    if (rnd < chanceNotRare)
                        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemCommon);
                    else
                        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemRare);
                }
            }
            else
            {
                if (gSpeciesInfo[species].itemCommon == gSpeciesInfo[species].itemRare && gSpeciesInfo[species].itemCommon != ITEM_NONE)
                {
                    // Both held items are the same, 100% chance to hold item
                    SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemCommon);
                }
                else
                {
                    if (rnd < chanceNoItem)
                        continue;
                    if (rnd < chanceNotRare)
                        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemCommon);
                    else
                        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gSpeciesInfo[species].itemRare);
                }
            }
        }
    }
}

bool8 IsMonShiny(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_IS_SHINY, NULL);
}

const u8 *GetTrainerPartnerName(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        if (gPartnerTrainerId == TRAINER_PARTNER(PARTNER_STEVEN))
        {
            return GetTrainerNameFromId(TRAINER_STEVEN);
        }
        else
        {
            GetFrontierTrainerName(gStringVar1, gPartnerTrainerId);
            return gStringVar1;
        }
    }
    else
    {
        u8 id = GetMultiplayerId();
        return gLinkPlayers[GetBattlerMultiplayerId(gLinkPlayers[id].id ^ 2)].name;
    }
}

#define READ_PTR_FROM_TASK(taskId, dataId)                      \
    (void *)(                                                   \
    ((u16)(gTasks[taskId].data[dataId]) |                       \
    ((u16)(gTasks[taskId].data[dataId + 1]) << 16)))

#define STORE_PTR_IN_TASK(ptr, taskId, dataId)                 \
{                                                              \
    gTasks[taskId].data[dataId] = (u32)(ptr);                  \
    gTasks[taskId].data[dataId + 1] = (u32)(ptr) >> 16;        \
}

#define sAnimId    data[2]
#define sAnimDelay data[3]

static void Task_AnimateAfterDelay(u8 taskId)
{
    if (--gTasks[taskId].sAnimDelay == 0)
    {
        LaunchAnimationTaskForFrontSprite(READ_PTR_FROM_TASK(taskId, 0), gTasks[taskId].sAnimId);
        DestroyTask(taskId);
    }
}

#define tIsShadow data[4]

static void Task_PokemonSummaryAnimateAfterDelay(u8 taskId)
{
    if (--gTasks[taskId].sAnimDelay == 0)
    {
        StartMonSummaryAnimation(READ_PTR_FROM_TASK(taskId, 0), gTasks[taskId].sAnimId);
        if (gTasks[taskId].tIsShadow)
            SummaryScreen_SetShadowAnimDelayTaskId_BW(TASK_NONE); // needed to track anim delay task for mon shadow in BW summary screen
        else
            SummaryScreen_SetAnimDelayTaskId(TASK_NONE);

        DestroyTask(taskId);
    }
}

void BattleAnimateFrontSprite(struct Sprite *sprite, u16 species, bool8 noCry, u8 panMode)
{
    if (gHitMarker & HITMARKER_NO_ANIMATIONS && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
        DoMonFrontSpriteAnimation(sprite, species, noCry, panMode | SKIP_FRONT_ANIM);
    else
        DoMonFrontSpriteAnimation(sprite, species, noCry, panMode);
}

void DoMonFrontSpriteAnimation(struct Sprite *sprite, u16 species, bool8 noCry, u8 panModeAnimFlag)
{
    s8 pan;
    switch (panModeAnimFlag & (u8)~SKIP_FRONT_ANIM) // Exclude anim flag to get pan mode
    {
    case 0:
        pan = -25;
        break;
    case 1:
        pan = 25;
        break;
    default:
        pan = 0;
        break;
    }
    if (panModeAnimFlag & SKIP_FRONT_ANIM)
    {
        // No animation, only check if cry needs to be played
        if (!noCry)
            PlayCry_Normal(species, pan);
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        if (!noCry)
        {
            PlayCry_Normal(species, pan);
            if (HasTwoFramesAnimation(species))
                StartSpriteAnim(sprite, 1);
        }
        if (gSpeciesInfo[species].frontAnimDelay != 0)
        {
            // Animation has delay, start delay task
            u8 taskId = CreateTask(Task_AnimateAfterDelay, 0);
            STORE_PTR_IN_TASK(sprite, taskId, 0);
            gTasks[taskId].sAnimId = gSpeciesInfo[species].frontAnimId;
            gTasks[taskId].sAnimDelay = gSpeciesInfo[species].frontAnimDelay;
        }
        else
        {
            // No delay, start animation
            LaunchAnimationTaskForFrontSprite(sprite, gSpeciesInfo[species].frontAnimId);
        }
        sprite->callback = SpriteCallbackDummy_2;
    }
}

void PokemonSummaryDoMonAnimation(struct Sprite *sprite, u16 species, bool8 oneFrame, bool32 isShadow)
{
    if (!oneFrame && HasTwoFramesAnimation(species))
        StartSpriteAnim(sprite, 1);
    if (gSpeciesInfo[species].frontAnimDelay != 0)
    {
        // Animation has delay, start delay task
        u8 taskId = CreateTask(Task_PokemonSummaryAnimateAfterDelay, 0);
        STORE_PTR_IN_TASK(sprite, taskId, 0);
        gTasks[taskId].sAnimId = gSpeciesInfo[species].frontAnimId;
        gTasks[taskId].sAnimDelay = gSpeciesInfo[species].frontAnimDelay;
        gTasks[taskId].tIsShadow = isShadow;  // needed to track anim delay task for mon shadow in BW summary screen

        if (isShadow)
            SummaryScreen_SetShadowAnimDelayTaskId_BW(taskId);
        else
            SummaryScreen_SetAnimDelayTaskId(taskId);

        SetSpriteCB_MonAnimDummy(sprite);
    }
    else
    {
        // No delay, start animation
        StartMonSummaryAnimation(sprite, gSpeciesInfo[species].frontAnimId);
    }
}

#define tIsShadow data[4]

void StopPokemonAnimationDelayTask(void)
{
    u8 delayTaskId = FindTaskIdByFunc(Task_PokemonSummaryAnimateAfterDelay);
    if (delayTaskId != TASK_NONE)
        DestroyTask(delayTaskId);
}

void BattleAnimateBackSprite(struct Sprite *sprite, u16 species)
{
    if (gHitMarker & HITMARKER_NO_ANIMATIONS && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
    {
        sprite->callback = SpriteCallbackDummy;
    }
    else
    {
        LaunchAnimationTaskForBackSprite(sprite, GetSpeciesBackAnimSet(species));
        sprite->callback = SpriteCallbackDummy_2;
    }
}

// Identical to GetOpposingLinkMultiBattlerId but for the player
// "rightSide" from that team's perspective, i.e. B_POSITION_*_RIGHT
static u8 UNUSED GetOwnOpposingLinkMultiBattlerId(bool8 rightSide)
{
    s32 i;
    s32 battlerId = 0;
    u8 multiplayerId = GetMultiplayerId();
    switch (gLinkPlayers[multiplayerId].id)
    {
    case 0:
    case 2:
        battlerId = rightSide ? 1 : 3;
        break;
    case 1:
    case 3:
        battlerId = rightSide ? 2 : 0;
        break;
    }
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayers[i].id == (s16)battlerId)
            break;
    }
    return i;
}

u8 GetOpposingLinkMultiBattlerId(bool8 rightSide, u8 multiplayerId)
{
    s32 i;
    s32 battlerId = 0;
    switch (gLinkPlayers[multiplayerId].id)
    {
    case 0:
    case 2:
        battlerId = rightSide ? 1 : 3;
        break;
    case 1:
    case 3:
        battlerId = rightSide ? 2 : 0;
        break;
    }
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayers[i].id == (s16)battlerId)
            break;
    }
    return i;
}

u16 FacilityClassToPicIndex(u16 facilityClass)
{
    return gFacilityClassToPicIndex[facilityClass];
}

u16 PlayerGenderToFrontTrainerPicId(u8 playerGender)
{
    return ReturnAvatarTrainerFrontPicId(gSaveBlock2Ptr->playerGfxType);
}

void HandleSetPokedexFlag(u16 nationalNum, u8 caseId, u32 personality)
{
    u8 getFlagCaseId = (caseId == FLAG_SET_SEEN) ? FLAG_GET_SEEN : FLAG_GET_CAUGHT;
    if (!GetSetPokedexFlag(nationalNum, getFlagCaseId)) // don't set if it's already set
    {
        GetSetPokedexFlag(nationalNum, caseId);
        if (NationalPokedexNumToSpecies(nationalNum) == SPECIES_UNOWN)
            gSaveBlock2Ptr->pokedex.unownPersonality = personality;
        if (NationalPokedexNumToSpecies(nationalNum) == SPECIES_SPINDA)
            gSaveBlock2Ptr->pokedex.spindaPersonality = personality;
    }
}

bool8 HasTwoFramesAnimation(u16 species)
{
    return P_TWO_FRAME_FRONT_SPRITES && species != SPECIES_UNOWN;
}

static bool8 ShouldSkipFriendshipChange(void)
{
    if (gMain.inBattle && gBattleTypeFlags & (BATTLE_TYPE_FRONTIER))
        return TRUE;
    if (!gMain.inBattle && (InBattlePike() || InBattlePyramid()))
        return TRUE;
    return FALSE;
}

// The below functions are for the 'MonSpritesGfxManager', a method of allocating
// space for Pokémon sprites. These are only used for the summary screen Pokémon
// sprites (unless gMonSpritesGfxPtr is in use), but were set up for more general use.
// Only the 'default' mode (MON_SPR_GFX_MODE_NORMAL) is used, which is set
// up to allocate 4 sprites using the battler sprite templates (gBattlerSpriteTemplates).
// MON_SPR_GFX_MODE_BATTLE is identical but never used.
// MON_SPR_GFX_MODE_FULL_PARTY is set up to allocate 7 sprites (party + trainer?)
// using a generic 64x64 template, and is also never used.

// Between the unnecessarily large sizes below, a mistake allocating the spritePointers
// field, and the fact that ultimately only 1 of the 4 sprite positions is used, this
// system wastes a good deal of memory.

#define ALLOC_FAIL_BUFFER (1 << 0)
#define ALLOC_FAIL_STRUCT (1 << 1)
#define GFX_MANAGER_ACTIVE 0xA3 // Arbitrary value

static void InitMonSpritesGfx_Battle(struct MonSpritesGfxManager* gfx)
{
    u16 i, j;
    for (i = 0; i < gfx->numSprites; i++)
    {
        gfx->templates[i] = gBattlerSpriteTemplates[i];
        for (j = 0; j < gfx->numFrames; j++)
            gfx->frameImages[i * gfx->numFrames + j].data = &gfx->spritePointers[i][j * MON_PIC_SIZE];

        gfx->templates[i].images = &gfx->frameImages[i * gfx->numFrames];
    }
}

static void InitMonSpritesGfx_FullParty(struct MonSpritesGfxManager* gfx)
{
    u16 i, j;
    for (i = 0; i < gfx->numSprites; i++)
    {
        gfx->templates[i] = sSpriteTemplate_64x64;
        for (j = 0; j < gfx->numFrames; j++)
            gfx->frameImages[i * gfx->numSprites + j].data = &gfx->spritePointers[i][j * MON_PIC_SIZE];

        gfx->templates[i].images = &gfx->frameImages[i * gfx->numSprites];
        gfx->templates[i].anims = gAnims_MonPic;
        gfx->templates[i].paletteTag = i;
    }
}

struct MonSpritesGfxManager *CreateMonSpritesGfxManager(u8 managerId, u8 mode)
{
    u8 i;
    u8 failureFlags;
    struct MonSpritesGfxManager *gfx;

    failureFlags = 0;
    managerId %= MON_SPR_GFX_MANAGERS_COUNT;
    gfx = AllocZeroed(sizeof(*gfx));
    if (gfx == NULL)
        return NULL;

    switch (mode)
    {
    case MON_SPR_GFX_MODE_FULL_PARTY:
        gfx->numSprites = PARTY_SIZE + 1;
        gfx->numSprites2 = PARTY_SIZE + 1;
        gfx->numFrames = MAX_MON_PIC_FRAMES;
        gfx->dataSize = 1;
        gfx->mode = MON_SPR_GFX_MODE_FULL_PARTY;
        break;
 // case MON_SPR_GFX_MODE_BATTLE:
    case MON_SPR_GFX_MODE_NORMAL:
    default:
        gfx->numSprites = MAX_BATTLERS_COUNT;
        gfx->numSprites2 = MAX_BATTLERS_COUNT;
        gfx->numFrames = MAX_MON_PIC_FRAMES;
        gfx->dataSize = 1;
        gfx->mode = MON_SPR_GFX_MODE_NORMAL;
        break;
    }

    // Set up sprite / sprite pointer buffers
    gfx->spriteBuffer = AllocZeroed(gfx->dataSize * MON_PIC_SIZE * MAX_MON_PIC_FRAMES * gfx->numSprites);
    gfx->spritePointers = AllocZeroed(gfx->numSprites * 32); // ? Only * 4 is necessary, perhaps they were thinking bits.
    if (gfx->spriteBuffer == NULL || gfx->spritePointers == NULL)
    {
        failureFlags |= ALLOC_FAIL_BUFFER;
    }
    else
    {
        for (i = 0; i < gfx->numSprites; i++)
            gfx->spritePointers[i] = gfx->spriteBuffer + (gfx->dataSize * MON_PIC_SIZE * MAX_MON_PIC_FRAMES * i);
    }

    // Set up sprite structs
    gfx->templates = AllocZeroed(sizeof(struct SpriteTemplate) * gfx->numSprites);
    gfx->frameImages = AllocZeroed(sizeof(struct SpriteFrameImage) * gfx->numSprites * gfx->numFrames);
    if (gfx->templates == NULL || gfx->frameImages == NULL)
    {
        failureFlags |= ALLOC_FAIL_STRUCT;
    }
    else
    {
        for (i = 0; i < gfx->numFrames * gfx->numSprites; i++)
            gfx->frameImages[i].size = MON_PIC_SIZE;

        switch (gfx->mode)
        {
        case MON_SPR_GFX_MODE_FULL_PARTY:
            InitMonSpritesGfx_FullParty(gfx);
            break;
        case MON_SPR_GFX_MODE_NORMAL:
        case MON_SPR_GFX_MODE_BATTLE:
        default:
            InitMonSpritesGfx_Battle(gfx);
            break;
        }
    }

    // If either of the allocations failed free their respective members
    if (failureFlags & ALLOC_FAIL_STRUCT)
    {
        TRY_FREE_AND_SET_NULL(gfx->frameImages);
        TRY_FREE_AND_SET_NULL(gfx->templates);
    }
    if (failureFlags & ALLOC_FAIL_BUFFER)
    {
        TRY_FREE_AND_SET_NULL(gfx->spritePointers);
        TRY_FREE_AND_SET_NULL(gfx->spriteBuffer);
    }

    if (failureFlags)
    {
        // Clear, something failed to allocate
        memset(gfx, 0, sizeof(*gfx));
        Free(gfx);
    }
    else
    {
        gfx->active = GFX_MANAGER_ACTIVE;
        sMonSpritesGfxManagers[managerId] = gfx;
    }

    return sMonSpritesGfxManagers[managerId];
}

void DestroyMonSpritesGfxManager(u8 managerId)
{
    struct MonSpritesGfxManager *gfx;

    managerId %= MON_SPR_GFX_MANAGERS_COUNT;
    gfx = sMonSpritesGfxManagers[managerId];
    if (gfx == NULL)
        return;

    if (gfx->active != GFX_MANAGER_ACTIVE)
    {
        memset(gfx, 0, sizeof(*gfx));
    }
    else
    {
        TRY_FREE_AND_SET_NULL(gfx->frameImages);
        TRY_FREE_AND_SET_NULL(gfx->templates);
        TRY_FREE_AND_SET_NULL(gfx->spritePointers);
        TRY_FREE_AND_SET_NULL(gfx->spriteBuffer);
        memset(gfx, 0, sizeof(*gfx));
        Free(gfx);
    }
}

u8 *MonSpritesGfxManager_GetSpritePtr(u8 managerId, u8 spriteNum)
{
    struct MonSpritesGfxManager *gfx = sMonSpritesGfxManagers[managerId % MON_SPR_GFX_MANAGERS_COUNT];
    if (gfx->active != GFX_MANAGER_ACTIVE)
    {
        return NULL;
    }
    else
    {
        if (spriteNum >= gfx->numSprites)
            spriteNum = 0;

        return gfx->spritePointers[spriteNum];
    }
}

u16 GetFormSpeciesId(u16 speciesId, u8 formId)
{
    if (GetSpeciesFormTable(speciesId) != NULL)
        return GetSpeciesFormTable(speciesId)[formId];
    else
        return speciesId;
}

u8 GetFormIdFromFormSpeciesId(u16 formSpeciesId)
{
    u8 targetFormId = 0;

    if (GetSpeciesFormTable(formSpeciesId) != NULL)
    {
        for (targetFormId = 0; GetSpeciesFormTable(formSpeciesId)[targetFormId] != FORM_SPECIES_END; targetFormId++)
        {
            if (formSpeciesId == GetSpeciesFormTable(formSpeciesId)[targetFormId])
                break;
        }
    }
    return targetFormId;
}

u16 GetFormChangeTargetSpecies(struct Pokemon *mon, u16 method, u32 arg)
{
    return GetFormChangeTargetSpeciesBoxMon(&mon->box, method, arg);
}

// Returns SPECIES_NONE if no form change is possible
u16 GetFormChangeTargetSpeciesBoxMon(struct BoxPokemon *boxMon, u16 method, u32 arg)
{
    u32 i;
    u16 targetSpecies = SPECIES_NONE;
    u16 species = GetBoxMonData(boxMon, MON_DATA_SPECIES, NULL);
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);
    u16 heldItem;
    u32 ability;

    if (formChanges != NULL)
    {
        heldItem = GetBoxMonData(boxMon, MON_DATA_HELD_ITEM, NULL);
        ability = GetAbilityBySpecies(species, GetBoxMonData(boxMon, MON_DATA_ABILITY_NUM, NULL));

        for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
        {
            if (method == formChanges[i].method && species != formChanges[i].targetSpecies)
            {
                switch (method)
                {
                case FORM_CHANGE_ITEM_HOLD:
                    if ((heldItem == formChanges[i].param1 || formChanges[i].param1 == ITEM_NONE)
                     && (ability == formChanges[i].param2 || formChanges[i].param2 == ABILITY_NONE))
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_ITEM_USE:
                    if (arg == formChanges[i].param1)
                    {
                        bool32 pass = TRUE;
                        switch (formChanges[i].param2)
                        {
                        case DAY:
                            if (GetTimeOfDay() == TIME_NIGHT)
                                pass = FALSE;
                            break;
                        case NIGHT:
                            if (GetTimeOfDay() != TIME_NIGHT)
                                pass = FALSE;
                            break;
                        }

                        if (formChanges[i].param3 != STATUS1_NONE && GetBoxMonData(boxMon, MON_DATA_STATUS, NULL) & formChanges[i].param3)
                            pass = FALSE;

                        if (pass)
                            targetSpecies = formChanges[i].targetSpecies;
                    }
                    break;
                case FORM_CHANGE_ITEM_USE_MULTICHOICE:
                    if (arg == formChanges[i].param1)
                    {
                        if (formChanges[i].param2 == gSpecialVar_Result)
                            targetSpecies = formChanges[i].targetSpecies;
                    }
                    break;
                case FORM_CHANGE_MOVE:
                    if (BoxMonKnowsMove(boxMon, formChanges[i].param1) != formChanges[i].param2)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_BEGIN_BATTLE:
                case FORM_CHANGE_END_BATTLE:
                    if (heldItem == formChanges[i].param1 || formChanges[i].param1 == ITEM_NONE)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_END_BATTLE_TERRAIN:
                    if (gBattleTerrain == formChanges[i].param1)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_WITHDRAW:
                case FORM_CHANGE_FAINT:
                case FORM_CHANGE_DAYS_PASSED:
                    targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_STATUS:
                    if (GetBoxMonData(boxMon, MON_DATA_STATUS, NULL) & formChanges[i].param1)
                        targetSpecies = formChanges[i].targetSpecies;
                    break;
                case FORM_CHANGE_TIME_OF_DAY:
                    switch (formChanges[i].param1)
                    {
                    case DAY:
                        if (GetTimeOfDay() != TIME_NIGHT)
                            targetSpecies = formChanges[i].targetSpecies;
                        break;
                    case NIGHT:
                        if (GetTimeOfDay() == TIME_NIGHT)
                            targetSpecies = formChanges[i].targetSpecies;
                        break;
                    }
                    break;
                }
            }
        }
    }

    return targetSpecies;
}

void TrySetDayLimitToFormChange(struct Pokemon *mon)
{
    u32 i;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == FORM_CHANGE_DAYS_PASSED && species != formChanges[i].targetSpecies)
        {
            SetMonData(mon, MON_DATA_DAYS_SINCE_FORM_CHANGE, &formChanges[i].param1);
            break;
        }
    }
}

bool32 DoesSpeciesHaveFormChangeMethod(u16 species, u16 method)
{
    u32 i;
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (formChanges != NULL)
    {
        for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
        {
            if (method == formChanges[i].method && species != formChanges[i].targetSpecies)
                return TRUE;
        }
    }

    return FALSE;
}

u16 MonTryLearningNewMoveEvolution(struct Pokemon *mon, bool8 firstMove)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);

    // Since you can learn more than one move per level,
    // the game needs to know whether you decided to
    // learn it or keep the old set to avoid asking
    // you to learn the same move over and over again.
    if (firstMove)
    {
        sLearningMoveTableID = 0;
    }
    while(learnset[sLearningMoveTableID].move != LEVEL_UP_MOVE_END)
    {
        while (learnset[sLearningMoveTableID].level == 0 || learnset[sLearningMoveTableID].level == level)
        {
        
            if(FlagGet(FLAG_RANDOM_MODE))
                gMoveToLearn = GetRandomMove(Random(), species);
            else
                gMoveToLearn = learnset[sLearningMoveTableID].move;

            sLearningMoveTableID++;
            return GiveMoveToMon(mon, gMoveToLearn);
        }
        sLearningMoveTableID++;
    }
    return 0;
}

static void RemoveIVIndexFromList(u8 *ivs, u8 selectedIv)
{
    s32 i, j;
    u8 temp[NUM_STATS];

    ivs[selectedIv] = 0xFF;
    for (i = 0; i < NUM_STATS; i++)
    {
        temp[i] = ivs[i];
    }

    j = 0;
    for (i = 0; i < NUM_STATS; i++)
    {
        if (temp[i] != 0xFF)
            ivs[j++] = temp[i];
    }
}

// Attempts to perform non-level/item related overworld evolutions; called by tryspecialevo command.
void TrySpecialOverworldEvo(void)
{
    u8 i;
    u8 evoMethod = gSpecialVar_0x8000;
    u16 canStopEvo = gSpecialVar_0x8001;
    u16 tryMultiple = gSpecialVar_0x8002;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 targetSpecies = GetEvolutionTargetSpecies(&gPlayerParty[i], EVO_MODE_OVERWORLD_SPECIAL, evoMethod, SPECIES_NONE);
        if (targetSpecies != SPECIES_NONE && !(sTriedEvolving & gBitTable[i]))
        {
            sTriedEvolving |= gBitTable[i];
            if(gMain.callback2 == TrySpecialOverworldEvo) // This fixes small graphics glitches.
                EvolutionScene(&gPlayerParty[i], targetSpecies, canStopEvo, i);
            else
                BeginEvolutionScene(&gPlayerParty[i], targetSpecies, canStopEvo, i);
            if (tryMultiple)
                gCB2_AfterEvolution = TrySpecialOverworldEvo;
            else
                gCB2_AfterEvolution = CB2_ReturnToField;
            return;
        }
    }

    sTriedEvolving = 0;
    SetMainCallback2(CB2_ReturnToField);
}

void TryLevelUpOverworldEvo(void)
{
    u8 i;
    if(!(FlagGet(FLAG_NO_EXP_MODE)))
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 targetSpecies = GetEvolutionTargetSpecies(&gPlayerParty[i], EVO_MODE_NORMAL, ITEM_NONE, SPECIES_NONE);
        if (targetSpecies != SPECIES_NONE && !(sTriedEvolving & gBitTable[i]))
        {
            sTriedEvolving |= gBitTable[i];
            if(gMain.callback2 == TryLevelUpOverworldEvo) // This fixes small graphics glitches.
                EvolutionScene(&gPlayerParty[i], targetSpecies, TRUE, i);
            else
                BeginEvolutionScene(&gPlayerParty[i], targetSpecies, TRUE, i);
            gCB2_AfterEvolution = TryLevelUpOverworldEvo;
            return;
        }
    }
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if((sTriedEvolving & gBitTable[i]))
        {
            sTriedEvolving = 0;
            gFieldCallback = FieldCB_ContinueScriptPlease;
            SetMainCallback2(CB2_ReturnToField);
            return;
        }
    }
    sTriedEvolving = 0;
    return;    
}

bool32 SpeciesHasGenderDifferences(u16 species)
{
    if (gSpeciesInfo[species].frontPicFemale != NULL
     || gSpeciesInfo[species].paletteFemale != NULL
     || gSpeciesInfo[species].backPicFemale != NULL
     || gSpeciesInfo[species].shinyPaletteFemale != NULL
     || gSpeciesInfo[species].iconSpriteFemale != NULL)
        return TRUE;

    return FALSE;
}

bool32 TryFormChange(u32 monId, u32 side, u16 method)
{
    struct Pokemon *party = (side == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
    u16 targetSpecies;

    if (GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_NONE
     || GetMonData(&party[monId], MON_DATA_SPECIES_OR_EGG, 0) == SPECIES_EGG)
        return FALSE;

    targetSpecies = GetFormChangeTargetSpecies(&party[monId], method, 0);

    if (targetSpecies == SPECIES_NONE && gBattleStruct != NULL)
        targetSpecies = gBattleStruct->changedSpecies[side][monId];

    if (targetSpecies != SPECIES_NONE)
    {
        TryToSetBattleFormChangeMoves(&party[monId], method);
        SetMonData(&party[monId], MON_DATA_SPECIES, &targetSpecies);
        CalculateMonStats(&party[monId]);
        return TRUE;
    }

    return FALSE;
}

u16 SanitizeSpeciesId(u16 species)
{
    if (species > NUM_SPECIES || !IsSpeciesEnabled(species))
        return SPECIES_NONE;
    else
        return species;
}

bool32 IsSpeciesEnabled(u16 species)
{
    return gSpeciesInfo[species].baseHP > 0 || species == SPECIES_EGG;
}

void TryToSetBattleFormChangeMoves(struct Pokemon *mon, u16 method)
{
    int i, j;
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (formChanges == NULL
        || (method != FORM_CHANGE_BEGIN_BATTLE && method != FORM_CHANGE_END_BATTLE))
        return;

    for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
    {
        if (formChanges[i].method == method
            && formChanges[i].param2
            && formChanges[i].param3
            && formChanges[i].targetSpecies != species)
        {
            u16 originalMove = formChanges[i].param2;
            u16 newMove = formChanges[i].param3;

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                u16 currMove = GetMonData(mon, MON_DATA_MOVE1 + j, NULL);
                if (currMove == originalMove)
                    SetMonMoveSlot_KeepPP(mon, newMove, j);
            }
            break;
        }
    }
}

u32 GetMonFriendshipScore(struct Pokemon *pokemon)
{
    u32 friendshipScore = GetMonData(pokemon, MON_DATA_FRIENDSHIP, NULL);

    if (friendshipScore == MAX_FRIENDSHIP)
        return FRIENDSHIP_MAX;
    if (friendshipScore >= 200)
        return FRIENDSHIP_200_TO_254;
    if (friendshipScore >= 150)
        return FRIENDSHIP_150_TO_199;
    if (friendshipScore >= 100)
        return FRIENDSHIP_100_TO_149;
    if (friendshipScore >= 50)
        return FRIENDSHIP_50_TO_99;
    if (friendshipScore >= 1)
        return FRIENDSHIP_1_TO_49;

    return FRIENDSHIP_NONE;
}

u32 GetMonAffectionHearts(struct Pokemon *pokemon)
{
    u32 friendship = GetMonData(pokemon, MON_DATA_FRIENDSHIP, NULL);

    if (friendship == MAX_FRIENDSHIP)
        return AFFECTION_FIVE_HEARTS;
    if (friendship >= 220)
        return AFFECTION_FOUR_HEARTS;
    if (friendship >= 180)
        return AFFECTION_THREE_HEARTS;
    if (friendship >= 130)
        return AFFECTION_TWO_HEARTS;
    if (friendship >= 80)
        return AFFECTION_ONE_HEART;

    return AFFECTION_NO_HEARTS;
}

void UpdateMonPersonality(struct BoxPokemon *boxMon, u32 personality)
{
    struct PokemonSubstruct0 *old0, *new0;
    struct PokemonSubstruct1 *old1, *new1;
    struct PokemonSubstruct2 *old2, *new2;
    struct PokemonSubstruct3 *old3, *new3;
    struct BoxPokemon old;

    bool32 isShiny = GetBoxMonData(boxMon, MON_DATA_IS_SHINY, NULL);
    u32 hiddenNature = GetBoxMonData(boxMon, MON_DATA_HIDDEN_NATURE, NULL);
    u32 teraType = GetBoxMonData(boxMon, MON_DATA_TERA_TYPE, NULL);

    old = *boxMon;
    old0 = &(GetSubstruct(&old, old.personality, 0)->type0);
    old1 = &(GetSubstruct(&old, old.personality, 1)->type1);
    old2 = &(GetSubstruct(&old, old.personality, 2)->type2);
    old3 = &(GetSubstruct(&old, old.personality, 3)->type3);

    new0 = &(GetSubstruct(boxMon, personality, 0)->type0);
    new1 = &(GetSubstruct(boxMon, personality, 1)->type1);
    new2 = &(GetSubstruct(boxMon, personality, 2)->type2);
    new3 = &(GetSubstruct(boxMon, personality, 3)->type3);

    DecryptBoxMon(&old);
    boxMon->personality = personality;
    *new0 = *old0;
    *new1 = *old1;
    *new2 = *old2;
    *new3 = *old3;
    boxMon->checksum = CalculateBoxMonChecksum(boxMon);
    EncryptBoxMon(boxMon);

    SetBoxMonData(boxMon, MON_DATA_IS_SHINY, &isShiny);
    SetBoxMonData(boxMon, MON_DATA_HIDDEN_NATURE, &hiddenNature);
    SetBoxMonData(boxMon, MON_DATA_TERA_TYPE, &teraType);
}

void HealPokemon(struct Pokemon *mon)
{
    u32 data;

    data = GetMonData(mon, MON_DATA_MAX_HP);
    SetMonData(mon, MON_DATA_HP, &data);

    data = STATUS1_NONE;
    SetMonData(mon, MON_DATA_STATUS, &data);

    MonRestorePP(mon);
}

void HealBoxPokemon(struct BoxPokemon *boxMon)
{
    u32 data;

    data = 0;
    SetBoxMonData(boxMon, MON_DATA_HP_LOST, &data);

    data = STATUS1_NONE;
    SetBoxMonData(boxMon, MON_DATA_STATUS, &data);

    BoxMonRestorePP(boxMon);
}

u16 GetCryIdBySpecies(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (P_CRIES_ENABLED == FALSE || gSpeciesInfo[species].cryId >= CRY_COUNT)
        return CRY_NONE;
    return gSpeciesInfo[species].cryId;
}

u16 GetSpeciesPreEvolution(u16 species)
{
    int i, j;

    for (i = SPECIES_BULBASAUR; i < NUM_SPECIES; i++)
    {
        const struct Evolution *evolutions = GetSpeciesEvolutions(i);
        if (evolutions == NULL)
            continue;
        for (j = 0; evolutions[j].method != EVOLUTIONS_END; j++)
        {
            if (SanitizeSpeciesId(evolutions[j].targetSpecies) == species)
                return i;
        }
    }

    return SPECIES_NONE;
}

//*********************** //tx_randomizer_and_challenges
#define EVO_TYPE_0 0
#define EVO_TYPE_1 1
#define EVO_TYPE_2 2
#define EVO_TYPE_SELF 3
#define EVO_TYPE_LEGENDARY 4

const u8 gRandomizationTypes[7][25] =
{
    [TX_RANDOM_T_WILD_POKEMON]    = _("TX RANDOM WILD PKMN"),
    [TX_RANDOM_T_TRAINER]         = _("TX RANDOM TRAINER  "),
    [TX_RANDOM_T_MOVES]           = _("TX RANDOM MOVES    "),
    [TX_RANDOM_T_ABILITY]         = _("TX RANDOM ABILITY  "),
    [TX_RANDOM_T_EVO]             = _("TX RANDOM EVO      "),
    [TX_RANDOM_T_EVO_METH]        = _("TX RANDOM EVO METH "),
    [TX_RANDOM_T_STATIC]          = _("TX RANDOM STATIC   "),
};
const u8 gEvoStages[5][20] = 
{
    [EVO_TYPE_0]            = _("EVO TYPE 0"),
    [EVO_TYPE_1]            = _("EVO TYPE 1"),
    [EVO_TYPE_2]            = _("EVO TYPE 2"),
    [EVO_TYPE_SELF]         = _("EVO TYPE SELF"),
    [EVO_TYPE_LEGENDARY]    = _("EVO TYPE LEGENDARY"),
};

#define RANDOM_SPECIES_COUNT_LEGENDARY ARRAY_COUNT(sRandomSpeciesLegendary)
static const u16 sRandomSpeciesLegendary[] =
{
    //SPECIES_NONE                    ,
    SPECIES_BULBASAUR               ,
    SPECIES_IVYSAUR                 ,
    SPECIES_VENUSAUR                ,
    SPECIES_CHARMANDER              ,
    SPECIES_CHARMELEON              ,
    SPECIES_CHARIZARD               ,
    SPECIES_SQUIRTLE                ,
    SPECIES_WARTORTLE               ,
    SPECIES_BLASTOISE               ,
    SPECIES_CATERPIE                ,
    SPECIES_METAPOD                 ,
    SPECIES_BUTTERFREE              ,
    SPECIES_WEEDLE                  ,
    SPECIES_KAKUNA                  ,
    SPECIES_BEEDRILL                ,
    SPECIES_PIDGEY                  ,
    SPECIES_PIDGEOTTO               ,
    SPECIES_PIDGEOT                 ,
    SPECIES_RATTATA                 ,
    SPECIES_RATICATE                ,
    SPECIES_SPEAROW                 ,
    SPECIES_FEAROW                  ,
    SPECIES_EKANS                   ,
    SPECIES_ARBOK                   ,
    SPECIES_PIKACHU                 ,
    SPECIES_RAICHU                  ,
    SPECIES_SANDSHREW               ,
    SPECIES_SANDSLASH               ,
    SPECIES_NIDORAN_F               ,
    SPECIES_NIDORINA                ,
    SPECIES_NIDOQUEEN               ,
    SPECIES_NIDORAN_M               ,
    SPECIES_NIDORINO                ,
    SPECIES_NIDOKING                ,
    SPECIES_CLEFAIRY                ,
    SPECIES_CLEFABLE                ,
    SPECIES_VULPIX                  ,
    SPECIES_NINETALES               ,
    SPECIES_JIGGLYPUFF              ,
    SPECIES_WIGGLYTUFF              ,
    SPECIES_ZUBAT                   ,
    SPECIES_GOLBAT                  ,
    SPECIES_ODDISH                  ,
    SPECIES_GLOOM                   ,
    SPECIES_VILEPLUME               ,
    SPECIES_PARAS                   ,
    SPECIES_PARASECT                ,
    SPECIES_VENONAT                 ,
    SPECIES_VENOMOTH                ,
    SPECIES_DIGLETT                 ,
    SPECIES_DUGTRIO                 ,
    SPECIES_MEOWTH                  ,
    SPECIES_PERSIAN                 ,
    SPECIES_PSYDUCK                 ,
    SPECIES_GOLDUCK                 ,
    SPECIES_MANKEY                  ,
    SPECIES_PRIMEAPE                ,
    SPECIES_GROWLITHE               ,
    SPECIES_ARCANINE                ,
    SPECIES_POLIWAG                 ,
    SPECIES_POLIWHIRL               ,
    SPECIES_POLIWRATH               ,
    SPECIES_ABRA                    ,
    SPECIES_KADABRA                 ,
    SPECIES_ALAKAZAM                ,
    SPECIES_MACHOP                  ,
    SPECIES_MACHOKE                 ,
    SPECIES_MACHAMP                 ,
    SPECIES_BELLSPROUT              ,
    SPECIES_WEEPINBELL              ,
    SPECIES_VICTREEBEL              ,
    SPECIES_TENTACOOL               ,
    SPECIES_TENTACRUEL              ,
    SPECIES_GEODUDE                 ,
    SPECIES_GRAVELER                ,
    SPECIES_GOLEM                   ,
    SPECIES_PONYTA                  ,
    SPECIES_RAPIDASH                ,
    SPECIES_SLOWPOKE                ,
    SPECIES_SLOWBRO                 ,
    SPECIES_MAGNEMITE               ,
    SPECIES_MAGNETON                ,
    SPECIES_FARFETCHD               ,
    SPECIES_DODUO                   ,
    SPECIES_DODRIO                  ,
    SPECIES_SEEL                    ,
    SPECIES_DEWGONG                 ,
    SPECIES_GRIMER                  ,
    SPECIES_MUK                     ,
    SPECIES_SHELLDER                ,
    SPECIES_CLOYSTER                ,
    SPECIES_GASTLY                  ,
    SPECIES_HAUNTER                 ,
    SPECIES_GENGAR                  ,
    SPECIES_ONIX                    ,
    SPECIES_DROWZEE                 ,
    SPECIES_HYPNO                   ,
    SPECIES_KRABBY                  ,
    SPECIES_KINGLER                 ,
    SPECIES_VOLTORB                 ,
    SPECIES_ELECTRODE               ,
    SPECIES_EXEGGCUTE               ,
    SPECIES_EXEGGUTOR               ,
    SPECIES_CUBONE                  ,
    SPECIES_MAROWAK                 ,
    SPECIES_HITMONLEE               ,
    SPECIES_HITMONCHAN              ,
    SPECIES_LICKITUNG               ,
    SPECIES_KOFFING                 ,
    SPECIES_WEEZING                 ,
    SPECIES_RHYHORN                 ,
    SPECIES_RHYDON                  ,
    SPECIES_CHANSEY                 ,
    SPECIES_TANGELA                 ,
    SPECIES_KANGASKHAN              ,
    SPECIES_HORSEA                  ,
    SPECIES_SEADRA                  ,
    SPECIES_GOLDEEN                 ,
    SPECIES_SEAKING                 ,
    SPECIES_STARYU                  ,
    SPECIES_STARMIE                 ,
    SPECIES_MR_MIME                 ,
    SPECIES_SCYTHER                 ,
    SPECIES_JYNX                    ,
    SPECIES_ELECTABUZZ              ,
    SPECIES_MAGMAR                  ,
    SPECIES_PINSIR                  ,
    SPECIES_TAUROS                  ,
    SPECIES_MAGIKARP                ,
    SPECIES_GYARADOS                ,
    SPECIES_LAPRAS                  ,
    SPECIES_DITTO                   ,
    SPECIES_EEVEE                   ,
    SPECIES_VAPOREON                ,
    SPECIES_JOLTEON                 ,
    SPECIES_FLAREON                 ,
    SPECIES_PORYGON                 ,
    SPECIES_OMANYTE                 ,
    SPECIES_OMASTAR                 ,
    SPECIES_KABUTO                  ,
    SPECIES_KABUTOPS                ,
    SPECIES_AERODACTYL              ,
    SPECIES_SNORLAX                 ,
    SPECIES_ARTICUNO                ,
    SPECIES_ZAPDOS                  ,
    SPECIES_MOLTRES                 ,
    SPECIES_DRATINI                 ,
    SPECIES_DRAGONAIR               ,
    SPECIES_DRAGONITE               ,
    SPECIES_MEWTWO                  ,
    SPECIES_MEW                     ,
    SPECIES_CHIKORITA                  ,
    SPECIES_BAYLEEF                    ,
    SPECIES_MEGANIUM                   ,
    SPECIES_CYNDAQUIL                  ,
    SPECIES_QUILAVA                    ,
    SPECIES_TYPHLOSION                 ,
    SPECIES_TOTODILE                   ,
    SPECIES_CROCONAW                   ,
    SPECIES_FERALIGATR                 ,
    SPECIES_SENTRET                    ,
    SPECIES_FURRET                     ,
    SPECIES_HOOTHOOT                   ,
    SPECIES_NOCTOWL                    ,
    SPECIES_LEDYBA                     ,
    SPECIES_LEDIAN                     ,
    SPECIES_SPINARAK                   ,
    SPECIES_ARIADOS                    ,
    SPECIES_CROBAT                     ,
    SPECIES_CHINCHOU                   ,
    SPECIES_LANTURN                    ,
    SPECIES_PICHU                      ,
    SPECIES_CLEFFA                     ,
    SPECIES_IGGLYBUFF                  ,
    SPECIES_TOGEPI                     ,
    SPECIES_TOGETIC                    ,
    SPECIES_NATU                       ,
    SPECIES_XATU                       ,
    SPECIES_MAREEP                     ,
    SPECIES_FLAAFFY                    ,
    SPECIES_AMPHAROS                   ,
    SPECIES_BELLOSSOM                  ,
    SPECIES_MARILL                     ,
    SPECIES_AZUMARILL                  ,
    SPECIES_SUDOWOODO                  ,
    SPECIES_POLITOED                   ,
    SPECIES_HOPPIP                     ,
    SPECIES_SKIPLOOM                   ,
    SPECIES_JUMPLUFF                   ,
    SPECIES_AIPOM                      ,
    SPECIES_SUNKERN                    ,
    SPECIES_SUNFLORA                   ,
    SPECIES_YANMA                      ,
    SPECIES_WOOPER                     ,
    SPECIES_QUAGSIRE                   ,
    SPECIES_ESPEON                     ,
    SPECIES_UMBREON                    ,
    SPECIES_MURKROW                    ,
    SPECIES_SLOWKING                   ,
    SPECIES_MISDREAVUS                 ,
    SPECIES_UNOWN                      ,
    SPECIES_WOBBUFFET                  ,
    SPECIES_GIRAFARIG                  ,
    SPECIES_PINECO                     ,
    SPECIES_FORRETRESS                 ,
    SPECIES_DUNSPARCE                  ,
    SPECIES_GLIGAR                     ,
    SPECIES_STEELIX                    ,
    SPECIES_SNUBBULL                   ,
    SPECIES_GRANBULL                   ,
    SPECIES_QWILFISH                   ,
    SPECIES_SCIZOR                     ,
    SPECIES_SHUCKLE                    ,
    SPECIES_HERACROSS                  ,
    SPECIES_SNEASEL                    ,
    SPECIES_TEDDIURSA                  ,
    SPECIES_URSARING                   ,
    SPECIES_SLUGMA                     ,
    SPECIES_MAGCARGO                   ,
    SPECIES_SWINUB                     ,
    SPECIES_PILOSWINE                  ,
    SPECIES_CORSOLA                    ,
    SPECIES_REMORAID                   ,
    SPECIES_OCTILLERY                  ,
    SPECIES_DELIBIRD                   ,
    SPECIES_MANTINE                    ,
    SPECIES_SKARMORY                   ,
    SPECIES_HOUNDOUR                   ,
    SPECIES_HOUNDOOM                   ,
    SPECIES_KINGDRA                    ,
    SPECIES_PHANPY                     ,
    SPECIES_DONPHAN                    ,
    SPECIES_PORYGON2                   ,
    SPECIES_STANTLER                   ,
    SPECIES_SMEARGLE                   ,
    SPECIES_TYROGUE                    ,
    SPECIES_HITMONTOP                  ,
    SPECIES_SMOOCHUM                   ,
    SPECIES_ELEKID                     ,
    SPECIES_MAGBY                      ,
    SPECIES_MILTANK                    ,
    SPECIES_BLISSEY                    ,
    SPECIES_RAIKOU                     ,
    SPECIES_ENTEI                      ,
    SPECIES_SUICUNE                    ,
    SPECIES_LARVITAR                   ,
    SPECIES_PUPITAR                    ,
    SPECIES_TYRANITAR                  ,
    SPECIES_LUGIA                      ,
    SPECIES_HO_OH                      ,
    SPECIES_CELEBI                     ,
    SPECIES_TREECKO           ,
    SPECIES_GROVYLE           ,
    SPECIES_SCEPTILE          ,
    SPECIES_TORCHIC           ,
    SPECIES_COMBUSKEN         ,
    SPECIES_BLAZIKEN          ,
    SPECIES_MUDKIP            ,
    SPECIES_MARSHTOMP         ,
    SPECIES_SWAMPERT          ,
    SPECIES_POOCHYENA         ,
    SPECIES_MIGHTYENA         ,
    SPECIES_ZIGZAGOON         ,
    SPECIES_LINOONE           ,
    SPECIES_WURMPLE           ,
    SPECIES_SILCOON           ,
    SPECIES_BEAUTIFLY         ,
    SPECIES_CASCOON           ,
    SPECIES_DUSTOX            ,
    SPECIES_LOTAD             ,
    SPECIES_LOMBRE            ,
    SPECIES_LUDICOLO          ,
    SPECIES_SEEDOT            ,
    SPECIES_NUZLEAF           ,
    SPECIES_SHIFTRY           ,
    SPECIES_NINCADA           ,
    SPECIES_NINJASK           ,
    // SPECIES_SHEDINJA          ,
    SPECIES_TAILLOW           ,
    SPECIES_SWELLOW           ,
    SPECIES_SHROOMISH         ,
    SPECIES_BRELOOM           ,
    SPECIES_SPINDA            ,
    SPECIES_WINGULL           ,
    SPECIES_PELIPPER          ,
    SPECIES_SURSKIT           ,
    SPECIES_MASQUERAIN        ,
    SPECIES_WAILMER           ,
    SPECIES_WAILORD           ,
    SPECIES_SKITTY            ,
    SPECIES_DELCATTY          ,
    SPECIES_KECLEON           ,
    SPECIES_BALTOY            ,
    SPECIES_CLAYDOL           ,
    SPECIES_NOSEPASS          ,
    SPECIES_TORKOAL           ,
    SPECIES_SABLEYE           ,
    SPECIES_BARBOACH          ,
    SPECIES_WHISCASH          ,
    SPECIES_LUVDISC           ,
    SPECIES_CORPHISH          ,
    SPECIES_CRAWDAUNT         ,
    SPECIES_FEEBAS            ,
    SPECIES_MILOTIC           ,
    SPECIES_CARVANHA          ,
    SPECIES_SHARPEDO          ,
    SPECIES_TRAPINCH          ,
    SPECIES_VIBRAVA           ,
    SPECIES_FLYGON            ,
    SPECIES_MAKUHITA          ,
    SPECIES_HARIYAMA          ,
    SPECIES_ELECTRIKE         ,
    SPECIES_MANECTRIC         ,
    SPECIES_NUMEL             ,
    SPECIES_CAMERUPT          ,
    SPECIES_SPHEAL            ,
    SPECIES_SEALEO            ,
    SPECIES_WALREIN           ,
    SPECIES_CACNEA            ,
    SPECIES_CACTURNE          ,
    SPECIES_SNORUNT           ,
    SPECIES_GLALIE            ,
    SPECIES_LUNATONE          ,
    SPECIES_SOLROCK           ,
    SPECIES_AZURILL           ,
    SPECIES_SPOINK            ,
    SPECIES_GRUMPIG           ,
    SPECIES_PLUSLE            ,
    SPECIES_MINUN             ,
    SPECIES_MAWILE            ,
    SPECIES_MEDITITE          ,
    SPECIES_MEDICHAM          ,
    SPECIES_SWABLU            ,
    SPECIES_ALTARIA           ,
    SPECIES_WYNAUT            ,
    SPECIES_DUSKULL           ,
    SPECIES_DUSCLOPS          ,
    SPECIES_ROSELIA           ,
    SPECIES_SLAKOTH           ,
    SPECIES_VIGOROTH          ,
    SPECIES_SLAKING           ,
    SPECIES_GULPIN            ,
    SPECIES_SWALOT            ,
    SPECIES_TROPIUS           ,
    SPECIES_WHISMUR           ,
    SPECIES_LOUDRED           ,
    SPECIES_EXPLOUD           ,
    SPECIES_CLAMPERL          ,
    SPECIES_HUNTAIL           ,
    SPECIES_GOREBYSS          ,
    SPECIES_ABSOL             ,
    SPECIES_SHUPPET           ,
    SPECIES_BANETTE           ,
    SPECIES_SEVIPER           ,
    SPECIES_ZANGOOSE          ,
    SPECIES_RELICANTH         ,
    SPECIES_ARON              ,
    SPECIES_LAIRON            ,
    SPECIES_AGGRON            ,
    // SPECIES_CASTFORM          ,
    SPECIES_VOLBEAT           ,
    SPECIES_ILLUMISE          ,
    SPECIES_LILEEP            ,
    SPECIES_CRADILY           ,
    SPECIES_ANORITH           ,
    SPECIES_ARMALDO           ,
    SPECIES_RALTS             ,
    SPECIES_KIRLIA            ,
    SPECIES_GARDEVOIR         ,
    SPECIES_BAGON             ,
    SPECIES_SHELGON           ,
    SPECIES_SALAMENCE         ,
    SPECIES_BELDUM            ,
    SPECIES_METANG            ,
    SPECIES_METAGROSS         ,
    SPECIES_REGIROCK          ,
    SPECIES_REGICE            ,
    SPECIES_REGISTEEL         ,
    SPECIES_KYOGRE            ,
    SPECIES_GROUDON           ,
    SPECIES_RAYQUAZA          ,
    SPECIES_LATIAS            ,
    SPECIES_LATIOS            ,
    SPECIES_JIRACHI           ,
    SPECIES_DEOXYS            ,
    SPECIES_CHIMECHO          ,
#ifdef PIT_GEN_5_MODE
    SPECIES_TURTWIG           ,
    SPECIES_GROTLE            ,
    SPECIES_TORTERRA          ,
    SPECIES_CHIMCHAR          ,
    SPECIES_MONFERNO          ,
    SPECIES_INFERNAPE         ,
    SPECIES_PIPLUP            ,
    SPECIES_PRINPLUP          ,
    SPECIES_EMPOLEON          ,
    SPECIES_STARLY            ,
    SPECIES_STARAVIA          ,
    SPECIES_STARAPTOR         ,
    SPECIES_BIDOOF            ,
    SPECIES_BIBAREL           ,
    SPECIES_KRICKETOT         ,
    SPECIES_KRICKETUNE        ,
    SPECIES_SHINX             ,
    SPECIES_LUXIO             ,
    SPECIES_LUXRAY            ,
    SPECIES_BUDEW             ,
    SPECIES_ROSERADE          ,
    SPECIES_CRANIDOS          ,
    SPECIES_RAMPARDOS         ,
    SPECIES_SHIELDON          ,
    SPECIES_BASTIODON         ,
    SPECIES_BURMY             ,
    SPECIES_WORMADAM          ,
    SPECIES_MOTHIM            ,
    SPECIES_COMBEE            ,
    SPECIES_VESPIQUEN         ,
    SPECIES_PACHIRISU         ,
    SPECIES_BUIZEL            ,
    SPECIES_FLOATZEL          ,
    SPECIES_CHERUBI           ,
    SPECIES_CHERRIM           ,
    SPECIES_SHELLOS           ,
    SPECIES_GASTRODON         ,
    SPECIES_AMBIPOM           ,
    SPECIES_DRIFLOON          ,
    SPECIES_DRIFBLIM          ,
    SPECIES_BUNEARY           ,
    SPECIES_LOPUNNY           ,
    SPECIES_MISMAGIUS         ,
    SPECIES_HONCHKROW         ,
    SPECIES_GLAMEOW           ,
    SPECIES_PURUGLY           ,
    SPECIES_CHINGLING         ,
    SPECIES_STUNKY            ,
    SPECIES_SKUNTANK          ,
    SPECIES_BRONZOR           ,
    SPECIES_BRONZONG          ,
    SPECIES_BONSLY            ,
    SPECIES_MIME_JR           ,
    SPECIES_HAPPINY           ,
    SPECIES_CHATOT            ,
    SPECIES_SPIRITOMB         ,
    SPECIES_GIBLE             ,
    SPECIES_GABITE            ,
    SPECIES_GARCHOMP          ,
    SPECIES_MUNCHLAX          ,
    SPECIES_RIOLU             ,
    SPECIES_LUCARIO           ,
    SPECIES_HIPPOPOTAS        ,
    SPECIES_HIPPOWDON         ,
    SPECIES_SKORUPI           ,
    SPECIES_DRAPION           ,
    SPECIES_CROAGUNK          ,
    SPECIES_TOXICROAK         ,
    SPECIES_CARNIVINE         ,
    SPECIES_FINNEON           ,
    SPECIES_LUMINEON          ,
    SPECIES_MANTYKE           ,
    SPECIES_SNOVER            ,
    SPECIES_ABOMASNOW         ,
    SPECIES_WEAVILE           ,
    SPECIES_MAGNEZONE         ,
    SPECIES_LICKILICKY        ,
    SPECIES_RHYPERIOR         ,
    SPECIES_TANGROWTH         ,
    SPECIES_ELECTIVIRE        ,
    SPECIES_MAGMORTAR         ,
    SPECIES_TOGEKISS          ,
    SPECIES_YANMEGA           ,
    SPECIES_LEAFEON           ,
    SPECIES_GLACEON           ,
    SPECIES_GLISCOR           ,
    SPECIES_MAMOSWINE         ,
    SPECIES_PORYGON_Z         ,
    SPECIES_GALLADE           ,
    SPECIES_PROBOPASS         ,
    SPECIES_DUSKNOIR          ,
    SPECIES_FROSLASS          ,
    SPECIES_ROTOM             ,
    SPECIES_UXIE              ,
    SPECIES_MESPRIT           ,
    SPECIES_AZELF             ,
    SPECIES_DIALGA            ,
    SPECIES_PALKIA            ,
    SPECIES_HEATRAN           ,
    SPECIES_REGIGIGAS         ,
    SPECIES_GIRATINA          ,
    SPECIES_CRESSELIA         ,
    SPECIES_PHIONE            ,
    SPECIES_MANAPHY           ,
    SPECIES_DARKRAI           ,
    SPECIES_SHAYMIN           ,
    SPECIES_ARCEUS            ,
    SPECIES_VICTINI           ,
    SPECIES_SNIVY             ,
    SPECIES_SERVINE           ,
    SPECIES_SERPERIOR         ,
    SPECIES_TEPIG             ,
    SPECIES_PIGNITE           ,
    SPECIES_EMBOAR            ,
    SPECIES_OSHAWOTT          ,
    SPECIES_DEWOTT            ,
    SPECIES_SAMUROTT          ,
    SPECIES_PATRAT            ,
    SPECIES_WATCHOG           ,
    SPECIES_LILLIPUP          ,
    SPECIES_HERDIER           ,
    SPECIES_STOUTLAND         ,
    SPECIES_PURRLOIN          ,
    SPECIES_LIEPARD           ,
    SPECIES_PANSAGE           ,
    SPECIES_SIMISAGE          ,
    SPECIES_PANSEAR           ,
    SPECIES_SIMISEAR          ,
    SPECIES_PANPOUR           ,
    SPECIES_SIMIPOUR          ,
    SPECIES_MUNNA             ,
    SPECIES_MUSHARNA          ,
    SPECIES_PIDOVE            ,
    SPECIES_TRANQUILL         ,
    SPECIES_UNFEZANT          ,
    SPECIES_BLITZLE           ,
    SPECIES_ZEBSTRIKA         ,
    SPECIES_ROGGENROLA        ,
    SPECIES_BOLDORE           ,
    SPECIES_GIGALITH          ,
    SPECIES_WOOBAT            ,
    SPECIES_SWOOBAT           ,
    SPECIES_DRILBUR           ,
    SPECIES_EXCADRILL         ,
    SPECIES_AUDINO            ,
    SPECIES_TIMBURR           ,
    SPECIES_GURDURR           ,
    SPECIES_CONKELDURR        ,
    SPECIES_TYMPOLE           ,
    SPECIES_PALPITOAD         ,
    SPECIES_SEISMITOAD        ,
    SPECIES_THROH             ,
    SPECIES_SAWK              ,
    SPECIES_SEWADDLE          ,
    SPECIES_SWADLOON          ,
    SPECIES_LEAVANNY          ,
    SPECIES_VENIPEDE          ,
    SPECIES_WHIRLIPEDE        ,
    SPECIES_SCOLIPEDE         ,
    SPECIES_COTTONEE          ,
    SPECIES_WHIMSICOTT        ,
    SPECIES_PETILIL           ,
    SPECIES_LILLIGANT         ,
    SPECIES_BASCULIN          ,
    SPECIES_SANDILE           ,
    SPECIES_KROKOROK          ,
    SPECIES_KROOKODILE        ,
    SPECIES_DARUMAKA          ,
    SPECIES_DARMANITAN        ,
    SPECIES_MARACTUS          ,
    SPECIES_DWEBBLE           ,
    SPECIES_CRUSTLE           ,
    SPECIES_SCRAGGY           ,
    SPECIES_SCRAFTY           ,
    SPECIES_SIGILYPH          ,
    SPECIES_YAMASK            ,
    SPECIES_COFAGRIGUS        ,
    SPECIES_TIRTOUGA          ,
    SPECIES_CARRACOSTA        ,
    SPECIES_ARCHEN            ,
    SPECIES_ARCHEOPS          ,
    SPECIES_TRUBBISH          ,
    SPECIES_GARBODOR          ,
    SPECIES_ZORUA             ,
    SPECIES_ZOROARK           ,
    SPECIES_MINCCINO          ,
    SPECIES_CINCCINO          ,
    SPECIES_GOTHITA           ,
    SPECIES_GOTHORITA         ,
    SPECIES_GOTHITELLE        ,
    SPECIES_SOLOSIS           ,
    SPECIES_DUOSION           ,
    SPECIES_REUNICLUS         ,
    SPECIES_DUCKLETT          ,
    SPECIES_SWANNA            ,
    SPECIES_VANILLITE         ,
    SPECIES_VANILLISH         ,
    SPECIES_VANILLUXE         ,
    SPECIES_DEERLING          ,
    SPECIES_SAWSBUCK          ,
    SPECIES_EMOLGA            ,
    SPECIES_KARRABLAST        ,
    SPECIES_ESCAVALIER        ,
    SPECIES_FOONGUS           ,
    SPECIES_AMOONGUSS         ,
    SPECIES_FRILLISH          ,
    SPECIES_JELLICENT         ,
    SPECIES_ALOMOMOLA         ,
    SPECIES_JOLTIK            ,
    SPECIES_GALVANTULA        ,
    SPECIES_FERROSEED         ,
    SPECIES_FERROTHORN        ,
    SPECIES_KLINK             ,
    SPECIES_KLANG             ,
    SPECIES_KLINKLANG         ,
    SPECIES_TYNAMO            ,
    SPECIES_EELEKTRIK         ,
    SPECIES_EELEKTROSS        ,
    SPECIES_ELGYEM            ,
    SPECIES_BEHEEYEM          ,
    SPECIES_LITWICK           ,
    SPECIES_LAMPENT           ,
    SPECIES_CHANDELURE        ,
    SPECIES_AXEW              ,
    SPECIES_FRAXURE           ,
    SPECIES_HAXORUS           ,
    SPECIES_CUBCHOO           ,
    SPECIES_BEARTIC           ,
    SPECIES_CRYOGONAL         ,
    SPECIES_SHELMET           ,
    SPECIES_ACCELGOR          ,
    SPECIES_STUNFISK          ,
    SPECIES_MIENFOO           ,
    SPECIES_MIENSHAO          ,
    SPECIES_DRUDDIGON         ,
    SPECIES_GOLETT            ,
    SPECIES_GOLURK            ,
    SPECIES_PAWNIARD          ,
    SPECIES_BISHARP           ,
    SPECIES_BOUFFALANT        ,
    SPECIES_RUFFLET           ,
    SPECIES_BRAVIARY          ,
    SPECIES_VULLABY           ,
    SPECIES_MANDIBUZZ         ,
    SPECIES_HEATMOR           ,
    SPECIES_DURANT            ,
    SPECIES_DEINO             ,
    SPECIES_ZWEILOUS          ,
    SPECIES_HYDREIGON         ,
    SPECIES_LARVESTA          ,
    SPECIES_VOLCARONA         ,
    SPECIES_COBALION          ,
    SPECIES_TERRAKION         ,
    SPECIES_VIRIZION          ,
    SPECIES_TORNADUS          ,
    SPECIES_THUNDURUS         ,
    SPECIES_RESHIRAM          ,
    SPECIES_ZEKROM            ,
    SPECIES_LANDORUS          ,
    SPECIES_KYUREM            ,
    SPECIES_KELDEO            ,
    SPECIES_MELOETTA          ,
    SPECIES_GENESECT          ,
#endif
#if GEN_LATEST > 5
    SPECIES_CHESPIN           ,
    SPECIES_QUILLADIN         ,
    SPECIES_CHESNAUGHT        ,
    SPECIES_FENNEKIN          ,
    SPECIES_BRAIXEN           ,
    SPECIES_DELPHOX           ,
    SPECIES_FROAKIE           ,
    SPECIES_FROGADIER         ,
    SPECIES_GRENINJA          ,
    SPECIES_BUNNELBY          ,
    SPECIES_DIGGERSBY         ,
    SPECIES_FLETCHLING        ,
    SPECIES_FLETCHINDER       ,
    SPECIES_TALONFLAME        ,
    SPECIES_SCATTERBUG        ,
    SPECIES_SPEWPA            ,
    SPECIES_VIVILLON          ,
    SPECIES_LITLEO            ,
    SPECIES_PYROAR            ,
    SPECIES_FLABEBE           ,
    SPECIES_FLOETTE           ,
    SPECIES_FLORGES           ,
    SPECIES_SKIDDO            ,
    SPECIES_GOGOAT            ,
    SPECIES_PANCHAM           ,
    SPECIES_PANGORO           ,
    SPECIES_FURFROU           ,
    SPECIES_ESPURR            ,
    SPECIES_MEOWSTIC          ,
    SPECIES_HONEDGE           ,
    SPECIES_DOUBLADE          ,
    SPECIES_AEGISLASH         ,
    SPECIES_SPRITZEE          ,
    SPECIES_AROMATISSE        ,
    SPECIES_SWIRLIX           ,
    SPECIES_SLURPUFF          ,
    SPECIES_INKAY             ,
    SPECIES_MALAMAR           ,
    SPECIES_BINACLE           ,
    SPECIES_BARBARACLE        ,
    SPECIES_SKRELP            ,
    SPECIES_DRAGALGE          ,
    SPECIES_CLAUNCHER         ,
    SPECIES_CLAWITZER         ,
    SPECIES_HELIOPTILE        ,
    SPECIES_HELIOLISK         ,
    SPECIES_TYRUNT            ,
    SPECIES_TYRANTRUM         ,
    SPECIES_AMAURA            ,
    SPECIES_AURORUS           ,
    SPECIES_SYLVEON           ,
    SPECIES_HAWLUCHA          ,
    SPECIES_DEDENNE           ,
    SPECIES_CARBINK           ,
    SPECIES_GOOMY             ,
    SPECIES_SLIGGOO           ,
    SPECIES_GOODRA            ,
    SPECIES_KLEFKI            ,
    SPECIES_PHANTUMP          ,
    SPECIES_TREVENANT         ,
    SPECIES_PUMPKABOO         ,
    SPECIES_GOURGEIST         ,
    SPECIES_BERGMITE          ,
    SPECIES_AVALUGG           ,
    SPECIES_NOIBAT            ,
    SPECIES_NOIVERN           ,
    SPECIES_XERNEAS           ,
    SPECIES_YVELTAL           ,
    SPECIES_ZYGARDE           ,
    SPECIES_DIANCIE           ,
    SPECIES_HOOPA             ,
    SPECIES_VOLCANION         ,
    SPECIES_ROWLET            ,
    SPECIES_DARTRIX           ,
    SPECIES_DECIDUEYE         ,
    SPECIES_LITTEN            ,
    SPECIES_TORRACAT          ,
    SPECIES_INCINEROAR        ,
    SPECIES_POPPLIO           ,
    SPECIES_BRIONNE           ,
    SPECIES_PRIMARINA         ,
    SPECIES_PIKIPEK           ,
    SPECIES_TRUMBEAK          ,
    SPECIES_TOUCANNON         ,
    SPECIES_YUNGOOS           ,
    SPECIES_GUMSHOOS          ,
    SPECIES_GRUBBIN           ,
    SPECIES_CHARJABUG         ,
    SPECIES_VIKAVOLT          ,
    SPECIES_CRABRAWLER        ,
    SPECIES_CRABOMINABLE      ,
    SPECIES_ORICORIO          ,
    SPECIES_CUTIEFLY          ,
    SPECIES_RIBOMBEE          ,
    SPECIES_ROCKRUFF          ,
    SPECIES_LYCANROC          ,
    SPECIES_WISHIWASHI        ,
    SPECIES_MAREANIE          ,
    SPECIES_TOXAPEX           ,
    SPECIES_MUDBRAY           ,
    SPECIES_MUDSDALE          ,
    SPECIES_DEWPIDER          ,
    SPECIES_ARAQUANID         ,
    SPECIES_FOMANTIS          ,
    SPECIES_LURANTIS          ,
    SPECIES_MORELULL          ,
    SPECIES_SHIINOTIC         ,
    SPECIES_SALANDIT          ,
    SPECIES_SALAZZLE          ,
    SPECIES_STUFFUL           ,
    SPECIES_BEWEAR            ,
    SPECIES_BOUNSWEET         ,
    SPECIES_STEENEE           ,
    SPECIES_TSAREENA          ,
    SPECIES_COMFEY            ,
    SPECIES_ORANGURU          ,
    SPECIES_PASSIMIAN         ,
    SPECIES_WIMPOD            ,
    SPECIES_GOLISOPOD         ,
    SPECIES_SANDYGAST         ,
    SPECIES_PALOSSAND         ,
    SPECIES_PYUKUMUKU         ,
    SPECIES_TYPE_NULL         ,
    SPECIES_SILVALLY          ,
    SPECIES_MINIOR            ,
    SPECIES_KOMALA            ,
    SPECIES_TURTONATOR        ,
    SPECIES_TOGEDEMARU        ,
    SPECIES_MIMIKYU           ,
    SPECIES_BRUXISH           ,
    SPECIES_DRAMPA            ,
    SPECIES_DHELMISE          ,
    SPECIES_JANGMO_O          ,
    SPECIES_HAKAMO_O          ,
    SPECIES_KOMMO_O           ,
    SPECIES_TAPU_KOKO         ,
    SPECIES_TAPU_LELE         ,
    SPECIES_TAPU_BULU         ,
    SPECIES_TAPU_FINI         ,
    SPECIES_COSMOG            ,
    SPECIES_COSMOEM           ,
    SPECIES_SOLGALEO          ,
    SPECIES_LUNALA            ,
    SPECIES_NIHILEGO          ,
    SPECIES_BUZZWOLE          ,
    SPECIES_PHEROMOSA         ,
    SPECIES_XURKITREE         ,
    SPECIES_CELESTEELA        ,
    SPECIES_KARTANA           ,
    SPECIES_GUZZLORD          ,
    SPECIES_NECROZMA          ,
    SPECIES_MAGEARNA          ,
    SPECIES_MARSHADOW         ,
    SPECIES_POIPOLE           ,
    SPECIES_NAGANADEL         ,
    SPECIES_STAKATAKA         ,
    SPECIES_BLACEPHALON       ,
    SPECIES_ZERAORA           ,
    SPECIES_MELTAN            ,
    SPECIES_MELMETAL          ,
    SPECIES_GROOKEY           ,
    SPECIES_THWACKEY          ,
    SPECIES_RILLABOOM         ,
    SPECIES_SCORBUNNY         ,
    SPECIES_RABOOT            ,
    SPECIES_CINDERACE         ,
    SPECIES_SOBBLE            ,
    SPECIES_DRIZZILE          ,
    SPECIES_INTELEON          ,
    SPECIES_SKWOVET           ,
    SPECIES_GREEDENT          ,
    SPECIES_ROOKIDEE          ,
    SPECIES_CORVISQUIRE       ,
    SPECIES_CORVIKNIGHT       ,
    SPECIES_BLIPBUG           ,
    SPECIES_DOTTLER           ,
    SPECIES_ORBEETLE          ,
    SPECIES_NICKIT            ,
    SPECIES_THIEVUL           ,
    SPECIES_GOSSIFLEUR        ,
    SPECIES_ELDEGOSS          ,
    SPECIES_WOOLOO            ,
    SPECIES_DUBWOOL           ,
    SPECIES_CHEWTLE           ,
    SPECIES_DREDNAW           ,
    SPECIES_YAMPER            ,
    SPECIES_BOLTUND           ,
    SPECIES_ROLYCOLY          ,
    SPECIES_CARKOL            ,
    SPECIES_COALOSSAL         ,
    SPECIES_APPLIN            ,
    SPECIES_FLAPPLE           ,
    SPECIES_APPLETUN          ,
    SPECIES_SILICOBRA         ,
    SPECIES_SANDACONDA        ,
    SPECIES_CRAMORANT         ,
    SPECIES_ARROKUDA          ,
    SPECIES_BARRASKEWDA       ,
    SPECIES_TOXEL             ,
    SPECIES_TOXTRICITY        ,
    SPECIES_SIZZLIPEDE        ,
    SPECIES_CENTISKORCH       ,
    SPECIES_CLOBBOPUS         ,
    SPECIES_GRAPPLOCT         ,
    SPECIES_SINISTEA          ,
    SPECIES_POLTEAGEIST       ,
    SPECIES_HATENNA           ,
    SPECIES_HATTREM           ,
    SPECIES_HATTERENE         ,
    SPECIES_IMPIDIMP          ,
    SPECIES_MORGREM           ,
    SPECIES_GRIMMSNARL        ,
    SPECIES_OBSTAGOON         ,
    SPECIES_PERRSERKER        ,
    SPECIES_CURSOLA           ,
    SPECIES_SIRFETCHD         ,
    SPECIES_MR_RIME           ,
    SPECIES_RUNERIGUS         ,
    SPECIES_MILCERY           ,
    SPECIES_ALCREMIE          ,
    SPECIES_FALINKS           ,
    SPECIES_PINCURCHIN        ,
    SPECIES_SNOM              ,
    SPECIES_FROSMOTH          ,
    SPECIES_STONJOURNER       ,
    SPECIES_EISCUE            ,
    SPECIES_INDEEDEE          ,
    SPECIES_MORPEKO           ,
    SPECIES_CUFANT            ,
    SPECIES_COPPERAJAH        ,
    SPECIES_DRACOZOLT         ,
    SPECIES_ARCTOZOLT         ,
    SPECIES_DRACOVISH         ,
    SPECIES_ARCTOVISH         ,
    SPECIES_DURALUDON         ,
    SPECIES_DREEPY            ,
    SPECIES_DRAKLOAK          ,
    SPECIES_DRAGAPULT         ,
    SPECIES_ZACIAN            ,
    SPECIES_ZAMAZENTA         ,
    SPECIES_ETERNATUS         ,
    SPECIES_KUBFU             ,
    SPECIES_URSHIFU           ,
    SPECIES_ZARUDE            ,
    SPECIES_REGIELEKI         ,
    SPECIES_REGIDRAGO         ,
    SPECIES_GLASTRIER         ,
    SPECIES_SPECTRIER         ,
    SPECIES_CALYREX           ,
    SPECIES_RATTATA_ALOLAN    ,
    SPECIES_RATICATE_ALOLAN   ,
    SPECIES_RAICHU_ALOLAN     ,
    SPECIES_SANDSHREW_ALOLAN  ,
    SPECIES_SANDSLASH_ALOLAN  ,
    SPECIES_VULPIX_ALOLAN     ,
    SPECIES_NINETALES_ALOLAN  ,
    SPECIES_DIGLETT_ALOLAN    ,
    SPECIES_DUGTRIO_ALOLAN    ,
    SPECIES_MEOWTH_ALOLAN     ,
    SPECIES_PERSIAN_ALOLAN    ,
    SPECIES_GEODUDE_ALOLAN    ,
    SPECIES_GRAVELER_ALOLAN   ,
    SPECIES_GOLEM_ALOLAN      ,
    SPECIES_GRIMER_ALOLAN     ,
    SPECIES_MUK_ALOLAN        ,
    SPECIES_EXEGGUTOR_ALOLAN  ,
    SPECIES_MAROWAK_ALOLAN    ,
    SPECIES_MEOWTH_GALARIAN   ,
    SPECIES_PONYTA_GALARIAN   ,
    SPECIES_RAPIDASH_GALARIAN ,
    SPECIES_SLOWPOKE_GALARIAN ,
    SPECIES_SLOWBRO_GALARIAN  ,
    SPECIES_FARFETCHD_GALARIAN ,
    SPECIES_WEEZING_GALARIAN  ,
    SPECIES_MR_MIME_GALARIAN  ,
    SPECIES_ARTICUNO_GALARIAN ,
    SPECIES_ZAPDOS_GALARIAN   ,
    SPECIES_MOLTRES_GALARIAN  ,
    SPECIES_SLOWKING_GALARIAN ,
    SPECIES_CORSOLA_GALARIAN  ,
    SPECIES_ZIGZAGOON_GALARIAN ,
    SPECIES_LINOONE_GALARIAN  ,
    SPECIES_DARUMAKA_GALARIAN ,
    SPECIES_DARMANITAN_GALARIAN ,
    SPECIES_YAMASK_GALARIAN   ,
    SPECIES_STUNFISK_GALARIAN ,
    SPECIES_PIKACHU_HOENN_CAP ,
    SPECIES_PICHU_SPIKY_EARED ,
    SPECIES_BURMY_SANDY_CLOAK ,
    SPECIES_BURMY_TRASH_CLOAK ,
    SPECIES_WORMADAM_SANDY_CLOAK ,
    SPECIES_WORMADAM_TRASH_CLOAK ,
    SPECIES_CHERRIM_SUNSHINE  ,
    SPECIES_DEERLING_SUMMER   ,
    SPECIES_DEERLING_AUTUMN   ,
    SPECIES_DEERLING_WINTER   ,
    SPECIES_SAWSBUCK_SUMMER   ,
    SPECIES_SAWSBUCK_AUTUMN   ,
    SPECIES_SAWSBUCK_WINTER   ,
    //SPECIES_KYUREM_WHITE      ,
    //SPECIES_KYUREM_BLACK      ,
    SPECIES_WYRDEER,
    SPECIES_KLEAVOR,
    SPECIES_URSALUNA,
    SPECIES_BASCULEGION_MALE,
    SPECIES_SNEASLER,
    SPECIES_OVERQWIL,
    SPECIES_ENAMORUS_INCARNATE,
    SPECIES_GROWLITHE_HISUIAN,
    SPECIES_ARCANINE_HISUIAN,
    SPECIES_VOLTORB_HISUIAN,
    SPECIES_ELECTRODE_HISUIAN,
    SPECIES_TYPHLOSION_HISUIAN,
    SPECIES_QWILFISH_HISUIAN,
    SPECIES_SNEASEL_HISUIAN,
    SPECIES_SAMUROTT_HISUIAN,
    SPECIES_LILLIGANT_HISUIAN,
    SPECIES_ZORUA_HISUIAN,
    SPECIES_ZOROARK_HISUIAN,
    SPECIES_BRAVIARY_HISUIAN,
    SPECIES_SLIGGOO_HISUIAN,
    SPECIES_GOODRA_HISUIAN,
    SPECIES_AVALUGG_HISUIAN,
    SPECIES_DECIDUEYE_HISUIAN,
    SPECIES_SPRIGATITO,
    SPECIES_FLORAGATO,
    SPECIES_MEOWSCARADA,
    SPECIES_FUECOCO,
    SPECIES_CROCALOR,
    SPECIES_SKELEDIRGE,
    SPECIES_QUAXLY,
    SPECIES_QUAXWELL,
    SPECIES_QUAQUAVAL,
    SPECIES_LECHONK,
    SPECIES_OINKOLOGNE_MALE,
    SPECIES_TAROUNTULA,
    SPECIES_SPIDOPS,
    SPECIES_NYMBLE,
    SPECIES_LOKIX,
    SPECIES_PAWMI,
    SPECIES_PAWMO,
    SPECIES_PAWMOT,
    SPECIES_TANDEMAUS,
    SPECIES_MAUSHOLD_FAMILY_OF_THREE,
    SPECIES_MAUSHOLD_FAMILY_OF_FOUR,
    SPECIES_FIDOUGH,
    SPECIES_DACHSBUN,
    SPECIES_SMOLIV,
    SPECIES_DOLLIV,
    SPECIES_ARBOLIVA,
    SPECIES_SQUAWKABILLY_GREEN_PLUMAGE,
    SPECIES_NACLI,
    SPECIES_NACLSTACK,
    SPECIES_GARGANACL,
    SPECIES_CHARCADET,
    SPECIES_ARMAROUGE,
    SPECIES_CERULEDGE,
    SPECIES_TADBULB,
    SPECIES_BELLIBOLT,
    SPECIES_WATTREL,
    SPECIES_KILOWATTREL,
    SPECIES_MASCHIFF,
    SPECIES_MABOSSTIFF,
    SPECIES_SHROODLE,
    SPECIES_GRAFAIAI,
    SPECIES_BRAMBLIN,
    SPECIES_BRAMBLEGHAST,
    SPECIES_TOEDSCOOL,
    SPECIES_TOEDSCRUEL,
    SPECIES_KLAWF,
    SPECIES_CAPSAKID,
    SPECIES_SCOVILLAIN,
    SPECIES_RELLOR,
    SPECIES_RABSCA,
    SPECIES_FLITTLE,
    SPECIES_ESPATHRA,
    SPECIES_TINKATINK,
    SPECIES_TINKATUFF,
    SPECIES_TINKATON,
    SPECIES_WIGLETT,
    SPECIES_WUGTRIO,
    SPECIES_BOMBIRDIER,
    SPECIES_FINIZEN,
    SPECIES_PALAFIN_ZERO,
    SPECIES_PALAFIN_HERO,
    SPECIES_VAROOM,
    SPECIES_REVAVROOM,
    SPECIES_CYCLIZAR,
    SPECIES_ORTHWORM,
    SPECIES_GLIMMET,
    SPECIES_GLIMMORA,
    SPECIES_GREAVARD,
    SPECIES_HOUNDSTONE,
    SPECIES_FLAMIGO,
    SPECIES_CETODDLE,
    SPECIES_CETITAN,
    SPECIES_VELUZA,
    SPECIES_DONDOZO,
    SPECIES_TATSUGIRI_CURLY,
    SPECIES_TATSUGIRI_DROOPY,
    SPECIES_TATSUGIRI_STRETCHY,
    SPECIES_ANNIHILAPE,
    SPECIES_CLODSIRE,
    SPECIES_FARIGIRAF,
    SPECIES_DUDUNSPARCE_TWO_SEGMENT,
    SPECIES_DUDUNSPARCE_THREE_SEGMENT,
    SPECIES_KINGAMBIT,
    SPECIES_GREAT_TUSK,
    SPECIES_SCREAM_TAIL,
    SPECIES_BRUTE_BONNET,
    SPECIES_FLUTTER_MANE,
    SPECIES_SLITHER_WING,
    SPECIES_SANDY_SHOCKS,
    SPECIES_IRON_TREADS,
    SPECIES_IRON_BUNDLE,
    SPECIES_IRON_HANDS,
    SPECIES_IRON_JUGULIS,
    SPECIES_IRON_MOTH,
    SPECIES_IRON_THORNS,
    SPECIES_FRIGIBAX,
    SPECIES_ARCTIBAX,
    SPECIES_BAXCALIBUR,
    SPECIES_GIMMIGHOUL_CHEST,
    SPECIES_GHOLDENGO,
    SPECIES_WO_CHIEN,
    SPECIES_CHIEN_PAO,
    SPECIES_TING_LU,
    SPECIES_CHI_YU,
    SPECIES_ROARING_MOON,
    SPECIES_IRON_VALIANT,
    SPECIES_KORAIDON,
    SPECIES_MIRAIDON,
    SPECIES_TAUROS_PALDEAN_COMBAT_BREED,
    SPECIES_TAUROS_PALDEAN_BLAZE_BREED,
    SPECIES_TAUROS_PALDEAN_AQUA_BREED,
    SPECIES_WOOPER_PALDEAN,
    SPECIES_WALKING_WAKE,
    SPECIES_IRON_LEAVES,
    SPECIES_DIPPLIN,
    SPECIES_POLTCHAGEIST_COUNTERFEIT,
    SPECIES_SINISTCHA_UNREMARKABLE,
    SPECIES_OKIDOGI,
    SPECIES_MUNKIDORI,
    SPECIES_FEZANDIPITI,
    SPECIES_OGERPON_TEAL_MASK,
    SPECIES_URSALUNA_BLOODMOON,
    SPECIES_ARCHALUDON,
    SPECIES_HYDRAPPLE,
    SPECIES_GOUGING_FIRE,
    SPECIES_RAGING_BOLT,
    SPECIES_IRON_BOULDER,
    SPECIES_IRON_CROWN,
    SPECIES_PECHARUNT,
    SPECIES_TERAPAGOS
    #endif
    // SPECIES_EGG       ,
};

u16 GetSpeciesRandomSeeded(u16 species)
{
    return sRandomSpeciesLegendary[RandomSeededModulo2(species, RANDOM_SPECIES_COUNT_LEGENDARY)];
}

u16 GetSpeciesRandomNotSeeded(u16 species)
{
    return sRandomSpeciesLegendary[RandomModulo(species, RANDOM_SPECIES_COUNT_LEGENDARY)];
}

u16 GetRandomMove(u16 move, u16 species)
{
    u16 val = RandomSeededModulo2(move + species, RANDOM_MOVES_COUNT);
    u16 final = sRandomValidMoves[val];
    return final;
}
const u8 *GetMoveName(u16 moveId)
{
    return gMovesInfo[moveId].name;
}

bool8 IsSpeciesLegendary(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].isLegendary)
        return TRUE;
    return FALSE;
}

bool8 IsSpeciesMythical(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].isMythical)
        return TRUE;
    return FALSE;
}

bool8 IsSpeciesUltraBeast(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].isUltraBeast)
        return TRUE;
    return FALSE;
}

bool8 IsSpeciesParadoxMon(u16 species)
{
    species = SanitizeSpeciesId(species);
    if (gSpeciesInfo[species].isParadox)
        return TRUE;
    return FALSE;
}

u8 GetNumberOfEggMoves(struct Pokemon *mon)
{
    u16 eggMoveBuffer[EGG_MOVES_ARRAY_COUNT];
    u16 learnedMoves[MAX_MON_MOVES];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0);
    u16 firstStage = GetEggSpecies(species);
    u8 numEggMoves = GetEggMovesBySpecies(firstStage, eggMoveBuffer);
    //u16 moves[numEggMoves];
    int i, j;
    bool8 hasMonMove = FALSE;

    if (species == SPECIES_EGG)
        return 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < numEggMoves; i++)
    {
        hasMonMove = FALSE;

        for (j = 0; j < MAX_MON_MOVES; j++){
            if(learnedMoves[j] == eggMoveBuffer[i])
                hasMonMove = TRUE;
        }

        if(!hasMonMove)
            numMoves++;
    }

    return numMoves;
}

u8 GetEggMoveTutorMoves(struct Pokemon *mon, u16 *moves)
{
    u16 learnedMoves[4];
    u8 numMoves = 0;
    u16 eggMoveBuffer[EGG_MOVES_ARRAY_COUNT];
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0);
    u16 eggSpecies = GetEggSpecies(species);
    u16 numEggMoves = GetEggMovesBySpecies(eggSpecies, eggMoveBuffer);
    int i, j;
    bool8 hasMonMove = FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < numEggMoves; i++)
    {
        hasMonMove = FALSE;

        for (j = 0; j < MAX_MON_MOVES; j++){
            if(learnedMoves[j] == eggMoveBuffer[i])
                hasMonMove = TRUE;
        }

        if(!hasMonMove)
            moves[numMoves++] = eggMoveBuffer[i];
    }

    return numMoves;
}

u8 GetNumberOfTutorMoves(struct Pokemon *mon)
{
    u16 tutorMoveBuffer[TUTOR_MOVES_ARRAY_COUNT];
    u16 learnedMoves[MAX_MON_MOVES];
    u8 numMoves = 0;
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0);
    //u16 firstStage = GetEggSpecies(species);
    u16 numTutorMoves = GetTutorMovesSpecies(species, tutorMoveBuffer);
    //u16 moves[numTutorMoves];
    int i, j;
    bool8 hasMonMove = FALSE;

    if (species == SPECIES_EGG)
        return 0;
    for (i = 0; i < MAX_MON_MOVES; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < numTutorMoves; i++)
    {
        hasMonMove = FALSE;

        for (j = 0; j < MAX_MON_MOVES; j++){
            if(learnedMoves[j] == tutorMoveBuffer[i])
                hasMonMove = TRUE;
        }

        if(!hasMonMove)
            numMoves++;
    }

    return numMoves;
}

u8 GetTutorMoves(struct Pokemon *mon, u16 *moves)
{
    u16 learnedMoves[4];
    u8 numMoves = 0;
    u16 tutorMoveBuffer[TUTOR_MOVES_ARRAY_COUNT];
    u16 species = GetMonData(mon, MON_DATA_SPECIES_OR_EGG, 0);
    //u16 eggSpecies = GetEggSpecies(species);
    u16 numTutorMoves = GetTutorMovesSpecies(species, tutorMoveBuffer);
    int i, j;
    bool8 hasMonMove = FALSE;

    for (i = 0; i < MAX_MON_MOVES; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    for (i = 0; i < numTutorMoves; i++)
    {
        hasMonMove = FALSE;

        for (j = 0; j < MAX_MON_MOVES; j++){
            if(learnedMoves[j] == tutorMoveBuffer[i])
                hasMonMove = TRUE;
        }

        if(!hasMonMove)
            moves[numMoves++] = tutorMoveBuffer[i];
    }

    return numMoves;
}

u8 GetPreEvoMoves(struct Pokemon *mon, u16 *moves, bool8 PreEvoCheckOnly)
{
    u16 learnedMoves[4];
    u8 numMoves = 0;
    u16 speciesPreEvo;
    u16 speciesOriginal = GetMonData(mon, MON_DATA_SPECIES, 0);
    u8 level = GetMonData(mon, MON_DATA_LEVEL, 0);
    const struct LevelUpMove *learnset, *learnsetOriginal;
    int i, j, k;

    speciesPreEvo = GetPreEvolution(speciesOriginal);
    learnset = GetSpeciesLevelUpLearnset(speciesPreEvo);
    learnsetOriginal = GetSpeciesLevelUpLearnset(speciesOriginal);

    //save current moveset
    for (i = 0; i < MAX_MON_MOVES; i++)
        learnedMoves[i] = GetMonData(mon, MON_DATA_MOVE1 + i, 0);

    while (speciesPreEvo != SPECIES_NONE)
    {
        //iterate all level up moves
        for (i = 0; i < MAX_LEVEL_UP_MOVES; i++)
        {
            u16 moveLevel;

            //exit if last move from learnset is reached
            if (learnset[i].move == LEVEL_UP_MOVE_END)
                break;

            //check if said move is not currently known
            for (j = 0; j < MAX_MON_MOVES && learnedMoves[j] != learnset[i].move; j++)
                ;

            //if move is currently unknown
            if (j == MAX_MON_MOVES)
            {
                //check if not already in the list
                for (k = 0; k < numMoves && moves[k] != learnset[i].move; k++)
                    ;

                if (k == numMoves)
                {
                    // check if move is not learnable by level-up by original species
                    // to identify if it as an actual PreEvo move
                    for (j = 0; j < MAX_LEVEL_UP_MOVES; j++)
                    {
                        if (learnsetOriginal[j].move == learnset[i].move)
                            break;
                        if (learnsetOriginal[j].move == LEVEL_UP_MOVE_END)
                        {
                            j = 255;
                            break;
                        }
                    }
                    //found a PreEvo move
                    if (j == 255)
                    {
                        if (PreEvoCheckOnly)
                            return TRUE;
                        moves[numMoves++] = learnset[i].move;
                    }
                }
            }
        }
        speciesPreEvo = GetPreEvolution(speciesPreEvo);
        learnset = GetSpeciesLevelUpLearnset(speciesPreEvo);
    }

    return numMoves;
}

#define TUTOR_MOVES_COUNT ARRAY_COUNT(sTutorMoves)
static const u16 sTutorMoves[] =
{
#ifdef PIT_GEN_9_MODE
    MOVE_GRASS_PLEDGE,
    MOVE_FIRE_PLEDGE,
    MOVE_WATER_PLEDGE,
    MOVE_DRACO_METEOR,
    MOVE_FRENZY_PLANT,
    MOVE_BLAST_BURN,
    MOVE_HYDRO_CANNON,
    MOVE_RELIC_SONG,
    MOVE_SECRET_SWORD,
#endif
};

u8 GetStaticTutorMoves(u16 *moves)
{
    int i;

    for (i = 0; i < TUTOR_MOVES_COUNT; i++)
        moves[i] = sTutorMoves[i];

    return TUTOR_MOVES_COUNT;
}

// Returns ITEM_NONE if no mega evolution by mega stone is possible
u16 GetMegaStone(u32 species)
{
    u32 i;
    u32 megaStone = ITEM_NONE;
    const struct FormChange *formChanges = GetSpeciesFormChanges(species);

    if (formChanges != NULL)
    {
        for (i = 0; formChanges[i].method != FORM_CHANGE_TERMINATOR; i++)
        {
            if (formChanges[i].method == FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM)
            {
                //multiple mega stones (X/Y) currently not considered
                megaStone = formChanges[i].param1;
            }
        }
    }

    return megaStone;
}

u32 GetMaxNumberOfSpecies(void)
{
    return RANDOM_SPECIES_COUNT_LEGENDARY;
}

u8 GetCurrentMaxMonGeneratedCount(void)
{
    u32 speciesCountReduced = ((GetMaxNumberOfSpecies() * 15) / 16);
    return (gSaveBlock3Ptr->monsGeneratedCount / (speciesCountReduced)) + 1;
}

u16 GetRandomSpeciesFlattenedCurve(void)
{
    u16 randomSpecies = 0;
    u16 largestMonCount = gSaveBlock3Ptr->largestMonCount;
    u16 notChosen = TRUE;
    u8 maxChosenNumber = 0;
    u16 breakOut = 0;

    gSaveBlock3Ptr->monsGeneratedCount += 1;
    maxChosenNumber = GetCurrentMaxMonGeneratedCount();

    //SeedRngWithRtc();

    while(notChosen)
    {
        randomSpecies = GetSpeciesRandomNotSeeded(0);
        if(gSaveBlock3Ptr->monRolledCounts[randomSpecies] < maxChosenNumber)
            notChosen = FALSE;

        breakOut++;
        if(breakOut > 100000)
            notChosen = FALSE;
    }

    gSaveBlock3Ptr->monRolledCounts[randomSpecies] += 1;
    if(gSaveBlock3Ptr->monRolledCounts[randomSpecies] > largestMonCount)
        gSaveBlock3Ptr->largestMonCount = gSaveBlock3Ptr->monRolledCounts[randomSpecies] + 1;

    return randomSpecies;
        
}

void ClearGeneratedMons(void)
{
    u16 i = 0;
    gSaveBlock3Ptr->monsGeneratedCount = 0;
    for(i = 0; i < GetMaxNumberOfSpecies(); i++)
    {
        gSaveBlock3Ptr->monRolledCounts[i] = 0;
    }
}

void DebugTestRandomness(void)
{
    u16 i = 0;
    u16 floor = 0;
    u16 partyNum = 0;
    u16 trainerNum = 0;

    ClearGeneratedMons();
    //SeedRngWithRtc();

    i = 0;
    while(i < 1)
    {
        for(floor = 0; floor < 10; floor++)
        {
            for(trainerNum = 0; trainerNum < 4; trainerNum++)
            {
                for(partyNum = 0; partyNum < 5; partyNum++)
                {
                    GetRandomSpeciesFlattenedCurve();
                }
            }
        }
        i++;
    }

    //DebugPrintf("\n\n\nDebugTestRandomness New");
    for(i = 0; i < GetMaxNumberOfSpecies(); i++)
    {
        StringCopy(gStringVar1, GetSpeciesName(i));
        //DebugPrintf("Species %S: %d", &gStringVar1, gSaveBlock3Ptr->monRolledCounts[i]);
    }
    //DebugPrintf("Number of Mons Generated: %d", gSaveBlock3Ptr->monsGeneratedCount);
    
    ClearGeneratedMons();
}

#define RANDOM_TYPE_COUNT ARRAY_COUNT(sOneTypeChallengeValidTypes)
static const u8  sOneTypeChallengeValidTypes[RANDOM_MON_TYPES - 2] =
{
    TYPE_NORMAL   ,
    TYPE_FIGHTING ,
    TYPE_FLYING   ,
    TYPE_POISON   ,
    TYPE_GROUND   ,
    TYPE_ROCK     ,
    TYPE_BUG      ,
    TYPE_GHOST    ,
    TYPE_STEEL    ,
    TYPE_FIRE     ,
    TYPE_WATER    ,
    TYPE_GRASS    ,
    TYPE_ELECTRIC ,
    TYPE_PSYCHIC  ,
    TYPE_ICE      ,
    TYPE_DRAGON   ,
    TYPE_DARK     ,
    #if P_UPDATED_TYPES >= GEN_6
        TYPE_FAIRY,
    #endif
};

u8 GetTypeBySpecies(u16 species, u8 typeNum)
{
    u8 type;

    if (typeNum == 1)
        type = gSpeciesInfo[species].types[0];
    else
        type = gSpeciesInfo[species].types[1];

    if (!gSaveBlock2Ptr->randomType)
        return type;

    type = sOneTypeChallengeValidTypes[RandomSeededModulo2(type + typeNum + species, RANDOM_MON_TYPES - 2) % (RANDOM_MON_TYPES - 2)];
    return type;
}

// 
// u8 GetTypeEffectivenessRandom(u8 type)
// {
//     if (type == TYPE_NONE)
//         return TYPE_NONE;
//     
//     if (!gSaveBlock1Ptr->tx_Random_TypeEffectiveness)
//         return type;
// 
//     return sTypeEffectivenessList[type];
// }
// 
const u8 *GetMoveAnimationScript(u16 moveId)
{
    if (gMovesInfo[moveId].battleAnimScript == NULL)
    {
        DebugPrintfLevel(MGBA_LOG_WARN, "No animation for moveId=%u", moveId);
        return Move_TACKLE;
    }
    return gMovesInfo[moveId].battleAnimScript;
}

void UpdateDaysPassedSinceFormChange(u16 days)
{
    u32 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        u8 daysSinceFormChange;

        if (!GetMonData(mon, MON_DATA_SPECIES, 0))
            continue;

        daysSinceFormChange = GetMonData(mon, MON_DATA_DAYS_SINCE_FORM_CHANGE, 0);
        if (daysSinceFormChange == 0)
            continue;

        if (daysSinceFormChange > days)
            daysSinceFormChange -= days;
        else
            daysSinceFormChange = 0;

        SetMonData(mon, MON_DATA_DAYS_SINCE_FORM_CHANGE, &daysSinceFormChange);

        if (daysSinceFormChange == 0)
        {
            u16 targetSpecies = GetFormChangeTargetSpecies(mon, FORM_CHANGE_DAYS_PASSED, 0);

            if (targetSpecies != SPECIES_NONE)
            {
                SetMonData(mon, MON_DATA_SPECIES, &targetSpecies);
                CalculateMonStats(mon);
            }
        }
    }
}

static u16 GetPreEvolution(u16 species)
{
    int i, j;

    for (i = 1; i < NUM_SPECIES; i++)
    {
        const struct Evolution *evolutions = GetSpeciesEvolutions(i);
        if (evolutions == NULL)
            continue;
        for (j = 0; evolutions[j].method != EVOLUTIONS_END; j++)
        {
            if (SanitizeSpeciesId(evolutions[j].targetSpecies) == species)
                return i;
        }
    }
    return SPECIES_NONE;
}
