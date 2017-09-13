	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    @ unknown unreferenced data
    
	.incbin "baserom.gba", 0x58d977, 0x2a1
