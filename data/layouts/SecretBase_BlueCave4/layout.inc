SecretBase_BlueCave4_MapBorder::
	.incbin "data/layouts/SecretBase_BlueCave4/border.bin"

SecretBase_BlueCave4_MapBlockdata::
	.incbin "data/layouts/SecretBase_BlueCave4/map.bin"

	.align 2
SecretBase_BlueCave4_Layout::
	.4byte 0x9
	.4byte 0x11
	.4byte SecretBase_BlueCave4_MapBorder
	.4byte SecretBase_BlueCave4_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseBlueCave

