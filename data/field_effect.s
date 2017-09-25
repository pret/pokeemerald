    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

	.align 2
gNewGameBirchPic:: @ 8553A90
	.incbin "graphics/birch_speech/birch.4bpp"

	.incbin "baserom.gba", 0x554290, 0x66c0

	.align 2
gNewGameBirchPalette:: @ 855A950
	.incbin "graphics/birch_speech/birch.gbapal"

	.align 2
	.incbin "baserom.gba", 0x55a970, 0x20

	.align 2
gFieldEffectObjectPalette4:: @ 855A990
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_04.gbapal"

	.incbin "baserom.gba", 0x55a9b0, 0x480

	.align 2
gFieldEffectObjectPalette5:: @ 855AE30
	.incbin "graphics/map_objects/palettes/field_effect_object_palette_05.gbapal"

gUnknown_0855AE50:: @ 855AE50
	.incbin "baserom.gba", 0x55ae50, 0x200

gUnknown_0855B050:: @ 855B050
	.incbin "baserom.gba", 0x55b050, 0x20

gUnknown_0855B070:: @ 855B070
	.incbin "baserom.gba", 0x55b070, 0x280

gUnknown_0855B2F0:: @ 855B2F0
	.incbin "baserom.gba", 0x55b2f0, 0x80

gUnknown_0855B370:: @ 855B370
	.incbin "baserom.gba", 0x55b370, 0x20

gUnknown_0855B390:: @ 855B390
	.incbin "baserom.gba", 0x55b390, 0x280

gUnknown_0855B610:: @ 855B610
	.incbin "baserom.gba", 0x55b610, 0x20

gUnknown_0855B630:: @ 855B630
	.incbin "baserom.gba", 0x55b630, 0xbc0

gUnknown_0855C1F0:: @ 855C1F0
	.incbin "baserom.gba", 0x55c1f0, 0x20

	.align 2
@ TODO: something else uses these too
gNewGameBirchOamAttributes:: @ 855C210
	.4byte OAM_SIZE_64x64
	.2byte 0

	.align 2
	.incbin "baserom.gba", 0x55c218, 0x10

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
	.2byte 0xFFFF @ tiles tag
	.2byte 0x1006 @ palette tag
	.4byte gNewGameBirchOamAttributes
	.4byte gNewGameBirchImageAnimTable
	.4byte gNewGameBirchPicTable
	.4byte gDummySpriteAffineAnimTable
	.4byte SpriteCallbackDummy

	.align 2
gFieldEffectObjectPaletteInfo4:: @ 855C25C
	obj_pal gFieldEffectObjectPalette4, 0x1007

	.align 2
gFieldEffectObjectPaletteInfo5:: @ 855C264
	obj_pal gFieldEffectObjectPalette5, 0x1010

	.incbin "baserom.gba", 0x55c26c, 0x40

gUnknown_0855C2AC:: @ 855C2AC
	.incbin "baserom.gba", 0x55c2ac, 0x18

gUnknown_0855C2C4:: @ 855C2C4
	.incbin "baserom.gba", 0x55c2c4, 0x40

gUnknown_0855C304:: @ 855C304
	.incbin "baserom.gba", 0x55c304, 0x18

gUnknown_0855C31C:: @ 855C31C
	.incbin "baserom.gba", 0x55c31c, 0x18

gUnknown_0855C334:: @ 855C334
	.incbin "baserom.gba", 0x55c334, 0x18

gUnknown_0855C34C:: @ 855C34C
	.incbin "baserom.gba", 0x55c34c, 0x18

gUnknown_0855C364:: @ 855C364
	.incbin "baserom.gba", 0x55c364, 0x10

gUnknown_0855C374:: @ 855C374
	.incbin "baserom.gba", 0x55c374, 0x10

gUnknown_0855C384:: @ 855C384
	.incbin "baserom.gba", 0x55c384, 0x20

gUnknown_0855C3A4:: @ 855C3A4
	.incbin "baserom.gba", 0x55c3a4, 0x18

gUnknown_0855C3BC:: @ 855C3BC
	.incbin "baserom.gba", 0x55c3bc, 0x4

gUnknown_0855C3C0:: @ 855C3C0
	.incbin "baserom.gba", 0x55c3c0, 0x4

gUnknown_0855C3C4:: @ 855C3C4
	.incbin "baserom.gba", 0x55c3c4, 0x4

gUnknown_0855C3C8:: @ 855C3C8
	.incbin "baserom.gba", 0x55c3c8, 0x1c

gUnknown_0855C3E4:: @ 855C3E4
	.incbin "baserom.gba", 0x55c3e4, 0x18

gUnknown_0855C3FC:: @ 855C3FC
	.incbin "baserom.gba", 0x55c3fc, 0x1c

gUnknown_0855C418:: @ 855C418
	.incbin "baserom.gba", 0x55c418, 0x14

gUnknown_0855C42C:: @ 855C42C
	.incbin "baserom.gba", 0x55c42c, 0xc

gUnknown_0855C438:: @ 855C438
	.incbin "baserom.gba", 0x55c438, 0x18

gUnknown_0855C450:: @ 855C450
	.incbin "baserom.gba", 0x55c450, 0x10

gUnknown_0855C460:: @ 855C460
	.incbin "baserom.gba", 0x55c460, 0x14

gUnknown_0855C474:: @ 855C474
	.incbin "baserom.gba", 0x55c474, 0x8

gUnknown_0855C47C:: @ 855C47C
	.incbin "baserom.gba", 0x55c47c, 0x8

gUnknown_0855C484:: @ 855C484
	.incbin "baserom.gba", 0x55c484, 0x8

gUnknown_0855C48C:: @ 855C48C
	.incbin "baserom.gba", 0x55c48c, 0x10

gUnknown_0855C49C:: @ 855C49C
	.incbin "baserom.gba", 0x55c49c, 0xc

gUnknown_0855C4A8:: @ 855C4A8
	.incbin "baserom.gba", 0x55c4a8, 0x1c

gUnknown_0855C4C4:: @ 855C4C4
	.incbin "baserom.gba", 0x55c4c4, 0x1c

gUnknown_0855C4E0:: @ 855C4E0
	.incbin "baserom.gba", 0x55c4e0, 0x14

gUnknown_0855C4F4:: @ 855C4F4
	.incbin "baserom.gba", 0x55c4f4, 0x54

gUnknown_0855C548:: @ 855C548
	.incbin "baserom.gba", 0x55c548, 0x8

gUnknown_0855C550:: @ 855C550
	.incbin "baserom.gba", 0x55c550, 0x1c

gUnknown_0855C56C:: @ 855C56C
	.incbin "baserom.gba", 0x55c56c, 0x24

gUnknown_0855C590:: @ 855C590
	.incbin "baserom.gba", 0x55c590, 0x5c

gUnknown_0855C5EC:: @ 855C5EC
	.incbin "baserom.gba", 0x55c5ec, 0x18
