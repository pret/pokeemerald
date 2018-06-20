	.align 2
UnknownMap_0843E750_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E750/border.bin"

	.align 2
UnknownMap_0843E750_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E750/map.bin"

	.align 2
UnknownMap_0843E750_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E750_MapBorder
	.4byte UnknownMap_0843E750_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
