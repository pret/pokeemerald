	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_0861D1A0:: @ 861D1A0
	.incbin "graphics/interface/region_map.8bpp.lz"

	.align 2
gUnknown_0861DEF4:: @ 861DEF4
	.incbin "graphics/interface/region_map.bin.lz"

	.align 2
gUnknown_0861E208:: @ 861E208
	.incbin "graphics/interface/region_map_affine.8bpp.lz"

	.align 2
gUnknown_0861EF64:: @ 861EF64
	.incbin "graphics/interface/region_map_affine.bin.lz"

	.align 2
gUnknown_0861F2B4:: @ 861F2B4
	.4byte 0x000011f0, 0x000001e1, 0x000021de

	.align 2
gUnknown_0861F2C0:: @ 861F2C0
	.4byte 0x00000000, sub_81C5460, sub_81C5518, 0x00000000, 0x00080000, 0x07003021

	.align 2
gUnknown_0861F2D8:: @ 861F2D8
	.4byte gMenuText_Use, sub_81C61E0
	.4byte gMenuText_Toss, sub_81C62C4
	.4byte gMenuText_Give, sub_81C6648
	.4byte gText_Cancel2, sub_81C6258
	.4byte gMenuText_Use, sub_81C679C
	.4byte gText_EmptyString2, NULL

gUnknown_0861F308:: @ 861F308
	.byte 0x00, 0x02, 0x01, 0x03

gUnknown_0861F30C:: @ 861F30C
	.byte 0x01, 0x03

gUnknown_0861F30E:: @ 861F30E
	.byte 0x04, 0x03

gUnknown_0861F310:: @ 861F310
	.byte 0x03, 0x00, 0x00, 0x00

gUnknown_0861F314:: @ 861F314
	.4byte sub_81C654C
	.4byte sub_81C63D0

gUnknown_0861F31C:: @ 861F31C
	.byte 0x00, 0x02, 0x03, 0x00, 0x03, 0x01, 0x01, 0x02, 0x03, 0x00, 0x00, 0x00

	.align 2
gUnknown_0861F328:: @ 861F328
	window_template 0x00, 0x0e, 0x02, 0x0f, 0x10, 0x0f, 0x001e
	window_template 0x00, 0x00, 0x0d, 0x0e, 0x06, 0x0f, 0x010e
	window_template 0x01, 0x02, 0x0f, 0x1b, 0x04, 0x0f, 0x0162
	window_template 0x01, 0x18, 0x11, 0x05, 0x02, 0x0f, 0x01ce
	null_window_template

	.align 2
gUnknown_0861F350:: @ 861F350
	window_template 0x01, 0x16, 0x11, 0x07, 0x02, 0x0f, 0x01d8
	window_template 0x01, 0x16, 0x0f, 0x07, 0x04, 0x0f, 0x01d8
	window_template 0x01, 0x0f, 0x0f, 0x0e, 0x04, 0x0f, 0x01d8
	window_template 0x01, 0x0f, 0x0d, 0x0e, 0x06, 0x0f, 0x01d8

	.align 2
gUnknown_0861F370:: @ 861F370
	window_template 0x01, 0x18, 0x0f, 0x05, 0x04, 0x0f, 0x01d8

	.align 2
gOamData_861F378:: @ 861F378
	.2byte 0x0100, 0xc000, 0x0400, 0x0000

	.align 2
gSpriteAnim_861F380:: @ 861F380
	.2byte 0x0000, 0x0004, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_861F388:: @ 861F388
	.4byte gSpriteAnim_861F380

	.align 2
gSpriteAffineAnim_861F38C:: @ 861F38C
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnim_861F39C:: @ 861F39C
	.2byte 0x0000, 0x0000, 0x02fe, 0x0000, 0x0000, 0x0000, 0x0402, 0x0000, 0x0000, 0x0000, 0x04fe, 0x0000, 0x0000, 0x0000, 0x0202, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_861F3C4:: @ 861F3C4
	.4byte gSpriteAffineAnim_861F38C
	.4byte gSpriteAffineAnim_861F39C

	.align 2
gUnknown_0861F3CC:: @ 861F3CC
	obj_tiles gBattleFrontierGfx_PyramidBag, 0x0800, 0x1024

	.align 2
gUnknown_0861F3D4:: @ 861F3D4
	spr_template 0x1024, 0x1024, gOamData_861F378, gSpriteAnimTable_861F388, NULL, gSpriteAffineAnimTable_861F3C4, SpriteCallbackDummy

