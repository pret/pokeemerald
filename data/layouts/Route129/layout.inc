Route129_MapBorder::
	.incbin "data/layouts/Route129/border.bin"

Route129_MapBlockdata::
	.incbin "data/layouts/Route129/map.bin"

	.align 2
Route129_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte Route129_MapBorder
	.4byte Route129_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mossdeep

