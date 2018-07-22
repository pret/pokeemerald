BattleFrontier_BattleTowerCorridor_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleTowerCorridor/border.bin"

BattleFrontier_BattleTowerCorridor_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleTowerCorridor/map.bin"

	.align 2
BattleFrontier_BattleTowerCorridor_Layout::
	.4byte 0x11
	.4byte 0x5
	.4byte BattleFrontier_BattleTowerCorridor_MapBorder
	.4byte BattleFrontier_BattleTowerCorridor_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier

