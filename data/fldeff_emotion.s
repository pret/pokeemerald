    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_085507B4:: @ 85507B4
	.incbin "baserom.gba", 0x5507b4, 0x18

gUnknown_085507CC:: @ 85507CC
	.incbin "baserom.gba", 0x5507cc, 0x18
