UnknownMap_084810FC_MapBorder::
	.incbin "data/layouts/UnknownMap_084810FC/border.bin"

UnknownMap_084810FC_MapBlockdata::
	.incbin "data/layouts/UnknownMap_084810FC/map.bin"

	.align 2
UnknownMap_084810FC_Layout::
	.4byte 0xE
	.4byte 0xE
	.4byte UnknownMap_084810FC_MapBorder
	.4byte UnknownMap_084810FC_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

