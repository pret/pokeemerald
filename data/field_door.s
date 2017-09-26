    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08496F8C:: @ 8496F8C
	.incbin "baserom.gba", 0x496f8c, 0x14

gUnknown_08496FA0:: @ 8496FA0
	.incbin "baserom.gba", 0x496fa0, 0x14

gUnknown_08496FB4:: @ 8496FB4
	.incbin "baserom.gba", 0x496fb4, 0x1c0

gUnknown_08497174:: @ 8497174
	.incbin "baserom.gba", 0x497174, 0x288
