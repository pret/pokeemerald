	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

gUnknown_086141FC:: @ 86141FC
	.byte 0, 2, 8, 0
	.byte 1, 2, -8, -1
	.byte 18, 2, 8, 0
	.byte 19, 2, -8, -1
	
gUnknown_0861420C:: @ 861420C
	.2byte 0
	.2byte 0x4000
	.2byte 0
	.2byte 0
	
gUnknown_08614214:: @ 8614214
	obj_image_anim_frame 0, 30
	obj_image_anim_end
	
gUnknown_0861421C:: @ 861421C
	obj_image_anim_frame 0, 0x5e
	obj_image_anim_end
	
gUnknown_08614224:: @ 8614224
	obj_image_anim_frame 4, 30
	obj_image_anim_end
	
gUnknown_0861422C:: @ 861422C
	obj_image_anim_frame 4, 0x9e
	obj_image_anim_end
	
gUnknown_08614234:: @ 8614234
	.4byte gUnknown_08614214
	.4byte gUnknown_0861421C
	.4byte gUnknown_08614224
	.4byte gUnknown_0861422C

gUnknown_08614244:: @ 8614244
	spr_template 0, 0, gUnknown_0861420C, gUnknown_08614234, NULL, gDummySpriteAffineAnimTable, sub_81AF264

gUnknown_0861425C:: @ 861425C
	.4byte 0x00000000

gUnknown_08614260:: @ 8614260
	.4byte 0x00100000

gUnknown_08614264:: @ 8614264
	.4byte 0x00200000

gUnknown_08614268:: @ 8614268
	.4byte 0x00300000

gUnknown_0861426C:: @ 861426C
	.4byte 0x00400000

gUnknown_08614270:: @ 8614270
	.4byte 0x00500000

gUnknown_08614274:: @ 8614274
	.4byte 0x00600000

gUnknown_08614278:: @ 8614278
	.4byte 0x00700000

gUnknown_0861427C:: @ 861427C
	.2byte 0
	.2byte 0x4000
	.2byte 0
	.2byte 0

gUnknown_08614284:: @ 8614284
	obj_image_anim_frame 0, 30
	obj_image_anim_end
	
gUnknown_0861428C:: @ 861428C
	.4byte gUnknown_08614284

gUnknown_08614290:: @ 8614290
	spr_template 0, 0, gUnknown_0861427C, gUnknown_0861428C, NULL, gDummySpriteAffineAnimTable, ObjectCB_RedArrowCursor

gUnknown_086142A8:: @ 86142A8
	.incbin "graphics/interface/red_arrow.gbapal"

gUnknown_086142C8:: @ 86142C8
	.incbin "graphics/interface/red_arrow_other.4bpp.lz"

gUnknown_08614338:: @ 8614338
	.incbin "graphics/interface/selector_outline.4bpp.lz"

gUnknown_08614378:: @ 8614378
	.incbin "graphics/interface/red_arrow.4bpp.lz"
