	.align 2
Underwater4_MapBorder::
	.incbin "data/layouts/Underwater4/border.bin"

	.align 2
Underwater4_MapBlockdata::
	.incbin "data/layouts/Underwater4/map.bin"

	.align 2
Underwater4_Layout::
	.4byte 0x78
	.4byte 0x28
	.4byte Underwater4_MapBorder
	.4byte Underwater4_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
