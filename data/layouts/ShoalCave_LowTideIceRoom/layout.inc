	.align 2
ShoalCave_LowTideIceRoom_MapBorder::
	.incbin "data/layouts/ShoalCave_LowTideIceRoom/border.bin"

	.align 2
ShoalCave_LowTideIceRoom_MapBlockdata::
	.incbin "data/layouts/ShoalCave_LowTideIceRoom/map.bin"

	.align 2
ShoalCave_LowTideIceRoom_Layout::
	.4byte 0x14
	.4byte 0x1e
	.4byte ShoalCave_LowTideIceRoom_MapBorder
	.4byte ShoalCave_LowTideIceRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
