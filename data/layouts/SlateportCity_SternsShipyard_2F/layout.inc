	.align 2
SlateportCity_SternsShipyard_2F_MapBorder::
	.incbin "data/layouts/SlateportCity_SternsShipyard_2F/border.bin"

	.align 2
SlateportCity_SternsShipyard_2F_MapBlockdata::
	.incbin "data/layouts/SlateportCity_SternsShipyard_2F/map.bin"

	.align 2
SlateportCity_SternsShipyard_2F_Layout::
	.4byte 0x11
	.4byte 0xf
	.4byte SlateportCity_SternsShipyard_2F_MapBorder
	.4byte SlateportCity_SternsShipyard_2F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
