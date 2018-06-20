RustboroCity_CuttersHouse_MapBorder::
	.incbin "data/layouts/RustboroCity_CuttersHouse/border.bin"

RustboroCity_CuttersHouse_MapBlockdata::
	.incbin "data/layouts/RustboroCity_CuttersHouse/map.bin"

	.align 2
RustboroCity_CuttersHouse_Layout::
	.4byte 0xb
	.4byte 0x9
	.4byte RustboroCity_CuttersHouse_MapBorder
	.4byte RustboroCity_CuttersHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

