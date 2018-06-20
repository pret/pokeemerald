	.align 2
UnknownMap_084294C4_MapBorder::
	.incbin "data/layouts/UnknownMap_084294C4/border.bin"

	.align 2
UnknownMap_084294C4_MapBlockdata::
	.incbin "data/layouts/UnknownMap_084294C4/map.bin"

	.align 2
UnknownMap_084294C4_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_084294C4_MapBorder
	.4byte UnknownMap_084294C4_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest
