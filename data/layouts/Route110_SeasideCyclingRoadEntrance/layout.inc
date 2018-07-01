Route110_SeasideCyclingRoadEntrance_MapBorder::
	.incbin "data/layouts/Route110_SeasideCyclingRoadEntrance/border.bin"

Route110_SeasideCyclingRoadEntrance_MapBlockdata::
	.incbin "data/layouts/Route110_SeasideCyclingRoadEntrance/map.bin"

	.align 2
Route110_SeasideCyclingRoadEntrance_Layout::
	.4byte 0xf
	.4byte 0x6
	.4byte Route110_SeasideCyclingRoadEntrance_MapBorder
	.4byte Route110_SeasideCyclingRoadEntrance_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Shop

