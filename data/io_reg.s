	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata



.align 2
gUnref_82EC784:: @ 82EC784
	.incbin "baserom.gba", 0x2EC784, 0x40

gUnknown_82EC7C4:: @ 82EC7C4
	.2byte 0x0100
	.2byte 0x0200
	.2byte 0x0400
	.2byte 0x0800

gUnknown_82EC7CC:: @ 82EC7CC
	.2byte 0x0001
	.2byte 0x0002
	.2byte 0x0004
	.2byte 0x0008
