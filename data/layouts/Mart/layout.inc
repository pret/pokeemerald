	.align 2
Mart_MapBorder::
	.incbin "data/layouts/Mart/border.bin"

	.align 2
Mart_MapBlockdata::
	.incbin "data/layouts/Mart/map.bin"

	.align 2
Mart_Layout::
	.4byte 0xb
	.4byte 0x8
	.4byte Mart_MapBorder
	.4byte Mart_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Shop
