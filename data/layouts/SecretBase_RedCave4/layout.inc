SecretBase_RedCave4_MapBorder::
	.incbin "data/layouts/SecretBase_RedCave4/border.bin"

SecretBase_RedCave4_MapBlockdata::
	.incbin "data/layouts/SecretBase_RedCave4/map.bin"

	.align 2
SecretBase_RedCave4_Layout::
	.4byte 0x9
	.4byte 0xf
	.4byte SecretBase_RedCave4_MapBorder
	.4byte SecretBase_RedCave4_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseRedCave

