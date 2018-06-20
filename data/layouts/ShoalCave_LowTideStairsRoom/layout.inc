	.align 2
ShoalCave_LowTideStairsRoom_MapBorder::
	.incbin "data/layouts/ShoalCave_LowTideStairsRoom/border.bin"

	.align 2
ShoalCave_LowTideStairsRoom_MapBlockdata::
	.incbin "data/layouts/ShoalCave_LowTideStairsRoom/map.bin"

	.align 2
ShoalCave_LowTideStairsRoom_Layout::
	.4byte 0x15
	.4byte 0xf
	.4byte ShoalCave_LowTideStairsRoom_MapBorder
	.4byte ShoalCave_LowTideStairsRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
