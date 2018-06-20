	.align 2
BattleFrontier_BattlePalaceLobby_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePalaceLobby/border.bin"

	.align 2
BattleFrontier_BattlePalaceLobby_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePalaceLobby/map.bin"

	.align 2
BattleFrontier_BattlePalaceLobby_Layout::
	.4byte 0x19
	.4byte 0xc
	.4byte BattleFrontier_BattlePalaceLobby_MapBorder
	.4byte BattleFrontier_BattlePalaceLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePalace
