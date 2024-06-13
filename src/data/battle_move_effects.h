#include "battle.h"
#include "battle_scripts.h"
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

    [EFFECT_SLEEP] =
    {
        .battleScript = BattleScript_EffectSleep,
        .battleTvScore = 1,
    },

    [EFFECT_ABSORB] =
    {
        .battleScript = BattleScript_EffectAbsorb,
        .battleTvScore = 4,
    },

    [EFFECT_EXPLOSION] =
    {
        .battleScript = BattleScript_EffectExplosion,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DREAM_EATER] =
    {
        .battleScript = BattleScript_EffectDreamEater,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_MIRROR_MOVE] =
    {
        .battleScript = BattleScript_EffectMirrorMove,
        .battleTvScore = 1,
    },

    [EFFECT_ATTACK_UP] =
    {
        .battleScript = BattleScript_EffectAttackUp,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_DEFENSE_UP] =
    {
        .battleScript = BattleScript_EffectDefenseUp,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPEED_UP] =
    {
        .battleScript = BattleScript_EffectSpeedUp,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPECIAL_ATTACK_UP] =
    {
        .battleScript = BattleScript_EffectSpecialAttackUp,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPECIAL_DEFENSE_UP] =
    {
        .battleScript = BattleScript_EffectSpecialDefenseUp,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_ACCURACY_UP] =
    {
        .battleScript = BattleScript_EffectAccuracyUp,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_EVASION_UP] =
    {
        .battleScript = BattleScript_EffectEvasionUp,
        .battleTvScore = 1,
    },

    [EFFECT_SPECIAL_ATTACK_UP_3] =
    {
        .battleScript = BattleScript_EffectSpecialAttackUp3,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ATTACK_DOWN] =
    {
        .battleScript = BattleScript_EffectAttackDown,
        .battleTvScore = 1,
    },

    [EFFECT_DEFENSE_DOWN] =
    {
        .battleScript = BattleScript_EffectDefenseDown,
        .battleTvScore = 1,
    },

    [EFFECT_SPEED_DOWN] =
    {
        .battleScript = BattleScript_EffectSpeedDown,
        .battleTvScore = 1,
    },

    [EFFECT_SPECIAL_ATTACK_DOWN] =
    {
        .battleScript = BattleScript_EffectSpecialAttackDown,
        .battleTvScore = 1,
    },

    [EFFECT_SPECIAL_DEFENSE_DOWN] =
    {
        .battleScript = BattleScript_EffectSpecialDefenseDown,
        .battleTvScore = 1,
    },

    [EFFECT_ACCURACY_DOWN] =
    {
        .battleScript = BattleScript_EffectAccuracyDown,
        .battleTvScore = 1,
    },

    [EFFECT_EVASION_DOWN] =
    {
        .battleScript = BattleScript_EffectEvasionDown,
        .battleTvScore = 1,
    },

    [EFFECT_HAZE] =
    {
        .battleScript = BattleScript_EffectHaze,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_BIDE] =
    {
        .battleScript = BattleScript_EffectBide,
        .battleTvScore = 5,
    },

    [EFFECT_ROAR] =
    {
        .battleScript = BattleScript_EffectRoar,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_MULTI_HIT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_CONVERSION] =
    {
        .battleScript = BattleScript_EffectConversion,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_RESTORE_HP] =
    {
        .battleScript = BattleScript_EffectRestoreHp,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_TOXIC] =
    {
        .battleScript = BattleScript_EffectToxic,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_LIGHT_SCREEN] =
    {
        .battleScript = BattleScript_EffectLightScreen,
        .battleTvScore = 7,
        .encourageEncore = TRUE,
    },

    [EFFECT_REST] =
    {
        .battleScript = BattleScript_EffectRest,
        .battleTvScore = 7,
        .encourageEncore = TRUE,
    },

    [EFFECT_OHKO] =
    {
        .battleScript = BattleScript_EffectOHKO,
        .battleTvScore = 7,
    },

    [EFFECT_FUSION_COMBO] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SUPER_FANG] =
    {
        .battleScript = BattleScript_EffectSuperFang,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_FIXED_DAMAGE_ARG] =
    {
        .battleScript = BattleScript_EffectFixedDamageArg,
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
        .battleScript = BattleScript_EffectRecoilIfMiss,
        .battleTvScore = 1,
    },

    [EFFECT_MIST] =
    {
        .battleScript = BattleScript_EffectMist,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_FOCUS_ENERGY] =
    {
        .battleScript = BattleScript_EffectFocusEnergy,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_CONFUSE] =
    {
        .battleScript = BattleScript_EffectConfuse,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_ATTACK_UP_2] =
    {
        .battleScript = BattleScript_EffectAttackUp2,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_DEFENSE_UP_2] =
    {
        .battleScript = BattleScript_EffectDefenseUp2,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPEED_UP_2] =
    {
        .battleScript = BattleScript_EffectSpeedUp2,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPECIAL_ATTACK_UP_2] =
    {
        .battleScript = BattleScript_EffectSpecialAttackUp2,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPECIAL_DEFENSE_UP_2] =
    {
        .battleScript = BattleScript_EffectSpecialDefenseUp2,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_ACCURACY_UP_2] =
    {
        .battleScript = BattleScript_EffectAccuracyUp2,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_EVASION_UP_2] =
    {
        .battleScript = BattleScript_EffectEvasionUp2,
        .battleTvScore = 1,
    },

    [EFFECT_TRANSFORM] =
    {
        .battleScript = BattleScript_EffectTransform,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ATTACK_DOWN_2] =
    {
        .battleScript = BattleScript_EffectAttackDown2,
        .battleTvScore = 1,
    },

    [EFFECT_DEFENSE_DOWN_2] =
    {
        .battleScript = BattleScript_EffectDefenseDown2,
        .battleTvScore = 1,
    },

    [EFFECT_SPEED_DOWN_2] =
    {
        .battleScript = BattleScript_EffectSpeedDown2,
        .battleTvScore = 1,
    },

    [EFFECT_SPECIAL_ATTACK_DOWN_2] =
    {
        .battleScript = BattleScript_EffectSpecialAttackDown2,
        .battleTvScore = 1,
    },

    [EFFECT_SPECIAL_DEFENSE_DOWN_2] =
    {
        .battleScript = BattleScript_EffectSpecialDefenseDown2,
        .battleTvScore = 1,
    },

    [EFFECT_ACCURACY_DOWN_2] =
    {
        .battleScript = BattleScript_EffectAccuracyDown2,
        .battleTvScore = 1,
    },

    [EFFECT_EVASION_DOWN_2] =
    {
        .battleScript = BattleScript_EffectEvasionDown2,
        .battleTvScore = 1,
    },

    [EFFECT_REFLECT] =
    {
        .battleScript = BattleScript_EffectReflect,
        .battleTvScore = 7,
        .encourageEncore = TRUE,
    },

    [EFFECT_POISON] =
    {
        .battleScript = BattleScript_EffectPoison,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_PARALYZE] =
    {
        .battleScript = BattleScript_EffectParalyze,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_TWO_TURNS_ATTACK] =
    {
        .battleScript = BattleScript_EffectTwoTurnsAttack,
        .battleTvScore = 3,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_SUBSTITUTE] =
    {
        .battleScript = BattleScript_EffectSubstitute,
        .battleTvScore = 4,
    },

    [EFFECT_RAGE] =
    {
        .battleScript = BattleScript_EffectRage,
        .battleTvScore = 2,
    },

    [EFFECT_MIMIC] =
    {
        .battleScript = BattleScript_EffectMimic,
        .battleTvScore = 4,
    },

    [EFFECT_METRONOME] =
    {
        .battleScript = BattleScript_EffectMetronome,
        .battleTvScore = 1,
    },

    [EFFECT_LEECH_SEED] =
    {
        .battleScript = BattleScript_EffectLeechSeed,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_DO_NOTHING] =
    {
        .battleScript = BattleScript_EffectDoNothing,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_DISABLE] =
    {
        .battleScript = BattleScript_EffectDisable,
        .battleTvScore = 7,
    },

    [EFFECT_LEVEL_DAMAGE] =
    {
        .battleScript = BattleScript_EffectLevelDamage,
        .battleTvScore = 2,
    },

    [EFFECT_PSYWAVE] =
    {
        .battleScript = BattleScript_EffectPsywave,
        .battleTvScore = 1,
    },

    [EFFECT_COUNTER] =
    {
        .battleScript = BattleScript_EffectCounter,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_ENCORE] =
    {
        .battleScript = BattleScript_EffectEncore,
        .battleTvScore = 7,
    },

    [EFFECT_PAIN_SPLIT] =
    {
        .battleScript = BattleScript_EffectPainSplit,
        .battleTvScore = 3,
    },

    [EFFECT_SNORE] =
    {
        .battleScript = BattleScript_EffectSnore,
        .battleTvScore = 3,
    },

    [EFFECT_CONVERSION_2] =
    {
        .battleScript = BattleScript_EffectConversion2,
        .battleTvScore = 4,
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
    },

    [EFFECT_SLEEP_TALK] =
    {
        .battleScript = BattleScript_EffectSleepTalk,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_DESTINY_BOND] =
    {
        .battleScript = BattleScript_EffectDestinyBond,
        .battleTvScore = 3,
    },

    [EFFECT_FLAIL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
    },

    [EFFECT_SPITE] =
    {
        .battleScript = BattleScript_EffectSpite,
        .battleTvScore = 4,
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
        .encourageEncore = TRUE,
    },

    [EFFECT_NIGHTMARE] =
    {
        .battleScript = BattleScript_EffectNightmare,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_MINIMIZE] =
    {
        .battleScript = BattleScript_EffectMinimize,
        .battleTvScore = 1,
    },

    [EFFECT_CURSE] =
    {
        .battleScript = BattleScript_EffectCurse,
        .battleTvScore = 2,
        .encourageEncore = TRUE,
    },

    [EFFECT_HEALING_WISH] =
    {
        .battleScript = BattleScript_EffectHealingWish,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PROTECT] =
    {
        .battleScript = BattleScript_EffectProtect,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
        .usesProtectCounter = TRUE,
    },

    [EFFECT_SPIKES] =
    {
        .battleScript = BattleScript_EffectSpikes,
        .battleTvScore = 4,
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
        .encourageEncore = TRUE,
    },

    [EFFECT_SANDSTORM] =
    {
        .battleScript = BattleScript_EffectSandstorm,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_ENDURE] =
    {
        .battleScript = BattleScript_EffectEndure,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
        .usesProtectCounter = TRUE,
    },

    [EFFECT_ROLLOUT] =
    {
        .battleScript = BattleScript_EffectRollout,
        .battleTvScore = 3,
    },

    [EFFECT_SWAGGER] =
    {
        .battleScript = BattleScript_EffectSwagger,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_FURY_CUTTER] =
    {
        .battleScript = BattleScript_EffectFuryCutter,
        .battleTvScore = 2,
    },

    [EFFECT_ATTRACT] =
    {
        .battleScript = BattleScript_EffectAttract,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_RETURN] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_PRESENT] =
    {
        .battleScript = BattleScript_EffectPresent,
        .battleTvScore = 1,
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
        .encourageEncore = TRUE,
    },

    [EFFECT_MAGNITUDE] =
    {
        .battleScript = BattleScript_EffectMagnitude,
        .battleTvScore = 1,
    },

    [EFFECT_BATON_PASS] =
    {
        .battleScript = BattleScript_EffectBatonPass,
        .battleTvScore = 7,
    },

    [EFFECT_PURSUIT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 2,
    },

    [EFFECT_CAPTIVATE] =
    {
        .battleScript = BattleScript_EffectCaptivate,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MORNING_SUN] =
    {
        .battleScript = BattleScript_EffectMorningSun,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_SYNTHESIS] =
    {
        .battleScript = BattleScript_EffectSynthesis,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_MOONLIGHT] =
    {
        .battleScript = BattleScript_EffectMoonlight,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_HIDDEN_POWER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_RAIN_DANCE] =
    {
        .battleScript = BattleScript_EffectRainDance,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_SUNNY_DAY] =
    {
        .battleScript = BattleScript_EffectSunnyDay,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_FELL_STINGER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BELLY_DRUM] =
    {
        .battleScript = BattleScript_EffectBellyDrum,
        .battleTvScore = 7,
        .encourageEncore = TRUE,
    },

    [EFFECT_PSYCH_UP] =
    {
        .battleScript = BattleScript_EffectPsychUp,
        .battleTvScore = 7,
        .encourageEncore = TRUE,
    },

    [EFFECT_MIRROR_COAT] =
    {
        .battleScript = BattleScript_EffectMirrorCoat,
        .battleTvScore = 6,
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
        .battleScript = BattleScript_EffectTwoTurnsAttack,
        .battleTvScore = 1,
        .twoTurnEffect = TRUE,
    },

    [EFFECT_THUNDER] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_TELEPORT] =
    {
        .battleScript = BattleScript_EffectTeleport,
        .battleTvScore = 1,
    },

    [EFFECT_BEAT_UP] =
    {
        .battleScript = BattleScript_EffectBeatUp,
        .battleTvScore = 2,
    },

    [EFFECT_SEMI_INVULNERABLE] =
    {
        .battleScript = BattleScript_EffectTwoTurnsAttack,
        .battleTvScore = 3,
        .twoTurnEffect = TRUE,
        .semiInvulnerableEffect = TRUE,
    },

    [EFFECT_DEFENSE_CURL] =
    {
        .battleScript = BattleScript_EffectDefenseCurl,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SOFTBOILED] =
    {
        .battleScript = BattleScript_EffectSoftboiled,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_FIRST_TURN_ONLY] =
    {
        .battleScript = BattleScript_EffectFirstTurnOnly,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_UPROAR] =
    {
        .battleScript = BattleScript_EffectUproar,
        .battleTvScore = 4,
    },

    [EFFECT_STOCKPILE] =
    {
        .battleScript = BattleScript_EffectStockpile,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SPIT_UP] =
    {
        .battleScript = BattleScript_EffectSpitUp,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_SWALLOW] =
    {
        .battleScript = BattleScript_EffectSwallow,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_WORRY_SEED] =
    {
        .battleScript = BattleScript_EffectWorrySeed,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_HAIL] =
    {
        .battleScript = BattleScript_EffectHail,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_TORMENT] =
    {
        .battleScript = BattleScript_EffectTorment,
        .battleTvScore = 7,
        .encourageEncore = TRUE,
    },

    [EFFECT_FLATTER] =
    {
        .battleScript = BattleScript_EffectFlatter,
        .battleTvScore = 7,
    },

    [EFFECT_WILL_O_WISP] =
    {
        .battleScript = BattleScript_EffectWillOWisp,
        .battleTvScore = 5,
        .encourageEncore = TRUE,
    },

    [EFFECT_MEMENTO] =
    {
        .battleScript = BattleScript_EffectMemento,
        .battleTvScore = 7,
    },

    [EFFECT_FACADE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_FOCUS_PUNCH] =
    {
        .battleScript = BattleScript_EffectFocusPunch,
        .battleTvScore = 7,
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
        .battleScript = BattleScript_EffectNaturePower,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CHARGE] =
    {
        .battleScript = BattleScript_EffectCharge,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_TAUNT] =
    {
        .battleScript = BattleScript_EffectTaunt,
        .battleTvScore = 4,
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
        .encourageEncore = TRUE,
    },

    [EFFECT_ROLE_PLAY] =
    {
        .battleScript = BattleScript_EffectRolePlay,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_WISH] =
    {
        .battleScript = BattleScript_EffectWish,
        .battleTvScore = 2,
    },

    [EFFECT_ASSIST] =
    {
        .battleScript = BattleScript_EffectAssist,
        .battleTvScore = 2,
    },

    [EFFECT_INGRAIN] =
    {
        .battleScript = BattleScript_EffectIngrain,
        .battleTvScore = 6,
        .encourageEncore = TRUE,
    },

    [EFFECT_MAGIC_COAT] =
    {
        .battleScript = BattleScript_EffectMagicCoat,
        .battleTvScore = 6,
    },

    [EFFECT_RECYCLE] =
    {
        .battleScript = BattleScript_EffectRecycle,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_REVENGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 4,
    },

    [EFFECT_BRICK_BREAK] =
    {
        .battleScript = BattleScript_EffectBrickBreak,
        .battleTvScore = 2,
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
    },

    [EFFECT_ENDEAVOR] =
    {
        .battleScript = BattleScript_EffectEndeavor,
        .battleTvScore = 1,
    },

    [EFFECT_ERUPTION] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_SKILL_SWAP] =
    {
        .battleScript = BattleScript_EffectSkillSwap,
        .battleTvScore = 6,
        .encourageEncore = TRUE,
    },

    [EFFECT_IMPRISON] =
    {
        .battleScript = BattleScript_EffectImprison,
        .battleTvScore = 6,
        .encourageEncore = TRUE,
    },

    [EFFECT_REFRESH] =
    {
        .battleScript = BattleScript_EffectRefresh,
        .battleTvScore = 6,
        .encourageEncore = TRUE,
    },

    [EFFECT_GRUDGE] =
    {
        .battleScript = BattleScript_EffectGrudge,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_SNATCH] =
    {
        .battleScript = BattleScript_EffectSnatch,
        .battleTvScore = 1,
    },

    [EFFECT_LOW_KICK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_HIT_ESCAPE] =
    {
        .battleScript = BattleScript_EffectHitEscape,
        .battleTvScore = 4,
    },

    [EFFECT_MUD_SPORT] =
    {
        .battleScript = BattleScript_EffectMudSport,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_WEATHER_BALL] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 1,
    },

    [EFFECT_TICKLE] =
    {
        .battleScript = BattleScript_EffectTickle,
        .battleTvScore = 1,
    },

    [EFFECT_COSMIC_POWER] =
    {
        .battleScript = BattleScript_EffectCosmicPower,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_BULK_UP] =
    {
        .battleScript = BattleScript_EffectBulkUp,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_WATER_SPORT] =
    {
        .battleScript = BattleScript_EffectWaterSport,
        .battleTvScore = 4,
        .encourageEncore = TRUE,
    },

    [EFFECT_CALM_MIND] =
    {
        .battleScript = BattleScript_EffectCalmMind,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_DRAGON_DANCE] =
    {
        .battleScript = BattleScript_EffectDragonDance,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_CAMOUFLAGE] =
    {
        .battleScript = BattleScript_EffectCamouflage,
        .battleTvScore = 3,
        .encourageEncore = TRUE,
    },

    [EFFECT_PLEDGE] =
    {
        .battleScript = BattleScript_EffectPledge,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FLING] =
    {
        .battleScript = BattleScript_EffectFling,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_NATURAL_GIFT] =
    {
        .battleScript = BattleScript_EffectNaturalGift,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_VARY_POWER_BASED_ON_HP] =
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
        .battleScript = BattleScript_EffectMircleEye,
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

    [EFFECT_METAL_BURST] =
    {
        .battleScript = BattleScript_EffectMetalBurst,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_LUCKY_CHANT] =
    {
        .battleScript = BattleScript_EffectLuckyChant,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SUCKER_PUNCH] =
    {
        .battleScript = BattleScript_EffectSuckerPunch,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SIMPLE_BEAM] =
    {
        .battleScript = BattleScript_EffectSimpleBeam,
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

    [EFFECT_MISTY_TERRAIN] =
    {
        .battleScript = BattleScript_EffectMistyTerrain,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GRASSY_TERRAIN] =
    {
        .battleScript = BattleScript_EffectGrassyTerrain,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ELECTRIC_TERRAIN] =
    {
        .battleScript = BattleScript_EffectElectricTerrain,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PSYCHIC_TERRAIN] =
    {
        .battleScript = BattleScript_EffectPsychicTerrain,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ATTACK_ACCURACY_UP] =
    {
        .battleScript = BattleScript_EffectAttackAccUp,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_ATTACK_SPATK_UP] =
    {
        .battleScript = BattleScript_EffectAttackSpAttackUp,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TWO_TYPED_MOVE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_ME_FIRST] =
    {
        .battleScript = BattleScript_EffectMeFirst,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_QUIVER_DANCE] =
    {
        .battleScript = BattleScript_EffectQuiverDance,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_COIL] =
    {
        .battleScript = BattleScript_EffectCoil,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
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
        .battleScript = BattleScript_EffectGrowth,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_LAST_RESORT] =
    {
        .battleScript = BattleScript_EffectLastResort,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHELL_SMASH] =
    {
        .battleScript = BattleScript_EffectShellSmash,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SHIFT_GEAR] =
    {
        .battleScript = BattleScript_EffectShiftGear,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_DEFENSE_UP_3] =
    {
        .battleScript = BattleScript_EffectDefenseUp3,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_NOBLE_ROAR] =
    {
        .battleScript = BattleScript_EffectNobleRoar,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_VENOM_DRENCH] =
    {
        .battleScript = BattleScript_EffectVenomDrench,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TOXIC_THREAD] =
    {
        .battleScript = BattleScript_EffectToxicThread,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HIT_SWITCH_TARGET] =
    {
        .battleScript = BattleScript_EffectHitSwitchTarget,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FINAL_GAMBIT] =
    {
        .battleScript = BattleScript_EffectFinalGambit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CHANGE_TYPE_ON_ITEM] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_AUTOTOMIZE] =
    {
        .battleScript = BattleScript_EffectAutotomize,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_COPYCAT] =
    {
        .battleScript = BattleScript_EffectCopycat,
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
        .battleScript = BattleScript_EffectSynchronoise,
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
        .battleScript = BattleScript_EffectRototiller,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FLOWER_SHIELD] =
    {
        .battleScript = BattleScript_EffectFlowerShield,
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
        .battleScript = BattleScript_EffectAcupressure,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_AROMATIC_MIST] =
    {
        .battleScript = BattleScript_EffectAromaticMist,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
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
        .battleScript = BattleScript_EffectPartingShot,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAT_BLOCK] =
    {
        .battleScript = BattleScript_EffectMatBlock,
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

    [EFFECT_MAGNETIC_FLUX] =
    {
        .battleScript = BattleScript_EffectMagneticFlux,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GEAR_UP] =
    {
        .battleScript = BattleScript_EffectGearUp,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_STRENGTH_SAP] =
    {
        .battleScript = BattleScript_EffectStrengthSap,
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
        .battleScript = BattleScript_FailIfNotArgType,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHORE_UP] =
    {
        .battleScript = BattleScript_EffectShoreUp,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GEOMANCY] =
    {
        .battleScript = BattleScript_EffectGeomancy,
        .battleTvScore = 0, // TODO: Assign points
        .twoTurnEffect = TRUE,
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

    [EFFECT_RELIC_SONG] =
    {
        .battleScript = BattleScript_EffectRelicSong,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BODY_PRESS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_EERIE_SPELL] =
    {
        .battleScript = BattleScript_EffectEerieSpell,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_JUNGLE_HEALING] =
    {
        .battleScript = BattleScript_EffectJungleHealing,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_COACHING] =
    {
        .battleScript = BattleScript_EffectCoaching,
        .battleTvScore = 0, // TODO: Assign points
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

    [EFFECT_DECORATE] =
    {
        .battleScript = BattleScript_EffectDecorate,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SNIPE_SHOT] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RECOIL_HP_25] =
    {
        .battleScript = BattleScript_EffectRecoilHP25,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_STUFF_CHEEKS] =
    {
        .battleScript = BattleScript_EffectStuffCheeks,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_GRAV_APPLE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GLITZY_GLOW] =
    {
        .battleScript = BattleScript_EffectGlitzyGlow,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BADDY_BAD] =
    {
        .battleScript = BattleScript_EffectBaddyBad,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SAPPY_SEED] =
    {
        .battleScript = BattleScript_EffectSappySeed,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_FREEZY_FROST] =
    {
        .battleScript = BattleScript_EffectFreezyFrost,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SPARKLY_SWIRL] =
    {
        .battleScript = BattleScript_EffectSparklySwirl,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PLASMA_FISTS] =
    {
        .battleScript = BattleScript_EffectPlasmaFists,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HYPERSPACE_FURY] =
    {
        .battleScript = BattleScript_EffectHyperspaceFury,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_AURA_WHEEL] =
    {
        .battleScript = BattleScript_EffectAuraWheel,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PHOTON_GEYSER] =
    {
        .battleScript = BattleScript_EffectPhotonGeyser,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERRAIN_PULSE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_NO_RETREAT] =
    {
        .battleScript = BattleScript_EffectNoRetreat,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TAR_SHOT] =
    {
        .battleScript = BattleScript_EffectTarShot,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_POLTERGEIST] =
    {
        .battleScript = BattleScript_EffectPoltergeist,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_OCTOLOCK] =
    {
        .battleScript = BattleScript_EffectOctolock,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CLANGOROUS_SOUL] =
    {
        .battleScript = BattleScript_EffectClangorousSoul,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_BOLT_BEAK] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SKY_DROP] =
    {
        .battleScript = BattleScript_EffectSkyDrop,
        .battleTvScore = 0, // TODO: Assign points
        .twoTurnEffect = TRUE,
        .semiInvulnerableEffect = TRUE,
    },

    [EFFECT_EXPANDING_FORCE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RISING_VOLTAGE] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
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

    [EFFECT_MIND_BLOWN] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_EXTREME_EVOBOOST] =
    {
        .battleScript = BattleScript_EffectExtremeEvoboost,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_HIT_SET_REMOVE_TERRAIN] =
    {
        .battleScript = BattleScript_EffectHitSetRemoveTerrain,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DARK_VOID] =
    {
        .battleScript = BattleScript_EffectDarkVoid,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_VICTORY_DANCE] =
    {
        .battleScript = BattleScript_EffectVictoryDance,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TEATIME] =
    {
        .battleScript = BattleScript_EffectTeatime,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_ATTACK_UP_USER_ALLY] =
    {
        .battleScript = BattleScript_EffectAttackUpUserAlly,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SHELL_TRAP] =
    {
        .battleScript = BattleScript_EffectShellTrap,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_PSYBLADE] =
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

    [EFFECT_SNOWSCAPE] =
    {
        .battleScript = BattleScript_EffectSnow,
        .battleTvScore = 4,
    },

    [EFFECT_TAKE_HEART] =
    {
        .battleScript = BattleScript_EffectTakeHeart,
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
    },

    [EFFECT_POPULATION_BOMB] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_SALT_CURE] =
    {
        .battleScript = BattleScript_EffectSaltCure,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_CHILLY_RECEPTION] =
    {
        .battleScript = BattleScript_EffectChillyReception,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_MAX_MOVE] =
    {
        .battleScript = BattleScript_EffectMaxMove,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_GLAIVE_RUSH] =
    {
        .battleScript = BattleScript_EffectGlaiveRush,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAGING_BULL] =
    {
        .battleScript = BattleScript_EffectBrickBreak,
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

    [EFFECT_FILLET_AWAY] =
    {
        .battleScript = BattleScript_EffectFilletAway,
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

    [EFFECT_BLIZZARD] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_RAIN_ALWAYS_HIT] =
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
        .battleScript = BattleScript_EffectUpperHand,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_DRAGON_CHEER] =
    {
        .battleScript = BattleScript_EffectFocusEnergy,
        .battleTvScore = 1,
        .encourageEncore = TRUE,
    },

    [EFFECT_LAST_RESPECTS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TIDY_UP] =
    {
        .battleScript = BattleScript_EffectTidyUp,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_SPICY_EXTRACT] =
    {
        .battleScript = BattleScript_EffectSpicyExtract,
        .battleTvScore = 0, // TODO: Assign points
        .encourageEncore = TRUE,
    },

    [EFFECT_TERA_BLAST] =
    {
        .battleScript = BattleScript_EffectPhotonGeyser,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_TERA_STARSTORM] =
    {
        .battleScript = BattleScript_EffectPhotonGeyser,
        .battleTvScore = 0, // TODO: Assign points
    },

    [EFFECT_DRAGON_DARTS] =
    {
        .battleScript = BattleScript_EffectHit,
        .battleTvScore = 0, // TODO: Assign points
    },
};
