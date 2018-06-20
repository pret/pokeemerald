	.align 2
NewMauville_Entrance_MapBorder::
	.incbin "data/layouts/NewMauville_Entrance/border.bin"

	.align 2
NewMauville_Entrance_MapBlockdata::
	.incbin "data/layouts/NewMauville_Entrance/map.bin"

	.align 2
NewMauville_Entrance_Layout::
	.4byte 0x9
	.4byte 0x9
	.4byte NewMauville_Entrance_MapBorder
	.4byte NewMauville_Entrance_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
