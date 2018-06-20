CableCarStation_MapBorder::
	.incbin "data/layouts/CableCarStation/border.bin"

CableCarStation_MapBlockdata::
	.incbin "data/layouts/CableCarStation/map.bin"

	.align 2
CableCarStation_Layout::
	.4byte 0xd
	.4byte 0xc
	.4byte CableCarStation_MapBorder
	.4byte CableCarStation_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

