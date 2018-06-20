	.align 2
GraniteCave_1F_MapBorder::
	.incbin "data/layouts/GraniteCave_1F/border.bin"

	.align 2
GraniteCave_1F_MapBlockdata::
	.incbin "data/layouts/GraniteCave_1F/map.bin"

	.align 2
GraniteCave_1F_Layout::
	.4byte 0x2a
	.4byte 0xf
	.4byte GraniteCave_1F_MapBorder
	.4byte GraniteCave_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
