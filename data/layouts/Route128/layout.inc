Route128_MapBorder::
	.incbin "data/layouts/Route128/border.bin"

Route128_MapBlockdata::
	.incbin "data/layouts/Route128/map.bin"

	.align 2
Route128_Layout::
	.4byte 0x78
	.4byte 0x28
	.4byte Route128_MapBorder
	.4byte Route128_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mossdeep

