UnknownMap_0843E870_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E870/border.bin"

UnknownMap_0843E870_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E870/map.bin"

	.align 2
UnknownMap_0843E870_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E870_MapBorder
	.4byte UnknownMap_0843E870_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

