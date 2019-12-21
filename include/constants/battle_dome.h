#ifndef GUARD_CONSTANTS_BATTLE_DOME_H
#define GUARD_CONSTANTS_BATTLE_DOME_H

#define DOME_ROUND1        0
#define DOME_ROUND2        1
#define DOME_SEMIFINAL     2
#define DOME_FINAL         3
#define DOME_ROUNDS_COUNT  4

//#define DOME_TOURNAMENT_TRAINERS_COUNT 16 : defined in global
#define DOME_TOURNAMENT_MATCHES_COUNT  DOME_TOURNAMENT_TRAINERS_COUNT - 1

#define DOME_BATTLE_PARTY_SIZE  2

#define DOME_PLAYER_WON_MATCH  1
#define DOME_PLAYER_LOST_MATCH 2
#define DOME_PLAYER_RETIRED    9

#define BATTLE_DOME_FUNC_INIT                       0
#define BATTLE_DOME_FUNC_GET_DATA                   1
#define BATTLE_DOME_FUNC_SET_DATA                   2
#define BATTLE_DOME_FUNC_GET_ROUND_TEXT             3
#define BATTLE_DOME_FUNC_GET_OPPONENT_NAME          4
#define BATTLE_DOME_FUNC_INIT_OPPONENT_PARTY        5
#define BATTLE_DOME_FUNC_SHOW_OPPONENT_INFO         6
#define BATTLE_DOME_FUNC_SHOW_TOURNEY_TREE          7
#define BATTLE_DOME_FUNC_SHOW_PREV_RESULTS_TREE     8
#define BATTLE_DOME_FUNC_SET_OPPONENT_ID            9
#define BATTLE_DOME_FUNC_SET_OPPONENT_GFX           10
#define BATTLE_DOME_FUNC_SHOW_STATIC_TOURNEY_TREE   11
#define BATTLE_DOME_FUNC_RESOLVE_WINNERS            12
#define BATTLE_DOME_FUNC_SAVE                       13
#define BATTLE_DOME_FUNC_INCREMENT_STREAK           14
#define BATTLE_DOME_FUNC_SET_TRAINERS               15
#define BATTLE_DOME_FUNC_RESET_SKETCH               16
#define BATTLE_DOME_FUNC_RESTORE_HELD_ITEMS         17
#define BATTLE_DOME_FUNC_REDUCE_PARTY               18
#define BATTLE_DOME_FUNC_COMPARE_SEEDS              19
#define BATTLE_DOME_FUNC_GET_WINNER_NAME            20
#define BATTLE_DOME_FUNC_INIT_RESULTS_TREE          21
#define BATTLE_DOME_FUNC_INIT_TRAINERS              22

#define DOME_DATA_WIN_STREAK              0
#define DOME_DATA_WIN_STREAK_ACTIVE       1
#define DOME_DATA_ATTEMPTED_SINGLES_50    2
#define DOME_DATA_ATTEMPTED_SINGLES_OPEN  3
#define DOME_DATA_HAS_WON_SINGLES_50      4
#define DOME_DATA_HAS_WON_SINGLES_OPEN    5
#define DOME_DATA_ATTEMPTED_CHALLENGE     6
#define DOME_DATA_HAS_WON_CHALLENGE       7
#define DOME_DATA_SELECTED_MONS           8
#define DOME_DATA_LAST_TOURNEY_TYPE       9

//TODO: 
#define DOME_WINTEXT_NO_WINNER_YET  0
#define DOME_WINTEXT_USED_MOVE      1
#define DOME_WINTEXT_CHAMP          2
#define DOME_WINTEXT_FORFEIT        3

#define DOME_STATTEXT_GOOD_DOUBLE_STAT   0
#define DOME_STATTEXT_GOOD_SINGLE_STAT  15
#define DOME_STATTEXT_WELL_BALANCED     42

// Move quality indexes, to determine Battle Dome trainers battle styles
#define MOVE_QUALITY_COMBO      0   // Moves that work well in combination (e.g. Rain Dance + Hydro Pump)
#define MOVE_QUALITY_STAT_RAISE 1
#define MOVE_QUALITY_STAT_LOWER 2
#define MOVE_QUALITY_RARE       3   // Uncommon moves. Mostly arbitrary
#define MOVE_QUALITY_HEAL       4
#define MOVE_QUALITY_RISKY      5
#define MOVE_QUALITY_STATUS     6
#define MOVE_QUALITY_DMG        7
#define MOVE_QUALITY_DEF        8   // Defensive moves, like Amnesia, Light Screen, or accuracy-lowers
#define MOVE_QUALITY_ACCURATE   9
#define MOVE_QUALITY_POWERFUL   10  // Most of the moves that are >= 100 power
#define MOVE_QUALITY_POPULAR    11  // Group seems arbitrary. All using it are TM/HMs, but its only 11/58
#define MOVE_QUALITY_LUCK       12  
#define MOVE_QUALITY_STRONG     13  // Most of the moves that are >= 90 power
#define MOVE_QUALITY_LOW_PP     14
#define MOVE_QUALITY_EFFECT     15  // Moves with additional effects
#define NUM_MOVE_QUALITIES      16

#define DOME_BATTLE_STYLE_RISKY           0
#define DOME_BATTLE_STYLE_STALL           1
#define DOME_BATTLE_STYLE_VARIED          2
#define DOME_BATTLE_STYLE_COMBO_HIGH      3
#define DOME_BATTLE_STYLE_RARE_MOVES      4
#define DOME_BATTLE_STYLE_RARE_MOVE       5
#define DOME_BATTLE_STYLE_HP              6
#define DOME_BATTLE_STYLE_STORE_POWER     7
#define DOME_BATTLE_STYLE_ENFEEBLE_LOW    8
#define DOME_BATTLE_STYLE_LUCK            9
#define DOME_BATTLE_STYLE_10              10
#define DOME_BATTLE_STYLE_LOW_PP          11
#define DOME_BATTLE_STYLE_STATUS_ATK      12
#define DOME_BATTLE_STYLE_ENDURE          13
#define DOME_BATTLE_STYLE_STATUS          14
#define DOME_BATTLE_STYLE_STRAIGHTFORWARD 15
#define DOME_BATTLE_STYLE_AGGRESSIVE      16
#define DOME_BATTLE_STYLE_DEF             17
#define DOME_BATTLE_STYLE_ENFEEBLE_HIGH   18
#define DOME_BATTLE_STYLE_POPULAR_POWER   19
#define DOME_BATTLE_STYLE_COMBO_LOW       20
#define DOME_BATTLE_STYLE_ACCURATE        21
#define DOME_BATTLE_STYLE_POWERFUL        22
#define DOME_BATTLE_STYLE_ATK_OVER_DEF    23
#define DOME_BATTLE_STYLE_DEF_OVER_ATK    24
#define DOME_BATTLE_STYLE_POPULAR_STRONG  25
#define DOME_BATTLE_STYLE_EFFECTS         26
#define DOME_BATTLE_STYLE_BALANCED        27
#define DOME_BATTLE_STYLE_UNUSED1         28
#define DOME_BATTLE_STYLE_UNUSED2         29
#define DOME_BATTLE_STYLE_UNUSED3         30
#define DOME_BATTLE_STYLE_UNUSED4         31
#define NUM_BATTLE_STYLES                 32


#endif //GUARD_CONSTANTS_BATTLE_DOME_H
