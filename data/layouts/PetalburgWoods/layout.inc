	.align 2
PetalburgWoods_MapBorder::
	.incbin "data/layouts/PetalburgWoods/border.bin"

	.align 2
PetalburgWoods_MapBlockdata::
	.incbin "data/layouts/PetalburgWoods/map.bin"

	.align 2
PetalburgWoods_Layout::
	.4byte 0x30
	.4byte 0x2c
	.4byte PetalburgWoods_MapBorder
	.4byte PetalburgWoods_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Rustboro
