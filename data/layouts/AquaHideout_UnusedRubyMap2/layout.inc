AquaHideout_UnusedRubyMap2_MapBorder::
	.incbin "data/layouts/AquaHideout_UnusedRubyMap2/border.bin"

AquaHideout_UnusedRubyMap2_MapBlockdata::
	.incbin "data/layouts/AquaHideout_UnusedRubyMap2/map.bin"

	.align 2
AquaHideout_UnusedRubyMap2_Layout::
	.4byte 0x3e
	.4byte 0x18
	.4byte AquaHideout_UnusedRubyMap2_MapBorder
	.4byte AquaHideout_UnusedRubyMap2_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

