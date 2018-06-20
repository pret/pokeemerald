	.align 2
AquaHideout_B1F_MapBorder::
	.incbin "data/layouts/AquaHideout_B1F/border.bin"

	.align 2
AquaHideout_B1F_MapBlockdata::
	.incbin "data/layouts/AquaHideout_B1F/map.bin"

	.align 2
AquaHideout_B1F_Layout::
	.4byte 0x33
	.4byte 0x18
	.4byte AquaHideout_B1F_MapBorder
	.4byte AquaHideout_B1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
