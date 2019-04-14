#ifndef GUARD_CONSTANTS_POKEMON_H
#define GUARD_CONSTANTS_POKEMON_H

// Pokemon types
#define TYPE_NONE     0xFF
#define TYPE_NORMAL   0x00
#define TYPE_FIGHTING 0x01
#define TYPE_FLYING   0x02
#define TYPE_POISON   0x03
#define TYPE_GROUND   0x04
#define TYPE_ROCK     0x05
#define TYPE_BUG      0x06
#define TYPE_GHOST    0x07
#define TYPE_STEEL    0x08
#define TYPE_MYSTERY  0x09
#define TYPE_FIRE     0x0a
#define TYPE_WATER    0x0b
#define TYPE_GRASS    0x0c
#define TYPE_ELECTRIC 0x0d
#define TYPE_PSYCHIC  0x0e
#define TYPE_ICE      0x0f
#define TYPE_DRAGON   0x10
#define TYPE_DARK     0x11
#define TYPE_FAIRY    0x12
#define NUMBER_OF_MON_TYPES     0x13


// Pokemon egg groups
#define EGG_GROUP_NONE 0
#define EGG_GROUP_MONSTER 1
#define EGG_GROUP_WATER_1 2
#define EGG_GROUP_BUG 3
#define EGG_GROUP_FLYING 4
#define EGG_GROUP_FIELD 5
#define EGG_GROUP_FAIRY 6
#define EGG_GROUP_GRASS 7
#define EGG_GROUP_HUMAN_LIKE 8
#define EGG_GROUP_WATER_3 9
#define EGG_GROUP_MINERAL 10
#define EGG_GROUP_AMORPHOUS 11
#define EGG_GROUP_WATER_2 12
#define EGG_GROUP_DITTO 13
#define EGG_GROUP_DRAGON 14
#define EGG_GROUP_UNDISCOVERED 15

// Pokemon natures
#define NATURE_HARDY 0
#define NATURE_LONELY 1
#define NATURE_BRAVE 2
#define NATURE_ADAMANT 3
#define NATURE_NAUGHTY 4
#define NATURE_BOLD 5
#define NATURE_DOCILE 6
#define NATURE_RELAXED 7
#define NATURE_IMPISH 8
#define NATURE_LAX 9
#define NATURE_TIMID 10
#define NATURE_HASTY 11
#define NATURE_SERIOUS 12
#define NATURE_JOLLY 13
#define NATURE_NAIVE 14
#define NATURE_MODEST 15
#define NATURE_MILD 16
#define NATURE_QUIET 17
#define NATURE_BASHFUL 18
#define NATURE_RASH 19
#define NATURE_CALM 20
#define NATURE_GENTLE 21
#define NATURE_SASSY 22
#define NATURE_CAREFUL 23
#define NATURE_QUIRKY 24

// Pokemon Stats
#define STAT_HP 0
#define STAT_ATK 1
#define STAT_DEF 2
#define STAT_SPEED 3
#define STAT_SPATK 4
#define STAT_SPDEF 5
#define STAT_ACC 6 // Only in battles.
#define STAT_EVASION 7 // Only in battles.

#define NUM_STATS 6
#define NUM_BATTLE_STATS 8

// Move flags.
#define FLAG_MAKES_CONTACT          0x1
#define FLAG_PROTECT_AFFECTED       0x2
#define FLAG_MAGICCOAT_AFFECTED     0x4
#define FLAG_SNATCH_AFFECTED        0x8
#define FLAG_MIRROR_MOVE_AFFECTED   0x10
#define FLAG_KINGSROCK_AFFECTED     0x20
#define FLAG_HIGH_CRIT              0x40
#define FLAG_RECKLESS_BOOST         0x80
#define FLAG_IRON_FIST_BOOST        0x100
#define FLAG_SHEER_FORCE_BOOST      0x200
#define FLAG_STRONG_JAW_BOOST       0x400
#define FLAG_MEGA_LAUNCHER_BOOST    0x800
#define FLAG_STAT_STAGES_IGNORED    0x1000
#define FLAG_DMG_MINIMIZE           0x2000
#define FLAG_DMG_UNDERGROUND        0x4000
#define FLAG_DMG_UNDERWATER         0x8000
#define FLAG_SOUND                  0x10000
#define FLAG_BALLISTIC              0x20000
#define FLAG_PROTECTION_MOVE        0x40000
#define FLAG_POWDER                 0x80000
#define FLAG_TARGET_ABILITY_IGNORED 0x100000
#define FLAG_DANCE                  0x200000

// Split defines.
#define SPLIT_PHYSICAL  0x0
#define SPLIT_SPECIAL   0x1
#define SPLIT_STATUS    0x2

#endif // GUARD_CONSTANTS_POKEMON_H
