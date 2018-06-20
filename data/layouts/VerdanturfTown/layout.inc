	.align 2
VerdanturfTown_MapBorder::
	.incbin "data/layouts/VerdanturfTown/border.bin"

	.align 2
VerdanturfTown_MapBlockdata::
	.incbin "data/layouts/VerdanturfTown/map.bin"

	.align 2
VerdanturfTown_Layout::
	.4byte 0x14
	.4byte 0x14
	.4byte VerdanturfTown_MapBorder
	.4byte VerdanturfTown_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Mauville
