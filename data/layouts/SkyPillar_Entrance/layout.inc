SkyPillar_Entrance_MapBorder::
	.incbin "data/layouts/SkyPillar_Entrance/border.bin"

SkyPillar_Entrance_MapBlockdata::
	.incbin "data/layouts/SkyPillar_Entrance/map.bin"

	.align 2
SkyPillar_Entrance_Layout::
	.4byte 0x12
	.4byte 0x12
	.4byte SkyPillar_Entrance_MapBorder
	.4byte SkyPillar_Entrance_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

