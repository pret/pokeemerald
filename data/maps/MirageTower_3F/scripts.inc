MirageTower_3F_MapScripts:: @ 823AD2C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_MapScript2_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_MapScript1_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_3F_MapScript1_SetHoleWarp
	.byte 0

MirageTower_3F_MapScript1_SetHoleWarp: @ 823AD3C
	setstepcallback 7
	setholewarp MAP_MIRAGE_TOWER_2F, 255, 0, 0
	end

