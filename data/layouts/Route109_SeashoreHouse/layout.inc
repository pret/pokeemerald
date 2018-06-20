	.align 2
Route109_SeashoreHouse_MapBorder::
	.incbin "data/layouts/Route109_SeashoreHouse/border.bin"

	.align 2
Route109_SeashoreHouse_MapBlockdata::
	.incbin "data/layouts/Route109_SeashoreHouse/map.bin"

	.align 2
Route109_SeashoreHouse_Layout::
	.4byte 0xf
	.4byte 0xa
	.4byte Route109_SeashoreHouse_MapBorder
	.4byte Route109_SeashoreHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_SeashoreHouse
