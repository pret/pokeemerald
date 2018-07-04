UnknownMap_0843E798_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E798/border.bin"

UnknownMap_0843E798_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E798/map.bin"

	.align 2
UnknownMap_0843E798_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E798_MapBorder
	.4byte UnknownMap_0843E798_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

