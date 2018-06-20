	.align 2
UnknownMap_08447028_MapBorder::
	.incbin "data/layouts/UnknownMap_08447028/border.bin"

	.align 2
UnknownMap_08447028_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08447028/map.bin"

	.align 2
UnknownMap_08447028_Layout::
	.4byte 0x3A
	.4byte 0x1A
	.4byte UnknownMap_08447028_MapBorder
	.4byte UnknownMap_08447028_MapBlockdata
	.4byte gTileset_General
	.4byte 0
