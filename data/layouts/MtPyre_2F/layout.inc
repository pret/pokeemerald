MtPyre_2F_MapBorder::
	.incbin "data/layouts/MtPyre_2F/border.bin"

MtPyre_2F_MapBlockdata::
	.incbin "data/layouts/MtPyre_2F/map.bin"

	.align 2
MtPyre_2F_Layout::
	.4byte 0xd
	.4byte 0xd
	.4byte MtPyre_2F_MapBorder
	.4byte MtPyre_2F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

