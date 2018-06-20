MauvilleCity_BikeShop_MapBorder::
	.incbin "data/layouts/MauvilleCity_BikeShop/border.bin"

MauvilleCity_BikeShop_MapBlockdata::
	.incbin "data/layouts/MauvilleCity_BikeShop/map.bin"

	.align 2
MauvilleCity_BikeShop_Layout::
	.4byte 0xc
	.4byte 0x9
	.4byte MauvilleCity_BikeShop_MapBorder
	.4byte MauvilleCity_BikeShop_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BikeShop

