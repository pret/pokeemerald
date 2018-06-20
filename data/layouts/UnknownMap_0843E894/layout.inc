UnknownMap_0843E894_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E894/border.bin"

UnknownMap_0843E894_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E894/map.bin"

	.align 2
UnknownMap_0843E894_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E894_MapBorder
	.4byte UnknownMap_0843E894_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

