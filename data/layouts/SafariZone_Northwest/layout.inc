	.align 2
SafariZone_Northwest_MapBorder::
	.incbin "data/layouts/SafariZone_Northwest/border.bin"

	.align 2
SafariZone_Northwest_MapBlockdata::
	.incbin "data/layouts/SafariZone_Northwest/map.bin"

	.align 2
SafariZone_Northwest_Layout::
	.4byte 0x28
	.4byte 0x28
	.4byte SafariZone_Northwest_MapBorder
	.4byte SafariZone_Northwest_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lilycove
