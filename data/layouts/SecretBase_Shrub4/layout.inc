	.align 2
SecretBase_Shrub4_MapBorder::
	.incbin "data/layouts/SecretBase_Shrub4/border.bin"

	.align 2
SecretBase_Shrub4_MapBlockdata::
	.incbin "data/layouts/SecretBase_Shrub4/map.bin"

	.align 2
SecretBase_Shrub4_Layout::
	.4byte 0xe
	.4byte 0xb
	.4byte SecretBase_Shrub4_MapBorder
	.4byte SecretBase_Shrub4_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseShrub
