	.align 2
MauvilleCity_Gym_MapBorder::
	.incbin "data/layouts/MauvilleCity_Gym/border.bin"

	.align 2
MauvilleCity_Gym_MapBlockdata::
	.incbin "data/layouts/MauvilleCity_Gym/map.bin"

	.align 2
MauvilleCity_Gym_Layout::
	.4byte 0xa
	.4byte 0x15
	.4byte MauvilleCity_Gym_MapBorder
	.4byte MauvilleCity_Gym_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_MauvilleGym
