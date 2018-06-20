	.align 2
Route124_MapBorder::
	.incbin "data/layouts/Route124/border.bin"

	.align 2
Route124_MapBlockdata::
	.incbin "data/layouts/Route124/map.bin"

	.align 2
Route124_Layout::
	.4byte 0x50
	.4byte 0x50
	.4byte Route124_MapBorder
	.4byte Route124_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mossdeep
