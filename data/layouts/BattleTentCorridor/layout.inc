	.align 2
BattleTentCorridor_MapBorder::
	.incbin "data/layouts/BattleTentCorridor/border.bin"

	.align 2
BattleTentCorridor_MapBlockdata::
	.incbin "data/layouts/BattleTentCorridor/map.bin"

	.align 2
BattleTentCorridor_Layout::
	.4byte 0x5
	.4byte 0x8
	.4byte BattleTentCorridor_MapBorder
	.4byte BattleTentCorridor_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleTent
