MirageTower_2F_MapScripts:: @ 823AD11
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MirageTower_2F_MapScript2_2A8327
	map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_2F_MapScript1_2A8331
	map_script MAP_SCRIPT_ON_RESUME, MirageTower_2F_MapScript1_23AD21
	.byte 0

MirageTower_2F_MapScript1_23AD21: @ 823AD21
	setstepcallback 7
	setholewarp MAP_MIRAGE_TOWER_1F, 255, 0, 0
	end

