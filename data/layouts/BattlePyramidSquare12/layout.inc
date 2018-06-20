	.align 2
BattlePyramidSquare12_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare12/border.bin"

	.align 2
BattlePyramidSquare12_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare12/map.bin"

	.align 2
BattlePyramidSquare12_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare12_MapBorder
	.4byte BattlePyramidSquare12_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
