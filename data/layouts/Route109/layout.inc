	.align 2
Route109_MapBorder::
	.incbin "data/layouts/Route109/border.bin"

	.align 2
Route109_MapBlockdata::
	.incbin "data/layouts/Route109/map.bin"

	.align 2
Route109_Layout::
	.4byte 0x28
	.4byte 0x3f
	.4byte Route109_MapBorder
	.4byte Route109_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Slateport
