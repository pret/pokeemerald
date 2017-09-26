    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08486EFC:: @ 8486EFC
	.incbin "baserom.gba", 0x486efc, 0x10090
