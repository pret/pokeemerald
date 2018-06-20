	.align 2
NewMauville_Inside_MapBorder::
	.incbin "data/layouts/NewMauville_Inside/border.bin"

	.align 2
NewMauville_Inside_MapBlockdata::
	.incbin "data/layouts/NewMauville_Inside/map.bin"

	.align 2
NewMauville_Inside_Layout::
	.4byte 0x29
	.4byte 0x29
	.4byte NewMauville_Inside_MapBorder
	.4byte NewMauville_Inside_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_BikeShop
