	.align 2
LinkContestRoom4_MapBorder::
	.incbin "data/layouts/LinkContestRoom4/border.bin"

	.align 2
LinkContestRoom4_MapBlockdata::
	.incbin "data/layouts/LinkContestRoom4/map.bin"

	.align 2
LinkContestRoom4_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte LinkContestRoom4_MapBorder
	.4byte LinkContestRoom4_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Contest
