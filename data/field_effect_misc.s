	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    .align 2
gSpriteImage_858D978:: @ 858D978
    .incbin "graphics/unknown/858E588/0.4bpp"

    .align 2
gSpriteImage_858D9F8:: @ 858D9F8
    .incbin "graphics/unknown/858E588/1.4bpp"

    .align 2
gSpriteImage_858DA78:: @ 858DA78
    .incbin "graphics/unknown/858E588/2.4bpp"

    .align 2
gSpriteImage_858DAF8:: @ 858DAF8
    .incbin "graphics/unknown/858E588/3.4bpp"

    .align 2
gSpriteImage_858DB78:: @ 858DB78
    .incbin "graphics/unknown/858E588/4.4bpp"

	.space 32

	.align 2
gFieldEffectObjectPalette7:: @ 858DC18
	.incbin "graphics/event_objects/palettes/field_effect_object_palette_07.gbapal"

    .align 2
gSpriteImage_858DC38:: @ 858DC38
    .incbin "graphics/unknown/858E5D8/0.4bpp"

    .align 2
gSpriteImage_858DCB8:: @ 858DCB8
    .incbin "graphics/unknown/858E5D8/1.4bpp"

    .align 2
gSpriteImage_858DD38:: @ 858DD38
    .incbin "graphics/unknown/858E5D8/2.4bpp"

    .align 2
gSpriteImage_858DDB8:: @ 858DDB8
    .incbin "graphics/unknown/858E5D8/3.4bpp"

    .align 2
gSpriteImage_858DE38:: @ 858DE38
    .incbin "graphics/unknown/858E5D8/4.4bpp"

    .align 2
gSpriteImage_858DEB8:: @ 858DEB8
    .incbin "graphics/unknown/858E5B0/0.4bpp"

    .align 2
gSpriteImage_858DF38:: @ 858DF38
    .incbin "graphics/unknown/858E5B0/1.4bpp"

    .align 2
gSpriteImage_858DFB8:: @ 858DFB8
    .incbin "graphics/unknown/858E5B0/2.4bpp"

    .align 2
gSpriteImage_858E038:: @ 858E038
    .incbin "graphics/unknown/858E5B0/3.4bpp"

    .align 2
gSpriteImage_858E0B8:: @ 858E0B8
    .incbin "graphics/unknown/858E5B0/4.4bpp"

    .align 2
gSpriteImage_858E138:: @ 858E138
    .incbin "graphics/unknown/858E5B0/5.4bpp"

	.align 2
gFieldEffectObjectPalette8:: @ 858E1B8
	.incbin "graphics/event_objects/palettes/field_effect_object_palette_08.gbapal"

    .align 2
gSpriteImage_858E1D8:: @ 858E1D8
    .incbin "graphics/unknown/858E674/0.4bpp"

    .align 2
gSpriteImage_858E2D8:: @ 858E2D8
    .incbin "graphics/unknown/858E674/1.4bpp"

    .align 2
gSpriteImage_858E3D8:: @ 858E3D8
    .incbin "graphics/unknown/858E674/2.4bpp"

	.align 2
gOamData_858E4D8:: @ 858E4D8
	.2byte 0x0000, 0x4000, 0x0800, 0x0000

	.align 2
gSpriteAnim_858E4E0:: @ 858E4E0
	.2byte 0x0000, 0x0008, 0x0001, 0x0008, 0x0002, 0x0008, 0x0003, 0x0008, 0x0004, 0x0008, 0xffff, 0x0000

	.align 2
gSpriteAnim_858E4F8:: @ 858E4F8
	.2byte 0x0000, 0x0008, 0x0001, 0x0008, 0x0002, 0x0008, 0x0003, 0x0008, 0x0004, 0x0008, 0xffff, 0x0000

	.align 2
gSpriteAnim_858E510:: @ 858E510
	.2byte 0x0004, 0x0008, 0x0003, 0x0008, 0x0002, 0x0008, 0x0001, 0x0008, 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gSpriteAnim_858E528:: @ 858E528
	.2byte 0x0000, 0x0048, 0x0001, 0x0048, 0x0002, 0x0048, 0x0003, 0x0048, 0x0004, 0x0048, 0xffff, 0x0000

	.align 2
gSpriteAnim_858E540:: @ 858E540
	.2byte 0x0004, 0x0048, 0x0003, 0x0048, 0x0002, 0x0048, 0x0001, 0x0048, 0x0000, 0x0048, 0xffff, 0x0000

	.align 2
gSpriteAnim_858E558:: @ 858E558
	.2byte 0x0000, 0x0008, 0x0001, 0x0008, 0x0002, 0x0008, 0x0003, 0x0008, 0x0004, 0x0008, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_858E570:: @ 858E570
	.4byte gSpriteAnim_858E4E0

	.align 2
gSpriteAnimTable_858E574:: @ 858E574
	.4byte gSpriteAnim_858E4F8
	.4byte gSpriteAnim_858E510
	.4byte gSpriteAnim_858E528
	.4byte gSpriteAnim_858E540

	.align 2
gSpriteAnimTable_858E584:: @ 858E584
	.4byte gSpriteAnim_858E558

	.align 2
gUnknown_858E588:: @ 858E588
	obj_frame_tiles gSpriteImage_858D978, 0x0080
	obj_frame_tiles gSpriteImage_858D9F8, 0x0080
	obj_frame_tiles gSpriteImage_858DA78, 0x0080
	obj_frame_tiles gSpriteImage_858DAF8, 0x0080
	obj_frame_tiles gSpriteImage_858DB78, 0x0080

	.align 2
gUnknown_858E5B0:: @ 858E5B0
	obj_frame_tiles gSpriteImage_858DEB8, 0x0080
	obj_frame_tiles gSpriteImage_858DF38, 0x0080
	obj_frame_tiles gSpriteImage_858DFB8, 0x0080
	obj_frame_tiles gSpriteImage_858E038, 0x0080
	obj_frame_tiles gSpriteImage_858E0B8, 0x0080

	.align 2
gUnknown_858E5D8:: @ 858E5D8
	obj_frame_tiles gSpriteImage_858DC38, 0x0080
	obj_frame_tiles gSpriteImage_858DCB8, 0x0080
	obj_frame_tiles gSpriteImage_858DD38, 0x0080
	obj_frame_tiles gSpriteImage_858DDB8, 0x0080
	obj_frame_tiles gSpriteImage_858DE38, 0x0080

	.align 2
gUnknown_0858E600:: @ 858E600
	spr_template 0xffff, 0x1003, gOamData_858E4D8, gSpriteAnimTable_858E570, gUnknown_858E588, gDummySpriteAffineAnimTable, sub_80FA18C

	.align 2
gUnknown_0858E618:: @ 858E618
	spr_template 0xffff, 0x1008, gOamData_858E4D8, gSpriteAnimTable_858E574, gUnknown_858E5B0, gDummySpriteAffineAnimTable, sub_80FA2D8

	.align 2
gUnknown_0858E630:: @ 858E630
	spr_template 0xffff, 0x1008, gOamData_858E4D8, gSpriteAnimTable_858E584, gUnknown_858E5D8, gDummySpriteAffineAnimTable, sub_80FA3FC

	.align 2
gFieldEffectObjectPaletteInfo7:: @ 858E648
	obj_pal gFieldEffectObjectPalette7, 0x1003

	.align 2
gFieldEffectObjectPaletteInfo8:: @ 858E650
	obj_pal gFieldEffectObjectPalette8, 0x1008

	.align 2
gOamData_858E658:: @ 858E658
	.2byte 0x8000, 0x8000, 0x0800, 0x0000

	.align 2
gSpriteAnim_858E660:: @ 858E660
	.2byte 0x0000, 0x0006, 0x0001, 0x0006, 0x0002, 0x0006, 0xffff, 0x0000

	.align 2
gSpriteAnimTable_858E670:: @ 858E670
	.4byte gSpriteAnim_858E660

	.align 2
gUnknown_0858E674:: @ 858E674
	obj_frame_tiles gSpriteImage_858E1D8, 0x0100
	obj_frame_tiles gSpriteImage_858E2D8, 0x0100
	obj_frame_tiles gSpriteImage_858E3D8, 0x0100

	.align 2
gUnknown_0858E68C:: @ 858E68C
	spr_template 0xffff, 0x100e, gOamData_858E658, gSpriteAnimTable_858E670, gUnknown_0858E674, gDummySpriteAffineAnimTable, door_restore_tilemap

	.align 2
@ This uses one of the secret base palettes, so there is no
@ "field_effect_object_palette_09.pal" file.
gFieldEffectObjectPaletteInfo9:: @ 858E6A4
	obj_pal gTilesetPalettes_SecretBase + 5 * 0x20, 0x100E

    .align 2
gSpriteImage_858E6AC:: @ 858E6AC
    .incbin "graphics/unknown/858E84C/0.4bpp"

    .align 2
gSpriteImage_858E72C:: @ 858E72C
    .incbin "graphics/unknown/858E84C/1.4bpp"

    .align 2
gSpriteImage_858E7AC:: @ 858E7AC
    .incbin "graphics/unknown/858E84C/2.4bpp"

    .align 2
gUnknown_0858E82C:: @ 858E82C
    .incbin "graphics/unknown/unknown_58E82C.gbapal"

    .align 2
gUnknown_0858E84C:: @ 858E84C
	obj_frame_tiles gSpriteImage_858E6AC, 0x0080
	obj_frame_tiles gSpriteImage_858E72C, 0x0080
	obj_frame_tiles gSpriteImage_858E7AC, 0x0080

    .align 2
gUnknown_0858E864:: @ 858E864
	obj_pal gUnknown_0858E82C, 0x1000

    .align 2
gSpriteAnim_858E86C:: @ 858E86C
	.2byte 0x0000, 0x001e, 0x0001, 0x001e, 0x0002, 0x001e, 0xfffe, 0x0000

    .align 2
gSpriteAnimTable_858E87C:: @ 858E87C
	.4byte gSpriteAnim_858E86C

    .align 2
gUnknown_0858E880:: @ 858E880
	spr_template 0xffff, 0x1000, gEventObjectBaseOam_32x8, gSpriteAnimTable_858E87C, gUnknown_0858E84C, gDummySpriteAffineAnimTable, SpriteCallbackDummy

