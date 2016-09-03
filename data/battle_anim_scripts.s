	.include "asm/macros.s"
	.include "constants/constants.s"

	.section script_data, "aw", %progbits

gUnknown_082C8D64:: @ 82C8D64
	.incbin "base_emerald.gba", 0x2c8d64, 0x8

gUnknown_082C8D6C:: @ 82C8D6C
	.incbin "base_emerald.gba", 0x2c8d6c, 0x590

gUnknown_082C92FC:: @ 82C92FC
	.incbin "base_emerald.gba", 0x2c92fc, 0x24

gUnknown_082C9320:: @ 82C9320
	.incbin "base_emerald.gba", 0x2c9320, 0x5c

gUnknown_082C937C:: @ 82C937C
	.incbin "base_emerald.gba", 0x2c937c, 0xf32c
