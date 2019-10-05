#ifndef GUARD_CONSTANTS_TRADE_H
#define GUARD_CONSTANTS_TRADE_H

#define TRADE_PLAYER  0
#define TRADE_PARTNER 1

#define INGAME_TRADE_SEEDOT 0
#define INGAME_TRADE_PLUSLE 1
#define INGAME_TRADE_HORSEA 2
#define INGAME_TRADE_MEOWTH 3

#define INGAME_TRADE_MAIL_LENGTH 9

#define PLAYER_MON_INVALID   0
#define PLAYER_MON_VALID     1
#define PARTNER_MON_INVALID  2

#define TRADE_ACTION_TEXT_CANCEL        0
#define TRADE_ACTION_TEXT_CHOOSE_MON    1
#define TRADE_ACTION_TEXT_SUMMARY       2
#define TRADE_ACTION_TEXT_TRADE         3
#define TRADE_ACTION_TEXT_CANCEL_TRADE  4
#define TRADE_ACTION_TEXT_JP_QUIT       5

#define MENU_ACTION_SUMMARY 0
#define MENU_ACTION_TRADE   1

// Message indexes for sTradeMessages
#define TRADE_MSG_STANDBY                    0
#define TRADE_MSG_CANCELED                   1
#define TRADE_MSG_ONLY_MON1                  2
#define TRADE_MSG_ONLY_MON2                  3
#define TRADE_MSG_WAITING_FOR_FRIEND         4
#define TRADE_MSG_FRIEND_WANTS_TO_TRADE      5
#define TRADE_MSG_MON_CANT_BE_TRADED         6
#define TRADE_MSG_EGG_CANT_BE_TRADED         7
#define TRADE_MSG_FRIENDS_MON_CANT_BE_TRADED 8

// Message indexes for sUnionRoomTradeMessages
#define UR_TRADE_MSG_NONE                         0
#define UR_TRADE_MSG_NOT_MON_PARTNER_WANTS        1
#define UR_TRADE_MSG_NOT_EGG                      2
#define UR_TRADE_MSG_MON_CANT_BE_TRADED_1         3
#define UR_TRADE_MSG_MON_CANT_BE_TRADED_2         4
#define UR_TRADE_MSG_PARTNERS_MON_CANT_BE_TRADED  5
#define UR_TRADE_MSG_EGG_CANT_BE_TRADED           6
#define UR_TRADE_MSG_PARTNER_CANT_ACCEPT_MON      7
#define UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_1    8
#define UR_TRADE_MSG_CANT_TRADE_WITH_PARTNER_2    9

// Return values for CanRegisterMonForTradingBoard
#define CAN_REGISTER_MON   0
#define CANT_REGISTER_MON  1
#define CANT_REGISTER_EGG  2


#endif //GUARD_CONSTANTS_TRADE_H
