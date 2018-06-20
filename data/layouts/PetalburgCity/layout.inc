	.align 2
PetalburgCity_MapBorder::
	.incbin "data/layouts/PetalburgCity/border.bin"

	.align 2
PetalburgCity_MapBlockdata::
	.incbin "data/layouts/PetalburgCity/map.bin"

	.align 2
PetalburgCity_Layout::
	.4byte 0x1e
	.4byte 0x1e
	.4byte PetalburgCity_MapBorder
	.4byte PetalburgCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Petalburg
