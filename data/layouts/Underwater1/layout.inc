	.align 2
Underwater1_MapBorder::
	.incbin "data/layouts/Underwater1/border.bin"

	.align 2
Underwater1_MapBlockdata::
	.incbin "data/layouts/Underwater1/map.bin"

	.align 2
Underwater1_Layout::
	.4byte 0x50
	.4byte 0x50
	.4byte Underwater1_MapBorder
	.4byte Underwater1_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
