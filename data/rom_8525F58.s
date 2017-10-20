    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

    .align 2


gUnknown_08525F58:: @ 8525F58
	.byte 0x48, 0x50, 0x00, 0x00, 0xb0, 0x28, 0x00, 0x00
	.byte 0x30, 0x28, 0x00, 0x00, 0x70, 0x50, 0x00, 0x00
	.byte 0x20, 0x50, 0x00, 0x00, 0xc8, 0x28, 0x00, 0x00
	.byte 0x5a, 0x58, 0x00, 0x00, 0x98, 0x20, 0x00, 0x00

    .align 2
gCastformFrontSpriteCoords:: @ 8525F78
	.byte 0x44, 0x11, 0x00, 0x00, 0x66, 0x09, 0x00, 0x00
	.byte 0x46, 0x09, 0x00, 0x00, 0x86, 0x08, 0x00, 0x00

    .align 2
gUnknown_08525F88:: @ 8525F88
	.byte 0x0d, 0x0e, 0x0d, 0x0d

    .align 2
gUnknown_08525F8C:: @ 8525F8C
	.byte 0x00, 0x00, 0x00, 0x00

    .align 2
gUnknown_08525F90:: @ 8525F90
	spr_template 0xd755, 0xd755, gUnknown_0852497C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
	spr_template 0xd756, 0xd756, gUnknown_0852497C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

    .align 2
gUnknown_08525FC0:: @ 8525FC0
	obj_tiles gMiscBlank_Gfx, 0x0800, 0xd755
	obj_tiles gMiscBlank_Gfx, 0x0800, 0xd756

    .align 2
@ the mother of all baserom includes
	.incbin "baserom.gba", 0x525fd0, 0x18f60

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

