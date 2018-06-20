	.align 2
UnknownMap_08480DAC_MapBorder::
	.incbin "data/layouts/UnknownMap_08480DAC/border.bin"

	.align 2
UnknownMap_08480DAC_MapBlockdata::
	.incbin "data/layouts/UnknownMap_08480DAC/map.bin"

	.align 2
UnknownMap_08480DAC_Layout::
	.4byte 0xD
	.4byte 0xD
	.4byte UnknownMap_08480DAC_MapBorder
	.4byte UnknownMap_08480DAC_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Lab
