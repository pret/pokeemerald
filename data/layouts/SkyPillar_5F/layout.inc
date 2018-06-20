SkyPillar_5F_MapBorder::
	.incbin "data/layouts/SkyPillar_5F/border.bin"

SkyPillar_5F_MapBlockdata::
	.incbin "data/layouts/SkyPillar_5F/map.bin"

	.align 2
SkyPillar_5F_Layout::
	.4byte 0xe
	.4byte 0xe
	.4byte SkyPillar_5F_MapBorder
	.4byte SkyPillar_5F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

