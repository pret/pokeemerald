    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_0857F464:: @ 857F464
	.incbin "baserom.gba", 0x57f464, 0xe0

gUnknown_0857F544:: @ 857F544
	.incbin "baserom.gba", 0x57f544, 0x5f0

gUnknown_0857FB34:: @ 857FB34
	.incbin "baserom.gba", 0x57fb34, 0x8

gUnknown_0857FB3C:: @ 857FB3C
	.incbin "baserom.gba", 0x57fb3c, 0x8

gUnknown_0857FB44:: @ 857FB44
	.incbin "baserom.gba", 0x57fb44, 0x8

gUnknown_0857FB4C:: @ 857FB4C
	.incbin "baserom.gba", 0x57fb4c, 0x4c

gUnknown_0857FB98:: @ 857FB98
	.incbin "baserom.gba", 0x57fb98, 0x4

gUnknown_0857FB9C:: @ 857FB9C
	.incbin "baserom.gba", 0x57fb9c, 0x4

gUnknown_0857FBA0:: @ 857FBA0
	.incbin "baserom.gba", 0x57fba0, 0x8

gUnknown_0857FBA8:: @ 857FBA8
	.incbin "baserom.gba", 0x57fba8, 0x8

gUnknown_0857FBB0:: @ 857FBB0
	.incbin "baserom.gba", 0x57fbb0, 0x3c

gUnknown_0857FBEC:: @ 857FBEC
	.incbin "baserom.gba", 0x57fbec, 0x90

gUnknown_0857FC7C:: @ 857FC7C
	.incbin "baserom.gba", 0x57fc7c, 0x18

@ 857FC94
	.include "data/graphics/berries/berry_pic_table.inc"

gUnknown_0857FDEC:: @ 857FDEC
	.incbin "baserom.gba", 0x57fdec, 0x8

gUnknown_0857FDF4:: @ 857FDF4
	.incbin "baserom.gba", 0x57fdf4, 0x1c

gUnknown_0857FE10:: @ 857FE10
	.incbin "baserom.gba", 0x57fe10, 0x90

@ 857FEA0
	.include "data/text/item_descriptions.inc"

@ 85839A0
	.include "data/items.inc"
