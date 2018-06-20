	.align 2
MossdeepCity_MapBorder::
	.incbin "data/layouts/MossdeepCity/border.bin"

	.align 2
MossdeepCity_MapBlockdata::
	.incbin "data/layouts/MossdeepCity/map.bin"

	.align 2
MossdeepCity_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte MossdeepCity_MapBorder
	.4byte MossdeepCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mossdeep
