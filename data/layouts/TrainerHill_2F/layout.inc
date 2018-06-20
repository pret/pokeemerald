TrainerHill_2F_MapBorder::
	.incbin "data/layouts/TrainerHill_2F/border.bin"

TrainerHill_2F_MapBlockdata::
	.incbin "data/layouts/TrainerHill_2F/map.bin"

	.align 2
TrainerHill_2F_Layout::
	.4byte 0x10
	.4byte 0x15
	.4byte TrainerHill_2F_MapBorder
	.4byte TrainerHill_2F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrainerHill

