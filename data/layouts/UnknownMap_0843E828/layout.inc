	.align 2
UnknownMap_0843E828_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E828/border.bin"

	.align 2
UnknownMap_0843E828_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E828/map.bin"

	.align 2
UnknownMap_0843E828_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E828_MapBorder
	.4byte UnknownMap_0843E828_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
