Route114_MapBorder::
	.incbin "data/layouts/Route114/border.bin"

Route114_MapBlockdata::
	.incbin "data/layouts/Route114/map.bin"

	.align 2
Route114_Layout::
	.4byte 0x28
	.4byte 0x50
	.4byte Route114_MapBorder
	.4byte Route114_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Fallarbor

