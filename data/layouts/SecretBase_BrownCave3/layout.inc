	.align 2
SecretBase_BrownCave3_MapBorder::
	.incbin "data/layouts/SecretBase_BrownCave3/border.bin"

	.align 2
SecretBase_BrownCave3_MapBlockdata::
	.incbin "data/layouts/SecretBase_BrownCave3/map.bin"

	.align 2
SecretBase_BrownCave3_Layout::
	.4byte 0xf
	.4byte 0xb
	.4byte SecretBase_BrownCave3_MapBorder
	.4byte SecretBase_BrownCave3_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseBrownCave
