	.align 2
Route119_WeatherInstitute_2F_MapBorder::
	.incbin "data/layouts/Route119_WeatherInstitute_2F/border.bin"

	.align 2
Route119_WeatherInstitute_2F_MapBlockdata::
	.incbin "data/layouts/Route119_WeatherInstitute_2F/map.bin"

	.align 2
Route119_WeatherInstitute_2F_Layout::
	.4byte 0x14
	.4byte 0xb
	.4byte Route119_WeatherInstitute_2F_MapBorder
	.4byte Route119_WeatherInstitute_2F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Lab
