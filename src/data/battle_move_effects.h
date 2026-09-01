#include "battle.h"
#include "battle_scripts.h"
#include "constants/battle_factory.h"
#include "constants/battle_move_effects.h"

const struct BattleMoveEffect gBattleMoveEffects[NUM_BATTLE_MOVE_EFFECTS] =
{
    [EFFECT_PLACEHOLDER] =
    {
        .battleScript = BattleScript_EffectPlaceholder,
        .battleTvScore = 0,
    },

    [EFFECT_HIT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_STAT_CHANGE] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_DEFENSE_CURL] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_MINIMIZE] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_AUTOTOMIZE] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_GEOMANCY] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        // .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_NON_VOLATILE_STATUS] =
    {
        .battleScript = BattleScript_EffectNonVolatileStatus,
        .battleTvScore = 0, // Handled within the battle TV functions
        .encourageEncore = TRUE,
    },

    [EFFECT_TERRAIN_BOOST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DREAM_EATER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_MIRROR_MOVE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_HAZE] =
    {
        .battleScript = BattleScript_EffectHaze,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_BIDE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_ROAR] =
    {
        .battleScript = BattleScript_EffectRoar,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_CONVERSION] =
    {
        .battleScript = BattleScript_EffectConversion,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_RESTORE_HP] =
    {
        .battleScript = BattleScript_EffectRestoreHp,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_LIGHT_SCREEN] =
    {
        .battleScript = BattleScript_EffectLightScreen,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_REST] =
    {
        .battleScript = BattleScript_EffectRest,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_OHKO] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FUSION_COMBO] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FIXED_PERCENT_DAMAGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_FIXED_HP_DAMAGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_HEAL_BLOCK] =
    {
        .battleScript = BattleScript_EffectHealBlock,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_RECOIL_IF_MISS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_MIST] =
    {
        .battleScript = BattleScript_EffectMist,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_FOCUS_ENERGY] =
    {
        .battleScript = BattleScript_EffectFocusEnergy,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_CONFUSE] =
    {
        .battleScript = BattleScript_EffectConfuse,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_TRANSFORM] =
    {
        .battleScript = BattleScript_EffectTransform,
        .battleTvScore = 0, // Natural 0
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_REFLECT] =
    {
        .battleScript = BattleScript_EffectReflect,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_TWO_TURNS_ATTACK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 3,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_SUBSTITUTE] =
    {
        .battleScript = BattleScript_EffectSubstitute,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_MIMIC] =
    {
        .battleScript = BattleScript_EffectMimic,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_METRONOME] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_LEECH_SEED] =
    {
        .battleScript = BattleScript_EffectLeechSeed,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_DO_NOTHING] =
    {
        .battleScript = BattleScript_EffectDoNothing,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_HOLD_HANDS] =
    {
        .battleScript = BattleScript_EffectHoldHands,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_CELEBRATE] =
    {
        .battleScript = BattleScript_EffectCelebrate,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_HAPPY_HOUR] =
    {
        .battleScript = BattleScript_EffectHappyHour,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_DISABLE] =
    {
        .battleScript = BattleScript_EffectDisable,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_LEVEL_DAMAGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
    },

    [EFFECT_PSYWAVE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_REFLECT_DAMAGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
        .encourageEncore = TRUE,
    },

    [EFFECT_ENCORE] =
    {
        .battleScript = BattleScript_EffectEncore,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_PAIN_SPLIT] =
    {
        .battleScript = BattleScript_EffectPainSplit,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_SNORE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 3,
    },

    [EFFECT_CONVERSION_2] =
    {
        .battleScript = BattleScript_EffectConversion2,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_LOCK_ON] =
    {
        .battleScript = BattleScript_EffectLockOn,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SKETCH] =
    {
        .battleScript = BattleScript_EffectSketch,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_SLEEP_TALK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_DESTINY_BOND] =
    {
        .battleScript = BattleScript_EffectDestinyBond,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FLAIL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_SPITE] =
    {
        .battleScript = BattleScript_EffectSpite,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_WEAKENING,
    },

    [EFFECT_FALSE_SWIPE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_HEAL_BELL] =
    {
        .battleScript = BattleScript_EffectHealBell,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_TRIPLE_KICK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_MEAN_LOOK] =
    {
        .battleScript = BattleScript_EffectMeanLook,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_NIGHTMARE] =
    {
        .battleScript = BattleScript_EffectNightmare,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_CURSE] =
    {
        .battleScript = BattleScript_EffectCurse,
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_HEALING_WISH] =
    {
        .battleScript = BattleScript_EffectHealingWish,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_LUNAR_DANCE] =
    {
        .battleScript = BattleScript_EffectHealingWish,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PROTECT] =
    {
        .battleScript = BattleScript_EffectProtect,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
        .usesProtectCounter = TRUE,
    },

    [EFFECT_SPIKES] =
    {
        .battleScript = BattleScript_EffectSpikes,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_FORESIGHT] =
    {
        .battleScript = BattleScript_EffectForesight,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_PERISH_SONG] =
    {
        .battleScript = BattleScript_EffectPerishSong,
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
        .encourageEncore = TRUE,
    },

    [EFFECT_ENDURE] =
    {
        .battleScript = BattleScript_EffectEndure,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
        .usesProtectCounter = TRUE,
    },

    [EFFECT_ROLLOUT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 3,
    },

    [EFFECT_SWAGGER] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_FURY_CUTTER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
    },

    [EFFECT_ATTRACT] =
    {
        .battleScript = BattleScript_EffectAttract,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_RETURN] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_PRESENT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_FRUSTRATION] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_SAFEGUARD] =
    {
        .battleScript = BattleScript_EffectSafeguard,
        .battleTvScore = 5,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_MAGNITUDE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_BATON_PASS] =
    {
        .battleScript = BattleScript_EffectBatonPass,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
    },

    [EFFECT_PURSUIT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
    },

    [EFFECT_CAPTIVATE] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MORNING_SUN] =
    {
        .battleScript = BattleScript_EffectMorningSun,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_SYNTHESIS] =
    {
        .battleScript = BattleScript_EffectSynthesis,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_MOONLIGHT] =
    {
        .battleScript = BattleScript_EffectMoonlight,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_HIDDEN_POWER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_WEATHER] =
    {
        .battleScript = BattleScript_EffectWeather,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_WEATHER,
        .encourageEncore = TRUE,
    },

    [EFFECT_FELL_STINGER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STAT_CHANGE_HALF_HP] =
    {
        .battleScript = BattleScript_EffectStatChangeHalfHp,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_BELLY_DRUM] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_PSYCH_UP] =
    {
        .battleScript = BattleScript_EffectPsychUp,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_EARTHQUAKE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_FUTURE_SIGHT] =
    {
        .battleScript = BattleScript_EffectFutureSight,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SOLAR_BEAM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_TELEPORT] =
    {
        .battleScript = BattleScript_EffectTeleport,
        .battleTvScore = 1,
    },

    [EFFECT_BEAT_UP] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
    },

    [EFFECT_SEMI_INVULNERABLE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 3,
        .twoTurnEffect = TRUE,
        .semiInvulnerableEffect = TRUE,
    },

    [EFFECT_SOFTBOILED] =
    {
        .battleScript = BattleScript_EffectSoftboiled,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_FIRST_TURN_ONLY] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_STOCKPILE] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPIT_UP] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SWALLOW] =
    {
        .battleScript = BattleScript_EffectSwallow,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_OVERWRITE_ABILITY] =
    {
        .battleScript = BattleScript_EffectOverwriteAbility,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TORMENT] =
    {
        .battleScript = BattleScript_EffectTorment,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_MEMENTO] =
    {
        .battleScript = BattleScript_EffectMemento,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FACADE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_FOCUS_PUNCH] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 7,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
    },

    [EFFECT_DOUBLE_POWER_ON_ARG_STATUS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_FOLLOW_ME] =
    {
        .battleScript = BattleScript_EffectFollowMe,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_NATURE_POWER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // Natural 0
    },

    [EFFECT_CHARGE] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_TAUNT] =
    {
        .battleScript = BattleScript_EffectTaunt,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_HELPING_HAND] =
    {
        .battleScript = BattleScript_EffectHelpingHand,
        .battleTvScore = 4,
    },

    [EFFECT_TRICK] =
    {
        .battleScript = BattleScript_EffectTrick,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_ROLE_PLAY] =
    {
        .battleScript = BattleScript_EffectRolePlay,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_WISH] =
    {
        .battleScript = BattleScript_EffectWish,
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
    },

    [EFFECT_ASSIST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
    },

    [EFFECT_INGRAIN] =
    {
        .battleScript = BattleScript_EffectIngrain,
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_MAGIC_COAT] =
    {
        .battleScript = BattleScript_EffectMagicCoat,
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
    },

    [EFFECT_RECYCLE] =
    {
        .battleScript = BattleScript_EffectRecycle,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_REVENGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 4,
    },

    [EFFECT_YAWN] =
    {
        .battleScript = BattleScript_EffectYawn,
        .battleTvScore = 5,
    },

    [EFFECT_KNOCK_OFF] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
        .battleFactoryStyle = FACTORY_STYLE_WEAKENING,
    },

    [EFFECT_STEAL_ITEM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 3,
    },

    [EFFECT_ENDEAVOR] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_POWER_BASED_ON_USER_HP] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_SKILL_SWAP] =
    {
        .battleScript = BattleScript_EffectSkillSwap,
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_IMPRISON] =
    {
        .battleScript = BattleScript_EffectImprison,
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
        .encourageEncore = TRUE,
    },

    [EFFECT_REFRESH] =
    {
        .battleScript = BattleScript_EffectRefresh,
        .battleTvScore = 6,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_GRUDGE] =
    {
        .battleScript = BattleScript_EffectGrudge,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_HIGH_RISK,
        .encourageEncore = TRUE,
    },

    [EFFECT_SNATCH] =
    {
        .battleScript = BattleScript_EffectSnatch,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_SLOW_STEADY,
    },

    [EFFECT_LOW_KICK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_HIT_ESCAPE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 4,
    },

    [EFFECT_MUD_SPORT] =
    {
        .battleScript = BattleScript_EffectMudSport,
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_WEATHER_BALL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_WEATHER,
    },

    [EFFECT_WATER_SPORT] =
    {
        .battleScript = BattleScript_EffectWaterSport,
        .battleTvScore = 4,
        .battleFactoryStyle = FACTORY_STYLE_ENDURANCE,
        .encourageEncore = TRUE,
    },

    [EFFECT_CAMOUFLAGE] =
    {
        .battleScript = BattleScript_EffectCamouflage,
        .battleTvScore = 3,
        .battleFactoryStyle = FACTORY_STYLE_UNPREDICTABLE,
        .encourageEncore = TRUE,
    },

    [EFFECT_PLEDGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FLING] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_NATURAL_GIFT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_POWER_BASED_ON_TARGET_HP] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ASSURANCE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TRUMP_CARD] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ACROBATICS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HEAT_CRASH] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PUNISHMENT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STORED_POWER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ELECTRO_BALL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GYRO_BALL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ECHOED_VOICE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PAYBACK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ROUND] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BRINE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RETALIATE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FOUL_PLAY] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PSYSHOCK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ROOST] =
    {
        .battleScript = BattleScript_EffectRoost,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GRAVITY] =
    {
        .battleScript = BattleScript_EffectGravity,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_MIRACLE_EYE] =
    {
        .battleScript = BattleScript_EffectMiracleEye,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TAILWIND] =
    {
        .battleScript = BattleScript_EffectTailwind,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_EMBARGO] =
    {
        .battleScript = BattleScript_EffectEmbargo,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_AQUA_RING] =
    {
        .battleScript = BattleScript_EffectAquaRing,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TRICK_ROOM] =
    {
        .battleScript = BattleScript_EffectTrickRoom,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_WONDER_ROOM] =
    {
        .battleScript = BattleScript_EffectWonderRoom,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAGIC_ROOM] =
    {
        .battleScript = BattleScript_EffectMagicRoom,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAGNET_RISE] =
    {
        .battleScript = BattleScript_EffectMagnetRise,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TOXIC_SPIKES] =
    {
        .battleScript = BattleScript_EffectToxicSpikes,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GASTRO_ACID] =
    {
        .battleScript = BattleScript_EffectGastroAcid,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STEALTH_ROCK] =
    {
        .battleScript = BattleScript_EffectStealthRock,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TELEKINESIS] =
    {
        .battleScript = BattleScript_EffectTelekinesis,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_POWER_SWAP] =
    {
        .battleScript = BattleScript_EffectPowerSwap,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GUARD_SWAP] =
    {
        .battleScript = BattleScript_EffectGuardSwap,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_HEART_SWAP] =
    {
        .battleScript = BattleScript_EffectHeartSwap,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POWER_SPLIT] =
    {
        .battleScript = BattleScript_EffectPowerSplit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GUARD_SPLIT] =
    {
        .battleScript = BattleScript_EffectGuardSplit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STICKY_WEB] =
    {
        .battleScript = BattleScript_EffectStickyWeb,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_LUCKY_CHANT] =
    {
        .battleScript = BattleScript_EffectLuckyChant,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SUCKER_PUNCH] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ENTRAINMENT] =
    {
        .battleScript = BattleScript_EffectEntrainment,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HEAL_PULSE] =
    {
        .battleScript = BattleScript_EffectHealPulse,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_QUASH] =
    {
        .battleScript = BattleScript_EffectQuash,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_ION_DELUGE] =
    {
        .battleScript = BattleScript_EffectIonDeluge,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SUPER_EFFECTIVE_ON_ARG] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TOPSY_TURVY] =
    {
        .battleScript = BattleScript_EffectTopsyTurvy,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERRAIN] =
    {
        .battleScript = BattleScript_EffectTerrain,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TWO_TYPED_MOVE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ME_FIRST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ELECTRIFY] =
    {
        .battleScript = BattleScript_EffectElectrify,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_REFLECT_TYPE] =
    {
        .battleScript = BattleScript_EffectReflectType,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SOAK] =
    {
        .battleScript = BattleScript_EffectSoak,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GROWTH] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_LAST_RESORT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STAT_CHANGE_ON_STATUS] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TOXIC_THREAD] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HIT_SWITCH_TARGET] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FINAL_GAMBIT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CHANGE_TYPE_ON_ITEM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_COPYCAT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DEFOG] =
    {
        .battleScript = BattleScript_EffectDefog,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_HIT_ENEMY_HEAL_ALLY] =
    {
        .battleScript = BattleScript_EffectHitEnemyHealAlly,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SYNCHRONOISE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PSYCHO_SHIFT] =
    {
        .battleScript = BattleScript_EffectPsychoShift,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POWER_TRICK] =
    {
        .battleScript = BattleScript_EffectPowerTrick,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_AFTER_YOU] =
    {
        .battleScript = BattleScript_EffectAfterYou,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_BESTOW] =
    {
        .battleScript = BattleScript_EffectBestow,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_ROTOTILLER] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FLOWER_SHIELD] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SPEED_SWAP] =
    {
        .battleScript = BattleScript_EffectSpeedSwap,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_REVELATION_DANCE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_AURORA_VEIL] =
    {
        .battleScript = BattleScript_EffectAuroraVeil,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_THIRD_TYPE] =
    {
        .battleScript = BattleScript_EffectThirdType,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ACUPRESSURE] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POWDER] =
    {
        .battleScript = BattleScript_EffectPowder,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BELCH] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PARTING_SHOT] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAT_BLOCK] =
    {
        .battleScript = BattleScript_EffectProtect,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_STOMPING_TANTRUM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_INSTRUCT] =
    {
        .battleScript = BattleScript_EffectInstruct,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_LASER_FOCUS] =
    {
        .battleScript = BattleScript_EffectLaserFocus,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_STAT_CHANGE_MAGNETIC] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_STRENGTH_SAP] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PURIFY] =
    {
        .battleScript = BattleScript_EffectPurify,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_FAIL_IF_NOT_ARG_TYPE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHORE_UP] =
    {
        .battleScript = BattleScript_EffectShoreUp,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_FAIRY_LOCK] =
    {
        .battleScript = BattleScript_EffectFairyLock,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ALLY_SWITCH] =
    {
        .battleScript = BattleScript_EffectAllySwitch,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BODY_PRESS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_JUNGLE_HEALING] =
    {
        .battleScript = BattleScript_EffectJungleHealing,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_LASH_OUT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GRASSY_GLIDE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DYNAMAX_DOUBLE_DMG] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SNIPE_SHOT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STRUGGLE] =
    {
        .battleScript = BattleScript_EffectStruggle,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STUFF_CHEEKS] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GRAV_APPLE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HYPERSPACE_FURY] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_AURA_WHEEL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PHOTON_GEYSER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERRAIN_PULSE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_NO_RETREAT] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TAR_SHOT] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POLTERGEIST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_OCTOLOCK] =
    {
        .battleScript = BattleScript_EffectOctolock,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CLANGOROUS_SOUL] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BOLT_BEAK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SKY_DROP] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
        .twoTurnEffect = TRUE,
        .semiInvulnerableEffect = TRUE,
    },

    [EFFECT_BEAK_BLAST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_COURT_CHANGE] =
    {
        .battleScript = BattleScript_EffectCourtChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAX_HP_50_RECOIL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CHLOROBLAST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_EXTREME_EVOBOOST] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DARK_VOID] =
    {
        .battleScript = BattleScript_EffectNonVolatileStatus,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TEATIME] =
    {
        .battleScript = BattleScript_EffectTeatime,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SHELL_TRAP] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HYDRO_STEAM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_REVIVAL_BLESSING] =
    {
        .battleScript = BattleScript_EffectRevivalBlessing,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TAKE_HEART] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_COLLISION_COURSE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CORROSIVE_GAS] =
    {
        .battleScript = BattleScript_EffectCorrosiveGas,
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_WEAKENING,
    },

    [EFFECT_POPULATION_BOMB] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_WEATHER_AND_SWITCH] =
    {
        .battleScript =BattleScript_EffectWeatherAndSwitch,
        .battleTvScore = 0, // TODO: Assign points
        .battleFactoryStyle = FACTORY_STYLE_WEATHER,
    },

    [EFFECT_MAX_MOVE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAGING_BULL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAGE_FIST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DOODLE] =
    {
        .battleScript = BattleScript_EffectDoodle,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_IVY_CUDGEL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FICKLE_BEAM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHED_TAIL] =
    {
        .battleScript = BattleScript_EffectShedTail,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_UPPER_HAND] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_DRAGON_CHEER] =
    {
        .battleScript = BattleScript_EffectFocusEnergy,
        .battleTvScore = 1,
        .battleFactoryStyle = FACTORY_STYLE_PREPARATION,
        .encourageEncore = TRUE,
    },

    [EFFECT_LAST_RESPECTS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TIDY_UP] =
    {
        .battleScript = BattleScript_EffectStatChange,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TERA_BLAST] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERA_STARSTORM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHELL_SIDE_ARM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAPID_SPIN] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
    },

    [EFFECT_RECOIL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SMACK_DOWN] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_LIFE_DEW] =
    {
        .battleScript = BattleScript_EffectLifeDew,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ICE_SPINNER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STEEL_ROLLER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STONE_AXE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CEASELESS_EDGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SPECIES_POWER_OVERRIDE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SCALE_SHOT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },
};
