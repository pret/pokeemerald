AbandonedShip_Rooms2_B1F_MapBorder::
	.incbin "data/layouts/AbandonedShip_Rooms2_B1F/border.bin"

AbandonedShip_Rooms2_B1F_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_Rooms2_B1F/map.bin"

	.align 2
AbandonedShip_Rooms2_B1F_Layout::
	.4byte 0x12
	.4byte 0x8
	.4byte AbandonedShip_Rooms2_B1F_MapBorder
	.4byte AbandonedShip_Rooms2_B1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip

