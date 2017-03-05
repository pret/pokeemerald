	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.incbin "baserom.gba", 0x5f53c4, 0x48

gUnknown_085F540C:: @ 85F540C
	.incbin "baserom.gba", 0x5f540c, 0x10

gUnknown_085F541C:: @ 85F541C
	.incbin "baserom.gba", 0x5f541c, 0x24

gUnknown_085F5440:: @ 85F5440
	.incbin "baserom.gba", 0x5f5440, 0x18

gUnknown_085F5458:: @ 85F5458
	.incbin "baserom.gba", 0x5f5458, 0x38
