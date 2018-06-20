Route119_MapBorder::
	.incbin "data/layouts/Route119/border.bin"

Route119_MapBlockdata::
	.incbin "data/layouts/Route119/map.bin"

	.align 2
Route119_Layout::
	.4byte 0x28
	.4byte 0x8c
	.4byte Route119_MapBorder
	.4byte Route119_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Fortree

