Route126_MapBorder::
	.incbin "data/layouts/Route126/border.bin"

Route126_MapBlockdata::
	.incbin "data/layouts/Route126/map.bin"

	.align 2
Route126_Layout::
	.4byte 0x50
	.4byte 0x50
	.4byte Route126_MapBorder
	.4byte Route126_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mossdeep

