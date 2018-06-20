LinkContestRoom3_MapBorder::
	.incbin "data/layouts/LinkContestRoom3/border.bin"

LinkContestRoom3_MapBlockdata::
	.incbin "data/layouts/LinkContestRoom3/map.bin"

	.align 2
LinkContestRoom3_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte LinkContestRoom3_MapBorder
	.4byte LinkContestRoom3_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Contest

