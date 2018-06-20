	.align 2
BattleFrontier_BattlePikeThreePathRoom_MapBorder::
	.incbin "data/layouts/BattleFrontier_BattlePikeThreePathRoom/border.bin"

	.align 2
BattleFrontier_BattlePikeThreePathRoom_MapBlockdata::
	.incbin "data/layouts/BattleFrontier_BattlePikeThreePathRoom/map.bin"

	.align 2
BattleFrontier_BattlePikeThreePathRoom_Layout::
	.4byte 0xd
	.4byte 0xb
	.4byte BattleFrontier_BattlePikeThreePathRoom_MapBorder
	.4byte BattleFrontier_BattlePikeThreePathRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePike
