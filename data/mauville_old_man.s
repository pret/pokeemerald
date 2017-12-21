	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_0859EFE4:: @ 859EFE4
	.2byte 0x2811, 0x1029, 0x1018, 0xE0D, 0x1A1A, 0x1A1D

gUnknown_0859EFF0:: @ 859EFF0
	.4byte gText_SoPretty
	.4byte gText_SoDarling
	.4byte gText_SoRelaxed
	.4byte gText_SoSunny
	.4byte gText_SoDesirable
	.4byte gText_SoExciting
	.4byte gText_SoAmusing
	.4byte gText_SoMagical

gUnknown_0859F010:: @ 859F010
	.4byte gUnknown_08294313
	.4byte gUnknown_08294359
	.4byte gUnknown_08294398
	.4byte gUnknown_082943DA
	.4byte gUnknown_0829441C
	.4byte gUnknown_08294460
	.4byte gUnknown_082944A0
	.4byte gUnknown_082944D5

gUnknown_0859F030:: @ 859F030
	.incbin "baserom.gba", 0x59f030, 0x18

gUnknown_0859F048:: @ 859F048
	.incbin "baserom.gba", 0x59f048, 0x230

gUnknown_0859F278:: @ 859F278
	.incbin "baserom.gba", 0x59f278, 0x10

gUnknown_0859F288:: @ 859F288
	.4byte 0x00000024, 0x00000008
