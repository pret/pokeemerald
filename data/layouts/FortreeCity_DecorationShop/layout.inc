	.align 2
FortreeCity_DecorationShop_MapBorder::
	.incbin "data/layouts/FortreeCity_DecorationShop/border.bin"

	.align 2
FortreeCity_DecorationShop_MapBlockdata::
	.incbin "data/layouts/FortreeCity_DecorationShop/map.bin"

	.align 2
FortreeCity_DecorationShop_Layout::
	.4byte 0x8
	.4byte 0x6
	.4byte FortreeCity_DecorationShop_MapBorder
	.4byte FortreeCity_DecorationShop_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
