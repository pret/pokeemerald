	.align 2
SealedChamber_OuterRoom_MapBorder::
	.incbin "data/layouts/SealedChamber_OuterRoom/border.bin"

	.align 2
SealedChamber_OuterRoom_MapBlockdata::
	.incbin "data/layouts/SealedChamber_OuterRoom/map.bin"

	.align 2
SealedChamber_OuterRoom_Layout::
	.4byte 0x15
	.4byte 0x17
	.4byte SealedChamber_OuterRoom_MapBorder
	.4byte SealedChamber_OuterRoom_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Cave
