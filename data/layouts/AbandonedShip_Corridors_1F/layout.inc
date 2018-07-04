AbandonedShip_Corridors_1F_MapBorder::
	.incbin "data/layouts/AbandonedShip_Corridors_1F/border.bin"

AbandonedShip_Corridors_1F_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_Corridors_1F/map.bin"

	.align 2
AbandonedShip_Corridors_1F_Layout::
	.4byte 0x12
	.4byte 0xc
	.4byte AbandonedShip_Corridors_1F_MapBorder
	.4byte AbandonedShip_Corridors_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip

