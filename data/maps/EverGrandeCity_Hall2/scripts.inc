EverGrandeCity_Hall2_MapScripts:: @ 822957E
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall2_MapScript2_229584
	.byte 0

EverGrandeCity_Hall2_MapScript2_229584: @ 8229584
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall2_EventScript_22958E
	.2byte 0

EverGrandeCity_Hall2_EventScript_22958E:: @ 822958E
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

