#ifndef GUARD_CONSTANTS_POKEMON_H
#define GUARD_CONSTANTS_POKEMON_H

// Pokémon types
#define TYPE_NONE             0
#define TYPE_NORMAL           1
#define TYPE_FIGHTING         2
#define TYPE_FLYING           3
#define TYPE_POISON           4
#define TYPE_GROUND           5
#define TYPE_ROCK             6
#define TYPE_BUG              7
#define TYPE_GHOST            8
#define TYPE_STEEL            9
#define TYPE_MYSTERY          10
#define TYPE_FIRE             11
#define TYPE_WATER            12
#define TYPE_GRASS            13
#define TYPE_ELECTRIC         14
#define TYPE_PSYCHIC          15
#define TYPE_ICE              16
#define TYPE_DRAGON           17
#define TYPE_DARK             18
#define TYPE_FAIRY            19
#define TYPE_STELLAR          20
#define NUMBER_OF_MON_TYPES   21

// Pokémon egg groups
#define EGG_GROUP_NONE                0
#define EGG_GROUP_MONSTER             1
#define EGG_GROUP_WATER_1             2
#define EGG_GROUP_BUG                 3
#define EGG_GROUP_FLYING              4
#define EGG_GROUP_FIELD               5
#define EGG_GROUP_FAIRY               6
#define EGG_GROUP_GRASS               7
#define EGG_GROUP_HUMAN_LIKE          8
#define EGG_GROUP_WATER_3             9
#define EGG_GROUP_MINERAL             10
#define EGG_GROUP_AMORPHOUS           11
#define EGG_GROUP_WATER_2             12
#define EGG_GROUP_DITTO               13
#define EGG_GROUP_DRAGON              14
#define EGG_GROUP_NO_EGGS_DISCOVERED  15

#define EGG_GROUPS_PER_MON            2

// Pokémon natures
#define NATURE_HARDY    0
#define NATURE_LONELY   1
#define NATURE_BRAVE    2
#define NATURE_ADAMANT  3
#define NATURE_NAUGHTY  4
#define NATURE_BOLD     5
#define NATURE_DOCILE   6
#define NATURE_RELAXED  7
#define NATURE_IMPISH   8
#define NATURE_LAX      9
#define NATURE_TIMID    10
#define NATURE_HASTY    11
#define NATURE_SERIOUS  12
#define NATURE_JOLLY    13
#define NATURE_NAIVE    14
#define NATURE_MODEST   15
#define NATURE_MILD     16
#define NATURE_QUIET    17
#define NATURE_BASHFUL  18
#define NATURE_RASH     19
#define NATURE_CALM     20
#define NATURE_GENTLE   21
#define NATURE_SASSY    22
#define NATURE_CAREFUL  23
#define NATURE_QUIRKY   24
#define NUM_NATURES     25

// Pokémon Stats
#define STAT_HP      0
#define STAT_ATK     1
#define STAT_DEF     2
#define STAT_SPEED   3
#define STAT_SPATK   4
#define STAT_SPDEF   5
#define NUM_STATS    6

#define STAT_ACC     6 // Only in battles.
#define STAT_EVASION 7 // Only in battles.

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

#define OT_ID_PLAYER_ID       0
#define OT_ID_PRESET          1
#define OT_ID_RANDOM_NO_SHINY 2

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

#define MAX_LEVEL_UP_MOVES       20

#define MON_MALE       0x00
#define MON_FEMALE     0xFE
#define MON_GENDERLESS 0xFF

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
#define DAMAGE_CATEGORY_PHYSICAL    0
#define DAMAGE_CATEGORY_SPECIAL     1
#define DAMAGE_CATEGORY_STATUS      2

// Growth rates
#define GROWTH_MEDIUM_FAST  0
#define GROWTH_ERRATIC      1
#define GROWTH_FLUCTUATING  2
#define GROWTH_MEDIUM_SLOW  3
#define GROWTH_FAST         4
#define GROWTH_SLOW         5

// Body colors for Pokédex search
#define BODY_COLOR_RED      0
#define BODY_COLOR_BLUE     1
#define BODY_COLOR_YELLOW   2
#define BODY_COLOR_GREEN    3
#define BODY_COLOR_BLACK    4
#define BODY_COLOR_BROWN    5
#define BODY_COLOR_PURPLE   6
#define BODY_COLOR_GRAY     7
#define BODY_COLOR_WHITE    8
#define BODY_COLOR_PINK     9

#define F_SUMMARY_SCREEN_FLIP_SPRITE 0x80

// Evolution types
#define EVOLUTIONS_END                    0xFFFF // Not an actual evolution, used to mark the end of an evolution array.
#define EVO_NONE                          0xFFFE // Not an actual evolution, used to generate offspring that can't evolve into the specified species, like regional forms.
#define EVO_FRIENDSHIP                    1      // Pokémon levels up with friendship ≥ 220
#define EVO_FRIENDSHIP_DAY                2      // Pokémon levels up during the day with friendship ≥ 220
#define EVO_FRIENDSHIP_NIGHT              3      // Pokémon levels up at night with friendship ≥ 220
#define EVO_LEVEL                         4      // Pokémon reaches the specified level
#define EVO_TRADE                         5      // Pokémon is traded
#define EVO_TRADE_ITEM                    6      // Pokémon is traded while it's holding the specified item
#define EVO_ITEM                          7      // specified item is used on Pokémon
#define EVO_LEVEL_ATK_GT_DEF              8      // Pokémon reaches the specified level with attack > defense
#define EVO_LEVEL_ATK_EQ_DEF              9      // Pokémon reaches the specified level with attack = defense
#define EVO_LEVEL_ATK_LT_DEF              10     // Pokémon reaches the specified level with attack < defense
#define EVO_LEVEL_SILCOON                 11     // Pokémon reaches the specified level with a Silcoon personality value
#define EVO_LEVEL_CASCOON                 12     // Pokémon reaches the specified level with a Cascoon personality value
#define EVO_LEVEL_NINJASK                 13     // Pokémon reaches the specified level (special value for Ninjask)
#define EVO_LEVEL_SHEDINJA                14     // Pokémon reaches the specified level (special value for Shedinja)
#define EVO_BEAUTY                        15     // Pokémon levels up with beauty ≥ specified value
#define EVO_LEVEL_FEMALE                  16     // Pokémon reaches the specified level, is female
#define EVO_LEVEL_MALE                    17     // Pokémon reaches the specified level, is male
#define EVO_LEVEL_NIGHT                   18     // Pokémon reaches the specified level, is night
#define EVO_LEVEL_DAY                     19     // Pokémon reaches the specified level, is day
#define EVO_LEVEL_DUSK                    20     // Pokémon reaches the specified level, is dusk (5-6 P.M)
#define EVO_ITEM_HOLD_DAY                 21     // Pokémon levels up, holds specified item at day
#define EVO_ITEM_HOLD_NIGHT               22     // Pokémon levels up, holds specified item at night
#define EVO_MOVE                          23     // Pokémon levels up, knows specified move
#define EVO_FRIENDSHIP_MOVE_TYPE          24     // Pokémon levels up with friendship ≥ 220, knows move with specified type
#define EVO_MAPSEC                        25     // Pokémon levels up on specified mapsec
#define EVO_ITEM_MALE                     26     // specified item is used on a male Pokémon
#define EVO_ITEM_FEMALE                   27     // specified item is used on a female Pokémon
#define EVO_LEVEL_RAIN                    28     // Pokémon reaches the specified level during rain in the overworld
#define EVO_SPECIFIC_MON_IN_PARTY         29     // Pokémon levels up with a specified Pokémon in party
#define EVO_LEVEL_DARK_TYPE_MON_IN_PARTY  30     // Pokémon reaches the specified level with a Dark Type Pokémon in party
#define EVO_TRADE_SPECIFIC_MON            31     // Pokémon is traded for a specified Pokémon
#define EVO_SPECIFIC_MAP                  32     // Pokémon levels up on specified map
#define EVO_LEVEL_NATURE_AMPED            33     // Pokémon reaches the specified level, it has a Hardy, Brave, Adamant, Naughty, Docile, Impish, Lax, Hasty, Jolly, Naive, Rash, Sassy, or Quirky nature.
#define EVO_LEVEL_NATURE_LOW_KEY          34     // Pokémon reaches the specified level, it has a Lonely, Bold, Relaxed, Timid, Serious, Modest, Mild, Quiet, Bashful, Calm, Gentle, or Careful nature.
#define EVO_CRITICAL_HITS                 35     // Pokémon performs specified number of critical hits in one battle
#define EVO_SCRIPT_TRIGGER_DMG            36     // Pokémon has specified HP below max, then player interacts trigger
#define EVO_DARK_SCROLL                   37     // interacts with Scroll of Darkness
#define EVO_WATER_SCROLL                  38     // interacts with Scroll of Waters
#define EVO_ITEM_NIGHT                    39     // specified item is used on Pokémon, is night
#define EVO_ITEM_DAY                      40     // specified item is used on Pokémon, is day
#define EVO_ITEM_HOLD                     41     // Pokémon levels up, holds specified item
#define EVO_LEVEL_FOG                     42     // Pokémon reaches the specified level during fog in the overworld
#define EVO_MOVE_TWO_SEGMENT              43     // Pokémon levels up, knows specified move, has a personality value with a modulus of 0
#define EVO_MOVE_THREE_SEGMENT            44     // Pokémon levels up, knows specified move, has a personality value with a modulus of 1-99
#define EVO_LEVEL_FAMILY_OF_THREE         45     // Pokémon reaches the specified level with a personality value with a modulus of 0
#define EVO_LEVEL_FAMILY_OF_FOUR          46     // Pokémon reaches the specified level with a personality value with a modulus of 1-99
#define EVO_USE_MOVE_TWENTY_TIMES         47     // Pokémon levels up after having used a move for at least 20 times
#define EVO_RECOIL_DAMAGE_MALE            48     // Pokémon levels up after having suffered specified amount of non-fainting recoil damage as a male
#define EVO_RECOIL_DAMAGE_FEMALE          49     // Pokémon levels up after having suffered specified amount of non-fainting recoil damage as a female
#define EVO_ITEM_COUNT_999                50     // Pokémon levels up after trainer has collected 999 of a specific item
#define EVO_DEFEAT_WITH_ITEM              51     // Pokémon levels up after having defeat 3 Pokémon of the same species holding the specified item

// Evolution 'modes,' for GetEvolutionTargetSpecies
#define EVO_MODE_NORMAL            0
#define EVO_MODE_CANT_STOP         1
#define EVO_MODE_TRADE             2
#define EVO_MODE_ITEM_USE          3
#define EVO_MODE_ITEM_CHECK        4 // If an Everstone is being held, still want to show that the stone *could* be used on that Pokémon to evolve
#define EVO_MODE_BATTLE_SPECIAL    5
#define EVO_MODE_OVERWORLD_SPECIAL 6

#define MON_PIC_WIDTH 64
#define MON_PIC_HEIGHT 64
#define MON_PIC_SIZE (MON_PIC_WIDTH * MON_PIC_HEIGHT / 2)

// Most Pokémon have 2 frames (a default and an alternate for their animation).
// There are 4 exceptions:
// - Deoxys has 2 frames, 1 for each form
// - Spinda has 1 frame, presumably to avoid the work of animating its spots
// - Unown has 1 frame, presumably to avoid the work of animating all 28 of its forms
#define MAX_MON_PIC_FRAMES 2

#define BATTLE_ALIVE_EXCEPT_BATTLER  0
#define BATTLE_ALIVE_SIDE            1

#define SKIP_FRONT_ANIM (1 << 7)

#define NUM_ABILITY_SLOTS (NUM_NORMAL_ABILITY_SLOTS + NUM_HIDDEN_ABILITY_SLOTS)
#define NUM_NORMAL_ABILITY_SLOTS 2
#define NUM_HIDDEN_ABILITY_SLOTS 1

// Used as a signal for givemon to generate a default ability by personality.
#define NUM_ABILITY_PERSONALITY 0xFF

#define LEGENDARY_PERFECT_IV_COUNT 3

#endif // GUARD_CONSTANTS_POKEMON_H
