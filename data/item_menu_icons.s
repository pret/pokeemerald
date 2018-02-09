#include "constants/items.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0857F564:: @ 857F564
	.incbin "graphics/interface/bag_spinner.gbapal"

	.align 2
gUnknown_0857F584:: @ 857F584
	.incbin "graphics/interface/bag_spinner.4bpp"

	.align 2
gUnknown_0857F604:: @ 857F604
	.incbin "graphics/unused/cherry.4bpp"

	.align 2
gUnknown_0857FA84:: @ 857FA84
	.incbin "graphics/unused/cherry.gbapal"

	.align 2
gOamData_857FAA4:: @ 857FAA4
	.2byte 0x0100, 0xc000, 0x0400, 0x0000

	.align 2
gSpriteAnim_857FAAC:: @ 857FAAC
	.2byte 0x0000, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnim_857FAB4:: @ 857FAB4
	.2byte 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnim_857FABC:: @ 857FABC
	.2byte 0x0080, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnim_857FAC4:: @ 857FAC4
	.2byte 0x00c0, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnim_857FACC:: @ 857FACC
	.2byte 0x0100, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnim_857FAD4:: @ 857FAD4
	.2byte 0x0140, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_857FADC:: @ 857FADC
	.4byte gSpriteAnim_857FAAC
	.4byte gSpriteAnim_857FAB4
	.4byte gSpriteAnim_857FAC4
	.4byte gSpriteAnim_857FACC
	.4byte gSpriteAnim_857FAD4
	.4byte gSpriteAnim_857FABC

	.align 2
gSpriteAffineAnim_857FAF4:: @ 857FAF4
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857FB04:: @ 857FB04
	.2byte 0x0000, 0x0000, 0x02fe, 0x0000, 0x0000, 0x0000, 0x0402, 0x0000, 0x0000, 0x0000, 0x04fe, 0x0000, 0x0000, 0x0000, 0x0202, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_857FB2C:: @ 857FB2C
	.4byte gSpriteAffineAnim_857FAF4
	.4byte gSpriteAffineAnim_857FB04

	.align 2
gUnknown_0857FB34:: @ 857FB34
	obj_tiles gBagMaleTiles, 0x3000, 0x0064

	.align 2
gUnknown_0857FB3C:: @ 857FB3C
	obj_tiles gBagFemaleTiles, 0x3000, 0x0064

	.align 2
gUnknown_0857FB44:: @ 857FB44
	obj_pal gBagPalette, 0x0064

	.align 2
gUnknown_0857FB4C:: @ 857FB4C
	spr_template 0x0064, 0x0064, gOamData_857FAA4, gSpriteAnimTable_857FADC, NULL, gSpriteAffineAnimTable_857FB2C, SpriteCallbackDummy

	.align 2
gOamData_857FB64:: @ 857FB64
	.2byte 0x0000, 0x4800, 0x0800, 0x0000

	.align 2
gSpriteAnim_857FB6C:: @ 857FB6C
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_857FB74:: @ 857FB74
	.4byte gSpriteAnim_857FB6C

	.align 2
gSpriteAffineAnim_857FB78:: @ 857FB78
	.2byte 0x0000, 0x0000, 0x1008, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857FB88:: @ 857FB88
	.2byte 0x0000, 0x0000, 0x10f8, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0857FB98:: @ 857FB98
	.4byte gSpriteAffineAnim_857FB78

	.align 2
gUnknown_0857FB9C:: @ 857FB9C
	.4byte gSpriteAffineAnim_857FB88

	.align 2
gUnknown_0857FBA0:: @ 857FBA0
	obj_tiles gUnknown_0857F584, 0x0080, 0x0065

	.align 2
gUnknown_0857FBA8:: @ 857FBA8
	obj_pal gUnknown_0857F564, 0x0065

	.align 2
gUnknown_0857FBB0:: @ 857FBB0
	spr_template 0x0065, 0x0065, gOamData_857FB64, gSpriteAnimTable_857FB74, NULL, gUnknown_0857FB98, ObjectCB_SwitchPocketRotatingBallInit

	.align 2
gOamData_857FBC8:: @ 857FBC8
	.2byte 0x0000, 0xc000, 0x7400, 0x0000

	.align 2
gOamData_857FBD0:: @ 857FBD0
	.2byte 0x0300, 0xc000, 0x7000, 0x0000

	.align 2
gSpriteAnim_857FBD8:: @ 857FBD8
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_857FBE0:: @ 857FBE0
	.4byte gSpriteAnim_857FBD8

	.align 2
gOamData_857FBE4:: @ 857FBE4
	.2byte 0xc000, 0x0201, 0x0800, 0x0000

	.align 2
gUnknown_0857FBEC:: @ 857FBEC
	spr_template 0xffff, 0x7544, gOamData_857FBC8, gSpriteAnimTable_857FBE0, gOamData_857FBE4, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gSpriteAffineAnim_857FC04:: @ 857FC04
	.2byte 0xffff, 0xffff, 0x60fd, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0xfffe, 0xfffe, 0x40ff, 0x0000, 0xfff8, 0x0000, 0x1000, 0x0000
	.2byte 0x0000, 0xfff8, 0x1000, 0x0000, 0x0100, 0x0100, 0x0000, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_857FC3C:: @ 857FC3C
	.2byte 0xffff, 0xffff, 0x6003, 0x0000, 0x0000, 0x0000, 0x1000, 0x0000, 0xfffe, 0xfffe, 0x4001, 0x0000, 0xfff8, 0x0000, 0x1000, 0x0000
	.2byte 0x0000, 0xfff8, 0x1000, 0x0000, 0x0100, 0x0100, 0x0000, 0x0000, 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_857FC74:: @ 857FC74
	.4byte gSpriteAffineAnim_857FC04
	.4byte gSpriteAffineAnim_857FC3C

	.align 2
gUnknown_0857FC7C:: @ 857FC7C
	spr_template 0xffff, 0x7544, gOamData_857FBD0, gSpriteAnimTable_857FBE0, gOamData_857FBE4, gSpriteAffineAnimTable_857FC74, SpriteCallbackDummy

@ 857FC94
	.include "data/graphics/berries/berry_pic_table.inc"

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
