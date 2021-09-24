#ifndef GUARD_CONSTANTS_BATTLE_DOME_H
#define GUARD_CONSTANTS_BATTLE_DOME_H

#define DOME_ROUND1        0
#define DOME_ROUND2        1
#define DOME_SEMIFINAL     2
#define DOME_FINAL         3
#define DOME_ROUNDS_COUNT  4

//#define DOME_TOURNAMENT_TRAINERS_COUNT 16 -- defined in global
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
#define BATTLE_DOME_FUNC_SHOW_PREV_TOURNEY_TREE     8
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
#define DOME_DATA_PREV_TOURNEY_TYPE       9

// ID for Exit/Cancel on the tourney tree
#define TOURNEY_TREE_CLOSE_BUTTON  31

// Input IDs on the tourney tree
#define TOURNEY_TREE_SELECTED_CLOSE   0
#define TOURNEY_TREE_NO_SELECTION     1
#define TOURNEY_TREE_SELECTED_TRAINER 2
#define TOURNEY_TREE_SELECTED_MATCH   3

// Modes for showing the tourney tree info card
#define INFOCARD_NEXT_OPPONENT  0
#define INFOCARD_TRAINER        1
#define INFOCARD_MATCH          2

// Input IDs for the info cards
#define INFOCARD_INPUT_NONE      0
#define TRAINERCARD_INPUT_UP     1
#define TRAINERCARD_INPUT_DOWN   2
#define TRAINERCARD_INPUT_LEFT   3
#define TRAINERCARD_INPUT_RIGHT  4
#define MATCHCARD_INPUT_UP       5
#define MATCHCARD_INPUT_DOWN     6
#define MATCHCARD_INPUT_LEFT     7
#define MATCHCARD_INPUT_RIGHT    8
#define INFOCARD_INPUT_AB        9

#define CARD_ALTERNATE_SLOT (1 << 0) // When set, uses an alternate slot to store the incoming card sprites
#define MOVE_CARD_RIGHT     (1 << 1)
#define MOVE_CARD_DOWN      (1 << 2)
#define MOVE_CARD_LEFT      (1 << 3)
#define MOVE_CARD_UP        (1 << 4)
#define MOVE_CARD           (MOVE_CARD_RIGHT | MOVE_CARD_DOWN | MOVE_CARD_LEFT | MOVE_CARD_UP)

// Text IDs for sBattleDomeWinTexts
#define DOME_TEXT_NO_WINNER_YET     0
#define DOME_TEXT_WON_USING_MOVE    1
#define DOME_TEXT_CHAMP_USING_MOVE  2
#define DOME_TEXT_WON_ON_FORFEIT    3
#define DOME_TEXT_CHAMP_ON_FORFEIT  4
#define DOME_TEXT_WON_NO_MOVES      5
#define DOME_TEXT_CHAMP_NO_MOVES    6

// Offsets/start positions within sBattleDomeOpponentStatsTexts
#define DOME_TEXT_TWO_GOOD_STATS   0
#define DOME_TEXT_ONE_GOOD_STAT    15
#define DOME_TEXT_TWO_BAD_STATS    21
#define DOME_TEXT_ONE_BAD_STAT     36
#define DOME_TEXT_WELL_BALANCED    42
#define DOME_TEXT_HP    0
#define DOME_TEXT_ATK   5
#define DOME_TEXT_DEF   9
#define DOME_TEXT_SPEED 12
#define DOME_TEXT_SPATK 14

// Move point indexes for sBattleStyleMovePoints[][], to determine Battle Dome trainers battle styles
#define MOVE_POINTS_COMBO      0   // Moves that work well in combination (e.g. Rain Dance + Hydro Pump)
#define MOVE_POINTS_STAT_RAISE 1
#define MOVE_POINTS_STAT_LOWER 2
#define MOVE_POINTS_RARE       3   // Uncommon moves. Mostly arbitrary
#define MOVE_POINTS_HEAL       4
#define MOVE_POINTS_RISKY      5
#define MOVE_POINTS_STATUS     6
#define MOVE_POINTS_DMG        7
#define MOVE_POINTS_DEF        8   // Defensive moves, like Amnesia, Light Screen, or accuracy-lowers
#define MOVE_POINTS_ACCURATE   9
#define MOVE_POINTS_POWERFUL   10  // Most of the moves that are >= 100 power
#define MOVE_POINTS_POPULAR    11  // Group seems arbitrary. All using it are TM/HMs, but its only 11/58
#define MOVE_POINTS_LUCK       12
#define MOVE_POINTS_STRONG     13  // Most of the moves that are >= 90 power
#define MOVE_POINTS_LOW_PP     14
#define MOVE_POINTS_EFFECT     15  // Moves with additional effects
#define NUM_MOVE_POINT_TYPES   16

// Battle style IDs for sBattleDomeOpponentStyleTexts
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
#define DOME_BATTLE_STYLE_REGAL           10
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
