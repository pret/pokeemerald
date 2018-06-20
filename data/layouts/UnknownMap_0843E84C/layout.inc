	.align 2
UnknownMap_0843E84C_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E84C/border.bin"

	.align 2
UnknownMap_0843E84C_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E84C/map.bin"

	.align 2
UnknownMap_0843E84C_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E84C_MapBorder
	.4byte UnknownMap_0843E84C_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
