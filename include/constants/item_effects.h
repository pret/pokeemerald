#ifndef GUARD_CONSTANTS_ITEM_EFFECTS_H
#define GUARD_CONSTANTS_ITEM_EFFECTS_H

// field 0 masks
#define ITEM0_DIRE_HIT          0x30 // Works the same way as the move Focus Energy.
#define ITEM0_SACRED_ASH        0x40
#define ITEM0_INFATUATION       0x80

// new field 1 masks
#define ITEM1_X_ATTACK          STAT_ATK
#define ITEM1_X_DEFENSE         STAT_DEF
#define ITEM1_X_SPEED           STAT_SPEED
#define ITEM1_X_SPATK           STAT_SPATK
#define ITEM1_X_SPDEF           STAT_SPDEF
#define ITEM1_X_ACCURACY        STAT_ACC

// field 3 masks
#define ITEM3_CONFUSION         0x1
#define ITEM3_PARALYSIS         0x2
#define ITEM3_FREEZE            0x4
#define ITEM3_BURN              0x8
#define ITEM3_POISON            0x10
#define ITEM3_SLEEP             0x20
#define ITEM3_LEVEL_UP          0x40
#define ITEM3_GUARD_SPEC        0x80 // Works the same way as the move Mist.

#define ITEM3_STATUS_ALL        (ITEM3_CONFUSION | ITEM3_PARALYSIS | ITEM3_FREEZE | ITEM3_BURN | ITEM3_POISON | ITEM3_SLEEP)

// field 4 masks
#define ITEM4_EV_HP             0x1
#define ITEM4_EV_ATK            0x2
#define ITEM4_HEAL_HP           0x4
#define ITEM4_HEAL_PP           0x8
#define ITEM4_HEAL_PP_ONE       0x10
#define ITEM4_PP_UP             0x20
#define ITEM4_REVIVE            0x40
#define ITEM4_EVO_STONE         0x80

// field 5 masks
#define ITEM5_EV_DEF            0x1
#define ITEM5_EV_SPEED          0x2
#define ITEM5_EV_SPDEF          0x4
#define ITEM5_EV_SPATK          0x8
#define ITEM5_PP_MAX            0x10
#define ITEM5_FRIENDSHIP_LOW    0x20
#define ITEM5_FRIENDSHIP_MID    0x40
#define ITEM5_FRIENDSHIP_HIGH   0x80

#define ITEM5_FRIENDSHIP_ALL    (ITEM5_FRIENDSHIP_LOW | ITEM5_FRIENDSHIP_MID | ITEM5_FRIENDSHIP_HIGH)

#define ITEM10_IS_VITAMIN       0x1

// fields 6 and onwards (except field 10) are item-specific arguments
#define ITEM_EFFECT_ARG_START 6

// Special HP recovery amounts for ITEM4_HEAL_HP
#define ITEM6_HEAL_HP_FULL    ((u8) -1)
#define ITEM6_HEAL_HP_HALF    ((u8) -2)
#define ITEM6_HEAL_HP_LVL_UP  ((u8) -3)
#define ITEM6_HEAL_HP_QUARTER ((u8) -4)

// Special PP recovery amounts for ITEM4_HEAL_PP
#define ITEM6_HEAL_PP_FULL   0x7F

// Amount of EV modified by ITEM4_EV_HP, ITEM4_EV_ATK, ITEM5_EV_DEF, ITEM5_EV_SPEED, ITEM5_EV_SPDEF and ITEM5_EV_SPATK
#define ITEM6_ADD_EV       10
#define ITEM6_SUBTRACT_EV -10
#define ITEM6_ADD_ONE_EV    1
#define ITEM6_RESET_EV      0

// Used for GetItemEffectType.
enum ItemEffectType
{
    ITEM_EFFECT_X_ITEM,
    ITEM_EFFECT_RAISE_LEVEL,
    ITEM_EFFECT_HEAL_HP,
    ITEM_EFFECT_CURE_POISON,
    ITEM_EFFECT_CURE_SLEEP,
    ITEM_EFFECT_CURE_BURN,
    ITEM_EFFECT_CURE_FREEZE_FROSTBITE,
    ITEM_EFFECT_CURE_PARALYSIS,
    ITEM_EFFECT_CURE_CONFUSION,
    ITEM_EFFECT_CURE_INFATUATION,
    ITEM_EFFECT_SACRED_ASH,
    ITEM_EFFECT_CURE_ALL_STATUS,
    ITEM_EFFECT_ATK_EV,
    ITEM_EFFECT_HP_EV,
    ITEM_EFFECT_SPATK_EV,
    ITEM_EFFECT_SPDEF_EV,
    ITEM_EFFECT_SPEED_EV,
    ITEM_EFFECT_DEF_EV,
    ITEM_EFFECT_EVO_STONE,
    ITEM_EFFECT_PP_UP,
    ITEM_EFFECT_PP_MAX,
    ITEM_EFFECT_HEAL_PP,
    ITEM_EFFECT_NONE
};

#define ITEM_FRIENDSHIP_MAPSEC_BONUS  1   // The amount of bonus friendship gained when an item is used on a Pokémon whose met location matches the current map section.
#define ITEM_FRIENDSHIP_LUXURY_BONUS  1   // The amount of bonus friendship gained when a Pokémon is in the Luxury Ball.

// Since X item stat increases are now handled by battle scripts, the friendship increase effect is now handled by the battle controller in HandleAction_UseItem.
#define X_ITEM_FRIENDSHIP_INCREASE    1   // The amount of friendship gained by using an X item on a Pokémon in battle.
#define X_ITEM_MAX_FRIENDSHIP         200 // Friendship threshold at which Pokémon stop receiving a friendship increase from using X items on them in battle.

#endif // GUARD_CONSTANTS_ITEM_EFFECTS_H
