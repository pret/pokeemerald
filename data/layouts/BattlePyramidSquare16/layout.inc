	.align 2
BattlePyramidSquare16_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare16/border.bin"

	.align 2
BattlePyramidSquare16_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare16/map.bin"

	.align 2
BattlePyramidSquare16_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare16_MapBorder
	.4byte BattlePyramidSquare16_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
