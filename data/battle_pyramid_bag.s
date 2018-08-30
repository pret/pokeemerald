	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata


	.align 2
gOamData_861F378:: @ 861F378
	.2byte 0x0100, 0xc000, 0x0400, 0x0000

	.align 2
gSpriteAnim_861F380:: @ 861F380
	.2byte 0x0000, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_861F388:: @ 861F388
	.4byte gSpriteAnim_861F380

	.align 2
gSpriteAffineAnim_861F38C:: @ 861F38C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_861F39C:: @ 861F39C
	.2byte 0x0000, 0x0000, 0x02fe, 0x0000, 0x0000, 0x0000, 0x0402, 0x0000, 0x0000, 0x0000, 0x04fe, 0x0000, 0x0000, 0x0000, 0x0202, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_861F3C4:: @ 861F3C4
	.4byte gSpriteAffineAnim_861F38C
	.4byte gSpriteAffineAnim_861F39C

	.align 2
gUnknown_0861F3CC:: @ 861F3CC
	obj_tiles gBattleFrontierGfx_PyramidBag, 0x0800, 0x1024

	.align 2
gUnknown_0861F3D4:: @ 861F3D4
	spr_template 0x1024, 0x1024, gOamData_861F378, gSpriteAnimTable_861F388, NULL, gSpriteAffineAnimTable_861F3C4, SpriteCallbackDummy

