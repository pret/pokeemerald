MossdeepCity_Gym_MapBorder::
	.incbin "data/layouts/MossdeepCity_Gym/border.bin"

MossdeepCity_Gym_MapBlockdata::
	.incbin "data/layouts/MossdeepCity_Gym/map.bin"

	.align 2
MossdeepCity_Gym_Layout::
	.4byte 0x1a
	.4byte 0x24
	.4byte MossdeepCity_Gym_MapBorder
	.4byte MossdeepCity_Gym_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_MossdeepGym

