	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085EFD64:: @ 85EFD64
	.4byte 0x1F8

gUnknown_085EFD68:: @ 85EFD68
	window_template 0, 4, 15, 22, 4, 14, 20
	window_template 0, 7, 6, 16, 4, 14, 0x6C
	null_window_template
