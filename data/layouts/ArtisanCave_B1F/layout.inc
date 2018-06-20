	.align 2
ArtisanCave_B1F_MapBorder::
	.incbin "data/layouts/ArtisanCave_B1F/border.bin"

	.align 2
ArtisanCave_B1F_MapBlockdata::
	.incbin "data/layouts/ArtisanCave_B1F/map.bin"

	.align 2
ArtisanCave_B1F_Layout::
	.4byte 0x2e
	.4byte 0x36
	.4byte ArtisanCave_B1F_MapBorder
	.4byte ArtisanCave_B1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
