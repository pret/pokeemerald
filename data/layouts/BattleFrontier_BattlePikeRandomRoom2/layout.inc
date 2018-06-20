BattleFrontier_BattlePikeRandomRoom2_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePikeRandomRoom2/border.bin"

BattleFrontier_BattlePikeRandomRoom2_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePikeRandomRoom2/map.bin"

	.align 2
BattleFrontier_BattlePikeRandomRoom2_Layout::
	.4byte 0x5
	.4byte 0x8
	.4byte BattleFrontier_BattlePikeRandomRoom2_MapBorder
	.4byte BattleFrontier_BattlePikeRandomRoom2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePike

