EverGrandeCity_HallOfFame_MapBorder::
	.incbin "data/layouts/EverGrandeCity_HallOfFame/border.bin"

EverGrandeCity_HallOfFame_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_HallOfFame/map.bin"

	.align 2
EverGrandeCity_HallOfFame_Layout::
	.4byte 0xf
	.4byte 0x11
	.4byte EverGrandeCity_HallOfFame_MapBorder
	.4byte EverGrandeCity_HallOfFame_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_CableClub

