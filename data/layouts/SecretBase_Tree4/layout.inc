SecretBase_Tree4_MapBorder::
	.incbin "data/layouts/SecretBase_Tree4/border.bin"

SecretBase_Tree4_MapBlockdata::
	.incbin "data/layouts/SecretBase_Tree4/map.bin"

	.align 2
SecretBase_Tree4_Layout::
	.4byte 0xe
	.4byte 0xe
	.4byte SecretBase_Tree4_MapBorder
	.4byte SecretBase_Tree4_MapBlockdata
	.4byte gTileset_SecretBase
	.4byte gTileset_SecretBaseTree

