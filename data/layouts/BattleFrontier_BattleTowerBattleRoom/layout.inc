	.align 2
BattleFrontier_BattleTowerBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleTowerBattleRoom/border.bin"

	.align 2
BattleFrontier_BattleTowerBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleTowerBattleRoom/map.bin"

	.align 2
BattleFrontier_BattleTowerBattleRoom_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte BattleFrontier_BattleTowerBattleRoom_MapBorder
	.4byte BattleFrontier_BattleTowerBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier
