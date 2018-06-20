BattleFrontier_BattleTowerCorridor2_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleTowerCorridor2/border.bin"

BattleFrontier_BattleTowerCorridor2_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleTowerCorridor2/map.bin"

	.align 2
BattleFrontier_BattleTowerCorridor2_Layout::
	.4byte 0x11
	.4byte 0x5
	.4byte BattleFrontier_BattleTowerCorridor2_MapBorder
	.4byte BattleFrontier_BattleTowerCorridor2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier

