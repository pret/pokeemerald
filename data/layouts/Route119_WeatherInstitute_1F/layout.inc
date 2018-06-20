	.align 2
Route119_WeatherInstitute_1F_MapBorder::
	.incbin "data/layouts/Route119_WeatherInstitute_1F/border.bin"

	.align 2
Route119_WeatherInstitute_1F_MapBlockdata::
	.incbin "data/layouts/Route119_WeatherInstitute_1F/map.bin"

	.align 2
Route119_WeatherInstitute_1F_Layout::
	.4byte 0x14
	.4byte 0xd
	.4byte Route119_WeatherInstitute_1F_MapBorder
	.4byte Route119_WeatherInstitute_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Lab
