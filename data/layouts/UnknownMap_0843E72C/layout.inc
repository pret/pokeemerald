UnknownMap_0843E72C_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E72C/border.bin"

UnknownMap_0843E72C_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E72C/map.bin"

	.align 2
UnknownMap_0843E72C_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E72C_MapBorder
	.4byte UnknownMap_0843E72C_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

