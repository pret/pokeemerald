	.align 2
MirageTower_4F_MapBorder::
	.incbin "data/layouts/MirageTower_4F/border.bin"

	.align 2
MirageTower_4F_MapBlockdata::
	.incbin "data/layouts/MirageTower_4F/map.bin"

	.align 2
MirageTower_4F_Layout::
	.4byte 0xd
	.4byte 0xa
	.4byte MirageTower_4F_MapBorder
	.4byte MirageTower_4F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_MirageTower
