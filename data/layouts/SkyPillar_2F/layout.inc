SkyPillar_2F_MapBorder::
	.incbin "data/layouts/SkyPillar_2F/border.bin"

SkyPillar_2F_MapBlockdata::
	.incbin "data/layouts/SkyPillar_2F/map.bin"

	.align 2
SkyPillar_2F_Layout::
	.4byte 0xe
	.4byte 0xe
	.4byte SkyPillar_2F_MapBorder
	.4byte SkyPillar_2F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

