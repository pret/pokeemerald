SecretBase_YellowCave4_MapBorder::
	.incbin "data/layouts/SecretBase_YellowCave4/border.bin"

SecretBase_YellowCave4_MapBlockdata::
	.incbin "data/layouts/SecretBase_YellowCave4/map.bin"

	.align 2
SecretBase_YellowCave4_Layout::
	.4byte 0xd
	.4byte 0xe
	.4byte SecretBase_YellowCave4_MapBorder
	.4byte SecretBase_YellowCave4_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseYellowCave

