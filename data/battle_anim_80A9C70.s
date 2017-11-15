    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

	.incbin "baserom.gba", 0x53ede4, 0x14c

    .align 2
gUnknown_0853EF30:: @ 853EF30
	.byte 0xf0, 0xf0, 0x0c, 0x80, 0xf0, 0x30, 0x0d, 0x84, 0x30, 0xf0, 0x0e, 0x86, 0x30, 0x30, 0x08, 0x88

    .align 2
gUnknown_0853EF40:: @ 853EF40
	.4byte 0x00000004, gUnknown_0853EF30

    .align 2
gUnknown_0853EF48:: @ 853EF48
	spr_template 0x271a, 0x271a, gUnknown_08524A3C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

    .align 2
gUnknown_0853EF60:: @ 853EF60
	spr_template 0x2798, 0x2798, gUnknown_08524904, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80A9E44

