	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gUnknown_082DBEF8:: @ 82DBEF8
	.incbin "baserom.gba", 0x2dbef8, 0x2458
