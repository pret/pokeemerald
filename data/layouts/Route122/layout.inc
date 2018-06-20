	.align 2
Route122_MapBorder::
	.incbin "data/layouts/Route122/border.bin"

	.align 2
Route122_MapBlockdata::
	.incbin "data/layouts/Route122/map.bin"

	.align 2
Route122_Layout::
	.4byte 0x28
	.4byte 0x28
	.4byte Route122_MapBorder
	.4byte Route122_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lilycove
