	.align 2
FallarborTown_LeftoverRSContestHall_MapBorder::
	.incbin "data/layouts/FallarborTown_LeftoverRSContestHall/border.bin"

	.align 2
FallarborTown_LeftoverRSContestHall_MapBlockdata::
	.incbin "data/layouts/FallarborTown_LeftoverRSContestHall/map.bin"

	.align 2
FallarborTown_LeftoverRSContestHall_Layout::
	.4byte 0x15
	.4byte 0x12
	.4byte FallarborTown_LeftoverRSContestHall_MapBorder
	.4byte FallarborTown_LeftoverRSContestHall_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Contest
