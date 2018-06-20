	.align 2
FallarborTown_LeftoverRSContestLobby_MapBorder::
	.incbin "data/layouts/FallarborTown_LeftoverRSContestLobby/border.bin"

	.align 2
FallarborTown_LeftoverRSContestLobby_MapBlockdata::
	.incbin "data/layouts/FallarborTown_LeftoverRSContestLobby/map.bin"

	.align 2
FallarborTown_LeftoverRSContestLobby_Layout::
	.4byte 0xf
	.4byte 0x7
	.4byte FallarborTown_LeftoverRSContestLobby_MapBorder
	.4byte FallarborTown_LeftoverRSContestLobby_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest
