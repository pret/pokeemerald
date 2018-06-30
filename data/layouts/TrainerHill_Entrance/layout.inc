TrainerHill_Entrance_MapBorder::
	.incbin "data/layouts/TrainerHill_Entrance/border.bin"

TrainerHill_Entrance_MapBlockdata::
	.incbin "data/layouts/TrainerHill_Entrance/map.bin"

	.align 2
TrainerHill_Entrance_Layout::
	.4byte 0x13
	.4byte 0x11
	.4byte TrainerHill_Entrance_MapBorder
	.4byte TrainerHill_Entrance_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_TrainerHill

