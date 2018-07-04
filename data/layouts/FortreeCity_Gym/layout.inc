FortreeCity_Gym_MapBorder::
	.incbin "data/layouts/FortreeCity_Gym/border.bin"

FortreeCity_Gym_MapBlockdata::
	.incbin "data/layouts/FortreeCity_Gym/map.bin"

	.align 2
FortreeCity_Gym_Layout::
	.4byte 0x14
	.4byte 0x19
	.4byte FortreeCity_Gym_MapBorder
	.4byte FortreeCity_Gym_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_FortreeGym

