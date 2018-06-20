DewfordTown_MapBorder::
	.incbin "data/layouts/DewfordTown/border.bin"

DewfordTown_MapBlockdata::
	.incbin "data/layouts/DewfordTown/map.bin"

	.align 2
DewfordTown_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte DewfordTown_MapBorder
	.4byte DewfordTown_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Dewford

