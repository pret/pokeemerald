	.align 2
LavaridgeTown_MapBorder::
	.incbin "data/layouts/LavaridgeTown/border.bin"

	.align 2
LavaridgeTown_MapBlockdata::
	.incbin "data/layouts/LavaridgeTown/map.bin"

	.align 2
LavaridgeTown_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte LavaridgeTown_MapBorder
	.4byte LavaridgeTown_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge
