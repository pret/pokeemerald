LinkContestRoom1_MapBorder::
	.incbin "data/layouts/LinkContestRoom1/border.bin"

LinkContestRoom1_MapBlockdata::
	.incbin "data/layouts/LinkContestRoom1/map.bin"

	.align 2
LinkContestRoom1_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte LinkContestRoom1_MapBorder
	.4byte LinkContestRoom1_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Contest

