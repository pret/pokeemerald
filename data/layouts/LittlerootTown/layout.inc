LittlerootTown_MapBorder::
	.incbin "data/layouts/LittlerootTown/border.bin"

LittlerootTown_MapBlockdata::
	.incbin "data/layouts/LittlerootTown/map.bin"

	.align 2
LittlerootTown_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte LittlerootTown_MapBorder
	.4byte LittlerootTown_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Petalburg

