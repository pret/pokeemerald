	.align 2
NavelRock_Fork_MapBorder::
	.incbin "data/layouts/NavelRock_Fork/border.bin"

	.align 2
NavelRock_Fork_MapBlockdata::
	.incbin "data/layouts/NavelRock_Fork/map.bin"

	.align 2
NavelRock_Fork_Layout::
	.4byte 0x1b
	.4byte 0x56
	.4byte NavelRock_Fork_MapBorder
	.4byte NavelRock_Fork_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_NavelRock
