    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08510404:: @ 8510404
	.incbin "baserom.gba", 0x510404, 0x4

gUnknown_08510408:: @ 8510408
	.incbin "baserom.gba", 0x510408, 0x14

gUnknown_0851041C:: @ 851041C
	.incbin "baserom.gba", 0x51041c, 0x4

gUnknown_08510420:: @ 8510420
	.incbin "baserom.gba", 0x510420, 0xa4

gUnknown_085104C4:: @ 85104C4
	.incbin "baserom.gba", 0x5104c4, 0x2c

gUnknown_085104F0:: @ 85104F0
	.incbin "baserom.gba", 0x5104f0, 0x18
