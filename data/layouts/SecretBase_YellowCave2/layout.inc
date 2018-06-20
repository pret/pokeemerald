	.align 2
SecretBase_YellowCave2_MapBorder::
	.incbin "data/layouts/SecretBase_YellowCave2/border.bin"

	.align 2
SecretBase_YellowCave2_MapBlockdata::
	.incbin "data/layouts/SecretBase_YellowCave2/map.bin"

	.align 2
SecretBase_YellowCave2_Layout::
	.4byte 0xe
	.4byte 0x9
	.4byte SecretBase_YellowCave2_MapBorder
	.4byte SecretBase_YellowCave2_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseYellowCave
