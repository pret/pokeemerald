# How to Use Follower NPCs
*Written by Bivurnum*
*gif by ghoulslash*

![follower-npc](img/follower_npc/follower-npc.gif)

## Configs
The configs for follower NPCs can be found in [include/config/follower_npc.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/config/follower_npc.h).

* `FNPC_ENABLE_NPC_FOLLOWERS`: This must be set to `TRUE` in order to enable follower NPCs. It is `FALSE` by default as it adds some size to the save block.
* `FNPC_FLAG_HEAL_AFTER_FOLLOWER_BATTLE`: The player's party can be automatically healed after every partner battle. Set it to a flag to toggle it on/off with scripts, or set it to `FNPC_ALWAYS` to have it happen every time.
* `FNPC_FLAG_PARTNER_WILD_BATTLES`: The battle partner can join the player for wild battles. Set it to a flag to toggle it on/off with scripts, or set it to `FNPC_ALWAYS` to have it happen every time.
* `FNPC_NPC_FOLLOWER_WILD_BATTLE_VS_2`: Wild battles with a battle partner default to two wild Pokémon appearing. You can set this to `FALSE` to make only one wild Pokémon appear.
* `FNPC_NPC_FOLLOWER_PARTY_PREVIEW`: By default, a preview of the player's and partner's teams will be shown at the start of every trainer battle. Set this to `FALSE` to disable this feature.
* `FNPC_FACE_NPC_FOLLOWER_ON_DOOR_EXIT`: If `TRUE` the player will turn to face the follower when they exit a doorway.
* `FNPC_NPC_FOLLOWER_SHOW_AFTER_LEAVE_ROUTE`: If `TRUE` the follower will walk out of the player automatically after using Fly, Teleport, or Escape Rope.

## Set the Follower
The `setfollowernpc` macro will turn the specified object into an NPC follower. It requires the object id, the [follower flags](#follower-flags), and optionally a custom script and a [battle partner](#battle-partner). If you do not include a custom script name (or you set it to `0`), the NPC follower will default to their normal interaction script. If there is a follower Pokémon present, it will be returned to its Pokeball until the NPC follower is destroyed.

Here's an example:
`setfollowernpc 3, FNPC_ALL, MyScript_Eventscript_CustomFollowerScript, PARTNER_STEVEN`
This would turn object number 3 on the current map into an NPC follower, give them access to all following behaviors, run that custom script when the player interacts with them, and adds the Steven battle partner to the follower ([more on this later](#battle-partner)).

The object ***MUST*** have an event flag or the NPC follower will not be created!

## Create a Follower
The `createfollowernpc` macro will create a new follower without needing to convert an existing NPC. It works similarly to `setfollowernpc`, but instead of providing an object id, you give it a GFX id. For example, if you wanted to create a follower with the May sprite, you could do something like this:
`createfollowernpc OBJ_EVENT_GFX_RIVAL_MAY_NORMAL, FNPC_ALL, EventScript_MayFollow`
The created follower NPC will initially be invisible until the player takes a step.

## Follower Flags
These are required to tell the game what behavior you want the NPC follower to have. They are defined in [include/constants/follower_npc.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/follower_npc.h). The second list of flags is the same as the first, but with shortened names to make them easier to type when scripting. The first 7 flags in the list are individual behaviors, whereas the remaining three are bundles of flags. For example, if you use `FNPC_SURF` in `setfollowernpc`, the NPC follower will be able to Surf behind the player. If you use `FNPC_ALL_WATER` instead, the NPC follower will be able to Dive and go up Waterfalls in addition to being able to Surf. Feel free to add your own custom bundles of flags to the file to meet your needs.

To make sure the NPC follower uses the correct animation frames, you should add an entry to `gFollowerAlternateSprites` in [include/follower_npc_alternate_sprites.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/follower_npc_alternate_sprites.h). Only do this if your object has distinct animation frames for different behaviors (running, biking, surfing, etc). Follow the templates for Rival May and Rival Brendan that already exist there.

## Follower Movements
You can use the `applymovement` macro on an NPC follower by using `OBJ_EVENT_ID_NPC_FOLLOWER` for the object id. This is convenient for making the NPC follower walk off-screen before destroying them. If an NPC follower is not immediately next to the player while the controls aren't locked, it will try to take steps to get back into position as the player moves, sometimes walking through impassable areas (like through the middle of buildings).

You can also use `facefollowernpc` to make both the player and the NPC follower face each other.

> [!NOTE]
> The existing vanilla movement scripts do not take NPC followers into account. Other NPCs may walk into the follower or the follower may get left behind. If you want follower NPCs to work with these existing scripts, you will need to add your own handling for them. The `hidefollowernpc` macro can be particularly useful for this.

## Check for Follower
You can use the `checkfollowernpc` macro to check whether or not an NPC follower currently exists. It will set `VAR_RESULT` to `TRUE` if an NPC follower exists, otherwise it will be set to `FALSE`.

## Hide the Follower
The `hidefollowernpc` macro makes the NPC follower walk into the player and be hidden. The game will wait until the movement is finished before continuing with the script. There is an optional parameter that can be used to set the desired walk speed for the movement. It can be from `0` (slowest) to `3` (fastest). If a walk speed is not specified, it will default to the normal walk speed. The NPC follower will reappear the next time the player takes a step (outside of scripts).

## Destroy the Follower
The `destroyfollowernpc` macro acts similarly to `removeobject`. It removes the NPC follower object instantly and sets their flag. If you have Pokémon followers enabled, the Pokémon will reappear the next time the player takes a step.

## Battle Partner
If you assign a battle partner to the NPC follower, that partner will fight alongside the player in all trainer battles while the follower is present. This turns all battles into multi battles, whether against one opponent or two.

You can use any battle partner that has been defined in [include/constants/battle_partner.h](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/include/constants/battle_partner.h). The partners' information and Pokémon teams can be set in [src/data/battle_partners.party](https://github.com/rh-hideout/pokeemerald-expansion/blob/upcoming/src/data/battle_partners.party).

To change the battle partner of an existing NPC follower, you can use the `changefollowerbattler` macro with the desired partner ID. If you change the ID to `0`, the NPC follower will not participate in any battles until you change it back to a valid partner ID.

Keep in mind that only the first 3 Pokémon in the player's party will participate in multi battles. The other three party members are temporarily replaced with the partner's Pokémon. This means the last three Pokémon in the player's party will not receive any experience points (even from the EXP Share).
