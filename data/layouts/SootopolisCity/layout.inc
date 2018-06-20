SootopolisCity_MapBorder::
	.incbin "data/layouts/SootopolisCity/border.bin"

SootopolisCity_MapBlockdata::
	.incbin "data/layouts/SootopolisCity/map.bin"

	.align 2
SootopolisCity_Layout::
	.4byte 0x3c
	.4byte 0x3c
	.4byte SootopolisCity_MapBorder
	.4byte SootopolisCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Sootopolis

