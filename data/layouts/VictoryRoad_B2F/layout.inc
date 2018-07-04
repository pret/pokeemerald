VictoryRoad_B2F_MapBorder::
	.incbin "data/layouts/VictoryRoad_B2F/border.bin"

VictoryRoad_B2F_MapBlockdata::
	.incbin "data/layouts/VictoryRoad_B2F/map.bin"

	.align 2
VictoryRoad_B2F_Layout::
	.4byte 0x2e
	.4byte 0x1f
	.4byte VictoryRoad_B2F_MapBorder
	.4byte VictoryRoad_B2F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

