EverGrandeCity_DrakesRoom_MapBorder::
	.incbin "data/layouts/EverGrandeCity_DrakesRoom/border.bin"

EverGrandeCity_DrakesRoom_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_DrakesRoom/map.bin"

	.align 2
EverGrandeCity_DrakesRoom_Layout::
	.4byte 0xd
	.4byte 0xe
	.4byte EverGrandeCity_DrakesRoom_MapBorder
	.4byte EverGrandeCity_DrakesRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_EliteFour

