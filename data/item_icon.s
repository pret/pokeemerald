	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 8614410
	.include "data/graphics/items/item_icon_table.inc"

@ 8614FE0
	.incbin "baserom.gba", 0x614fe0, 0x14

gUnknown_08614FF4:: @ 8614FF4
	.incbin "baserom.gba", 0x614ff4, 0x18
