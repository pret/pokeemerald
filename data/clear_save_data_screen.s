	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085F06C0:: @ 85F06C0
	.incbin "baserom.gba", 0x5f06c0, 0x8

gUnknown_085F06C8:: @ 85F06C8
	.incbin "baserom.gba", 0x5f06c8, 0x10

gUnknown_085F06D8:: @ 85F06D8
	.incbin "baserom.gba", 0x5f06d8, 0x8
