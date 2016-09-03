	.include "asm/macros.s"
	.include "constants/constants.s"

	.section script_data, "aw", %progbits

	.align 2
gUnknown_082DBEF8:: @ 82DBEF8
	.incbin "base_emerald.gba", 0x2dbef8, 0x2458
