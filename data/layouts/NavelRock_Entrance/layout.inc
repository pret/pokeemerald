NavelRock_Entrance_MapBorder::
	.incbin "data/layouts/NavelRock_Entrance/border.bin"

NavelRock_Entrance_MapBlockdata::
	.incbin "data/layouts/NavelRock_Entrance/map.bin"

	.align 2
NavelRock_Entrance_Layout::
	.4byte 0x15
	.4byte 0x20
	.4byte NavelRock_Entrance_MapBorder
	.4byte NavelRock_Entrance_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_NavelRock

