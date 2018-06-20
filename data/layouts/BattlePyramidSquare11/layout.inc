	.align 2
BattlePyramidSquare11_MapBorder::
	.incbin "data/layouts/BattlePyramidSquare11/border.bin"

	.align 2
BattlePyramidSquare11_MapBlockdata::
	.incbin "data/layouts/BattlePyramidSquare11/map.bin"

	.align 2
BattlePyramidSquare11_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte BattlePyramidSquare11_MapBorder
	.4byte BattlePyramidSquare11_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
