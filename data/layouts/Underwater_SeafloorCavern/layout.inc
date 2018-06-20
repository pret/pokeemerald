Underwater_SeafloorCavern_MapBorder::
	.incbin "data/layouts/Underwater_SeafloorCavern/border.bin"

Underwater_SeafloorCavern_MapBlockdata::
	.incbin "data/layouts/Underwater_SeafloorCavern/map.bin"

	.align 2
Underwater_SeafloorCavern_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte Underwater_SeafloorCavern_MapBorder
	.4byte Underwater_SeafloorCavern_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater

