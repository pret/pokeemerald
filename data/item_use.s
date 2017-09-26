
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_085920D8:: @ 85920D8
	.incbin "baserom.gba", 0x5920d8, 0xc

gUnknown_085920E4:: @ 85920E4
	.incbin "baserom.gba", 0x5920e4, 0x4

gUnknown_085920E8:: @ 85920E8
	.incbin "baserom.gba", 0x5920e8, 0x128
