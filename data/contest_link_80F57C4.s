	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0858D6B0:: @ 858D6B0
	.incbin "graphics/unknown/unknown_58D6B0.gbapal"

	.align 2
gUnknown_0858D6D0:: @ 858D6D0
	.incbin "graphics/unknown/unknown_58D6D0.4bpp"

	.align 2
gMiscBlank_Pal:: @ 858D7D0
	.incbin "graphics/interface/blank.gbapal"

	.align 2
gOamData_858D7F0:: @ 858D7F0
	.2byte 0x4000
	.2byte 0xC000
	.2byte 0x2C00

	.align 2
gSpriteTemplate_858D7F8:: @ 858D7F8
	spr_template 0x0bc1, 0x0bc1, gOamData_858D7F0, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0858D810:: @ 858D810
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc1
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc2
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc3
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc4
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc5
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc6
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc7
	obj_tiles gMiscBlank_Gfx, 0x0400, 0x0bc8

	.align 2
gUnknown_0858D850:: @ 858D850
	obj_pal gMiscBlank_Pal, 0x0bc1

	.align 2
gOamData_858D858:: @ 858D858
	.2byte 0x0000
	.2byte 0x0000
	.2byte 0x0000

	.align 2
gSpriteTemplate_858D860:: @ 858D860
	spr_template 0x0bc9, 0x0bc9, gOamData_858D858, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80F7768

	.align 2
gUnknown_0858D878:: @ 858D878
	obj_tiles gContestConfetti_Gfx, 0x0220, 0x0bc9

	.align 2
gUnknown_0858D880:: @ 858D880
	obj_pal gContestConfetti_Pal, 0x0bc9

	.align 2
gUnknown_0858D888:: @ 858D888
	.4byte 0x000001e0, 0x00003181, 0x000031c2, 0x000031a3

	.align 2
gUnknown_0858D898:: @ 858D898
	window_template 0x01, 0x07, 0x04, 0x0c, 0x02, 0x0f, 0x0302
	window_template 0x01, 0x07, 0x07, 0x0c, 0x02, 0x0f, 0x031a
	window_template 0x01, 0x07, 0x0a, 0x0c, 0x02, 0x0f, 0x0332
	window_template 0x01, 0x07, 0x0d, 0x0c, 0x02, 0x0f, 0x034a
	null_window_template

	.align 2
gUnknown_0858D8C0:: @ 858D8C0
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

	.align 2
gSpriteTemplate_858D8C8:: @ 858D8C8
	spr_template 0x56ce, 0x0000, gUnknown_0858D8C0, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0858D8E0:: @ 858D8E0
	obj_tiles gMiscBlank_Gfx, 0x0200, 0x56ce

	.align 2
sContestLinkTextColors:: @ 858D8E8
	.byte 0x01, 0x0f, 0x0e, 0x00  @ TEXT_COLOR_WHITE, TEXT_DYNAMIC_COLOR_6, TEXT_DYNAMIC_COLOR_5

