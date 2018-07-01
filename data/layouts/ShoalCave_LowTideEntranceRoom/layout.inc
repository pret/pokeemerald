ShoalCave_LowTideEntranceRoom_MapBorder::
	.incbin "data/layouts/ShoalCave_LowTideEntranceRoom/border.bin"

ShoalCave_LowTideEntranceRoom_MapBlockdata::
	.incbin "data/layouts/ShoalCave_LowTideEntranceRoom/map.bin"

	.align 2
ShoalCave_LowTideEntranceRoom_Layout::
	.4byte 0x23
	.4byte 0x23
	.4byte ShoalCave_LowTideEntranceRoom_MapBorder
	.4byte ShoalCave_LowTideEntranceRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

