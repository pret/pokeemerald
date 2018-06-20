	.align 2
Underwater5_MapBorder::
	.incbin "data/layouts/Underwater5/border.bin"

	.align 2
Underwater5_MapBlockdata::
	.incbin "data/layouts/Underwater5/map.bin"

	.align 2
Underwater5_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte Underwater5_MapBorder
	.4byte Underwater5_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
