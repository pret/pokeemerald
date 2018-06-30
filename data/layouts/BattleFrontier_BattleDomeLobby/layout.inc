BattleFrontier_BattleDomeLobby_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleDomeLobby/border.bin"

BattleFrontier_BattleDomeLobby_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleDomeLobby/map.bin"

	.align 2
BattleFrontier_BattleDomeLobby_Layout::
	.4byte 0x17
	.4byte 0x11
	.4byte BattleFrontier_BattleDomeLobby_MapBorder
	.4byte BattleFrontier_BattleDomeLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleDome

