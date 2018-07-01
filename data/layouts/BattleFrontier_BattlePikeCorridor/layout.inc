BattleFrontier_BattlePikeCorridor_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePikeCorridor/border.bin"

BattleFrontier_BattlePikeCorridor_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePikeCorridor/map.bin"

	.align 2
BattleFrontier_BattlePikeCorridor_Layout::
	.4byte 0xe
	.4byte 0x8
	.4byte BattleFrontier_BattlePikeCorridor_MapBorder
	.4byte BattleFrontier_BattlePikeCorridor_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePike

