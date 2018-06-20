	.align 2
AbandonedShip_CaptainsOffice_MapBorder::
	.incbin "data/layouts/AbandonedShip_CaptainsOffice/border.bin"

	.align 2
AbandonedShip_CaptainsOffice_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_CaptainsOffice/map.bin"

	.align 2
AbandonedShip_CaptainsOffice_Layout::
	.4byte 0x9
	.4byte 0x7
	.4byte AbandonedShip_CaptainsOffice_MapBorder
	.4byte AbandonedShip_CaptainsOffice_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
