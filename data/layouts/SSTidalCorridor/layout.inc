SSTidalCorridor_MapBorder::
	.incbin "data/layouts/SSTidalCorridor/border.bin"

SSTidalCorridor_MapBlockdata::
	.incbin "data/layouts/SSTidalCorridor/map.bin"

	.align 2
SSTidalCorridor_Layout::
	.4byte 0x12
	.4byte 0xd
	.4byte SSTidalCorridor_MapBorder
	.4byte SSTidalCorridor_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip

