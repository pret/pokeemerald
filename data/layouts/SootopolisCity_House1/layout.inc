SootopolisCity_House1_MapBorder::
	.incbin "data/layouts/SootopolisCity_House1/border.bin"

SootopolisCity_House1_MapBlockdata::
	.incbin "data/layouts/SootopolisCity_House1/map.bin"

	.align 2
SootopolisCity_House1_Layout::
	.4byte 0x8
	.4byte 0x7
	.4byte SootopolisCity_House1_MapBorder
	.4byte SootopolisCity_House1_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

