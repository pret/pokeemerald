	.align 2
EverGrandeCity_PokemonLeague_1F_MapBorder::
	.incbin "data/layouts/EverGrandeCity_PokemonLeague_1F/border.bin"

	.align 2
EverGrandeCity_PokemonLeague_1F_MapBlockdata::
	.incbin "data/layouts/EverGrandeCity_PokemonLeague_1F/map.bin"

	.align 2
EverGrandeCity_PokemonLeague_1F_Layout::
	.4byte 0x13
	.4byte 0xc
	.4byte EverGrandeCity_PokemonLeague_1F_MapBorder
	.4byte EverGrandeCity_PokemonLeague_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_PokemonCenter
