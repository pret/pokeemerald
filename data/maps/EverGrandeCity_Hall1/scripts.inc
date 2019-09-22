EverGrandeCity_Hall1_MapScripts:: @ 8229569
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall1_MapScript2_22956F
	.byte 0

EverGrandeCity_Hall1_MapScript2_22956F: @ 822956F
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall1_EventScript_229579
	.2byte 0

EverGrandeCity_Hall1_EventScript_229579:: @ 8229579
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end

