	.align 2
LavaridgeTown_PokemonCenter_1F_MapBorder::
	.incbin "data/layouts/LavaridgeTown_PokemonCenter_1F/border.bin"

	.align 2
LavaridgeTown_PokemonCenter_1F_MapBlockdata::
	.incbin "data/layouts/LavaridgeTown_PokemonCenter_1F/map.bin"

	.align 2
LavaridgeTown_PokemonCenter_1F_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte LavaridgeTown_PokemonCenter_1F_MapBorder
	.4byte LavaridgeTown_PokemonCenter_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_PokemonCenter
