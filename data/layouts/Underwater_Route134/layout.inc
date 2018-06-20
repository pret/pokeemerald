	.align 2
Underwater_Route134_MapBorder::
	.incbin "data/layouts/Underwater_Route134/border.bin"

	.align 2
Underwater_Route134_MapBlockdata::
	.incbin "data/layouts/Underwater_Route134/map.bin"

	.align 2
Underwater_Route134_Layout::
	.4byte 0x12
	.4byte 0xa
	.4byte Underwater_Route134_MapBorder
	.4byte Underwater_Route134_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
