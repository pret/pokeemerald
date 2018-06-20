	.align 2
MtPyre_Exterior_MapBorder::
	.incbin "data/layouts/MtPyre_Exterior/border.bin"

	.align 2
MtPyre_Exterior_MapBlockdata::
	.incbin "data/layouts/MtPyre_Exterior/map.bin"

	.align 2
MtPyre_Exterior_Layout::
	.4byte 0x26
	.4byte 0x33
	.4byte MtPyre_Exterior_MapBorder
	.4byte MtPyre_Exterior_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
