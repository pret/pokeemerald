	.align 2
BattleFrontier_BattlePikeRandomRoom1_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePikeRandomRoom1/border.bin"

	.align 2
BattleFrontier_BattlePikeRandomRoom1_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePikeRandomRoom1/map.bin"

	.align 2
BattleFrontier_BattlePikeRandomRoom1_Layout::
	.4byte 0x9
	.4byte 0x8
	.4byte BattleFrontier_BattlePikeRandomRoom1_MapBorder
	.4byte BattleFrontier_BattlePikeRandomRoom1_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePike
