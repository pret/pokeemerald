	.align 2
GraniteCave_StevensRoom_MapBorder::
	.incbin "data/layouts/GraniteCave_StevensRoom/border.bin"

	.align 2
GraniteCave_StevensRoom_MapBlockdata::
	.incbin "data/layouts/GraniteCave_StevensRoom/map.bin"

	.align 2
GraniteCave_StevensRoom_Layout::
	.4byte 0xf
	.4byte 0xe
	.4byte GraniteCave_StevensRoom_MapBorder
	.4byte GraniteCave_StevensRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
