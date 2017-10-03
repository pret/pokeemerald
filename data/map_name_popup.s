    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0857C684:: @ 857C684
	.incbin "baserom.gba", 0x57c684, 0x1680

gUnknown_0857DD04:: @ 857DD04
	.incbin "baserom.gba", 0x57dd04, 0x1680

gUnknown_0857F384:: @ 857F384
	.incbin "baserom.gba", 0x57f384, 0xc0

gUnknown_0857F444:: @ 857F444
	.incbin "baserom.gba", 0x57f444, 0x20
