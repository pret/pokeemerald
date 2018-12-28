Route111_NoMirageTower_MapBorder::
	.incbin "data/layouts/Route111_NoMirageTower/border.bin"

Route111_NoMirageTower_MapBlockdata::
	.incbin "data/layouts/Route111_NoMirageTower/map.bin"

	.align 2
Route111_NoMirageTower_Layout::
	.4byte 0x28
	.4byte 0x8C
	.4byte Route111_NoMirageTower_MapBorder
	.4byte Route111_NoMirageTower_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mauville

