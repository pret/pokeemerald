#include "constants/items.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0857FDEC:: @ 857FDEC
	obj_tiles gBerryCheckCircle_Gfx, 0x0800, 0x2710

	.align 2
gUnknown_0857FDF4:: @ 857FDF4
	obj_pal gUnknown_08D9BEF0, 0x2710

	.align 2
gOamData_857FDFC:: @ 857FDFC
	.2byte 0x0000, 0xc000, 0x0400, 0x0000

	.align 2
gSpriteAnim_857FE04:: @ 857FE04
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_857FE0C:: @ 857FE0C
	.4byte gSpriteAnim_857FE04

	.align 2
gUnknown_0857FE10:: @ 857FE10
	spr_template 0x2710, 0x2710, gOamData_857FDFC, gSpriteAnimTable_857FE0C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0857FE28:: @ 857FE28
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80D5860

	.align 2
gUnknown_0857FE40:: @ 857FE40
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80D58F8

	.align 2
gUnknown_0857FE58:: @ 857FE58
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80D5968

	.align 2
gUnknown_0857FE70:: @ 857FE70
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80D5A94

	.align 2
gUnknown_0857FE88:: @ 857FE88
	spr_template 0x0000, 0x0000, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80D5B48

@ 857FEA0
	.include "data/text/item_descriptions.inc"

@ 85839A0
	.include "data/items.inc"
