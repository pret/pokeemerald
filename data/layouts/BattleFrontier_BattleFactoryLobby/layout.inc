	.align 2
BattleFrontier_BattleFactoryLobby_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleFactoryLobby/border.bin"

	.align 2
BattleFrontier_BattleFactoryLobby_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleFactoryLobby/map.bin"

	.align 2
BattleFrontier_BattleFactoryLobby_Layout::
	.4byte 0x13
	.4byte 0xc
	.4byte BattleFrontier_BattleFactoryLobby_MapBorder
	.4byte BattleFrontier_BattleFactoryLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFactory
