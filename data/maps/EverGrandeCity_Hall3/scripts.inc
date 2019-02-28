EverGrandeCity_Hall3_MapScripts:: @ 8229593
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall3_MapScript2_229599
	.byte 0

EverGrandeCity_Hall3_MapScript2_229599: @ 8229599
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall3_EventScript_2295A3
	.2byte 0

EverGrandeCity_Hall3_EventScript_2295A3:: @ 82295A3
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

