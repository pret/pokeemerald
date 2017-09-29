    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_8486FEC:: @ 8486FEC
	.incbin "baserom.gba", 0x486fec, 0xFFA0
