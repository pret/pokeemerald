	.align 2
AquaHideout_1F_MapBorder::
	.incbin "data/layouts/AquaHideout_1F/border.bin"

	.align 2
AquaHideout_1F_MapBlockdata::
	.incbin "data/layouts/AquaHideout_1F/map.bin"

	.align 2
AquaHideout_1F_Layout::
	.4byte 0x1c
	.4byte 0x1e
	.4byte AquaHideout_1F_MapBorder
	.4byte AquaHideout_1F_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Facility
