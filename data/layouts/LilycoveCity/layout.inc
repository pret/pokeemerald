LilycoveCity_MapBorder::
	.incbin "data/layouts/LilycoveCity/border.bin"

LilycoveCity_MapBlockdata::
	.incbin "data/layouts/LilycoveCity/map.bin"

	.align 2
LilycoveCity_Layout::
	.4byte 0x50
	.4byte 0x28
	.4byte LilycoveCity_MapBorder
	.4byte LilycoveCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lilycove

