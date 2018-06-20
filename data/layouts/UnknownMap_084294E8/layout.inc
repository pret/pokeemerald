	.align 2
UnknownMap_084294E8_MapBorder::
	.incbin "data/layouts/UnknownMap_084294E8/border.bin"

	.align 2
UnknownMap_084294E8_MapBlockdata::
	.incbin "data/layouts/UnknownMap_084294E8/map.bin"

	.align 2
UnknownMap_084294E8_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_084294E8_MapBorder
	.4byte UnknownMap_084294E8_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest
