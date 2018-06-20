	.align 2
SSTidalRooms_MapBorder::
	.incbin "data/layouts/SSTidalRooms/border.bin"

	.align 2
SSTidalRooms_MapBlockdata::
	.incbin "data/layouts/SSTidalRooms/map.bin"

	.align 2
SSTidalRooms_Layout::
	.4byte 0x24
	.4byte 0x12
	.4byte SSTidalRooms_MapBorder
	.4byte SSTidalRooms_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideShip
