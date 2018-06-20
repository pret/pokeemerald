	.align 2
JaggedPass_MapBorder::
	.incbin "data/layouts/JaggedPass/border.bin"

	.align 2
JaggedPass_MapBlockdata::
	.incbin "data/layouts/JaggedPass/map.bin"

	.align 2
JaggedPass_Layout::
	.4byte 0x1e
	.4byte 0x2e
	.4byte JaggedPass_MapBorder
	.4byte JaggedPass_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge
