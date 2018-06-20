	.align 2
RustboroCity_PokemonSchool_MapBorder::
	.incbin "data/layouts/RustboroCity_PokemonSchool/border.bin"

	.align 2
RustboroCity_PokemonSchool_MapBlockdata::
	.incbin "data/layouts/RustboroCity_PokemonSchool/map.bin"

	.align 2
RustboroCity_PokemonSchool_Layout::
	.4byte 0xc
	.4byte 0xb
	.4byte RustboroCity_PokemonSchool_MapBorder
	.4byte RustboroCity_PokemonSchool_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_PokemonSchool
