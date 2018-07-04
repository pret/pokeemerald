SlateportCity_PokemonFanClub_MapBorder::
	.incbin "data/layouts/SlateportCity_PokemonFanClub/border.bin"

SlateportCity_PokemonFanClub_MapBlockdata::
	.incbin "data/layouts/SlateportCity_PokemonFanClub/map.bin"

	.align 2
SlateportCity_PokemonFanClub_Layout::
	.4byte 0xe
	.4byte 0xb
	.4byte SlateportCity_PokemonFanClub_MapBorder
	.4byte SlateportCity_PokemonFanClub_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_PokemonFanClub

