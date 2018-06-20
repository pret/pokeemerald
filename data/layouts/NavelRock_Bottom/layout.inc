	.align 2
NavelRock_Bottom_MapBorder::
	.incbin "data/layouts/NavelRock_Bottom/border.bin"

	.align 2
NavelRock_Bottom_MapBlockdata::
	.incbin "data/layouts/NavelRock_Bottom/map.bin"

	.align 2
NavelRock_Bottom_Layout::
	.4byte 0x16
	.4byte 0x16
	.4byte NavelRock_Bottom_MapBorder
	.4byte NavelRock_Bottom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_NavelRock
