	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_085A1EE4:: @ 85A1EE4
	.incbin "baserom.gba", 0x5a1ee4, 0xc

gUnknown_085A1EF0:: @ 85A1EF0
	.incbin "baserom.gba", 0x5a1ef0, 0x20

gUnknown_085A1F10:: @ 85A1F10
	.incbin "baserom.gba", 0x5a1f10, 0x8

gUnknown_085A1F18:: @ 85A1F18
	.incbin "baserom.gba", 0x5a1f18, 0x64

gUnknown_085A1F7C:: @ 85A1F7C
	.incbin "baserom.gba", 0x5a1f7c, 0x18
