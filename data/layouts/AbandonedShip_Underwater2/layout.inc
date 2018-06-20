	.align 2
AbandonedShip_Underwater2_MapBorder::
	.incbin "data/layouts/AbandonedShip_Underwater2/border.bin"

	.align 2
AbandonedShip_Underwater2_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_Underwater2/map.bin"

	.align 2
AbandonedShip_Underwater2_Layout::
	.4byte 0x15
	.4byte 0x7
	.4byte AbandonedShip_Underwater2_MapBorder
	.4byte AbandonedShip_Underwater2_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip
