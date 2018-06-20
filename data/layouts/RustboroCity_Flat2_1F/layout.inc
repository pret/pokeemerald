RustboroCity_Flat2_1F_MapBorder::
	.incbin "data/layouts/RustboroCity_Flat2_1F/border.bin"

RustboroCity_Flat2_1F_MapBlockdata::
	.incbin "data/layouts/RustboroCity_Flat2_1F/map.bin"

	.align 2
RustboroCity_Flat2_1F_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte RustboroCity_Flat2_1F_MapBorder
	.4byte RustboroCity_Flat2_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

