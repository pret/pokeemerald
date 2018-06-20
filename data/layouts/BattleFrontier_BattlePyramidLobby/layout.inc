	.align 2
BattleFrontier_BattlePyramidLobby_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePyramidLobby/border.bin"

	.align 2
BattleFrontier_BattlePyramidLobby_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePyramidLobby/map.bin"

	.align 2
BattleFrontier_BattlePyramidLobby_Layout::
	.4byte 0xf
	.4byte 0x12
	.4byte BattleFrontier_BattlePyramidLobby_MapBorder
	.4byte BattleFrontier_BattlePyramidLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePyramid
