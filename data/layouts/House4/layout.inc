	.align 2
House4_MapBorder::
	.incbin "data/layouts/House4/border.bin"

	.align 2
House4_MapBlockdata::
	.incbin "data/layouts/House4/map.bin"

	.align 2
House4_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte House4_MapBorder
	.4byte House4_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
