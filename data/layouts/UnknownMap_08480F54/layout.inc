	.align 2
UnknownMap_08480F54_MapBorder::
	.incbin "data/layouts/UnknownMap_08480F54/border.bin"

	.align 2
UnknownMap_08480F54_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08480F54/map.bin"

	.align 2
UnknownMap_08480F54_Layout::
	.4byte 0xE
	.4byte 0xE
	.4byte UnknownMap_08480F54_MapBorder
	.4byte UnknownMap_08480F54_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
