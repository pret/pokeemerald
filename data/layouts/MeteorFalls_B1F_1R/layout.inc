MeteorFalls_B1F_1R_MapBorder::
	.incbin "data/layouts/MeteorFalls_B1F_1R/border.bin"

MeteorFalls_B1F_1R_MapBlockdata::
	.incbin "data/layouts/MeteorFalls_B1F_1R/map.bin"

	.align 2
MeteorFalls_B1F_1R_Layout::
	.4byte 0x1d
	.4byte 0x26
	.4byte MeteorFalls_B1F_1R_MapBorder
	.4byte MeteorFalls_B1F_1R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MeteorFalls

