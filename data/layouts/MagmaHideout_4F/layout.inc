	.align 2
MagmaHideout_4F_MapBorder::
	.incbin "data/layouts/MagmaHideout_4F/border.bin"

	.align 2
MagmaHideout_4F_MapBlockdata::
	.incbin "data/layouts/MagmaHideout_4F/map.bin"

	.align 2
MagmaHideout_4F_Layout::
	.4byte 0x3b
	.4byte 0x1c
	.4byte MagmaHideout_4F_MapBorder
	.4byte MagmaHideout_4F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge
