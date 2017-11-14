@ the fourth big chunk of data

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    
.align 2
    
gUnknown_085B09E4:: @ 85B09E4
	.incbin "baserom.gba", 0x5b09e4, 0x10

gUnknown_085B09F4:: @ 85B09F4
	.incbin "baserom.gba", 0x5b09f4, 0x4

gUnknown_085B09F8:: @ 85B09F8
	.incbin "baserom.gba", 0x5b09f8, 0x8

