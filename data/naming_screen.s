	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0858BBF8:: @ 858BBF8
	.incbin "graphics/naming_screen/pc_icon/0.4bpp"

	.align 2
gUnknown_0858BCB8:: @ 858BCB8
	.incbin "graphics/naming_screen/pc_icon/1.4bpp"

	.align 2
gUnknown_0858BD78:: @ 858BD78
	.incbin "graphics/naming_screen/0.gbapal"
	.incbin "graphics/naming_screen/1.gbapal"

	.align 2
gUnknown_0858BDB8:: @ 858BDB8
	.4byte gText_PkmnTransferredSomeonesPC
	.4byte gText_PkmnTransferredLanettesPC
	.4byte gText_PkmnBoxSomeonesPCFull
	.4byte gText_PkmnBoxLanettesPCFull

gUnknown_0858BDC8:: @ 858BDC8
	.string "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!$"

	.align 2
gUnknown_0858BE00:: @ 858BE00
	.4byte 0x000001e0, 0x000011d9, 0x000021ca, 0x000031ff

	.align 2
gUnknown_0858BE10:: @ 858BE10
	window_template 0x01, 0x03, 0x0a, 0x13, 0x08, 0x0a, 0x0030
	window_template 0x02, 0x03, 0x0a, 0x13, 0x08, 0x0a, 0x00c8
	window_template 0x03, 0x08, 0x06, 0x11, 0x02, 0x0a, 0x0030
	window_template 0x03, 0x08, 0x04, 0x11, 0x02, 0x0a, 0x0052
	window_template 0x00, 0x00, 0x00, 0x1e, 0x02, 0x0b, 0x0074
	null_window_template

gUnknown_0858BE40:: @ 858BE40
	.string "abcdef .ghijkl ,mnopqrs tuvwxyz ABCDEF .GHIJKL ,MNOPQRS TUVWXYZ 01234   56789   !?♂♀/-  …“”‘’   "

gUnknown_0858BEA0:: @ 858BEA0
	.byte 0x08, 0x08, 0x06

gUnknown_0858BEA3:: @ 858BEA3
	.byte 0x00, 0x0c, 0x18, 0x38, 0x44, 0x50, 0x5c, 0x7b, 0x00, 0x0c, 0x18, 0x38, 0x44, 0x50, 0x5c, 0x7b, 0x00, 0x16, 0x2c, 0x42, 0x58, 0x6e, 0x00, 0x00

gUnknown_0858BEBB:: @ 858BEBB
	.byte 0x00, 0x02, 0x01

gUnknown_0858BEBE:: @ 858BEBE
	.byte 0x01, 0x00, 0x02

gUnknown_0858BEC1:: @ 858BEC1
	.byte 0x02, 0x01, 0x00

gUnknown_0858BEC4:: @ 858BEC4
	.4byte sub_80E37B4
	.4byte sub_80E37DC
	.4byte sub_80E3870
	.4byte sub_80E3904

gUnknown_0858BED4:: @ 858BED4
	.2byte 0x0000, 0xfffc, 0xfffe, 0xffff

gUnknown_0858BEDC:: @ 858BEDC
	.2byte 0x0002, 0x0003, 0x0002, 0x0001

gUnknown_0858BEE4:: @ 858BEE4
	.byte 0x01, 0x02, 0x03, 0x00

gUnknown_0858BEE8:: @ 858BEE8
	.4byte sub_80E40AC
	.4byte sub_80E4100
	.4byte sub_80E4104
	.4byte sub_80E4178

gUnknown_0858BEF8:: @ 858BEF8
	.2byte 0x0001, 0x0003, 0x0002

gUnknown_0858BEFE:: @ 858BEFE
	.2byte 0x0004, 0x0006, 0x0005

gUnknown_0858BF04:: @ 858BF04
	.4byte TaskDummy2
	.4byte sub_80E4384
	.4byte sub_80E43E0
	.4byte sub_80E4420
	.4byte sub_80E447C

gUnknown_0858BF18:: @ 858BF18
	.4byte sub_80E450C
	.4byte sub_80E4558
	.4byte sub_80E4580
	.4byte sub_80E45A4

gUnknown_0858BF28:: @ 858BF28
	.4byte sub_80E468C
	.4byte sub_80E4692
	.4byte sub_80E46E8

gUnknown_0858BF34:: @ 858BF34
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x00

gUnknown_0858BF3E:: @ 858BF3E
	.byte 0x00, 0x00, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00

gUnknown_0858BF48:: @ 858BF48
	.byte 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00

gUnknown_0858BF50:: @ 858BF50
	.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00

	.align 2
gUnknown_0858BF58:: @ 858BF58
	.4byte sub_80E4894
	.4byte sub_80E4894
	.4byte sub_80E48E8
	.4byte sub_80E48E8
	.4byte sub_80E4894

	.align 2
gUnknown_0858BF6C:: @ 858BF6C
	.4byte TaskDummy3
	.4byte sub_80E49BC

	.align 2
gUnknown_0858BF74:: @ 858BF74
	window_template 0x00, 0x09, 0x08, 0x00, 0x05, 0x04, 0x0000

gUnknown_0858BF7C:: @ 858BF7C
	.4byte 0x0002010D
	
gUnknown_0858BF80:: @ 858BF80
	.4byte 0x0002010E
	
gUnknown_0858BF84:: @ 858BF84
	.4byte 0x0002010F

gUnknown_0858BF88:: @ 858BF88
	.byte 0xee, 0xdd, 0xff, 0x00

gUnknown_0858BF8C:: @ 858BF8C
	.4byte gUnknown_0858BF80
	.4byte gUnknown_0858BF7C
	.4byte gUnknown_0858BF84

gUnknown_0858BF98:: @ 858BF98
	.4byte gUnknown_08DD4620
	.4byte gUnknown_08DD46E0
	.4byte gUnknown_08DD47A0

gUnknown_0858BFA4:: @ 858BFA4
	.byte 0x0f, 0x01, 0x02

	.align 2
gUnknown_0858BFA8:: @ 858BFA8
	.byte 0x00, 0x07, 0x01, 0x00, 0x01, 0x23, 0x00, 0x00
	.4byte gText_YourName

	.align 2
gUnknown_0858BFB4:: @ 858BFB4
	.byte 0x00, 0x08, 0x02, 0x00, 0x01, 0x13, 0x00, 0x00
	.4byte gText_BoxName

	.align 2
gUnknown_0858BFC0:: @ 858BFC0
	.byte 0x00, 0x0a, 0x03, 0x01, 0x01, 0x23, 0x00, 0x00
	.4byte gText_PkmnsNickname

	.align 2
gUnknown_0858BFCC:: @ 858BFCC
	.byte 0x01, 0x0f, 0x04, 0x00, 0x01, 0x0b, 0x00, 0x00
	.4byte gText_TellHimTheWords

	.align 2
gUnknown_0858BFD8:: @ 858BFD8
	.4byte gUnknown_0858BFA8
	.4byte gUnknown_0858BFB4
	.4byte gUnknown_0858BFC0
	.4byte gUnknown_0858BFC0
	.4byte gUnknown_0858BFCC

	.align 2
gOamData_858BFEC:: @ 858BFEC
	.2byte 0x0000, 0x0000, 0x0000, 0x0000

	.align 2
gOamData_858BFF4:: @ 858BFF4
	.2byte 0x0000, 0x4000, 0x0000, 0x0000

	.align 2
gOamData_858BFFC:: @ 858BFFC
	.2byte 0x4000, 0x8000, 0x0000, 0x0000

	.align 2
gUnknown_0858C004:: @ 858C004
	.byte 0xec, 0xf0, 0x05, 0x40, 0x0c, 0xf0, 0x40, 0x40, 0xec, 0xf8, 0x55, 0x40, 0x0c, 0xf8, 0x90, 0x40, 0xec, 0x00, 0xa5, 0x40, 0x0c, 0x00, 0xe0, 0x40, 0xec, 0x08, 0xf5, 0x40, 0x0c, 0x08, 0x30, 0x41

	.align 2
gUnknown_0858C024:: @ 858C024
	.byte 0xf4, 0xfc, 0x01, 0x40, 0x04, 0xfc, 0x20, 0x40

	.align 2
gUnknown_0858C02C:: @ 858C02C
	.byte 0xec, 0xf4, 0x05, 0x40, 0x0c, 0xf4, 0x40, 0x40, 0xec, 0xfc, 0x55, 0x40, 0x0c, 0xfc, 0x90, 0x40, 0xec, 0x04, 0xa5, 0x40, 0x0c, 0x04, 0xe0, 0x40

	.align 2
gUnknown_0858C044:: @ 858C044
	.byte 0xf8, 0xf4, 0x01, 0xc0, 0xf8, 0xfc, 0x21, 0xc0, 0xf8, 0x04, 0x41, 0xc0

	.align 2
gUnknown_0858C050:: @ 858C050
	.byte 0x08, 0x00, 0x00, 0x00
	.4byte gUnknown_0858C004

	.align 2
gUnknown_0858C058:: @ 858C058
	.4byte 0x02
	.4byte gUnknown_0858C024
	.4byte 0x02
	.4byte gUnknown_0858C024
	.4byte 0x02
	.4byte gUnknown_0858C024

	.align 2
gUnknown_0858C070:: @ 858C070
	.4byte 0x06
	.4byte gUnknown_0858C02C

	.align 2
gUnknown_0858C078:: @ 858C078
	.4byte 0x03
	.4byte gUnknown_0858C044

	.align 2
gUnknown_0858C080:: @ 858C080
	obj_frame_tiles gUnknown_0858BBF8, 0x00c0
	obj_frame_tiles gUnknown_0858BCB8, 0x00c0

	.align 2
gSpriteAnim_858C090:: @ 858C090
	.2byte 0x0000, 0x0001, 0xfffe, 0x0000

	.align 2
gSpriteAnim_858C098:: @ 858C098
	.2byte 0x0004, 0x0008, 0x0008, 0x0008, 0xffff, 0x0000

	.align 2
gSpriteAnim_858C0A4:: @ 858C0A4
	.2byte 0x0000, 0x0002, 0x0001, 0x0002, 0xfffe, 0x0000

	.align 2
gSpriteAnimTable_858C0B0:: @ 858C0B0
	.4byte gSpriteAnim_858C090

	.align 2
gSpriteAnimTable_858C0B4:: @ 858C0B4
	.4byte gSpriteAnim_858C090
	.4byte gSpriteAnim_858C098

	.align 2
gSpriteAnimTable_858C0BC:: @ 858C0BC
	.4byte gSpriteAnim_858C0A4

	.align 2
gUnknown_0858C0C0:: @ 858C0C0
	spr_template 0x0002, 0x0004, gOamData_858BFEC, gSpriteAnimTable_858C0B0, NULL, gDummySpriteAffineAnimTable, sub_80E4084

	.align 2
gUnknown_0858C0D8:: @ 858C0D8
	spr_template 0x0003, 0x0001, gOamData_858BFFC, gSpriteAnimTable_858C0B0, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0858C0F0:: @ 858C0F0
	spr_template 0x0004, 0x0004, gOamData_858BFEC, gSpriteAnimTable_858C0B0, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0858C108:: @ 858C108
	spr_template 0x0000, 0x0006, gOamData_858BFEC, gSpriteAnimTable_858C0B0, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0858C120:: @ 858C120
	spr_template 0x0001, 0x0007, gOamData_858BFEC, gSpriteAnimTable_858C0B0, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0858C138:: @ 858C138
	spr_template 0x0007, 0x0005, gOamData_858BFF4, gSpriteAnimTable_858C0B4, NULL, gDummySpriteAffineAnimTable, sub_80E3B30

	.align 2
gUnknown_0858C150:: @ 858C150
	spr_template 0x000a, 0x0003, gOamData_858BFEC, gSpriteAnimTable_858C0B0, NULL, gDummySpriteAffineAnimTable, sub_80E3C20

	.align 2
gUnknown_0858C168:: @ 858C168
	spr_template 0x000b, 0x0003, gOamData_858BFEC, gSpriteAnimTable_858C0B0, NULL, gDummySpriteAffineAnimTable, sub_80E3C6C

	.align 2
gUnknown_0858C180:: @ 858C180
	spr_template 0xffff, 0x0000, gOamData_858BFEC, gSpriteAnimTable_858C0BC, gUnknown_0858C080, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0858C198:: @ 858C198
	.4byte gUnknown_0862B88D
	.4byte gUnknown_0862B8AE
	.4byte gUnknown_0862B8CF
	.4byte gUnknown_0862B8F0
	.4byte gUnknown_0862B911
	.4byte gUnknown_0862B932
	.4byte gUnknown_0862B953
	.4byte gUnknown_0862B974
	.4byte gUnknown_0862B995
	.4byte gUnknown_0862B9AE
	.4byte gUnknown_0862B9C7
	.4byte gUnknown_0862B9E0

	.align 2
gUnknown_0858C1C8:: @ 858C1C8
	obj_tiles gNamingScreenRWindow_Gfx+0x280, 0x01e0, 0x0000
	obj_tiles gNamingScreenRWindow_Gfx+0x460, 0x01e0, 0x0001
	obj_tiles gNamingScreenRWindow_Gfx, 0x0280, 0x0002
	obj_tiles gNamingScreenKeyboardButton_Gfx+0x20, 0x0100, 0x0003
	obj_tiles gNamingScreenROptions_Gfx, 0x0060, 0x0004
	obj_tiles gNamingScreenROptions_Gfx+0xA0, 0x0060, 0x0005
	obj_tiles gNamingScreenROptions_Gfx+0x140, 0x0060, 0x0006
	obj_tiles gNamingScreenCursor_Gfx, 0x0080, 0x0007
	obj_tiles gNamingScreenCursor_Gfx+0xA0, 0x0080, 0x0008
	obj_tiles gNamingScreenCursor_Gfx+0x140, 0x0080, 0x0009
	obj_tiles gNamingScreenRightPointingTriangleTiles, 0x0020, 0x000a
	obj_tiles gNamingScreenUnderscoreTiles, 0x0020, 0x000b
	null_obj_tiles

	.align 2
gUnknown_0858C230:: @ 858C230
	obj_pal gNamingScreenMenu_Pal, 0x0000
	obj_pal gNamingScreenMenu_Pal+0x20, 0x0001
	obj_pal gNamingScreenMenu_Pal+0x40, 0x0002
	obj_pal gNamingScreenMenu_Pal+0x60, 0x0003
	obj_pal gNamingScreenMenu_Pal+0x80, 0x0004
	obj_pal gNamingScreenMenu_Pal+0xA0, 0x0005
	obj_pal gNamingScreenMenu_Pal+0x80, 0x0006
	obj_pal gNamingScreenMenu_Pal+0x80, 0x0007
	null_obj_pal
