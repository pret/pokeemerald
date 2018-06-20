UnknownMap_0843E804_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E804/border.bin"

UnknownMap_0843E804_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E804/map.bin"

	.align 2
UnknownMap_0843E804_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E804_MapBorder
	.4byte UnknownMap_0843E804_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

