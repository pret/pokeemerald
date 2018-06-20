	.align 2
UnknownMap_0845ECB4_MapBorder::
	.incbin "data/layouts/UnknownMap_0845ECB4/border.bin"

	.align 2
UnknownMap_0845ECB4_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0845ECB4/map.bin"

	.align 2
UnknownMap_0845ECB4_Layout::
	.4byte 0x1B
	.4byte 0x2E
	.4byte UnknownMap_0845ECB4_MapBorder
	.4byte UnknownMap_0845ECB4_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
