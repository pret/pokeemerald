SafariZone_North_MapBorder::
	.incbin "data/layouts/SafariZone_North/border.bin"

SafariZone_North_MapBlockdata::
	.incbin "data/layouts/SafariZone_North/map.bin"

	.align 2
SafariZone_North_Layout::
	.4byte 0x28
	.4byte 0x28
	.4byte SafariZone_North_MapBorder
	.4byte SafariZone_North_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lilycove

