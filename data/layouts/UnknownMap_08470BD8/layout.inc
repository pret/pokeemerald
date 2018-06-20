UnknownMap_08470BD8_MapBorder::
	.incbin "data/layouts/UnknownMap_08470BD8/border.bin"

UnknownMap_08470BD8_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08470BD8/map.bin"

	.align 2
UnknownMap_08470BD8_Layout::
	.4byte 0x28
	.4byte 0x8C
	.4byte UnknownMap_08470BD8_MapBorder
	.4byte UnknownMap_08470BD8_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mauville

