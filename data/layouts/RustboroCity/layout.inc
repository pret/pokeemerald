	.align 2
RustboroCity_MapBorder::
	.incbin "data/layouts/RustboroCity/border.bin"

	.align 2
RustboroCity_MapBlockdata::
	.incbin "data/layouts/RustboroCity/map.bin"

	.align 2
RustboroCity_Layout::
	.4byte 0x28
	.4byte 0x3c
	.4byte RustboroCity_MapBorder
	.4byte RustboroCity_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Rustboro
