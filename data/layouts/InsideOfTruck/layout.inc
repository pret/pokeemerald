InsideOfTruck_MapBorder::
	.incbin "data/layouts/InsideOfTruck/border.bin"

InsideOfTruck_MapBlockdata::
	.incbin "data/layouts/InsideOfTruck/map.bin"

	.align 2
InsideOfTruck_Layout::
	.4byte 0x5
	.4byte 0x5
	.4byte InsideOfTruck_MapBorder
	.4byte InsideOfTruck_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_InsideOfTruck

