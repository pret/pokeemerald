	.align 2
SingleBattleColosseum_MapBorder::
	.incbin "data/layouts/SingleBattleColosseum/border.bin"

	.align 2
SingleBattleColosseum_MapBlockdata::
	.incbin "data/layouts/SingleBattleColosseum/map.bin"

	.align 2
SingleBattleColosseum_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte SingleBattleColosseum_MapBorder
	.4byte SingleBattleColosseum_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_CableClub
