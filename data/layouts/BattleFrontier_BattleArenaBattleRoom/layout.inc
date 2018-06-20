	.align 2
BattleFrontier_BattleArenaBattleRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleArenaBattleRoom/border.bin"

	.align 2
BattleFrontier_BattleArenaBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleArenaBattleRoom/map.bin"

	.align 2
BattleFrontier_BattleArenaBattleRoom_Layout::
	.4byte 0x10
	.4byte 0xb
	.4byte BattleFrontier_BattleArenaBattleRoom_MapBorder
	.4byte BattleFrontier_BattleArenaBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleArena
