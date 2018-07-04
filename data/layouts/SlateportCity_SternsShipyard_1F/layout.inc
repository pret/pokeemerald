SlateportCity_SternsShipyard_1F_MapBorder::
	.incbin "data/layouts/SlateportCity_SternsShipyard_1F/border.bin"

SlateportCity_SternsShipyard_1F_MapBlockdata::
	.incbin "data/layouts/SlateportCity_SternsShipyard_1F/map.bin"

	.align 2
SlateportCity_SternsShipyard_1F_Layout::
	.4byte 0x15
	.4byte 0xf
	.4byte SlateportCity_SternsShipyard_1F_MapBorder
	.4byte SlateportCity_SternsShipyard_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

