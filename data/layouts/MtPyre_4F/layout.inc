	.align 2
MtPyre_4F_MapBorder::
	.incbin "data/layouts/MtPyre_4F/border.bin"

	.align 2
MtPyre_4F_MapBlockdata::
	.incbin "data/layouts/MtPyre_4F/map.bin"

	.align 2
MtPyre_4F_Layout::
	.4byte 0xd
	.4byte 0xd
	.4byte MtPyre_4F_MapBorder
	.4byte MtPyre_4F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
