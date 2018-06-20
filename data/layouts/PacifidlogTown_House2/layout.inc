PacifidlogTown_House2_MapBorder::
	.incbin "data/layouts/PacifidlogTown_House2/border.bin"

PacifidlogTown_House2_MapBlockdata::
	.incbin "data/layouts/PacifidlogTown_House2/map.bin"

	.align 2
PacifidlogTown_House2_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte PacifidlogTown_House2_MapBorder
	.4byte PacifidlogTown_House2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

