	.align 2
UnionRoom_MapBorder::
	.incbin "data/layouts/UnionRoom/border.bin"

	.align 2
UnionRoom_MapBlockdata::
	.incbin "data/layouts/UnionRoom/map.bin"

	.align 2
UnionRoom_Layout::
	.4byte 0xf
	.4byte 0xc
	.4byte UnionRoom_MapBorder
	.4byte UnionRoom_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_UnionRoom
