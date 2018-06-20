	.align 2
AquaHideout_UnusedRubyMap1_MapBorder::
	.incbin "data/layouts/AquaHideout_UnusedRubyMap1/border.bin"

	.align 2
AquaHideout_UnusedRubyMap1_MapBlockdata::
	.incbin "data/layouts/AquaHideout_UnusedRubyMap1/map.bin"

	.align 2
AquaHideout_UnusedRubyMap1_Layout::
	.4byte 0x1c
	.4byte 0x1e
	.4byte AquaHideout_UnusedRubyMap1_MapBorder
	.4byte AquaHideout_UnusedRubyMap1_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
