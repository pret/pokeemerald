Underwater_MarineCave_MapBorder::
	.incbin "data/layouts/Underwater_MarineCave/border.bin"

Underwater_MarineCave_MapBlockdata::
	.incbin "data/layouts/Underwater_MarineCave/map.bin"

	.align 2
Underwater_MarineCave_Layout::
	.4byte 0x14
	.4byte 0xa
	.4byte Underwater_MarineCave_MapBorder
	.4byte Underwater_MarineCave_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater

