EverGrandeCity_SidneysRoom_MapBorder::
	.incbin "data/layouts/EverGrandeCity_SidneysRoom/border.bin"

EverGrandeCity_SidneysRoom_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_SidneysRoom/map.bin"

	.align 2
EverGrandeCity_SidneysRoom_Layout::
	.4byte 0xd
	.4byte 0xe
	.4byte EverGrandeCity_SidneysRoom_MapBorder
	.4byte EverGrandeCity_SidneysRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_EliteFour

