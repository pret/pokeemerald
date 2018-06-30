RustboroCity_Gym_MapBorder::
	.incbin "data/layouts/RustboroCity_Gym/border.bin"

RustboroCity_Gym_MapBlockdata::
	.incbin "data/layouts/RustboroCity_Gym/map.bin"

	.align 2
RustboroCity_Gym_Layout::
	.4byte 0xb
	.4byte 0x14
	.4byte RustboroCity_Gym_MapBorder
	.4byte RustboroCity_Gym_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_RustboroGym

