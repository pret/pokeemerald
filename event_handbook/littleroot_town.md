# Littleroot Town


## Inside of the Moving Van
Map folder: InsideOfTruck

### Box messages
There are five tiles with moving boxes on them that use the
`InsideOfTruck_EventScript_MovingBoxLogo` event. It displays a
short description of a moving box's logo. They are coded as background
events.

There are three objects that jostle around during the opening scene.
These boxes also have the `InsideOfTruck_EventScript_MovingBoxLogo` script
assigned, but cannot be reached by the player, so the script is never used.

### Exit setup
Vars: VAR_INTRO_SEQUENCE_STATE, VAR_0x408C, VAR_0x4082

There are three tiles with the `InsideOfTruck_EventScript_SetupGenderHideFlags` script, that appear one step before the sunlit exit. When the player walks onto one of these tiles, the script will freeze all movement, and then check the player's gender.

If the player is male, `InsideOfTruck_EventScript_SetupBrendanHideFlags` is run. This script sets the player's respawn point to Brendan's house, sets VAR_INTRO_SEQUENCE_STATE to MALE, and also sets VAR_0x408C to 1.
If the player is female, `InsideOfTruck_EventScript_SetupMayHideFlags` is run instead. This sets the player's respawn point to May's house, sets VAR_INTRO_SEQUENCE_STATE to FEMALE, and also sets VAR_0x4082 to 1.

These scripts then set a few flags, based on gender, to hide props in LittlerootTown and the two rival houses. At the start of the game, all the props and graphics for both intro sequences are enabled, and the game uses these flags to hide half of them.

Finally, the script sets up the warp tiles to point to the correct location on the LittlerootTown map, depending on the gender. If male, the player will warp to (3, 10). If female, (12, 10).

It is currently unknown what the VAR_0x408C and VAR_INTRO_SEQUENCE_STATE vars do.

### Warp tiles

These tiles are one step off the map. They are dynamic warps, and are setup by the exit tiles described above.

## Littleroot Town
Map folder: LittlerootTown

### OnMapTransition
This is the first script to run in Littleroot Town. It sets the flag for visiting the town, then sets up the rival's sprite as object id 0. The script will check if the 