Route105_MapBorder::
	.incbin "data/layouts/Route105/border.bin"

Route105_MapBlockdata::
	.incbin "data/layouts/Route105/map.bin"

	.align 2
Route105_Layout::
	.4byte 0x28
	.4byte 0x50
	.4byte Route105_MapBorder
	.4byte Route105_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Dewford

