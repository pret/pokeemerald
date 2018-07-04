SafariZone_South_MapBorder::
	.incbin "data/layouts/SafariZone_South/border.bin"

SafariZone_South_MapBlockdata::
	.incbin "data/layouts/SafariZone_South/map.bin"

	.align 2
SafariZone_South_Layout::
	.4byte 0x28
	.4byte 0x28
	.4byte SafariZone_South_MapBorder
	.4byte SafariZone_South_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lilycove

