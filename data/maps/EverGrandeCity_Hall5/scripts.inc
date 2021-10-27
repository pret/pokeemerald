EverGrandeCity_Hall5_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall5_OnWarp
	.byte 0

EverGrandeCity_Hall5_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall5_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall5_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

