	.align 2
SecretBase_Tree1_MapBorder::
	.incbin "data/layouts/SecretBase_Tree1/border.bin"

	.align 2
SecretBase_Tree1_MapBlockdata::
	.incbin "data/layouts/SecretBase_Tree1/map.bin"

	.align 2
SecretBase_Tree1_Layout::
	.4byte 0xb
	.4byte 0x9
	.4byte SecretBase_Tree1_MapBorder
	.4byte SecretBase_Tree1_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseTree
