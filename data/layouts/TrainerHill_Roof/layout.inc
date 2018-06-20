	.align 2
TrainerHill_Roof_MapBorder::
	.incbin "data/layouts/TrainerHill_Roof/border.bin"

	.align 2
TrainerHill_Roof_MapBlockdata::
	.incbin "data/layouts/TrainerHill_Roof/map.bin"

	.align 2
TrainerHill_Roof_Layout::
	.4byte 0x19
	.4byte 0x10
	.4byte TrainerHill_Roof_MapBorder
	.4byte TrainerHill_Roof_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrainerHill
