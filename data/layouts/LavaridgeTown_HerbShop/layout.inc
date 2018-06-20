LavaridgeTown_HerbShop_MapBorder::
	.incbin "data/layouts/LavaridgeTown_HerbShop/border.bin"

LavaridgeTown_HerbShop_MapBlockdata::
	.incbin "data/layouts/LavaridgeTown_HerbShop/map.bin"

	.align 2
LavaridgeTown_HerbShop_Layout::
	.4byte 0xb
	.4byte 0x8
	.4byte LavaridgeTown_HerbShop_MapBorder
	.4byte LavaridgeTown_HerbShop_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Shop

