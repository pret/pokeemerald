SecretBase_RedCave2_MapBorder::
	.incbin "data/layouts/SecretBase_RedCave2/border.bin"

SecretBase_RedCave2_MapBlockdata::
	.incbin "data/layouts/SecretBase_RedCave2/map.bin"

	.align 2
SecretBase_RedCave2_Layout::
	.4byte 0x7
	.4byte 0x10
	.4byte SecretBase_RedCave2_MapBorder
	.4byte SecretBase_RedCave2_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseRedCave

