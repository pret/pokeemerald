UnknownMap_25_33_MapBorder::
	.incbin "data/layouts/UnknownMap_25_33/border.bin"

UnknownMap_25_33_MapBlockdata::
	.incbin "data/layouts/UnknownMap_25_33/map.bin"

	.align 2
UnknownMap_25_33_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_25_33_MapBorder
	.4byte UnknownMap_25_33_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest

