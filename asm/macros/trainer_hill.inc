@ TODO: These need to have description comment

	.macro trainerhill_start
	setvar VAR_0x8004, TRAINER_HILL_FUNC_START
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_getownerstate
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_OWNER_STATE
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_giveprize
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GIVE_PRIZE
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_finaltime
	setvar VAR_0x8004, TRAINER_HILL_FUNC_CHECK_FINAL_TIME
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_resumetimer
	setvar VAR_0x8004, TRAINER_HILL_FUNC_RESUME_TIMER
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_lost
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_LOST
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_getstatus
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_CHALLENGE_STATUS
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_gettime
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_CHALLENGE_TIME
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_allfloorsused
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_ALL_FLOORS_USED
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_clearresult
	setvar VAR_0x8004, TRAINER_HILL_FUNC_CLEAR_RESULT
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_inchallenge
	setvar VAR_0x8004, TRAINER_HILL_FUNC_IN_CHALLENGE
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_postbattletext
	setvar VAR_0x8004, TRAINER_HILL_FUNC_POST_BATTLE_TEXT
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_settrainerflags
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_ALL_TRAINER_FLAGS
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_getsaved
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_GAME_SAVED
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_setsaved
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_GAME_SAVED
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_clearsaved
	setvar VAR_0x8004, TRAINER_HILL_FUNC_CLEAR_GAME_SAVED
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_getwon
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_WON
	special CallTrainerHillFunction
	.endm

	.macro trainerhill_settag tag:req
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_TAG
	copyvar VAR_0x8005, \tag
	special CallTrainerHillFunction
	.endm
