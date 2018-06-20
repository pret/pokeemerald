	.align 2
Route132_MapBorder::
	.incbin "data/layouts/Route132/border.bin"

	.align 2
Route132_MapBlockdata::
	.incbin "data/layouts/Route132/map.bin"

	.align 2
Route132_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte Route132_MapBorder
	.4byte Route132_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog
