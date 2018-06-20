	.align 2
LittlerootTown_MaysHouse_2F_MapBorder::
	.incbin "data/layouts/LittlerootTown_MaysHouse_2F/border.bin"

	.align 2
LittlerootTown_MaysHouse_2F_MapBlockdata::
	.incbin "data/layouts/LittlerootTown_MaysHouse_2F/map.bin"

	.align 2
LittlerootTown_MaysHouse_2F_Layout::
	.4byte 0x9
	.4byte 0x8
	.4byte LittlerootTown_MaysHouse_2F_MapBorder
	.4byte LittlerootTown_MaysHouse_2F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BrendansMaysHouse
