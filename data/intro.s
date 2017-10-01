	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gIntro1DropsPal:: @ 85DFF90
	.incbin "graphics/intro/intro1_drops.gbapal"

	.align 2
gIntro1GFLogoPal:: @ 85DFFB0
	.incbin "graphics/intro/intro1_gflogo.gbapal"

	.align 2
gIntroTiles:: @ 85DFFD0
	.incbin "graphics/intro/intro.4bpp.lz"

	.align 2
gIntro1BGPals:: @ 85E05C4
	.incbin "graphics/intro/intro1_bgpal.gbapal"

	.align 2
gIntro1BG0_Tilemap:: @ 85E07C4
	.incbin "graphics/intro/intro1_bg0_map.bin.lz"

	.align 2
gIntro1BG1_Tilemap:: @ 85E0B78
	.incbin "graphics/intro/intro1_bg1_map.bin.lz"

	.align 2
gIntro1BG2_Tilemap:: @ 85E0EAC
	.incbin "graphics/intro/intro1_bg2_map.bin.lz"

	.align 2
gIntro1BG3_Tilemap:: @ 85E119C
	.incbin "graphics/intro/intro1_bg3_map.bin.lz"

	.align 2
gIntro1BGLeavesGfx:: @ 85E13B4
	.incbin "graphics/intro/introgfx.4bpp.lz"

	.align 2
gIntro3PokeballPal:: @ 85E3524
	.incbin "graphics/intro/intro3_pokeball.gbapal"

	.align 2
gIntro3Pokeball_Tilemap:: @ 85E3724
	.incbin "graphics/intro/intro3_pokeball_map.bin.lz"

	.align 2
gIntro3Pokeball_Gfx:: @ 85E3854
	.incbin "graphics/intro/intro3_pokeball.8bpp.lz"

	.align 2
	.incbin "graphics/intro/intro3_streaks.gbapal"

	.align 2
	.incbin "graphics/intro/intro3_streaks.4bpp.lz"

	.align 2
	.incbin "graphics/intro/intro3_streaks_map.bin.lz"

	.align 2
gIntro3Misc1Pal:: @ 85E4570
	.incbin "graphics/intro/intro3_misc1.gbapal"

	.align 2
	.incbin "graphics/intro/intro3_misc2.gbapal"

	.align 2
gIntro3MiscTiles:: @ 85E45B0
	.incbin "graphics/intro/intro3_misc.4bpp.lz"

	.align 2
gIntro1FlygonPal:: @ 85E492C
	.incbin "graphics/intro/intro1_flygon.gbapal"

	.align 2
	.incbin "graphics/intro/intro1_eon.4bpp.lz"

	.align 2
	.byte 0x02, 0x03, 0x04, 0x05, 0x01, 0x01, 0x01, 0x06
	.byte 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x02, 0x0d
	.byte 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15
	.byte 0x16, 0x17, 0x18, 0x19, 0x02, 0x0d, 0x0e, 0x0f
	.byte 0x10, 0x11, 0x12, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e
	.byte 0x1f, 0x20, 0x21, 0x02, 0x0d, 0x0e, 0x0f, 0x10
	.byte 0x11, 0x12, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27
	.byte 0x28, 0x29, 0x2a, 0x00

	.align 2
gUnknown_085E4A74:: @ 85E4A74
	obj_tiles gIntro1SparkleGfx, 0x0400, 0x05e1
	null_obj_tiles

	.align 2
gUnknown_085E4A84:: @ 85E4A84
	obj_pal gIntro3LightningPal, 0x05e1
	null_obj_pal

	.align 2
gUnknown_085E4A94:: @ 85E4A94
	.byte 0xa0, 0x00, 0x00, 0x40, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_085E4A9C:: @ 85E4A9C
	.2byte 0x0000, 0x0002, 0x0004, 0x0002, 0x0008, 0x0002, 0x000c, 0x0002, 0x0010, 0x0002, 0xfffe, 0x0000

	.align 2
gUnknown_085E4AB4:: @ 85E4AB4
	.4byte gUnknown_085E4A9C

	.align 2
gUnknown_085E4AB8:: @ 85E4AB8
	spr_template 0x05e1, 0x05e1, gUnknown_085E4A94, gUnknown_085E4AB4, NULL, gDummySpriteAffineAnimTable, sub_816D338

	.align 2
gUnknown_085E4AD0:: @ 85E4AD0
	.byte 0x7c, 0x28, 0x66, 0x1e, 0x4d, 0x1e, 0x36, 0x0f
	.byte 0x94, 0x09, 0x3f, 0x1c, 0x5d, 0x28, 0x94, 0x20
	.byte 0xad, 0x29, 0x5e, 0x14, 0xd0, 0x26, 0x00, 0x00

	.align 2
gUnknown_085E4AE8:: @ 85E4AE8
	obj_tiles gIntro2VolbeatGfx, 0x0400, 0x05dc
	obj_tiles gIntro2TorchicGfx, 0x0c00, 0x05dd
	obj_tiles gIntro2ManectricGfx, 0x2000, 0x05de
	null_obj_tiles

	.align 2
gUnknown_085E4B08:: @ 85E4B08
	obj_pal gIntro2VolbeatPal, 0x05dc
	obj_pal gIntro2TorchicPal, 0x05dd
	obj_pal gIntro2ManectricPal, 0x05de
	null_obj_pal

	.align 2
gUnknown_085E4B28:: @ 85E4B28
	.byte 0xa0, 0x00, 0x00, 0x80, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_085E4B30:: @ 85E4B30
	.2byte 0x0000, 0x0002, 0x0010, 0x0002, 0xfffe, 0x0000

	.align 2
gUnknown_085E4B3C:: @ 85E4B3C
	.4byte gUnknown_085E4B30

	.align 2
gUnknown_085E4B40:: @ 85E4B40
	spr_template 0x05dc, 0x05dc, gUnknown_085E4B28, gUnknown_085E4B3C, NULL, gDummySpriteAffineAnimTable, sub_816D81C

	.align 2
gUnknown_085E4B58:: @ 85E4B58
	.byte 0xa0, 0x00, 0x00, 0x80, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_085E4B60:: @ 85E4B60
	.2byte 0x0000, 0x0005, 0x0010, 0x0005, 0x0020, 0x0005, 0x0010, 0x0005, 0xfffe, 0x0000

	.align 2
gUnknown_085E4B74:: @ 85E4B74
	.2byte 0x0000, 0x0003, 0x0010, 0x0003, 0x0020, 0x0003, 0x0010, 0x0003, 0xfffe, 0x0000

	.align 2
gUnknown_085E4B88:: @ 85E4B88
	.2byte 0x0030, 0x0004, 0x0040, 0x0006, 0x0050, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_085E4B98:: @ 85E4B98
	.4byte gUnknown_085E4B60
	.4byte gUnknown_085E4B74
	.4byte gUnknown_085E4B88

	.align 2
gUnknown_085E4BA4:: @ 85E4BA4
	spr_template 0x05dd, 0x05dd, gUnknown_085E4B58, gUnknown_085E4B98, NULL, gDummySpriteAffineAnimTable, sub_816D9C0

	.align 2
gUnknown_085E4BBC:: @ 85E4BBC
	.byte 0xa0, 0x00, 0x00, 0xc0, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_085E4BC4:: @ 85E4BC4
	.2byte 0x0000, 0x0004, 0x0040, 0x0004, 0x0080, 0x0004, 0x00c0, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_085E4BD8:: @ 85E4BD8
	.4byte gUnknown_085E4BC4

	.align 2
gUnknown_085E4BDC:: @ 85E4BDC
	spr_template 0x05de, 0x05de, gUnknown_085E4BBC, gUnknown_085E4BD8, NULL, gDummySpriteAffineAnimTable, sub_816DAE8

	.align 2
gUnknown_085E4BF4:: @ 85E4BF4
	obj_tiles gIntro3LightningGfx, 0x0c00, 0x05df
	null_obj_tiles

	.align 2
gUnknown_085E4C04:: @ 85E4C04
	obj_pal gIntro3LightningPal, 0x05df
	null_obj_pal

	.align 2
gUnknown_085E4C14:: @ 85E4C14
	.byte 0xa0, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_085E4C1C:: @ 85E4C1C
	.2byte 0x0000, 0x0002, 0x0030, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_085E4C28:: @ 85E4C28
	.2byte 0x0010, 0x0002, 0x0040, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_085E4C34:: @ 85E4C34
	.2byte 0x0020, 0x0002, 0x0050, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_085E4C40:: @ 85E4C40
	.4byte gUnknown_085E4C1C
	.4byte gUnknown_085E4C28
	.4byte gUnknown_085E4C34

	.align 2
gUnknown_085E4C4C:: @ 85E4C4C
	spr_template 0x05df, 0x05df, gUnknown_085E4C14, gUnknown_085E4C40, NULL, gDummySpriteAffineAnimTable, sub_816EC6C

	.align 2
gUnknown_085E4C64:: @ 85E4C64
	.2byte 0x0068, 0x0000, 0x00c0, 0x008e, 0x0003, 0x0280, 0x0053, 0x0001
	.2byte 0x0180, 0x009b, 0x0000, 0x0080, 0x0038, 0x0002, 0x0200, 0x00ae
	.2byte 0x0001, 0x0100

	.align 2
gUnknown_085E4C88:: @ 85E4C88
	obj_tiles gIntro2BubblesGfx, 0x0600, 0x05e0
	null_obj_tiles

	.align 2
gUnknown_085E4C98:: @ 85E4C98
	obj_pal gIntro2BubblesPal, 0x05e0
	null_obj_pal

	.align 2
gUnknown_085E4CA8:: @ 85E4CA8
	.2byte 0x0042, 0x0040, 0x0001, 0x0060, 0x0060, 0x0008, 0x0080, 0x0040
	.2byte 0x0001, 0x0090, 0x0030, 0x0008, 0x00a0, 0x0048, 0x0001, 0x00b0
	.2byte 0x0060, 0x0008, 0x0060, 0x0060, 0x0004, 0x0070, 0x0068, 0x0008
	.2byte 0x0080, 0x0060, 0x0004, 0x0058, 0x0020, 0x0004, 0x0068, 0x0018
	.2byte 0x0008, 0x0078, 0x0020, 0x0004

	.align 2
gUnknown_085E4CF0:: @ 85E4CF0
	.byte 0xa0, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_085E4CF8:: @ 85E4CF8
	.2byte 0x0000, 0x0004, 0x0008, 0x0004, 0x0010, 0x0004, 0x0018, 0x0004
	.2byte 0x0020, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085E4D10:: @ 85E4D10
	.4byte gUnknown_085E4CF8

	.align 2
gUnknown_085E4D14:: @ 85E4D14
	spr_template 0x05e0, 0x05e0, gUnknown_085E4CF0, gUnknown_085E4D10, NULL, gDummySpriteAffineAnimTable, sub_816E7B4

	.align 2
gUnknown_085E4D2C:: @ 85E4D2C
	.byte 0xa0, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_085E4D34:: @ 85E4D34
	.2byte 0x0010, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4D3C:: @ 85E4D3C
	.2byte 0x0018, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4D44:: @ 85E4D44
	.2byte 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4D4C:: @ 85E4D4C
	.2byte 0x0030, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4D54:: @ 85E4D54
	.4byte gUnknown_085E4D34
	.4byte gUnknown_085E4D3C
	.4byte gUnknown_085E4D44
	.4byte gUnknown_085E4D4C

	.align 2
gUnknown_085E4D64:: @ 85E4D64
	spr_template 0x07d0, 0x07d0, gUnknown_085E4D2C, gUnknown_085E4D54, NULL, gDummySpriteAffineAnimTable, sub_816F454

	.align 2
gUnknown_085E4D7C:: @ 85E4D7C
	.byte 0x00, 0x00, 0x04, 0x00, 0x40, 0x00, 0x04, 0x00

	.align 2
gUnknown_085E4D84:: @ 85E4D84
	.2byte 0x0080, 0x0004, 0x00c0, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_085E4D90:: @ 85E4D90
	.2byte 0x0000, 0x0008, 0x0040, 0x0008, 0x0080, 0x0008, 0x00c0, 0x0008, 0xfffe, 0x0000

	.align 2
gUnknown_085E4DA4:: @ 85E4DA4
	.2byte 0x0100, 0x0004, 0x0140, 0x0004, 0x0180, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085E4DB4:: @ 85E4DB4
	.2byte 0x0180, 0x0010, 0x0140, 0x0010, 0x0100, 0x0010, 0xffff, 0x0000

	.align 2
gUnknown_085E4DC4:: @ 85E4DC4
	.4byte gUnknown_085E4D7C
	.4byte gUnknown_085E4D90
	.4byte gUnknown_085E4DA4
	.4byte gUnknown_085E4DB4

	.align 2
gUnknown_085E4DD4:: @ 85E4DD4
	.2byte 0x03a0, 0x4000, 0x0000, 0x0000

	.align 2
gUnknown_085E4DDC:: @ 85E4DDC
	.2byte 0x00a0, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085E4DE4:: @ 85E4DE4
	.2byte 0x87a0, 0xc000, 0x0000, 0x0000

	.align 2
gUnknown_085E4DEC:: @ 85E4DEC
	.2byte 0x0050, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4DF4:: @ 85E4DF4
	.2byte 0x0054, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4DFC:: @ 85E4DFC
	.2byte 0x0058, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E04:: @ 85E4E04
	.2byte 0x005c, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E0C:: @ 85E4E0C
	.2byte 0x0060, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E14:: @ 85E4E14
	.2byte 0x0064, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E1C:: @ 85E4E1C
	.2byte 0x0068, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E24:: @ 85E4E24
	.2byte 0x0070, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E2C:: @ 85E4E2C
	.2byte 0x0071, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E34:: @ 85E4E34
	.2byte 0x0072, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E3C:: @ 85E4E3C
	.2byte 0x0073, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E44:: @ 85E4E44
	.2byte 0x0074, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E4C:: @ 85E4E4C
	.2byte 0x0075, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E54:: @ 85E4E54
	.2byte 0x0080, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E4E5C:: @ 85E4E5C
	.4byte gUnknown_085E4DEC
	.4byte gUnknown_085E4DF4
	.4byte gUnknown_085E4DFC
	.4byte gUnknown_085E4E04
	.4byte gUnknown_085E4E0C
	.4byte gUnknown_085E4E14
	.4byte gUnknown_085E4E1C

	.align 2
gUnknown_085E4E78:: @ 85E4E78
	.4byte gUnknown_085E4E24
	.4byte gUnknown_085E4E2C
	.4byte gUnknown_085E4E34
	.4byte gUnknown_085E4E3C
	.4byte gUnknown_085E4E44
	.4byte gUnknown_085E4E4C

	.align 2
gUnknown_085E4E90:: @ 85E4E90
	.4byte gUnknown_085E4E54

	.align 2
gUnknown_085E4E94:: @ 85E4E94
	.2byte 0x0000, 0xffb8, 0x0001, 0xffc8, 0x0002, 0xffd8, 0x0003, 0xffe8
	.2byte 0x0004, 0x0008, 0x0005, 0x0018, 0x0003, 0x0028, 0x0001, 0x0038
	.2byte 0x0006, 0x0048, 0x0000, 0xffe4, 0x0001, 0xffec, 0x0002, 0xfff4
	.2byte 0x0003, 0xfffc, 0x0002, 0x0004, 0x0004, 0x000c, 0x0005, 0x0014
	.2byte 0x0003, 0x001c

	.align 2
gUnknown_085E4ED8:: @ 85E4ED8
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085E4EE8:: @ 85E4EE8
	.2byte 0x0080, 0x0080, 0x0000, 0x0000, 0x0010, 0x0010, 0x1000, 0x0000
	.2byte 0xfff0, 0xfff0, 0x0800, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085E4F08:: @ 85E4F08
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0008, 0x0008, 0x3000, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085E4F20:: @ 85E4F20
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0002, 0x0002, 0x3000, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085E4F38:: @ 85E4F38
	.4byte gUnknown_085E4ED8
	.4byte gUnknown_085E4EE8
	.4byte gUnknown_085E4F08
	.4byte gUnknown_085E4F20

	.align 2
gUnknown_085E4F48:: @ 85E4F48
	.2byte 0x0100, 0x00c0, 0x0080, 0x0040, 0x0000, 0x0040, 0x0080, 0x00c0
	.2byte 0x0100, 0x0000

	.align 2
gUnknown_085E4F5C:: @ 85E4F5C
	spr_template 0x07d0, 0x07d1, gUnknown_085E4DD4, gUnknown_085E4E5C, NULL, gUnknown_085E4F38, sub_816FB38
	spr_template 0x07d0, 0x07d1, gUnknown_085E4DDC, gUnknown_085E4E78, NULL, gDummySpriteAffineAnimTable, sub_816FB38

	.align 2
gUnknown_085E4F8C:: @ 85E4F8C
	spr_template 0x07d0, 0x07d1, gUnknown_085E4DE4, gUnknown_085E4E90, NULL, gUnknown_085E4F38, sub_816FD44

	.align 2
gUnknown_085E4FA4:: @ 85E4FA4
	.byte 0x00, 0x17, 0x17, 0x31, 0x3e, 0x24, 0x24, 0x0a, 0x0a, 0x00, 0x00, 0x00

	.align 2
gUnknown_085E4FB0:: @ 85E4FB0
	.byte 0xa0, 0x40, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_085E4FB8:: @ 85E4FB8
	.2byte 0x0000, 0x000a, 0xfffe, 0x0000

	.align 2
gUnknown_085E4FC0:: @ 85E4FC0
	.4byte gUnknown_085E4FB8

	.align 2
gUnknown_085E4FC4:: @ 85E4FC4
	spr_template 0x07d2, 0x07d2, gUnknown_085E4FB0, gUnknown_085E4FC0, NULL, gDummySpriteAffineAnimTable, sub_816FEDC

	.align 2
gUnknown_085E4FDC:: @ 85E4FDC
	obj_tiles gIntroTiles, 0x1400, 0x07d0
	null_obj_tiles

gUnknown_085E4FEC:: @ 85E4FEC
	obj_tiles gIntro1FlygonGfx, 0x0400, 0x07d2
	null_obj_tiles

	.align 2
gUnknown_085E4FFC:: @ 85E4FFC
	obj_pal gIntro1DropsPal, 0x07d0
	obj_pal gIntro1GFLogoPal, 0x07d1
	obj_pal gIntro1FlygonPal, 0x07d2
	null_obj_pal

	.align 2
gUnknown_085E501C:: @ 85E501C
	.byte 0xa0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_085E5024:: @ 85E5024
	.2byte 0x0010, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E502C:: @ 85E502C
	.4byte gUnknown_085E5024

	.align 2
gUnknown_085E5030:: @ 85E5030
	spr_template 0x07d3, 0x07d3, gUnknown_085E501C, gUnknown_085E502C, NULL, gDummySpriteAffineAnimTable, sub_8170040

	.align 2
gUnknown_085E5048:: @ 85E5048
	obj_tiles gIntro3MiscTiles, 0x0a00, 0x07d3
	null_obj_tiles

gUnknown_085E5058:: @ 85E5058
	obj_pal gIntro3Misc1Pal, 0x07d3
	null_obj_pal

