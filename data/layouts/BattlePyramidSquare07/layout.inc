BattlePyramidSquare07_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare07/border.bin"

BattlePyramidSquare07_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare07/map.bin"

	.align 2
BattlePyramidSquare07_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare07_MapBorder
	.4byte BattlePyramidSquare07_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

