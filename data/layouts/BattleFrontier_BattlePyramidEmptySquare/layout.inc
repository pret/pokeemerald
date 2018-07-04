BattleFrontier_BattlePyramidEmptySquare_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePyramidEmptySquare/border.bin"

BattleFrontier_BattlePyramidEmptySquare_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePyramidEmptySquare/map.bin"

	.align 2
BattleFrontier_BattlePyramidEmptySquare_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattleFrontier_BattlePyramidEmptySquare_MapBorder
	.4byte BattleFrontier_BattlePyramidEmptySquare_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid

