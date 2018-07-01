House3_MapBorder::
	.incbin "data/layouts/House3/border.bin"

House3_MapBlockdata::
	.incbin "data/layouts/House3/map.bin"

	.align 2
House3_Layout::
	.4byte 0xa
	.4byte 0x8
	.4byte House3_MapBorder
	.4byte House3_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

