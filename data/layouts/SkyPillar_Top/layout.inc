	.align 2
SkyPillar_Top_MapBorder::
	.incbin "data/layouts/SkyPillar_Top/border.bin"

	.align 2
SkyPillar_Top_MapBlockdata::
	.incbin "data/layouts/SkyPillar_Top/map.bin"

	.align 2
SkyPillar_Top_Layout::
	.4byte 0x1b
	.4byte 0x18
	.4byte SkyPillar_Top_MapBorder
	.4byte SkyPillar_Top_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
