LinkContestRoom2_MapBorder::
	.incbin "data/layouts/LinkContestRoom2/border.bin"

LinkContestRoom2_MapBlockdata::
	.incbin "data/layouts/LinkContestRoom2/map.bin"

	.align 2
LinkContestRoom2_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte LinkContestRoom2_MapBorder
	.4byte LinkContestRoom2_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Contest

