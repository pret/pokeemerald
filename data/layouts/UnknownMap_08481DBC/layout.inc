	.align 2
UnknownMap_08481DBC_MapBorder::
	.incbin "data/layouts/UnknownMap_08481DBC/border.bin"

	.align 2
UnknownMap_08481DBC_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08481DBC/map.bin"

	.align 2
UnknownMap_08481DBC_Layout::
	.4byte 0xB
	.4byte 0x8
	.4byte UnknownMap_08481DBC_MapBorder
	.4byte UnknownMap_08481DBC_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_MysteryEventsHouse
