	.align 2
TrainerHill_4F_MapBorder::
	.incbin "data/layouts/TrainerHill_4F/border.bin"

	.align 2
TrainerHill_4F_MapBlockdata::
	.incbin "data/layouts/TrainerHill_4F/map.bin"

	.align 2
TrainerHill_4F_Layout::
	.4byte 0x10
	.4byte 0x15
	.4byte TrainerHill_4F_MapBorder
	.4byte TrainerHill_4F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrainerHill
