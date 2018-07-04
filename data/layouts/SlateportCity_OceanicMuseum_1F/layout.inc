SlateportCity_OceanicMuseum_1F_MapBorder::
	.incbin "data/layouts/SlateportCity_OceanicMuseum_1F/border.bin"

SlateportCity_OceanicMuseum_1F_MapBlockdata::
	.incbin "data/layouts/SlateportCity_OceanicMuseum_1F/map.bin"

	.align 2
SlateportCity_OceanicMuseum_1F_Layout::
	.4byte 0x14
	.4byte 0x9
	.4byte SlateportCity_OceanicMuseum_1F_MapBorder
	.4byte SlateportCity_OceanicMuseum_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_OceanicMuseum

