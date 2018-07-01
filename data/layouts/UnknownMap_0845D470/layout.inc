UnknownMap_0845D470_MapBorder::
	.incbin "data/layouts/UnknownMap_0845D470/border.bin"

UnknownMap_0845D470_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0845D470/map.bin"

	.align 2
UnknownMap_0845D470_Layout::
	.4byte 0x3C
	.4byte 0x28
	.4byte UnknownMap_0845D470_MapBorder
	.4byte UnknownMap_0845D470_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

