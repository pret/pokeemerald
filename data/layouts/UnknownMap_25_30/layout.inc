UnknownMap_25_30_MapBorder::
	.incbin "data/layouts/UnknownMap_25_30/border.bin"

UnknownMap_25_30_MapBlockdata::
	.incbin "data/layouts/UnknownMap_25_30/map.bin"

	.align 2
UnknownMap_25_30_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_25_30_MapBorder
	.4byte UnknownMap_25_30_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest

