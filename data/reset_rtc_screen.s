    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gUnknown_08510404:: @ 8510404 struct BgTemplate
	.4byte 0x000001f0

	.align 2
gUnknown_08510408:: @ 8510408
	window_template 0x00, 0x01, 0x01, 0x13, 0x09, 0x0f, 0x0155
	window_template 0x00, 0x02, 0x0f, 0x1b, 0x04, 0x0f, 0x00e9
	window_template_terminator

	.align 2
gUnknown_08510420:: @ 8510420
	window_template 0x00, 0x04, 0x09, 0x15, 0x02, 0x0f, 0x00bf

	.align 2
gUnknown_08510428:: @ 8510428
	.byte   3,  0,  1,  0, 15, 39,  0,  2,  0,  0,  0,  0
	.byte   4,  0,  0,  0, 23,  0,  1,  3,  0,  0,  0,  0
	.byte   5,  0,  0,  0, 59,  0,  2,  4,  0,  0,  0,  0
	.byte   6,  0,  0,  0, 59,  0,  3,  5,  0,  0,  0,  0
	.byte   7,  0,  0,  0,  0,  0,  4,  0,  6,  0,  0,  0

	.align 2
gOamData_08510464:: @ 8510464
	.2byte 0x0000
	.2byte 0x0000
	.2byte 0x0000

	.align 2
gResetRtcScreen_DownArrowGfx:: @ 851046C
	.incbin "graphics/misc/reset_rtc_screen_downarrow.4bpp"

	.align 2
gResetRtcScreen_RightArrowGfx:: @ 851048C
	.incbin "graphics/misc/reset_rtc_screen_rightarrow.4bpp"

	.align 2
gResetRtcScreen_ArrowPal: @ 85104AC
	.incbin "graphics/misc/reset_rtc_screen_arrow.gbapal"

	.align 2
gSpriteImageTable_85104B4:: @ 85104B4
	obj_frame_tiles gResetRtcScreen_DownArrowGfx, 0x20
	obj_frame_tiles gResetRtcScreen_RightArrowGfx, 0x20

	.align 2
gUnknown_085104C4:: @ 85104C4
	obj_pal gResetRtcScreen_ArrowPal, 0x1000

	.align 2
gSpriteAnim_85104CC:: @ 85104CC
	obj_image_anim_frame 0, 30
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85104D4: @ 85104D4
	obj_image_anim_frame 0, 30, OBJ_IMAGE_ANIM_V_FLIP
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85104DC:: @ 85104DC
	obj_image_anim_frame 1, 30
	obj_image_anim_jump 0

	.align 2
gSpriteAnimTable_85104E4:: @ 85104E4
	.4byte gSpriteAnim_85104CC
	.4byte gSpriteAnim_85104D4
	.4byte gSpriteAnim_85104DC

	.align 2
gSpriteTemplate_85104F0:: @ 85104F0
	spr_template 0xFFFF, 0x1000, gOamData_08510464, gSpriteAnimTable_85104E4, gSpriteImageTable_85104B4, gDummySpriteAffineAnimTable, SpriteCallbackDummy
