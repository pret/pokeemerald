UnknownMap_0843E708_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E708/border.bin"

UnknownMap_0843E708_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E708/map.bin"

	.align 2
UnknownMap_0843E708_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E708_MapBorder
	.4byte UnknownMap_0843E708_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

