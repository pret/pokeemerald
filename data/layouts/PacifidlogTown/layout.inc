PacifidlogTown_MapBorder::
	.incbin "data/layouts/PacifidlogTown/border.bin"

PacifidlogTown_MapBlockdata::
	.incbin "data/layouts/PacifidlogTown/map.bin"

	.align 2
PacifidlogTown_Layout::
	.4byte 0x14
	.4byte 0x28
	.4byte PacifidlogTown_MapBorder
	.4byte PacifidlogTown_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Pacifidlog

