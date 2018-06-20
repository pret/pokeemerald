TerraCave_End_MapBorder::
	.incbin "data/layouts/TerraCave_End/border.bin"

TerraCave_End_MapBlockdata::
	.incbin "data/layouts/TerraCave_End/map.bin"

	.align 2
TerraCave_End_Layout::
	.4byte 0x1b
	.4byte 0x1e
	.4byte TerraCave_End_MapBorder
	.4byte TerraCave_End_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

