UnknownMap_25_29_MapBorder::
	.incbin "data/layouts/UnknownMap_25_29/border.bin"

UnknownMap_25_29_MapBlockdata::
	.incbin "data/layouts/UnknownMap_25_29/map.bin"

	.align 2
UnknownMap_25_29_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_25_29_MapBorder
	.4byte UnknownMap_25_29_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest

