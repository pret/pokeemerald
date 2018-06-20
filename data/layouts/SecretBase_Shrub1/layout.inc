SecretBase_Shrub1_MapBorder::
	.incbin "data/layouts/SecretBase_Shrub1/border.bin"

SecretBase_Shrub1_MapBlockdata::
	.incbin "data/layouts/SecretBase_Shrub1/map.bin"

	.align 2
SecretBase_Shrub1_Layout::
	.4byte 0xb
	.4byte 0x9
	.4byte SecretBase_Shrub1_MapBorder
	.4byte SecretBase_Shrub1_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseShrub

