	.align 2
MarineCave_Entrance_MapBorder::
	.incbin "data/layouts/MarineCave_Entrance/border.bin"

	.align 2
MarineCave_Entrance_MapBlockdata::
	.incbin "data/layouts/MarineCave_Entrance/map.bin"

	.align 2
MarineCave_Entrance_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte MarineCave_Entrance_MapBorder
	.4byte MarineCave_Entrance_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
