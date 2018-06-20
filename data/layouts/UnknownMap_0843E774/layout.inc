UnknownMap_0843E774_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E774/border.bin"

UnknownMap_0843E774_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E774/map.bin"

	.align 2
UnknownMap_0843E774_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E774_MapBorder
	.4byte UnknownMap_0843E774_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

