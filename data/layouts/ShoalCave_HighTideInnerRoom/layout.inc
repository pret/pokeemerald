	.align 2
ShoalCave_HighTideInnerRoom_MapBorder::
	.incbin "data/layouts/ShoalCave_HighTideInnerRoom/border.bin"

	.align 2
ShoalCave_HighTideInnerRoom_MapBlockdata::
	.incbin "data/layouts/ShoalCave_HighTideInnerRoom/map.bin"

	.align 2
ShoalCave_HighTideInnerRoom_Layout::
	.4byte 0x2e
	.4byte 0x26
	.4byte ShoalCave_HighTideInnerRoom_MapBorder
	.4byte ShoalCave_HighTideInnerRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
