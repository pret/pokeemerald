#include "constants/easy_chat.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_08597530:: @ 8597530
	.4byte 0x0000001a
	.4byte sub_811A8CC
	.4byte 0x00000019
	.4byte sub_811A8F0
	.4byte 0x0000001c
	.4byte sub_811A914
	.4byte 0x0000001b
	.4byte sub_811A938

gEasyChatScreenTemplates:: @ 8597550
	.byte 0x00, 0x02, 0x02, 0x00

	.align 2
	.4byte gText_Profile
	.4byte gText_CombineFourWordsOrPhrases
	.4byte gText_AndMakeYourProfile
	.4byte gText_YourProfile
	.4byte gText_IsAsShownOkay

	.byte 0x01, 0x02, 0x03, 0x01

	.align 2
	.4byte gText_AtTheBattlesStart
	.4byte gText_CombineSixWordsOrPhrases
	.4byte gText_AndMakeAMessage
	.4byte gText_YourFeelingAtTheBattlesStart
	.4byte gText_IsAsShownOkay

	.byte 0x02, 0x02, 0x03, 0x01

	.align 2
	.4byte gText_UponWinningABattle
	.4byte gText_CombineSixWordsOrPhrases
	.4byte gText_AndMakeAMessage
	.4byte gText_WhatYouSayIfYouWin
	.4byte gText_IsAsShownOkay

	.byte 0x03, 0x02, 0x03, 0x01

	.align 2
	.4byte gText_UponLosingABattle
	.4byte gText_CombineSixWordsOrPhrases
	.4byte gText_AndMakeAMessage
	.4byte gText_WhatYouSayIfYouLose
	.4byte gText_IsAsShownOkay

	.byte 0x04, 0x02, 0x05, 0x02

	.align 2
	.4byte NULL
	.4byte gText_CombineNineWordsOrPhrases
	.4byte gText_AndMakeAMessage2
	.4byte gText_TheMailMessage
	.4byte gText_IsAsShownOkay

	.byte 0x05, 0x02, 0x02, 0x05

	.align 2
	.4byte gText_Interview
	.4byte gText_CombineFourWordsOrPhrases
	.4byte gText_LetsReplyToTheInterview
	.4byte gText_TheAnswer
	.4byte gText_IsAsShownOkay

	.byte 0x06, 0x02, 0x03, 0x01

	.align 2
	.4byte gText_TheBardsSong
	.4byte gText_ChangeJustOneWordOrPhrase
	.4byte gText_AndImproveTheBardsSong
	.4byte gText_TheBardsSong2
	.4byte gText_IsAsShownOkay

	.byte 0x07, 0x01, 0x01, 0x04

	.align 2
	.4byte gText_Interview
	.4byte gText_FindWordsThatDescribeYour
	.4byte gText_FeelingsRightNow
	.4byte gText_TheAnswer
	.4byte gText_IsAsShownOkay

	.byte 0x09, 0x02, 0x01, 0x03

	.align 2
	.4byte gText_WhatsHipAndHappening
	.4byte gText_CombineTwoWordsOrPhrases
	.4byte gText_AndMakeATrendySaying
	.4byte gText_TheTrendySaying
	.4byte gText_IsAsShownOkay

	.byte 0x10, 0x02, 0x05, 0x87

	.align 2
	.4byte NULL
	.4byte gText_AfterYouHaveReadTheQuiz
	.4byte gText_QuestionPressTheAButton
	.4byte NULL
	.4byte NULL

	.byte 0x0f, 0x01, 0x01, 0x86

	.align 2
	.4byte gText_TheQuizAnswerIs
	.4byte gText_OutOfTheListedChoices
	.4byte gText_SelectTheAnswerToTheQuiz
	.4byte gText_TheAnswerColon
	.4byte gText_IsAsShownOkay

	.byte 0x11, 0x02, 0x05, 0x88

	.align 2
	.4byte NULL
	.4byte gText_CombineNineWordsOrPhrases
	.4byte gText_AndCreateAQuiz
	.4byte gText_IsThisQuizOK
	.4byte NULL

	.byte 0x12, 0x01, 0x01, 0x86

	.align 2
	.4byte gText_TheQuizAnswerIs
	.4byte gText_PickAWordOrPhraseAnd
	.4byte gText_SetTheQuizAnswer
	.4byte gText_IsThisQuizOK
	.4byte NULL

	.byte 0x06, 0x02, 0x03, 0x01

	.align 2
	.4byte gText_TheBardsSong
	.4byte gText_ChangeJustOneWordOrPhrase
	.4byte gText_AndImproveTheBardsSong
	.4byte gText_TheBardsSong2
	.4byte gText_IsAsShownOkay

	.byte 0x13, 0x02, 0x03, 0x01

	.align 2
	.4byte gText_ApprenticesPhrase
	.4byte gText_FindWordsWhichFit
	.4byte gText_TheTrainersImage
	.4byte gText_ApprenticePhrase
	.4byte gText_IsAsShownOkay

	.byte 0x0d, 0x02, 0x01, 0x03

	.align 2
	.4byte gText_GoodSaying
	.4byte gText_CombineTwoWordsOrPhrases2
	.4byte gText_ToTeachHerAGoodSaying
	.4byte gText_TheAnswer
	.4byte gText_IsAsShownOkay

	.byte 0x0a, 0x01, 0x01, 0x04

	.align 2
	.4byte gText_Interview
	.4byte gText_FindWordsThatDescribeYour
	.4byte gText_FeelingsRightNow
	.4byte gText_TheAnswer
	.4byte gText_IsAsShownOkay

	.byte 0x0c, 0x01, 0x01, 0x04

	.align 2
	.4byte gText_Interview
	.4byte gText_FindWordsThatDescribeYour
	.4byte gText_FeelingsRightNow
	.4byte gText_TheAnswer
	.4byte gText_IsAsShownOkay

	.byte 0x0b, 0x01, 0x01, 0x04

	.align 2
	.4byte gText_Interview
	.4byte gText_FindWordsThatDescribeYour
	.4byte gText_FeelingsRightNow
	.4byte gText_TheAnswer
	.4byte gText_IsAsShownOkay

	.byte 0x0e, 0x01, 0x01, 0x04

	.align 2
	.4byte gText_FansQuestion
	.4byte gText_FindWordsWhichFit
	.4byte gText_TheTrainersImage
	.4byte gText_TheImage
	.4byte gText_IsAsShownOkay

	.byte 0x14, 0x02, 0x02, 0x00

	.align 2
	.4byte gText_Questionnaire
	.4byte gText_CombineFourWordsOrPhrases
	.4byte gText_AndFillOutTheQuestionnaire
	.4byte gText_TheAnswer
	.4byte gText_IsAsShownOkay

gUnknown_08597748:: @ 8597748
	.byte 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00
	.byte 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x00
	.byte 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13
	.byte 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a

gUnknown_08597764:: @ 8597764
	.2byte 0x0209, 0x140b, 0x1030, 0x102a

gUnknown_0859776C:: @ 859776C
	.2byte 0x1240, 0x0628
	.2byte 0x061f, 0x2204
	.2byte 0x1422, 0x0197
	.2byte 0x0415, 0x0198
	.2byte 0x2207, 0x0449

	.align 2
gUnknown_08597780:: @ 8597780
	.incbin "graphics/misc/interview_triangle_cursor.gbapal"

	.align 2
gUnknown_085977A0:: @ 85977A0
	.incbin "graphics/misc/interview_triangle_cursor.4bpp"

	.align 2
gUnknown_085977C0:: @ 85977C0
	.incbin "graphics/misc/interview_arrow.4bpp"

	.align 2
gUnknown_085978C0:: @ 85978C0
	.incbin "graphics/misc/interview_buttons.4bpp"

	.align 2
gUnknown_085979C0:: @ 85979C0
	.incbin "graphics/misc/interview_frame.gbapal"

	.align 2
gUnknown_085979E0:: @ 85979E0
	.incbin "graphics/misc/interview_frame.4bpp.lz"

	.align 2
gUnknown_08597B14:: @ 8597B14
	.incbin "graphics/misc/interview_frame_orange.gbapal"

	.align 2
gUnknown_08597B34:: @ 8597B34
	.incbin "graphics/misc/interview_frame_green.gbapal"

	.align 2
gUnknown_08597B54:: @ 8597B54
	.incbin "graphics/misc/interview_frame_2.4bpp.lz"

	.align 2
gUnknown_08597C1C:: @ 8597C1C
	.incbin "graphics/misc/8597C1C.gbapal"

	.align 2
gUnknown_08597C24:: @ 8597C24
	.incbin "graphics/misc/8597C24.gbapal"

gUnknown_08597C30:: @ 8597C30
	.byte 0x83, 0x18, 0x04, 0x00
	.byte 0x63, 0x18, 0x06, 0x00
	.byte 0x03, 0x18, 0x0a, 0x00
	.byte 0xa3, 0x18, 0x02, 0x00
	.byte 0xb0, 0x0c, 0x02, 0x00
	.byte 0x83, 0x18, 0x04, 0x00
	.byte 0x89, 0x0c, 0x02, 0x01
	.byte 0x65, 0x14, 0x0a, 0x03
	.byte 0x03, 0x18, 0x0a, 0x02

	.align 2
gUnknown_08597C54:: @ 8597C54
	.4byte 0x000001c0, 0x000011dd, 0x002021e2, 0x000031fb

	.align 2
gUnknown_08597C64:: @ 8597C64
	window_template 0x01, 0x06, 0x00, 0x12, 0x02, 0x0a, 0x0010
	window_template 0x00, 0x03, 0x0f, 0x18, 0x04, 0x0f, 0x000a
	window_template 0x02, 0x01, 0x00, 0x1c, 0x20, 0x03, 0x0000
	null_window_template

	.align 2
gUnknown_08597C84:: @ 8597C84
	window_template 0x00, 0x16, 0x09, 0x05, 0x04, 0x0f, 0x006a

gUnknown_08597C8C:: @ 8597C8C
	.string "{CLEAR 17}$"

	.align 2
gUnknown_08597C90:: @ 8597C90
	.4byte gUnknown_862B810
	.4byte gUnknown_862B832
	.4byte gUnknown_862B84B
	.4byte gUnknown_862B86C

	.align 2
gUnknown_08597CA0:: @ 8597CA0
	obj_tiles gUnknown_085977A0, 0x0020, 0x0000
	obj_tiles gUnknown_085977C0, 0x0100, 0x0002
	obj_tiles gUnknown_085978C0, 0x0100, 0x0003
	null_obj_tiles

	.align 2
gUnknown_08597CC0:: @ 8597CC0
	obj_pal gUnknown_08597780, 0x0000
	obj_pal gEasyChatCursor_Pal, 0x0001
	obj_pal gEasyChatRightWindow_Pal, 0x0002
	obj_pal gUnknown_085979C0, 0x0003
	null_obj_pal

	.align 2
gUnknown_08597CE8:: @ 8597CE8
	obj_tiles gUnknown_085979E0, 0x0800, 0x0005
	obj_tiles gEasyChatCursor_Gfx, 0x1000, 0x0001
	obj_tiles gEasyChatRightWindow_Gfx, 0x0800, 0x0006
	obj_tiles gEasyChatMode_Gfx, 0x1000, 0x0004

gUnknown_08597D08:: @ 8597D08
	.byte 0x00, 0x0c, 0x18, 0x38, 0x44, 0x50, 0x5c, 0x00

	.align 2
gOamData_8597D10:: @ 8597D10
	.2byte 0x0000
	.2byte 0x0000
	.2byte 0x0C00

	.align 2
gUnknown_08597D18:: @ 8597D18
	spr_template 0x0000, 0x0000, gOamData_8597D10, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_811DF28

	.align 2
gUnknown_08597D30:: @ 8597D30
	.2byte 0x4000, 0xc000, 0x0400, 0x0000

	.align 2
gUnknown_08597D38:: @ 8597D38
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597D40:: @ 8597D40
	.2byte 0x0020, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597D48:: @ 8597D48
	.2byte 0x0040, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597D50:: @ 8597D50
	.2byte 0x0060, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597D58:: @ 8597D58
	.4byte gUnknown_08597D38
	.4byte gUnknown_08597D40
	.4byte gUnknown_08597D48
	.4byte gUnknown_08597D50

	.align 2
gUnknown_08597D68:: @ 8597D68
	spr_template 0x0001, 0x0001, gUnknown_08597D30, gUnknown_08597D58, NULL, gDummySpriteAffineAnimTable, sub_811DF28

	.align 2
gUnknown_08597D80:: @ 8597D80
	.2byte 0x4000, 0xc000, 0x0400, 0x0000

	.align 2
gUnknown_08597D88:: @ 8597D88
	.2byte 0x0060, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597D90:: @ 8597D90
	.2byte 0x0040, 0x0004, 0x0020, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08597D9C:: @ 8597D9C
	.2byte 0x0040, 0x0004, 0x0000, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08597DA8:: @ 8597DA8
	.2byte 0x0040, 0x0004, 0x0060, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597DB4:: @ 8597DB4
	.2byte 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_08597DBC:: @ 8597DBC
	.4byte gUnknown_08597D88
	.4byte gUnknown_08597D90
	.4byte gUnknown_08597D9C
	.4byte gUnknown_08597DA8
	.4byte gUnknown_08597DB4

	.align 2
gUnknown_08597DD0:: @ 8597DD0
	spr_template 0x0004, 0x0002, gUnknown_08597D80, gUnknown_08597DBC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08597DE8:: @ 8597DE8
	.2byte 0x0000, 0xc000, 0x0c00, 0x0000

	.align 2
gUnknown_08597DF0:: @ 8597DF0
	spr_template 0x0006, 0x0002, gUnknown_08597DE8, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08597E08:: @ 8597E08
	.2byte 0x4000, 0x4000, 0x0400, 0x0000

	.align 2
gUnknown_08597E10:: @ 8597E10
	.2byte 0x0000, 0x4000, 0x0400, 0x0000

	.align 2
gUnknown_08597E18:: @ 8597E18
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597E20:: @ 8597E20
	.2byte 0x0004, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_08597E28:: @ 8597E28
	.4byte gUnknown_08597E18
	.4byte gUnknown_08597E20

	.align 2
gUnknown_08597E30:: @ 8597E30
	spr_template 0x0003, 0x0002, gUnknown_08597E08, gUnknown_08597E28, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_08597E48:: @ 8597E48
	spr_template 0x0002, 0x0002, gUnknown_08597E10, gUnknown_08597E28, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_08597E60:: @ 8597E60
	.byte 0x10, 0x6f, 0xc4, 0x00
	.byte 0x10, 0x4e, 0x82, 0xa0
	.byte 0x10, 0x50, 0x86, 0xaa

	.align 2
gUnknown_08597E6C:: @ 8597E6C
	.4byte gText_DelAll
	.4byte gText_Cancel5
	.4byte gText_Ok2
	.4byte NULL

	.4byte gText_DelAll
	.4byte gText_Cancel5
	.4byte gText_Ok2
	.4byte gText_Quiz

	.4byte gText_DelAll
	.4byte gText_Cancel5
	.4byte gText_Ok2
	.4byte gText_Answer

@ 8597E9C
	.include "data/text/easy_chat/easy_chat_groups.inc"

@ 859D0B4
	.include "data/text/easy_chat/easy_chat_words_by_letter.inc"

@ 859E5D4
	.include "data/text/easy_chat/easy_chat_group_name_pointers.inc"

gUnknown_0859E62C:: @ 859E62C
	.2byte 0x0a29, 0x1020, 0x020e, 0x0a33

gUnknown_0859E634:: @ 859E634
	.2byte 0x100f, 0x0a02, 0x0e25, 0x0c03, 0x0803, 0x0c00

gUnknown_0859E640:: @ 859E640
	.2byte 0x0c3a, 0x0c3a, 0x0c01, 0x0a2a, 0x0607, 0x0c01

gUnknown_0859E64C:: @ 859E64C
	.2byte 0x1039, 0x122e, 0x0c04, 0x0a3d, 0x0630, 0x0c04

gUnknown_0859E658:: @ 859E658
	.2byte 0x019a, 0x0000
