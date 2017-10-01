	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_085F06E0:: @ 85F06E0
	.incbin "graphics/intro/intro2_grass.gbapal"

	.align 2
gUnknown_085F0700:: @ 85F0700
	.incbin "graphics/intro/intro2_grass_afternoon.gbapal"

	.align 2
gUnknown_085F0720:: @ 85F0720
	.incbin "graphics/intro/intro2_grass_night.gbapal"

	.align 2
gUnknown_085F0740:: @ 85F0740
	.incbin "graphics/intro/intro2_grass.4bpp.lz"

	.align 2
gUnknown_085F0BC0:: @ 85F0BC0
	.incbin "graphics/intro/intro2_grass_map.bin.lz"

	.align 2
gUnknown_085F0CFC:: @ 85F0CFC
	.incbin "graphics/intro/85F0CFC.gbapal"

	.align 2
gUnknown_085F0D5C:: @ 85F0D5C
	.incbin "graphics/intro/85F0D5C.gbapal"

	.align 2
gUnknown_085F0DBC:: @ 85F0DBC
	.incbin "graphics/intro/intro2_bgclouds.4bpp.lz"

	.align 2
gUnknown_085F1398:: @ 85F1398
	.incbin "graphics/intro/intro2_bgclouds_map.bin.lz"

	.align 2
gUnknown_085F1668:: @ 85F1668
	.incbin "graphics/intro/intro2_bgclouds.gbapal"

	.align 2
gUnknown_085F1688:: @ 85F1688
	.incbin "graphics/intro/intro2_bgclouds_afternoon.gbapal"

	.align 2
gUnknown_085F16A8:: @ 85F16A8
	.incbin "graphics/intro/intro2_bgclouds2.4bpp.lz"

	.align 2
gUnknown_085F17E4:: @ 85F17E4
	.incbin "graphics/intro/intro2_bgtrees2.gbapal"

	.align 2
gUnknown_085F1804:: @ 85F1804
	.incbin "graphics/intro/intro2_bgtrees2_afternoon.gbapal"

	.align 2
gUnknown_085F1824:: @ 85F1824
	.incbin "graphics/intro/intro2_bgtrees.4bpp.lz"

	.align 2
gUnknown_085F1EAC:: @ 85F1EAC
	.incbin "graphics/intro/intro2_bgtrees_map.bin.lz"

	.align 2
gUnknown_085F21B0:: @ 85F21B0
	.incbin "graphics/intro/intro2_bgtrees.gbapal"

	.align 2
gIntro2TreeGfx:: @ 85F21D0
	.incbin "graphics/intro/intro2_bgtreessmall.4bpp.lz"

	.align 2
gUnknown_085F231C:: @ 85F231C
	.incbin "graphics/intro/85F231C.gbapal"

	.align 2
gUnknown_085F235C:: @ 85F235C
	.incbin "graphics/intro/intro2_bgnight.4bpp.lz"

	.align 2
gUnknown_085F2548:: @ 85F2548
	.incbin "graphics/intro/intro2_bgnight.gbapal"

	.align 2
gUnknown_085F2568:: @ 85F2568
	.incbin "graphics/intro/intro2_bgnight_map.bin.lz"

	.align 2
gIntro2NightGfx:: @ 85F2814
	.incbin "graphics/intro/intro2_night.4bpp.lz"

	.align 2
gIntro2BrendanPal:: @ 85F2898
	.incbin "graphics/intro/intro2_brendan.gbapal"

	.align 2
gIntro2BrendanGfx:: @ 85F28B8
	.incbin "graphics/intro/intro2_brendan.4bpp.lz"

	.align 2
gIntro2MayPal:: @ 85F3470
	.incbin "graphics/intro/intro2_may.gbapal"

	.align 2
gUnknown_085F3490:: @ 85F3490
	.space 0x1E0

	.align 2
gIntro2MayGfx:: @ 85F3670
	.incbin "graphics/intro/intro2_may.4bpp.lz"

	.align 2
gIntro2BicycleGfx:: @ 85F4318
	.incbin "graphics/intro/intro2_bicycle.4bpp.lz"

	.align 2
gIntro2LatiosPal:: @ 85F4744
	.incbin "graphics/intro/intro2_latios.gbapal"

	.align 2
gIntro2LatiosGfx:: @ 85F4764
	.incbin "graphics/intro/intro2_latios.4bpp.lz"

	.align 2
gIntro2LatiasPal:: @ 85F4C08
	.incbin "graphics/intro/intro2_latias.gbapal"

	.align 2
gIntro2LatiasGfx:: @ 85F4C28
	.incbin "graphics/intro/intro2_latias.4bpp.lz"

	.align 2
gUnknown_085F504C:: @ 85F504C
	spr_template 0x07d0, 0xffff, gDummyOamData, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_817B62C

	.align 2
gUnknown_085F5064:: @ 85F5064
	obj_tiles gUnknown_085F16A8, 0x0400, 0x07d0
	null_obj_tiles

	.align 2
gUnknown_085F5074:: @ 85F5074
	obj_image_anim_frame 0, 30
	obj_image_anim_end

	.align 2
gUnknown_085F507C:: @ 85F507C
	obj_image_anim_frame 16, 30
	obj_image_anim_end

	.align 2
gUnknown_085F5084:: @ 85F5084
	obj_image_anim_frame 20, 30
	obj_image_anim_end

	.align 2
gUnknown_085F508C:: @ 85F508C
	obj_image_anim_frame 22, 30
	obj_image_anim_end

	.align 2
gUnknown_085F5094:: @ 85F5094
	.4byte gUnknown_085F5074
	.4byte gUnknown_085F507C
	.4byte gUnknown_085F5084
	.4byte gUnknown_085F508C

	.align 2
gUnknown_085F50A4:: @ 85F50A4
	.byte -128, 72, 32, 100
	.2byte 0xC00
	.space 2
	.byte -128, -98, 32, 100
	.2byte 0xC00
	.space 2
	.byte 65, -64, 40, 101
	.2byte 0x800
	.space 2
	.byte 65, 56, 40, 101
	.2byte 0x800
	.space 2
	.byte 18, 100, 44, 102
	.2byte 0x400
	.space 2
	.byte 18, -104, 44, 102
	.2byte 0x400
	.space 2
	.byte 19, 8, 46, 103
	.2byte 0x100
	.space 2
	.byte 19, 56, 46, 103
	.2byte 0x100
	.space 2
	.byte 19, -16, 46, 103
	.2byte 0x100
	.space 2

	.align 2
gUnknown_085F50EC:: @ 85F50EC
	obj_tiles gIntro2TreeGfx, 0x0400, 0x07d0
	null_obj_tiles

	.align 2
gUnknown_085F50FC:: @ 85F50FC
	obj_image_anim_frame 0, 30
	obj_image_anim_end

	.align 2
gUnknown_085F5104:: @ 85F5104
	obj_image_anim_frame 16, 30
	obj_image_anim_end

	.align 2
gUnknown_085F510C:: @ 85F510C
	obj_image_anim_frame 24, 30
	obj_image_anim_end

	.align 2
gUnknown_085F5114:: @ 85F5114
	.4byte gUnknown_085F50FC
	.4byte gUnknown_085F5104
	.4byte gUnknown_085F510C

	.align 2
gUnknown_085F5120:: @ 85F5120
	.byte -128, 16, 88, 100
	.2byte 0x2000
	.space 2
	.byte -128, 80, 88, 100
	.2byte 0x2000
	.space 2
	.byte -128, -112, 88, 100
	.2byte 0x2000
	.space 2
	.byte -128, -48, 88, 100
	.2byte 0x2000
	.space 2
	.byte -95, 40, 88, 101
	.2byte 0x1000
	.space 2
	.byte -95, 104, 88, 101
	.2byte 0x1000
	.space 2
	.byte -95, -88, 88, 101
	.2byte 0x1000
	.space 2
	.byte -95, -24, 88, 101
	.2byte 0x1000
	.space 2
	.byte -94, 56, 88, 102
	.2byte 0x800
	.space 2
	.byte -94, 120, 88, 102
	.2byte 0x800
	.space 2
	.byte -94, -72, 88, 102
	.2byte 0x800
	.space 2
	.byte -94, -8, 88, 102
	.2byte 0x800
	.space 2

	.align 2
gUnknown_085F5180:: @ 85F5180
	obj_tiles gIntro2NightGfx, 0x0400, 0x07d0
	null_obj_tiles

	.align 2
gUnknown_085F5190:: @ 85F5190
	obj_image_anim_frame 0, 30
	obj_image_anim_end

	.align 2
gUnknown_085F5198:: @ 85F5198
	.4byte gUnknown_085F5190

	.align 2
gUnknown_085F519C:: @ 85F519C
	.byte -128, 24, 88, 100
	.2byte 0x1000
	.space 2
	.byte -128, 64, 88, 100
	.2byte 0x1000
	.space 2
	.byte -128, 104, 88, 100
	.2byte 0x1000
	.space 2
	.byte -128, -112, 88, 100
	.2byte 0x1000
	.space 2
	.byte -128, -72, 88, 100
	.2byte 0x1000
	.space 2
	.byte -128, -32, 88, 100
	.2byte 0x1000
	.space 2

	.align 2
gOamData_85F51CC:: @ 85F51CC
	.2byte 0x00A0
	.2byte 0xC000
	.2byte 0x0400

	.align 2
gUnknown_085F51D4:: @ 85F51D4
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 64, 8
	obj_image_anim_frame 128, 8
	obj_image_anim_frame 192, 8
	obj_image_anim_jump 0

	.align 2
gUnknown_085F51E8:: @ 85F51E8
	.4byte gUnknown_085F51D4

	.align 2
gUnknown_085F51EC:: @ 85F51EC
	spr_template 0x03ea, 0x03ea, gOamData_85F51CC, gUnknown_085F51E8, NULL, gDummySpriteAffineAnimTable, nullsub_65

	.align 2
gUnknown_085F5204:: @ 85F5204
	spr_template 0x03eb, 0x03eb, gOamData_85F51CC, gUnknown_085F51E8, NULL, gDummySpriteAffineAnimTable, nullsub_65

	.align 2
gUnknown_085F521C:: @ 85F521C
	.2byte 0x40A0
	.2byte 0xC000
	.2byte 0x0400

	.align 2
gUnknown_085F5224:: @ 85F5224
	obj_image_anim_frame 0, 8
	obj_image_anim_frame 32, 8
	obj_image_anim_frame 64, 8
	obj_image_anim_frame 96, 8
	obj_image_anim_jump 0

	.align 2
gUnknown_085F5238:: @ 85F5238
	.4byte gUnknown_085F5224

	.align 2
gUnknown_085F523C:: @ 85F523C
	spr_template 0x03e9, 0x03ea, gUnknown_085F521C, gUnknown_085F5238, NULL, gDummySpriteAffineAnimTable, sub_817B7C4

	.align 2
gUnknown_085F5254:: @ 85F5254
	spr_template 0x03e9, 0x03eb, gUnknown_085F521C, gUnknown_085F5238, NULL, gDummySpriteAffineAnimTable, sub_817B7C4

	.align 2
gUnknown_085F526C:: @ 85F526C
	.2byte 0x00A0
	.2byte 0xC000
	.2byte 0x0400

	.align 2
gUnknown_085F5274:: @ 85F5274
	obj_image_anim_frame 0, 16
	obj_image_anim_end

	.align 2
gUnknown_085F527C:: @ 85F527C
	obj_image_anim_frame 64, 16
	obj_image_anim_end

	.align 2
gUnknown_085F5284:: @ 85F5284
	.4byte gUnknown_085F5274
	.4byte gUnknown_085F527C

	.align 2
gUnknown_085F528C:: @ 85F528C
	spr_template 0x03ec, 0x03ec, gUnknown_085F526C, gUnknown_085F5284, NULL, gDummySpriteAffineAnimTable, nullsub_66

	.align 2
gUnknown_085F52A4:: @ 85F52A4
	spr_template 0x03ed, 0x03ed, gUnknown_085F526C, gUnknown_085F5284, NULL, gDummySpriteAffineAnimTable, nullsub_66

	.align 2
gUnknown_085F52BC:: @ 85F52BC
	obj_tiles gIntro2BrendanNoTurnGfx, 0x2000, 0x03ea
	null_obj_tiles

	.align 2
gUnknown_085F52CC:: @ 85F52CC
	obj_tiles gIntro2MayNoTurnGfx, 0x2000, 0x03eb
	null_obj_tiles

	.align 2
gUnknown_085F52DC:: @ 85F52DC
	obj_tiles gIntro2BicycleGfx, 0x1000, 0x03e9
	null_obj_tiles

	.align 2
gUnknown_085F52EC:: @ 85F52EC
	obj_tiles gIntro2FlygonGfx, 0x1000, 0x03ec
	null_obj_tiles

	.align 2
gUnknown_085F52FC:: @ 85F52FC
	obj_tiles gIntro2FlygonGfx, 0x1000, 0x03ed
	null_obj_tiles

	.align 2
gUnknown_085F530C:: @ 85F530C
	obj_pal gIntro2BrendanNoTurnPal, 0x03ea
	obj_pal gIntro2BrendanNoTurnPal, 0x03eb
	obj_pal gIntro2FlygonPal, 0x03ec
	obj_pal gIntro2FlygonPal, 0x03ed
	null_obj_pal

	.align 2
gUnknown_085F5334:: @ 85F5334
	obj_tiles gIntro2BrendanGfx, 0x3800, 0x03ea
	null_obj_tiles

	.align 2
gUnknown_085F5344:: @ 85F5344
	obj_tiles gIntro2MayGfx, 0x3800, 0x03eb
	null_obj_tiles

	.align 2
gUnknown_085F5354:: @ 85F5354
	obj_tiles gIntro2BicycleGfx, 0x1000, 0x03e9
	null_obj_tiles

	.align 2
gUnknown_085F5364:: @ 85F5364
	obj_tiles gIntro2LatiosGfx, 0x1000, 0x03ec
	null_obj_tiles

	.align 2
gUnknown_085F5374:: @ 85F5374
	obj_tiles gIntro2LatiasGfx, 0x1000, 0x03ed
	null_obj_pal

	.align 2
gUnknown_085F5384:: @ 85F5384
	obj_pal gIntro2BrendanPal, 0x03ea
	obj_pal gIntro2MayPal, 0x03eb
	obj_pal gIntro2LatiosPal, 0x03ec
	obj_pal gIntro2LatiasPal, 0x03ed
	null_obj_pal

	.align 2
gUnknown_085F53AC:: @ 85F53AC
	obj_tiles gIntro2BrendanGfx, 0x2000, 0x03ea
	null_obj_tiles

	.align 2
gUnknown_085F53BC:: @ 85F53BC
	obj_tiles gIntro2MayGfx, 0x2000, 0x03eb
	null_obj_tiles
