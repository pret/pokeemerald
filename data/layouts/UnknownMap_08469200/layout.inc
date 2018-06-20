	.align 2
UnknownMap_08469200_MapBorder::
	.incbin "data/layouts/UnknownMap_08469200/border.bin"

	.align 2
UnknownMap_08469200_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08469200/map.bin"

	.align 2
UnknownMap_08469200_Layout::
	.4byte 0x3C
	.4byte 0x3C
	.4byte UnknownMap_08469200_MapBorder
	.4byte UnknownMap_08469200_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Sootopolis
