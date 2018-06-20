	.align 2
Underwater7_MapBorder::
	.incbin "data/layouts/Underwater7/border.bin"

	.align 2
Underwater7_MapBlockdata::
	.incbin "data/layouts/Underwater7/map.bin"

	.align 2
Underwater7_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte Underwater7_MapBorder
	.4byte Underwater7_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
