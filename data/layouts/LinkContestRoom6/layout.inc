LinkContestRoom6_MapBorder::
	.incbin "data/layouts/LinkContestRoom6/border.bin"

LinkContestRoom6_MapBlockdata::
	.incbin "data/layouts/LinkContestRoom6/map.bin"

	.align 2
LinkContestRoom6_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte LinkContestRoom6_MapBorder
	.4byte LinkContestRoom6_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Contest

