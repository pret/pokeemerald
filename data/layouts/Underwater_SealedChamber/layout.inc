	.align 2
Underwater_SealedChamber_MapBorder::
	.incbin "data/layouts/Underwater_SealedChamber/border.bin"

	.align 2
Underwater_SealedChamber_MapBlockdata::
	.incbin "data/layouts/Underwater_SealedChamber/map.bin"

	.align 2
Underwater_SealedChamber_Layout::
	.4byte 0x16
	.4byte 0x30
	.4byte Underwater_SealedChamber_MapBorder
	.4byte Underwater_SealedChamber_MapBlockdata
	.4byte gTileset_General
	.4byte gTileset_Underwater
