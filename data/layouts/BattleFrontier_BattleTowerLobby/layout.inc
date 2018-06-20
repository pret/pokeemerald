	.align 2
BattleFrontier_BattleTowerLobby_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleTowerLobby/border.bin"

	.align 2
BattleFrontier_BattleTowerLobby_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleTowerLobby/map.bin"

	.align 2
BattleFrontier_BattleTowerLobby_Layout::
	.4byte 0x19
	.4byte 0xa
	.4byte BattleFrontier_BattleTowerLobby_MapBorder
	.4byte BattleFrontier_BattleTowerLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier
