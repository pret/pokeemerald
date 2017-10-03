    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gTitleScreenRayquazaGfx:: @ 853F058
	.incbin "graphics/title_screen/rayquaza.4bpp.lz"

	.align 2
gTitleScreenRayquazaTilemap:: @ 853F83C
	.incbin "graphics/title_screen/rayquaza.bin.lz"

	.align 2
gTitleScreenLogoShineGfx:: @ 853FB3C
	.incbin "graphics/title_screen/logo_shine.4bpp.lz"

	.align 2
gTitleScreenCloudsGfx:: @ 853FC8C
	.incbin "graphics/title_screen/clouds.4bpp.lz"

	.align 2
gUnknown_0853FF70:: @ 853FF70
	.2byte 0x0010, 0x0110, 0x0210, 0x0310, 0x0410, 0x0510, 0x0610, 0x0710
	.2byte 0x0810, 0x0910, 0x0a10, 0x0b10, 0x0c10, 0x0d10, 0x0e10, 0x0f10
	.2byte 0x100f, 0x100e, 0x100d, 0x100c, 0x100b, 0x100a, 0x1009, 0x1008
	.2byte 0x1007, 0x1006, 0x1005, 0x1004, 0x1003, 0x1002, 0x1001, 0x1000
	.2byte 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000
	.2byte 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000
	.2byte 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000
	.2byte 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000

	.align 2
gUnknown_0853FFF0:: @ 853FFF0
	.byte 0xa0, 0x60, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_0853FFF8:: @ 853FFF8
	.byte 0xa0, 0x60, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_08540000:: @ 8540000
	.2byte 0x0000, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_08540008:: @ 8540008
	.2byte 0x0040, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_08540010:: @ 8540010
	.4byte gUnknown_08540000

	.align 2
gUnknown_08540014:: @ 8540014
	.4byte gUnknown_08540008

	.align 2
gUnknown_08540018:: @ 8540018
	spr_template 0x03e8, 0x03e8, gUnknown_0853FFF0, gUnknown_08540010, NULL, gDummySpriteAffineAnimTable, sub_80AA40C

	.align 2
gUnknown_08540030:: @ 8540030
	spr_template 0x03e8, 0x03e8, gUnknown_0853FFF8, gUnknown_08540014, NULL, gDummySpriteAffineAnimTable, sub_80AA474

	.align 2
gUnknown_08540048:: @ 8540048
	obj_tiles gTitleScreenEmeraldVersionGfx, 0x1000, 0x03e8
	null_obj_tiles

	.align 2
gUnknown_08540058:: @ 8540058
	.byte 0xa0, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_08540060:: @ 8540060
	.2byte 0x0001, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540068:: @ 8540068
	.2byte 0x0005, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540070:: @ 8540070
	.2byte 0x0009, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540078:: @ 8540078
	.2byte 0x000d, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540080:: @ 8540080
	.2byte 0x0011, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540088:: @ 8540088
	.2byte 0x0015, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540090:: @ 8540090
	.2byte 0x0019, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540098:: @ 8540098
	.2byte 0x001d, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085400A0:: @ 85400A0
	.2byte 0x0021, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085400A8:: @ 85400A8
	.2byte 0x0025, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085400B0:: @ 85400B0
	.4byte gUnknown_08540060
	.4byte gUnknown_08540068
	.4byte gUnknown_08540070
	.4byte gUnknown_08540078
	.4byte gUnknown_08540080
	.4byte gUnknown_08540088
	.4byte gUnknown_08540090
	.4byte gUnknown_08540098
	.4byte gUnknown_085400A0
	.4byte gUnknown_085400A8

	.align 2
gUnknown_085400D8:: @ 85400D8
	spr_template 0x03e9, 0x03e9, gUnknown_08540058, gUnknown_085400B0, NULL, gDummySpriteAffineAnimTable, sub_80AA4B4

	.align 2
gUnknown_085400F0:: @ 85400F0
	obj_tiles gTitleScreenPressStartGfx, 0x0520, 0x03e9
	null_obj_tiles

	.align 2
gUnknown_08540100:: @ 8540100
	obj_pal gTitleScreenPressStartPal, 0x03e9
	null_obj_pal

	.align 2
gUnknown_08540110:: @ 8540110
	.byte 0xa0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_08540118:: @ 8540118
	.2byte 0x0000, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08540120:: @ 8540120
	.4byte gUnknown_08540118

	.align 2
gUnknown_08540124:: @ 8540124
	spr_template 0x03ea, 0x03e9, gUnknown_08540110, gUnknown_08540120, NULL, gDummySpriteAffineAnimTable, title_screen_logo_shine_obj_callback_type1

	.align 2
gUnknown_0854013C:: @ 854013C
	obj_tiles gTitleScreenLogoShineGfx, 0x0800, 0x03ea
	null_obj_tiles
