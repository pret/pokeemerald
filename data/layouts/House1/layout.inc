	.align 2
House1_MapBorder::
	.incbin "data/layouts/House1/border.bin"

	.align 2
House1_MapBlockdata::
	.incbin "data/layouts/House1/map.bin"

	.align 2
House1_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte House1_MapBorder
	.4byte House1_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
