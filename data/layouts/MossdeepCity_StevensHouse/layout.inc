MossdeepCity_StevensHouse_MapBorder::
	.incbin "data/layouts/MossdeepCity_StevensHouse/border.bin"

MossdeepCity_StevensHouse_MapBlockdata::
	.incbin "data/layouts/MossdeepCity_StevensHouse/map.bin"

	.align 2
MossdeepCity_StevensHouse_Layout::
	.4byte 0xb
	.4byte 0x8
	.4byte MossdeepCity_StevensHouse_MapBorder
	.4byte MossdeepCity_StevensHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding

