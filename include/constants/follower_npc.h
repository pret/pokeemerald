#ifndef GUARD_CONSTANTS_FOLLOWER_NPC_H
#define GUARD_CONSTANTS_FOLLOWER_NPC_H

// NPC Follower Flags
#define FOLLOWER_NPC_FLAG_CAN_BIKE              0x2     // Player is allowed to use the Bike. Part of FOLLOWER_NPC_FLAG_ALL_LAND.
#define FOLLOWER_NPC_FLAG_CAN_LEAVE_ROUTE       0x4     // Player is allowed to use Fly/Teleport/EscapeRope/etc. Part of FOLLOWER_NPC_FLAG_ALL_LAND.
#define FOLLOWER_NPC_FLAG_CAN_SURF              0x8     // Player is allowed to Surf. Part of FOLLOWER_NPC_FLAG_ALL_WATER.
#define FOLLOWER_NPC_FLAG_CAN_WATERFALL         0x10    // Player is allowed to use Waterfall. Part of FOLLOWER_NPC_FLAG_ALL_WATER.
#define FOLLOWER_NPC_FLAG_CAN_DIVE              0x20    // Player is allowed to use Dive. Part of FOLLOWER_NPC_FLAG_ALL_WATER.
#define FOLLOWER_NPC_FLAG_CLEAR_ON_WHITE_OUT    0x80    // The NPC follower will be destroyed if the player whites out.

#define FOLLOWER_NPC_FLAG_ALL_LAND              FOLLOWER_NPC_FLAG_CAN_BIKE | FOLLOWER_NPC_FLAG_CAN_LEAVE_ROUTE
#define FOLLOWER_NPC_FLAG_ALL_WATER             FOLLOWER_NPC_FLAG_CAN_SURF | FOLLOWER_NPC_FLAG_CAN_WATERFALL | FOLLOWER_NPC_FLAG_CAN_DIVE
#define FOLLOWER_NPC_FLAG_ALL                   FOLLOWER_NPC_FLAG_ALL_LAND | FOLLOWER_NPC_FLAG_ALL_WATER | FOLLOWER_NPC_FLAG_CLEAR_ON_WHITE_OUT

// Shorter flag names for ease of use in setfollowernpc script macro
#define FNPC_BIKE                             FOLLOWER_NPC_FLAG_CAN_BIKE
#define FNPC_LEAVE_ROUTE                      FOLLOWER_NPC_FLAG_CAN_LEAVE_ROUTE
#define FNPC_SURF                             FOLLOWER_NPC_FLAG_CAN_SURF
#define FNPC_WATERFALL                        FOLLOWER_NPC_FLAG_CAN_WATERFALL
#define FNPC_DIVE                             FOLLOWER_NPC_FLAG_CAN_DIVE
#define FNPC_WHITE_OUT                        FOLLOWER_NPC_FLAG_CLEAR_ON_WHITE_OUT

#define FNPC_ALL_LAND                         FOLLOWER_NPC_FLAG_ALL_LAND
#define FNPC_ALL_WATER                        FOLLOWER_NPC_FLAG_ALL_WATER
#define FNPC_ALL                              FOLLOWER_NPC_FLAG_ALL

#endif // GUARD_CONSTANTS_FOLLOWER_NPC_H
