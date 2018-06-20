	.align 2
BattleFrontier_BattlePalaceCorridor_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePalaceCorridor/border.bin"

	.align 2
BattleFrontier_BattlePalaceCorridor_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePalaceCorridor/map.bin"

	.align 2
BattleFrontier_BattlePalaceCorridor_Layout::
	.4byte 0x11
	.4byte 0xe
	.4byte BattleFrontier_BattlePalaceCorridor_MapBorder
	.4byte BattleFrontier_BattlePalaceCorridor_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BattlePalace
