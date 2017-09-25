    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0855C604:: @ 855C604
	.incbin "baserom.gba", 0x55c604, 0x60

gUnknown_0855C664:: @ 855C664
	.incbin "baserom.gba", 0x55c664, 0x1c

gUnknown_0855C680:: @ 855C680
	.incbin "baserom.gba", 0x55c680, 0x18

gUnknown_0855C698:: @ 855C698
	.incbin "baserom.gba", 0x55c698, 0x8

gUnknown_0855C6A0:: @ 855C6A0
	.incbin "baserom.gba", 0x55c6a0, 0x4
