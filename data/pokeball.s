	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_0832C400:: @ 832C400
	.incbin "baserom.gba", 0x32c400, 0x60

gUnknown_0832C460:: @ 832C460
	.incbin "baserom.gba", 0x32c460, 0x128

gUnknown_0832C588:: @ 832C588
	.incbin "baserom.gba", 0x32c588, 0x138
