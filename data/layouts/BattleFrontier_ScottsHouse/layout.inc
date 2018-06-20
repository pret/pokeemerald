	.align 2
BattleFrontier_ScottsHouse_MapBorder::
	.incbin "data/layouts/BattleFrontier_ScottsHouse/border.bin"

	.align 2
BattleFrontier_ScottsHouse_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_ScottsHouse/map.bin"

	.align 2
BattleFrontier_ScottsHouse_Layout::
	.4byte 0x6
	.4byte 0x8
	.4byte BattleFrontier_ScottsHouse_MapBorder
	.4byte BattleFrontier_ScottsHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier
