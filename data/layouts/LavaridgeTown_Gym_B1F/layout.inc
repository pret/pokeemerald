LavaridgeTown_Gym_B1F_MapBorder::
	.incbin "data/layouts/LavaridgeTown_Gym_B1F/border.bin"

LavaridgeTown_Gym_B1F_MapBlockdata::
	.incbin "data/layouts/LavaridgeTown_Gym_B1F/map.bin"

	.align 2
LavaridgeTown_Gym_B1F_Layout::
	.4byte 0x11
	.4byte 0x13
	.4byte LavaridgeTown_Gym_B1F_MapBorder
	.4byte LavaridgeTown_Gym_B1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_LavaridgeGym

