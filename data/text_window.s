	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gTextWindowFrame1_Gfx:: @ 850E87C
	.incbin "graphics/text_window/1.4bpp"

	.align 2
gTextWindowFrame2_Gfx:: @ 850E99C
	.incbin "graphics/text_window/2.4bpp"

	.align 2
gTextWindowFrame3_Gfx:: @ 850EABC
	.incbin "graphics/text_window/3.4bpp"

	.align 2
gTextWindowFrame4_Gfx:: @ 850EBDC
	.incbin "graphics/text_window/4.4bpp"

	.align 2
gTextWindowFrame5_Gfx:: @ 850ECFC
	.incbin "graphics/text_window/5.4bpp"

	.align 2
gTextWindowFrame6_Gfx:: @ 850EE1C
	.incbin "graphics/text_window/6.4bpp"

	.align 2
gTextWindowFrame7_Gfx:: @ 850EF3C
	.incbin "graphics/text_window/7.4bpp"

	.align 2
gTextWindowFrame8_Gfx:: @ 850F05C
	.incbin "graphics/text_window/8.4bpp"

	.align 2
gTextWindowFrame9_Gfx:: @ 850F17C
	.incbin "graphics/text_window/9.4bpp"

	.align 2
gTextWindowFrame10_Gfx:: @ 850F29C
	.incbin "graphics/text_window/10.4bpp"

	.align 2
gTextWindowFrame11_Gfx:: @ 850F3BC
	.incbin "graphics/text_window/11.4bpp"

	.align 2
gTextWindowFrame12_Gfx:: @ 850F4DC
	.incbin "graphics/text_window/12.4bpp"

	.align 2
gTextWindowFrame13_Gfx:: @ 850F5FC
	.incbin "graphics/text_window/13.4bpp"

	.align 2
gTextWindowFrame14_Gfx:: @ 850F71C
	.incbin "graphics/text_window/14.4bpp"

	.align 2
gTextWindowFrame15_Gfx:: @ 850F83C
	.incbin "graphics/text_window/15.4bpp"

	.align 2
gTextWindowFrame16_Gfx:: @ 850F95C
	.incbin "graphics/text_window/16.4bpp"

	.align 2
gTextWindowFrame17_Gfx:: @ 850FA7C
	.incbin "graphics/text_window/17.4bpp"

	.align 2
gTextWindowFrame18_Gfx:: @ 850FB9C
	.incbin "graphics/text_window/18.4bpp"

	.align 2
gTextWindowFrame19_Gfx:: @ 850FCBC
	.incbin "graphics/text_window/19.4bpp"

	.align 2
gTextWindowFrame20_Gfx:: @ 850FDDC
	.incbin "graphics/text_window/20.4bpp"

	.align 2
gTextWindowFrame1_Pal:: @ 850FEFC
	.incbin "graphics/text_window/1.gbapal"

	.align 2
gTextWindowFrame2_Pal:: @ 850FF1C
	.incbin "graphics/text_window/2.gbapal"

	.align 2
gTextWindowFrame3_Pal:: @ 850FF3C
	.incbin "graphics/text_window/3.gbapal"

	.align 2
gTextWindowFrame4_Pal:: @ 850FF5C
	.incbin "graphics/text_window/4.gbapal"

	.align 2
gTextWindowFrame5_Pal:: @ 850FF7C
	.incbin "graphics/text_window/5.gbapal"

	.align 2
gTextWindowFrame6_Pal:: @ 850FF9C
	.incbin "graphics/text_window/6.gbapal"

	.align 2
gTextWindowFrame7_Pal:: @ 850FFBC
	.incbin "graphics/text_window/7.gbapal"

	.align 2
gTextWindowFrame8_Pal:: @ 850FFDC
	.incbin "graphics/text_window/8.gbapal"

	.align 2
gTextWindowFrame9_Pal:: @ 850FFFC
	.incbin "graphics/text_window/9.gbapal"

	.align 2
gTextWindowFrame10_Pal:: @ 851001C
	.incbin "graphics/text_window/10.gbapal"

	.align 2
gTextWindowFrame11_Pal:: @ 851003C
	.incbin "graphics/text_window/11.gbapal"

	.align 2
gTextWindowFrame12_Pal:: @ 851005C
	.incbin "graphics/text_window/12.gbapal"

	.align 2
gTextWindowFrame13_Pal:: @ 851007C
	.incbin "graphics/text_window/13.gbapal"

	.align 2
gTextWindowFrame14_Pal:: @ 851009C
	.incbin "graphics/text_window/14.gbapal"

	.align 2
gTextWindowFrame15_Pal:: @ 85100BC
	.incbin "graphics/text_window/15.gbapal"

	.align 2
gTextWindowFrame16_Pal:: @ 85100DC
	.incbin "graphics/text_window/16.gbapal"

	.align 2
gTextWindowFrame17_Pal:: @ 85100FC
	.incbin "graphics/text_window/17.gbapal"

	.align 2
gTextWindowFrame18_Pal:: @ 851011C
	.incbin "graphics/text_window/18.gbapal"

	.align 2
gTextWindowFrame19_Pal:: @ 851013C
	.incbin "graphics/text_window/19.gbapal"

	.align 2
gTextWindowFrame20_Pal:: @ 851015C
	.incbin "graphics/text_window/20.gbapal"

	.align 2
gUnknown_0851017C:: @ 851017C
	.incbin "graphics/text_window/message_box.gbapal"

	.incbin "graphics/text_window/text_pal1.gbapal"
	.incbin "graphics/text_window/text_pal2.gbapal"
	.incbin "graphics/text_window/text_pal3.gbapal"
	.incbin "graphics/text_window/text_pal4.gbapal"

	.align 2
gUnknown_0851021C:: @ 851021C
	.4byte gTextWindowFrame1_Gfx, gTextWindowFrame1_Pal
	.4byte gTextWindowFrame2_Gfx, gTextWindowFrame2_Pal
	.4byte gTextWindowFrame3_Gfx, gTextWindowFrame3_Pal
	.4byte gTextWindowFrame4_Gfx, gTextWindowFrame4_Pal
	.4byte gTextWindowFrame5_Gfx, gTextWindowFrame5_Pal
	.4byte gTextWindowFrame6_Gfx, gTextWindowFrame6_Pal
	.4byte gTextWindowFrame7_Gfx, gTextWindowFrame7_Pal
	.4byte gTextWindowFrame8_Gfx, gTextWindowFrame8_Pal
	.4byte gTextWindowFrame9_Gfx, gTextWindowFrame9_Pal
	.4byte gTextWindowFrame10_Gfx, gTextWindowFrame10_Pal
	.4byte gTextWindowFrame11_Gfx, gTextWindowFrame11_Pal
	.4byte gTextWindowFrame12_Gfx, gTextWindowFrame12_Pal
	.4byte gTextWindowFrame13_Gfx, gTextWindowFrame13_Pal
	.4byte gTextWindowFrame14_Gfx, gTextWindowFrame14_Pal
	.4byte gTextWindowFrame15_Gfx, gTextWindowFrame15_Pal
	.4byte gTextWindowFrame16_Gfx, gTextWindowFrame16_Pal
	.4byte gTextWindowFrame17_Gfx, gTextWindowFrame17_Pal
	.4byte gTextWindowFrame18_Gfx, gTextWindowFrame18_Pal
	.4byte gTextWindowFrame19_Gfx, gTextWindowFrame19_Pal
	.4byte gTextWindowFrame20_Gfx, gTextWindowFrame20_Pal
