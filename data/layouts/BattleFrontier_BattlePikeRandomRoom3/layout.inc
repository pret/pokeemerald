	.align 2
BattleFrontier_BattlePikeRandomRoom3_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePikeRandomRoom3/border.bin"

	.align 2
BattleFrontier_BattlePikeRandomRoom3_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePikeRandomRoom3/map.bin"

	.align 2
BattleFrontier_BattlePikeRandomRoom3_Layout::
	.4byte 0x9
	.4byte 0x14
	.4byte BattleFrontier_BattlePikeRandomRoom3_MapBorder
	.4byte BattleFrontier_BattlePikeRandomRoom3_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePike
