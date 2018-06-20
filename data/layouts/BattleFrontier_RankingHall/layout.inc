BattleFrontier_RankingHall_MapBorder::
	.incbin "data/layouts/BattleFrontier_RankingHall/border.bin"

BattleFrontier_RankingHall_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_RankingHall/map.bin"

	.align 2
BattleFrontier_RankingHall_Layout::
	.4byte 0x35
	.4byte 0xf
	.4byte BattleFrontier_RankingHall_MapBorder
	.4byte BattleFrontier_RankingHall_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontierRankingHall

