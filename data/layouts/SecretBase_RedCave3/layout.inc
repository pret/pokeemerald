	.align 2
SecretBase_RedCave3_MapBorder::
	.incbin "data/layouts/SecretBase_RedCave3/border.bin"

	.align 2
SecretBase_RedCave3_MapBlockdata::
	.incbin "data/layouts/SecretBase_RedCave3/map.bin"

	.align 2
SecretBase_RedCave3_Layout::
	.4byte 0xf
	.4byte 0x8
	.4byte SecretBase_RedCave3_MapBorder
	.4byte SecretBase_RedCave3_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseRedCave
