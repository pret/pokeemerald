	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082F315C:: @ 82F315C struct SpritePalette
	.4byte gUnknown_082F2DF0
	.2byte 0x0000

	.align 2
gUnknown_082F3164:: @ 82F3164
	.2byte 0x4000, 0xc000, 0x0400, 0x0000

	.align 2
gUnknown_082F316C:: @ 82F316C
	.2byte 0x0000, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_082F3174:: @ 82F3174
	.2byte 0x0020, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_082F317C:: @ 82F317C
	.2byte 0x0040, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_082F3184:: @ 82F3184
	.2byte 0x0060, 0x001e, 0xffff, 0x0000

gUnknown_082F318C:: @ 82F318C
	.4byte gUnknown_082F316C
	.4byte gUnknown_082F3174
	.4byte gUnknown_082F317C
	.4byte gUnknown_082F3184

	.align 2
gUnknown_082F319C:: @ 82F319C
	spr_template 0x0000, 0x0000, gUnknown_082F3164, gUnknown_082F318C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F31B4:: @ 82F31B4
	.byte 0x00, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082F31BC:: @ 82F31BC
	spr_template 0x0002, 0x0000, gUnknown_082F31B4, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8020ABC

	.align 2
gUnknown_082F31D4:: @ 82F31D4
	spr_template 0x0001, 0x0000, gUnknown_082F31B4, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8020AF4

	.align 2
gUnknown_082F31EC:: @ 82F31EC
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082F31F4:: @ 82F31F4
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082F31FC:: @ 82F31FC
	.2byte 0x0000, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F3204:: @ 82F3204
	.2byte 0x0008, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F320C:: @ 82F320C
	.2byte 0x0010, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F3214:: @ 82F3214
	.2byte 0x0018, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F321C:: @ 82F321C
	.4byte gUnknown_082F31FC
	.4byte gUnknown_082F3204
	.4byte gUnknown_082F320C
	.4byte gUnknown_082F3214

	.align 2
gUnknown_082F322C:: @ 82F322C
	spr_template 0x0003, 0x0000, gUnknown_082F31EC, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F3244:: @ 82F3244
	spr_template 0x0004, 0x0000, gUnknown_082F31F4, gUnknown_082F321C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
