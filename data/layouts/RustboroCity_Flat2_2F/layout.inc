	.align 2
RustboroCity_Flat2_2F_MapBorder::
	.incbin "data/layouts/RustboroCity_Flat2_2F/border.bin"

	.align 2
RustboroCity_Flat2_2F_MapBlockdata::
	.incbin "data/layouts/RustboroCity_Flat2_2F/map.bin"

	.align 2
RustboroCity_Flat2_2F_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte RustboroCity_Flat2_2F_MapBorder
	.4byte RustboroCity_Flat2_2F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
