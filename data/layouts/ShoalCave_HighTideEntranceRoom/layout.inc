ShoalCave_HighTideEntranceRoom_MapBorder::
	.incbin "data/layouts/ShoalCave_HighTideEntranceRoom/border.bin"

ShoalCave_HighTideEntranceRoom_MapBlockdata::
	.incbin "data/layouts/ShoalCave_HighTideEntranceRoom/map.bin"

	.align 2
ShoalCave_HighTideEntranceRoom_Layout::
	.4byte 0x23
	.4byte 0x23
	.4byte ShoalCave_HighTideEntranceRoom_MapBorder
	.4byte ShoalCave_HighTideEntranceRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

