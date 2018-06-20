	.align 2
Route110_TrickHousePuzzle1_MapBorder::
	.incbin "data/layouts/Route110_TrickHousePuzzle1/border.bin"

	.align 2
Route110_TrickHousePuzzle1_MapBlockdata::
	.incbin "data/layouts/Route110_TrickHousePuzzle1/map.bin"

	.align 2
Route110_TrickHousePuzzle1_Layout::
	.4byte 0xf
	.4byte 0x16
	.4byte Route110_TrickHousePuzzle1_MapBorder
	.4byte Route110_TrickHousePuzzle1_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrickHousePuzzle
