	.align 2
CaveOfOrigin_1F_MapBorder::
	.incbin "data/layouts/CaveOfOrigin_1F/border.bin"

	.align 2
CaveOfOrigin_1F_MapBlockdata::
	.incbin "data/layouts/CaveOfOrigin_1F/map.bin"

	.align 2
CaveOfOrigin_1F_Layout::
	.4byte 0x17
	.4byte 0x17
	.4byte CaveOfOrigin_1F_MapBorder
	.4byte CaveOfOrigin_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
