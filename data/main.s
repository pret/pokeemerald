	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_82E9530:: @ 82E9530
	.byte 3

gUnknown_82E9531:: @ 82E9531
	.byte 2

	.align 2
@ compile time
	.asciz "2005 02 21 11:10"

	.align 2
gRomInterruptTable:: @ 82E9548
	.4byte VCountIntr
	.4byte SerialIntr
	.4byte Timer3Intr
	.4byte HBlankIntr
	.4byte VBlankIntr
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
	.4byte DummyIntrHandler
