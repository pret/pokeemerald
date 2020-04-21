EverGrandeCity_Hall2_MapScripts:: @ 822957E
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall2_OnWarp
	.byte 0

EverGrandeCity_Hall2_OnWarp: @ 8229584
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall2_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall2_EventScript_TurnPlayerNorth:: @ 822958E
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

