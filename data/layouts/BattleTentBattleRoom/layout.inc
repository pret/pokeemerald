	.align 2
BattleTentBattleRoom_MapBorder::
	.incbin "data/layouts/BattleTentBattleRoom/border.bin"

	.align 2
BattleTentBattleRoom_MapBlockdata::
	.incbin "data/layouts/BattleTentBattleRoom/map.bin"

	.align 2
BattleTentBattleRoom_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte BattleTentBattleRoom_MapBorder
	.4byte BattleTentBattleRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleTent
