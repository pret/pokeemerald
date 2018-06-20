BattlePyramidSquare14_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare14/border.bin"

BattlePyramidSquare14_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare14/map.bin"

	.align 2
BattlePyramidSquare14_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare14_MapBorder
	.4byte BattlePyramidSquare14_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

