Route112_MapBorder::
	.incbin "data/layouts/Route112/border.bin"

Route112_MapBlockdata::
	.incbin "data/layouts/Route112/map.bin"

	.align 2
Route112_Layout::
	.4byte 0x28
	.4byte 0x3c
	.4byte Route112_MapBorder
	.4byte Route112_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge

