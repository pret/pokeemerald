VerdanturfTown_BattleTentBattleRoom_MapBorder::
	.incbin "data/layouts/VerdanturfTown_BattleTentBattleRoom/border.bin"

VerdanturfTown_BattleTentBattleRoom_MapBlockdata::
	.incbin "data/layouts/VerdanturfTown_BattleTentBattleRoom/map.bin"

	.align 2
VerdanturfTown_BattleTentBattleRoom_Layout::
	.4byte 0xd
	.4byte 0x9
	.4byte VerdanturfTown_BattleTentBattleRoom_MapBorder
	.4byte VerdanturfTown_BattleTentBattleRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BattleTent

