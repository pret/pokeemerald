	.align 2
Route110_TrickHousePuzzle6_MapBorder::
	.incbin "data/layouts/Route110_TrickHousePuzzle6/border.bin"

	.align 2
Route110_TrickHousePuzzle6_MapBlockdata::
	.incbin "data/layouts/Route110_TrickHousePuzzle6/map.bin"

	.align 2
Route110_TrickHousePuzzle6_Layout::
	.4byte 0xf
	.4byte 0x16
	.4byte Route110_TrickHousePuzzle6_MapBorder
	.4byte Route110_TrickHousePuzzle6_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrickHousePuzzle
