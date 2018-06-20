UnknownMap_0848144C_MapBorder::
	.incbin "data/layouts/UnknownMap_0848144C/border.bin"

UnknownMap_0848144C_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0848144C/map.bin"

	.align 2
UnknownMap_0848144C_Layout::
	.4byte 0xE
	.4byte 0xE
	.4byte UnknownMap_0848144C_MapBorder
	.4byte UnknownMap_0848144C_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

