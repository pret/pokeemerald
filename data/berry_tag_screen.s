	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085EFCF0:: @ 85EFCF0
	.incbin "baserom.gba", 0x5efcf0, 0x10

gUnknown_085EFD00:: @ 85EFD00
	.incbin "baserom.gba", 0x5efd00, 0x20

gUnknown_085EFD20:: @ 85EFD20
	.incbin "baserom.gba", 0x5efd20, 0x8

gUnknown_085EFD28:: @ 85EFD28
	.incbin "baserom.gba", 0x5efd28, 0x28

gBerryFirmnessStringPointers:: @ 85EFD50
	.4byte gBerryFirmnessString_VerySoft
	.4byte gBerryFirmnessString_Soft
	.4byte gBerryFirmnessString_Hard
	.4byte gBerryFirmnessString_VeryHard
	.4byte gBerryFirmnessString_SuperHard
