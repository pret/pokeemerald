	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 8614410
	.include "data/graphics/items/item_icon_table.inc"

gUnknown_08614FE0:: @ 8614FE0
	.2byte 0
	.2byte 0x8000
	.2byte 0x2400
	.2byte 0
	
gUnknown_08614FE8:: @ 8614FE8
	obj_image_anim_frame 0, 0
	obj_image_anim_end
	
gUnknown_08614FF0:: @ 8614FF0
	.4byte gUnknown_08614FE8

gUnknown_08614FF4:: @ 8614FF4
	spr_template 0, 0, gUnknown_08614FE0, gUnknown_08614FF0, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
