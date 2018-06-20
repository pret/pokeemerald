	.align 2
MtPyre_6F_MapBorder::
	.incbin "data/layouts/MtPyre_6F/border.bin"

	.align 2
MtPyre_6F_MapBlockdata::
	.incbin "data/layouts/MtPyre_6F/map.bin"

	.align 2
MtPyre_6F_Layout::
	.4byte 0xd
	.4byte 0xd
	.4byte MtPyre_6F_MapBorder
	.4byte MtPyre_6F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
