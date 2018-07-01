SootopolisCity_LotadAndSeedotHouse_MapBorder::
	.incbin "data/layouts/SootopolisCity_LotadAndSeedotHouse/border.bin"

SootopolisCity_LotadAndSeedotHouse_MapBlockdata::
	.incbin "data/layouts/SootopolisCity_LotadAndSeedotHouse/map.bin"

	.align 2
SootopolisCity_LotadAndSeedotHouse_Layout::
	.4byte 0x8
	.4byte 0x7
	.4byte SootopolisCity_LotadAndSeedotHouse_MapBorder
	.4byte SootopolisCity_LotadAndSeedotHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

