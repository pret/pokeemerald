GraniteCave_B1F_MapScripts:: @ 822DC5E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_MapScript2_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_MapScript1_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_MapScript1_SetHoleWarp
	.byte 0

GraniteCave_B1F_MapScript1_SetHoleWarp: @ 822DC6E
	setstepcallback 7
	setholewarp MAP_GRANITE_CAVE_B2F, 255, 0, 0
	end

