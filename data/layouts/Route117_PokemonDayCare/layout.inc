	.align 2
Route117_PokemonDayCare_MapBorder::
	.incbin "data/layouts/Route117_PokemonDayCare/border.bin"

	.align 2
Route117_PokemonDayCare_MapBlockdata::
	.incbin "data/layouts/Route117_PokemonDayCare/map.bin"

	.align 2
Route117_PokemonDayCare_Layout::
	.4byte 0xc
	.4byte 0x9
	.4byte Route117_PokemonDayCare_MapBorder
	.4byte Route117_PokemonDayCare_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_PokemonDayCare
