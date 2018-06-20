	.align 2
SkyPillar_4F_MapBorder::
	.incbin "data/layouts/SkyPillar_4F/border.bin"

	.align 2
SkyPillar_4F_MapBlockdata::
	.incbin "data/layouts/SkyPillar_4F/map.bin"

	.align 2
SkyPillar_4F_Layout::
	.4byte 0xe
	.4byte 0xe
	.4byte SkyPillar_4F_MapBorder
	.4byte SkyPillar_4F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
