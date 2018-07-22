BattlePyramidSquare05_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare05/border.bin"

BattlePyramidSquare05_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare05/map.bin"

	.align 2
BattlePyramidSquare05_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare05_MapBorder
	.4byte BattlePyramidSquare05_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

