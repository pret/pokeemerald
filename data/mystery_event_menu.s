	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085EFD64:: @ 85EFD64
	.incbin "baserom.gba", 0x5efd64, 0x4

gUnknown_085EFD68:: @ 85EFD68
	.incbin "baserom.gba", 0x5efd68, 0x18
