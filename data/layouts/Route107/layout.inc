	.align 2
Route107_MapBorder::
	.incbin "data/layouts/Route107/border.bin"

	.align 2
Route107_MapBlockdata::
	.incbin "data/layouts/Route107/map.bin"

	.align 2
Route107_Layout::
	.4byte 0x3c
	.4byte 0x14
	.4byte Route107_MapBorder
	.4byte Route107_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Dewford
