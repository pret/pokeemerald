	.align 2
SootopolisCity_House3_MapBorder::
	.incbin "data/layouts/SootopolisCity_House3/border.bin"

	.align 2
SootopolisCity_House3_MapBlockdata::
	.incbin "data/layouts/SootopolisCity_House3/map.bin"

	.align 2
SootopolisCity_House3_Layout::
	.4byte 0x8
	.4byte 0x7
	.4byte SootopolisCity_House3_MapBorder
	.4byte SootopolisCity_House3_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
