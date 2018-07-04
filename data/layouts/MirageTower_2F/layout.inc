MirageTower_2F_MapBorder::
	.incbin "data/layouts/MirageTower_2F/border.bin"

MirageTower_2F_MapBlockdata::
	.incbin "data/layouts/MirageTower_2F/map.bin"

	.align 2
MirageTower_2F_Layout::
	.4byte 0x15
	.4byte 0x11
	.4byte MirageTower_2F_MapBorder
	.4byte MirageTower_2F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MirageTower

