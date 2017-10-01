    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata

    .align 2
gEmotion_ExclamationMarkGfx:: @ 85505AC
	.incbin "graphics/misc/emotion_exclamation.4bpp"

    .align 2
gEmotion_QuestionMarkGfx:: @ 855062C
	.incbin "graphics/misc/emotion_question.4bpp"

    .align 2
gEmotion_HeartGfx:: @ 85506AC
	.incbin "graphics/misc/emotion_heart.4bpp"

    .align 2
gIsTrainerInRange:: @ 855072C
	.4byte IsTrainerInRangeSouth
	.4byte IsTrainerInRangeNorth
	.4byte IsTrainerInRangeWest
	.4byte IsTrainerInRangeEast

    .align 2
gTrainerSeeFuncList:: @ 855073C
	.4byte sub_80B4178
	.4byte sub_80B417C
	.4byte sub_80B41C0
	.4byte sub_80B4200
	.4byte sub_80B425C
	.4byte sub_80B4318
	.4byte sub_80B435C
	.4byte sub_80B4390
	.4byte sub_80B43AC
	.4byte sub_80B43E0
	.4byte sub_80B4438
	.4byte sub_80B44AC

    .align 2
gTrainerSeeFuncList2:: @ 855076C
	.4byte sub_80B43AC
	.4byte sub_80B43E0
	.4byte sub_80B4438
	.4byte sub_80B44AC

	.align 2
gOamData_855077C:: @ 855077C
	.2byte 0x0000
	.2byte 0x4000
	.2byte 0x0400

	.align 2
gSpriteImageTable_8550784:: @ 8550784
	obj_tiles gEmotion_ExclamationMarkGfx, 0x0080, 0x0000
	obj_tiles gEmotion_QuestionMarkGfx, 0x0080, 0x0000

	.align 2
gSpriteImageTable_8550794:: @ 8550794
	obj_tiles gEmotion_HeartGfx, 0x0080, 0x0000

	.align 2
gSpriteAnim_855079C:: @ 855079C
	obj_image_anim_frame 0, 60
	obj_image_anim_end

	.align 2
gSpriteAnim_85507A4:: @ 85507A4
	obj_image_anim_frame 1, 60
	obj_image_anim_end

	.align 2
gSpriteAnimTable_85507AC:: @ 85507AC
	.4byte gSpriteAnim_855079C
	.4byte gSpriteAnim_85507A4

	.align 2
gSpriteTemplate_85507B4:: @ 85507B4
	spr_template 0xffff, 0xffff, gOamData_855077C, gSpriteAnimTable_85507AC, gSpriteImageTable_8550784, gDummySpriteAffineAnimTable, objc_exclamation_mark_probably

	.align 2
gSpriteTemplate_85507CC:: @ 85507CC
	spr_template 0xffff, 0x1004, gOamData_855077C, gSpriteAnimTable_85507AC, gSpriteImageTable_8550794, gDummySpriteAffineAnimTable, objc_exclamation_mark_probably
