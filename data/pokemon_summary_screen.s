	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 86181C1
	.include "data/text/move_descriptions.inc"

@ 861CAAC
	.include "data/text/nature_names.inc"

	.align 2
gUnknown_0861CBB4:: @ 861CBB4
	.4byte 0x000001f0, 0x000013b9, 0x0000239a, 0x000033db

	.align 2
gUnknown_0861CBC4:: @ 861CBC4
	.incbin "graphics/interface/unk_tilemap2.bin"

	.align 2
gUnknown_0861CBEC:: @ 861CBEC
	.4byte gUnknown_0861CBC4
	.byte 0x01, 0x00, 0x0a, 0x02, 0x00, 0x12

	.align 2
gUnknown_0861CBF8:: @ 861CBF8
	.4byte gUnknown_0861CBC4
	.byte 0x01, 0x00, 0x0a, 0x02, 0x00, 0x32

	.align 2
gUnknown_0861CC04:: @ 861CC04
	.4byte gSummaryScreenPowAcc_Tilemap
	.byte 0x00
	.byte 0x00
	.byte 0x0A
	.byte 0x07
	.byte 0x00
	.byte 0x2D

	.align 2
gUnknown_0861CC10:: @ 861CC10
	.4byte gUnknown_08DC3C34
	.byte 0x00
	.byte 0x00
	.byte 0x0A
	.byte 0x07
	.byte 0x00
	.byte 0x2D

	.align 2
gUnknown_0861CC1C:: @ 861CC1C
	.byte 0x00, 0x02, 0x03, 0x01, 0x04, 0x05, 0x00, 0x00

	.align 2
gUnknown_0861CC24:: @ 861CC24
	window_template 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x0001
	window_template 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x0017
	window_template 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x002d
	window_template 0x00, 0x00, 0x00, 0x0b, 0x02, 0x06, 0x0043
	window_template 0x00, 0x16, 0x00, 0x08, 0x02, 0x07, 0x0059
	window_template 0x00, 0x16, 0x00, 0x08, 0x02, 0x07, 0x0069
	window_template 0x00, 0x16, 0x00, 0x08, 0x02, 0x07, 0x0079
	window_template 0x00, 0x0b, 0x04, 0x00, 0x02, 0x06, 0x0089
	window_template 0x00, 0x0b, 0x04, 0x12, 0x02, 0x06, 0x0089
	window_template 0x00, 0x0b, 0x06, 0x12, 0x02, 0x06, 0x00ad
	window_template 0x00, 0x0a, 0x07, 0x06, 0x06, 0x06, 0x00d1
	window_template 0x00, 0x16, 0x07, 0x05, 0x06, 0x06, 0x00f5
	window_template 0x00, 0x0a, 0x0e, 0x0b, 0x04, 0x06, 0x0113
	window_template 0x00, 0x00, 0x12, 0x06, 0x02, 0x06, 0x013f
	window_template 0x00, 0x01, 0x0f, 0x09, 0x04, 0x06, 0x014b
	window_template 0x00, 0x01, 0x0f, 0x05, 0x04, 0x06, 0x016f
	window_template 0x00, 0x16, 0x04, 0x00, 0x02, 0x06, 0x0183
	window_template 0x00, 0x01, 0x02, 0x04, 0x02, 0x07, 0x0183
	window_template 0x00, 0x01, 0x0c, 0x09, 0x02, 0x06, 0x018b
	window_template 0x00, 0x01, 0x0e, 0x09, 0x04, 0x06, 0x019d
	null_window_template

	.align 2
gUnknown_0861CCCC:: @ 861CCCC
	window_template 0x00, 0x0b, 0x04, 0x0b, 0x02, 0x06, 0x01c1
	window_template 0x00, 0x16, 0x04, 0x07, 0x02, 0x06, 0x01d7
	window_template 0x00, 0x0b, 0x09, 0x12, 0x04, 0x06, 0x01e5
	window_template 0x00, 0x0b, 0x0e, 0x12, 0x06, 0x06, 0x022d

	.align 2
gUnknown_0861CCEC:: @ 861CCEC
	window_template 0x00, 0x0a, 0x04, 0x0a, 0x02, 0x06, 0x01c1
	window_template 0x00, 0x14, 0x04, 0x0a, 0x02, 0x06, 0x01d5
	window_template 0x00, 0x10, 0x07, 0x06, 0x06, 0x06, 0x01e9
	window_template 0x00, 0x1b, 0x07, 0x03, 0x06, 0x06, 0x020d
	window_template 0x00, 0x18, 0x0e, 0x06, 0x04, 0x06, 0x021f

	.align 2
gUnknown_0861CD14:: @ 861CD14
	window_template 0x00, 0x0f, 0x04, 0x09, 0x0a, 0x06, 0x01c1
	window_template 0x00, 0x18, 0x04, 0x06, 0x0a, 0x08, 0x021b
	window_template 0x00, 0x0a, 0x0f, 0x14, 0x04, 0x06, 0x0257

gUnknown_0861CD2C:: @ 861CD2C
	.byte 0x00, 0x01, 0x02, 0x00, 0x03, 0x04, 0x00, 0x05, 0x06, 0x00, 0x07, 0x08, 0x00, 0x09, 0x0a, 0x00, 0x0b, 0x0c, 0x00, 0x0d, 0x0e, 0x00, 0x07, 0x08, 0x0d, 0x0f, 0x0e, 0x00, 0x01, 0x02, 0x00, 0x03
	.byte 0x04, 0x00, 0x05, 0x06, 0x00, 0x07, 0x08

gUnknown_0861CD53:: @ 861CD53
	.incbin "graphics/interface/summary_a_button.4bpp"

gUnknown_0861CDD3:: @ 861CDD3
	.incbin "graphics/interface/summary_b_button.4bpp"

	.align 2
gUnknown_0861CE54:: @ 861CE54
	.4byte sub_81C2E00
	.4byte sub_81C3530
	.4byte sub_81C3984
	.4byte sub_81C3D08

	.align 2
gUnknown_0861CE64:: @ 861CE64
	.4byte sub_81C2E40
	.4byte sub_81C3554
	.4byte sub_81C39F0
	.4byte sub_81C3D54

gUnknown_0861CE74:: @ 861CE74
	.string "{COLOR LIGHT_RED}{SHADOW GREEN}$"

gUnknown_0861CE7B:: @ 861CE7B
	.string "{COLOR WHITE}{SHADOW DARK_GREY}$"

gUnknown_0861CE82:: @ 861CE82
	.string "{SPECIAL_F7 0x00}/{SPECIAL_F7 0x01}\n"
	.string "{SPECIAL_F7 0x02}\n"
	.string "{SPECIAL_F7 0x03}$"

gUnknown_0861CE8E:: @ 861CE8E
	.string "{SPECIAL_F7 0x00}\n"
	.string "{SPECIAL_F7 0x01}\n"
	.string "{SPECIAL_F7 0x02}$"

gUnknown_0861CE97:: @ 861CE97
	.string "{UNK_CTRL_F9 0x06}{SPECIAL_F7 0x00}/{SPECIAL_F7 0x01}$"

	.align 2
gOamData_861CEA0:: @ 861CEA0
	.2byte 0x4000, 0x8000, 0x0400, 0x0000

	.align 2
gSpriteAnim_861CEA8:: @ 861CEA8
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEB0:: @ 861CEB0
	.2byte 0x0008, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEB8:: @ 861CEB8
	.2byte 0x0010, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEC0:: @ 861CEC0
	.2byte 0x0018, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEC8:: @ 861CEC8
	.2byte 0x0020, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CED0:: @ 861CED0
	.2byte 0x0028, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CED8:: @ 861CED8
	.2byte 0x0030, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEE0:: @ 861CEE0
	.2byte 0x0038, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEE8:: @ 861CEE8
	.2byte 0x0040, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEF0:: @ 861CEF0
	.2byte 0x0048, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CEF8:: @ 861CEF8
	.2byte 0x0050, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF00:: @ 861CF00
	.2byte 0x0058, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF08:: @ 861CF08
	.2byte 0x0060, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF10:: @ 861CF10
	.2byte 0x0068, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF18:: @ 861CF18
	.2byte 0x0070, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF20:: @ 861CF20
	.2byte 0x0078, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF28:: @ 861CF28
	.2byte 0x0080, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF30:: @ 861CF30
	.2byte 0x0088, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF38:: @ 861CF38
	.2byte 0x0090, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF40:: @ 861CF40
	.2byte 0x0098, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF48:: @ 861CF48
	.2byte 0x00a0, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF50:: @ 861CF50
	.2byte 0x00a8, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861CF58:: @ 861CF58
	.2byte 0x00b0, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_861CF60:: @ 861CF60
	.4byte gSpriteAnim_861CEA8
	.4byte gSpriteAnim_861CEB0
	.4byte gSpriteAnim_861CEB8
	.4byte gSpriteAnim_861CEC0
	.4byte gSpriteAnim_861CEC8
	.4byte gSpriteAnim_861CED0
	.4byte gSpriteAnim_861CED8
	.4byte gSpriteAnim_861CEE0
	.4byte gSpriteAnim_861CEE8
	.4byte gSpriteAnim_861CEF0
	.4byte gSpriteAnim_861CEF8
	.4byte gSpriteAnim_861CF00
	.4byte gSpriteAnim_861CF08
	.4byte gSpriteAnim_861CF10
	.4byte gSpriteAnim_861CF18
	.4byte gSpriteAnim_861CF20
	.4byte gSpriteAnim_861CF28
	.4byte gSpriteAnim_861CF30
	.4byte gSpriteAnim_861CF38
	.4byte gSpriteAnim_861CF40
	.4byte gSpriteAnim_861CF48
	.4byte gSpriteAnim_861CF50
	.4byte gSpriteAnim_861CF58

	.align 2
gUnknown_0861CFBC:: @ 861CFBC
	obj_tiles gMoveTypes_Gfx, 0x1700, 0x7532

	.align 2
gUnknown_0861CFC4:: @ 861CFC4
	spr_template 0x7532, 0x7532, gOamData_861CEA0, gSpriteAnimTable_861CF60, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_0861CFDC:: @ 861CFDC
	.byte 0x0d, 0x0d, 0x0e, 0x0e, 0x0d, 0x0d, 0x0f, 0x0e, 0x0d, 0x0f, 0x0d, 0x0e, 0x0f, 0x0d, 0x0e, 0x0e, 0x0f, 0x0d, 0x0d, 0x0e, 0x0e, 0x0f, 0x0d, 0x00

	.align 2
gOamData_861CFF4:: @ 861CFF4
	.2byte 0x0000, 0x4000, 0x0400, 0x0000

	.align 2
gSpriteAnim_861CFFC:: @ 861CFFC
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D004:: @ 861D004
	.2byte 0x0004, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D00C:: @ 861D00C
	.2byte 0x0008, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D014:: @ 861D014
	.2byte 0x000c, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D01C:: @ 861D01C
	.2byte 0x0010, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D024:: @ 861D024
	.2byte 0x0010, 0x0040, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D02C:: @ 861D02C
	.2byte 0x0014, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D034:: @ 861D034
	.2byte 0x0018, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D03C:: @ 861D03C
	.2byte 0x0018, 0x0040, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D044:: @ 861D044
	.2byte 0x001c, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_861D04C:: @ 861D04C
	.4byte gSpriteAnim_861CFFC
	.4byte gSpriteAnim_861D004
	.4byte gSpriteAnim_861D00C
	.4byte gSpriteAnim_861D014
	.4byte gSpriteAnim_861D01C
	.4byte gSpriteAnim_861D024
	.4byte gSpriteAnim_861D02C
	.4byte gSpriteAnim_861D034
	.4byte gSpriteAnim_861D03C
	.4byte gSpriteAnim_861D044

	.align 2
gUnknown_0861D074:: @ 861D074
	obj_tiles gUnknown_08D97BEC, 0x0400, 0x7530

	.align 2
gUnknown_0861D07C:: @ 861D07C
	obj_pal gUnknown_08D97CF4, 0x7530

	.align 2
gUnknown_0861D084:: @ 861D084
	spr_template 0x7530, 0x7530, gOamData_861CFF4, gSpriteAnimTable_861D04C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gOamData_861D09C:: @ 861D09C
	.2byte 0x4000, 0x4000, 0x0c00, 0x0000

	.align 2
gSpriteAnim_861D0A4:: @ 861D0A4
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D0AC:: @ 861D0AC
	.2byte 0x0004, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D0B4:: @ 861D0B4
	.2byte 0x0008, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D0BC:: @ 861D0BC
	.2byte 0x000c, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D0C4:: @ 861D0C4
	.2byte 0x0010, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D0CC:: @ 861D0CC
	.2byte 0x0014, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_861D0D4:: @ 861D0D4
	.2byte 0x0018, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_861D0DC:: @ 861D0DC
	.4byte gSpriteAnim_861D0A4
	.4byte gSpriteAnim_861D0AC
	.4byte gSpriteAnim_861D0B4
	.4byte gSpriteAnim_861D0BC
	.4byte gSpriteAnim_861D0C4
	.4byte gSpriteAnim_861D0CC
	.4byte gSpriteAnim_861D0D4

	.align 2
gUnknown_0861D0F8:: @ 861D0F8
	obj_tiles gStatusGfx_Icons, 0x0380, 0x7531

	.align 2
gUnknown_0861D100:: @ 861D100
	obj_pal gStatusPal_Icons, 0x7531

	.align 2
gUnknown_0861D108:: @ 861D108
	spr_template 0x7531, 0x7531, gOamData_861D09C, gSpriteAnimTable_861D0DC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_0861D120:: @ 861D120
	.incbin "graphics/interface/summary_markings.gbapal"

	.align 2
gUnknown_0861D140:: @ 861D140
	.incbin "graphics/interface/region_map.gbapal"

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

