UnknownMap_0843E6E4_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E6E4/border.bin"

UnknownMap_0843E6E4_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E6E4/map.bin"

	.align 2
UnknownMap_0843E6E4_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E6E4_MapBorder
	.4byte UnknownMap_0843E6E4_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

