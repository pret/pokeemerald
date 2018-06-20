LinkContestRoom5_MapBorder::
	.incbin "data/layouts/LinkContestRoom5/border.bin"

LinkContestRoom5_MapBlockdata::
	.incbin "data/layouts/LinkContestRoom5/map.bin"

	.align 2
LinkContestRoom5_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte LinkContestRoom5_MapBorder
	.4byte LinkContestRoom5_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Contest

