EverGrandeCity_Hall4_MapBorder::
	.incbin "data/layouts/EverGrandeCity_Hall4/border.bin"

EverGrandeCity_Hall4_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_Hall4/map.bin"

	.align 2
EverGrandeCity_Hall4_Layout::
	.4byte 0xb
	.4byte 0x22
	.4byte EverGrandeCity_Hall4_MapBorder
	.4byte EverGrandeCity_Hall4_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_EliteFour

