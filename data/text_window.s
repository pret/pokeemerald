    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0850E87C:: @ 850E87C
	.incbin "baserom.gba", 0x50e87c, 0x1680

gUnknown_0850FEFC:: @ 850FEFC
	.incbin "baserom.gba", 0x50fefc, 0x280

gUnknown_0851017C:: @ 851017C
	.incbin "baserom.gba", 0x51017c, 0xa0

gUnknown_0851021C:: @ 851021C
	.incbin "baserom.gba", 0x51021c, 0xa0
