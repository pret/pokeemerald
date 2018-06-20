	.align 2
Route110_TrickHouseEntrance_MapBorder::
	.incbin "data/layouts/Route110_TrickHouseEntrance/border.bin"

	.align 2
Route110_TrickHouseEntrance_MapBlockdata::
	.incbin "data/layouts/Route110_TrickHouseEntrance/map.bin"

	.align 2
Route110_TrickHouseEntrance_Layout::
	.4byte 0xc
	.4byte 0x8
	.4byte Route110_TrickHouseEntrance_MapBorder
	.4byte Route110_TrickHouseEntrance_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
