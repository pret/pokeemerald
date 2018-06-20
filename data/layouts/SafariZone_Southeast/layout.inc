	.align 2
SafariZone_Southeast_MapBorder::
	.incbin "data/layouts/SafariZone_Southeast/border.bin"

	.align 2
SafariZone_Southeast_MapBlockdata::
	.incbin "data/layouts/SafariZone_Southeast/map.bin"

	.align 2
SafariZone_Southeast_Layout::
	.4byte 0x28
	.4byte 0x28
	.4byte SafariZone_Southeast_MapBorder
	.4byte SafariZone_Southeast_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lilycove
