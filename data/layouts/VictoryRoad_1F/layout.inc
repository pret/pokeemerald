	.align 2
VictoryRoad_1F_MapBorder::
	.incbin "data/layouts/VictoryRoad_1F/border.bin"

	.align 2
VictoryRoad_1F_MapBlockdata::
	.incbin "data/layouts/VictoryRoad_1F/map.bin"

	.align 2
VictoryRoad_1F_Layout::
	.4byte 0x2e
	.4byte 0x2d
	.4byte VictoryRoad_1F_MapBorder
	.4byte VictoryRoad_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
