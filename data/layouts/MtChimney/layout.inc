	.align 2
MtChimney_MapBorder::
	.incbin "data/layouts/MtChimney/border.bin"

	.align 2
MtChimney_MapBlockdata::
	.incbin "data/layouts/MtChimney/map.bin"

	.align 2
MtChimney_Layout::
	.4byte 0x28
	.4byte 0x2f
	.4byte MtChimney_MapBorder
	.4byte MtChimney_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge
