	.align 2
MossdeepCity_SpaceCenter_2F_MapBorder::
	.incbin "data/layouts/MossdeepCity_SpaceCenter_2F/border.bin"

	.align 2
MossdeepCity_SpaceCenter_2F_MapBlockdata::
	.incbin "data/layouts/MossdeepCity_SpaceCenter_2F/map.bin"

	.align 2
MossdeepCity_SpaceCenter_2F_Layout::
	.4byte 0x10
	.4byte 0xa
	.4byte MossdeepCity_SpaceCenter_2F_MapBorder
	.4byte MossdeepCity_SpaceCenter_2F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
