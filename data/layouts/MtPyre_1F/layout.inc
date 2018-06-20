	.align 2
MtPyre_1F_MapBorder::
	.incbin "data/layouts/MtPyre_1F/border.bin"

	.align 2
MtPyre_1F_MapBlockdata::
	.incbin "data/layouts/MtPyre_1F/map.bin"

	.align 2
MtPyre_1F_Layout::
	.4byte 0x16
	.4byte 0x13
	.4byte MtPyre_1F_MapBorder
	.4byte MtPyre_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
