FieryPath_MapBorder::
	.incbin "data/layouts/FieryPath/border.bin"

FieryPath_MapBlockdata::
	.incbin "data/layouts/FieryPath/map.bin"

	.align 2
FieryPath_Layout::
	.4byte 0x23
	.4byte 0x26
	.4byte FieryPath_MapBorder
	.4byte FieryPath_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Lavaridge

