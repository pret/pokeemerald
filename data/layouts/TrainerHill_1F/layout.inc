	.align 2
TrainerHill_1F_MapBorder::
	.incbin "data/layouts/TrainerHill_1F/border.bin"

	.align 2
TrainerHill_1F_MapBlockdata::
	.incbin "data/layouts/TrainerHill_1F/map.bin"

	.align 2
TrainerHill_1F_Layout::
	.4byte 0x10
	.4byte 0x15
	.4byte TrainerHill_1F_MapBorder
	.4byte TrainerHill_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrainerHill
