MagmaHideout_3F_2R_MapBorder::
	.incbin "data/layouts/MagmaHideout_3F_2R/border.bin"

MagmaHideout_3F_2R_MapBlockdata::
	.incbin "data/layouts/MagmaHideout_3F_2R/map.bin"

	.align 2
MagmaHideout_3F_2R_Layout::
	.4byte 0x18
	.4byte 0x11
	.4byte MagmaHideout_3F_2R_MapBorder
	.4byte MagmaHideout_3F_2R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge

