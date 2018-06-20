BattleFrontier_Lounge2_MapBorder::
	.incbin "data/layouts/BattleFrontier_Lounge2/border.bin"

BattleFrontier_Lounge2_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_Lounge2/map.bin"

	.align 2
BattleFrontier_Lounge2_Layout::
	.4byte 0x9
	.4byte 0xa
	.4byte BattleFrontier_Lounge2_MapBorder
	.4byte BattleFrontier_Lounge2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier

