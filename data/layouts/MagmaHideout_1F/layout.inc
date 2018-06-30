MagmaHideout_1F_MapBorder::
	.incbin "data/layouts/MagmaHideout_1F/border.bin"

MagmaHideout_1F_MapBlockdata::
	.incbin "data/layouts/MagmaHideout_1F/map.bin"

	.align 2
MagmaHideout_1F_Layout::
	.4byte 0x25
	.4byte 0x26
	.4byte MagmaHideout_1F_MapBorder
	.4byte MagmaHideout_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge

