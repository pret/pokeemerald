	.align 2
NavelRock_Top_MapBorder::
	.incbin "data/layouts/NavelRock_Top/border.bin"

	.align 2
NavelRock_Top_MapBlockdata::
	.incbin "data/layouts/NavelRock_Top/map.bin"

	.align 2
NavelRock_Top_Layout::
	.4byte 0x19
	.4byte 0x1c
	.4byte NavelRock_Top_MapBorder
	.4byte NavelRock_Top_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_NavelRock
