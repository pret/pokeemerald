#ifndef GUARD_FOLLOWER_NPC_OVERWORLD_H
#define GUARD_FOLLOWER_NPC_OVERWORLD_H

// NPC Followers
#define FNPC_ENABLE_NPC_FOLLOWERS                 FALSE // Enables the use of script macros to designate NPCs to follow behind the player, DPP style. Slightly increases the size of the saveblock (SaveBlock3).
#define FNPC_FLAG_HEAL_AFTER_FOLLOWER_BATTLE      0     // Replace the 0 with a flag in order to use that flag to toggle whether the Player's party will be automatically healed after every follower partner battle. If you want this to always be active without using a flag, replace 0 with FNPC_ALWAYS.
#define FNPC_FLAG_PARTNER_WILD_BATTLES            0     // Replace the 0 with a flag in order to use that flag to toggle whether the follower partner will join you for wild battles. If you want this to always be active without using a flag, replace 0 with FNPC_ALWAYS.
#define FNPC_NPC_FOLLOWER_WILD_BATTLE_VS_2        TRUE  // If set to TRUE, two wild Pokemon will show up to the partner battle instead of just one.
#define FNPC_NPC_FOLLOWER_PARTY_PREVIEW           TRUE  // If set to TRUE, a preview of the player's and partner's teams will be shown before every trainer battle.
#define FNPC_FACE_NPC_FOLLOWER_ON_DOOR_EXIT       TRUE  // If set to TRUE, the player will turn to face the follower when they exit a doorway.
#define FNPC_NPC_FOLLOWER_SHOW_AFTER_LEAVE_ROUTE  TRUE  // If set to TRUE, the follower will reappear and walk out of the player after using Fly, Escape Rope, or Teleport.

#endif // GUARD_FOLLOWER_NPC_OVERWORLD_H
