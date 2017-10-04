    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

@ 857BCA8
	.include "data/graphics/pokemon/icon_table.inc"

@ 857C388
	.include "data/graphics/pokemon/icon_palette_indices.inc"

@ 857C540
	.include "data/graphics/pokemon/icon_palette_table.inc"

gUnknown_0857C570:: @ 857C570
	.incbin "baserom.gba", 0x57c570, 0x44

gUnknown_0857C5B4:: @ 857C5B4
	.incbin "baserom.gba", 0x57c5b4, 0x34

gUnknown_0857C5E8:: @ 857C5E8
	.incbin "baserom.gba", 0x57c5e8, 0x8

gUnknown_0857C5F0:: @ 857C5F0
	.incbin "baserom.gba", 0x57c5f0, 0x18
