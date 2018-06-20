	.align 2
BattlePyramidSquare15_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare15/border.bin"

	.align 2
BattlePyramidSquare15_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare15/map.bin"

	.align 2
BattlePyramidSquare15_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare15_MapBorder
	.4byte BattlePyramidSquare15_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
