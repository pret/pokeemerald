	.align 2
Route104_Prototype_MapBorder::
	.incbin "data/layouts/Route104_Prototype/border.bin"

	.align 2
Route104_Prototype_MapBlockdata::
	.incbin "data/layouts/Route104_Prototype/map.bin"

	.align 2
Route104_Prototype_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte Route104_Prototype_MapBorder
	.4byte Route104_Prototype_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Rustboro
