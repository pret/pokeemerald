	.align 2
Route127_MapBorder::
	.incbin "data/layouts/Route127/border.bin"

	.align 2
Route127_MapBlockdata::
	.incbin "data/layouts/Route127/map.bin"

	.align 2
Route127_Layout::
	.4byte 0x50
	.4byte 0x50
	.4byte Route127_MapBorder
	.4byte Route127_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mossdeep
