	.align 2
Underwater2_MapBorder::
	.incbin "data/layouts/Underwater2/border.bin"

	.align 2
Underwater2_MapBlockdata::
	.incbin "data/layouts/Underwater2/map.bin"

	.align 2
Underwater2_Layout::
	.4byte 0x50
	.4byte 0x50
	.4byte Underwater2_MapBorder
	.4byte Underwater2_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
