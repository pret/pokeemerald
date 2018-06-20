	.align 2
UnknownMap_084693AC_MapBorder::
	.incbin "data/layouts/UnknownMap_084693AC/border.bin"

	.align 2
UnknownMap_084693AC_MapBlockdata::
	.incbin "data/layouts/UnknownMap_084693AC/map.bin"

	.align 2
UnknownMap_084693AC_Layout::
	.4byte 0x1
	.4byte 0x1
	.4byte UnknownMap_084693AC_MapBorder
	.4byte UnknownMap_084693AC_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattlePike
