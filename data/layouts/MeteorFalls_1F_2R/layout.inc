	.align 2
MeteorFalls_1F_2R_MapBorder::
	.incbin "data/layouts/MeteorFalls_1F_2R/border.bin"

	.align 2
MeteorFalls_1F_2R_MapBlockdata::
	.incbin "data/layouts/MeteorFalls_1F_2R/map.bin"

	.align 2
MeteorFalls_1F_2R_Layout::
	.4byte 0x1e
	.4byte 0x20
	.4byte MeteorFalls_1F_2R_MapBorder
	.4byte MeteorFalls_1F_2R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MeteorFalls
