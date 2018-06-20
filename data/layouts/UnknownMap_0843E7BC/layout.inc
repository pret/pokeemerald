	.align 2
UnknownMap_0843E7BC_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E7BC/border.bin"

	.align 2
UnknownMap_0843E7BC_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E7BC/map.bin"

	.align 2
UnknownMap_0843E7BC_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E7BC_MapBorder
	.4byte UnknownMap_0843E7BC_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
