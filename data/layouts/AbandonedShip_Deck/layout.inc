AbandonedShip_Deck_MapBorder::
	.incbin "data/layouts/AbandonedShip_Deck/border.bin"

AbandonedShip_Deck_MapBlockdata::
	.incbin "data/layouts/AbandonedShip_Deck/map.bin"

	.align 2
AbandonedShip_Deck_Layout::
	.4byte 0x17
	.4byte 0x15
	.4byte AbandonedShip_Deck_MapBorder
	.4byte AbandonedShip_Deck_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

