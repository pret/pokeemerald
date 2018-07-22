NavelRock_LadderRoom1_MapBorder::
	.incbin "data/layouts/NavelRock_LadderRoom1/border.bin"

NavelRock_LadderRoom1_MapBlockdata::
	.incbin "data/layouts/NavelRock_LadderRoom1/map.bin"

	.align 2
NavelRock_LadderRoom1_Layout::
	.4byte 0x9
	.4byte 0x8
	.4byte NavelRock_LadderRoom1_MapBorder
	.4byte NavelRock_LadderRoom1_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_NavelRock

