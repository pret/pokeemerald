	.align 2
BattleFrontier_BattleFactoryBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleFactoryBattleRoom/border.bin"

	.align 2
BattleFrontier_BattleFactoryBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleFactoryBattleRoom/map.bin"

	.align 2
BattleFrontier_BattleFactoryBattleRoom_Layout::
	.4byte 0xd
	.4byte 0xc
	.4byte BattleFrontier_BattleFactoryBattleRoom_MapBorder
	.4byte BattleFrontier_BattleFactoryBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFactory
