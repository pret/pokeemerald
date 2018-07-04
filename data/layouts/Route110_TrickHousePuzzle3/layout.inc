Route110_TrickHousePuzzle3_MapBorder::
	.incbin "data/layouts/Route110_TrickHousePuzzle3/border.bin"

Route110_TrickHousePuzzle3_MapBlockdata::
	.incbin "data/layouts/Route110_TrickHousePuzzle3/map.bin"

	.align 2
Route110_TrickHousePuzzle3_Layout::
	.4byte 0xf
	.4byte 0x16
	.4byte Route110_TrickHousePuzzle3_MapBorder
	.4byte Route110_TrickHousePuzzle3_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrickHousePuzzle

