    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

	.align 2
gNewGameBirchPic:: @ 8553A90
	.incbin "graphics/birch_speech/birch.4bpp"

	.space 0x3800

	.incbin "graphics/unused/intro_birch_beauty.4bpp"

	.align 2
gNewGameBirchPalette:: @ 855A950
	.incbin "graphics/birch_speech/birch.gbapal"

	.align 2
gSpriteImage_855A970:: @ 855A970
	.incbin "graphics/misc/pokeball_glow.4bpp"

	.align 2
gFieldEffectObjectPalette4:: @ 855A990
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_04.gbapal"

	.align 2
gSpriteImage_855A9B0:: @ 855A9B0
	.incbin "graphics/misc/pokecenter_monitor/0.4bpp"

	.align 2
gSpriteImage_855AA70:: @ 855AA70
	.incbin "graphics/misc/pokecenter_monitor/1.4bpp"

	.align 2
gSpriteImage_855AB30:: @ 855AB30
	.incbin "graphics/misc/big_hof_monitor.4bpp"

	.align 2
gSpriteImage_855AD30:: @ 855AD30
	.incbin "graphics/misc/small_hof_monitor.4bpp"

	.align 2
gFieldEffectObjectPalette5:: @ 855AE30
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_05.gbapal"

	.align 2
gUnknown_0855AE50:: @ 855AE50
	.incbin "graphics/misc/field_move_streaks.4bpp"

	.align 2
gUnknown_0855B050:: @ 855B050
	.incbin "graphics/misc/field_move_streaks.gbapal"

	.align 2
gUnknown_0855B070:: @ 855B070
	.incbin "graphics/misc/field_move_streaks_map.bin"

	.align 2
gUnknown_0855B2F0:: @ 855B2F0
	.incbin "graphics/misc/darkness_field_move_streaks.4bpp"

	.align 2
gUnknown_0855B370:: @ 855B370
	.incbin "graphics/misc/darkness_field_move_streaks.gbapal"

	.align 2
gUnknown_0855B390:: @ 855B390
	.incbin "graphics/misc/darkness_field_move_streaks_map.bin"

	.align 2
gUnknown_0855B610:: @ 855B610
	.incbin "graphics/misc/spotlight.gbapal"

	.align 2
gUnknown_0855B630:: @ 855B630
	.incbin "graphics/misc/spotlight.4bpp"

	.align 2
gUnknown_0855C170:: @ 855C170
	.incbin "graphics/unknown/unknown_55C170.4bpp"

	.align 2
gUnknown_0855C1F0:: @ 855C1F0
	.4byte FieldEffectCmd_loadtiles
	.4byte FieldEffectCmd_loadfadedpal
	.4byte FieldEffectCmd_loadpal
	.4byte FieldEffectCmd_callnative
	.4byte FieldEffectCmd_end
	.4byte FieldEffectCmd_loadgfx_callnative
	.4byte FieldEffectCmd_loadtiles_callnative
	.4byte FieldEffectCmd_loadfadedpal_callnative

	.align 2
@ TODO: something else uses these too
gNewGameBirchOamAttributes:: @ 855C210
	.4byte OAM_SIZE_64x64
	.2byte 0

	.align 2
gOamData_855C218:: @ 855C218
	.2byte 0x0000, 0x0000, 0x0000, 0x0000

	.align 2
gOamData_855C220:: @ 855C220
	.2byte 0x0000, 0x4000, 0x0000, 0x0000

	.align 2
gNewGameBirchPicTable:: @ 855C228
	obj_tiles gNewGameBirchPic, 0x800

	.align 2
gNewGameBirchObjectPaletteInfo:: @ 855C230
	obj_pal gNewGameBirchPalette, 0x1006

	.align 2
gNewGameBirchImageAnim:: @ 855C238
	obj_image_anim_frame 0, 1
	obj_image_anim_end

	.align 2
gNewGameBirchImageAnimTable:: @ 855C240
	.4byte gNewGameBirchImageAnim

	.align 2
gNewGameBirchObjectTemplate:: @ 855C244
	spr_template 0xFFFF, 0x1006, gNewGameBirchOamAttributes, gNewGameBirchImageAnimTable, gNewGameBirchPicTable, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gFieldEffectObjectPaletteInfo4:: @ 855C25C
	obj_pal gFieldEffectObjectPalette4, 0x1007

	.align 2
gFieldEffectObjectPaletteInfo5:: @ 855C264
	obj_pal gFieldEffectObjectPalette5, 0x1010

	.align 2
gOamData_855C26C:: @ 855C26C
	.2byte 0x4000, 0x8000, 0x0000, 0x0000

	.align 2
gUnknown_855C274:: @ 855C274
	obj_frame_tiles gSpriteImage_855A970, 0x0020

	.align 2
gUnknown_855C27C:: @ 855C27C
	obj_frame_tiles gSpriteImage_855A9B0, 0x00c0
	obj_frame_tiles gSpriteImage_855AA70, 0x00c0

	.align 2
gUnknown_855C28C:: @ 855C28C
	obj_frame_tiles gSpriteImage_855AB30, 0x0200

	.align 2
gUnknown_855C294:: @ 855C294
	obj_frame_tiles gSpriteImage_855AD30, 0x0200

	.align 2
gSubspriteTable_855C29C:: @ 855C29C
	subsprite -12, -8, 2,  0, 16x8
	subsprite   4, -8, 2,  2, 8x8
	subsprite -12,  0, 2,  3, 16x8
	subsprite   4,  0, 2,  5, 8x8

	.align 2
gUnknown_0855C2AC:: @ 855C2AC
	.4byte 4, gSubspriteTable_855C29C

	.align 2
gSubspriteTable_855C2B4:: @ 855C2B4
	subsprite -32, -8, 2,  0, 32x8
	subsprite   0, -8, 2,  4, 32x8
	subsprite -32,  0, 2,  8, 32x8
	subsprite   0,  0, 2, 12, 32x8

	.align 2
gUnknown_0855C2C4:: @ 855C2C4
	.4byte 4, gSubspriteTable_855C2B4

	.align 2
gUnknown_0855C2CC:: @ 855C2CC
	.2byte 0x0000, 0x0001, 0xfffe, 0x0000

	.align 2
gUnknown_0855C2D4:: @ 855C2D4
	.2byte 0x0000, 0x0010, 0x0001, 0x0010, 0x0000, 0x0010, 0x0001, 0x0010, 0x0000, 0x0010, 0x0001, 0x0010, 0x0000, 0x0010, 0x0001, 0x0010
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_0855C2F8:: @ 855C2F8
	.4byte gUnknown_0855C2CC
	.4byte gUnknown_0855C2D4

	.align 2
gUnknown_0855C300:: @ 855C300
	.4byte gUnknown_0855C2CC

	.align 2
gUnknown_0855C304:: @ 855C304
	spr_template 0xffff, 0x1007, gOamData_855C218, gUnknown_0855C2F8, gUnknown_855C274, gDummySpriteAffineAnimTable, sub_80B6828

	.align 2
gUnknown_0855C31C:: @ 855C31C
	spr_template 0xffff, 0x1004, gOamData_855C220, gUnknown_0855C2F8, gUnknown_855C27C, gDummySpriteAffineAnimTable, sub_80B68AC

	.align 2
gUnknown_0855C334:: @ 855C334
	spr_template 0xffff, 0x1010, gOamData_855C220, gUnknown_0855C300, gUnknown_855C28C, gDummySpriteAffineAnimTable, sub_80B6970

	.align 2
gUnknown_0855C34C:: @ 855C34C
	spr_template 0xffff, 0x1010, gOamData_855C26C, gUnknown_0855C300, gUnknown_855C294, gDummySpriteAffineAnimTable, sub_80B6970

	.align 2
gUnknown_0855C364:: @ 855C364
	.4byte sub_80B6214
	.4byte sub_80B6250
	.4byte sub_80B628C
	.4byte sub_80B62B4

	.align 2
gUnknown_0855C374:: @ 855C374
	.4byte sub_80B6360
	.4byte sub_80B63D4
	.4byte sub_80B6404
	.4byte sub_80B642C

	.align 2
gUnknown_0855C384:: @ 855C384
	.4byte sub_80B64DC
	.4byte sub_80B6574
	.4byte sub_80B65A8
	.4byte sub_80B66E8
	.4byte sub_80B67DC
	.4byte sub_80B67F8
	.4byte sub_80B6800
	.4byte nullsub_97

	.align 1
gUnknown_0855C3A4:: @ 855C3A4
	.2byte 0x0000, 0x0000, 0x0006, 0x0000, 0x0000, 0x0004, 0x0006, 0x0004, 0x0000, 0x0008, 0x0006, 0x0008

gUnknown_0855C3BC:: @ 855C3BC
	.byte 0x10, 0x0c, 0x08, 0x00

gUnknown_0855C3C0:: @ 855C3C0
	.byte 0x10, 0x0c, 0x08, 0x00

gUnknown_0855C3C4:: @ 855C3C4
	.byte 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_0855C3C8:: @ 855C3C8
	.4byte sub_80B6BCC
	.4byte sub_80B6C74
	.4byte sub_80B6C90
	.4byte sub_80B6D04
	.4byte sub_80B6DBC
	.4byte sub_80B6DD8
	.4byte sub_80B6E18

	.align 2
gUnknown_0855C3E4:: @ 855C3E4
	.4byte sub_80B6EC0
	.4byte sub_80B6EE0
	.4byte sub_80B6F50
	.4byte sub_80B6F74
	.4byte sub_80B6F84
	.4byte sub_80B6FA8

	.align 2
gUnknown_0855C3FC:: @ 855C3FC
	.4byte sub_80B7114
	.4byte sub_80B7190
	.4byte sub_80B71D0
	.4byte sub_80B7230
	.4byte sub_80B7270
	.4byte sub_80B72D0
	.4byte sub_80B72F4

	.align 2
gUnknown_0855C418:: @ 855C418
	.4byte sub_80B73D0
	.4byte waterfall_1_do_anim_probably
	.4byte waterfall_2_wait_anim_finish_probably
	.4byte sub_80B7450
	.4byte sub_80B7478

	.align 2
gUnknown_0855C42C:: @ 855C42C
	.4byte dive_1_lock
	.4byte dive_2_unknown
	.4byte dive_3_unknown

	.align 2
gUnknown_0855C438:: @ 855C438
	.4byte sub_80B764C
	.4byte sub_80B7684
	.4byte sub_80B76B8
	.4byte sub_80B7704
	.4byte sub_80B77F8
	.4byte sub_80B7814

	.align 2
gUnknown_0855C450:: @ 855C450
	.4byte sub_80B78EC
	.4byte sub_80B791C
	.4byte sub_80B7968
	.4byte sub_80B79BC

	.align 2
gUnknown_0855C460:: @ 855C460
	.4byte sub_80B7AE8
	.4byte sub_80B7B18
	.4byte sub_80B7B94
	.4byte sub_80B7BCC
	.4byte sub_80B7BF4

	.align 2
gUnknown_0855C474:: @ 855C474
	.4byte sub_80B7D14
	.4byte sub_80B7D34

gUnknown_0855C47C:: @ 855C47C
	.byte 0x01, 0x03, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00

	.align 2
gUnknown_0855C484:: @ 855C484
	.4byte sub_80B7EC4
	.4byte sub_80B7EE8

	.align 2
gUnknown_0855C48C:: @ 855C48C
	.4byte sub_80B800C
	.4byte sub_80B8034
	.4byte sub_80B80C4
	.4byte sub_80B8198

	.align 2
gUnknown_0855C49C:: @ 855C49C
	.4byte sub_80B8280
	.4byte sub_80B830C
	.4byte sub_80B8410

	.align 2
gUnknown_0855C4A8:: @ 855C4A8
	.4byte sub_80B8584
	.4byte sub_80B85F8
	.4byte sub_80B8660
	.4byte sub_80B86EC
	.4byte sub_80B871C
	.4byte sub_80B8770
	.4byte overworld_bg_setup_2

	.align 2
gUnknown_0855C4C4:: @ 855C4C4
	.4byte sub_80B88E4
	.4byte sub_80B8920
	.4byte sub_80B898C
	.4byte sub_80B89DC
	.4byte sub_80B8A0C
	.4byte sub_80B8A44
	.4byte sub_80B8A64

	.align 2
gUnknown_0855C4E0:: @ 855C4E0
	.4byte sub_80B8DB4
	.4byte sub_80B8E14
	.4byte sub_80B8E60
	.4byte sub_80B8EA8
	.4byte sub_80B8F24

	.align 2
gUnknown_0855C4F4:: @ 855C4F4
	.4byte sub_80B9204
	.4byte sub_80B925C
	.4byte sub_80B92A0
	.4byte sub_80B92F8
	.4byte sub_80B933C
	.4byte sub_80B9390
	.4byte sub_80B9418
	.4byte sub_80B9474
	.4byte sub_80B9494

	.align 2
gUnknown_0855C518:: @ 855C518
	.2byte 0x0008, 0x0008, 0x00e2, 0x0000, 0x001c, 0x001c, 0x1e00, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0855C530:: @ 855C530
	.2byte 0x0100, 0x0100, 0x0040, 0x0000, 0xfff6, 0xfff6, 0x1600, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_0855C548:: @ 855C548
	.4byte gUnknown_0855C518
	.4byte gUnknown_0855C530

	.align 2
gUnknown_0855C550:: @ 855C550
	.4byte sub_80B9804
	.4byte sub_80B98B8
	.4byte sub_80B9924
	.4byte sub_80B9978
	.4byte sub_80B99F0
	.4byte sub_80B9A28
	.4byte sub_80B9A60

gUnknown_0855C56C:: @ 855C56C
	.byte 0xfe, 0xff, 0xfc, 0xff, 0xfb, 0xff, 0xfa, 0xff, 0xf9, 0xff, 0xf8, 0xff, 0xf8, 0xff, 0xf8, 0xff, 0xf9, 0xff, 0xf9, 0xff, 0xfa, 0xff, 0xfb, 0xff, 0xfd, 0xff, 0xfe, 0xff, 0x00, 0x00, 0x02, 0x00
	.byte 0x04, 0x00, 0x08, 0x00

	.align 2
gUnknown_0855C590:: @ 855C590
	.4byte sub_80B9C28
	.4byte sub_80B9C54
	.4byte sub_80B9CDC

	.align 2
gUnknown_0855C59C:: @ 855C59C
	obj_frame_tiles gUnknown_0855C170, 0x0020
	obj_frame_tiles gUnknown_0855C170 + 0x20, 0x0020
	obj_frame_tiles gUnknown_0855C170 + 0x40, 0x0020
	obj_frame_tiles gUnknown_0855C170 + 0x60, 0x0020

	.align 2
gUnknown_0855C5BC:: @ 855C5BC
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_0855C5C4:: @ 855C5C4
	.2byte 0x0001, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_0855C5CC:: @ 855C5CC
	.2byte 0x0002, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_0855C5D4:: @ 855C5D4
	.2byte 0x0003, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_0855C5DC:: @ 855C5DC
	.4byte gUnknown_0855C5BC
	.4byte gUnknown_0855C5C4
	.4byte gUnknown_0855C5CC
	.4byte gUnknown_0855C5D4

	.align 2
gUnknown_0855C5EC:: @ 855C5EC
	spr_template 0xffff, 0x111a, gOamData_855C218, gUnknown_0855C5DC, gUnknown_0855C59C, gDummySpriteAffineAnimTable, sub_80B9DB8

