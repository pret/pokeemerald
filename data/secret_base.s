	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2, 0

gUnknown_0858CFCC:: @ 858CFCC
	.incbin "baserom.gba", 0x58cfcc, 0x1c

gUnknown_0858CFE8:: @ 858CFE8
	.incbin "baserom.gba", 0x58cfe8, 0x60

gUnknown_0858D048:: @ 858D048
	.incbin "baserom.gba", 0x58d048, 0x10

gUnknown_0858D058:: @ 858D058
	.incbin "baserom.gba", 0x58d058, 0x8

gUnknown_0858D060:: @ 858D060
	.incbin "baserom.gba", 0x58d060, 0xc

gUnknown_0858D06C:: @ 858D06C
	.incbin "baserom.gba", 0x58d06c, 0x10

gUnknown_0858D07C:: @ 858D07C
	.incbin "baserom.gba", 0x58d07c, 0x18
