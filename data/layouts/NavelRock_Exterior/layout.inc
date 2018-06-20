NavelRock_Exterior_MapBorder::
	.incbin "data/layouts/NavelRock_Exterior/border.bin"

NavelRock_Exterior_MapBlockdata::
	.incbin "data/layouts/NavelRock_Exterior/map.bin"

	.align 2
NavelRock_Exterior_Layout::
	.4byte 0x15
	.4byte 0x18
	.4byte NavelRock_Exterior_MapBorder
	.4byte NavelRock_Exterior_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Dewford

