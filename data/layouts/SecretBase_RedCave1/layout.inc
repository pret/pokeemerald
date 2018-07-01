SecretBase_RedCave1_MapBorder::
	.incbin "data/layouts/SecretBase_RedCave1/border.bin"

SecretBase_RedCave1_MapBlockdata::
	.incbin "data/layouts/SecretBase_RedCave1/map.bin"

	.align 2
SecretBase_RedCave1_Layout::
	.4byte 0xb
	.4byte 0x9
	.4byte SecretBase_RedCave1_MapBorder
	.4byte SecretBase_RedCave1_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseRedCave

