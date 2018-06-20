	.align 2
IslandHarbor_MapBorder::
	.incbin "data/layouts/IslandHarbor/border.bin"

	.align 2
IslandHarbor_MapBlockdata::
	.incbin "data/layouts/IslandHarbor/map.bin"

	.align 2
IslandHarbor_Layout::
	.4byte 0x11
	.4byte 0xd
	.4byte IslandHarbor_MapBorder
	.4byte IslandHarbor_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_IslandHarbor
