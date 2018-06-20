	.align 2
ArtisanCave_1F_MapBorder::
	.incbin "data/layouts/ArtisanCave_1F/border.bin"

	.align 2
ArtisanCave_1F_MapBlockdata::
	.incbin "data/layouts/ArtisanCave_1F/map.bin"

	.align 2
ArtisanCave_1F_Layout::
	.4byte 0x15
	.4byte 0x16
	.4byte ArtisanCave_1F_MapBorder
	.4byte ArtisanCave_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
