	.align 2
Route131_MapBorder::
	.incbin "data/layouts/Route131/border.bin"

	.align 2
Route131_MapBlockdata::
	.incbin "data/layouts/Route131/map.bin"

	.align 2
Route131_Layout::
	.4byte 0x3c
	.4byte 0x28
	.4byte Route131_MapBorder
	.4byte Route131_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
