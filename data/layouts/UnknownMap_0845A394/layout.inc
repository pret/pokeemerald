UnknownMap_0845A394_MapBorder::
	.incbin "data/layouts/UnknownMap_0845A394/border.bin"

UnknownMap_0845A394_MapBlockdata::
	.incbin "data/layouts/UnknownMap_0845A394/map.bin"

	.align 2
UnknownMap_0845A394_Layout::
	.4byte 0x13
	.4byte 0x13
	.4byte UnknownMap_0845A394_MapBorder
	.4byte UnknownMap_0845A394_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

