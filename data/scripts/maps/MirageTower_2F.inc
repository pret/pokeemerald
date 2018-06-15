MirageTower_2F_MapScripts:: @ 823AD11
	map_script 2, MirageTower_2F_MapScript2_2A8327
	map_script 3, MirageTower_2F_MapScript1_2A8331
	map_script 5, MirageTower_2F_MapScript1_23AD21
	.byte 0

MirageTower_2F_MapScript1_23AD21: @ 823AD21
	setstepcallback 7
	setholewarp MAP_MIRAGE_TOWER_1F, 255, 0, 0
	end

