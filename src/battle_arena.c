#include "global.h"
#include "battle.h"
#include "battle_arena.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "gpu_regs.h"
#include "item.h"
#include "m4a.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "util.h"
#include "constants/songs.h"
#include "constants/battle_arena.h"
#include "constants/battle_string_ids.h"
#include "constants/battle_frontier.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/rgb.h"

static void InitArenaChallenge(void);
static void GetArenaData(void);
static void SetArenaData(void);
static void SaveArenaChallenge(void);
static void SetArenaPrize(void);
static void GiveArenaPrize(void);
static void BufferArenaOpponentName(void);
static void SpriteCB_JudgmentIcon(struct Sprite *sprite);
static void ShowJudgmentSprite(u8 x, u8 y, u8 category, u8 battler);

#define JUDGMENT_STATE_FINISHED 8

#define TAG_JUDGMENT_ICON 1000

enum {
    ANIM_ICON_X,        // Player lost
    ANIM_ICON_TRIANGLE, // Tie
    ANIM_ICON_CIRCLE,   // Player won
    ANIM_ICON_LINE,     // Line segment for separating the score total at the bottom
};

// This table holds the number of points to add to the 'mind' score for each move.
// All moves with power != 0 give 1 point, with the following exceptions:
//    - Counter, Mirror Coat, Metal Burst, and Bide give 0 points
//    - Fake Out and First Impression subtract 1 point
// All moves with power == 0 give 0 points, with the following exceptions:
//    - EFFECT_PROTECT moves and Endure subtract 1 point
static const s8 sMindRatings[MOVES_COUNT] =
{
    [MOVE_POUND] = 1,
    [MOVE_KARATE_CHOP] = 1,
    [MOVE_DOUBLE_SLAP] = 1,
    [MOVE_COMET_PUNCH] = 1,
    [MOVE_MEGA_PUNCH] = 1,
    [MOVE_PAY_DAY] = 1,
    [MOVE_FIRE_PUNCH] = 1,
    [MOVE_ICE_PUNCH] = 1,
    [MOVE_THUNDER_PUNCH] = 1,
    [MOVE_SCRATCH] = 1,
    [MOVE_VISE_GRIP] = 1,
    [MOVE_GUILLOTINE] = 1,
    [MOVE_RAZOR_WIND] = 1,
    [MOVE_CUT] = 1,
    [MOVE_GUST] = 1,
    [MOVE_WING_ATTACK] = 1,
    [MOVE_FLY] = 1,
    [MOVE_BIND] = 1,
    [MOVE_SLAM] = 1,
    [MOVE_VINE_WHIP] = 1,
    [MOVE_STOMP] = 1,
    [MOVE_DOUBLE_KICK] = 1,
    [MOVE_MEGA_KICK] = 1,
    [MOVE_JUMP_KICK] = 1,
    [MOVE_ROLLING_KICK] = 1,
    [MOVE_HEADBUTT] = 1,
    [MOVE_HORN_ATTACK] = 1,
    [MOVE_FURY_ATTACK] = 1,
    [MOVE_HORN_DRILL] = 1,
    [MOVE_TACKLE] = 1,
    [MOVE_BODY_SLAM] = 1,
    [MOVE_WRAP] = 1,
    [MOVE_TAKE_DOWN] = 1,
    [MOVE_THRASH] = 1,
    [MOVE_DOUBLE_EDGE] = 1,
    [MOVE_POISON_STING] = 1,
    [MOVE_TWINEEDLE] = 1,
    [MOVE_PIN_MISSILE] = 1,
    [MOVE_BITE] = 1,
    [MOVE_SONIC_BOOM] = 1,
    [MOVE_ACID] = 1,
    [MOVE_EMBER] = 1,
    [MOVE_FLAMETHROWER] = 1,
    [MOVE_WATER_GUN] = 1,
    [MOVE_HYDRO_PUMP] = 1,
    [MOVE_SURF] = 1,
    [MOVE_ICE_BEAM] = 1,
    [MOVE_BLIZZARD] = 1,
    [MOVE_PSYBEAM] = 1,
    [MOVE_BUBBLE_BEAM] = 1,
    [MOVE_AURORA_BEAM] = 1,
    [MOVE_HYPER_BEAM] = 1,
    [MOVE_PECK] = 1,
    [MOVE_DRILL_PECK] = 1,
    [MOVE_SUBMISSION] = 1,
    [MOVE_LOW_KICK] = 1,
    [MOVE_SEISMIC_TOSS] = 1,
    [MOVE_STRENGTH] = 1,
    [MOVE_ABSORB] = 1,
    [MOVE_MEGA_DRAIN] = 1,
    [MOVE_RAZOR_LEAF] = 1,
    [MOVE_SOLAR_BEAM] = 1,
    [MOVE_PETAL_DANCE] = 1,
    [MOVE_DRAGON_RAGE] = 1,
    [MOVE_FIRE_SPIN] = 1,
    [MOVE_THUNDER_SHOCK] = 1,
    [MOVE_THUNDERBOLT] = 1,
    [MOVE_THUNDER] = 1,
    [MOVE_ROCK_THROW] = 1,
    [MOVE_EARTHQUAKE] = 1,
    [MOVE_FISSURE] = 1,
    [MOVE_DIG] = 1,
    [MOVE_CONFUSION] = 1,
    [MOVE_PSYCHIC] = 1,
    [MOVE_QUICK_ATTACK] = 1,
    [MOVE_RAGE] = 1,
    [MOVE_NIGHT_SHADE] = 1,
    [MOVE_SELF_DESTRUCT] = 1,
    [MOVE_EGG_BOMB] = 1,
    [MOVE_LICK] = 1,
    [MOVE_SMOG] = 1,
    [MOVE_SLUDGE] = 1,
    [MOVE_BONE_CLUB] = 1,
    [MOVE_FIRE_BLAST] = 1,
    [MOVE_WATERFALL] = 1,
    [MOVE_CLAMP] = 1,
    [MOVE_SWIFT] = 1,
    [MOVE_SKULL_BASH] = 1,
    [MOVE_SPIKE_CANNON] = 1,
    [MOVE_CONSTRICT] = 1,
    [MOVE_HIGH_JUMP_KICK] = 1,
    [MOVE_DREAM_EATER] = 1,
    [MOVE_BARRAGE] = 1,
    [MOVE_LEECH_LIFE] = 1,
    [MOVE_SKY_ATTACK] = 1,
    [MOVE_BUBBLE] = 1,
    [MOVE_DIZZY_PUNCH] = 1,
    [MOVE_PSYWAVE] = 1,
    [MOVE_CRABHAMMER] = 1,
    [MOVE_EXPLOSION] = 1,
    [MOVE_FURY_SWIPES] = 1,
    [MOVE_BONEMERANG] = 1,
    [MOVE_ROCK_SLIDE] = 1,
    [MOVE_HYPER_FANG] = 1,
    [MOVE_TRI_ATTACK] = 1,
    [MOVE_SUPER_FANG] = 1,
    [MOVE_SLASH] = 1,
    [MOVE_STRUGGLE] = 1,
    [MOVE_TRIPLE_KICK] = 1,
    [MOVE_THIEF] = 1,
    [MOVE_FLAME_WHEEL] = 1,
    [MOVE_SNORE] = 1,
    [MOVE_FLAIL] = 1,
    [MOVE_AEROBLAST] = 1,
    [MOVE_REVERSAL] = 1,
    [MOVE_POWDER_SNOW] = 1,
    [MOVE_PROTECT] = -1,
    [MOVE_MACH_PUNCH] = 1,
    [MOVE_FEINT_ATTACK] = 1,
    [MOVE_SLUDGE_BOMB] = 1,
    [MOVE_MUD_SLAP] = 1,
    [MOVE_OCTAZOOKA] = 1,
    [MOVE_ZAP_CANNON] = 1,
    [MOVE_ICY_WIND] = 1,
    [MOVE_DETECT] = -1,
    [MOVE_BONE_RUSH] = 1,
    [MOVE_OUTRAGE] = 1,
    [MOVE_GIGA_DRAIN] = 1,
    [MOVE_ENDURE] = -1,
    [MOVE_ROLLOUT] = 1,
    [MOVE_FALSE_SWIPE] = 1,
    [MOVE_SPARK] = 1,
    [MOVE_FURY_CUTTER] = 1,
    [MOVE_STEEL_WING] = 1,
    [MOVE_RETURN] = 1,
    [MOVE_PRESENT] = 1,
    [MOVE_FRUSTRATION] = 1,
    [MOVE_SACRED_FIRE] = 1,
    [MOVE_MAGNITUDE] = 1,
    [MOVE_DYNAMIC_PUNCH] = 1,
    [MOVE_MEGAHORN] = 1,
    [MOVE_DRAGON_BREATH] = 1,
    [MOVE_PURSUIT] = 1,
    [MOVE_RAPID_SPIN] = 1,
    [MOVE_IRON_TAIL] = 1,
    [MOVE_METAL_CLAW] = 1,
    [MOVE_VITAL_THROW] = 1,
    [MOVE_HIDDEN_POWER] = 1,
    [MOVE_CROSS_CHOP] = 1,
    [MOVE_TWISTER] = 1,
    [MOVE_CRUNCH] = 1,
    [MOVE_EXTREME_SPEED] = 1,
    [MOVE_ANCIENT_POWER] = 1,
    [MOVE_SHADOW_BALL] = 1,
    [MOVE_FUTURE_SIGHT] = 1,
    [MOVE_ROCK_SMASH] = 1,
    [MOVE_WHIRLPOOL] = 1,
    [MOVE_BEAT_UP] = 1,
    [MOVE_FAKE_OUT] = -1,
    [MOVE_UPROAR] = 1,
    [MOVE_SPIT_UP] = 1,
    [MOVE_HEAT_WAVE] = 1,
    [MOVE_FACADE] = 1,
    [MOVE_FOCUS_PUNCH] = 1,
    [MOVE_SMELLING_SALTS] = 1,
    [MOVE_SUPERPOWER] = 1,
    [MOVE_REVENGE] = 1,
    [MOVE_BRICK_BREAK] = 1,
    [MOVE_KNOCK_OFF] = 1,
    [MOVE_ENDEAVOR] = 1,
    [MOVE_ERUPTION] = 1,
    [MOVE_SECRET_POWER] = 1,
    [MOVE_DIVE] = 1,
    [MOVE_ARM_THRUST] = 1,
    [MOVE_LUSTER_PURGE] = 1,
    [MOVE_MIST_BALL] = 1,
    [MOVE_BLAZE_KICK] = 1,
    [MOVE_ICE_BALL] = 1,
    [MOVE_NEEDLE_ARM] = 1,
    [MOVE_HYPER_VOICE] = 1,
    [MOVE_POISON_FANG] = 1,
    [MOVE_CRUSH_CLAW] = 1,
    [MOVE_BLAST_BURN] = 1,
    [MOVE_HYDRO_CANNON] = 1,
    [MOVE_METEOR_MASH] = 1,
    [MOVE_ASTONISH] = 1,
    [MOVE_WEATHER_BALL] = 1,
    [MOVE_AIR_CUTTER] = 1,
    [MOVE_OVERHEAT] = 1,
    [MOVE_ROCK_TOMB] = 1,
    [MOVE_SILVER_WIND] = 1,
    [MOVE_WATER_SPOUT] = 1,
    [MOVE_SIGNAL_BEAM] = 1,
    [MOVE_SHADOW_PUNCH] = 1,
    [MOVE_EXTRASENSORY] = 1,
    [MOVE_SKY_UPPERCUT] = 1,
    [MOVE_SAND_TOMB] = 1,
    [MOVE_SHEER_COLD] = 1,
    [MOVE_MUDDY_WATER] = 1,
    [MOVE_BULLET_SEED] = 1,
    [MOVE_AERIAL_ACE] = 1,
    [MOVE_ICICLE_SPEAR] = 1,
    [MOVE_DRAGON_CLAW] = 1,
    [MOVE_FRENZY_PLANT] = 1,
    [MOVE_BOUNCE] = 1,
    [MOVE_MUD_SHOT] = 1,
    [MOVE_POISON_TAIL] = 1,
    [MOVE_COVET] = 1,
    [MOVE_VOLT_TACKLE] = 1,
    [MOVE_MAGICAL_LEAF] = 1,
    [MOVE_LEAF_BLADE] = 1,
    [MOVE_ROCK_BLAST] = 1,
    [MOVE_SHOCK_WAVE] = 1,
    [MOVE_WATER_PULSE] = 1,
    [MOVE_DOOM_DESIRE] = 1,
    [MOVE_PSYCHO_BOOST] = 1,
    [MOVE_ROOST] = 0,
    [MOVE_GRAVITY] = 0,
    [MOVE_MIRACLE_EYE] = 0,
    [MOVE_WAKE_UP_SLAP] = 1,
    [MOVE_HAMMER_ARM] = 1,
    [MOVE_GYRO_BALL] = 1,
    [MOVE_HEALING_WISH] = 0,
    [MOVE_BRINE] = 1,
    [MOVE_NATURAL_GIFT] = 1,
    [MOVE_FEINT] = 1,
    [MOVE_PLUCK] = 1,
    [MOVE_TAILWIND] = 0,
    [MOVE_ACUPRESSURE] = 0,
    [MOVE_METAL_BURST] = 0,
    [MOVE_U_TURN] = 1,
    [MOVE_CLOSE_COMBAT] = 1,
    [MOVE_PAYBACK] = 1,
    [MOVE_ASSURANCE] = 1,
    [MOVE_EMBARGO] = 0,
    [MOVE_FLING] = 1,
    [MOVE_PSYCHO_SHIFT] = 0,
    [MOVE_TRUMP_CARD] = 0,
    [MOVE_HEAL_BLOCK] = 0,
    [MOVE_WRING_OUT] = 0,
    [MOVE_POWER_TRICK] = 0,
    [MOVE_GASTRO_ACID] = 0,
    [MOVE_LUCKY_CHANT] = 0,
    [MOVE_ME_FIRST] = 0,
    [MOVE_COPYCAT] = 0,
    [MOVE_POWER_SWAP] = 0,
    [MOVE_GUARD_SWAP] = 0,
    [MOVE_PUNISHMENT] = 1,
    [MOVE_LAST_RESORT] = 1,
    [MOVE_WORRY_SEED] = 0,
    [MOVE_SUCKER_PUNCH] = 1,
    [MOVE_TOXIC_SPIKES] = 0,
    [MOVE_HEART_SWAP] = 0,
    [MOVE_AQUA_RING] = 0,
    [MOVE_MAGNET_RISE] = 0,
    [MOVE_FLARE_BLITZ] = 1,
    [MOVE_FORCE_PALM] = 1,
    [MOVE_AURA_SPHERE] = 1,
    [MOVE_ROCK_POLISH] = 0,
    [MOVE_POISON_JAB] = 1,
    [MOVE_DARK_PULSE] = 1,
    [MOVE_NIGHT_SLASH] = 1,
    [MOVE_AQUA_TAIL] = 1,
    [MOVE_SEED_BOMB] = 1,
    [MOVE_AIR_SLASH] = 1,
    [MOVE_X_SCISSOR] = 1,
    [MOVE_BUG_BUZZ] = 1,
    [MOVE_DRAGON_PULSE] = 1,
    [MOVE_DRAGON_RUSH] = 1,
    [MOVE_POWER_GEM] = 1,
    [MOVE_DRAIN_PUNCH] = 1,
    [MOVE_VACUUM_WAVE] = 1,
    [MOVE_FOCUS_BLAST] = 1,
    [MOVE_ENERGY_BALL] = 1,
    [MOVE_BRAVE_BIRD] = 1,
    [MOVE_EARTH_POWER] = 1,
    [MOVE_SWITCHEROO] = 0,
    [MOVE_GIGA_IMPACT] = 1,
    [MOVE_NASTY_PLOT] = 0,
    [MOVE_BULLET_PUNCH] = 1,
    [MOVE_AVALANCHE] = 1,
    [MOVE_ICE_SHARD] = 1,
    [MOVE_SHADOW_CLAW] = 1,
    [MOVE_THUNDER_FANG] = 1,
    [MOVE_ICE_FANG] = 1,
    [MOVE_FIRE_FANG] = 1,
    [MOVE_SHADOW_SNEAK] = 1,
    [MOVE_MUD_BOMB] = 1,
    [MOVE_PSYCHO_CUT] = 1,
    [MOVE_ZEN_HEADBUTT] = 1,
    [MOVE_MIRROR_SHOT] = 1,
    [MOVE_FLASH_CANNON] = 1,
    [MOVE_ROCK_CLIMB] = 1,
    [MOVE_DEFOG] = 0,
    [MOVE_TRICK_ROOM] = 0,
    [MOVE_DRACO_METEOR] = 1,
    [MOVE_DISCHARGE] = 1,
    [MOVE_LAVA_PLUME] = 1,
    [MOVE_LEAF_STORM] = 1,
    [MOVE_POWER_WHIP] = 1,
    [MOVE_ROCK_WRECKER] = 1,
    [MOVE_CROSS_POISON] = 1,
    [MOVE_GUNK_SHOT] = 1,
    [MOVE_IRON_HEAD] = 1,
    [MOVE_MAGNET_BOMB] = 1,
    [MOVE_STONE_EDGE] = 1,
    [MOVE_CAPTIVATE] = 0,
    [MOVE_STEALTH_ROCK] = 0,
    [MOVE_GRASS_KNOT] = 1,
    [MOVE_CHATTER] = 1,
    [MOVE_JUDGMENT] = 1,
    [MOVE_BUG_BITE] = 1,
    [MOVE_CHARGE_BEAM] = 1,
    [MOVE_WOOD_HAMMER] = 1,
    [MOVE_AQUA_JET] = 1,
    [MOVE_ATTACK_ORDER] = 1,
    [MOVE_DEFEND_ORDER] = 0,
    [MOVE_HEAL_ORDER] = 0,
    [MOVE_HEAD_SMASH] = 1,
    [MOVE_DOUBLE_HIT] = 1,
    [MOVE_ROAR_OF_TIME] = 1,
    [MOVE_SPACIAL_REND] = 1,
    [MOVE_LUNAR_DANCE] = 0,
    [MOVE_CRUSH_GRIP] = 1,
    [MOVE_MAGMA_STORM] = 1,
    [MOVE_DARK_VOID] = 0,
    [MOVE_SEED_FLARE] = 1,
    [MOVE_OMINOUS_WIND] = 1,
    [MOVE_SHADOW_FORCE] = 1,
    [MOVE_HONE_CLAWS] = 0,
    [MOVE_WIDE_GUARD] = -1,
    [MOVE_GUARD_SPLIT] = 0,
    [MOVE_POWER_SPLIT] = 0,
    [MOVE_WONDER_ROOM] = 0,
    [MOVE_PSYSHOCK] = 1,
    [MOVE_VENOSHOCK] = 1,
    [MOVE_AUTOTOMIZE] = 0,
    [MOVE_RAGE_POWDER] = 0,
    [MOVE_TELEKINESIS] = 0,
    [MOVE_MAGIC_ROOM] = 0,
    [MOVE_SMACK_DOWN] = 1,
    [MOVE_STORM_THROW] = 1,
    [MOVE_FLAME_BURST] = 1,
    [MOVE_SLUDGE_WAVE] = 1,
    [MOVE_QUIVER_DANCE] = 0,
    [MOVE_HEAVY_SLAM] = 1,
    [MOVE_SYNCHRONOISE] = 1,
    [MOVE_ELECTRO_BALL] = 1,
    [MOVE_SOAK] = 0,
    [MOVE_FLAME_CHARGE] = 1,
    [MOVE_COIL] = 0,
    [MOVE_LOW_SWEEP] = 1,
    [MOVE_ACID_SPRAY] = 1,
    [MOVE_FOUL_PLAY] = 1,
    [MOVE_SIMPLE_BEAM] = 0,
    [MOVE_ENTRAINMENT] = 0,
    [MOVE_AFTER_YOU] = 0,
    [MOVE_ROUND] = 1,
    [MOVE_ECHOED_VOICE] = 1,
    [MOVE_CHIP_AWAY] = 1,
    [MOVE_CLEAR_SMOG] = 1,
    [MOVE_STORED_POWER] = 1,
    [MOVE_QUICK_GUARD] = -1,
    [MOVE_ALLY_SWITCH] = 0,
    [MOVE_SCALD] = 1,
    [MOVE_SHELL_SMASH] = 0,
    [MOVE_HEAL_PULSE] = 0,
    [MOVE_HEX] = 1,
    [MOVE_SKY_DROP] = 1,
    [MOVE_SHIFT_GEAR] = 0,
    [MOVE_CIRCLE_THROW] = 1,
    [MOVE_INCINERATE] = 1,
    [MOVE_QUASH] = 0,
    [MOVE_ACROBATICS] = 1,
    [MOVE_REFLECT_TYPE] = 0,
    [MOVE_RETALIATE] = 1,
    [MOVE_FINAL_GAMBIT] = 1,
    [MOVE_BESTOW] = 0,
    [MOVE_INFERNO] = 1,
    [MOVE_WATER_PLEDGE] = 1,
    [MOVE_FIRE_PLEDGE] = 1,
    [MOVE_GRASS_PLEDGE] = 1,
    [MOVE_VOLT_SWITCH] = 1,
    [MOVE_STRUGGLE_BUG] = 1,
    [MOVE_BULLDOZE] = 1,
    [MOVE_FROST_BREATH] = 1,
    [MOVE_DRAGON_TAIL] = 1,
    [MOVE_WORK_UP] = 0,
    [MOVE_ELECTROWEB] = 1,
    [MOVE_WILD_CHARGE] = 1,
    [MOVE_DRILL_RUN] = 1,
    [MOVE_DUAL_CHOP] = 1,
    [MOVE_HEART_STAMP] = 1,
    [MOVE_HORN_LEECH] = 1,
    [MOVE_SACRED_SWORD] = 1,
    [MOVE_RAZOR_SHELL] = 1,
    [MOVE_HEAT_CRASH] = 1,
    [MOVE_LEAF_TORNADO] = 1,
    [MOVE_STEAMROLLER] = 1,
    [MOVE_COTTON_GUARD] = 0,
    [MOVE_NIGHT_DAZE] = 1,
    [MOVE_PSYSTRIKE] = 1,
    [MOVE_TAIL_SLAP] = 1,
    [MOVE_HURRICANE] = 1,
    [MOVE_HEAD_CHARGE] = 1,
    [MOVE_GEAR_GRIND] = 1,
    [MOVE_SEARING_SHOT] = 1,
    [MOVE_TECHNO_BLAST] = 1,
    [MOVE_RELIC_SONG] = 1,
    [MOVE_SECRET_SWORD] = 1,
    [MOVE_GLACIATE] = 1,
    [MOVE_BOLT_STRIKE] = 1,
    [MOVE_BLUE_FLARE] = 1,
    [MOVE_FIERY_DANCE] = 1,
    [MOVE_FREEZE_SHOCK] = 1,
    [MOVE_ICE_BURN] = 1,
    [MOVE_SNARL] = 1,
    [MOVE_ICICLE_CRASH] = 1,
    [MOVE_V_CREATE] = 1,
    [MOVE_FUSION_FLARE] = 1,
    [MOVE_FUSION_BOLT] = 1,
    [MOVE_FLYING_PRESS] = 1,
    [MOVE_MAT_BLOCK] = 0,
    [MOVE_BELCH] = 1,
    [MOVE_ROTOTILLER] = 0,
    [MOVE_STICKY_WEB] = 0,
    [MOVE_FELL_STINGER] = 1,
    [MOVE_PHANTOM_FORCE] = 1,
    [MOVE_TRICK_OR_TREAT] = 0,
    [MOVE_NOBLE_ROAR] = 0,
    [MOVE_ION_DELUGE] = 0,
    [MOVE_PARABOLIC_CHARGE] = 1,
    [MOVE_FORESTS_CURSE] = 0,
    [MOVE_PETAL_BLIZZARD] = 1,
    [MOVE_FREEZE_DRY] = 1,
    [MOVE_DISARMING_VOICE] = 1,
    [MOVE_PARTING_SHOT] = 0,
    [MOVE_TOPSY_TURVY] = 0,
    [MOVE_DRAINING_KISS] = 1,
    [MOVE_CRAFTY_SHIELD] = -1,
    [MOVE_FLOWER_SHIELD] = 0,
    [MOVE_GRASSY_TERRAIN] = 0,
    [MOVE_MISTY_TERRAIN] = 0,
    [MOVE_ELECTRIFY] = 0,
    [MOVE_PLAY_ROUGH] = 1,
    [MOVE_FAIRY_WIND] = 1,
    [MOVE_MOONBLAST] = 1,
    [MOVE_BOOMBURST] = 1,
    [MOVE_FAIRY_LOCK] = 0,
    [MOVE_KINGS_SHIELD] = -1,
    [MOVE_PLAY_NICE] = 0,
    [MOVE_CONFIDE] = 0,
    [MOVE_DIAMOND_STORM] = 1,
    [MOVE_STEAM_ERUPTION] = 1,
    [MOVE_HYPERSPACE_HOLE] = 1,
    [MOVE_WATER_SHURIKEN] = 1,
    [MOVE_MYSTICAL_FIRE] = 1,
    [MOVE_SPIKY_SHIELD] = -1,
    [MOVE_AROMATIC_MIST] = 0,
    [MOVE_EERIE_IMPULSE] = 0,
    [MOVE_VENOM_DRENCH] = 0,
    [MOVE_POWDER] = 0,
    [MOVE_GEOMANCY] = 0,
    [MOVE_MAGNETIC_FLUX] = 0,
    [MOVE_HAPPY_HOUR] = 0,
    [MOVE_ELECTRIC_TERRAIN] = 0,
    [MOVE_DAZZLING_GLEAM] = 1,
    [MOVE_CELEBRATE] = 0,
    [MOVE_HOLD_HANDS] = 0,
    [MOVE_BABY_DOLL_EYES] = 0,
    [MOVE_NUZZLE] = 1,
    [MOVE_HOLD_BACK] = 1,
    [MOVE_INFESTATION] = 1,
    [MOVE_POWER_UP_PUNCH] = 1,
    [MOVE_OBLIVION_WING] = 1,
    [MOVE_THOUSAND_ARROWS] = 1,
    [MOVE_THOUSAND_WAVES] = 1,
    [MOVE_LANDS_WRATH] = 1,
    [MOVE_LIGHT_OF_RUIN] = 1,
    [MOVE_ORIGIN_PULSE] = 1,
    [MOVE_PRECIPICE_BLADES] = 1,
    [MOVE_DRAGON_ASCENT] = 1,
    [MOVE_HYPERSPACE_FURY] = 1,
    [MOVE_SHORE_UP] = 0,
    [MOVE_FIRST_IMPRESSION] = -1,
    [MOVE_BANEFUL_BUNKER] = -1,
    [MOVE_SPIRIT_SHACKLE] = 1,
    [MOVE_DARKEST_LARIAT] = 1,
    [MOVE_SPARKLING_ARIA] = 1,
    [MOVE_ICE_HAMMER] = 1,
    [MOVE_FLORAL_HEALING] = 0,
    [MOVE_HIGH_HORSEPOWER] = 1,
    [MOVE_STRENGTH_SAP] = 0,
    [MOVE_SOLAR_BLADE] = 1,
    [MOVE_LEAFAGE] = 1,
    [MOVE_SPOTLIGHT] = 0,
    [MOVE_TOXIC_THREAD] = 0,
    [MOVE_LASER_FOCUS] = 0,
    [MOVE_GEAR_UP] = 0,
    [MOVE_THROAT_CHOP] = 1,
    [MOVE_POLLEN_PUFF] = 1,
    [MOVE_ANCHOR_SHOT] = 1,
    [MOVE_PSYCHIC_TERRAIN] = 0,
    [MOVE_LUNGE] = 1,
    [MOVE_FIRE_LASH] = 1,
    [MOVE_POWER_TRIP] = 1,
    [MOVE_BURN_UP] = 1,
    [MOVE_SPEED_SWAP] = 0,
    [MOVE_SMART_STRIKE] = 1,
    [MOVE_PURIFY] = 0,
    [MOVE_REVELATION_DANCE] = 1,
    [MOVE_CORE_ENFORCER] = 1,
    [MOVE_TROP_KICK] = 1,
    [MOVE_INSTRUCT] = 0,
    [MOVE_BEAK_BLAST] = 1,
    [MOVE_CLANGING_SCALES] = 1,
    [MOVE_DRAGON_HAMMER] = 1,
    [MOVE_BRUTAL_SWING] = 1,
    [MOVE_AURORA_VEIL] = 0,
    [MOVE_SHELL_TRAP] = 1,
    [MOVE_FLEUR_CANNON] = 1,
    [MOVE_PSYCHIC_FANGS] = 1,
    [MOVE_STOMPING_TANTRUM] = 1,
    [MOVE_SHADOW_BONE] = 1,
    [MOVE_ACCELEROCK] = 1,
    [MOVE_LIQUIDATION] = 1,
    [MOVE_PRISMATIC_LASER] = 1,
    [MOVE_SPECTRAL_THIEF] = 1,
    [MOVE_SUNSTEEL_STRIKE] = 1,
    [MOVE_MOONGEIST_BEAM] = 1,
    [MOVE_TEARFUL_LOOK] = 0,
    [MOVE_ZING_ZAP] = 1,
    [MOVE_NATURES_MADNESS] = 1,
    [MOVE_MULTI_ATTACK] = 1,
    [MOVE_MIND_BLOWN] = 1,
    [MOVE_PLASMA_FISTS] = 1,
    [MOVE_PHOTON_GEYSER] = 1,
    [MOVE_ZIPPY_ZAP] = 1,
    [MOVE_SPLISHY_SPLASH] = 1,
    [MOVE_FLOATY_FALL] = 1,
    [MOVE_PIKA_PAPOW] = 1,
    [MOVE_BOUNCY_BUBBLE] = 1,
    [MOVE_BUZZY_BUZZ] = 1,
    [MOVE_SIZZLY_SLIDE] = 1,
    [MOVE_GLITZY_GLOW] = 1,
    [MOVE_BADDY_BAD] = 1,
    [MOVE_SAPPY_SEED] = 1,
    [MOVE_FREEZY_FROST] = 1,
    [MOVE_SPARKLY_SWIRL] = 1,
    [MOVE_VEEVEE_VOLLEY] = 1,
    [MOVE_DOUBLE_IRON_BASH] = 1,
    [MOVE_DYNAMAX_CANNON] = 1,
    [MOVE_SNIPE_SHOT] = 1,
    [MOVE_JAW_LOCK] = 1,
    [MOVE_STUFF_CHEEKS] = 0,
    [MOVE_NO_RETREAT] = 0,
    [MOVE_TAR_SHOT] = 0,
    [MOVE_MAGIC_POWDER] = 0,
    [MOVE_DRAGON_DARTS] = 1,
    [MOVE_TEATIME] = 0,
    [MOVE_OCTOLOCK] = 0,
    [MOVE_BOLT_BEAK] = 1,
    [MOVE_FISHIOUS_REND] = 1,
    [MOVE_COURT_CHANGE] = 0,
    [MOVE_CLANGOROUS_SOUL] = 0,
    [MOVE_BODY_PRESS] = 1,
    [MOVE_DECORATE] = 0,
    [MOVE_DRUM_BEATING] = 1,
    [MOVE_SNAP_TRAP] = 1,
    [MOVE_PYRO_BALL] = 1,
    [MOVE_BEHEMOTH_BLADE] = 1,
    [MOVE_BEHEMOTH_BASH] = 1,
    [MOVE_AURA_WHEEL] = 1,
    [MOVE_BREAKING_SWIPE] = 1,
    [MOVE_BRANCH_POKE] = 1,
    [MOVE_OVERDRIVE] = 1,
    [MOVE_APPLE_ACID] = 1,
    [MOVE_GRAV_APPLE] = 1,
    [MOVE_SPIRIT_BREAK] = 1,
    [MOVE_STRANGE_STEAM] = 1,
    [MOVE_LIFE_DEW] = 0,
    [MOVE_OBSTRUCT] = -1,
    [MOVE_FALSE_SURRENDER] = 1,
    [MOVE_METEOR_ASSAULT] = 1,
    [MOVE_ETERNABEAM] = 1,
    [MOVE_STEEL_BEAM] = 1,
    [MOVE_EXPANDING_FORCE] = 1,
    [MOVE_STEEL_ROLLER] = 1,
    [MOVE_SCALE_SHOT] = 1,
    [MOVE_METEOR_BEAM] = 1,
    [MOVE_SHELL_SIDE_ARM] = 1,
    [MOVE_MISTY_EXPLOSION] = 1,
    [MOVE_GRASSY_GLIDE] = 1,
    [MOVE_RISING_VOLTAGE] = 1,
    [MOVE_TERRAIN_PULSE] = 1,
    [MOVE_SKITTER_SMACK] = 1,
    [MOVE_BURNING_JEALOUSY] = 1,
    [MOVE_LASH_OUT] = 1,
    [MOVE_POLTERGEIST] = 1,
    [MOVE_CORROSIVE_GAS] = 0,
    [MOVE_COACHING] = 0,
    [MOVE_FLIP_TURN] = 1,
    [MOVE_TRIPLE_AXEL] = 1,
    [MOVE_DUAL_WINGBEAT] = 1,
    [MOVE_SCORCHING_SANDS] = 1,
    [MOVE_JUNGLE_HEALING] = 0,
    [MOVE_WICKED_BLOW] = 1,
    [MOVE_SURGING_STRIKES] = 1,
    [MOVE_THUNDER_CAGE] = 1,
    [MOVE_DRAGON_ENERGY] = 1,
    [MOVE_FREEZING_GLARE] = 1,
    [MOVE_FIERY_WRATH] = 1,
    [MOVE_THUNDEROUS_KICK] = 1,
    [MOVE_GLACIAL_LANCE] = 1,
    [MOVE_ASTRAL_BARRAGE] = 1,
    [MOVE_EERIE_SPELL] = 1,
    [MOVE_DIRE_CLAW] = 1,
    [MOVE_PSYSHIELD_BASH] = 1,
    [MOVE_POWER_SHIFT] = 0,
    [MOVE_STONE_AXE] = 1,
    [MOVE_SPRINGTIDE_STORM] = 1,
    [MOVE_MYSTICAL_POWER] = 1,
    [MOVE_RAGING_FURY] = 1,
    [MOVE_WAVE_CRASH] = 1,
    [MOVE_CHLOROBLAST] = 1,
    [MOVE_MOUNTAIN_GALE] = 1,
    [MOVE_VICTORY_DANCE] = 0,
    [MOVE_HEADLONG_RUSH] = 1,
    [MOVE_BARB_BARRAGE] = 1,
    [MOVE_ESPER_WING] = 1,
    [MOVE_BITTER_MALICE] = 1,
    [MOVE_SHELTER] = 0,
    [MOVE_TRIPLE_ARROWS] = 1,
    [MOVE_INFERNAL_PARADE] = 1,
    [MOVE_CEASELESS_EDGE] = 1,
    [MOVE_BLEAKWIND_STORM] = 1,
    [MOVE_WILDBOLT_STORM] = 1,
    [MOVE_SANDSEAR_STORM] = 1,
    [MOVE_LUNAR_BLESSING] = 0,
    [MOVE_TAKE_HEART] = 0,
};

static const struct OamData sOam_JudgmentIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 15,
    .affineParam = 0
};

static const union AnimCmd sAnim_JudgmentIcon_X[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Triangle[] =
{
    ANIMCMD_FRAME(4, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Circle[] =
{
    ANIMCMD_FRAME(8, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_JudgmentIcon_Line[] =
{
    ANIMCMD_FRAME(12, 1),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_JudgmentIcon[] =
{
    [ANIM_ICON_X]        = sAnim_JudgmentIcon_X,
    [ANIM_ICON_TRIANGLE] = sAnim_JudgmentIcon_Triangle,
    [ANIM_ICON_CIRCLE]   = sAnim_JudgmentIcon_Circle,
    [ANIM_ICON_LINE]     = sAnim_JudgmentIcon_Line,
};

static const struct SpriteTemplate sSpriteTemplate_JudgmentIcon =
{
    .tileTag = TAG_JUDGMENT_ICON,
    .paletteTag = TAG_NONE,
    .oam = &sOam_JudgmentIcon,
    .anims = sAnims_JudgmentIcon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_JudgmentIcon,
};

static const struct CompressedSpriteSheet sBattleArenaJudgmentSymbolsSpriteSheet[] =
{
    {gBattleArenaJudgmentSymbolsGfx, 0x200, TAG_JUDGMENT_ICON},
    {0}
};

static void (* const sArenaFunctions[])(void) =
{
    [BATTLE_ARENA_FUNC_INIT]             = InitArenaChallenge,
    [BATTLE_ARENA_FUNC_GET_DATA]         = GetArenaData,
    [BATTLE_ARENA_FUNC_SET_DATA]         = SetArenaData,
    [BATTLE_ARENA_FUNC_SAVE]             = SaveArenaChallenge,
    [BATTLE_ARENA_FUNC_SET_PRIZE]        = SetArenaPrize,
    [BATTLE_ARENA_FUNC_GIVE_PRIZE]       = GiveArenaPrize,
    [BATTLE_ARENA_FUNC_GET_TRAINER_NAME] = BufferArenaOpponentName,
};

static const u16 sShortStreakPrizeItems[] =
{
    ITEM_HP_UP,
    ITEM_PROTEIN,
    ITEM_IRON,
    ITEM_CALCIUM,
    ITEM_CARBOS,
    ITEM_ZINC,
};

static const u16 sLongStreakPrizeItems[] =
{
    ITEM_BRIGHT_POWDER,
    ITEM_WHITE_HERB,
    ITEM_QUICK_CLAW,
    ITEM_LEFTOVERS,
    ITEM_MENTAL_HERB,
    ITEM_KINGS_ROCK,
    ITEM_FOCUS_BAND,
    ITEM_SCOPE_LENS,
    ITEM_CHOICE_BAND,
};

void CallBattleArenaFunction(void)
{
    sArenaFunctions[gSpecialVar_0x8004]();
}

u8 BattleArena_ShowJudgmentWindow(u8 *state)
{
    int i;
    u8 result = ARENA_RESULT_RUNNING;
    switch (*state)
    {
    case 0:
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 0, 8, RGB_BLACK);
        SetGpuReg(REG_OFFSET_WININ, (WININ_WIN0_ALL & ~WININ_WIN0_BG0) | WININ_WIN1_ALL);
        LoadCompressedSpriteSheet(sBattleArenaJudgmentSymbolsSpriteSheet);
        LoadCompressedPalette(gBattleArenaJudgmentSymbolsPalette, 0x1F0, 0x20);
        gBattle_WIN0H = 0xFF;
        gBattle_WIN0V = 0x70;
        (*state)++;
        break;
    case 1:
        if (!gPaletteFade.active)
        {
            HandleBattleWindow(5, 0, 24, 13, 0);
            (*state)++;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            gBattleTextBuff1[0] = CHAR_0;
            gBattleTextBuff1[1] = EOS;
            gBattleTextBuff2[0] = CHAR_0;
            gBattleTextBuff2[1] = EOS;
            BattleStringExpandPlaceholdersToDisplayedString(gText_PlayerMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_PLAYER_NAME);
            BattlePutTextOnWindow(gText_Vs, ARENA_WIN_VS);
            BattleStringExpandPlaceholdersToDisplayedString(gText_OpponentMon1Name);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_OPPONENT_NAME);
            BattlePutTextOnWindow(gText_Mind, ARENA_WIN_MIND);
            BattlePutTextOnWindow(gText_Skill, ARENA_WIN_SKILL);
            BattlePutTextOnWindow(gText_Body, ARENA_WIN_BODY);
            BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
            BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
            (*state)++;
        }
        break;
    case 3:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);

            // Create dividing line for the the score totals at the bottom
            for (i = 0; i < 8; i++)
            {
                u8 spriteId = CreateSprite(&sSpriteTemplate_JudgmentIcon, 64 + i * 16, 84, 0);
                StartSpriteAnim(&gSprites[spriteId], ANIM_ICON_LINE);
            }
            result = ARENA_RESULT_STEP_DONE;
            (*state)++;
        }
        break;
    case 4:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 40, ARENA_CATEGORY_MIND, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 40, ARENA_CATEGORY_MIND, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 5:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 56, ARENA_CATEGORY_SKILL, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 56, ARENA_CATEGORY_SKILL, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 6:
        PlaySE(SE_ARENA_TIMEUP1);
        ShowJudgmentSprite(80, 72, ARENA_CATEGORY_BODY, B_POSITION_PLAYER_LEFT);
        ShowJudgmentSprite(160, 72, ARENA_CATEGORY_BODY, B_POSITION_OPPONENT_LEFT);
        BattleStringExpandPlaceholdersToDisplayedString(gText_Judgment);
        BattlePutTextOnWindow(gDisplayedStringBattle, ARENA_WIN_JUDGMENT_TITLE);
        (*state)++;
        result = ARENA_RESULT_STEP_DONE;
        break;
    case 7:
        PlaySE(SE_ARENA_TIMEUP2);
        if (gBattleTextBuff1[0] > gBattleTextBuff2[0])
        {
            result = ARENA_RESULT_PLAYER_WON;
            gBattleScripting.battler = 0;
        }
        else if (gBattleTextBuff1[0] < gBattleTextBuff2[0])
        {
            result = ARENA_RESULT_PLAYER_LOST;
            gBattleScripting.battler = 1;
        }
        else
        {
            result = ARENA_RESULT_TIE;
        }
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED:
        // Finishing this state is the indicator to SpriteCB_JudgmentIcon that its safe to destroy the judgment icon sprites
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED + 1:
        SetGpuReg(REG_OFFSET_WININ, (WININ_WIN0_ALL & ~WININ_WIN0_BG0) | WININ_WIN1_ALL);
        HandleBattleWindow(5, 0, 24, 13, WINDOW_CLEAR);
        CopyBgTilemapBufferToVram(0);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 256);
        BeginNormalPaletteFade(0x7FFFFF1C, 4, 8, 0, RGB_BLACK);
        (*state)++;
        break;
    case JUDGMENT_STATE_FINISHED + 2:
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);
            FreeSpriteTilesByTag(TAG_JUDGMENT_ICON);
            result = ARENA_RESULT_STEP_DONE;
            (*state)++;
        }
        break;
    }

    return result;
}

static void ShowJudgmentSprite(u8 x, u8 y, u8 category, u8 battler)
{
    int animNum = 0;
    int pointsPlayer = 0;
    int pointsOpponent = 0;
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    switch (category)
    {
    case ARENA_CATEGORY_MIND:
        pointsPlayer = mindPoints[battler];
        pointsOpponent = mindPoints[BATTLE_OPPOSITE(battler)];
        break;
    case ARENA_CATEGORY_SKILL:
        pointsPlayer = skillPoints[battler];
        pointsOpponent = skillPoints[BATTLE_OPPOSITE(battler)];
        break;
    case ARENA_CATEGORY_BODY:
        pointsPlayer = (gBattleMons[battler].hp * 100) / hpAtStart[battler];
        pointsOpponent = (gBattleMons[BATTLE_OPPOSITE(battler)].hp * 100) / hpAtStart[BATTLE_OPPOSITE(battler)];
        break;
    }

    if (pointsPlayer > pointsOpponent)
    {
        animNum = ANIM_ICON_CIRCLE;
        // +2 to score total for winning
        if (battler != 0)
            gBattleTextBuff2[0] += 2;
        else
            gBattleTextBuff1[0] += 2;
    }
    else if (pointsPlayer == pointsOpponent)
    {
        animNum = ANIM_ICON_TRIANGLE;
        // +1 to score total for a tie
        if (battler != 0)
            gBattleTextBuff2[0] += 1;
        else
            gBattleTextBuff1[0] += 1;
    }
    else
    {
        animNum = ANIM_ICON_X;
    }

    pointsPlayer = CreateSprite(&sSpriteTemplate_JudgmentIcon, x, y, 0);
    StartSpriteAnim(&gSprites[pointsPlayer], animNum);
}

static void SpriteCB_JudgmentIcon(struct Sprite *sprite)
{
    if (gBattleCommunication[0] > JUDGMENT_STATE_FINISHED)
        DestroySprite(sprite);
}

void BattleArena_InitPoints(void)
{
    s8 *mindPoints = gBattleStruct->arenaMindPoints;
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    mindPoints[0] = 0;
    mindPoints[1] = 0;
    skillPoints[0] = 0;
    skillPoints[1] = 0;
    hpAtStart[0] = gBattleMons[0].hp;
    hpAtStart[1] = gBattleMons[1].hp;
}

void BattleArena_AddMindPoints(u8 battler)
{
    gBattleStruct->arenaMindPoints[battler] += sMindRatings[gCurrentMove];
}

void BattleArena_AddSkillPoints(u8 battler)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    if (gHitMarker & HITMARKER_OBEYS)
    {
        u8 *failedMoveBits = &gBattleStruct->alreadyStatusedMoveAttempt;
        if (*failedMoveBits & gBitTable[battler])
        {
            *failedMoveBits &= ~(gBitTable[battler]);
            skillPoints[battler] -= 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NO_EFFECT)
        {
            if (!(gMoveResultFlags & MOVE_RESULT_MISSED) || gBattleCommunication[MISS_TYPE] != B_MSG_PROTECTED)
                skillPoints[battler] -= 2;
        }
        else if ((gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE) && (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE))
        {
            skillPoints[battler] += 1;
        }
        else if (gMoveResultFlags & MOVE_RESULT_SUPER_EFFECTIVE)
        {
            skillPoints[battler] += 2;
        }
        else if (gMoveResultFlags & MOVE_RESULT_NOT_VERY_EFFECTIVE)
        {
            skillPoints[battler] -= 1;
        }
        else if (!gProtectStructs[battler].protected)
        {
            skillPoints[battler] += 1;
        }
    }
}

void BattleArena_DeductSkillPoints(u8 battler, u16 stringId)
{
    s8 *skillPoints = gBattleStruct->arenaSkillPoints;

    switch (stringId)
    {
    case STRINGID_PKMNSXMADEYUSELESS:
    case STRINGID_PKMNSXMADEITINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSFLINCHING:
    case STRINGID_PKMNSXBLOCKSY2:
    case STRINGID_PKMNSXPREVENTSYLOSS:
    case STRINGID_PKMNSXMADEYINEFFECTIVE:
    case STRINGID_PKMNSXPREVENTSBURNS:
    case STRINGID_PKMNSXBLOCKSY:
    case STRINGID_PKMNPROTECTEDBY:
    case STRINGID_PKMNPREVENTSUSAGE:
    case STRINGID_PKMNRESTOREDHPUSING:
    case STRINGID_PKMNPREVENTSPARALYSISWITH:
    case STRINGID_PKMNPREVENTSROMANCEWITH:
    case STRINGID_PKMNPREVENTSPOISONINGWITH:
    case STRINGID_PKMNPREVENTSCONFUSIONWITH:
    case STRINGID_PKMNRAISEDFIREPOWERWITH:
    case STRINGID_PKMNANCHORSITSELFWITH:
    case STRINGID_PKMNPREVENTSSTATLOSSWITH:
    case STRINGID_PKMNSTAYEDAWAKEUSING:
        skillPoints[battler] -= 3;
        break;
    }
}

// Unused
static void UpdateHPAtStart(u8 battler)
{
    u16 *hpAtStart = gBattleStruct->arenaStartHp;

    hpAtStart[battler] = gBattleMons[battler].hp;
    if (hpAtStart[BATTLE_OPPOSITE(battler)] > gBattleMons[BATTLE_OPPOSITE(battler)].hp)
        hpAtStart[BATTLE_OPPOSITE(battler)] = gBattleMons[BATTLE_OPPOSITE(battler)].hp;
}

static void InitArenaChallenge(void)
{
    bool32 isCurrent;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    gSaveBlock2Ptr->frontier.challengeStatus = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.challengePaused = FALSE;
    gSaveBlock2Ptr->frontier.disableRecordBattle = FALSE;
    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_OPEN;
    else
        isCurrent = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_50;

    if (!isCurrent)
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = 0;

    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    gTrainerBattleOpponent_A = 0;
}

static void GetArenaData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case ARENA_DATA_PRIZE:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.arenaPrize;
        break;
    case ARENA_DATA_WIN_STREAK:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
        break;
    case ARENA_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_OPEN;
        else
            gSpecialVar_Result = gSaveBlock2Ptr->frontier.winStreakActiveFlags & STREAK_ARENA_50;
        break;
    }
}

static void SetArenaData(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    switch (gSpecialVar_0x8005)
    {
    case ARENA_DATA_PRIZE:
        gSaveBlock2Ptr->frontier.arenaPrize = gSpecialVar_0x8006;
        break;
    case ARENA_DATA_WIN_STREAK:
        gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] = gSpecialVar_0x8006;
        break;
    case ARENA_DATA_WIN_STREAK_ACTIVE:
        if (lvlMode != FRONTIER_LVL_50)
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_ARENA_OPEN;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~(STREAK_ARENA_OPEN);
        }
        else
        {
            if (gSpecialVar_0x8006)
                gSaveBlock2Ptr->frontier.winStreakActiveFlags |= STREAK_ARENA_50;
            else
                gSaveBlock2Ptr->frontier.winStreakActiveFlags &= ~(STREAK_ARENA_50);
        }
        break;
    }
}

static void SaveArenaChallenge(void)
{
    gSaveBlock2Ptr->frontier.challengeStatus = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.challengePaused = TRUE;
    SaveGameFrontier();
}

static void SetArenaPrize(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode] > 41)
        gSaveBlock2Ptr->frontier.arenaPrize = sLongStreakPrizeItems[Random() % ARRAY_COUNT(sLongStreakPrizeItems)];
    else
        gSaveBlock2Ptr->frontier.arenaPrize = sShortStreakPrizeItems[Random() % ARRAY_COUNT(sShortStreakPrizeItems)];
}

static void GiveArenaPrize(void)
{
    if (AddBagItem(gSaveBlock2Ptr->frontier.arenaPrize, 1) == TRUE)
    {
        CopyItemName(gSaveBlock2Ptr->frontier.arenaPrize, gStringVar1);
        gSaveBlock2Ptr->frontier.arenaPrize = ITEM_NONE;
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

static void BufferArenaOpponentName(void)
{
    GetFrontierTrainerName(gStringVar1, gTrainerBattleOpponent_A);
}

void DrawArenaRefereeTextBox(void)
{
    u8 width = 27;
    u8 palNum = 7;

    FillBgTilemapBufferRect(0, 0,    254, 14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0,    32,  14, 1,  6, palNum);
    FillBgTilemapBufferRect(0, 0x31, 0,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x33, 1,   14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x34, 2,   14, width, 1, palNum);
    width++;
    FillBgTilemapBufferRect(0, 0x35, 28,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x36, 29,  14, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x37, 0,   15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x39, 1,   15, width, 5, palNum);
    FillBgTilemapBufferRect(0, 0x3A, 29,  15, 1,  5, palNum);
    FillBgTilemapBufferRect(0, 0x831, 0,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x833, 1,  19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x834, 2,  19, width - 2, 1, palNum);
    FillBgTilemapBufferRect(0, 0x835, 28, 19, 1,  1, palNum);
    FillBgTilemapBufferRect(0, 0x836, 29, 19, 1,  1, palNum);
}

void EraseArenaRefereeTextBox(void)
{
    u8 width;
    u8 height;
    u8 palNum = 0;

    FillBgTilemapBufferRect(0, 3, 0, 14, 1, 1, palNum);
    height = 4;
    FillBgTilemapBufferRect(0, 4, 1, 14, 1, 1, palNum);
    width = 27;
    FillBgTilemapBufferRect(0, 5, 2, 14, width, 1, palNum);
    FillBgTilemapBufferRect(0, 6, 28, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 7, 29, 14, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 8, 0, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 9, 1, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xA, 2, 15, width, height, palNum);
    FillBgTilemapBufferRect(0, 0xB, 28, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xC, 29, 15, 1, height, palNum);
    FillBgTilemapBufferRect(0, 0xD, 0, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xE, 1, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0xF, 2, 19, width, 1, palNum);
    FillBgTilemapBufferRect(0, 0x10, 28, 19, 1, 1, palNum);
    FillBgTilemapBufferRect(0, 0x11, 29, 19, 1, 1, palNum);
}
