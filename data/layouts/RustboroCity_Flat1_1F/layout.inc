RustboroCity_Flat1_1F_MapBorder::
	.incbin "data/layouts/RustboroCity_Flat1_1F/border.bin"

RustboroCity_Flat1_1F_MapBlockdata::
	.incbin "data/layouts/RustboroCity_Flat1_1F/map.bin"

	.align 2
RustboroCity_Flat1_1F_Layout::
	.4byte 0xe
	.4byte 0x8
	.4byte RustboroCity_Flat1_1F_MapBorder
	.4byte RustboroCity_Flat1_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

