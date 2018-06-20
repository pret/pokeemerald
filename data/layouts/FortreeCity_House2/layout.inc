	.align 2
FortreeCity_House2_MapBorder::
	.incbin "data/layouts/FortreeCity_House2/border.bin"

	.align 2
FortreeCity_House2_MapBlockdata::
	.incbin "data/layouts/FortreeCity_House2/map.bin"

	.align 2
FortreeCity_House2_Layout::
	.4byte 0x8
	.4byte 0x6
	.4byte FortreeCity_House2_MapBorder
	.4byte FortreeCity_House2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
