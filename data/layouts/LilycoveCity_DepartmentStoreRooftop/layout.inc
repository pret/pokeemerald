	.align 2
LilycoveCity_DepartmentStoreRooftop_MapBorder::
	.incbin "data/layouts/LilycoveCity_DepartmentStoreRooftop/border.bin"

	.align 2
LilycoveCity_DepartmentStoreRooftop_MapBlockdata::
	.incbin "data/layouts/LilycoveCity_DepartmentStoreRooftop/map.bin"

	.align 2
LilycoveCity_DepartmentStoreRooftop_Layout::
	.4byte 0x12
	.4byte 0xc
	.4byte LilycoveCity_DepartmentStoreRooftop_MapBorder
	.4byte LilycoveCity_DepartmentStoreRooftop_MapBlockdata
	.4byte gTileset_Building
	.4byte gTileset_Shop
