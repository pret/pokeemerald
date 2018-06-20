EverGrandeCity_MapBorder::
	.incbin "data/layouts/EverGrandeCity/border.bin"

EverGrandeCity_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity/map.bin"

	.align 2
EverGrandeCity_Layout::
	.4byte 0x28
	.4byte 0x50
	.4byte EverGrandeCity_MapBorder
	.4byte EverGrandeCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_EverGrande

