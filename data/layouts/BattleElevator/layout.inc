	.align 2
BattleElevator_MapBorder::
	.incbin "data/layouts/BattleElevator/border.bin"

	.align 2
BattleElevator_MapBlockdata::
	.incbin "data/layouts/BattleElevator/map.bin"

	.align 2
BattleElevator_Layout::
	.4byte 0x5
	.4byte 0x7
	.4byte BattleElevator_MapBorder
	.4byte BattleElevator_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier
