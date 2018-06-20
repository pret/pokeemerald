	.align 2
DewfordTown_Hall_MapBorder::
	.incbin "data/layouts/DewfordTown_Hall/border.bin"

	.align 2
DewfordTown_Hall_MapBlockdata::
	.incbin "data/layouts/DewfordTown_Hall/map.bin"

	.align 2
DewfordTown_Hall_Layout::
	.4byte 0x11
	.4byte 0x9
	.4byte DewfordTown_Hall_MapBorder
	.4byte DewfordTown_Hall_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
