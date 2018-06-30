BattleFrontier_BattlePikeLobby_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePikeLobby/border.bin"

BattleFrontier_BattlePikeLobby_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePikeLobby/map.bin"

	.align 2
BattleFrontier_BattlePikeLobby_Layout::
	.4byte 0xb
	.4byte 0xd
	.4byte BattleFrontier_BattlePikeLobby_MapBorder
	.4byte BattleFrontier_BattlePikeLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePike

