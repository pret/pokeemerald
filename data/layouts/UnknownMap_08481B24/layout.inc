UnknownMap_08481B24_MapBorder::
	.incbin "data/layouts/UnknownMap_08481B24/border.bin"

UnknownMap_08481B24_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08481B24/map.bin"

	.align 2
UnknownMap_08481B24_Layout::
	.4byte 0x1B
	.4byte 0x18
	.4byte UnknownMap_08481B24_MapBorder
	.4byte UnknownMap_08481B24_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

