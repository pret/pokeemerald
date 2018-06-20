	.align 2
SootopolisCity_MysteryEventsHouse_B1F_MapBorder::
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_B1F/border.bin"

	.align 2
SootopolisCity_MysteryEventsHouse_B1F_MapBlockdata::
	.incbin "data/layouts/SootopolisCity_MysteryEventsHouse_B1F/map.bin"

	.align 2
SootopolisCity_MysteryEventsHouse_B1F_Layout::
	.4byte 0xc
	.4byte 0x9
	.4byte SootopolisCity_MysteryEventsHouse_B1F_MapBorder
	.4byte SootopolisCity_MysteryEventsHouse_B1F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_MysteryEventsHouse
