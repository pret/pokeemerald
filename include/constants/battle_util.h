#ifndef GUARD_CONSTANTS_BATTLE_UTIL_H
#define GUARD_CONSTANTS_BATTLE_UTIL_H

#define MOVE_LIMITATION_ZEROMOVE                (1 << 0)
#define MOVE_LIMITATION_PP                      (1 << 1)
#define MOVE_LIMITATION_DISABLED                (1 << 2)
#define MOVE_LIMITATION_TORMENTED               (1 << 3)
#define MOVE_LIMITATION_TAUNT                   (1 << 4)
#define MOVE_LIMITATION_IMPRISON                (1 << 5)
#define MOVE_LIMITATION_ENCORE                  (1 << 6)
#define MOVE_LIMITATION_CHOICE_ITEM             (1 << 7)
#define MOVE_LIMITATION_ASSAULT_VEST            (1 << 8)
#define MOVE_LIMITATION_GRAVITY                 (1 << 9)
#define MOVE_LIMITATION_HEAL_BLOCK              (1 << 10)
#define MOVE_LIMITATION_BELCH                   (1 << 11)
#define MOVE_LIMITATION_THROAT_CHOP             (1 << 12)
#define MOVE_LIMITATION_STUFF_CHEEKS            (1 << 13)
#define MOVE_LIMITATION_CANT_USE_TWICE          (1 << 14)
#define MOVE_LIMITATION_UNUSABLE                (1 << 15)

#define MOVE_LIMITATION_PLACEHOLDER             (1 << 16)
#define MOVE_LIMITATIONS_ALL                    0xFFFF

#define IS_WHOLE_SIDE_ALIVE(battler)    ((IsBattlerAlive(battler) && IsBattlerAlive(GetPartnerBattler(battler))))
#define IS_ALIVE_AND_PRESENT(battler)   (IsBattlerAlive(battler) && IsBattlerSpritePresent(battler))

// Lowest and highest percentages used for damage roll calculations
#define DMG_ROLL_PERCENT_LO 85
#define DMG_ROLL_PERCENT_HI 100

// Crit chance exceptions
#define CRITICAL_HIT_BLOCKED -1
#define CRITICAL_HIT_ALWAYS  -2

#define _ADD_TRUTHY(arg) ((arg) != 0) +
#define CountTrue(arg0, ...) (RECURSIVELY(R_FOR_EACH(_ADD_TRUTHY, arg0, __VA_ARGS__)) 0)

// Switches between simulated battle calc and actual battle combat
enum ResultOption
{
    CHECK_TRIGGER, // Check the function without running scripts / setting any flags.
    AI_CHECK,  // Check the function without running scripts / setting any flags. Same as CHECK_TRIGGER but only used when additional data has to be fetched during ai calcs
    RUN_SCRIPT,
};

enum FieldEffectCases
{
    FIELD_EFFECT_TRAINER_STATUSES,
    FIELD_EFFECT_OVERWORLD_TERRAIN,
    FIELD_EFFECT_OVERWORLD_WEATHER,
};

enum AbilityEffect
{
    ABILITYEFFECT_ENDTURN,
    ABILITYEFFECT_MOVE_END_ATTACKER,
    ABILITYEFFECT_COLOR_CHANGE, // Color Change / Berserk / Anger Shell
    ABILITYEFFECT_MOVE_END,
    ABILITYEFFECT_IMMUNITY,
    ABILITYEFFECT_FORM_CHANGE_ON_HIT,
    ABILITYEFFECT_DANCER,
    ABILITYEFFECT_MOVE_END_FOES_FAINTED, // Moxie-like abilities / Battle Bond / Magician

    ABILITYEFFECT_ON_FORM_CHANGE,

    // On Switch in
    ABILITYEFFECT_TERA_SHIFT,
    ABILITYEFFECT_NEUTRALIZINGGAS,
    ABILITYEFFECT_UNNERVE,
    ABILITYEFFECT_ON_SWITCHIN,
    ABILITYEFFECT_SWITCH_IN_FORM_CHANGE,
    ABILITYEFFECT_DEPENDS_ON_ALLY, // Commander / Hospitality / Costar
    ABILITYEFFECT_ON_WEATHER,
    ABILITYEFFECT_ON_TERRAIN,
    ABILITYEFFECT_OPPORTUNIST,
};

enum ItemEffect
{
    ITEM_NO_EFFECT,
    ITEM_STATUS_CHANGE,
    ITEM_EFFECT_OTHER,
    ITEM_PP_CHANGE,
    ITEM_HP_CHANGE,
    ITEM_STATS_CHANGE,
};

enum ImmunityHealStatusOutcome
{
    IMMUNITY_NO_EFFECT,
    IMMUNITY_STATUS_CLEARED,
    IMMUNITY_CONFUSION_CLEARED,
    IMMUNITY_INFATUATION_CLEARED,
    IMMUNITY_TAUNT_CLEARED,
};

enum SleepClauseBlock
{
    NOT_BLOCKED_BY_SLEEP_CLAUSE,
    BLOCKED_BY_SLEEP_CLAUSE,
};

enum EjectPackTiming
{
    START_OF_TURN,
    END_TURN,
    OTHER,
};

enum SubCheck
{
    EXCLUDING_SUBSTITUTES,
    INCLUDING_SUBSTITUTES
};

enum WeatherFailure
{
    WEATHER_FAILURE_SAME_WEATHER,
    WEATHER_FAILURE_OVERWORLD,
    WEATHER_FAILURE_PRIMAL,
    WEATHER_FAILURE_SUCCESS,
};

#endif // GUARD_CONSTANTS_BATTLE_UTIL_H
