	.align 2
Route114_LanettesHouse_MapBorder::
	.incbin "data/layouts/Route114_LanettesHouse/border.bin"

	.align 2
Route114_LanettesHouse_MapBlockdata::
	.incbin "data/layouts/Route114_LanettesHouse/map.bin"

	.align 2
Route114_LanettesHouse_Layout::
	.4byte 0xb
	.4byte 0x8
	.4byte Route114_LanettesHouse_MapBorder
	.4byte Route114_LanettesHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Lab
