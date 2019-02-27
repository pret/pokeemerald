MirageTower_3F_MapScripts:: @ 823AD2C
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MirageTower_3F_MapScript2_2A8327
	map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_3F_MapScript1_2A8331
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_3F_MapScript1_23AD3C
	.byte 0

MirageTower_3F_MapScript1_23AD3C: @ 823AD3C
	setstepcallback 7
	setholewarp MAP_MIRAGE_TOWER_2F, 255, 0, 0
	end

