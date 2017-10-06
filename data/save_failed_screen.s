	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gClockOamData:: @ 85EFD80
	.incbin "baserom.gba", 0x5efd80, 0x8

gUnknown_085EFD88:: @ 85EFD88
	.incbin "baserom.gba", 0x5efd88, 0xc

gUnknown_085EFD94:: @ 85EFD94
	.incbin "baserom.gba", 0x5efd94, 0x8

gUnknown_085EFD9C:: @ 85EFD9C
	.incbin "baserom.gba", 0x5efd9c, 0x8

gUnknown_085EFDA4:: @ 85EFDA4
	.incbin "baserom.gba", 0x5efda4, 0x8

gClockFrames:: @ 85EFDAC
	.incbin "baserom.gba", 0x5efdac, 0x18

gSaveFailedClockPal:: @ 85EFDC4
	.incbin "baserom.gba", 0x5efdc4, 0x20

gSaveFailedClockGfx:: @ 85EFDE4
	.incbin "baserom.gba", 0x5efde4, 0x90
