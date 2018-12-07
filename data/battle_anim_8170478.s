#include "constants/battle_anim.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    .align 2
gUnknown_085E5088:: @ 85E5088
    .byte 0x0a, 0x02, 0xfd, 0x00, 0x0f, 0x00, 0xfc, 0x00
    .byte 0xf6, 0x02, 0xfc, 0x00

    .align 2
gUnknown_085E5094:: @ 85E5094
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6ec
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6ed
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6ee
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6ef
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f0
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f1
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f2
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f3
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f4
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f5
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f6
	obj_tiles gBattleAnimSpriteSheet_Particles, 0x0100, 0xd6f7

	.align 2
gUnknown_085E50F4:: @ 85E50F4
	obj_pal gBattleAnimSpritePalette_136, 0xd6ec
	obj_pal gBattleAnimSpritePalette_136, 0xd6ed
	obj_pal gBattleAnimSpritePalette_136, 0xd6ee
	obj_pal gBattleAnimSpritePalette_136, 0xd6ef
	obj_pal gBattleAnimSpritePalette_136, 0xd6f0
	obj_pal gBattleAnimSpritePalette_136, 0xd6f1
	obj_pal gBattleAnimSpritePalette_136, 0xd6f2
	obj_pal gBattleAnimSpritePalette_136, 0xd6f3
	obj_pal gBattleAnimSpritePalette_136, 0xd6f4
	obj_pal gBattleAnimSpritePalette_136, 0xd6f5
	obj_pal gBattleAnimSpritePalette_136, 0xd6f6
	obj_pal gBattleAnimSpritePalette_136, 0xd6f7

	.align 2
gUnknown_085E5154:: @ 85E5154
	.2byte 0x0000, 0x0001, 0x0001, 0x0001
	.2byte 0x0002, 0x0001, 0x0000, 0x0041
	.2byte 0x0002, 0x0001, 0x0001, 0x0001
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_085E5170:: @ 85E5170
	.2byte 0x0003, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085E5178:: @ 85E5178
	.2byte 0x0004, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085E5180:: @ 85E5180
	.2byte 0x0005, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085E5188:: @ 85E5188
	.2byte 0x0006, 0x0004, 0x0007, 0x0004
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_085E5194:: @ 85E5194
	.2byte 0x0007, 0x0004, 0xffff, 0x0000

    .align 2
gUnknown_085E519C:: @ 85E519C
	.4byte gUnknown_085E5154
	.4byte gUnknown_085E5170
	.4byte gUnknown_085E5178
	.4byte gUnknown_085E5180
	.4byte gUnknown_085E5188
	.4byte gUnknown_085E5194

	.align 2
gUnknown_085E51B4:: @ 85E51B4
	.byte 0x00, 0x00, 0x00, 0x05, 0x01, 0x02, 0x02, 0x03
	.byte 0x05, 0x05, 0x04, 0x04

	.align 2
gUnknown_085E51C0:: @ 85E51C0
	.4byte sub_8171E50
	.4byte sub_81723D4
	.4byte sub_81721CC
	.4byte sub_81722CC
	.4byte sub_81726BC
	.4byte sub_81721CC
	.4byte sub_81720C8
	.4byte sub_81722CC
	.4byte sub_8172560
	.4byte sub_8171FC4
	.4byte sub_81723D4
	.4byte sub_81727E8

	.align 2
gUnknown_085E51F0:: @ 85E51F0
	spr_template 0xd6ec, 0xd6ec, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6ed, 0xd6ed, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6ee, 0xd6ee, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6ef, 0xd6ef, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085E5250:: @ 85E5250
	spr_template 0xd6f0, 0xd6f0, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6f1, 0xd6f1, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6f2, 0xd6f2, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6f3, 0xd6f3, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6f4, 0xd6f4, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6f5, 0xd6f5, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6f6, 0xd6f6, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
	spr_template 0xd6f7, 0xd6f7, gUnknown_08524904, gUnknown_085E519C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085E5310:: @ 85E5310
	.2byte 0x7adf, 0x7af0, 0x53d7, 0x3fff, 0x7297, 0x67f5, 0x7b2c, 0x2b7e
	.2byte 0x431f, 0x7bdd, 0x2a3f, 0x293f, 0x0000, 0x0201, 0x0403, 0x0101
	.2byte 0x0100, 0x0503, 0x0506, 0x0004

	.align 2
gBattleAnimSpriteTemplate_85E5338:: @ 85E5338
	spr_template ANIM_TAG_UNUSED_RED_BRICK, ANIM_TAG_UNUSED_RED_BRICK, gUnknown_0852490C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_817330C

	.align 2
gUnknown_085E5350:: @ 8535350
	.2byte 0x0040, 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085E5358:: @ 8535358
	.4byte gUnknown_085E5350

	.align 2
	spr_template ANIM_TAG_ROCKS, ANIM_TAG_ROCKS, gUnknown_08524914, gUnknown_085E5358, NULL, gDummySpriteAffineAnimTable, sub_817330C

