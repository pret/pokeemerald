Route108_MapBorder::
	.incbin "data/layouts/Route108/border.bin"

Route108_MapBlockdata::
	.incbin "data/layouts/Route108/map.bin"

	.align 2
Route108_Layout::
	.4byte 0x3c
	.4byte 0x14
	.4byte Route108_MapBorder
	.4byte Route108_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Slateport

