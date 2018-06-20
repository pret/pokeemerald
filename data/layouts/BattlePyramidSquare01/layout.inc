	.align 2
BattlePyramidSquare01_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare01/border.bin"

	.align 2
BattlePyramidSquare01_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare01/map.bin"

	.align 2
BattlePyramidSquare01_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare01_MapBorder
	.4byte BattlePyramidSquare01_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
