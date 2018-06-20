BattleFrontier_BattleArenaLobby_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleArenaLobby/border.bin"

BattleFrontier_BattleArenaLobby_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleArenaLobby/map.bin"

	.align 2
BattleFrontier_BattleArenaLobby_Layout::
	.4byte 0x10
	.4byte 0xd
	.4byte BattleFrontier_BattleArenaLobby_MapBorder
	.4byte BattleFrontier_BattleArenaLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleArena

