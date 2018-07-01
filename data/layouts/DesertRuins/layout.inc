DesertRuins_MapBorder::
	.incbin "data/layouts/DesertRuins/border.bin"

DesertRuins_MapBlockdata::
	.incbin "data/layouts/DesertRuins/map.bin"

	.align 2
DesertRuins_Layout::
	.4byte 0x11
	.4byte 0x21
	.4byte DesertRuins_MapBorder
	.4byte DesertRuins_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

