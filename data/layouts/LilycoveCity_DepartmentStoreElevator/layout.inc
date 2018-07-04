LilycoveCity_DepartmentStoreElevator_MapBorder::
	.incbin "data/layouts/LilycoveCity_DepartmentStoreElevator/border.bin"

LilycoveCity_DepartmentStoreElevator_MapBlockdata::
	.incbin "data/layouts/LilycoveCity_DepartmentStoreElevator/map.bin"

	.align 2
LilycoveCity_DepartmentStoreElevator_Layout::
	.4byte 0x5
	.4byte 0x6
	.4byte LilycoveCity_DepartmentStoreElevator_MapBorder
	.4byte LilycoveCity_DepartmentStoreElevator_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_BattleFrontier

