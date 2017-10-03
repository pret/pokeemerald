	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_085CEBB0:: @ 85CEBB0
	.incbin "baserom.gba", 0x5cebb0, 0x8

gUnknown_085CEBB8:: @ 85CEBB8
	.incbin "baserom.gba", 0x5cebb8, 0x8

gUnknown_085CEBC0:: @ 85CEBC0
	.incbin "baserom.gba", 0x5cebc0, 0x10

gUnknown_085CEBD0:: @ 85CEBD0
	.incbin "baserom.gba", 0x5cebd0, 0x40

gUnknown_085CEC10:: @ 85CEC10
	.incbin "baserom.gba", 0x5cec10, 0x18

gUnknown_085CEC28:: @ 85CEC28
	.incbin "baserom.gba", 0x5cec28, 0x8
