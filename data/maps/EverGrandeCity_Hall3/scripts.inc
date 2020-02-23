EverGrandeCity_Hall3_MapScripts:: @ 8229593
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall3_OnWarp
	.byte 0

EverGrandeCity_Hall3_OnWarp: @ 8229599
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall3_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall3_EventScript_TurnPlayerNorth:: @ 82295A3
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

