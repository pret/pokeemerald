MirageTower_2F_MapScripts:: @ 823AD11
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_2F_SetHoleWarp
	.byte 0

MirageTower_2F_SetHoleWarp: @ 823AD21
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MIRAGE_TOWER_1F, 255, 0, 0
	end

