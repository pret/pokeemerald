Route101_MapBorder::
	.incbin "data/layouts/Route101/border.bin"

Route101_MapBlockdata::
	.incbin "data/layouts/Route101/map.bin"

	.align 2
Route101_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte Route101_MapBorder
	.4byte Route101_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Petalburg

