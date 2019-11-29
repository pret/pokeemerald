@ TODO: These need to have description comment

	.macro apprentice_gavelvlmode
	setvar VAR_0x8004, APPRENTICE_FUNC_GAVE_LVLMODE
	special CallApprenticeFunction
	.endm

	.macro apprentice_setlvlmode lvlmode:req
	setvar VAR_0x8004, APPRENTICE_FUNC_SET_LVLMODE
	setorcopyvar VAR_0x8005, \lvlmode
	addvar VAR_0x8005, 1
	special CallApprenticeFunction
	.endm

	.macro apprentice_answeredquestion
	setvar VAR_0x8004, APPRENTICE_FUNC_ANSWERED_QUESTION
	special CallApprenticeFunction
	.endm

	.macro apprentice_menu  which:req
	setvar VAR_0x8004, APPRENTICE_FUNC_MENU
	setvar VAR_0x8005, \which
	special CallApprenticeFunction
	waitstate
	.endm

	.macro apprentice_shufflespecies
	setvar VAR_0x8004, APPRENTICE_FUNC_SHUFFLE_SPECIES
	special CallApprenticeFunction
	.endm

	.macro apprentice_randomizequestions
	setvar VAR_0x8004, APPRENTICE_FUNC_RANDOMIZE_QUESTIONS
	special CallApprenticeFunction
	.endm

	.macro apprentice_msg  waitbuttonpress:req, which:req
	setvar VAR_0x8004, APPRENTICE_FUNC_PRINT_MSG
	setvar VAR_0x8005, \waitbuttonpress
	setvar VAR_0x8006, \which
	special CallApprenticeFunction
	waitstate
	.endm

	.macro apprentice_reset
	setvar VAR_0x8004, APPRENTICE_FUNC_RESET
	special CallApprenticeFunction
	.endm

	.macro apprentice_shouldcheckgone
	setvar VAR_0x8004, APPRENTICE_FUNC_CHECK_GONE
	special CallApprenticeFunction
	.endm

	.macro apprentice_getquestion
	setvar VAR_0x8004, APPRENTICE_FUNC_GET_QUESTION
	special CallApprenticeFunction
	.endm

	.macro apprentice_getnumpartymons
	setvar VAR_0x8004, APPRENTICE_FUNC_GET_NUM_PARTY_MONS
	special CallApprenticeFunction
	.endm

	.macro apprentice_setpartymon  slot:req
	copyvar VAR_0x8006, \slot
	setvar VAR_0x8004, APPRENTICE_FUNC_SET_PARTY_MON
	special CallApprenticeFunction
	.endm

	.macro apprentice_initquestion  which:req
	setvar VAR_0x8004, APPRENTICE_FUNC_INIT_QUESTION_DATA
	setvar VAR_0x8005, \which
	special CallApprenticeFunction
	.endm

	.macro apprentice_freequestion
	setvar VAR_0x8004, APPRENTICE_FUNC_FREE_QUESTION_DATA
	special CallApprenticeFunction
	.endm

	.macro apprentice_buff  whichstringvar:req, tobuff:req
	setvar VAR_0x8004, APPRENTICE_FUNC_BUFFER_STRING
	setvar VAR_0x8005, \whichstringvar
	.if \tobuff >= VARS_START
	copyvar VAR_0x8006, \tobuff
	.else
	setvar VAR_0x8006, \tobuff
	.endif
	special CallApprenticeFunction
	.endm

	.macro apprentice_setmove
	setvar VAR_0x8004, APPRENTICE_FUNC_SET_MOVE
	special CallApprenticeFunction
	.endm

	.macro apprentice_setleadmon  monId:req
	copyvar VAR_0x8005, \monId
	setvar VAR_0x8004, APPRENTICE_FUNC_SET_LEAD_MON
	special CallApprenticeFunction
	.endm

	.macro apprentice_openbag
	setvar VAR_0x8004, APPRENTICE_FUNC_OPEN_BAG
	special CallApprenticeFunction
	waitstate
	.endm

	.macro apprentice_trysetitem
	setvar VAR_0x8004, APPRENTICE_FUNC_TRY_SET_HELD_ITEM
	special CallApprenticeFunction
	.endm

	.macro apprentice_save
	setvar VAR_0x8004, APPRENTICE_FUNC_SAVE
	special CallApprenticeFunction
	.endm

	.macro apprentice_setgfx
	setvar VAR_0x8004, APPRENTICE_FUNC_SET_GFX
	special CallApprenticeFunction
	.endm

	.macro apprentice_shouldleave
	setvar VAR_0x8004, APPRENTICE_FUNC_SHOULD_LEAVE
	special CallApprenticeFunction
	.endm

	.macro apprentice_shiftsaved
	setvar VAR_0x8004, APPRENTICE_FUNC_SHIFT_SAVED
	special CallApprenticeFunction
	.endm
