BattleTentLobby_MapBorder::
	.incbin "data/layouts/BattleTentLobby/border.bin"

BattleTentLobby_MapBlockdata::
	.incbin "data/layouts/BattleTentLobby/map.bin"

	.align 2
BattleTentLobby_Layout::
	.4byte 0xd
	.4byte 0xa
	.4byte BattleTentLobby_MapBorder
	.4byte BattleTentLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleTent

