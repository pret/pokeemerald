BattlePyramidSquare13_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare13/border.bin"

BattlePyramidSquare13_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare13/map.bin"

	.align 2
BattlePyramidSquare13_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare13_MapBorder
	.4byte BattlePyramidSquare13_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

