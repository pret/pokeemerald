
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
sPhase2_Rayquaza_Funcs:: @ 85C8D60
	.4byte Phase2_WeatherTrio_Func1
	.4byte Phase2_WaitPaletteFade
	.4byte sub_81492B4
	.4byte sub_8149358
	.4byte sub_8149388
	.4byte sub_81493D8
	.4byte sub_8149410
	.4byte sub_814943C
	.4byte sub_814946C
	.4byte Phase2_Blackhole1_Func2
	.4byte Phase2_Blackhole1_Func3

	.align 2
gUnknown_085C8D8C:: @ 85C8D8C
	.4byte sub_81495B0
	.4byte sub_8149628
	.4byte sub_814969C
	.4byte sub_81496D8
	.4byte sub_8149740

	.align 1
sUnknown_085C8DA0:: @ 85C8DA0
	.2byte 0x0000, 0x0014, 0x000f, 0x0028, 0x000a, 0x0019, 0x0023, 0x0005

	.align 2
sUnknown_085C8DB0:: @ 85C8DB0
	.4byte sub_8149994
	.4byte sub_81499E8
	.4byte sub_8149A40

	.align 2
sPhase2_Shards_Funcs:: @ 85C8DBC
	.4byte sub_8149AA4
	.4byte sub_8149B08
	.4byte sub_8149B84
	.4byte sub_8149C60
	.4byte sub_8149CCC

	.align 1
sUnknown_085C8DD0:: @ 85C8DD0
	.2byte 0x0038, 0x0000, 0x0000, 0x00a0, 0x0000, 0x0068, 0x00a0, 0x00f0, 0x0058, 0x0001, 0x00f0, 0x0048, 0x0038, 0x0000, 0x0001, 0x0000
	.2byte 0x0020, 0x0090, 0x00a0, 0x0000, 0x0090, 0x00a0, 0x00b8, 0x0000, 0x0001, 0x0038, 0x0000, 0x00a8, 0x00a0, 0x0000, 0x00a8, 0x00a0
	.2byte 0x0030, 0x0000, 0x0001

	.align 1
sUnknown_085C8E16:: @ 85C8E16
	.2byte 0x0008, 0x0004, 0x0002, 0x0001, 0x0001, 0x0001, 0x0000

	.align 2
sPhase1_TransitionAll_Funcs:: @ 85C8E24
	.4byte sub_8149E34
	.4byte sub_8149E90

	.align 2
sSpriteImageTable_85C8E2C:: @ 85C8E2C
	obj_frame_tiles sSpriteImage_85B98F0, 0x0200

	.align 2
sSpriteAnim_85C8E34:: @ 85C8E34
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
sSpriteAnimTable_85C8E3C:: @ 85C8E3C
	.4byte sSpriteAnim_85C8E34

	.align 2
sSpriteAffineAnim_85C8E40:: @ 85C8E40
	obj_rot_scal_anim_frame 0, 0, -4, 1
	obj_rot_scal_anim_jump 0

	.align 2
sSpriteAffineAnim_85C8E50:: @ 85C8E50
	obj_rot_scal_anim_frame 0, 0, 4, 1
	obj_rot_scal_anim_jump 0

	.align 2
sSpriteAffineAnimTable_85C8E60:: @ 85C8E60
	.4byte sSpriteAffineAnim_85C8E40
	.4byte sSpriteAffineAnim_85C8E50

	.align 2
gUnknown_085C8E68:: @ 85C8E68
	spr_template 0xffff, 0x1009, gFieldObjectBaseOam_32x32, sSpriteAnimTable_85C8E3C, sSpriteImageTable_85C8E2C, sSpriteAffineAnimTable_85C8E60, sub_814713C

	.align 2
gOamData_85C8E80:: @ 85C8E80
	.2byte 0x0000, 0xc000, 0x0000, 0x0000

	.align 2
sSpriteImageTable_85C8E88:: @ 85C8E88
	obj_frame_tiles sSpriteImage_85B9CD0, 0x0800

	.align 2
sSpriteImageTable_85C8E90:: @ 85C8E90
	obj_frame_tiles sSpriteImage_85BA4D0, 0x0800

	.align 2
sSpriteAnim_85C8E98:: @ 85C8E98
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
sSpriteAnimTable_85C8EA0:: @ 85C8EA0
	.4byte sSpriteAnim_85C8E98

	.align 2
sSpriteTemplate_85C8EA4:: @ 85C8EA4
	spr_template 0xffff, 0x100a, gOamData_85C8E80, sSpriteAnimTable_85C8EA0, sSpriteImageTable_85C8E88, gDummySpriteAffineAnimTable, sub_8148380

	.align 2
sSpriteTemplate_85C8EBC:: @ 85C8EBC
	spr_template 0xffff, 0x100a, gOamData_85C8E80, sSpriteAnimTable_85C8EA0, sSpriteImageTable_85C8E90, gDummySpriteAffineAnimTable, sub_8148380

	.align 2
gFieldEffectObjectPalette10:: @ 85C8ED4
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_10.gbapal"

	.align 2
gFieldEffectObjectPaletteInfo10:: @ 85C8EF4
	obj_pal gFieldEffectObjectPalette10, 0x1009

	.align 2
sMugshotPal_Sidney:: @ 85C8EFC
	.incbin "graphics/battle_transitions/sidney_bg.gbapal"

	.align 2
sMugshotPal_Phoebe:: @ 85C8F1C
	.incbin "graphics/battle_transitions/phoebe_bg.gbapal"

	.align 2
sMugshotPal_Glacia:: @ 85C8F3C
	.incbin "graphics/battle_transitions/glacia_bg.gbapal"

	.align 2
sMugshotPal_Drake:: @ 85C8F5C
	.incbin "graphics/battle_transitions/drake_bg.gbapal"

	.align 2
sMugshotPal_Wallace:: @ 85C8F7C
	.incbin "graphics/battle_transitions/wallace_bg.gbapal"

	.align 2
sMugshotPal_Brendan:: @ 85C8F9C
	.incbin "graphics/battle_transitions/brendan_bg.gbapal"

	.align 2
sMugshotPal_May:: @ 85C8EFC
	.incbin "graphics/battle_transitions/may_bg.gbapal"

	.align 2
sOpponentMugshotsPals:: @ 85C8FDC
	.4byte sMugshotPal_Sidney
	.4byte sMugshotPal_Phoebe
	.4byte sMugshotPal_Glacia
	.4byte sMugshotPal_Drake
	.4byte sMugshotPal_Wallace

	.align 2
sPlayerMugshotsPals:: @ 85C8FF0
	.4byte sMugshotPal_Brendan
	.4byte sMugshotPal_May

	.align 2
sUnusedTrainerPalette:: @ 85C8EF8
	.incbin "graphics/battle_transitions/unused_trainer.gbapal"

	.align 2
sSpritePalette_UnusedTrainer:: @ 85C8EFC
	obj_pal sUnusedTrainerPalette, 0x100A

	.align 2
sBigPokeball_Tilemap:: @ 85C9020
	.incbin "graphics/battle_transitions/big_pokeball_map.bin"

	.align 2
sMugshotsTilemap:: @ 85C94D0
	.incbin "graphics/battle_transitions/elite_four_bg_map.bin"

	.align 2
gUnknown_085C99D0:: @ 85C99D0
	.4byte sub_814A324
	.4byte sub_814A374
	.4byte Phase2_BigPokeball_Func3
	.4byte Phase2_BigPokeball_Func4
	.4byte Phase2_BigPokeball_Func5
	.4byte Phase2_BigPokeball_Func6

	.align 2
gUnknown_085C99E8:: @ 85C99E8
	.4byte sub_814A42C
	.4byte sub_814A4D4
	.4byte sub_814A500
	.4byte sub_814A550

	.align 2
gUnknown_085C99F8:: @ 85C99F8
	.4byte sub_814A798
	.4byte sub_814A828
	.4byte sub_814A898
	.4byte sub_814ABA0

	.align 2
gUnknown_085C9A08:: @ 85C9A08
	.4byte sub_814A960
	.4byte sub_814AA04
	.4byte sub_814AA84
	.4byte sub_814AAB8
	.4byte sub_814ABA0

	.align 2
gUnknown_085C9A1C:: @ 85C9A1C
	.4byte sub_814AC38
	.4byte sub_814AD48
	.4byte sub_814ADB4
	.4byte sub_814ADD8
	.4byte sub_814AE40

gUnknown_085C9A30:: @ 85C9A30
	.byte 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x1b, 0x14, 0x0d, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 0x07, 0x0e, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x13, 0x0c, 0x0b, 0x0a, 0x09, 0x08, 0x0f
	.byte 0x10, 0x11, 0x12

gUnknown_085C9A53:: @ 85C9A53
	.byte 0x00, 0x10, 0x29, 0x16, 0x2c, 0x02, 0x2b, 0x15, 0x2e, 0x1b, 0x09, 0x30, 0x26, 0x05, 0x39, 0x3b, 0x0c, 0x3f, 0x23, 0x1c, 0x0a, 0x35, 0x07, 0x31, 0x27, 0x17, 0x37, 0x01, 0x3e, 0x11, 0x3d, 0x1e
	.byte 0x06, 0x22, 0x0f, 0x33, 0x20, 0x3a, 0x0d, 0x2d, 0x25, 0x34, 0x0b, 0x18, 0x3c, 0x13, 0x38, 0x21, 0x1d, 0x32, 0x28, 0x36, 0x0e, 0x03, 0x2f, 0x14, 0x12, 0x19, 0x04, 0x24, 0x1a, 0x2a, 0x1f, 0x08
	.byte 0x00

