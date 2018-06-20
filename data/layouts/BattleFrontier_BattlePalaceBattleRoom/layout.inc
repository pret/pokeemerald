	.align 2
BattleFrontier_BattlePalaceBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePalaceBattleRoom/border.bin"

	.align 2
BattleFrontier_BattlePalaceBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePalaceBattleRoom/map.bin"

	.align 2
BattleFrontier_BattlePalaceBattleRoom_Layout::
	.4byte 0xf
	.4byte 0xa
	.4byte BattleFrontier_BattlePalaceBattleRoom_MapBorder
	.4byte BattleFrontier_BattlePalaceBattleRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BattlePalace
