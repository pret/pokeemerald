	.align 2
FarawayIsland_Interior_MapBorder::
	.incbin "data/layouts/FarawayIsland_Interior/border.bin"

	.align 2
FarawayIsland_Interior_MapBlockdata::
	.incbin "data/layouts/FarawayIsland_Interior/map.bin"

	.align 2
FarawayIsland_Interior_Layout::
	.4byte 0x1d
	.4byte 0x1a
	.4byte FarawayIsland_Interior_MapBorder
	.4byte FarawayIsland_Interior_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Fortree
