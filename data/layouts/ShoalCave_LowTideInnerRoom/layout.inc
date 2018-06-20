	.align 2
ShoalCave_LowTideInnerRoom_MapBorder::
	.incbin "data/layouts/ShoalCave_LowTideInnerRoom/border.bin"

	.align 2
ShoalCave_LowTideInnerRoom_MapBlockdata::
	.incbin "data/layouts/ShoalCave_LowTideInnerRoom/map.bin"

	.align 2
ShoalCave_LowTideInnerRoom_Layout::
	.4byte 0x2e
	.4byte 0x26
	.4byte ShoalCave_LowTideInnerRoom_MapBorder
	.4byte ShoalCave_LowTideInnerRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
