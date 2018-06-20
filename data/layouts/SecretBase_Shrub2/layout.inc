	.align 2
SecretBase_Shrub2_MapBorder::
	.incbin "data/layouts/SecretBase_Shrub2/border.bin"

	.align 2
SecretBase_Shrub2_MapBlockdata::
	.incbin "data/layouts/SecretBase_Shrub2/map.bin"

	.align 2
SecretBase_Shrub2_Layout::
	.4byte 0xf
	.4byte 0x7
	.4byte SecretBase_Shrub2_MapBorder
	.4byte SecretBase_Shrub2_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseShrub
