DesertUnderpass_MapBorder::
	.incbin "data/layouts/DesertUnderpass/border.bin"

DesertUnderpass_MapBlockdata::
	.incbin "data/layouts/DesertUnderpass/map.bin"

	.align 2
DesertUnderpass_Layout::
	.4byte 0x8b
	.4byte 0x17
	.4byte DesertUnderpass_MapBorder
	.4byte DesertUnderpass_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

