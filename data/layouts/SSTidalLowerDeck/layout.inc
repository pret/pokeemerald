	.align 2
SSTidalLowerDeck_MapBorder::
	.incbin "data/layouts/SSTidalLowerDeck/border.bin"

	.align 2
SSTidalLowerDeck_MapBlockdata::
	.incbin "data/layouts/SSTidalLowerDeck/map.bin"

	.align 2
SSTidalLowerDeck_Layout::
	.4byte 0x11
	.4byte 0xd
	.4byte SSTidalLowerDeck_MapBorder
	.4byte SSTidalLowerDeck_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip
