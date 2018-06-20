	.align 2
ShoalCave_LowTideLowerRoom_MapBorder::
	.incbin "data/layouts/ShoalCave_LowTideLowerRoom/border.bin"

	.align 2
ShoalCave_LowTideLowerRoom_MapBlockdata::
	.incbin "data/layouts/ShoalCave_LowTideLowerRoom/map.bin"

	.align 2
ShoalCave_LowTideLowerRoom_Layout::
	.4byte 0x1f
	.4byte 0xe
	.4byte ShoalCave_LowTideLowerRoom_MapBorder
	.4byte ShoalCave_LowTideLowerRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
