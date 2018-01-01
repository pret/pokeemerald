
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
sPhase2_Transition_Blur_Funcs:: @ 85C8AA8
	.4byte sub_8146144
	.4byte sub_8146178
	.4byte sub_81461D8

	.align 2
sPhase2_Transition_Swirl_Funcs:: @ 85C8AB4
	.4byte sub_814623C
	.4byte sub_81462A8

	.align 2
sPhase2_Transition_Shuffle_Funcs:: @ 85C8ABC
	.4byte sub_81463BC
	.4byte sub_8146420

	.align 2
gUnknown_085C8AC4:: @ 85C8AC4
	.4byte sub_814670C
	.4byte sub_81468E4
	.4byte sub_8146BF8
	.4byte sub_8146C8C
	.4byte sub_8146D20
	.4byte sub_8146D90
	.4byte sub_8146DF8

	.align 2
gUnknown_085C8AE0:: @ 85C8AE0
	.4byte sub_8146760
	.4byte sub_814692C
	.4byte sub_8146BF8
	.4byte sub_8146C8C
	.4byte sub_8146D20
	.4byte sub_8146D90
	.4byte sub_8146DF8

	.align 2
gUnknown_085C8AFC:: @ 85C8AFC
	.4byte sub_8146800
	.4byte sub_8146854
	.4byte sub_8146BF8
	.4byte sub_8146C8C
	.4byte sub_8146D20
	.4byte sub_8146DF8

	.align 2
gUnknown_085C8B14:: @ 85C8B14
	.4byte sub_81467B4
	.4byte sub_8146974
	.4byte sub_8146BF8
	.4byte sub_8146C8C
	.4byte sub_8146D20
	.4byte sub_8146DF8

	.align 2
gUnknown_085C8B2C:: @ 85C8B2C
	.4byte sub_81467B4
	.4byte sub_81469CC
	.4byte sub_8146BF8
	.4byte sub_8146C8C
	.4byte sub_8146D20
	.4byte sub_8146DF8

	.align 2
gUnknown_085C8B44:: @ 85C8B44
	.4byte sub_81467B4
	.4byte sub_8146A24
	.4byte sub_8146BF8
	.4byte sub_8146C8C
	.4byte sub_8146D20
	.4byte sub_8146DF8

	.align 2
gUnknown_085C8B5C:: @ 85C8B5C
	.4byte sub_8146DAC
	.4byte sub_8146DD8
	.4byte sub_8146A7C
	.4byte sub_8146AC8
	.4byte sub_8146B24
	.4byte sub_8146D90
	.4byte sub_8146B7C
	.4byte sub_8146BA8

	.align 2
sPhase2_Transition_PokeballsTrail_Funcs:: @ 85C8B7C
	.4byte sub_8146FCC
	.4byte sub_8147018
	.4byte sub_81470A4

	.align 1
sUnknown_085C8B88:: @ 85C8B88
	.2byte 0xfff0, 0x0100

	.align 1
sUnknown_085C8B8C:: @ 85C8B8C
	.2byte 0x0000, 0x0020, 0x0040, 0x0012, 0x0030

	.align 1
sUnknown_085C8B96:: @ 85C8B96
	.2byte 0x0008, 0xfff8, 0x0000

	.align 2
sPhase2_Transition_Clockwise_BlackFade_Funcs:: @ 85C8B9C
	.4byte sub_814723C
	.4byte sub_81472A4
	.4byte sub_8147334
	.4byte sub_8147428
	.4byte sub_81474B0
	.4byte sub_81475B0
	.4byte sub_8147648

	.align 2
sPhase2_Transition_Ripple_Funcs:: @ 85C8BB8
	.4byte sub_8147750
	.4byte sub_81477A8

	.align 2
sPhase2_Transition_Wave_Funcs:: @ 85C8BC0
	.4byte sub_8147924
	.4byte sub_814797C
	.4byte sub_8147A18

	.align 2
sPhase2_Mugshot_Transition_Funcs:: @ 85C8BCC
	.4byte sub_8147BBC
	.4byte sub_8147C24
	.4byte sub_8147CE4
	.4byte sub_8147DD0
	.4byte sub_8147E4C
	.4byte sub_8147E88
	.4byte sub_8147F40
	.4byte sub_8148008
	.4byte sub_8148040
	.4byte sub_814808C

sMugshotsTrainerPicIDsTable:: @ 85C8BF4
	.byte 0x24, 0x25, 0x26, 0x27, 0x36, 0x00

	.align 1
sMugshotsOpponentRotationScales:: @ 85C8BFA
	.2byte 0x0200, 0x0200, 0x0200, 0x0200, 0x01b0, 0x01b0, 0x01a0, 0x01a0, 0x0188, 0x0188

	.align 1
sMugshotsOpponentCoords:: @ 85C8C0E
	.2byte 0x0000, 0x0000, 0x0000, 0x0000, 0xfffc, 0x0004, 0x0000, 0x0005, 0xfff8, 0x0007, 0x0000

	.align 2
sUnknown_085C8C24:: @ 85C8C24
	.4byte sub_81483A8
	.4byte sub_81483AC
	.4byte sub_81483F8
	.4byte sub_814842C
	.4byte sub_81483A8
	.4byte sub_8148458
	.4byte sub_81483A8

	.align 1
sUnknown_085C8C40:: @ 85C8C40
	.2byte 0x000c, 0xfff4

	.align 1
sUnknown_085C8C44:: @ 85C8C44
	.2byte 0xffff, 0x0001

	.align 2
gUnknown_085C8C48:: @ 85C8C48
	.4byte sub_8148508
	.4byte sub_8148590
	.4byte sub_814865C

	.align 2
gUnknown_085C8C54:: @ 85C8C54
	.4byte sub_8148798
	.4byte sub_8148864
	.4byte sub_8148AD4
	.4byte sub_8148B14

	.align 1
gUnknown_085C8C64:: @ 85C8C64
	.2byte 0x7727

	.align 1
gUnknown_085C8C66:: @ 85C8C66
	.2byte 0x0001, 0xffff, 0x0000

	.align 2
gUnknown_085C8C6C:: @ 85C8C6C
	.4byte sub_8148BC4
	.4byte sub_8148CE8
	.4byte sub_8148C28

	.align 2
gUnknown_085C8C78:: @ 85C8C78
	.4byte sub_8148BC4
	.4byte sub_8148D6C

	.align 1
gUnknown_085C8C80:: @ 85C8C80
	.2byte 0xfffa, 0x0004

	.align 2
gUnknown_085C8C84:: @ 85C8C84
	.4byte sub_8148E8C
	.4byte sub_8148F4C
	.4byte sub_8149008

gUnknown_085C8C90:: @ 85C8C90
	.2byte 0x0001, 0x001b, 0x0113, 0xffff

gUnknown_085C8C98:: @ 85C8C98
	.2byte 0x0002, 0x01e6, 0xffff

gUnknown_085C8C9E:: @ 85C8C9E
	.2byte 0x0003, 0x0106, 0xffff

gUnknown_085C8CA4:: @ 85C8CA4
	.2byte 0x0004, 0x01fb, 0xfffe

gUnknown_085C8CAA:: @ 85C8CAA
	.2byte 0x0001, 0x00d5, 0xffff

gUnknown_085C8CB0:: @ 85C8CB0
	.2byte 0x0002, 0x0224, 0xfffe

gUnknown_085C8CB6:: @ 85C8CB6
	.2byte 0x0003, 0x00c4, 0xffff

gUnknown_085C8CBC:: @ 85C8CBC
	.2byte 0x0004, 0x023d, 0x0135, 0xffff

gUnknown_085C8CC4:: @ 85C8CC4
	.2byte 0x0001, 0x01da, 0xffff

gUnknown_085C8CCA:: @ 85C8CCA
	.2byte 0x0002, 0x0127, 0x0020, 0xffff

gUnknown_085C8CD2:: @ 85C8CD2
	.2byte 0x0003, 0x003a, 0xffff

gUnknown_085C8CD8:: @ 85C8CD8
	.2byte 0x0004, 0x01c7, 0xffff

gUnknown_085C8CDE:: @ 85C8CDE
	.2byte 0x0001, 0x021c, 0xffff

gUnknown_085C8CE4:: @ 85C8CE4
	.2byte 0x0002, 0x00e5, 0xffff

gUnknown_085C8CEA:: @ 85C8CEA
	.2byte 0x0003, 0x00f4, 0x001c, 0xffff

gUnknown_085C8CF2:: @ 85C8CF2
	.2byte 0x0004, 0x0205, 0xffff

	.align 2
gUnknown_085C8CF8:: @ 85C8CF8
	.4byte gUnknown_085C8C90
	.4byte gUnknown_085C8CA4
	.4byte gUnknown_085C8C98
	.4byte gUnknown_085C8C9E
	.4byte gUnknown_085C8CEA
	.4byte gUnknown_085C8CE4
	.4byte gUnknown_085C8CF2
	.4byte gUnknown_085C8CDE

	.align 2
gUnknown_085C8D18:: @ 85C8D18
	.4byte gUnknown_085C8CBC
	.4byte gUnknown_085C8CB0
	.4byte gUnknown_085C8CB6
	.4byte gUnknown_085C8CAA
	.4byte gUnknown_085C8CCA
	.4byte gUnknown_085C8CD8
	.4byte gUnknown_085C8CC4
	.4byte gUnknown_085C8CD2

	.align 2
gUnknown_085C8D38:: @ 85C8D38
	.4byte gUnknown_085C8CF8
	.4byte gUnknown_085C8D18

	.align 2
gUnknown_085C8D40:: @ 85C8D40
	.4byte sub_8146DAC
	.4byte sub_8146DD8
	.4byte sub_8149178
	.4byte sub_81491C8
	.4byte sub_8149224
	.4byte sub_8146D90
	.4byte sub_8146B7C
	.4byte sub_8146BA8

	.align 2
gUnknown_085C8D60:: @ 85C8D60
	.4byte sub_8146DAC
	.4byte sub_8146DD8
	.4byte sub_81492B4
	.4byte sub_8149358
	.4byte sub_8149388
	.4byte sub_81493D8
	.4byte sub_8149410
	.4byte sub_814943C
	.4byte sub_814946C
	.4byte sub_8148CE8
	.4byte sub_8148C28

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
sPhase2_Transition_Shards_Funcs:: @ 85C8DBC
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
	.4byte sub_8146BF8
	.4byte sub_8146C8C
	.4byte sub_8146D20
	.4byte sub_8146DF8

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

