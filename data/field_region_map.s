	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085E5068:: @ 85E5068
	.incbin "baserom.gba", 0x5e5068, 0x8

gUnknown_085E5070:: @ 85E5070
	.incbin "baserom.gba", 0x5e5070, 0x18
