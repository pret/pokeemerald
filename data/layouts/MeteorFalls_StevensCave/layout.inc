	.align 2
MeteorFalls_StevensCave_MapBorder::
	.incbin "data/layouts/MeteorFalls_StevensCave/border.bin"

	.align 2
MeteorFalls_StevensCave_MapBlockdata::
	.incbin "data/layouts/MeteorFalls_StevensCave/map.bin"

	.align 2
MeteorFalls_StevensCave_Layout::
	.4byte 0x1e
	.4byte 0x20
	.4byte MeteorFalls_StevensCave_MapBorder
	.4byte MeteorFalls_StevensCave_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MeteorFalls
