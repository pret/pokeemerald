# Inside of the Moving Van
Map folder: InsideOfTruck

## Map Scripts

When the map is first displayed on screen, it's already running an event sequence to animate the boxes moving around. The OnLoad map script runs immediately after this animation terminates, and sets the three tiles at the back of the truck to the bright-exit tile. This simulates the truck door being "opened."

The OnResume map script then starts the `EndTruckSequence` per-step callback.

## Box messages
There are five tiles with moving boxes on them that use the
`InsideOfTruck_EventScript_MovingBoxLogo` event. It displays a
short description of a moving box's logo. They are coded as background
events.

There are three objects that jostle around during the opening scene.
These boxes also have the `InsideOfTruck_EventScript_MovingBoxLogo` script
assigned, but cannot be reached by the player, so the script is never used.

## Exit setup
Vars: VAR_LITTLEROOT_INTRO_STATE, VAR_LITTLEROOT_HOUSES_STATE_2, VAR_LITTLEROOT_HOUSES_STATE

There are three tiles with the `InsideOfTruck_EventScript_SetupRivalHideFlags` script, that appear one step before the sunlit exit. When the player walks onto one of these tiles, the script will freeze all movement, and then check the player's gender.

If the player is male, `InsideOfTruck_EventScript_SetupBrendanHideFlags` is run. This script sets the player's respawn point to Brendan's house, sets VAR_LITTLEROOT_INTRO_STATE to MALE, and also sets VAR_LITTLEROOT_HOUSES_STATE_2 to HOUSES_STATE_1.
If the player is female, `InsideOfTruck_EventScript_SetupMayHideFlags` is run instead. This sets the player's respawn point to May's house, sets VAR_LITTLEROOT_INTRO_STATE to FEMALE, and also sets VAR_LITTLEROOT_HOUSES_STATE to HOUSES_STATE_1.

These scripts then set a few flags, based on gender, to hide props in LittlerootTown and the two rival houses. At the start of the game, all the props and graphics for both intro sequences are enabled, and the game uses these flags to hide half of them.

Finally, the script sets up the warp tiles to point to the correct location on the LittlerootTown map, depending on the gender. If male, the player will warp to (3, 10). If female, (12, 10).

## Warp tiles

These tiles are one step off the map. They are dynamic warps, and are setup by the exit tiles described above.