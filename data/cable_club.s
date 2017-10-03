    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08550594:: @ 8550594
	.incbin "baserom.gba", 0x550594, 0x8

gUnknown_0855059C:: @ 855059C
	.incbin "baserom.gba", 0x55059c, 0x190
