	.align 2
Route113_MapBorder::
	.incbin "data/layouts/Route113/border.bin"

	.align 2
Route113_MapBlockdata::
	.incbin "data/layouts/Route113/map.bin"

	.align 2
Route113_Layout::
	.4byte 0x64
	.4byte 0x14
	.4byte Route113_MapBorder
	.4byte Route113_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Fallarbor
