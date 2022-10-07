#ifndef GUARD_CONSTANTS_TRADE_H
#define GUARD_CONSTANTS_TRADE_H

#define TRADE_PLAYER  0
#define TRADE_PARTNER 1

#define LINK_TRADE_TIMEOUT 300

// In-game Trade IDs
#define INGAME_TRADE_SEEDOT 0
#define INGAME_TRADE_PLUSLE 1
#define INGAME_TRADE_HORSEA 2
#define INGAME_TRADE_MEOWTH 3

// Flag IDs for sending link data
#define INITIATE_TRADE  1
#define CANCEL_TRADE    2
#define WANTS_TO_TRADE   1
#define WANTS_TO_CANCEL  2
#define READY_FINISH_TRADE  1
#define FINISH_TRADE        2

// Return values for CanTradeSelectedMon and CanSpinTradeMon
#define CAN_TRADE_MON           0
#define CANT_TRADE_LAST_MON     1
#define CANT_TRADE_NATIONAL     2
#define CANT_TRADE_EGG_YET      3
#define CANT_TRADE_INVALID_MON  4
#define CANT_TRADE_EGG_YET2     5

// Return values for CheckValidityOfTradeMons
#define PLAYER_MON_INVALID   0
#define BOTH_MONS_VALID      1
#define PARTNER_MON_INVALID  2

// Return values for GetGameProgressForLinkTrade
#define TRADE_BOTH_PLAYERS_READY      0
#define TRADE_PLAYER_NOT_READY        1
#define TRADE_PARTNER_NOT_READY       2

// Indexes for sTradeActionTexts
#define TRADE_TEXT_CANCEL        0
#define TRADE_TEXT_CHOOSE_MON    1
#define TRADE_TEXT_SUMMARY       2
#define TRADE_TEXT_TRADE         3
#define TRADE_TEXT_CANCEL_TRADE  4
#define TRADE_TEXT_JP_QUIT       5

// Checked to confirm DrawTradeMenuParty has reached final state
#define DRAW_PARTY_FINISH 5

// Message indexes for sTradeMessages
#define TRADE_MSG_STANDBY                     0
#define TRADE_MSG_CANCELED                    1
#define TRADE_MSG_ONLY_MON1                   2
#define TRADE_MSG_ONLY_MON2                   3
#define TRADE_MSG_WAITING_FOR_FRIEND          4
#define TRADE_MSG_FRIEND_WANTS_TO_TRADE       5
#define TRADE_MSG_MON_CANT_BE_TRADED          6
#define TRADE_MSG_EGG_CANT_BE_TRADED          7
#define TRADE_MSG_FRIENDS_MON_CANT_BE_TRADED  8

// IDs for QueueAction
#define QUEUE_SEND_DATA                   0
#define QUEUE_STANDBY                     1
#define QUEUE_ONLY_MON1                   2
#define QUEUE_ONLY_MON2                   3
#define QUEUE_UNUSED1                     4
#define QUEUE_UNUSED2                     5
#define QUEUE_MON_CANT_BE_TRADED          6
#define QUEUE_EGG_CANT_BE_TRADED          7
#define QUEUE_FRIENDS_MON_CANT_BE_TRADED  8

#define QUEUE_DELAY_MSG   3
#define QUEUE_DELAY_DATA  5

// IDs for CallTradeMenuFunc
#define TRADEMENUFUNC_MAIN_MENU                0
#define TRADEMENUFUNC_SELECTED_MON             1
#define TRADEMENUFUNC_SHOW_MON_SUMMARY         2
#define TRADEMENUFUNC_CONFIRM_OR_CANCEL_TRADE  3
#define TRADEMENUFUNC_CANCEL_TRADE_PROMPT      4
#define TRADEMENUFUNC_UNUSED_5                 5
#define TRADEMENUFUNC_BOTH_MONS_SELECTED       6
#define TRADEMENUFUNC_CONFIRM_TRADE_PROMPT     7
#define TRADEMENUFUNC_REDRAW_MAIN_MENU         8
#define TRADEMENUFUNC_LINK_TRADE_FADE_OUT      9
#define TRADEMENUFUNC_LINK_TRADE_WAIT_FADE     10
#define TRADEMENUFUNC_CANCEL_TRADE_1           11
#define TRADEMENUFUNC_CANCEL_TRADE_2           12
#define TRADEMENUFUNC_START_LINK_TRADE         13
#define TRADEMENUFUNC_DELAY_TRADE_CONFIRM      14
#define TRADEMENUFUNC_UNUSED_15                15
#define TRADEMENUFUNC_LINK_TRADE_WAIT_QUEUE    16
#define TRADEMENUFUNC_PARTNER_MON_INVALID      17
#define TRADEMENUFUNC_STANDBY                  100

// Message indexes for sUnionRoomTradeMessages
#define UR_TRADE_MSG_NONE                         0
#define UR_TRADE_MSG_NOT_MON_PARTNER_WANTS        1
#define UR_TRADE_MSG_NOT_EGG                      2
#define UR_TRADE_MSG_MON_CANT_BE_TRADED_NOW       3
#define UR_TRADE_MSG_MON_CANT_BE_TRADED           4
#define UR_TRADE_MSG_PARTNERS_MON_CANT_BE_TRADED  5
#define UR_TRADE_MSG_EGG_CANT_BE_TRADED           6
#define UR_TRADE_MSG_PARTNER_CANT_ACCEPT_MON      7
#define UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_1    8
#define UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_2    9

// Return values for CanRegisterMonForTradingBoard
#define CAN_REGISTER_MON      0
#define CANT_REGISTER_MON_NOW 1
#define CANT_REGISTER_MON     2
#define CANT_REGISTER_EGG     3


#endif //GUARD_CONSTANTS_TRADE_H
