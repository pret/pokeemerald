RustboroCity_House_MapBorder::
	.incbin "data/layouts/RustboroCity_House/border.bin"

RustboroCity_House_MapBlockdata::
	.incbin "data/layouts/RustboroCity_House/map.bin"

	.align 2
RustboroCity_House_Layout::
	.4byte 0xc
	.4byte 0x9
	.4byte RustboroCity_House_MapBorder
	.4byte RustboroCity_House_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

