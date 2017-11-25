@ the fourth big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085B2230:: @ 85B2230
	.incbin "baserom.gba", 0x5b2230, 0x20

gUnknown_085B2250:: @ 85B2250
	.incbin "baserom.gba", 0x5b2250, 0x18

gUnknown_085B2268:: @ 85B2268
	.incbin "baserom.gba", 0x5b2268, 0x38

gUnknown_085B22A0:: @ 85B22A0
	.incbin "baserom.gba", 0x5b22a0, 0x18

gUnknown_085B22B8:: @ 85B22B8
	.incbin "baserom.gba", 0x5b22b8, 0x18

gUnknown_085B22D0:: @ 85B22D0
	.incbin "baserom.gba", 0x5b22d0, 0x2d0
