GraniteCave_B1F_MapScripts:: @ 822DC5E
	map_script MAP_SCRIPT_TRIGGER_EVENTS, GraniteCave_B1F_MapScript2_2A8327
	map_script MAP_SCRIPT_SET_DATA, GraniteCave_B1F_MapScript1_2A8331
	map_script MAP_SCRIPT_TRIGGER_SPECIALS, GraniteCave_B1F_MapScript1_22DC6E
	.byte 0

GraniteCave_B1F_MapScript1_22DC6E: @ 822DC6E
	setstepcallback 7
	setholewarp MAP_GRANITE_CAVE_B2F, 255, 0, 0
	end

