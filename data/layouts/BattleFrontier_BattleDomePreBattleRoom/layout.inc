BattleFrontier_BattleDomePreBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleDomePreBattleRoom/border.bin"

BattleFrontier_BattleDomePreBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleDomePreBattleRoom/map.bin"

	.align 2
BattleFrontier_BattleDomePreBattleRoom_Layout::
	.4byte 0x9
	.4byte 0x8
	.4byte BattleFrontier_BattleDomePreBattleRoom_MapBorder
	.4byte BattleFrontier_BattleDomePreBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleDome

