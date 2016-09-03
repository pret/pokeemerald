	.include "asm/macros.s"
	.include "constants/constants.s"

	.section script_data, "aw", %progbits

	.align 2
gUnknown_082DE350:: @ 82DE350
	.incbin "baserom.gba", 0x2de350, 0x9dc
