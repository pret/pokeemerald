	.align 2
Route116_TunnelersRestHouse_MapBorder::
	.incbin "data/layouts/Route116_TunnelersRestHouse/border.bin"

	.align 2
Route116_TunnelersRestHouse_MapBlockdata::
	.incbin "data/layouts/Route116_TunnelersRestHouse/map.bin"

	.align 2
Route116_TunnelersRestHouse_Layout::
	.4byte 0xa
	.4byte 0x9
	.4byte Route116_TunnelersRestHouse_MapBorder
	.4byte Route116_TunnelersRestHouse_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_GenericBuilding
