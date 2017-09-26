    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

sFanfares:: @ 85248BC
	.incbin "baserom.gba", 0x5248bc, 0x48
