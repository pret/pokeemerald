	.align 2
Route106_MapBorder::
	.incbin "data/layouts/Route106/border.bin"

	.align 2
Route106_MapBlockdata::
	.incbin "data/layouts/Route106/map.bin"

	.align 2
Route106_Layout::
	.4byte 0x50
	.4byte 0x14
	.4byte Route106_MapBorder
	.4byte Route106_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Dewford
