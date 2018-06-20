Harbor_MapBorder::
	.incbin "data/layouts/Harbor/border.bin"

Harbor_MapBlockdata::
	.incbin "data/layouts/Harbor/map.bin"

	.align 2
Harbor_Layout::
	.4byte 0x18
	.4byte 0xf
	.4byte Harbor_MapBorder
	.4byte Harbor_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

