	.align 2
BattleFrontier_BattlePyramidTop_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePyramidTop/border.bin"

	.align 2
BattleFrontier_BattlePyramidTop_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePyramidTop/map.bin"

	.align 2
BattleFrontier_BattlePyramidTop_Layout::
	.4byte 0x22
	.4byte 0x17
	.4byte BattleFrontier_BattlePyramidTop_MapBorder
	.4byte BattleFrontier_BattlePyramidTop_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
