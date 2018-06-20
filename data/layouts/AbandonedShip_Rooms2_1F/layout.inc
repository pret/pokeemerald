AbandonedShip_Rooms2_1F_MapBorder::
	.incbin "data/layouts/AbandonedShip_Rooms2_1F/border.bin"

AbandonedShip_Rooms2_1F_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_Rooms2_1F/map.bin"

	.align 2
AbandonedShip_Rooms2_1F_Layout::
	.4byte 0x9
	.4byte 0x11
	.4byte AbandonedShip_Rooms2_1F_MapBorder
	.4byte AbandonedShip_Rooms2_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip

