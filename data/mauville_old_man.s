	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_0859EFE4:: @ 859EFE4
	.2byte 0x2811, 0x1029, 0x1018, 0xE0D, 0x1A1A, 0x1A1D

gUnknown_0859EFF0:: @ 859EFF0
	.4byte 0x8294295
	.4byte 0x82942a1
	.4byte 0x82942ae
	.4byte 0x82942bb
	.4byte 0x82942c6
	.4byte 0x82942d5
	.4byte 0x82942e3
	.4byte 0x82942f0

gUnknown_0859F010:: @ 859F010
	.4byte 0x8294313
	.4byte 0x8294359
	.4byte 0x8294398
	.4byte 0x82943da
	.4byte 0x829441c
	.4byte 0x8294460
	.4byte 0x82944a0
	.4byte 0x82944d5

gUnknown_0859F030:: @ 859F030
	.incbin "baserom.gba", 0x59f030, 0x18

gUnknown_0859F048:: @ 859F048
	.incbin "baserom.gba", 0x59f048, 0x230

gUnknown_0859F278:: @ 859F278
	.incbin "baserom.gba", 0x59f278, 0x10

gUnknown_0859F288:: @ 859F288
	.4byte 0x00000024, 0x00000008
