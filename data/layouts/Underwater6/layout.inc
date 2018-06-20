	.align 2
Underwater6_MapBorder::
	.incbin "data/layouts/Underwater6/border.bin"

	.align 2
Underwater6_MapBlockdata::
	.incbin "data/layouts/Underwater6/map.bin"

	.align 2
Underwater6_Layout::
	.4byte 0x28
	.4byte 0x50
	.4byte Underwater6_MapBorder
	.4byte Underwater6_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
