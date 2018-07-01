BattleFrontier_BattleDomeCorridor_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattleDomeCorridor/border.bin"

BattleFrontier_BattleDomeCorridor_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattleDomeCorridor/map.bin"

	.align 2
BattleFrontier_BattleDomeCorridor_Layout::
	.4byte 0x30
	.4byte 0x7
	.4byte BattleFrontier_BattleDomeCorridor_MapBorder
	.4byte BattleFrontier_BattleDomeCorridor_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleDome

