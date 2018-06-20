	.align 2
BattleFrontier_Lounge1_MapBorder::
	.incbin "data/layouts/BattleFrontier_Lounge1/border.bin"

	.align 2
BattleFrontier_Lounge1_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_Lounge1/map.bin"

	.align 2
BattleFrontier_Lounge1_Layout::
	.4byte 0xd
	.4byte 0x8
	.4byte BattleFrontier_Lounge1_MapBorder
	.4byte BattleFrontier_Lounge1_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier
