	.align 2
BattlePyramidSquare04_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare04/border.bin"

	.align 2
BattlePyramidSquare04_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare04/map.bin"

	.align 2
BattlePyramidSquare04_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare04_MapBorder
	.4byte BattlePyramidSquare04_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
