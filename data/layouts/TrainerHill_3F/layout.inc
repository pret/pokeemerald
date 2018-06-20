	.align 2
TrainerHill_3F_MapBorder::
	.incbin "data/layouts/TrainerHill_3F/border.bin"

	.align 2
TrainerHill_3F_MapBlockdata::
	.incbin "data/layouts/TrainerHill_3F/map.bin"

	.align 2
TrainerHill_3F_Layout::
	.4byte 0x10
	.4byte 0x15
	.4byte TrainerHill_3F_MapBorder
	.4byte TrainerHill_3F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrainerHill
