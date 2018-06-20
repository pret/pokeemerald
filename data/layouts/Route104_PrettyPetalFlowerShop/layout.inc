	.align 2
Route104_PrettyPetalFlowerShop_MapBorder::
	.incbin "data/layouts/Route104_PrettyPetalFlowerShop/border.bin"

	.align 2
Route104_PrettyPetalFlowerShop_MapBlockdata::
	.incbin "data/layouts/Route104_PrettyPetalFlowerShop/map.bin"

	.align 2
Route104_PrettyPetalFlowerShop_Layout::
	.4byte 0xf
	.4byte 0x9
	.4byte Route104_PrettyPetalFlowerShop_MapBorder
	.4byte Route104_PrettyPetalFlowerShop_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_PrettyPetalFlowerShop
