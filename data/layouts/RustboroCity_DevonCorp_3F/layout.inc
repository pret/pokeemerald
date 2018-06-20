	.align 2
RustboroCity_DevonCorp_3F_MapBorder::
	.incbin "data/layouts/RustboroCity_DevonCorp_3F/border.bin"

	.align 2
RustboroCity_DevonCorp_3F_MapBlockdata::
	.incbin "data/layouts/RustboroCity_DevonCorp_3F/map.bin"

	.align 2
RustboroCity_DevonCorp_3F_Layout::
	.4byte 0x13
	.4byte 0x9
	.4byte RustboroCity_DevonCorp_3F_MapBorder
	.4byte RustboroCity_DevonCorp_3F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Facility
