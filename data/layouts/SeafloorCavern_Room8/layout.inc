	.align 2
SeafloorCavern_Room8_MapBorder::
	.incbin "data/layouts/SeafloorCavern_Room8/border.bin"

	.align 2
SeafloorCavern_Room8_MapBlockdata::
	.incbin "data/layouts/SeafloorCavern_Room8/map.bin"

	.align 2
SeafloorCavern_Room8_Layout::
	.4byte 0xb
	.4byte 0xe
	.4byte SeafloorCavern_Room8_MapBorder
	.4byte SeafloorCavern_Room8_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
