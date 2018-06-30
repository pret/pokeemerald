CaveOfOrigin_B1F_MapBorder::
	.incbin "data/layouts/CaveOfOrigin_B1F/border.bin"

CaveOfOrigin_B1F_MapBlockdata::
	.incbin "data/layouts/CaveOfOrigin_B1F/map.bin"

	.align 2
CaveOfOrigin_B1F_Layout::
	.4byte 0x13
	.4byte 0x13
	.4byte CaveOfOrigin_B1F_MapBorder
	.4byte CaveOfOrigin_B1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

