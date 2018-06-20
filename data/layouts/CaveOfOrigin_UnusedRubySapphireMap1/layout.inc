CaveOfOrigin_UnusedRubySapphireMap1_MapBorder::
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap1/border.bin"

CaveOfOrigin_UnusedRubySapphireMap1_MapBlockdata::
	.incbin "data/layouts/CaveOfOrigin_UnusedRubySapphireMap1/map.bin"

	.align 2
CaveOfOrigin_UnusedRubySapphireMap1_Layout::
	.4byte 0x17
	.4byte 0x17
	.4byte CaveOfOrigin_UnusedRubySapphireMap1_MapBorder
	.4byte CaveOfOrigin_UnusedRubySapphireMap1_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave

