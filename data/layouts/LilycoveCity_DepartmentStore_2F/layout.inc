	.align 2
LilycoveCity_DepartmentStore_2F_MapBorder::
	.incbin "data/layouts/LilycoveCity_DepartmentStore_2F/border.bin"

	.align 2
LilycoveCity_DepartmentStore_2F_MapBlockdata::
	.incbin "data/layouts/LilycoveCity_DepartmentStore_2F/map.bin"

	.align 2
LilycoveCity_DepartmentStore_2F_Layout::
	.4byte 0x12
	.4byte 0x8
	.4byte LilycoveCity_DepartmentStore_2F_MapBorder
	.4byte LilycoveCity_DepartmentStore_2F_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Shop
