#ifndef GUARD_CONSTANTS_BATTLE_ANIM_H
#define GUARD_CONSTANTS_BATTLE_ANIM_H

// battlers
#define ANIM_ATTACKER 0
#define ANIM_TARGET 1
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
#define BG_SEISMICTOSS_SKUUPPERCUT 17
#define BG_FLYING 18
#define BG_FLYING_CONTESTS 19
#define BG_AURORABEAM 20
#define BG_FISSURE 21
#define BG_BUG_OPPONENT 22
#define BG_BUG_PLAYER 23
#define BG_SOLARBEAM_OPPONENT 24
#define BG_SOLARBEAM_PLAYER 25
#define BG_SOLARBEAM_CONTESTS 26

// table ids for general animations
#define B_ANIM_CASTFORM_CHANGE          0x0
#define B_ANIM_STATS_CHANGE             0x1
#define B_ANIM_SUBSTITUTE_FADE          0x2
#define B_ANIM_SUBSTITUTE_APPEAR        0x3
#define B_ANIM_x4                       0x4
#define B_ANIM_ITEM_KNOCKOFF            0x5
#define B_ANIM_TURN_TRAP                0x6
#define B_ANIM_ITEM_EFFECT              0x7
#define B_ANIM_SMOKEBALL_ESCAPE         0x8
#define B_ANIM_HANGED_ON                0x9
#define B_ANIM_RAIN_CONTINUES           0xA
#define B_ANIM_SUN_CONTINUES            0xB
#define B_ANIM_SANDSTORM_CONTINUES      0xC
#define B_ANIM_HAIL_CONTINUES           0xD
#define B_ANIM_LEECH_SEED_DRAIN         0xE
#define B_ANIM_MON_HIT                  0xF
#define B_ANIM_ITEM_STEAL               0x10
#define B_ANIM_SNATCH_MOVE              0x11
#define B_ANIM_FUTURE_SIGHT_HIT         0x12
#define B_ANIM_DOOM_DESIRE_HIT          0x13
#define B_ANIM_x14                      0x14
#define B_ANIM_INGRAIN_HEAL             0x15
#define B_ANIM_WISH_HEAL                0x16

// special animations table
#define B_ANIM_LVL_UP                   0x0
#define B_ANIM_SWITCH_OUT_PLAYER_MON    0x1
#define B_ANIM_SWITCH_OUT_OPPONENT_MON  0x2
#define B_ANIM_BALL_THROW               0x3
#define B_ANIM_SAFARI_BALL_THROW        0x4
#define B_ANIM_SUBSTITUTE_TO_MON        0x5
#define B_ANIM_MON_TO_SUBSTITUTE        0x6

// status animation table
#define B_ANIM_STATUS_PSN               0x0
#define B_ANIM_STATUS_CONFUSION         0x1
#define B_ANIM_STATUS_BRN               0x2
#define B_ANIM_STATUS_INFATUATION       0x3
#define B_ANIM_STATUS_SLP               0x4
#define B_ANIM_STATUS_PRZ               0x5
#define B_ANIM_STATUS_FRZ               0x6
#define B_ANIM_STATUS_CURSED            0x7
#define B_ANIM_STATUS_NIGHTMARE         0x8
#define B_ANIM_STATUS_WRAPPED           0x9 // does not actually exist

#endif // GUARD_CONSTANTS_BATTLE_ANIM_H
