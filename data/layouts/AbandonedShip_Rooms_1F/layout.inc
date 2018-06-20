	.align 2
AbandonedShip_Rooms_1F_MapBorder::
	.incbin "data/layouts/AbandonedShip_Rooms_1F/border.bin"

	.align 2
AbandonedShip_Rooms_1F_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_Rooms_1F/map.bin"

	.align 2
AbandonedShip_Rooms_1F_Layout::
	.4byte 0x12
	.4byte 0x11
	.4byte AbandonedShip_Rooms_1F_MapBorder
	.4byte AbandonedShip_Rooms_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip
