	.align 2
MirageTower_1F_MapBorder::
	.incbin "data/layouts/MirageTower_1F/border.bin"

	.align 2
MirageTower_1F_MapBlockdata::
	.incbin "data/layouts/MirageTower_1F/map.bin"

	.align 2
MirageTower_1F_Layout::
	.4byte 0x15
	.4byte 0x11
	.4byte MirageTower_1F_MapBorder
	.4byte MirageTower_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MirageTower
