MirageTower_3F_MapBorder::
	.incbin "data/layouts/MirageTower_3F/border.bin"

MirageTower_3F_MapBlockdata::
	.incbin "data/layouts/MirageTower_3F/map.bin"

	.align 2
MirageTower_3F_Layout::
	.4byte 0x15
	.4byte 0x11
	.4byte MirageTower_3F_MapBorder
	.4byte MirageTower_3F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MirageTower

