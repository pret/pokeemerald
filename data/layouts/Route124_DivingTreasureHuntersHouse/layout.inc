	.align 2
Route124_DivingTreasureHuntersHouse_MapBorder::
	.incbin "data/layouts/Route124_DivingTreasureHuntersHouse/border.bin"

	.align 2
Route124_DivingTreasureHuntersHouse_MapBlockdata::
	.incbin "data/layouts/Route124_DivingTreasureHuntersHouse/map.bin"

	.align 2
Route124_DivingTreasureHuntersHouse_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte Route124_DivingTreasureHuntersHouse_MapBorder
	.4byte Route124_DivingTreasureHuntersHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
