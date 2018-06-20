	.align 2
BattleFrontier_BattlePointExchangeServiceCorner_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePointExchangeServiceCorner/border.bin"

	.align 2
BattleFrontier_BattlePointExchangeServiceCorner_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePointExchangeServiceCorner/map.bin"

	.align 2
BattleFrontier_BattlePointExchangeServiceCorner_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_MapBorder
	.4byte BattleFrontier_BattlePointExchangeServiceCorner_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier
