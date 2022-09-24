	@ Initialize the Trainer Hill challenge and start the timer
	.macro trainerhill_start
	setvar VAR_0x8004, TRAINER_HILL_FUNC_START
	special CallTrainerHillFunction
	.endm

	@ 0 if not spoken to yet, 1 if spoken to but not received prize, 2 if received prize
	.macro trainerhill_getownerstate
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_OWNER_STATE
	special CallTrainerHillFunction
	.endm

	@ Try to give prize. 0 if given successfully, 1 if no room for prize, 2 if giving prize should be skipped
	.macro trainerhill_giveprize
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GIVE_PRIZE
	special CallTrainerHillFunction
	.endm

	@ Check the final challenge time. 0 if new record, 1 if not, 2 if time has already been checked
	.macro trainerhill_finaltime
	setvar VAR_0x8004, TRAINER_HILL_FUNC_CHECK_FINAL_TIME
	special CallTrainerHillFunction
	.endm

	@ Resume the timer. Wont resume if owner has been spoken to or max time has been reached
	.macro trainerhill_resumetimer
	setvar VAR_0x8004, TRAINER_HILL_FUNC_RESUME_TIMER
	special CallTrainerHillFunction
	.endm

	@ Set player lost the challenge (trainerHill.hasLost) to TRUE
	.macro trainerhill_lost
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_LOST
	special CallTrainerHillFunction
	.endm

	@ Get the current challenge status (TRAINER_HILL_PLAYER_STATUS_*)
	.macro trainerhill_getstatus
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_CHALLENGE_STATUS
	special CallTrainerHillFunction
	.endm

	@ Buffer the current timer to string vars (mins to STR_VAR_1, secs to STR_VAR_2, fraction of sec to STR_VAR_3)
	.macro trainerhill_gettime
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_CHALLENGE_TIME
	special CallTrainerHillFunction
	.endm

	@ FALSE if fewer than all 4 floors used, TRUE otherwise. Only FALSE in JP-exclusive modes
	.macro trainerhill_allfloorsused
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_ALL_FLOORS_USED
	special CallTrainerHillFunction
	.endm

	@ Unknown, dummied. E-Reader association is assumed. Only side effect is setting VAR_RESULT to 0.
	.macro trainerhill_getusingereader
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_IN_EREADER_MODE
	special CallTrainerHillFunction
	.endm

	@ TRUE if currently in a Trainer Hill challenge
	.macro trainerhill_inchallenge
	setvar VAR_0x8004, TRAINER_HILL_FUNC_IN_CHALLENGE
	special CallTrainerHillFunction
	.endm

	@ Show the post battle text for the spoken to Trainer Hill trainer
	.macro trainerhill_postbattletext
	setvar VAR_0x8004, TRAINER_HILL_FUNC_POST_BATTLE_TEXT
	special CallTrainerHillFunction
	.endm

	@ Set all Trainer Hill trainers defeated
	.macro trainerhill_settrainerflags
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_ALL_TRAINER_FLAGS
	special CallTrainerHillFunction
	.endm

	@ TRUE if the game has been saved for the challenge, FALSE otherwise
	.macro trainerhill_getsaved
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_GAME_SAVED
	special CallTrainerHillFunction
	.endm

	@ Set that the game has been saved for the challenge
	.macro trainerhill_setsaved
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_GAME_SAVED
	special CallTrainerHillFunction
	.endm

	@ Clear that the game has been saved for the challenge
	.macro trainerhill_clearsaved
	setvar VAR_0x8004, TRAINER_HILL_FUNC_CLEAR_GAME_SAVED
	special CallTrainerHillFunction
	.endm

	@ FALSE if the Trainer Hill challenge was lost, TRUE otherwise
	.macro trainerhill_getwon
	setvar VAR_0x8004, TRAINER_HILL_FUNC_GET_WON
	special CallTrainerHillFunction
	.endm

	@ Set the challenge mode to HILL_MODE_* (Normal, Variety, Unique, or Expert)
	.macro trainerhill_setmode mode:req
	setvar VAR_0x8004, TRAINER_HILL_FUNC_SET_MODE
	copyvar VAR_0x8005, \mode
	special CallTrainerHillFunction
	.endm
