	.align 2
PacifidlogTown_House1_MapBorder::
	.incbin "data/layouts/PacifidlogTown_House1/border.bin"

	.align 2
PacifidlogTown_House1_MapBlockdata::
	.incbin "data/layouts/PacifidlogTown_House1/map.bin"

	.align 2
PacifidlogTown_House1_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte PacifidlogTown_House1_MapBorder
	.4byte PacifidlogTown_House1_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
