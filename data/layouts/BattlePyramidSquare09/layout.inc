BattlePyramidSquare09_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare09/border.bin"

BattlePyramidSquare09_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare09/map.bin"

	.align 2
BattlePyramidSquare09_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare09_MapBorder
	.4byte BattlePyramidSquare09_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

