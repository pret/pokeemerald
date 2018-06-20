	.align 2
SecretBase_Shrub3_MapBorder::
	.incbin "data/layouts/SecretBase_Shrub3/border.bin"

	.align 2
SecretBase_Shrub3_MapBlockdata::
	.incbin "data/layouts/SecretBase_Shrub3/map.bin"

	.align 2
SecretBase_Shrub3_Layout::
	.4byte 0xd
	.4byte 0xb
	.4byte SecretBase_Shrub3_MapBorder
	.4byte SecretBase_Shrub3_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseShrub
