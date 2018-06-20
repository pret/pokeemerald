BattlePyramidSquare03_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare03/border.bin"

BattlePyramidSquare03_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare03/map.bin"

	.align 2
BattlePyramidSquare03_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare03_MapBorder
	.4byte BattlePyramidSquare03_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

