# Littleroot Town
Map folder: LittlerootTown

## Map Scripts

### OnMapTransition
This is the first script to run in Littleroot Town. It sets the flag for visiting the town, then sets up the rival's sprite as object id 0.

The script will then check VAR_LITTLEROOT_INTRO_STATE. By default, Mom is placed in front of Brendan's house. This checks if the intro state is LITTLEROOT_INTRO_STATE_FEMALE; if it is, then Mom needs to be moved in front of May's house.

If the player hasn't rescued birch yet, `LittlerootTown_EventScript_PlaceTwin` is called. This script places the twin in their "guarding" position or their "concerned" position, depending on VAR_PROF_BIRCH_STATE. The guarding position is to the left of the northern exit, so that they can intercept the player if they try to leave. The concerned position is on the west side of the northern exit, looking towards where birch is being attacked.

TODO: Several unknown checks happen.

### OnFrame
If the intro sequence is active (i.e. VAR_LITTLEROOT_INTRO_STATE is MALE or FEMALE), then the MoveInMomSequence will start. First, depending on the player's gender, VAR_0x8004 and VAR_0x8005 are set to the X and Y coords of the front door of the player's house. The player jumps out of the truck, Mom exits the house and talks to the player, then the player follows Mom back into the house. The script hides the Truck and Mom and warps to the player's house.

VAR_NATIONAL_DEX_STATE is checked, but it hasn't been documented yet.

## Object Events

### The Twin

