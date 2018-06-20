	.align 2
UnknownMap_0843E7E0_MapBorder::
	.incbin "data/layouts/UnknownMap_0843E7E0/border.bin"

	.align 2
UnknownMap_0843E7E0_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0843E7E0/map.bin"

	.align 2
UnknownMap_0843E7E0_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_0843E7E0_MapBorder
	.4byte UnknownMap_0843E7E0_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
