AbandonedShip_HiddenFloorRooms_MapBorder::
	.incbin "data/layouts/AbandonedShip_HiddenFloorRooms/border.bin"

AbandonedShip_HiddenFloorRooms_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_HiddenFloorRooms/map.bin"

	.align 2
AbandonedShip_HiddenFloorRooms_Layout::
	.4byte 0x2c
	.4byte 0xf
	.4byte AbandonedShip_HiddenFloorRooms_MapBorder
	.4byte AbandonedShip_HiddenFloorRooms_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip

