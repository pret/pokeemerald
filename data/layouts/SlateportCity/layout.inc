	.align 2
SlateportCity_MapBorder::
	.incbin "data/layouts/SlateportCity/border.bin"

	.align 2
SlateportCity_MapBlockdata::
	.incbin "data/layouts/SlateportCity/map.bin"

	.align 2
SlateportCity_Layout::
	.4byte 0x28
	.4byte 0x3c
	.4byte SlateportCity_MapBorder
	.4byte SlateportCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Slateport
