#ifndef GUARD_CONSTANTS_CABLE_CLUB_H
#define GUARD_CONSTANTS_CABLE_CLUB_H

// States for VAR_CABLE_CLUB_STATE
#define USING_SINGLE_BATTLE  1
#define USING_DOUBLE_BATTLE  2
#define USING_TRADE_CENTER   3
#define USING_RECORD_CORNER  4
#define USING_MULTI_BATTLE   5
#define USING_UNION_ROOM     6
#define USING_BERRY_CRUSH    7
#define USING_MINIGAME       8
#define USING_BATTLE_TOWER   9

// Return states for the group of specials that use CreateLinkupTask
// A few also used by TryBecomeLinkLeader and TryJoinLinkGroup
#define LINKUP_ONGOING              0
#define LINKUP_SUCCESS              1
#define LINKUP_SOMEONE_NOT_READY    2
#define LINKUP_DIFF_SELECTIONS      3
#define LINKUP_WRONG_NUM_PLAYERS    4
#define LINKUP_FAILED               5
#define LINKUP_CONNECTION_ERROR     6
#define LINKUP_PLAYER_NOT_READY     7
#define LINKUP_RETRY_ROLE_ASSIGN    8
#define LINKUP_PARTNER_NOT_READY    9
#define LINKUP_FAILED_CONTEST_GMODE 10
#define LINKUP_FAILED_BATTLE_TOWER  11
#define LINKUP_FOREIGN_GAME         12

#endif //GUARD_CONSTANTS_CABLE_CLUB_H
