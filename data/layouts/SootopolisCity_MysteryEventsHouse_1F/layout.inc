	.align 2
SootopolisCity_MysteryEventsHouse_1F_MapBorder::
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_1F/border.bin"

	.align 2
SootopolisCity_MysteryEventsHouse_1F_MapBlockdata::
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_1F/map.bin"

	.align 2
SootopolisCity_MysteryEventsHouse_1F_Layout::
	.4byte 0xb
	.4byte 0x8
	.4byte SootopolisCity_MysteryEventsHouse_1F_MapBorder
	.4byte SootopolisCity_MysteryEventsHouse_1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_MysteryEventsHouse
