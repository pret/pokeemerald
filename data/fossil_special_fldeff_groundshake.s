	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_08617274:: @ 8617274
	.space 0x20
	.incbin "graphics/misc/mirage_tower.4bpp"

	.align 2
gUnknown_08617B94:: @ 8617B94
	.incbin "graphics/misc/mirage_tower.bin"

	.align 2
gRootFossil_Pal:: @ 8617C24
	.incbin "graphics/misc/fossil.gbapal"

	.align 2
gRootFossil_Gfx:: @ 8617C44
	.incbin "graphics/misc/fossil.4bpp"

	.align 2
gMirageTowerCrumbles_Gfx:: @ 8617CC4
	.incbin "graphics/misc/mirage_tower_crumbles.4bpp"

	.align 2
gMirageTowerCrumbles_Palette:: @ 8617D44
	.incbin "graphics/misc/mirage_tower_crumbles.gbapal"

	.align 1
gUnknown_08617D64:: @ 8617D64
	.2byte 0x0000, 0x000a, 0x0041, 0x0011, 0x0003, 0x0032, 0xfff4, 0x0000, 0x004b, 0x000a, 0x000f, 0x005a, 0x0007, 0x0008, 0x0041, 0xffee
	.2byte 0x0005, 0x004b, 0x0016, 0xfff6, 0x0037, 0xffe8, 0xfffc, 0x0041

	.align 2
gUnknown_08617D94:: @ 8617D94
	obj_tiles gMirageTowerCrumbles_Gfx, 0x0080, 0x0fa0
	null_obj_tiles

	.align 2
gUnknown_08617DA4:: @ 8617DA4
	.byte 0x12, 0x35, 0x51, 0x02, 0x13, 0x35, 0x51, 0x02, 0x14, 0x35, 0x51, 0x02, 0x12, 0x36, 0x51, 0x02, 0x13, 0x36, 0x51, 0x02, 0x14, 0x36, 0x51, 0x02, 0x12, 0x37, 0x51, 0x02, 0x13, 0x37, 0x51, 0x02
	.byte 0x14, 0x37, 0x51, 0x02, 0x12, 0x38, 0x51, 0x02, 0x13, 0x38, 0x51, 0x02, 0x14, 0x38, 0x51, 0x02, 0x12, 0x39, 0x59, 0x02, 0x13, 0x39, 0x59, 0x02, 0x14, 0x39, 0x59, 0x02, 0x12, 0x3a, 0x21, 0x01
	.byte 0x13, 0x3a, 0x21, 0x01, 0x14, 0x3a, 0x21, 0x01

	.align 2
gSpriteAnim_8617DEC:: @ 8617DEC
	.2byte 0x0000, 0x0001, 0xffff, 0x0000

	.align 2
gOamData_8617DF4:: @ 8617DF4
	.2byte 0x0000, 0x4000, 0x3000, 0x0000

	.align 2
gSpriteAnimTable_8617DFC:: @ 8617DFC
	.4byte gSpriteAnim_8617DEC

	.align 2
gUnknown_08617E00:: @ 8617E00
	spr_template 0xffff, 0xffff, gOamData_8617DF4, gSpriteAnimTable_8617DFC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08617E18:: @ 8617E18
	.byte 0x3b, 0x43, 0x61, 0x00, 0x0f, 0x05, 0xff, 0x9b

	.align 2
gSpriteAnim_8617E20:: @ 8617E20
	.2byte 0x0000, 0x000c, 0xfffe, 0x0000

	.align 2
gSpriteAnimTable_8617E28:: @ 8617E28
	.4byte gSpriteAnim_8617E20

	.align 2
gUnknown_08617E2C:: @ 8617E2C
	.2byte 0x0000, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_08617E34:: @ 8617E34
	spr_template 0x0fa0, 0xffff, gUnknown_08617E2C, gSpriteAnimTable_8617E28, NULL, gDummySpriteAffineAnimTable, sub_81BEAD8

	.align 2
gSpriteAnim_8617E4C:: @ 8617E4C
	.2byte 0x0000, 0x000c, 0xfffe, 0x0000

	.align 2
gSpriteAnim_8617E54:: @ 8617E54
	.4byte gSpriteAnim_8617E4C

	.align 2
gOamData_8617E58:: @ 8617E58
	.2byte 0x0000, 0x4000, 0x0000, 0x0000

	.align 2
gUnknown_08617E60:: @ 8617E60
	spr_template 0x0fa0, 0xffff, gOamData_8617E58, gSpriteAnim_8617E54, NULL, gDummySpriteAffineAnimTable, sub_81BEAD8

