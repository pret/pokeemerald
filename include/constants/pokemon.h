#ifndef GUARD_CONSTANTS_POKEMON_H
#define GUARD_CONSTANTS_POKEMON_H

// Pokémon types
enum __attribute__((packed)) Type
{
    TYPE_NONE = 0,
    TYPE_NORMAL = 1,
    TYPE_FIGHTING = 2,
    TYPE_FLYING = 3,
    TYPE_POISON = 4,
    TYPE_GROUND = 5,
    TYPE_ROCK = 6,
    TYPE_BUG = 7,
    TYPE_GHOST = 8,
    TYPE_STEEL = 9,
    TYPE_MYSTERY = 10,
    TYPE_FIRE = 11,
    TYPE_WATER = 12,
    TYPE_GRASS = 13,
    TYPE_ELECTRIC = 14,
    TYPE_PSYCHIC = 15,
    TYPE_ICE = 16,
    TYPE_DRAGON = 17,
    TYPE_DARK = 18,
    TYPE_FAIRY = 19,
    TYPE_STELLAR = 20,
    NUMBER_OF_MON_TYPES
};

// Pokémon egg groups
enum __attribute__((packed)) EggGroup
{
    EGG_GROUP_NONE,
    EGG_GROUP_MONSTER,
    EGG_GROUP_WATER_1,
    EGG_GROUP_BUG,
    EGG_GROUP_FLYING,
    EGG_GROUP_FIELD,
    EGG_GROUP_FAIRY,
    EGG_GROUP_GRASS,
    EGG_GROUP_HUMAN_LIKE,
    EGG_GROUP_WATER_3,
    EGG_GROUP_MINERAL,
    EGG_GROUP_AMORPHOUS,
    EGG_GROUP_WATER_2,
    EGG_GROUP_DITTO,
    EGG_GROUP_DRAGON,
    EGG_GROUP_NO_EGGS_DISCOVERED,
};

#define EGG_GROUPS_PER_MON            2

// Pokémon natures
#define NATURE_HARDY    0 // Neutral
#define NATURE_LONELY   1 // +Atk -Def
#define NATURE_BRAVE    2 // +Atk -Speed
#define NATURE_ADAMANT  3 // +Atk -SpAtk
#define NATURE_NAUGHTY  4 // +Atk -SpDef
#define NATURE_BOLD     5 // +Def -Atk
#define NATURE_DOCILE   6 // Neutral
#define NATURE_RELAXED  7 // +Def -Speed
#define NATURE_IMPISH   8 // +Def -SpAtk
#define NATURE_LAX      9 // +Def -SpDef
#define NATURE_TIMID    10 // +Speed -Atk
#define NATURE_HASTY    11 // +Speed -Def
#define NATURE_SERIOUS  12 // Neutral
#define NATURE_JOLLY    13 // +Speed -SpAtk
#define NATURE_NAIVE    14 // +Speed - SpDef
#define NATURE_MODEST   15 // +SpAtk -Atk
#define NATURE_MILD     16 // +SpAtk -Def
#define NATURE_QUIET    17 // +SpAtk -Speed
#define NATURE_BASHFUL  18 // Neutral
#define NATURE_RASH     19 // +SpAtk -SpDef
#define NATURE_CALM     20 // +SpDef -Atk
#define NATURE_GENTLE   21 // +SpDef -Def
#define NATURE_SASSY    22 // +SpDef -Speed
#define NATURE_CAREFUL  23 // +SpDef -SpAtk
#define NATURE_QUIRKY   24 // Neutral
#define NUM_NATURES     25

#define NATURE_RANDOM            NUM_NATURES
#define NATURE_MAY_SYNCHRONIZE   NUM_NATURES + 1

// Pokémon Stats
enum __attribute__((packed)) Stat
{
    STAT_HP,
    STAT_ATK,
    STAT_DEF,
    STAT_SPEED,
    STAT_SPATK,
    STAT_SPDEF,
    NUM_STATS,
    STAT_ACC = NUM_STATS, // Only in battles.
    STAT_EVASION,         // Only in battles.
};

#define NUM_NATURE_STATS (NUM_STATS - 1) // excludes HP
#define NUM_BATTLE_STATS (NUM_STATS + 2) // includes Accuracy and Evasion

#define MIN_STAT_STAGE     0
#define DEFAULT_STAT_STAGE 6
#define MAX_STAT_STAGE    12

// Shiny odds
#define SHINY_ODDS 8 // Actual probability is SHINY_ODDS/65536

// Ribbon IDs used by TV and Pokénav
#define CHAMPION_RIBBON       0
#define COOL_RIBBON_NORMAL    1
#define COOL_RIBBON_SUPER     2
#define COOL_RIBBON_HYPER     3
#define COOL_RIBBON_MASTER    4
#define BEAUTY_RIBBON_NORMAL  5
#define BEAUTY_RIBBON_SUPER   6
#define BEAUTY_RIBBON_HYPER   7
#define BEAUTY_RIBBON_MASTER  8
#define CUTE_RIBBON_NORMAL    9
#define CUTE_RIBBON_SUPER    10
#define CUTE_RIBBON_HYPER    11
#define CUTE_RIBBON_MASTER   12
#define SMART_RIBBON_NORMAL  13
#define SMART_RIBBON_SUPER   14
#define SMART_RIBBON_HYPER   15
#define SMART_RIBBON_MASTER  16
#define TOUGH_RIBBON_NORMAL  17
#define TOUGH_RIBBON_SUPER   18
#define TOUGH_RIBBON_HYPER   19
#define TOUGH_RIBBON_MASTER  20
#define WINNING_RIBBON       21
#define VICTORY_RIBBON       22
#define ARTIST_RIBBON        23
#define EFFORT_RIBBON        24
#define MARINE_RIBBON        25
#define LAND_RIBBON          26
#define SKY_RIBBON           27
#define COUNTRY_RIBBON       28
#define NATIONAL_RIBBON      29
#define EARTH_RIBBON         30
#define WORLD_RIBBON         31

#define FIRST_GIFT_RIBBON MARINE_RIBBON
#define LAST_GIFT_RIBBON  WORLD_RIBBON
#define NUM_GIFT_RIBBONS  (1 + LAST_GIFT_RIBBON - FIRST_GIFT_RIBBON)

// The above gift ribbons (Marine - World) are
// special distribution ribbons that correspond to
// 1 bit each in the Pokémon struct. Gen 4 hard-codes
// each of these to the given name. In Gen 3 they're
// used to get an index into giftRibbons in the save block,
// which can have a value 0-64 (0 is 'no ribbon') that
// corresponds to one of the special ribbons listed
// in gGiftRibbonDescriptionPointers. Most of these were
// never distributed
#define MAX_GIFT_RIBBON 64

#define MIN_LEVEL 1
#define MAX_LEVEL 100

#define MAX_DYNAMAX_LEVEL 10

enum OtIdMethod
{
    OT_ID_PLAYER_ID,
    OT_ID_PRESET,
    OT_ID_RANDOM_NO_SHINY
};

#define MON_GIVEN_TO_PARTY      0
#define MON_GIVEN_TO_PC         1
#define MON_CANT_GIVE           2

#define PLAYER_HAS_TWO_USABLE_MONS     0
#define PLAYER_HAS_ONE_MON             1
#define PLAYER_HAS_ONE_USABLE_MON      2

#define MON_ALREADY_KNOWS_MOVE  0xFFFE
#define MON_HAS_MAX_MOVES       0xFFFF

#define LEVEL_UP_MOVE_ID   0x01FF
#define LEVEL_UP_MOVE_LV   0xFE00
#define LEVEL_UP_MOVE_END  0xFFFF

#define MON_MALE       0x00
#define MON_FEMALE     0xFE
#define MON_GENDERLESS 0xFF

#define MON_GENDER_RANDOM         0x01
#define MON_GENDER_MAY_CUTE_CHARM 0x02

// Constants for AdjustFriendship
#define FRIENDSHIP_EVENT_GROW_LEVEL       0
#define FRIENDSHIP_EVENT_VITAMIN          1 // unused, handled by PokemonUseItemEffects
#define FRIENDSHIP_EVENT_BATTLE_ITEM      2 // unused, handled by PokemonUseItemEffects
#define FRIENDSHIP_EVENT_LEAGUE_BATTLE    3
#define FRIENDSHIP_EVENT_LEARN_TMHM       4
#define FRIENDSHIP_EVENT_WALKING          5
#define FRIENDSHIP_EVENT_FAINT_SMALL      6
#define FRIENDSHIP_EVENT_FAINT_FIELD_PSN  7
#define FRIENDSHIP_EVENT_FAINT_LARGE      8 // If opponent was >= 30 levels higher. See AdjustFriendshipOnBattleFaint
#define FRIENDSHIP_EVENT_MASSAGE          9

// Constants for GetLeadMonFriendshipScore
#define FRIENDSHIP_NONE        0
#define FRIENDSHIP_1_TO_49     1
#define FRIENDSHIP_50_TO_99    2
#define FRIENDSHIP_100_TO_149  3
#define FRIENDSHIP_150_TO_199  4
#define FRIENDSHIP_200_TO_254  5
#define FRIENDSHIP_MAX         6

// Constants for GetBattlerAffectionHearts (based on friendship value)
#define AFFECTION_NO_HEARTS     0 // 0-79 friendship
#define AFFECTION_ONE_HEART     1 // 80-129 friendship
#define AFFECTION_TWO_HEARTS    2 // 130-179 friendship
#define AFFECTION_THREE_HEARTS  3 // 180-219 friendship
#define AFFECTION_FOUR_HEARTS   4 // 220-254 friendship
#define AFFECTION_FIVE_HEARTS   5 // Max friendship

// Friendship value that the majority of species use.
#define STANDARD_FRIENDSHIP ((P_UPDATED_FRIENDSHIP >= GEN_8) ? 50 : 70)

#define MAX_FRIENDSHIP  255
#define MAX_SHEEN       255
#define MAX_CONDITION   255

#define MAX_PER_STAT_IVS 31
#define MAX_IV_MASK 31
#define USE_RANDOM_IVS (MAX_PER_STAT_IVS + 1)
#define MAX_PER_STAT_EVS ((P_EV_CAP >= GEN_6) ? 252 : 255)
#define MAX_TOTAL_EVS 510
#define EV_ITEM_RAISE_LIMIT ((I_VITAMIN_EV_CAP >= GEN_8) ? MAX_PER_STAT_EVS : 100)

// Move category defines.
enum __attribute__((packed)) DamageCategory
{
    DAMAGE_CATEGORY_NONE,
    DAMAGE_CATEGORY_PHYSICAL,
    DAMAGE_CATEGORY_SPECIAL,
    DAMAGE_CATEGORY_STATUS
};

// Growth rates
enum __attribute__((packed)) GrowthRate
{
    GROWTH_MEDIUM_FAST,
    GROWTH_ERRATIC,
    GROWTH_FLUCTUATING,
    GROWTH_MEDIUM_SLOW,
    GROWTH_FAST,
    GROWTH_SLOW,
};

// Body colors for Pokédex search
enum BodyColor
{
    BODY_COLOR_RED,
    BODY_COLOR_BLUE,
    BODY_COLOR_YELLOW,
    BODY_COLOR_GREEN,
    BODY_COLOR_BLACK,
    BODY_COLOR_BROWN,
    BODY_COLOR_PURPLE,
    BODY_COLOR_GRAY,
    BODY_COLOR_WHITE,
    BODY_COLOR_PINK,
};

#define F_SUMMARY_SCREEN_FLIP_SPRITE 0x80

#define EVOLUTIONS_END                    0xFFFF // Not an actual evolution, used to mark the end of an evolution array.

enum EvolutionConditions {
    // Gen 2
    IF_GENDER,                          // The Pokémon is of specific gender.
    IF_TIME,                            // It is currently the specific time of day.
    IF_NOT_TIME,                        // It is NOT currently the specific time of day.
    IF_MIN_FRIENDSHIP,                  // The Pokémon has the defined amount of Friendship.
    IF_ATK_GT_DEF,                      // The Pokémon's Attack is greater than its Defense stat.
    IF_ATK_EQ_DEF,                      // The Pokémon's Attack is equal to its Defense stat.
    IF_ATK_LT_DEF,                      // The Pokémon's Attack is lower than its Defense stat.
    IF_HOLD_ITEM,                       // The Pokémon is holding a specific item.
    // Gen 3
    IF_PID_UPPER_MODULO_10_GT,          // The Pokémon's upper personality value's modulo by 10 is greater than the defined value.
    IF_PID_UPPER_MODULO_10_EQ,          // The Pokémon's upper personality value's modulo by 10 is equal to the defined value.
    IF_PID_UPPER_MODULO_10_LT,          // The Pokémon's upper personality value's modulo by 10 is lower or equal than the defined value.
    IF_MIN_BEAUTY,                      // The Pokémon has the defined amount of Beauty.
    IF_MIN_COOLNESS,                    // The Pokémon has the defined amount of Coolness.
    IF_MIN_SMARTNESS,                   // The Pokémon has the defined amount of Smartness. (aka Cleverness in Gen6+)
    IF_MIN_TOUGHNESS,                   // The Pokémon has the defined amount of Toughness.
    IF_MIN_CUTENESS,                    // The Pokémon has the defined amount of Cuteness.
    // Gen 4
    IF_SPECIES_IN_PARTY,                // The party contains a Pokémon of the specified species.
    IF_IN_MAP,                          // The player is currently in the specific map.
    IF_IN_MAPSEC,                       // The player is currently in the specific map sector.
    IF_KNOWS_MOVE,                      // The Pokémon knows specific move.
    // Gen 5
    IF_TRADE_PARTNER_SPECIES,           // The Pokémon is traded for a specific species.
    // Gen 6
    IF_TYPE_IN_PARTY,                   // The party contains a Pokémon of the specified type.
    IF_WEATHER,                         // It is currently the specific weather in the current map.
    IF_KNOWS_MOVE_TYPE,                 // The Pokémon knows a move with a specific type.
    // Gen 8
    IF_NATURE,                          // The Pokémon has a specific nature.
    IF_AMPED_NATURE,                    // The Pokémon has one of the following natures: Hardy, Brave, Adamant, Naughty, Docile, Impish, Lax, Hasty, Jolly, Naive, Rash, Sassy, or Quirky.
    IF_LOW_KEY_NATURE,                  // The Pokémon has one of the following natures: Lonely, Bold, Relaxed, Timid, Serious, Modest, Mild, Quiet, Bashful, Calm, Gentle, or Careful.
    IF_RECOIL_DAMAGE_GE,                // The Pokémon suffered at least certain amount of non-fainting recoil damage.
    IF_CURRENT_DAMAGE_GE,               // The Pokémon has the specified difference of HP from its Max HP.
    IF_CRITICAL_HITS_GE,                // The Pokémon performed the specified number of critical hits in one battle at least.
    IF_USED_MOVE_X_TIMES,               // The Pokémon has used a move for at least X amount of times.
    // Gen 9
    IF_DEFEAT_X_WITH_ITEMS,             // The Pokémon defeated X amount of Pokémon of the specified species that are holding the specified item.
    IF_PID_MODULO_100_GT,               // The Pokémon's personality value's modulo by 100 is greater than the defined value.
    IF_PID_MODULO_100_EQ,               // The Pokémon's personality value's modulo by 100 is equal than the defined value.
    IF_PID_MODULO_100_LT,               // The Pokémon's personality value's modulo by 100 is lower than the defined value.
    IF_MIN_OVERWORLD_STEPS,             // The Player has taken a specific amount of steps in the overworld with the Pokémon following them or in the first slot of the party.
    IF_BAG_ITEM_COUNT,                  // The Player has the specific amount of an item in the bag. It then removes those items.
    IF_REGION,                          // The Player is in the specific region.
    IF_NOT_REGION,                      // The Player is NOT in the specific region.
    CONDITIONS_END
};

enum EvolutionMethods {
    EVO_NONE,                   // Not an actual evolution, used to generate offspring that can't evolve into the specified species, like regional forms.
    EVO_LEVEL,                  // Pokémon reaches the specified level
    EVO_TRADE,                  // Pokémon is traded
    EVO_ITEM,                   // specified item is used on Pokémon
    EVO_SPLIT_FROM_EVO,         // A clone is generated and evolved when another evolution happens
    EVO_SCRIPT_TRIGGER,         // Player interacts with an overworld trigger
    EVO_LEVEL_BATTLE_ONLY,      // Pokémon reaches the specified level, in battle only
    EVO_BATTLE_END,             // Battle ends, doesn't need to level up
    EVO_SPIN                    // The player spins in the overworld
};

enum EvolutionMode {
    EVO_MODE_NORMAL,
    EVO_MODE_TRADE,
    EVO_MODE_ITEM_USE,
    EVO_MODE_ITEM_CHECK,         // If an Everstone is being held, still want to show that the stone *could* be used on that Pokémon to evolve
    EVO_MODE_BATTLE_SPECIAL,
    EVO_MODE_OVERWORLD_SPECIAL,
    EVO_MODE_SCRIPT_TRIGGER,
    EVO_MODE_BATTLE_ONLY,        // This mode is only used in battles to support Tandemaus' unique requirement
};

enum EvoTriggerVersion {
    EVO_TRIGGER_TABLET_CURSE,
    EVO_TRIGGER_DARK_SCROLL,
    EVO_TRIGGER_WATER_SCROLL,
};

enum EvolutionEventResult {
    EVO_EVENT_IMPOSSIBLE,
    EVO_EVENT_INTERRUPTED,
    EVO_EVENT_SUCCESSFUL,
};

// used to determine whether an evolution is happening or not, so we know if items should be removed
enum EvoState {
    CHECK_EVO,
    DO_EVO,
};

enum PokemonJumpType {
    PKMN_JUMP_TYPE_NONE,        // Not allowed in Pokémon Jump
    PKMN_JUMP_TYPE_NORMAL,
    PKMN_JUMP_TYPE_FAST,
    PKMN_JUMP_TYPE_SLOW,
};

enum EvoSpinDirections {
    SPIN_CW_SHORT,              // Player spins clockwise
    SPIN_CW_LONG,               // Player spins clockwise
    SPIN_CCW_SHORT,             // Player spins counter-clockwise
    SPIN_CCW_LONG,              // Player spins counter-clockwise
    SPIN_EITHER,                // Player spins either clockwise or counter-clockwise
};

enum ShinyMode {
    SHINY_MODE_NEVER,
    SHINY_MODE_ALWAYS,
    SHINY_MODE_RANDOM,
};

enum GeneratedMonOrigin
{
    UNDEFINED_MON_ORIGIN,
    WILDMON_ORIGIN,
    STATIC_WILDMON_ORIGIN,
    ROAMER_ORIGIN,
    GIFTMON_ORIGIN
};

#define MON_PIC_WIDTH 64
#define MON_PIC_HEIGHT 64
#define MON_PIC_SIZE (MON_PIC_WIDTH * MON_PIC_HEIGHT / 2)

// Most Pokémon have 2 frames (a default and an alternate for their animation).
// There are 4 exceptions:
// - Deoxys has 2 frames, 1 for each form
// - Spinda has 1 frame, presumably to avoid the work of animating its spots
// - Unown has 1 frame, presumably to avoid the work of animating all 28 of its forms
#define MAX_MON_PIC_FRAMES 2

#define BATTLE_ALIVE_EXCEPT_BATTLER      0
#define BATTLE_ALIVE_EXCEPT_BATTLER_SIDE 1
#define BATTLE_ALIVE_SIDE                2

#define SKIP_FRONT_ANIM (1 << 7)

#define NUM_ABILITY_SLOTS (NUM_NORMAL_ABILITY_SLOTS + NUM_HIDDEN_ABILITY_SLOTS)
#define NUM_NORMAL_ABILITY_SLOTS 2
#define NUM_HIDDEN_ABILITY_SLOTS 1

// Used as a signal for givemon to generate a default ability by personality.
#define NUM_ABILITY_PERSONALITY 0xFF

#if P_LEGENDARY_PERFECT_IVS >= GEN_6
#define LEGENDARY_PERFECT_IV_COUNT 3
#else
#define LEGENDARY_PERFECT_IV_COUNT 0
#endif

#endif // GUARD_CONSTANTS_POKEMON_H
