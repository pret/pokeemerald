BattlePyramidSquare02_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare02/border.bin"

BattlePyramidSquare02_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare02/map.bin"

	.align 2
BattlePyramidSquare02_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare02_MapBorder
	.4byte BattlePyramidSquare02_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

