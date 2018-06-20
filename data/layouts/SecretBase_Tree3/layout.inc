	.align 2
SecretBase_Tree3_MapBorder::
	.incbin "data/layouts/SecretBase_Tree3/border.bin"

	.align 2
SecretBase_Tree3_MapBlockdata::
	.incbin "data/layouts/SecretBase_Tree3/map.bin"

	.align 2
SecretBase_Tree3_Layout::
	.4byte 0x11
	.4byte 0x8
	.4byte SecretBase_Tree3_MapBorder
	.4byte SecretBase_Tree3_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseTree
