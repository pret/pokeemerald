AncientTomb_MapBorder::
	.incbin "data/layouts/AncientTomb/border.bin"

AncientTomb_MapBlockdata::
	.incbin "data/layouts/AncientTomb/map.bin"

	.align 2
AncientTomb_Layout::
	.4byte 0x11
	.4byte 0x21
	.4byte AncientTomb_MapBorder
	.4byte AncientTomb_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

