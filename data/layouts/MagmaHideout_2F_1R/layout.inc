MagmaHideout_2F_1R_MapBorder::
	.incbin "data/layouts/MagmaHideout_2F_1R/border.bin"

MagmaHideout_2F_1R_MapBlockdata::
	.incbin "data/layouts/MagmaHideout_2F_1R/map.bin"

	.align 2
MagmaHideout_2F_1R_Layout::
	.4byte 0x21
	.4byte 0x27
	.4byte MagmaHideout_2F_1R_MapBorder
	.4byte MagmaHideout_2F_1R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge

