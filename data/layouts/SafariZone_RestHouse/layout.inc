	.align 2
SafariZone_RestHouse_MapBorder::
	.incbin "data/layouts/SafariZone_RestHouse/border.bin"

	.align 2
SafariZone_RestHouse_MapBlockdata::
	.incbin "data/layouts/SafariZone_RestHouse/map.bin"

	.align 2
SafariZone_RestHouse_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte SafariZone_RestHouse_MapBorder
	.4byte SafariZone_RestHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
