MirageTower_2F_MapScripts:: @ 823AD11
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_MapScript2_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_MapScript1_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_2F_MapScript1_SetHoleWarp
	.byte 0

MirageTower_2F_MapScript1_SetHoleWarp: @ 823AD21
	setstepcallback 7
	setholewarp MAP_MIRAGE_TOWER_1F, 255, 0, 0
	end

