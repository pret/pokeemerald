AquaHideout_UnusedRubyMap3_MapBorder::
	.incbin "data/layouts/AquaHideout_UnusedRubyMap3/border.bin"

AquaHideout_UnusedRubyMap3_MapBlockdata::
	.incbin "data/layouts/AquaHideout_UnusedRubyMap3/map.bin"

	.align 2
AquaHideout_UnusedRubyMap3_Layout::
	.4byte 0x22
	.4byte 0x18
	.4byte AquaHideout_UnusedRubyMap3_MapBorder
	.4byte AquaHideout_UnusedRubyMap3_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility

