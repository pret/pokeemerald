BattleFrontier_BattleFactoryPreBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleFactoryPreBattleRoom/border.bin"

BattleFrontier_BattleFactoryPreBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleFactoryPreBattleRoom/map.bin"

	.align 2
BattleFrontier_BattleFactoryPreBattleRoom_Layout::
	.4byte 0x11
	.4byte 0xe
	.4byte BattleFrontier_BattleFactoryPreBattleRoom_MapBorder
	.4byte BattleFrontier_BattleFactoryPreBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFactory

