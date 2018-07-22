UnknownMap_08417FC4_MapBorder::
	.incbin "data/layouts/UnknownMap_08417FC4/border.bin"

UnknownMap_08417FC4_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08417FC4/map.bin"

	.align 2
UnknownMap_08417FC4_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte UnknownMap_08417FC4_MapBorder
	.4byte UnknownMap_08417FC4_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

