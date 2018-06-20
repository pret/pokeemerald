	.align 2
Route110_TrickHousePuzzle2_MapBorder::
	.incbin "data/layouts/Route110_TrickHousePuzzle2/border.bin"

	.align 2
Route110_TrickHousePuzzle2_MapBlockdata::
	.incbin "data/layouts/Route110_TrickHousePuzzle2/map.bin"

	.align 2
Route110_TrickHousePuzzle2_Layout::
	.4byte 0xf
	.4byte 0x16
	.4byte Route110_TrickHousePuzzle2_MapBorder
	.4byte Route110_TrickHousePuzzle2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrickHousePuzzle
