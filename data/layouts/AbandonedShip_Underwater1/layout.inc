AbandonedShip_Underwater1_MapBorder::
	.incbin "data/layouts/AbandonedShip_Underwater1/border.bin"

AbandonedShip_Underwater1_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_Underwater1/map.bin"

	.align 2
AbandonedShip_Underwater1_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte AbandonedShip_Underwater1_MapBorder
	.4byte AbandonedShip_Underwater1_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip

