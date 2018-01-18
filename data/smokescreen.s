@ data used in battle_7.s and smokescreen.s, can't split because they're interleaved

	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0831C604:: @ 831C604
	.byte 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x02, 0x00
	.byte 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x02, 0x01
	.byte 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01
	.byte 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_0831C620:: @ 831C620
	obj_tiles gSmokescreenImpactTiles, 0x0180, 0xd6eb

	.align 2
gUnknown_0831C628:: @ 831C628
	obj_pal gSmokescreenImpactPalette, 0xd6eb

	.align 2
gUnknown_0831C630:: @ 831C630
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_0831C638:: @ 831C638
	.2byte 0x0000, 0x0004, 0x0004, 0x0004, 0x0008, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_0831C648:: @ 831C648
	.2byte 0x0000, 0x0044, 0x0004, 0x0044, 0x0008, 0x0044, 0xffff, 0x0000

	.align 2
gUnknown_0831C658:: @ 831C658
	.2byte 0x0000, 0x0084, 0x0004, 0x0084, 0x0008, 0x0084, 0xffff, 0x0000

	.align 2
gUnknown_0831C668:: @ 831C668
	.2byte 0x0000, 0x00c4, 0x0004, 0x00c4, 0x0008, 0x00c4, 0xffff, 0x0000

	.align 2
gUnknown_0831C678:: @ 831C678
	.4byte gUnknown_0831C638
	.4byte gUnknown_0831C648
	.4byte gUnknown_0831C658
	.4byte gUnknown_0831C668

	.align 2
gUnknown_0831C688:: @ 831C688
	spr_template 0xd6eb, 0xd6eb, gUnknown_0831C630, gUnknown_0831C678, NULL, gDummySpriteAffineAnimTable, sub_80753B4

	.align 2
gSpriteSheet_EnemyShadow:: @ 831C6A0
	obj_tiles gEnemyMonShadow_Gfx, 0x0080, 0xd759

	.align 2
gUnknown_0831C6A8:: @ 831C6A8
	.byte 0x00, 0x40, 0x00, 0x40, 0x00, 0x0c, 0x00, 0x00

	.align 2
gSpriteTemplate_EnemyShadow:: @ 831C6B0
	spr_template 0xd759, 0xd6ff, gUnknown_0831C6A8, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCB_SetInvisible
