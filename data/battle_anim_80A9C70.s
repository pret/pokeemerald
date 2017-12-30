    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

    .align 2
gUnknown_0853EDE4:: @ 853EDE4
	.2byte 0x0000, 0x0003, 0x0004, 0x0003, 0x0008, 0x0003, 0x000c, 0x0003, 0xfffe, 0x0000

    .align 2
gUnknown_0853EDF8:: @ 853EDF8
	.4byte gUnknown_0853EDE4

    .align 2
gUnknown_0853EDFC:: @ 853EDFC
	spr_template 0x2714, 0x2714, gUnknown_0852490C, gUnknown_0853EDF8, NULL, gDummySpriteAffineAnimTable, sub_80A8AEC
	spr_template 0x2714, 0x2714, gUnknown_0852490C, gUnknown_0853EDF8, NULL, gDummySpriteAffineAnimTable, sub_80A8A6C

    .align 2
gUnknown_0853EE2C:: @ 853EE2C
	.2byte 0x0000, 0x0003, 0xfffe, 0x0000

    .align 2
gUnknown_0853EE34:: @ 853EE34
	.4byte gUnknown_0853EE2C

    .align 2
gUnknown_0853EE38:: @ 853EE38
	spr_template 0x282b, 0x282b, gUnknown_08524914, gUnknown_0853EE34, NULL, gDummySpriteAffineAnimTable, sub_80A8E30
	spr_template 0x282b, 0x282b, gUnknown_08524914, gUnknown_0853EE34, NULL, gDummySpriteAffineAnimTable, sub_80A8EE4

    .align 2
gUnknown_0853EE68:: @ 853EE68
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0030, 0x0003, 0x0040, 0x0003, 0xffff, 0x0000

    .align 2
gUnknown_0853EE80:: @ 853EE80
	.4byte gUnknown_0853EE68

    .align 2
gUnknown_0853EE84:: @ 853EE84
	spr_template 0x2757, 0x2757, gUnknown_08524914, gUnknown_0853EE80, NULL, gDummySpriteAffineAnimTable, sub_80A8B64
	spr_template 0x2743, 0x2743, gUnknown_08524914, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80A8AEC

    .align 2
gUnknown_0853EEB4:: @ 853EEB4
	.2byte 0x0000, 0x0005, 0xfffe, 0x0000

    .align 2
gUnknown_0853EEBC:: @ 853EEBC
	.2byte 0x0000, 0x0005, 0xfffe, 0x0000

    .align 2
gUnknown_0853EEC4:: @ 853EEC4
	.2byte 0x0000, 0x0005, 0xfffe, 0x0000

    .align 2
gUnknown_0853EECC:: @ 853EECC
	.4byte gUnknown_0853EEB4
	.4byte gUnknown_0853EEBC
	.4byte gUnknown_0853EEC4

    .align 2
gUnknown_0853EED8:: @ 853EED8
	spr_template 0x2797, 0x2797, gUnknown_08524914, gUnknown_0853EECC, NULL, gDummySpriteAffineAnimTable, sub_80A8AEC

    .align 2
gUnknown_0853EEF0:: @ 853EEF0
	.2byte 0x0000, 0x000f, 0xfffe, 0x0000

    .align 2
gUnknown_0853EEF8:: @ 853EEF8
	.4byte gUnknown_0853EEF0

    .align 2
gUnknown_0853EEFC:: @ 853EEFC
	.2byte 0x0060, 0x0060, 0x0000, 0x0000, 0x0002, 0x0002, 0x0100, 0x0000, 0x7ffe, 0x0001, 0x0000, 0x0000

    .align 2
gUnknown_0853EF14:: @ 853EF14
	.4byte gUnknown_0853EEFC

    .align 2
gUnknown_0853EF18:: @ 853EF18
	spr_template 0x2714, 0x2714, gUnknown_085249CC, gUnknown_0853EEF8, NULL, gUnknown_0853EF14, sub_80A8A6C

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

