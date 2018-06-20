	.align 2
ScorchedSlab_MapBorder::
	.incbin "data/layouts/ScorchedSlab/border.bin"

	.align 2
ScorchedSlab_MapBlockdata::
	.incbin "data/layouts/ScorchedSlab/map.bin"

	.align 2
ScorchedSlab_Layout::
	.4byte 0xf
	.4byte 0x14
	.4byte ScorchedSlab_MapBorder
	.4byte ScorchedSlab_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
