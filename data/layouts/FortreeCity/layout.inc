	.align 2
FortreeCity_MapBorder::
	.incbin "data/layouts/FortreeCity/border.bin"

	.align 2
FortreeCity_MapBlockdata::
	.incbin "data/layouts/FortreeCity/map.bin"

	.align 2
FortreeCity_Layout::
	.4byte 0x28
	.4byte 0x14
	.4byte FortreeCity_MapBorder
	.4byte FortreeCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Fortree
