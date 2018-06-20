UnknownMap_25_32_MapBorder::
	.incbin "data/layouts/UnknownMap_25_32/border.bin"

UnknownMap_25_32_MapBlockdata::
	.incbin "data/layouts/UnknownMap_25_32/map.bin"

	.align 2
UnknownMap_25_32_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_25_32_MapBorder
	.4byte UnknownMap_25_32_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest

