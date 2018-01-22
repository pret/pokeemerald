	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

gUnknown_0859E65C:: @ 859E65C
	.incbin "graphics/misc/mon_markings.gbapal"

gUnknown_0859E67C:: @ 859E67C
	.incbin "graphics/misc/mon_markings.4bpp"

gUnknown_0859EE7C:: @ 859EE7C
	.2byte 0, 0xC000, 0, 0

gUnknown_0859EE84:: @ 859EE84
	.2byte 0, 0, 0, 0
	
gUnknown_0859EE8C:: @ 859EE8C
	.2byte 0, 5, -1, 0
	
gUnknown_0859EE94:: @ 859EE94
	.2byte 1, 5, -1, 0
	
gUnknown_0859EE9C:: @ 859EE9C
	.2byte 2, 5, -1, 0
	
gUnknown_0859EEA4:: @ 859EEA4
	.2byte 3, 5, -1, 0
	
gUnknown_0859EEAC:: @ 859EEAC
	.2byte 4, 5, -1, 0
	
gUnknown_0859EEB4:: @ 859EEB4
	.2byte 5, 5, -1, 0
	
gUnknown_0859EEBC:: @ 859EEBC
	.2byte 6, 5, -1, 0
	
gUnknown_0859EEC4:: @ 859EEC4
	.2byte 7, 5, -1, 0
	
gUnknown_0859EECC:: @ 859EECC
	.2byte 8, 5, -1, 0
	
gUnknown_0859EED4:: @ 859EED4
	.2byte 9, 5, -1, 0

gUnknown_0859EEDC:: @ 859EEDC
	.4byte gUnknown_0859EE8C
	.4byte gUnknown_0859EE94
	.4byte gUnknown_0859EE9C
	.4byte gUnknown_0859EEA4
	.4byte gUnknown_0859EEAC
	.4byte gUnknown_0859EEB4
	.4byte gUnknown_0859EEBC
	.4byte gUnknown_0859EEC4
	.4byte gUnknown_0859EECC
	.4byte gUnknown_0859EED4

gUnknown_0859EF04:: @ 859EF04
	.2byte 0, 5, -1, 0
	
gUnknown_0859EF0C:: @ 859EF0C
	.2byte 64, 5, -1, 0
	
gUnknown_0859EF14:: @ 859EF14
	.4byte gUnknown_0859EF04
	.4byte gUnknown_0859EF0C

gUnknown_0859EF1C:: @ 859EF1C
	.2byte 0x4000
	.2byte 0x4000
	.2byte 0
	.2byte 0

gUnknown_0859EF24:: @ 859EF24
	obj_image_anim_frame 0, 5
	obj_image_anim_end

gUnknown_0859EF2C:: @ 859EF2C
	obj_image_anim_frame 4, 5
	obj_image_anim_end

gUnknown_0859EF34:: @ 859EF34
	obj_image_anim_frame 8, 5
	obj_image_anim_end

gUnknown_0859EF3C:: @ 859EF3C
	obj_image_anim_frame 12, 5
	obj_image_anim_end

gUnknown_0859EF44:: @ 859EF44
	obj_image_anim_frame 16, 5
	obj_image_anim_end

gUnknown_0859EF4C:: @ 859EF4C
	obj_image_anim_frame 20, 5
	obj_image_anim_end

gUnknown_0859EF54:: @ 859EF54
	obj_image_anim_frame 24, 5
	obj_image_anim_end

gUnknown_0859EF5C:: @ 859EF5C
	obj_image_anim_frame 28, 5
	obj_image_anim_end

gUnknown_0859EF64:: @ 859EF64
	obj_image_anim_frame 32, 5
	obj_image_anim_end

gUnknown_0859EF6C:: @ 859EF6C
	obj_image_anim_frame 36, 5
	obj_image_anim_end

gUnknown_0859EF74:: @ 859EF74
	obj_image_anim_frame 40, 5
	obj_image_anim_end

gUnknown_0859EF7C:: @ 859EF7C
	obj_image_anim_frame 44, 5
	obj_image_anim_end

gUnknown_0859EF84:: @ 859EF84
	obj_image_anim_frame 48, 5
	obj_image_anim_end

gUnknown_0859EF8C:: @ 859EF8C
	obj_image_anim_frame 52, 5
	obj_image_anim_end

gUnknown_0859EF94:: @ 859EF94
	obj_image_anim_frame 56, 5
	obj_image_anim_end

gUnknown_0859EF9C:: @ 859EF9C
	obj_image_anim_frame 60, 5
	obj_image_anim_end

gUnknown_0859EFA4:: @ 859EFA4
	.4byte gUnknown_0859EF24
	.4byte gUnknown_0859EF2C
	.4byte gUnknown_0859EF34
	.4byte gUnknown_0859EF3C
	.4byte gUnknown_0859EF44
	.4byte gUnknown_0859EF4C
	.4byte gUnknown_0859EF54
	.4byte gUnknown_0859EF5C
	.4byte gUnknown_0859EF64
	.4byte gUnknown_0859EF6C
	.4byte gUnknown_0859EF74
	.4byte gUnknown_0859EF7C
	.4byte gUnknown_0859EF84
	.4byte gUnknown_0859EF8C
	.4byte gUnknown_0859EF94
	.4byte gUnknown_0859EF9C
