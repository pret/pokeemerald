	.align 2
SecretBase_BlueCave2_MapBorder::
	.incbin "data/layouts/SecretBase_BlueCave2/border.bin"

	.align 2
SecretBase_BlueCave2_MapBlockdata::
	.incbin "data/layouts/SecretBase_BlueCave2/map.bin"

	.align 2
SecretBase_BlueCave2_Layout::
	.4byte 0xf
	.4byte 0x7
	.4byte SecretBase_BlueCave2_MapBorder
	.4byte SecretBase_BlueCave2_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseBlueCave
