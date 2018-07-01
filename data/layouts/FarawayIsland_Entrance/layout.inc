FarawayIsland_Entrance_MapBorder::
	.incbin "data/layouts/FarawayIsland_Entrance/border.bin"

FarawayIsland_Entrance_MapBlockdata::
	.incbin "data/layouts/FarawayIsland_Entrance/map.bin"

	.align 2
FarawayIsland_Entrance_Layout::
	.4byte 0x22
	.4byte 0x2e
	.4byte FarawayIsland_Entrance_MapBorder
	.4byte FarawayIsland_Entrance_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Rustboro

