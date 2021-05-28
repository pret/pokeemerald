#ifndef GUARD_CONSTANTS_BATTLE_ANIM_H
#define GUARD_CONSTANTS_BATTLE_ANIM_H

// battlers
#define ANIM_ATTACKER    0
#define ANIM_TARGET      1
#define ANIM_ATK_PARTNER 2
#define ANIM_DEF_PARTNER 3

// stereo panning constants [0-255]
//
//          0
//         .  .
//      .        .
// 192 .          . 63
//     .          .
//      .        .
//         .  .
//          127
//
#define SOUND_PAN_ATTACKER -64
#define SOUND_PAN_TARGET    63

// move background ids
#define BG_DARK_ 0 // the same as BG_DARK but is unused
#define BG_DARK 1
#define BG_GHOST 2
#define BG_PSYCHIC 3
#define BG_IMPACT_OPPONENT 4
#define BG_IMPACT_PLAYER 5
#define BG_IMPACT_CONTESTS 6
#define BG_DRILL 7
#define BG_DRILL_CONTESTS 8
#define BG_HIGHSPEED_OPPONENT 9
#define BG_HIGHSPEED_PLAYER 10
#define BG_THUNDER 11
#define BG_GUILLOTINE_OPPONENT 12
#define BG_GUILLOTINE_PLAYER 13
#define BG_GUILLOTINE_CONTESTS 14
#define BG_ICE 15
#define BG_COSMIC 16
#define BG_IN_AIR 17
#define BG_SKY 18
#define BG_SKY_CONTESTS 19
#define BG_AURORA 20
#define BG_FISSURE 21
#define BG_BUG_OPPONENT 22
#define BG_BUG_PLAYER 23
#define BG_SOLARBEAM_OPPONENT 24
#define BG_SOLARBEAM_PLAYER 25
#define BG_SOLARBEAM_CONTESTS 26

// table ids for general animations (gBattleAnims_General)
#define B_ANIM_CASTFORM_CHANGE          0
#define B_ANIM_STATS_CHANGE             1
#define B_ANIM_SUBSTITUTE_FADE          2
#define B_ANIM_SUBSTITUTE_APPEAR        3
#define B_ANIM_POKEBLOCK_THROW          4
#define B_ANIM_ITEM_KNOCKOFF            5
#define B_ANIM_TURN_TRAP                6
#define B_ANIM_HELD_ITEM_EFFECT         7
#define B_ANIM_SMOKEBALL_ESCAPE         8
#define B_ANIM_FOCUS_BAND               9
#define B_ANIM_RAIN_CONTINUES           10
#define B_ANIM_SUN_CONTINUES            11
#define B_ANIM_SANDSTORM_CONTINUES      12
#define B_ANIM_HAIL_CONTINUES           13
#define B_ANIM_LEECH_SEED_DRAIN         14
#define B_ANIM_MON_HIT                  15
#define B_ANIM_ITEM_STEAL               16
#define B_ANIM_SNATCH_MOVE              17
#define B_ANIM_FUTURE_SIGHT_HIT         18
#define B_ANIM_DOOM_DESIRE_HIT          19
#define B_ANIM_FOCUS_PUNCH_SETUP        20
#define B_ANIM_INGRAIN_HEAL             21
#define B_ANIM_WISH_HEAL                22

// special animations table (gBattleAnims_Special)
#define B_ANIM_LVL_UP                   0
#define B_ANIM_SWITCH_OUT_PLAYER_MON    1
#define B_ANIM_SWITCH_OUT_OPPONENT_MON  2
#define B_ANIM_BALL_THROW               3
#define B_ANIM_BALL_THROW_WITH_TRAINER  4
#define B_ANIM_SUBSTITUTE_TO_MON        5
#define B_ANIM_MON_TO_SUBSTITUTE        6

// status animation table (gBattleAnims_StatusConditions)
#define B_ANIM_STATUS_PSN               0
#define B_ANIM_STATUS_CONFUSION         1
#define B_ANIM_STATUS_BRN               2
#define B_ANIM_STATUS_INFATUATION       3
#define B_ANIM_STATUS_SLP               4
#define B_ANIM_STATUS_PRZ               5
#define B_ANIM_STATUS_FRZ               6
#define B_ANIM_STATUS_CURSED            7
#define B_ANIM_STATUS_NIGHTMARE         8
#define B_ANIM_STATUS_WRAPPED           9 // does not actually exist

// Tasks with return values often assign them to gBattleAnimArgs[7].
#define ARG_RET_ID 7

// Trapping Wrap-like moves end turn animation.
#define TRAP_ANIM_BIND 0
#define TRAP_ANIM_WRAP 0
#define TRAP_ANIM_FIRE_SPIN 1
#define TRAP_ANIM_WHIRLPOOL 2
#define TRAP_ANIM_CLAMP 3
#define TRAP_ANIM_SAND_TOMB 4

// Weather defines for battle animation scripts.
#define ANIM_WEATHER_NONE 0
#define ANIM_WEATHER_SUN 1
#define ANIM_WEATHER_RAIN 2
#define ANIM_WEATHER_SANDSTORM 3
#define ANIM_WEATHER_HAIL 4

#endif // GUARD_CONSTANTS_BATTLE_ANIM_H
