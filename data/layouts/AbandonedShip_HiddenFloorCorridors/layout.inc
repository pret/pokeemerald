	.align 2
AbandonedShip_HiddenFloorCorridors_MapBorder::
	.incbin "data/layouts/AbandonedShip_HiddenFloorCorridors/border.bin"

	.align 2
AbandonedShip_HiddenFloorCorridors_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_HiddenFloorCorridors/map.bin"

	.align 2
AbandonedShip_HiddenFloorCorridors_Layout::
	.4byte 0xd
	.4byte 0xb
	.4byte AbandonedShip_HiddenFloorCorridors_MapBorder
	.4byte AbandonedShip_HiddenFloorCorridors_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip
