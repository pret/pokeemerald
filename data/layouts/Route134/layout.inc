Route134_MapBorder::
	.incbin "data/layouts/Route134/border.bin"

Route134_MapBlockdata::
	.incbin "data/layouts/Route134/map.bin"

	.align 2
Route134_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte Route134_MapBorder
	.4byte Route134_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

