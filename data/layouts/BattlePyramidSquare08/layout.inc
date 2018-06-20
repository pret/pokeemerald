	.align 2
BattlePyramidSquare08_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare08/border.bin"

	.align 2
BattlePyramidSquare08_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare08/map.bin"

	.align 2
BattlePyramidSquare08_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare08_MapBorder
	.4byte BattlePyramidSquare08_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
