	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

.macro unk_trainer_card_struct text1, text2, short1, short2, short3, short4
	.4byte \text1
	.4byte \text2
	.2byte \short1
	.2byte \short2
	.2byte \short3
	.2byte \short4
.endm

gUnknown_0856F018:: @ 856F018
	 .incbin "baserom.gba", 0x56f018, 0x194

gEmeraldTrainerCard1Star_Pal:: @ 856F1AC
	 .incbin "baserom.gba", 0x56f1ac, 0x60

gFireRedTrainerCard1Star_Pal:: @ 856F20C
	 .incbin "baserom.gba", 0x56f20c, 0x60

gEmeraldTrainerCard2Star_Pal:: @ 856F26C
	 .incbin "baserom.gba", 0x56f26c, 0x60

gFireRedTrainerCard2Star_Pal:: @ 856F2CC
	 .incbin "baserom.gba", 0x56f2cc, 0x60

gEmeraldTrainerCard3Star_Pal:: @ 856F32C
	 .incbin "baserom.gba", 0x56f32c, 0x60

gFireRedTrainerCard3Star_Pal:: @ 856F38C
	 .incbin "baserom.gba", 0x56f38c, 0x60

gEmeraldTrainerCard4Star_Pal:: @ 856F3EC
	 .incbin "baserom.gba", 0x56f3ec, 0x60

gFireRedTrainerCard4Star_Pal:: @ 856F44C
	 .incbin "baserom.gba", 0x56f44c, 0x60

gUnknown_0856F4AC:: @ 856F4AC
	.incbin "baserom.gba", 0x56f4ac, 0x20

gUnknown_0856F4CC:: @ 856F4CC
	.incbin "baserom.gba", 0x56f4cc, 0x20

gUnknown_0856F4EC:: @ 856F4EC
	.incbin "baserom.gba", 0x56f4ec, 0x20

gUnknown_0856F50C:: @ 856F50C
	.incbin "baserom.gba", 0x56f50c, 0x20

gUnknown_0856F52C:: @ 856F52C
	.incbin "baserom.gba", 0x56f52c, 0x20

gUnknown_0856F54C:: @ 856F54C
	.incbin "baserom.gba", 0x56f54c, 0x20

gUnknown_0856F56C:: @ 856F56C
	.incbin "baserom.gba", 0x56f56c, 0x20

gUnknown_0856F58C:: @ 856F58C
	.incbin "baserom.gba", 0x56f58c, 0x20

gUnknown_0856F5AC:: @ 856F5AC
	.incbin "baserom.gba", 0x56f5ac, 0x20

gUnknown_0856F5CC:: @ 856F5CC
	.incbin "baserom.gba", 0x56f5cc, 0x248

gUnknown_0856F814:: @ 856F814
	.incbin "baserom.gba", 0x56f814, 0x2a0

gUnknown_0856FAB4:: @ 856FAB4
	.incbin "baserom.gba", 0x56fab4, 0x10

gUnknown_0856FAC4:: @ 856FAC4
	.incbin "baserom.gba", 0x56fac4, 0x20

	.align 2
gEmeraldTrainerCardStarPals:: @ 856FAE4
	.4byte gEmeraldTrainerCard0Star_Pal
	.4byte gEmeraldTrainerCard1Star_Pal
	.4byte gEmeraldTrainerCard2Star_Pal
	.4byte gEmeraldTrainerCard3Star_Pal
	.4byte gEmeraldTrainerCard4Star_Pal

	.align 2
gFireRedTrainerCardStarPals:: @ 856FAF8
	.4byte gFireRedTrainerCard0Star_Pal
	.4byte gFireRedTrainerCard1Star_Pal
	.4byte gFireRedTrainerCard2Star_Pal
	.4byte gFireRedTrainerCard3Star_Pal
	.4byte gFireRedTrainerCard4Star_Pal

gUnknown_0856FB0C:: @ 856FB0C
	.incbin "baserom.gba", 0x56fb0c, 0x3

gUnknown_0856FB0F:: @ 856FB0F
	 .incbin "baserom.gba", 0x56fb0f, 0x3

gUnknown_0856FB12:: @ 856FB12
	 .incbin "baserom.gba", 0x56fb12, 0x6

gUnknown_0856FB18:: @ 856FB18
	.incbin "baserom.gba", 0x56fb18, 0x8

gUnknown_0856FB20:: @ 856FB20
	.incbin "baserom.gba", 0x56fb20, 0x8

gUnknown_0856FB28:: @ 856FB28
	.4byte sub_80C4998
	.4byte sub_80C49D8
	.4byte sub_80C4B08
	.4byte sub_80C4C1C
	.4byte sub_80C4C84
	.4byte sub_80C4DB0

gUnknown_0856FB40:: @ 856FB40
	.4byte gUnknown_0856FB0C
	.4byte gUnknown_0856FB12

gUnknown_0856FB48:: @ 856FB48
	.incbin "baserom.gba", 0x56fb48, 0x2

gUnknown_0856FB4A:: @ 856FB4A
	.incbin "baserom.gba", 0x56fb4a, 0x2

gUnknown_0856FB4C:: @ 856FB4C
	.incbin "baserom.gba", 0x56fb4c, 0x9

gUnknown_0856FB55:: @ 856FB55
	.incbin "baserom.gba", 0x56fb55, 0x2

gUnknown_0856FB57:: @ 856FB57
	.incbin "baserom.gba", 0x56fb57, 0x5

gUnknown_0856FB5C:: @ 856FB5C
	.4byte gText_LinkBattles
	.4byte gText_LinkCableBattles
	.4byte gText_LinkBattles

gUnknown_0856FB68:: @ 856FB68
	.incbin "baserom.gba", 0x56fb68, 0x6

gUnknown_0856FB6E:: @ 856FB6E
	.incbin "baserom.gba", 0x56fb6e, 0x6

gUnknown_0856FB74:: @ 856FB74
	.incbin "baserom.gba", 0x56fb74, 0x4

gUnknown_0856FB78:: @ 856FB78
	 .incbin "baserom.gba", 0x56fb78, 0x4

gUnknown_0856FB7C:: @ 856FB7C
	 .incbin "baserom.gba", 0x56fb7c, 0x20

gUnknown_0856FB9C:: @ 856FB9C
	 .incbin "baserom.gba", 0x56fb9c, 0x20

gUnknown_0856FBBC:: @ 856FBBC
	 .incbin "baserom.gba", 0x56fbbc, 0xFEC

	 .align 2
gFrontierPassCursor_Gfx:: @ 8570BA8
	 .incbin "graphics/frontier_pass/cursor.4bpp.lz"

gUnknown_08570C44:: @ 8570C44
	 .incbin "baserom.gba", 0x570c44, 0xBC

	 .align 2
gFrontierPassMapCursor_Gfx:: @ 8570D00
	 .incbin "graphics/frontier_pass/map_cursor.4bpp.lz"

gUnknown_08570E00:: @ 8570E00
	.incbin "baserom.gba", 0x570e00, 0x260

gUnknown_08571060:: @ 8571060
	.incbin "baserom.gba", 0x571060, 0x260

gUnknown_085712C0:: @ 85712C0
	.incbin "baserom.gba", 0x5712c0, 0x38

gUnknown_085712F8:: @ 85712F8
	.incbin "baserom.gba", 0x5712f8, 0xe8

gUnknown_085713E0:: @ 85713E0
	.incbin "baserom.gba", 0x5713e0, 0x8

gUnknown_085713E8:: @ 85713E8
	.incbin "baserom.gba", 0x5713e8, 0xc

gUnknown_085713F4:: @ 85713F4
	.incbin "baserom.gba", 0x5713f4, 0xc

gUnknown_08571400:: @ 8571400
	.incbin "baserom.gba", 0x571400, 0x28

gUnknown_08571428:: @ 8571428
	.incbin "baserom.gba", 0x571428, 0x20

gUnknown_08571448:: @ 8571448
	.incbin "baserom.gba", 0x571448, 0x3

gUnknown_0857144B:: @ 857144B
	.incbin "baserom.gba", 0x57144b, 0x3

gUnknown_0857144E:: @ 857144E
	.incbin "baserom.gba", 0x57144e, 0x6

gUnknown_08571454:: @ 8571454
	.incbin "baserom.gba", 0x571454, 0x68

gUnknown_085714BC:: @ 85714BC
	obj_tiles gFrontierPassCursor_Gfx, 0x100, 0
	obj_tiles gFrontierPassMapCursor_Gfx, 0x400, 1
	obj_tiles gFrontierPassMedals_Gfx, 0x380, 2

gUnknown_085714D4:: @ 85714D4
	obj_tiles gUnknown_08570C44, 0x100, 4
	null_obj_tiles

gUnknown_085714E4:: @ 85714E4
	 obj_pal gFrontierPassCursor_Pal, 0
	 obj_pal gFrontierPassMapCursor_Pal, 1
	 obj_pal gFrontierPassMedalsSilver_Pal, 2
	 obj_pal gFrontierPassMedalsGold_Pal, 3
	 obj_pal gUnknown_0856FB7C, 4
	 obj_pal gUnknown_0856FB9C, 5
	 null_obj_pal

	 @ this doesnt look like its part of the same table.
	 .4byte 0x0, 0xFFFF

gUnknown_08571524:: @ 8571524
	 .incbin "baserom.gba", 0x571524, 0x8

gUnknown_0857152C:: @ 857152C
	 .incbin "baserom.gba", 0x57152c, 0x8

gUnknown_08571534:: @ 8571534
	 .incbin "baserom.gba", 0x571534, 0x8

gUnknown_0857153C:: @ 857153C
	 .incbin "baserom.gba", 0x57153c, 0x8

gUnknown_08571544:: @ 8571544
	 .incbin "baserom.gba", 0x571544, 0x8

gUnknown_0857154C:: @ 857154C
	 .incbin "baserom.gba", 0x57154c, 0x8

gUnknown_08571554:: @ 8571554
	 .incbin "baserom.gba", 0x571554, 0x8

gUnknown_0857155C:: @ 857155C
	 .incbin "baserom.gba", 0x57155c, 0xC

gUnknown_08571568:: @ 8571568
	 .incbin "baserom.gba", 0x571568, 0xC

gUnknown_08571574:: @ 8571574
	 .4byte gUnknown_08571524
	 .4byte gUnknown_0857152C

gUnknown_0857157C:: @ 857157C
	.4byte gUnknown_08571524 
	.4byte gUnknown_0857152C
	.4byte gUnknown_08571534
	.4byte gUnknown_0857153C
	.4byte gUnknown_08571544
	.4byte gUnknown_0857154C
	.4byte gUnknown_08571554

gUnknown_08571598:: @ 8571598
	 .4byte gUnknown_0857155C
	 .4byte gUnknown_08571568

gUnknown_085715A0:: @ 85715A0
	 .incbin "baserom.gba", 0x5715a0, 0x10

gUnknown_085715B0:: @ 85715B0
	 .4byte gUnknown_085715A0

gUnknown_085715B4:: @ 85715B4
	spr_template 0, 0, gUnknown_0852490C, gUnknown_08571574, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy
	spr_template 1, 1, gUnknown_08524934, gUnknown_08571598, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_085715E4:: @ 85715E4
	spr_template 2, 2, gUnknown_0852490C, gUnknown_0857157C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_085715FC:: @ 85715FC
	spr_template 4, 4, gUnknown_0852490C, gUnknown_08571574, NULL, gDummySpriteAffineAnimTable, nullsub_39

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

gUnknown_08571650:: @ 8571650
	unk_trainer_card_struct gUnknown_085EDAB1, gUnknown_085EDB0F, 0x59, 0x28, 1, 0
	unk_trainer_card_struct gUnknown_085EDABE, gUnknown_085EDB4E, 0x21, 0x2A, 1, 0
	unk_trainer_card_struct gUnknown_085EDACA, gUnknown_085EDB8B, 0x78, 0x56, 0, 0
	unk_trainer_card_struct gUnknown_085EDAD8, gUnknown_085EDBC2, 0x72, 0x3B, 0, 0
	unk_trainer_card_struct gUnknown_085EDAE5, gUnknown_085EDC00, 0x19, 0x43, 0, 0
	unk_trainer_card_struct gUnknown_085EDAF4, gUnknown_085EDC45, 0x39, 0x39, 1, 0
	unk_trainer_card_struct gUnknown_085EDB00, gUnknown_085EDC84, 0x86, 0x29, 1, 0
