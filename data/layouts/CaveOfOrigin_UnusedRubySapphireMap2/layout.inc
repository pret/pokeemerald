	.align 2
CaveOfOrigin_UnusedRubySapphireMap2_MapBorder::
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap2/border.bin"

	.align 2
CaveOfOrigin_UnusedRubySapphireMap2_MapBlockdata::
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap2/map.bin"

	.align 2
CaveOfOrigin_UnusedRubySapphireMap2_Layout::
	.4byte 0x15
	.4byte 0x15
	.4byte CaveOfOrigin_UnusedRubySapphireMap2_MapBorder
	.4byte CaveOfOrigin_UnusedRubySapphireMap2_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
