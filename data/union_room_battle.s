	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082F0DD0:: @ 82F0DD0
	.4byte 0x000001FC

	.align 2
gUnknown_082F0DD4:: @ 82F0DD4
	window_template 0x00, 0x03, 0x0f, 0x18, 0x04, 0x0e, 0x0014
	null_window_template

	.align 2
gUnknown_082F0DE4:: @ 82F0DE4
	.byte 0x01, 0x02, 0x03
