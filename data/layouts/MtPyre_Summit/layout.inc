MtPyre_Summit_MapBorder::
	.incbin "data/layouts/MtPyre_Summit/border.bin"

MtPyre_Summit_MapBlockdata::
	.incbin "data/layouts/MtPyre_Summit/map.bin"

	.align 2
MtPyre_Summit_Layout::
	.4byte 0x32
	.4byte 0x25
	.4byte MtPyre_Summit_MapBorder
	.4byte MtPyre_Summit_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

