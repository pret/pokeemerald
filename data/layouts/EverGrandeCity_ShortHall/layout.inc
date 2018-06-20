	.align 2
EverGrandeCity_ShortHall_MapBorder::
	.incbin "data/layouts/EverGrandeCity_ShortHall/border.bin"

	.align 2
EverGrandeCity_ShortHall_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_ShortHall/map.bin"

	.align 2
EverGrandeCity_ShortHall_Layout::
	.4byte 0xb
	.4byte 0xd
	.4byte EverGrandeCity_ShortHall_MapBorder
	.4byte EverGrandeCity_ShortHall_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_EliteFour
