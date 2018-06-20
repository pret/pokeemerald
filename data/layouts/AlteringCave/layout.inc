	.align 2
AlteringCave_MapBorder::
	.incbin "data/layouts/AlteringCave/border.bin"

	.align 2
AlteringCave_MapBlockdata::
	.incbin "data/layouts/AlteringCave/map.bin"

	.align 2
AlteringCave_Layout::
	.4byte 0x20
	.4byte 0x18
	.4byte AlteringCave_MapBorder
	.4byte AlteringCave_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
