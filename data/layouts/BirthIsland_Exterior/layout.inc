BirthIsland_Exterior_MapBorder::
	.incbin "data/layouts/BirthIsland_Exterior/border.bin"

BirthIsland_Exterior_MapBlockdata::
	.incbin "data/layouts/BirthIsland_Exterior/map.bin"

	.align 2
BirthIsland_Exterior_Layout::
	.4byte 0x1e
	.4byte 0x1e
	.4byte BirthIsland_Exterior_MapBorder
	.4byte BirthIsland_Exterior_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Dewford

