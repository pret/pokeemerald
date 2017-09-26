    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gNullScriptPtr:: @ 85102BC
	.incbin "baserom.gba", 0x5102bc, 0x4

gUnknown_085102C0:: @ 85102C0
	.incbin "baserom.gba", 0x5102c0, 0x14

gUnknown_085102D4:: @ 85102D4
	.incbin "baserom.gba", 0x5102d4, 0xc
