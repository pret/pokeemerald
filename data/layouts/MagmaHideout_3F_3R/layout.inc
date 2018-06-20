	.align 2
MagmaHideout_3F_3R_MapBorder::
	.incbin "data/layouts/MagmaHideout_3F_3R/border.bin"

	.align 2
MagmaHideout_3F_3R_MapBlockdata::
	.incbin "data/layouts/MagmaHideout_3F_3R/map.bin"

	.align 2
MagmaHideout_3F_3R_Layout::
	.4byte 0x21
	.4byte 0x18
	.4byte MagmaHideout_3F_3R_MapBorder
	.4byte MagmaHideout_3F_3R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge
