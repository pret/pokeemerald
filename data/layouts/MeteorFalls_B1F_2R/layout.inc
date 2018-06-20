	.align 2
MeteorFalls_B1F_2R_MapBorder::
	.incbin "data/layouts/MeteorFalls_B1F_2R/border.bin"

	.align 2
MeteorFalls_B1F_2R_MapBlockdata::
	.incbin "data/layouts/MeteorFalls_B1F_2R/map.bin"

	.align 2
MeteorFalls_B1F_2R_Layout::
	.4byte 0xb
	.4byte 0x12
	.4byte MeteorFalls_B1F_2R_MapBorder
	.4byte MeteorFalls_B1F_2R_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MeteorFalls
