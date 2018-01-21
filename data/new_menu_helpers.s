	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_0860F074:: @ 860F074
	.incbin "graphics/interface/860F074.gbapal"

gUnknown_0860F094:: @ 860F094
	.byte 8, 4, 1, 0

gUnknown_0860F098:: @ 860F098
	window_template 0, 2, 15, 27, 4, 15, 0x194
	null_window_template

gUnknown_0860F0A8:: @ 860F0A8
	window_template 0, 21, 9, 5, 4, 15, 0x125

    @ These are not referenced in src/new_menu_helpers.c; rather, they are in src/menu.c.  Regardless, they were plopped here.

gUnknown_0860F0B0:: @ 860F0B0
	.incbin "graphics/interface/860F0B0.gbapal"

gUnknown_0860F0D0:: @ 860F0D0
	.byte 15, 1, 2, 0

gUnknown_0860F0D4:: @ 860F0D4
	.2byte 0xC0C, 0
	.2byte 0xC20, 32
	.2byte 0xC20, 100
	.2byte 0xC20, 0x60
	.2byte 0xC20, 0x80
	.2byte 0xC20, 0x48
	.2byte 0xC20, 0x44
	.2byte 0xC20, 0x6C
	.2byte 0xC20, 0x68
	.2byte 0xC20, 0x88
	.2byte 0xC20, 0xA4
	.2byte 0xC20, 0x24
	.2byte 0xC20, 0x28
	.2byte 0xC20, 0x2C
	.2byte 0xC20, 0x40
	.2byte 0xC20, 0x84
	.2byte 0xC20, 0x4C
	.2byte 0xC20, 0xA0
	.2byte 0xC20, 0x8C
	.2byte 0xC2A, 0xA8
	.2byte 0xC2A, 0xC0
	.2byte 0xC2A, 0xC8
	.2byte 0xC2A, 0xE0
	.2byte 0xC2A, 0xE8
	.2byte 0x808, 0xAE
	.2byte 0x808, 0xAF
