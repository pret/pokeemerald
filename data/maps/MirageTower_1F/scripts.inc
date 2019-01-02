MirageTower_1F_MapScripts:: @ 823AD01
	map_script 3, MirageTower_1F_MapScript1_23AD07
	.byte 0

MirageTower_1F_MapScript1_23AD07: @ 823AD07
	setflag FLAG_ENTERED_MIRAGE_TOWER
	setflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setflag FLAG_LANDMARK_MIRAGE_TOWER
	end

