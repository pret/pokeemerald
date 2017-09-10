@ the second big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2


gUnknown_0831C5F8:: @ 831C5F8
	.incbin "baserom.gba", 0x31c5f8, 0xc

gUnknown_0831C604:: @ 831C604
	.incbin "baserom.gba", 0x31c604, 0x1c

gUnknown_0831C620:: @ 831C620
	.incbin "baserom.gba", 0x31c620, 0x8

gUnknown_0831C628:: @ 831C628
	.incbin "baserom.gba", 0x31c628, 0x60

gUnknown_0831C688:: @ 831C688
	.incbin "baserom.gba", 0x31c688, 0x18

gUnknown_0831C6A0:: @ 831C6A0
	.incbin "baserom.gba", 0x31c6a0, 0x10

gUnknown_0831C6B0:: @ 831C6B0
	.incbin "baserom.gba", 0x31c6b0, 0x18
