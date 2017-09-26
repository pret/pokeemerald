    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0852487C:: @ 852487C
	.incbin "baserom.gba", 0x52487c, 0x10

gDummyPaletteStructTemplate:: @ 852488C
	.2byte 0xFFFF
	.space 9
	.byte 0x20
	.space 4

	.align 2
gUnknown_0852489C:: @ 852489C
	.incbin "baserom.gba", 0x52489c, 0x20
