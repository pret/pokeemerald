	.align 2
MarineCave_End_MapBorder::
	.incbin "data/layouts/MarineCave_End/border.bin"

	.align 2
MarineCave_End_MapBlockdata::
	.incbin "data/layouts/MarineCave_End/map.bin"

	.align 2
MarineCave_End_Layout::
	.4byte 0x1b
	.4byte 0x1e
	.4byte MarineCave_End_MapBorder
	.4byte MarineCave_End_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
