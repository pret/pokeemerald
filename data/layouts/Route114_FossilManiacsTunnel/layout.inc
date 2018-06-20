Route114_FossilManiacsTunnel_MapBorder::
	.incbin "data/layouts/Route114_FossilManiacsTunnel/border.bin"

Route114_FossilManiacsTunnel_MapBlockdata::
	.incbin "data/layouts/Route114_FossilManiacsTunnel/map.bin"

	.align 2
Route114_FossilManiacsTunnel_Layout::
	.4byte 0xd
	.4byte 0x1a
	.4byte Route114_FossilManiacsTunnel_MapBorder
	.4byte Route114_FossilManiacsTunnel_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Fallarbor

