	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_0859F4E8:: @ 859F4E8
    .2byte 0x00
	.2byte 0x4000 
	.2byte 0x00
	.2byte 0x00

gUnknown_0859F4F0:: @ 859F4F0
    obj_image_anim_frame 0x00, 0x00
	obj_image_anim_end

gUnknown_0859F4F8:: @ 859F4F8
    obj_image_anim_frame 0x04, 0x00
	obj_image_anim_end

gUnknown_0859F500:: @ 859F500
    obj_image_anim_frame 0x00, 0x40
	obj_image_anim_end

gUnknown_0859F508:: @ 859F508
    .4byte gUnknown_0859F4F0
    .4byte gUnknown_0859F4F8
    .4byte gUnknown_0859F500
	
gUnknown_0859F514:: @ 859F514
	.4byte gBagSwapLineGfx, 0x6D0100

gUnknown_0859F51C:: @ 859F51C
	.4byte gBagSwapLinePal, 0x6D

gUnknown_0859F524:: @ 859F524
	spr_template 0x6D, 0x6D, gUnknown_0859F4E8, gUnknown_0859F508, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
