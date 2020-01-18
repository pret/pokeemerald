#ifndef GUARD_CONSTANTS_ITEM_EFFECTS_H
#define GUARD_CONSTANTS_ITEM_EFFECTS_H

// field 0 masks
#define ITEM0_X_ATTACK          0x0F
#define ITEM0_DIRE_HIT          0x30 // Works the same way as the move Focus Energy.
#define ITEM0_SACRED_ASH        0x40
#define ITEM0_INFATUATION       0x80

// field 1 masks
#define ITEM1_X_SPEED           0x0F
#define ITEM1_X_DEFEND          0xF0

// field 2 masks
#define ITEM2_X_SPATK           0x0F
#define ITEM2_X_ACCURACY        0xF0

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
#define ITEM4_HEAL_PP_ALL       0x8
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

// fields 6 - 9 are item-specific arguments

#define ITEM10_IS_VITAMIN       0x1

// Used for GetItemEffectType.
#define ITEM_EFFECT_X_ITEM 0
#define ITEM_EFFECT_RAISE_LEVEL 1
#define ITEM_EFFECT_HEAL_HP 2
#define ITEM_EFFECT_CURE_POISON 3
#define ITEM_EFFECT_CURE_SLEEP 4
#define ITEM_EFFECT_CURE_BURN 5
#define ITEM_EFFECT_CURE_FREEZE 6
#define ITEM_EFFECT_CURE_PARALYSIS 7
#define ITEM_EFFECT_CURE_CONFUSION 8
#define ITEM_EFFECT_CURE_INFATUATION 9
#define ITEM_EFFECT_SACRED_ASH 10
#define ITEM_EFFECT_CURE_ALL_STATUS 11
#define ITEM_EFFECT_ATK_EV 12
#define ITEM_EFFECT_HP_EV 13
#define ITEM_EFFECT_SPATK_EV 14
#define ITEM_EFFECT_SPDEF_EV 15
#define ITEM_EFFECT_SPEED_EV 16
#define ITEM_EFFECT_DEF_EV 17
#define ITEM_EFFECT_EVO_STONE 18
#define ITEM_EFFECT_PP_UP 19
#define ITEM_EFFECT_PP_MAX 20
#define ITEM_EFFECT_HEAL_PP 21
#define ITEM_EFFECT_NONE 22

#endif // GUARD_CONSTANTS_ITEM_EFFECTS_H
