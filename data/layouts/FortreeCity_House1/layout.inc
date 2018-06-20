FortreeCity_House1_MapBorder::
	.incbin "data/layouts/FortreeCity_House1/border.bin"

FortreeCity_House1_MapBlockdata::
	.incbin "data/layouts/FortreeCity_House1/map.bin"

	.align 2
FortreeCity_House1_Layout::
	.4byte 0x8
	.4byte 0x6
	.4byte FortreeCity_House1_MapBorder
	.4byte FortreeCity_House1_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

