PokemonCenter_1F_MapBorder::
	.incbin "data/layouts/PokemonCenter_1F/border.bin"

PokemonCenter_1F_MapBlockdata::
	.incbin "data/layouts/PokemonCenter_1F/map.bin"

	.align 2
PokemonCenter_1F_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte PokemonCenter_1F_MapBorder
	.4byte PokemonCenter_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_PokemonCenter

