MagmaHideout_2F_2R_MapBorder::
	.incbin "data/layouts/MagmaHideout_2F_2R/border.bin"

MagmaHideout_2F_2R_MapBlockdata::
	.incbin "data/layouts/MagmaHideout_2F_2R/map.bin"

	.align 2
MagmaHideout_2F_2R_Layout::
	.4byte 0x31
	.4byte 0x1c
	.4byte MagmaHideout_2F_2R_MapBorder
	.4byte MagmaHideout_2F_2R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge

