TradeCenter_MapBorder::
	.incbin "data/layouts/TradeCenter/border.bin"

TradeCenter_MapBlockdata::
	.incbin "data/layouts/TradeCenter/map.bin"

	.align 2
TradeCenter_Layout::
	.4byte 0xc
	.4byte 0x9
	.4byte TradeCenter_MapBorder
	.4byte TradeCenter_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_CableClub

