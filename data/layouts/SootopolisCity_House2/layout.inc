SootopolisCity_House2_MapBorder::
	.incbin "data/layouts/SootopolisCity_House2/border.bin"

SootopolisCity_House2_MapBlockdata::
	.incbin "data/layouts/SootopolisCity_House2/map.bin"

	.align 2
SootopolisCity_House2_Layout::
	.4byte 0x8
	.4byte 0x7
	.4byte SootopolisCity_House2_MapBorder
	.4byte SootopolisCity_House2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

