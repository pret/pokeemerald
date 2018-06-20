	.align 2
LilycoveCity_ContestLobby_MapBorder::
	.incbin "data/layouts/LilycoveCity_ContestLobby/border.bin"

	.align 2
LilycoveCity_ContestLobby_MapBlockdata::
	.incbin "data/layouts/LilycoveCity_ContestLobby/map.bin"

	.align 2
LilycoveCity_ContestLobby_Layout::
	.4byte 0x1f
	.4byte 0xc
	.4byte LilycoveCity_ContestLobby_MapBorder
	.4byte LilycoveCity_ContestLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest
