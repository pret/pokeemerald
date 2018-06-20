NavelRock_B1F_MapBorder::
	.incbin "data/layouts/NavelRock_B1F/border.bin"

NavelRock_B1F_MapBlockdata::
	.incbin "data/layouts/NavelRock_B1F/map.bin"

	.align 2
NavelRock_B1F_Layout::
	.4byte 0x17
	.4byte 0xb
	.4byte NavelRock_B1F_MapBorder
	.4byte NavelRock_B1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_NavelRock

