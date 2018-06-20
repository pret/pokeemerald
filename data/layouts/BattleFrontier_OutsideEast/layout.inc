BattleFrontier_OutsideEast_MapBorder::
	.incbin "data/layouts/BattleFrontier_OutsideEast/border.bin"

BattleFrontier_OutsideEast_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_OutsideEast/map.bin"

	.align 2
BattleFrontier_OutsideEast_Layout::
	.4byte 0x48
	.4byte 0x48
	.4byte BattleFrontier_OutsideEast_MapBorder
	.4byte BattleFrontier_OutsideEast_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BattleFrontierOutsideEast

