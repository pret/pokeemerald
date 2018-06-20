	.align 2
SkyPillar_3F_MapBorder::
	.incbin "data/layouts/SkyPillar_3F/border.bin"

	.align 2
SkyPillar_3F_MapBlockdata::
	.incbin "data/layouts/SkyPillar_3F/map.bin"

	.align 2
SkyPillar_3F_Layout::
	.4byte 0xe
	.4byte 0xe
	.4byte SkyPillar_3F_MapBorder
	.4byte SkyPillar_3F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
