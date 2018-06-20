	.align 2
BattleFrontier_OutsideWest_MapBorder::
	.incbin "data/layouts/BattleFrontier_OutsideWest/border.bin"

	.align 2
BattleFrontier_OutsideWest_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_OutsideWest/map.bin"

	.align 2
BattleFrontier_OutsideWest_Layout::
	.4byte 0x38
	.4byte 0x48
	.4byte BattleFrontier_OutsideWest_MapBorder
	.4byte BattleFrontier_OutsideWest_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BattleFrontierOutsideWest
