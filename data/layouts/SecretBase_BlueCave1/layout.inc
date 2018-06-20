SecretBase_BlueCave1_MapBorder::
	.incbin "data/layouts/SecretBase_BlueCave1/border.bin"

SecretBase_BlueCave1_MapBlockdata::
	.incbin "data/layouts/SecretBase_BlueCave1/map.bin"

	.align 2
SecretBase_BlueCave1_Layout::
	.4byte 0xb
	.4byte 0x9
	.4byte SecretBase_BlueCave1_MapBorder
	.4byte SecretBase_BlueCave1_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseBlueCave

