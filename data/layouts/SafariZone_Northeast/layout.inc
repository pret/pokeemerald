	.align 2
SafariZone_Northeast_MapBorder::
	.incbin "data/layouts/SafariZone_Northeast/border.bin"

	.align 2
SafariZone_Northeast_MapBlockdata::
	.incbin "data/layouts/SafariZone_Northeast/map.bin"

	.align 2
SafariZone_Northeast_Layout::
	.4byte 0x28
	.4byte 0x28
	.4byte SafariZone_Northeast_MapBorder
	.4byte SafariZone_Northeast_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lilycove
