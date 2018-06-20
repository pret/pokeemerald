	.align 2
BattlePyramidSquare06_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare06/border.bin"

	.align 2
BattlePyramidSquare06_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare06/map.bin"

	.align 2
BattlePyramidSquare06_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare06_MapBorder
	.4byte BattlePyramidSquare06_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
