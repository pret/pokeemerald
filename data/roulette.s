
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 1
gUnknown_085B5BFC:: @ 85B5BFC
	.incbin "graphics/roulette/85B5BFC.gbapal"

	.align 2
gUnknown_085B5DFC:: @ 85B5DFC
	.incbin "graphics/roulette/85B5DFC.bin.lz"

	.align 2
gUnknown_085B5FA0:: @ 85B5FA0
	.incbin "graphics/roulette/wheel_map.bin.lz"

	.align 2
gUnknown_085B6140:: @ 85B6140
	.4byte 0x000001f8, 0x00001241, 0x00002a66

	.align 2
gUnknown_085B614C:: @ 85B614C
	window_template 0x00, 0x03, 0x0f, 0x18, 0x04, 0x0f, 0x00c5

	.align 2
gUnknown_085B6154:: @ 85B6154
	.byte 0xFF, 0x00, 0x00, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x0C, 0x14, 0x00, 0x11, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x42, 0x08, 0x01, 0x00, 0x00, 0xE0, 0x00, 0x00
	.byte 0x0D, 0x24, 0x00, 0x14, 0x07, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x84, 0x10, 0x02, 0x00, 0x00, 0xE0, 0x00, 0x00
	.byte 0x0E, 0x34, 0x00, 0x17, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x21, 0x04, 0x00, 0x00, 0xE0, 0x00, 0x00
	.byte 0x0F, 0x44, 0x00, 0x1A, 0x07, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x42, 0x08, 0x00, 0x00, 0xE0, 0x00, 0x00
	.byte 0x10, 0x03, 0x01, 0x0E, 0x0A, 0x00, 0x0C, 0x00, 0x20, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x49, 0x02, 0x00, 0x00
	.byte 0x00, 0x1C, 0x01, 0x11, 0x0A, 0x03, 0x03, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x01, 0x20, 0x00, 0x00
	.byte 0x09, 0x2C, 0x01, 0x14, 0x0A, 0x03, 0x03, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00
	.byte 0x06, 0x3C, 0x01, 0x17, 0x0A, 0x03, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x20, 0x00, 0x00
	.byte 0x03, 0x4C, 0x01, 0x1A, 0x0A, 0x03, 0x03, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00
	.byte 0x11, 0x03, 0x02, 0x0E, 0x0D, 0x03, 0x0F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x92, 0x04, 0x00, 0x00
	.byte 0x04, 0x1C, 0x02, 0x11, 0x0D, 0x06, 0x06, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x20, 0x00, 0x00
	.byte 0x01, 0x2C, 0x02, 0x14, 0x0D, 0x06, 0x06, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00
	.byte 0x0A, 0x3C, 0x02, 0x17, 0x0D, 0x06, 0x06, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00
	.byte 0x07, 0x4C, 0x02, 0x1A, 0x0D, 0x06, 0x06, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x80, 0x20, 0x00, 0x00
	.byte 0x12, 0x03, 0x03, 0x0E, 0x10, 0x06, 0x12, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 0x24, 0x09, 0x00, 0x00
	.byte 0x08, 0x1C, 0x03, 0x11, 0x10, 0x09, 0x09, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x21, 0x00, 0x00
	.byte 0x05, 0x2C, 0x03, 0x14, 0x10, 0x09, 0x09, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x20, 0x00, 0x00
	.byte 0x02, 0x3C, 0x03, 0x17, 0x10, 0x09, 0x09, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x20, 0x00, 0x00
	.byte 0x0B, 0x4C, 0x03, 0x1A, 0x10, 0x09, 0x09, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x28, 0x00, 0x00

	.align 2
gUnknown_085B62E4:: @ 85B62E4
	.byte    0,   1,   6,   0,  64,   0,   0,   0
	.byte    1,   3,  12,   0,   0,  16,   0,   0
	.byte    2,   5,  18,   0,   0,   0,   4,   0
	.byte    3,   7,   9,   0,   0,   2,   0,   0
	.byte    4,   9,  11,   0,   0,   8,   0,   0
	.byte    5,  11,  17,   0,   0,   0,   2,   0
	.byte    6,  13,   8,   0,   0,   1,   0,   0
	.byte    7,  15,  14,   0,   0,  64,   0,   0
	.byte    8,  17,  16,   0,   0,   0,   1,   0
	.byte    9,  19,   7,   0, 128,   0,   0,   0
	.byte   10,  21,  13,   0,   0,  32,   0,   0
	.byte   11,  23,  19,   0,   0,   0,   8,   0

gUnknown_085B6344:: @ 85B6344
	.byte 1, 3
	.byte 1, 6

	.align 2
gUnknown_085B6348:: @ 85B6348
	.byte 0x01, 0x3C, 0x1E, 0x01, 0x01, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x00, 0x00, 0x4B, 0x00, 0x1B, 0x00, 0x18, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x68, 0x01, 0x00, 0x00, 0x00, 0xBF
	.byte 0x03, 0x1E, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x4B, 0x00, 0x3C, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x30, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x0E, 0x01, 0x00, 0x00, 0x80, 0xBF

	.align 2
gUnknown_085B6388:: @ 85B6388
	.byte 0x00, 0x80, 0x05, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x0A, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x15, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x55, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x5A, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x65, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x75, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x7A, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x85, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x95, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0x9A, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0x00, 0x80, 0xA5, 0x00, 0x01, 0x01, 0xFF, 0x48
	.byte 0xD6, 0x77, 0x28, 0x00, 0x02, 0x0A, 0xFF, 0x4E

	.align 1
gUnknown_085B63F0:: @ 85B63F0
	.2byte 0x53FF
	.2byte 0x0101
	.2byte 0x1E05
	.2byte 0x4EFF
	.2byte 0x7FFB
	.2byte 0x0106
	.2byte 0x1E05
	.2byte 0x4EFF
	.2byte 0x7F7F
	.2byte 0x010B
	.2byte 0x1E05
	.2byte 0x4EFF

	.align 2
gUnknown_085B6408:: @ 85B6408
	.4byte sub_8142918
	.4byte sub_814297C

	.align 2
gUnknown_085B6410:: @ 85B6410
	.4byte sub_8140968
	.4byte sub_8140994

	.align 1
gUnknown_085B6418:: @ 85B6418
	.2byte 0x2898
	.2byte 0x1A6A
	.2byte 0x2898

gUnknown_085B641E:: @ 85B641E
	.byte 0xFB, 0x05, 0xFF, 0x01

	.align 1
gUnknown_085B6422:: @ 85B6422
	.2byte  0, 180
	.2byte 90, 270

	.align 2
gUnknown_085B642C:: @ 85B642C
	.4byte 0x10842
	.4byte 0x21084
	.4byte 0x42108
	.4byte 0x84210

	.align 2
gUnknown_085B643C:: @ 85B643C
	.4byte   0x3E0
	.4byte  0x7C00
	.4byte 0xF8000

gUnknown_085B6448:: @ 85B6448
	.byte 0, 3, 4, 6, 12

	.align 2
RouletteSpritePalette_01: @ 85B6450
	.incbin "graphics/roulette/shadow.gbapal"

	.align 2
RouletteSpritePalette_02: @ 85B6470
	.incbin "graphics/roulette/ball.gbapal"

	.align 2
RouletteSpritePalette_03: @ 85B6490
	.incbin "graphics/roulette/ball_counter.gbapal"

	.align 2
RouletteSpritePalette_04: @ 85B64B0
	.incbin "graphics/roulette/cursor.gbapal"

	.align 2
RouletteSpritePalette_05: @ 85B64D0
	.incbin "graphics/roulette/credit.gbapal"

	.align 2
RouletteSpritePalette_06: @ 85B64F0
	.incbin "graphics/roulette/shroomish.gbapal"

	.align 2
RouletteSpritePalette_07: @ 85B6510
	.incbin "graphics/roulette/tailow.gbapal"

	.align 2
RouletteSpritePalette_08: @ 85B6530
	.incbin "graphics/roulette/poke_icons.gbapal"

	.align 2
RouletteSpritePalette_09: @ 85B6550
	.incbin "graphics/roulette/wynaut.gbapal"

	.align 2
RouletteSpritePalette_10: @ 85B6570
	.incbin "graphics/roulette/azurill.gbapal"

	.align 2
RouletteSpritePalette_11: @ 85B6590
	.incbin "graphics/roulette/skitty.gbapal"

	.align 2
RouletteSpritePalette_12: @ 85B65B0
	.incbin "graphics/roulette/makuhita.gbapal"

	.align 2
RouletteSpritePalette_13: @ 85B65D0
	.incbin "graphics/roulette/85B65D0.gbapal"

	.align 2
RouletteSpritePalette_14: @ 85B65F0
	.incbin "graphics/roulette/85B65F0.gbapal"

	.align 2
RouletteSpritePalette_15: @ 85B6610
	.incbin "graphics/roulette/85B6610.gbapal"

	.align 2
RouletteSpritePalette_16: @ 85B6630
	.incbin "graphics/roulette/85B6630.gbapal"

	.align 2
gUnknown_085B6650:: @ 85B6650
	.incbin "graphics/roulette/ball.4bpp.lz"

	.align 2
RouletteBallCounterTiles: @ 85B6798
	.incbin "graphics/roulette/ball_counter.4bpp.lz"

	.align 2
gUnknown_085B67FC:: @ 85B67FC
	.incbin "graphics/roulette/roulette_tilt.4bpp.lz"

	.align 2
RoulettePokeIconsTiles: @ 85B6BEC
	.incbin "graphics/roulette/poke_icons.4bpp.lz"

	.align 2
RoulettePokeIcons2Tiles: @ 85B6D90
	.incbin "graphics/roulette/poke_icons2.4bpp.lz"

	.align 2
gUnknown_085B7290:: @ 85B7290
	.incbin "graphics/roulette/shadow.4bpp.lz"

	.align 2
RouletteCursorTiles: @ 85B7328
	.incbin "graphics/roulette/cursor.4bpp.lz"

	.align 2
gUnknown_085B7384:: @ 85B7384
	obj_pal RouletteSpritePalette_01, 1
	obj_pal RouletteSpritePalette_02, 2
	obj_pal RouletteSpritePalette_03, 3
	obj_pal RouletteSpritePalette_04, 4
	obj_pal RouletteSpritePalette_05, 5
	obj_pal RouletteSpritePalette_06, 6
	obj_pal RouletteSpritePalette_07, 7
	obj_pal RouletteSpritePalette_08, 8
	obj_pal RouletteSpritePalette_09, 9
	obj_pal RouletteSpritePalette_10, 10
	obj_pal RouletteSpritePalette_11, 11
	obj_pal RouletteSpritePalette_12, 12
	null_obj_pal

	.align 2
gOamData_85B73EC:: @ 85B73EC
	.2byte 0x0000
	.2byte 0x8000
	.2byte 0x0400

	.align 2
gOamData_85B73F4:: @ 85B73F4
	.2byte 0x0000
	.2byte 0x4000
	.2byte 0x0400

	.align 2
gOamData_85B73FC:: @ 85B73FC
	.2byte 0x833C
	.2byte 0x8000
	.2byte 0x0800

	.align 2
gSpriteAnim_85B7404:: @ 85B7404
	obj_image_anim_frame 0, 0
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85B740C:: @ 85B740C
	.4byte gSpriteAnim_85B7404

	.align 2
gSpriteAffineAnim_85B7410:: @ 85B7410
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnimTable_85B7418:: @ 85B7418
	.4byte gSpriteAffineAnim_85B7410

	.align 2
gUnknown_085B741C:: @ 85B741C
	obj_tiles RoulettePokeIcons2Tiles, 0xC00, 0

	.align 2
gSpriteAnim_85B7420:: @ 85B7420
	obj_image_anim_frame 0, 0
	obj_image_anim_frame 32, 0
	obj_image_anim_frame 64, 0
	obj_image_anim_frame 72, 0
	obj_image_anim_frame 8, 0
	obj_image_anim_frame 40, 0
	obj_image_anim_frame 48, 0
	obj_image_anim_frame 80, 0
	obj_image_anim_frame 16, 0
	obj_image_anim_frame 24, 0
	obj_image_anim_frame 56, 0
	obj_image_anim_frame 88, 0
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85B7458:: @ 85B7458
	.4byte gSpriteAnim_85B7420

	.align 2
gSpriteAnimTable_85B745C:: @ 85B745C
	.4byte gSpriteAnim_85B7420 + 0x4

	.align 2
gSpriteAnimTable_85B7460:: @ 85B7460
	.4byte gSpriteAnim_85B7420 + 0x8

	.align 2
gSpriteAnimTable_85B7464:: @ 85B7464
	.4byte gSpriteAnim_85B7420 + 0xC

	.align 2
gSpriteAnimTable_85B7468:: @ 85B7468
	.4byte gSpriteAnim_85B7420 + 0x10

	.align 2
gSpriteAnimTable_85B746C:: @ 85B746C
	.4byte gSpriteAnim_85B7420 + 0x14

	.align 2
gSpriteAnimTable_85B7470:: @ 85B7470
	.4byte gSpriteAnim_85B7420 + 0x18

	.align 2
gSpriteAnimTable_85B7474:: @ 85B7474
	.4byte gSpriteAnim_85B7420 + 0x1C

	.align 2
gSpriteAnimTable_85B7478:: @ 85B7478
	.4byte gSpriteAnim_85B7420 + 0x20

	.align 2
gSpriteAnimTable_85B747C:: @ 85B747C
	.4byte gSpriteAnim_85B7420 + 0x24

	.align 2
gSpriteAnimTable_85B7480:: @ 85B7480
	.4byte gSpriteAnim_85B7420 + 0x28

	.align 2
gSpriteAnimTable_85B7484:: @ 85B7484
	.4byte gSpriteAnim_85B7420 + 0x2C

	.align 2
gUnknown_085B7488:: @ 85B7488
	obj_tiles gRouletteHeadersTiles, 0x1600, 4

	.align 2
gUnknown_085B7490:: @ 85B7490
	obj_tiles RoulettePokeIconsTiles, 0x400, 5

	.align 2
gSpriteAnim_85B7498:: @ 85B7498
	obj_image_anim_frame 0, 0
	obj_image_anim_frame 16, 0
	obj_image_anim_frame 32, 0
	obj_image_anim_frame 48, 0
	obj_image_anim_frame 64, 0
	obj_image_anim_frame 80, 0
	obj_image_anim_frame 96, 0
	obj_image_anim_frame 112, 0
	obj_image_anim_frame 128, 0
	obj_image_anim_frame 144, 0
	obj_image_anim_frame 160, 0
	obj_image_anim_end

	.align 2
gSpriteAnim_85B74C8:: @ 85B74C8
	obj_image_anim_frame 0, 0
	obj_image_anim_frame 4, 0
	obj_image_anim_frame 8, 0
	obj_image_anim_frame 12, 0
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85B74DC:: @ 85B74DC
	.4byte gSpriteAnim_85B7498

	.align 2
gSpriteAnimTable_85B74E0:: @ 85B74E0
	.4byte gSpriteAnim_85B7498 + 0x8

	.align 2
gSpriteAnimTable_85B74E4:: @ 85B74E4
	.4byte gSpriteAnim_85B7498 + 0x10

	.align 2
gSpriteAnimTable_85B74E8:: @ 85B74E8
	.4byte gSpriteAnim_85B7498 + 0x18

	.align 2
gSpriteAnimTable_85B74EC:: @ 85B74EC
	.4byte gSpriteAnim_85B7498 + 0x20

	.align 2
gSpriteAnimTable_85B74F0:: @ 85B74F0
	.4byte gSpriteAnim_85B7498 + 0x24

	.align 2
gSpriteAnimTable_85B74F4:: @ 85B74F4
	.4byte gSpriteAnim_85B7498 + 0x28

	.align 2
gSpriteAnimTable_85B74F8:: @ 85B74F8
	.4byte gSpriteAnim_85B74C8

	.align 2
gSpriteAnimTable_85B74FC:: @ 85B74FC
	.4byte gSpriteAnim_85B74C8 + 0x4

	.align 2
gSpriteAnimTable_85B7500:: @ 85B7500
	.4byte gSpriteAnim_85B74C8 + 0x8

	.align 2
gSpriteAnimTable_85B7504:: @ 85B7504
	.4byte gSpriteAnim_85B74C8 + 0xC

	.align 2
gSpriteTemplate_85B7508:: @ 85B7508
	spr_template 4, 8, gOamData_85B73EC, gSpriteAnimTable_85B74DC, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B7520:: @ 85B7520
	spr_template 4, 8, gOamData_85B73EC, gSpriteAnimTable_85B74E0, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B7538:: @ 85B7538
	spr_template 4, 8, gOamData_85B73EC, gSpriteAnimTable_85B74E4, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B7550:: @ 85B7550
	spr_template 4, 8, gOamData_85B73EC, gSpriteAnimTable_85B74E8, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B7568:: @ 85B7568
	spr_template 4, 8, gOamData_85B73EC, gSpriteAnimTable_85B74EC, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B7580:: @ 85B7580
	spr_template 4, 8, gOamData_85B73EC, gSpriteAnimTable_85B74F0, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B7598:: @ 85B7598
	spr_template 4, 8, gOamData_85B73EC, gSpriteAnimTable_85B74F4, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B75B0:: @ 85B75B0
	spr_template 5, 8, gOamData_85B73F4, gSpriteAnimTable_85B74F8, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B75C8:: @ 85B75C8
	spr_template 5, 8, gOamData_85B73F4, gSpriteAnimTable_85B74FC, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B75E0:: @ 85B75E0
	spr_template 5, 8, gOamData_85B73F4, gSpriteAnimTable_85B7500, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B75F8:: @ 85B75F8
	spr_template 5, 8, gOamData_85B73F4, gSpriteAnimTable_85B7504, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gSpriteTemplate_85B7610:: @ 85B7610
	spr_template 0, 9, gOamData_85B73FC, gSpriteAnimTable_85B7458, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B7628:: @ 85B7628
	spr_template 0, 10, gOamData_85B73FC, gSpriteAnimTable_85B745C, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B7640:: @ 85B7640
	spr_template 0, 11, gOamData_85B73FC, gSpriteAnimTable_85B7460, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B7658:: @ 85B7658
	spr_template 0, 12, gOamData_85B73FC, gSpriteAnimTable_85B7464, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B7670:: @ 85B7670
	spr_template 0, 9, gOamData_85B73FC, gSpriteAnimTable_85B7468, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B7688:: @ 85B7688
	spr_template 0, 10, gOamData_85B73FC, gSpriteAnimTable_85B746C, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B76A0:: @ 85B76A0
	spr_template 0, 11, gOamData_85B73FC, gSpriteAnimTable_85B7470, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B76B8:: @ 85B76B8
	spr_template 0, 12, gOamData_85B73FC, gSpriteAnimTable_85B7474, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B76D0:: @ 85B76D0
	spr_template 0, 9, gOamData_85B73FC, gSpriteAnimTable_85B7478, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B76E8:: @ 85B76E8
	spr_template 0, 10, gOamData_85B73FC, gSpriteAnimTable_85B747C, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B7700:: @ 85B7700
	spr_template 0, 11, gOamData_85B73FC, gSpriteAnimTable_85B7480, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gSpriteTemplate_85B7718:: @ 85B7718
	spr_template 0, 12, gOamData_85B73FC, gSpriteAnimTable_85B7484, NULL, gDummySpriteAffineAnimTable, sub_8143280

	.align 2
gOamData_85B7730:: @ 85B7730
	.2byte 0x4000
	.2byte 0xC000
	.2byte 0x0400

	.align 2
gOamData_85B7738:: @ 85B7738
	.2byte 0x8000
	.2byte 0x0000
	.2byte 0x0400

	.align 2
gOamData_85B7740:: @ 85B7740
	.2byte 0x4000
	.2byte 0x8000
	.2byte 0x0400

	.align 2
gOamData_85B7748:: @ 85B7748
	.2byte 0x4000
	.2byte 0x0000
	.2byte 0x0400

	.align 2
gUnknown_085B7750:: @ 85B7750
	obj_tiles gRouletteCreditTiles, 0x400, 7
	obj_tiles gRouletteNumbersTiles, 0x280, 8
	obj_tiles gRouletteMultiplierTiles, 0x500, 9
	obj_tiles RouletteBallCounterTiles, 0x140, 10
	obj_tiles RouletteCursorTiles, 0x200, 11
	null_obj_tiles

	.align 2
gSpriteAnim_85B7780:: @ 85B7780
	obj_image_anim_frame 0, 0
	obj_image_anim_frame 2, 0
	obj_image_anim_frame 4, 0
	obj_image_anim_frame 6, 0
	obj_image_anim_frame 8, 0
	obj_image_anim_frame 10, 0
	obj_image_anim_frame 12, 0
	obj_image_anim_frame 14, 0
	obj_image_anim_frame 16, 0
	obj_image_anim_frame 18, 0

	.align 2
gSpriteAnimTable_85B77A8:: @ 85B77A8
	.4byte gSpriteAnim_85B7780

	.align 2
gSpriteAnim_85B77AC:: @ 85B77AC
	obj_image_anim_frame 0, 0
	obj_image_anim_frame 8, 0
	obj_image_anim_frame 16, 0
	obj_image_anim_frame 24, 0
	obj_image_anim_frame 32, 0
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85B77C4:: @ 85B77C4
	.4byte gSpriteAnim_85B77AC

	.align 2
gSpriteAnim_85B77C8:: @ 85B77C8
	obj_image_anim_frame 0, 0
	obj_image_anim_frame 2, 0
	obj_image_anim_frame 4, 0
	obj_image_anim_frame 6, 0
	obj_image_anim_frame 8, 0
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85B77E0:: @ 85B77E0
	.4byte gSpriteAnim_85B77C8

	.align 2
gSpriteTemplate_85B77E4:: @ 85B77E4
	spr_template 7, 5, gOamData_85B7730, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085B77FC:: @ 85B77FC
	spr_template 8, 5, gOamData_85B7738, gSpriteAnimTable_85B77A8, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085B7814:: @ 85B7814
	spr_template 9, 5, gOamData_85B7740, gSpriteAnimTable_85B77C4, NULL, gDummySpriteAffineAnimTable, sub_814390C

	.align 2
gUnknown_085B782C:: @ 85B782C
	spr_template 10, 3, gOamData_85B7748, gSpriteAnimTable_85B77E0, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085B7844:: @ 85B7844
	spr_template 11, 5, gOamData_85B73EC, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gOamData_85B785C:: @ 85B785C
	.2byte 0x0000
	.2byte 0x4000
	.2byte 0x0800

	.align 2
gUnknown_085B7864:: @ 85B7864
	obj_tiles gUnknown_085B6650, 0x200, 0xC

	.align 2
gSpriteAnim_85B786C:: @ 85B786C
	obj_image_anim_frame 0, 5
	obj_image_anim_frame 4, 5
	obj_image_anim_frame 8, 5
	obj_image_anim_frame 4, 5
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85B7880:: @ 85B7880
	obj_image_anim_frame 0, 10
	obj_image_anim_frame 4, 10
	obj_image_anim_frame 8, 10
	obj_image_anim_frame 4, 10
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85B7894:: @ 85B7894
	obj_image_anim_frame 0, 15
	obj_image_anim_frame 4, 15
	obj_image_anim_frame 8, 15
	obj_image_anim_frame 4, 15
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85B78A8:: @ 85B78A8
	obj_image_anim_frame 4, 2
	obj_image_anim_frame 8, 5
	obj_image_anim_frame 4, 5
	obj_image_anim_frame 12, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_85B78BC:: @ 85B78BC
	obj_image_anim_frame 4, 2
	obj_image_anim_frame 0, 4
	obj_image_anim_frame 4, 4
	obj_image_anim_frame 8, 4
	obj_image_anim_frame 12, 4
	obj_image_anim_end

	.align 2
gSpriteAnim_85B78D4:: @ 85B78D4
	obj_image_anim_frame 0, 2
	obj_image_anim_frame 4, 5
	obj_image_anim_frame 8, 5
	obj_image_anim_frame 12, 5
	obj_image_anim_end

	.align 2
gSpriteAnim_85B78E8:: @ 85B78E8
	obj_image_anim_frame 12, 0
	obj_image_anim_end

	.align 2
gSpriteAnim_85B78F0:: @ 85B78F0
	obj_image_anim_frame 8, 2
	obj_image_anim_frame 4, 5
	obj_image_anim_frame 0, 5
	obj_image_anim_frame 12, 5
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85B7904:: @ 85B7904
	.4byte gSpriteAnim_85B786C
	.4byte gSpriteAnim_85B7880
	.4byte gSpriteAnim_85B7894
	.4byte gSpriteAnim_85B78A8
	.4byte gSpriteAnim_85B78F0
	.4byte gSpriteAnim_85B78BC
	.4byte gSpriteAnim_85B78D4
	.4byte gSpriteAnim_85B78D4
	.4byte gSpriteAnim_85B78E8

	.align 2
gSpriteTemplate_85B7928:: @ 85B7928
	spr_template 12, 2, gOamData_85B785C, gSpriteAnimTable_85B7904, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gOamData_85B7940:: @ 85B7940
	.2byte 0x0351
	.2byte 0xC000
	.2byte 0x0800

	.align 2
gUnknown_085B7948:: @ 85B7948
	obj_tiles gRouletteCenter_Gfx, 2048, 0x0006

	.align 2
gSpriteTemplate_85B7950:: @ 85B7950
	spr_template 6, 2, gOamData_85B7940, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_814399C

	.align 2
gOamData_85B7968:: @ 85B7968
	.2byte 0x0000
	.2byte 0x8000
	.2byte 0x0800

	.align 2
gOamData_85B7970:: @ 85B7970
	.2byte 0x0000
	.2byte 0x8000
	.2byte 0x0800

	.align 2
gUnknown_085B7978:: @ 85B7978
	obj_tiles gUnknown_085B67FC, 0xE00, 0x000D

	.align 2
gSpriteAnim_85B7980:: @ 85B7980
	obj_image_anim_frame 0x00, 6
	obj_image_anim_frame 0x10, 6
	obj_image_anim_frame 0x20, 6
	obj_image_anim_frame 0x30, 6
	obj_image_anim_frame 0x20, 6
	obj_image_anim_frame 0x40, 6
	obj_image_anim_jump 2

	.align 2
gSpriteAnim_85B799C:: @ 85B799C
	obj_image_anim_frame 0x50, 10
	obj_image_anim_end

	.align 2
gSpriteAnim_85B79A4:: @ 85B79A4
	obj_image_anim_frame 0x50, 10, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_end

	.align 2
gSpriteAnim_85B79AC:: @ 85B79AC
	obj_image_anim_frame 0x50, 20
	obj_image_anim_frame 0x60, 20
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85B79B8:: @ 85B79B8
	obj_image_anim_frame 0x50, 20, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_frame 0x60, 20, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85B79C4:: @ 85B79C4
	obj_image_anim_frame 0x50, 10
	obj_image_anim_frame 0x60, 10
	obj_image_anim_jump 0

	.align 2
gSpriteAnim_85B79D0:: @ 85B79D0
	obj_image_anim_frame 0x50, 10, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_frame 0x60, 10, OBJ_IMAGE_ANIM_H_FLIP
	obj_image_anim_jump 0

	.align 2
gSpriteAnimTable_85B79DC:: @ 85B79DC
	.4byte gSpriteAnim_85B7980

	.align 2
gSpriteAnimTable_85B79E0:: @ 85B79E0
	.4byte gSpriteAnim_85B799C
	.4byte gSpriteAnim_85B79A4
	.4byte gSpriteAnim_85B79AC
	.4byte gSpriteAnim_85B79B8
	.4byte gSpriteAnim_85B79C4
	.4byte gSpriteAnim_85B79D0

	.align 2
gSpriteTemplate_85B79F8:: @ 85B79F8
	spr_template 13, 6, gOamData_85B7968, gSpriteAnimTable_85B79DC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gSpriteTemplate_85B7A10:: @ 85B7A10
	spr_template 13, 7, gOamData_85B7970, gSpriteAnimTable_85B79E0, NULL, gDummySpriteAffineAnimTable, sub_8145294

	.align 2
gOamData_85B7A28:: @ 85B7A28
	.2byte 0x0000
	.2byte 0x4000
	.2byte 0x0800

	.align 2
gOamData_85B7A30:: @ 85B7A30
	.2byte 0x4000
	.2byte 0x8000
	.2byte 0x0800

	.align 2
gOamData_85B7A38:: @ 85B7A38
	.2byte 0x4100
	.2byte 0x8000
	.2byte 0x0800

	.align 2
gUnknown_085B7A40:: @ 85B7A40
	obj_tiles gUnknown_085B7290, 0x180, 0x000E

	.align 2
gSpriteAffineAnim_85B7A48:: @ 85B7A48
	obj_rot_scal_anim_frame 0x80, 0x80, 0, 0
	obj_rot_scal_anim_frame 0x2, 0x2, 0, 60
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnim_85B7A60:: @ 85B7A60
	obj_rot_scal_anim_frame 0x100, 0x100, 0, 0
	obj_rot_scal_anim_frame 0xFFFE, 0x0, 0, 15
	obj_rot_scal_anim_frame 0xFFFF, 0xFFFE, 0, 15
	obj_rot_scal_anim_frame 0xFFFF, 0xFFFB, 0, 24
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnimTable_85B7A88:: @ 85B7A88
	.4byte gSpriteAffineAnim_85B7A48

	.align 2
gSpriteAffineAnimTable_85B7A8C:: @ 85B7A8C
	.4byte gSpriteAffineAnim_85B7A60

	.align 2
gSpriteAffineAnim_85B7A90:: @ 85B7A90
	obj_rot_scal_anim_frame 0x100, 0x100, 0, 0
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnimTable_85B7AA0:: @ 85B7AA0
	.4byte gSpriteAffineAnim_85B7A90

	.align 2
gSpriteAnim_85B7AA4:: @ 85B7AA4
	obj_image_anim_frame 0, 0
	obj_image_anim_end

	.align 2
gSpriteAnim_85B7AAC:: @ 85B7AAC
	obj_image_anim_frame 4, 0
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85B7AB4:: @ 85B7AB4
	.4byte gSpriteAnim_85B7AA4

	.align 2
gSpriteAnimTable_85B7AB8:: @ 85B7AB8
	.4byte gSpriteAnim_85B7AAC

	.align 2
gSpriteTemplate_85B7ABC:: @ 85B7ABC
	spr_template 14, 1, gOamData_85B7A28, gSpriteAnimTable_85B7AB4, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gSpriteTemplate_83FA5D8:: @ 83FA5D8
	spr_template 14, 1, gOamData_85B7A30, gSpriteAnimTable_85B7AB8, NULL, gDummySpriteAffineAnimTable, sub_8144E60

	.align 2
gUnknown_085B7AEC:: @ 85B7AEC
	spr_template 14, 1, gOamData_85B7A38, gSpriteAnimTable_85B7AB8, NULL, gSpriteAffineAnimTable_85B7A8C, sub_8145294

gUnknown_085B7B04:: @ 85B7B04
	.byte 0, 1, 2, 3, 4

	.align 1
gUnknown_085B7B0A:: @ 85B7B0A
	.2byte 0x74, 0x2C
	.2byte 0x74, 0x70

	.align 1
gUnknown_085B7B12:: @ 85B7B12
	.2byte 256, 84
	.2byte -16, 84

	.align 1
gUnknown_085B7B1A:: @ 85B7B1A
	.2byte 0x907
	.2byte 0x808
	.2byte 0x709
	.2byte 0x60A
	.2byte 0x50B
	.2byte 0x40C
	.2byte 0x30D
	.2byte 0x20E
	.2byte 0x10F
	.2byte  0x10

	.align 1
gUnknown_085B7B2E:: @ 85B7B2E
	.2byte  -1,  0,  1,  0
	.2byte  -2,  0,  2,  0
	.2byte  -3,  0,  3,  0

gUnknown_085B7B46:: @ 85B7B46
	.byte -1, 1

gUnknown_085B7B48:: @ 85B7B48
	.byte   2,  0
	.byte   2,  0
	.byte   2, -1
	.byte   2, -1
	.byte   2, -1
	.byte   2, -1
	.byte   2, -2
	.byte   2, -2
