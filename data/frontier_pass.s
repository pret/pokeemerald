	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

.macro unk_trainer_card_struct text1, text2, short1, short2, short3, short4
	.4byte \text1
	.4byte \text2
	.2byte \short1
	.2byte \short2
	.2byte \short3
	.2byte \short4
.endm

	.align 2
gUnknown_0856FB7C:: @ 856FB7C
	.incbin "graphics/frontier_pass/map_heads.gbapal"

	.align 2
gUnknown_0856FB9C:: @ 856FB9C
	.incbin "graphics/frontier_pass/map_heads_female.gbapal"

	.align 2
gUnknown_0856FBBC:: @ 856FBBC
	.incbin "graphics/frontier_pass/map_screen.4bpp.lz"

	.align 2
gFrontierPassCursor_Gfx:: @ 8570BA8
	.incbin "graphics/frontier_pass/cursor.4bpp.lz"

	.align 2
gUnknown_08570C44:: @ 8570C44
	.incbin "graphics/frontier_pass/map_heads.4bpp.lz"

	.align 2
gFrontierPassMapCursor_Gfx:: @ 8570D00
	.incbin "graphics/frontier_pass/map_cursor.4bpp.lz"

	.align 2
gUnknown_08570E00:: @ 8570E00
	.incbin "graphics/frontier_pass/map_screen.bin.lz"

	.align 2
gUnknown_08571060:: @ 8571060
	.incbin "graphics/frontier_pass/small_map_and_card.bin.lz"

	.align 2
gUnknown_08571298:: @ 8571298
	.incbin "graphics/frontier_pass/unknown_571298.bin"

	.align 2
gUnknown_085712C0:: @ 85712C0
	.incbin "graphics/frontier_pass/record_frame.bin.lz"

	.align 2
gUnknown_085712F8:: @ 85712F8
	.incbin "graphics/frontier_pass/small_map_and_card_affine.bin.lz"

gUnknown_085713E0:: @ 85713E0
	.2byte 0x00d8, 0x0020, 0x00d8, 0x0080

	.align 2
gUnknown_085713E8:: @ 85713E8
	.4byte 0x000011f8, 0x000021e1, 0x00000bd6

	.align 2
gUnknown_085713F4:: @ 85713F4
	.4byte 0x000001f8, 0x000011e1, 0x000021d2

	.align 2
gUnknown_08571400:: @ 8571400
	window_template 0x00, 0x02, 0x03, 0x0c, 0x03, 0x0f, 0x0001
	window_template 0x00, 0x02, 0x0a, 0x0c, 0x03, 0x0f, 0x0026
	window_template 0x00, 0x02, 0x0d, 0x0c, 0x04, 0x0f, 0x004b
	window_template 0x00, 0x00, 0x12, 0x1e, 0x03, 0x0f, 0x007c
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

	.align 2
gUnknown_08571428:: @ 8571428
	window_template 0x00, 0x00, 0x01, 0x0f, 0x05, 0x0f, 0x0001
	window_template 0x00, 0x14, 0x01, 0x0a, 0x0e, 0x0f, 0x004d
	window_template 0x00, 0x02, 0x10, 0x1a, 0x04, 0x0f, 0x00da
	window_template 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0000

gUnknown_08571448:: @ 8571448
	.byte 0x00, 0x02, 0x03

gUnknown_0857144B:: @ 857144B
	.byte 0x00, 0x01, 0x09

gUnknown_0857144E:: @ 857144E
	.byte 0x00, 0x04, 0x05

	.align 2
gUnknown_08571454:: @ 8571454
    .2byte 0x001c, 0x004c, 0x0084, 0x00dc, 0x0054, 0x0084, 0x0084, 0x00dc, 0x0050, 0x0066, 0x0014, 0x006c, 0x0000, 0x0010, 0x0098, 0x00f0
    .2byte 0x006c, 0x0086, 0x0014, 0x006c, 0x0018, 0x0030, 0x0014, 0x006c, 0x0032, 0x0042, 0x0014, 0x0024, 0x0042, 0x0052, 0x0020, 0x0030
    .2byte 0x0032, 0x0042, 0x002c, 0x003c, 0x0042, 0x0052, 0x0038, 0x0048, 0x0032, 0x0042, 0x0044, 0x0054, 0x0042, 0x0052, 0x0050, 0x0060
    .2byte 0x0032, 0x0042, 0x005c, 0x006c

	.align 2
gUnknown_085714BC:: @ 85714BC
	obj_tiles gFrontierPassCursor_Gfx, 0x100, 0
	obj_tiles gFrontierPassMapCursor_Gfx, 0x400, 1
	obj_tiles gFrontierPassMedals_Gfx, 0x380, 2

	.align 2
gUnknown_085714D4:: @ 85714D4
	obj_tiles gUnknown_08570C44, 0x100, 4
	null_obj_tiles

	.align 2
gUnknown_085714E4:: @ 85714E4
	obj_pal gFrontierPassCursor_Pal, 0
	obj_pal gFrontierPassMapCursor_Pal, 1
	obj_pal gFrontierPassMedalsSilver_Pal, 2
	obj_pal gFrontierPassMedalsGold_Pal, 3
	obj_pal gUnknown_0856FB7C, 4
	obj_pal gUnknown_0856FB9C, 5
	null_obj_pal

	.align 2
gSpriteAnim_857151C:: @ 857151C
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_8571524:: @ 8571524
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_857152C:: @ 857152C
	.2byte 0x0004, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_8571534:: @ 8571534
	.2byte 0x0008, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_857153C:: @ 857153C
	.2byte 0x000c, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_8571544:: @ 8571544
	.2byte 0x0010, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_857154C:: @ 857154C
	.2byte 0x0014, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_8571554:: @ 8571554
	.2byte 0x0018, 0x0000, 0xffff, 0x0000

	.align 2
gSpriteAnim_857155C:: @ 857155C
	.2byte 0x0000, 0x002d, 0x0008, 0x002d, 0xfffe, 0x0000

	.align 2
gSpriteAnim_8571568:: @ 8571568
	.2byte 0x0010, 0x002d, 0x0018, 0x002d, 0xfffe, 0x0000

	.align 2
gSpriteAnimTable_08571574:: @ 8571574
	.4byte gSpriteAnim_8571524
	.4byte gSpriteAnim_857152C

	.align 2
gSpriteAnimTable_0857157C:: @ 857157C
	.4byte gSpriteAnim_8571524 
	.4byte gSpriteAnim_857152C
	.4byte gSpriteAnim_8571534
	.4byte gSpriteAnim_857153C
	.4byte gSpriteAnim_8571544
	.4byte gSpriteAnim_857154C
	.4byte gSpriteAnim_8571554

	.align 2
gSpriteAnimTable_08571598:: @ 8571598
	.4byte gSpriteAnim_857155C
	.4byte gSpriteAnim_8571568

	.align 2
gSpriteAffineAnim_085715A0:: @ 85715A0
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gSpriteAffineAnimTable_085715B0:: @ 85715B0
	.4byte gSpriteAffineAnim_085715A0

	.align 2
gUnknown_085715B4:: @ 85715B4
	spr_template 0, 0, gUnknown_0852490C, gSpriteAnimTable_08571574, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
	spr_template 1, 1, gUnknown_08524934, gSpriteAnimTable_08571598, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085715E4:: @ 85715E4
	spr_template 2, 2, gUnknown_0852490C, gSpriteAnimTable_0857157C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_085715FC:: @ 85715FC
	spr_template 4, 4, gUnknown_0852490C, gSpriteAnimTable_08571574, NULL, gDummySpriteAffineAnimTable, nullsub_39

	.align 2
gUnknown_08571614:: @ 8571614
	.4byte gUnknown_085EDA96
	.4byte gUnknown_085ED932
	.4byte gUnknown_085ED94D
	.4byte gUnknown_085ED961
	.4byte gUnknown_085ED977
	.4byte gUnknown_085ED993
	.4byte gUnknown_085ED9AF
	.4byte gUnknown_085ED9C7
	.4byte gUnknown_085ED9E5
	.4byte gUnknown_085EDA02
	.4byte gUnknown_085EDA21
	.4byte gUnknown_085EDA3C
	.4byte gUnknown_085EDA5E
	.4byte gUnknown_085EDA78
	.4byte gUnknown_085ED931

	.align 2
gUnknown_08571650:: @ 8571650
	unk_trainer_card_struct gUnknown_085EDAB1, gUnknown_085EDB0F, 0x59, 0x28, 1, 0
	unk_trainer_card_struct gUnknown_085EDABE, gUnknown_085EDB4E, 0x21, 0x2A, 1, 0
	unk_trainer_card_struct gUnknown_085EDACA, gUnknown_085EDB8B, 0x78, 0x56, 0, 0
	unk_trainer_card_struct gUnknown_085EDAD8, gUnknown_085EDBC2, 0x72, 0x3B, 0, 0
	unk_trainer_card_struct gUnknown_085EDAE5, gUnknown_085EDC00, 0x19, 0x43, 0, 0
	unk_trainer_card_struct gUnknown_085EDAF4, gUnknown_085EDC45, 0x39, 0x39, 1, 0
	unk_trainer_card_struct gUnknown_085EDB00, gUnknown_085EDC84, 0x86, 0x29, 1, 0
