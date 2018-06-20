	.align 2
MagmaHideout_3F_1R_MapBorder::
	.incbin "data/layouts/MagmaHideout_3F_1R/border.bin"

	.align 2
MagmaHideout_3F_1R_MapBlockdata::
	.incbin "data/layouts/MagmaHideout_3F_1R/map.bin"

	.align 2
MagmaHideout_3F_1R_Layout::
	.4byte 0x1c
	.4byte 0x18
	.4byte MagmaHideout_3F_1R_MapBorder
	.4byte MagmaHideout_3F_1R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge
