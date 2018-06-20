	.align 2
UnknownMap_08428450_MapBorder::
	.incbin "data/layouts/UnknownMap_08428450/border.bin"

	.align 2
UnknownMap_08428450_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08428450/map.bin"

	.align 2
UnknownMap_08428450_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_08428450_MapBorder
	.4byte UnknownMap_08428450_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest
