LilycoveCity_LilycoveMuseum_1F_MapBorder::
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_1F/border.bin"

LilycoveCity_LilycoveMuseum_1F_MapBlockdata::
	.incbin "data/layouts/LilycoveCity_LilycoveMuseum_1F/map.bin"

	.align 2
LilycoveCity_LilycoveMuseum_1F_Layout::
	.4byte 0x15
	.4byte 0xe
	.4byte LilycoveCity_LilycoveMuseum_1F_MapBorder
	.4byte LilycoveCity_LilycoveMuseum_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_LilycoveMuseum

