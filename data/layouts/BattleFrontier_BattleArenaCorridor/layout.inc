	.align 2
BattleFrontier_BattleArenaCorridor_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleArenaCorridor/border.bin"

	.align 2
BattleFrontier_BattleArenaCorridor_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleArenaCorridor/map.bin"

	.align 2
BattleFrontier_BattleArenaCorridor_Layout::
	.4byte 0x12
	.4byte 0xe
	.4byte BattleFrontier_BattleArenaCorridor_MapBorder
	.4byte BattleFrontier_BattleArenaCorridor_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleArena
