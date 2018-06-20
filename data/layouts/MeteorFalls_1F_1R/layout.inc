	.align 2
MeteorFalls_1F_1R_MapBorder::
	.incbin "data/layouts/MeteorFalls_1F_1R/border.bin"

	.align 2
MeteorFalls_1F_1R_MapBlockdata::
	.incbin "data/layouts/MeteorFalls_1F_1R/map.bin"

	.align 2
MeteorFalls_1F_1R_Layout::
	.4byte 0x1e
	.4byte 0x2a
	.4byte MeteorFalls_1F_1R_MapBorder
	.4byte MeteorFalls_1F_1R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MeteorFalls
