SkyPillar_1F_MapBorder::
	.incbin "data/layouts/SkyPillar_1F/border.bin"

SkyPillar_1F_MapBlockdata::
	.incbin "data/layouts/SkyPillar_1F/map.bin"

	.align 2
SkyPillar_1F_Layout::
	.4byte 0xe
	.4byte 0xe
	.4byte SkyPillar_1F_MapBorder
	.4byte SkyPillar_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

