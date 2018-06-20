	.align 2
EverGrandeCity_GlaciasRoom_MapBorder::
	.incbin "data/layouts/EverGrandeCity_GlaciasRoom/border.bin"

	.align 2
EverGrandeCity_GlaciasRoom_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_GlaciasRoom/map.bin"

	.align 2
EverGrandeCity_GlaciasRoom_Layout::
	.4byte 0xd
	.4byte 0xe
	.4byte EverGrandeCity_GlaciasRoom_MapBorder
	.4byte EverGrandeCity_GlaciasRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_EliteFour
