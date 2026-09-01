	@ Sets NPC gfx and the floor layout depending on current challenge and floor
	.macro ttower_initfloor
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_INIT_FLOOR
	special CallTrainerTowerFunc
	.endm

	@ Buffers the opponents battle speech to gStringVar4. speech is any TRAINER_TOWER_TEXT_*.
	.macro ttower_getspeech speech:req, trainer=0xFF
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_SPEECH
	setvar VAR_0x8005, \speech
	.if \trainer >= VARS_START && \trainer != 0xFF
	copyvar VAR_0x8006, \trainer
	.elseif \trainer != 0xFF
	setvar VAR_0x8006, \trainer
	.endif
	special CallTrainerTowerFunc
	.endm

	@ Starts a trainer tower battle. VAR_0x8005 is unused
	.macro ttower_dobattle
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_DO_BATTLE
	setvar VAR_0x8005, 0
	special CallTrainerTowerFunc
	.endm

	@ Returns the current challenge type (CHALLENGE_TYPE_*). Mixed challenges use different types for each floor. If VAR_0x8005 is != FALSE, does nothing
	.macro ttower_getchallengetype
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_CHALLENGE_TYPE
	setvar VAR_0x8005, FALSE
	special CallTrainerTowerFunc
	.endm

	@ Adds 1 to the number of floors cleared (all trainers on floor defeated)
	.macro ttower_clearedfloor
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_CLEARED_FLOOR
	special CallTrainerTowerFunc
	.endm

	@ TRUE if the trainers on this floor were already beaten, FALSE otherwise
	.macro ttower_isfloorcleared
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_FLOOR_CLEARED
	special CallTrainerTowerFunc
	.endm

	@ Initializes the Trainer Tower challenge and starts the timer
	.macro ttower_startchallenge
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_START_CHALLENGE
	special CallTrainerTowerFunc
	.endm

	@ 0 if not spoken to yet, 1 if spoken to but not received prize, 2 if received prize
	.macro ttower_getownerstate
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_OWNER_STATE
	special CallTrainerTowerFunc
	.endm

	@ Tries to give prize. 0 if given successfully, 1 if no room for prize, 2 if giving prize should be skipped
	.macro ttower_giveprize
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GIVE_PRIZE
	special CallTrainerTowerFunc
	.endm

	@ Checks the final challenge time. 0 if new record, 1 if not, 2 if time has already been checked
	.macro ttower_checkfinaltime
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_CHECK_FINAL_TIME
	special CallTrainerTowerFunc
	.endm

	@ Resumes the challenge timer (or starts, if the timer is 0)
	.macro ttower_resumetimer
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_RESUME_TIMER
	special CallTrainerTowerFunc
	.endm

	@ Sets that the player lost the challenge
	.macro ttower_setlost
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_SET_LOST
	special CallTrainerTowerFunc
	.endm

	@ Returns the status of the current Trainer Tower challenge (CHALLENGE_STATUS_*)
	.macro ttower_getchallengestatus
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_CHALLENGE_STATUS
	special CallTrainerTowerFunc
	.endm

	@ Buffers the current challenge time (min in gStringVar1, sec in gStringVar2, fraction sec in gStringVar3)
	.macro ttower_gettime
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_TIME
	special CallTrainerTowerFunc
	.endm

	@ Unused. Displays Trainer Tower results. Handled by ShowBattleRecords instead
	.macro ttower_showresults
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_SHOW_RESULTS
	special CallTrainerTowerFunc
	.endm

	@ Unused. See above
	.macro ttower_closeresults
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_CLOSE_RESULTS
	special CallTrainerTowerFunc
	.endm

	@ Returns the eligibility of the players party for a double battle (using GetMonsStateToDoubles)
	.macro ttower_checkdoubles
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_CHECK_DOUBLES
	special CallTrainerTowerFunc
	.endm

	@ For the unused E-Reader challenges, gets the number of floors used. Otherwise returns FALSE (all floors used)
	.macro ttower_getnumfloors
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_NUM_FLOORS
	special CallTrainerTowerFunc
	.endm

	@ Dummied, always returns FALSE
	.macro ttower_shouldexit
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_SHOULD_WARP_TO_COUNTER
	special CallTrainerTowerFunc
	.endm

	@ Plays the encounter music for the trainer number in VAR_TEMP_1
	.macro ttower_encountermusic
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_ENCOUNTER_MUSIC
	special CallTrainerTowerFunc
	.endm

	@ TRUE if the player reached the Battle Tower owner, FALSE otherwise
	.macro ttower_getbeatchallenge
	setvar VAR_0x8004, TRAINER_TOWER_FUNC_GET_BEAT_CHALLENGE
	special CallTrainerTowerFunc
	.endm
