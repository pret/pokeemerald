EverGrandeCity_Hall5_MapScripts:: @ 82295BD
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall5_OnWarp
	.byte 0

EverGrandeCity_Hall5_OnWarp: @ 82295C3
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall5_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall5_EventScript_TurnPlayerNorth:: @ 82295CD
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

