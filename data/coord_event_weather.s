    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_085102E0:: @ 85102E0
	.incbin "baserom.gba", 0x5102e0, 0x68
