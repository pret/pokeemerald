	.align 2
RecordCorner_MapBorder::
	.incbin "data/layouts/RecordCorner/border.bin"

	.align 2
RecordCorner_MapBlockdata::
	.incbin "data/layouts/RecordCorner/map.bin"

	.align 2
RecordCorner_Layout::
	.4byte 0x14
	.4byte 0xa
	.4byte RecordCorner_MapBorder
	.4byte RecordCorner_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_CableClub
