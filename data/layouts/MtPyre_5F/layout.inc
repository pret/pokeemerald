	.align 2
MtPyre_5F_MapBorder::
	.incbin "data/layouts/MtPyre_5F/border.bin"

	.align 2
MtPyre_5F_MapBlockdata::
	.incbin "data/layouts/MtPyre_5F/map.bin"

	.align 2
MtPyre_5F_Layout::
	.4byte 0xd
	.4byte 0xd
	.4byte MtPyre_5F_MapBorder
	.4byte MtPyre_5F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
