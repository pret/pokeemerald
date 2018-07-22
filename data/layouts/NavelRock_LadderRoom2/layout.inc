NavelRock_LadderRoom2_MapBorder::
	.incbin "data/layouts/NavelRock_LadderRoom2/border.bin"

NavelRock_LadderRoom2_MapBlockdata::
	.incbin "data/layouts/NavelRock_LadderRoom2/map.bin"

	.align 2
NavelRock_LadderRoom2_Layout::
	.4byte 0x9
	.4byte 0x8
	.4byte NavelRock_LadderRoom2_MapBorder
	.4byte NavelRock_LadderRoom2_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_NavelRock

