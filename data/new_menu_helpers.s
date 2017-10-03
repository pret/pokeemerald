	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_0860F074:: @ 860F074
	.incbin "baserom.gba", 0x60f074, 0x20

gUnknown_0860F094:: @ 860F094
	.incbin "baserom.gba", 0x60f094, 0x4

gUnknown_0860F098:: @ 860F098
	.incbin "baserom.gba", 0x60f098, 0x10

gUnknown_0860F0A8:: @ 860F0A8
	.incbin "baserom.gba", 0x60f0a8, 0x8

    @ These are not referenced in src/new_menu_helpers.c; rather, they are in src/menu.c.  Regardless, they were plopped here.

gUnknown_0860F0B0:: @ 860F0B0
	.incbin "baserom.gba", 0x60f0b0, 0x20

gUnknown_0860F0D0:: @ 860F0D0
	.incbin "baserom.gba", 0x60f0d0, 0x4

gUnknown_0860F0D4:: @ 860F0D4
	.incbin "baserom.gba", 0x60f0d4, 0x68
