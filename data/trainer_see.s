    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0855072C:: @ 855072C
	.incbin "baserom.gba", 0x55072c, 0x10

gUnknown_0855073C:: @ 855073C
	.incbin "baserom.gba", 0x55073c, 0x30

gUnknown_0855076C:: @ 855076C
	.incbin "baserom.gba", 0x55076c, 0x48
