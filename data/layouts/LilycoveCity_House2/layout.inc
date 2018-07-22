LilycoveCity_House2_MapBorder::
	.incbin "data/layouts/LilycoveCity_House2/border.bin"

LilycoveCity_House2_MapBlockdata::
	.incbin "data/layouts/LilycoveCity_House2/map.bin"

	.align 2
LilycoveCity_House2_Layout::
	.4byte 0x8
	.4byte 0x8
	.4byte LilycoveCity_House2_MapBorder
	.4byte LilycoveCity_House2_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

