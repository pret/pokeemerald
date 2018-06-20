	.align 2
DoubleBattleColosseum_MapBorder::
	.incbin "data/layouts/DoubleBattleColosseum/border.bin"

	.align 2
DoubleBattleColosseum_MapBlockdata::
	.incbin "data/layouts/DoubleBattleColosseum/map.bin"

	.align 2
DoubleBattleColosseum_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte DoubleBattleColosseum_MapBorder
	.4byte DoubleBattleColosseum_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_CableClub
