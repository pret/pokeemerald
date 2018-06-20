BattleFrontier_BattleDomeBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleDomeBattleRoom/border.bin"

BattleFrontier_BattleDomeBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleDomeBattleRoom/map.bin"

	.align 2
BattleFrontier_BattleDomeBattleRoom_Layout::
	.4byte 0x14
	.4byte 0xa
	.4byte BattleFrontier_BattleDomeBattleRoom_MapBorder
	.4byte BattleFrontier_BattleDomeBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleDome

