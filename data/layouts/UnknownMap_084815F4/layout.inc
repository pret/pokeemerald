	.align 2
UnknownMap_084815F4_MapBorder::
	.incbin "data/layouts/UnknownMap_084815F4/border.bin"

	.align 2
UnknownMap_084815F4_MapBlockdata::
	.incbin "data/layouts/UnknownMap_084815F4/map.bin"

	.align 2
UnknownMap_084815F4_Layout::
	.4byte 0xE
	.4byte 0xE
	.4byte UnknownMap_084815F4_MapBorder
	.4byte UnknownMap_084815F4_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
