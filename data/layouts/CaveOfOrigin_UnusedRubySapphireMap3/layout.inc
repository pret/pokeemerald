	.align 2
CaveOfOrigin_UnusedRubySapphireMap3_MapBorder::
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap3/border.bin"

	.align 2
CaveOfOrigin_UnusedRubySapphireMap3_MapBlockdata::
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap3/map.bin"

	.align 2
CaveOfOrigin_UnusedRubySapphireMap3_Layout::
	.4byte 0x13
	.4byte 0x15
	.4byte CaveOfOrigin_UnusedRubySapphireMap3_MapBorder
	.4byte CaveOfOrigin_UnusedRubySapphireMap3_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
