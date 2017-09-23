	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_08616124:: @ 8616124
	.incbin "baserom.gba", 0x616124, 0x4

	.align 2
gFont6BrailleGlyphs:: @ 8616128
	.incbin "data/graphics/fonts/font6.fwjpnfont"
