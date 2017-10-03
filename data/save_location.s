	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_086143BC:: @ 86143BC
	.incbin "baserom.gba", 0x6143bc, 0x4e

gUnknown_0861440A:: @ 861440A
	.incbin "baserom.gba", 0x61440a, 0x4

gUnknown_0861440E:: @ 861440E
	.incbin "baserom.gba", 0x61440e, 0x2
