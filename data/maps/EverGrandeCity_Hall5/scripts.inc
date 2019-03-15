EverGrandeCity_Hall5_MapScripts:: @ 82295BD
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall5_MapScript2_2295C3
	.byte 0

EverGrandeCity_Hall5_MapScript2_2295C3: @ 82295C3
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall5_EventScript_2295CD
	.2byte 0

EverGrandeCity_Hall5_EventScript_2295CD:: @ 82295CD
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

