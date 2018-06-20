	.align 2
SecretBase_YellowCave3_MapBorder::
	.incbin "data/layouts/SecretBase_YellowCave3/border.bin"

	.align 2
SecretBase_YellowCave3_MapBlockdata::
	.incbin "data/layouts/SecretBase_YellowCave3/map.bin"

	.align 2
SecretBase_YellowCave3_Layout::
	.4byte 0xc
	.4byte 0xb
	.4byte SecretBase_YellowCave3_MapBorder
	.4byte SecretBase_YellowCave3_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseYellowCave
