SeafloorCavern_Room2_MapBorder::
	.incbin "data/layouts/SeafloorCavern_Room2/border.bin"

SeafloorCavern_Room2_MapBlockdata::
	.incbin "data/layouts/SeafloorCavern_Room2/map.bin"

	.align 2
SeafloorCavern_Room2_Layout::
	.4byte 0x12
	.4byte 0xc
	.4byte SeafloorCavern_Room2_MapBorder
	.4byte SeafloorCavern_Room2_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

