Route110_MapBorder::
	.incbin "data/layouts/Route110/border.bin"

Route110_MapBlockdata::
	.incbin "data/layouts/Route110/map.bin"

	.align 2
Route110_Layout::
	.4byte 0x28
	.4byte 0x64
	.4byte Route110_MapBorder
	.4byte Route110_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mauville

