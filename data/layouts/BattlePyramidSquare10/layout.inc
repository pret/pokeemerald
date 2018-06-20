BattlePyramidSquare10_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare10/border.bin"

BattlePyramidSquare10_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare10/map.bin"

	.align 2
BattlePyramidSquare10_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare10_MapBorder
	.4byte BattlePyramidSquare10_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

