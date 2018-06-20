	.align 2
SeafloorCavern_Entrance_MapBorder::
	.incbin "data/layouts/SeafloorCavern_Entrance/border.bin"

	.align 2
SeafloorCavern_Entrance_MapBlockdata::
	.incbin "data/layouts/SeafloorCavern_Entrance/map.bin"

	.align 2
SeafloorCavern_Entrance_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte SeafloorCavern_Entrance_MapBorder
	.4byte SeafloorCavern_Entrance_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
