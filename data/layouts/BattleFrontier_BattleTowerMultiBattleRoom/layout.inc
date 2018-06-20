BattleFrontier_BattleTowerMultiBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleTowerMultiBattleRoom/border.bin"

BattleFrontier_BattleTowerMultiBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleTowerMultiBattleRoom/map.bin"

	.align 2
BattleFrontier_BattleTowerMultiBattleRoom_Layout::
	.4byte 0x15
	.4byte 0xf
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_MapBorder
	.4byte BattleFrontier_BattleTowerMultiBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier

