	.align 2
TerraCave_Entrance_MapBorder::
	.incbin "data/layouts/TerraCave_Entrance/border.bin"

	.align 2
TerraCave_Entrance_MapBlockdata::
	.incbin "data/layouts/TerraCave_Entrance/map.bin"

	.align 2
TerraCave_Entrance_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte TerraCave_Entrance_MapBorder
	.4byte TerraCave_Entrance_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
