EverGrandeCity_ChampionsRoom_MapBorder::
	.incbin "data/layouts/EverGrandeCity_ChampionsRoom/border.bin"

EverGrandeCity_ChampionsRoom_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_ChampionsRoom/map.bin"

	.align 2
EverGrandeCity_ChampionsRoom_Layout::
	.4byte 0xd
	.4byte 0xd
	.4byte EverGrandeCity_ChampionsRoom_MapBorder
	.4byte EverGrandeCity_ChampionsRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_EliteFour

